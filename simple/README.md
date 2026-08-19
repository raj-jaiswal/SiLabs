# Simple Pipeline: 19-Feature Intraoperative Adverse Event Predictors

This directory contains the **Simple Model Pipeline** configured with **19 Instantaneous Vital & Biomarker Features** and **STRIDE = 10** for low-latency, ultra-compact embedded deployment on Silicon Labs EFR32 microcontrollers.

---

## 🎯 Clinical Prediction Targets
1. **`Future_Hypotension`** (Mean Arterial Pressure < 65 mmHg within 10 minutes)
2. **`Future_Hypoxia`** (Peripheral Oxygen Saturation $\text{SpO}_2 < 90\%$ within 10 minutes)
3. **`Future_Tachycardia`** (Heart Rate > 100 bpm within 10 minutes)

---

## 📊 Input Feature Specification (19 Channels)

| Index | Feature Column Name | Category | Description |
| :--- | :--- | :--- | :--- |
| `00` | `Solar8000/HR` | Base Vital | Heart Rate (bpm) |
| `01` | `Solar8000/ART_SBP` | Base Vital | Arterial Systolic Blood Pressure (mmHg) |
| `02` | `Solar8000/ART_DBP` | Base Vital | Arterial Diastolic Blood Pressure (mmHg) |
| `03` | `Solar8000/ART_MBP` | Base Vital | Arterial Mean Blood Pressure (mmHg) |
| `04` | `Solar8000/PLETH_SPO2` | Base Vital | Pulse Oximetry Oxygen Saturation (%) |
| `05` | `Solar8000/RR_CO2` | Base Vital | Respiratory Rate from Capnography (br/min) |
| `06` | `Solar8000/ETCO2` | Base Vital | End-Tidal Carbon Dioxide (mmHg) |
| `07` | `Primus/FIO2` | Base Vital | Fraction of Inspired Oxygen (%) |
| `08` | `Solar8000/BT` | Base Vital | Body Core Temperature (°C) |
| `09` | `Feature_Pulse_Pressure` | Biomarker | $\text{SBP} - \text{DBP}$ |
| `10` | `Feature_Shock_Index` | Biomarker | $\text{HR} / \text{SBP}$ |
| `11` | `Feature_Modified_Shock_Index`| Biomarker | $\text{HR} / \text{MBP}$ |
| `12` | `Feature_Rate_Pressure_Product`| Biomarker | $(\text{HR} \times \text{SBP}) / 100$ |
| `13` | `Feature_HR_Mean_60s` | Moving Stat | 60-second moving average of HR |
| `14` | `Feature_HR_Std_60s` | Moving Stat | 60-second moving standard deviation of HR |
| `15` | `Feature_HR_Delta_60s` | Moving Stat | 60-second rate of change of HR |
| `16` | `Feature_MBP_Mean_60s` | Moving Stat | 60-second moving average of MBP |
| `17` | `Feature_MBP_Std_60s` | Moving Stat | 60-second moving standard deviation of MBP |
| `18` | `Feature_MBP_Delta_60s` | Moving Stat | 60-second rate of change of MBP |

---

## 📓 Notebook Catalog

| Notebook | Models Trained | Output Folder | Key Highlight |
| :--- | :--- | :--- | :--- |
| **`01_decision_tree_rf.ipynb`** | Decision Tree & Random Forest | `models/decision_tree/`, `models/random_forest/` | Fast tree inference & C code export |
| **`02_logistic_regression.ipynb`**| Logistic Regression & Calibration | `models/logistic_regression/` | Ultra-lightweight linear probability estimator |
| **`03_gradient_boosting.ipynb`** | Gradient Boosting & HistGB | `models/gradient_boosting/` | Boosted sequential decision trees |
| **`04_extra_trees_svm.ipynb`** | ExtraTrees & Linear SVM | `models/extra_trees_svm/` | Randomized ensembles & calibrated SVM |

---

## 💾 Designated Model Storage (`simple/models/`)

```
simple/models/
├── decision_tree/          # dt_<target>.joblib & efr32_decision_tree_19.h
├── random_forest/          # rf_<target>.joblib
├── gradient_boosting/      # gb_<target>.joblib
├── logistic_regression/    # lr_<target>.joblib
├── extra_trees_svm/        # extra_trees_<target>.joblib & svm_<target>.joblib
└── scalers/                # scaler_<target>.json (Cached StandardScaler params)
```
