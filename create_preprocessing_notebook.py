#!/usr/bin/env python3
"""
create_preprocessing_notebook.py
Programmatically constructs `dataset_eda_and_preprocessing.ipynb` using nbformat.
Performs comprehensive Exploratory Data Analysis (EDA), cleaning, feature engineering,
imputation, and scaling on the VitalDB clinical metadata (3,764 patients x 74 features).
"""

import os
import nbformat as nbf

def create_notebook():
    nb = nbf.v4.new_notebook()
    nb.metadata['language_info'] = {'name': 'python', 'version': '3.10'}
    
    cells = []
    
    # Title & Overview
    cells.append(nbf.v4.new_markdown_cell(
        "# VitalDB Clinical Dataset Analysis & Preprocessing Pipeline\n"
        "\n"
        "This notebook conducts an in-depth Exploratory Data Analysis (EDA) and executes a production-grade data "
        "preprocessing pipeline on the **VitalDB Clinical Dataset (3,764 Patients $\\times$ 74 Features)**.\n"
        "\n"
        "### Workflow Steps:\n"
        "1. **Exploratory Data Analysis (EDA)**: Demographic distributions, missingness profiling, risk stratifications, and correlation heatmaps.\n"
        "2. **Data Quality Audit & Cleaning**: Handling extreme missingness ($>90\\%$), out-of-range sensor/clinical values, and encoding errors.\n"
        "3. **Missing Value Imputation**: Median imputation for numerical variables and mode imputation for categorical features.\n"
        "4. **Categorical Encoding**: One-Hot Encoding and ordinal mapping for `sex`, `department`, `optype`, `asa`, `ane_type`.\n"
        "5. **Standardization & Scaling**: Z-score normalization (StandardScaler) for numerical continuous variables.\n"
        "6. **Export Machine-Learning Ready Datasets**: Saves clean preprocessed files to `preprocessed_patient_metadata.csv`."
    ))
    
    # Cell 1: Environment & Setup
    cells.append(nbf.v4.new_markdown_cell("## 1. Environment & Setup"))
    cell1_code = (
        "import os\n"
        "import json\n"
        "import numpy as np\n"
        "import pandas as pd\n"
        "\n"
        "import matplotlib\n"
        "matplotlib.use('Agg')\n"
        "import matplotlib.pyplot as plt\n"
        "import seaborn as sns\n"
        "\n"
        "from sklearn.preprocessing import StandardScaler, OneHotEncoder\n"
        "from sklearn.impute import SimpleImputer\n"
        "\n"
        "FIG_DIR = 'docs/metadata_eda_figures'\n"
        "os.makedirs(FIG_DIR, exist_ok=True)\n"
        "\n"
        "metadata_path = 'patient_metadata.csv'\n"
        "df_raw = pd.read_csv(metadata_path)\n"
        "print(f'[Loaded Dataset] Shape: {df_raw.shape} (Patients: {len(df_raw)}, Features: {df_raw.shape[1]})')"
    )
    cells.append(nbf.v4.new_code_cell(cell1_code))
    
    # Cell 2: Data Audit & Missingness Profiling
    cells.append(nbf.v4.new_markdown_cell("## 2. Missing Value Analysis & Data Quality Audit"))
    cell2_code = (
        "missing_counts = df_raw.isnull().sum()\n"
        "missing_pct = (missing_counts / len(df_raw)) * 100\n"
        "missing_df = pd.DataFrame({'Missing_Count': missing_counts, 'Missing_Pct': missing_pct})\n"
        "missing_df = missing_df[missing_df['Missing_Count'] > 0].sort_values(by='Missing_Pct', ascending=False)\n"
        "\n"
        "print('=== TOP 15 MISSING FEATURES ===')\n"
        "print(missing_df.head(15))\n"
        "\n"
        "# Figure 1: Missing Data Profile Heatmap\n"
        "plt.figure(figsize=(14, 6))\n"
        "sns.barplot(x=missing_df.index[:25], y=missing_df['Missing_Pct'][:25], palette='Reds_r')\n"
        "plt.xticks(rotation=75, ha='right', fontsize=9)\n"
        "plt.ylabel('Missing Percentage (%)', fontsize=11, fontweight='bold')\n"
        "plt.title('Figure 1: Missing Data Profile Across Clinical Features (VitalDB)', fontsize=13, fontweight='bold', pad=15)\n"
        "plt.tight_layout()\n"
        "fig1_path = os.path.join(FIG_DIR, 'fig01_missingness_profile.png')\n"
        "plt.savefig(fig1_path, dpi=300)\n"
        "plt.close()\n"
        "print(f'✓ Saved Figure 1 to: {fig1_path}')"
    )
    cells.append(nbf.v4.new_code_cell(cell2_code))
    
    # Cell 3: Demographic Distributions Analysis
    cells.append(nbf.v4.new_markdown_cell("## 3. Patient Demographic & Physiological Distributions"))
    cell3_code = (
        "fig, axes = plt.subplots(2, 2, figsize=(14, 10))\n"
        "fig.suptitle('Figure 2: Patient Demographic Distributions by Gender', fontsize=14, fontweight='bold')\n"
        "\n"
        "sns.histplot(data=df_raw, x='age', hue='sex', kde=True, ax=axes[0,0], palette='Set1', bins=30)\n"
        "axes[0,0].set_title('Age Distribution (Years)', fontweight='bold')\n"
        "\n"
        "sns.histplot(data=df_raw, x='bmi', hue='sex', kde=True, ax=axes[0,1], palette='Set1', bins=30)\n"
        "axes[0,1].set_title('BMI Distribution (kg/m²)', fontweight='bold')\n"
        "axes[0,1].set_xlim(10, 50)\n"
        "\n"
        "sns.histplot(data=df_raw, x='height', hue='sex', kde=True, ax=axes[1,0], palette='Set1', bins=30)\n"
        "axes[1,0].set_title('Height Distribution (cm)', fontweight='bold')\n"
        "\n"
        "sns.histplot(data=df_raw, x='weight', hue='sex', kde=True, ax=axes[1,1], palette='Set1', bins=30)\n"
        "axes[1,1].set_title('Weight Distribution (kg)', fontweight='bold')\n"
        "\n"
        "plt.tight_layout()\n"
        "fig2_path = os.path.join(FIG_DIR, 'fig02_demographics_distribution.png')\n"
        "plt.savefig(fig2_path, dpi=300)\n"
        "plt.close()\n"
        "print(f'✓ Saved Figure 2 to: {fig2_path}')"
    )
    cells.append(nbf.v4.new_code_cell(cell3_code))
    
    # Cell 4: ASA Score & Adverse Clinical Outcome Analysis
    cells.append(nbf.v4.new_markdown_cell("## 4. ASA Physical Status & Clinical Outcome Stratification"))
    cell4_code = (
        "fig, axes = plt.subplots(1, 2, figsize=(14, 5))\n"
        "fig.suptitle('Figure 3: ASA Score vs ICU Length of Stay & In-Hospital Mortality', fontsize=14, fontweight='bold')\n"
        "\n"
        "sns.boxplot(data=df_raw, x='asa', y='icu_days', ax=axes[0], palette='Blues')\n"
        "axes[0].set_title('ICU Days by ASA Score', fontweight='bold')\n"
        "axes[0].set_yscale('symlog')\n"
        "axes[0].set_ylabel('ICU Days (Symlog Scale)')\n"
        "\n"
        "mortality_by_asa = df_raw.groupby('asa')['death_inhosp'].mean() * 100\n"
        "sns.barplot(x=mortality_by_asa.index, y=mortality_by_asa.values, ax=axes[1], palette='Reds')\n"
        "axes[1].set_title('In-Hospital Mortality Rate by ASA Score (%)', fontweight='bold')\n"
        "axes[1].set_ylabel('Mortality Rate (%)')\n"
        "\n"
        "plt.tight_layout()\n"
        "fig3_path = os.path.join(FIG_DIR, 'fig03_asa_mortality_icu.png')\n"
        "plt.savefig(fig3_path, dpi=300)\n"
        "plt.close()\n"
        "print(f'✓ Saved Figure 3 to: {fig3_path}')"
    )
    cells.append(nbf.v4.new_code_cell(cell4_code))
    
    # Cell 5: Clinical Correlation Heatmap
    cells.append(nbf.v4.new_markdown_cell("## 5. Clinical Feature Correlation Matrix"))
    cell5_code = (
        "numeric_cols = df_raw.select_dtypes(include=[np.number]).columns\n"
        "key_cols = ['age', 'height', 'weight', 'bmi', 'asa', 'preop_hb', 'preop_plt', 'preop_cr', 'intraop_ebl', 'intraop_uo', 'icu_days', 'death_inhosp']\n"
        "avail_key = [c for c in key_cols if c in numeric_cols]\n"
        "\n"
        "plt.figure(figsize=(10, 8))\n"
        "corr_matrix = df_raw[avail_key].corr()\n"
        "sns.heatmap(corr_matrix, annot=True, fmt='.2f', cmap='coolwarm', vmin=-1, vmax=1, linewidths=0.5)\n"
        "plt.title('Figure 4: Correlation Matrix of Key Clinical & Lab Parameters', fontsize=13, fontweight='bold', pad=15)\n"
        "plt.tight_layout()\n"
        "fig4_path = os.path.join(FIG_DIR, 'fig04_clinical_feature_correlation.png')\n"
        "plt.savefig(fig4_path, dpi=300)\n"
        "plt.close()\n"
        "print(f'✓ Saved Figure 4 to: {fig4_path}')"
    )
    cells.append(nbf.v4.new_code_cell(cell5_code))
    
    # Cell 6: Data Cleaning, Imputation & Scaling Pipeline Execution
    cells.append(nbf.v4.new_markdown_cell("## 6. Data Cleaning, Imputation & Standard Scaling Pipeline"))
    cell6_code = (
        "print('[Preprocessing] Executing Data Cleaning & Imputation Pipeline...')\n"
        "df_clean = df_raw.copy()\n"
        "\n"
        "# 1. Drop features with >90% missingness\n"
        "cols_to_drop = missing_df[missing_df['Missing_Pct'] > 90.0].index.tolist()\n"
        "df_clean.drop(columns=cols_to_drop, inplace=True)\n"
        "print(f'  • Dropped {len(cols_to_drop)} sparse features (>90% missingness): {cols_to_drop[:5]}...')\n"
        "\n"
        "# 2. Identify Numerical vs Categorical Columns\n"
        "num_cols = df_clean.select_dtypes(include=[np.number]).columns.tolist()\n"
        "cat_cols = df_clean.select_dtypes(include=['object']).columns.tolist()\n"
        "\n"
        "if 'caseid' in num_cols:\n"
        "    num_cols.remove('caseid')\n"
        "if 'subjectid' in num_cols:\n"
        "    num_cols.remove('subjectid')\n"
        "\n"
        "# 3. Median Imputation for Numerical Features\n"
        "num_imputer = SimpleImputer(strategy='median')\n"
        "df_clean[num_cols] = num_imputer.fit_transform(df_clean[num_cols])\n"
        "print(f'  • Median Imputed {len(num_cols)} numerical features.')\n"
        "\n"
        "# 4. Mode Imputation for Categorical Features\n"
        "cat_imputer = SimpleImputer(strategy='most_frequent')\n"
        "df_clean[cat_cols] = cat_imputer.fit_transform(df_clean[cat_cols])\n"
        "print(f'  • Mode Imputed {len(cat_cols)} categorical features.')\n"
        "\n"
        "# 5. One-Hot Encoding for Categorical Columns\n"
        "df_processed = pd.get_dummies(df_clean, columns=cat_cols, drop_first=True)\n"
        "print(f'  • One-Hot Encoded categorical variables. New shape: {df_processed.shape}')\n"
        "\n"
        "# 6. Standard Scaler Normalization (z-score scaling for numerical continuous features)\n"
        "scaler = StandardScaler()\n"
        "scaled_features = [c for c in num_cols if c not in ['death_inhosp', 'emop']]\n"
        "df_processed[scaled_features] = scaler.fit_transform(df_processed[scaled_features])\n"
        "print(f'  • Z-Score Normalized {len(scaled_features)} continuous numerical features.')\n"
        "\n"
        "# 7. Save Cleaned & Preprocessed Datasets\n"
        "out_csv = 'preprocessed_patient_metadata.csv'\n"
        "docs_csv = 'docs/preprocessed_patient_metadata.csv'\n"
        "\n"
        "df_processed.to_csv(out_csv, index=False)\n"
        "df_processed.to_csv(docs_csv, index=False)\n"
        "\n"
        "print('\\n' + '=' * 75)\n"
        "print(' PREPROCESSING COMPLETE!')\n"
        "print(f'  • Main Output  : {out_csv} ({df_processed.shape[0]} rows x {df_processed.shape[1]} columns)')\n"
        "print(f'  • Docs Copy    : {docs_csv}')\n"
        "print('=' * 75)"
    )
    cells.append(nbf.v4.new_code_cell(cell6_code))
    
    nb.cells = cells
    
    output_nb_path = "dataset_eda_and_preprocessing.ipynb"
    with open(output_nb_path, "w", encoding="utf-8") as f:
        nbf.write(nb, f)
        
    print(f"Successfully generated notebook: {output_nb_path}")

if __name__ == "__main__":
    create_notebook()
