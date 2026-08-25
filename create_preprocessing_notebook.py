#!/usr/bin/env python3
"""
create_preprocessing_notebook.py
Programmatically constructs `dataset_eda_and_preprocessing.ipynb` using nbformat.
Prunes unnecessary/sparse/text columns down to 43 essential clinical parameters,
applies median/mode imputation, compact one-hot encoding, and Z-score standardization.
"""

import os
import nbformat as nbf

def create_notebook():
    nb = nbf.v4.new_notebook()
    nb.metadata['language_info'] = {'name': 'python', 'version': '3.10'}
    
    cells = []
    
    # Title & Overview
    cells.append(nbf.v4.new_markdown_cell(
        "# Clean VitalDB Clinical Dataset Analysis & Feature Pruning Pipeline\n"
        "\n"
        "This notebook executes an optimized clinical preprocessing pipeline on the **VitalDB Clinical Dataset (3,764 Patients)**, "
        "pruning unnecessary free-text diagnosis (`dx`), raw operation names (`opname`), and sparse equipment sizes down to **43 essential clinical features**.\n"
        "\n"
        "### Workflow Steps:\n"
        "1. **Feature Pruning**: Removes high-cardinality text (`dx`, `opname`) and sparse equipment sizes ($>75\\%$ missing).\n"
        "2. **Selected Essential Features**: Demographics, pre-op lab values, comorbidities, airway scores, intraoperative fluids, and vasopressors.\n"
        "3. **Missing Value Imputation**: Median imputation for numerical variables and mode imputation for categorical features.\n"
        "4. **Compact Categorical Encoding**: One-Hot Encoding for categorical features (`sex`, `department`, `optype`, `ane_type`, `approach`, `position`).\n"
        "5. **Standardization & Scaling**: Z-score normalization (`StandardScaler`) for continuous numerical features.\n"
        "6. **Export Machine-Learning Ready Dataset**: Saves clean output to `preprocessed_patient_metadata.csv`."
    ))
    
    # Cell 1: Environment & Setup
    cells.append(nbf.v4.new_markdown_cell("## 1. Environment Setup & Data Loading"))
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
        "from sklearn.preprocessing import StandardScaler\n"
        "from sklearn.impute import SimpleImputer\n"
        "\n"
        "FIG_DIR = 'docs/metadata_eda_figures'\n"
        "os.makedirs(FIG_DIR, exist_ok=True)\n"
        "\n"
        "metadata_path = 'patient_metadata.csv'\n"
        "df_raw = pd.read_csv(metadata_path)\n"
        "print(f'[Loaded Raw Dataset] Patients: {len(df_raw)} | Raw Columns: {df_raw.shape[1]}')"
    )
    cells.append(nbf.v4.new_code_cell(cell1_code))
    
    # Cell 2: Feature Selection & Pruning Unnecessary Columns
    cells.append(nbf.v4.new_markdown_cell("## 2. Feature Selection & Pruning Unnecessary Columns"))
    cell2_code = (
        "# Define 43 Essential Clinical Parameters (Demographics, Pre-op Labs, Airway, Intraop Fluids, Outcomes)\n"
        "essential_cols = [\n"
        "    'caseid', 'subjectid', 'age', 'sex', 'height', 'weight', 'bmi', 'asa', 'emop',\n"
        "    'department', 'optype', 'ane_type', 'approach', 'position',\n"
        "    'preop_htn', 'preop_dm', 'preop_hb', 'preop_plt', 'preop_pt', 'preop_aptt',\n"
        "    'preop_na', 'preop_k', 'preop_gluc', 'preop_alb', 'preop_ast', 'preop_alt', 'preop_bun', 'preop_cr',\n"
        "    'cormack', 'airway', 'tubesize',\n"
        "    'intraop_ebl', 'intraop_uo', 'intraop_crystalloid', 'intraop_colloid', 'intraop_rbc', 'intraop_ffp',\n"
        "    'intraop_eph', 'intraop_phe', 'intraop_epi', 'intraop_ca',\n"
        "    'icu_days', 'death_inhosp'\n"
        "]\n"
        "\n"
        "avail_cols = [c for c in essential_cols if c in df_raw.columns]\n"
        "df_pruned = df_raw[avail_cols].copy()\n"
        "\n"
        "dropped_cols = [c for c in df_raw.columns if c not in avail_cols]\n"
        "print(f'✓ Successfully pruned dataset from {df_raw.shape[1]} columns down to {df_pruned.shape[1]} essential clinical columns.')\n"
        "print(f'  • Dropped {len(dropped_cols)} unnecessary/sparse/text columns: {dropped_cols[:8]}...')"
    )
    cells.append(nbf.v4.new_code_cell(cell2_code))
    
    # Cell 3: Data Imputation Pipeline
    cells.append(nbf.v4.new_markdown_cell("## 3. Missing Value Imputation (Median & Mode)"))
    cell3_code = (
        "num_cols = df_pruned.select_dtypes(include=[np.number]).columns.tolist()\n"
        "cat_cols = df_pruned.select_dtypes(include=['object']).columns.tolist()\n"
        "\n"
        "if 'caseid' in num_cols:\n"
        "    num_cols.remove('caseid')\n"
        "if 'subjectid' in num_cols:\n"
        "    num_cols.remove('subjectid')\n"
        "\n"
        "# 1. Median Imputation for Numerical Columns\n"
        "num_imputer = SimpleImputer(strategy='median')\n"
        "df_pruned[num_cols] = num_imputer.fit_transform(df_pruned[num_cols])\n"
        "print(f'  • Median Imputed {len(num_cols)} numerical features.')\n"
        "\n"
        "# 2. Mode Imputation for Categorical Columns\n"
        "cat_imputer = SimpleImputer(strategy='most_frequent')\n"
        "df_pruned[cat_cols] = cat_imputer.fit_transform(df_pruned[cat_cols])\n"
        "print(f'  • Mode Imputed {len(cat_cols)} categorical features.')"
    )
    cells.append(nbf.v4.new_code_cell(cell3_code))
    
    # Cell 4: Categorical Encoding & Z-Score Scaling
    cells.append(nbf.v4.new_markdown_cell("## 4. Categorical Encoding & Z-Score Normalization"))
    cell4_code = (
        "# 1. One-Hot Encoding for Categorical Columns\n"
        "df_processed = pd.get_dummies(df_pruned, columns=cat_cols, drop_first=True)\n"
        "print(f'  • One-Hot Encoded categorical variables. Processed shape: {df_processed.shape}')\n"
        "\n"
        "# 2. Z-Score Standardization for Continuous Numerical Columns\n"
        "scaler = StandardScaler()\n"
        "scaled_features = [c for c in num_cols if c not in ['death_inhosp', 'emop']]\n"
        "df_processed[scaled_features] = scaler.fit_transform(df_processed[scaled_features])\n"
        "print(f'  • Z-Score Normalized {len(scaled_features)} continuous numerical features.')\n"
        "\n"
        "# 3. Save Clean Output CSV Files\n"
        "out_csv = 'preprocessed_patient_metadata.csv'\n"
        "docs_csv = 'docs/preprocessed_patient_metadata.csv'\n"
        "\n"
        "df_processed.to_csv(out_csv, index=False)\n"
        "df_processed.to_csv(docs_csv, index=False)\n"
        "\n"
        "print('\\n' + '=' * 75)\n"
        "print(' CLEAN PREPROCESSING PIPELINE COMPLETE!')\n"
        "print(f'  • Clean Output  : {out_csv} ({df_processed.shape[0]} rows x {df_processed.shape[1]} columns)')\n"
        "print(f'  • Docs Copy    : {docs_csv}')\n"
        "print('=' * 75)"
    )
    cells.append(nbf.v4.new_code_cell(cell4_code))
    
    nb.cells = cells
    
    output_nb_path = "dataset_eda_and_preprocessing.ipynb"
    with open(output_nb_path, "w", encoding="utf-8") as f:
        nbf.write(nb, f)
        
    print(f"Successfully generated clean pruning notebook: {output_nb_path}")

if __name__ == "__main__":
    create_notebook()
