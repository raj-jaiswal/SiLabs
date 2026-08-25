#!/usr/bin/env python3
"""
generate_stacked_meta_dataset.py
--------------------------------
Generates a combined multi-model stacked dataset across 500 patient records from `process_labeled_data`.
Integrates:
1. Patient Clinical Metadata (65 features from preprocessed_patient_metadata.csv).
2. 3 1D CNN INT8 TFLite predictions (cnn_pred_hypotension, cnn_pred_hypoxia, cnn_pred_tachycardia).
3. 3 Decision Tree predictions (dt_pred_hypotension, dt_pred_hypoxia, dt_pred_tachycardia).
Saves output to `stacked_meta_dataset_500_patients.csv`.
"""

import os
import glob
import json
import gc
import re
import joblib
import numpy as np
import pandas as pd
import tensorflow as tf

# Setup Paths
base_dir = "/home/logan78/Desktop/SiLabs"
input_dir = os.path.join(base_dir, "process_labeled_data")
metadata_path = os.path.join(base_dir, "preprocessed_patient_metadata.csv")
scaler_path = os.path.join(base_dir, "CNN/models_int8/scaler_1d_cnn_int8.json")
models_dir = os.path.join(base_dir, "CNN/models_int8")
dt_models_dir = os.path.join(base_dir, "models/decision_tree")

print("=" * 80)
print(" STACKED META DATASET GENERATOR (500 PATIENTS)")
print("=" * 80)

# 1. Load Clinical Metadata
df_meta = pd.read_csv(metadata_path)
print(f"[1] Loaded Preprocessed Clinical Metadata: {len(df_meta)} patients x {df_meta.shape[1]} columns")
meta_case_dict = df_meta.set_index('caseid').to_dict(orient='index')
meta_feature_names = [c for c in df_meta.columns if c not in ['caseid', 'subjectid']]

# 2. Load INT8 Scaler Parameters
with open(scaler_path) as f:
    scaler_dict = json.load(f)

cnn_features = scaler_dict['features']
int8_scales = np.array([scaler_dict['int8_scale'][feat] for feat in cnn_features], dtype=np.float32)
int8_zps = np.array([scaler_dict['int8_zero_point'][feat] for feat in cnn_features], dtype=np.int32)

# 3. Load 3 INT8 TFLite CNN Models
targets = ["Future_Hypotension", "Future_Hypoxia", "Future_Tachycardia"]
cnn_interpreters = {}
cnn_input_details = {}
cnn_output_details = {}

for target in targets:
    model_path = os.path.join(models_dir, f"cnn_int8_{target}.tflite")
    interp = tf.lite.Interpreter(model_path=model_path)
    interp.allocate_tensors()
    cnn_interpreters[target] = interp
    cnn_input_details[target] = interp.get_input_details()[0]
    cnn_output_details[target] = interp.get_output_details()[0]
print("✓ Loaded 3 INT8 CNN TFLite Models (Hypotension, Hypoxia, Tachycardia)")

# 4. Load 3 Decision Tree Models
dt_models = {}
for target in targets:
    dt_path = os.path.join(dt_models_dir, f"dt_{target}.joblib")
    dt_models[target] = joblib.load(dt_path)
print("✓ Loaded 3 Decision Tree Models (Hypotension, Hypoxia, Tachycardia)")

# 5. Process 500 Patient Files
patient_files = sorted(glob.glob(os.path.join(input_dir, "patient_*_1hz.csv")))[:500]
print(f"[2] Extracting sliding window stacked samples across {len(patient_files)} patient records...")

WINDOW_SIZE = 600
STRIDE = 60  # 60-second stride to capture high-resolution temporal dynamics
MAX_WINDOWS_PER_PATIENT = 50

stacked_rows = []

for file_idx, file_path in enumerate(patient_files):
    fname = os.path.basename(file_path)
    m = re.search(r'patient_(\d+)', fname)
    if not m:
        continue
    case_id = int(m.group(1))
    
    if case_id not in meta_case_dict:
        continue
        
    meta_row = meta_case_dict[case_id]
    meta_vector = [meta_row[col] for col in meta_feature_names]
    
    try:
        df_p = pd.read_csv(file_path)
        avail_cnn = [c for c in cnn_features if c in df_p.columns]
        if len(avail_cnn) < len(cnn_features):
            continue
            
        df_cnn_sub = df_p[avail_cnn].ffill().bfill().fillna(0)
        raw_vals = df_cnn_sub[cnn_features].values.astype(np.float32)
        
        # Quantize to INT8 (-128 to 127) for CNN
        q_vals = np.round((raw_vals / int8_scales) + int8_zps)
        arr_int8 = np.clip(q_vals, -128, 127).astype(np.int8)
        
        # Target columns
        y_hypo = df_p['Future_Hypotension'].values.astype(np.float32) if 'Future_Hypotension' in df_p.columns else np.zeros(len(df_p))
        y_hypox = df_p['Future_Hypoxia'].values.astype(np.float32) if 'Future_Hypoxia' in df_p.columns else np.zeros(len(df_p))
        y_tachy = df_p['Future_Tachycardia'].values.astype(np.float32) if 'Future_Tachycardia' in df_p.columns else np.zeros(len(df_p))
        
        patient_wins = 0
        for i in range(0, len(arr_int8) - WINDOW_SIZE, STRIDE):
            end_idx = i + WINDOW_SIZE - 1
            if np.isnan(y_hypo[end_idx]):
                continue
                
            # 1. Run CNN 3-Model Predictions
            cnn_input = np.expand_dims(arr_int8[i : i + WINDOW_SIZE], axis=0) # (1, 600, 19)
            cnn_preds = []
            for target in targets:
                interp = cnn_interpreters[target]
                interp.set_tensor(cnn_input_details[target]['index'], cnn_input)
                interp.invoke()
                raw_out = interp.get_tensor(cnn_output_details[target]['index'])[0][0]
                prob = ((float(raw_out) + 128.0) / 255.0) # Float probability [0.0, 1.0]
                cnn_preds.append(prob)
                
            # 2. Run Decision Tree 3-Model Predictions (95 Features: mean, std, min, max, delta)
            window_raw = raw_vals[i : i + WINDOW_SIZE]
            w_mean = np.mean(window_raw, axis=0)
            w_std = np.std(window_raw, axis=0)
            w_min = np.min(window_raw, axis=0)
            w_max = np.max(window_raw, axis=0)
            w_delta = window_raw[-1] - window_raw[0]
            
            dt_input_95 = np.hstack([w_mean, w_std, w_min, w_max, w_delta]).reshape(1, -1)
            
            dt_preds = []
            for target in targets:
                dt_m = dt_models[target]
                try:
                    dt_prob = dt_m.predict_proba(dt_input_95)[0][1]
                except Exception:
                    dt_prob = dt_m.predict(dt_input_95)[0]
                dt_preds.append(float(dt_prob))
                
            # 3. Form Combined Stacked Row
            row_data = meta_vector + cnn_preds + dt_preds + [
                float(y_hypo[end_idx]),
                float(y_hypox[end_idx]),
                float(y_tachy[end_idx])
            ]
            stacked_rows.append(row_data)
            patient_wins += 1
            if patient_wins >= MAX_WINDOWS_PER_PATIENT:
                break
                
    except Exception:
        continue
        
    if (file_idx + 1) % 50 == 0:
        print(f"  • Processed {file_idx + 1}/{len(patient_files)} patients -> Generated {len(stacked_rows)} stacked window samples")

print(f"\n[3] Total Stacked Dataset Samples Generated: {len(stacked_rows)}")

# Define Column Names for Stacked Dataset
column_names = meta_feature_names + [
    'cnn_pred_hypotension', 'cnn_pred_hypoxia', 'cnn_pred_tachycardia',
    'dt_pred_hypotension', 'dt_pred_hypoxia', 'dt_pred_tachycardia',
    'target_hypotension', 'target_hypoxia', 'target_tachycardia'
]

df_stacked = pd.DataFrame(stacked_rows, columns=column_names)

output_csv = "stacked_meta_dataset_500_patients.csv"
docs_csv = "docs/stacked_meta_dataset_500_patients.csv"

os.makedirs("docs", exist_ok=True)
df_stacked.to_csv(output_csv, index=False)
df_stacked.to_csv(docs_csv, index=False)

print("\n" + "=" * 80)
print(" STACKED META DATASET GENERATION COMPLETED!")
print(f"  • Output CSV  : {output_csv} ({df_stacked.shape[0]} rows x {df_stacked.shape[1]} columns)")
print(f"  • Docs Copy   : {docs_csv}")
print("=" * 80)
