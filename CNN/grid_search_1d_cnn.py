import os
import glob
import json
import gc
import numpy as np
import pandas as pd
import tensorflow as tf
from tensorflow import keras
from sklearn.model_selection import train_test_split, GridSearchCV, StratifiedKFold
from sklearn.utils.class_weight import compute_class_weight
from sklearn.metrics import f1_score, make_scorer
from sklearn.base import BaseEstimator, ClassifierMixin

# Check GPU
gpus = tf.config.list_physical_devices('GPU')
print("Num GPUs Available: ", len(gpus))
if gpus:
    try:
        for gpu in gpus:
            tf.config.experimental.set_memory_growth(gpu, True)
        print("GPU memory growth and optimization enabled!")
    except RuntimeError as e:
        print(e)

# --- Config ---
WINDOW_SIZE = 600
STRIDE = 10  # Use a larger stride for grid search to reduce memory and speed up
EPOCHS_GS = 5  # Smaller number of epochs for fast grid search

# Resolving paths
base_dir = os.path.dirname(os.getcwd())
if os.path.exists(os.path.join(os.getcwd(), "patient_labeled_data")):
    input_dir = os.path.join(os.getcwd(), "patient_labeled_data")
elif os.path.exists(os.path.join(os.getcwd(), "..", "patient_labeled_data")):
    input_dir = os.path.join(os.getcwd(), "..", "patient_labeled_data")
else:
    input_dir = "../patient_labeled_data"

csv_files = sorted(glob.glob(os.path.join(input_dir, "patient_*_1hz.csv")))

base_features = [
    "Solar8000/HR", "Solar8000/ART_SBP", "Solar8000/ART_DBP", "Solar8000/ART_MBP",
    "Solar8000/PLETH_SPO2", "Solar8000/RR_CO2", "Solar8000/ETCO2", "Primus/FIO2", "Solar8000/BT"
]
engineered_features = [
    "Feature_Pulse_Pressure", "Feature_Shock_Index", "Feature_Modified_Shock_Index",
    "Feature_Rate_Pressure_Product", "Feature_HR_Mean_60s", "Feature_HR_Std_60s",
    "Feature_HR_Delta_60s", "Feature_MBP_Mean_60s", "Feature_MBP_Std_60s", "Feature_MBP_Delta_60s"
]
features = base_features + engineered_features

print(f"Total CSV Files: {len(csv_files)}")
train_val_files, test_files = train_test_split(csv_files, test_size=0.20, random_state=42, shuffle=True)
train_files, val_files = train_test_split(train_val_files, test_size=0.125, random_state=42, shuffle=True)

# VERY small subset for grid search
MAX_TRAIN_GS = 15

class WindowDataGenerator(keras.utils.Sequence):
    def __init__(self, file_list, target_col, features, batch_size=64, window_size=600, stride=5, shuffle=True):
        self.batch_size = batch_size
        self.window_size = window_size
        self.stride = stride
        self.shuffle = shuffle
        self.X_data = []
        self.y_data = []
        self.window_indices = []
        
        print(f"Pre-loading raw CSVs into memory for {target_col}...")
        for file_idx, file in enumerate(file_list):
            try:
                df = pd.read_csv(file)
                avail_features = [c for c in features if c in df.columns]
                if len(avail_features) < len(features) or target_col not in df.columns:
                    continue
                
                df_sub = df[avail_features + [target_col]].ffill().bfill().fillna(0)
                arr = df_sub[avail_features].values.astype(np.float32)
                y_vals = df_sub[target_col].values.astype(np.float32)
                
                self.X_data.append(arr)
                self.y_data.append(y_vals)
                
                for i in range(0, len(arr) - window_size, stride):
                    if not np.isnan(y_vals[i + window_size - 1]):
                        self.window_indices.append((file_idx, i))
                        
            except Exception as e:
                continue
                
        self.indices = np.arange(len(self.window_indices))
        if self.shuffle:
            np.random.shuffle(self.indices)
            
    def __len__(self):
        return int(np.ceil(len(self.window_indices) / self.batch_size))
        
    def __getitem__(self, idx):
        batch_inds = self.indices[idx * self.batch_size : (idx + 1) * self.batch_size]
        X_batch = np.empty((len(batch_inds), self.window_size, len(features)), dtype=np.float32)
        y_batch = np.empty((len(batch_inds),), dtype=np.float32)
        
        for i, b_idx in enumerate(batch_inds):
            file_idx, start = self.window_indices[b_idx]
            X_batch[i] = self.X_data[file_idx][start : start + self.window_size]
            y_batch[i] = self.y_data[file_idx][start + self.window_size - 1]
            
        return X_batch, y_batch
        
    def get_all_data(self):
        X_all = np.empty((len(self.window_indices), self.window_size, len(features)), dtype=np.float32)
        y_all = np.empty(len(self.window_indices), dtype=np.float32)
        for i, w_idx in enumerate(self.window_indices):
            file_idx, start = w_idx
            X_all[i] = self.X_data[file_idx][start : start + self.window_size]
            y_all[i] = self.y_data[file_idx][start + self.window_size - 1]
        return X_all, y_all

# --- Global Scaler ---
print("[Global] Computing single Normalizer (Mean/Variance) for all 19 features...")
scaler_data = []
for file in train_files[:MAX_TRAIN_GS]:
    try:
        df = pd.read_csv(file)
        avail = [c for c in features if c in df.columns]
        if len(avail) == len(features):
            scaler_data.append(df[features].ffill().bfill().fillna(0).values.astype(np.float32))
    except:
        continue
if scaler_data:
    stacked = np.vstack(scaler_data)
    global_mean = np.mean(stacked, axis=0)
    global_variance = np.var(stacked, axis=0)
else:
    print("Failed to compute scaler data. Aborting.")
    exit(1)


def get_compiled_model(learning_rate=0.0005, filters_1=16, filters_2=32, kernel_size=3, dropout_rate=0.5):
    inputs = keras.Input(shape=(WINDOW_SIZE, len(features)))
    
    norm_layer = keras.layers.Normalization(mean=global_mean, variance=global_variance)
    x = norm_layer(inputs)
    
    # Simple CNN, hardware friendly for EFR32
    x = keras.layers.Conv1D(filters=filters_1, kernel_size=kernel_size, strides=2, activation='relu', padding='same', kernel_regularizer=keras.regularizers.l2(0.001))(x)
    x = keras.layers.MaxPool1D(pool_size=2)(x)
    
    x = keras.layers.Conv1D(filters=filters_2, kernel_size=kernel_size, strides=2, activation='relu', padding='same', kernel_regularizer=keras.regularizers.l2(0.001))(x)
    x = keras.layers.MaxPool1D(pool_size=2)(x)
    
    x = keras.layers.Conv1D(filters=filters_2, kernel_size=kernel_size, strides=2, activation='relu', padding='same', kernel_regularizer=keras.regularizers.l2(0.001))(x)
    
    x = keras.layers.GlobalAveragePooling1D()(x)
    x = keras.layers.Dropout(dropout_rate)(x)
    
    outputs = keras.layers.Dense(1, activation='sigmoid')(x)
    
    model = keras.Model(inputs=inputs, outputs=outputs)
    model.compile(optimizer=keras.optimizers.Adam(learning_rate=learning_rate), 
                  loss='binary_crossentropy', 
                  metrics=[keras.metrics.AUC(name='auc')])
    return model


class KerasGridSearchWrapper(BaseEstimator, ClassifierMixin):
    def __init__(self, learning_rate=0.0005, filters_1=16, filters_2=32, kernel_size=3, dropout_rate=0.5, batch_size=128):
        self.learning_rate = learning_rate
        self.filters_1 = filters_1
        self.filters_2 = filters_2
        self.kernel_size = kernel_size
        self.dropout_rate = dropout_rate
        self.batch_size = batch_size
        self.model_ = None
        self.classes_ = None

    def fit(self, X, y):
        self.classes_ = np.unique(y)
        self.model_ = get_compiled_model(
            learning_rate=self.learning_rate, 
            filters_1=self.filters_1, 
            filters_2=self.filters_2, 
            kernel_size=self.kernel_size, 
            dropout_rate=self.dropout_rate
        )
        # Handle class imbalance
        weights = compute_class_weight('balanced', classes=self.classes_, y=y)
        class_weights = dict(zip(self.classes_, weights))
        
        self.model_.fit(X, y, epochs=EPOCHS_GS, batch_size=self.batch_size, class_weight=class_weights, verbose=0)
        return self

    def predict(self, X):
        return (self.model_.predict(X, verbose=0) > 0.5).astype(int).flatten()

    def predict_proba(self, X):
        probs = self.model_.predict(X, verbose=0)
        return np.hstack([1 - probs, probs])


targets = ["Future_Hypotension", "Future_Hypoxia", "Future_Tachycardia"]

# Grid search parameter space (kept small for demonstration/speed, but tunable)
param_grid = {
    'learning_rate': [0.001, 0.0005],
    'filters_1': [8, 16],
    'filters_2': [16, 32],
    'kernel_size': [3, 5],
    'dropout_rate': [0.3, 0.5],
    'batch_size': [128, 256]
}

# We will score using F1 to account for class imbalance where negatives are more than positives
f1_scorer = make_scorer(f1_score)

print("\n=======================================================")
print(" STARTING GRID SEARCH FOR ALL TARGETS")
print("=======================================================\n")

best_params_per_target = {}

for target in targets:
    print("=" * 60)
    print(f" EXTRACTING DATA & RUNNING GRID SEARCH FOR: {target}")
    print("=" * 60)
    
    # Use a small subset (15 files) with a large stride (stride=10) to generate a manageable dataset for GS
    gen = WindowDataGenerator(train_files[:MAX_TRAIN_GS], target, features, batch_size=128, window_size=WINDOW_SIZE, stride=STRIDE, shuffle=False)
    
    if len(gen) == 0:
        print(f"No valid data found for {target}. Skipping...")
        continue
    
    X_all, y_all = gen.get_all_data()
    print(f"Extracted {len(y_all)} windows for Grid Search on {target}.")
    
    # Free generator memory
    del gen
    gc.collect()

    if len(np.unique(y_all)) < 2:
        print(f"Only 1 class found for {target} in this small subset. Skipping Grid Search...")
        continue

    # Stratified K-Fold to maintain class distribution in splits
    cv = StratifiedKFold(n_splits=3, shuffle=True, random_state=42)
    
    model_wrapper = KerasGridSearchWrapper()
    
    grid = GridSearchCV(estimator=model_wrapper, 
                        param_grid=param_grid, 
                        scoring=f1_scorer, 
                        cv=cv, 
                        verbose=2, 
                        n_jobs=1) # n_jobs=1 because TF doesn't always play nice with multiprocessing
    
    print(f"Starting Grid Search CV for {target}...")
    grid_result = grid.fit(X_all, y_all)
    
    print(f"\n--- Best Hyperparameters for {target} ---")
    print(f"Best Score (F1): {grid_result.best_score_:.4f}")
    print(f"Best Params: {grid_result.best_params_}\n")
    
    best_params_per_target[target] = grid_result.best_params_
    
    del X_all, y_all, grid_result, grid
    gc.collect()

print("=" * 60)
print(" GRID SEARCH COMPLETE")
print("=" * 60)
print("Best Hyperparameters summary:")
for target, params in best_params_per_target.items():
    print(f"\n{target}:")
    for k, v in params.items():
        print(f"  {k}: {v}")
