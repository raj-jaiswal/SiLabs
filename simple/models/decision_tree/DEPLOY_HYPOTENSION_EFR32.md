# 🩺 EFR32 Deployment Guide: Future Hypotension Classifier

> **Target Platform:** Silicon Labs EFR32 (ARM Cortex-M33 / Cortex-M4)  
> **Audience:** Embedded Software / Firmware Engineers (Zero Machine Learning Knowledge Required)  
> **Model Header File:** [`efr32_decision_tree_hypotension.h`](file:///home/logan78/Desktop/SiLabs/simple/models/decision_tree/efr32_decision_tree_hypotension.h)  
> **Scaler JSON File:** [`scalers/scaler_Future_Hypotension.json`](file:///home/logan78/Desktop/SiLabs/simple/models/decision_tree/scalers/scaler_Future_Hypotension.json)

---

## 📌 1. What Does This Model Do?

This model predicts if a patient is going to develop **Hypotension (Mean Arterial Pressure < 65 mmHg)** in the next 15 to 60 minutes.

- **Input:** An array of **95 `float` values** calculated from a 10-minute (600-second) window of 1 Hz vital sign data.
- **Output:** `true` (High Risk / Trigger Alert) or `false` (Normal / Stable).
- **Execution Cost:** ~0.005 milliseconds latency, 0 Bytes heap RAM (zero `malloc`).

---

## 🛠️ 2. Step-by-Step Embedded Deployment Guide

### Step 1: Include the C Header File
Copy `efr32_decision_tree_hypotension.h` into your project's `inc/` directory and include it in your C file:

```c
#include "efr32_decision_tree_hypotension.h"
```

This header provides a single direct C function:
```c
static inline bool predict_hypotension_95(const float* features);
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
Before calling `predict_hypotension_95()`, the raw 95 features **must be normalized** using the target's baseline average (`mean`) and variation (`std`).

$$\text{scaled\_features}[i] = \frac{\text{raw\_features}[i] - \text{MEAN}[i]}{\text{STD}[i]}$$

Load the values from `scalers/scaler_Future_Hypotension.json` into static Flash arrays:

```c
// 95 Mean Values (from scaler_Future_Hypotension.json "mean")
static const float HYPOTENSION_MEAN[95] = {
    74.395929f, 108.534083f, 57.398228f, 76.355037f, 99.424683f, 13.916447f, 33.976928f, 47.821084f, 33.699057f, 51.658239f, 
    0.703356f, 1.024863f, 80.896293f, 74.400437f, 2.123400f, -0.010464f, 76.412837f, 3.438800f, 1.025504f, 4.364578f, 
    9.702166f, 5.243504f, 9.686031f, 0.376769f, 0.573725f, 1.414648f, 2.467518f, 0.186940f, 6.123875f, 0.077824f, 
    0.119442f, 9.977728f, 3.234206f, 1.504776f, 4.924078f, 7.645919f, 4.017601f, 10.540971f, 66.124995f, 89.093632f, 
    43.760712f, 62.140882f, 98.095986f, 12.726602f, 29.929447f, 43.491987f, 33.404985f, 38.793527f, 0.549908f, 0.761363f, 
    62.382389f, 69.264095f, 0.456616f, -17.054418f, 66.468719f, 0.697778f, -34.683032f, 90.461967f, 135.328643f, 70.423153f, 
    111.160012f, 99.829210f, 14.990461f, 36.622211f, 52.112246f, 33.942342f, 74.910586f, 0.950712f, 1.384080f, 113.103294f, 
    81.194674f, 6.293906f, 17.936588f, 94.633524f, 15.369225f, 37.461044f, -0.000161f, 0.001511f, 0.000633f, 0.001269f, 
    0.000080f, 0.000465f, 0.000673f, 0.000184f, 0.000226f, -0.000024f, -0.000043f, -0.000075f, 0.001315f, -0.000195f, 
    -0.000072f, 0.000053f, 0.001288f, -0.000171f, -0.001922f
};

// 95 Standard Deviation Values (from scaler_Future_Hypotension.json "std")
static const float HYPOTENSION_STD[95] = {
    15.296941f, 25.737578f, 15.128511f, 19.389534f, 2.257126f, 2.913264f, 4.696115f, 18.779998f, 6.965654f, 16.564650f, 
    0.279202f, 0.475601f, 25.600522f, 15.284856f, 2.153849f, 0.896687f, 19.289143f, 4.030678f, 8.487279f, 3.851792f, 
    9.640807f, 5.107120f, 11.337701f, 1.044067f, 1.161479f, 1.868101f, 5.613961f, 0.636007f, 6.421529f, 0.109925f, 
    0.170335f, 9.133748f, 3.067065f, 1.693085f, 4.679185f, 8.841957f, 6.629511f, 14.560048f, 14.545404f, 26.323373f, 
    16.900028f, 19.176148f, 4.495913f, 3.863202f, 7.783811f, 16.576409f, 7.027243f, 17.439913f, 0.223011f, 0.437047f, 
    22.618216f, 14.732587f, 0.822005f, 18.632977f, 18.432343f, 1.169592f, 54.636054f, 25.169072f, 41.491542f, 23.147394f, 
    57.036726f, 1.250965f, 3.823719f, 5.178114f, 22.434158f, 6.972246f, 35.345245f, 0.475532f, 0.739635f, 45.761062f, 
    17.586506f, 6.230473f, 18.844792f, 34.981653f, 22.156678f, 52.556197f, 0.017382f, 0.045176f, 0.024144f, 0.043057f, 
    0.003650f, 0.004117f, 0.007710f, 0.025410f, 0.002695f, 0.028133f, 0.000461f, 0.000744f, 0.043555f, 0.014884f, 
    0.006191f, 0.016220f, 0.036838f, 0.020207f, 0.044660f
};
```

---

### Step 4: Write the Prediction Wrapper Function
Here is the complete C function to normalize features and run inference:

```c
bool check_future_hypotension(const float* raw_95_features) {
    float scaled_features[95];

    // 1. Scale all 95 features
    for (int i = 0; i < 95; ++i) {
        float s = HYPOTENSION_STD[i];
        if (s > 1e-7f) {
            scaled_features[i] = (raw_95_features[i] - HYPOTENSION_MEAN[i]) / s;
        } else {
            scaled_features[i] = 0.0f;
        }
    }

    // 2. Run Direct Decision Tree Function
    return predict_hypotension_95(scaled_features);
}
```

---

## ⚡ 3. Critical Features Checked by the Decision Tree

When `predict_hypotension_95()` executes, it performs nested `if/else` checks on these top features:
1. `features[39]` (`ART_SBP_min`): Minimum Systolic BP over 10 min. (Root node threshold $\le 0.09726$)
2. `features[73]` (`Feature_MBP_Mean_60s_max`): Peak 60-second moving average of Mean Arterial Pressure.
3. `features[2]` (`ART_DBP_mean`): Mean Diastolic BP baseline over 10 min.
4. `features[87]` (`Feature_Modified_Shock_Index_slope`): Rate of change of Modified Shock Index ($\text{HR}/\text{MBP}$).

---

## 📊 4. Microcontroller Footprint Summary

| Resource Metric | Value on Silicon Labs EFR32 |
| :--- | :--- |
| **Flash Memory** | ~40.6 KB |
| **Dynamic RAM (Heap)** | 0 KB (Zero `malloc`) |
| **Static RAM** | Array of 95 floats (~380 Bytes) |
| **Execution Latency** | < 0.005 milliseconds |
