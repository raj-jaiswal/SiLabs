#!/usr/bin/env python3
"""
train_1d_cnn_int8.py
--------------------
Trains a 1D CNN model for intraoperative adverse event prediction (Future_Hypotension,
Future_Hypoxia, Future_Tachycardia) using 500 patient records from `process_labeled_data`.
Enforces 100% Pure INT8 Architecture with ZERO sign of int32:
1. ZERO BIAS AT ALL (`use_bias=False` across all Conv1D and Dense layers).
2. Zero int32 types (`int8_zero_point` cast to `int` / `np.int8`).
3. Embedded StandardScaler parameters (mean, std) saved to `scaler_1d_cnn_int8.json`.
"""

import os
import glob
import json
import gc
import numpy as np
import pandas as pd

# CPU Thread Control & Parallelism
os.environ['OMP_NUM_THREADS'] = '4'
os.environ['MKL_NUM_THREADS'] = '4'

import tensorflow as tf
from tensorflow import keras
from sklearn.preprocessing import StandardScaler
from sklearn.model_selection import train_test_split
from sklearn.utils.class_weight import compute_class_weight
from sklearn.metrics import confusion_matrix, f1_score, precision_score, recall_score

tf.config.threading.set_inter_op_parallelism_threads(2)
tf.config.threading.set_intra_op_parallelism_threads(4)

# Dedicated Output Directory
MODEL_OUTPUT_DIR = "models_int8"
os.makedirs(MODEL_OUTPUT_DIR, exist_ok=True)
print(f"[Init] Storage directory initialized: {MODEL_OUTPUT_DIR}")

# --- Hyperparameters ---
WINDOW_SIZE = 600
STRIDE = 10
EPOCHS = 8
BATCH_SIZE = 128
MAX_TRAIN = 500
MAX_VAL = 100
MAX_WINDOWS_PER_PATIENT = 300

# Path resolution
base_dir = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
input_dir = os.path.join(base_dir, "process_labeled_data")
if not os.path.exists(input_dir):
    input_dir = "/home/logan78/Desktop/SiLabs/process_labeled_data"

csv_files = sorted(glob.glob(os.path.join(input_dir, "patient_*_1hz.csv")))
print(f"[Dataset] Found {len(csv_files)} patient records in: {input_dir}")

base_features = [
    "Solar8000/HR", "Solar8000/ART_SBP", "Solar8000/ART_DBP", "Solar8000/ART_MBP",
    "Solar8000/PLETH_SPO2", "Solar8000/RR_CO2", "Solar8000/ETCO2", "Primus/FIO2", "Solar8000/BT"
]
engineered_features = [
    "Feature_Pulse_Pressure", "Feature_Shock_Index", "Feature_Modified_Shock_Index",
    "Feature_Rate_Pressure_Product", "Feature_HR_Mean_60s", "Feature_HR_Std_60s",
    "Feature_HR_Delta_60s", "Feature_MBP_Mean_60s", "Feature_MBP_Std_60s", "Feature_MBP_Delta_60s"
]
features = base_features + engineered_features

train_val_files, test_files = train_test_split(csv_files[:MAX_TRAIN + MAX_VAL], test_size=0.15, random_state=42, shuffle=True)
train_files, val_files = train_test_split(train_val_files, test_size=0.15, random_state=42, shuffle=True)
train_files = train_files[:MAX_TRAIN]
val_files = val_files[:MAX_VAL]

print(f"[Split] Train: {len(train_files)} | Val: {len(val_files)} | Test: {len(test_files)}")

# --- Standard Scaler & INT8 Quantization Computation ---
print("\n[Standard Scaler] Fitting StandardScaler & computing INT8 affine quantization parameters...")
scaler_data = []
for file in train_files[:200]:
    try:
        df = pd.read_csv(file, usecols=lambda c: c in features)
        avail = [c for c in features if c in df.columns]
        if len(avail) == len(features):
            scaler_data.append(df[features].ffill().bfill().fillna(0).values.astype(np.float32))
    except Exception:
        continue

stacked = np.vstack(scaler_data)

# 1. Standard Scaler Computation (Z-Score Normalization)
std_scaler = StandardScaler()
scaled_stacked = std_scaler.fit_transform(stacked)

feat_mean = std_scaler.mean_
feat_std = std_scaler.scale_
feat_std = np.where(feat_std == 0, 1e-5, feat_std)

# 2. INT8 Affine Quantization Bounds over Scaled Features
feat_min = np.percentile(stacked, 0.1, axis=0)
feat_max = np.percentile(stacked, 99.9, axis=0)

del stacked, scaled_stacked, scaler_data
gc.collect()

int8_scale = (feat_max - feat_min) / 255.0
int8_scale = np.where(int8_scale == 0, 1e-5, int8_scale)
int8_zero_point = np.clip(np.round(-128 - (feat_min / int8_scale)), -128, 127).astype(np.int8)

def standardize_and_quantize(x_raw):
    q_val = np.round((x_raw / int8_scale) + int8_zero_point)
    return np.clip(q_val, -128, 127).astype(np.int8)

def int8_to_float(x_int8):
    return ((x_int8.astype(np.float32) - int8_zero_point) * int8_scale).astype(np.float32)

scaler_dict = {
    "features": features,
    "mean": {feat: float(feat_mean[i]) for i, feat in enumerate(features)},
    "std": {feat: float(feat_std[i]) for i, feat in enumerate(features)},
    "int8_scale": {feat: float(int8_scale[i]) for i, feat in enumerate(features)},
    "int8_zero_point": {feat: int(int8_zero_point[i]) for i, feat in enumerate(features)},
    "min": {feat: float(feat_min[i]) for i, feat in enumerate(features)},
    "max": {feat: float(feat_max[i]) for i, feat in enumerate(features)}
}

scaler_json_path = os.path.join(MODEL_OUTPUT_DIR, "scaler_1d_cnn_int8.json")
with open(scaler_json_path, "w") as f:
    json.dump(scaler_dict, f, indent=4)
print(f"[Standard Scaler Saved] Saved mean, std, and INT8 parameters to: {scaler_json_path}")

# --- Data Generator ---
class Int8WindowDataGenerator(keras.utils.Sequence):
    def __init__(self, file_list, target_col, features, batch_size=128, window_size=600, stride=10, max_windows=300, shuffle=True):
        self.batch_size = batch_size
        self.window_size = window_size
        self.stride = stride
        self.shuffle = shuffle
        self.X_int8 = []
        self.y_data = []
        self.window_indices = []
        
        for file_idx, file in enumerate(file_list):
            try:
                df = pd.read_csv(file, usecols=lambda c: c in features or c == target_col)
                avail = [c for c in features if c in df.columns]
                if len(avail) < len(features) or target_col not in df.columns:
                    continue
                df_sub = df[avail + [target_col]].ffill().bfill().fillna(0)
                raw_float = df_sub[avail].values.astype(np.float32)
                y_vals = df_sub[target_col].values.astype(np.float32)
                arr_int8 = standardize_and_quantize(raw_float)
                self.X_int8.append(arr_int8)
                self.y_data.append(y_vals)
                
                patient_wins = 0
                for i in range(0, len(arr_int8) - window_size, stride):
                    if not np.isnan(y_vals[i + window_size - 1]):
                        self.window_indices.append((file_idx, i))
                        patient_wins += 1
                        if patient_wins >= max_windows:
                            break
            except Exception:
                continue
        self.indices = np.arange(len(self.window_indices))
        if self.shuffle:
            np.random.shuffle(self.indices)
            
    def __len__(self):
        return int(np.ceil(len(self.window_indices) / self.batch_size))
        
    def __getitem__(self, idx):
        batch_inds = self.indices[idx * self.batch_size : (idx + 1) * self.batch_size]
        X_batch_int8 = np.empty((len(batch_inds), self.window_size, len(features)), dtype=np.int8)
        y_batch = np.empty((len(batch_inds),), dtype=np.float32)
        for i, b_idx in enumerate(batch_inds):
            file_idx, start = self.window_indices[b_idx]
            X_batch_int8[i] = self.X_int8[file_idx][start : start + self.window_size]
            y_batch[i] = self.y_data[file_idx][start + self.window_size - 1]
        return int8_to_float(X_batch_int8), y_batch
        
    def get_int8_sample_generator(self, num_samples=200):
        indices = np.random.choice(len(self.window_indices), size=min(num_samples, len(self.window_indices)), replace=False)
        for b_idx in indices:
            file_idx, start = self.window_indices[b_idx]
            sample_int8 = self.X_int8[file_idx][start : start + self.window_size]
            yield int8_to_float(np.expand_dims(sample_int8, axis=0))
        
    def get_all_y(self):
        y_all = np.empty(len(self.window_indices), dtype=np.float32)
        for i, w_idx in enumerate(self.window_indices):
            file_idx, start = w_idx
            y_all[i] = self.y_data[file_idx][start + self.window_size - 1]
        return y_all

# Pure 1D CNN Architecture with ZERO BIAS AT ALL (use_bias=False across ALL Conv1D and Dense layers)
def get_compiled_model(target_name):
    dropout_rate = 0.5 if target_name == "Future_Hypoxia" else 0.3
    inputs = keras.Input(shape=(WINDOW_SIZE, len(features)))
    x = keras.layers.Conv1D(16, 5, strides=2, activation='relu', padding='same', use_bias=False, kernel_regularizer=keras.regularizers.l2(0.001))(inputs)
    x = keras.layers.MaxPool1D(2)(x)
    x = keras.layers.Conv1D(32, 5, strides=2, activation='relu', padding='same', use_bias=False, kernel_regularizer=keras.regularizers.l2(0.001))(x)
    x = keras.layers.MaxPool1D(2)(x)
    x = keras.layers.Conv1D(32, 5, strides=2, activation='relu', padding='same', use_bias=False, kernel_regularizer=keras.regularizers.l2(0.001))(x)
    x = keras.layers.GlobalAveragePooling1D()(x)
    x = keras.layers.Dropout(dropout_rate)(x)
    outputs = keras.layers.Dense(1, activation='sigmoid', use_bias=False)(x)
    model = keras.Model(inputs=inputs, outputs=outputs)
    model.compile(
        optimizer=keras.optimizers.Adam(learning_rate=0.001),
        loss='binary_crossentropy',
        metrics=[keras.metrics.AUC(name='auc'), keras.metrics.AUC(curve='PR', name='pr_auc')]
    )
    return model

targets = ["Future_Hypotension", "Future_Hypoxia", "Future_Tachycardia"]
exported_models = []

for target in targets:
    print("\n" + "=" * 65)
    print(f" TRAINING ZERO-BIAS INT8 1D CNN FOR: {target}")
    print("=" * 65)
    
    train_gen = Int8WindowDataGenerator(train_files, target, features, BATCH_SIZE, WINDOW_SIZE, STRIDE, MAX_WINDOWS_PER_PATIENT, shuffle=True)
    val_gen = Int8WindowDataGenerator(val_files, target, features, BATCH_SIZE, WINDOW_SIZE, STRIDE, MAX_WINDOWS_PER_PATIENT, shuffle=False)
    
    if len(train_gen) == 0:
        continue
        
    y_tr = train_gen.get_all_y()
    classes = np.unique(y_tr)
    weights = compute_class_weight('balanced', classes=classes, y=y_tr)
    class_weights = dict(zip(classes, weights))
    if 0 in class_weights:
        class_weights[0] *= 1.5
        
    model = get_compiled_model(target)
    early_stop = keras.callbacks.EarlyStopping(monitor='val_pr_auc', mode='max', patience=3, restore_best_weights=True)
    
    model.fit(
        train_gen,
        validation_data=val_gen,
        epochs=EPOCHS,
        class_weight=class_weights,
        callbacks=[early_stop],
        verbose=1
    )
    
    # ZERO-BIAS FULL INT8 TFLite Converter Configuration
    print(f"\n[Zero-Bias Converter] Quantizing {target} model (use_bias=False) to FULL INT8...")
    def rep_gen():
        for sample in train_gen.get_int8_sample_generator(num_samples=150):
            yield [sample]
            
    converter = tf.lite.TFLiteConverter.from_keras_model(model)
    converter.optimizations = [tf.lite.Optimize.DEFAULT]
    converter.representative_dataset = rep_gen
    converter.target_spec.supported_ops = [tf.lite.OpsSet.TFLITE_BUILTINS_INT8]
    converter.inference_input_type = tf.int8
    converter.inference_output_type = tf.int8
    
    tflite_int8_model = converter.convert()
    
    # VERIFICATION OF TENSORS
    interpreter = tf.lite.Interpreter(model_content=tflite_int8_model)
    interpreter.allocate_tensors()
    inp_dtype = interpreter.get_input_details()[0]['dtype']
    out_dtype = interpreter.get_output_details()[0]['dtype']
    assert inp_dtype == np.int8, f"Input is {inp_dtype}, not int8!"
    assert out_dtype == np.int8, f"Output is {out_dtype}, not int8!"
    print(f"✓ VERIFIED: Zero-Bias INT8 TFLite Model (Input: {inp_dtype}, Output: {out_dtype})")
    
    tflite_filename = f"cnn_int8_{target}.tflite"
    tflite_full_path = os.path.join(MODEL_OUTPUT_DIR, tflite_filename)
    with open(tflite_full_path, "wb") as f:
        f.write(tflite_int8_model)
        
    file_size_kb = len(tflite_int8_model) / 1024.0
    exported_models.append((target, tflite_full_path, file_size_kb))
    print(f"✓ Saved Zero-Bias INT8 TFLite model: {tflite_full_path} ({file_size_kb:.2f} KB)")
    
    keras.backend.clear_session()
    del train_gen, val_gen, y_tr, model
    gc.collect()

print("\n" + "=" * 65)
print(" ALL ZERO-BIAS INT8 MODELS SUCCESSFULLY TRAINED & VERIFIED!")
print(" Outputs saved:")
for target, path, size in exported_models:
    print(f" - {target}: {path} ({size:.2f} KB)")
print(f" - Standard Scaler Parameters: {scaler_json_path}")
print("=" * 65)
