# SiLabs Hospital Triage & Telemetry System — Technical Documentation

## Executive Overview

The **SiLabs Hospital Triage & Telemetry System** is an end-to-end, ultra-low latency intraoperative telemetry and adverse event risk prediction platform. It combines:
1. **100% Pure INT8 Microcontroller Models**: Zero-bias (`use_bias=False`) 1D CNN TFLite models optimized for Silicon Labs **EFR32** microcontrollers with hardware MVP acceleration.
2. **Clinical Patient Metadata Integration**: VitalDB preoperative clinical metadata (3,764 patients $\times$ 43 essential parameters $\rightarrow$ 67 clean ML features).
3. **Multi-Model Stacking Meta-Ensemble**: Combines 6 baseline predictors (3 1D CNN INT8 models + 3 Decision Tree models) with patient clinical metadata to predict **Future Hypotension**, **Future Hypoxia**, and **Future Tachycardia**.
4. **Dual-Input End-to-End Neural Networks**: Fuses 600-second 1D CNN telemetry embeddings with 65-dimensional clinical metadata vectors ($0.926 - 0.988\text{ Test AUC}$).
5. **Real-Time Web & API Dashboards**: A Python telemetry server (`server.py` on Port 5000) and a Next.js Glassmorphism Triage Dashboard (`triage_app` on Port 3000).

---

## 1. System Architecture & Model Suite

```
  ┌───────────────────────────────────────────────┐
  │  600s Telemetry Signal (19 Vital Features)   │
  └───────────────────────┬───────────────────────┘
                          │
  ┌───────────────────────┴───────────────────────┐      ┌───────────────────────────────────┐
  │ 3x 1D CNN INT8 TFLite Models (Zero-Bias)     ├─────►│                                   │
  │ (Hypotension | Hypoxia | Tachycardia)         │      │  Stacking Meta Neural Network     │
  └───────────────────────────────────────────────┘      │  (Meta-NN Models)                 │
                                                         │                                   ├──► Final Risk Probability
  ┌───────────────────────────────────────────────┐      │  Inputs:                          │    (0% to 99%)
  │ 3x Decision Tree Models (Joblib)              ├─────►│  • 65 Clinical Metadata Features   │
  │ (Hypotension | Hypoxia | Tachycardia)         │      │  • 3 CNN Predictions              │
  └───────────────────────────────────────────────┘      │  • 3 Decision Tree Predictions    │
                                                         │                                   │
  ┌───────────────────────────────────────────────┐      │                                   │
  │ Preprocessed Clinical Patient Metadata        ├─────►│                                   │
  │ (Age, Sex, BMI, ASA, Pre-Op Labs, Fluids, etc)│      └───────────────────────────────────┘
  └───────────────────────────────────────────────┘
```

### Model Suite Performance Metrics:

| Model Architecture | Target Event | Model File | Test AUC | Test F1-Score | Optimal Threshold |
| :--- | :--- | :--- | :---: | :---: | :---: |
| **Dual-Input Neural Network** | `Future_Hypotension` | `models/dual_input_nn/nn_Future_Hypotension.keras` | **0.9263** | **0.8412** | 0.50 |
| **Dual-Input Neural Network** | `Future_Hypoxia` | `models/dual_input_nn/nn_Future_Hypoxia.keras` | **0.9879** | **0.5912** | 0.46 |
| **Dual-Input Neural Network** | `Future_Tachycardia` | `models/dual_input_nn/nn_Future_Tachycardia.keras` | **0.9291** | **0.6203** | 0.52 |
| **Stacking Meta-Ensemble NN** | `Future_Hypotension` | `models/meta_neural_network/meta_nn_Future_Hypotension.keras` | **0.8750** | **0.7622** | 0.50 |
| **Stacking Meta-Ensemble NN** | `Future_Hypoxia` | `models/meta_neural_network/meta_nn_Future_Hypoxia.keras` | **0.9702** | **0.4800** | 0.44 |
| **Stacking Meta-Ensemble NN** | `Future_Tachycardia` | `models/meta_neural_network/meta_nn_Future_Tachycardia.keras` | **0.9451** | **0.6190** | 0.52 |
| **1D CNN INT8 TFLite (EFR32)** | `Future_Hypotension` | `CNN/models_int8/cnn_int8_Future_Hypotension.tflite` | **0.8850** | **0.7650** | 0.50 |
| **1D CNN INT8 TFLite (EFR32)** | `Future_Hypoxia` | `CNN/models_int8/cnn_int8_Future_Hypoxia.tflite` | **0.9420** | **0.4750** | 0.50 |
| **1D CNN INT8 TFLite (EFR32)** | `Future_Tachycardia` | `CNN/models_int8/cnn_int8_Future_Tachycardia.tflite` | **0.9310** | **0.6050** | 0.50 |

---

## 2. Clinical Dataset & Feature Preprocessing

### VitalDB Clinical Metadata (3,764 Patients $\times$ 43 Essential Features)
The raw dataset was audited, pruned, and preprocessed from 74 raw columns down to **43 essential clinical parameters**:
* **Demographics**: `caseid`, `subjectid`, `age`, `sex`, `height`, `weight`, `bmi`, `asa` (ASA physical status 1–6)
* **Surgical Details**: `department`, `optype`, `ane_type`, `approach`, `position`, `emop` (emergency operation)
* **Preoperative Labs & History**: `preop_htn`, `preop_dm`, `preop_hb`, `preop_plt`, `preop_pt`, `preop_aptt`, `preop_na`, `preop_k`, `preop_gluc`, `preop_alb`, `preop_ast`, `preop_alt`, `preop_bun`, `preop_cr`
* **Airway Score**: `cormack`, `airway`
* **Intraoperative Fluids & Drugs**: `intraop_ebl`, `intraop_uo`, `intraop_crystalloid`, `intraop_colloid`, `intraop_rbc`, `intraop_ffp`, `intraop_eph`, `intraop_phe`, `intraop_epi`, `intraop_ca`
* **Outcomes**: `icu_days`, `death_inhosp`

### Data Preprocessing Pipeline (`preprocess_dataset.py`)
1. **Pruning High-Missingness Features**: Removed 31 unnecessary/text/sparse columns ($>90\%$ missingness, e.g., free-text diagnosis `dx` and raw operation strings `opname`).
2. **Numerical Imputation**: Median imputation applied to continuous numerical variables.
3. **Categorical Imputation**: Mode (most frequent) imputation applied to categorical variables.
4. **Categorical Feature Encoding**: One-Hot Encoding applied to categorical variables, producing **67 clean machine-learning features**.
5. **Z-Score Normalization**: Continuous numerical variables normalized via `StandardScaler` ($\mu=0, \sigma=1$).
6. **Output Preprocessed File**: [preprocessed_patient_metadata.csv](file:///home/logan78/Desktop/SiLabs/preprocessed_patient_metadata.csv) (**3,764 Rows $\times$ 67 Columns**).

---

## 3. Web & API Server Dependencies

### A. Python Telemetry Server (`server.py`)
* **Host & Port**: `0.0.0.0:5000`
* **API Endpoints**:
  * `POST /api/pred`: Receives JSON telemetry payloads from microcontrollers (ESP32/EFR32).
  * `GET /api/devices`: Returns JSON of active registered devices and risk history.
  * `GET /`: Serves the responsive, live-updating Glassmorphism Web Dashboard with Chart.js.
* **Dependencies**: Python 3.10+, `numpy`, `pandas`, `tensorflow` (2.16+), `scikit-learn` (1.5+), `joblib`.

### B. Next.js Hospital Triage Dashboard (`triage_app`)
* **Host & Port**: `localhost:3000`
* **Environment**: Node.js `v20.20.2` & npm `10.8.2`
* **Dependencies**:

```json
{
  "dependencies": {
    "next": "^14.2.5",
    "react": "^18.3.1",
    "react-dom": "^18.3.1",
    "lucide-react": "^0.424.0",
    "clsx": "^2.1.1",
    "tailwind-merge": "^2.4.0"
  },
  "devDependencies": {
    "@types/node": "^20.14.10",
    "@types/react": "^18.3.3",
    "@types/react-dom": "^18.3.0",
    "autoprefixer": "^10.4.19",
    "postcss": "^8.4.39",
    "tailwindcss": "^3.4.6",
    "typescript": "^5.5.3"
  }
}
```

---

## 4. Operational Commands & Execution Guide

### Launch Both Servers (Single Command)
```bash
cd /home/logan78/Desktop/SiLabs
./run_servers.sh
```

### Stop Both Servers
```bash
fuser -k 5000/tcp 3000/tcp
```

### Run End-to-End Multi-Model Inference for Any Patient
```bash
python3 predict_meta_ensemble.py
```

### Re-Train Stacking Meta Ensemble Neural Networks
```bash
python3 generate_stacked_meta_dataset.py   # Extracts 500-patient stacked dataset
python3 train_meta_neural_network.py        # Trains 3 Meta-NN models
```

### Re-Train Dual-Input End-to-End Neural Networks
```bash
python3 train_dual_input_neural_network.py
```
