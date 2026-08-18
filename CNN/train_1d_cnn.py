import os
import glob
import json
import gc
import numpy as np
import pandas as pd
import tensorflow as tf
from tensorflow import keras
from sklearn.model_selection import train_test_split
from sklearn.utils.class_weight import compute_class_weight
from sklearn.metrics import confusion_matrix

# Check GPU
gpus = tf.config.list_physical_devices('GPU')
print("Num GPUs Available: ", len(gpus))
if gpus:
    try:
        for gpu in gpus:
            tf.config.experimental.set_memory_growth(gpu, True)
        print("GPU memory growth and optimization enabled!")
    except RuntimeError as e:
        print(e)

# --- Config ---
WINDOW_SIZE = 600
STRIDE = 5
EPOCHS = 10
BATCH_SIZE = 64

# Resolving paths
base_dir = os.path.dirname(os.getcwd())
if os.path.exists(os.path.join(os.getcwd(), "patient_labeled_data")):
    input_dir = os.path.join(os.getcwd(), "patient_labeled_data")
elif os.path.exists(os.path.join(os.getcwd(), "..", "patient_labeled_data")):
    input_dir = os.path.join(os.getcwd(), "..", "patient_labeled_data")
else:
    input_dir = "../patient_labeled_data"

csv_files = sorted(glob.glob(os.path.join(input_dir, "patient_*_1hz.csv")))

# The exact 19 features present in the CSV
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

print(f"Total CSV Files: {len(csv_files)}")
train_val_files, test_files = train_test_split(csv_files, test_size=0.20, random_state=42, shuffle=True)
train_files, val_files = train_test_split(train_val_files, test_size=0.125, random_state=42, shuffle=True)

# We will use only a subset for memory reasons if dataset is very large, but let's try max possible
MAX_TRAIN = 500
MAX_VAL = 100

class WindowDataGenerator(keras.utils.Sequence):
    def __init__(self, file_list, target_col, features, batch_size=64, window_size=600, stride=5, shuffle=True):
        self.batch_size = batch_size
        self.window_size = window_size
        self.stride = stride
        self.shuffle = shuffle
        self.X_data = []
        self.y_data = []
        self.window_indices = []
        
        print(f"Pre-loading raw CSVs into memory for {target_col}...")
        for file_idx, file in enumerate(file_list):
            try:
                df = pd.read_csv(file)
                avail_features = [c for c in features if c in df.columns]
                if len(avail_features) < len(features) or target_col not in df.columns:
                    continue
                
                df_sub = df[avail_features + [target_col]].ffill().bfill().fillna(0)
                arr = df_sub[avail_features].values.astype(np.float32)
                y_vals = df_sub[target_col].values.astype(np.float32)
                
                self.X_data.append(arr)
                self.y_data.append(y_vals)
                
                # Pre-calculate valid window start indices for this patient
                for i in range(0, len(arr) - window_size, stride):
                    if not np.isnan(y_vals[i + window_size - 1]):
                        self.window_indices.append((file_idx, i))
                        
            except Exception as e:
                continue
                
        self.indices = np.arange(len(self.window_indices))
        if self.shuffle:
            np.random.shuffle(self.indices)
            
    def __len__(self):
        return int(np.ceil(len(self.window_indices) / self.batch_size))
        
    def __getitem__(self, idx):
        batch_inds = self.indices[idx * self.batch_size : (idx + 1) * self.batch_size]
        X_batch = np.empty((len(batch_inds), self.window_size, len(features)), dtype=np.float32)
        y_batch = np.empty((len(batch_inds),), dtype=np.float32)
        
        for i, b_idx in enumerate(batch_inds):
            file_idx, start = self.window_indices[b_idx]
            X_batch[i] = self.X_data[file_idx][start : start + self.window_size]
            y_batch[i] = self.y_data[file_idx][start + self.window_size - 1]
            
        return X_batch, y_batch
        
    def get_all_y(self):
        y_all = np.empty(len(self.window_indices), dtype=np.float32)
        for i, w_idx in enumerate(self.window_indices):
            file_idx, start = w_idx
            y_all[i] = self.y_data[file_idx][start + self.window_size - 1]
        return y_all

MAX_TRAIN = 500  # You can increase this safely now!
MAX_VAL = 100

# --- Global Scaler ---
print("[Global] Computing single Normalizer (Mean/Variance) for all 19 features...")
scaler_data = []
for file in train_files[:MAX_TRAIN]:
    try:
        df = pd.read_csv(file)
        avail = [c for c in features if c in df.columns]
        if len(avail) == len(features):
            scaler_data.append(df[features].ffill().bfill().fillna(0).values.astype(np.float32))
    except:
        continue
if scaler_data:
    stacked = np.vstack(scaler_data)
    global_mean = np.mean(stacked, axis=0)
    global_variance = np.var(stacked, axis=0)
    
    scaler_dict = {
        "mean": {feat: float(global_mean[i]) for i, feat in enumerate(features)},
        "variance": {feat: float(global_variance[i]) for i, feat in enumerate(features)},
        "std": {feat: float(np.sqrt(global_variance[i])) for i, feat in enumerate(features)}
    }
    with open("scaler_1d_cnn.json", "w") as f:
        json.dump(scaler_dict, f, indent=4)
else:
    print("Failed to compute scaler data. Aborting.")
    exit(1)


# Build TFLite CNN Architecture
def get_compiled_model():
    inputs = keras.Input(shape=(WINDOW_SIZE, len(features)))
    
    norm_layer = keras.layers.Normalization(mean=global_mean, variance=global_variance)
    x = norm_layer(inputs)
    
    x = keras.layers.Conv1D(filters=16, kernel_size=5, strides=2, activation='relu', padding='same', kernel_regularizer=keras.regularizers.l2(0.001))(x)
    x = keras.layers.MaxPool1D(pool_size=2)(x)
    
    x = keras.layers.Conv1D(filters=32, kernel_size=3, strides=2, activation='relu', padding='same', kernel_regularizer=keras.regularizers.l2(0.001))(x)
    x = keras.layers.MaxPool1D(pool_size=2)(x)
    
    x = keras.layers.Conv1D(filters=32, kernel_size=3, strides=2, activation='relu', padding='same', kernel_regularizer=keras.regularizers.l2(0.001))(x)
    
    x = keras.layers.GlobalAveragePooling1D()(x)
    x = keras.layers.Dropout(0.5)(x)
    
    outputs = keras.layers.Dense(1, activation='sigmoid')(x)
    
    model = keras.Model(inputs=inputs, outputs=outputs)
    model.compile(optimizer=keras.optimizers.Adam(learning_rate=0.0005), 
                  loss='binary_crossentropy', 
                  metrics=[keras.metrics.AUC(name='auc')])
    return model

class EpochEndCallback(keras.callbacks.Callback):
    def __init__(self, val_gen, target):
        super().__init__()
        self.val_gen = val_gen
        self.target = target
        
    def on_epoch_end(self, epoch, logs=None):
        print(f"\n--- Epoch {epoch+1} Confusion Matrix ---")
        y_true = self.val_gen.get_all_y()
        y_pred_prob = self.model.predict(self.val_gen, verbose=0)
        y_pred = (y_pred_prob > 0.5).astype(int).flatten()
        cm = confusion_matrix(y_true, y_pred)
        print(cm)
        
        checkpoint_name = f"checkpoint_epoch{epoch+1}.tfile"
        try:
            converter = tf.lite.TFLiteConverter.from_keras_model(self.model)
            converter.optimizations = [tf.lite.Optimize.DEFAULT]
            tflite_model = converter.convert()
            with open(checkpoint_name, "wb") as f:
                f.write(tflite_model)
            print(f"Saved {checkpoint_name}")
        except Exception as e:
            print(f"Failed to save {checkpoint_name}: {e}")

targets = ["Future_Hypotension", "Future_Hypoxia", "Future_Tachycardia"]

for target in targets:
    print("=" * 60)
    print(f" TRAINING 1D CNN FOR: {target}")
    print("=" * 60)
    
    train_gen = WindowDataGenerator(train_files[:MAX_TRAIN], target, features, BATCH_SIZE, WINDOW_SIZE, STRIDE, shuffle=True)
    val_gen = WindowDataGenerator(val_files[:MAX_VAL], target, features, BATCH_SIZE, WINDOW_SIZE, STRIDE, shuffle=False)
    
    if len(train_gen) == 0:
        print(f"No valid data found for {target}. Skipping...")
        continue
    
    y_tr_all = train_gen.get_all_y()
    classes = np.unique(y_tr_all)
    weights = compute_class_weight('balanced', classes=classes, y=y_tr_all)
    class_weights = dict(zip(classes, weights))
    print(f"Class Weights applied for imbalance: {class_weights}")
    print(f"Train Windows: {len(y_tr_all)} | Val Windows: {len(val_gen.get_all_y())}")
    
    model = get_compiled_model()
    early_stop = keras.callbacks.EarlyStopping(monitor='val_auc', mode='max', patience=3, restore_best_weights=True)
    epoch_end_cb = EpochEndCallback(val_gen, target)
    
    model.fit(
        train_gen,
        validation_data=val_gen,
        epochs=EPOCHS,
        class_weight=class_weights,
        callbacks=[early_stop, epoch_end_cb],
        verbose=1
    )
    
    # Export to TFLite
    print(f"Exporting {target} to TFLite...")
    converter = tf.lite.TFLiteConverter.from_keras_model(model)
    converter.optimizations = [tf.lite.Optimize.DEFAULT]
    tflite_model = converter.convert()
    
    tflite_path = f"cnn_{target}.tflite"
    with open(tflite_path, "wb") as f:
        f.write(tflite_model)
    print(f"Successfully saved {tflite_path} ({len(tflite_model) / 1024:.2f} KB)")
    
    # Free up memory
    del train_gen, val_gen, y_tr_all, model
    gc.collect()

print("All targets processed successfully!")
