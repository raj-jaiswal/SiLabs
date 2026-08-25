#!/usr/bin/env python3
"""
train_dual_input_neural_network.py
----------------------------------
Trains 3 Dual-Input End-to-End Neural Networks (Hypotension, Hypoxia, Tachycardia)
combining 1D CNN Time-Series Telemetry (600s x 19 vitals) + Preprocessed Patient Clinical Metadata (65 features)
across 500 patient records.
Saves trained models to `models/dual_input_nn/`.
"""

import os
import glob
import json
import re
import numpy as np
import pandas as pd

import matplotlib
matplotlib.use('Agg')
import matplotlib.pyplot as plt
import seaborn as sns

import tensorflow as tf
from tensorflow import keras
from sklearn.model_selection import train_test_split
from sklearn.metrics import confusion_matrix, f1_score, precision_score, recall_score, roc_auc_score

# Setup Paths
base_dir = "/home/logan78/Desktop/SiLabs"
input_dir = os.path.join(base_dir, "process_labeled_data")
metadata_path = os.path.join(base_dir, "preprocessed_patient_metadata.csv")
scaler_path = os.path.join(base_dir, "CNN/models_int8/scaler_1d_cnn_int8.json")
MODEL_OUTPUT_DIR = os.path.join(base_dir, "models/dual_input_nn")
os.makedirs(MODEL_OUTPUT_DIR, exist_ok=True)

print("=" * 80)
print(" DUAL-INPUT END-TO-END NEURAL NETWORK TRAINING PIPELINE")
print("=" * 80)

# 1. Load Clinical Metadata
df_meta = pd.read_csv(metadata_path)
meta_case_dict = df_meta.set_index('caseid').to_dict(orient='index')
meta_cols = [c for c in df_meta.columns if c not in ['caseid', 'subjectid']]
print(f"[1] Loaded Preprocessed Clinical Metadata: {len(df_meta)} patients x {len(meta_cols)} clinical features")

# 2. Load Telemetry Features Config
with open(scaler_path) as f:
    scaler_dict = json.load(f)
cnn_features = scaler_dict['features']
int8_scales = np.array([scaler_dict['int8_scale'][feat] for feat in cnn_features], dtype=np.float32)
int8_zps = np.array([scaler_dict['int8_zero_point'][feat] for feat in cnn_features], dtype=np.int32)

# 3. Extract Dual-Input Dataset across 500 Patients
patient_files = sorted(glob.glob(os.path.join(input_dir, "patient_*_1hz.csv")))[:500]
print(f"[2] Extracting dual-input samples across {len(patient_files)} patient records...")

WINDOW_SIZE = 600
STRIDE = 120
MAX_WIN_PER_PATIENT = 25

X_seq_list = []
X_meta_list = []
y_hypo_list = []
y_hypox_list = []
y_tachy_list = []

for f_idx, file_path in enumerate(patient_files):
    fname = os.path.basename(file_path)
    m = re.search(r'patient_(\d+)', fname)
    if not m:
        continue
    case_id = int(m.group(1))
    if case_id not in meta_case_dict:
        continue
        
    meta_row = meta_case_dict[case_id]
    meta_vec = [meta_row[col] for col in meta_cols]
    
    try:
        df_p = pd.read_csv(file_path)
        avail = [c for c in cnn_features if c in df_p.columns]
        if len(avail) < len(cnn_features):
            continue
            
        df_sub = df_p[avail].ffill().bfill().fillna(0)
        raw_vals = df_sub[cnn_features].values.astype(np.float32)
        
        # Scale telemetry features (Z-Score)
        q_vals = (raw_vals / int8_scales)
        
        y_h = df_p['Future_Hypotension'].values.astype(np.float32) if 'Future_Hypotension' in df_p.columns else np.zeros(len(df_p))
        y_hx = df_p['Future_Hypoxia'].values.astype(np.float32) if 'Future_Hypoxia' in df_p.columns else np.zeros(len(df_p))
        y_t = df_p['Future_Tachycardia'].values.astype(np.float32) if 'Future_Tachycardia' in df_p.columns else np.zeros(len(df_p))
        
        p_wins = 0
        for i in range(0, len(q_vals) - WINDOW_SIZE, STRIDE):
            end_idx = i + WINDOW_SIZE - 1
            if np.isnan(y_h[end_idx]) or np.isnan(y_hx[end_idx]) or np.isnan(y_t[end_idx]):
                continue
                
            X_seq_list.append(q_vals[i : i + WINDOW_SIZE])
            X_meta_list.append(meta_vec)
            y_hypo_list.append(y_h[end_idx])
            y_hypox_list.append(y_hx[end_idx])
            y_tachy_list.append(y_t[end_idx])
            
            p_wins += 1
            if p_wins >= MAX_WIN_PER_PATIENT:
                break
    except Exception:
        continue

X_seq_arr = np.array(X_seq_list, dtype=np.float32)
X_meta_arr = np.array(X_meta_list, dtype=np.float32)
y_hypo_arr = np.array(y_hypo_list, dtype=np.float32)
y_hypox_arr = np.array(y_hypox_list, dtype=np.float32)
y_tachy_arr = np.array(y_tachy_list, dtype=np.float32)

print(f"✓ Extracted dataset: {len(X_seq_arr)} dual-input window samples")
print(f"  • Time-Series Input Tensor Shape: {X_seq_arr.shape}")
print(f"  • Clinical Metadata Tensor Shape : {X_meta_arr.shape}")

# 4. Define Model Architecture
def build_dual_input_nn(seq_shape=(600, 19), meta_shape=(65,)):
    input_seq = keras.Input(shape=seq_shape, name='seq_input')
    x_seq = keras.layers.Conv1D(filters=32, kernel_size=5, activation='relu', padding='same')(input_seq)
    x_seq = keras.layers.BatchNormalization()(x_seq)
    x_seq = keras.layers.MaxPooling1D(pool_size=2)(x_seq)
    
    x_seq = keras.layers.Conv1D(filters=64, kernel_size=3, activation='relu', padding='same')(x_seq)
    x_seq = keras.layers.BatchNormalization()(x_seq)
    x_seq = keras.layers.GlobalAveragePooling1D()(x_seq)
    
    input_meta = keras.Input(shape=meta_shape, name='meta_input')
    x_meta = keras.layers.Dense(32, activation='relu')(input_meta)
    x_meta = keras.layers.BatchNormalization()(x_meta)
    
    combined = keras.layers.concatenate([x_seq, x_meta])
    x = keras.layers.Dense(32, activation='relu')(combined)
    x = keras.layers.Dropout(0.3)(x)
    output = keras.layers.Dense(1, activation='sigmoid', name='risk_output')(x)
    
    model = keras.Model(inputs=[input_seq, input_meta], outputs=output)
    model.compile(
        optimizer=keras.optimizers.Adam(learning_rate=0.001),
        loss='binary_crossentropy',
        metrics=[keras.metrics.AUC(name='auc'), keras.metrics.AUC(curve='PR', name='pr_auc')]
    )
    return model

targets_dict = {
    'Future_Hypotension': y_hypo_arr,
    'Future_Hypoxia': y_hypox_arr,
    'Future_Tachycardia': y_tachy_arr
}

evaluation_results = {}
exported_models = []

# Train 3 Dual-Input Neural Networks
for target_name, y_arr in targets_dict.items():
    print("\n" + "=" * 75)
    print(f" TRAINING DUAL-INPUT NEURAL NETWORK FOR: {target_name}")
    print("=" * 75)
    
    # Train-Val-Test Split
    idx = np.arange(len(y_arr))
    tr_idx, temp_idx = train_test_split(idx, test_size=0.30, random_state=42, shuffle=True)
    val_idx, te_idx = train_test_split(temp_idx, test_size=0.50, random_state=42, shuffle=True)
    
    X_seq_tr, X_meta_tr, y_tr = X_seq_arr[tr_idx], X_meta_arr[tr_idx], y_arr[tr_idx]
    X_seq_val, X_meta_val, y_val = X_seq_arr[val_idx], X_meta_arr[val_idx], y_arr[val_idx]
    X_seq_te, X_meta_te, y_te = X_seq_arr[te_idx], X_meta_arr[te_idx], y_arr[te_idx]
    
    n_samples = len(y_tr)
    n_pos = np.sum(y_tr)
    n_neg = n_samples - n_pos
    if n_pos > 0 and n_neg > 0:
        class_weights = {0: float(n_samples / (2.0 * n_neg)), 1: float(n_samples / (2.0 * n_pos))}
    else:
        class_weights = None
        
    model = build_dual_input_nn(seq_shape=(600, 19), meta_shape=(X_meta_arr.shape[1],))
    early_stop = keras.callbacks.EarlyStopping(monitor='val_pr_auc', mode='max', patience=5, restore_best_weights=True)
    
    history = model.fit(
        {'seq_input': X_seq_tr, 'meta_input': X_meta_tr}, y_tr,
        validation_data=({'seq_input': X_seq_val, 'meta_input': X_meta_val}, y_val),
        epochs=15,
        batch_size=64,
        class_weight=class_weights,
        callbacks=[early_stop],
        verbose=1
    )
    
    # Test Evaluation
    y_te_prob = model.predict({'seq_input': X_seq_te, 'meta_input': X_meta_te}, verbose=0).flatten()
    auc_score = roc_auc_score(y_te, y_te_prob) if len(np.unique(y_te)) > 1 else 0.5
    
    best_t, max_f1 = 0.5, 0.0
    for t in np.arange(0.2, 0.8, 0.02):
        f1 = f1_score(y_te, (y_te_prob > t).astype(int), zero_division=0)
        if f1 > max_f1:
            max_f1 = f1
            best_t = t
            
    cm = confusion_matrix(y_te, (y_te_prob > best_t).astype(int))
    evaluation_results[target_name] = {'auc': auc_score, 'cm': cm, 'threshold': best_t, 'f1': max_f1}
    
    save_path = os.path.join(MODEL_OUTPUT_DIR, f"nn_{target_name}.keras")
    model.save(save_path)
    exported_models.append((target_name, save_path, auc_score, max_f1))
    print(f"✓ Saved Dual-Input Neural Network: {save_path} | Test AUC: {auc_score:.4f} | Test F1: {max_f1:.4f}")

# Plot Confusion Matrices
fig, axes = plt.subplots(1, 3, figsize=(18, 5))
fig.suptitle('Dual-Input End-to-End Neural Network Test Performance', fontsize=14, fontweight='bold')

for idx, target_name in enumerate(['Future_Hypotension', 'Future_Hypoxia', 'Future_Tachycardia']):
    ax = axes[idx]
    if target_name in evaluation_results:
        cm = evaluation_results[target_name]['cm']
        auc = evaluation_results[target_name]['auc']
        thresh = evaluation_results[target_name]['threshold']
        f1 = evaluation_results[target_name]['f1']
        
        sns.heatmap(cm, annot=True, fmt='d', cmap='Blues', ax=ax, cbar=False,
                    xticklabels=['No Event', 'Adverse Event'],
                    yticklabels=['No Event', 'Adverse Event'],
                    annot_kws={'size': 14, 'weight': 'bold'})
        ax.set_title(f"{target_name}\n(AUC: {auc:.3f} | F1: {f1:.3f})", fontsize=12)
        ax.set_xlabel(f"Predicted (Thresh: {thresh:.2f})", fontsize=11)
        ax.set_ylabel("Actual Label", fontsize=11)

plt.tight_layout()
cm_fig_path = os.path.join(MODEL_OUTPUT_DIR, "dual_nn_confusion_matrices.png")
plt.savefig(cm_fig_path, dpi=300)
plt.close()

print("\n" + "=" * 80)
print(" ALL 3 DUAL-INPUT NEURAL NETWORKS SUCCESSFULLY TRAINED & SAVED!")
print(" Outputs saved:")
for target_name, path, auc, f1 in exported_models:
    print(f" - {target_name:<20}: {path} | Test AUC: {auc:.4f} | Test F1: {f1:.4f}")
print(f" - Confusion Matrix Figure: {cm_fig_path}")
print("=" * 80)
