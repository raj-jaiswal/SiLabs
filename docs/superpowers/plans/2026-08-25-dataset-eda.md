# Exploratory Data Analysis (`dataset_eda.ipynb`) Implementation Plan

> **For agentic workers:** REQUIRED SUB-SKILL: Use superpowers:subagent-driven-development (recommended) or superpowers:executing-plans to implement this plan task-by-task. Steps use checkbox (`- [ ]`) syntax for tracking.

**Goal:** Create, execute, and verify `dataset_eda.ipynb` with 15 publication-quality visualization figures covering cohort statistics, vitals distributions, engineered features, time-series telemetry, and adverse event risk profiling.

**Architecture:** A modular Jupyter Notebook structured in 5 analytical sections, writing rendered plots to inline notebook cells and exporting figure PNGs to `docs/eda_figures/`.

**Tech Stack:** Python 3, Jupyter Notebook (`nbformat`), `pandas`, `numpy`, `matplotlib`, `seaborn`.

## Global Constraints

- Must produce exactly 15 distinct visualization figures.
- Notebook must be completely self-contained and executable without manual intervention.
- Exports all figures to `docs/eda_figures/fig01_*.png` through `fig15_*.png`.
- Color scheme: Seaborn `whitegrid` theme with colorblind-friendly palettes.

---

### Task 1: Setup Workspace & Notebook Generator Script

**Files:**
- Create: `create_eda_notebook.py`
- Output Target: `dataset_eda.ipynb`
- Output Folder: `docs/eda_figures/`

**Interfaces:**
- Consumes: Raw CSVs in `patient_raw_data/` and processed CSVs in `process_labeled_data/`
- Produces: `dataset_eda.ipynb` populated with notebook cells and execution logic

- [ ] **Step 1: Create `create_eda_notebook.py` builder script**

Create `create_eda_notebook.py` to programmatically build the `.ipynb` JSON file containing all markdown and code cells for 15 figures.

- [ ] **Step 2: Run script to generate `dataset_eda.ipynb` base structure**

Run `python3 create_eda_notebook.py` to create `dataset_eda.ipynb`.

---

### Task 2: Implement Sections 1 & 2 (Figures 1 to 5)

**Files:**
- Modify: `create_eda_notebook.py`
- Modify: `dataset_eda.ipynb`

**Interfaces:**
- Figures 1-2: Patient monitoring duration distribution and missingness bar plot.
- Figures 3-5: Core vitals distribution subplots, $SBP > MBP > DBP$ jointplot, and raw waveform artifact plot.

- [ ] **Step 1: Add cell code for Figures 1 & 2 (Cohort duration & missingness)**
- [ ] **Step 2: Add cell code for Figures 3, 4 & 5 (Vitals distribution, hierarchy, artifacts)**

---

### Task 3: Implement Sections 3 & 4 (Figures 6 to 11)

**Files:**
- Modify: `create_eda_notebook.py`
- Modify: `dataset_eda.ipynb`

**Interfaces:**
- Figures 6-9: Feature correlation matrix, Shock Index hexbin plot, Pulse Pressure ridgeline, 60s rolling stats dynamics.
- Figures 10-11: Multi-channel single-patient telemetry timeline and event-aligned pre-onset trajectory.

- [ ] **Step 1: Add cell code for Figures 6, 7, 8, 9 (Correlation, Shock Index, PP, Rolling stats)**
- [ ] **Step 2: Add cell code for Figures 10 & 11 (Telemetry timeline & event-aligned trajectory)**

---

### Task 4: Implement Section 5 (Figures 12 to 15) & Execution Pipeline

**Files:**
- Modify: `create_eda_notebook.py`
- Modify: `dataset_eda.ipynb`
- Generate: `docs/eda_figures/fig01_*.png` ... `fig15_*.png`

**Interfaces:**
- Figures 12-15: Target prevalence bar chart, co-occurrence heatmap, feature separability violins, risk ECDF curves.

- [ ] **Step 1: Add cell code for Figures 12, 13, 14 & 15**
- [ ] **Step 2: Execute `dataset_eda.ipynb` via Python notebook execution (`jupyter nbconvert --execute` or `nbclient`)**
- [ ] **Step 3: Verify all 15 figures generated and saved to `docs/eda_figures/`**
