# 🫁 EFR32 Deployment Guide: Future Hypoxia Classifier

> **Target Platform:** Silicon Labs EFR32 (ARM Cortex-M33 / Cortex-M4)  
> **Audience:** Embedded Software / Firmware Engineers (Zero Machine Learning Knowledge Required)  
> **Model Header File:** [`efr32_decision_tree_hypoxia.h`](file:///home/logan78/Desktop/SiLabs/simple/models/decision_tree/efr32_decision_tree_hypoxia.h)  
> **Scaler JSON File:** [`scalers/scaler_Future_Hypoxia.json`](file:///home/logan78/Desktop/SiLabs/simple/models/decision_tree/scalers/scaler_Future_Hypoxia.json)

---

## 📌 1. What Does This Model Do?

This model predicts if a patient is going to develop **Hypoxia (Oxygen Saturation SpO2 < 90%)** in the next 15 to 60 minutes.

- **Input:** An array of **95 `float` values** calculated from a 10-minute (600-second) window of 1 Hz vital sign data.
- **Output:** `true` (High Risk / Trigger Alert) or `false` (Normal / Stable).
- **Execution Cost:** ~0.015 milliseconds latency, 0 Bytes heap RAM (zero `malloc`).

---

## 🛠️ 2. Step-by-Step Embedded Deployment Guide

### Step 1: Include the C Header File
Copy `efr32_decision_tree_hypoxia.h` into your project's `inc/` directory and include it in your C file:

```c
#include "efr32_decision_tree_hypoxia.h"
```

This header provides a single direct C function:
```c
static inline bool predict_hypoxia_95(const float* features);
```

---

### Step 2: Understand the 95 Feature Inputs
The input `features` array must contain **95 floats** in exact sequential order:
- **Indices 0–18:** Mean values of 19 vital sign channels (HR, SBP, DBP, MBP, SpO2, etc.) over 600s.
- **Indices 19–37:** Standard Deviation values of 19 channels over 600s.
- **Indices 38–56:** Minimum values of 19 channels over 600s.
- **Indices 57–75:** Maximum values of 19 channels over 600s.
- **Indices 76–94:** Slopes (rate of change) of 19 channels over 600s.

---

### Step 3: Apply Z-Score Normalization (StandardScaler)
Before calling `predict_hypoxia_95()`, the raw 95 features **must be normalized** using the target's baseline average (`mean`) and variation (`std`).

$$\text{scaled\_features}[i] = \frac{\text{raw\_features}[i] - \text{MEAN}[i]}{\text{STD}[i]}$$

Load the values from `scalers/scaler_Future_Hypoxia.json` into static Flash arrays:

```c
// 95 Mean Values (from scaler_Future_Hypoxia.json "mean")
static const float HYPOXIA_MEAN[95] = {
    74.323041f, 4.422082f, 66.128920f, 90.548557f, 0.001062f, 110.630309f, 9.238386f, 91.904150f, 136.498430f, 0.005126f, 
    59.796882f, 5.165871f, 46.127642f, 72.940467f, 0.002602f, 79.010727f, 9.013530f, 65.234130f, 110.872000f, 0.004031f, 
    99.250838f, 0.487007f, 97.525369f, 99.776331f, -0.000135f, 14.035328f, 0.613775f, 12.758797f, 15.239014f, 0.000473f, 
    33.914732f, 1.437878f, 29.702826f, 36.651122f, 0.000614f, 48.891097f, 3.088897f, 43.938089f, 54.150558f, 0.003899f, 
    33.548657f, 0.203174f, 33.235071f, 33.806246f, -0.000014f, 51.267473f, 5.888306f, 38.618447f, 74.110407f, 0.001741f, 
    0.660175f, 0.069282f, 0.522031f, 0.883384f, -0.000046f, 0.941370f, 0.104283f, 0.711084f, 1.261985f, -0.000077f, 
    82.354893f, 9.797450f, 64.233996f, 114.289718f, 0.005333f, 74.294363f, 3.310669f, 69.135282f, 81.270969f, 0.000914f, 
    2.075362f, 1.511135f, 0.435256f, 6.307660f, 0.000150f, 0.054727f, 4.893173f, -16.808014f, 18.005097f, 0.000289f, 
    78.974538f, 7.171207f, 69.444148f, 95.718823f, 0.003809f, 3.176375f, 3.585638f, 0.672703f, 13.863201f, 0.000027f, 
    0.948219f, 9.581424f, -31.489577f, 34.224679f, -0.001116f
};

// 95 Standard Deviation Values (from scaler_Future_Hypoxia.json "std")
static const float HYPOXIA_STD[95] = {
    14.732601f, 3.935301f, 14.184315f, 24.509876f, 0.017987f, 29.772289f, 8.918630f, 28.869876f, 44.478539f, 0.043196f, 
    16.894183f, 4.877249f, 17.917940f, 24.718992f, 0.023523f, 21.923104f, 10.440863f, 21.071592f, 55.265377f, 0.040518f, 
    2.998941f, 1.287751f, 5.583455f, 1.662804f, 0.004555f, 2.890199f, 1.217951f, 3.859576f, 4.048296f, 0.004415f, 
    4.929951f, 1.849494f, 7.987471f, 5.571903f, 0.007705f, 19.311223f, 6.475288f, 17.016755f, 23.553485f, 0.029652f, 
    7.469072f, 0.672711f, 7.525489f, 7.481337f, 0.002856f, 17.960292f, 6.034822f, 18.066713f, 36.366594f, 0.027197f, 
    0.270117f, 0.098588f, 0.215635f, 0.454417f, 0.000416f, 0.445949f, 0.153954f, 0.396392f, 0.701298f, 0.000667f, 
    27.765812f, 8.930426f, 24.134066f, 47.552275f, 0.043741f, 14.720232f, 3.202006f, 14.262085f, 17.146922f, 0.015756f, 
    2.060535f, 1.711375f, 0.755366f, 6.275237f, 0.006322f, 0.946599f, 4.623683f, 18.504363f, 18.873811f, 0.015784f, 
    21.838074f, 8.117592f, 20.589737f, 34.986350f, 0.034923f, 3.718121f, 6.135062f, 0.943995f, 20.605493f, 0.018555f, 
    7.274794f, 13.373627f, 50.873370f, 49.127805f, 0.040217f
};
```

---

### Step 4: Write the Prediction Wrapper Function
Here is the complete C function to normalize features and run inference:

```c
bool check_future_hypoxia(const float* raw_95_features) {
    float scaled_features[95];

    // 1. Scale all 95 features
    for (int i = 0; i < 95; ++i) {
        float s = HYPOXIA_STD[i];
        if (s > 1e-7f) {
            scaled_features[i] = (raw_95_features[i] - HYPOXIA_MEAN[i]) / s;
        } else {
            scaled_features[i] = 0.0f;
        }
    }

    // 2. Run Direct Decision Tree Function
    return predict_hypoxia_95(scaled_features);
}
```

---

## ⚡ 3. Critical Features Checked by the Decision Tree

When `predict_hypoxia_95()` executes, it performs nested `if/else` checks on these top features:
1. `features[83]` (`FIO2_slope`): 10-minute linear trend / slope of Inspired Oxygen Fraction. (Root threshold $\le 1.19125$)
2. `features[42]` (`PLETH_SPO2_min`): Minimum Oxygen Saturation ($SpO_2$) nadir over 10 min.
3. `features[80]` (`PLETH_SPO2_slope`): Rate of decline in $SpO_2$.
4. `features[70]` (`Feature_HR_Mean_60s_max`): Peak 60-second moving average of Heart Rate.

---

## 📊 4. Microcontroller Footprint Summary

| Resource Metric | Value on Silicon Labs EFR32 |
| :--- | :--- |
| **Flash Memory** | ~741.4 KB |
| **Dynamic RAM (Heap)** | 0 KB (Zero `malloc`) |
| **Static RAM** | Array of 95 floats (~380 Bytes) |
| **Execution Latency** | < 0.015 milliseconds |
