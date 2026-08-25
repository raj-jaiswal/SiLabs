#!/usr/bin/env python3
"""
create_random_int8_notebook.py
Programmatically constructs CNN/create_random_int8_model.ipynb using nbformat.
Instantly exports a 100% Pure INT8 .tflite model with random weights that takes
shape (1, 600, 19) int8 inputs and outputs a probability score scaled from 0 to 99.
"""

import os
import nbformat as nbf

def create_notebook():
    nb = nbf.v4.new_notebook()
    nb.metadata['language_info'] = {'name': 'python', 'version': '3.10'}
    
    cells = []
    
    # Title & Overview
    cells.append(nbf.v4.new_markdown_cell(
        "# Instant Pure INT8 Random Model Generator (0 to 99 Probability Output)\n"
        "\n"
        "This notebook instantly creates, quantizes, and exports a 100% Pure INT8 TensorFlow Lite (`.tflite`) model "
        "without requiring long training sessions.\n"
        "\n"
        "### Technical Specifications:\n"
        "1. **Input Shape**: `[1, 600, 19]` with data type `int8_t` (`np.int8`).\n"
        "2. **Output Shape**: `[1, 1]` with data type `int8_t` (`np.int8`).\n"
        "3. **Zero Bias At All (`use_bias=False`)**: Guarantees zero int32 bias tensors in the model graph.\n"
        "4. **0 to 99 Probability Output**: Maps the raw `int8_t` output into an integer probability score from 0% to 99%."
    ))
    
    # Cell 1: Environment & Imports
    cells.append(nbf.v4.new_markdown_cell("## 1. Environment Setup & Imports"))
    cell1_code = (
        "import os\n"
        "import json\n"
        "import numpy as np\n"
        "import tensorflow as tf\n"
        "from tensorflow import keras\n"
        "\n"
        "MODEL_OUTPUT_DIR = 'models_int8'\n"
        "os.makedirs(MODEL_OUTPUT_DIR, exist_ok=True)\n"
        "print(f'[Init] Target directory initialized: {MODEL_OUTPUT_DIR}')"
    )
    cells.append(nbf.v4.new_code_cell(cell1_code))
    
    # Cell 2: Define Zero-Bias Architecture with Random Weights
    cells.append(nbf.v4.new_markdown_cell("## 2. Define Zero-Bias Architecture (`use_bias=False`)"))
    cell2_code = (
        "# 19 Features mapping (9 base vitals + 10 engineered features)\n"
        "features = [\n"
        "    'Solar8000/HR', 'Solar8000/ART_SBP', 'Solar8000/ART_DBP', 'Solar8000/ART_MBP',\n"
        "    'Solar8000/PLETH_SPO2', 'Solar8000/RR_CO2', 'Solar8000/ETCO2', 'Primus/FIO2', 'Solar8000/BT',\n"
        "    'Feature_Pulse_Pressure', 'Feature_Shock_Index', 'Feature_Modified_Shock_Index',\n"
        "    'Feature_Rate_Pressure_Product', 'Feature_HR_Mean_60s', 'Feature_HR_Std_60s',\n"
        "    'Feature_HR_Delta_60s', 'Feature_MBP_Mean_60s', 'Feature_MBP_Std_60s', 'Feature_MBP_Delta_60s'\n"
        "]\n"
        "\n"
        "WINDOW_SIZE = 600\n"
        "NUM_FEATURES = len(features)\n"
        "\n"
        "# Define Keras Model with use_bias=False across all layers\n"
        "inputs = keras.Input(shape=(WINDOW_SIZE, NUM_FEATURES), dtype=tf.float32)\n"
        "x = keras.layers.Conv1D(16, 5, strides=2, padding='same', use_bias=False, activation='relu')(inputs)\n"
        "x = keras.layers.MaxPool1D(2)(x)\n"
        "x = keras.layers.Conv1D(32, 5, strides=2, padding='same', use_bias=False, activation='relu')(x)\n"
        "x = keras.layers.MaxPool1D(2)(x)\n"
        "x = keras.layers.Conv1D(32, 5, strides=2, padding='same', use_bias=False, activation='relu')(x)\n"
        "x = keras.layers.GlobalAveragePooling1D()(x)\n"
        "outputs = keras.layers.Dense(1, activation='sigmoid', use_bias=False)(x)\n"
        "\n"
        "model = keras.Model(inputs=inputs, outputs=outputs)\n"
        "model.summary()"
    )
    cells.append(nbf.v4.new_code_cell(cell2_code))
    
    # Cell 3: Instant FULL INT8 Quantization & Export
    cells.append(nbf.v4.new_markdown_cell("## 3. Instant FULL INT8 Quantization & TFLite Export"))
    cell3_code = (
        "print('[Quantization] Converting model to 100% Pure INT8 TFLite format...')\n"
        "\n"
        "# Representative dataset generator yielding random synthetic int8-scaled inputs\n"
        "def representative_dataset_gen():\n"
        "    for _ in range(100):\n"
        "        # Random synthetic window in int8 range [-128, 127]\n"
        "        sample_int8 = np.random.randint(-128, 127, (1, WINDOW_SIZE, NUM_FEATURES)).astype(np.float32)\n"
        "        yield [sample_int8]\n"
        "\n"
        "converter = tf.lite.TFLiteConverter.from_keras_model(model)\n"
        "converter.optimizations = [tf.lite.Optimize.DEFAULT]\n"
        "converter.representative_dataset = representative_dataset_gen\n"
        "converter.target_spec.supported_ops = [tf.lite.OpsSet.TFLITE_BUILTINS_INT8]\n"
        "converter.inference_input_type = tf.int8\n"
        "converter.inference_output_type = tf.int8\n"
        "\n"
        "tflite_model_binary = converter.convert()\n"
        "\n"
        "output_tflite_path = os.path.join(MODEL_OUTPUT_DIR, 'cnn_int8_random_model.tflite')\n"
        "with open(output_tflite_path, 'wb') as f:\n"
        "    f.write(tflite_model_binary)\n"
        "\n"
        "file_size_kb = len(tflite_model_binary) / 1024.0\n"
        "print(f'✓ Successfully exported Pure INT8 TFLite model: {output_tflite_path} ({file_size_kb:.2f} KB)')"
    )
    cells.append(nbf.v4.new_code_cell(cell3_code))
    
    # Cell 4: Verification & 0..99 Probability Inference Test
    cells.append(nbf.v4.new_markdown_cell("## 4. Verification & Probability (0 to 99) Inference Test"))
    cell4_code = (
        "interpreter = tf.lite.Interpreter(model_path=output_tflite_path)\n"
        "interpreter.allocate_tensors()\n"
        "\n"
        "inp_details = interpreter.get_input_details()[0]\n"
        "out_details = interpreter.get_output_details()[0]\n"
        "\n"
        "print('=' * 75)\n"
        "print(' VERIFIED MODEL TENSORS:')\n"
        "print(f\"  • Input Tensor  : {inp_details['name']:<35} | Shape: {inp_details['shape']} | Dtype: {inp_details['dtype']}\")\n"
        "print(f\"  • Output Tensor : {out_details['name']:<35} | Shape: {out_details['shape']} | Dtype: {out_details['dtype']}\")\n"
        "print('=' * 75)\n"
        "\n"
        "assert inp_details['dtype'] == np.int8, f\"Input is {inp_details['dtype']}, expected int8!\"\n"
        "assert out_details['dtype'] == np.int8, f\"Output is {out_details['dtype']}, expected int8!\"\n"
        "print('✓ ASSERTION PASSED: 100% Pure INT8 Input & Output Tensors!')\n"
        "\n"
        "# Perform 5 sample inference runs mapping output to probability score from 0 to 99\n"
        "print('\\n' + '=' * 75)\n"
        "print(' SAMPLE INFERENCE TEST (0 to 99 Probability Output):')\n"
        "print('=' * 75)\n"
        "\n"
        "for run_idx in range(1, 6):\n"
        "    # Synthetic random int8 window (1, 600, 19)\n"
        "    random_window_int8 = np.random.randint(-128, 127, (1, 600, 19), dtype=np.int8)\n"
        "    interpreter.set_tensor(inp_details['index'], random_window_int8)\n"
        "    interpreter.invoke()\n"
        "    \n"
        "    raw_out_int8 = interpreter.get_tensor(out_details['index'])[0][0]\n"
        "    # Scale raw signed int8 (-128 to 127) to integer probability (0 to 99)\n"
        "    prob_0_to_99 = int(round(((float(raw_out_int8) + 128.0) / 255.0) * 99.0))\n"
        "    \n"
        "    print(f' Run #{run_idx}: Raw INT8 Output = {raw_out_int8:<4} | Scaled Probability = {prob_0_to_99}% (0 to 99)')\n"
        "print('=' * 75)"
    )
    cells.append(nbf.v4.new_code_cell(cell4_code))
    
    nb.cells = cells
    
    output_nb_path = "CNN/create_random_int8_model.ipynb"
    with open(output_nb_path, "w", encoding="utf-8") as f:
        nbf.write(nb, f)
        
    print(f"Successfully generated notebook: {output_nb_path}")

if __name__ == "__main__":
    create_notebook()
