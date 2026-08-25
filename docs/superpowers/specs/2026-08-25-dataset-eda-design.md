# Design Specification: Perioperative Telemetry Dataset Exploratory Data Analysis (`dataset_eda.ipynb`)

**Date**: 2026-08-25  
**Topic**: Exploratory Data Analysis (EDA) Notebook with 15 Embedded Visualizations  
**Target File**: `dataset_eda.ipynb`  
**Artifact Directory**: `docs/eda_figures/`  

---

## 1. Executive Summary

This specification outlines the design for `dataset_eda.ipynb`, a comprehensive Jupyter Notebook that performs Exploratory Data Analysis (EDA) on the high-resolution perioperative patient telemetry dataset (`patient_raw_data/` and `process_labeled_data/`). The notebook will generate and embed 15 publication-quality, clinically insightful visualizations analyzing data completeness, physiological distributions, engineered hemodynamic features, multi-parameter time-series trajectories, and adverse event target risk profiling.

---

## 2. Dataset Overview & Context

- **Raw Telemetry Input (`patient_raw_data/*.csv`)**: High-frequency waveform signals (`SNUADC/ECG_II`, `SNUADC/PLETH`) and 1 Hz numerical vitals (`Solar8000/HR`, `Solar8000/ART_SBP`, `Solar8000/ART_DBP`, `Solar8000/ART_MBP`, `Solar8000/PLETH_SPO2`, `Solar8000/RR_CO2`, `Solar8000/ETCO2`, `Primus/FIO2`, `Solar8000/BT`).
- **Engineered & Labeled Telemetry Input (`process_labeled_data/*.csv`)**: Cleaned vitals with derivative features (`Feature_Pulse_Pressure`, `Feature_Shock_Index`, `Feature_Modified_Shock_Index`, `Feature_Rate_Pressure_Product`, 60s rolling stats) and 10-minute forward target labels (`Future_Hypotension`, `Future_Hypoxia`, `Future_Tachycardia`).

---

## 3. Visualization Breakdown (15 Figures)

### Section 1: Cohort & Data Completeness Analysis
1. **Figure 1: Patient Monitoring Duration & Record Length Distribution**
   - *Type*: Combined Histogram and Kernel Density Estimation (KDE).
   - *Insight*: Distribution of surgical case durations (minutes/hours per patient).
2. **Figure 2: Missing Data Profile & Sensor Coverage**
   - *Type*: Bar plot of percentage missing values per vital sign across raw vs. processed files.
   - *Insight*: Identifies unmonitored channels, disconnection rates, and data imputation impact.

### Section 2: Physiological Vitals & Artifact Analysis
3. **Figure 3: Core Vitals Distributions with Clinical Reference Bounds**
   - *Type*: 6-panel Subplot Grid (Histograms + KDE) for HR, SBP, DBP, MBP, SpO2, and ETCO2.
   - *Insight*: Evaluates physiological normality and sensor saturation limits.
4. **Figure 4: Hemodynamic Hierarchy & Consistency (SBP vs. MBP vs. DBP)**
   - *Type*: Jointplot / Scatter Plot matrix enforcing $SBP > MBP > DBP$.
   - *Insight*: Validates transducer pressure line consistency and physiological bounds.
5. **Figure 5: Artifact Rejection & Raw Waveform Quality Analysis**
   - *Type*: Dual-panel time series plot showing raw ECG/PPG waveforms with out-of-bounds artifact highlighting.
   - *Insight*: Demonstrates noise filtering and out-of-range sensor code removal.

### Section 3: Engineered Hemodynamic Biomarkers
6. **Figure 6: Feature Correlation Matrix & Multicollinearity Heatmap**
   - *Type*: Annotated Correlation Heatmap across all 20+ numerical vital features.
   - *Insight*: Highlights collinearity between raw pressure measurements and derived indices.
7. **Figure 7: Shock Index ($HR / SBP$) vs. Modified Shock Index ($HR / MBP$) Risk Distribution**
   - *Type*: 2D Hexbin / Contour density plot with critical clinical threshold lines ($SI > 0.9$).
   - *Insight*: Visualizes patient distribution across hemodynamic stability zones.
8. **Figure 8: Pulse Pressure ($PP$) vs. Rate Pressure Product ($RPP$) Distributions**
   - *Type*: Dual Box plots and Ridgeline/Violin distributions by age or recording phase.
   - *Insight*: Examines arterial stiffness ($PP$) and myocardial workload ($RPP$).
9. **Figure 9: Multi-Scale Rolling Dynamics (60s Mean, Variability/Std, Deltas)**
   - *Type*: Multi-panel line/shade plots comparing rolling stats for steady vs. unstable periods.
   - *Insight*: Demonstrates short-term vital sign volatility before clinical decompensation.

### Section 4: Telemetry Time-Series & Patient Trajectories
10. **Figure 10: Multi-Parameter High-Resolution Telemetry Timeline**
    - *Type*: Stacked 5-panel Time Series Plot for a representative single patient case.
    - *Insight*: Complete intraoperative telemetry visual record (ECG, PLETH, Pressures, SpO2, ETCO2).
11. **Figure 11: Real-Time Physiological Trend Preceding Adverse Event Onset**
    - *Type*: Event-aligned trajectory plot (5 minutes before to 2 minutes after event onset).
    - *Insight*: Reveals pre-hypotensive and pre-hypoxic vital sign trajectory dynamics.

### Section 5: Adverse Event Risk & Separability Profiling
12. **Figure 12: Target Prevalence & Class Imbalance Analysis**
    - *Type*: Grouped Bar Chart comparing current vs. 10-minute future target event rates.
    - *Insight*: Quantifies class imbalance across Hypotension, Hypoxia, and Tachycardia.
13. **Figure 13: Adverse Event Co-Occurrence & Multi-Label Heatmap**
    - *Type*: Co-occurrence matrix heatmap (percentage of simultaneous events).
    - *Insight*: Identifies overlapping clinical crises (e.g. combined Hypotension + Tachycardia).
14. **Figure 14: Feature Separability Violin Plots (Event vs. Non-Event)**
    - *Type*: Side-by-side Violin Plots for key features grouped by `Future_Hypotension = 0` vs. `1`.
    - *Insight*: Evaluates predictive signal strength of features prior to event onset.
15. **Figure 15: Cumulative Risk Density Curves (CDF/KDE of Shock Index & MBP)**
    - *Type*: Empirical Cumulative Distribution Function (ECDF) curves comparing stable vs. adverse event cohorts.
    - *Insight*: Establishes empirical decision boundaries for risk stratification.

---

## 4. Technical Implementation & Dependencies

- **Python Libraries**: `pandas`, `numpy`, `matplotlib`, `seaborn`, `tqdm`.
- **Styling**: Clean, high-resolution aesthetic (Seaborn `whitegrid` theme, custom color palettes, 300 DPI figure exports).
- **Execution & Storage**: `dataset_eda.ipynb` will be fully executed with output cells saved inline and image files saved to `docs/eda_figures/`.
