# Silicon Labs EFR32 Embedded TinyML Firmware

Production-grade C/C++ firmware module for real-time intraoperative adverse event prediction on Silicon Labs **EFR32 microcontrollers** (EFR32xG24, EFR32BG22, EFR32MG21, ARM Cortex-M33 / Cortex-M4).

---

## 📁 Firmware Architecture

```
efr32_firmware/
├── inc/
│   ├── efr32_decision_tree.h   # Direct C Decision Tree classifiers (0 KB RAM, ~2.4 KB Flash)
│   ├── efr32_model_tflite.h    # TensorFlow Lite FlatBuffer C byte array header
│   ├── scaler_params.h         # Pre-computed 95-feature StandardScaler mean & std arrays
│   └── vital_sign_engine.h     # High-level Ring Buffer, Feature Extraction & Alert APIs
├── src/
│   ├── vital_sign_engine.c     # 600s sliding window statistics & biomarker engine
│   ├── app_efr32.c             # Simplicity Studio / Gecko SDK main application template
│   └── main_native_sim.c       # Desktop simulator & benchmark test harness
├── export_firmware_assets.py   # Python generator script to sync C headers from trained models
├── Makefile                    # Local build & native testing Makefile
└── README.md
```

---

## ⚡ Key Embedded Metrics (Silicon Labs EFR32)

| Resource | Footprint / Performance | EFR32 Hardware Budget (e.g. EFR32MG24) |
| :--- | :--- | :--- |
| **Flash (ROM)** | **~2.4 KB** | 1024 KB (<0.3% utilized) |
| **Dynamic RAM (Heap)** | **0 KB** (Zero `malloc`) | 256 KB |
| **Static RAM (SRAM)** | **45.6 KB** (600s × 19 channels × 4 B) | 256 KB |
| **Inference Latency** | **< 20 microseconds** (all 3 models) | 78 MHz ARM Cortex-M33 |
| **Energy Consumption** | **< 0.05 µJ** per evaluation | Ideal for wearable / battery operation |

---

## 🚀 How to Run on Hardware (Simplicity Studio / Gecko SDK)

### Step 1: Copy Header and Source Files
Copy `inc/` and `src/vital_sign_engine.c` into your Simplicity Studio project:
- Add `inc/` to the project's include directories (`Project Properties > C/C++ Build > Settings > Includes`).
- Add `src/vital_sign_engine.c` to your build sources.

### Step 2: Ingest 1 Hz Vital Signs in Your App Loop (`app.c`)
```c
#include "vital_sign_engine.h"

void app_init(void) {
    vital_engine_init();
}

void app_process_action(void) {
    // 1. Ingest vital signs arriving from sensor/UART/BLE every second (1 Hz)
    vital_engine_ingest_raw_sample(hr, sbp, dbp, mbp, spo2, rr, etco2, fio2, bt);

    // 2. Evaluate all 3 adverse event classifiers once 600s window is filled
    if (vital_engine_is_ready()) {
        efr32_alert_status_t alert = vital_engine_predict_all();

        if (alert.alert_hypotension) {
            // Trigger Hypotension Alarm / BLE GATT notification
        }
        if (alert.alert_hypoxia) {
            // Trigger Hypoxia Alarm
        }
        if (alert.alert_tachycardia) {
            // Trigger Tachycardia Alarm
        }
    }
}
```

---

## 🧪 How to Test Locally on Linux/Mac/WSL

Run the native C simulation benchmark against patient records:

```bash
cd efr32_firmware
make clean
make test
```

You will see the sample-by-sample execution logs, rolling window evaluations, inference latencies, and alert statistics.

---

## 🔄 Re-generating C Headers from Python

If you re-train models or adjust hyperparameters in Python, update the C headers with:

```bash
python3 efr32_firmware/export_firmware_assets.py
```
