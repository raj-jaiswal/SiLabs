#!/usr/bin/env python3
"""
create_random_int8_model.py
----------------------------
Instantly creates, quantizes, and exports a 100% Pure INT8 TensorFlow Lite (.tflite) model
with random weights without training.
Input: (1, 600, 19) int8_t
Output: (1, 1) int8_t mapped to probability score from 0 to 99.
"""

import os
import json
import numpy as np
import tensorflow as tf
from tensorflow import keras

MODEL_OUTPUT_DIR = "models_int8"
os.makedirs(MODEL_OUTPUT_DIR, exist_ok=True)
print(f"[Init] Target directory initialized: {MODEL_OUTPUT_DIR}")

# 19 Features mapping (9 base vitals + 10 engineered features)
features = [
    'Solar8000/HR', 'Solar8000/ART_SBP', 'Solar8000/ART_DBP', 'Solar8000/ART_MBP',
    'Solar8000/PLETH_SPO2', 'Solar8000/RR_CO2', 'Solar8000/ETCO2', 'Primus/FIO2', 'Solar8000/BT',
    'Feature_Pulse_Pressure', 'Feature_Shock_Index', 'Feature_Modified_Shock_Index',
    'Feature_Rate_Pressure_Product', 'Feature_HR_Mean_60s', 'Feature_HR_Std_60s',
    'Feature_HR_Delta_60s', 'Feature_MBP_Mean_60s', 'Feature_MBP_Std_60s', 'Feature_MBP_Delta_60s'
]

WINDOW_SIZE = 600
NUM_FEATURES = len(features)

# Define Keras Model with use_bias=False across all layers
inputs = keras.Input(shape=(WINDOW_SIZE, NUM_FEATURES), dtype=tf.float32)
x = keras.layers.Conv1D(16, 5, strides=2, padding='same', use_bias=False, activation='relu')(inputs)
x = keras.layers.MaxPool1D(2)(x)
x = keras.layers.Conv1D(32, 5, strides=2, padding='same', use_bias=False, activation='relu')(x)
x = keras.layers.MaxPool1D(2)(x)
x = keras.layers.Conv1D(32, 5, strides=2, padding='same', use_bias=False, activation='relu')(x)
x = keras.layers.GlobalAveragePooling1D()(x)
outputs = keras.layers.Dense(1, activation='sigmoid', use_bias=False)(x)

model = keras.Model(inputs=inputs, outputs=outputs)
print("\n[Architecture] Zero-Bias Model Summary:")
model.summary()

# FULL INT8 TFLite Converter Configuration
print("\n[Quantization] Converting model to 100% Pure INT8 TFLite format...")

def representative_dataset_gen():
    for _ in range(100):
        sample_int8 = np.random.randint(-128, 127, (1, WINDOW_SIZE, NUM_FEATURES)).astype(np.float32)
        yield [sample_int8]

converter = tf.lite.TFLiteConverter.from_keras_model(model)
converter.optimizations = [tf.lite.Optimize.DEFAULT]
converter.representative_dataset = representative_dataset_gen
converter.target_spec.supported_ops = [tf.lite.OpsSet.TFLITE_BUILTINS_INT8]
converter.inference_input_type = tf.int8
converter.inference_output_type = tf.int8

tflite_model_binary = converter.convert()

output_tflite_path = os.path.join(MODEL_OUTPUT_DIR, "cnn_int8_random_model.tflite")
with open(output_tflite_path, "wb") as f:
    f.write(tflite_model_binary)

file_size_kb = len(tflite_model_binary) / 1024.0
print(f"✓ Successfully exported Pure INT8 TFLite model: {output_tflite_path} ({file_size_kb:.2f} KB)")

# Verification
interpreter = tf.lite.Interpreter(model_path=output_tflite_path)
interpreter.allocate_tensors()

inp_details = interpreter.get_input_details()[0]
out_details = interpreter.get_output_details()[0]

print("\n" + "=" * 75)
print(" VERIFIED MODEL TENSORS:")
print(f"  • Input Tensor  : {inp_details['name']:<35} | Shape: {inp_details['shape']} | Dtype: {inp_details['dtype']}")
print(f"  • Output Tensor : {out_details['name']:<35} | Shape: {out_details['shape']} | Dtype: {out_details['dtype']}")
print("=" * 75)

assert inp_details['dtype'] == np.int8, f"Input is {inp_details['dtype']}, expected int8!"
assert out_details['dtype'] == np.int8, f"Output is {out_details['dtype']}, expected int8!"
print("✓ ASSERTION PASSED: 100% Pure INT8 Input & Output Tensors!")

print("\n" + "=" * 75)
print(" SAMPLE INFERENCE TEST (0 to 99 Probability Output):")
print("=" * 75)

for run_idx in range(1, 6):
    random_window_int8 = np.random.randint(-128, 127, (1, 600, 19), dtype=np.int8)
    interpreter.set_tensor(inp_details['index'], random_window_int8)
    interpreter.invoke()
    
    raw_out_int8 = interpreter.get_tensor(out_details['index'])[0][0]
    prob_0_to_99 = int(round(((float(raw_out_int8) + 128.0) / 255.0) * 99.0))
    
    print(f" Run #{run_idx}: Raw INT8 Output = {raw_out_int8:<4} | Scaled Probability = {prob_0_to_99}% (0 to 99)")
print("=" * 75)
