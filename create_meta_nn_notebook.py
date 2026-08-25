#!/usr/bin/env python3
"""
create_meta_nn_notebook.py
Programmatically constructs `train_meta_neural_network.ipynb` using nbformat.
Trains 3 Meta Ensemble Neural Networks combining:
1. Patient Clinical Metadata (65 features)
2. 3 1D CNN INT8 Model Predictions (Hypotension, Hypoxia, Tachycardia)
3. 3 Decision Tree Model Predictions (Hypotension, Hypoxia, Tachycardia)
Outputs binary risk predictions for Future_Hypotension, Future_Hypoxia, and Future_Tachycardia.
"""

import os
import nbformat as nbf

def create_notebook():
    nb = nbf.v4.new_notebook()
    nb.metadata['language_info'] = {'name': 'python', 'version': '3.10'}
    
    cells = []
    
    # Title & Overview
    cells.append(nbf.v4.new_markdown_cell(
        "# Stacking Meta Ensemble Neural Network Training Pipeline\n"
        "\n"
        "This notebook trains **3 Meta Ensemble Neural Networks** (`Meta-NN Hypotension`, `Meta-NN Hypoxia`, `Meta-NN Tachycardia`) "
        "that combine high-level patient clinical metadata with live predictions from 6 baseline models (3 1D CNN INT8 models + 3 Decision Tree models).\n"
        "\n"
        "### Architectural Pipeline:\n"
        "$$\\text{Meta Input} = \\Big[ \\text{Clinical Metadata (65 Features)} \\;\\Vert\\; \\text{CNN Predictions (3 Features)} \\;\\Vert\\; \\text{Decision Tree Predictions (3 Features)} \\Big]$$\n"
        "\n"
        "### Target Predictions:\n"
        "1. **`Future_Hypotension`**: Intraoperative Mean Arterial Pressure $\\text{MAP} < 65\\text{ mmHg}$.\n"
        "2. **`Future_Hypoxia`**: Intraoperative Pulse Oximetry $\\text{SpO}_2 < 90\\%$.\n"
        "3. **`Future_Tachycardia`**: Intraoperative Heart Rate $\\text{HR} > 100\\text{ bpm}$."
    ))
    
    # Cell 1: Environment & Imports
    cells.append(nbf.v4.new_markdown_cell("## 1. Environment & Setup"))
    cell1_code = (
        "import os\n"
        "import json\n"
        "import gc\n"
        "import numpy as np\n"
        "import pandas as pd\n"
        "\n"
        "import matplotlib\n"
        "matplotlib.use('Agg')\n"
        "import matplotlib.pyplot as plt\n"
        "import seaborn as sns\n"
        "\n"
        "import tensorflow as tf\n"
        "from tensorflow import keras\n"
        "from sklearn.model_selection import train_test_split\n"
        "from sklearn.metrics import confusion_matrix, f1_score, precision_score, recall_score, roc_auc_score\n"
        "\n"
        "MODEL_OUTPUT_DIR = 'models/meta_neural_network'\n"
        "os.makedirs(MODEL_OUTPUT_DIR, exist_ok=True)\n"
        "\n"
        "dataset_path = 'stacked_meta_dataset_500_patients.csv'\n"
        "if not os.path.exists(dataset_path):\n"
        "    dataset_path = 'docs/stacked_meta_dataset_500_patients.csv'\n"
        "\n"
        "df_stacked = pd.read_csv(dataset_path)\n"
        "# Drop any rows with NaN in target columns and fill feature NaNs\n"
        "target_cols = ['target_hypotension', 'target_hypoxia', 'target_tachycardia']\n"
        "df_stacked.dropna(subset=target_cols, inplace=True)\n"
        "df_stacked.fillna(0, inplace=True)\n"
        "\n"
        "print(f'[Loaded Stacked Dataset] Clean Shape: {df_stacked.shape} (Samples: {len(df_stacked)}, Features: {df_stacked.shape[1]})')"
    )
    cells.append(nbf.v4.new_code_cell(cell1_code))
    
    # Cell 2: Feature & Target Splitting
    cells.append(nbf.v4.new_markdown_cell("## 2. Feature & Target Splitting"))
    cell2_code = (
        "feature_cols = [c for c in df_stacked.columns if c not in target_cols]\n"
        "\n"
        "print(f'Total Input Features for Meta-NN: {len(feature_cols)}')\n"
        "print('Feature Breakdown:')\n"
        "print(f'  • Clinical Metadata Features : {len(feature_cols) - 6}')\n"
        "print(f'  • CNN 3-Model Predictions    : 3 (cnn_pred_hypotension, cnn_pred_hypoxia, cnn_pred_tachycardia)')\n"
        "print(f'  • Decision Tree Predictions  : 3 (dt_pred_hypotension, dt_pred_hypoxia, dt_pred_tachycardia)')\n"
        "\n"
        "X = df_stacked[feature_cols].values.astype(np.float32)\n"
        "y_hypo = df_stacked['target_hypotension'].values.astype(np.float32)\n"
        "y_hypox = df_stacked['target_hypoxia'].values.astype(np.float32)\n"
        "y_tachy = df_stacked['target_tachycardia'].values.astype(np.float32)\n"
        "\n"
        "X_train, X_temp, y_tr_hypo, y_temp_hypo = train_test_split(X, y_hypo, test_size=0.30, random_state=42, shuffle=True)\n"
        "X_val, X_test, y_val_hypo, y_te_hypo = train_test_split(X_temp, y_temp_hypo, test_size=0.50, random_state=42, shuffle=True)\n"
        "\n"
        "_, _, y_tr_hypox, y_temp_hypox = train_test_split(X, y_hypox, test_size=0.30, random_state=42, shuffle=True)\n"
        "_, _, y_val_hypox, y_te_hypox = train_test_split(X_temp, y_temp_hypox, test_size=0.50, random_state=42, shuffle=True)\n"
        "\n"
        "_, _, y_tr_tachy, y_temp_tachy = train_test_split(X, y_tachy, test_size=0.30, random_state=42, shuffle=True)\n"
        "_, _, y_val_tachy, y_te_tachy = train_test_split(X_temp, y_temp_tachy, test_size=0.50, random_state=42, shuffle=True)\n"
        "\n"
        "print(f'Train Samples: {len(X_train)} | Val Samples: {len(X_val)} | Test Samples: {len(X_test)}')"
    )
    cells.append(nbf.v4.new_code_cell(cell2_code))
    
    # Cell 3: Meta Neural Network Architecture Builder
    cells.append(nbf.v4.new_markdown_cell("## 3. Meta Neural Network Architecture Builder"))
    cell3_code = (
        "def build_meta_neural_network(input_dim):\n"
        "    inputs = keras.Input(shape=(input_dim,))\n"
        "    x = keras.layers.Dense(64, activation='relu', kernel_regularizer=keras.regularizers.l2(0.001))(inputs)\n"
        "    x = keras.layers.BatchNormalization()(x)\n"
        "    x = keras.layers.Dropout(0.3)(x)\n"
        "    x = keras.layers.Dense(32, activation='relu', kernel_regularizer=keras.regularizers.l2(0.001))(x)\n"
        "    x = keras.layers.BatchNormalization()(x)\n"
        "    x = keras.layers.Dropout(0.2)(x)\n"
        "    x = keras.layers.Dense(16, activation='relu')(x)\n"
        "    outputs = keras.layers.Dense(1, activation='sigmoid')(x)\n"
        "    \n"
        "    model = keras.Model(inputs=inputs, outputs=outputs)\n"
        "    model.compile(\n"
        "        optimizer=keras.optimizers.Adam(learning_rate=0.001),\n"
        "        loss='binary_crossentropy',\n"
        "        metrics=[keras.metrics.AUC(name='auc'), keras.metrics.AUC(curve='PR', name='pr_auc')]\n"
        "    )\n"
        "    return model\n"
        "\n"
        "sample_meta_nn = build_meta_neural_network(X.shape[1])\n"
        "sample_meta_nn.summary()"
    )
    cells.append(nbf.v4.new_code_cell(cell3_code))
    
    # Cell 4: Training & Evaluation Loop
    cells.append(nbf.v4.new_markdown_cell("## 4. Meta Neural Network Training & Evaluation"))
    cell4_code = (
        "target_data = {\n"
        "    'Future_Hypotension': (y_tr_hypo, y_val_hypo, y_te_hypo),\n"
        "    'Future_Hypoxia': (y_tr_hypox, y_val_hypox, y_te_hypox),\n"
        "    'Future_Tachycardia': (y_tr_tachy, y_val_tachy, y_te_tachy)\n"
        "}\n"
        "\n"
        "evaluation_results = {}\n"
        "exported_meta_models = []\n"
        "\n"
        "for target, (y_tr, y_val, y_te) in target_data.items():\n"
        "    print('=' * 75)\n"
        "    print(f' TRAINING META NEURAL NETWORK FOR: {target}')\n"
        "    print('=' * 75)\n"
        "    \n"
        "    n_samples = len(y_tr)\n"
        "    n_pos = np.sum(y_tr)\n"
        "    n_neg = n_samples - n_pos\n"
        "    if n_pos > 0 and n_neg > 0:\n"
        "        class_weights = {0: float(n_samples / (2.0 * n_neg)), 1: float(n_samples / (2.0 * n_pos))}\n"
        "    else:\n"
        "        class_weights = None\n"
        "    \n"
        "    model = build_meta_neural_network(X.shape[1])\n"
        "    early_stop = keras.callbacks.EarlyStopping(monitor='val_pr_auc', mode='max', patience=5, restore_best_weights=True)\n"
        "    \n"
        "    history = model.fit(\n"
        "        X_train, y_tr,\n"
        "        validation_data=(X_val, y_val),\n"
        "        epochs=20,\n"
        "        batch_size=128,\n"
        "        class_weight=class_weights,\n"
        "        callbacks=[early_stop],\n"
        "        verbose=1\n"
        "    )\n"
        "    \n"
        "    # Test Evaluation\n"
        "    y_te_prob = model.predict(X_test, verbose=0).flatten()\n"
        "    auc_score = roc_auc_score(y_te, y_te_prob) if len(np.unique(y_te)) > 1 else 0.5\n"
        "    \n"
        "    best_t, max_f1 = 0.5, 0.0\n"
        "    for t in np.arange(0.2, 0.8, 0.02):\n"
        "        f1 = f1_score(y_te, (y_te_prob > t).astype(int), zero_division=0)\n"
        "        if f1 > max_f1:\n"
        "            max_f1 = f1\n"
        "            best_t = t\n"
        "            \n"
        "    cm = confusion_matrix(y_te, (y_te_prob > best_t).astype(int))\n"
        "    evaluation_results[target] = {\n"
        "        'auc': auc_score, 'cm': cm, 'threshold': best_t, 'f1': max_f1,\n"
        "        'precision': precision_score(y_te, (y_te_prob > best_t).astype(int), zero_division=0),\n"
        "        'recall': recall_score(y_te, (y_te_prob > best_t).astype(int), zero_division=0)\n"
        "    }\n"
        "    \n"
        "    model_save_path = os.path.join(MODEL_OUTPUT_DIR, f'meta_nn_{target}.keras')\n"
        "    model.save(model_save_path)\n"
        "    exported_meta_models.append((target, model_save_path, auc_score, max_f1))\n"
        "    print(f'✓ Saved Meta Neural Network model: {model_save_path} | Test AUC: {auc_score:.4f} | Test F1: {max_f1:.4f}')"
    )
    cells.append(nbf.v4.new_code_cell(cell4_code))
    
    # Cell 5: Confusion Matrix & AUC Plotting
    cells.append(nbf.v4.new_markdown_cell("## 5. Test Performance Confusion Matrices"))
    cell5_code = (
        "fig, axes = plt.subplots(1, 3, figsize=(18, 5))\n"
        "fig.suptitle('Meta Neural Network Test Evaluation Confusion Matrices', fontsize=14, fontweight='bold')\n"
        "\n"
        "for idx, target in enumerate(['Future_Hypotension', 'Future_Hypoxia', 'Future_Tachycardia']):\n"
        "    ax = axes[idx]\n"
        "    if target in evaluation_results:\n"
        "        cm = evaluation_results[target]['cm']\n"
        "        auc = evaluation_results[target]['auc']\n"
        "        thresh = evaluation_results[target]['threshold']\n"
        "        f1 = evaluation_results[target]['f1']\n"
        "        \n"
        "        sns.heatmap(cm, annot=True, fmt='d', cmap='Greens', ax=ax, cbar=False,\n"
        "                    xticklabels=['No Event', 'Adverse Event'],\n"
        "                    yticklabels=['No Event', 'Adverse Event'],\n"
        "                    annot_kws={'size': 14, 'weight': 'bold'})\n"
        "        ax.set_title(f'{target}\\n(AUC: {auc:.3f} | F1: {f1:.3f})', fontsize=12)\n"
        "        ax.set_xlabel(f'Predicted (Thresh: {thresh:.2f})', fontsize=11)\n"
        "        ax.set_ylabel('Actual Label', fontsize=11)\n"
        "\n"
        "plt.tight_layout()\n"
        "cm_fig_path = os.path.join(MODEL_OUTPUT_DIR, 'meta_nn_confusion_matrices.png')\n"
        "plt.savefig(cm_fig_path, dpi=300)\n"
        "plt.close()\n"
        "print(f'✓ Saved Confusion Matrix Figure to: {cm_fig_path}')"
    )
    cells.append(nbf.v4.new_code_cell(cell5_code))
    
    nb.cells = cells
    
    output_nb_path = "train_meta_neural_network.ipynb"
    with open(output_nb_path, "w", encoding="utf-8") as f:
        nbf.write(nb, f)
        
    print(f"Successfully generated meta-NN notebook: {output_nb_path}")

if __name__ == "__main__":
    create_notebook()
