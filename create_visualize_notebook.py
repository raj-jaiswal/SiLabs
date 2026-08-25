#!/usr/bin/env python3
"""
create_visualize_notebook.py
Programmatically constructs CNN/models_int8/visualize_tflite_model.ipynb using nbformat.
"""

import os
import nbformat as nbf

def create_notebook():
    nb = nbf.v4.new_notebook()
    nb.metadata['language_info'] = {'name': 'python', 'version': '3.10'}
    
    cells = []
    
    # Markdown Title
    cells.append(nbf.v4.new_markdown_cell(
        "# TFLite INT8 Model Visualizer & Inspector\n"
        "\n"
        "This notebook parses, inspects, and visualizes TensorFlow Lite (`.tflite`) model architectures, "
        "tensor shapes, data types (`int8`/`int32`), quantization parameters (scale and zero-point), and renders "
        "a visual architecture diagram."
    ))
    
    # Cell 1: Environment & Setup
    cells.append(nbf.v4.new_markdown_cell("## 1. Import Libraries & Configure Setup"))
    cell1_code = (
        "import os\n"
        "import sys\n"
        "import numpy as np\n"
        "import matplotlib.pyplot as plt\n"
        "import tensorflow as tf\n"
        "\n"
        "# Path to target INT8 TFLite model\n"
        "MODEL_PATH = 'cnn_int8_Future_Hypotension.tflite'\n"
        "if not os.path.exists(MODEL_PATH):\n"
        "    MODEL_PATH = 'CNN/models_int8/cnn_int8_Future_Hypotension.tflite'\n"
        "\n"
        "print(f'[Visualizer] Ready to inspect: {MODEL_PATH}')"
    )
    cells.append(nbf.v4.new_code_cell(cell1_code))
    
    # Cell 2: TFLite Model Loading & Input/Output Inspection
    cells.append(nbf.v4.new_markdown_cell("## 2. Input & Output Tensor Inspection"))
    cell2_code = (
        "interpreter = tf.lite.Interpreter(model_path=MODEL_PATH)\n"
        "interpreter.allocate_tensors()\n"
        "\n"
        "input_details = interpreter.get_input_details()\n"
        "output_details = interpreter.get_output_details()\n"
        "\n"
        "print('=' * 75)\n"
        "print('INPUT TENSORS:')\n"
        "for inp in input_details:\n"
        "    print(f\"  • Name        : {inp['name']}\")\n"
        "    print(f\"  • Shape       : {inp['shape']}\")\n"
        "    print(f\"  • Data Type   : {inp['dtype']}\")\n"
        "    print(f\"  • Scale       : {inp['quantization_parameters']['scales']}\")\n"
        "    print(f\"  • Zero Point  : {inp['quantization_parameters']['zero_points']}\")\n"
        "\n"
        "print('\\n' + '=' * 75)\n"
        "print('OUTPUT TENSORS:')\n"
        "for out in output_details:\n"
        "    print(f\"  • Name        : {out['name']}\")\n"
        "    print(f\"  • Shape       : {out['shape']}\")\n"
        "    print(f\"  • Data Type   : {out['dtype']}\")\n"
        "    print(f\"  • Scale       : {out['quantization_parameters']['scales']}\")\n"
        "    print(f\"  • Zero Point  : {out['quantization_parameters']['zero_points']}\")\n"
        "print('=' * 75)"
    )
    cells.append(nbf.v4.new_code_cell(cell2_code))
    
    # Cell 3: Complete Tensor Map Table
    cells.append(nbf.v4.new_markdown_cell("## 3. Complete Internal Tensor Map Table"))
    cell3_code = (
        "tensor_details = interpreter.get_tensor_details()\n"
        "print(f\"{'ID':<4} | {'Tensor Name':<55} | {'Shape':<15} | {'Dtype':<15}\")\n"
        "print('-' * 95)\n"
        "\n"
        "for detail in tensor_details:\n"
        "    tid = detail['index']\n"
        "    name = detail['name']\n"
        "    shape = str(detail['shape'])\n"
        "    dtype = str(detail['dtype']).replace(\"<class 'numpy.\", \"\").replace(\"'>\", \"\")\n"
        "    print(f\"{tid:<4} | {name:<55} | {shape:<15} | {dtype:<15}\")"
    )
    cells.append(nbf.v4.new_code_cell(cell3_code))
    
    # Cell 4: Flowchart Diagram Visualization
    cells.append(nbf.v4.new_markdown_cell("## 4. Visual Architecture Flowchart Diagram"))
    cell4_code = (
        "fig, ax = plt.subplots(figsize=(10, 10))\n"
        "ax.axis('off')\n"
        "ax.set_title('INT8 1D CNN Model Architecture Flowchart\\n(cnn_int8_Future_Hypotension.tflite)', fontsize=14, fontweight='bold', pad=20)\n"
        "\n"
        "layer_names = [\n"
        "    ('Input Tensor', '[1, 600, 19]', 'int8', '#e3f2fd'),\n"
        "    ('Conv1D Layer #1\\n(16 Filters, Kernel 5, Stride 2)', '[1, 300, 16]', 'int8', '#bbdefb'),\n"
        "    ('MaxPool1D Layer #1\\n(Pool Size 2, Stride 2)', '[1, 150, 16]', 'int8', '#90caf9'),\n"
        "    ('Conv1D Layer #2\\n(32 Filters, Kernel 5, Stride 2)', '[1, 75, 32]', 'int8', '#64b5f6'),\n"
        "    ('MaxPool1D Layer #2\\n(Pool Size 2, Stride 2)', '[1, 37, 32]', 'int8', '#42a5f5'),\n"
        "    ('Conv1D Layer #3\\n(32 Filters, Kernel 5, Stride 2)', '[1, 19, 32]', 'int8', '#2196f3'),\n"
        "    ('Global Average Pooling', '[1, 32]', 'int8', '#1e88e5'),\n"
        "    ('Fully Connected Dense Output\\n(Sigmoid Risk Score)', '[1, 1]', 'int8', '#1565c0')\n"
        "]\n"
        "\n"
        "y_pos = np.linspace(0.9, 0.1, len(layer_names))\n"
        "x_pos = 0.5\n"
        "\n"
        "for i, (title, shape, dtype, color) in enumerate(layer_names):\n"
        "    box_text = f\"{title}\\nShape: {shape} | Type: {dtype}\"\n"
        "    ax.text(x_pos, y_pos[i], box_text, ha='center', va='center', fontsize=10, fontweight='bold',\n"
        "            bbox=dict(boxstyle='round,pad=0.6', facecolor=color, edgecolor='#0d47a1', lw=2),\n"
        "            color='white' if i >= 4 else 'black')\n"
        "    \n"
        "    if i < len(layer_names) - 1:\n"
        "        ax.annotate('', xy=(x_pos, y_pos[i+1] + 0.04), xytext=(x_pos, y_pos[i] - 0.04),\n"
        "                    arrowprops=dict(arrowstyle='->', lw=2.5, color='#0d47a1'))\n"
        "\n"
        "plt.tight_layout()\n"
        "output_plot = 'cnn_int8_Hypotension_architecture.png'\n"
        "plt.savefig(output_plot, dpi=300, bbox_inches='tight')\n"
        "plt.show()\n"
        "print(f'[Visualizer] Saved diagram to: {output_plot}')"
    )
    cells.append(nbf.v4.new_code_cell(cell4_code))
    
    nb.cells = cells
    
    output_notebook = "CNN/models_int8/visualize_tflite_model.ipynb"
    with open(output_notebook, "w", encoding="utf-8") as f:
        nbf.write(nb, f)
        
    print(f"Successfully created notebook: {output_notebook}")

if __name__ == "__main__":
    create_notebook()
