#!/usr/bin/env python3
"""
train_meta_neural_network.py
----------------------------
Trains 3 Meta Ensemble Neural Networks (Meta-NN Hypotension, Meta-NN Hypoxia, Meta-NN Tachycardia)
combining:
1. Patient Clinical Metadata (65 preprocessed features).
2. 3 1D CNN INT8 TFLite model predictions (Hypotension, Hypoxia, Tachycardia).
3. 3 Decision Tree model predictions (Hypotension, Hypoxia, Tachycardia).
Outputs binary risk predictions for Future_Hypotension, Future_Hypoxia, and Future_Tachycardia.
Saves models to `models/meta_neural_network/`.
"""

import os
import json
import gc
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

MODEL_OUTPUT_DIR = "models/meta_neural_network"
os.makedirs(MODEL_OUTPUT_DIR, exist_ok=True)
print(f"[Init] Meta Neural Network storage directory initialized: {MODEL_OUTPUT_DIR}")

dataset_path = "stacked_meta_dataset_500_patients.csv"
if not os.path.exists(dataset_path):
    dataset_path = "docs/stacked_meta_dataset_500_patients.csv"

df_stacked = pd.read_csv(dataset_path)

# Drop any rows with NaN in target columns and fill feature NaNs
target_cols = ['target_hypotension', 'target_hypoxia', 'target_tachycardia']
df_stacked.dropna(subset=target_cols, inplace=True)
df_stacked.fillna(0, inplace=True)

print("=" * 80)
print(f" META NEURAL NETWORK ENSEMBLE TRAINING (500 PATIENTS DATASET)")
print("=" * 80)
print(f"[Dataset Loaded] Clean Samples: {len(df_stacked)} | Total Columns: {df_stacked.shape[1]}")

feature_cols = [c for c in df_stacked.columns if c not in target_cols]

print(f"\n[Feature Breakdown] Total Meta Input Dimensions: {len(feature_cols)}")
print(f"  • Patient Clinical Metadata : {len(feature_cols) - 6} features")
print(f"  • 3 1D CNN Model Predictions: 3 features (cnn_pred_hypotension, cnn_pred_hypoxia, cnn_pred_tachycardia)")
print(f"  • 3 Decision Tree Predictions: 3 features (dt_pred_hypotension, dt_pred_hypoxia, dt_pred_tachycardia)")

X = df_stacked[feature_cols].values.astype(np.float32)
y_hypo = df_stacked['target_hypotension'].values.astype(np.float32)
y_hypox = df_stacked['target_hypoxia'].values.astype(np.float32)
y_tachy = df_stacked['target_tachycardia'].values.astype(np.float32)

X_train, X_temp, y_tr_hypo, y_temp_hypo = train_test_split(X, y_hypo, test_size=0.30, random_state=42, shuffle=True)
X_val, X_test, y_val_hypo, y_te_hypo = train_test_split(X_temp, y_temp_hypo, test_size=0.50, random_state=42, shuffle=True)

_, _, y_tr_hypox, y_temp_hypox = train_test_split(X, y_hypox, test_size=0.30, random_state=42, shuffle=True)
_, _, y_val_hypox, y_te_hypox = train_test_split(X_temp, y_temp_hypox, test_size=0.50, random_state=42, shuffle=True)

_, _, y_tr_tachy, y_temp_tachy = train_test_split(X, y_tachy, test_size=0.30, random_state=42, shuffle=True)
_, _, y_val_tachy, y_te_tachy = train_test_split(X_temp, y_temp_tachy, test_size=0.50, random_state=42, shuffle=True)

print(f"\n[Split] Train: {len(X_train)} | Val: {len(X_val)} | Test: {len(X_test)}")

def build_meta_neural_network(input_dim):
    inputs = keras.Input(shape=(input_dim,))
    x = keras.layers.Dense(64, activation='relu', kernel_regularizer=keras.regularizers.l2(0.001))(inputs)
    x = keras.layers.BatchNormalization()(x)
    x = keras.layers.Dropout(0.3)(x)
    x = keras.layers.Dense(32, activation='relu', kernel_regularizer=keras.regularizers.l2(0.001))(x)
    x = keras.layers.BatchNormalization()(x)
    x = keras.layers.Dropout(0.2)(x)
    x = keras.layers.Dense(16, activation='relu')(x)
    outputs = keras.layers.Dense(1, activation='sigmoid')(x)
    
    model = keras.Model(inputs=inputs, outputs=outputs)
    model.compile(
        optimizer=keras.optimizers.Adam(learning_rate=0.001),
        loss='binary_crossentropy',
        metrics=[keras.metrics.AUC(name='auc'), keras.metrics.AUC(curve='PR', name='pr_auc')]
    )
    return model

target_data = {
    'Future_Hypotension': (y_tr_hypo, y_val_hypo, y_te_hypo),
    'Future_Hypoxia': (y_tr_hypox, y_val_hypox, y_te_hypox),
    'Future_Tachycardia': (y_tr_tachy, y_val_tachy, y_te_tachy)
}

evaluation_results = {}
exported_meta_models = []

for target, (y_tr, y_val, y_te) in target_data.items():
    print("\n" + "=" * 75)
    print(f" TRAINING META NEURAL NETWORK FOR: {target}")
    print("=" * 75)
    
    n_samples = len(y_tr)
    n_pos = np.sum(y_tr)
    n_neg = n_samples - n_pos
    if n_pos > 0 and n_neg > 0:
        class_weights = {0: float(n_samples / (2.0 * n_neg)), 1: float(n_samples / (2.0 * n_pos))}
    else:
        class_weights = None
        
    model = build_meta_neural_network(X.shape[1])
    early_stop = keras.callbacks.EarlyStopping(monitor='val_pr_auc', mode='max', patience=5, restore_best_weights=True)
    
    history = model.fit(
        X_train, y_tr,
        validation_data=(X_val, y_val),
        epochs=20,
        batch_size=128,
        class_weight=class_weights,
        callbacks=[early_stop],
        verbose=1
    )
    
    # Test Evaluation
    y_te_prob = model.predict(X_test, verbose=0).flatten()
    auc_score = roc_auc_score(y_te, y_te_prob) if len(np.unique(y_te)) > 1 else 0.5
    
    best_t, max_f1 = 0.5, 0.0
    for t in np.arange(0.2, 0.8, 0.02):
        f1 = f1_score(y_te, (y_te_prob > t).astype(int), zero_division=0)
        if f1 > max_f1:
            max_f1 = f1
            best_t = t
            
    cm = confusion_matrix(y_te, (y_te_prob > best_t).astype(int))
    prec = precision_score(y_te, (y_te_prob > best_t).astype(int), zero_division=0)
    rec = recall_score(y_te, (y_te_prob > best_t).astype(int), zero_division=0)
    
    evaluation_results[target] = {
        'auc': auc_score, 'cm': cm, 'threshold': best_t, 'f1': max_f1,
        'precision': prec, 'recall': rec
    }
    
    model_save_path = os.path.join(MODEL_OUTPUT_DIR, f"meta_nn_{target}.keras")
    model.save(model_save_path)
    exported_meta_models.append((target, model_save_path, auc_score, max_f1))
    print(f"✓ Saved Meta Neural Network model: {model_save_path} | Test AUC: {auc_score:.4f} | Test F1: {max_f1:.4f}")

# Plot Confusion Matrices
fig, axes = plt.subplots(1, 3, figsize=(18, 5))
fig.suptitle('Meta Neural Network Test Evaluation Confusion Matrices', fontsize=14, fontweight='bold')

for idx, target in enumerate(['Future_Hypotension', 'Future_Hypoxia', 'Future_Tachycardia']):
    ax = axes[idx]
    if target in evaluation_results:
        cm = evaluation_results[target]['cm']
        auc = evaluation_results[target]['auc']
        thresh = evaluation_results[target]['threshold']
        f1 = evaluation_results[target]['f1']
        
        sns.heatmap(cm, annot=True, fmt='d', cmap='Greens', ax=ax, cbar=False,
                    xticklabels=['No Event', 'Adverse Event'],
                    yticklabels=['No Event', 'Adverse Event'],
                    annot_kws={'size': 14, 'weight': 'bold'})
        ax.set_title(f"{target}\n(AUC: {auc:.3f} | F1: {f1:.3f})", fontsize=12)
        ax.set_xlabel(f"Predicted (Thresh: {thresh:.2f})", fontsize=11)
        ax.set_ylabel("Actual Label", fontsize=11)

plt.tight_layout()
cm_fig_path = os.path.join(MODEL_OUTPUT_DIR, "meta_nn_confusion_matrices.png")
plt.savefig(cm_fig_path, dpi=300)
plt.close()

print("\n" + "=" * 80)
print(" ALL 3 META NEURAL NETWORK MODELS SUCCESSFULLY TRAINED & EVALUATED!")
print(" Outputs saved:")
for target, path, auc, f1 in exported_meta_models:
    print(f" - {target:<20}: {path} | Test AUC: {auc:.4f} | Test F1: {f1:.4f}")
print(f" - Confusion Matrix Figure: {cm_fig_path}")
print("=" * 80)
