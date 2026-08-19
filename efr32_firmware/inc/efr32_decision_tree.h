#ifndef EFR32_DECISION_TREE_H
#define EFR32_DECISION_TREE_H

// Silicon Labs EFR32 Fast Direct C Decision Tree Classifiers
// Target Platforms: EFR32xG24, EFR32BG22, EFR32MG21, Cortex-M33/M4

#include <stdbool.h>

// 1. Future_Hypotension Classifier (MAP < 65 mmHg)
// Flash footprint: ~0.92 KB | Dynamic RAM: 0 KB
static inline bool predict_hypotension_efr32(const float* features) {
    if (features[3] /* ART_MBP_mean */ <= -0.15822f) {
        if (features[11] /* Feature_Modified_Shock_Index_mean */ <= -1.03889f) {
            if (features[17] /* Feature_MBP_Std_60s_mean */ <= 0.80472f) {
                if (features[0] /* HR_mean */ <= -3.17342f) {
                    if (features[14] /* Feature_HR_Std_60s_mean */ <= -0.06020f) {
                        return false;
                    } else {
                        return true;
                    }
                } else {
                    if (features[11] /* Feature_Modified_Shock_Index_mean */ <= -1.05283f) {
                        return false;
                    } else {
                        return false;
                    }
                }
            } else {
                if (features[3] /* ART_MBP_mean */ <= -0.65586f) {
                    return false;
                } else {
                    return true;
                }
            }
        } else {
            if (features[3] /* ART_MBP_mean */ <= -0.36414f) {
                if (features[3] /* ART_MBP_mean */ <= -0.39846f) {
                    if (features[3] /* ART_MBP_mean */ <= -0.42134f) {
                        return true;
                    } else {
                        return true;
                    }
                } else {
                    if (features[17] /* Feature_MBP_Std_60s_mean */ <= -0.33211f) {
                        return true;
                    } else {
                        return true;
                    }
                }
            } else {
                if (features[3] /* ART_MBP_mean */ <= -0.26118f) {
                    if (features[17] /* Feature_MBP_Std_60s_mean */ <= -0.30440f) {
                        return true;
                    } else {
                        return true;
                    }
                } else {
                    if (features[17] /* Feature_MBP_Std_60s_mean */ <= -0.26728f) {
                        return true;
                    } else {
                        return true;
                    }
                }
            }
        }
    } else {
        if (features[2] /* ART_DBP_mean */ <= 0.12071f) {
            if (features[17] /* Feature_MBP_Std_60s_mean */ <= -0.15982f) {
                if (features[3] /* ART_MBP_mean */ <= -0.05526f) {
                    if (features[17] /* Feature_MBP_Std_60s_mean */ <= -0.28687f) {
                        return false;
                    } else {
                        return false;
                    }
                } else {
                    if (features[17] /* Feature_MBP_Std_60s_mean */ <= -0.24728f) {
                        return false;
                    } else {
                        return false;
                    }
                }
            } else {
                if (features[2] /* ART_DBP_mean */ <= -0.22265f) {
                    if (features[1] /* ART_SBP_mean */ <= -0.24609f) {
                        return true;
                    } else {
                        return true;
                    }
                } else {
                    if (features[8] /* BT_mean */ <= -0.44713f) {
                        return true;
                    } else {
                        return true;
                    }
                }
            }
        } else {
            if (features[17] /* Feature_MBP_Std_60s_mean */ <= -0.04697f) {
                if (features[3] /* ART_MBP_mean */ <= 0.11634f) {
                    if (features[17] /* Feature_MBP_Std_60s_mean */ <= -0.25954f) {
                        return false;
                    } else {
                        return false;
                    }
                } else {
                    if (features[7] /* FIO2_mean */ <= 1.49039f) {
                        return false;
                    } else {
                        return false;
                    }
                }
            } else {
                if (features[7] /* FIO2_mean */ <= 1.44291f) {
                    if (features[10] /* Feature_Shock_Index_mean */ <= 0.52268f) {
                        return false;
                    } else {
                        return true;
                    }
                } else {
                    if (features[16] /* Feature_MBP_Mean_60s_mean */ <= 0.04639f) {
                        return true;
                    } else {
                        return false;
                    }
                }
            }
        }
    }
}

// 2. Future_Hypoxia Classifier (SpO2 < 90%)
// Flash footprint: ~0.98 KB | Dynamic RAM: 0 KB
static inline bool predict_hypoxia_efr32(const float* features) {
    if (features[39] /* ART_SBP_min */ <= 0.12145f) {
        if (features[22] /* ART_MBP_std */ <= -0.54185f) {
            if (features[22] /* ART_MBP_std */ <= -1.07915f) {
                if (features[24] /* RR_CO2_std */ <= -0.51918f) {
                    if (features[24] /* RR_CO2_std */ <= -1.61698f) {
                        return true;
                    } else {
                        return true;
                    }
                } else {
                    if (features[20] /* ART_SBP_std */ <= -0.88754f) {
                        return true;
                    } else {
                        return true;
                    }
                }
            } else {
                if (features[24] /* RR_CO2_std */ <= -0.88512f) {
                    if (features[20] /* ART_SBP_std */ <= -0.34985f) {
                        return true;
                    } else {
                        return true;
                    }
                } else {
                    if (features[60] /* ART_MBP_max */ <= 0.98069f) {
                        return true;
                    } else {
                        return true;
                    }
                }
            }
        } else {
            if (features[44] /* ETCO2_min */ <= -0.25775f) {
                if (features[44] /* ETCO2_min */ <= -1.01646f) {
                    if (features[64] /* FIO2_max */ <= -0.16173f) {
                        return true;
                    } else {
                        return true;
                    }
                } else {
                    if (features[53] /* Feature_HR_Delta_60s_min */ <= 0.29335f) {
                        return true;
                    } else {
                        return false;
                    }
                }
            } else {
                if (features[38] /* HR_min */ <= -0.32482f) {
                    if (features[22] /* ART_MBP_std */ <= -0.00454f) {
                        return false;
                    } else {
                        return false;
                    }
                } else {
                    if (features[28] /* Feature_Pulse_Pressure_std */ <= 1.79359f) {
                        return false;
                    } else {
                        return true;
                    }
                }
            }
        }
    } else {
        if (features[39] /* ART_SBP_min */ <= 1.58284f) {
            if (features[24] /* RR_CO2_std */ <= 0.21268f) {
                if (features[22] /* ART_MBP_std */ <= -1.07915f) {
                    if (features[24] /* RR_CO2_std */ <= -0.51918f) {
                        return true;
                    } else {
                        return true;
                    }
                } else {
                    if (features[8] /* BT_mean */ <= 0.24735f) {
                        return true;
                    } else {
                        return true;
                    }
                }
            } else {
                if (features[22] /* ART_MBP_std */ <= -1.07915f) {
                    if (features[36] /* Feature_MBP_Std_60s_std */ <= 1.11081f) {
                        return true;
                    } else {
                        return false;
                    }
                } else {
                    if (features[44] /* ETCO2_min */ <= -0.19939f) {
                        return true;
                    } else {
                        return false;
                    }
                }
            }
        } else {
            if (features[55] /* Feature_MBP_Std_60s_min */ <= 1.55137f) {
                if (features[25] /* ETCO2_std */ <= -1.76643f) {
                    if (features[42] /* PLETH_SPO2_min */ <= -0.56941f) {
                        return false;
                    } else {
                        return true;
                    }
                } else {
                    if (features[87] /* Feature_Modified_Shock_Index_slope */ <= 3.05969f) {
                        return true;
                    } else {
                        return false;
                    }
                }
            } else {
                if (features[20] /* ART_SBP_std */ <= -0.60299f) {
                    if (features[15] /* Feature_HR_Delta_60s_mean */ <= -2.62724f) {
                        return false;
                    } else {
                        return true;
                    }
                } else {
                    if (features[77] /* ART_SBP_slope */ <= -1.17226f) {
                        return true;
                    } else {
                        return false;
                    }
                }
            }
        }
    }
}

// 3. Future_Tachycardia Classifier (HR > 100 bpm)
// Flash footprint: ~0.98 KB | Dynamic RAM: 0 KB
static inline bool predict_tachycardia_efr32(const float* features) {
    if (features[3] /* ART_MBP_mean */ <= 0.27638f) {
        if (features[38] /* HR_min */ <= 0.24946f) {
            if (features[3] /* ART_MBP_mean */ <= -0.29940f) {
                if (features[3] /* ART_MBP_mean */ <= -0.76721f) {
                    if (features[47] /* Feature_Pulse_Pressure_min */ <= -2.56285f) {
                        return true;
                    } else {
                        return false;
                    }
                } else {
                    if (features[42] /* PLETH_SPO2_min */ <= 0.20835f) {
                        return false;
                    } else {
                        return false;
                    }
                }
            } else {
                if (features[3] /* ART_MBP_mean */ <= 0.09645f) {
                    if (features[5] /* RR_CO2_mean */ <= -0.65058f) {
                        return false;
                    } else {
                        return false;
                    }
                } else {
                    if (features[4] /* PLETH_SPO2_mean */ <= 1.20012f) {
                        return false;
                    } else {
                        return true;
                    }
                }
            }
        } else {
            if (features[39] /* ART_SBP_min */ <= -1.19809f) {
                if (features[3] /* ART_MBP_mean */ <= 0.13244f) {
                    if (features[26] /* FIO2_std */ <= 0.61264f) {
                        return false;
                    } else {
                        return false;
                    }
                } else {
                    if (features[57] /* HR_max */ <= 0.27128f) {
                        return false;
                    } else {
                        return true;
                    }
                }
            } else {
                if (features[3] /* ART_MBP_mean */ <= -0.22742f) {
                    if (features[30] /* Feature_Modified_Shock_Index_std */ <= 0.00803f) {
                        return false;
                    } else {
                        return false;
                    }
                } else {
                    if (features[39] /* ART_SBP_min */ <= 2.53938f) {
                        return false;
                    } else {
                        return true;
                    }
                }
            }
        }
    } else {
        if (features[68] /* Feature_Modified_Shock_Index_max */ <= 1.11871f) {
            if (features[4] /* PLETH_SPO2_mean */ <= 0.94056f) {
                if (features[68] /* Feature_Modified_Shock_Index_max */ <= 0.35689f) {
                    if (features[38] /* HR_min */ <= 0.24946f) {
                        return false;
                    } else {
                        return true;
                    }
                } else {
                    if (features[70] /* Feature_HR_Mean_60s_max */ <= 1.55562f) {
                        return true;
                    } else {
                        return true;
                    }
                }
            } else {
                if (features[4] /* PLETH_SPO2_mean */ <= 2.41138f) {
                    if (features[68] /* Feature_Modified_Shock_Index_max */ <= 0.52370f) {
                        return true;
                    } else {
                        return true;
                    }
                } else {
                    if (features[3] /* ART_MBP_mean */ <= 0.56427f) {
                        return true;
                    } else {
                        return true;
                    }
                }
            }
        } else {
            if (features[0] /* HR_mean */ <= 1.81423f) {
                if (features[4] /* PLETH_SPO2_mean */ <= 0.16189f) {
                    if (features[3] /* ART_MBP_mean */ <= 1.17603f) {
                        return true;
                    } else {
                        return true;
                    }
                } else {
                    if (features[4] /* PLETH_SPO2_mean */ <= 1.63271f) {
                        return true;
                    } else {
                        return true;
                    }
                }
            } else {
                if (features[0] /* HR_mean */ <= 1.98657f) {
                    if (features[4] /* PLETH_SPO2_mean */ <= 0.07537f) {
                        return true;
                    } else {
                        return true;
                    }
                } else {
                    if (features[68] /* Feature_Modified_Shock_Index_max */ <= 7.04671f) {
                        return true;
                    } else {
                        return false;
                    }
                }
            }
        }
    }
}

#endif // EFR32_DECISION_TREE_H
