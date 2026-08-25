#!/usr/bin/env python3
"""
preprocess_dataset.py
---------------------
Executes feature pruning (selecting 43 essential clinical parameters),
median/mode imputation, one-hot encoding, and Z-score standardization on VitalDB clinical metadata.
Output: `preprocessed_patient_metadata.csv` (3,764 rows x 58 clean columns).
"""

import os
import json
import numpy as np
import pandas as pd

from sklearn.preprocessing import StandardScaler
from sklearn.impute import SimpleImputer

metadata_path = "patient_metadata.csv"
if not os.path.exists(metadata_path):
    print(f"Error: File not found at '{metadata_path}'")
    exit(1)

df_raw = pd.read_csv(metadata_path)
print("=" * 80)
print(f" CLEAN CLINICAL METADATA PREPROCESSING PIPELINE (VitalDB)")
print("=" * 80)
print(f"[Dataset Loaded] Patients: {len(df_raw)} | Raw Columns: {df_raw.shape[1]}")

# Define 43 Essential Clinical Parameters (Demographics, Pre-op Labs, Airway, Intraop Fluids, Outcomes)
essential_cols = [
    'caseid', 'subjectid', 'age', 'sex', 'height', 'weight', 'bmi', 'asa', 'emop',
    'department', 'optype', 'ane_type', 'approach', 'position',
    'preop_htn', 'preop_dm', 'preop_hb', 'preop_plt', 'preop_pt', 'preop_aptt',
    'preop_na', 'preop_k', 'preop_gluc', 'preop_alb', 'preop_ast', 'preop_alt', 'preop_bun', 'preop_cr',
    'cormack', 'airway', 'tubesize',
    'intraop_ebl', 'intraop_uo', 'intraop_crystalloid', 'intraop_colloid', 'intraop_rbc', 'intraop_ffp',
    'intraop_eph', 'intraop_phe', 'intraop_epi', 'intraop_ca',
    'icu_days', 'death_inhosp'
]

avail_cols = [c for c in essential_cols if c in df_raw.columns]
df_pruned = df_raw[avail_cols].copy()

dropped_cols = [c for c in df_raw.columns if c not in avail_cols]
print(f"\n[1] Feature Selection & Pruning Complete:")
print(f"  • Reduced from {df_raw.shape[1]} raw columns down to {df_pruned.shape[1]} essential clinical columns.")
print(f"  • Dropped {len(dropped_cols)} unnecessary/sparse/text columns.")

num_cols = df_pruned.select_dtypes(include=[np.number]).columns.tolist()
cat_cols = df_pruned.select_dtypes(include=['object']).columns.tolist()

if 'caseid' in num_cols:
    num_cols.remove('caseid')
if 'subjectid' in num_cols:
    num_cols.remove('subjectid')

# 1. Median Imputation for Numerical Features
num_imputer = SimpleImputer(strategy='median')
df_pruned[num_cols] = num_imputer.fit_transform(df_pruned[num_cols])
print(f"\n[2] Imputation & Encoding Complete:")
print(f"  • Median Imputed {len(num_cols)} numerical features.")

# 2. Mode Imputation for Categorical Features
cat_imputer = SimpleImputer(strategy='most_frequent')
df_pruned[cat_cols] = cat_imputer.fit_transform(df_pruned[cat_cols])
print(f"  • Mode Imputed {len(cat_cols)} categorical features.")

# 3. One-Hot Encoding for Categorical Columns
df_processed = pd.get_dummies(df_pruned, columns=cat_cols, drop_first=True)
print(f"  • One-Hot Encoded categorical variables. Processed shape: {df_processed.shape}")

# 4. Standard Scaler Normalization (Z-Score Scaling)
scaler = StandardScaler()
scaled_features = [c for c in num_cols if c not in ['death_inhosp', 'emop']]
df_processed[scaled_features] = scaler.fit_transform(df_processed[scaled_features])
print(f"  • Z-Score Normalized {len(scaled_features)} continuous numerical features.")

# 5. Save Cleaned & Preprocessed Output CSV Files
out_csv = "preprocessed_patient_metadata.csv"
docs_csv = "docs/preprocessed_patient_metadata.csv"

df_processed.to_csv(out_csv, index=False)
df_processed.to_csv(docs_csv, index=False)

print("\n" + "=" * 80)
print(" PREPROCESSING PIPELINE COMPLETED SUCCESSFULLY!")
print(f"  • Clean Output CSV : {out_csv} ({df_processed.shape[0]} rows x {df_processed.shape[1]} columns)")
print(f"  • Docs Copy       : {docs_csv}")
print("=" * 80)
