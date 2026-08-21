# Silicon Labs EFR32 Decision Tree Deployment Guides

Welcome! This directory contains the pre-compiled C decision tree headers and step-by-step deployment guides for deploying **3 clinical prediction models** onto the **Silicon Labs EFR32 (ARM Cortex-M33)** microcontroller.

> **Target Audience:** Embedded Software & Firmware Engineers (Zero Machine Learning Knowledge Required).

---

## 📂 Model Headers & Deployment Guides

| Clinical Condition | Model C Header File | Step-by-Step Deployment Guide | RAM / Flash Footprint |
| :--- | :--- | :--- | :--- |
| **Future Hypotension** | [`efr32_decision_tree_hypotension.h`](file:///home/logan78/Desktop/SiLabs/simple/models/decision_tree/efr32_decision_tree_hypotension.h) | 📕 **[`DEPLOY_HYPOTENSION_EFR32.md`](file:///home/logan78/Desktop/SiLabs/simple/models/decision_tree/DEPLOY_HYPOTENSION_EFR32.md)** | **0 KB RAM** \| ~40.6 KB Flash |
| **Future Hypoxia** | [`efr32_decision_tree_hypoxia.h`](file:///home/logan78/Desktop/SiLabs/simple/models/decision_tree/efr32_decision_tree_hypoxia.h) | 📙 **[`DEPLOY_HYPOXIA_EFR32.md`](file:///home/logan78/Desktop/SiLabs/simple/models/decision_tree/DEPLOY_HYPOXIA_EFR32.md)** | **0 KB RAM** \| ~741.4 KB Flash |
| **Future Tachycardia** | [`efr32_decision_tree_tachycardia.h`](file:///home/logan78/Desktop/SiLabs/simple/models/decision_tree/efr32_decision_tree_tachycardia.h) | 📗 **[`DEPLOY_TACHYCARDIA_EFR32.md`](file:///home/logan78/Desktop/SiLabs/simple/models/decision_tree/DEPLOY_TACHYCARDIA_EFR32.md)** | **0 KB RAM** \| ~334.1 KB Flash |

---

## ⚡ Basic Deployment Steps for Embedded Engineers

1. **Copy the Header File:** Copy the target `.h` file into your Simplicity Studio / Gecko SDK `inc/` folder.
2. **Normalize the 95 Input Features:** Standardize raw features using the `MEAN` and `STD` arrays provided in each model's guide:
   $$\text{scaled\_features}[i] = \frac{\text{raw\_features}[i] - \text{MEAN}[i]}{\text{STD}[i]}$$
3. **Execute Prediction:** Call the direct C function:
   - `predict_hypotension_95(scaled_features)`
   - `predict_hypoxia_95(scaled_features)`
   - `predict_tachycardia_95(scaled_features)`
