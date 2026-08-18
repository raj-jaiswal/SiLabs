# Trained Machine Learning Models & Normalization Scalers for Silicon Labs EFR32

This directory contains trained models, scalers, and deployment headers for intraoperative prediction of 3 clinical targets:
1. **`Future_Hypotension`** (Mean Arterial Pressure < 65 mmHg)
2. **`Future_Hypoxia`** (Peripheral Oxygen Saturation $\text{SpO}_2 < 90\%$)
3. **`Future_Tachycardia`** (Heart Rate > 100 bpm)

---

## 📁 Directory Structure

```
models/
├── decision_tree/
│   ├── efr32_dt_Future_Hypotension.joblib   # Scikit-learn Decision Tree model (Hypotension)
│   ├── efr32_dt_Future_Hypoxia.joblib       # Scikit-learn Decision Tree model (Hypoxia)
│   ├── efr32_dt_Future_Tachycardia.joblib   # Scikit-learn Decision Tree model (Tachycardia)
│   └── efr32_decision_tree.h                # Direct C decision tree logic (0 KB dynamic RAM)
│
├── random_forest/
│   ├── efr32_rf_Future_Hypotension.joblib   # Random Forest ensemble model (Hypotension)
│   ├── efr32_rf_Future_Hypoxia.joblib       # Random Forest ensemble model (Hypoxia)
│   └── efr32_rf_Future_Tachycardia.joblib   # Random Forest ensemble model (Tachycardia)
│
├── gradient_boosting/
│   ├── efr32_gb_Future_Hypotension.joblib   # Gradient Boosting model (Hypotension)
│   ├── efr32_gb_Future_Hypoxia.joblib       # Gradient Boosting model (Hypoxia)
│   └── efr32_gb_Future_Tachycardia.joblib   # Gradient Boosting model (Tachycardia)
│
├── tflite/
│   ├── efr32_model_Future_Hypotension.tflite # Compact TensorFlow Lite FlatBuffer binary
│   └── efr32_model_tflite.h                 # C byte array header (g_efr32_hypotension_model_data)
│
└── scalers/
    ├── scaler_Future_Hypotension.json       # 95-feature StandardScaler mean, var, std
    ├── scaler_Future_Hypoxia.json            # 95-feature StandardScaler mean, var, std
    ├── scaler_Future_Tachycardia.json        # 95-feature StandardScaler mean, var, std
    ├── scaler_global.json                   # Global dataset scaler
    └── scaler_raw_columns_*.json            # 19 raw channel scalers (unwindowed)
```

---

## 📊 Summary of Model Performance (Full Patient Cohort)

| Target | Model Architecture | AUROC | AUPRC | Optimal $\tau^*$ | Memory Profile (EFR32) |
| :--- | :--- | :--- | :--- | :--- | :--- |
| **Hypotension** | Random Forest | **0.8824** | **0.7996** | 0.60 | ~1.1 MB (Server/Edge) |
| | Decision Tree | **0.8647** | **0.7712** | 0.62 | **~2 KB Flash / 0 KB RAM** |
| | Gradient Boosting | **0.8850** | **0.8013** | 0.55 | ~85 KB Flash |
| **Hypoxia** | Random Forest | **0.8952** | **0.5128** | 0.76 | ~1.1 MB |
| | Decision Tree | **0.8805** | **0.4790** | 0.76 | **~1 KB Flash / 0 KB RAM** |
| | Gradient Boosting | **0.8941** | **0.5568** | 0.36 | ~87 KB Flash |
| **Tachycardia** | Random Forest | **0.8871** | **0.6473** | 0.77 | ~1.2 MB |
| | Decision Tree | **0.8773** | **0.6038** | 0.78 | **~1 KB Flash / 0 KB RAM** |
| | Gradient Boosting | **0.8871** | **0.6562** | 0.42 | ~87 KB Flash |
