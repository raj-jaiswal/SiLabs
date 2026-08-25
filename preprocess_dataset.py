#!/usr/bin/env python3
"""
preprocess_dataset.py
---------------------
Executes the dataset analysis, cleaning, median/mode imputation, one-hot encoding,
and standard scaling pipeline on the VitalDB clinical metadata (3,764 patients x 74 features).
Saves figures to `docs/metadata_eda_figures/` and preprocessed datasets to `preprocessed_patient_metadata.csv`.
"""

import os
import json
import numpy as np
import pandas as pd

import matplotlib
matplotlib.use('Agg')
import matplotlib.pyplot as plt
import seaborn as sns

from sklearn.preprocessing import StandardScaler
from sklearn.impute import SimpleImputer

FIG_DIR = "docs/metadata_eda_figures"
os.makedirs(FIG_DIR, exist_ok=True)

metadata_path = "patient_metadata.csv"
if not os.path.exists(metadata_path):
    print(f"Error: File not found at '{metadata_path}'")
    exit(1)

df_raw = pd.read_csv(metadata_path)
print("=" * 80)
print(f" CLINICAL METADATA PREPROCESSING PIPELINE (VitalDB)")
print("=" * 80)
print(f"[Dataset Loaded] Total Patients: {len(df_raw)} | Original Features: {df_raw.shape[1]}")

# 1. Missingness Profile Analysis
missing_counts = df_raw.isnull().sum()
missing_pct = (missing_counts / len(df_raw)) * 100
missing_df = pd.DataFrame({'Missing_Count': missing_counts, 'Missing_Pct': missing_pct})
missing_df = missing_df[missing_df['Missing_Count'] > 0].sort_values(by='Missing_Pct', ascending=False)

print("\n[1] Top 10 Features with Missing Values:")
print(missing_df.head(10))

# Figure 1: Missingness Bar Plot
plt.figure(figsize=(14, 6))
sns.barplot(x=missing_df.index[:25], y=missing_df['Missing_Pct'][:25], palette='Reds_r')
plt.xticks(rotation=75, ha='right', fontsize=9)
plt.ylabel('Missing Percentage (%)', fontsize=11, fontweight='bold')
plt.title('Figure 1: Missing Data Profile Across Clinical Features (VitalDB)', fontsize=13, fontweight='bold', pad=15)
plt.tight_layout()
fig1_path = os.path.join(FIG_DIR, 'fig01_missingness_profile.png')
plt.savefig(fig1_path, dpi=300)
plt.close()
print(f"✓ Saved Figure 1 to: {fig1_path}")

# Figure 2: Demographic Distributions by Gender
fig, axes = plt.subplots(2, 2, figsize=(14, 10))
fig.suptitle('Figure 2: Patient Demographic Distributions by Gender', fontsize=14, fontweight='bold')

sns.histplot(data=df_raw, x='age', hue='sex', kde=True, ax=axes[0,0], palette='Set1', bins=30)
axes[0,0].set_title('Age Distribution (Years)', fontweight='bold')

sns.histplot(data=df_raw, x='bmi', hue='sex', kde=True, ax=axes[0,1], palette='Set1', bins=30)
axes[0,1].set_title('BMI Distribution (kg/m²)', fontweight='bold')
axes[0,1].set_xlim(10, 50)

sns.histplot(data=df_raw, x='height', hue='sex', kde=True, ax=axes[1,0], palette='Set1', bins=30)
axes[1,0].set_title('Height Distribution (cm)', fontweight='bold')

sns.histplot(data=df_raw, x='weight', hue='sex', kde=True, ax=axes[1,1], palette='Set1', bins=30)
axes[1,1].set_title('Weight Distribution (kg)', fontweight='bold')

plt.tight_layout()
fig2_path = os.path.join(FIG_DIR, 'fig02_demographics_distribution.png')
plt.savefig(fig2_path, dpi=300)
plt.close()
print(f"✓ Saved Figure 2 to: {fig2_path}")

# Figure 3: ASA Score vs ICU Length of Stay & In-Hospital Mortality
fig, axes = plt.subplots(1, 2, figsize=(14, 5))
fig.suptitle('Figure 3: ASA Score vs ICU Length of Stay & In-Hospital Mortality', fontsize=14, fontweight='bold')

sns.boxplot(data=df_raw, x='asa', y='icu_days', ax=axes[0], palette='Blues')
axes[0].set_title('ICU Days by ASA Score', fontweight='bold')
axes[0].set_yscale('symlog')
axes[0].set_ylabel('ICU Days (Symlog Scale)')

mortality_by_asa = df_raw.groupby('asa')['death_inhosp'].mean() * 100
sns.barplot(x=mortality_by_asa.index, y=mortality_by_asa.values, ax=axes[1], palette='Reds')
axes[1].set_title('In-Hospital Mortality Rate by ASA Score (%)', fontweight='bold')
axes[1].set_ylabel('Mortality Rate (%)')

plt.tight_layout()
fig3_path = os.path.join(FIG_DIR, 'fig03_asa_mortality_icu.png')
plt.savefig(fig3_path, dpi=300)
plt.close()
print(f"✓ Saved Figure 3 to: {fig3_path}")

# Figure 4: Correlation Matrix Heatmap
numeric_cols = df_raw.select_dtypes(include=[np.number]).columns
key_cols = ['age', 'height', 'weight', 'bmi', 'asa', 'preop_hb', 'preop_plt', 'preop_cr', 'intraop_ebl', 'intraop_uo', 'icu_days', 'death_inhosp']
avail_key = [c for c in key_cols if c in numeric_cols]

plt.figure(figsize=(10, 8))
corr_matrix = df_raw[avail_key].corr()
sns.heatmap(corr_matrix, annot=True, fmt='.2f', cmap='coolwarm', vmin=-1, vmax=1, linewidths=0.5)
plt.title('Figure 4: Correlation Matrix of Key Clinical & Lab Parameters', fontsize=13, fontweight='bold', pad=15)
plt.tight_layout()
fig4_path = os.path.join(FIG_DIR, 'fig04_clinical_feature_correlation.png')
plt.savefig(fig4_path, dpi=300)
plt.close()
print(f"✓ Saved Figure 4 to: {fig4_path}")

# --- Data Cleaning & Preprocessing Pipeline ---
print("\n[2] Executing Data Cleaning & Imputation Pipeline...")
df_clean = df_raw.copy()

# 1. Drop features with >90% missingness
cols_to_drop = missing_df[missing_df['Missing_Pct'] > 90.0].index.tolist()
df_clean.drop(columns=cols_to_drop, inplace=True)
print(f"  • Dropped {len(cols_to_drop)} sparse features (>90% missingness): {cols_to_drop[:5]}...")

# 2. Separate Numerical vs Categorical Columns
num_cols = df_clean.select_dtypes(include=[np.number]).columns.tolist()
cat_cols = df_clean.select_dtypes(include=['object']).columns.tolist()

if 'caseid' in num_cols:
    num_cols.remove('caseid')
if 'subjectid' in num_cols:
    num_cols.remove('subjectid')

# 3. Median Imputation for Numerical Features
num_imputer = SimpleImputer(strategy='median')
df_clean[num_cols] = num_imputer.fit_transform(df_clean[num_cols])
print(f"  • Median Imputed {len(num_cols)} numerical features.")

# 4. Mode Imputation for Categorical Features
cat_imputer = SimpleImputer(strategy='most_frequent')
df_clean[cat_cols] = cat_imputer.fit_transform(df_clean[cat_cols])
print(f"  • Mode Imputed {len(cat_cols)} categorical features.")

# 5. One-Hot Encoding for Categorical Columns
df_processed = pd.get_dummies(df_clean, columns=cat_cols, drop_first=True)
print(f"  • One-Hot Encoded categorical variables. Processed shape: {df_processed.shape}")

# 6. Standard Scaler Normalization (Z-Score Scaling)
scaler = StandardScaler()
scaled_features = [c for c in num_cols if c not in ['death_inhosp', 'emop']]
df_processed[scaled_features] = scaler.fit_transform(df_processed[scaled_features])
print(f"  • Z-Score Normalized {len(scaled_features)} continuous numerical features.")

# 7. Save Cleaned & Preprocessed Output Files
out_csv = "preprocessed_patient_metadata.csv"
docs_csv = "docs/preprocessed_patient_metadata.csv"

df_processed.to_csv(out_csv, index=False)
df_processed.to_csv(docs_csv, index=False)

print("\n" + "=" * 80)
print(" PREPROCESSING PIPELINE COMPLETED SUCCESSFULLY!")
print(f"  • Main Output  : {out_csv} ({df_processed.shape[0]} rows x {df_processed.shape[1]} columns)")
print(f"  • Docs Copy    : {docs_csv}")
print("=" * 80)
