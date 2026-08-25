#!/usr/bin/env python3
"""
predict_patient_1.py
--------------------
Reads `/home/logan78/Desktop/SiLabs/process_labeled_data/patient_1_1hz.csv`,
extracts 600-second sliding windows, applies StandardScaler + INT8 quantization mapping,
and runs live inference on all 3 INT8 TFLite models (`Future_Hypotension`, `Future_Hypoxia`, `Future_Tachycardia`).
"""

import os
import json
import numpy as np
import pandas as pd
import tensorflow as tf

csv_file = "/home/logan78/Desktop/SiLabs/process_labeled_data/patient_1_1hz.csv"
scaler_path = "/home/logan78/Desktop/SiLabs/CNN/models_int8/scaler_1d_cnn_int8.json"
models_dir = "/home/logan78/Desktop/SiLabs/CNN/models_int8"

if not os.path.exists(csv_file):
    print(f"Error: CSV file not found at '{csv_file}'")
    exit(1)

# Load Scaler Parameters
with open(scaler_path) as f:
    scaler_dict = json.load(f)

features = scaler_dict['features']
int8_scales = np.array([scaler_dict['int8_scale'][feat] for feat in features], dtype=np.float32)
int8_zps = np.array([scaler_dict['int8_zero_point'][feat] for feat in features], dtype=np.int32)

print(f"[Init] Reading patient record: {csv_file}")
df = pd.read_csv(csv_file)
print(f"[Init] Total rows in patient record: {len(df)} seconds")

# Extract and forward-fill feature columns
avail_features = [c for c in features if c in df.columns]
if len(avail_features) < len(features):
    print(f"Warning: Missing features. Available: {len(avail_features)}/{len(features)}")

df_features = df[avail_features].ffill().bfill().fillna(0)
raw_values = df_features.values.astype(np.float32)

# Quantize to INT8 (-128 to 127)
q_values = np.round((raw_values / int8_scales) + int8_zps)
int8_values = np.clip(q_values, -128, 127).astype(np.int8)

# Load TFLite Interpreters
targets = ["Future_Hypotension", "Future_Hypoxia", "Future_Tachycardia"]
interpreters = {}
input_details = {}
output_details = {}

for target in targets:
    model_path = os.path.join(models_dir, f"cnn_int8_{target}.tflite")
    interp = tf.lite.Interpreter(model_path=model_path)
    interp.allocate_tensors()
    interpreters[target] = interp
    input_details[target] = interp.get_input_details()[0]
    output_details[target] = interp.get_output_details()[0]

WINDOW_SIZE = 600
STRIDE = 120

print("\n" + "=" * 90)
print(f" LIVE INT8 WINDOW PREDICTIONS FOR: patient_1_1hz.csv")
print("=" * 90)
header_str = f"| {'Window Range':<18} | {'Hypotension (0..99%)':<22} | {'Hypoxia (0..99%)':<18} | {'Tachycardia (0..99%)':<20} |"
print(header_str)
print("-" * 90)

for start in range(0, len(int8_values) - WINDOW_SIZE, STRIDE):
    window = int8_values[start : start + WINDOW_SIZE]
    input_tensor = np.expand_dims(window, axis=0)  # Shape (1, 600, 19)
    
    results = {}
    for target in targets:
        interp = interpreters[target]
        inp_idx = input_details[target]['index']
        out_idx = output_details[target]['index']
        
        interp.set_tensor(inp_idx, input_tensor)
        interp.invoke()
        
        raw_out = interp.get_tensor(out_idx)[0][0]
        prob_0_to_99 = int(round(((float(raw_out) + 128.0) / 255.0) * 99.0))
        results[target] = (raw_out, prob_0_to_99)
        
    time_str = f"t={start}s to {start+WINDOW_SIZE}s"
    hypo_str = f"{results['Future_Hypotension'][1]}% (int8: {results['Future_Hypotension'][0]})"
    hypox_str = f"{results['Future_Hypoxia'][1]}% (int8: {results['Future_Hypoxia'][0]})"
    tachy_str = f"{results['Future_Tachycardia'][1]}% (int8: {results['Future_Tachycardia'][0]})"
    
    row_str = f"| {time_str:<18} | {hypo_str:<22} | {hypox_str:<18} | {tachy_str:<20} |"
    print(row_str)

print("=" * 90)
