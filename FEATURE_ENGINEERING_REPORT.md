# Complete 95-Feature StandardScaler & Calculation Guide

This guide explains why there are **95 features** in the StandardScaler JSON file and how each one is calculated.

---

## Why are there 95 Features?

The ML model processes a **600-second (10-minute) sliding window** of patient vital data. 

There are **19 core feature channels** (9 raw vitals + 10 newly engineered features). For every 600-second window, the model calculates **5 statistical summary metrics** per channel:

$$\text{Total Features in StandardScaler} = 19 \text{ channels} \times 5 \text{ window statistics} = 95 \text{ features}$$

```
┌──────────────────────────────────────────────┐
│            19 Core Feature Channels          │
│ (9 Base Vitals + 10 Engineered Biomarkers)   │
└──────────────────────┬───────────────────────┘
                       │
       Calculated over 600s Sliding Window (W=600)
                       ▼
┌────────────────────────────────────────────────────────┐
│               5 Window Statistics per Channel          │
├──────────────┬─────────────────────────────────────────┤
│ 1. `_mean`   │ 19 features (Average over 600s)         │
│ 2. `_std`    │ 19 features (Standard Deviation in 600s)│
│ 3. `_min`    │ 19 features (Minimum value in 600s)     │
│ 4. `_max`    │ 19 features (Maximum value in 600s)     │
│ 5. `_slope`  │ 19 features (Trajectory slope in 600s)  │
├──────────────┼─────────────────────────────────────────┤
│ TOTAL        │ 19 × 5 = 95 Features                    │
└──────────────┴─────────────────────────────────────────┘
```

---

## The 19 Core Feature Channels

### A. 9 Base Vitals (From Patient Monitors)
1. `HR` (`Solar8000/HR`): Heart Rate (bpm)
2. `ART_SBP` (`Solar8000/ART_SBP`): Systolic Blood Pressure (mmHg)
3. `ART_DBP` (`Solar8000/ART_DBP`): Diastolic Blood Pressure (mmHg)
4. `ART_MBP` (`Solar8000/ART_MBP`): Mean Arterial Pressure (mmHg)
5. `PLETH_SPO2` (`Solar8000/PLETH_SPO2`): Oxygen Saturation (%)
6. `RR_CO2` (`Solar8000/RR_CO2`): Respiratory Rate (breaths/min)
7. `ETCO2` (`Solar8000/ETCO2`): End-Tidal CO2 (mmHg)
8. `FIO2` (`Primus/FIO2`): Inspired Oxygen Fraction (%)
9. `BT` (`Solar8000/BT`): Body Temperature (°C)

### B. 10 Newly Engineered Features
10. `Feature_Pulse_Pressure` = `ART_SBP` − `ART_DBP`
11. `Feature_Shock_Index` = `HR` / `ART_SBP`
12. `Feature_Modified_Shock_Index` = `HR` / `ART_MBP`
13. `Feature_Rate_Pressure_Product` = (`HR` × `ART_SBP`) / 100
14. `Feature_HR_Mean_60s` = Average of `HR` over past 60s
15. `Feature_HR_Std_60s` = Standard deviation of `HR` over past 60s
16. `Feature_HR_Delta_60s` = `HR(t)` − `HR(t−60)`
17. `Feature_MBP_Mean_60s` = Average of `ART_MBP` over past 60s
18. `Feature_MBP_Std_60s` = Standard deviation of `ART_MBP` over past 60s
19. `Feature_MBP_Delta_60s` = `ART_MBP(t)` − `ART_MBP(t−60)`

---

## How the 5 Window Statistics (95 Features) are Calculated

For each 600-second window ($x_1, x_2, \dots, x_{600}$ at 1 Hz):

| Window Stat Group | Feature Count | Formula over 600s Window | What it measures |
|---|---|---|---|
| **1. `_mean`** (1 to 19) | 19 | $\mu = \frac{1}{600}\sum_{i=1}^{600} x_i$ | Average level over the 10-minute period |
| **2. `_std`** (20 to 38) | 19 | $\sigma = \sqrt{\frac{1}{600}\sum_{i=1}^{600} (x_i - \mu)^2}$ | Instability & volatility over 10 minutes |
| **3. `_min`** (39 to 57) | 19 | $\min(x_1, x_2, \dots, x_{600})$ | Deepest drop / lowest point reached |
| **4. `_max`** (58 to 76) | 19 | $\max(x_1, x_2, \dots, x_{600})$ | Highest surge / peak point reached |
| **5. `_slope`** (77 to 95) | 19 | $\frac{x_{600} - x_1}{600}$ | Rate of rise or drop per second |

---

## Complete List of All 95 Features in StandardScaler JSON

### Group 1: 600s Window Means (19 Features)
- `HR_mean`
- `ART_SBP_mean`
- `ART_DBP_mean`
- `ART_MBP_mean`
- `PLETH_SPO2_mean`
- `RR_CO2_mean`
- `ETCO2_mean`
- `FIO2_mean`
- `BT_mean`
- `Feature_Pulse_Pressure_mean`
- `Feature_Shock_Index_mean`
- `Feature_Modified_Shock_Index_mean`
- `Feature_Rate_Pressure_Product_mean`
- `Feature_HR_Mean_60s_mean`
- `Feature_HR_Std_60s_mean`
- `Feature_HR_Delta_60s_mean`
- `Feature_MBP_Mean_60s_mean`
- `Feature_MBP_Std_60s_mean`
- `Feature_MBP_Delta_60s_mean`

### Group 2: 600s Window Standard Deviations (19 Features)
- `HR_std`
- `ART_SBP_std`
- `ART_DBP_std`
- `ART_MBP_std`
- `PLETH_SPO2_std`
- `RR_CO2_std`
- `ETCO2_std`
- `FIO2_std`
- `BT_std`
- `Feature_Pulse_Pressure_std`
- `Feature_Shock_Index_std`
- `Feature_Modified_Shock_Index_std`
- `Feature_Rate_Pressure_Product_std`
- `Feature_HR_Mean_60s_std`
- `Feature_HR_Std_60s_std`
- `Feature_HR_Delta_60s_std`
- `Feature_MBP_Mean_60s_std`
- `Feature_MBP_Std_60s_std`
- `Feature_MBP_Delta_60s_std`

### Group 3: 600s Window Minimums (19 Features)
- `HR_min`
- `ART_SBP_min`
- `ART_DBP_min`
- `ART_MBP_min`
- `PLETH_SPO2_min`
- `RR_CO2_min`
- `ETCO2_min`
- `FIO2_min`
- `BT_min`
- `Feature_Pulse_Pressure_min`
- `Feature_Shock_Index_min`
- `Feature_Modified_Shock_Index_min`
- `Feature_Rate_Pressure_Product_min`
- `Feature_HR_Mean_60s_min`
- `Feature_HR_Std_60s_min`
- `Feature_HR_Delta_60s_min`
- `Feature_MBP_Mean_60s_min`
- `Feature_MBP_Std_60s_min`
- `Feature_MBP_Delta_60s_min`

### Group 4: 600s Window Maximums (19 Features)
- `HR_max`
- `ART_SBP_max`
- `ART_DBP_max`
- `ART_MBP_max`
- `PLETH_SPO2_max`
- `RR_CO2_max`
- `ETCO2_max`
- `FIO2_max`
- `BT_max`
- `Feature_Pulse_Pressure_max`
- `Feature_Shock_Index_max`
- `Feature_Modified_Shock_Index_max`
- `Feature_Rate_Pressure_Product_max`
- `Feature_HR_Mean_60s_max`
- `Feature_HR_Std_60s_max`
- `Feature_HR_Delta_60s_max`
- `Feature_MBP_Mean_60s_max`
- `Feature_MBP_Std_60s_max`
- `Feature_MBP_Delta_60s_max`

### Group 5: 600s Window Slopes (19 Features)
- `HR_slope`
- `ART_SBP_slope`
- `ART_DBP_slope`
- `ART_MBP_slope`
- `PLETH_SPO2_slope`
- `RR_CO2_slope`
- `ETCO2_slope`
- `FIO2_slope`
- `BT_slope`
- `Feature_Pulse_Pressure_slope`
- `Feature_Shock_Index_slope`
- `Feature_Modified_Shock_Index_slope`
- `Feature_Rate_Pressure_Product_slope`
- `Feature_HR_Mean_60s_slope`
- `Feature_HR_Std_60s_slope`
- `Feature_HR_Delta_60s_slope`
- `Feature_MBP_Mean_60s_slope`
- `Feature_MBP_Std_60s_slope`
- `Feature_MBP_Delta_60s_slope`
