// Direct C Decision Tree for Future Tachycardia (95 Features, W=600s, STRIDE=5s)
// Direct C Decision Tree Inference Engine for Silicon Labs EFR32
// Supports both class 0 (Normal) and class 1 (Event) percentage outputs at leaf nodes.
#ifndef DECISION_TREE_TYPES_DEFINED
#define DECISION_TREE_TYPES_DEFINED
#include <stdbool.h>

typedef struct {
    float percent_0;   // Percentage probability for Class 0 (0.0% to 100.0%)
    float percent_1;   // Percentage probability for Class 1 (0.0% to 100.0%)
    float prob_0;      // Fractional probability for Class 0 (0.0 to 1.0)
    float prob_1;      // Fractional probability for Class 1 (0.0 to 1.0)
    bool prediction;   // Binary decision (true if prob_1 >= tau)
} DecisionTreeResult;
#endif

static inline DecisionTreeResult predict_tachycardia_95(const float* features) {
    if (features[19] /* HR_std */ <= 1.19222f) {
        if (features[14] /* Feature_HR_Std_60s_mean */ <= 0.55980f) {
            if (features[67] /* Feature_Shock_Index_max */ <= 0.44039f) {
                if (features[67] /* Feature_Shock_Index_max */ <= -0.01388f) {
                    if (features[50] /* Feature_Rate_Pressure_Product_min */ <= 2.20910f) {
                        if (features[45] /* FIO2_min */ <= 1.13554f) {
                            if (features[34] /* Feature_HR_Delta_60s_std */ <= -0.37781f) {
                                if (features[26] /* FIO2_std */ <= 0.30618f) {
                                    if (features[1] /* ART_SBP_mean */ <= -3.08171f) {
                                        if (features[70] /* Feature_HR_Mean_60s_max */ <= 1.39581f) {
                                            if (features[44] /* ETCO2_min */ <= -3.70392f) {
                                                {
                                                    DecisionTreeResult res = { 82.7586f, 17.2414f, 0.82759f, 0.17241f, false };
                                                    return res; /* Class 0: 82.76%, Class 1: 17.24% (tau=0.31) */
                                                }
                                            } else {
                                                if (features[70] /* Feature_HR_Mean_60s_max */ <= 0.50380f) {
                                                    {
                                                        DecisionTreeResult res = { 97.8402f, 2.1598f, 0.97840f, 0.02160f, false };
                                                        return res; /* Class 0: 97.84%, Class 1: 2.16% (tau=0.31) */
                                                    }
                                                } else {
                                                    {
                                                        DecisionTreeResult res = { 88.7480f, 11.2520f, 0.88748f, 0.11252f, false };
                                                        return res; /* Class 0: 88.75%, Class 1: 11.25% (tau=0.31) */
                                                    }
                                                }
                                            }
                                        } else {
                                            {
                                                DecisionTreeResult res = { 42.8571f, 57.1429f, 0.42857f, 0.57143f, true };
                                                return res; /* Class 0: 42.86%, Class 1: 57.14% (tau=0.31) */
                                            }
                                        }
                                    } else {
                                        if (features[13] /* Feature_HR_Mean_60s_mean */ <= 1.04084f) {
                                            if (features[0] /* HR_mean */ <= -0.28450f) {
                                                if (features[65] /* BT_max */ <= 0.53714f) {
                                                    {
                                                        DecisionTreeResult res = { 99.2287f, 0.7713f, 0.99229f, 0.00771f, false };
                                                        return res; /* Class 0: 99.23%, Class 1: 0.77% (tau=0.31) */
                                                    }
                                                } else {
                                                    {
                                                        DecisionTreeResult res = { 91.6667f, 8.3333f, 0.91667f, 0.08333f, false };
                                                        return res; /* Class 0: 91.67%, Class 1: 8.33% (tau=0.31) */
                                                    }
                                                }
                                            } else {
                                                if (features[69] /* Feature_Rate_Pressure_Product_max */ <= 3.03822f) {
                                                    {
                                                        DecisionTreeResult res = { 98.3725f, 1.6275f, 0.98373f, 0.01627f, false };
                                                        return res; /* Class 0: 98.37%, Class 1: 1.63% (tau=0.31) */
                                                    }
                                                } else {
                                                    {
                                                        DecisionTreeResult res = { 50.0000f, 50.0000f, 0.50000f, 0.50000f, true };
                                                        return res; /* Class 0: 50.00%, Class 1: 50.00% (tau=0.31) */
                                                    }
                                                }
                                            }
                                        } else {
                                            if (features[43] /* RR_CO2_min */ <= -2.68488f) {
                                                {
                                                    DecisionTreeResult res = { 12.5000f, 87.5000f, 0.12500f, 0.87500f, true };
                                                    return res; /* Class 0: 12.50%, Class 1: 87.50% (tau=0.31) */
                                                }
                                            } else {
                                                if (features[5] /* RR_CO2_mean */ <= -1.61674f) {
                                                    {
                                                        DecisionTreeResult res = { 0.0000f, 100.0000f, 0.00000f, 1.00000f, true };
                                                        return res; /* Class 0: 0.00%, Class 1: 100.00% (tau=0.31) */
                                                    }
                                                } else {
                                                    {
                                                        DecisionTreeResult res = { 94.6597f, 5.3403f, 0.94660f, 0.05340f, false };
                                                        return res; /* Class 0: 94.66%, Class 1: 5.34% (tau=0.31) */
                                                    }
                                                }
                                            }
                                        }
                                    }
                                } else {
                                    if (features[50] /* Feature_Rate_Pressure_Product_min */ <= 1.86124f) {
                                        if (features[24] /* RR_CO2_std */ <= 0.23095f) {
                                            if (features[33] /* Feature_HR_Std_60s_std */ <= -0.70943f) {
                                                if (features[28] /* Feature_Pulse_Pressure_std */ <= 2.92714f) {
                                                    {
                                                        DecisionTreeResult res = { 95.4945f, 4.5055f, 0.95495f, 0.04505f, false };
                                                        return res; /* Class 0: 95.49%, Class 1: 4.51% (tau=0.31) */
                                                    }
                                                } else {
                                                    {
                                                        DecisionTreeResult res = { 65.3846f, 34.6154f, 0.65385f, 0.34615f, true };
                                                        return res; /* Class 0: 65.38%, Class 1: 34.62% (tau=0.31) */
                                                    }
                                                }
                                            } else {
                                                if (features[12] /* Feature_Rate_Pressure_Product_mean */ <= 0.16940f) {
                                                    {
                                                        DecisionTreeResult res = { 94.1262f, 5.8738f, 0.94126f, 0.05874f, false };
                                                        return res; /* Class 0: 94.13%, Class 1: 5.87% (tau=0.31) */
                                                    }
                                                } else {
                                                    {
                                                        DecisionTreeResult res = { 87.3494f, 12.6506f, 0.87349f, 0.12651f, false };
                                                        return res; /* Class 0: 87.35%, Class 1: 12.65% (tau=0.31) */
                                                    }
                                                }
                                            }
                                        } else {
                                            if (features[84] /* BT_slope */ <= -5.41331f) {
                                                {
                                                    DecisionTreeResult res = { 67.7419f, 32.2581f, 0.67742f, 0.32258f, true };
                                                    return res; /* Class 0: 67.74%, Class 1: 32.26% (tau=0.31) */
                                                }
                                            } else {
                                                if (features[0] /* HR_mean */ <= 1.00986f) {
                                                    {
                                                        DecisionTreeResult res = { 97.0841f, 2.9159f, 0.97084f, 0.02916f, false };
                                                        return res; /* Class 0: 97.08%, Class 1: 2.92% (tau=0.31) */
                                                    }
                                                } else {
                                                    {
                                                        DecisionTreeResult res = { 86.0465f, 13.9535f, 0.86047f, 0.13953f, false };
                                                        return res; /* Class 0: 86.05%, Class 1: 13.95% (tau=0.31) */
                                                    }
                                                }
                                            }
                                        }
                                    } else {
                                        if (features[50] /* Feature_Rate_Pressure_Product_min */ <= 2.06825f) {
                                            if (features[41] /* ART_MBP_min */ <= 1.54498f) {
                                                if (features[39] /* ART_SBP_min */ <= 1.12598f) {
                                                    {
                                                        DecisionTreeResult res = { 46.0000f, 54.0000f, 0.46000f, 0.54000f, true };
                                                        return res; /* Class 0: 46.00%, Class 1: 54.00% (tau=0.31) */
                                                    }
                                                } else {
                                                    {
                                                        DecisionTreeResult res = { 94.0000f, 6.0000f, 0.94000f, 0.06000f, false };
                                                        return res; /* Class 0: 94.00%, Class 1: 6.00% (tau=0.31) */
                                                    }
                                                }
                                            } else {
                                                {
                                                    DecisionTreeResult res = { 32.1429f, 67.8571f, 0.32143f, 0.67857f, true };
                                                    return res; /* Class 0: 32.14%, Class 1: 67.86% (tau=0.31) */
                                                }
                                            }
                                        } else {
                                            if (features[84] /* BT_slope */ <= 0.00500f) {
                                                if (features[14] /* Feature_HR_Std_60s_mean */ <= -0.39678f) {
                                                    {
                                                        DecisionTreeResult res = { 100.0000f, 0.0000f, 1.00000f, 0.00000f, false };
                                                        return res; /* Class 0: 100.00%, Class 1: 0.00% (tau=0.31) */
                                                    }
                                                } else {
                                                    {
                                                        DecisionTreeResult res = { 80.0000f, 20.0000f, 0.80000f, 0.20000f, false };
                                                        return res; /* Class 0: 80.00%, Class 1: 20.00% (tau=0.31) */
                                                    }
                                                }
                                            } else {
                                                {
                                                    DecisionTreeResult res = { 81.8182f, 18.1818f, 0.81818f, 0.18182f, false };
                                                    return res; /* Class 0: 81.82%, Class 1: 18.18% (tau=0.31) */
                                                }
                                            }
                                        }
                                    }
                                }
                            } else {
                                if (features[57] /* HR_max */ <= 0.49079f) {
                                    if (features[7] /* FIO2_mean */ <= -0.11985f) {
                                        if (features[76] /* HR_slope */ <= 1.78851f) {
                                            if (features[83] /* FIO2_slope */ <= 1.67294f) {
                                                if (features[22] /* ART_MBP_std */ <= -0.70733f) {
                                                    {
                                                        DecisionTreeResult res = { 96.4671f, 3.5329f, 0.96467f, 0.03533f, false };
                                                        return res; /* Class 0: 96.47%, Class 1: 3.53% (tau=0.31) */
                                                    }
                                                } else {
                                                    {
                                                        DecisionTreeResult res = { 98.3215f, 1.6785f, 0.98321f, 0.01679f, false };
                                                        return res; /* Class 0: 98.32%, Class 1: 1.68% (tau=0.31) */
                                                    }
                                                }
                                            } else {
                                                if (features[88] /* Feature_Rate_Pressure_Product_slope */ <= 2.21626f) {
                                                    {
                                                        DecisionTreeResult res = { 85.2941f, 14.7059f, 0.85294f, 0.14706f, false };
                                                        return res; /* Class 0: 85.29%, Class 1: 14.71% (tau=0.31) */
                                                    }
                                                } else {
                                                    {
                                                        DecisionTreeResult res = { 28.5714f, 71.4286f, 0.28571f, 0.71429f, true };
                                                        return res; /* Class 0: 28.57%, Class 1: 71.43% (tau=0.31) */
                                                    }
                                                }
                                            }
                                        } else {
                                            if (features[38] /* HR_min */ <= 0.17296f) {
                                                if (features[57] /* HR_max */ <= -0.19170f) {
                                                    {
                                                        DecisionTreeResult res = { 98.3083f, 1.6917f, 0.98308f, 0.01692f, false };
                                                        return res; /* Class 0: 98.31%, Class 1: 1.69% (tau=0.31) */
                                                    }
                                                } else {
                                                    {
                                                        DecisionTreeResult res = { 91.9753f, 8.0247f, 0.91975f, 0.08025f, false };
                                                        return res; /* Class 0: 91.98%, Class 1: 8.02% (tau=0.31) */
                                                    }
                                                }
                                            } else {
                                                if (features[58] /* ART_SBP_max */ <= 0.75490f) {
                                                    {
                                                        DecisionTreeResult res = { 85.5072f, 14.4928f, 0.85507f, 0.14493f, false };
                                                        return res; /* Class 0: 85.51%, Class 1: 14.49% (tau=0.31) */
                                                    }
                                                } else {
                                                    {
                                                        DecisionTreeResult res = { 51.5152f, 48.4848f, 0.51515f, 0.48485f, true };
                                                        return res; /* Class 0: 51.52%, Class 1: 48.48% (tau=0.31) */
                                                    }
                                                }
                                            }
                                        }
                                    } else {
                                        if (features[83] /* FIO2_slope */ <= 3.11801f) {
                                            if (features[10] /* Feature_Shock_Index_mean */ <= -0.59234f) {
                                                if (features[72] /* Feature_HR_Delta_60s_max */ <= 1.56520f) {
                                                    {
                                                        DecisionTreeResult res = { 97.9338f, 2.0662f, 0.97934f, 0.02066f, false };
                                                        return res; /* Class 0: 97.93%, Class 1: 2.07% (tau=0.31) */
                                                    }
                                                } else {
                                                    {
                                                        DecisionTreeResult res = { 70.0000f, 30.0000f, 0.70000f, 0.30000f, false };
                                                        return res; /* Class 0: 70.00%, Class 1: 30.00% (tau=0.31) */
                                                    }
                                                }
                                            } else {
                                                if (features[51] /* Feature_HR_Mean_60s_min */ <= 1.34994f) {
                                                    {
                                                        DecisionTreeResult res = { 95.7184f, 4.2816f, 0.95718f, 0.04282f, false };
                                                        return res; /* Class 0: 95.72%, Class 1: 4.28% (tau=0.31) */
                                                    }
                                                } else {
                                                    {
                                                        DecisionTreeResult res = { 37.5000f, 62.5000f, 0.37500f, 0.62500f, true };
                                                        return res; /* Class 0: 37.50%, Class 1: 62.50% (tau=0.31) */
                                                    }
                                                }
                                            }
                                        } else {
                                            if (features[57] /* HR_max */ <= 0.41050f) {
                                                if (features[63] /* ETCO2_max */ <= 0.16613f) {
                                                    {
                                                        DecisionTreeResult res = { 85.3223f, 14.6777f, 0.85322f, 0.14678f, false };
                                                        return res; /* Class 0: 85.32%, Class 1: 14.68% (tau=0.31) */
                                                    }
                                                } else {
                                                    {
                                                        DecisionTreeResult res = { 92.9502f, 7.0498f, 0.92950f, 0.07050f, false };
                                                        return res; /* Class 0: 92.95%, Class 1: 7.05% (tau=0.31) */
                                                    }
                                                }
                                            } else {
                                                if (features[65] /* BT_max */ <= 0.05957f) {
                                                    {
                                                        DecisionTreeResult res = { 95.8333f, 4.1667f, 0.95833f, 0.04167f, false };
                                                        return res; /* Class 0: 95.83%, Class 1: 4.17% (tau=0.31) */
                                                    }
                                                } else {
                                                    {
                                                        DecisionTreeResult res = { 52.5424f, 47.4576f, 0.52542f, 0.47458f, true };
                                                        return res; /* Class 0: 52.54%, Class 1: 47.46% (tau=0.31) */
                                                    }
                                                }
                                            }
                                        }
                                    }
                                } else {
                                    if (features[13] /* Feature_HR_Mean_60s_mean */ <= 1.47902f) {
                                        if (features[70] /* Feature_HR_Mean_60s_max */ <= 0.95521f) {
                                            if (features[16] /* Feature_MBP_Mean_60s_mean */ <= -0.21004f) {
                                                if (features[91] /* Feature_HR_Delta_60s_slope */ <= 2.29942f) {
                                                    {
                                                        DecisionTreeResult res = { 90.9341f, 9.0659f, 0.90934f, 0.09066f, false };
                                                        return res; /* Class 0: 90.93%, Class 1: 9.07% (tau=0.31) */
                                                    }
                                                } else {
                                                    {
                                                        DecisionTreeResult res = { 55.0000f, 45.0000f, 0.55000f, 0.45000f, true };
                                                        return res; /* Class 0: 55.00%, Class 1: 45.00% (tau=0.31) */
                                                    }
                                                }
                                            } else {
                                                if (features[76] /* HR_slope */ <= 2.25052f) {
                                                    {
                                                        DecisionTreeResult res = { 95.5633f, 4.4367f, 0.95563f, 0.04437f, false };
                                                        return res; /* Class 0: 95.56%, Class 1: 4.44% (tau=0.31) */
                                                    }
                                                } else {
                                                    {
                                                        DecisionTreeResult res = { 70.2703f, 29.7297f, 0.70270f, 0.29730f, false };
                                                        return res; /* Class 0: 70.27%, Class 1: 29.73% (tau=0.31) */
                                                    }
                                                }
                                            }
                                        } else {
                                            if (features[62] /* RR_CO2_max */ <= 3.89086f) {
                                                if (features[77] /* ART_SBP_slope */ <= 0.27738f) {
                                                    {
                                                        DecisionTreeResult res = { 85.6182f, 14.3818f, 0.85618f, 0.14382f, false };
                                                        return res; /* Class 0: 85.62%, Class 1: 14.38% (tau=0.31) */
                                                    }
                                                } else {
                                                    {
                                                        DecisionTreeResult res = { 67.1968f, 32.8032f, 0.67197f, 0.32803f, true };
                                                        return res; /* Class 0: 67.20%, Class 1: 32.80% (tau=0.31) */
                                                    }
                                                }
                                            } else {
                                                {
                                                    DecisionTreeResult res = { 15.0000f, 85.0000f, 0.15000f, 0.85000f, true };
                                                    return res; /* Class 0: 15.00%, Class 1: 85.00% (tau=0.31) */
                                                }
                                            }
                                        }
                                    } else {
                                        if (features[76] /* HR_slope */ <= 0.77210f) {
                                            if (features[0] /* HR_mean */ <= 2.76970f) {
                                                if (features[39] /* ART_SBP_min */ <= 1.64034f) {
                                                    {
                                                        DecisionTreeResult res = { 74.4141f, 25.5859f, 0.74414f, 0.25586f, false };
                                                        return res; /* Class 0: 74.41%, Class 1: 25.59% (tau=0.31) */
                                                    }
                                                } else {
                                                    {
                                                        DecisionTreeResult res = { 0.0000f, 100.0000f, 0.00000f, 1.00000f, true };
                                                        return res; /* Class 0: 0.00%, Class 1: 100.00% (tau=0.31) */
                                                    }
                                                }
                                            } else {
                                                {
                                                    DecisionTreeResult res = { 0.0000f, 100.0000f, 0.00000f, 1.00000f, true };
                                                    return res; /* Class 0: 0.00%, Class 1: 100.00% (tau=0.31) */
                                                }
                                            }
                                        } else {
                                            if (features[75] /* Feature_MBP_Delta_60s_max */ <= 0.34871f) {
                                                if (features[51] /* Feature_HR_Mean_60s_min */ <= 1.36401f) {
                                                    {
                                                        DecisionTreeResult res = { 66.6667f, 33.3333f, 0.66667f, 0.33333f, true };
                                                        return res; /* Class 0: 66.67%, Class 1: 33.33% (tau=0.31) */
                                                    }
                                                } else {
                                                    {
                                                        DecisionTreeResult res = { 23.5294f, 76.4706f, 0.23529f, 0.76471f, true };
                                                        return res; /* Class 0: 23.53%, Class 1: 76.47% (tau=0.31) */
                                                    }
                                                }
                                            } else {
                                                {
                                                    DecisionTreeResult res = { 100.0000f, 0.0000f, 1.00000f, 0.00000f, false };
                                                    return res; /* Class 0: 100.00%, Class 1: 0.00% (tau=0.31) */
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        } else {
                            if (features[6] /* ETCO2_mean */ <= 0.06828f) {
                                if (features[40] /* ART_DBP_min */ <= -0.06226f) {
                                    if (features[10] /* Feature_Shock_Index_mean */ <= 0.56432f) {
                                        if (features[17] /* Feature_MBP_Std_60s_mean */ <= -0.14355f) {
                                            if (features[27] /* BT_std */ <= -0.24783f) {
                                                if (features[26] /* FIO2_std */ <= -0.15024f) {
                                                    {
                                                        DecisionTreeResult res = { 92.3258f, 7.6742f, 0.92326f, 0.07674f, false };
                                                        return res; /* Class 0: 92.33%, Class 1: 7.67% (tau=0.31) */
                                                    }
                                                } else {
                                                    {
                                                        DecisionTreeResult res = { 82.7011f, 17.2989f, 0.82701f, 0.17299f, false };
                                                        return res; /* Class 0: 82.70%, Class 1: 17.30% (tau=0.31) */
                                                    }
                                                }
                                            } else {
                                                if (features[34] /* Feature_HR_Delta_60s_std */ <= -0.85751f) {
                                                    {
                                                        DecisionTreeResult res = { 10.0000f, 90.0000f, 0.10000f, 0.90000f, true };
                                                        return res; /* Class 0: 10.00%, Class 1: 90.00% (tau=0.31) */
                                                    }
                                                } else {
                                                    {
                                                        DecisionTreeResult res = { 82.1764f, 17.8236f, 0.82176f, 0.17824f, false };
                                                        return res; /* Class 0: 82.18%, Class 1: 17.82% (tau=0.31) */
                                                    }
                                                }
                                            }
                                        } else {
                                            if (features[88] /* Feature_Rate_Pressure_Product_slope */ <= 0.06534f) {
                                                if (features[19] /* HR_std */ <= -0.50463f) {
                                                    {
                                                        DecisionTreeResult res = { 90.1099f, 9.8901f, 0.90110f, 0.09890f, false };
                                                        return res; /* Class 0: 90.11%, Class 1: 9.89% (tau=0.31) */
                                                    }
                                                } else {
                                                    {
                                                        DecisionTreeResult res = { 95.9469f, 4.0531f, 0.95947f, 0.04053f, false };
                                                        return res; /* Class 0: 95.95%, Class 1: 4.05% (tau=0.31) */
                                                    }
                                                }
                                            } else {
                                                if (features[7] /* FIO2_mean */ <= 1.92116f) {
                                                    {
                                                        DecisionTreeResult res = { 79.6512f, 20.3488f, 0.79651f, 0.20349f, false };
                                                        return res; /* Class 0: 79.65%, Class 1: 20.35% (tau=0.31) */
                                                    }
                                                } else {
                                                    {
                                                        DecisionTreeResult res = { 90.8595f, 9.1405f, 0.90859f, 0.09141f, false };
                                                        return res; /* Class 0: 90.86%, Class 1: 9.14% (tau=0.31) */
                                                    }
                                                }
                                            }
                                        }
                                    } else {
                                        {
                                            DecisionTreeResult res = { 0.0000f, 100.0000f, 0.00000f, 1.00000f, true };
                                            return res; /* Class 0: 0.00%, Class 1: 100.00% (tau=0.31) */
                                        }
                                    }
                                } else {
                                    if (features[57] /* HR_max */ <= 0.69152f) {
                                        if (features[74] /* Feature_MBP_Std_60s_max */ <= 2.86905f) {
                                            if (features[19] /* HR_std */ <= 0.49158f) {
                                                if (features[16] /* Feature_MBP_Mean_60s_mean */ <= 7.18601f) {
                                                    {
                                                        DecisionTreeResult res = { 94.0946f, 5.9054f, 0.94095f, 0.05905f, false };
                                                        return res; /* Class 0: 94.09%, Class 1: 5.91% (tau=0.31) */
                                                    }
                                                } else {
                                                    {
                                                        DecisionTreeResult res = { 20.0000f, 80.0000f, 0.20000f, 0.80000f, true };
                                                        return res; /* Class 0: 20.00%, Class 1: 80.00% (tau=0.31) */
                                                    }
                                                }
                                            } else {
                                                if (features[30] /* Feature_Modified_Shock_Index_std */ <= 0.07233f) {
                                                    {
                                                        DecisionTreeResult res = { 87.0968f, 12.9032f, 0.87097f, 0.12903f, false };
                                                        return res; /* Class 0: 87.10%, Class 1: 12.90% (tau=0.31) */
                                                    }
                                                } else {
                                                    {
                                                        DecisionTreeResult res = { 60.8108f, 39.1892f, 0.60811f, 0.39189f, true };
                                                        return res; /* Class 0: 60.81%, Class 1: 39.19% (tau=0.31) */
                                                    }
                                                }
                                            }
                                        } else {
                                            if (features[16] /* Feature_MBP_Mean_60s_mean */ <= 0.77552f) {
                                                {
                                                    DecisionTreeResult res = { 47.7273f, 52.2727f, 0.47727f, 0.52273f, true };
                                                    return res; /* Class 0: 47.73%, Class 1: 52.27% (tau=0.31) */
                                                }
                                            } else {
                                                {
                                                    DecisionTreeResult res = { 94.5946f, 5.4054f, 0.94595f, 0.05405f, false };
                                                    return res; /* Class 0: 94.59%, Class 1: 5.41% (tau=0.31) */
                                                }
                                            }
                                        }
                                    } else {
                                        if (features[0] /* HR_mean */ <= 1.51518f) {
                                            if (features[45] /* FIO2_min */ <= 1.83575f) {
                                                if (features[17] /* Feature_MBP_Std_60s_mean */ <= 0.09616f) {
                                                    {
                                                        DecisionTreeResult res = { 98.1481f, 1.8519f, 0.98148f, 0.01852f, false };
                                                        return res; /* Class 0: 98.15%, Class 1: 1.85% (tau=0.31) */
                                                    }
                                                } else {
                                                    {
                                                        DecisionTreeResult res = { 66.6667f, 33.3333f, 0.66667f, 0.33333f, true };
                                                        return res; /* Class 0: 66.67%, Class 1: 33.33% (tau=0.31) */
                                                    }
                                                }
                                            } else {
                                                if (features[41] /* ART_MBP_min */ <= 0.47063f) {
                                                    {
                                                        DecisionTreeResult res = { 37.9310f, 62.0690f, 0.37931f, 0.62069f, true };
                                                        return res; /* Class 0: 37.93%, Class 1: 62.07% (tau=0.31) */
                                                    }
                                                } else {
                                                    {
                                                        DecisionTreeResult res = { 74.2268f, 25.7732f, 0.74227f, 0.25773f, false };
                                                        return res; /* Class 0: 74.23%, Class 1: 25.77% (tau=0.31) */
                                                    }
                                                }
                                            }
                                        } else {
                                            {
                                                DecisionTreeResult res = { 0.0000f, 100.0000f, 0.00000f, 1.00000f, true };
                                                return res; /* Class 0: 0.00%, Class 1: 100.00% (tau=0.31) */
                                            }
                                        }
                                    }
                                }
                            } else {
                                if (features[67] /* Feature_Shock_Index_max */ <= -0.04299f) {
                                    if (features[57] /* HR_max */ <= 1.21342f) {
                                        if (features[6] /* ETCO2_mean */ <= 3.19227f) {
                                            if (features[26] /* FIO2_std */ <= -0.34182f) {
                                                if (features[34] /* Feature_HR_Delta_60s_std */ <= 0.67297f) {
                                                    {
                                                        DecisionTreeResult res = { 97.8329f, 2.1671f, 0.97833f, 0.02167f, false };
                                                        return res; /* Class 0: 97.83%, Class 1: 2.17% (tau=0.31) */
                                                    }
                                                } else {
                                                    {
                                                        DecisionTreeResult res = { 87.1951f, 12.8049f, 0.87195f, 0.12805f, false };
                                                        return res; /* Class 0: 87.20%, Class 1: 12.80% (tau=0.31) */
                                                    }
                                                }
                                            } else {
                                                if (features[13] /* Feature_HR_Mean_60s_mean */ <= 0.84491f) {
                                                    {
                                                        DecisionTreeResult res = { 95.5245f, 4.4755f, 0.95524f, 0.04476f, false };
                                                        return res; /* Class 0: 95.52%, Class 1: 4.48% (tau=0.31) */
                                                    }
                                                } else {
                                                    {
                                                        DecisionTreeResult res = { 76.8340f, 23.1660f, 0.76834f, 0.23166f, false };
                                                        return res; /* Class 0: 76.83%, Class 1: 23.17% (tau=0.31) */
                                                    }
                                                }
                                            }
                                        } else {
                                            {
                                                DecisionTreeResult res = { 40.0000f, 60.0000f, 0.40000f, 0.60000f, true };
                                                return res; /* Class 0: 40.00%, Class 1: 60.00% (tau=0.31) */
                                            }
                                        }
                                    } else {
                                        {
                                            DecisionTreeResult res = { 52.6316f, 47.3684f, 0.52632f, 0.47368f, true };
                                            return res; /* Class 0: 52.63%, Class 1: 47.37% (tau=0.31) */
                                        }
                                    }
                                } else {
                                    if (features[51] /* Feature_HR_Mean_60s_min */ <= -0.86741f) {
                                        {
                                            DecisionTreeResult res = { 37.5000f, 62.5000f, 0.37500f, 0.62500f, true };
                                            return res; /* Class 0: 37.50%, Class 1: 62.50% (tau=0.31) */
                                        }
                                    } else {
                                        if (features[38] /* HR_min */ <= 0.51221f) {
                                            if (features[0] /* HR_mean */ <= -0.76116f) {
                                                {
                                                    DecisionTreeResult res = { 40.0000f, 60.0000f, 0.40000f, 0.60000f, true };
                                                    return res; /* Class 0: 40.00%, Class 1: 60.00% (tau=0.31) */
                                                }
                                            } else {
                                                if (features[8] /* BT_mean */ <= 0.44742f) {
                                                    {
                                                        DecisionTreeResult res = { 95.9184f, 4.0816f, 0.95918f, 0.04082f, false };
                                                        return res; /* Class 0: 95.92%, Class 1: 4.08% (tau=0.31) */
                                                    }
                                                } else {
                                                    {
                                                        DecisionTreeResult res = { 60.0000f, 40.0000f, 0.60000f, 0.40000f, true };
                                                        return res; /* Class 0: 60.00%, Class 1: 40.00% (tau=0.31) */
                                                    }
                                                }
                                            }
                                        } else {
                                            if (features[39] /* ART_SBP_min */ <= -0.10848f) {
                                                {
                                                    DecisionTreeResult res = { 25.0000f, 75.0000f, 0.25000f, 0.75000f, true };
                                                    return res; /* Class 0: 25.00%, Class 1: 75.00% (tau=0.31) */
                                                }
                                            } else {
                                                if (features[72] /* Feature_HR_Delta_60s_max */ <= -0.54084f) {
                                                    {
                                                        DecisionTreeResult res = { 96.4706f, 3.5294f, 0.96471f, 0.03529f, false };
                                                        return res; /* Class 0: 96.47%, Class 1: 3.53% (tau=0.31) */
                                                    }
                                                } else {
                                                    {
                                                        DecisionTreeResult res = { 74.7899f, 25.2101f, 0.74790f, 0.25210f, false };
                                                        return res; /* Class 0: 74.79%, Class 1: 25.21% (tau=0.31) */
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    } else {
                        if (features[68] /* Feature_Modified_Shock_Index_max */ <= -0.09850f) {
                            if (features[51] /* Feature_HR_Mean_60s_min */ <= 2.36607f) {
                                if (features[9] /* Feature_Pulse_Pressure_mean */ <= 1.29010f) {
                                    if (features[14] /* Feature_HR_Std_60s_mean */ <= -0.51691f) {
                                        if (features[40] /* ART_DBP_min */ <= 3.13565f) {
                                            if (features[13] /* Feature_HR_Mean_60s_mean */ <= 1.52425f) {
                                                if (features[26] /* FIO2_std */ <= 1.41567f) {
                                                    {
                                                        DecisionTreeResult res = { 98.4576f, 1.5424f, 0.98458f, 0.01542f, false };
                                                        return res; /* Class 0: 98.46%, Class 1: 1.54% (tau=0.31) */
                                                    }
                                                } else {
                                                    {
                                                        DecisionTreeResult res = { 57.1429f, 42.8571f, 0.57143f, 0.42857f, true };
                                                        return res; /* Class 0: 57.14%, Class 1: 42.86% (tau=0.31) */
                                                    }
                                                }
                                            } else {
                                                if (features[72] /* Feature_HR_Delta_60s_max */ <= -0.59158f) {
                                                    {
                                                        DecisionTreeResult res = { 89.8305f, 10.1695f, 0.89831f, 0.10169f, false };
                                                        return res; /* Class 0: 89.83%, Class 1: 10.17% (tau=0.31) */
                                                    }
                                                } else {
                                                    {
                                                        DecisionTreeResult res = { 60.0000f, 40.0000f, 0.60000f, 0.40000f, true };
                                                        return res; /* Class 0: 60.00%, Class 1: 40.00% (tau=0.31) */
                                                    }
                                                }
                                            }
                                        } else {
                                            {
                                                DecisionTreeResult res = { 20.0000f, 80.0000f, 0.20000f, 0.80000f, true };
                                                return res; /* Class 0: 20.00%, Class 1: 80.00% (tau=0.31) */
                                            }
                                        }
                                    } else {
                                        if (features[21] /* ART_DBP_std */ <= 0.38032f) {
                                            if (features[46] /* BT_min */ <= 0.03849f) {
                                                if (features[9] /* Feature_Pulse_Pressure_mean */ <= -0.59745f) {
                                                    {
                                                        DecisionTreeResult res = { 25.0000f, 75.0000f, 0.25000f, 0.75000f, true };
                                                        return res; /* Class 0: 25.00%, Class 1: 75.00% (tau=0.31) */
                                                    }
                                                } else {
                                                    {
                                                        DecisionTreeResult res = { 67.0455f, 32.9545f, 0.67045f, 0.32955f, true };
                                                        return res; /* Class 0: 67.05%, Class 1: 32.95% (tau=0.31) */
                                                    }
                                                }
                                            } else {
                                                if (features[88] /* Feature_Rate_Pressure_Product_slope */ <= -0.05128f) {
                                                    {
                                                        DecisionTreeResult res = { 90.1099f, 9.8901f, 0.90110f, 0.09890f, false };
                                                        return res; /* Class 0: 90.11%, Class 1: 9.89% (tau=0.31) */
                                                    }
                                                } else {
                                                    {
                                                        DecisionTreeResult res = { 72.6908f, 27.3092f, 0.72691f, 0.27309f, false };
                                                        return res; /* Class 0: 72.69%, Class 1: 27.31% (tau=0.31) */
                                                    }
                                                }
                                            }
                                        } else {
                                            if (features[26] /* FIO2_std */ <= -0.11203f) {
                                                if (features[8] /* BT_mean */ <= 0.20967f) {
                                                    {
                                                        DecisionTreeResult res = { 41.3793f, 58.6207f, 0.41379f, 0.58621f, true };
                                                        return res; /* Class 0: 41.38%, Class 1: 58.62% (tau=0.31) */
                                                    }
                                                } else {
                                                    {
                                                        DecisionTreeResult res = { 85.0000f, 15.0000f, 0.85000f, 0.15000f, false };
                                                        return res; /* Class 0: 85.00%, Class 1: 15.00% (tau=0.31) */
                                                    }
                                                }
                                            } else {
                                                {
                                                    DecisionTreeResult res = { 22.5000f, 77.5000f, 0.22500f, 0.77500f, true };
                                                    return res; /* Class 0: 22.50%, Class 1: 77.50% (tau=0.31) */
                                                }
                                            }
                                        }
                                    }
                                } else {
                                    if (features[14] /* Feature_HR_Std_60s_mean */ <= -0.11087f) {
                                        if (features[12] /* Feature_Rate_Pressure_Product_mean */ <= 2.74129f) {
                                            if (features[50] /* Feature_Rate_Pressure_Product_min */ <= 2.24988f) {
                                                {
                                                    DecisionTreeResult res = { 91.6667f, 8.3333f, 0.91667f, 0.08333f, false };
                                                    return res; /* Class 0: 91.67%, Class 1: 8.33% (tau=0.31) */
                                                }
                                            } else {
                                                if (features[70] /* Feature_HR_Mean_60s_max */ <= -0.01015f) {
                                                    {
                                                        DecisionTreeResult res = { 96.3636f, 3.6364f, 0.96364f, 0.03636f, false };
                                                        return res; /* Class 0: 96.36%, Class 1: 3.64% (tau=0.31) */
                                                    }
                                                } else {
                                                    {
                                                        DecisionTreeResult res = { 99.6988f, 0.3012f, 0.99699f, 0.00301f, false };
                                                        return res; /* Class 0: 99.70%, Class 1: 0.30% (tau=0.31) */
                                                    }
                                                }
                                            }
                                        } else {
                                            if (features[13] /* Feature_HR_Mean_60s_mean */ <= 2.01693f) {
                                                if (features[13] /* Feature_HR_Mean_60s_mean */ <= 1.69705f) {
                                                    {
                                                        DecisionTreeResult res = { 97.8799f, 2.1201f, 0.97880f, 0.02120f, false };
                                                        return res; /* Class 0: 97.88%, Class 1: 2.12% (tau=0.31) */
                                                    }
                                                } else {
                                                    {
                                                        DecisionTreeResult res = { 86.0759f, 13.9241f, 0.86076f, 0.13924f, false };
                                                        return res; /* Class 0: 86.08%, Class 1: 13.92% (tau=0.31) */
                                                    }
                                                }
                                            } else {
                                                {
                                                    DecisionTreeResult res = { 33.3333f, 66.6667f, 0.33333f, 0.66667f, true };
                                                    return res; /* Class 0: 33.33%, Class 1: 66.67% (tau=0.31) */
                                                }
                                            }
                                        }
                                    } else {
                                        if (features[13] /* Feature_HR_Mean_60s_mean */ <= 1.89894f) {
                                            if (features[24] /* RR_CO2_std */ <= 5.36051f) {
                                                if (features[13] /* Feature_HR_Mean_60s_mean */ <= 1.02125f) {
                                                    {
                                                        DecisionTreeResult res = { 99.1597f, 0.8403f, 0.99160f, 0.00840f, false };
                                                        return res; /* Class 0: 99.16%, Class 1: 0.84% (tau=0.31) */
                                                    }
                                                } else {
                                                    {
                                                        DecisionTreeResult res = { 82.2917f, 17.7083f, 0.82292f, 0.17708f, false };
                                                        return res; /* Class 0: 82.29%, Class 1: 17.71% (tau=0.31) */
                                                    }
                                                }
                                            } else {
                                                {
                                                    DecisionTreeResult res = { 20.0000f, 80.0000f, 0.20000f, 0.80000f, true };
                                                    return res; /* Class 0: 20.00%, Class 1: 80.00% (tau=0.31) */
                                                }
                                            }
                                        } else {
                                            {
                                                DecisionTreeResult res = { 18.5185f, 81.4815f, 0.18519f, 0.81481f, true };
                                                return res; /* Class 0: 18.52%, Class 1: 81.48% (tau=0.31) */
                                            }
                                        }
                                    }
                                }
                            } else {
                                if (features[92] /* Feature_MBP_Mean_60s_slope */ <= -0.12669f) {
                                    {
                                        DecisionTreeResult res = { 0.0000f, 100.0000f, 0.00000f, 1.00000f, true };
                                        return res; /* Class 0: 0.00%, Class 1: 100.00% (tau=0.31) */
                                    }
                                } else {
                                    {
                                        DecisionTreeResult res = { 30.0000f, 70.0000f, 0.30000f, 0.70000f, true };
                                        return res; /* Class 0: 30.00%, Class 1: 70.00% (tau=0.31) */
                                    }
                                }
                            }
                        } else {
                            if (features[70] /* Feature_HR_Mean_60s_max */ <= 1.54534f) {
                                if (features[25] /* ETCO2_std */ <= 0.11752f) {
                                    if (features[70] /* Feature_HR_Mean_60s_max */ <= 1.36430f) {
                                        if (features[90] /* Feature_HR_Std_60s_slope */ <= 0.28175f) {
                                            if (features[29] /* Feature_Shock_Index_std */ <= -0.44737f) {
                                                if (features[55] /* Feature_MBP_Std_60s_min */ <= -0.39022f) {
                                                    {
                                                        DecisionTreeResult res = { 100.0000f, 0.0000f, 1.00000f, 0.00000f, false };
                                                        return res; /* Class 0: 100.00%, Class 1: 0.00% (tau=0.31) */
                                                    }
                                                } else {
                                                    {
                                                        DecisionTreeResult res = { 76.7241f, 23.2759f, 0.76724f, 0.23276f, false };
                                                        return res; /* Class 0: 76.72%, Class 1: 23.28% (tau=0.31) */
                                                    }
                                                }
                                            } else {
                                                if (features[68] /* Feature_Modified_Shock_Index_max */ <= 0.92805f) {
                                                    {
                                                        DecisionTreeResult res = { 97.0085f, 2.9915f, 0.97009f, 0.02991f, false };
                                                        return res; /* Class 0: 97.01%, Class 1: 2.99% (tau=0.31) */
                                                    }
                                                } else {
                                                    {
                                                        DecisionTreeResult res = { 66.6667f, 33.3333f, 0.66667f, 0.33333f, true };
                                                        return res; /* Class 0: 66.67%, Class 1: 33.33% (tau=0.31) */
                                                    }
                                                }
                                            }
                                        } else {
                                            if (features[48] /* Feature_Shock_Index_min */ <= 0.66921f) {
                                                if (features[83] /* FIO2_slope */ <= -0.04738f) {
                                                    {
                                                        DecisionTreeResult res = { 100.0000f, 0.0000f, 1.00000f, 0.00000f, false };
                                                        return res; /* Class 0: 100.00%, Class 1: 0.00% (tau=0.31) */
                                                    }
                                                } else {
                                                    {
                                                        DecisionTreeResult res = { 68.3333f, 31.6667f, 0.68333f, 0.31667f, true };
                                                        return res; /* Class 0: 68.33%, Class 1: 31.67% (tau=0.31) */
                                                    }
                                                }
                                            } else {
                                                {
                                                    DecisionTreeResult res = { 16.6667f, 83.3333f, 0.16667f, 0.83333f, true };
                                                    return res; /* Class 0: 16.67%, Class 1: 83.33% (tau=0.31) */
                                                }
                                            }
                                        }
                                    } else {
                                        if (features[16] /* Feature_MBP_Mean_60s_mean */ <= 1.05999f) {
                                            if (features[43] /* RR_CO2_min */ <= 1.23712f) {
                                                if (features[17] /* Feature_MBP_Std_60s_mean */ <= -0.29703f) {
                                                    {
                                                        DecisionTreeResult res = { 67.2414f, 32.7586f, 0.67241f, 0.32759f, true };
                                                        return res; /* Class 0: 67.24%, Class 1: 32.76% (tau=0.31) */
                                                    }
                                                } else {
                                                    {
                                                        DecisionTreeResult res = { 94.4444f, 5.5556f, 0.94444f, 0.05556f, false };
                                                        return res; /* Class 0: 94.44%, Class 1: 5.56% (tau=0.31) */
                                                    }
                                                }
                                            } else {
                                                {
                                                    DecisionTreeResult res = { 20.0000f, 80.0000f, 0.20000f, 0.80000f, true };
                                                    return res; /* Class 0: 20.00%, Class 1: 80.00% (tau=0.31) */
                                                }
                                            }
                                        } else {
                                            {
                                                DecisionTreeResult res = { 0.0000f, 100.0000f, 0.00000f, 1.00000f, true };
                                                return res; /* Class 0: 0.00%, Class 1: 100.00% (tau=0.31) */
                                            }
                                        }
                                    }
                                } else {
                                    if (features[4] /* PLETH_SPO2_mean */ <= -0.17559f) {
                                        {
                                            DecisionTreeResult res = { 35.0000f, 65.0000f, 0.35000f, 0.65000f, true };
                                            return res; /* Class 0: 35.00%, Class 1: 65.00% (tau=0.31) */
                                        }
                                    } else {
                                        if (features[44] /* ETCO2_min */ <= -0.35632f) {
                                            {
                                                DecisionTreeResult res = { 100.0000f, 0.0000f, 1.00000f, 0.00000f, false };
                                                return res; /* Class 0: 100.00%, Class 1: 0.00% (tau=0.31) */
                                            }
                                        } else {
                                            {
                                                DecisionTreeResult res = { 46.8750f, 53.1250f, 0.46875f, 0.53125f, true };
                                                return res; /* Class 0: 46.88%, Class 1: 53.12% (tau=0.31) */
                                            }
                                        }
                                    }
                                }
                            } else {
                                if (features[7] /* FIO2_mean */ <= -0.74402f) {
                                    {
                                        DecisionTreeResult res = { 66.6667f, 33.3333f, 0.66667f, 0.33333f, true };
                                        return res; /* Class 0: 66.67%, Class 1: 33.33% (tau=0.31) */
                                    }
                                } else {
                                    if (features[21] /* ART_DBP_std */ <= 0.36672f) {
                                        if (features[31] /* Feature_Rate_Pressure_Product_std */ <= 0.60646f) {
                                            if (features[54] /* Feature_MBP_Mean_60s_min */ <= 0.73897f) {
                                                {
                                                    DecisionTreeResult res = { 0.0000f, 100.0000f, 0.00000f, 1.00000f, true };
                                                    return res; /* Class 0: 0.00%, Class 1: 100.00% (tau=0.31) */
                                                }
                                            } else {
                                                if (features[87] /* Feature_Modified_Shock_Index_slope */ <= -0.23610f) {
                                                    {
                                                        DecisionTreeResult res = { 54.5455f, 45.4545f, 0.54545f, 0.45455f, true };
                                                        return res; /* Class 0: 54.55%, Class 1: 45.45% (tau=0.31) */
                                                    }
                                                } else {
                                                    {
                                                        DecisionTreeResult res = { 3.1250f, 96.8750f, 0.03125f, 0.96875f, true };
                                                        return res; /* Class 0: 3.12%, Class 1: 96.88% (tau=0.31) */
                                                    }
                                                }
                                            }
                                        } else {
                                            {
                                                DecisionTreeResult res = { 54.5455f, 45.4545f, 0.54545f, 0.45455f, true };
                                                return res; /* Class 0: 54.55%, Class 1: 45.45% (tau=0.31) */
                                            }
                                        }
                                    } else {
                                        {
                                            DecisionTreeResult res = { 48.0000f, 52.0000f, 0.48000f, 0.52000f, true };
                                            return res; /* Class 0: 48.00%, Class 1: 52.00% (tau=0.31) */
                                        }
                                    }
                                }
                            }
                        }
                    }
                } else {
                    if (features[0] /* HR_mean */ <= 2.07398f) {
                        if (features[83] /* FIO2_slope */ <= 1.05363f) {
                            if (features[12] /* Feature_Rate_Pressure_Product_mean */ <= 1.24631f) {
                                if (features[64] /* FIO2_max */ <= 0.45762f) {
                                    if (features[12] /* Feature_Rate_Pressure_Product_mean */ <= 0.79963f) {
                                        if (features[39] /* ART_SBP_min */ <= -0.14277f) {
                                            if (features[90] /* Feature_HR_Std_60s_slope */ <= 1.31342f) {
                                                if (features[52] /* Feature_HR_Std_60s_min */ <= 0.36870f) {
                                                    {
                                                        DecisionTreeResult res = { 97.8973f, 2.1027f, 0.97897f, 0.02103f, false };
                                                        return res; /* Class 0: 97.90%, Class 1: 2.10% (tau=0.31) */
                                                    }
                                                } else {
                                                    {
                                                        DecisionTreeResult res = { 95.1220f, 4.8780f, 0.95122f, 0.04878f, false };
                                                        return res; /* Class 0: 95.12%, Class 1: 4.88% (tau=0.31) */
                                                    }
                                                }
                                            } else {
                                                if (features[62] /* RR_CO2_max */ <= 0.37012f) {
                                                    {
                                                        DecisionTreeResult res = { 91.9137f, 8.0863f, 0.91914f, 0.08086f, false };
                                                        return res; /* Class 0: 91.91%, Class 1: 8.09% (tau=0.31) */
                                                    }
                                                } else {
                                                    {
                                                        DecisionTreeResult res = { 80.3279f, 19.6721f, 0.80328f, 0.19672f, false };
                                                        return res; /* Class 0: 80.33%, Class 1: 19.67% (tau=0.31) */
                                                    }
                                                }
                                            }
                                        } else {
                                            if (features[49] /* Feature_Modified_Shock_Index_min */ <= 2.16986f) {
                                                if (features[15] /* Feature_HR_Delta_60s_mean */ <= 1.24761f) {
                                                    {
                                                        DecisionTreeResult res = { 95.6944f, 4.3056f, 0.95694f, 0.04306f, false };
                                                        return res; /* Class 0: 95.69%, Class 1: 4.31% (tau=0.31) */
                                                    }
                                                } else {
                                                    {
                                                        DecisionTreeResult res = { 86.0465f, 13.9535f, 0.86047f, 0.13953f, false };
                                                        return res; /* Class 0: 86.05%, Class 1: 13.95% (tau=0.31) */
                                                    }
                                                }
                                            } else {
                                                {
                                                    DecisionTreeResult res = { 62.5000f, 37.5000f, 0.62500f, 0.37500f, true };
                                                    return res; /* Class 0: 62.50%, Class 1: 37.50% (tau=0.31) */
                                                }
                                            }
                                        }
                                    } else {
                                        if (features[76] /* HR_slope */ <= 1.32651f) {
                                            if (features[38] /* HR_min */ <= 2.27634f) {
                                                if (features[64] /* FIO2_max */ <= -0.87730f) {
                                                    {
                                                        DecisionTreeResult res = { 77.8210f, 22.1790f, 0.77821f, 0.22179f, false };
                                                        return res; /* Class 0: 77.82%, Class 1: 22.18% (tau=0.31) */
                                                    }
                                                } else {
                                                    {
                                                        DecisionTreeResult res = { 93.4626f, 6.5374f, 0.93463f, 0.06537f, false };
                                                        return res; /* Class 0: 93.46%, Class 1: 6.54% (tau=0.31) */
                                                    }
                                                }
                                            } else {
                                                if (features[65] /* BT_max */ <= 0.07604f) {
                                                    {
                                                        DecisionTreeResult res = { 97.8261f, 2.1739f, 0.97826f, 0.02174f, false };
                                                        return res; /* Class 0: 97.83%, Class 1: 2.17% (tau=0.31) */
                                                    }
                                                } else {
                                                    {
                                                        DecisionTreeResult res = { 68.6567f, 31.3433f, 0.68657f, 0.31343f, true };
                                                        return res; /* Class 0: 68.66%, Class 1: 31.34% (tau=0.31) */
                                                    }
                                                }
                                            }
                                        } else {
                                            if (features[48] /* Feature_Shock_Index_min */ <= 0.62497f) {
                                                if (features[89] /* Feature_HR_Mean_60s_slope */ <= 2.60666f) {
                                                    {
                                                        DecisionTreeResult res = { 80.4878f, 19.5122f, 0.80488f, 0.19512f, false };
                                                        return res; /* Class 0: 80.49%, Class 1: 19.51% (tau=0.31) */
                                                    }
                                                } else {
                                                    {
                                                        DecisionTreeResult res = { 33.3333f, 66.6667f, 0.33333f, 0.66667f, true };
                                                        return res; /* Class 0: 33.33%, Class 1: 66.67% (tau=0.31) */
                                                    }
                                                }
                                            } else {
                                                {
                                                    DecisionTreeResult res = { 34.7826f, 65.2174f, 0.34783f, 0.65217f, true };
                                                    return res; /* Class 0: 34.78%, Class 1: 65.22% (tau=0.31) */
                                                }
                                            }
                                        }
                                    }
                                } else {
                                    if (features[50] /* Feature_Rate_Pressure_Product_min */ <= 0.76627f) {
                                        if (features[76] /* HR_slope */ <= 2.06572f) {
                                            if (features[33] /* Feature_HR_Std_60s_std */ <= 0.62212f) {
                                                if (features[30] /* Feature_Modified_Shock_Index_std */ <= 0.55948f) {
                                                    {
                                                        DecisionTreeResult res = { 92.1012f, 7.8988f, 0.92101f, 0.07899f, false };
                                                        return res; /* Class 0: 92.10%, Class 1: 7.90% (tau=0.31) */
                                                    }
                                                } else {
                                                    {
                                                        DecisionTreeResult res = { 97.3146f, 2.6854f, 0.97315f, 0.02685f, false };
                                                        return res; /* Class 0: 97.31%, Class 1: 2.69% (tau=0.31) */
                                                    }
                                                }
                                            } else {
                                                if (features[78] /* ART_DBP_slope */ <= 0.31203f) {
                                                    {
                                                        DecisionTreeResult res = { 88.8230f, 11.1770f, 0.88823f, 0.11177f, false };
                                                        return res; /* Class 0: 88.82%, Class 1: 11.18% (tau=0.31) */
                                                    }
                                                } else {
                                                    {
                                                        DecisionTreeResult res = { 76.9036f, 23.0964f, 0.76904f, 0.23096f, false };
                                                        return res; /* Class 0: 76.90%, Class 1: 23.10% (tau=0.31) */
                                                    }
                                                }
                                            }
                                        } else {
                                            if (features[67] /* Feature_Shock_Index_max */ <= 0.18906f) {
                                                if (features[69] /* Feature_Rate_Pressure_Product_max */ <= 0.41291f) {
                                                    {
                                                        DecisionTreeResult res = { 88.8889f, 11.1111f, 0.88889f, 0.11111f, false };
                                                        return res; /* Class 0: 88.89%, Class 1: 11.11% (tau=0.31) */
                                                    }
                                                } else {
                                                    {
                                                        DecisionTreeResult res = { 66.6667f, 33.3333f, 0.66667f, 0.33333f, true };
                                                        return res; /* Class 0: 66.67%, Class 1: 33.33% (tau=0.31) */
                                                    }
                                                }
                                            } else {
                                                if (features[52] /* Feature_HR_Std_60s_min */ <= -0.27186f) {
                                                    {
                                                        DecisionTreeResult res = { 31.5789f, 68.4211f, 0.31579f, 0.68421f, true };
                                                        return res; /* Class 0: 31.58%, Class 1: 68.42% (tau=0.31) */
                                                    }
                                                } else {
                                                    {
                                                        DecisionTreeResult res = { 61.8182f, 38.1818f, 0.61818f, 0.38182f, true };
                                                        return res; /* Class 0: 61.82%, Class 1: 38.18% (tau=0.31) */
                                                    }
                                                }
                                            }
                                        }
                                    } else {
                                        if (features[57] /* HR_max */ <= 1.29372f) {
                                            if (features[15] /* Feature_HR_Delta_60s_mean */ <= 1.14979f) {
                                                if (features[44] /* ETCO2_min */ <= -2.76659f) {
                                                    {
                                                        DecisionTreeResult res = { 61.9718f, 38.0282f, 0.61972f, 0.38028f, true };
                                                        return res; /* Class 0: 61.97%, Class 1: 38.03% (tau=0.31) */
                                                    }
                                                } else {
                                                    {
                                                        DecisionTreeResult res = { 89.1409f, 10.8591f, 0.89141f, 0.10859f, false };
                                                        return res; /* Class 0: 89.14%, Class 1: 10.86% (tau=0.31) */
                                                    }
                                                }
                                            } else {
                                                if (features[56] /* Feature_MBP_Delta_60s_min */ <= -2.15950f) {
                                                    {
                                                        DecisionTreeResult res = { 0.0000f, 100.0000f, 0.00000f, 1.00000f, true };
                                                        return res; /* Class 0: 0.00%, Class 1: 100.00% (tau=0.31) */
                                                    }
                                                } else {
                                                    {
                                                        DecisionTreeResult res = { 64.5833f, 35.4167f, 0.64583f, 0.35417f, true };
                                                        return res; /* Class 0: 64.58%, Class 1: 35.42% (tau=0.31) */
                                                    }
                                                }
                                            }
                                        } else {
                                            if (features[33] /* Feature_HR_Std_60s_std */ <= 0.28500f) {
                                                {
                                                    DecisionTreeResult res = { 11.7647f, 88.2353f, 0.11765f, 0.88235f, true };
                                                    return res; /* Class 0: 11.76%, Class 1: 88.24% (tau=0.31) */
                                                }
                                            } else {
                                                if (features[29] /* Feature_Shock_Index_std */ <= -0.31186f) {
                                                    {
                                                        DecisionTreeResult res = { 31.5789f, 68.4211f, 0.31579f, 0.68421f, true };
                                                        return res; /* Class 0: 31.58%, Class 1: 68.42% (tau=0.31) */
                                                    }
                                                } else {
                                                    {
                                                        DecisionTreeResult res = { 83.8235f, 16.1765f, 0.83824f, 0.16176f, false };
                                                        return res; /* Class 0: 83.82%, Class 1: 16.18% (tau=0.31) */
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            } else {
                                if (features[51] /* Feature_HR_Mean_60s_min */ <= 2.08700f) {
                                    if (features[66] /* Feature_Pulse_Pressure_max */ <= -0.48091f) {
                                        if (features[74] /* Feature_MBP_Std_60s_max */ <= -0.51062f) {
                                            if (features[15] /* Feature_HR_Delta_60s_mean */ <= 1.10510f) {
                                                if (features[91] /* Feature_HR_Delta_60s_slope */ <= 1.51415f) {
                                                    {
                                                        DecisionTreeResult res = { 95.4887f, 4.5113f, 0.95489f, 0.04511f, false };
                                                        return res; /* Class 0: 95.49%, Class 1: 4.51% (tau=0.31) */
                                                    }
                                                } else {
                                                    {
                                                        DecisionTreeResult res = { 40.0000f, 60.0000f, 0.40000f, 0.60000f, true };
                                                        return res; /* Class 0: 40.00%, Class 1: 60.00% (tau=0.31) */
                                                    }
                                                }
                                            } else {
                                                {
                                                    DecisionTreeResult res = { 14.2857f, 85.7143f, 0.14286f, 0.85714f, true };
                                                    return res; /* Class 0: 14.29%, Class 1: 85.71% (tau=0.31) */
                                                }
                                            }
                                        } else {
                                            if (features[54] /* Feature_MBP_Mean_60s_min */ <= 0.96081f) {
                                                if (features[34] /* Feature_HR_Delta_60s_std */ <= 0.08364f) {
                                                    {
                                                        DecisionTreeResult res = { 73.2394f, 26.7606f, 0.73239f, 0.26761f, false };
                                                        return res; /* Class 0: 73.24%, Class 1: 26.76% (tau=0.31) */
                                                    }
                                                } else {
                                                    {
                                                        DecisionTreeResult res = { 36.3636f, 63.6364f, 0.36364f, 0.63636f, true };
                                                        return res; /* Class 0: 36.36%, Class 1: 63.64% (tau=0.31) */
                                                    }
                                                }
                                            } else {
                                                if (features[8] /* BT_mean */ <= 0.19922f) {
                                                    {
                                                        DecisionTreeResult res = { 71.4286f, 28.5714f, 0.71429f, 0.28571f, false };
                                                        return res; /* Class 0: 71.43%, Class 1: 28.57% (tau=0.31) */
                                                    }
                                                } else {
                                                    {
                                                        DecisionTreeResult res = { 18.0328f, 81.9672f, 0.18033f, 0.81967f, true };
                                                        return res; /* Class 0: 18.03%, Class 1: 81.97% (tau=0.31) */
                                                    }
                                                }
                                            }
                                        }
                                    } else {
                                        if (features[71] /* Feature_HR_Std_60s_max */ <= -0.37174f) {
                                            if (features[19] /* HR_std */ <= 0.81480f) {
                                                if (features[76] /* HR_slope */ <= 1.32651f) {
                                                    {
                                                        DecisionTreeResult res = { 91.3480f, 8.6520f, 0.91348f, 0.08652f, false };
                                                        return res; /* Class 0: 91.35%, Class 1: 8.65% (tau=0.31) */
                                                    }
                                                } else {
                                                    {
                                                        DecisionTreeResult res = { 43.3333f, 56.6667f, 0.43333f, 0.56667f, true };
                                                        return res; /* Class 0: 43.33%, Class 1: 56.67% (tau=0.31) */
                                                    }
                                                }
                                            } else {
                                                {
                                                    DecisionTreeResult res = { 11.1111f, 88.8889f, 0.11111f, 0.88889f, true };
                                                    return res; /* Class 0: 11.11%, Class 1: 88.89% (tau=0.31) */
                                                }
                                            }
                                        } else {
                                            if (features[69] /* Feature_Rate_Pressure_Product_max */ <= 0.91254f) {
                                                if (features[17] /* Feature_MBP_Std_60s_mean */ <= -0.60653f) {
                                                    {
                                                        DecisionTreeResult res = { 12.5000f, 87.5000f, 0.12500f, 0.87500f, true };
                                                        return res; /* Class 0: 12.50%, Class 1: 87.50% (tau=0.31) */
                                                    }
                                                } else {
                                                    {
                                                        DecisionTreeResult res = { 89.2816f, 10.7184f, 0.89282f, 0.10718f, false };
                                                        return res; /* Class 0: 89.28%, Class 1: 10.72% (tau=0.31) */
                                                    }
                                                }
                                            } else {
                                                if (features[10] /* Feature_Shock_Index_mean */ <= 0.20873f) {
                                                    {
                                                        DecisionTreeResult res = { 84.8408f, 15.1592f, 0.84841f, 0.15159f, false };
                                                        return res; /* Class 0: 84.84%, Class 1: 15.16% (tau=0.31) */
                                                    }
                                                } else {
                                                    {
                                                        DecisionTreeResult res = { 71.1292f, 28.8708f, 0.71129f, 0.28871f, false };
                                                        return res; /* Class 0: 71.13%, Class 1: 28.87% (tau=0.31) */
                                                    }
                                                }
                                            }
                                        }
                                    }
                                } else {
                                    if (features[12] /* Feature_Rate_Pressure_Product_mean */ <= 1.92890f) {
                                        if (features[9] /* Feature_Pulse_Pressure_mean */ <= -0.04261f) {
                                            if (features[28] /* Feature_Pulse_Pressure_std */ <= 0.80473f) {
                                                if (features[18] /* Feature_MBP_Delta_60s_mean */ <= -0.28278f) {
                                                    {
                                                        DecisionTreeResult res = { 86.6667f, 13.3333f, 0.86667f, 0.13333f, false };
                                                        return res; /* Class 0: 86.67%, Class 1: 13.33% (tau=0.31) */
                                                    }
                                                } else {
                                                    {
                                                        DecisionTreeResult res = { 100.0000f, 0.0000f, 1.00000f, 0.00000f, false };
                                                        return res; /* Class 0: 100.00%, Class 1: 0.00% (tau=0.31) */
                                                    }
                                                }
                                            } else {
                                                {
                                                    DecisionTreeResult res = { 42.8571f, 57.1429f, 0.42857f, 0.57143f, true };
                                                    return res; /* Class 0: 42.86%, Class 1: 57.14% (tau=0.31) */
                                                }
                                            }
                                        } else {
                                            if (features[34] /* Feature_HR_Delta_60s_std */ <= -0.43630f) {
                                                if (features[4] /* PLETH_SPO2_mean */ <= -0.15181f) {
                                                    {
                                                        DecisionTreeResult res = { 25.4902f, 74.5098f, 0.25490f, 0.74510f, true };
                                                        return res; /* Class 0: 25.49%, Class 1: 74.51% (tau=0.31) */
                                                    }
                                                } else {
                                                    {
                                                        DecisionTreeResult res = { 77.8761f, 22.1239f, 0.77876f, 0.22124f, false };
                                                        return res; /* Class 0: 77.88%, Class 1: 22.12% (tau=0.31) */
                                                    }
                                                }
                                            } else {
                                                if (features[68] /* Feature_Modified_Shock_Index_max */ <= 0.43791f) {
                                                    {
                                                        DecisionTreeResult res = { 19.5652f, 80.4348f, 0.19565f, 0.80435f, true };
                                                        return res; /* Class 0: 19.57%, Class 1: 80.43% (tau=0.31) */
                                                    }
                                                } else {
                                                    {
                                                        DecisionTreeResult res = { 77.7778f, 22.2222f, 0.77778f, 0.22222f, false };
                                                        return res; /* Class 0: 77.78%, Class 1: 22.22% (tau=0.31) */
                                                    }
                                                }
                                            }
                                        }
                                    } else {
                                        if (features[14] /* Feature_HR_Std_60s_mean */ <= -0.64677f) {
                                            {
                                                DecisionTreeResult res = { 97.2973f, 2.7027f, 0.97297f, 0.02703f, false };
                                                return res; /* Class 0: 97.30%, Class 1: 2.70% (tau=0.31) */
                                            }
                                        } else {
                                            if (features[37] /* Feature_MBP_Delta_60s_std */ <= -0.51940f) {
                                                {
                                                    DecisionTreeResult res = { 100.0000f, 0.0000f, 1.00000f, 0.00000f, false };
                                                    return res; /* Class 0: 100.00%, Class 1: 0.00% (tau=0.31) */
                                                }
                                            } else {
                                                if (features[35] /* Feature_MBP_Mean_60s_std */ <= -0.45243f) {
                                                    {
                                                        DecisionTreeResult res = { 10.9091f, 89.0909f, 0.10909f, 0.89091f, true };
                                                        return res; /* Class 0: 10.91%, Class 1: 89.09% (tau=0.31) */
                                                    }
                                                } else {
                                                    {
                                                        DecisionTreeResult res = { 39.0625f, 60.9375f, 0.39062f, 0.60938f, true };
                                                        return res; /* Class 0: 39.06%, Class 1: 60.94% (tau=0.31) */
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        } else {
                            if (features[57] /* HR_max */ <= 0.24991f) {
                                if (features[55] /* Feature_MBP_Std_60s_min */ <= 0.07241f) {
                                    if (features[4] /* PLETH_SPO2_mean */ <= -0.07501f) {
                                        if (features[13] /* Feature_HR_Mean_60s_mean */ <= 0.94653f) {
                                            if (features[7] /* FIO2_mean */ <= 2.14051f) {
                                                if (features[56] /* Feature_MBP_Delta_60s_min */ <= -2.38118f) {
                                                    {
                                                        DecisionTreeResult res = { 80.0000f, 20.0000f, 0.80000f, 0.20000f, false };
                                                        return res; /* Class 0: 80.00%, Class 1: 20.00% (tau=0.31) */
                                                    }
                                                } else {
                                                    {
                                                        DecisionTreeResult res = { 97.3214f, 2.6786f, 0.97321f, 0.02679f, false };
                                                        return res; /* Class 0: 97.32%, Class 1: 2.68% (tau=0.31) */
                                                    }
                                                }
                                            } else {
                                                {
                                                    DecisionTreeResult res = { 62.5000f, 37.5000f, 0.62500f, 0.37500f, true };
                                                    return res; /* Class 0: 62.50%, Class 1: 37.50% (tau=0.31) */
                                                }
                                            }
                                        } else {
                                            {
                                                DecisionTreeResult res = { 75.0000f, 25.0000f, 0.75000f, 0.25000f, false };
                                                return res; /* Class 0: 75.00%, Class 1: 25.00% (tau=0.31) */
                                            }
                                        }
                                    } else {
                                        if (features[74] /* Feature_MBP_Std_60s_max */ <= -0.49158f) {
                                            if (features[52] /* Feature_HR_Std_60s_min */ <= 0.52241f) {
                                                if (features[19] /* HR_std */ <= 0.67946f) {
                                                    {
                                                        DecisionTreeResult res = { 78.3251f, 21.6749f, 0.78325f, 0.21675f, false };
                                                        return res; /* Class 0: 78.33%, Class 1: 21.67% (tau=0.31) */
                                                    }
                                                } else {
                                                    {
                                                        DecisionTreeResult res = { 0.0000f, 100.0000f, 0.00000f, 1.00000f, true };
                                                        return res; /* Class 0: 0.00%, Class 1: 100.00% (tau=0.31) */
                                                    }
                                                }
                                            } else {
                                                {
                                                    DecisionTreeResult res = { 12.5000f, 87.5000f, 0.12500f, 0.87500f, true };
                                                    return res; /* Class 0: 12.50%, Class 1: 87.50% (tau=0.31) */
                                                }
                                            }
                                        } else {
                                            if (features[2] /* ART_DBP_mean */ <= 0.86332f) {
                                                if (features[10] /* Feature_Shock_Index_mean */ <= -0.19280f) {
                                                    {
                                                        DecisionTreeResult res = { 78.1250f, 21.8750f, 0.78125f, 0.21875f, false };
                                                        return res; /* Class 0: 78.12%, Class 1: 21.88% (tau=0.31) */
                                                    }
                                                } else {
                                                    {
                                                        DecisionTreeResult res = { 91.5367f, 8.4633f, 0.91537f, 0.08463f, false };
                                                        return res; /* Class 0: 91.54%, Class 1: 8.46% (tau=0.31) */
                                                    }
                                                }
                                            } else {
                                                {
                                                    DecisionTreeResult res = { 58.0645f, 41.9355f, 0.58065f, 0.41935f, true };
                                                    return res; /* Class 0: 58.06%, Class 1: 41.94% (tau=0.31) */
                                                }
                                            }
                                        }
                                    }
                                } else {
                                    if (features[19] /* HR_std */ <= -0.62574f) {
                                        {
                                            DecisionTreeResult res = { 91.1765f, 8.8235f, 0.91176f, 0.08824f, false };
                                            return res; /* Class 0: 91.18%, Class 1: 8.82% (tau=0.31) */
                                        }
                                    } else {
                                        if (features[73] /* Feature_MBP_Mean_60s_max */ <= -2.03918f) {
                                            {
                                                DecisionTreeResult res = { 80.0000f, 20.0000f, 0.80000f, 0.20000f, false };
                                                return res; /* Class 0: 80.00%, Class 1: 20.00% (tau=0.31) */
                                            }
                                        } else {
                                            if (features[90] /* Feature_HR_Std_60s_slope */ <= 1.37987f) {
                                                {
                                                    DecisionTreeResult res = { 100.0000f, 0.0000f, 1.00000f, 0.00000f, false };
                                                    return res; /* Class 0: 100.00%, Class 1: 0.00% (tau=0.31) */
                                                }
                                            } else {
                                                {
                                                    DecisionTreeResult res = { 92.3077f, 7.6923f, 0.92308f, 0.07692f, false };
                                                    return res; /* Class 0: 92.31%, Class 1: 7.69% (tau=0.31) */
                                                }
                                            }
                                        }
                                    }
                                }
                            } else {
                                if (features[53] /* Feature_HR_Delta_60s_min */ <= -0.01601f) {
                                    if (features[14] /* Feature_HR_Std_60s_mean */ <= -0.37298f) {
                                        {
                                            DecisionTreeResult res = { 25.0000f, 75.0000f, 0.25000f, 0.75000f, true };
                                            return res; /* Class 0: 25.00%, Class 1: 75.00% (tau=0.31) */
                                        }
                                    } else {
                                        if (features[75] /* Feature_MBP_Delta_60s_max */ <= -0.58411f) {
                                            {
                                                DecisionTreeResult res = { 25.0000f, 75.0000f, 0.25000f, 0.75000f, true };
                                                return res; /* Class 0: 25.00%, Class 1: 75.00% (tau=0.31) */
                                            }
                                        } else {
                                            if (features[55] /* Feature_MBP_Std_60s_min */ <= 0.00775f) {
                                                if (features[92] /* Feature_MBP_Mean_60s_slope */ <= 0.32562f) {
                                                    {
                                                        DecisionTreeResult res = { 87.9032f, 12.0968f, 0.87903f, 0.12097f, false };
                                                        return res; /* Class 0: 87.90%, Class 1: 12.10% (tau=0.31) */
                                                    }
                                                } else {
                                                    {
                                                        DecisionTreeResult res = { 67.3267f, 32.6733f, 0.67327f, 0.32673f, true };
                                                        return res; /* Class 0: 67.33%, Class 1: 32.67% (tau=0.31) */
                                                    }
                                                }
                                            } else {
                                                if (features[88] /* Feature_Rate_Pressure_Product_slope */ <= -0.13635f) {
                                                    {
                                                        DecisionTreeResult res = { 82.5000f, 17.5000f, 0.82500f, 0.17500f, false };
                                                        return res; /* Class 0: 82.50%, Class 1: 17.50% (tau=0.31) */
                                                    }
                                                } else {
                                                    {
                                                        DecisionTreeResult res = { 98.9362f, 1.0638f, 0.98936f, 0.01064f, false };
                                                        return res; /* Class 0: 98.94%, Class 1: 1.06% (tau=0.31) */
                                                    }
                                                }
                                            }
                                        }
                                    }
                                } else {
                                    if (features[75] /* Feature_MBP_Delta_60s_max */ <= 2.49221f) {
                                        if (features[0] /* HR_mean */ <= 0.90496f) {
                                            if (features[48] /* Feature_Shock_Index_min */ <= -0.31778f) {
                                                if (features[89] /* Feature_HR_Mean_60s_slope */ <= 2.00332f) {
                                                    {
                                                        DecisionTreeResult res = { 100.0000f, 0.0000f, 1.00000f, 0.00000f, false };
                                                        return res; /* Class 0: 100.00%, Class 1: 0.00% (tau=0.31) */
                                                    }
                                                } else {
                                                    {
                                                        DecisionTreeResult res = { 66.6667f, 33.3333f, 0.66667f, 0.33333f, true };
                                                        return res; /* Class 0: 66.67%, Class 1: 33.33% (tau=0.31) */
                                                    }
                                                }
                                            } else {
                                                if (features[47] /* Feature_Pulse_Pressure_min */ <= -0.51388f) {
                                                    {
                                                        DecisionTreeResult res = { 97.1014f, 2.8986f, 0.97101f, 0.02899f, false };
                                                        return res; /* Class 0: 97.10%, Class 1: 2.90% (tau=0.31) */
                                                    }
                                                } else {
                                                    {
                                                        DecisionTreeResult res = { 71.6535f, 28.3465f, 0.71654f, 0.28346f, false };
                                                        return res; /* Class 0: 71.65%, Class 1: 28.35% (tau=0.31) */
                                                    }
                                                }
                                            }
                                        } else {
                                            if (features[34] /* Feature_HR_Delta_60s_std */ <= -0.31785f) {
                                                if (features[54] /* Feature_MBP_Mean_60s_min */ <= -0.16601f) {
                                                    {
                                                        DecisionTreeResult res = { 89.4737f, 10.5263f, 0.89474f, 0.10526f, false };
                                                        return res; /* Class 0: 89.47%, Class 1: 10.53% (tau=0.31) */
                                                    }
                                                } else {
                                                    {
                                                        DecisionTreeResult res = { 63.9847f, 36.0153f, 0.63985f, 0.36015f, true };
                                                        return res; /* Class 0: 63.98%, Class 1: 36.02% (tau=0.31) */
                                                    }
                                                }
                                            } else {
                                                if (features[43] /* RR_CO2_min */ <= -1.63901f) {
                                                    {
                                                        DecisionTreeResult res = { 78.3333f, 21.6667f, 0.78333f, 0.21667f, false };
                                                        return res; /* Class 0: 78.33%, Class 1: 21.67% (tau=0.31) */
                                                    }
                                                } else {
                                                    {
                                                        DecisionTreeResult res = { 34.1615f, 65.8385f, 0.34161f, 0.65839f, true };
                                                        return res; /* Class 0: 34.16%, Class 1: 65.84% (tau=0.31) */
                                                    }
                                                }
                                            }
                                        }
                                    } else {
                                        {
                                            DecisionTreeResult res = { 31.4286f, 68.5714f, 0.31429f, 0.68571f, true };
                                            return res; /* Class 0: 31.43%, Class 1: 68.57% (tau=0.31) */
                                        }
                                    }
                                }
                            }
                        }
                    } else {
                        if (features[13] /* Feature_HR_Mean_60s_mean */ <= 2.24082f) {
                            if (features[14] /* Feature_HR_Std_60s_mean */ <= -0.76847f) {
                                {
                                    DecisionTreeResult res = { 91.4286f, 8.5714f, 0.91429f, 0.08571f, false };
                                    return res; /* Class 0: 91.43%, Class 1: 8.57% (tau=0.31) */
                                }
                            } else {
                                if (features[89] /* Feature_HR_Mean_60s_slope */ <= 0.21307f) {
                                    if (features[1] /* ART_SBP_mean */ <= 0.19865f) {
                                        if (features[9] /* Feature_Pulse_Pressure_mean */ <= 0.64082f) {
                                            if (features[54] /* Feature_MBP_Mean_60s_min */ <= 0.18477f) {
                                                {
                                                    DecisionTreeResult res = { 6.0606f, 93.9394f, 0.06061f, 0.93939f, true };
                                                    return res; /* Class 0: 6.06%, Class 1: 93.94% (tau=0.31) */
                                                }
                                            } else {
                                                {
                                                    DecisionTreeResult res = { 37.5000f, 62.5000f, 0.37500f, 0.62500f, true };
                                                    return res; /* Class 0: 37.50%, Class 1: 62.50% (tau=0.31) */
                                                }
                                            }
                                        } else {
                                            {
                                                DecisionTreeResult res = { 83.3333f, 16.6667f, 0.83333f, 0.16667f, false };
                                                return res; /* Class 0: 83.33%, Class 1: 16.67% (tau=0.31) */
                                            }
                                        }
                                    } else {
                                        if (features[43] /* RR_CO2_min */ <= 1.23712f) {
                                            if (features[26] /* FIO2_std */ <= -0.20330f) {
                                                if (features[5] /* RR_CO2_mean */ <= -1.35655f) {
                                                    {
                                                        DecisionTreeResult res = { 0.0000f, 100.0000f, 0.00000f, 1.00000f, true };
                                                        return res; /* Class 0: 0.00%, Class 1: 100.00% (tau=0.31) */
                                                    }
                                                } else {
                                                    {
                                                        DecisionTreeResult res = { 77.3810f, 22.6190f, 0.77381f, 0.22619f, false };
                                                        return res; /* Class 0: 77.38%, Class 1: 22.62% (tau=0.31) */
                                                    }
                                                }
                                            } else {
                                                {
                                                    DecisionTreeResult res = { 30.0000f, 70.0000f, 0.30000f, 0.70000f, true };
                                                    return res; /* Class 0: 30.00%, Class 1: 70.00% (tau=0.31) */
                                                }
                                            }
                                        } else {
                                            if (features[44] /* ETCO2_min */ <= 1.45138f) {
                                                if (features[63] /* ETCO2_max */ <= 1.15487f) {
                                                    {
                                                        DecisionTreeResult res = { 15.2174f, 84.7826f, 0.15217f, 0.84783f, true };
                                                        return res; /* Class 0: 15.22%, Class 1: 84.78% (tau=0.31) */
                                                    }
                                                } else {
                                                    {
                                                        DecisionTreeResult res = { 80.0000f, 20.0000f, 0.80000f, 0.20000f, false };
                                                        return res; /* Class 0: 80.00%, Class 1: 20.00% (tau=0.31) */
                                                    }
                                                }
                                            } else {
                                                {
                                                    DecisionTreeResult res = { 100.0000f, 0.0000f, 1.00000f, 0.00000f, false };
                                                    return res; /* Class 0: 100.00%, Class 1: 0.00% (tau=0.31) */
                                                }
                                            }
                                        }
                                    }
                                } else {
                                    if (features[90] /* Feature_HR_Std_60s_slope */ <= 0.00007f) {
                                        if (features[63] /* ETCO2_max */ <= 0.56162f) {
                                            if (features[46] /* BT_min */ <= 0.42770f) {
                                                if (features[48] /* Feature_Shock_Index_min */ <= 0.96277f) {
                                                    {
                                                        DecisionTreeResult res = { 6.1224f, 93.8776f, 0.06122f, 0.93878f, true };
                                                        return res; /* Class 0: 6.12%, Class 1: 93.88% (tau=0.31) */
                                                    }
                                                } else {
                                                    {
                                                        DecisionTreeResult res = { 27.2727f, 72.7273f, 0.27273f, 0.72727f, true };
                                                        return res; /* Class 0: 27.27%, Class 1: 72.73% (tau=0.31) */
                                                    }
                                                }
                                            } else {
                                                {
                                                    DecisionTreeResult res = { 72.7273f, 27.2727f, 0.72727f, 0.27273f, false };
                                                    return res; /* Class 0: 72.73%, Class 1: 27.27% (tau=0.31) */
                                                }
                                            }
                                        } else {
                                            {
                                                DecisionTreeResult res = { 54.7619f, 45.2381f, 0.54762f, 0.45238f, true };
                                                return res; /* Class 0: 54.76%, Class 1: 45.24% (tau=0.31) */
                                            }
                                        }
                                    } else {
                                        if (features[54] /* Feature_MBP_Mean_60s_min */ <= 0.28488f) {
                                            {
                                                DecisionTreeResult res = { 0.0000f, 100.0000f, 0.00000f, 1.00000f, true };
                                                return res; /* Class 0: 0.00%, Class 1: 100.00% (tau=0.31) */
                                            }
                                        } else {
                                            if (features[42] /* PLETH_SPO2_min */ <= 0.33752f) {
                                                {
                                                    DecisionTreeResult res = { 38.8889f, 61.1111f, 0.38889f, 0.61111f, true };
                                                    return res; /* Class 0: 38.89%, Class 1: 61.11% (tau=0.31) */
                                                }
                                            } else {
                                                if (features[39] /* ART_SBP_min */ <= 0.47446f) {
                                                    {
                                                        DecisionTreeResult res = { 37.5000f, 62.5000f, 0.37500f, 0.62500f, true };
                                                        return res; /* Class 0: 37.50%, Class 1: 62.50% (tau=0.31) */
                                                    }
                                                } else {
                                                    {
                                                        DecisionTreeResult res = { 2.1739f, 97.8261f, 0.02174f, 0.97826f, true };
                                                        return res; /* Class 0: 2.17%, Class 1: 97.83% (tau=0.31) */
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        } else {
                            if (features[89] /* Feature_HR_Mean_60s_slope */ <= 0.04492f) {
                                if (features[51] /* Feature_HR_Mean_60s_min */ <= 2.66933f) {
                                    if (features[68] /* Feature_Modified_Shock_Index_max */ <= -0.05865f) {
                                        {
                                            DecisionTreeResult res = { 90.4762f, 9.5238f, 0.90476f, 0.09524f, false };
                                            return res; /* Class 0: 90.48%, Class 1: 9.52% (tau=0.31) */
                                        }
                                    } else {
                                        if (features[6] /* ETCO2_mean */ <= 1.28794f) {
                                            if (features[31] /* Feature_Rate_Pressure_Product_std */ <= -0.64923f) {
                                                {
                                                    DecisionTreeResult res = { 0.0000f, 100.0000f, 0.00000f, 1.00000f, true };
                                                    return res; /* Class 0: 0.00%, Class 1: 100.00% (tau=0.31) */
                                                }
                                            } else {
                                                if (features[71] /* Feature_HR_Std_60s_max */ <= -0.81702f) {
                                                    {
                                                        DecisionTreeResult res = { 77.7778f, 22.2222f, 0.77778f, 0.22222f, false };
                                                        return res; /* Class 0: 77.78%, Class 1: 22.22% (tau=0.31) */
                                                    }
                                                } else {
                                                    {
                                                        DecisionTreeResult res = { 25.5319f, 74.4681f, 0.25532f, 0.74468f, true };
                                                        return res; /* Class 0: 25.53%, Class 1: 74.47% (tau=0.31) */
                                                    }
                                                }
                                            }
                                        } else {
                                            {
                                                DecisionTreeResult res = { 73.0769f, 26.9231f, 0.73077f, 0.26923f, false };
                                                return res; /* Class 0: 73.08%, Class 1: 26.92% (tau=0.31) */
                                            }
                                        }
                                    }
                                } else {
                                    if (features[31] /* Feature_Rate_Pressure_Product_std */ <= -0.90041f) {
                                        {
                                            DecisionTreeResult res = { 77.7778f, 22.2222f, 0.77778f, 0.22222f, false };
                                            return res; /* Class 0: 77.78%, Class 1: 22.22% (tau=0.31) */
                                        }
                                    } else {
                                        if (features[88] /* Feature_Rate_Pressure_Product_slope */ <= -1.12870f) {
                                            {
                                                DecisionTreeResult res = { 21.8750f, 78.1250f, 0.21875f, 0.78125f, true };
                                                return res; /* Class 0: 21.88%, Class 1: 78.12% (tau=0.31) */
                                            }
                                        } else {
                                            if (features[0] /* HR_mean */ <= 2.41921f) {
                                                {
                                                    DecisionTreeResult res = { 9.0909f, 90.9091f, 0.09091f, 0.90909f, true };
                                                    return res; /* Class 0: 9.09%, Class 1: 90.91% (tau=0.31) */
                                                }
                                            } else {
                                                if (features[16] /* Feature_MBP_Mean_60s_mean */ <= -0.27835f) {
                                                    {
                                                        DecisionTreeResult res = { 20.0000f, 80.0000f, 0.20000f, 0.80000f, true };
                                                        return res; /* Class 0: 20.00%, Class 1: 80.00% (tau=0.31) */
                                                    }
                                                } else {
                                                    {
                                                        DecisionTreeResult res = { 0.0000f, 100.0000f, 0.00000f, 1.00000f, true };
                                                        return res; /* Class 0: 0.00%, Class 1: 100.00% (tau=0.31) */
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            } else {
                                if (features[51] /* Feature_HR_Mean_60s_min */ <= 1.20703f) {
                                    {
                                        DecisionTreeResult res = { 60.0000f, 40.0000f, 0.60000f, 0.40000f, true };
                                        return res; /* Class 0: 60.00%, Class 1: 40.00% (tau=0.31) */
                                    }
                                } else {
                                    if (features[59] /* ART_DBP_max */ <= 2.88154f) {
                                        if (features[2] /* ART_DBP_mean */ <= 1.55493f) {
                                            if (features[37] /* Feature_MBP_Delta_60s_std */ <= -0.31795f) {
                                                if (features[48] /* Feature_Shock_Index_min */ <= 0.35568f) {
                                                    {
                                                        DecisionTreeResult res = { 37.5000f, 62.5000f, 0.37500f, 0.62500f, true };
                                                        return res; /* Class 0: 37.50%, Class 1: 62.50% (tau=0.31) */
                                                    }
                                                } else {
                                                    {
                                                        DecisionTreeResult res = { 3.9841f, 96.0159f, 0.03984f, 0.96016f, true };
                                                        return res; /* Class 0: 3.98%, Class 1: 96.02% (tau=0.31) */
                                                    }
                                                }
                                            } else {
                                                {
                                                    DecisionTreeResult res = { 0.0000f, 100.0000f, 0.00000f, 1.00000f, true };
                                                    return res; /* Class 0: 0.00%, Class 1: 100.00% (tau=0.31) */
                                                }
                                            }
                                        } else {
                                            {
                                                DecisionTreeResult res = { 26.6667f, 73.3333f, 0.26667f, 0.73333f, true };
                                                return res; /* Class 0: 26.67%, Class 1: 73.33% (tau=0.31) */
                                            }
                                        }
                                    } else {
                                        {
                                            DecisionTreeResult res = { 37.5000f, 62.5000f, 0.37500f, 0.62500f, true };
                                            return res; /* Class 0: 37.50%, Class 1: 62.50% (tau=0.31) */
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            } else {
                if (features[54] /* Feature_MBP_Mean_60s_min */ <= -1.56912f) {
                    if (features[70] /* Feature_HR_Mean_60s_max */ <= 1.64784f) {
                        if (features[20] /* ART_SBP_std */ <= -0.77338f) {
                            if (features[50] /* Feature_Rate_Pressure_Product_min */ <= -1.40390f) {
                                if (features[75] /* Feature_MBP_Delta_60s_max */ <= -0.58411f) {
                                    if (features[49] /* Feature_Modified_Shock_Index_min */ <= 12.42286f) {
                                        if (features[56] /* Feature_MBP_Delta_60s_min */ <= 0.71581f) {
                                            if (features[70] /* Feature_HR_Mean_60s_max */ <= 0.39094f) {
                                                if (features[7] /* FIO2_mean */ <= 2.58709f) {
                                                    {
                                                        DecisionTreeResult res = { 98.7113f, 1.2887f, 0.98711f, 0.01289f, false };
                                                        return res; /* Class 0: 98.71%, Class 1: 1.29% (tau=0.31) */
                                                    }
                                                } else {
                                                    {
                                                        DecisionTreeResult res = { 20.0000f, 80.0000f, 0.20000f, 0.80000f, true };
                                                        return res; /* Class 0: 20.00%, Class 1: 80.00% (tau=0.31) */
                                                    }
                                                }
                                            } else {
                                                {
                                                    DecisionTreeResult res = { 75.8621f, 24.1379f, 0.75862f, 0.24138f, false };
                                                    return res; /* Class 0: 75.86%, Class 1: 24.14% (tau=0.31) */
                                                }
                                            }
                                        } else {
                                            {
                                                DecisionTreeResult res = { 57.1429f, 42.8571f, 0.57143f, 0.42857f, true };
                                                return res; /* Class 0: 57.14%, Class 1: 42.86% (tau=0.31) */
                                            }
                                        }
                                    } else {
                                        {
                                            DecisionTreeResult res = { 30.7692f, 69.2308f, 0.30769f, 0.69231f, true };
                                            return res; /* Class 0: 30.77%, Class 1: 69.23% (tau=0.31) */
                                        }
                                    }
                                } else {
                                    {
                                        DecisionTreeResult res = { 100.0000f, 0.0000f, 1.00000f, 0.00000f, false };
                                        return res; /* Class 0: 100.00%, Class 1: 0.00% (tau=0.31) */
                                    }
                                }
                            } else {
                                if (features[1] /* ART_SBP_mean */ <= -2.50672f) {
                                    if (features[17] /* Feature_MBP_Std_60s_mean */ <= -0.25517f) {
                                        if (features[50] /* Feature_Rate_Pressure_Product_min */ <= -1.30611f) {
                                            {
                                                DecisionTreeResult res = { 34.6154f, 65.3846f, 0.34615f, 0.65385f, true };
                                                return res; /* Class 0: 34.62%, Class 1: 65.38% (tau=0.31) */
                                            }
                                        } else {
                                            {
                                                DecisionTreeResult res = { 4.0000f, 96.0000f, 0.04000f, 0.96000f, true };
                                                return res; /* Class 0: 4.00%, Class 1: 96.00% (tau=0.31) */
                                            }
                                        }
                                    } else {
                                        {
                                            DecisionTreeResult res = { 100.0000f, 0.0000f, 1.00000f, 0.00000f, false };
                                            return res; /* Class 0: 100.00%, Class 1: 0.00% (tau=0.31) */
                                        }
                                    }
                                } else {
                                    if (features[46] /* BT_min */ <= 0.50879f) {
                                        if (features[49] /* Feature_Modified_Shock_Index_min */ <= 9.64177f) {
                                            if (features[27] /* BT_std */ <= -0.03369f) {
                                                if (features[2] /* ART_DBP_mean */ <= -1.54331f) {
                                                    {
                                                        DecisionTreeResult res = { 96.2963f, 3.7037f, 0.96296f, 0.03704f, false };
                                                        return res; /* Class 0: 96.30%, Class 1: 3.70% (tau=0.31) */
                                                    }
                                                } else {
                                                    {
                                                        DecisionTreeResult res = { 83.3333f, 16.6667f, 0.83333f, 0.16667f, false };
                                                        return res; /* Class 0: 83.33%, Class 1: 16.67% (tau=0.31) */
                                                    }
                                                }
                                            } else {
                                                {
                                                    DecisionTreeResult res = { 23.0769f, 76.9231f, 0.23077f, 0.76923f, true };
                                                    return res; /* Class 0: 23.08%, Class 1: 76.92% (tau=0.31) */
                                                }
                                            }
                                        } else {
                                            {
                                                DecisionTreeResult res = { 50.0000f, 50.0000f, 0.50000f, 0.50000f, true };
                                                return res; /* Class 0: 50.00%, Class 1: 50.00% (tau=0.31) */
                                            }
                                        }
                                    } else {
                                        {
                                            DecisionTreeResult res = { 0.0000f, 100.0000f, 0.00000f, 1.00000f, true };
                                            return res; /* Class 0: 0.00%, Class 1: 100.00% (tau=0.31) */
                                        }
                                    }
                                }
                            }
                        } else {
                            if (features[49] /* Feature_Modified_Shock_Index_min */ <= 8.98122f) {
                                if (features[79] /* ART_MBP_slope */ <= -8.57479f) {
                                    {
                                        DecisionTreeResult res = { 16.6667f, 83.3333f, 0.16667f, 0.83333f, true };
                                        return res; /* Class 0: 16.67%, Class 1: 83.33% (tau=0.31) */
                                    }
                                } else {
                                    if (features[13] /* Feature_HR_Mean_60s_mean */ <= 0.91634f) {
                                        if (features[77] /* ART_SBP_slope */ <= 5.01678f) {
                                            if (features[76] /* HR_slope */ <= 3.54414f) {
                                                if (features[8] /* BT_mean */ <= 0.38369f) {
                                                    {
                                                        DecisionTreeResult res = { 97.9441f, 2.0559f, 0.97944f, 0.02056f, false };
                                                        return res; /* Class 0: 97.94%, Class 1: 2.06% (tau=0.31) */
                                                    }
                                                } else {
                                                    {
                                                        DecisionTreeResult res = { 89.9329f, 10.0671f, 0.89933f, 0.10067f, false };
                                                        return res; /* Class 0: 89.93%, Class 1: 10.07% (tau=0.31) */
                                                    }
                                                }
                                            } else {
                                                {
                                                    DecisionTreeResult res = { 50.0000f, 50.0000f, 0.50000f, 0.50000f, true };
                                                    return res; /* Class 0: 50.00%, Class 1: 50.00% (tau=0.31) */
                                                }
                                            }
                                        } else {
                                            if (features[54] /* Feature_MBP_Mean_60s_min */ <= -1.89107f) {
                                                if (features[7] /* FIO2_mean */ <= 0.26323f) {
                                                    {
                                                        DecisionTreeResult res = { 77.4194f, 22.5806f, 0.77419f, 0.22581f, false };
                                                        return res; /* Class 0: 77.42%, Class 1: 22.58% (tau=0.31) */
                                                    }
                                                } else {
                                                    {
                                                        DecisionTreeResult res = { 98.0952f, 1.9048f, 0.98095f, 0.01905f, false };
                                                        return res; /* Class 0: 98.10%, Class 1: 1.90% (tau=0.31) */
                                                    }
                                                }
                                            } else {
                                                {
                                                    DecisionTreeResult res = { 62.5000f, 37.5000f, 0.62500f, 0.37500f, true };
                                                    return res; /* Class 0: 62.50%, Class 1: 37.50% (tau=0.31) */
                                                }
                                            }
                                        }
                                    } else {
                                        if (features[5] /* RR_CO2_mean */ <= -0.07699f) {
                                            if (features[65] /* BT_max */ <= -0.92850f) {
                                                if (features[49] /* Feature_Modified_Shock_Index_min */ <= -0.14809f) {
                                                    {
                                                        DecisionTreeResult res = { 92.3077f, 7.6923f, 0.92308f, 0.07692f, false };
                                                        return res; /* Class 0: 92.31%, Class 1: 7.69% (tau=0.31) */
                                                    }
                                                } else {
                                                    {
                                                        DecisionTreeResult res = { 53.2609f, 46.7391f, 0.53261f, 0.46739f, true };
                                                        return res; /* Class 0: 53.26%, Class 1: 46.74% (tau=0.31) */
                                                    }
                                                }
                                            } else {
                                                if (features[35] /* Feature_MBP_Mean_60s_std */ <= -0.85431f) {
                                                    {
                                                        DecisionTreeResult res = { 0.0000f, 100.0000f, 0.00000f, 1.00000f, true };
                                                        return res; /* Class 0: 0.00%, Class 1: 100.00% (tau=0.31) */
                                                    }
                                                } else {
                                                    {
                                                        DecisionTreeResult res = { 86.4919f, 13.5081f, 0.86492f, 0.13508f, false };
                                                        return res; /* Class 0: 86.49%, Class 1: 13.51% (tau=0.31) */
                                                    }
                                                }
                                            }
                                        } else {
                                            if (features[60] /* ART_MBP_max */ <= 2.46759f) {
                                                if (features[8] /* BT_mean */ <= -3.33271f) {
                                                    {
                                                        DecisionTreeResult res = { 70.0000f, 30.0000f, 0.70000f, 0.30000f, false };
                                                        return res; /* Class 0: 70.00%, Class 1: 30.00% (tau=0.31) */
                                                    }
                                                } else {
                                                    {
                                                        DecisionTreeResult res = { 99.0385f, 0.9615f, 0.99038f, 0.00962f, false };
                                                        return res; /* Class 0: 99.04%, Class 1: 0.96% (tau=0.31) */
                                                    }
                                                }
                                            } else {
                                                {
                                                    DecisionTreeResult res = { 50.0000f, 50.0000f, 0.50000f, 0.50000f, true };
                                                    return res; /* Class 0: 50.00%, Class 1: 50.00% (tau=0.31) */
                                                }
                                            }
                                        }
                                    }
                                }
                            } else {
                                {
                                    DecisionTreeResult res = { 42.8571f, 57.1429f, 0.42857f, 0.57143f, true };
                                    return res; /* Class 0: 42.86%, Class 1: 57.14% (tau=0.31) */
                                }
                            }
                        }
                    } else {
                        if (features[68] /* Feature_Modified_Shock_Index_max */ <= 5.88961f) {
                            if (features[50] /* Feature_Rate_Pressure_Product_min */ <= -1.28718f) {
                                if (features[25] /* ETCO2_std */ <= -0.11542f) {
                                    {
                                        DecisionTreeResult res = { 0.0000f, 100.0000f, 0.00000f, 1.00000f, true };
                                        return res; /* Class 0: 0.00%, Class 1: 100.00% (tau=0.31) */
                                    }
                                } else {
                                    if (features[41] /* ART_MBP_min */ <= -2.05955f) {
                                        if (features[41] /* ART_MBP_min */ <= -2.17632f) {
                                            {
                                                DecisionTreeResult res = { 62.5000f, 37.5000f, 0.62500f, 0.37500f, true };
                                                return res; /* Class 0: 62.50%, Class 1: 37.50% (tau=0.31) */
                                            }
                                        } else {
                                            {
                                                DecisionTreeResult res = { 97.7273f, 2.2727f, 0.97727f, 0.02273f, false };
                                                return res; /* Class 0: 97.73%, Class 1: 2.27% (tau=0.31) */
                                            }
                                        }
                                    } else {
                                        {
                                            DecisionTreeResult res = { 47.0588f, 52.9412f, 0.47059f, 0.52941f, true };
                                            return res; /* Class 0: 47.06%, Class 1: 52.94% (tau=0.31) */
                                        }
                                    }
                                }
                            } else {
                                if (features[15] /* Feature_HR_Delta_60s_mean */ <= -0.02066f) {
                                    if (features[0] /* HR_mean */ <= 2.40436f) {
                                        if (features[60] /* ART_MBP_max */ <= -1.52936f) {
                                            {
                                                DecisionTreeResult res = { 0.0000f, 100.0000f, 0.00000f, 1.00000f, true };
                                                return res; /* Class 0: 0.00%, Class 1: 100.00% (tau=0.31) */
                                            }
                                        } else {
                                            if (features[71] /* Feature_HR_Std_60s_max */ <= 0.02394f) {
                                                {
                                                    DecisionTreeResult res = { 93.4783f, 6.5217f, 0.93478f, 0.06522f, false };
                                                    return res; /* Class 0: 93.48%, Class 1: 6.52% (tau=0.31) */
                                                }
                                            } else {
                                                {
                                                    DecisionTreeResult res = { 71.8750f, 28.1250f, 0.71875f, 0.28125f, false };
                                                    return res; /* Class 0: 71.88%, Class 1: 28.12% (tau=0.31) */
                                                }
                                            }
                                        }
                                    } else {
                                        if (features[2] /* ART_DBP_mean */ <= -1.99050f) {
                                            {
                                                DecisionTreeResult res = { 12.5000f, 87.5000f, 0.12500f, 0.87500f, true };
                                                return res; /* Class 0: 12.50%, Class 1: 87.50% (tau=0.31) */
                                            }
                                        } else {
                                            if (features[68] /* Feature_Modified_Shock_Index_max */ <= 3.31100f) {
                                                {
                                                    DecisionTreeResult res = { 20.0000f, 80.0000f, 0.20000f, 0.80000f, true };
                                                    return res; /* Class 0: 20.00%, Class 1: 80.00% (tau=0.31) */
                                                }
                                            } else {
                                                {
                                                    DecisionTreeResult res = { 0.0000f, 100.0000f, 0.00000f, 1.00000f, true };
                                                    return res; /* Class 0: 0.00%, Class 1: 100.00% (tau=0.31) */
                                                }
                                            }
                                        }
                                    }
                                } else {
                                    if (features[39] /* ART_SBP_min */ <= -1.84016f) {
                                        if (features[64] /* FIO2_max */ <= 1.97052f) {
                                            {
                                                DecisionTreeResult res = { 0.0000f, 100.0000f, 0.00000f, 1.00000f, true };
                                                return res; /* Class 0: 0.00%, Class 1: 100.00% (tau=0.31) */
                                            }
                                        } else {
                                            {
                                                DecisionTreeResult res = { 20.0000f, 80.0000f, 0.20000f, 0.80000f, true };
                                                return res; /* Class 0: 20.00%, Class 1: 80.00% (tau=0.31) */
                                            }
                                        }
                                    } else {
                                        {
                                            DecisionTreeResult res = { 25.0000f, 75.0000f, 0.25000f, 0.75000f, true };
                                            return res; /* Class 0: 25.00%, Class 1: 75.00% (tau=0.31) */
                                        }
                                    }
                                }
                            }
                        } else {
                            if (features[38] /* HR_min */ <= 2.61559f) {
                                if (features[20] /* ART_SBP_std */ <= 2.71085f) {
                                    if (features[3] /* ART_MBP_mean */ <= -2.67254f) {
                                        {
                                            DecisionTreeResult res = { 71.4286f, 28.5714f, 0.71429f, 0.28571f, false };
                                            return res; /* Class 0: 71.43%, Class 1: 28.57% (tau=0.31) */
                                        }
                                    } else {
                                        if (features[43] /* RR_CO2_min */ <= -1.90048f) {
                                            {
                                                DecisionTreeResult res = { 33.3333f, 66.6667f, 0.33333f, 0.66667f, true };
                                                return res; /* Class 0: 33.33%, Class 1: 66.67% (tau=0.31) */
                                            }
                                        } else {
                                            {
                                                DecisionTreeResult res = { 2.1277f, 97.8723f, 0.02128f, 0.97872f, true };
                                                return res; /* Class 0: 2.13%, Class 1: 97.87% (tau=0.31) */
                                            }
                                        }
                                    }
                                } else {
                                    {
                                        DecisionTreeResult res = { 61.1111f, 38.8889f, 0.61111f, 0.38889f, true };
                                        return res; /* Class 0: 61.11%, Class 1: 38.89% (tau=0.31) */
                                    }
                                }
                            } else {
                                if (features[26] /* FIO2_std */ <= -0.42424f) {
                                    {
                                        DecisionTreeResult res = { 11.7647f, 88.2353f, 0.11765f, 0.88235f, true };
                                        return res; /* Class 0: 11.76%, Class 1: 88.24% (tau=0.31) */
                                    }
                                } else {
                                    {
                                        DecisionTreeResult res = { 0.0000f, 100.0000f, 0.00000f, 1.00000f, true };
                                        return res; /* Class 0: 0.00%, Class 1: 100.00% (tau=0.31) */
                                    }
                                }
                            }
                        }
                    }
                } else {
                    if (features[8] /* BT_mean */ <= 0.28560f) {
                        if (features[57] /* HR_max */ <= 0.81196f) {
                            if (features[13] /* Feature_HR_Mean_60s_mean */ <= 1.91421f) {
                                if (features[0] /* HR_mean */ <= 1.33147f) {
                                    if (features[89] /* Feature_HR_Mean_60s_slope */ <= 0.50350f) {
                                        if (features[67] /* Feature_Shock_Index_max */ <= 0.44097f) {
                                            {
                                                DecisionTreeResult res = { 7.1429f, 92.8571f, 0.07143f, 0.92857f, true };
                                                return res; /* Class 0: 7.14%, Class 1: 92.86% (tau=0.31) */
                                            }
                                        } else {
                                            if (features[14] /* Feature_HR_Std_60s_mean */ <= -0.91053f) {
                                                {
                                                    DecisionTreeResult res = { 0.0000f, 100.0000f, 0.00000f, 1.00000f, true };
                                                    return res; /* Class 0: 0.00%, Class 1: 100.00% (tau=0.31) */
                                                }
                                            } else {
                                                if (features[49] /* Feature_Modified_Shock_Index_min */ <= 6.10443f) {
                                                    {
                                                        DecisionTreeResult res = { 95.6047f, 4.3953f, 0.95605f, 0.04395f, false };
                                                        return res; /* Class 0: 95.60%, Class 1: 4.40% (tau=0.31) */
                                                    }
                                                } else {
                                                    {
                                                        DecisionTreeResult res = { 68.7500f, 31.2500f, 0.68750f, 0.31250f, true };
                                                        return res; /* Class 0: 68.75%, Class 1: 31.25% (tau=0.31) */
                                                    }
                                                }
                                            }
                                        }
                                    } else {
                                        if (features[70] /* Feature_HR_Mean_60s_max */ <= 0.92135f) {
                                            if (features[13] /* Feature_HR_Mean_60s_mean */ <= -0.01568f) {
                                                if (features[57] /* HR_max */ <= 0.73167f) {
                                                    {
                                                        DecisionTreeResult res = { 96.2585f, 3.7415f, 0.96259f, 0.03741f, false };
                                                        return res; /* Class 0: 96.26%, Class 1: 3.74% (tau=0.31) */
                                                    }
                                                } else {
                                                    {
                                                        DecisionTreeResult res = { 66.6667f, 33.3333f, 0.66667f, 0.33333f, true };
                                                        return res; /* Class 0: 66.67%, Class 1: 33.33% (tau=0.31) */
                                                    }
                                                }
                                            } else {
                                                if (features[64] /* FIO2_max */ <= -0.87730f) {
                                                    {
                                                        DecisionTreeResult res = { 33.3333f, 66.6667f, 0.33333f, 0.66667f, true };
                                                        return res; /* Class 0: 33.33%, Class 1: 66.67% (tau=0.31) */
                                                    }
                                                } else {
                                                    {
                                                        DecisionTreeResult res = { 90.9383f, 9.0617f, 0.90938f, 0.09062f, false };
                                                        return res; /* Class 0: 90.94%, Class 1: 9.06% (tau=0.31) */
                                                    }
                                                }
                                            }
                                        } else {
                                            if (features[26] /* FIO2_std */ <= 1.44106f) {
                                                if (features[14] /* Feature_HR_Std_60s_mean */ <= 0.30286f) {
                                                    {
                                                        DecisionTreeResult res = { 84.9624f, 15.0376f, 0.84962f, 0.15038f, false };
                                                        return res; /* Class 0: 84.96%, Class 1: 15.04% (tau=0.31) */
                                                    }
                                                } else {
                                                    {
                                                        DecisionTreeResult res = { 46.8750f, 53.1250f, 0.46875f, 0.53125f, true };
                                                        return res; /* Class 0: 46.88%, Class 1: 53.12% (tau=0.31) */
                                                    }
                                                }
                                            } else {
                                                if (features[69] /* Feature_Rate_Pressure_Product_max */ <= 1.14145f) {
                                                    {
                                                        DecisionTreeResult res = { 23.3333f, 76.6667f, 0.23333f, 0.76667f, true };
                                                        return res; /* Class 0: 23.33%, Class 1: 76.67% (tau=0.31) */
                                                    }
                                                } else {
                                                    {
                                                        DecisionTreeResult res = { 90.0000f, 10.0000f, 0.90000f, 0.10000f, false };
                                                        return res; /* Class 0: 90.00%, Class 1: 10.00% (tau=0.31) */
                                                    }
                                                }
                                            }
                                        }
                                    }
                                } else {
                                    if (features[33] /* Feature_HR_Std_60s_std */ <= -0.38034f) {
                                        if (features[76] /* HR_slope */ <= 1.14170f) {
                                            if (features[7] /* FIO2_mean */ <= -0.81824f) {
                                                if (features[65] /* BT_max */ <= 0.11721f) {
                                                    {
                                                        DecisionTreeResult res = { 89.2308f, 10.7692f, 0.89231f, 0.10769f, false };
                                                        return res; /* Class 0: 89.23%, Class 1: 10.77% (tau=0.31) */
                                                    }
                                                } else {
                                                    {
                                                        DecisionTreeResult res = { 37.9310f, 62.0690f, 0.37931f, 0.62069f, true };
                                                        return res; /* Class 0: 37.93%, Class 1: 62.07% (tau=0.31) */
                                                    }
                                                }
                                            } else {
                                                if (features[25] /* ETCO2_std */ <= 5.87660f) {
                                                    {
                                                        DecisionTreeResult res = { 92.1357f, 7.8643f, 0.92136f, 0.07864f, false };
                                                        return res; /* Class 0: 92.14%, Class 1: 7.86% (tau=0.31) */
                                                    }
                                                } else {
                                                    {
                                                        DecisionTreeResult res = { 0.0000f, 100.0000f, 0.00000f, 1.00000f, true };
                                                        return res; /* Class 0: 0.00%, Class 1: 100.00% (tau=0.31) */
                                                    }
                                                }
                                            }
                                        } else {
                                            {
                                                DecisionTreeResult res = { 50.0000f, 50.0000f, 0.50000f, 0.50000f, true };
                                                return res; /* Class 0: 50.00%, Class 1: 50.00% (tau=0.31) */
                                            }
                                        }
                                    } else {
                                        if (features[31] /* Feature_Rate_Pressure_Product_std */ <= 0.53690f) {
                                            if (features[76] /* HR_slope */ <= 0.58730f) {
                                                if (features[5] /* RR_CO2_mean */ <= -1.28979f) {
                                                    {
                                                        DecisionTreeResult res = { 67.1053f, 32.8947f, 0.67105f, 0.32895f, true };
                                                        return res; /* Class 0: 67.11%, Class 1: 32.89% (tau=0.31) */
                                                    }
                                                } else {
                                                    {
                                                        DecisionTreeResult res = { 88.5246f, 11.4754f, 0.88525f, 0.11475f, false };
                                                        return res; /* Class 0: 88.52%, Class 1: 11.48% (tau=0.31) */
                                                    }
                                                }
                                            } else {
                                                if (features[29] /* Feature_Shock_Index_std */ <= 1.38604f) {
                                                    {
                                                        DecisionTreeResult res = { 68.4211f, 31.5789f, 0.68421f, 0.31579f, true };
                                                        return res; /* Class 0: 68.42%, Class 1: 31.58% (tau=0.31) */
                                                    }
                                                } else {
                                                    {
                                                        DecisionTreeResult res = { 0.0000f, 100.0000f, 0.00000f, 1.00000f, true };
                                                        return res; /* Class 0: 0.00%, Class 1: 100.00% (tau=0.31) */
                                                    }
                                                }
                                            }
                                        } else {
                                            if (features[6] /* ETCO2_mean */ <= 0.81186f) {
                                                if (features[54] /* Feature_MBP_Mean_60s_min */ <= -0.34220f) {
                                                    {
                                                        DecisionTreeResult res = { 50.6849f, 49.3151f, 0.50685f, 0.49315f, true };
                                                        return res; /* Class 0: 50.68%, Class 1: 49.32% (tau=0.31) */
                                                    }
                                                } else {
                                                    {
                                                        DecisionTreeResult res = { 75.6757f, 24.3243f, 0.75676f, 0.24324f, false };
                                                        return res; /* Class 0: 75.68%, Class 1: 24.32% (tau=0.31) */
                                                    }
                                                }
                                            } else {
                                                {
                                                    DecisionTreeResult res = { 100.0000f, 0.0000f, 1.00000f, 0.00000f, false };
                                                    return res; /* Class 0: 100.00%, Class 1: 0.00% (tau=0.31) */
                                                }
                                            }
                                        }
                                    }
                                }
                            } else {
                                if (features[24] /* RR_CO2_std */ <= -0.04031f) {
                                    if (features[28] /* Feature_Pulse_Pressure_std */ <= -0.81586f) {
                                        {
                                            DecisionTreeResult res = { 26.0870f, 73.9130f, 0.26087f, 0.73913f, true };
                                            return res; /* Class 0: 26.09%, Class 1: 73.91% (tau=0.31) */
                                        }
                                    } else {
                                        if (features[37] /* Feature_MBP_Delta_60s_std */ <= -0.53033f) {
                                            if (features[82] /* ETCO2_slope */ <= -0.20597f) {
                                                if (features[0] /* HR_mean */ <= 2.21264f) {
                                                    {
                                                        DecisionTreeResult res = { 89.5349f, 10.4651f, 0.89535f, 0.10465f, false };
                                                        return res; /* Class 0: 89.53%, Class 1: 10.47% (tau=0.31) */
                                                    }
                                                } else {
                                                    {
                                                        DecisionTreeResult res = { 33.3333f, 66.6667f, 0.33333f, 0.66667f, true };
                                                        return res; /* Class 0: 33.33%, Class 1: 66.67% (tau=0.31) */
                                                    }
                                                }
                                            } else {
                                                if (features[41] /* ART_MBP_min */ <= 0.28378f) {
                                                    {
                                                        DecisionTreeResult res = { 97.9592f, 2.0408f, 0.97959f, 0.02041f, false };
                                                        return res; /* Class 0: 97.96%, Class 1: 2.04% (tau=0.31) */
                                                    }
                                                } else {
                                                    {
                                                        DecisionTreeResult res = { 71.4286f, 28.5714f, 0.71429f, 0.28571f, false };
                                                        return res; /* Class 0: 71.43%, Class 1: 28.57% (tau=0.31) */
                                                    }
                                                }
                                            }
                                        } else {
                                            if (features[66] /* Feature_Pulse_Pressure_max */ <= -0.71210f) {
                                                if (features[0] /* HR_mean */ <= 2.06428f) {
                                                    {
                                                        DecisionTreeResult res = { 74.6667f, 25.3333f, 0.74667f, 0.25333f, false };
                                                        return res; /* Class 0: 74.67%, Class 1: 25.33% (tau=0.31) */
                                                    }
                                                } else {
                                                    {
                                                        DecisionTreeResult res = { 39.3939f, 60.6061f, 0.39394f, 0.60606f, true };
                                                        return res; /* Class 0: 39.39%, Class 1: 60.61% (tau=0.31) */
                                                    }
                                                }
                                            } else {
                                                if (features[50] /* Feature_Rate_Pressure_Product_min */ <= 1.30887f) {
                                                    {
                                                        DecisionTreeResult res = { 79.9031f, 20.0969f, 0.79903f, 0.20097f, false };
                                                        return res; /* Class 0: 79.90%, Class 1: 20.10% (tau=0.31) */
                                                    }
                                                } else {
                                                    {
                                                        DecisionTreeResult res = { 44.6809f, 55.3191f, 0.44681f, 0.55319f, true };
                                                        return res; /* Class 0: 44.68%, Class 1: 55.32% (tau=0.31) */
                                                    }
                                                }
                                            }
                                        }
                                    }
                                } else {
                                    if (features[30] /* Feature_Modified_Shock_Index_std */ <= -0.45293f) {
                                        {
                                            DecisionTreeResult res = { 0.0000f, 100.0000f, 0.00000f, 1.00000f, true };
                                            return res; /* Class 0: 0.00%, Class 1: 100.00% (tau=0.31) */
                                        }
                                    } else {
                                        if (features[59] /* ART_DBP_max */ <= 0.45162f) {
                                            if (features[49] /* Feature_Modified_Shock_Index_min */ <= 1.11307f) {
                                                {
                                                    DecisionTreeResult res = { 14.7059f, 85.2941f, 0.14706f, 0.85294f, true };
                                                    return res; /* Class 0: 14.71%, Class 1: 85.29% (tau=0.31) */
                                                }
                                            } else {
                                                if (features[46] /* BT_min */ <= 0.18445f) {
                                                    {
                                                        DecisionTreeResult res = { 62.8571f, 37.1429f, 0.62857f, 0.37143f, true };
                                                        return res; /* Class 0: 62.86%, Class 1: 37.14% (tau=0.31) */
                                                    }
                                                } else {
                                                    {
                                                        DecisionTreeResult res = { 91.3043f, 8.6957f, 0.91304f, 0.08696f, false };
                                                        return res; /* Class 0: 91.30%, Class 1: 8.70% (tau=0.31) */
                                                    }
                                                }
                                            }
                                        } else {
                                            {
                                                DecisionTreeResult res = { 92.3077f, 7.6923f, 0.92308f, 0.07692f, false };
                                                return res; /* Class 0: 92.31%, Class 1: 7.69% (tau=0.31) */
                                            }
                                        }
                                    }
                                }
                            }
                        } else {
                            if (features[51] /* Feature_HR_Mean_60s_min */ <= 2.23497f) {
                                if (features[15] /* Feature_HR_Delta_60s_mean */ <= 0.58480f) {
                                    if (features[13] /* Feature_HR_Mean_60s_mean */ <= 1.73367f) {
                                        if (features[46] /* BT_min */ <= -0.95075f) {
                                            if (features[16] /* Feature_MBP_Mean_60s_mean */ <= -0.39299f) {
                                                if (features[57] /* HR_max */ <= 1.41416f) {
                                                    {
                                                        DecisionTreeResult res = { 51.2500f, 48.7500f, 0.51250f, 0.48750f, true };
                                                        return res; /* Class 0: 51.25%, Class 1: 48.75% (tau=0.31) */
                                                    }
                                                } else {
                                                    {
                                                        DecisionTreeResult res = { 85.3659f, 14.6341f, 0.85366f, 0.14634f, false };
                                                        return res; /* Class 0: 85.37%, Class 1: 14.63% (tau=0.31) */
                                                    }
                                                }
                                            } else {
                                                if (features[7] /* FIO2_mean */ <= 1.33030f) {
                                                    {
                                                        DecisionTreeResult res = { 88.5496f, 11.4504f, 0.88550f, 0.11450f, false };
                                                        return res; /* Class 0: 88.55%, Class 1: 11.45% (tau=0.31) */
                                                    }
                                                } else {
                                                    {
                                                        DecisionTreeResult res = { 67.8571f, 32.1429f, 0.67857f, 0.32143f, true };
                                                        return res; /* Class 0: 67.86%, Class 1: 32.14% (tau=0.31) */
                                                    }
                                                }
                                            }
                                        } else {
                                            if (features[44] /* ETCO2_min */ <= 1.65223f) {
                                                if (features[13] /* Feature_HR_Mean_60s_mean */ <= 1.07760f) {
                                                    {
                                                        DecisionTreeResult res = { 93.0548f, 6.9452f, 0.93055f, 0.06945f, false };
                                                        return res; /* Class 0: 93.05%, Class 1: 6.95% (tau=0.31) */
                                                    }
                                                } else {
                                                    {
                                                        DecisionTreeResult res = { 83.5331f, 16.4669f, 0.83533f, 0.16467f, false };
                                                        return res; /* Class 0: 83.53%, Class 1: 16.47% (tau=0.31) */
                                                    }
                                                }
                                            } else {
                                                {
                                                    DecisionTreeResult res = { 40.0000f, 60.0000f, 0.40000f, 0.60000f, true };
                                                    return res; /* Class 0: 40.00%, Class 1: 60.00% (tau=0.31) */
                                                }
                                            }
                                        }
                                    } else {
                                        if (features[11] /* Feature_Modified_Shock_Index_mean */ <= 1.81088f) {
                                            if (features[14] /* Feature_HR_Std_60s_mean */ <= -0.20803f) {
                                                if (features[65] /* BT_max */ <= 0.28189f) {
                                                    {
                                                        DecisionTreeResult res = { 76.7642f, 23.2358f, 0.76764f, 0.23236f, false };
                                                        return res; /* Class 0: 76.76%, Class 1: 23.24% (tau=0.31) */
                                                    }
                                                } else {
                                                    {
                                                        DecisionTreeResult res = { 27.7778f, 72.2222f, 0.27778f, 0.72222f, true };
                                                        return res; /* Class 0: 27.78%, Class 1: 72.22% (tau=0.31) */
                                                    }
                                                }
                                            } else {
                                                if (features[62] /* RR_CO2_max */ <= -0.13284f) {
                                                    {
                                                        DecisionTreeResult res = { 52.3649f, 47.6351f, 0.52365f, 0.47635f, true };
                                                        return res; /* Class 0: 52.36%, Class 1: 47.64% (tau=0.31) */
                                                    }
                                                } else {
                                                    {
                                                        DecisionTreeResult res = { 66.5842f, 33.4158f, 0.66584f, 0.33416f, true };
                                                        return res; /* Class 0: 66.58%, Class 1: 33.42% (tau=0.31) */
                                                    }
                                                }
                                            }
                                        } else {
                                            if (features[53] /* Feature_HR_Delta_60s_min */ <= -0.01601f) {
                                                if (features[36] /* Feature_MBP_Std_60s_std */ <= -0.20760f) {
                                                    {
                                                        DecisionTreeResult res = { 6.2500f, 93.7500f, 0.06250f, 0.93750f, true };
                                                        return res; /* Class 0: 6.25%, Class 1: 93.75% (tau=0.31) */
                                                    }
                                                } else {
                                                    {
                                                        DecisionTreeResult res = { 55.2632f, 44.7368f, 0.55263f, 0.44737f, true };
                                                        return res; /* Class 0: 55.26%, Class 1: 44.74% (tau=0.31) */
                                                    }
                                                }
                                            } else {
                                                if (features[59] /* ART_DBP_max */ <= -0.98140f) {
                                                    {
                                                        DecisionTreeResult res = { 82.6087f, 17.3913f, 0.82609f, 0.17391f, false };
                                                        return res; /* Class 0: 82.61%, Class 1: 17.39% (tau=0.31) */
                                                    }
                                                } else {
                                                    {
                                                        DecisionTreeResult res = { 47.7273f, 52.2727f, 0.47727f, 0.52273f, true };
                                                        return res; /* Class 0: 47.73%, Class 1: 52.27% (tau=0.31) */
                                                    }
                                                }
                                            }
                                        }
                                    }
                                } else {
                                    if (features[72] /* Feature_HR_Delta_60s_max */ <= 0.47412f) {
                                        if (features[28] /* Feature_Pulse_Pressure_std */ <= 3.79277f) {
                                            if (features[70] /* Feature_HR_Mean_60s_max */ <= 1.45082f) {
                                                if (features[70] /* Feature_HR_Mean_60s_max */ <= 1.23687f) {
                                                    {
                                                        DecisionTreeResult res = { 73.4513f, 26.5487f, 0.73451f, 0.26549f, false };
                                                        return res; /* Class 0: 73.45%, Class 1: 26.55% (tau=0.31) */
                                                    }
                                                } else {
                                                    {
                                                        DecisionTreeResult res = { 51.8072f, 48.1928f, 0.51807f, 0.48193f, true };
                                                        return res; /* Class 0: 51.81%, Class 1: 48.19% (tau=0.31) */
                                                    }
                                                }
                                            } else {
                                                if (features[48] /* Feature_Shock_Index_min */ <= 1.91090f) {
                                                    {
                                                        DecisionTreeResult res = { 25.0000f, 75.0000f, 0.25000f, 0.75000f, true };
                                                        return res; /* Class 0: 25.00%, Class 1: 75.00% (tau=0.31) */
                                                    }
                                                } else {
                                                    {
                                                        DecisionTreeResult res = { 6.8966f, 93.1034f, 0.06897f, 0.93103f, true };
                                                        return res; /* Class 0: 6.90%, Class 1: 93.10% (tau=0.31) */
                                                    }
                                                }
                                            }
                                        } else {
                                            {
                                                DecisionTreeResult res = { 92.8571f, 7.1429f, 0.92857f, 0.07143f, false };
                                                return res; /* Class 0: 92.86%, Class 1: 7.14% (tau=0.31) */
                                            }
                                        }
                                    } else {
                                        if (features[76] /* HR_slope */ <= 1.41891f) {
                                            if (features[50] /* Feature_Rate_Pressure_Product_min */ <= 1.23043f) {
                                                if (features[13] /* Feature_HR_Mean_60s_mean */ <= 1.05503f) {
                                                    {
                                                        DecisionTreeResult res = { 87.4359f, 12.5641f, 0.87436f, 0.12564f, false };
                                                        return res; /* Class 0: 87.44%, Class 1: 12.56% (tau=0.31) */
                                                    }
                                                } else {
                                                    {
                                                        DecisionTreeResult res = { 63.0208f, 36.9792f, 0.63021f, 0.36979f, true };
                                                        return res; /* Class 0: 63.02%, Class 1: 36.98% (tau=0.31) */
                                                    }
                                                }
                                            } else {
                                                {
                                                    DecisionTreeResult res = { 26.6667f, 73.3333f, 0.26667f, 0.73333f, true };
                                                    return res; /* Class 0: 26.67%, Class 1: 73.33% (tau=0.31) */
                                                }
                                            }
                                        } else {
                                            if (features[0] /* HR_mean */ <= 1.69396f) {
                                                if (features[44] /* ETCO2_min */ <= 1.45138f) {
                                                    {
                                                        DecisionTreeResult res = { 55.2486f, 44.7514f, 0.55249f, 0.44751f, true };
                                                        return res; /* Class 0: 55.25%, Class 1: 44.75% (tau=0.31) */
                                                    }
                                                } else {
                                                    {
                                                        DecisionTreeResult res = { 0.0000f, 100.0000f, 0.00000f, 1.00000f, true };
                                                        return res; /* Class 0: 0.00%, Class 1: 100.00% (tau=0.31) */
                                                    }
                                                }
                                            } else {
                                                {
                                                    DecisionTreeResult res = { 12.5000f, 87.5000f, 0.12500f, 0.87500f, true };
                                                    return res; /* Class 0: 12.50%, Class 1: 87.50% (tau=0.31) */
                                                }
                                            }
                                        }
                                    }
                                }
                            } else {
                                if (features[57] /* HR_max */ <= 0.97255f) {
                                    if (features[44] /* ETCO2_min */ <= 2.05394f) {
                                        if (features[31] /* Feature_Rate_Pressure_Product_std */ <= 0.01701f) {
                                            if (features[62] /* RR_CO2_max */ <= -0.13284f) {
                                                if (features[89] /* Feature_HR_Mean_60s_slope */ <= -0.10254f) {
                                                    {
                                                        DecisionTreeResult res = { 57.6923f, 42.3077f, 0.57692f, 0.42308f, true };
                                                        return res; /* Class 0: 57.69%, Class 1: 42.31% (tau=0.31) */
                                                    }
                                                } else {
                                                    {
                                                        DecisionTreeResult res = { 23.3333f, 76.6667f, 0.23333f, 0.76667f, true };
                                                        return res; /* Class 0: 23.33%, Class 1: 76.67% (tau=0.31) */
                                                    }
                                                }
                                            } else {
                                                if (features[7] /* FIO2_mean */ <= -0.79207f) {
                                                    {
                                                        DecisionTreeResult res = { 32.9412f, 67.0588f, 0.32941f, 0.67059f, true };
                                                        return res; /* Class 0: 32.94%, Class 1: 67.06% (tau=0.31) */
                                                    }
                                                } else {
                                                    {
                                                        DecisionTreeResult res = { 6.4327f, 93.5673f, 0.06433f, 0.93567f, true };
                                                        return res; /* Class 0: 6.43%, Class 1: 93.57% (tau=0.31) */
                                                    }
                                                }
                                            }
                                        } else {
                                            if (features[5] /* RR_CO2_mean */ <= 1.13010f) {
                                                if (features[60] /* ART_MBP_max */ <= 2.11886f) {
                                                    {
                                                        DecisionTreeResult res = { 62.5850f, 37.4150f, 0.62585f, 0.37415f, true };
                                                        return res; /* Class 0: 62.59%, Class 1: 37.41% (tau=0.31) */
                                                    }
                                                } else {
                                                    {
                                                        DecisionTreeResult res = { 20.0000f, 80.0000f, 0.20000f, 0.80000f, true };
                                                        return res; /* Class 0: 20.00%, Class 1: 80.00% (tau=0.31) */
                                                    }
                                                }
                                            } else {
                                                {
                                                    DecisionTreeResult res = { 2.8571f, 97.1429f, 0.02857f, 0.97143f, true };
                                                    return res; /* Class 0: 2.86%, Class 1: 97.14% (tau=0.31) */
                                                }
                                            }
                                        }
                                    } else {
                                        {
                                            DecisionTreeResult res = { 100.0000f, 0.0000f, 1.00000f, 0.00000f, false };
                                            return res; /* Class 0: 100.00%, Class 1: 0.00% (tau=0.31) */
                                        }
                                    }
                                } else {
                                    if (features[13] /* Feature_HR_Mean_60s_mean */ <= 2.28221f) {
                                        if (features[34] /* Feature_HR_Delta_60s_std */ <= -0.41485f) {
                                            if (features[53] /* Feature_HR_Delta_60s_min */ <= 0.39719f) {
                                                if (features[46] /* BT_min */ <= 0.18445f) {
                                                    {
                                                        DecisionTreeResult res = { 56.0000f, 44.0000f, 0.56000f, 0.44000f, true };
                                                        return res; /* Class 0: 56.00%, Class 1: 44.00% (tau=0.31) */
                                                    }
                                                } else {
                                                    {
                                                        DecisionTreeResult res = { 100.0000f, 0.0000f, 1.00000f, 0.00000f, false };
                                                        return res; /* Class 0: 100.00%, Class 1: 0.00% (tau=0.31) */
                                                    }
                                                }
                                            } else {
                                                {
                                                    DecisionTreeResult res = { 26.0870f, 73.9130f, 0.26087f, 0.73913f, true };
                                                    return res; /* Class 0: 26.09%, Class 1: 73.91% (tau=0.31) */
                                                }
                                            }
                                        } else {
                                            if (features[47] /* Feature_Pulse_Pressure_min */ <= 0.91774f) {
                                                if (features[44] /* ETCO2_min */ <= 0.44710f) {
                                                    {
                                                        DecisionTreeResult res = { 15.0685f, 84.9315f, 0.15068f, 0.84932f, true };
                                                        return res; /* Class 0: 15.07%, Class 1: 84.93% (tau=0.31) */
                                                    }
                                                } else {
                                                    {
                                                        DecisionTreeResult res = { 41.7910f, 58.2090f, 0.41791f, 0.58209f, true };
                                                        return res; /* Class 0: 41.79%, Class 1: 58.21% (tau=0.31) */
                                                    }
                                                }
                                            } else {
                                                {
                                                    DecisionTreeResult res = { 83.3333f, 16.6667f, 0.83333f, 0.16667f, false };
                                                    return res; /* Class 0: 83.33%, Class 1: 16.67% (tau=0.31) */
                                                }
                                            }
                                        }
                                    } else {
                                        if (features[6] /* ETCO2_mean */ <= 2.99077f) {
                                            if (features[19] /* HR_std */ <= -0.29461f) {
                                                if (features[72] /* Feature_HR_Delta_60s_max */ <= -0.23635f) {
                                                    {
                                                        DecisionTreeResult res = { 0.6993f, 99.3007f, 0.00699f, 0.99301f, true };
                                                        return res; /* Class 0: 0.70%, Class 1: 99.30% (tau=0.31) */
                                                    }
                                                } else {
                                                    {
                                                        DecisionTreeResult res = { 4.7753f, 95.2247f, 0.04775f, 0.95225f, true };
                                                        return res; /* Class 0: 4.78%, Class 1: 95.22% (tau=0.31) */
                                                    }
                                                }
                                            } else {
                                                if (features[31] /* Feature_Rate_Pressure_Product_std */ <= -0.40589f) {
                                                    {
                                                        DecisionTreeResult res = { 18.1034f, 81.8966f, 0.18103f, 0.81897f, true };
                                                        return res; /* Class 0: 18.10%, Class 1: 81.90% (tau=0.31) */
                                                    }
                                                } else {
                                                    {
                                                        DecisionTreeResult res = { 6.0629f, 93.9371f, 0.06063f, 0.93937f, true };
                                                        return res; /* Class 0: 6.06%, Class 1: 93.94% (tau=0.31) */
                                                    }
                                                }
                                            }
                                        } else {
                                            {
                                                DecisionTreeResult res = { 100.0000f, 0.0000f, 1.00000f, 0.00000f, false };
                                                return res; /* Class 0: 100.00%, Class 1: 0.00% (tau=0.31) */
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    } else {
                        if (features[13] /* Feature_HR_Mean_60s_mean */ <= 2.19224f) {
                            if (features[76] /* HR_slope */ <= 0.49490f) {
                                if (features[45] /* FIO2_min */ <= 1.31059f) {
                                    if (features[13] /* Feature_HR_Mean_60s_mean */ <= 1.89981f) {
                                        if (features[70] /* Feature_HR_Mean_60s_max */ <= 1.23358f) {
                                            if (features[43] /* RR_CO2_min */ <= 2.54446f) {
                                                if (features[70] /* Feature_HR_Mean_60s_max */ <= 0.86822f) {
                                                    {
                                                        DecisionTreeResult res = { 95.7948f, 4.2052f, 0.95795f, 0.04205f, false };
                                                        return res; /* Class 0: 95.79%, Class 1: 4.21% (tau=0.31) */
                                                    }
                                                } else {
                                                    {
                                                        DecisionTreeResult res = { 90.8622f, 9.1378f, 0.90862f, 0.09138f, false };
                                                        return res; /* Class 0: 90.86%, Class 1: 9.14% (tau=0.31) */
                                                    }
                                                }
                                            } else {
                                                if (features[9] /* Feature_Pulse_Pressure_mean */ <= -1.29297f) {
                                                    {
                                                        DecisionTreeResult res = { 7.1429f, 92.8571f, 0.07143f, 0.92857f, true };
                                                        return res; /* Class 0: 7.14%, Class 1: 92.86% (tau=0.31) */
                                                    }
                                                } else {
                                                    {
                                                        DecisionTreeResult res = { 78.6164f, 21.3836f, 0.78616f, 0.21384f, false };
                                                        return res; /* Class 0: 78.62%, Class 1: 21.38% (tau=0.31) */
                                                    }
                                                }
                                            }
                                        } else {
                                            if (features[78] /* ART_DBP_slope */ <= -1.42346f) {
                                                if (features[94] /* Feature_MBP_Delta_60s_slope */ <= -0.71815f) {
                                                    {
                                                        DecisionTreeResult res = { 94.1176f, 5.8824f, 0.94118f, 0.05882f, false };
                                                        return res; /* Class 0: 94.12%, Class 1: 5.88% (tau=0.31) */
                                                    }
                                                } else {
                                                    {
                                                        DecisionTreeResult res = { 43.0769f, 56.9231f, 0.43077f, 0.56923f, true };
                                                        return res; /* Class 0: 43.08%, Class 1: 56.92% (tau=0.31) */
                                                    }
                                                }
                                            } else {
                                                if (features[65] /* BT_max */ <= 0.50421f) {
                                                    {
                                                        DecisionTreeResult res = { 82.3586f, 17.6414f, 0.82359f, 0.17641f, false };
                                                        return res; /* Class 0: 82.36%, Class 1: 17.64% (tau=0.31) */
                                                    }
                                                } else {
                                                    {
                                                        DecisionTreeResult res = { 42.3077f, 57.6923f, 0.42308f, 0.57692f, true };
                                                        return res; /* Class 0: 42.31%, Class 1: 57.69% (tau=0.31) */
                                                    }
                                                }
                                            }
                                        }
                                    } else {
                                        if (features[3] /* ART_MBP_mean */ <= -0.44532f) {
                                            if (features[68] /* Feature_Modified_Shock_Index_max */ <= 0.69267f) {
                                                if (features[30] /* Feature_Modified_Shock_Index_std */ <= -0.28137f) {
                                                    {
                                                        DecisionTreeResult res = { 87.5000f, 12.5000f, 0.87500f, 0.12500f, false };
                                                        return res; /* Class 0: 87.50%, Class 1: 12.50% (tau=0.31) */
                                                    }
                                                } else {
                                                    {
                                                        DecisionTreeResult res = { 100.0000f, 0.0000f, 1.00000f, 0.00000f, false };
                                                        return res; /* Class 0: 100.00%, Class 1: 0.00% (tau=0.31) */
                                                    }
                                                }
                                            } else {
                                                if (features[12] /* Feature_Rate_Pressure_Product_mean */ <= 0.65198f) {
                                                    {
                                                        DecisionTreeResult res = { 83.8323f, 16.1677f, 0.83832f, 0.16168f, false };
                                                        return res; /* Class 0: 83.83%, Class 1: 16.17% (tau=0.31) */
                                                    }
                                                } else {
                                                    {
                                                        DecisionTreeResult res = { 44.7059f, 55.2941f, 0.44706f, 0.55294f, true };
                                                        return res; /* Class 0: 44.71%, Class 1: 55.29% (tau=0.31) */
                                                    }
                                                }
                                            }
                                        } else {
                                            if (features[76] /* HR_slope */ <= 0.12529f) {
                                                if (features[4] /* PLETH_SPO2_mean */ <= 0.32122f) {
                                                    {
                                                        DecisionTreeResult res = { 44.9612f, 55.0388f, 0.44961f, 0.55039f, true };
                                                        return res; /* Class 0: 44.96%, Class 1: 55.04% (tau=0.31) */
                                                    }
                                                } else {
                                                    {
                                                        DecisionTreeResult res = { 64.9446f, 35.0554f, 0.64945f, 0.35055f, true };
                                                        return res; /* Class 0: 64.94%, Class 1: 35.06% (tau=0.31) */
                                                    }
                                                }
                                            } else {
                                                if (features[17] /* Feature_MBP_Std_60s_mean */ <= -0.38418f) {
                                                    {
                                                        DecisionTreeResult res = { 8.3333f, 91.6667f, 0.08333f, 0.91667f, true };
                                                        return res; /* Class 0: 8.33%, Class 1: 91.67% (tau=0.31) */
                                                    }
                                                } else {
                                                    {
                                                        DecisionTreeResult res = { 41.1765f, 58.8235f, 0.41176f, 0.58824f, true };
                                                        return res; /* Class 0: 41.18%, Class 1: 58.82% (tau=0.31) */
                                                    }
                                                }
                                            }
                                        }
                                    }
                                } else {
                                    if (features[51] /* Feature_HR_Mean_60s_min */ <= 1.24529f) {
                                        if (features[90] /* Feature_HR_Std_60s_slope */ <= 1.63031f) {
                                            if (features[7] /* FIO2_mean */ <= 2.06055f) {
                                                if (features[5] /* RR_CO2_mean */ <= 0.40915f) {
                                                    {
                                                        DecisionTreeResult res = { 70.0980f, 29.9020f, 0.70098f, 0.29902f, false };
                                                        return res; /* Class 0: 70.10%, Class 1: 29.90% (tau=0.31) */
                                                    }
                                                } else {
                                                    {
                                                        DecisionTreeResult res = { 86.2222f, 13.7778f, 0.86222f, 0.13778f, false };
                                                        return res; /* Class 0: 86.22%, Class 1: 13.78% (tau=0.31) */
                                                    }
                                                }
                                            } else {
                                                if (features[20] /* ART_SBP_std */ <= 0.65435f) {
                                                    {
                                                        DecisionTreeResult res = { 89.2857f, 10.7143f, 0.89286f, 0.10714f, false };
                                                        return res; /* Class 0: 89.29%, Class 1: 10.71% (tau=0.31) */
                                                    }
                                                } else {
                                                    {
                                                        DecisionTreeResult res = { 96.9605f, 3.0395f, 0.96960f, 0.03040f, false };
                                                        return res; /* Class 0: 96.96%, Class 1: 3.04% (tau=0.31) */
                                                    }
                                                }
                                            }
                                        } else {
                                            if (features[7] /* FIO2_mean */ <= 1.43520f) {
                                                {
                                                    DecisionTreeResult res = { 100.0000f, 0.0000f, 1.00000f, 0.00000f, false };
                                                    return res; /* Class 0: 100.00%, Class 1: 0.00% (tau=0.31) */
                                                }
                                            } else {
                                                {
                                                    DecisionTreeResult res = { 51.0638f, 48.9362f, 0.51064f, 0.48936f, true };
                                                    return res; /* Class 0: 51.06%, Class 1: 48.94% (tau=0.31) */
                                                }
                                            }
                                        }
                                    } else {
                                        if (features[38] /* HR_min */ <= 1.59783f) {
                                            if (features[26] /* FIO2_std */ <= -0.37237f) {
                                                if (features[25] /* ETCO2_std */ <= -0.48981f) {
                                                    {
                                                        DecisionTreeResult res = { 16.6667f, 83.3333f, 0.16667f, 0.83333f, true };
                                                        return res; /* Class 0: 16.67%, Class 1: 83.33% (tau=0.31) */
                                                    }
                                                } else {
                                                    {
                                                        DecisionTreeResult res = { 82.8571f, 17.1429f, 0.82857f, 0.17143f, false };
                                                        return res; /* Class 0: 82.86%, Class 1: 17.14% (tau=0.31) */
                                                    }
                                                }
                                            } else {
                                                if (features[54] /* Feature_MBP_Mean_60s_min */ <= -0.16281f) {
                                                    {
                                                        DecisionTreeResult res = { 62.0690f, 37.9310f, 0.62069f, 0.37931f, true };
                                                        return res; /* Class 0: 62.07%, Class 1: 37.93% (tau=0.31) */
                                                    }
                                                } else {
                                                    {
                                                        DecisionTreeResult res = { 20.7792f, 79.2208f, 0.20779f, 0.79221f, true };
                                                        return res; /* Class 0: 20.78%, Class 1: 79.22% (tau=0.31) */
                                                    }
                                                }
                                            }
                                        } else {
                                            if (features[42] /* PLETH_SPO2_min */ <= -1.22221f) {
                                                {
                                                    DecisionTreeResult res = { 51.3514f, 48.6486f, 0.51351f, 0.48649f, true };
                                                    return res; /* Class 0: 51.35%, Class 1: 48.65% (tau=0.31) */
                                                }
                                            } else {
                                                if (features[57] /* HR_max */ <= 1.81562f) {
                                                    {
                                                        DecisionTreeResult res = { 89.8182f, 10.1818f, 0.89818f, 0.10182f, false };
                                                        return res; /* Class 0: 89.82%, Class 1: 10.18% (tau=0.31) */
                                                    }
                                                } else {
                                                    {
                                                        DecisionTreeResult res = { 17.6471f, 82.3529f, 0.17647f, 0.82353f, true };
                                                        return res; /* Class 0: 17.65%, Class 1: 82.35% (tau=0.31) */
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            } else {
                                if (features[38] /* HR_min */ <= 1.66568f) {
                                    if (features[0] /* HR_mean */ <= 1.36917f) {
                                        if (features[51] /* Feature_HR_Mean_60s_min */ <= 0.89702f) {
                                            if (features[33] /* Feature_HR_Std_60s_std */ <= 0.92190f) {
                                                if (features[44] /* ETCO2_min */ <= -0.08852f) {
                                                    {
                                                        DecisionTreeResult res = { 84.2995f, 15.7005f, 0.84300f, 0.15700f, false };
                                                        return res; /* Class 0: 84.30%, Class 1: 15.70% (tau=0.31) */
                                                    }
                                                } else {
                                                    {
                                                        DecisionTreeResult res = { 93.3210f, 6.6790f, 0.93321f, 0.06679f, false };
                                                        return res; /* Class 0: 93.32%, Class 1: 6.68% (tau=0.31) */
                                                    }
                                                }
                                            } else {
                                                if (features[59] /* ART_DBP_max */ <= -0.44142f) {
                                                    {
                                                        DecisionTreeResult res = { 44.4444f, 55.5556f, 0.44444f, 0.55556f, true };
                                                        return res; /* Class 0: 44.44%, Class 1: 55.56% (tau=0.31) */
                                                    }
                                                } else {
                                                    {
                                                        DecisionTreeResult res = { 80.7143f, 19.2857f, 0.80714f, 0.19286f, false };
                                                        return res; /* Class 0: 80.71%, Class 1: 19.29% (tau=0.31) */
                                                    }
                                                }
                                            }
                                        } else {
                                            if (features[31] /* Feature_Rate_Pressure_Product_std */ <= 2.18563f) {
                                                if (features[90] /* Feature_HR_Std_60s_slope */ <= 1.95071f) {
                                                    {
                                                        DecisionTreeResult res = { 79.6392f, 20.3608f, 0.79639f, 0.20361f, false };
                                                        return res; /* Class 0: 79.64%, Class 1: 20.36% (tau=0.31) */
                                                    }
                                                } else {
                                                    {
                                                        DecisionTreeResult res = { 13.0435f, 86.9565f, 0.13043f, 0.86957f, true };
                                                        return res; /* Class 0: 13.04%, Class 1: 86.96% (tau=0.31) */
                                                    }
                                                }
                                            } else {
                                                {
                                                    DecisionTreeResult res = { 14.2857f, 85.7143f, 0.14286f, 0.85714f, true };
                                                    return res; /* Class 0: 14.29%, Class 1: 85.71% (tau=0.31) */
                                                }
                                            }
                                        }
                                    } else {
                                        if (features[7] /* FIO2_mean */ <= -0.86174f) {
                                            {
                                                DecisionTreeResult res = { 0.0000f, 100.0000f, 0.00000f, 1.00000f, true };
                                                return res; /* Class 0: 0.00%, Class 1: 100.00% (tau=0.31) */
                                            }
                                        } else {
                                            if (features[72] /* Feature_HR_Delta_60s_max */ <= 0.06814f) {
                                                if (features[25] /* ETCO2_std */ <= 1.03335f) {
                                                    {
                                                        DecisionTreeResult res = { 79.1139f, 20.8861f, 0.79114f, 0.20886f, false };
                                                        return res; /* Class 0: 79.11%, Class 1: 20.89% (tau=0.31) */
                                                    }
                                                } else {
                                                    {
                                                        DecisionTreeResult res = { 40.0000f, 60.0000f, 0.40000f, 0.60000f, true };
                                                        return res; /* Class 0: 40.00%, Class 1: 60.00% (tau=0.31) */
                                                    }
                                                }
                                            } else {
                                                if (features[41] /* ART_MBP_min */ <= 0.14365f) {
                                                    {
                                                        DecisionTreeResult res = { 58.7302f, 41.2698f, 0.58730f, 0.41270f, true };
                                                        return res; /* Class 0: 58.73%, Class 1: 41.27% (tau=0.31) */
                                                    }
                                                } else {
                                                    {
                                                        DecisionTreeResult res = { 28.8889f, 71.1111f, 0.28889f, 0.71111f, true };
                                                        return res; /* Class 0: 28.89%, Class 1: 71.11% (tau=0.31) */
                                                    }
                                                }
                                            }
                                        }
                                    }
                                } else {
                                    if (features[70] /* Feature_HR_Mean_60s_max */ <= 1.47997f) {
                                        if (features[19] /* HR_std */ <= -0.09469f) {
                                            if (features[41] /* ART_MBP_min */ <= 0.19036f) {
                                                if (features[11] /* Feature_Modified_Shock_Index_mean */ <= 1.43586f) {
                                                    {
                                                        DecisionTreeResult res = { 86.9565f, 13.0435f, 0.86957f, 0.13043f, false };
                                                        return res; /* Class 0: 86.96%, Class 1: 13.04% (tau=0.31) */
                                                    }
                                                } else {
                                                    {
                                                        DecisionTreeResult res = { 18.7500f, 81.2500f, 0.18750f, 0.81250f, true };
                                                        return res; /* Class 0: 18.75%, Class 1: 81.25% (tau=0.31) */
                                                    }
                                                }
                                            } else {
                                                {
                                                    DecisionTreeResult res = { 35.2941f, 64.7059f, 0.35294f, 0.64706f, true };
                                                    return res; /* Class 0: 35.29%, Class 1: 64.71% (tau=0.31) */
                                                }
                                            }
                                        } else {
                                            {
                                                DecisionTreeResult res = { 14.2857f, 85.7143f, 0.14286f, 0.85714f, true };
                                                return res; /* Class 0: 14.29%, Class 1: 85.71% (tau=0.31) */
                                            }
                                        }
                                    } else {
                                        if (features[76] /* HR_slope */ <= 0.95690f) {
                                            if (features[84] /* BT_slope */ <= -0.09351f) {
                                                {
                                                    DecisionTreeResult res = { 50.0000f, 50.0000f, 0.50000f, 0.50000f, true };
                                                    return res; /* Class 0: 50.00%, Class 1: 50.00% (tau=0.31) */
                                                }
                                            } else {
                                                if (features[58] /* ART_SBP_max */ <= 0.14383f) {
                                                    {
                                                        DecisionTreeResult res = { 4.6154f, 95.3846f, 0.04615f, 0.95385f, true };
                                                        return res; /* Class 0: 4.62%, Class 1: 95.38% (tau=0.31) */
                                                    }
                                                } else {
                                                    {
                                                        DecisionTreeResult res = { 37.0370f, 62.9630f, 0.37037f, 0.62963f, true };
                                                        return res; /* Class 0: 37.04%, Class 1: 62.96% (tau=0.31) */
                                                    }
                                                }
                                            }
                                        } else {
                                            if (features[85] /* Feature_Pulse_Pressure_slope */ <= -0.91399f) {
                                                {
                                                    DecisionTreeResult res = { 40.0000f, 60.0000f, 0.40000f, 0.60000f, true };
                                                    return res; /* Class 0: 40.00%, Class 1: 60.00% (tau=0.31) */
                                                }
                                            } else {
                                                if (features[84] /* BT_slope */ <= 0.03784f) {
                                                    {
                                                        DecisionTreeResult res = { 0.0000f, 100.0000f, 0.00000f, 1.00000f, true };
                                                        return res; /* Class 0: 0.00%, Class 1: 100.00% (tau=0.31) */
                                                    }
                                                } else {
                                                    {
                                                        DecisionTreeResult res = { 20.0000f, 80.0000f, 0.20000f, 0.80000f, true };
                                                        return res; /* Class 0: 20.00%, Class 1: 80.00% (tau=0.31) */
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        } else {
                            if (features[70] /* Feature_HR_Mean_60s_max */ <= 1.91446f) {
                                if (features[19] /* HR_std */ <= -0.40182f) {
                                    if (features[51] /* Feature_HR_Mean_60s_min */ <= 2.71546f) {
                                        if (features[76] /* HR_slope */ <= -0.24431f) {
                                            if (features[39] /* ART_SBP_min */ <= -0.45139f) {
                                                if (features[69] /* Feature_Rate_Pressure_Product_max */ <= 0.94290f) {
                                                    {
                                                        DecisionTreeResult res = { 82.6923f, 17.3077f, 0.82692f, 0.17308f, false };
                                                        return res; /* Class 0: 82.69%, Class 1: 17.31% (tau=0.31) */
                                                    }
                                                } else {
                                                    {
                                                        DecisionTreeResult res = { 16.6667f, 83.3333f, 0.16667f, 0.83333f, true };
                                                        return res; /* Class 0: 16.67%, Class 1: 83.33% (tau=0.31) */
                                                    }
                                                }
                                            } else {
                                                if (features[64] /* FIO2_max */ <= -0.65481f) {
                                                    {
                                                        DecisionTreeResult res = { 39.4737f, 60.5263f, 0.39474f, 0.60526f, true };
                                                        return res; /* Class 0: 39.47%, Class 1: 60.53% (tau=0.31) */
                                                    }
                                                } else {
                                                    {
                                                        DecisionTreeResult res = { 0.0000f, 100.0000f, 0.00000f, 1.00000f, true };
                                                        return res; /* Class 0: 0.00%, Class 1: 100.00% (tau=0.31) */
                                                    }
                                                }
                                            }
                                        } else {
                                            if (features[48] /* Feature_Shock_Index_min */ <= 3.17104f) {
                                                if (features[30] /* Feature_Modified_Shock_Index_std */ <= -0.50292f) {
                                                    {
                                                        DecisionTreeResult res = { 47.3684f, 52.6316f, 0.47368f, 0.52632f, true };
                                                        return res; /* Class 0: 47.37%, Class 1: 52.63% (tau=0.31) */
                                                    }
                                                } else {
                                                    {
                                                        DecisionTreeResult res = { 9.1286f, 90.8714f, 0.09129f, 0.90871f, true };
                                                        return res; /* Class 0: 9.13%, Class 1: 90.87% (tau=0.31) */
                                                    }
                                                }
                                            } else {
                                                {
                                                    DecisionTreeResult res = { 100.0000f, 0.0000f, 1.00000f, 0.00000f, false };
                                                    return res; /* Class 0: 100.00%, Class 1: 0.00% (tau=0.31) */
                                                }
                                            }
                                        }
                                    } else {
                                        if (features[11] /* Feature_Modified_Shock_Index_mean */ <= 2.32398f) {
                                            if (features[16] /* Feature_MBP_Mean_60s_mean */ <= 0.49224f) {
                                                if (features[91] /* Feature_HR_Delta_60s_slope */ <= -0.25272f) {
                                                    {
                                                        DecisionTreeResult res = { 11.1111f, 88.8889f, 0.11111f, 0.88889f, true };
                                                        return res; /* Class 0: 11.11%, Class 1: 88.89% (tau=0.31) */
                                                    }
                                                } else {
                                                    {
                                                        DecisionTreeResult res = { 0.6250f, 99.3750f, 0.00625f, 0.99375f, true };
                                                        return res; /* Class 0: 0.62%, Class 1: 99.38% (tau=0.31) */
                                                    }
                                                }
                                            } else {
                                                {
                                                    DecisionTreeResult res = { 20.0000f, 80.0000f, 0.20000f, 0.80000f, true };
                                                    return res; /* Class 0: 20.00%, Class 1: 80.00% (tau=0.31) */
                                                }
                                            }
                                        } else {
                                            {
                                                DecisionTreeResult res = { 18.1818f, 81.8182f, 0.18182f, 0.81818f, true };
                                                return res; /* Class 0: 18.18%, Class 1: 81.82% (tau=0.31) */
                                            }
                                        }
                                    }
                                } else {
                                    if (features[68] /* Feature_Modified_Shock_Index_max */ <= 0.45544f) {
                                        {
                                            DecisionTreeResult res = { 0.0000f, 100.0000f, 0.00000f, 1.00000f, true };
                                            return res; /* Class 0: 0.00%, Class 1: 100.00% (tau=0.31) */
                                        }
                                    } else {
                                        if (features[28] /* Feature_Pulse_Pressure_std */ <= 1.85183f) {
                                            if (features[89] /* Feature_HR_Mean_60s_slope */ <= 0.25083f) {
                                                if (features[91] /* Feature_HR_Delta_60s_slope */ <= 0.33623f) {
                                                    {
                                                        DecisionTreeResult res = { 80.5195f, 19.4805f, 0.80519f, 0.19481f, false };
                                                        return res; /* Class 0: 80.52%, Class 1: 19.48% (tau=0.31) */
                                                    }
                                                } else {
                                                    {
                                                        DecisionTreeResult res = { 25.0000f, 75.0000f, 0.25000f, 0.75000f, true };
                                                        return res; /* Class 0: 25.00%, Class 1: 75.00% (tau=0.31) */
                                                    }
                                                }
                                            } else {
                                                {
                                                    DecisionTreeResult res = { 8.3333f, 91.6667f, 0.08333f, 0.91667f, true };
                                                    return res; /* Class 0: 8.33%, Class 1: 91.67% (tau=0.31) */
                                                }
                                            }
                                        } else {
                                            {
                                                DecisionTreeResult res = { 0.0000f, 100.0000f, 0.00000f, 1.00000f, true };
                                                return res; /* Class 0: 0.00%, Class 1: 100.00% (tau=0.31) */
                                            }
                                        }
                                    }
                                }
                            } else {
                                if (features[13] /* Feature_HR_Mean_60s_mean */ <= 2.55808f) {
                                    if (features[17] /* Feature_MBP_Std_60s_mean */ <= -0.45808f) {
                                        {
                                            DecisionTreeResult res = { 0.0000f, 100.0000f, 0.00000f, 1.00000f, true };
                                            return res; /* Class 0: 0.00%, Class 1: 100.00% (tau=0.31) */
                                        }
                                    } else {
                                        if (features[32] /* Feature_HR_Mean_60s_std */ <= -0.21954f) {
                                            if (features[92] /* Feature_MBP_Mean_60s_slope */ <= -0.82514f) {
                                                {
                                                    DecisionTreeResult res = { 25.0000f, 75.0000f, 0.25000f, 0.75000f, true };
                                                    return res; /* Class 0: 25.00%, Class 1: 75.00% (tau=0.31) */
                                                }
                                            } else {
                                                if (features[50] /* Feature_Rate_Pressure_Product_min */ <= 0.42029f) {
                                                    {
                                                        DecisionTreeResult res = { 20.0000f, 80.0000f, 0.20000f, 0.80000f, true };
                                                        return res; /* Class 0: 20.00%, Class 1: 80.00% (tau=0.31) */
                                                    }
                                                } else {
                                                    {
                                                        DecisionTreeResult res = { 1.2048f, 98.7952f, 0.01205f, 0.98795f, true };
                                                        return res; /* Class 0: 1.20%, Class 1: 98.80% (tau=0.31) */
                                                    }
                                                }
                                            }
                                        } else {
                                            if (features[43] /* RR_CO2_min */ <= 3.85179f) {
                                                if (features[57] /* HR_max */ <= 1.17328f) {
                                                    {
                                                        DecisionTreeResult res = { 29.8387f, 70.1613f, 0.29839f, 0.70161f, true };
                                                        return res; /* Class 0: 29.84%, Class 1: 70.16% (tau=0.31) */
                                                    }
                                                } else {
                                                    {
                                                        DecisionTreeResult res = { 12.3348f, 87.6652f, 0.12335f, 0.87665f, true };
                                                        return res; /* Class 0: 12.33%, Class 1: 87.67% (tau=0.31) */
                                                    }
                                                }
                                            } else {
                                                {
                                                    DecisionTreeResult res = { 100.0000f, 0.0000f, 1.00000f, 0.00000f, false };
                                                    return res; /* Class 0: 100.00%, Class 1: 0.00% (tau=0.31) */
                                                }
                                            }
                                        }
                                    }
                                } else {
                                    if (features[14] /* Feature_HR_Std_60s_mean */ <= -0.93233f) {
                                        {
                                            DecisionTreeResult res = { 100.0000f, 0.0000f, 1.00000f, 0.00000f, false };
                                            return res; /* Class 0: 100.00%, Class 1: 0.00% (tau=0.31) */
                                        }
                                    } else {
                                        if (features[19] /* HR_std */ <= 0.23816f) {
                                            if (features[13] /* Feature_HR_Mean_60s_mean */ <= 5.55340f) {
                                                if (features[51] /* Feature_HR_Mean_60s_min */ <= 2.80436f) {
                                                    {
                                                        DecisionTreeResult res = { 3.2847f, 96.7153f, 0.03285f, 0.96715f, true };
                                                        return res; /* Class 0: 3.28%, Class 1: 96.72% (tau=0.31) */
                                                    }
                                                } else {
                                                    {
                                                        DecisionTreeResult res = { 0.0000f, 100.0000f, 0.00000f, 1.00000f, true };
                                                        return res; /* Class 0: 0.00%, Class 1: 100.00% (tau=0.31) */
                                                    }
                                                }
                                            } else {
                                                {
                                                    DecisionTreeResult res = { 20.0000f, 80.0000f, 0.20000f, 0.80000f, true };
                                                    return res; /* Class 0: 20.00%, Class 1: 80.00% (tau=0.31) */
                                                }
                                            }
                                        } else {
                                            if (features[3] /* ART_MBP_mean */ <= -0.15888f) {
                                                if (features[93] /* Feature_MBP_Std_60s_slope */ <= -4.34014f) {
                                                    {
                                                        DecisionTreeResult res = { 20.0000f, 80.0000f, 0.20000f, 0.80000f, true };
                                                        return res; /* Class 0: 20.00%, Class 1: 80.00% (tau=0.31) */
                                                    }
                                                } else {
                                                    {
                                                        DecisionTreeResult res = { 0.0000f, 100.0000f, 0.00000f, 1.00000f, true };
                                                        return res; /* Class 0: 0.00%, Class 1: 100.00% (tau=0.31) */
                                                    }
                                                }
                                            } else {
                                                if (features[27] /* BT_std */ <= -0.27547f) {
                                                    {
                                                        DecisionTreeResult res = { 31.0345f, 68.9655f, 0.31034f, 0.68966f, true };
                                                        return res; /* Class 0: 31.03%, Class 1: 68.97% (tau=0.31) */
                                                    }
                                                } else {
                                                    {
                                                        DecisionTreeResult res = { 6.1404f, 93.8596f, 0.06140f, 0.93860f, true };
                                                        return res; /* Class 0: 6.14%, Class 1: 93.86% (tau=0.31) */
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        } else {
            if (features[65] /* BT_max */ <= 0.33953f) {
                if (features[69] /* Feature_Rate_Pressure_Product_max */ <= 0.95510f) {
                    if (features[14] /* Feature_HR_Std_60s_mean */ <= 2.02001f) {
                        if (features[38] /* HR_min */ <= 0.85147f) {
                            if (features[72] /* Feature_HR_Delta_60s_max */ <= 0.37263f) {
                                if (features[40] /* ART_DBP_min */ <= 2.66699f) {
                                    if (features[49] /* Feature_Modified_Shock_Index_min */ <= 0.40261f) {
                                        if (features[57] /* HR_max */ <= -0.11141f) {
                                            if (features[33] /* Feature_HR_Std_60s_std */ <= 0.23569f) {
                                                if (features[35] /* Feature_MBP_Mean_60s_std */ <= 4.82665f) {
                                                    {
                                                        DecisionTreeResult res = { 99.4140f, 0.5860f, 0.99414f, 0.00586f, false };
                                                        return res; /* Class 0: 99.41%, Class 1: 0.59% (tau=0.31) */
                                                    }
                                                } else {
                                                    {
                                                        DecisionTreeResult res = { 60.0000f, 40.0000f, 0.60000f, 0.40000f, true };
                                                        return res; /* Class 0: 60.00%, Class 1: 40.00% (tau=0.31) */
                                                    }
                                                }
                                            } else {
                                                if (features[86] /* Feature_Shock_Index_slope */ <= 0.48041f) {
                                                    {
                                                        DecisionTreeResult res = { 96.5672f, 3.4328f, 0.96567f, 0.03433f, false };
                                                        return res; /* Class 0: 96.57%, Class 1: 3.43% (tau=0.31) */
                                                    }
                                                } else {
                                                    {
                                                        DecisionTreeResult res = { 87.5000f, 12.5000f, 0.87500f, 0.12500f, false };
                                                        return res; /* Class 0: 87.50%, Class 1: 12.50% (tau=0.31) */
                                                    }
                                                }
                                            }
                                        } else {
                                            if (features[26] /* FIO2_std */ <= 0.06921f) {
                                                if (features[17] /* Feature_MBP_Std_60s_mean */ <= -0.56510f) {
                                                    {
                                                        DecisionTreeResult res = { 84.8485f, 15.1515f, 0.84848f, 0.15152f, false };
                                                        return res; /* Class 0: 84.85%, Class 1: 15.15% (tau=0.31) */
                                                    }
                                                } else {
                                                    {
                                                        DecisionTreeResult res = { 95.6938f, 4.3062f, 0.95694f, 0.04306f, false };
                                                        return res; /* Class 0: 95.69%, Class 1: 4.31% (tau=0.31) */
                                                    }
                                                }
                                            } else {
                                                if (features[38] /* HR_min */ <= -1.38761f) {
                                                    {
                                                        DecisionTreeResult res = { 16.6667f, 83.3333f, 0.16667f, 0.83333f, true };
                                                        return res; /* Class 0: 16.67%, Class 1: 83.33% (tau=0.31) */
                                                    }
                                                } else {
                                                    {
                                                        DecisionTreeResult res = { 87.5000f, 12.5000f, 0.87500f, 0.12500f, false };
                                                        return res; /* Class 0: 87.50%, Class 1: 12.50% (tau=0.31) */
                                                    }
                                                }
                                            }
                                        }
                                    } else {
                                        if (features[65] /* BT_max */ <= -3.37397f) {
                                            {
                                                DecisionTreeResult res = { 48.0000f, 52.0000f, 0.48000f, 0.52000f, true };
                                                return res; /* Class 0: 48.00%, Class 1: 52.00% (tau=0.31) */
                                            }
                                        } else {
                                            if (features[92] /* Feature_MBP_Mean_60s_slope */ <= 2.57232f) {
                                                if (features[17] /* Feature_MBP_Std_60s_mean */ <= 5.78594f) {
                                                    {
                                                        DecisionTreeResult res = { 91.7870f, 8.2130f, 0.91787f, 0.08213f, false };
                                                        return res; /* Class 0: 91.79%, Class 1: 8.21% (tau=0.31) */
                                                    }
                                                } else {
                                                    {
                                                        DecisionTreeResult res = { 25.0000f, 75.0000f, 0.25000f, 0.75000f, true };
                                                        return res; /* Class 0: 25.00%, Class 1: 75.00% (tau=0.31) */
                                                    }
                                                }
                                            } else {
                                                {
                                                    DecisionTreeResult res = { 55.5556f, 44.4444f, 0.55556f, 0.44444f, true };
                                                    return res; /* Class 0: 55.56%, Class 1: 44.44% (tau=0.31) */
                                                }
                                            }
                                        }
                                    }
                                } else {
                                    {
                                        DecisionTreeResult res = { 46.4286f, 53.5714f, 0.46429f, 0.53571f, true };
                                        return res; /* Class 0: 46.43%, Class 1: 53.57% (tau=0.31) */
                                    }
                                }
                            } else {
                                if (features[57] /* HR_max */ <= 0.69152f) {
                                    if (features[11] /* Feature_Modified_Shock_Index_mean */ <= 7.96100f) {
                                        if (features[68] /* Feature_Modified_Shock_Index_max */ <= 0.12034f) {
                                            if (features[51] /* Feature_HR_Mean_60s_min */ <= -2.20930f) {
                                                {
                                                    DecisionTreeResult res = { 75.5556f, 24.4444f, 0.75556f, 0.24444f, false };
                                                    return res; /* Class 0: 75.56%, Class 1: 24.44% (tau=0.31) */
                                                }
                                            } else {
                                                if (features[76] /* HR_slope */ <= 1.51131f) {
                                                    {
                                                        DecisionTreeResult res = { 94.5617f, 5.4383f, 0.94562f, 0.05438f, false };
                                                        return res; /* Class 0: 94.56%, Class 1: 5.44% (tau=0.31) */
                                                    }
                                                } else {
                                                    {
                                                        DecisionTreeResult res = { 88.0000f, 12.0000f, 0.88000f, 0.12000f, false };
                                                        return res; /* Class 0: 88.00%, Class 1: 12.00% (tau=0.31) */
                                                    }
                                                }
                                            }
                                        } else {
                                            if (features[0] /* HR_mean */ <= 1.46602f) {
                                                if (features[67] /* Feature_Shock_Index_max */ <= 1.53706f) {
                                                    {
                                                        DecisionTreeResult res = { 89.1040f, 10.8960f, 0.89104f, 0.10896f, false };
                                                        return res; /* Class 0: 89.10%, Class 1: 10.90% (tau=0.31) */
                                                    }
                                                } else {
                                                    {
                                                        DecisionTreeResult res = { 96.0976f, 3.9024f, 0.96098f, 0.03902f, false };
                                                        return res; /* Class 0: 96.10%, Class 1: 3.90% (tau=0.31) */
                                                    }
                                                }
                                            } else {
                                                {
                                                    DecisionTreeResult res = { 20.0000f, 80.0000f, 0.20000f, 0.80000f, true };
                                                    return res; /* Class 0: 20.00%, Class 1: 80.00% (tau=0.31) */
                                                }
                                            }
                                        }
                                    } else {
                                        {
                                            DecisionTreeResult res = { 33.3333f, 66.6667f, 0.33333f, 0.66667f, true };
                                            return res; /* Class 0: 33.33%, Class 1: 66.67% (tau=0.31) */
                                        }
                                    }
                                } else {
                                    if (features[1] /* ART_SBP_mean */ <= -0.63389f) {
                                        if (features[54] /* Feature_MBP_Mean_60s_min */ <= -0.83313f) {
                                            if (features[13] /* Feature_HR_Mean_60s_mean */ <= 1.02330f) {
                                                if (features[46] /* BT_min */ <= -3.24548f) {
                                                    {
                                                        DecisionTreeResult res = { 52.5000f, 47.5000f, 0.52500f, 0.47500f, true };
                                                        return res; /* Class 0: 52.50%, Class 1: 47.50% (tau=0.31) */
                                                    }
                                                } else {
                                                    {
                                                        DecisionTreeResult res = { 90.6067f, 9.3933f, 0.90607f, 0.09393f, false };
                                                        return res; /* Class 0: 90.61%, Class 1: 9.39% (tau=0.31) */
                                                    }
                                                }
                                            } else {
                                                if (features[25] /* ETCO2_std */ <= 2.90806f) {
                                                    {
                                                        DecisionTreeResult res = { 35.5932f, 64.4068f, 0.35593f, 0.64407f, true };
                                                        return res; /* Class 0: 35.59%, Class 1: 64.41% (tau=0.31) */
                                                    }
                                                } else {
                                                    {
                                                        DecisionTreeResult res = { 93.3333f, 6.6667f, 0.93333f, 0.06667f, false };
                                                        return res; /* Class 0: 93.33%, Class 1: 6.67% (tau=0.31) */
                                                    }
                                                }
                                            }
                                        } else {
                                            if (features[17] /* Feature_MBP_Std_60s_mean */ <= 0.26352f) {
                                                if (features[12] /* Feature_Rate_Pressure_Product_mean */ <= 0.11199f) {
                                                    {
                                                        DecisionTreeResult res = { 65.6863f, 34.3137f, 0.65686f, 0.34314f, true };
                                                        return res; /* Class 0: 65.69%, Class 1: 34.31% (tau=0.31) */
                                                    }
                                                } else {
                                                    {
                                                        DecisionTreeResult res = { 18.1818f, 81.8182f, 0.18182f, 0.81818f, true };
                                                        return res; /* Class 0: 18.18%, Class 1: 81.82% (tau=0.31) */
                                                    }
                                                }
                                            } else {
                                                if (features[22] /* ART_MBP_std */ <= 1.07978f) {
                                                    {
                                                        DecisionTreeResult res = { 98.3051f, 1.6949f, 0.98305f, 0.01695f, false };
                                                        return res; /* Class 0: 98.31%, Class 1: 1.69% (tau=0.31) */
                                                    }
                                                } else {
                                                    {
                                                        DecisionTreeResult res = { 70.5882f, 29.4118f, 0.70588f, 0.29412f, false };
                                                        return res; /* Class 0: 70.59%, Class 1: 29.41% (tau=0.31) */
                                                    }
                                                }
                                            }
                                        }
                                    } else {
                                        if (features[38] /* HR_min */ <= 0.03726f) {
                                            if (features[0] /* HR_mean */ <= 1.42754f) {
                                                if (features[72] /* Feature_HR_Delta_60s_max */ <= 0.57562f) {
                                                    {
                                                        DecisionTreeResult res = { 77.6398f, 22.3602f, 0.77640f, 0.22360f, false };
                                                        return res; /* Class 0: 77.64%, Class 1: 22.36% (tau=0.31) */
                                                    }
                                                } else {
                                                    {
                                                        DecisionTreeResult res = { 91.3024f, 8.6976f, 0.91302f, 0.08698f, false };
                                                        return res; /* Class 0: 91.30%, Class 1: 8.70% (tau=0.31) */
                                                    }
                                                }
                                            } else {
                                                {
                                                    DecisionTreeResult res = { 21.4286f, 78.5714f, 0.21429f, 0.78571f, true };
                                                    return res; /* Class 0: 21.43%, Class 1: 78.57% (tau=0.31) */
                                                }
                                            }
                                        } else {
                                            if (features[51] /* Feature_HR_Mean_60s_min */ <= 1.46135f) {
                                                if (features[5] /* RR_CO2_mean */ <= -1.13287f) {
                                                    {
                                                        DecisionTreeResult res = { 67.0455f, 32.9545f, 0.67045f, 0.32955f, true };
                                                        return res; /* Class 0: 67.05%, Class 1: 32.95% (tau=0.31) */
                                                    }
                                                } else {
                                                    {
                                                        DecisionTreeResult res = { 85.0691f, 14.9309f, 0.85069f, 0.14931f, false };
                                                        return res; /* Class 0: 85.07%, Class 1: 14.93% (tau=0.31) */
                                                    }
                                                }
                                            } else {
                                                if (features[40] /* ART_DBP_min */ <= 0.46154f) {
                                                    {
                                                        DecisionTreeResult res = { 28.5714f, 71.4286f, 0.28571f, 0.71429f, true };
                                                        return res; /* Class 0: 28.57%, Class 1: 71.43% (tau=0.31) */
                                                    }
                                                } else {
                                                    {
                                                        DecisionTreeResult res = { 79.1667f, 20.8333f, 0.79167f, 0.20833f, false };
                                                        return res; /* Class 0: 79.17%, Class 1: 20.83% (tau=0.31) */
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        } else {
                            if (features[67] /* Feature_Shock_Index_max */ <= 0.46812f) {
                                if (features[0] /* HR_mean */ <= 1.76663f) {
                                    if (features[60] /* ART_MBP_max */ <= -0.44741f) {
                                        if (features[51] /* Feature_HR_Mean_60s_min */ <= 1.52324f) {
                                            if (features[60] /* ART_MBP_max */ <= -1.34158f) {
                                                if (features[51] /* Feature_HR_Mean_60s_min */ <= 0.98648f) {
                                                    {
                                                        DecisionTreeResult res = { 29.6296f, 70.3704f, 0.29630f, 0.70370f, true };
                                                        return res; /* Class 0: 29.63%, Class 1: 70.37% (tau=0.31) */
                                                    }
                                                } else {
                                                    {
                                                        DecisionTreeResult res = { 80.3279f, 19.6721f, 0.80328f, 0.19672f, false };
                                                        return res; /* Class 0: 80.33%, Class 1: 19.67% (tau=0.31) */
                                                    }
                                                }
                                            } else {
                                                if (features[30] /* Feature_Modified_Shock_Index_std */ <= -0.07641f) {
                                                    {
                                                        DecisionTreeResult res = { 94.1176f, 5.8824f, 0.94118f, 0.05882f, false };
                                                        return res; /* Class 0: 94.12%, Class 1: 5.88% (tau=0.31) */
                                                    }
                                                } else {
                                                    {
                                                        DecisionTreeResult res = { 57.1429f, 42.8571f, 0.57143f, 0.42857f, true };
                                                        return res; /* Class 0: 57.14%, Class 1: 42.86% (tau=0.31) */
                                                    }
                                                }
                                            }
                                        } else {
                                            {
                                                DecisionTreeResult res = { 20.8333f, 79.1667f, 0.20833f, 0.79167f, true };
                                                return res; /* Class 0: 20.83%, Class 1: 79.17% (tau=0.31) */
                                            }
                                        }
                                    } else {
                                        if (features[55] /* Feature_MBP_Std_60s_min */ <= 0.38066f) {
                                            if (features[53] /* Feature_HR_Delta_60s_min */ <= -0.63580f) {
                                                if (features[3] /* ART_MBP_mean */ <= 0.25726f) {
                                                    {
                                                        DecisionTreeResult res = { 40.0000f, 60.0000f, 0.40000f, 0.60000f, true };
                                                        return res; /* Class 0: 40.00%, Class 1: 60.00% (tau=0.31) */
                                                    }
                                                } else {
                                                    {
                                                        DecisionTreeResult res = { 88.0952f, 11.9048f, 0.88095f, 0.11905f, false };
                                                        return res; /* Class 0: 88.10%, Class 1: 11.90% (tau=0.31) */
                                                    }
                                                }
                                            } else {
                                                if (features[26] /* FIO2_std */ <= 1.45162f) {
                                                    {
                                                        DecisionTreeResult res = { 98.9130f, 1.0870f, 0.98913f, 0.01087f, false };
                                                        return res; /* Class 0: 98.91%, Class 1: 1.09% (tau=0.31) */
                                                    }
                                                } else {
                                                    {
                                                        DecisionTreeResult res = { 50.0000f, 50.0000f, 0.50000f, 0.50000f, true };
                                                        return res; /* Class 0: 50.00%, Class 1: 50.00% (tau=0.31) */
                                                    }
                                                }
                                            }
                                        } else {
                                            {
                                                DecisionTreeResult res = { 63.6364f, 36.3636f, 0.63636f, 0.36364f, true };
                                                return res; /* Class 0: 63.64%, Class 1: 36.36% (tau=0.31) */
                                            }
                                        }
                                    }
                                } else {
                                    if (features[62] /* RR_CO2_max */ <= -0.63580f) {
                                        {
                                            DecisionTreeResult res = { 100.0000f, 0.0000f, 1.00000f, 0.00000f, false };
                                            return res; /* Class 0: 100.00%, Class 1: 0.00% (tau=0.31) */
                                        }
                                    } else {
                                        {
                                            DecisionTreeResult res = { 31.1111f, 68.8889f, 0.31111f, 0.68889f, true };
                                            return res; /* Class 0: 31.11%, Class 1: 68.89% (tau=0.31) */
                                        }
                                    }
                                }
                            } else {
                                if (features[51] /* Feature_HR_Mean_60s_min */ <= 1.80005f) {
                                    if (features[22] /* ART_MBP_std */ <= -0.50274f) {
                                        if (features[25] /* ETCO2_std */ <= -0.15865f) {
                                            if (features[3] /* ART_MBP_mean */ <= 0.07884f) {
                                                if (features[43] /* RR_CO2_min */ <= 0.71419f) {
                                                    {
                                                        DecisionTreeResult res = { 47.0588f, 52.9412f, 0.47059f, 0.52941f, true };
                                                        return res; /* Class 0: 47.06%, Class 1: 52.94% (tau=0.31) */
                                                    }
                                                } else {
                                                    {
                                                        DecisionTreeResult res = { 21.1765f, 78.8235f, 0.21176f, 0.78824f, true };
                                                        return res; /* Class 0: 21.18%, Class 1: 78.82% (tau=0.31) */
                                                    }
                                                }
                                            } else {
                                                {
                                                    DecisionTreeResult res = { 70.0000f, 30.0000f, 0.70000f, 0.30000f, false };
                                                    return res; /* Class 0: 70.00%, Class 1: 30.00% (tau=0.31) */
                                                }
                                            }
                                        } else {
                                            if (features[21] /* ART_DBP_std */ <= -0.74701f) {
                                                {
                                                    DecisionTreeResult res = { 26.6667f, 73.3333f, 0.26667f, 0.73333f, true };
                                                    return res; /* Class 0: 26.67%, Class 1: 73.33% (tau=0.31) */
                                                }
                                            } else {
                                                if (features[32] /* Feature_HR_Mean_60s_std */ <= -0.28068f) {
                                                    {
                                                        DecisionTreeResult res = { 22.2222f, 77.7778f, 0.22222f, 0.77778f, true };
                                                        return res; /* Class 0: 22.22%, Class 1: 77.78% (tau=0.31) */
                                                    }
                                                } else {
                                                    {
                                                        DecisionTreeResult res = { 90.0000f, 10.0000f, 0.90000f, 0.10000f, false };
                                                        return res; /* Class 0: 90.00%, Class 1: 10.00% (tau=0.31) */
                                                    }
                                                }
                                            }
                                        }
                                    } else {
                                        if (features[70] /* Feature_HR_Mean_60s_max */ <= 1.26273f) {
                                            if (features[35] /* Feature_MBP_Mean_60s_std */ <= -0.53515f) {
                                                {
                                                    DecisionTreeResult res = { 16.6667f, 83.3333f, 0.16667f, 0.83333f, true };
                                                    return res; /* Class 0: 16.67%, Class 1: 83.33% (tau=0.31) */
                                                }
                                            } else {
                                                if (features[66] /* Feature_Pulse_Pressure_max */ <= 1.75875f) {
                                                    {
                                                        DecisionTreeResult res = { 87.4552f, 12.5448f, 0.87455f, 0.12545f, false };
                                                        return res; /* Class 0: 87.46%, Class 1: 12.54% (tau=0.31) */
                                                    }
                                                } else {
                                                    {
                                                        DecisionTreeResult res = { 0.0000f, 100.0000f, 0.00000f, 1.00000f, true };
                                                        return res; /* Class 0: 0.00%, Class 1: 100.00% (tau=0.31) */
                                                    }
                                                }
                                            }
                                        } else {
                                            if (features[20] /* ART_SBP_std */ <= -0.17217f) {
                                                if (features[25] /* ETCO2_std */ <= 0.18306f) {
                                                    {
                                                        DecisionTreeResult res = { 64.7059f, 35.2941f, 0.64706f, 0.35294f, true };
                                                        return res; /* Class 0: 64.71%, Class 1: 35.29% (tau=0.31) */
                                                    }
                                                } else {
                                                    {
                                                        DecisionTreeResult res = { 100.0000f, 0.0000f, 1.00000f, 0.00000f, false };
                                                        return res; /* Class 0: 100.00%, Class 1: 0.00% (tau=0.31) */
                                                    }
                                                }
                                            } else {
                                                if (features[39] /* ART_SBP_min */ <= -1.75443f) {
                                                    {
                                                        DecisionTreeResult res = { 89.1892f, 10.8108f, 0.89189f, 0.10811f, false };
                                                        return res; /* Class 0: 89.19%, Class 1: 10.81% (tau=0.31) */
                                                    }
                                                } else {
                                                    {
                                                        DecisionTreeResult res = { 35.1351f, 64.8649f, 0.35135f, 0.64865f, true };
                                                        return res; /* Class 0: 35.14%, Class 1: 64.86% (tau=0.31) */
                                                    }
                                                }
                                            }
                                        }
                                    }
                                } else {
                                    if (features[68] /* Feature_Modified_Shock_Index_max */ <= 0.93078f) {
                                        if (features[82] /* ETCO2_slope */ <= 0.01874f) {
                                            {
                                                DecisionTreeResult res = { 56.5217f, 43.4783f, 0.56522f, 0.43478f, true };
                                                return res; /* Class 0: 56.52%, Class 1: 43.48% (tau=0.31) */
                                            }
                                        } else {
                                            {
                                                DecisionTreeResult res = { 13.7931f, 86.2069f, 0.13793f, 0.86207f, true };
                                                return res; /* Class 0: 13.79%, Class 1: 86.21% (tau=0.31) */
                                            }
                                        }
                                    } else {
                                        if (features[48] /* Feature_Shock_Index_min */ <= 1.94284f) {
                                            if (features[17] /* Feature_MBP_Std_60s_mean */ <= 0.34319f) {
                                                if (features[6] /* ETCO2_mean */ <= 0.60569f) {
                                                    {
                                                        DecisionTreeResult res = { 9.3333f, 90.6667f, 0.09333f, 0.90667f, true };
                                                        return res; /* Class 0: 9.33%, Class 1: 90.67% (tau=0.31) */
                                                    }
                                                } else {
                                                    {
                                                        DecisionTreeResult res = { 55.5556f, 44.4444f, 0.55556f, 0.44444f, true };
                                                        return res; /* Class 0: 55.56%, Class 1: 44.44% (tau=0.31) */
                                                    }
                                                }
                                            } else {
                                                {
                                                    DecisionTreeResult res = { 45.4545f, 54.5455f, 0.45455f, 0.54545f, true };
                                                    return res; /* Class 0: 45.45%, Class 1: 54.55% (tau=0.31) */
                                                }
                                            }
                                        } else {
                                            {
                                                DecisionTreeResult res = { 0.0000f, 100.0000f, 0.00000f, 1.00000f, true };
                                                return res; /* Class 0: 0.00%, Class 1: 100.00% (tau=0.31) */
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    } else {
                        if (features[0] /* HR_mean */ <= 1.53129f) {
                            if (features[38] /* HR_min */ <= 0.30866f) {
                                if (features[52] /* Feature_HR_Std_60s_min */ <= 4.18688f) {
                                    if (features[51] /* Feature_HR_Mean_60s_min */ <= 0.66803f) {
                                        if (features[54] /* Feature_MBP_Mean_60s_min */ <= 0.24964f) {
                                            if (features[10] /* Feature_Shock_Index_mean */ <= 0.80438f) {
                                                if (features[33] /* Feature_HR_Std_60s_std */ <= 2.05523f) {
                                                    {
                                                        DecisionTreeResult res = { 94.9091f, 5.0909f, 0.94909f, 0.05091f, false };
                                                        return res; /* Class 0: 94.91%, Class 1: 5.09% (tau=0.31) */
                                                    }
                                                } else {
                                                    {
                                                        DecisionTreeResult res = { 62.5000f, 37.5000f, 0.62500f, 0.37500f, true };
                                                        return res; /* Class 0: 62.50%, Class 1: 37.50% (tau=0.31) */
                                                    }
                                                }
                                            } else {
                                                {
                                                    DecisionTreeResult res = { 47.3684f, 52.6316f, 0.47368f, 0.52632f, true };
                                                    return res; /* Class 0: 47.37%, Class 1: 52.63% (tau=0.31) */
                                                }
                                            }
                                        } else {
                                            if (features[18] /* Feature_MBP_Delta_60s_mean */ <= -0.08828f) {
                                                if (features[52] /* Feature_HR_Std_60s_min */ <= -0.40007f) {
                                                    {
                                                        DecisionTreeResult res = { 42.8571f, 57.1429f, 0.42857f, 0.57143f, true };
                                                        return res; /* Class 0: 42.86%, Class 1: 57.14% (tau=0.31) */
                                                    }
                                                } else {
                                                    {
                                                        DecisionTreeResult res = { 89.5833f, 10.4167f, 0.89583f, 0.10417f, false };
                                                        return res; /* Class 0: 89.58%, Class 1: 10.42% (tau=0.31) */
                                                    }
                                                }
                                            } else {
                                                if (features[7] /* FIO2_mean */ <= -0.69089f) {
                                                    {
                                                        DecisionTreeResult res = { 28.5714f, 71.4286f, 0.28571f, 0.71429f, true };
                                                        return res; /* Class 0: 28.57%, Class 1: 71.43% (tau=0.31) */
                                                    }
                                                } else {
                                                    {
                                                        DecisionTreeResult res = { 76.5625f, 23.4375f, 0.76562f, 0.23438f, false };
                                                        return res; /* Class 0: 76.56%, Class 1: 23.44% (tau=0.31) */
                                                    }
                                                }
                                            }
                                        }
                                    } else {
                                        {
                                            DecisionTreeResult res = { 38.0952f, 61.9048f, 0.38095f, 0.61905f, true };
                                            return res; /* Class 0: 38.10%, Class 1: 61.90% (tau=0.31) */
                                        }
                                    }
                                } else {
                                    if (features[86] /* Feature_Shock_Index_slope */ <= 1.55302f) {
                                        if (features[77] /* ART_SBP_slope */ <= 1.13909f) {
                                            if (features[17] /* Feature_MBP_Std_60s_mean */ <= -0.45741f) {
                                                {
                                                    DecisionTreeResult res = { 64.2857f, 35.7143f, 0.64286f, 0.35714f, true };
                                                    return res; /* Class 0: 64.29%, Class 1: 35.71% (tau=0.31) */
                                                }
                                            } else {
                                                if (features[42] /* PLETH_SPO2_min */ <= -0.18239f) {
                                                    {
                                                        DecisionTreeResult res = { 99.4819f, 0.5181f, 0.99482f, 0.00518f, false };
                                                        return res; /* Class 0: 99.48%, Class 1: 0.52% (tau=0.31) */
                                                    }
                                                } else {
                                                    {
                                                        DecisionTreeResult res = { 92.9688f, 7.0312f, 0.92969f, 0.07031f, false };
                                                        return res; /* Class 0: 92.97%, Class 1: 7.03% (tau=0.31) */
                                                    }
                                                }
                                            }
                                        } else {
                                            {
                                                DecisionTreeResult res = { 55.5556f, 44.4444f, 0.55556f, 0.44444f, true };
                                                return res; /* Class 0: 55.56%, Class 1: 44.44% (tau=0.31) */
                                            }
                                        }
                                    } else {
                                        {
                                            DecisionTreeResult res = { 41.6667f, 58.3333f, 0.41667f, 0.58333f, true };
                                            return res; /* Class 0: 41.67%, Class 1: 58.33% (tau=0.31) */
                                        }
                                    }
                                }
                            } else {
                                if (features[8] /* BT_mean */ <= -0.92455f) {
                                    {
                                        DecisionTreeResult res = { 42.8571f, 57.1429f, 0.42857f, 0.57143f, true };
                                        return res; /* Class 0: 42.86%, Class 1: 57.14% (tau=0.31) */
                                    }
                                } else {
                                    if (features[27] /* BT_std */ <= -0.13538f) {
                                        if (features[7] /* FIO2_mean */ <= 2.02143f) {
                                            if (features[64] /* FIO2_max */ <= -0.07635f) {
                                                if (features[86] /* Feature_Shock_Index_slope */ <= -0.96989f) {
                                                    {
                                                        DecisionTreeResult res = { 16.6667f, 83.3333f, 0.16667f, 0.83333f, true };
                                                        return res; /* Class 0: 16.67%, Class 1: 83.33% (tau=0.31) */
                                                    }
                                                } else {
                                                    {
                                                        DecisionTreeResult res = { 76.3158f, 23.6842f, 0.76316f, 0.23684f, false };
                                                        return res; /* Class 0: 76.32%, Class 1: 23.68% (tau=0.31) */
                                                    }
                                                }
                                            } else {
                                                if (features[65] /* BT_max */ <= 0.30659f) {
                                                    {
                                                        DecisionTreeResult res = { 98.3333f, 1.6667f, 0.98333f, 0.01667f, false };
                                                        return res; /* Class 0: 98.33%, Class 1: 1.67% (tau=0.31) */
                                                    }
                                                } else {
                                                    {
                                                        DecisionTreeResult res = { 71.4286f, 28.5714f, 0.71429f, 0.28571f, false };
                                                        return res; /* Class 0: 71.43%, Class 1: 28.57% (tau=0.31) */
                                                    }
                                                }
                                            }
                                        } else {
                                            {
                                                DecisionTreeResult res = { 28.5714f, 71.4286f, 0.28571f, 0.71429f, true };
                                                return res; /* Class 0: 28.57%, Class 1: 71.43% (tau=0.31) */
                                            }
                                        }
                                    } else {
                                        {
                                            DecisionTreeResult res = { 13.3333f, 86.6667f, 0.13333f, 0.86667f, true };
                                            return res; /* Class 0: 13.33%, Class 1: 86.67% (tau=0.31) */
                                        }
                                    }
                                }
                            }
                        } else {
                            if (features[8] /* BT_mean */ <= -0.09242f) {
                                if (features[0] /* HR_mean */ <= 1.79535f) {
                                    {
                                        DecisionTreeResult res = { 77.7778f, 22.2222f, 0.77778f, 0.22222f, false };
                                        return res; /* Class 0: 77.78%, Class 1: 22.22% (tau=0.31) */
                                    }
                                } else {
                                    {
                                        DecisionTreeResult res = { 25.7143f, 74.2857f, 0.25714f, 0.74286f, true };
                                        return res; /* Class 0: 25.71%, Class 1: 74.29% (tau=0.31) */
                                    }
                                }
                            } else {
                                if (features[34] /* Feature_HR_Delta_60s_std */ <= 1.08820f) {
                                    {
                                        DecisionTreeResult res = { 22.2222f, 77.7778f, 0.22222f, 0.77778f, true };
                                        return res; /* Class 0: 22.22%, Class 1: 77.78% (tau=0.31) */
                                    }
                                } else {
                                    if (features[63] /* ETCO2_max */ <= 0.75937f) {
                                        {
                                            DecisionTreeResult res = { 0.0000f, 100.0000f, 0.00000f, 1.00000f, true };
                                            return res; /* Class 0: 0.00%, Class 1: 100.00% (tau=0.31) */
                                        }
                                    } else {
                                        {
                                            DecisionTreeResult res = { 20.0000f, 80.0000f, 0.20000f, 0.80000f, true };
                                            return res; /* Class 0: 20.00%, Class 1: 80.00% (tau=0.31) */
                                        }
                                    }
                                }
                            }
                        }
                    }
                } else {
                    if (features[70] /* Feature_HR_Mean_60s_max */ <= 1.40662f) {
                        if (features[49] /* Feature_Modified_Shock_Index_min */ <= 0.61237f) {
                            if (features[0] /* HR_mean */ <= 0.50981f) {
                                if (features[76] /* HR_slope */ <= 4.14475f) {
                                    if (features[8] /* BT_mean */ <= 0.27018f) {
                                        if (features[54] /* Feature_MBP_Mean_60s_min */ <= -2.47086f) {
                                            {
                                                DecisionTreeResult res = { 63.6364f, 36.3636f, 0.63636f, 0.36364f, true };
                                                return res; /* Class 0: 63.64%, Class 1: 36.36% (tau=0.31) */
                                            }
                                        } else {
                                            if (features[48] /* Feature_Shock_Index_min */ <= -0.70820f) {
                                                if (features[89] /* Feature_HR_Mean_60s_slope */ <= 2.08874f) {
                                                    {
                                                        DecisionTreeResult res = { 97.9843f, 2.0157f, 0.97984f, 0.02016f, false };
                                                        return res; /* Class 0: 97.98%, Class 1: 2.02% (tau=0.31) */
                                                    }
                                                } else {
                                                    {
                                                        DecisionTreeResult res = { 85.7143f, 14.2857f, 0.85714f, 0.14286f, false };
                                                        return res; /* Class 0: 85.71%, Class 1: 14.29% (tau=0.31) */
                                                    }
                                                }
                                            } else {
                                                if (features[45] /* FIO2_min */ <= 1.13554f) {
                                                    {
                                                        DecisionTreeResult res = { 94.5573f, 5.4427f, 0.94557f, 0.05443f, false };
                                                        return res; /* Class 0: 94.56%, Class 1: 5.44% (tau=0.31) */
                                                    }
                                                } else {
                                                    {
                                                        DecisionTreeResult res = { 83.7278f, 16.2722f, 0.83728f, 0.16272f, false };
                                                        return res; /* Class 0: 83.73%, Class 1: 16.27% (tau=0.31) */
                                                    }
                                                }
                                            }
                                        }
                                    } else {
                                        if (features[54] /* Feature_MBP_Mean_60s_min */ <= 0.57239f) {
                                            if (features[64] /* FIO2_max */ <= 0.63560f) {
                                                if (features[73] /* Feature_MBP_Mean_60s_max */ <= 3.79203f) {
                                                    {
                                                        DecisionTreeResult res = { 99.3377f, 0.6623f, 0.99338f, 0.00662f, false };
                                                        return res; /* Class 0: 99.34%, Class 1: 0.66% (tau=0.31) */
                                                    }
                                                } else {
                                                    {
                                                        DecisionTreeResult res = { 71.4286f, 28.5714f, 0.71429f, 0.28571f, false };
                                                        return res; /* Class 0: 71.43%, Class 1: 28.57% (tau=0.31) */
                                                    }
                                                }
                                            } else {
                                                if (features[35] /* Feature_MBP_Mean_60s_std */ <= 0.99774f) {
                                                    {
                                                        DecisionTreeResult res = { 85.7143f, 14.2857f, 0.85714f, 0.14286f, false };
                                                        return res; /* Class 0: 85.71%, Class 1: 14.29% (tau=0.31) */
                                                    }
                                                } else {
                                                    {
                                                        DecisionTreeResult res = { 97.2789f, 2.7211f, 0.97279f, 0.02721f, false };
                                                        return res; /* Class 0: 97.28%, Class 1: 2.72% (tau=0.31) */
                                                    }
                                                }
                                            }
                                        } else {
                                            if (features[1] /* ART_SBP_mean */ <= 0.33747f) {
                                                {
                                                    DecisionTreeResult res = { 37.1429f, 62.8571f, 0.37143f, 0.62857f, true };
                                                    return res; /* Class 0: 37.14%, Class 1: 62.86% (tau=0.31) */
                                                }
                                            } else {
                                                if (features[68] /* Feature_Modified_Shock_Index_max */ <= -0.83430f) {
                                                    {
                                                        DecisionTreeResult res = { 0.0000f, 100.0000f, 0.00000f, 1.00000f, true };
                                                        return res; /* Class 0: 0.00%, Class 1: 100.00% (tau=0.31) */
                                                    }
                                                } else {
                                                    {
                                                        DecisionTreeResult res = { 85.9060f, 14.0940f, 0.85906f, 0.14094f, false };
                                                        return res; /* Class 0: 85.91%, Class 1: 14.09% (tau=0.31) */
                                                    }
                                                }
                                            }
                                        }
                                    }
                                } else {
                                    {
                                        DecisionTreeResult res = { 20.0000f, 80.0000f, 0.20000f, 0.80000f, true };
                                        return res; /* Class 0: 20.00%, Class 1: 80.00% (tau=0.31) */
                                    }
                                }
                            } else {
                                if (features[4] /* PLETH_SPO2_mean */ <= -3.11681f) {
                                    {
                                        DecisionTreeResult res = { 40.0000f, 60.0000f, 0.40000f, 0.60000f, true };
                                        return res; /* Class 0: 40.00%, Class 1: 60.00% (tau=0.31) */
                                    }
                                } else {
                                    if (features[20] /* ART_SBP_std */ <= -0.78215f) {
                                        {
                                            DecisionTreeResult res = { 14.2857f, 85.7143f, 0.14286f, 0.85714f, true };
                                            return res; /* Class 0: 14.29%, Class 1: 85.71% (tau=0.31) */
                                        }
                                    } else {
                                        if (features[21] /* ART_DBP_std */ <= 2.05875f) {
                                            if (features[57] /* HR_max */ <= 0.97255f) {
                                                if (features[47] /* Feature_Pulse_Pressure_min */ <= 2.46164f) {
                                                    {
                                                        DecisionTreeResult res = { 89.9293f, 10.0707f, 0.89929f, 0.10071f, false };
                                                        return res; /* Class 0: 89.93%, Class 1: 10.07% (tau=0.31) */
                                                    }
                                                } else {
                                                    {
                                                        DecisionTreeResult res = { 0.0000f, 100.0000f, 0.00000f, 1.00000f, true };
                                                        return res; /* Class 0: 0.00%, Class 1: 100.00% (tau=0.31) */
                                                    }
                                                }
                                            } else {
                                                if (features[0] /* HR_mean */ <= 1.55952f) {
                                                    {
                                                        DecisionTreeResult res = { 75.9076f, 24.0924f, 0.75908f, 0.24092f, false };
                                                        return res; /* Class 0: 75.91%, Class 1: 24.09% (tau=0.31) */
                                                    }
                                                } else {
                                                    {
                                                        DecisionTreeResult res = { 42.8571f, 57.1429f, 0.42857f, 0.57143f, true };
                                                        return res; /* Class 0: 42.86%, Class 1: 57.14% (tau=0.31) */
                                                    }
                                                }
                                            }
                                        } else {
                                            if (features[54] /* Feature_MBP_Mean_60s_min */ <= 1.08654f) {
                                                if (features[60] /* ART_MBP_max */ <= 0.56300f) {
                                                    {
                                                        DecisionTreeResult res = { 86.3636f, 13.6364f, 0.86364f, 0.13636f, false };
                                                        return res; /* Class 0: 86.36%, Class 1: 13.64% (tau=0.31) */
                                                    }
                                                } else {
                                                    {
                                                        DecisionTreeResult res = { 98.7578f, 1.2422f, 0.98758f, 0.01242f, false };
                                                        return res; /* Class 0: 98.76%, Class 1: 1.24% (tau=0.31) */
                                                    }
                                                }
                                            } else {
                                                {
                                                    DecisionTreeResult res = { 66.6667f, 33.3333f, 0.66667f, 0.33333f, true };
                                                    return res; /* Class 0: 66.67%, Class 1: 33.33% (tau=0.31) */
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        } else {
                            if (features[67] /* Feature_Shock_Index_max */ <= 0.14141f) {
                                {
                                    DecisionTreeResult res = { 95.4545f, 4.5455f, 0.95455f, 0.04545f, false };
                                    return res; /* Class 0: 95.45%, Class 1: 4.55% (tau=0.31) */
                                }
                            } else {
                                if (features[24] /* RR_CO2_std */ <= 1.36017f) {
                                    if (features[35] /* Feature_MBP_Mean_60s_std */ <= -0.69372f) {
                                        {
                                            DecisionTreeResult res = { 92.3077f, 7.6923f, 0.92308f, 0.07692f, false };
                                            return res; /* Class 0: 92.31%, Class 1: 7.69% (tau=0.31) */
                                        }
                                    } else {
                                        if (features[5] /* RR_CO2_mean */ <= 0.27992f) {
                                            if (features[50] /* Feature_Rate_Pressure_Product_min */ <= 0.78604f) {
                                                if (features[22] /* ART_MBP_std */ <= 0.24451f) {
                                                    {
                                                        DecisionTreeResult res = { 78.9474f, 21.0526f, 0.78947f, 0.21053f, false };
                                                        return res; /* Class 0: 78.95%, Class 1: 21.05% (tau=0.31) */
                                                    }
                                                } else {
                                                    {
                                                        DecisionTreeResult res = { 10.0000f, 90.0000f, 0.10000f, 0.90000f, true };
                                                        return res; /* Class 0: 10.00%, Class 1: 90.00% (tau=0.31) */
                                                    }
                                                }
                                            } else {
                                                {
                                                    DecisionTreeResult res = { 35.4167f, 64.5833f, 0.35417f, 0.64583f, true };
                                                    return res; /* Class 0: 35.42%, Class 1: 64.58% (tau=0.31) */
                                                }
                                            }
                                        } else {
                                            if (features[33] /* Feature_HR_Std_60s_std */ <= 1.62544f) {
                                                if (features[69] /* Feature_Rate_Pressure_Product_max */ <= 1.26541f) {
                                                    {
                                                        DecisionTreeResult res = { 16.2162f, 83.7838f, 0.16216f, 0.83784f, true };
                                                        return res; /* Class 0: 16.22%, Class 1: 83.78% (tau=0.31) */
                                                    }
                                                } else {
                                                    {
                                                        DecisionTreeResult res = { 64.8649f, 35.1351f, 0.64865f, 0.35135f, true };
                                                        return res; /* Class 0: 64.86%, Class 1: 35.14% (tau=0.31) */
                                                    }
                                                }
                                            } else {
                                                if (features[28] /* Feature_Pulse_Pressure_std */ <= -0.65967f) {
                                                    {
                                                        DecisionTreeResult res = { 60.0000f, 40.0000f, 0.60000f, 0.40000f, true };
                                                        return res; /* Class 0: 60.00%, Class 1: 40.00% (tau=0.31) */
                                                    }
                                                } else {
                                                    {
                                                        DecisionTreeResult res = { 4.1667f, 95.8333f, 0.04167f, 0.95833f, true };
                                                        return res; /* Class 0: 4.17%, Class 1: 95.83% (tau=0.31) */
                                                    }
                                                }
                                            }
                                        }
                                    }
                                } else {
                                    if (features[44] /* ETCO2_min */ <= -3.16830f) {
                                        {
                                            DecisionTreeResult res = { 33.3333f, 66.6667f, 0.33333f, 0.66667f, true };
                                            return res; /* Class 0: 33.33%, Class 1: 66.67% (tau=0.31) */
                                        }
                                    } else {
                                        {
                                            DecisionTreeResult res = { 100.0000f, 0.0000f, 1.00000f, 0.00000f, false };
                                            return res; /* Class 0: 100.00%, Class 1: 0.00% (tau=0.31) */
                                        }
                                    }
                                }
                            }
                        }
                    } else {
                        if (features[0] /* HR_mean */ <= 1.75446f) {
                            if (features[31] /* Feature_Rate_Pressure_Product_std */ <= 2.01976f) {
                                if (features[10] /* Feature_Shock_Index_mean */ <= 0.49821f) {
                                    if (features[11] /* Feature_Modified_Shock_Index_mean */ <= 0.67341f) {
                                        if (features[67] /* Feature_Shock_Index_max */ <= -0.10977f) {
                                            {
                                                DecisionTreeResult res = { 39.3939f, 60.6061f, 0.39394f, 0.60606f, true };
                                                return res; /* Class 0: 39.39%, Class 1: 60.61% (tau=0.31) */
                                            }
                                        } else {
                                            if (features[33] /* Feature_HR_Std_60s_std */ <= 0.38213f) {
                                                if (features[39] /* ART_SBP_min */ <= 0.85166f) {
                                                    {
                                                        DecisionTreeResult res = { 97.7778f, 2.2222f, 0.97778f, 0.02222f, false };
                                                        return res; /* Class 0: 97.78%, Class 1: 2.22% (tau=0.31) */
                                                    }
                                                } else {
                                                    {
                                                        DecisionTreeResult res = { 60.0000f, 40.0000f, 0.60000f, 0.40000f, true };
                                                        return res; /* Class 0: 60.00%, Class 1: 40.00% (tau=0.31) */
                                                    }
                                                }
                                            } else {
                                                if (features[15] /* Feature_HR_Delta_60s_mean */ <= -2.14483f) {
                                                    {
                                                        DecisionTreeResult res = { 90.0000f, 10.0000f, 0.90000f, 0.10000f, false };
                                                        return res; /* Class 0: 90.00%, Class 1: 10.00% (tau=0.31) */
                                                    }
                                                } else {
                                                    {
                                                        DecisionTreeResult res = { 52.0000f, 48.0000f, 0.52000f, 0.48000f, true };
                                                        return res; /* Class 0: 52.00%, Class 1: 48.00% (tau=0.31) */
                                                    }
                                                }
                                            }
                                        }
                                    } else {
                                        {
                                            DecisionTreeResult res = { 0.0000f, 100.0000f, 0.00000f, 1.00000f, true };
                                            return res; /* Class 0: 0.00%, Class 1: 100.00% (tau=0.31) */
                                        }
                                    }
                                } else {
                                    if (features[51] /* Feature_HR_Mean_60s_min */ <= 1.34319f) {
                                        {
                                            DecisionTreeResult res = { 58.6957f, 41.3043f, 0.58696f, 0.41304f, true };
                                            return res; /* Class 0: 58.70%, Class 1: 41.30% (tau=0.31) */
                                        }
                                    } else {
                                        if (features[66] /* Feature_Pulse_Pressure_max */ <= 3.72388f) {
                                            if (features[85] /* Feature_Pulse_Pressure_slope */ <= -1.07446f) {
                                                {
                                                    DecisionTreeResult res = { 77.7778f, 22.2222f, 0.77778f, 0.22222f, false };
                                                    return res; /* Class 0: 77.78%, Class 1: 22.22% (tau=0.31) */
                                                }
                                            } else {
                                                if (features[14] /* Feature_HR_Std_60s_mean */ <= 0.67251f) {
                                                    {
                                                        DecisionTreeResult res = { 42.8571f, 57.1429f, 0.42857f, 0.57143f, true };
                                                        return res; /* Class 0: 42.86%, Class 1: 57.14% (tau=0.31) */
                                                    }
                                                } else {
                                                    {
                                                        DecisionTreeResult res = { 4.7619f, 95.2381f, 0.04762f, 0.95238f, true };
                                                        return res; /* Class 0: 4.76%, Class 1: 95.24% (tau=0.31) */
                                                    }
                                                }
                                            }
                                        } else {
                                            {
                                                DecisionTreeResult res = { 100.0000f, 0.0000f, 1.00000f, 0.00000f, false };
                                                return res; /* Class 0: 100.00%, Class 1: 0.00% (tau=0.31) */
                                            }
                                        }
                                    }
                                }
                            } else {
                                if (features[9] /* Feature_Pulse_Pressure_mean */ <= -1.21211f) {
                                    {
                                        DecisionTreeResult res = { 0.0000f, 100.0000f, 0.00000f, 1.00000f, true };
                                        return res; /* Class 0: 0.00%, Class 1: 100.00% (tau=0.31) */
                                    }
                                } else {
                                    if (features[61] /* PLETH_SPO2_max */ <= -1.88715f) {
                                        {
                                            DecisionTreeResult res = { 50.0000f, 50.0000f, 0.50000f, 0.50000f, true };
                                            return res; /* Class 0: 50.00%, Class 1: 50.00% (tau=0.31) */
                                        }
                                    } else {
                                        if (features[44] /* ETCO2_min */ <= -1.02584f) {
                                            {
                                                DecisionTreeResult res = { 100.0000f, 0.0000f, 1.00000f, 0.00000f, false };
                                                return res; /* Class 0: 100.00%, Class 1: 0.00% (tau=0.31) */
                                            }
                                        } else {
                                            if (features[22] /* ART_MBP_std */ <= 0.68049f) {
                                                {
                                                    DecisionTreeResult res = { 20.0000f, 80.0000f, 0.20000f, 0.80000f, true };
                                                    return res; /* Class 0: 20.00%, Class 1: 80.00% (tau=0.31) */
                                                }
                                            } else {
                                                {
                                                    DecisionTreeResult res = { 86.9565f, 13.0435f, 0.86957f, 0.13043f, false };
                                                    return res; /* Class 0: 86.96%, Class 1: 13.04% (tau=0.31) */
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        } else {
                            if (features[20] /* ART_SBP_std */ <= 1.72157f) {
                                if (features[76] /* HR_slope */ <= -1.72273f) {
                                    {
                                        DecisionTreeResult res = { 34.0426f, 65.9574f, 0.34043f, 0.65957f, true };
                                        return res; /* Class 0: 34.04%, Class 1: 65.96% (tau=0.31) */
                                    }
                                } else {
                                    if (features[21] /* ART_DBP_std */ <= -0.60160f) {
                                        if (features[37] /* Feature_MBP_Delta_60s_std */ <= -0.50438f) {
                                            {
                                                DecisionTreeResult res = { 15.5556f, 84.4444f, 0.15556f, 0.84444f, true };
                                                return res; /* Class 0: 15.56%, Class 1: 84.44% (tau=0.31) */
                                            }
                                        } else {
                                            {
                                                DecisionTreeResult res = { 78.5714f, 21.4286f, 0.78571f, 0.21429f, false };
                                                return res; /* Class 0: 78.57%, Class 1: 21.43% (tau=0.31) */
                                            }
                                        }
                                    } else {
                                        if (features[70] /* Feature_HR_Mean_60s_max */ <= 1.67371f) {
                                            if (features[50] /* Feature_Rate_Pressure_Product_min */ <= 1.05172f) {
                                                if (features[88] /* Feature_Rate_Pressure_Product_slope */ <= -0.00953f) {
                                                    {
                                                        DecisionTreeResult res = { 92.8571f, 7.1429f, 0.92857f, 0.07143f, false };
                                                        return res; /* Class 0: 92.86%, Class 1: 7.14% (tau=0.31) */
                                                    }
                                                } else {
                                                    {
                                                        DecisionTreeResult res = { 25.6410f, 74.3590f, 0.25641f, 0.74359f, true };
                                                        return res; /* Class 0: 25.64%, Class 1: 74.36% (tau=0.31) */
                                                    }
                                                }
                                            } else {
                                                if (features[10] /* Feature_Shock_Index_mean */ <= 0.07947f) {
                                                    {
                                                        DecisionTreeResult res = { 80.0000f, 20.0000f, 0.80000f, 0.20000f, false };
                                                        return res; /* Class 0: 80.00%, Class 1: 20.00% (tau=0.31) */
                                                    }
                                                } else {
                                                    {
                                                        DecisionTreeResult res = { 8.1633f, 91.8367f, 0.08163f, 0.91837f, true };
                                                        return res; /* Class 0: 8.16%, Class 1: 91.84% (tau=0.31) */
                                                    }
                                                }
                                            }
                                        } else {
                                            if (features[60] /* ART_MBP_max */ <= 2.46759f) {
                                                if (features[69] /* Feature_Rate_Pressure_Product_max */ <= 1.56776f) {
                                                    {
                                                        DecisionTreeResult res = { 7.8078f, 92.1922f, 0.07808f, 0.92192f, true };
                                                        return res; /* Class 0: 7.81%, Class 1: 92.19% (tau=0.31) */
                                                    }
                                                } else {
                                                    {
                                                        DecisionTreeResult res = { 1.0169f, 98.9831f, 0.01017f, 0.98983f, true };
                                                        return res; /* Class 0: 1.02%, Class 1: 98.98% (tau=0.31) */
                                                    }
                                                }
                                            } else {
                                                {
                                                    DecisionTreeResult res = { 80.0000f, 20.0000f, 0.80000f, 0.20000f, false };
                                                    return res; /* Class 0: 80.00%, Class 1: 20.00% (tau=0.31) */
                                                }
                                            }
                                        }
                                    }
                                }
                            } else {
                                if (features[89] /* Feature_HR_Mean_60s_slope */ <= -0.71578f) {
                                    {
                                        DecisionTreeResult res = { 71.4286f, 28.5714f, 0.71429f, 0.28571f, false };
                                        return res; /* Class 0: 71.43%, Class 1: 28.57% (tau=0.31) */
                                    }
                                } else {
                                    if (features[28] /* Feature_Pulse_Pressure_std */ <= 1.93314f) {
                                        {
                                            DecisionTreeResult res = { 25.5319f, 74.4681f, 0.25532f, 0.74468f, true };
                                            return res; /* Class 0: 25.53%, Class 1: 74.47% (tau=0.31) */
                                        }
                                    } else {
                                        if (features[13] /* Feature_HR_Mean_60s_mean */ <= 2.01403f) {
                                            {
                                                DecisionTreeResult res = { 22.2222f, 77.7778f, 0.22222f, 0.77778f, true };
                                                return res; /* Class 0: 22.22%, Class 1: 77.78% (tau=0.31) */
                                            }
                                        } else {
                                            if (features[15] /* Feature_HR_Delta_60s_mean */ <= -0.25677f) {
                                                {
                                                    DecisionTreeResult res = { 10.0000f, 90.0000f, 0.10000f, 0.90000f, true };
                                                    return res; /* Class 0: 10.00%, Class 1: 90.00% (tau=0.31) */
                                                }
                                            } else {
                                                {
                                                    DecisionTreeResult res = { 0.0000f, 100.0000f, 0.00000f, 1.00000f, true };
                                                    return res; /* Class 0: 0.00%, Class 1: 100.00% (tau=0.31) */
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            } else {
                if (features[13] /* Feature_HR_Mean_60s_mean */ <= 1.74286f) {
                    if (features[11] /* Feature_Modified_Shock_Index_mean */ <= 0.26576f) {
                        if (features[55] /* Feature_MBP_Std_60s_min */ <= 0.52872f) {
                            if (features[45] /* FIO2_min */ <= -0.73168f) {
                                if (features[38] /* HR_min */ <= 0.64792f) {
                                    if (features[86] /* Feature_Shock_Index_slope */ <= 1.05340f) {
                                        if (features[9] /* Feature_Pulse_Pressure_mean */ <= -0.32036f) {
                                            {
                                                DecisionTreeResult res = { 56.0000f, 44.0000f, 0.56000f, 0.44000f, true };
                                                return res; /* Class 0: 56.00%, Class 1: 44.00% (tau=0.31) */
                                            }
                                        } else {
                                            if (features[1] /* ART_SBP_mean */ <= 1.02816f) {
                                                if (features[92] /* Feature_MBP_Mean_60s_slope */ <= -1.39143f) {
                                                    {
                                                        DecisionTreeResult res = { 80.0000f, 20.0000f, 0.80000f, 0.20000f, false };
                                                        return res; /* Class 0: 80.00%, Class 1: 20.00% (tau=0.31) */
                                                    }
                                                } else {
                                                    {
                                                        DecisionTreeResult res = { 98.7952f, 1.2048f, 0.98795f, 0.01205f, false };
                                                        return res; /* Class 0: 98.80%, Class 1: 1.20% (tau=0.31) */
                                                    }
                                                }
                                            } else {
                                                {
                                                    DecisionTreeResult res = { 81.8182f, 18.1818f, 0.81818f, 0.18182f, false };
                                                    return res; /* Class 0: 81.82%, Class 1: 18.18% (tau=0.31) */
                                                }
                                            }
                                        }
                                    } else {
                                        {
                                            DecisionTreeResult res = { 16.6667f, 83.3333f, 0.16667f, 0.83333f, true };
                                            return res; /* Class 0: 16.67%, Class 1: 83.33% (tau=0.31) */
                                        }
                                    }
                                } else {
                                    {
                                        DecisionTreeResult res = { 16.6667f, 83.3333f, 0.16667f, 0.83333f, true };
                                        return res; /* Class 0: 16.67%, Class 1: 83.33% (tau=0.31) */
                                    }
                                }
                            } else {
                                if (features[52] /* Feature_HR_Std_60s_min */ <= -0.27186f) {
                                    if (features[47] /* Feature_Pulse_Pressure_min */ <= 2.29321f) {
                                        if (features[75] /* Feature_MBP_Delta_60s_max */ <= 2.41282f) {
                                            if (features[83] /* FIO2_slope */ <= -0.04738f) {
                                                if (features[23] /* PLETH_SPO2_std */ <= 0.28197f) {
                                                    {
                                                        DecisionTreeResult res = { 70.0000f, 30.0000f, 0.70000f, 0.30000f, false };
                                                        return res; /* Class 0: 70.00%, Class 1: 30.00% (tau=0.31) */
                                                    }
                                                } else {
                                                    {
                                                        DecisionTreeResult res = { 100.0000f, 0.0000f, 1.00000f, 0.00000f, false };
                                                        return res; /* Class 0: 100.00%, Class 1: 0.00% (tau=0.31) */
                                                    }
                                                }
                                            } else {
                                                if (features[48] /* Feature_Shock_Index_min */ <= -0.97814f) {
                                                    {
                                                        DecisionTreeResult res = { 72.0000f, 28.0000f, 0.72000f, 0.28000f, false };
                                                        return res; /* Class 0: 72.00%, Class 1: 28.00% (tau=0.31) */
                                                    }
                                                } else {
                                                    {
                                                        DecisionTreeResult res = { 91.8367f, 8.1633f, 0.91837f, 0.08163f, false };
                                                        return res; /* Class 0: 91.84%, Class 1: 8.16% (tau=0.31) */
                                                    }
                                                }
                                            }
                                        } else {
                                            {
                                                DecisionTreeResult res = { 43.3333f, 56.6667f, 0.43333f, 0.56667f, true };
                                                return res; /* Class 0: 43.33%, Class 1: 56.67% (tau=0.31) */
                                            }
                                        }
                                    } else {
                                        {
                                            DecisionTreeResult res = { 0.0000f, 100.0000f, 0.00000f, 1.00000f, true };
                                            return res; /* Class 0: 0.00%, Class 1: 100.00% (tau=0.31) */
                                        }
                                    }
                                } else {
                                    if (features[34] /* Feature_HR_Delta_60s_std */ <= 1.61622f) {
                                        if (features[78] /* ART_DBP_slope */ <= -3.37588f) {
                                            {
                                                DecisionTreeResult res = { 54.5455f, 45.4545f, 0.54545f, 0.45455f, true };
                                                return res; /* Class 0: 54.55%, Class 1: 45.45% (tau=0.31) */
                                            }
                                        } else {
                                            if (features[65] /* BT_max */ <= 0.43833f) {
                                                if (features[44] /* ETCO2_min */ <= 1.38442f) {
                                                    {
                                                        DecisionTreeResult res = { 91.8870f, 8.1130f, 0.91887f, 0.08113f, false };
                                                        return res; /* Class 0: 91.89%, Class 1: 8.11% (tau=0.31) */
                                                    }
                                                } else {
                                                    {
                                                        DecisionTreeResult res = { 65.5172f, 34.4828f, 0.65517f, 0.34483f, true };
                                                        return res; /* Class 0: 65.52%, Class 1: 34.48% (tau=0.31) */
                                                    }
                                                }
                                            } else {
                                                if (features[62] /* RR_CO2_max */ <= 3.51364f) {
                                                    {
                                                        DecisionTreeResult res = { 85.0242f, 14.9758f, 0.85024f, 0.14976f, false };
                                                        return res; /* Class 0: 85.02%, Class 1: 14.98% (tau=0.31) */
                                                    }
                                                } else {
                                                    {
                                                        DecisionTreeResult res = { 0.0000f, 100.0000f, 0.00000f, 1.00000f, true };
                                                        return res; /* Class 0: 0.00%, Class 1: 100.00% (tau=0.31) */
                                                    }
                                                }
                                            }
                                        }
                                    } else {
                                        if (features[33] /* Feature_HR_Std_60s_std */ <= 1.54307f) {
                                            {
                                                DecisionTreeResult res = { 57.1429f, 42.8571f, 0.57143f, 0.42857f, true };
                                                return res; /* Class 0: 57.14%, Class 1: 42.86% (tau=0.31) */
                                            }
                                        } else {
                                            if (features[8] /* BT_mean */ <= 0.44030f) {
                                                {
                                                    DecisionTreeResult res = { 95.1220f, 4.8780f, 0.95122f, 0.04878f, false };
                                                    return res; /* Class 0: 95.12%, Class 1: 4.88% (tau=0.31) */
                                                }
                                            } else {
                                                {
                                                    DecisionTreeResult res = { 40.0000f, 60.0000f, 0.40000f, 0.60000f, true };
                                                    return res; /* Class 0: 40.00%, Class 1: 60.00% (tau=0.31) */
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        } else {
                            if (features[12] /* Feature_Rate_Pressure_Product_mean */ <= 1.25890f) {
                                if (features[3] /* ART_MBP_mean */ <= 2.15589f) {
                                    if (features[14] /* Feature_HR_Std_60s_mean */ <= 1.92298f) {
                                        {
                                            DecisionTreeResult res = { 100.0000f, 0.0000f, 1.00000f, 0.00000f, false };
                                            return res; /* Class 0: 100.00%, Class 1: 0.00% (tau=0.31) */
                                        }
                                    } else {
                                        {
                                            DecisionTreeResult res = { 70.5882f, 29.4118f, 0.70588f, 0.29412f, false };
                                            return res; /* Class 0: 70.59%, Class 1: 29.41% (tau=0.31) */
                                        }
                                    }
                                } else {
                                    {
                                        DecisionTreeResult res = { 20.0000f, 80.0000f, 0.20000f, 0.80000f, true };
                                        return res; /* Class 0: 20.00%, Class 1: 80.00% (tau=0.31) */
                                    }
                                }
                            } else {
                                if (features[20] /* ART_SBP_std */ <= 1.12523f) {
                                    if (features[4] /* PLETH_SPO2_mean */ <= 0.36999f) {
                                        {
                                            DecisionTreeResult res = { 6.5217f, 93.4783f, 0.06522f, 0.93478f, true };
                                            return res; /* Class 0: 6.52%, Class 1: 93.48% (tau=0.31) */
                                        }
                                    } else {
                                        {
                                            DecisionTreeResult res = { 55.0000f, 45.0000f, 0.55000f, 0.45000f, true };
                                            return res; /* Class 0: 55.00%, Class 1: 45.00% (tau=0.31) */
                                        }
                                    }
                                } else {
                                    {
                                        DecisionTreeResult res = { 75.0000f, 25.0000f, 0.75000f, 0.25000f, false };
                                        return res; /* Class 0: 75.00%, Class 1: 25.00% (tau=0.31) */
                                    }
                                }
                            }
                        }
                    } else {
                        if (features[51] /* Feature_HR_Mean_60s_min */ <= 0.99098f) {
                            if (features[46] /* BT_min */ <= 0.50879f) {
                                if (features[57] /* HR_max */ <= 1.25357f) {
                                    if (features[27] /* BT_std */ <= 1.10133f) {
                                        if (features[25] /* ETCO2_std */ <= -0.51814f) {
                                            {
                                                DecisionTreeResult res = { 67.3913f, 32.6087f, 0.67391f, 0.32609f, true };
                                                return res; /* Class 0: 67.39%, Class 1: 32.61% (tau=0.31) */
                                            }
                                        } else {
                                            if (features[63] /* ETCO2_max */ <= 0.56162f) {
                                                if (features[18] /* Feature_MBP_Delta_60s_mean */ <= 6.47096f) {
                                                    {
                                                        DecisionTreeResult res = { 94.9612f, 5.0388f, 0.94961f, 0.05039f, false };
                                                        return res; /* Class 0: 94.96%, Class 1: 5.04% (tau=0.31) */
                                                    }
                                                } else {
                                                    {
                                                        DecisionTreeResult res = { 20.0000f, 80.0000f, 0.20000f, 0.80000f, true };
                                                        return res; /* Class 0: 20.00%, Class 1: 80.00% (tau=0.31) */
                                                    }
                                                }
                                            } else {
                                                if (features[41] /* ART_MBP_min */ <= -0.55701f) {
                                                    {
                                                        DecisionTreeResult res = { 95.1613f, 4.8387f, 0.95161f, 0.04839f, false };
                                                        return res; /* Class 0: 95.16%, Class 1: 4.84% (tau=0.31) */
                                                    }
                                                } else {
                                                    {
                                                        DecisionTreeResult res = { 67.1233f, 32.8767f, 0.67123f, 0.32877f, true };
                                                        return res; /* Class 0: 67.12%, Class 1: 32.88% (tau=0.31) */
                                                    }
                                                }
                                            }
                                        }
                                    } else {
                                        {
                                            DecisionTreeResult res = { 53.1915f, 46.8085f, 0.53191f, 0.46809f, true };
                                            return res; /* Class 0: 53.19%, Class 1: 46.81% (tau=0.31) */
                                        }
                                    }
                                } else {
                                    if (features[53] /* Feature_HR_Delta_60s_min */ <= -2.39189f) {
                                        {
                                            DecisionTreeResult res = { 93.0233f, 6.9767f, 0.93023f, 0.06977f, false };
                                            return res; /* Class 0: 93.02%, Class 1: 6.98% (tau=0.31) */
                                        }
                                    } else {
                                        if (features[16] /* Feature_MBP_Mean_60s_mean */ <= -0.46537f) {
                                            if (features[34] /* Feature_HR_Delta_60s_std */ <= 0.61164f) {
                                                {
                                                    DecisionTreeResult res = { 90.9091f, 9.0909f, 0.90909f, 0.09091f, false };
                                                    return res; /* Class 0: 90.91%, Class 1: 9.09% (tau=0.31) */
                                                }
                                            } else {
                                                if (features[66] /* Feature_Pulse_Pressure_max */ <= 0.66060f) {
                                                    {
                                                        DecisionTreeResult res = { 17.5439f, 82.4561f, 0.17544f, 0.82456f, true };
                                                        return res; /* Class 0: 17.54%, Class 1: 82.46% (tau=0.31) */
                                                    }
                                                } else {
                                                    {
                                                        DecisionTreeResult res = { 100.0000f, 0.0000f, 1.00000f, 0.00000f, false };
                                                        return res; /* Class 0: 100.00%, Class 1: 0.00% (tau=0.31) */
                                                    }
                                                }
                                            }
                                        } else {
                                            if (features[59] /* ART_DBP_max */ <= -0.60757f) {
                                                {
                                                    DecisionTreeResult res = { 16.6667f, 83.3333f, 0.16667f, 0.83333f, true };
                                                    return res; /* Class 0: 16.67%, Class 1: 83.33% (tau=0.31) */
                                                }
                                            } else {
                                                if (features[1] /* ART_SBP_mean */ <= 0.11971f) {
                                                    {
                                                        DecisionTreeResult res = { 93.5897f, 6.4103f, 0.93590f, 0.06410f, false };
                                                        return res; /* Class 0: 93.59%, Class 1: 6.41% (tau=0.31) */
                                                    }
                                                } else {
                                                    {
                                                        DecisionTreeResult res = { 41.9355f, 58.0645f, 0.41935f, 0.58065f, true };
                                                        return res; /* Class 0: 41.94%, Class 1: 58.06% (tau=0.31) */
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            } else {
                                if (features[52] /* Feature_HR_Std_60s_min */ <= 0.12560f) {
                                    {
                                        DecisionTreeResult res = { 74.1935f, 25.8065f, 0.74194f, 0.25806f, false };
                                        return res; /* Class 0: 74.19%, Class 1: 25.81% (tau=0.31) */
                                    }
                                } else {
                                    {
                                        DecisionTreeResult res = { 18.5185f, 81.4815f, 0.18519f, 0.81481f, true };
                                        return res; /* Class 0: 18.52%, Class 1: 81.48% (tau=0.31) */
                                    }
                                }
                            }
                        } else {
                            if (features[28] /* Feature_Pulse_Pressure_std */ <= -0.16470f) {
                                if (features[10] /* Feature_Shock_Index_mean */ <= 0.27207f) {
                                    {
                                        DecisionTreeResult res = { 0.0000f, 100.0000f, 0.00000f, 1.00000f, true };
                                        return res; /* Class 0: 0.00%, Class 1: 100.00% (tau=0.31) */
                                    }
                                } else {
                                    if (features[91] /* Feature_HR_Delta_60s_slope */ <= 2.00494f) {
                                        if (features[54] /* Feature_MBP_Mean_60s_min */ <= 0.69732f) {
                                            if (features[26] /* FIO2_std */ <= -0.38218f) {
                                                if (features[11] /* Feature_Modified_Shock_Index_mean */ <= 1.17274f) {
                                                    {
                                                        DecisionTreeResult res = { 98.0198f, 1.9802f, 0.98020f, 0.01980f, false };
                                                        return res; /* Class 0: 98.02%, Class 1: 1.98% (tau=0.31) */
                                                    }
                                                } else {
                                                    {
                                                        DecisionTreeResult res = { 40.0000f, 60.0000f, 0.40000f, 0.60000f, true };
                                                        return res; /* Class 0: 40.00%, Class 1: 60.00% (tau=0.31) */
                                                    }
                                                }
                                            } else {
                                                if (features[74] /* Feature_MBP_Std_60s_max */ <= -0.54423f) {
                                                    {
                                                        DecisionTreeResult res = { 89.2308f, 10.7692f, 0.89231f, 0.10769f, false };
                                                        return res; /* Class 0: 89.23%, Class 1: 10.77% (tau=0.31) */
                                                    }
                                                } else {
                                                    {
                                                        DecisionTreeResult res = { 67.0330f, 32.9670f, 0.67033f, 0.32967f, true };
                                                        return res; /* Class 0: 67.03%, Class 1: 32.97% (tau=0.31) */
                                                    }
                                                }
                                            }
                                        } else {
                                            {
                                                DecisionTreeResult res = { 35.7143f, 64.2857f, 0.35714f, 0.64286f, true };
                                                return res; /* Class 0: 35.71%, Class 1: 64.29% (tau=0.31) */
                                            }
                                        }
                                    } else {
                                        {
                                            DecisionTreeResult res = { 33.3333f, 66.6667f, 0.33333f, 0.66667f, true };
                                            return res; /* Class 0: 33.33%, Class 1: 66.67% (tau=0.31) */
                                        }
                                    }
                                }
                            } else {
                                if (features[7] /* FIO2_mean */ <= -0.14847f) {
                                    if (features[45] /* FIO2_min */ <= -0.61498f) {
                                        {
                                            DecisionTreeResult res = { 68.1818f, 31.8182f, 0.68182f, 0.31818f, true };
                                            return res; /* Class 0: 68.18%, Class 1: 31.82% (tau=0.31) */
                                        }
                                    } else {
                                        if (features[52] /* Feature_HR_Std_60s_min */ <= 0.58226f) {
                                            {
                                                DecisionTreeResult res = { 58.8235f, 41.1765f, 0.58824f, 0.41176f, true };
                                                return res; /* Class 0: 58.82%, Class 1: 41.18% (tau=0.31) */
                                            }
                                        } else {
                                            if (features[48] /* Feature_Shock_Index_min */ <= -0.25283f) {
                                                {
                                                    DecisionTreeResult res = { 100.0000f, 0.0000f, 1.00000f, 0.00000f, false };
                                                    return res; /* Class 0: 100.00%, Class 1: 0.00% (tau=0.31) */
                                                }
                                            } else {
                                                if (features[15] /* Feature_HR_Delta_60s_mean */ <= -0.11594f) {
                                                    {
                                                        DecisionTreeResult res = { 29.2683f, 70.7317f, 0.29268f, 0.70732f, true };
                                                        return res; /* Class 0: 29.27%, Class 1: 70.73% (tau=0.31) */
                                                    }
                                                } else {
                                                    {
                                                        DecisionTreeResult res = { 2.4390f, 97.5610f, 0.02439f, 0.97561f, true };
                                                        return res; /* Class 0: 2.44%, Class 1: 97.56% (tau=0.31) */
                                                    }
                                                }
                                            }
                                        }
                                    }
                                } else {
                                    if (features[32] /* Feature_HR_Mean_60s_std */ <= -0.14111f) {
                                        if (features[46] /* BT_min */ <= 0.46014f) {
                                            {
                                                DecisionTreeResult res = { 100.0000f, 0.0000f, 1.00000f, 0.00000f, false };
                                                return res; /* Class 0: 100.00%, Class 1: 0.00% (tau=0.31) */
                                            }
                                        } else {
                                            {
                                                DecisionTreeResult res = { 70.0000f, 30.0000f, 0.70000f, 0.30000f, false };
                                                return res; /* Class 0: 70.00%, Class 1: 30.00% (tau=0.31) */
                                            }
                                        }
                                    } else {
                                        if (features[46] /* BT_min */ <= 0.38716f) {
                                            {
                                                DecisionTreeResult res = { 91.6667f, 8.3333f, 0.91667f, 0.08333f, false };
                                                return res; /* Class 0: 91.67%, Class 1: 8.33% (tau=0.31) */
                                            }
                                        } else {
                                            if (features[89] /* Feature_HR_Mean_60s_slope */ <= -0.90101f) {
                                                {
                                                    DecisionTreeResult res = { 92.0000f, 8.0000f, 0.92000f, 0.08000f, false };
                                                    return res; /* Class 0: 92.00%, Class 1: 8.00% (tau=0.31) */
                                                }
                                            } else {
                                                if (features[38] /* HR_min */ <= 0.98717f) {
                                                    {
                                                        DecisionTreeResult res = { 90.0000f, 10.0000f, 0.90000f, 0.10000f, false };
                                                        return res; /* Class 0: 90.00%, Class 1: 10.00% (tau=0.31) */
                                                    }
                                                } else {
                                                    {
                                                        DecisionTreeResult res = { 16.0000f, 84.0000f, 0.16000f, 0.84000f, true };
                                                        return res; /* Class 0: 16.00%, Class 1: 84.00% (tau=0.31) */
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                } else {
                    if (features[70] /* Feature_HR_Mean_60s_max */ <= 1.54298f) {
                        if (features[39] /* ART_SBP_min */ <= 0.06297f) {
                            {
                                DecisionTreeResult res = { 100.0000f, 0.0000f, 1.00000f, 0.00000f, false };
                                return res; /* Class 0: 100.00%, Class 1: 0.00% (tau=0.31) */
                            }
                        } else {
                            {
                                DecisionTreeResult res = { 38.0952f, 61.9048f, 0.38095f, 0.61905f, true };
                                return res; /* Class 0: 38.10%, Class 1: 61.90% (tau=0.31) */
                            }
                        }
                    } else {
                        if (features[73] /* Feature_MBP_Mean_60s_max */ <= 0.58758f) {
                            if (features[11] /* Feature_Modified_Shock_Index_mean */ <= 1.60004f) {
                                if (features[25] /* ETCO2_std */ <= -0.20883f) {
                                    if (features[69] /* Feature_Rate_Pressure_Product_max */ <= 0.52010f) {
                                        {
                                            DecisionTreeResult res = { 71.4286f, 28.5714f, 0.71429f, 0.28571f, false };
                                            return res; /* Class 0: 71.43%, Class 1: 28.57% (tau=0.31) */
                                        }
                                    } else {
                                        if (features[31] /* Feature_Rate_Pressure_Product_std */ <= 0.11598f) {
                                            {
                                                DecisionTreeResult res = { 7.1429f, 92.8571f, 0.07143f, 0.92857f, true };
                                                return res; /* Class 0: 7.14%, Class 1: 92.86% (tau=0.31) */
                                            }
                                        } else {
                                            {
                                                DecisionTreeResult res = { 0.0000f, 100.0000f, 0.00000f, 1.00000f, true };
                                                return res; /* Class 0: 0.00%, Class 1: 100.00% (tau=0.31) */
                                            }
                                        }
                                    }
                                } else {
                                    if (features[85] /* Feature_Pulse_Pressure_slope */ <= -1.36330f) {
                                        {
                                            DecisionTreeResult res = { 66.6667f, 33.3333f, 0.66667f, 0.33333f, true };
                                            return res; /* Class 0: 66.67%, Class 1: 33.33% (tau=0.31) */
                                        }
                                    } else {
                                        if (features[52] /* Feature_HR_Std_60s_min */ <= 0.62304f) {
                                            if (features[91] /* Feature_HR_Delta_60s_slope */ <= -0.35088f) {
                                                {
                                                    DecisionTreeResult res = { 26.6667f, 73.3333f, 0.26667f, 0.73333f, true };
                                                    return res; /* Class 0: 26.67%, Class 1: 73.33% (tau=0.31) */
                                                }
                                            } else {
                                                {
                                                    DecisionTreeResult res = { 0.0000f, 100.0000f, 0.00000f, 1.00000f, true };
                                                    return res; /* Class 0: 0.00%, Class 1: 100.00% (tau=0.31) */
                                                }
                                            }
                                        } else {
                                            {
                                                DecisionTreeResult res = { 50.0000f, 50.0000f, 0.50000f, 0.50000f, true };
                                                return res; /* Class 0: 50.00%, Class 1: 50.00% (tau=0.31) */
                                            }
                                        }
                                    }
                                }
                            } else {
                                {
                                    DecisionTreeResult res = { 0.0000f, 100.0000f, 0.00000f, 1.00000f, true };
                                    return res; /* Class 0: 0.00%, Class 1: 100.00% (tau=0.31) */
                                }
                            }
                        } else {
                            if (features[63] /* ETCO2_max */ <= 0.56162f) {
                                if (features[4] /* PLETH_SPO2_mean */ <= 0.06824f) {
                                    {
                                        DecisionTreeResult res = { 15.0000f, 85.0000f, 0.15000f, 0.85000f, true };
                                        return res; /* Class 0: 15.00%, Class 1: 85.00% (tau=0.31) */
                                    }
                                } else {
                                    {
                                        DecisionTreeResult res = { 83.8710f, 16.1290f, 0.83871f, 0.16129f, false };
                                        return res; /* Class 0: 83.87%, Class 1: 16.13% (tau=0.31) */
                                    }
                                }
                            } else {
                                {
                                    DecisionTreeResult res = { 13.3333f, 86.6667f, 0.13333f, 0.86667f, true };
                                    return res; /* Class 0: 13.33%, Class 1: 86.67% (tau=0.31) */
                                }
                            }
                        }
                    }
                }
            }
        }
    } else {
        if (features[14] /* Feature_HR_Std_60s_mean */ <= 2.88427f) {
            if (features[0] /* HR_mean */ <= 1.25342f) {
                if (features[88] /* Feature_Rate_Pressure_Product_slope */ <= 2.47184f) {
                    if (features[57] /* HR_max */ <= 0.81196f) {
                        if (features[75] /* Feature_MBP_Delta_60s_max */ <= -0.22686f) {
                            if (features[68] /* Feature_Modified_Shock_Index_max */ <= 0.24458f) {
                                if (features[0] /* HR_mean */ <= 0.31086f) {
                                    if (features[54] /* Feature_MBP_Mean_60s_min */ <= -0.19644f) {
                                        if (features[84] /* BT_slope */ <= -5.05209f) {
                                            {
                                                DecisionTreeResult res = { 66.6667f, 33.3333f, 0.66667f, 0.33333f, true };
                                                return res; /* Class 0: 66.67%, Class 1: 33.33% (tau=0.31) */
                                            }
                                        } else {
                                            if (features[91] /* Feature_HR_Delta_60s_slope */ <= 1.12151f) {
                                                if (features[3] /* ART_MBP_mean */ <= -0.32066f) {
                                                    {
                                                        DecisionTreeResult res = { 95.8763f, 4.1237f, 0.95876f, 0.04124f, false };
                                                        return res; /* Class 0: 95.88%, Class 1: 4.12% (tau=0.31) */
                                                    }
                                                } else {
                                                    {
                                                        DecisionTreeResult res = { 99.0826f, 0.9174f, 0.99083f, 0.00917f, false };
                                                        return res; /* Class 0: 99.08%, Class 1: 0.92% (tau=0.31) */
                                                    }
                                                }
                                            } else {
                                                if (features[45] /* FIO2_min */ <= 1.83575f) {
                                                    {
                                                        DecisionTreeResult res = { 91.3793f, 8.6207f, 0.91379f, 0.08621f, false };
                                                        return res; /* Class 0: 91.38%, Class 1: 8.62% (tau=0.31) */
                                                    }
                                                } else {
                                                    {
                                                        DecisionTreeResult res = { 60.0000f, 40.0000f, 0.60000f, 0.40000f, true };
                                                        return res; /* Class 0: 60.00%, Class 1: 40.00% (tau=0.31) */
                                                    }
                                                }
                                            }
                                        }
                                    } else {
                                        if (features[64] /* FIO2_max */ <= 1.70353f) {
                                            if (features[51] /* Feature_HR_Mean_60s_min */ <= -3.20066f) {
                                                {
                                                    DecisionTreeResult res = { 46.6667f, 53.3333f, 0.46667f, 0.53333f, true };
                                                    return res; /* Class 0: 46.67%, Class 1: 53.33% (tau=0.31) */
                                                }
                                            } else {
                                                if (features[67] /* Feature_Shock_Index_max */ <= -0.29815f) {
                                                    {
                                                        DecisionTreeResult res = { 97.4233f, 2.5767f, 0.97423f, 0.02577f, false };
                                                        return res; /* Class 0: 97.42%, Class 1: 2.58% (tau=0.31) */
                                                    }
                                                } else {
                                                    {
                                                        DecisionTreeResult res = { 89.6245f, 10.3755f, 0.89625f, 0.10375f, false };
                                                        return res; /* Class 0: 89.62%, Class 1: 10.38% (tau=0.31) */
                                                    }
                                                }
                                            }
                                        } else {
                                            if (features[38] /* HR_min */ <= -1.52331f) {
                                                if (features[66] /* Feature_Pulse_Pressure_max */ <= -0.19192f) {
                                                    {
                                                        DecisionTreeResult res = { 95.2381f, 4.7619f, 0.95238f, 0.04762f, false };
                                                        return res; /* Class 0: 95.24%, Class 1: 4.76% (tau=0.31) */
                                                    }
                                                } else {
                                                    {
                                                        DecisionTreeResult res = { 64.9635f, 35.0365f, 0.64964f, 0.35036f, true };
                                                        return res; /* Class 0: 64.96%, Class 1: 35.04% (tau=0.31) */
                                                    }
                                                }
                                            } else {
                                                if (features[1] /* ART_SBP_mean */ <= -2.21406f) {
                                                    {
                                                        DecisionTreeResult res = { 28.5714f, 71.4286f, 0.28571f, 0.71429f, true };
                                                        return res; /* Class 0: 28.57%, Class 1: 71.43% (tau=0.31) */
                                                    }
                                                } else {
                                                    {
                                                        DecisionTreeResult res = { 88.6878f, 11.3122f, 0.88688f, 0.11312f, false };
                                                        return res; /* Class 0: 88.69%, Class 1: 11.31% (tau=0.31) */
                                                    }
                                                }
                                            }
                                        }
                                    }
                                } else {
                                    if (features[53] /* Feature_HR_Delta_60s_min */ <= 0.34554f) {
                                        if (features[25] /* ETCO2_std */ <= -0.55035f) {
                                            {
                                                DecisionTreeResult res = { 20.0000f, 80.0000f, 0.20000f, 0.80000f, true };
                                                return res; /* Class 0: 20.00%, Class 1: 80.00% (tau=0.31) */
                                            }
                                        } else {
                                            if (features[91] /* Feature_HR_Delta_60s_slope */ <= 2.83929f) {
                                                if (features[41] /* ART_MBP_min */ <= 1.40484f) {
                                                    {
                                                        DecisionTreeResult res = { 88.0174f, 11.9826f, 0.88017f, 0.11983f, false };
                                                        return res; /* Class 0: 88.02%, Class 1: 11.98% (tau=0.31) */
                                                    }
                                                } else {
                                                    {
                                                        DecisionTreeResult res = { 55.0000f, 45.0000f, 0.55000f, 0.45000f, true };
                                                        return res; /* Class 0: 55.00%, Class 1: 45.00% (tau=0.31) */
                                                    }
                                                }
                                            } else {
                                                {
                                                    DecisionTreeResult res = { 28.5714f, 71.4286f, 0.28571f, 0.71429f, true };
                                                    return res; /* Class 0: 28.57%, Class 1: 71.43% (tau=0.31) */
                                                }
                                            }
                                        }
                                    } else {
                                        if (features[83] /* FIO2_slope */ <= 0.09025f) {
                                            if (features[39] /* ART_SBP_min */ <= 0.74878f) {
                                                {
                                                    DecisionTreeResult res = { 79.5918f, 20.4082f, 0.79592f, 0.20408f, false };
                                                    return res; /* Class 0: 79.59%, Class 1: 20.41% (tau=0.31) */
                                                }
                                            } else {
                                                {
                                                    DecisionTreeResult res = { 100.0000f, 0.0000f, 1.00000f, 0.00000f, false };
                                                    return res; /* Class 0: 100.00%, Class 1: 0.00% (tau=0.31) */
                                                }
                                            }
                                        } else {
                                            if (features[24] /* RR_CO2_std */ <= -0.33957f) {
                                                {
                                                    DecisionTreeResult res = { 4.7619f, 95.2381f, 0.04762f, 0.95238f, true };
                                                    return res; /* Class 0: 4.76%, Class 1: 95.24% (tau=0.31) */
                                                }
                                            } else {
                                                {
                                                    DecisionTreeResult res = { 70.8333f, 29.1667f, 0.70833f, 0.29167f, false };
                                                    return res; /* Class 0: 70.83%, Class 1: 29.17% (tau=0.31) */
                                                }
                                            }
                                        }
                                    }
                                }
                            } else {
                                if (features[51] /* Feature_HR_Mean_60s_min */ <= -2.51875f) {
                                    {
                                        DecisionTreeResult res = { 30.4348f, 69.5652f, 0.30435f, 0.69565f, true };
                                        return res; /* Class 0: 30.43%, Class 1: 69.57% (tau=0.31) */
                                    }
                                } else {
                                    if (features[12] /* Feature_Rate_Pressure_Product_mean */ <= -1.22344f) {
                                        if (features[15] /* Feature_HR_Delta_60s_mean */ <= -3.30516f) {
                                            {
                                                DecisionTreeResult res = { 66.6667f, 33.3333f, 0.66667f, 0.33333f, true };
                                                return res; /* Class 0: 66.67%, Class 1: 33.33% (tau=0.31) */
                                            }
                                        } else {
                                            if (features[49] /* Feature_Modified_Shock_Index_min */ <= 9.43290f) {
                                                if (features[88] /* Feature_Rate_Pressure_Product_slope */ <= -0.40467f) {
                                                    {
                                                        DecisionTreeResult res = { 95.0000f, 5.0000f, 0.95000f, 0.05000f, false };
                                                        return res; /* Class 0: 95.00%, Class 1: 5.00% (tau=0.31) */
                                                    }
                                                } else {
                                                    {
                                                        DecisionTreeResult res = { 100.0000f, 0.0000f, 1.00000f, 0.00000f, false };
                                                        return res; /* Class 0: 100.00%, Class 1: 0.00% (tau=0.31) */
                                                    }
                                                }
                                            } else {
                                                {
                                                    DecisionTreeResult res = { 80.0000f, 20.0000f, 0.80000f, 0.20000f, false };
                                                    return res; /* Class 0: 80.00%, Class 1: 20.00% (tau=0.31) */
                                                }
                                            }
                                        }
                                    } else {
                                        if (features[7] /* FIO2_mean */ <= 1.41787f) {
                                            if (features[0] /* HR_mean */ <= 0.94179f) {
                                                if (features[87] /* Feature_Modified_Shock_Index_slope */ <= 1.03609f) {
                                                    {
                                                        DecisionTreeResult res = { 92.0962f, 7.9038f, 0.92096f, 0.07904f, false };
                                                        return res; /* Class 0: 92.10%, Class 1: 7.90% (tau=0.31) */
                                                    }
                                                } else {
                                                    {
                                                        DecisionTreeResult res = { 70.5263f, 29.4737f, 0.70526f, 0.29474f, false };
                                                        return res; /* Class 0: 70.53%, Class 1: 29.47% (tau=0.31) */
                                                    }
                                                }
                                            } else {
                                                {
                                                    DecisionTreeResult res = { 62.1622f, 37.8378f, 0.62162f, 0.37838f, true };
                                                    return res; /* Class 0: 62.16%, Class 1: 37.84% (tau=0.31) */
                                                }
                                            }
                                        } else {
                                            if (features[1] /* ART_SBP_mean */ <= 0.18170f) {
                                                if (features[52] /* Feature_HR_Std_60s_min */ <= 0.01446f) {
                                                    {
                                                        DecisionTreeResult res = { 38.6667f, 61.3333f, 0.38667f, 0.61333f, true };
                                                        return res; /* Class 0: 38.67%, Class 1: 61.33% (tau=0.31) */
                                                    }
                                                } else {
                                                    {
                                                        DecisionTreeResult res = { 79.3651f, 20.6349f, 0.79365f, 0.20635f, false };
                                                        return res; /* Class 0: 79.37%, Class 1: 20.63% (tau=0.31) */
                                                    }
                                                }
                                            } else {
                                                {
                                                    DecisionTreeResult res = { 93.8776f, 6.1224f, 0.93878f, 0.06122f, false };
                                                    return res; /* Class 0: 93.88%, Class 1: 6.12% (tau=0.31) */
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        } else {
                            if (features[45] /* FIO2_min */ <= 0.61038f) {
                                if (features[84] /* BT_slope */ <= 5.45615f) {
                                    if (features[59] /* ART_DBP_max */ <= -0.15066f) {
                                        if (features[67] /* Feature_Shock_Index_max */ <= 5.04016f) {
                                            if (features[3] /* ART_MBP_mean */ <= 0.66106f) {
                                                if (features[24] /* RR_CO2_std */ <= -0.48061f) {
                                                    {
                                                        DecisionTreeResult res = { 83.3333f, 16.6667f, 0.83333f, 0.16667f, false };
                                                        return res; /* Class 0: 83.33%, Class 1: 16.67% (tau=0.31) */
                                                    }
                                                } else {
                                                    {
                                                        DecisionTreeResult res = { 95.7286f, 4.2714f, 0.95729f, 0.04271f, false };
                                                        return res; /* Class 0: 95.73%, Class 1: 4.27% (tau=0.31) */
                                                    }
                                                }
                                            } else {
                                                {
                                                    DecisionTreeResult res = { 36.3636f, 63.6364f, 0.36364f, 0.63636f, true };
                                                    return res; /* Class 0: 36.36%, Class 1: 63.64% (tau=0.31) */
                                                }
                                            }
                                        } else {
                                            {
                                                DecisionTreeResult res = { 20.0000f, 80.0000f, 0.20000f, 0.80000f, true };
                                                return res; /* Class 0: 20.00%, Class 1: 80.00% (tau=0.31) */
                                            }
                                        }
                                    } else {
                                        if (features[87] /* Feature_Modified_Shock_Index_slope */ <= 2.02084f) {
                                            if (features[83] /* FIO2_slope */ <= 3.87495f) {
                                                if (features[19] /* HR_std */ <= 2.89288f) {
                                                    {
                                                        DecisionTreeResult res = { 97.6017f, 2.3983f, 0.97602f, 0.02398f, false };
                                                        return res; /* Class 0: 97.60%, Class 1: 2.40% (tau=0.31) */
                                                    }
                                                } else {
                                                    {
                                                        DecisionTreeResult res = { 88.5496f, 11.4504f, 0.88550f, 0.11450f, false };
                                                        return res; /* Class 0: 88.55%, Class 1: 11.45% (tau=0.31) */
                                                    }
                                                }
                                            } else {
                                                if (features[46] /* BT_min */ <= -0.95075f) {
                                                    {
                                                        DecisionTreeResult res = { 51.7241f, 48.2759f, 0.51724f, 0.48276f, true };
                                                        return res; /* Class 0: 51.72%, Class 1: 48.28% (tau=0.31) */
                                                    }
                                                } else {
                                                    {
                                                        DecisionTreeResult res = { 89.3617f, 10.6383f, 0.89362f, 0.10638f, false };
                                                        return res; /* Class 0: 89.36%, Class 1: 10.64% (tau=0.31) */
                                                    }
                                                }
                                            }
                                        } else {
                                            {
                                                DecisionTreeResult res = { 62.5000f, 37.5000f, 0.62500f, 0.37500f, true };
                                                return res; /* Class 0: 62.50%, Class 1: 37.50% (tau=0.31) */
                                            }
                                        }
                                    }
                                } else {
                                    {
                                        DecisionTreeResult res = { 50.0000f, 50.0000f, 0.50000f, 0.50000f, true };
                                        return res; /* Class 0: 50.00%, Class 1: 50.00% (tau=0.31) */
                                    }
                                }
                            } else {
                                if (features[34] /* Feature_HR_Delta_60s_std */ <= 4.19315f) {
                                    if (features[63] /* ETCO2_max */ <= 5.50535f) {
                                        if (features[66] /* Feature_Pulse_Pressure_max */ <= 0.79064f) {
                                            if (features[13] /* Feature_HR_Mean_60s_mean */ <= 0.39275f) {
                                                if (features[14] /* Feature_HR_Std_60s_mean */ <= 1.68337f) {
                                                    {
                                                        DecisionTreeResult res = { 91.5352f, 8.4648f, 0.91535f, 0.08465f, false };
                                                        return res; /* Class 0: 91.54%, Class 1: 8.46% (tau=0.31) */
                                                    }
                                                } else {
                                                    {
                                                        DecisionTreeResult res = { 77.6536f, 22.3464f, 0.77654f, 0.22346f, false };
                                                        return res; /* Class 0: 77.65%, Class 1: 22.35% (tau=0.31) */
                                                    }
                                                }
                                            } else {
                                                if (features[71] /* Feature_HR_Std_60s_max */ <= 0.81981f) {
                                                    {
                                                        DecisionTreeResult res = { 94.8718f, 5.1282f, 0.94872f, 0.05128f, false };
                                                        return res; /* Class 0: 94.87%, Class 1: 5.13% (tau=0.31) */
                                                    }
                                                } else {
                                                    {
                                                        DecisionTreeResult res = { 60.2941f, 39.7059f, 0.60294f, 0.39706f, true };
                                                        return res; /* Class 0: 60.29%, Class 1: 39.71% (tau=0.31) */
                                                    }
                                                }
                                            }
                                        } else {
                                            if (features[50] /* Feature_Rate_Pressure_Product_min */ <= -2.12146f) {
                                                {
                                                    DecisionTreeResult res = { 37.5000f, 62.5000f, 0.37500f, 0.62500f, true };
                                                    return res; /* Class 0: 37.50%, Class 1: 62.50% (tau=0.31) */
                                                }
                                            } else {
                                                if (features[21] /* ART_DBP_std */ <= 1.94468f) {
                                                    {
                                                        DecisionTreeResult res = { 93.4783f, 6.5217f, 0.93478f, 0.06522f, false };
                                                        return res; /* Class 0: 93.48%, Class 1: 6.52% (tau=0.31) */
                                                    }
                                                } else {
                                                    {
                                                        DecisionTreeResult res = { 99.0826f, 0.9174f, 0.99083f, 0.00917f, false };
                                                        return res; /* Class 0: 99.08%, Class 1: 0.92% (tau=0.31) */
                                                    }
                                                }
                                            }
                                        }
                                    } else {
                                        {
                                            DecisionTreeResult res = { 0.0000f, 100.0000f, 0.00000f, 1.00000f, true };
                                            return res; /* Class 0: 0.00%, Class 1: 100.00% (tau=0.31) */
                                        }
                                    }
                                } else {
                                    {
                                        DecisionTreeResult res = { 11.1111f, 88.8889f, 0.11111f, 0.88889f, true };
                                        return res; /* Class 0: 11.11%, Class 1: 88.89% (tau=0.31) */
                                    }
                                }
                            }
                        }
                    } else {
                        if (features[0] /* HR_mean */ <= 0.49879f) {
                            if (features[76] /* HR_slope */ <= 2.89733f) {
                                if (features[7] /* FIO2_mean */ <= 0.86219f) {
                                    if (features[52] /* Feature_HR_Std_60s_min */ <= -0.48680f) {
                                        if (features[66] /* Feature_Pulse_Pressure_max */ <= 1.19523f) {
                                            if (features[46] /* BT_min */ <= 0.39527f) {
                                                if (features[23] /* PLETH_SPO2_std */ <= 1.33156f) {
                                                    {
                                                        DecisionTreeResult res = { 86.2201f, 13.7799f, 0.86220f, 0.13780f, false };
                                                        return res; /* Class 0: 86.22%, Class 1: 13.78% (tau=0.31) */
                                                    }
                                                } else {
                                                    {
                                                        DecisionTreeResult res = { 56.5217f, 43.4783f, 0.56522f, 0.43478f, true };
                                                        return res; /* Class 0: 56.52%, Class 1: 43.48% (tau=0.31) */
                                                    }
                                                }
                                            } else {
                                                if (features[4] /* PLETH_SPO2_mean */ <= 0.35536f) {
                                                    {
                                                        DecisionTreeResult res = { 89.7436f, 10.2564f, 0.89744f, 0.10256f, false };
                                                        return res; /* Class 0: 89.74%, Class 1: 10.26% (tau=0.31) */
                                                    }
                                                } else {
                                                    {
                                                        DecisionTreeResult res = { 41.0959f, 58.9041f, 0.41096f, 0.58904f, true };
                                                        return res; /* Class 0: 41.10%, Class 1: 58.90% (tau=0.31) */
                                                    }
                                                }
                                            }
                                        } else {
                                            if (features[30] /* Feature_Modified_Shock_Index_std */ <= 0.94924f) {
                                                if (features[77] /* ART_SBP_slope */ <= 1.49161f) {
                                                    {
                                                        DecisionTreeResult res = { 42.7184f, 57.2816f, 0.42718f, 0.57282f, true };
                                                        return res; /* Class 0: 42.72%, Class 1: 57.28% (tau=0.31) */
                                                    }
                                                } else {
                                                    {
                                                        DecisionTreeResult res = { 88.2353f, 11.7647f, 0.88235f, 0.11765f, false };
                                                        return res; /* Class 0: 88.24%, Class 1: 11.76% (tau=0.31) */
                                                    }
                                                }
                                            } else {
                                                {
                                                    DecisionTreeResult res = { 95.6522f, 4.3478f, 0.95652f, 0.04348f, false };
                                                    return res; /* Class 0: 95.65%, Class 1: 4.35% (tau=0.31) */
                                                }
                                            }
                                        }
                                    } else {
                                        if (features[15] /* Feature_HR_Delta_60s_mean */ <= 1.73164f) {
                                            if (features[46] /* BT_min */ <= 0.36284f) {
                                                if (features[29] /* Feature_Shock_Index_std */ <= 0.25369f) {
                                                    {
                                                        DecisionTreeResult res = { 93.7785f, 6.2215f, 0.93778f, 0.06222f, false };
                                                        return res; /* Class 0: 93.78%, Class 1: 6.22% (tau=0.31) */
                                                    }
                                                } else {
                                                    {
                                                        DecisionTreeResult res = { 88.1258f, 11.8742f, 0.88126f, 0.11874f, false };
                                                        return res; /* Class 0: 88.13%, Class 1: 11.87% (tau=0.31) */
                                                    }
                                                }
                                            } else {
                                                if (features[17] /* Feature_MBP_Std_60s_mean */ <= -0.44737f) {
                                                    {
                                                        DecisionTreeResult res = { 66.8790f, 33.1210f, 0.66879f, 0.33121f, true };
                                                        return res; /* Class 0: 66.88%, Class 1: 33.12% (tau=0.31) */
                                                    }
                                                } else {
                                                    {
                                                        DecisionTreeResult res = { 87.1148f, 12.8852f, 0.87115f, 0.12885f, false };
                                                        return res; /* Class 0: 87.11%, Class 1: 12.89% (tau=0.31) */
                                                    }
                                                }
                                            }
                                        } else {
                                            if (features[68] /* Feature_Modified_Shock_Index_max */ <= -0.06529f) {
                                                if (features[85] /* Feature_Pulse_Pressure_slope */ <= 0.11299f) {
                                                    {
                                                        DecisionTreeResult res = { 81.8182f, 18.1818f, 0.81818f, 0.18182f, false };
                                                        return res; /* Class 0: 81.82%, Class 1: 18.18% (tau=0.31) */
                                                    }
                                                } else {
                                                    {
                                                        DecisionTreeResult res = { 97.5000f, 2.5000f, 0.97500f, 0.02500f, false };
                                                        return res; /* Class 0: 97.50%, Class 1: 2.50% (tau=0.31) */
                                                    }
                                                }
                                            } else {
                                                if (features[25] /* ETCO2_std */ <= -0.46051f) {
                                                    {
                                                        DecisionTreeResult res = { 46.3415f, 53.6585f, 0.46341f, 0.53659f, true };
                                                        return res; /* Class 0: 46.34%, Class 1: 53.66% (tau=0.31) */
                                                    }
                                                } else {
                                                    {
                                                        DecisionTreeResult res = { 74.8954f, 25.1046f, 0.74895f, 0.25105f, false };
                                                        return res; /* Class 0: 74.90%, Class 1: 25.10% (tau=0.31) */
                                                    }
                                                }
                                            }
                                        }
                                    }
                                } else {
                                    if (features[75] /* Feature_MBP_Delta_60s_max */ <= 3.26625f) {
                                        if (features[59] /* ART_DBP_max */ <= 0.30625f) {
                                            if (features[66] /* Feature_Pulse_Pressure_max */ <= 0.12597f) {
                                                if (features[55] /* Feature_MBP_Std_60s_min */ <= -0.08545f) {
                                                    {
                                                        DecisionTreeResult res = { 82.4026f, 17.5974f, 0.82403f, 0.17597f, false };
                                                        return res; /* Class 0: 82.40%, Class 1: 17.60% (tau=0.31) */
                                                    }
                                                } else {
                                                    {
                                                        DecisionTreeResult res = { 71.3725f, 28.6275f, 0.71373f, 0.28627f, false };
                                                        return res; /* Class 0: 71.37%, Class 1: 28.63% (tau=0.31) */
                                                    }
                                                }
                                            } else {
                                                if (features[71] /* Feature_HR_Std_60s_max */ <= 3.09556f) {
                                                    {
                                                        DecisionTreeResult res = { 74.5856f, 25.4144f, 0.74586f, 0.25414f, false };
                                                        return res; /* Class 0: 74.59%, Class 1: 25.41% (tau=0.31) */
                                                    }
                                                } else {
                                                    {
                                                        DecisionTreeResult res = { 56.0976f, 43.9024f, 0.56098f, 0.43902f, true };
                                                        return res; /* Class 0: 56.10%, Class 1: 43.90% (tau=0.31) */
                                                    }
                                                }
                                            }
                                        } else {
                                            if (features[70] /* Feature_HR_Mean_60s_max */ <= 0.11728f) {
                                                if (features[46] /* BT_min */ <= 0.44392f) {
                                                    {
                                                        DecisionTreeResult res = { 95.0000f, 5.0000f, 0.95000f, 0.05000f, false };
                                                        return res; /* Class 0: 95.00%, Class 1: 5.00% (tau=0.31) */
                                                    }
                                                } else {
                                                    {
                                                        DecisionTreeResult res = { 33.3333f, 66.6667f, 0.33333f, 0.66667f, true };
                                                        return res; /* Class 0: 33.33%, Class 1: 66.67% (tau=0.31) */
                                                    }
                                                }
                                            } else {
                                                if (features[90] /* Feature_HR_Std_60s_slope */ <= 1.23592f) {
                                                    {
                                                        DecisionTreeResult res = { 85.6198f, 14.3802f, 0.85620f, 0.14380f, false };
                                                        return res; /* Class 0: 85.62%, Class 1: 14.38% (tau=0.31) */
                                                    }
                                                } else {
                                                    {
                                                        DecisionTreeResult res = { 66.9468f, 33.0532f, 0.66947f, 0.33053f, true };
                                                        return res; /* Class 0: 66.95%, Class 1: 33.05% (tau=0.31) */
                                                    }
                                                }
                                            }
                                        }
                                    } else {
                                        {
                                            DecisionTreeResult res = { 5.5556f, 94.4444f, 0.05556f, 0.94444f, true };
                                            return res; /* Class 0: 5.56%, Class 1: 94.44% (tau=0.31) */
                                        }
                                    }
                                }
                            } else {
                                if (features[38] /* HR_min */ <= -1.04836f) {
                                    if (features[51] /* Feature_HR_Mean_60s_min */ <= -1.96961f) {
                                        {
                                            DecisionTreeResult res = { 91.6667f, 8.3333f, 0.91667f, 0.08333f, false };
                                            return res; /* Class 0: 91.67%, Class 1: 8.33% (tau=0.31) */
                                        }
                                    } else {
                                        if (features[10] /* Feature_Shock_Index_mean */ <= 0.50829f) {
                                            if (features[50] /* Feature_Rate_Pressure_Product_min */ <= -0.58439f) {
                                                if (features[68] /* Feature_Modified_Shock_Index_max */ <= -0.09583f) {
                                                    {
                                                        DecisionTreeResult res = { 100.0000f, 0.0000f, 1.00000f, 0.00000f, false };
                                                        return res; /* Class 0: 100.00%, Class 1: 0.00% (tau=0.31) */
                                                    }
                                                } else {
                                                    {
                                                        DecisionTreeResult res = { 35.2941f, 64.7059f, 0.35294f, 0.64706f, true };
                                                        return res; /* Class 0: 35.29%, Class 1: 64.71% (tau=0.31) */
                                                    }
                                                }
                                            } else {
                                                {
                                                    DecisionTreeResult res = { 77.7778f, 22.2222f, 0.77778f, 0.22222f, false };
                                                    return res; /* Class 0: 77.78%, Class 1: 22.22% (tau=0.31) */
                                                }
                                            }
                                        } else {
                                            {
                                                DecisionTreeResult res = { 0.0000f, 100.0000f, 0.00000f, 1.00000f, true };
                                                return res; /* Class 0: 0.00%, Class 1: 100.00% (tau=0.31) */
                                            }
                                        }
                                    }
                                } else {
                                    if (features[88] /* Feature_Rate_Pressure_Product_slope */ <= 1.16491f) {
                                        if (features[23] /* PLETH_SPO2_std */ <= 0.10542f) {
                                            if (features[87] /* Feature_Modified_Shock_Index_slope */ <= 2.02637f) {
                                                if (features[2] /* ART_DBP_mean */ <= 0.05280f) {
                                                    {
                                                        DecisionTreeResult res = { 52.9412f, 47.0588f, 0.52941f, 0.47059f, true };
                                                        return res; /* Class 0: 52.94%, Class 1: 47.06% (tau=0.31) */
                                                    }
                                                } else {
                                                    {
                                                        DecisionTreeResult res = { 94.4444f, 5.5556f, 0.94444f, 0.05556f, false };
                                                        return res; /* Class 0: 94.44%, Class 1: 5.56% (tau=0.31) */
                                                    }
                                                }
                                            } else {
                                                {
                                                    DecisionTreeResult res = { 12.5000f, 87.5000f, 0.12500f, 0.87500f, true };
                                                    return res; /* Class 0: 12.50%, Class 1: 87.50% (tau=0.31) */
                                                }
                                            }
                                        } else {
                                            if (features[76] /* HR_slope */ <= 4.09855f) {
                                                {
                                                    DecisionTreeResult res = { 51.5152f, 48.4848f, 0.51515f, 0.48485f, true };
                                                    return res; /* Class 0: 51.52%, Class 1: 48.48% (tau=0.31) */
                                                }
                                            } else {
                                                {
                                                    DecisionTreeResult res = { 3.8462f, 96.1538f, 0.03846f, 0.96154f, true };
                                                    return res; /* Class 0: 3.85%, Class 1: 96.15% (tau=0.31) */
                                                }
                                            }
                                        }
                                    } else {
                                        if (features[70] /* Feature_HR_Mean_60s_max */ <= 1.29894f) {
                                            if (features[36] /* Feature_MBP_Std_60s_std */ <= -0.44748f) {
                                                if (features[45] /* FIO2_min */ <= 1.95245f) {
                                                    {
                                                        DecisionTreeResult res = { 15.6250f, 84.3750f, 0.15625f, 0.84375f, true };
                                                        return res; /* Class 0: 15.62%, Class 1: 84.38% (tau=0.31) */
                                                    }
                                                } else {
                                                    {
                                                        DecisionTreeResult res = { 71.4286f, 28.5714f, 0.71429f, 0.28571f, false };
                                                        return res; /* Class 0: 71.43%, Class 1: 28.57% (tau=0.31) */
                                                    }
                                                }
                                            } else {
                                                if (features[94] /* Feature_MBP_Delta_60s_slope */ <= 0.42405f) {
                                                    {
                                                        DecisionTreeResult res = { 48.3871f, 51.6129f, 0.48387f, 0.51613f, true };
                                                        return res; /* Class 0: 48.39%, Class 1: 51.61% (tau=0.31) */
                                                    }
                                                } else {
                                                    {
                                                        DecisionTreeResult res = { 0.0000f, 100.0000f, 0.00000f, 1.00000f, true };
                                                        return res; /* Class 0: 0.00%, Class 1: 100.00% (tau=0.31) */
                                                    }
                                                }
                                            }
                                        } else {
                                            if (features[3] /* ART_MBP_mean */ <= 0.71216f) {
                                                if (features[13] /* Feature_HR_Mean_60s_mean */ <= 0.32224f) {
                                                    {
                                                        DecisionTreeResult res = { 4.9180f, 95.0820f, 0.04918f, 0.95082f, true };
                                                        return res; /* Class 0: 4.92%, Class 1: 95.08% (tau=0.31) */
                                                    }
                                                } else {
                                                    {
                                                        DecisionTreeResult res = { 40.0000f, 60.0000f, 0.40000f, 0.60000f, true };
                                                        return res; /* Class 0: 40.00%, Class 1: 60.00% (tau=0.31) */
                                                    }
                                                }
                                            } else {
                                                {
                                                    DecisionTreeResult res = { 31.2500f, 68.7500f, 0.31250f, 0.68750f, true };
                                                    return res; /* Class 0: 31.25%, Class 1: 68.75% (tau=0.31) */
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        } else {
                            if (features[76] /* HR_slope */ <= 2.62013f) {
                                if (features[51] /* Feature_HR_Mean_60s_min */ <= 0.52906f) {
                                    if (features[67] /* Feature_Shock_Index_max */ <= -0.19841f) {
                                        if (features[19] /* HR_std */ <= 1.51959f) {
                                            if (features[15] /* Feature_HR_Delta_60s_mean */ <= 0.95247f) {
                                                if (features[63] /* ETCO2_max */ <= -0.42712f) {
                                                    {
                                                        DecisionTreeResult res = { 62.5000f, 37.5000f, 0.62500f, 0.37500f, true };
                                                        return res; /* Class 0: 62.50%, Class 1: 37.50% (tau=0.31) */
                                                    }
                                                } else {
                                                    {
                                                        DecisionTreeResult res = { 95.4545f, 4.5455f, 0.95455f, 0.04545f, false };
                                                        return res; /* Class 0: 95.45%, Class 1: 4.55% (tau=0.31) */
                                                    }
                                                }
                                            } else {
                                                {
                                                    DecisionTreeResult res = { 61.1111f, 38.8889f, 0.61111f, 0.38889f, true };
                                                    return res; /* Class 0: 61.11%, Class 1: 38.89% (tau=0.31) */
                                                }
                                            }
                                        } else {
                                            if (features[4] /* PLETH_SPO2_mean */ <= 0.37791f) {
                                                if (features[70] /* Feature_HR_Mean_60s_max */ <= 1.27684f) {
                                                    {
                                                        DecisionTreeResult res = { 33.3333f, 66.6667f, 0.33333f, 0.66667f, true };
                                                        return res; /* Class 0: 33.33%, Class 1: 66.67% (tau=0.31) */
                                                    }
                                                } else {
                                                    {
                                                        DecisionTreeResult res = { 93.5484f, 6.4516f, 0.93548f, 0.06452f, false };
                                                        return res; /* Class 0: 93.55%, Class 1: 6.45% (tau=0.31) */
                                                    }
                                                }
                                            } else {
                                                {
                                                    DecisionTreeResult res = { 100.0000f, 0.0000f, 1.00000f, 0.00000f, false };
                                                    return res; /* Class 0: 100.00%, Class 1: 0.00% (tau=0.31) */
                                                }
                                            }
                                        }
                                    } else {
                                        if (features[74] /* Feature_MBP_Std_60s_max */ <= -0.27692f) {
                                            if (features[71] /* Feature_HR_Std_60s_max */ <= 1.21149f) {
                                                if (features[42] /* PLETH_SPO2_min */ <= -2.00207f) {
                                                    {
                                                        DecisionTreeResult res = { 9.0909f, 90.9091f, 0.09091f, 0.90909f, true };
                                                        return res; /* Class 0: 9.09%, Class 1: 90.91% (tau=0.31) */
                                                    }
                                                } else {
                                                    {
                                                        DecisionTreeResult res = { 81.0277f, 18.9723f, 0.81028f, 0.18972f, false };
                                                        return res; /* Class 0: 81.03%, Class 1: 18.97% (tau=0.31) */
                                                    }
                                                }
                                            } else {
                                                if (features[90] /* Feature_HR_Std_60s_slope */ <= 1.06043f) {
                                                    {
                                                        DecisionTreeResult res = { 68.0120f, 31.9880f, 0.68012f, 0.31988f, true };
                                                        return res; /* Class 0: 68.01%, Class 1: 31.99% (tau=0.31) */
                                                    }
                                                } else {
                                                    {
                                                        DecisionTreeResult res = { 44.2804f, 55.7196f, 0.44280f, 0.55720f, true };
                                                        return res; /* Class 0: 44.28%, Class 1: 55.72% (tau=0.31) */
                                                    }
                                                }
                                            }
                                        } else {
                                            if (features[71] /* Feature_HR_Std_60s_max */ <= 1.32057f) {
                                                if (features[28] /* Feature_Pulse_Pressure_std */ <= 1.85828f) {
                                                    {
                                                        DecisionTreeResult res = { 91.1638f, 8.8362f, 0.91164f, 0.08836f, false };
                                                        return res; /* Class 0: 91.16%, Class 1: 8.84% (tau=0.31) */
                                                    }
                                                } else {
                                                    {
                                                        DecisionTreeResult res = { 77.0115f, 22.9885f, 0.77011f, 0.22989f, false };
                                                        return res; /* Class 0: 77.01%, Class 1: 22.99% (tau=0.31) */
                                                    }
                                                }
                                            } else {
                                                if (features[28] /* Feature_Pulse_Pressure_std */ <= 2.07521f) {
                                                    {
                                                        DecisionTreeResult res = { 72.9508f, 27.0492f, 0.72951f, 0.27049f, false };
                                                        return res; /* Class 0: 72.95%, Class 1: 27.05% (tau=0.31) */
                                                    }
                                                } else {
                                                    {
                                                        DecisionTreeResult res = { 87.4372f, 12.5628f, 0.87437f, 0.12563f, false };
                                                        return res; /* Class 0: 87.44%, Class 1: 12.56% (tau=0.31) */
                                                    }
                                                }
                                            }
                                        }
                                    }
                                } else {
                                    if (features[57] /* HR_max */ <= 1.41416f) {
                                        if (features[28] /* Feature_Pulse_Pressure_std */ <= -0.53934f) {
                                            if (features[34] /* Feature_HR_Delta_60s_std */ <= 0.62677f) {
                                                {
                                                    DecisionTreeResult res = { 68.4211f, 31.5789f, 0.68421f, 0.31579f, true };
                                                    return res; /* Class 0: 68.42%, Class 1: 31.58% (tau=0.31) */
                                                }
                                            } else {
                                                if (features[80] /* PLETH_SPO2_slope */ <= -0.28680f) {
                                                    {
                                                        DecisionTreeResult res = { 85.7143f, 14.2857f, 0.85714f, 0.14286f, false };
                                                        return res; /* Class 0: 85.71%, Class 1: 14.29% (tau=0.31) */
                                                    }
                                                } else {
                                                    {
                                                        DecisionTreeResult res = { 98.4127f, 1.5873f, 0.98413f, 0.01587f, false };
                                                        return res; /* Class 0: 98.41%, Class 1: 1.59% (tau=0.31) */
                                                    }
                                                }
                                            }
                                        } else {
                                            if (features[46] /* BT_min */ <= 0.49257f) {
                                                if (features[76] /* HR_slope */ <= 0.58730f) {
                                                    {
                                                        DecisionTreeResult res = { 84.2105f, 15.7895f, 0.84211f, 0.15789f, false };
                                                        return res; /* Class 0: 84.21%, Class 1: 15.79% (tau=0.31) */
                                                    }
                                                } else {
                                                    {
                                                        DecisionTreeResult res = { 50.0000f, 50.0000f, 0.50000f, 0.50000f, true };
                                                        return res; /* Class 0: 50.00%, Class 1: 50.00% (tau=0.31) */
                                                    }
                                                }
                                            } else {
                                                {
                                                    DecisionTreeResult res = { 0.0000f, 100.0000f, 0.00000f, 1.00000f, true };
                                                    return res; /* Class 0: 0.00%, Class 1: 100.00% (tau=0.31) */
                                                }
                                            }
                                        }
                                    } else {
                                        if (features[31] /* Feature_Rate_Pressure_Product_std */ <= 0.32387f) {
                                            if (features[15] /* Feature_HR_Delta_60s_mean */ <= 0.50722f) {
                                                if (features[42] /* PLETH_SPO2_min */ <= -0.44235f) {
                                                    {
                                                        DecisionTreeResult res = { 32.0000f, 68.0000f, 0.32000f, 0.68000f, true };
                                                        return res; /* Class 0: 32.00%, Class 1: 68.00% (tau=0.31) */
                                                    }
                                                } else {
                                                    {
                                                        DecisionTreeResult res = { 67.4419f, 32.5581f, 0.67442f, 0.32558f, true };
                                                        return res; /* Class 0: 67.44%, Class 1: 32.56% (tau=0.31) */
                                                    }
                                                }
                                            } else {
                                                if (features[54] /* Feature_MBP_Mean_60s_min */ <= -0.22928f) {
                                                    {
                                                        DecisionTreeResult res = { 47.0588f, 52.9412f, 0.47059f, 0.52941f, true };
                                                        return res; /* Class 0: 47.06%, Class 1: 52.94% (tau=0.31) */
                                                    }
                                                } else {
                                                    {
                                                        DecisionTreeResult res = { 21.0526f, 78.9474f, 0.21053f, 0.78947f, true };
                                                        return res; /* Class 0: 21.05%, Class 1: 78.95% (tau=0.31) */
                                                    }
                                                }
                                            }
                                        } else {
                                            if (features[15] /* Feature_HR_Delta_60s_mean */ <= 0.23569f) {
                                                if (features[6] /* ETCO2_mean */ <= -0.04617f) {
                                                    {
                                                        DecisionTreeResult res = { 57.4163f, 42.5837f, 0.57416f, 0.42584f, true };
                                                        return res; /* Class 0: 57.42%, Class 1: 42.58% (tau=0.31) */
                                                    }
                                                } else {
                                                    {
                                                        DecisionTreeResult res = { 80.6548f, 19.3452f, 0.80655f, 0.19345f, false };
                                                        return res; /* Class 0: 80.65%, Class 1: 19.35% (tau=0.31) */
                                                    }
                                                }
                                            } else {
                                                if (features[88] /* Feature_Rate_Pressure_Product_slope */ <= 0.63394f) {
                                                    {
                                                        DecisionTreeResult res = { 58.6387f, 41.3613f, 0.58639f, 0.41361f, true };
                                                        return res; /* Class 0: 58.64%, Class 1: 41.36% (tau=0.31) */
                                                    }
                                                } else {
                                                    {
                                                        DecisionTreeResult res = { 36.5385f, 63.4615f, 0.36538f, 0.63462f, true };
                                                        return res; /* Class 0: 36.54%, Class 1: 63.46% (tau=0.31) */
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            } else {
                                if (features[48] /* Feature_Shock_Index_min */ <= 0.63396f) {
                                    if (features[57] /* HR_max */ <= 0.93240f) {
                                        {
                                            DecisionTreeResult res = { 48.9362f, 51.0638f, 0.48936f, 0.51064f, true };
                                            return res; /* Class 0: 48.94%, Class 1: 51.06% (tau=0.31) */
                                        }
                                    } else {
                                        if (features[60] /* ART_MBP_max */ <= 0.88490f) {
                                            if (features[25] /* ETCO2_std */ <= 4.66705f) {
                                                if (features[41] /* ART_MBP_min */ <= 0.79760f) {
                                                    {
                                                        DecisionTreeResult res = { 16.8367f, 83.1633f, 0.16837f, 0.83163f, true };
                                                        return res; /* Class 0: 16.84%, Class 1: 83.16% (tau=0.31) */
                                                    }
                                                } else {
                                                    {
                                                        DecisionTreeResult res = { 32.4324f, 67.5676f, 0.32432f, 0.67568f, true };
                                                        return res; /* Class 0: 32.43%, Class 1: 67.57% (tau=0.31) */
                                                    }
                                                }
                                            } else {
                                                {
                                                    DecisionTreeResult res = { 54.5455f, 45.4545f, 0.54545f, 0.45455f, true };
                                                    return res; /* Class 0: 54.55%, Class 1: 45.45% (tau=0.31) */
                                                }
                                            }
                                        } else {
                                            if (features[39] /* ART_SBP_min */ <= 0.66306f) {
                                                {
                                                    DecisionTreeResult res = { 32.6087f, 67.3913f, 0.32609f, 0.67391f, true };
                                                    return res; /* Class 0: 32.61%, Class 1: 67.39% (tau=0.31) */
                                                }
                                            } else {
                                                {
                                                    DecisionTreeResult res = { 100.0000f, 0.0000f, 1.00000f, 0.00000f, false };
                                                    return res; /* Class 0: 100.00%, Class 1: 0.00% (tau=0.31) */
                                                }
                                            }
                                        }
                                    }
                                } else {
                                    if (features[32] /* Feature_HR_Mean_60s_std */ <= 2.43731f) {
                                        {
                                            DecisionTreeResult res = { 0.0000f, 100.0000f, 0.00000f, 1.00000f, true };
                                            return res; /* Class 0: 0.00%, Class 1: 100.00% (tau=0.31) */
                                        }
                                    } else {
                                        {
                                            DecisionTreeResult res = { 21.6216f, 78.3784f, 0.21622f, 0.78378f, true };
                                            return res; /* Class 0: 21.62%, Class 1: 78.38% (tau=0.31) */
                                        }
                                    }
                                }
                            }
                        }
                    }
                } else {
                    if (features[90] /* Feature_HR_Std_60s_slope */ <= 3.43872f) {
                        if (features[57] /* HR_max */ <= 0.85211f) {
                            if (features[22] /* ART_MBP_std */ <= 0.48202f) {
                                if (features[39] /* ART_SBP_min */ <= 1.60605f) {
                                    if (features[57] /* HR_max */ <= 0.69152f) {
                                        if (features[91] /* Feature_HR_Delta_60s_slope */ <= 1.31783f) {
                                            if (features[93] /* Feature_MBP_Std_60s_slope */ <= -0.00464f) {
                                                if (features[88] /* Feature_Rate_Pressure_Product_slope */ <= 2.69274f) {
                                                    {
                                                        DecisionTreeResult res = { 50.0000f, 50.0000f, 0.50000f, 0.50000f, true };
                                                        return res; /* Class 0: 50.00%, Class 1: 50.00% (tau=0.31) */
                                                    }
                                                } else {
                                                    {
                                                        DecisionTreeResult res = { 89.2857f, 10.7143f, 0.89286f, 0.10714f, false };
                                                        return res; /* Class 0: 89.29%, Class 1: 10.71% (tau=0.31) */
                                                    }
                                                }
                                            } else {
                                                if (features[38] /* HR_min */ <= -0.50555f) {
                                                    {
                                                        DecisionTreeResult res = { 95.2381f, 4.7619f, 0.95238f, 0.04762f, false };
                                                        return res; /* Class 0: 95.24%, Class 1: 4.76% (tau=0.31) */
                                                    }
                                                } else {
                                                    {
                                                        DecisionTreeResult res = { 81.1765f, 18.8235f, 0.81176f, 0.18824f, false };
                                                        return res; /* Class 0: 81.18%, Class 1: 18.82% (tau=0.31) */
                                                    }
                                                }
                                            }
                                        } else {
                                            if (features[2] /* ART_DBP_mean */ <= 0.79125f) {
                                                {
                                                    DecisionTreeResult res = { 61.2245f, 38.7755f, 0.61224f, 0.38776f, true };
                                                    return res; /* Class 0: 61.22%, Class 1: 38.78% (tau=0.31) */
                                                }
                                            } else {
                                                {
                                                    DecisionTreeResult res = { 100.0000f, 0.0000f, 1.00000f, 0.00000f, false };
                                                    return res; /* Class 0: 100.00%, Class 1: 0.00% (tau=0.31) */
                                                }
                                            }
                                        }
                                    } else {
                                        if (features[64] /* FIO2_max */ <= 1.61454f) {
                                            {
                                                DecisionTreeResult res = { 65.7895f, 34.2105f, 0.65789f, 0.34211f, true };
                                                return res; /* Class 0: 65.79%, Class 1: 34.21% (tau=0.31) */
                                            }
                                        } else {
                                            {
                                                DecisionTreeResult res = { 30.9524f, 69.0476f, 0.30952f, 0.69048f, true };
                                                return res; /* Class 0: 30.95%, Class 1: 69.05% (tau=0.31) */
                                            }
                                        }
                                    }
                                } else {
                                    {
                                        DecisionTreeResult res = { 31.2500f, 68.7500f, 0.31250f, 0.68750f, true };
                                        return res; /* Class 0: 31.25%, Class 1: 68.75% (tau=0.31) */
                                    }
                                }
                            } else {
                                if (features[57] /* HR_max */ <= 0.69152f) {
                                    if (features[38] /* HR_min */ <= 0.17296f) {
                                        if (features[25] /* ETCO2_std */ <= -0.48652f) {
                                            {
                                                DecisionTreeResult res = { 50.0000f, 50.0000f, 0.50000f, 0.50000f, true };
                                                return res; /* Class 0: 50.00%, Class 1: 50.00% (tau=0.31) */
                                            }
                                        } else {
                                            if (features[27] /* BT_std */ <= 4.92958f) {
                                                if (features[63] /* ETCO2_max */ <= -1.02037f) {
                                                    {
                                                        DecisionTreeResult res = { 55.0000f, 45.0000f, 0.55000f, 0.45000f, true };
                                                        return res; /* Class 0: 55.00%, Class 1: 45.00% (tau=0.31) */
                                                    }
                                                } else {
                                                    {
                                                        DecisionTreeResult res = { 95.4498f, 4.5502f, 0.95450f, 0.04550f, false };
                                                        return res; /* Class 0: 95.45%, Class 1: 4.55% (tau=0.31) */
                                                    }
                                                }
                                            } else {
                                                {
                                                    DecisionTreeResult res = { 84.0909f, 15.9091f, 0.84091f, 0.15909f, false };
                                                    return res; /* Class 0: 84.09%, Class 1: 15.91% (tau=0.31) */
                                                }
                                            }
                                        }
                                    } else {
                                        {
                                            DecisionTreeResult res = { 73.6842f, 26.3158f, 0.73684f, 0.26316f, false };
                                            return res; /* Class 0: 73.68%, Class 1: 26.32% (tau=0.31) */
                                        }
                                    }
                                } else {
                                    if (features[76] /* HR_slope */ <= 3.35934f) {
                                        if (features[72] /* Feature_HR_Delta_60s_max */ <= 1.18459f) {
                                            if (features[66] /* Feature_Pulse_Pressure_max */ <= 2.03329f) {
                                                if (features[48] /* Feature_Shock_Index_min */ <= -0.62357f) {
                                                    {
                                                        DecisionTreeResult res = { 14.2857f, 85.7143f, 0.14286f, 0.85714f, true };
                                                        return res; /* Class 0: 14.29%, Class 1: 85.71% (tau=0.31) */
                                                    }
                                                } else {
                                                    {
                                                        DecisionTreeResult res = { 77.6471f, 22.3529f, 0.77647f, 0.22353f, false };
                                                        return res; /* Class 0: 77.65%, Class 1: 22.35% (tau=0.31) */
                                                    }
                                                }
                                            } else {
                                                {
                                                    DecisionTreeResult res = { 96.5517f, 3.4483f, 0.96552f, 0.03448f, false };
                                                    return res; /* Class 0: 96.55%, Class 1: 3.45% (tau=0.31) */
                                                }
                                            }
                                        } else {
                                            {
                                                DecisionTreeResult res = { 100.0000f, 0.0000f, 1.00000f, 0.00000f, false };
                                                return res; /* Class 0: 100.00%, Class 1: 0.00% (tau=0.31) */
                                            }
                                        }
                                    } else {
                                        {
                                            DecisionTreeResult res = { 55.5556f, 44.4444f, 0.55556f, 0.44444f, true };
                                            return res; /* Class 0: 55.56%, Class 1: 44.44% (tau=0.31) */
                                        }
                                    }
                                }
                            }
                        } else {
                            if (features[77] /* ART_SBP_slope */ <= 2.31415f) {
                                if (features[20] /* ART_SBP_std */ <= 1.10105f) {
                                    if (features[49] /* Feature_Modified_Shock_Index_min */ <= 0.18393f) {
                                        if (features[29] /* Feature_Shock_Index_std */ <= 1.08191f) {
                                            if (features[93] /* Feature_MBP_Std_60s_slope */ <= 0.21873f) {
                                                if (features[87] /* Feature_Modified_Shock_Index_slope */ <= 0.32092f) {
                                                    {
                                                        DecisionTreeResult res = { 68.5714f, 31.4286f, 0.68571f, 0.31429f, true };
                                                        return res; /* Class 0: 68.57%, Class 1: 31.43% (tau=0.31) */
                                                    }
                                                } else {
                                                    {
                                                        DecisionTreeResult res = { 38.7387f, 61.2613f, 0.38739f, 0.61261f, true };
                                                        return res; /* Class 0: 38.74%, Class 1: 61.26% (tau=0.31) */
                                                    }
                                                }
                                            } else {
                                                if (features[1] /* ART_SBP_mean */ <= -0.03099f) {
                                                    {
                                                        DecisionTreeResult res = { 46.1538f, 53.8462f, 0.46154f, 0.53846f, true };
                                                        return res; /* Class 0: 46.15%, Class 1: 53.85% (tau=0.31) */
                                                    }
                                                } else {
                                                    {
                                                        DecisionTreeResult res = { 17.2727f, 82.7273f, 0.17273f, 0.82727f, true };
                                                        return res; /* Class 0: 17.27%, Class 1: 82.73% (tau=0.31) */
                                                    }
                                                }
                                            }
                                        } else {
                                            {
                                                DecisionTreeResult res = { 8.1633f, 91.8367f, 0.08163f, 0.91837f, true };
                                                return res; /* Class 0: 8.16%, Class 1: 91.84% (tau=0.31) */
                                            }
                                        }
                                    } else {
                                        if (features[40] /* ART_DBP_min */ <= 0.70965f) {
                                            if (features[31] /* Feature_Rate_Pressure_Product_std */ <= 0.40378f) {
                                                {
                                                    DecisionTreeResult res = { 60.0000f, 40.0000f, 0.60000f, 0.40000f, true };
                                                    return res; /* Class 0: 60.00%, Class 1: 40.00% (tau=0.31) */
                                                }
                                            } else {
                                                if (features[50] /* Feature_Rate_Pressure_Product_min */ <= 1.01073f) {
                                                    {
                                                        DecisionTreeResult res = { 3.8462f, 96.1538f, 0.03846f, 0.96154f, true };
                                                        return res; /* Class 0: 3.85%, Class 1: 96.15% (tau=0.31) */
                                                    }
                                                } else {
                                                    {
                                                        DecisionTreeResult res = { 33.3333f, 66.6667f, 0.33333f, 0.66667f, true };
                                                        return res; /* Class 0: 33.33%, Class 1: 66.67% (tau=0.31) */
                                                    }
                                                }
                                            }
                                        } else {
                                            {
                                                DecisionTreeResult res = { 50.0000f, 50.0000f, 0.50000f, 0.50000f, true };
                                                return res; /* Class 0: 50.00%, Class 1: 50.00% (tau=0.31) */
                                            }
                                        }
                                    }
                                } else {
                                    if (features[7] /* FIO2_mean */ <= 1.30102f) {
                                        if (features[26] /* FIO2_std */ <= 4.54606f) {
                                            if (features[24] /* RR_CO2_std */ <= -0.48061f) {
                                                {
                                                    DecisionTreeResult res = { 62.1622f, 37.8378f, 0.62162f, 0.37838f, true };
                                                    return res; /* Class 0: 62.16%, Class 1: 37.84% (tau=0.31) */
                                                }
                                            } else {
                                                if (features[64] /* FIO2_max */ <= -0.69931f) {
                                                    {
                                                        DecisionTreeResult res = { 0.0000f, 100.0000f, 0.00000f, 1.00000f, true };
                                                        return res; /* Class 0: 0.00%, Class 1: 100.00% (tau=0.31) */
                                                    }
                                                } else {
                                                    {
                                                        DecisionTreeResult res = { 36.8421f, 63.1579f, 0.36842f, 0.63158f, true };
                                                        return res; /* Class 0: 36.84%, Class 1: 63.16% (tau=0.31) */
                                                    }
                                                }
                                            }
                                        } else {
                                            {
                                                DecisionTreeResult res = { 4.5455f, 95.4545f, 0.04545f, 0.95455f, true };
                                                return res; /* Class 0: 4.55%, Class 1: 95.45% (tau=0.31) */
                                            }
                                        }
                                    } else {
                                        if (features[88] /* Feature_Rate_Pressure_Product_slope */ <= 3.90912f) {
                                            if (features[67] /* Feature_Shock_Index_max */ <= 2.94516f) {
                                                if (features[50] /* Feature_Rate_Pressure_Product_min */ <= -0.48723f) {
                                                    {
                                                        DecisionTreeResult res = { 89.2857f, 10.7143f, 0.89286f, 0.10714f, false };
                                                        return res; /* Class 0: 89.29%, Class 1: 10.71% (tau=0.31) */
                                                    }
                                                } else {
                                                    {
                                                        DecisionTreeResult res = { 67.4419f, 32.5581f, 0.67442f, 0.32558f, true };
                                                        return res; /* Class 0: 67.44%, Class 1: 32.56% (tau=0.31) */
                                                    }
                                                }
                                            } else {
                                                {
                                                    DecisionTreeResult res = { 0.0000f, 100.0000f, 0.00000f, 1.00000f, true };
                                                    return res; /* Class 0: 0.00%, Class 1: 100.00% (tau=0.31) */
                                                }
                                            }
                                        } else {
                                            {
                                                DecisionTreeResult res = { 19.2308f, 80.7692f, 0.19231f, 0.80769f, true };
                                                return res; /* Class 0: 19.23%, Class 1: 80.77% (tau=0.31) */
                                            }
                                        }
                                    }
                                }
                            } else {
                                if (features[89] /* Feature_HR_Mean_60s_slope */ <= 3.65959f) {
                                    if (features[17] /* Feature_MBP_Std_60s_mean */ <= 0.34345f) {
                                        if (features[22] /* ART_MBP_std */ <= 0.15185f) {
                                            {
                                                DecisionTreeResult res = { 95.6522f, 4.3478f, 0.95652f, 0.04348f, false };
                                                return res; /* Class 0: 95.65%, Class 1: 4.35% (tau=0.31) */
                                            }
                                        } else {
                                            if (features[69] /* Feature_Rate_Pressure_Product_max */ <= 1.30266f) {
                                                {
                                                    DecisionTreeResult res = { 78.7879f, 21.2121f, 0.78788f, 0.21212f, false };
                                                    return res; /* Class 0: 78.79%, Class 1: 21.21% (tau=0.31) */
                                                }
                                            } else {
                                                if (features[66] /* Feature_Pulse_Pressure_max */ <= 1.22412f) {
                                                    {
                                                        DecisionTreeResult res = { 39.7059f, 60.2941f, 0.39706f, 0.60294f, true };
                                                        return res; /* Class 0: 39.71%, Class 1: 60.29% (tau=0.31) */
                                                    }
                                                } else {
                                                    {
                                                        DecisionTreeResult res = { 75.0000f, 25.0000f, 0.75000f, 0.25000f, false };
                                                        return res; /* Class 0: 75.00%, Class 1: 25.00% (tau=0.31) */
                                                    }
                                                }
                                            }
                                        }
                                    } else {
                                        if (features[76] /* HR_slope */ <= 3.26693f) {
                                            if (features[74] /* Feature_MBP_Std_60s_max */ <= 1.10808f) {
                                                if (features[41] /* ART_MBP_min */ <= -0.65043f) {
                                                    {
                                                        DecisionTreeResult res = { 65.5172f, 34.4828f, 0.65517f, 0.34483f, true };
                                                        return res; /* Class 0: 65.52%, Class 1: 34.48% (tau=0.31) */
                                                    }
                                                } else {
                                                    {
                                                        DecisionTreeResult res = { 90.4762f, 9.5238f, 0.90476f, 0.09524f, false };
                                                        return res; /* Class 0: 90.48%, Class 1: 9.52% (tau=0.31) */
                                                    }
                                                }
                                            } else {
                                                if (features[18] /* Feature_MBP_Delta_60s_mean */ <= 0.61052f) {
                                                    {
                                                        DecisionTreeResult res = { 80.0000f, 20.0000f, 0.80000f, 0.20000f, false };
                                                        return res; /* Class 0: 80.00%, Class 1: 20.00% (tau=0.31) */
                                                    }
                                                } else {
                                                    {
                                                        DecisionTreeResult res = { 96.0000f, 4.0000f, 0.96000f, 0.04000f, false };
                                                        return res; /* Class 0: 96.00%, Class 1: 4.00% (tau=0.31) */
                                                    }
                                                }
                                            }
                                        } else {
                                            {
                                                DecisionTreeResult res = { 40.0000f, 60.0000f, 0.40000f, 0.60000f, true };
                                                return res; /* Class 0: 40.00%, Class 1: 60.00% (tau=0.31) */
                                            }
                                        }
                                    }
                                } else {
                                    if (features[88] /* Feature_Rate_Pressure_Product_slope */ <= 4.65941f) {
                                        {
                                            DecisionTreeResult res = { 60.8696f, 39.1304f, 0.60870f, 0.39130f, true };
                                            return res; /* Class 0: 60.87%, Class 1: 39.13% (tau=0.31) */
                                        }
                                    } else {
                                        if (features[36] /* Feature_MBP_Std_60s_std */ <= 0.11767f) {
                                            {
                                                DecisionTreeResult res = { 6.3830f, 93.6170f, 0.06383f, 0.93617f, true };
                                                return res; /* Class 0: 6.38%, Class 1: 93.62% (tau=0.31) */
                                            }
                                        } else {
                                            if (features[11] /* Feature_Modified_Shock_Index_mean */ <= -0.37392f) {
                                                {
                                                    DecisionTreeResult res = { 47.8261f, 52.1739f, 0.47826f, 0.52174f, true };
                                                    return res; /* Class 0: 47.83%, Class 1: 52.17% (tau=0.31) */
                                                }
                                            } else {
                                                {
                                                    DecisionTreeResult res = { 5.1282f, 94.8718f, 0.05128f, 0.94872f, true };
                                                    return res; /* Class 0: 5.13%, Class 1: 94.87% (tau=0.31) */
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    } else {
                        if (features[92] /* Feature_MBP_Mean_60s_slope */ <= 0.53694f) {
                            if (features[70] /* Feature_HR_Mean_60s_max */ <= 0.05803f) {
                                {
                                    DecisionTreeResult res = { 19.2308f, 80.7692f, 0.19231f, 0.80769f, true };
                                    return res; /* Class 0: 19.23%, Class 1: 80.77% (tau=0.31) */
                                }
                            } else {
                                if (features[54] /* Feature_MBP_Mean_60s_min */ <= -0.48075f) {
                                    {
                                        DecisionTreeResult res = { 25.0000f, 75.0000f, 0.25000f, 0.75000f, true };
                                        return res; /* Class 0: 25.00%, Class 1: 75.00% (tau=0.31) */
                                    }
                                } else {
                                    {
                                        DecisionTreeResult res = { 0.0000f, 100.0000f, 0.00000f, 1.00000f, true };
                                        return res; /* Class 0: 0.00%, Class 1: 100.00% (tau=0.31) */
                                    }
                                }
                            }
                        } else {
                            if (features[89] /* Feature_HR_Mean_60s_slope */ <= 0.24903f) {
                                {
                                    DecisionTreeResult res = { 78.5714f, 21.4286f, 0.78571f, 0.21429f, false };
                                    return res; /* Class 0: 78.57%, Class 1: 21.43% (tau=0.31) */
                                }
                            } else {
                                if (features[2] /* ART_DBP_mean */ <= 1.37827f) {
                                    if (features[57] /* HR_max */ <= 0.93240f) {
                                        {
                                            DecisionTreeResult res = { 64.0000f, 36.0000f, 0.64000f, 0.36000f, true };
                                            return res; /* Class 0: 64.00%, Class 1: 36.00% (tau=0.31) */
                                        }
                                    } else {
                                        if (features[80] /* PLETH_SPO2_slope */ <= -2.42818f) {
                                            {
                                                DecisionTreeResult res = { 57.1429f, 42.8571f, 0.57143f, 0.42857f, true };
                                                return res; /* Class 0: 57.14%, Class 1: 42.86% (tau=0.31) */
                                            }
                                        } else {
                                            if (features[91] /* Feature_HR_Delta_60s_slope */ <= 3.08469f) {
                                                if (features[5] /* RR_CO2_mean */ <= -0.32377f) {
                                                    {
                                                        DecisionTreeResult res = { 17.2414f, 82.7586f, 0.17241f, 0.82759f, true };
                                                        return res; /* Class 0: 17.24%, Class 1: 82.76% (tau=0.31) */
                                                    }
                                                } else {
                                                    {
                                                        DecisionTreeResult res = { 55.1724f, 44.8276f, 0.55172f, 0.44828f, true };
                                                        return res; /* Class 0: 55.17%, Class 1: 44.83% (tau=0.31) */
                                                    }
                                                }
                                            } else {
                                                if (features[42] /* PLETH_SPO2_min */ <= 0.33752f) {
                                                    {
                                                        DecisionTreeResult res = { 0.0000f, 100.0000f, 0.00000f, 1.00000f, true };
                                                        return res; /* Class 0: 0.00%, Class 1: 100.00% (tau=0.31) */
                                                    }
                                                } else {
                                                    {
                                                        DecisionTreeResult res = { 12.5000f, 87.5000f, 0.12500f, 0.87500f, true };
                                                        return res; /* Class 0: 12.50%, Class 1: 87.50% (tau=0.31) */
                                                    }
                                                }
                                            }
                                        }
                                    }
                                } else {
                                    {
                                        DecisionTreeResult res = { 72.7273f, 27.2727f, 0.72727f, 0.27273f, false };
                                        return res; /* Class 0: 72.73%, Class 1: 27.27% (tau=0.31) */
                                    }
                                }
                            }
                        }
                    }
                }
            } else {
                if (features[12] /* Feature_Rate_Pressure_Product_mean */ <= 0.83289f) {
                    if (features[89] /* Feature_HR_Mean_60s_slope */ <= 1.97095f) {
                        if (features[42] /* PLETH_SPO2_min */ <= -1.48216f) {
                            if (features[68] /* Feature_Modified_Shock_Index_max */ <= 0.59603f) {
                                {
                                    DecisionTreeResult res = { 80.0000f, 20.0000f, 0.80000f, 0.20000f, false };
                                    return res; /* Class 0: 80.00%, Class 1: 20.00% (tau=0.31) */
                                }
                            } else {
                                if (features[94] /* Feature_MBP_Delta_60s_slope */ <= -0.93478f) {
                                    {
                                        DecisionTreeResult res = { 69.2308f, 30.7692f, 0.69231f, 0.30769f, false };
                                        return res; /* Class 0: 69.23%, Class 1: 30.77% (tau=0.31) */
                                    }
                                } else {
                                    if (features[66] /* Feature_Pulse_Pressure_max */ <= -0.13412f) {
                                        if (features[10] /* Feature_Shock_Index_mean */ <= 2.23353f) {
                                            if (features[64] /* FIO2_max */ <= 1.08058f) {
                                                {
                                                    DecisionTreeResult res = { 0.0000f, 100.0000f, 0.00000f, 1.00000f, true };
                                                    return res; /* Class 0: 0.00%, Class 1: 100.00% (tau=0.31) */
                                                }
                                            } else {
                                                {
                                                    DecisionTreeResult res = { 55.1724f, 44.8276f, 0.55172f, 0.44828f, true };
                                                    return res; /* Class 0: 55.17%, Class 1: 44.83% (tau=0.31) */
                                                }
                                            }
                                        } else {
                                            {
                                                DecisionTreeResult res = { 0.0000f, 100.0000f, 0.00000f, 1.00000f, true };
                                                return res; /* Class 0: 0.00%, Class 1: 100.00% (tau=0.31) */
                                            }
                                        }
                                    } else {
                                        if (features[26] /* FIO2_std */ <= 0.51429f) {
                                            {
                                                DecisionTreeResult res = { 13.6364f, 86.3636f, 0.13636f, 0.86364f, true };
                                                return res; /* Class 0: 13.64%, Class 1: 86.36% (tau=0.31) */
                                            }
                                        } else {
                                            {
                                                DecisionTreeResult res = { 69.2308f, 30.7692f, 0.69231f, 0.30769f, false };
                                                return res; /* Class 0: 69.23%, Class 1: 30.77% (tau=0.31) */
                                            }
                                        }
                                    }
                                }
                            }
                        } else {
                            if (features[45] /* FIO2_min */ <= 2.88606f) {
                                if (features[86] /* Feature_Shock_Index_slope */ <= -0.08090f) {
                                    if (features[71] /* Feature_HR_Std_60s_max */ <= 1.50045f) {
                                        if (features[53] /* Feature_HR_Delta_60s_min */ <= -0.37756f) {
                                            if (features[36] /* Feature_MBP_Std_60s_std */ <= 2.71243f) {
                                                if (features[33] /* Feature_HR_Std_60s_std */ <= 1.38527f) {
                                                    {
                                                        DecisionTreeResult res = { 80.5882f, 19.4118f, 0.80588f, 0.19412f, false };
                                                        return res; /* Class 0: 80.59%, Class 1: 19.41% (tau=0.31) */
                                                    }
                                                } else {
                                                    {
                                                        DecisionTreeResult res = { 43.4783f, 56.5217f, 0.43478f, 0.56522f, true };
                                                        return res; /* Class 0: 43.48%, Class 1: 56.52% (tau=0.31) */
                                                    }
                                                }
                                            } else {
                                                {
                                                    DecisionTreeResult res = { 30.4348f, 69.5652f, 0.30435f, 0.69565f, true };
                                                    return res; /* Class 0: 30.43%, Class 1: 69.57% (tau=0.31) */
                                                }
                                            }
                                        } else {
                                            if (features[0] /* HR_mean */ <= 1.96190f) {
                                                if (features[49] /* Feature_Modified_Shock_Index_min */ <= 1.80962f) {
                                                    {
                                                        DecisionTreeResult res = { 95.7983f, 4.2017f, 0.95798f, 0.04202f, false };
                                                        return res; /* Class 0: 95.80%, Class 1: 4.20% (tau=0.31) */
                                                    }
                                                } else {
                                                    {
                                                        DecisionTreeResult res = { 40.0000f, 60.0000f, 0.40000f, 0.60000f, true };
                                                        return res; /* Class 0: 40.00%, Class 1: 60.00% (tau=0.31) */
                                                    }
                                                }
                                            } else {
                                                {
                                                    DecisionTreeResult res = { 70.3704f, 29.6296f, 0.70370f, 0.29630f, false };
                                                    return res; /* Class 0: 70.37%, Class 1: 29.63% (tau=0.31) */
                                                }
                                            }
                                        }
                                    } else {
                                        if (features[25] /* ETCO2_std */ <= -0.10776f) {
                                            if (features[10] /* Feature_Shock_Index_mean */ <= 1.91458f) {
                                                if (features[65] /* BT_max */ <= 0.32306f) {
                                                    {
                                                        DecisionTreeResult res = { 44.9275f, 55.0725f, 0.44928f, 0.55072f, true };
                                                        return res; /* Class 0: 44.93%, Class 1: 55.07% (tau=0.31) */
                                                    }
                                                } else {
                                                    {
                                                        DecisionTreeResult res = { 85.7143f, 14.2857f, 0.85714f, 0.14286f, false };
                                                        return res; /* Class 0: 85.71%, Class 1: 14.29% (tau=0.31) */
                                                    }
                                                }
                                            } else {
                                                {
                                                    DecisionTreeResult res = { 4.7619f, 95.2381f, 0.04762f, 0.95238f, true };
                                                    return res; /* Class 0: 4.76%, Class 1: 95.24% (tau=0.31) */
                                                }
                                            }
                                        } else {
                                            if (features[57] /* HR_max */ <= 3.06016f) {
                                                if (features[11] /* Feature_Modified_Shock_Index_mean */ <= 7.22762f) {
                                                    {
                                                        DecisionTreeResult res = { 72.3214f, 27.6786f, 0.72321f, 0.27679f, false };
                                                        return res; /* Class 0: 72.32%, Class 1: 27.68% (tau=0.31) */
                                                    }
                                                } else {
                                                    {
                                                        DecisionTreeResult res = { 0.0000f, 100.0000f, 0.00000f, 1.00000f, true };
                                                        return res; /* Class 0: 0.00%, Class 1: 100.00% (tau=0.31) */
                                                    }
                                                }
                                            } else {
                                                {
                                                    DecisionTreeResult res = { 100.0000f, 0.0000f, 1.00000f, 0.00000f, false };
                                                    return res; /* Class 0: 100.00%, Class 1: 0.00% (tau=0.31) */
                                                }
                                            }
                                        }
                                    }
                                } else {
                                    if (features[13] /* Feature_HR_Mean_60s_mean */ <= 2.00163f) {
                                        if (features[64] /* FIO2_max */ <= 0.23513f) {
                                            if (features[89] /* Feature_HR_Mean_60s_slope */ <= -0.92079f) {
                                                if (features[72] /* Feature_HR_Delta_60s_max */ <= 2.42792f) {
                                                    {
                                                        DecisionTreeResult res = { 79.5455f, 20.4545f, 0.79545f, 0.20455f, false };
                                                        return res; /* Class 0: 79.55%, Class 1: 20.45% (tau=0.31) */
                                                    }
                                                } else {
                                                    {
                                                        DecisionTreeResult res = { 16.6667f, 83.3333f, 0.16667f, 0.83333f, true };
                                                        return res; /* Class 0: 16.67%, Class 1: 83.33% (tau=0.31) */
                                                    }
                                                }
                                            } else {
                                                if (features[9] /* Feature_Pulse_Pressure_mean */ <= -0.86577f) {
                                                    {
                                                        DecisionTreeResult res = { 21.2500f, 78.7500f, 0.21250f, 0.78750f, true };
                                                        return res; /* Class 0: 21.25%, Class 1: 78.75% (tau=0.31) */
                                                    }
                                                } else {
                                                    {
                                                        DecisionTreeResult res = { 49.4949f, 50.5051f, 0.49495f, 0.50505f, true };
                                                        return res; /* Class 0: 49.49%, Class 1: 50.51% (tau=0.31) */
                                                    }
                                                }
                                            }
                                        } else {
                                            if (features[10] /* Feature_Shock_Index_mean */ <= 0.97134f) {
                                                if (features[26] /* FIO2_std */ <= 5.07584f) {
                                                    {
                                                        DecisionTreeResult res = { 87.9630f, 12.0370f, 0.87963f, 0.12037f, false };
                                                        return res; /* Class 0: 87.96%, Class 1: 12.04% (tau=0.31) */
                                                    }
                                                } else {
                                                    {
                                                        DecisionTreeResult res = { 16.6667f, 83.3333f, 0.16667f, 0.83333f, true };
                                                        return res; /* Class 0: 16.67%, Class 1: 83.33% (tau=0.31) */
                                                    }
                                                }
                                            } else {
                                                if (features[46] /* BT_min */ <= 0.37905f) {
                                                    {
                                                        DecisionTreeResult res = { 48.9362f, 51.0638f, 0.48936f, 0.51064f, true };
                                                        return res; /* Class 0: 48.94%, Class 1: 51.06% (tau=0.31) */
                                                    }
                                                } else {
                                                    {
                                                        DecisionTreeResult res = { 82.5000f, 17.5000f, 0.82500f, 0.17500f, false };
                                                        return res; /* Class 0: 82.50%, Class 1: 17.50% (tau=0.31) */
                                                    }
                                                }
                                            }
                                        }
                                    } else {
                                        if (features[4] /* PLETH_SPO2_mean */ <= 0.37547f) {
                                            if (features[70] /* Feature_HR_Mean_60s_max */ <= 2.13828f) {
                                                {
                                                    DecisionTreeResult res = { 20.0000f, 80.0000f, 0.20000f, 0.80000f, true };
                                                    return res; /* Class 0: 20.00%, Class 1: 80.00% (tau=0.31) */
                                                }
                                            } else {
                                                {
                                                    DecisionTreeResult res = { 2.2727f, 97.7273f, 0.02273f, 0.97727f, true };
                                                    return res; /* Class 0: 2.27%, Class 1: 97.73% (tau=0.31) */
                                                }
                                            }
                                        } else {
                                            {
                                                DecisionTreeResult res = { 50.0000f, 50.0000f, 0.50000f, 0.50000f, true };
                                                return res; /* Class 0: 50.00%, Class 1: 50.00% (tau=0.31) */
                                            }
                                        }
                                    }
                                }
                            } else {
                                if (features[5] /* RR_CO2_mean */ <= 0.18348f) {
                                    {
                                        DecisionTreeResult res = { 66.6667f, 33.3333f, 0.66667f, 0.33333f, true };
                                        return res; /* Class 0: 66.67%, Class 1: 33.33% (tau=0.31) */
                                    }
                                } else {
                                    if (features[22] /* ART_MBP_std */ <= -0.61733f) {
                                        {
                                            DecisionTreeResult res = { 36.0000f, 64.0000f, 0.36000f, 0.64000f, true };
                                            return res; /* Class 0: 36.00%, Class 1: 64.00% (tau=0.31) */
                                        }
                                    } else {
                                        {
                                            DecisionTreeResult res = { 0.0000f, 100.0000f, 0.00000f, 1.00000f, true };
                                            return res; /* Class 0: 0.00%, Class 1: 100.00% (tau=0.31) */
                                        }
                                    }
                                }
                            }
                        }
                    } else {
                        if (features[39] /* ART_SBP_min */ <= -2.13163f) {
                            if (features[15] /* Feature_HR_Delta_60s_mean */ <= 2.40793f) {
                                {
                                    DecisionTreeResult res = { 51.1628f, 48.8372f, 0.51163f, 0.48837f, true };
                                    return res; /* Class 0: 51.16%, Class 1: 48.84% (tau=0.31) */
                                }
                            } else {
                                if (features[90] /* Feature_HR_Std_60s_slope */ <= -2.03945f) {
                                    {
                                        DecisionTreeResult res = { 80.0000f, 20.0000f, 0.80000f, 0.20000f, false };
                                        return res; /* Class 0: 80.00%, Class 1: 20.00% (tau=0.31) */
                                    }
                                } else {
                                    if (features[83] /* FIO2_slope */ <= 0.50312f) {
                                        if (features[7] /* FIO2_mean */ <= 1.58111f) {
                                            {
                                                DecisionTreeResult res = { 17.9487f, 82.0513f, 0.17949f, 0.82051f, true };
                                                return res; /* Class 0: 17.95%, Class 1: 82.05% (tau=0.31) */
                                            }
                                        } else {
                                            {
                                                DecisionTreeResult res = { 46.6667f, 53.3333f, 0.46667f, 0.53333f, true };
                                                return res; /* Class 0: 46.67%, Class 1: 53.33% (tau=0.31) */
                                            }
                                        }
                                    } else {
                                        {
                                            DecisionTreeResult res = { 5.0000f, 95.0000f, 0.05000f, 0.95000f, true };
                                            return res; /* Class 0: 5.00%, Class 1: 95.00% (tau=0.31) */
                                        }
                                    }
                                }
                            }
                        } else {
                            if (features[57] /* HR_max */ <= 0.93240f) {
                                {
                                    DecisionTreeResult res = { 54.5455f, 45.4545f, 0.54545f, 0.45455f, true };
                                    return res; /* Class 0: 54.55%, Class 1: 45.45% (tau=0.31) */
                                }
                            } else {
                                if (features[70] /* Feature_HR_Mean_60s_max */ <= 1.47621f) {
                                    {
                                        DecisionTreeResult res = { 80.0000f, 20.0000f, 0.80000f, 0.20000f, false };
                                        return res; /* Class 0: 80.00%, Class 1: 20.00% (tau=0.31) */
                                    }
                                } else {
                                    if (features[42] /* PLETH_SPO2_min */ <= 0.33752f) {
                                        if (features[31] /* Feature_Rate_Pressure_Product_std */ <= 4.40656f) {
                                            if (features[15] /* Feature_HR_Delta_60s_mean */ <= 2.04112f) {
                                                {
                                                    DecisionTreeResult res = { 15.5556f, 84.4444f, 0.15556f, 0.84444f, true };
                                                    return res; /* Class 0: 15.56%, Class 1: 84.44% (tau=0.31) */
                                                }
                                            } else {
                                                if (features[47] /* Feature_Pulse_Pressure_min */ <= 1.25459f) {
                                                    {
                                                        DecisionTreeResult res = { 0.5376f, 99.4624f, 0.00538f, 0.99462f, true };
                                                        return res; /* Class 0: 0.54%, Class 1: 99.46% (tau=0.31) */
                                                    }
                                                } else {
                                                    {
                                                        DecisionTreeResult res = { 11.1111f, 88.8889f, 0.11111f, 0.88889f, true };
                                                        return res; /* Class 0: 11.11%, Class 1: 88.89% (tau=0.31) */
                                                    }
                                                }
                                            }
                                        } else {
                                            {
                                                DecisionTreeResult res = { 25.0000f, 75.0000f, 0.25000f, 0.75000f, true };
                                                return res; /* Class 0: 25.00%, Class 1: 75.00% (tau=0.31) */
                                            }
                                        }
                                    } else {
                                        if (features[51] /* Feature_HR_Mean_60s_min */ <= -0.19618f) {
                                            {
                                                DecisionTreeResult res = { 66.6667f, 33.3333f, 0.66667f, 0.33333f, true };
                                                return res; /* Class 0: 66.67%, Class 1: 33.33% (tau=0.31) */
                                            }
                                        } else {
                                            if (features[7] /* FIO2_mean */ <= -0.81500f) {
                                                {
                                                    DecisionTreeResult res = { 71.4286f, 28.5714f, 0.71429f, 0.28571f, false };
                                                    return res; /* Class 0: 71.43%, Class 1: 28.57% (tau=0.31) */
                                                }
                                            } else {
                                                if (features[15] /* Feature_HR_Delta_60s_mean */ <= 2.84390f) {
                                                    {
                                                        DecisionTreeResult res = { 29.0909f, 70.9091f, 0.29091f, 0.70909f, true };
                                                        return res; /* Class 0: 29.09%, Class 1: 70.91% (tau=0.31) */
                                                    }
                                                } else {
                                                    {
                                                        DecisionTreeResult res = { 1.8868f, 98.1132f, 0.01887f, 0.98113f, true };
                                                        return res; /* Class 0: 1.89%, Class 1: 98.11% (tau=0.31) */
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                } else {
                    if (features[70] /* Feature_HR_Mean_60s_max */ <= 2.05364f) {
                        if (features[53] /* Feature_HR_Delta_60s_min */ <= -0.99735f) {
                            if (features[14] /* Feature_HR_Std_60s_mean */ <= 2.02584f) {
                                if (features[11] /* Feature_Modified_Shock_Index_mean */ <= 0.22481f) {
                                    if (features[57] /* HR_max */ <= 2.17694f) {
                                        {
                                            DecisionTreeResult res = { 60.4167f, 39.5833f, 0.60417f, 0.39583f, true };
                                            return res; /* Class 0: 60.42%, Class 1: 39.58% (tau=0.31) */
                                        }
                                    } else {
                                        {
                                            DecisionTreeResult res = { 92.5926f, 7.4074f, 0.92593f, 0.07407f, false };
                                            return res; /* Class 0: 92.59%, Class 1: 7.41% (tau=0.31) */
                                        }
                                    }
                                } else {
                                    if (features[89] /* Feature_HR_Mean_60s_slope */ <= 0.12854f) {
                                        if (features[67] /* Feature_Shock_Index_max */ <= 0.82053f) {
                                            {
                                                DecisionTreeResult res = { 26.3158f, 73.6842f, 0.26316f, 0.73684f, true };
                                                return res; /* Class 0: 26.32%, Class 1: 73.68% (tau=0.31) */
                                            }
                                        } else {
                                            {
                                                DecisionTreeResult res = { 75.0000f, 25.0000f, 0.75000f, 0.25000f, false };
                                                return res; /* Class 0: 75.00%, Class 1: 25.00% (tau=0.31) */
                                            }
                                        }
                                    } else {
                                        if (features[27] /* BT_std */ <= -0.27089f) {
                                            {
                                                DecisionTreeResult res = { 2.9412f, 97.0588f, 0.02941f, 0.97059f, true };
                                                return res; /* Class 0: 2.94%, Class 1: 97.06% (tau=0.31) */
                                            }
                                        } else {
                                            if (features[8] /* BT_mean */ <= 0.30375f) {
                                                {
                                                    DecisionTreeResult res = { 47.3684f, 52.6316f, 0.47368f, 0.52632f, true };
                                                    return res; /* Class 0: 47.37%, Class 1: 52.63% (tau=0.31) */
                                                }
                                            } else {
                                                {
                                                    DecisionTreeResult res = { 4.5455f, 95.4545f, 0.04545f, 0.95455f, true };
                                                    return res; /* Class 0: 4.55%, Class 1: 95.45% (tau=0.31) */
                                                }
                                            }
                                        }
                                    }
                                }
                            } else {
                                if (features[67] /* Feature_Shock_Index_max */ <= 0.20159f) {
                                    {
                                        DecisionTreeResult res = { 73.3333f, 26.6667f, 0.73333f, 0.26667f, false };
                                        return res; /* Class 0: 73.33%, Class 1: 26.67% (tau=0.31) */
                                    }
                                } else {
                                    if (features[33] /* Feature_HR_Std_60s_std */ <= 0.72579f) {
                                        {
                                            DecisionTreeResult res = { 53.5714f, 46.4286f, 0.53571f, 0.46429f, true };
                                            return res; /* Class 0: 53.57%, Class 1: 46.43% (tau=0.31) */
                                        }
                                    } else {
                                        if (features[33] /* Feature_HR_Std_60s_std */ <= 3.36557f) {
                                            if (features[17] /* Feature_MBP_Std_60s_mean */ <= -0.04182f) {
                                                if (features[56] /* Feature_MBP_Delta_60s_min */ <= 0.15360f) {
                                                    {
                                                        DecisionTreeResult res = { 66.6667f, 33.3333f, 0.66667f, 0.33333f, true };
                                                        return res; /* Class 0: 66.67%, Class 1: 33.33% (tau=0.31) */
                                                    }
                                                } else {
                                                    {
                                                        DecisionTreeResult res = { 10.7143f, 89.2857f, 0.10714f, 0.89286f, true };
                                                        return res; /* Class 0: 10.71%, Class 1: 89.29% (tau=0.31) */
                                                    }
                                                }
                                            } else {
                                                if (features[82] /* ETCO2_slope */ <= 1.59167f) {
                                                    {
                                                        DecisionTreeResult res = { 0.0000f, 100.0000f, 0.00000f, 1.00000f, true };
                                                        return res; /* Class 0: 0.00%, Class 1: 100.00% (tau=0.31) */
                                                    }
                                                } else {
                                                    {
                                                        DecisionTreeResult res = { 20.0000f, 80.0000f, 0.20000f, 0.80000f, true };
                                                        return res; /* Class 0: 20.00%, Class 1: 80.00% (tau=0.31) */
                                                    }
                                                }
                                            }
                                        } else {
                                            {
                                                DecisionTreeResult res = { 50.0000f, 50.0000f, 0.50000f, 0.50000f, true };
                                                return res; /* Class 0: 50.00%, Class 1: 50.00% (tau=0.31) */
                                            }
                                        }
                                    }
                                }
                            }
                        } else {
                            if (features[31] /* Feature_Rate_Pressure_Product_std */ <= 0.66126f) {
                                if (features[7] /* FIO2_mean */ <= -0.10623f) {
                                    {
                                        DecisionTreeResult res = { 16.6667f, 83.3333f, 0.16667f, 0.83333f, true };
                                        return res; /* Class 0: 16.67%, Class 1: 83.33% (tau=0.31) */
                                    }
                                } else {
                                    if (features[45] /* FIO2_min */ <= 1.86492f) {
                                        {
                                            DecisionTreeResult res = { 67.3913f, 32.6087f, 0.67391f, 0.32609f, true };
                                            return res; /* Class 0: 67.39%, Class 1: 32.61% (tau=0.31) */
                                        }
                                    } else {
                                        {
                                            DecisionTreeResult res = { 21.4286f, 78.5714f, 0.21429f, 0.78571f, true };
                                            return res; /* Class 0: 21.43%, Class 1: 78.57% (tau=0.31) */
                                        }
                                    }
                                }
                            } else {
                                if (features[74] /* Feature_MBP_Std_60s_max */ <= -0.47003f) {
                                    {
                                        DecisionTreeResult res = { 27.0270f, 72.9730f, 0.27027f, 0.72973f, true };
                                        return res; /* Class 0: 27.03%, Class 1: 72.97% (tau=0.31) */
                                    }
                                } else {
                                    if (features[3] /* ART_MBP_mean */ <= 2.43176f) {
                                        if (features[0] /* HR_mean */ <= 1.70700f) {
                                            if (features[57] /* HR_max */ <= 1.81562f) {
                                                if (features[75] /* Feature_MBP_Delta_60s_max */ <= 0.84489f) {
                                                    {
                                                        DecisionTreeResult res = { 68.1648f, 31.8352f, 0.68165f, 0.31835f, true };
                                                        return res; /* Class 0: 68.16%, Class 1: 31.84% (tau=0.31) */
                                                    }
                                                } else {
                                                    {
                                                        DecisionTreeResult res = { 88.2883f, 11.7117f, 0.88288f, 0.11712f, false };
                                                        return res; /* Class 0: 88.29%, Class 1: 11.71% (tau=0.31) */
                                                    }
                                                }
                                            } else {
                                                {
                                                    DecisionTreeResult res = { 11.1111f, 88.8889f, 0.11111f, 0.88889f, true };
                                                    return res; /* Class 0: 11.11%, Class 1: 88.89% (tau=0.31) */
                                                }
                                            }
                                        } else {
                                            if (features[71] /* Feature_HR_Std_60s_max */ <= 0.57745f) {
                                                {
                                                    DecisionTreeResult res = { 59.1837f, 40.8163f, 0.59184f, 0.40816f, true };
                                                    return res; /* Class 0: 59.18%, Class 1: 40.82% (tau=0.31) */
                                                }
                                            } else {
                                                {
                                                    DecisionTreeResult res = { 20.0000f, 80.0000f, 0.20000f, 0.80000f, true };
                                                    return res; /* Class 0: 20.00%, Class 1: 80.00% (tau=0.31) */
                                                }
                                            }
                                        }
                                    } else {
                                        {
                                            DecisionTreeResult res = { 0.0000f, 100.0000f, 0.00000f, 1.00000f, true };
                                            return res; /* Class 0: 0.00%, Class 1: 100.00% (tau=0.31) */
                                        }
                                    }
                                }
                            }
                        }
                    } else {
                        if (features[13] /* Feature_HR_Mean_60s_mean */ <= 2.29117f) {
                            if (features[15] /* Feature_HR_Delta_60s_mean */ <= 1.02414f) {
                                if (features[49] /* Feature_Modified_Shock_Index_min */ <= 0.62723f) {
                                    if (features[76] /* HR_slope */ <= 1.23411f) {
                                        if (features[90] /* Feature_HR_Std_60s_slope */ <= 1.75487f) {
                                            if (features[92] /* Feature_MBP_Mean_60s_slope */ <= -1.53270f) {
                                                if (features[68] /* Feature_Modified_Shock_Index_max */ <= 0.69797f) {
                                                    {
                                                        DecisionTreeResult res = { 66.6667f, 33.3333f, 0.66667f, 0.33333f, true };
                                                        return res; /* Class 0: 66.67%, Class 1: 33.33% (tau=0.31) */
                                                    }
                                                } else {
                                                    {
                                                        DecisionTreeResult res = { 20.0000f, 80.0000f, 0.20000f, 0.80000f, true };
                                                        return res; /* Class 0: 20.00%, Class 1: 80.00% (tau=0.31) */
                                                    }
                                                }
                                            } else {
                                                if (features[0] /* HR_mean */ <= 1.74432f) {
                                                    {
                                                        DecisionTreeResult res = { 78.9062f, 21.0938f, 0.78906f, 0.21094f, false };
                                                        return res; /* Class 0: 78.91%, Class 1: 21.09% (tau=0.31) */
                                                    }
                                                } else {
                                                    {
                                                        DecisionTreeResult res = { 62.1951f, 37.8049f, 0.62195f, 0.37805f, true };
                                                        return res; /* Class 0: 62.20%, Class 1: 37.80% (tau=0.31) */
                                                    }
                                                }
                                            }
                                        } else {
                                            {
                                                DecisionTreeResult res = { 31.7073f, 68.2927f, 0.31707f, 0.68293f, true };
                                                return res; /* Class 0: 31.71%, Class 1: 68.29% (tau=0.31) */
                                            }
                                        }
                                    } else {
                                        {
                                            DecisionTreeResult res = { 16.0000f, 84.0000f, 0.16000f, 0.84000f, true };
                                            return res; /* Class 0: 16.00%, Class 1: 84.00% (tau=0.31) */
                                        }
                                    }
                                } else {
                                    if (features[51] /* Feature_HR_Mean_60s_min */ <= 1.20253f) {
                                        {
                                            DecisionTreeResult res = { 73.8095f, 26.1905f, 0.73810f, 0.26190f, false };
                                            return res; /* Class 0: 73.81%, Class 1: 26.19% (tau=0.31) */
                                        }
                                    } else {
                                        if (features[45] /* FIO2_min */ <= -0.61498f) {
                                            {
                                                DecisionTreeResult res = { 76.9231f, 23.0769f, 0.76923f, 0.23077f, false };
                                                return res; /* Class 0: 76.92%, Class 1: 23.08% (tau=0.31) */
                                            }
                                        } else {
                                            if (features[30] /* Feature_Modified_Shock_Index_std */ <= 0.72860f) {
                                                if (features[57] /* HR_max */ <= 3.72257f) {
                                                    {
                                                        DecisionTreeResult res = { 8.4337f, 91.5663f, 0.08434f, 0.91566f, true };
                                                        return res; /* Class 0: 8.43%, Class 1: 91.57% (tau=0.31) */
                                                    }
                                                } else {
                                                    {
                                                        DecisionTreeResult res = { 41.6667f, 58.3333f, 0.41667f, 0.58333f, true };
                                                        return res; /* Class 0: 41.67%, Class 1: 58.33% (tau=0.31) */
                                                    }
                                                }
                                            } else {
                                                {
                                                    DecisionTreeResult res = { 44.4444f, 55.5556f, 0.44444f, 0.55556f, true };
                                                    return res; /* Class 0: 44.44%, Class 1: 55.56% (tau=0.31) */
                                                }
                                            }
                                        }
                                    }
                                }
                            } else {
                                if (features[53] /* Feature_HR_Delta_60s_min */ <= 0.03564f) {
                                    if (features[37] /* Feature_MBP_Delta_60s_std */ <= 0.16242f) {
                                        if (features[88] /* Feature_Rate_Pressure_Product_slope */ <= 1.04378f) {
                                            if (features[11] /* Feature_Modified_Shock_Index_mean */ <= 0.47957f) {
                                                if (features[27] /* BT_std */ <= -0.15490f) {
                                                    {
                                                        DecisionTreeResult res = { 30.6122f, 69.3878f, 0.30612f, 0.69388f, true };
                                                        return res; /* Class 0: 30.61%, Class 1: 69.39% (tau=0.31) */
                                                    }
                                                } else {
                                                    {
                                                        DecisionTreeResult res = { 100.0000f, 0.0000f, 1.00000f, 0.00000f, false };
                                                        return res; /* Class 0: 100.00%, Class 1: 0.00% (tau=0.31) */
                                                    }
                                                }
                                            } else {
                                                if (features[23] /* PLETH_SPO2_std */ <= 0.12382f) {
                                                    {
                                                        DecisionTreeResult res = { 1.7857f, 98.2143f, 0.01786f, 0.98214f, true };
                                                        return res; /* Class 0: 1.79%, Class 1: 98.21% (tau=0.31) */
                                                    }
                                                } else {
                                                    {
                                                        DecisionTreeResult res = { 25.0000f, 75.0000f, 0.25000f, 0.75000f, true };
                                                        return res; /* Class 0: 25.00%, Class 1: 75.00% (tau=0.31) */
                                                    }
                                                }
                                            }
                                        } else {
                                            if (features[46] /* BT_min */ <= 0.33040f) {
                                                if (features[83] /* FIO2_slope */ <= 4.15020f) {
                                                    {
                                                        DecisionTreeResult res = { 8.6538f, 91.3462f, 0.08654f, 0.91346f, true };
                                                        return res; /* Class 0: 8.65%, Class 1: 91.35% (tau=0.31) */
                                                    }
                                                } else {
                                                    {
                                                        DecisionTreeResult res = { 66.6667f, 33.3333f, 0.66667f, 0.33333f, true };
                                                        return res; /* Class 0: 66.67%, Class 1: 33.33% (tau=0.31) */
                                                    }
                                                }
                                            } else {
                                                {
                                                    DecisionTreeResult res = { 0.0000f, 100.0000f, 0.00000f, 1.00000f, true };
                                                    return res; /* Class 0: 0.00%, Class 1: 100.00% (tau=0.31) */
                                                }
                                            }
                                        }
                                    } else {
                                        if (features[75] /* Feature_MBP_Delta_60s_max */ <= 0.26932f) {
                                            {
                                                DecisionTreeResult res = { 78.9474f, 21.0526f, 0.78947f, 0.21053f, false };
                                                return res; /* Class 0: 78.95%, Class 1: 21.05% (tau=0.31) */
                                            }
                                        } else {
                                            if (features[2] /* ART_DBP_mean */ <= 2.12320f) {
                                                if (features[51] /* Feature_HR_Mean_60s_min */ <= 0.77887f) {
                                                    {
                                                        DecisionTreeResult res = { 41.5385f, 58.4615f, 0.41538f, 0.58462f, true };
                                                        return res; /* Class 0: 41.54%, Class 1: 58.46% (tau=0.31) */
                                                    }
                                                } else {
                                                    {
                                                        DecisionTreeResult res = { 8.6207f, 91.3793f, 0.08621f, 0.91379f, true };
                                                        return res; /* Class 0: 8.62%, Class 1: 91.38% (tau=0.31) */
                                                    }
                                                }
                                            } else {
                                                {
                                                    DecisionTreeResult res = { 70.5882f, 29.4118f, 0.70588f, 0.29412f, false };
                                                    return res; /* Class 0: 70.59%, Class 1: 29.41% (tau=0.31) */
                                                }
                                            }
                                        }
                                    }
                                } else {
                                    if (features[17] /* Feature_MBP_Std_60s_mean */ <= -0.51468f) {
                                        {
                                            DecisionTreeResult res = { 60.0000f, 40.0000f, 0.60000f, 0.40000f, true };
                                            return res; /* Class 0: 60.00%, Class 1: 40.00% (tau=0.31) */
                                        }
                                    } else {
                                        if (features[48] /* Feature_Shock_Index_min */ <= 1.44733f) {
                                            if (features[63] /* ETCO2_max */ <= 2.53911f) {
                                                if (features[44] /* ETCO2_min */ <= 0.71491f) {
                                                    {
                                                        DecisionTreeResult res = { 1.1364f, 98.8636f, 0.01136f, 0.98864f, true };
                                                        return res; /* Class 0: 1.14%, Class 1: 98.86% (tau=0.31) */
                                                    }
                                                } else {
                                                    {
                                                        DecisionTreeResult res = { 23.0769f, 76.9231f, 0.23077f, 0.76923f, true };
                                                        return res; /* Class 0: 23.08%, Class 1: 76.92% (tau=0.31) */
                                                    }
                                                }
                                            } else {
                                                {
                                                    DecisionTreeResult res = { 18.7500f, 81.2500f, 0.18750f, 0.81250f, true };
                                                    return res; /* Class 0: 18.75%, Class 1: 81.25% (tau=0.31) */
                                                }
                                            }
                                        } else {
                                            {
                                                DecisionTreeResult res = { 50.0000f, 50.0000f, 0.50000f, 0.50000f, true };
                                                return res; /* Class 0: 50.00%, Class 1: 50.00% (tau=0.31) */
                                            }
                                        }
                                    }
                                }
                            }
                        } else {
                            if (features[57] /* HR_max */ <= 1.93606f) {
                                if (features[7] /* FIO2_mean */ <= 2.08419f) {
                                    if (features[38] /* HR_min */ <= -0.91266f) {
                                        {
                                            DecisionTreeResult res = { 100.0000f, 0.0000f, 1.00000f, 0.00000f, false };
                                            return res; /* Class 0: 100.00%, Class 1: 0.00% (tau=0.31) */
                                        }
                                    } else {
                                        if (features[86] /* Feature_Shock_Index_slope */ <= -2.33758f) {
                                            {
                                                DecisionTreeResult res = { 66.6667f, 33.3333f, 0.66667f, 0.33333f, true };
                                                return res; /* Class 0: 66.67%, Class 1: 33.33% (tau=0.31) */
                                            }
                                        } else {
                                            if (features[40] /* ART_DBP_min */ <= 1.45399f) {
                                                if (features[42] /* PLETH_SPO2_min */ <= -3.95172f) {
                                                    {
                                                        DecisionTreeResult res = { 80.0000f, 20.0000f, 0.80000f, 0.20000f, false };
                                                        return res; /* Class 0: 80.00%, Class 1: 20.00% (tau=0.31) */
                                                    }
                                                } else {
                                                    {
                                                        DecisionTreeResult res = { 6.7010f, 93.2990f, 0.06701f, 0.93299f, true };
                                                        return res; /* Class 0: 6.70%, Class 1: 93.30% (tau=0.31) */
                                                    }
                                                }
                                            } else {
                                                {
                                                    DecisionTreeResult res = { 88.8889f, 11.1111f, 0.88889f, 0.11111f, false };
                                                    return res; /* Class 0: 88.89%, Class 1: 11.11% (tau=0.31) */
                                                }
                                            }
                                        }
                                    }
                                } else {
                                    if (features[53] /* Feature_HR_Delta_60s_min */ <= 0.00981f) {
                                        {
                                            DecisionTreeResult res = { 65.0000f, 35.0000f, 0.65000f, 0.35000f, true };
                                            return res; /* Class 0: 65.00%, Class 1: 35.00% (tau=0.31) */
                                        }
                                    } else {
                                        {
                                            DecisionTreeResult res = { 0.0000f, 100.0000f, 0.00000f, 1.00000f, true };
                                            return res; /* Class 0: 0.00%, Class 1: 100.00% (tau=0.31) */
                                        }
                                    }
                                }
                            } else {
                                if (features[48] /* Feature_Shock_Index_min */ <= -0.53067f) {
                                    {
                                        DecisionTreeResult res = { 59.0909f, 40.9091f, 0.59091f, 0.40909f, true };
                                        return res; /* Class 0: 59.09%, Class 1: 40.91% (tau=0.31) */
                                    }
                                } else {
                                    if (features[0] /* HR_mean */ <= 2.67927f) {
                                        if (features[69] /* Feature_Rate_Pressure_Product_max */ <= 2.90333f) {
                                            if (features[45] /* FIO2_min */ <= -0.55663f) {
                                                {
                                                    DecisionTreeResult res = { 39.0244f, 60.9756f, 0.39024f, 0.60976f, true };
                                                    return res; /* Class 0: 39.02%, Class 1: 60.98% (tau=0.31) */
                                                }
                                            } else {
                                                if (features[36] /* Feature_MBP_Std_60s_std */ <= -0.52375f) {
                                                    {
                                                        DecisionTreeResult res = { 60.0000f, 40.0000f, 0.60000f, 0.40000f, true };
                                                        return res; /* Class 0: 60.00%, Class 1: 40.00% (tau=0.31) */
                                                    }
                                                } else {
                                                    {
                                                        DecisionTreeResult res = { 7.9710f, 92.0290f, 0.07971f, 0.92029f, true };
                                                        return res; /* Class 0: 7.97%, Class 1: 92.03% (tau=0.31) */
                                                    }
                                                }
                                            }
                                        } else {
                                            {
                                                DecisionTreeResult res = { 51.7241f, 48.2759f, 0.51724f, 0.48276f, true };
                                                return res; /* Class 0: 51.72%, Class 1: 48.28% (tau=0.31) */
                                            }
                                        }
                                    } else {
                                        if (features[74] /* Feature_MBP_Std_60s_max */ <= -0.55937f) {
                                            {
                                                DecisionTreeResult res = { 21.4286f, 78.5714f, 0.21429f, 0.78571f, true };
                                                return res; /* Class 0: 21.43%, Class 1: 78.57% (tau=0.31) */
                                            }
                                        } else {
                                            if (features[92] /* Feature_MBP_Mean_60s_slope */ <= -2.43179f) {
                                                {
                                                    DecisionTreeResult res = { 40.0000f, 60.0000f, 0.40000f, 0.60000f, true };
                                                    return res; /* Class 0: 40.00%, Class 1: 60.00% (tau=0.31) */
                                                }
                                            } else {
                                                if (features[25] /* ETCO2_std */ <= 3.02202f) {
                                                    {
                                                        DecisionTreeResult res = { 2.0992f, 97.9008f, 0.02099f, 0.97901f, true };
                                                        return res; /* Class 0: 2.10%, Class 1: 97.90% (tau=0.31) */
                                                    }
                                                } else {
                                                    {
                                                        DecisionTreeResult res = { 13.9535f, 86.0465f, 0.13953f, 0.86047f, true };
                                                        return res; /* Class 0: 13.95%, Class 1: 86.05% (tau=0.31) */
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        } else {
            if (features[68] /* Feature_Modified_Shock_Index_max */ <= 0.70118f) {
                if (features[51] /* Feature_HR_Mean_60s_min */ <= 1.05512f) {
                    if (features[54] /* Feature_MBP_Mean_60s_min */ <= 0.12550f) {
                        if (features[38] /* HR_min */ <= -0.09844f) {
                            if (features[66] /* Feature_Pulse_Pressure_max */ <= -1.02999f) {
                                if (features[45] /* FIO2_min */ <= 0.28946f) {
                                    if (features[91] /* Feature_HR_Delta_60s_slope */ <= 6.17671f) {
                                        if (features[42] /* PLETH_SPO2_min */ <= 0.07756f) {
                                            if (features[13] /* Feature_HR_Mean_60s_mean */ <= -1.30673f) {
                                                {
                                                    DecisionTreeResult res = { 50.0000f, 50.0000f, 0.50000f, 0.50000f, true };
                                                    return res; /* Class 0: 50.00%, Class 1: 50.00% (tau=0.31) */
                                                }
                                            } else {
                                                if (features[7] /* FIO2_mean */ <= -0.60292f) {
                                                    {
                                                        DecisionTreeResult res = { 83.3333f, 16.6667f, 0.83333f, 0.16667f, false };
                                                        return res; /* Class 0: 83.33%, Class 1: 16.67% (tau=0.31) */
                                                    }
                                                } else {
                                                    {
                                                        DecisionTreeResult res = { 100.0000f, 0.0000f, 1.00000f, 0.00000f, false };
                                                        return res; /* Class 0: 100.00%, Class 1: 0.00% (tau=0.31) */
                                                    }
                                                }
                                            }
                                        } else {
                                            if (features[72] /* Feature_HR_Delta_60s_max */ <= 3.97573f) {
                                                if (features[14] /* Feature_HR_Std_60s_mean */ <= 3.52168f) {
                                                    {
                                                        DecisionTreeResult res = { 94.1176f, 5.8824f, 0.94118f, 0.05882f, false };
                                                        return res; /* Class 0: 94.12%, Class 1: 5.88% (tau=0.31) */
                                                    }
                                                } else {
                                                    {
                                                        DecisionTreeResult res = { 63.6364f, 36.3636f, 0.63636f, 0.36364f, true };
                                                        return res; /* Class 0: 63.64%, Class 1: 36.36% (tau=0.31) */
                                                    }
                                                }
                                            } else {
                                                {
                                                    DecisionTreeResult res = { 20.0000f, 80.0000f, 0.20000f, 0.80000f, true };
                                                    return res; /* Class 0: 20.00%, Class 1: 80.00% (tau=0.31) */
                                                }
                                            }
                                        }
                                    } else {
                                        {
                                            DecisionTreeResult res = { 0.0000f, 100.0000f, 0.00000f, 1.00000f, true };
                                            return res; /* Class 0: 0.00%, Class 1: 100.00% (tau=0.31) */
                                        }
                                    }
                                } else {
                                    {
                                        DecisionTreeResult res = { 22.7273f, 77.2727f, 0.22727f, 0.77273f, true };
                                        return res; /* Class 0: 22.73%, Class 1: 77.27% (tau=0.31) */
                                    }
                                }
                            } else {
                                if (features[12] /* Feature_Rate_Pressure_Product_mean */ <= 0.55374f) {
                                    if (features[26] /* FIO2_std */ <= -0.19998f) {
                                        if (features[49] /* Feature_Modified_Shock_Index_min */ <= -1.35952f) {
                                            {
                                                DecisionTreeResult res = { 20.0000f, 80.0000f, 0.20000f, 0.80000f, true };
                                                return res; /* Class 0: 20.00%, Class 1: 80.00% (tau=0.31) */
                                            }
                                        } else {
                                            if (features[55] /* Feature_MBP_Std_60s_min */ <= -0.28558f) {
                                                {
                                                    DecisionTreeResult res = { 55.5556f, 44.4444f, 0.55556f, 0.44444f, true };
                                                    return res; /* Class 0: 55.56%, Class 1: 44.44% (tau=0.31) */
                                                }
                                            } else {
                                                if (features[15] /* Feature_HR_Delta_60s_mean */ <= 1.02246f) {
                                                    {
                                                        DecisionTreeResult res = { 98.4314f, 1.5686f, 0.98431f, 0.01569f, false };
                                                        return res; /* Class 0: 98.43%, Class 1: 1.57% (tau=0.31) */
                                                    }
                                                } else {
                                                    {
                                                        DecisionTreeResult res = { 85.4167f, 14.5833f, 0.85417f, 0.14583f, false };
                                                        return res; /* Class 0: 85.42%, Class 1: 14.58% (tau=0.31) */
                                                    }
                                                }
                                            }
                                        }
                                    } else {
                                        if (features[92] /* Feature_MBP_Mean_60s_slope */ <= -0.88450f) {
                                            {
                                                DecisionTreeResult res = { 44.8276f, 55.1724f, 0.44828f, 0.55172f, true };
                                                return res; /* Class 0: 44.83%, Class 1: 55.17% (tau=0.31) */
                                            }
                                        } else {
                                            if (features[86] /* Feature_Shock_Index_slope */ <= -1.84747f) {
                                                {
                                                    DecisionTreeResult res = { 37.5000f, 62.5000f, 0.37500f, 0.62500f, true };
                                                    return res; /* Class 0: 37.50%, Class 1: 62.50% (tau=0.31) */
                                                }
                                            } else {
                                                if (features[28] /* Feature_Pulse_Pressure_std */ <= 2.43012f) {
                                                    {
                                                        DecisionTreeResult res = { 88.7574f, 11.2426f, 0.88757f, 0.11243f, false };
                                                        return res; /* Class 0: 88.76%, Class 1: 11.24% (tau=0.31) */
                                                    }
                                                } else {
                                                    {
                                                        DecisionTreeResult res = { 50.0000f, 50.0000f, 0.50000f, 0.50000f, true };
                                                        return res; /* Class 0: 50.00%, Class 1: 50.00% (tau=0.31) */
                                                    }
                                                }
                                            }
                                        }
                                    }
                                } else {
                                    if (features[10] /* Feature_Shock_Index_mean */ <= -0.11503f) {
                                        {
                                            DecisionTreeResult res = { 88.8889f, 11.1111f, 0.88889f, 0.11111f, false };
                                            return res; /* Class 0: 88.89%, Class 1: 11.11% (tau=0.31) */
                                        }
                                    } else {
                                        {
                                            DecisionTreeResult res = { 48.6486f, 51.3514f, 0.48649f, 0.51351f, true };
                                            return res; /* Class 0: 48.65%, Class 1: 51.35% (tau=0.31) */
                                        }
                                    }
                                }
                            }
                        } else {
                            if (features[64] /* FIO2_max */ <= 1.45880f) {
                                if (features[89] /* Feature_HR_Mean_60s_slope */ <= 1.98734f) {
                                    if (features[14] /* Feature_HR_Std_60s_mean */ <= 4.57104f) {
                                        if (features[19] /* HR_std */ <= 2.05422f) {
                                            {
                                                DecisionTreeResult res = { 66.6667f, 33.3333f, 0.66667f, 0.33333f, true };
                                                return res; /* Class 0: 66.67%, Class 1: 33.33% (tau=0.31) */
                                            }
                                        } else {
                                            {
                                                DecisionTreeResult res = { 29.5455f, 70.4545f, 0.29545f, 0.70455f, true };
                                                return res; /* Class 0: 29.55%, Class 1: 70.45% (tau=0.31) */
                                            }
                                        }
                                    } else {
                                        {
                                            DecisionTreeResult res = { 90.9091f, 9.0909f, 0.90909f, 0.09091f, false };
                                            return res; /* Class 0: 90.91%, Class 1: 9.09% (tau=0.31) */
                                        }
                                    }
                                } else {
                                    {
                                        DecisionTreeResult res = { 9.0909f, 90.9091f, 0.09091f, 0.90909f, true };
                                        return res; /* Class 0: 9.09%, Class 1: 90.91% (tau=0.31) */
                                    }
                                }
                            } else {
                                {
                                    DecisionTreeResult res = { 82.3529f, 17.6471f, 0.82353f, 0.17647f, false };
                                    return res; /* Class 0: 82.35%, Class 1: 17.65% (tau=0.31) */
                                }
                            }
                        }
                    } else {
                        if (features[13] /* Feature_HR_Mean_60s_mean */ <= 0.64560f) {
                            if (features[14] /* Feature_HR_Std_60s_mean */ <= 4.54151f) {
                                if (features[64] /* FIO2_max */ <= -0.61031f) {
                                    if (features[65] /* BT_max */ <= 0.27366f) {
                                        if (features[78] /* ART_DBP_slope */ <= 0.81821f) {
                                            if (features[91] /* Feature_HR_Delta_60s_slope */ <= 4.70432f) {
                                                if (features[77] /* ART_SBP_slope */ <= 0.39489f) {
                                                    {
                                                        DecisionTreeResult res = { 98.5915f, 1.4085f, 0.98592f, 0.01408f, false };
                                                        return res; /* Class 0: 98.59%, Class 1: 1.41% (tau=0.31) */
                                                    }
                                                } else {
                                                    {
                                                        DecisionTreeResult res = { 86.6667f, 13.3333f, 0.86667f, 0.13333f, false };
                                                        return res; /* Class 0: 86.67%, Class 1: 13.33% (tau=0.31) */
                                                    }
                                                }
                                            } else {
                                                {
                                                    DecisionTreeResult res = { 71.4286f, 28.5714f, 0.71429f, 0.28571f, false };
                                                    return res; /* Class 0: 71.43%, Class 1: 28.57% (tau=0.31) */
                                                }
                                            }
                                        } else {
                                            {
                                                DecisionTreeResult res = { 40.0000f, 60.0000f, 0.40000f, 0.60000f, true };
                                                return res; /* Class 0: 40.00%, Class 1: 60.00% (tau=0.31) */
                                            }
                                        }
                                    } else {
                                        if (features[34] /* Feature_HR_Delta_60s_std */ <= 3.07076f) {
                                            if (features[13] /* Feature_HR_Mean_60s_mean */ <= -0.21994f) {
                                                {
                                                    DecisionTreeResult res = { 70.0000f, 30.0000f, 0.70000f, 0.30000f, false };
                                                    return res; /* Class 0: 70.00%, Class 1: 30.00% (tau=0.31) */
                                                }
                                            } else {
                                                {
                                                    DecisionTreeResult res = { 97.1429f, 2.8571f, 0.97143f, 0.02857f, false };
                                                    return res; /* Class 0: 97.14%, Class 1: 2.86% (tau=0.31) */
                                                }
                                            }
                                        } else {
                                            {
                                                DecisionTreeResult res = { 50.0000f, 50.0000f, 0.50000f, 0.50000f, true };
                                                return res; /* Class 0: 50.00%, Class 1: 50.00% (tau=0.31) */
                                            }
                                        }
                                    }
                                } else {
                                    if (features[67] /* Feature_Shock_Index_max */ <= -0.07194f) {
                                        if (features[37] /* Feature_MBP_Delta_60s_std */ <= -0.51445f) {
                                            {
                                                DecisionTreeResult res = { 59.3750f, 40.6250f, 0.59375f, 0.40625f, true };
                                                return res; /* Class 0: 59.38%, Class 1: 40.62% (tau=0.31) */
                                            }
                                        } else {
                                            if (features[24] /* RR_CO2_std */ <= 1.51756f) {
                                                if (features[35] /* Feature_MBP_Mean_60s_std */ <= -0.70651f) {
                                                    {
                                                        DecisionTreeResult res = { 60.0000f, 40.0000f, 0.60000f, 0.40000f, true };
                                                        return res; /* Class 0: 60.00%, Class 1: 40.00% (tau=0.31) */
                                                    }
                                                } else {
                                                    {
                                                        DecisionTreeResult res = { 98.0583f, 1.9417f, 0.98058f, 0.01942f, false };
                                                        return res; /* Class 0: 98.06%, Class 1: 1.94% (tau=0.31) */
                                                    }
                                                }
                                            } else {
                                                {
                                                    DecisionTreeResult res = { 50.0000f, 50.0000f, 0.50000f, 0.50000f, true };
                                                    return res; /* Class 0: 50.00%, Class 1: 50.00% (tau=0.31) */
                                                }
                                            }
                                        }
                                    } else {
                                        if (features[61] /* PLETH_SPO2_max */ <= -1.88715f) {
                                            if (features[56] /* Feature_MBP_Delta_60s_min */ <= -1.53304f) {
                                                {
                                                    DecisionTreeResult res = { 69.2308f, 30.7692f, 0.69231f, 0.30769f, false };
                                                    return res; /* Class 0: 69.23%, Class 1: 30.77% (tau=0.31) */
                                                }
                                            } else {
                                                {
                                                    DecisionTreeResult res = { 18.9189f, 81.0811f, 0.18919f, 0.81081f, true };
                                                    return res; /* Class 0: 18.92%, Class 1: 81.08% (tau=0.31) */
                                                }
                                            }
                                        } else {
                                            if (features[59] /* ART_DBP_max */ <= -0.35835f) {
                                                {
                                                    DecisionTreeResult res = { 31.9149f, 68.0851f, 0.31915f, 0.68085f, true };
                                                    return res; /* Class 0: 31.91%, Class 1: 68.09% (tau=0.31) */
                                                }
                                            } else {
                                                if (features[89] /* Feature_HR_Mean_60s_slope */ <= 1.53935f) {
                                                    {
                                                        DecisionTreeResult res = { 72.3834f, 27.6166f, 0.72383f, 0.27617f, false };
                                                        return res; /* Class 0: 72.38%, Class 1: 27.62% (tau=0.31) */
                                                    }
                                                } else {
                                                    {
                                                        DecisionTreeResult res = { 46.8421f, 53.1579f, 0.46842f, 0.53158f, true };
                                                        return res; /* Class 0: 46.84%, Class 1: 53.16% (tau=0.31) */
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            } else {
                                if (features[68] /* Feature_Modified_Shock_Index_max */ <= 0.48425f) {
                                    if (features[40] /* ART_DBP_min */ <= 0.21343f) {
                                        {
                                            DecisionTreeResult res = { 26.9231f, 73.0769f, 0.26923f, 0.73077f, true };
                                            return res; /* Class 0: 26.92%, Class 1: 73.08% (tau=0.31) */
                                        }
                                    } else {
                                        if (features[72] /* Feature_HR_Delta_60s_max */ <= 4.45784f) {
                                            if (features[39] /* ART_SBP_min */ <= 1.82894f) {
                                                if (features[49] /* Feature_Modified_Shock_Index_min */ <= -0.20428f) {
                                                    {
                                                        DecisionTreeResult res = { 84.9057f, 15.0943f, 0.84906f, 0.15094f, false };
                                                        return res; /* Class 0: 84.91%, Class 1: 15.09% (tau=0.31) */
                                                    }
                                                } else {
                                                    {
                                                        DecisionTreeResult res = { 0.0000f, 100.0000f, 0.00000f, 1.00000f, true };
                                                        return res; /* Class 0: 0.00%, Class 1: 100.00% (tau=0.31) */
                                                    }
                                                }
                                            } else {
                                                {
                                                    DecisionTreeResult res = { 10.0000f, 90.0000f, 0.10000f, 0.90000f, true };
                                                    return res; /* Class 0: 10.00%, Class 1: 90.00% (tau=0.31) */
                                                }
                                            }
                                        } else {
                                            {
                                                DecisionTreeResult res = { 6.2500f, 93.7500f, 0.06250f, 0.93750f, true };
                                                return res; /* Class 0: 6.25%, Class 1: 93.75% (tau=0.31) */
                                            }
                                        }
                                    }
                                } else {
                                    if (features[64] /* FIO2_max */ <= -0.25434f) {
                                        {
                                            DecisionTreeResult res = { 81.2500f, 18.7500f, 0.81250f, 0.18750f, false };
                                            return res; /* Class 0: 81.25%, Class 1: 18.75% (tau=0.31) */
                                        }
                                    } else {
                                        if (features[40] /* ART_DBP_min */ <= 1.01290f) {
                                            if (features[73] /* Feature_MBP_Mean_60s_max */ <= -0.22220f) {
                                                {
                                                    DecisionTreeResult res = { 71.4286f, 28.5714f, 0.71429f, 0.28571f, false };
                                                    return res; /* Class 0: 71.43%, Class 1: 28.57% (tau=0.31) */
                                                }
                                            } else {
                                                if (features[30] /* Feature_Modified_Shock_Index_std */ <= 0.41062f) {
                                                    {
                                                        DecisionTreeResult res = { 80.0000f, 20.0000f, 0.80000f, 0.20000f, false };
                                                        return res; /* Class 0: 80.00%, Class 1: 20.00% (tau=0.31) */
                                                    }
                                                } else {
                                                    {
                                                        DecisionTreeResult res = { 4.9180f, 95.0820f, 0.04918f, 0.95082f, true };
                                                        return res; /* Class 0: 4.92%, Class 1: 95.08% (tau=0.31) */
                                                    }
                                                }
                                            }
                                        } else {
                                            {
                                                DecisionTreeResult res = { 64.2857f, 35.7143f, 0.64286f, 0.35714f, true };
                                                return res; /* Class 0: 64.29%, Class 1: 35.71% (tau=0.31) */
                                            }
                                        }
                                    }
                                }
                            }
                        } else {
                            if (features[8] /* BT_mean */ <= -0.19121f) {
                                {
                                    DecisionTreeResult res = { 76.1905f, 23.8095f, 0.76190f, 0.23810f, false };
                                    return res; /* Class 0: 76.19%, Class 1: 23.81% (tau=0.31) */
                                }
                            } else {
                                if (features[23] /* PLETH_SPO2_std */ <= 0.86695f) {
                                    if (features[72] /* Feature_HR_Delta_60s_max */ <= 1.94581f) {
                                        if (features[54] /* Feature_MBP_Mean_60s_min */ <= 0.55317f) {
                                            if (features[49] /* Feature_Modified_Shock_Index_min */ <= -0.15565f) {
                                                {
                                                    DecisionTreeResult res = { 72.0000f, 28.0000f, 0.72000f, 0.28000f, false };
                                                    return res; /* Class 0: 72.00%, Class 1: 28.00% (tau=0.31) */
                                                }
                                            } else {
                                                {
                                                    DecisionTreeResult res = { 30.5556f, 69.4444f, 0.30556f, 0.69444f, true };
                                                    return res; /* Class 0: 30.56%, Class 1: 69.44% (tau=0.31) */
                                                }
                                            }
                                        } else {
                                            if (features[36] /* Feature_MBP_Std_60s_std */ <= 2.14777f) {
                                                {
                                                    DecisionTreeResult res = { 91.1111f, 8.8889f, 0.91111f, 0.08889f, false };
                                                    return res; /* Class 0: 91.11%, Class 1: 8.89% (tau=0.31) */
                                                }
                                            } else {
                                                {
                                                    DecisionTreeResult res = { 20.0000f, 80.0000f, 0.20000f, 0.80000f, true };
                                                    return res; /* Class 0: 20.00%, Class 1: 80.00% (tau=0.31) */
                                                }
                                            }
                                        }
                                    } else {
                                        if (features[82] /* ETCO2_slope */ <= -0.43067f) {
                                            {
                                                DecisionTreeResult res = { 60.4167f, 39.5833f, 0.60417f, 0.39583f, true };
                                                return res; /* Class 0: 60.42%, Class 1: 39.58% (tau=0.31) */
                                            }
                                        } else {
                                            if (features[44] /* ETCO2_min */ <= -1.76231f) {
                                                {
                                                    DecisionTreeResult res = { 71.4286f, 28.5714f, 0.71429f, 0.28571f, false };
                                                    return res; /* Class 0: 71.43%, Class 1: 28.57% (tau=0.31) */
                                                }
                                            } else {
                                                if (features[76] /* HR_slope */ <= -2.18474f) {
                                                    {
                                                        DecisionTreeResult res = { 52.7778f, 47.2222f, 0.52778f, 0.47222f, true };
                                                        return res; /* Class 0: 52.78%, Class 1: 47.22% (tau=0.31) */
                                                    }
                                                } else {
                                                    {
                                                        DecisionTreeResult res = { 22.8571f, 77.1429f, 0.22857f, 0.77143f, true };
                                                        return res; /* Class 0: 22.86%, Class 1: 77.14% (tau=0.31) */
                                                    }
                                                }
                                            }
                                        }
                                    }
                                } else {
                                    if (features[57] /* HR_max */ <= 1.91599f) {
                                        {
                                            DecisionTreeResult res = { 55.5556f, 44.4444f, 0.55556f, 0.44444f, true };
                                            return res; /* Class 0: 55.56%, Class 1: 44.44% (tau=0.31) */
                                        }
                                    } else {
                                        if (features[48] /* Feature_Shock_Index_min */ <= 0.24761f) {
                                            if (features[22] /* ART_MBP_std */ <= -0.29475f) {
                                                {
                                                    DecisionTreeResult res = { 0.0000f, 100.0000f, 0.00000f, 1.00000f, true };
                                                    return res; /* Class 0: 0.00%, Class 1: 100.00% (tau=0.31) */
                                                }
                                            } else {
                                                {
                                                    DecisionTreeResult res = { 25.0000f, 75.0000f, 0.25000f, 0.75000f, true };
                                                    return res; /* Class 0: 25.00%, Class 1: 75.00% (tau=0.31) */
                                                }
                                            }
                                        } else {
                                            {
                                                DecisionTreeResult res = { 66.6667f, 33.3333f, 0.66667f, 0.33333f, true };
                                                return res; /* Class 0: 66.67%, Class 1: 33.33% (tau=0.31) */
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                } else {
                    if (features[42] /* PLETH_SPO2_min */ <= 0.33752f) {
                        if (features[44] /* ETCO2_min */ <= 1.11662f) {
                            if (features[46] /* BT_min */ <= -0.96697f) {
                                {
                                    DecisionTreeResult res = { 88.8889f, 11.1111f, 0.88889f, 0.11111f, false };
                                    return res; /* Class 0: 88.89%, Class 1: 11.11% (tau=0.31) */
                                }
                            } else {
                                if (features[37] /* Feature_MBP_Delta_60s_std */ <= -0.31752f) {
                                    {
                                        DecisionTreeResult res = { 0.0000f, 100.0000f, 0.00000f, 1.00000f, true };
                                        return res; /* Class 0: 0.00%, Class 1: 100.00% (tau=0.31) */
                                    }
                                } else {
                                    if (features[9] /* Feature_Pulse_Pressure_mean */ <= -0.08176f) {
                                        {
                                            DecisionTreeResult res = { 38.4615f, 61.5385f, 0.38462f, 0.61538f, true };
                                            return res; /* Class 0: 38.46%, Class 1: 61.54% (tau=0.31) */
                                        }
                                    } else {
                                        {
                                            DecisionTreeResult res = { 8.1633f, 91.8367f, 0.08163f, 0.91837f, true };
                                            return res; /* Class 0: 8.16%, Class 1: 91.84% (tau=0.31) */
                                        }
                                    }
                                }
                            }
                        } else {
                            {
                                DecisionTreeResult res = { 72.7273f, 27.2727f, 0.72727f, 0.27273f, false };
                                return res; /* Class 0: 72.73%, Class 1: 27.27% (tau=0.31) */
                            }
                        }
                    } else {
                        if (features[26] /* FIO2_std */ <= 0.42899f) {
                            if (features[67] /* Feature_Shock_Index_max */ <= 0.63007f) {
                                if (features[88] /* Feature_Rate_Pressure_Product_slope */ <= 0.54319f) {
                                    {
                                        DecisionTreeResult res = { 88.6364f, 11.3636f, 0.88636f, 0.11364f, false };
                                        return res; /* Class 0: 88.64%, Class 1: 11.36% (tau=0.31) */
                                    }
                                } else {
                                    {
                                        DecisionTreeResult res = { 0.0000f, 100.0000f, 0.00000f, 1.00000f, true };
                                        return res; /* Class 0: 0.00%, Class 1: 100.00% (tau=0.31) */
                                    }
                                }
                            } else {
                                {
                                    DecisionTreeResult res = { 6.2500f, 93.7500f, 0.06250f, 0.93750f, true };
                                    return res; /* Class 0: 6.25%, Class 1: 93.75% (tau=0.31) */
                                }
                            }
                        } else {
                            {
                                DecisionTreeResult res = { 0.0000f, 100.0000f, 0.00000f, 1.00000f, true };
                                return res; /* Class 0: 0.00%, Class 1: 100.00% (tau=0.31) */
                            }
                        }
                    }
                }
            } else {
                if (features[13] /* Feature_HR_Mean_60s_mean */ <= 0.97998f) {
                    if (features[70] /* Feature_HR_Mean_60s_max */ <= 0.65991f) {
                        if (features[46] /* BT_min */ <= 0.18445f) {
                            if (features[57] /* HR_max */ <= 4.76638f) {
                                if (features[25] /* ETCO2_std */ <= -0.48483f) {
                                    {
                                        DecisionTreeResult res = { 42.8571f, 57.1429f, 0.42857f, 0.57143f, true };
                                        return res; /* Class 0: 42.86%, Class 1: 57.14% (tau=0.31) */
                                    }
                                } else {
                                    if (features[66] /* Feature_Pulse_Pressure_max */ <= 0.22711f) {
                                        if (features[12] /* Feature_Rate_Pressure_Product_mean */ <= 0.12729f) {
                                            if (features[21] /* ART_DBP_std */ <= -0.04616f) {
                                                if (features[82] /* ETCO2_slope */ <= 0.91756f) {
                                                    {
                                                        DecisionTreeResult res = { 97.0149f, 2.9851f, 0.97015f, 0.02985f, false };
                                                        return res; /* Class 0: 97.01%, Class 1: 2.99% (tau=0.31) */
                                                    }
                                                } else {
                                                    {
                                                        DecisionTreeResult res = { 80.0000f, 20.0000f, 0.80000f, 0.20000f, false };
                                                        return res; /* Class 0: 80.00%, Class 1: 20.00% (tau=0.31) */
                                                    }
                                                }
                                            } else {
                                                {
                                                    DecisionTreeResult res = { 47.8261f, 52.1739f, 0.47826f, 0.52174f, true };
                                                    return res; /* Class 0: 47.83%, Class 1: 52.17% (tau=0.31) */
                                                }
                                            }
                                        } else {
                                            {
                                                DecisionTreeResult res = { 0.0000f, 100.0000f, 0.00000f, 1.00000f, true };
                                                return res; /* Class 0: 0.00%, Class 1: 100.00% (tau=0.31) */
                                            }
                                        }
                                    } else {
                                        if (features[72] /* Feature_HR_Delta_60s_max */ <= 2.96077f) {
                                            if (features[87] /* Feature_Modified_Shock_Index_slope */ <= -5.46745f) {
                                                {
                                                    DecisionTreeResult res = { 80.0000f, 20.0000f, 0.80000f, 0.20000f, false };
                                                    return res; /* Class 0: 80.00%, Class 1: 20.00% (tau=0.31) */
                                                }
                                            } else {
                                                {
                                                    DecisionTreeResult res = { 100.0000f, 0.0000f, 1.00000f, 0.00000f, false };
                                                    return res; /* Class 0: 100.00%, Class 1: 0.00% (tau=0.31) */
                                                }
                                            }
                                        } else {
                                            if (features[7] /* FIO2_mean */ <= 1.39625f) {
                                                {
                                                    DecisionTreeResult res = { 97.1429f, 2.8571f, 0.97143f, 0.02857f, false };
                                                    return res; /* Class 0: 97.14%, Class 1: 2.86% (tau=0.31) */
                                                }
                                            } else {
                                                {
                                                    DecisionTreeResult res = { 62.5000f, 37.5000f, 0.62500f, 0.37500f, true };
                                                    return res; /* Class 0: 62.50%, Class 1: 37.50% (tau=0.31) */
                                                }
                                            }
                                        }
                                    }
                                }
                            } else {
                                {
                                    DecisionTreeResult res = { 33.3333f, 66.6667f, 0.33333f, 0.66667f, true };
                                    return res; /* Class 0: 33.33%, Class 1: 66.67% (tau=0.31) */
                                }
                            }
                        } else {
                            if (features[40] /* ART_DBP_min */ <= -1.71635f) {
                                if (features[32] /* Feature_HR_Mean_60s_std */ <= 3.11182f) {
                                    if (features[58] /* ART_SBP_max */ <= 0.80102f) {
                                        if (features[36] /* Feature_MBP_Std_60s_std */ <= 0.46935f) {
                                            {
                                                DecisionTreeResult res = { 100.0000f, 0.0000f, 1.00000f, 0.00000f, false };
                                                return res; /* Class 0: 100.00%, Class 1: 0.00% (tau=0.31) */
                                            }
                                        } else {
                                            {
                                                DecisionTreeResult res = { 80.0000f, 20.0000f, 0.80000f, 0.20000f, false };
                                                return res; /* Class 0: 80.00%, Class 1: 20.00% (tau=0.31) */
                                            }
                                        }
                                    } else {
                                        {
                                            DecisionTreeResult res = { 60.0000f, 40.0000f, 0.60000f, 0.40000f, true };
                                            return res; /* Class 0: 60.00%, Class 1: 40.00% (tau=0.31) */
                                        }
                                    }
                                } else {
                                    {
                                        DecisionTreeResult res = { 50.0000f, 50.0000f, 0.50000f, 0.50000f, true };
                                        return res; /* Class 0: 50.00%, Class 1: 50.00% (tau=0.31) */
                                    }
                                }
                            } else {
                                if (features[66] /* Feature_Pulse_Pressure_max */ <= 0.21266f) {
                                    if (features[85] /* Feature_Pulse_Pressure_slope */ <= -0.01538f) {
                                        if (features[10] /* Feature_Shock_Index_mean */ <= -0.19768f) {
                                            if (features[53] /* Feature_HR_Delta_60s_min */ <= -2.72761f) {
                                                if (features[28] /* Feature_Pulse_Pressure_std */ <= 0.05852f) {
                                                    {
                                                        DecisionTreeResult res = { 96.0000f, 4.0000f, 0.96000f, 0.04000f, false };
                                                        return res; /* Class 0: 96.00%, Class 1: 4.00% (tau=0.31) */
                                                    }
                                                } else {
                                                    {
                                                        DecisionTreeResult res = { 75.0000f, 25.0000f, 0.75000f, 0.25000f, false };
                                                        return res; /* Class 0: 75.00%, Class 1: 25.00% (tau=0.31) */
                                                    }
                                                }
                                            } else {
                                                {
                                                    DecisionTreeResult res = { 50.0000f, 50.0000f, 0.50000f, 0.50000f, true };
                                                    return res; /* Class 0: 50.00%, Class 1: 50.00% (tau=0.31) */
                                                }
                                            }
                                        } else {
                                            if (features[72] /* Feature_HR_Delta_60s_max */ <= 3.87424f) {
                                                if (features[32] /* Feature_HR_Mean_60s_std */ <= 1.15482f) {
                                                    {
                                                        DecisionTreeResult res = { 66.2162f, 33.7838f, 0.66216f, 0.33784f, true };
                                                        return res; /* Class 0: 66.22%, Class 1: 33.78% (tau=0.31) */
                                                    }
                                                } else {
                                                    {
                                                        DecisionTreeResult res = { 95.1220f, 4.8780f, 0.95122f, 0.04878f, false };
                                                        return res; /* Class 0: 95.12%, Class 1: 4.88% (tau=0.31) */
                                                    }
                                                }
                                            } else {
                                                {
                                                    DecisionTreeResult res = { 23.0769f, 76.9231f, 0.23077f, 0.76923f, true };
                                                    return res; /* Class 0: 23.08%, Class 1: 76.92% (tau=0.31) */
                                                }
                                            }
                                        }
                                    } else {
                                        if (features[55] /* Feature_MBP_Std_60s_min */ <= 0.08274f) {
                                            if (features[74] /* Feature_MBP_Std_60s_max */ <= -0.47016f) {
                                                if (features[13] /* Feature_HR_Mean_60s_mean */ <= -0.12373f) {
                                                    {
                                                        DecisionTreeResult res = { 47.6923f, 52.3077f, 0.47692f, 0.52308f, true };
                                                        return res; /* Class 0: 47.69%, Class 1: 52.31% (tau=0.31) */
                                                    }
                                                } else {
                                                    {
                                                        DecisionTreeResult res = { 0.0000f, 100.0000f, 0.00000f, 1.00000f, true };
                                                        return res; /* Class 0: 0.00%, Class 1: 100.00% (tau=0.31) */
                                                    }
                                                }
                                            } else {
                                                if (features[29] /* Feature_Shock_Index_std */ <= 0.95703f) {
                                                    {
                                                        DecisionTreeResult res = { 72.4138f, 27.5862f, 0.72414f, 0.27586f, false };
                                                        return res; /* Class 0: 72.41%, Class 1: 27.59% (tau=0.31) */
                                                    }
                                                } else {
                                                    {
                                                        DecisionTreeResult res = { 35.0000f, 65.0000f, 0.35000f, 0.65000f, true };
                                                        return res; /* Class 0: 35.00%, Class 1: 65.00% (tau=0.31) */
                                                    }
                                                }
                                            }
                                        } else {
                                            if (features[75] /* Feature_MBP_Delta_60s_max */ <= -0.40548f) {
                                                {
                                                    DecisionTreeResult res = { 78.9474f, 21.0526f, 0.78947f, 0.21053f, false };
                                                    return res; /* Class 0: 78.95%, Class 1: 21.05% (tau=0.31) */
                                                }
                                            } else {
                                                {
                                                    DecisionTreeResult res = { 97.2222f, 2.7778f, 0.97222f, 0.02778f, false };
                                                    return res; /* Class 0: 97.22%, Class 1: 2.78% (tau=0.31) */
                                                }
                                            }
                                        }
                                    }
                                } else {
                                    if (features[14] /* Feature_HR_Std_60s_mean */ <= 3.80881f) {
                                        if (features[2] /* ART_DBP_mean */ <= 0.77524f) {
                                            if (features[1] /* ART_SBP_mean */ <= -0.40549f) {
                                                {
                                                    DecisionTreeResult res = { 8.3333f, 91.6667f, 0.08333f, 0.91667f, true };
                                                    return res; /* Class 0: 8.33%, Class 1: 91.67% (tau=0.31) */
                                                }
                                            } else {
                                                if (features[53] /* Feature_HR_Delta_60s_min */ <= -3.52817f) {
                                                    {
                                                        DecisionTreeResult res = { 88.3721f, 11.6279f, 0.88372f, 0.11628f, false };
                                                        return res; /* Class 0: 88.37%, Class 1: 11.63% (tau=0.31) */
                                                    }
                                                } else {
                                                    {
                                                        DecisionTreeResult res = { 45.4545f, 54.5455f, 0.45455f, 0.54545f, true };
                                                        return res; /* Class 0: 45.45%, Class 1: 54.55% (tau=0.31) */
                                                    }
                                                }
                                            }
                                        } else {
                                            {
                                                DecisionTreeResult res = { 0.0000f, 100.0000f, 0.00000f, 1.00000f, true };
                                                return res; /* Class 0: 0.00%, Class 1: 100.00% (tau=0.31) */
                                            }
                                        }
                                    } else {
                                        if (features[33] /* Feature_HR_Std_60s_std */ <= 3.52496f) {
                                            {
                                                DecisionTreeResult res = { 5.2632f, 94.7368f, 0.05263f, 0.94737f, true };
                                                return res; /* Class 0: 5.26%, Class 1: 94.74% (tau=0.31) */
                                            }
                                        } else {
                                            {
                                                DecisionTreeResult res = { 40.9091f, 59.0909f, 0.40909f, 0.59091f, true };
                                                return res; /* Class 0: 40.91%, Class 1: 59.09% (tau=0.31) */
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    } else {
                        if (features[15] /* Feature_HR_Delta_60s_mean */ <= 1.53432f) {
                            if (features[76] /* HR_slope */ <= 2.25052f) {
                                if (features[58] /* ART_SBP_max */ <= 2.62270f) {
                                    if (features[68] /* Feature_Modified_Shock_Index_max */ <= 2.20979f) {
                                        if (features[5] /* RR_CO2_mean */ <= 0.28762f) {
                                            if (features[50] /* Feature_Rate_Pressure_Product_min */ <= 0.05932f) {
                                                if (features[44] /* ETCO2_min */ <= 0.58100f) {
                                                    {
                                                        DecisionTreeResult res = { 59.1274f, 40.8726f, 0.59127f, 0.40873f, true };
                                                        return res; /* Class 0: 59.13%, Class 1: 40.87% (tau=0.31) */
                                                    }
                                                } else {
                                                    {
                                                        DecisionTreeResult res = { 78.6260f, 21.3740f, 0.78626f, 0.21374f, false };
                                                        return res; /* Class 0: 78.63%, Class 1: 21.37% (tau=0.31) */
                                                    }
                                                }
                                            } else {
                                                if (features[59] /* ART_DBP_max */ <= -0.39988f) {
                                                    {
                                                        DecisionTreeResult res = { 12.7273f, 87.2727f, 0.12727f, 0.87273f, true };
                                                        return res; /* Class 0: 12.73%, Class 1: 87.27% (tau=0.31) */
                                                    }
                                                } else {
                                                    {
                                                        DecisionTreeResult res = { 57.4924f, 42.5076f, 0.57492f, 0.42508f, true };
                                                        return res; /* Class 0: 57.49%, Class 1: 42.51% (tau=0.31) */
                                                    }
                                                }
                                            }
                                        } else {
                                            if (features[59] /* ART_DBP_max */ <= 0.14010f) {
                                                if (features[13] /* Feature_HR_Mean_60s_mean */ <= -0.36510f) {
                                                    {
                                                        DecisionTreeResult res = { 82.9545f, 17.0455f, 0.82955f, 0.17045f, false };
                                                        return res; /* Class 0: 82.95%, Class 1: 17.05% (tau=0.31) */
                                                    }
                                                } else {
                                                    {
                                                        DecisionTreeResult res = { 61.2546f, 38.7454f, 0.61255f, 0.38745f, true };
                                                        return res; /* Class 0: 61.25%, Class 1: 38.75% (tau=0.31) */
                                                    }
                                                }
                                            } else {
                                                if (features[9] /* Feature_Pulse_Pressure_mean */ <= 0.65468f) {
                                                    {
                                                        DecisionTreeResult res = { 74.4828f, 25.5172f, 0.74483f, 0.25517f, false };
                                                        return res; /* Class 0: 74.48%, Class 1: 25.52% (tau=0.31) */
                                                    }
                                                } else {
                                                    {
                                                        DecisionTreeResult res = { 100.0000f, 0.0000f, 1.00000f, 0.00000f, false };
                                                        return res; /* Class 0: 100.00%, Class 1: 0.00% (tau=0.31) */
                                                    }
                                                }
                                            }
                                        }
                                    } else {
                                        if (features[28] /* Feature_Pulse_Pressure_std */ <= 0.55272f) {
                                            if (features[4] /* PLETH_SPO2_mean */ <= 0.33280f) {
                                                if (features[86] /* Feature_Shock_Index_slope */ <= -1.87662f) {
                                                    {
                                                        DecisionTreeResult res = { 46.1538f, 53.8462f, 0.46154f, 0.53846f, true };
                                                        return res; /* Class 0: 46.15%, Class 1: 53.85% (tau=0.31) */
                                                    }
                                                } else {
                                                    {
                                                        DecisionTreeResult res = { 11.2500f, 88.7500f, 0.11250f, 0.88750f, true };
                                                        return res; /* Class 0: 11.25%, Class 1: 88.75% (tau=0.31) */
                                                    }
                                                }
                                            } else {
                                                {
                                                    DecisionTreeResult res = { 47.6190f, 52.3810f, 0.47619f, 0.52381f, true };
                                                    return res; /* Class 0: 47.62%, Class 1: 52.38% (tau=0.31) */
                                                }
                                            }
                                        } else {
                                            if (features[57] /* HR_max */ <= 2.91964f) {
                                                {
                                                    DecisionTreeResult res = { 36.6667f, 63.3333f, 0.36667f, 0.63333f, true };
                                                    return res; /* Class 0: 36.67%, Class 1: 63.33% (tau=0.31) */
                                                }
                                            } else {
                                                {
                                                    DecisionTreeResult res = { 91.3043f, 8.6957f, 0.91304f, 0.08696f, false };
                                                    return res; /* Class 0: 91.30%, Class 1: 8.70% (tau=0.31) */
                                                }
                                            }
                                        }
                                    }
                                } else {
                                    {
                                        DecisionTreeResult res = { 22.5000f, 77.5000f, 0.22500f, 0.77500f, true };
                                        return res; /* Class 0: 22.50%, Class 1: 77.50% (tau=0.31) */
                                    }
                                }
                            } else {
                                if (features[51] /* Feature_HR_Mean_60s_min */ <= -1.24269f) {
                                    if (features[20] /* ART_SBP_std */ <= -0.59810f) {
                                        {
                                            DecisionTreeResult res = { 11.1111f, 88.8889f, 0.11111f, 0.88889f, true };
                                            return res; /* Class 0: 11.11%, Class 1: 88.89% (tau=0.31) */
                                        }
                                    } else {
                                        {
                                            DecisionTreeResult res = { 54.3478f, 45.6522f, 0.54348f, 0.45652f, true };
                                            return res; /* Class 0: 54.35%, Class 1: 45.65% (tau=0.31) */
                                        }
                                    }
                                } else {
                                    if (features[19] /* HR_std */ <= 3.54280f) {
                                        if (features[24] /* RR_CO2_std */ <= 0.28346f) {
                                            if (features[47] /* Feature_Pulse_Pressure_min */ <= -1.18758f) {
                                                {
                                                    DecisionTreeResult res = { 0.0000f, 100.0000f, 0.00000f, 1.00000f, true };
                                                    return res; /* Class 0: 0.00%, Class 1: 100.00% (tau=0.31) */
                                                }
                                            } else {
                                                if (features[94] /* Feature_MBP_Delta_60s_slope */ <= 0.28620f) {
                                                    {
                                                        DecisionTreeResult res = { 23.2558f, 76.7442f, 0.23256f, 0.76744f, true };
                                                        return res; /* Class 0: 23.26%, Class 1: 76.74% (tau=0.31) */
                                                    }
                                                } else {
                                                    {
                                                        DecisionTreeResult res = { 70.0000f, 30.0000f, 0.70000f, 0.30000f, false };
                                                        return res; /* Class 0: 70.00%, Class 1: 30.00% (tau=0.31) */
                                                    }
                                                }
                                            }
                                        } else {
                                            {
                                                DecisionTreeResult res = { 75.0000f, 25.0000f, 0.75000f, 0.25000f, false };
                                                return res; /* Class 0: 75.00%, Class 1: 25.00% (tau=0.31) */
                                            }
                                        }
                                    } else {
                                        if (features[74] /* Feature_MBP_Std_60s_max */ <= -0.58669f) {
                                            {
                                                DecisionTreeResult res = { 60.0000f, 40.0000f, 0.60000f, 0.40000f, true };
                                                return res; /* Class 0: 60.00%, Class 1: 40.00% (tau=0.31) */
                                            }
                                        } else {
                                            if (features[43] /* RR_CO2_min */ <= 0.45272f) {
                                                if (features[65] /* BT_max */ <= 0.25719f) {
                                                    {
                                                        DecisionTreeResult res = { 0.0000f, 100.0000f, 0.00000f, 1.00000f, true };
                                                        return res; /* Class 0: 0.00%, Class 1: 100.00% (tau=0.31) */
                                                    }
                                                } else {
                                                    {
                                                        DecisionTreeResult res = { 13.3333f, 86.6667f, 0.13333f, 0.86667f, true };
                                                        return res; /* Class 0: 13.33%, Class 1: 86.67% (tau=0.31) */
                                                    }
                                                }
                                            } else {
                                                {
                                                    DecisionTreeResult res = { 30.7692f, 69.2308f, 0.30769f, 0.69231f, true };
                                                    return res; /* Class 0: 30.77%, Class 1: 69.23% (tau=0.31) */
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        } else {
                            if (features[91] /* Feature_HR_Delta_60s_slope */ <= 0.63071f) {
                                if (features[38] /* HR_min */ <= -1.18406f) {
                                    if (features[27] /* BT_std */ <= -0.26910f) {
                                        {
                                            DecisionTreeResult res = { 19.0476f, 80.9524f, 0.19048f, 0.80952f, true };
                                            return res; /* Class 0: 19.05%, Class 1: 80.95% (tau=0.31) */
                                        }
                                    } else {
                                        if (features[39] /* ART_SBP_min */ <= -0.63999f) {
                                            {
                                                DecisionTreeResult res = { 18.1818f, 81.8182f, 0.18182f, 0.81818f, true };
                                                return res; /* Class 0: 18.18%, Class 1: 81.82% (tau=0.31) */
                                            }
                                        } else {
                                            if (features[56] /* Feature_MBP_Delta_60s_min */ <= 0.53911f) {
                                                if (features[44] /* ETCO2_min */ <= 0.58100f) {
                                                    {
                                                        DecisionTreeResult res = { 85.2459f, 14.7541f, 0.85246f, 0.14754f, false };
                                                        return res; /* Class 0: 85.25%, Class 1: 14.75% (tau=0.31) */
                                                    }
                                                } else {
                                                    {
                                                        DecisionTreeResult res = { 37.5000f, 62.5000f, 0.37500f, 0.62500f, true };
                                                        return res; /* Class 0: 37.50%, Class 1: 62.50% (tau=0.31) */
                                                    }
                                                }
                                            } else {
                                                {
                                                    DecisionTreeResult res = { 28.5714f, 71.4286f, 0.28571f, 0.71429f, true };
                                                    return res; /* Class 0: 28.57%, Class 1: 71.43% (tau=0.31) */
                                                }
                                            }
                                        }
                                    }
                                } else {
                                    if (features[65] /* BT_max */ <= 0.25719f) {
                                        if (features[29] /* Feature_Shock_Index_std */ <= 0.89488f) {
                                            if (features[12] /* Feature_Rate_Pressure_Product_mean */ <= 1.25072f) {
                                                {
                                                    DecisionTreeResult res = { 40.0000f, 60.0000f, 0.40000f, 0.60000f, true };
                                                    return res; /* Class 0: 40.00%, Class 1: 60.00% (tau=0.31) */
                                                }
                                            } else {
                                                {
                                                    DecisionTreeResult res = { 100.0000f, 0.0000f, 1.00000f, 0.00000f, false };
                                                    return res; /* Class 0: 100.00%, Class 1: 0.00% (tau=0.31) */
                                                }
                                            }
                                        } else {
                                            if (features[16] /* Feature_MBP_Mean_60s_mean */ <= 0.00499f) {
                                                if (features[93] /* Feature_MBP_Std_60s_slope */ <= 0.03832f) {
                                                    {
                                                        DecisionTreeResult res = { 15.2174f, 84.7826f, 0.15217f, 0.84783f, true };
                                                        return res; /* Class 0: 15.22%, Class 1: 84.78% (tau=0.31) */
                                                    }
                                                } else {
                                                    {
                                                        DecisionTreeResult res = { 44.4444f, 55.5556f, 0.44444f, 0.55556f, true };
                                                        return res; /* Class 0: 44.44%, Class 1: 55.56% (tau=0.31) */
                                                    }
                                                }
                                            } else {
                                                if (features[43] /* RR_CO2_min */ <= -0.33168f) {
                                                    {
                                                        DecisionTreeResult res = { 0.0000f, 100.0000f, 0.00000f, 1.00000f, true };
                                                        return res; /* Class 0: 0.00%, Class 1: 100.00% (tau=0.31) */
                                                    }
                                                } else {
                                                    {
                                                        DecisionTreeResult res = { 9.0909f, 90.9091f, 0.09091f, 0.90909f, true };
                                                        return res; /* Class 0: 9.09%, Class 1: 90.91% (tau=0.31) */
                                                    }
                                                }
                                            }
                                        }
                                    } else {
                                        if (features[11] /* Feature_Modified_Shock_Index_mean */ <= 0.64701f) {
                                            if (features[47] /* Feature_Pulse_Pressure_min */ <= -0.34545f) {
                                                {
                                                    DecisionTreeResult res = { 26.4706f, 73.5294f, 0.26471f, 0.73529f, true };
                                                    return res; /* Class 0: 26.47%, Class 1: 73.53% (tau=0.31) */
                                                }
                                            } else {
                                                if (features[19] /* HR_std */ <= 4.56957f) {
                                                    {
                                                        DecisionTreeResult res = { 63.7681f, 36.2319f, 0.63768f, 0.36232f, true };
                                                        return res; /* Class 0: 63.77%, Class 1: 36.23% (tau=0.31) */
                                                    }
                                                } else {
                                                    {
                                                        DecisionTreeResult res = { 37.5000f, 62.5000f, 0.37500f, 0.62500f, true };
                                                        return res; /* Class 0: 37.50%, Class 1: 62.50% (tau=0.31) */
                                                    }
                                                }
                                            }
                                        } else {
                                            {
                                                DecisionTreeResult res = { 0.0000f, 100.0000f, 0.00000f, 1.00000f, true };
                                                return res; /* Class 0: 0.00%, Class 1: 100.00% (tau=0.31) */
                                            }
                                        }
                                    }
                                }
                            } else {
                                if (features[0] /* HR_mean */ <= 0.30527f) {
                                    if (features[15] /* Feature_HR_Delta_60s_mean */ <= 2.24350f) {
                                        {
                                            DecisionTreeResult res = { 48.2759f, 51.7241f, 0.48276f, 0.51724f, true };
                                            return res; /* Class 0: 48.28%, Class 1: 51.72% (tau=0.31) */
                                        }
                                    } else {
                                        if (features[82] /* ETCO2_slope */ <= -0.20597f) {
                                            {
                                                DecisionTreeResult res = { 31.8182f, 68.1818f, 0.31818f, 0.68182f, true };
                                                return res; /* Class 0: 31.82%, Class 1: 68.18% (tau=0.31) */
                                            }
                                        } else {
                                            if (features[0] /* HR_mean */ <= -0.05043f) {
                                                {
                                                    DecisionTreeResult res = { 0.0000f, 100.0000f, 0.00000f, 1.00000f, true };
                                                    return res; /* Class 0: 0.00%, Class 1: 100.00% (tau=0.31) */
                                                }
                                            } else {
                                                {
                                                    DecisionTreeResult res = { 19.2308f, 80.7692f, 0.19231f, 0.80769f, true };
                                                    return res; /* Class 0: 19.23%, Class 1: 80.77% (tau=0.31) */
                                                }
                                            }
                                        }
                                    }
                                } else {
                                    if (features[87] /* Feature_Modified_Shock_Index_slope */ <= 1.40503f) {
                                        if (features[67] /* Feature_Shock_Index_max */ <= 0.99947f) {
                                            {
                                                DecisionTreeResult res = { 38.0952f, 61.9048f, 0.38095f, 0.61905f, true };
                                                return res; /* Class 0: 38.10%, Class 1: 61.90% (tau=0.31) */
                                            }
                                        } else {
                                            if (features[31] /* Feature_Rate_Pressure_Product_std */ <= 2.56831f) {
                                                {
                                                    DecisionTreeResult res = { 4.7619f, 95.2381f, 0.04762f, 0.95238f, true };
                                                    return res; /* Class 0: 4.76%, Class 1: 95.24% (tau=0.31) */
                                                }
                                            } else {
                                                {
                                                    DecisionTreeResult res = { 25.0000f, 75.0000f, 0.25000f, 0.75000f, true };
                                                    return res; /* Class 0: 25.00%, Class 1: 75.00% (tau=0.31) */
                                                }
                                            }
                                        }
                                    } else {
                                        if (features[74] /* Feature_MBP_Std_60s_max */ <= -0.57815f) {
                                            {
                                                DecisionTreeResult res = { 20.0000f, 80.0000f, 0.20000f, 0.80000f, true };
                                                return res; /* Class 0: 20.00%, Class 1: 80.00% (tau=0.31) */
                                            }
                                        } else {
                                            {
                                                DecisionTreeResult res = { 0.0000f, 100.0000f, 0.00000f, 1.00000f, true };
                                                return res; /* Class 0: 0.00%, Class 1: 100.00% (tau=0.31) */
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                } else {
                    if (features[10] /* Feature_Shock_Index_mean */ <= 0.82681f) {
                        if (features[12] /* Feature_Rate_Pressure_Product_mean */ <= 0.77728f) {
                            if (features[87] /* Feature_Modified_Shock_Index_slope */ <= 0.57845f) {
                                if (features[2] /* ART_DBP_mean */ <= -0.08802f) {
                                    if (features[39] /* ART_SBP_min */ <= 0.25157f) {
                                        if (features[70] /* Feature_HR_Mean_60s_max */ <= 1.27496f) {
                                            {
                                                DecisionTreeResult res = { 90.0000f, 10.0000f, 0.90000f, 0.10000f, false };
                                                return res; /* Class 0: 90.00%, Class 1: 10.00% (tau=0.31) */
                                            }
                                        } else {
                                            if (features[16] /* Feature_MBP_Mean_60s_mean */ <= -0.20156f) {
                                                {
                                                    DecisionTreeResult res = { 15.0000f, 85.0000f, 0.15000f, 0.85000f, true };
                                                    return res; /* Class 0: 15.00%, Class 1: 85.00% (tau=0.31) */
                                                }
                                            } else {
                                                {
                                                    DecisionTreeResult res = { 71.4286f, 28.5714f, 0.71429f, 0.28571f, false };
                                                    return res; /* Class 0: 71.43%, Class 1: 28.57% (tau=0.31) */
                                                }
                                            }
                                        }
                                    } else {
                                        {
                                            DecisionTreeResult res = { 0.0000f, 100.0000f, 0.00000f, 1.00000f, true };
                                            return res; /* Class 0: 0.00%, Class 1: 100.00% (tau=0.31) */
                                        }
                                    }
                                } else {
                                    if (features[39] /* ART_SBP_min */ <= -0.19421f) {
                                        {
                                            DecisionTreeResult res = { 25.0000f, 75.0000f, 0.25000f, 0.75000f, true };
                                            return res; /* Class 0: 25.00%, Class 1: 75.00% (tau=0.31) */
                                        }
                                    } else {
                                        if (features[52] /* Feature_HR_Std_60s_min */ <= 5.33201f) {
                                            if (features[68] /* Feature_Modified_Shock_Index_max */ <= 1.38653f) {
                                                if (features[5] /* RR_CO2_mean */ <= 0.52584f) {
                                                    {
                                                        DecisionTreeResult res = { 75.0000f, 25.0000f, 0.75000f, 0.25000f, false };
                                                        return res; /* Class 0: 75.00%, Class 1: 25.00% (tau=0.31) */
                                                    }
                                                } else {
                                                    {
                                                        DecisionTreeResult res = { 11.1111f, 88.8889f, 0.11111f, 0.88889f, true };
                                                        return res; /* Class 0: 11.11%, Class 1: 88.89% (tau=0.31) */
                                                    }
                                                }
                                            } else {
                                                {
                                                    DecisionTreeResult res = { 95.8333f, 4.1667f, 0.95833f, 0.04167f, false };
                                                    return res; /* Class 0: 95.83%, Class 1: 4.17% (tau=0.31) */
                                                }
                                            }
                                        } else {
                                            {
                                                DecisionTreeResult res = { 20.0000f, 80.0000f, 0.20000f, 0.80000f, true };
                                                return res; /* Class 0: 20.00%, Class 1: 80.00% (tau=0.31) */
                                            }
                                        }
                                    }
                                }
                            } else {
                                if (features[69] /* Feature_Rate_Pressure_Product_max */ <= 1.56818f) {
                                    {
                                        DecisionTreeResult res = { 6.4516f, 93.5484f, 0.06452f, 0.93548f, true };
                                        return res; /* Class 0: 6.45%, Class 1: 93.55% (tau=0.31) */
                                    }
                                } else {
                                    {
                                        DecisionTreeResult res = { 40.0000f, 60.0000f, 0.40000f, 0.60000f, true };
                                        return res; /* Class 0: 40.00%, Class 1: 60.00% (tau=0.31) */
                                    }
                                }
                            }
                        } else {
                            if (features[88] /* Feature_Rate_Pressure_Product_slope */ <= 0.63688f) {
                                if (features[90] /* Feature_HR_Std_60s_slope */ <= -3.56961f) {
                                    if (features[59] /* ART_DBP_max */ <= -0.19220f) {
                                        {
                                            DecisionTreeResult res = { 16.6667f, 83.3333f, 0.16667f, 0.83333f, true };
                                            return res; /* Class 0: 16.67%, Class 1: 83.33% (tau=0.31) */
                                        }
                                    } else {
                                        if (features[77] /* ART_SBP_slope */ <= 0.39489f) {
                                            if (features[50] /* Feature_Rate_Pressure_Product_min */ <= 0.71488f) {
                                                {
                                                    DecisionTreeResult res = { 32.3529f, 67.6471f, 0.32353f, 0.67647f, true };
                                                    return res; /* Class 0: 32.35%, Class 1: 67.65% (tau=0.31) */
                                                }
                                            } else {
                                                {
                                                    DecisionTreeResult res = { 72.2222f, 27.7778f, 0.72222f, 0.27778f, false };
                                                    return res; /* Class 0: 72.22%, Class 1: 27.78% (tau=0.31) */
                                                }
                                            }
                                        } else {
                                            {
                                                DecisionTreeResult res = { 83.3333f, 16.6667f, 0.83333f, 0.16667f, false };
                                                return res; /* Class 0: 83.33%, Class 1: 16.67% (tau=0.31) */
                                            }
                                        }
                                    }
                                } else {
                                    if (features[71] /* Feature_HR_Std_60s_max */ <= 6.90998f) {
                                        if (features[69] /* Feature_Rate_Pressure_Product_max */ <= 2.70690f) {
                                            if (features[39] /* ART_SBP_min */ <= -0.41710f) {
                                                {
                                                    DecisionTreeResult res = { 56.2500f, 43.7500f, 0.56250f, 0.43750f, true };
                                                    return res; /* Class 0: 56.25%, Class 1: 43.75% (tau=0.31) */
                                                }
                                            } else {
                                                if (features[55] /* Feature_MBP_Std_60s_min */ <= 0.52616f) {
                                                    {
                                                        DecisionTreeResult res = { 29.4498f, 70.5502f, 0.29450f, 0.70550f, true };
                                                        return res; /* Class 0: 29.45%, Class 1: 70.55% (tau=0.31) */
                                                    }
                                                } else {
                                                    {
                                                        DecisionTreeResult res = { 0.0000f, 100.0000f, 0.00000f, 1.00000f, true };
                                                        return res; /* Class 0: 0.00%, Class 1: 100.00% (tau=0.31) */
                                                    }
                                                }
                                            }
                                        } else {
                                            if (features[25] /* ETCO2_std */ <= 1.75733f) {
                                                if (features[10] /* Feature_Shock_Index_mean */ <= -0.24875f) {
                                                    {
                                                        DecisionTreeResult res = { 100.0000f, 0.0000f, 1.00000f, 0.00000f, false };
                                                        return res; /* Class 0: 100.00%, Class 1: 0.00% (tau=0.31) */
                                                    }
                                                } else {
                                                    {
                                                        DecisionTreeResult res = { 3.7267f, 96.2733f, 0.03727f, 0.96273f, true };
                                                        return res; /* Class 0: 3.73%, Class 1: 96.27% (tau=0.31) */
                                                    }
                                                }
                                            } else {
                                                {
                                                    DecisionTreeResult res = { 70.0000f, 30.0000f, 0.70000f, 0.30000f, false };
                                                    return res; /* Class 0: 70.00%, Class 1: 30.00% (tau=0.31) */
                                                }
                                            }
                                        }
                                    } else {
                                        {
                                            DecisionTreeResult res = { 56.6667f, 43.3333f, 0.56667f, 0.43333f, true };
                                            return res; /* Class 0: 56.67%, Class 1: 43.33% (tau=0.31) */
                                        }
                                    }
                                }
                            } else {
                                if (features[78] /* ART_DBP_slope */ <= 0.89052f) {
                                    if (features[79] /* ART_MBP_slope */ <= -0.13927f) {
                                        {
                                            DecisionTreeResult res = { 0.0000f, 100.0000f, 0.00000f, 1.00000f, true };
                                            return res; /* Class 0: 0.00%, Class 1: 100.00% (tau=0.31) */
                                        }
                                    } else {
                                        if (features[32] /* Feature_HR_Mean_60s_std */ <= 8.10010f) {
                                            if (features[0] /* HR_mean */ <= 1.22931f) {
                                                {
                                                    DecisionTreeResult res = { 29.1667f, 70.8333f, 0.29167f, 0.70833f, true };
                                                    return res; /* Class 0: 29.17%, Class 1: 70.83% (tau=0.31) */
                                                }
                                            } else {
                                                if (features[58] /* ART_SBP_max */ <= 0.31678f) {
                                                    {
                                                        DecisionTreeResult res = { 14.8148f, 85.1852f, 0.14815f, 0.85185f, true };
                                                        return res; /* Class 0: 14.81%, Class 1: 85.19% (tau=0.31) */
                                                    }
                                                } else {
                                                    {
                                                        DecisionTreeResult res = { 0.0000f, 100.0000f, 0.00000f, 1.00000f, true };
                                                        return res; /* Class 0: 0.00%, Class 1: 100.00% (tau=0.31) */
                                                    }
                                                }
                                            }
                                        } else {
                                            {
                                                DecisionTreeResult res = { 50.0000f, 50.0000f, 0.50000f, 0.50000f, true };
                                                return res; /* Class 0: 50.00%, Class 1: 50.00% (tau=0.31) */
                                            }
                                        }
                                    }
                                } else {
                                    if (features[35] /* Feature_MBP_Mean_60s_std */ <= -0.06120f) {
                                        {
                                            DecisionTreeResult res = { 83.3333f, 16.6667f, 0.83333f, 0.16667f, false };
                                            return res; /* Class 0: 83.33%, Class 1: 16.67% (tau=0.31) */
                                        }
                                    } else {
                                        if (features[13] /* Feature_HR_Mean_60s_mean */ <= 1.03501f) {
                                            {
                                                DecisionTreeResult res = { 80.0000f, 20.0000f, 0.80000f, 0.20000f, false };
                                                return res; /* Class 0: 80.00%, Class 1: 20.00% (tau=0.31) */
                                            }
                                        } else {
                                            if (features[65] /* BT_max */ <= 0.04311f) {
                                                {
                                                    DecisionTreeResult res = { 50.0000f, 50.0000f, 0.50000f, 0.50000f, true };
                                                    return res; /* Class 0: 50.00%, Class 1: 50.00% (tau=0.31) */
                                                }
                                            } else {
                                                {
                                                    DecisionTreeResult res = { 6.3830f, 93.6170f, 0.06383f, 0.93617f, true };
                                                    return res; /* Class 0: 6.38%, Class 1: 93.62% (tau=0.31) */
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    } else {
                        if (features[0] /* HR_mean */ <= 1.87504f) {
                            if (features[57] /* HR_max */ <= 1.25357f) {
                                {
                                    DecisionTreeResult res = { 100.0000f, 0.0000f, 1.00000f, 0.00000f, false };
                                    return res; /* Class 0: 100.00%, Class 1: 0.00% (tau=0.31) */
                                }
                            } else {
                                if (features[9] /* Feature_Pulse_Pressure_mean */ <= -1.20791f) {
                                    if (features[32] /* Feature_HR_Mean_60s_std */ <= 1.04321f) {
                                        {
                                            DecisionTreeResult res = { 89.2857f, 10.7143f, 0.89286f, 0.10714f, false };
                                            return res; /* Class 0: 89.29%, Class 1: 10.71% (tau=0.31) */
                                        }
                                    } else {
                                        if (features[39] /* ART_SBP_min */ <= -1.27436f) {
                                            {
                                                DecisionTreeResult res = { 76.4706f, 23.5294f, 0.76471f, 0.23529f, false };
                                                return res; /* Class 0: 76.47%, Class 1: 23.53% (tau=0.31) */
                                            }
                                        } else {
                                            {
                                                DecisionTreeResult res = { 19.4444f, 80.5556f, 0.19444f, 0.80556f, true };
                                                return res; /* Class 0: 19.44%, Class 1: 80.56% (tau=0.31) */
                                            }
                                        }
                                    }
                                } else {
                                    if (features[27] /* BT_std */ <= -0.19738f) {
                                        if (features[47] /* Feature_Pulse_Pressure_min */ <= -0.12089f) {
                                            if (features[23] /* PLETH_SPO2_std */ <= 3.59471f) {
                                                if (features[68] /* Feature_Modified_Shock_Index_max */ <= 0.78219f) {
                                                    {
                                                        DecisionTreeResult res = { 38.4615f, 61.5385f, 0.38462f, 0.61538f, true };
                                                        return res; /* Class 0: 38.46%, Class 1: 61.54% (tau=0.31) */
                                                    }
                                                } else {
                                                    {
                                                        DecisionTreeResult res = { 9.9359f, 90.0641f, 0.09936f, 0.90064f, true };
                                                        return res; /* Class 0: 9.94%, Class 1: 90.06% (tau=0.31) */
                                                    }
                                                }
                                            } else {
                                                if (features[77] /* ART_SBP_slope */ <= 0.17946f) {
                                                    {
                                                        DecisionTreeResult res = { 10.5263f, 89.4737f, 0.10526f, 0.89474f, true };
                                                        return res; /* Class 0: 10.53%, Class 1: 89.47% (tau=0.31) */
                                                    }
                                                } else {
                                                    {
                                                        DecisionTreeResult res = { 68.7500f, 31.2500f, 0.68750f, 0.31250f, true };
                                                        return res; /* Class 0: 68.75%, Class 1: 31.25% (tau=0.31) */
                                                    }
                                                }
                                            }
                                        } else {
                                            if (features[14] /* Feature_HR_Std_60s_mean */ <= 3.23721f) {
                                                {
                                                    DecisionTreeResult res = { 69.5652f, 30.4348f, 0.69565f, 0.30435f, false };
                                                    return res; /* Class 0: 69.57%, Class 1: 30.43% (tau=0.31) */
                                                }
                                            } else {
                                                if (features[79] /* ART_MBP_slope */ <= -0.40225f) {
                                                    {
                                                        DecisionTreeResult res = { 58.8235f, 41.1765f, 0.58824f, 0.41176f, true };
                                                        return res; /* Class 0: 58.82%, Class 1: 41.18% (tau=0.31) */
                                                    }
                                                } else {
                                                    {
                                                        DecisionTreeResult res = { 19.0476f, 80.9524f, 0.19048f, 0.80952f, true };
                                                        return res; /* Class 0: 19.05%, Class 1: 80.95% (tau=0.31) */
                                                    }
                                                }
                                            }
                                        }
                                    } else {
                                        if (features[7] /* FIO2_mean */ <= -0.06326f) {
                                            if (features[39] /* ART_SBP_min */ <= -0.14277f) {
                                                if (features[10] /* Feature_Shock_Index_mean */ <= 1.01686f) {
                                                    {
                                                        DecisionTreeResult res = { 20.0000f, 80.0000f, 0.20000f, 0.80000f, true };
                                                        return res; /* Class 0: 20.00%, Class 1: 80.00% (tau=0.31) */
                                                    }
                                                } else {
                                                    {
                                                        DecisionTreeResult res = { 1.9231f, 98.0769f, 0.01923f, 0.98077f, true };
                                                        return res; /* Class 0: 1.92%, Class 1: 98.08% (tau=0.31) */
                                                    }
                                                }
                                            } else {
                                                {
                                                    DecisionTreeResult res = { 100.0000f, 0.0000f, 1.00000f, 0.00000f, false };
                                                    return res; /* Class 0: 100.00%, Class 1: 0.00% (tau=0.31) */
                                                }
                                            }
                                        } else {
                                            if (features[73] /* Feature_MBP_Mean_60s_max */ <= 0.40846f) {
                                                if (features[60] /* ART_MBP_max */ <= -0.69778f) {
                                                    {
                                                        DecisionTreeResult res = { 14.2857f, 85.7143f, 0.14286f, 0.85714f, true };
                                                        return res; /* Class 0: 14.29%, Class 1: 85.71% (tau=0.31) */
                                                    }
                                                } else {
                                                    {
                                                        DecisionTreeResult res = { 68.7500f, 31.2500f, 0.68750f, 0.31250f, true };
                                                        return res; /* Class 0: 68.75%, Class 1: 31.25% (tau=0.31) */
                                                    }
                                                }
                                            } else {
                                                {
                                                    DecisionTreeResult res = { 15.7895f, 84.2105f, 0.15789f, 0.84211f, true };
                                                    return res; /* Class 0: 15.79%, Class 1: 84.21% (tau=0.31) */
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        } else {
                            if (features[70] /* Feature_HR_Mean_60s_max */ <= 7.84676f) {
                                if (features[63] /* ETCO2_max */ <= 2.14361f) {
                                    if (features[41] /* ART_MBP_min */ <= -2.00505f) {
                                        {
                                            DecisionTreeResult res = { 42.8571f, 57.1429f, 0.42857f, 0.57143f, true };
                                            return res; /* Class 0: 42.86%, Class 1: 57.14% (tau=0.31) */
                                        }
                                    } else {
                                        if (features[63] /* ETCO2_max */ <= -2.00911f) {
                                            {
                                                DecisionTreeResult res = { 43.7500f, 56.2500f, 0.43750f, 0.56250f, true };
                                                return res; /* Class 0: 43.75%, Class 1: 56.25% (tau=0.31) */
                                            }
                                        } else {
                                            if (features[13] /* Feature_HR_Mean_60s_mean */ <= 2.59895f) {
                                                if (features[11] /* Feature_Modified_Shock_Index_mean */ <= 2.29461f) {
                                                    {
                                                        DecisionTreeResult res = { 6.2102f, 93.7898f, 0.06210f, 0.93790f, true };
                                                        return res; /* Class 0: 6.21%, Class 1: 93.79% (tau=0.31) */
                                                    }
                                                } else {
                                                    {
                                                        DecisionTreeResult res = { 58.3333f, 41.6667f, 0.58333f, 0.41667f, true };
                                                        return res; /* Class 0: 58.33%, Class 1: 41.67% (tau=0.31) */
                                                    }
                                                }
                                            } else {
                                                if (features[40] /* ART_DBP_min */ <= 1.09561f) {
                                                    {
                                                        DecisionTreeResult res = { 1.1905f, 98.8095f, 0.01190f, 0.98810f, true };
                                                        return res; /* Class 0: 1.19%, Class 1: 98.81% (tau=0.31) */
                                                    }
                                                } else {
                                                    {
                                                        DecisionTreeResult res = { 42.8571f, 57.1429f, 0.42857f, 0.57143f, true };
                                                        return res; /* Class 0: 42.86%, Class 1: 57.14% (tau=0.31) */
                                                    }
                                                }
                                            }
                                        }
                                    }
                                } else {
                                    {
                                        DecisionTreeResult res = { 31.5789f, 68.4211f, 0.31579f, 0.68421f, true };
                                        return res; /* Class 0: 31.58%, Class 1: 68.42% (tau=0.31) */
                                    }
                                }
                            } else {
                                {
                                    DecisionTreeResult res = { 100.0000f, 0.0000f, 1.00000f, 0.00000f, false };
                                    return res; /* Class 0: 100.00%, Class 1: 0.00% (tau=0.31) */
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}

static inline bool predict_tachycardia_95_pct(const float* features, float* percent_0, float* percent_1) {
    DecisionTreeResult res = predict_tachycardia_95(features);
    if (percent_0) *percent_0 = res.percent_0;
    if (percent_1) *percent_1 = res.percent_1;
    return res.prediction;
}

