#!/usr/bin/env python3
"""
visualize_tflite_model.py
-------------------------
Visualizes the architecture, tensor shapes, quantization parameters (scales & zero points),
and graph structure of `/home/logan78/Desktop/SiLabs/CNN/models_int8/cnn_int8_Future_Hypotension.tflite`.
Saves a graphical flowchart diagram as `CNN/models_int8/cnn_int8_Hypotension_architecture.png`.
"""

import os
import sys
import numpy as np

# Set non-interactive Agg backend before importing pyplot
import matplotlib
matplotlib.use('Agg')
import matplotlib.pyplot as plt

import tensorflow as tf

def visualize_model(tflite_path):
    if not os.path.exists(tflite_path):
        print(f"Error: File not found at '{tflite_path}'")
        return

    print("=" * 80)
    print(f" TFLITE MODEL VISUALIZER: {tflite_path}")
    print("=" * 80)

    interpreter = tf.lite.Interpreter(model_path=tflite_path)
    interpreter.allocate_tensors()

    input_details = interpreter.get_input_details()
    output_details = interpreter.get_output_details()
    tensor_details = interpreter.get_tensor_details()

    print("\n[1] INPUT TENSOR DETAILS:")
    for inp in input_details:
        scale, zp = inp.get('quantization', (0.0, 0))
        print(f"  • Name        : {inp['name']}")
        print(f"  • Shape       : {inp['shape']}")
        print(f"  • Data Type   : {inp['dtype']}")
        print(f"  • Quant Scale : {inp['quantization_parameters']['scales']}")
        print(f"  • Zero Point  : {inp['quantization_parameters']['zero_points']}")

    print("\n[2] OUTPUT TENSOR DETAILS:")
    for out in output_details:
        print(f"  • Name        : {out['name']}")
        print(f"  • Shape       : {out['shape']}")
        print(f"  • Data Type   : {out['dtype']}")
        print(f"  • Quant Scale : {out['quantization_parameters']['scales']}")
        print(f"  • Zero Point  : {out['quantization_parameters']['zero_points']}")

    print("\n[3] COMPLETE TENSOR MAP:")
    print(f"{'ID':<4} | {'Tensor Name':<50} | {'Shape':<15} | {'Dtype':<15}")
    print("-" * 90)

    for detail in tensor_details:
        tid = detail['index']
        name = detail['name']
        shape = str(detail['shape'])
        dtype = str(detail['dtype']).replace("<class 'numpy.", "").replace("'>", "")
        print(f"{tid:<4} | {name:<50} | {shape:<15} | {dtype:<15}")

    # --- Draw Graphical Flowchart Diagram ---
    fig, ax = plt.subplots(figsize=(10, 10))
    ax.axis('off')
    ax.set_title("INT8 1D CNN Architecture\n(cnn_int8_Future_Hypotension.tflite)", fontsize=14, fontweight='bold', pad=20)

    layer_names = [
        ("Input Tensor", "[1, 600, 19]", "int8", "#e3f2fd"),
        ("Conv1D Layer #1\n(16 Filters, Kernel 5, Stride 2)", "[1, 300, 16]", "int8", "#bbdefb"),
        ("MaxPool1D Layer #1\n(Pool Size 2, Stride 2)", "[1, 150, 16]", "int8", "#90caf9"),
        ("Conv1D Layer #2\n(32 Filters, Kernel 5, Stride 2)", "[1, 75, 32]", "int8", "#64b5f6"),
        ("MaxPool1D Layer #2\n(Pool Size 2, Stride 2)", "[1, 37, 32]", "int8", "#42a5f5"),
        ("Conv1D Layer #3\n(32 Filters, Kernel 5, Stride 2)", "[1, 19, 32]", "int8", "#2196f3"),
        ("Global Average Pooling", "[1, 32]", "int8", "#1e88e5"),
        ("Fully Connected Dense Output\n(Sigmoid Risk Score)", "[1, 1]", "int8", "#1565c0")
    ]

    y_pos = np.linspace(0.9, 0.1, len(layer_names))
    x_pos = 0.5

    for i, (title, shape, dtype, color) in enumerate(layer_names):
        box_text = f"{title}\nShape: {shape} | Type: {dtype}"
        ax.text(x_pos, y_pos[i], box_text, ha='center', va='center', fontsize=10, fontweight='bold',
                bbox=dict(boxstyle='round,pad=0.6', facecolor=color, edgecolor='#0d47a1', lw=2),
                color='white' if i >= 4 else 'black')
        
        if i < len(layer_names) - 1:
            ax.annotate('', xy=(x_pos, y_pos[i+1] + 0.04), xytext=(x_pos, y_pos[i] - 0.04),
                        arrowprops=dict(arrowstyle='->', lw=2.5, color='#0d47a1'))

    output_plot_path = os.path.join(os.path.dirname(tflite_path), "cnn_int8_Hypotension_architecture.png")
    plt.tight_layout()
    plt.savefig(output_plot_path, dpi=300, bbox_inches='tight')
    plt.close()

    print("\n" + "=" * 80)
    print(f"✓ Saved visual architecture diagram to: {output_plot_path}")
    print("=" * 80)

if __name__ == "__main__":
    tflite_file = "CNN/models_int8/cnn_int8_Future_Hypotension.tflite"
    if len(sys.argv) > 1:
        tflite_file = sys.argv[1]
    visualize_model(tflite_file)
