#!/usr/bin/env python3
"""
predict_meta_ensemble.py
------------------------
Takes a patient telemetry CSV and preprocessed clinical metadata vector as input,
runs inference across:
  - 3 1D CNN INT8 TFLite models
  - 3 Decision Tree models
  - Preprocessed Patient Clinical Metadata
and feeds the 71-dimensional stacked feature vector into the 3 Meta Ensemble Neural Network models.
Outputs the final probabilities and risk flags for Hypotension, Hypoxia, and Tachycardia.
"""

import os
import json
import re
import joblib
import numpy as np
import pandas as pd
import tensorflow as tf
from tensorflow import keras

# Paths
base_dir = "/home/logan78/Desktop/SiLabs"
scaler_path = os.path.join(base_dir, "CNN/models_int8/scaler_1d_cnn_int8.json")
models_dir = os.path.join(base_dir, "CNN/models_int8")
dt_models_dir = os.path.join(base_dir, "models/decision_tree")
meta_nn_dir = os.path.join(base_dir, "models/meta_neural_network")
metadata_path = os.path.join(base_dir, "preprocessed_patient_metadata.csv")

def run_meta_ensemble_prediction(patient_csv_path, case_id=None):
    if not os.path.exists(patient_csv_path):
        print(f"Error: Patient CSV file not found at '{patient_csv_path}'")
        return
        
    # 1. Extract Case ID and Metadata
    if case_id is None:
        m = re.search(r'patient_(\d+)', os.path.basename(patient_csv_path))
        if m:
            case_id = int(m.group(1))
            
    df_meta = pd.read_csv(metadata_path)
    meta_cols = [c for c in df_meta.columns if c not in ['caseid', 'subjectid']]
    
    if case_id in df_meta['caseid'].values:
        meta_row = df_meta[df_meta['caseid'] == case_id].iloc[0]
        meta_vector = [meta_row[col] for col in meta_cols]
    else:
        print(f"Warning: Case ID {case_id} not in metadata. Using median default metadata.")
        meta_vector = df_meta[meta_cols].median().tolist()
        
    # 2. Load INT8 Scaler & Feature Config
    with open(scaler_path) as f:
        scaler_dict = json.load(f)
    cnn_features = scaler_dict['features']
    int8_scales = np.array([scaler_dict['int8_scale'][feat] for feat in cnn_features], dtype=np.float32)
    int8_zps = np.array([scaler_dict['int8_zero_point'][feat] for feat in cnn_features], dtype=np.int32)
    
    # 3. Load 3 INT8 CNN Interpreters
    targets = ["Future_Hypotension", "Future_Hypoxia", "Future_Tachycardia"]
    cnn_interpreters = {}
    cnn_input_details = {}
    cnn_output_details = {}
    for target in targets:
        model_p = os.path.join(models_dir, f"cnn_int8_{target}.tflite")
        interp = tf.lite.Interpreter(model_path=model_p)
        interp.allocate_tensors()
        cnn_interpreters[target] = interp
        cnn_input_details[target] = interp.get_input_details()[0]
        cnn_output_details[target] = interp.get_output_details()[0]
        
    # 4. Load 3 Decision Trees
    dt_models = {}
    for target in targets:
        dt_path = os.path.join(dt_models_dir, f"dt_{target}.joblib")
        dt_models[target] = joblib.load(dt_path)
        
    # 5. Load 3 Meta Neural Networks
    meta_nn_models = {}
    for target in targets:
        meta_path = os.path.join(meta_nn_dir, f"meta_nn_{target}.keras")
        meta_nn_models[target] = keras.models.load_model(meta_path)
        
    # 6. Read Patient Telemetry & Quantize Window
    df_p = pd.read_csv(patient_csv_path)
    df_sub = df_p[cnn_features].ffill().bfill().fillna(0)
    raw_vals = df_sub.values.astype(np.float32)
    
    q_vals = np.round((raw_vals / int8_scales) + int8_zps)
    arr_int8 = np.clip(q_vals, -128, 127).astype(np.int8)
    
    WINDOW_SIZE = 600
    if len(arr_int8) < WINDOW_SIZE:
        print(f"Error: Patient telemetry record has {len(arr_int8)} rows (< 600 required window size).")
        return
        
    # Take latest 600s window
    window_int8 = arr_int8[-WINDOW_SIZE:]
    window_raw = raw_vals[-WINDOW_SIZE:]
    
    # Run 3 CNN predictions
    cnn_input = np.expand_dims(window_int8, axis=0) # (1, 600, 19)
    cnn_preds = []
    for target in targets:
        interp = cnn_interpreters[target]
        interp.set_tensor(cnn_input_details[target]['index'], cnn_input)
        interp.invoke()
        raw_out = interp.get_tensor(cnn_output_details[target]['index'])[0][0]
        prob = (float(raw_out) + 128.0) / 255.0
        cnn_preds.append(prob)
        
    # Run 3 Decision Tree predictions (95 summary stats)
    w_mean = np.mean(window_raw, axis=0)
    w_std = np.std(window_raw, axis=0)
    w_min = np.min(window_raw, axis=0)
    w_max = np.max(window_raw, axis=0)
    w_delta = window_raw[-1] - window_raw[0]
    dt_input_95 = np.hstack([w_mean, w_std, w_min, w_max, w_delta]).reshape(1, -1)
    
    dt_preds = []
    for target in targets:
        dt_prob = dt_models[target].predict_proba(dt_input_95)[0][1]
        dt_preds.append(float(dt_prob))
        
    # Stack Meta Input Vector: [Clinical Metadata (65) + CNN (3) + DT (3)] = 71 Features
    meta_input_vector = np.array(meta_vector + cnn_preds + dt_preds, dtype=np.float32).reshape(1, -1)
    
    # Run Meta Neural Network Predictions
    results = {}
    for target in targets:
        prob = float(meta_nn_models[target].predict(meta_input_vector, verbose=0)[0][0])
        prob_0_to_99 = int(round(prob * 99.0))
        results[target] = (prob, prob_0_to_99)
        
    print("\n" + "=" * 80)
    print(f" META ENSEMBLE PREDICTION RESULTS FOR PATIENT: {os.path.basename(patient_csv_path)}")
    print("=" * 80)
    print(f"  • Case ID                 : {case_id}")
    print(f"  • Base CNN Predictions    : Hypo={cnn_preds[0]*100:.1f}%, Hypox={cnn_preds[1]*100:.1f}%, Tachy={cnn_preds[2]*100:.1f}%")
    print(f"  • Decision Tree Preds     : Hypo={dt_preds[0]*100:.1f}%, Hypox={dt_preds[1]*100:.1f}%, Tachy={dt_preds[2]*100:.1f}%")
    print("-" * 80)
    print(f"  ★ META-NN HYPOTENSION RISK: {results['Future_Hypotension'][1]}% probability ({results['Future_Hypotension'][0]:.4f})")
    print(f"  ★ META-NN HYPOXIA RISK    : {results['Future_Hypoxia'][1]}% probability ({results['Future_Hypoxia'][0]:.4f})")
    print(f"  ★ META-NN TACHYCARDIA RISK: {results['Future_Tachycardia'][1]}% probability ({results['Future_Tachycardia'][0]:.4f})")
    print("=" * 80)

if __name__ == "__main__":
    sample_patient = "/home/logan78/Desktop/SiLabs/process_labeled_data/patient_1_1hz.csv"
    run_meta_ensemble_prediction(sample_patient)
