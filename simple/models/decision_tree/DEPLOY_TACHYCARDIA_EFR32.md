# ❤️ EFR32 Deployment Guide: Future Tachycardia Classifier

> **Target Platform:** Silicon Labs EFR32 (ARM Cortex-M33 / Cortex-M4)  
> **Audience:** Embedded Software / Firmware Engineers (Zero Machine Learning Knowledge Required)  
> **Model Header File:** [`efr32_decision_tree_tachycardia.h`](file:///home/logan78/Desktop/SiLabs/simple/models/decision_tree/efr32_decision_tree_tachycardia.h)  
> **Scaler JSON File:** [`scalers/scaler_Future_Tachycardia.json`](file:///home/logan78/Desktop/SiLabs/simple/models/decision_tree/scalers/scaler_Future_Tachycardia.json)

---

## 📌 1. What Does This Model Do?

This model predicts if a patient is going to develop **Tachycardia (Heart Rate HR > 100 bpm)** in the next 15 to 60 minutes.

- **Input:** An array of **95 `float` values** calculated from a 10-minute (600-second) window of 1 Hz vital sign data.
- **Output:** `true` (High Risk / Trigger Alert) or `false` (Normal / Stable).
- **Execution Cost:** ~0.010 milliseconds latency, 0 Bytes heap RAM (zero `malloc`).

---

## 🛠️ 2. Step-by-Step Embedded Deployment Guide

### Step 1: Include the C Header File
Copy `efr32_decision_tree_tachycardia.h` into your project's `inc/` directory and include it in your C file:

```c
#include "efr32_decision_tree_tachycardia.h"
```

This header provides a single direct C function:
```c
static inline bool predict_tachycardia_95(const float* features);
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
Before calling `predict_tachycardia_95()`, the raw 95 features **must be normalized** using the target's baseline average (`mean`) and variation (`std`).

$$\text{scaled\_features}[i] = \frac{\text{raw\_features}[i] - \text{MEAN}[i]}{\text{STD}[i]}$$

Load the values from `scalers/scaler_Future_Tachycardia.json` into static Flash arrays:

```c
// 95 Mean Values (from scaler_Future_Tachycardia.json "mean")
static const float TACHYCARDIA_MEAN[95] = {
    76.927629f, 4.784585f, 68.047893f, 94.819795f, 0.001048f, 110.527794f, 9.223914f, 91.916066f, 136.158995f, 0.004407f, 
    59.597625f, 5.103758f, 46.378837f, 72.515179f, 0.002254f, 78.795333f, 9.193576f, 64.963408f, 111.544526f, 0.003421f, 
    99.443908f, 0.369046f, 98.104212f, 99.828090f, 0.000074f, 13.995006f, 0.568087f, 12.834784f, 15.066504f, 0.000486f, 
    34.171730f, 1.388381f, 30.177934f, 36.778806f, 0.000661f, 48.715087f, 2.396431f, 44.465856f, 52.858947f, 0.000752f, 
    33.700675f, 0.178181f, 33.413807f, 33.926531f, 0.000133f, 51.387308f, 5.750260f, 39.103871f, 73.359216f, 0.001312f, 
    0.691014f, 0.075440f, 0.542067f, 0.936790f, -0.000048f, 0.990582f, 0.114682f, 0.739685f, 1.346202f, -0.000086f, 
    85.117692f, 10.266390f, 66.159490f, 119.002715f, 0.004824f, 76.898132f, 3.479685f, 71.463887f, 84.304831f, 0.000857f, 
    2.343392f, 1.690383f, 0.481178f, 6.979657f, 0.000237f, 0.057319f, 5.422729f, -18.834679f, 19.965888f, 0.000383f, 
    78.800108f, 7.282488f, 69.217636f, 96.017055f, 0.003157f, 3.285578f, 3.739956f, 0.694504f, 14.407116f, -0.000238f, 
    0.911478f, 9.943833f, -32.616149f, 35.315899f, -0.001198f
};

// 95 Standard Deviation Values (from scaler_Future_Tachycardia.json "std")
static const float TACHYCARDIA_STD[95] = {
    16.779302f, 4.410309f, 15.755987f, 27.788684f, 0.019264f, 28.308736f, 9.015557f, 28.183021f, 42.876511f, 0.042958f, 
    16.365159f, 4.840790f, 17.689308f, 23.798932f, 0.023508f, 21.087660f, 10.724155f, 20.602220f, 55.850562f, 0.041072f, 
    2.348157f, 1.047695f, 4.584803f, 1.357254f, 0.003516f, 2.949111f, 1.170167f, 3.856641f, 3.890780f, 0.004145f, 
    4.249511f, 1.824721f, 7.520649f, 4.843764f, 0.007414f, 19.241980f, 5.519614f, 17.251824f, 22.613079f, 0.024972f, 
    7.319763f, 0.619889f, 7.373314f, 7.329839f, 0.002616f, 17.241392f, 5.913980f, 17.794228f, 35.321096f, 0.026314f, 
    0.287092f, 0.107447f, 0.222756f, 0.491941f, 0.000447f, 0.482182f, 0.170301f, 0.421065f, 0.764559f, 0.000734f, 
    28.529889f, 9.249932f, 24.926820f, 49.428004f, 0.044967f, 16.756991f, 3.442645f, 16.068000f, 19.483597f, 0.016354f, 
    2.477790f, 1.935319f, 0.917664f, 7.072223f, 0.007244f, 0.995458f, 5.344386f, 20.653050f, 20.973091f, 0.017935f, 
    20.994222f, 8.323542f, 20.012969f, 34.984092f, 0.035277f, 3.828298f, 6.321368f, 0.993336f, 21.166217f, 0.019120f, 
    7.369714f, 13.831283f, 52.102715f, 50.225043f, 0.041465f
};
```

---

### Step 4: Write the Prediction Wrapper Function
Here is the complete C function to normalize features and run inference:

```c
bool check_future_tachycardia(const float* raw_95_features) {
    float scaled_features[95];

    // 1. Scale all 95 features
    for (int i = 0; i < 95; ++i) {
        float s = TACHYCARDIA_STD[i];
        if (s > 1e-7f) {
            scaled_features[i] = (raw_95_features[i] - TACHYCARDIA_MEAN[i]) / s;
        } else {
            scaled_features[i] = 0.0f;
        }
    }

    // 2. Run Direct Decision Tree Function
    return predict_tachycardia_95(scaled_features);
}
```

---

## ⚡ 3. Critical Features Checked by the Decision Tree

When `predict_tachycardia_95()` executes, it performs nested `if/else` checks on these top features:
1. `features[19]` (`HR_std`): Standard Deviation of Heart Rate over 10 min. (Root threshold $\le 1.19222$)
2. `features[14]` (`Feature_HR_Std_60s_mean`): Mean of 60-second moving HR standard deviations.
3. `features[67]` (`Feature_Shock_Index_max`): Peak Shock Index ($\text{HR}/\text{SBP}$) over 10 min.
4. `features[50]` (`Feature_Rate_Pressure_Product_min`): Minimum Rate Pressure Product nadir.

---

## 📊 4. Microcontroller Footprint Summary

| Resource Metric | Value on Silicon Labs EFR32 |
| :--- | :--- |
| **Flash Memory** | ~334.1 KB |
| **Dynamic RAM (Heap)** | 0 KB (Zero `malloc`) |
| **Static RAM** | Array of 95 floats (~380 Bytes) |
| **Execution Latency** | < 0.010 milliseconds |
