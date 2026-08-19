# Advanced Pipeline: 95-Feature Rolling Window Predictors

This directory contains the **Advanced Model Pipeline** configured with **95 Statistical Rolling Window Features** (19 channels $\times$ 5 window summary statistics over a 600s sliding window) and **STRIDE = 10** for maximum clinical discrimination and early warning reliability.

---

## 🎯 Clinical Prediction Targets
1. **`Future_Hypotension`** (Mean Arterial Pressure < 65 mmHg within 10 minutes)
2. **`Future_Hypoxia`** (Peripheral Oxygen Saturation $\text{SpO}_2 < 90\%$ within 10 minutes)
3. **`Future_Tachycardia`** (Heart Rate > 100 bpm within 10 minutes)

---

## 📊 Feature Calculation Architecture (95 Features)

- **Sliding Window Size**: 600 seconds (10 minutes)
- **Stride**: 10 seconds
- **Base Channels**: 19 vital channels (9 continuous vital signs + 10 hemodynamic biomarkers)
- **5 Statistical Measures per Channel**:
  1. `mean`: $\frac{1}{W} \sum_{t=1}^{W} x_t$ (Baseline central tendency)
  2. `std`: $\sqrt{\frac{1}{W} \sum_{t=1}^{W} (x_t - \mu)^2}$ (Physiological stability/volatility)
  3. `min`: $\min_{t} x_t$ (Nadir / acute drop)
  4. `max`: $\max_{t} x_t$ (Peak / acute surge)
  5. `slope`: $\frac{x_W - x_1}{W}$ (Temporal hemodynamic trajectory)
- **Total Features**: $19 \times 5 = 95$ Float32 inputs

---

## 📓 Notebook Catalog

| Notebook | Models Trained | Output Folder | Key Highlight |
| :--- | :--- | :--- | :--- |
| **`01_decision_tree_rf.ipynb`** | Decision Tree & Random Forest | `models/decision_tree/`, `models/random_forest/` | Direct C code export & 95-feature trees |
| **`02_logistic_regression.ipynb`**| ElasticNet & Ridge Logistic Reg | `models/logistic_regression/` | Feature importance ranking & L1/L2 regularization |
| **`03_gradient_boosting.ipynb`** | Gradient Boosting & HistGB | `models/gradient_boosting/` | High AUROC gradient boosted decision trees |
| **`04_extra_trees_ensemble.ipynb`**| ExtraTrees & Soft Voting Ensemble| `models/extra_trees_ensemble/` | Stacking ensemble combining DT, RF, LR, and ExtraTrees |
| **`05_mlp_neural_network.ipynb`** | MLP Neural Network & TFLite | `models/mlp_tflite/` | TinyML Deep Learning + 8-bit TFLite FlatBuffer export |

---

## 💾 Designated Model Storage (`advanced/models/`)

```
advanced/models/
├── decision_tree/          # dt_<target>.joblib & efr32_decision_tree_95.h
├── random_forest/          # rf_<target>.joblib
├── gradient_boosting/      # gb_<target>.joblib
├── logistic_regression/    # lr_<target>.joblib
├── extra_trees_ensemble/   # ensemble_<target>.joblib
├── mlp_tflite/             # mlp_<target>.joblib, mlp_<target>.tflite, & efr32_mlp_tflite.h
└── scalers/                # scaler_<target>.json (95-feature StandardScaler parameters)
```
