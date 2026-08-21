// Direct C Decision Tree for Future Tachycardia (95 Features, W=600s, STRIDE=5s)
#include <stdbool.h>

static inline bool predict_tachycardia_95(const float* features) {
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
                                                return false; /* p_pos=0.172, tau=0.45 */
                                            } else {
                                                if (features[70] /* Feature_HR_Mean_60s_max */ <= 0.50380f) {
                                                    return false; /* p_pos=0.022, tau=0.45 */
                                                } else {
                                                    return false; /* p_pos=0.113, tau=0.45 */
                                                }
                                            }
                                        } else {
                                            return true; /* p_pos=0.571, tau=0.45 */
                                        }
                                    } else {
                                        if (features[13] /* Feature_HR_Mean_60s_mean */ <= 1.04084f) {
                                            if (features[0] /* HR_mean */ <= -0.28450f) {
                                                if (features[65] /* BT_max */ <= 0.53714f) {
                                                    return false; /* p_pos=0.008, tau=0.45 */
                                                } else {
                                                    return false; /* p_pos=0.083, tau=0.45 */
                                                }
                                            } else {
                                                if (features[69] /* Feature_Rate_Pressure_Product_max */ <= 3.03822f) {
                                                    return false; /* p_pos=0.016, tau=0.45 */
                                                } else {
                                                    return true; /* p_pos=0.500, tau=0.45 */
                                                }
                                            }
                                        } else {
                                            if (features[43] /* RR_CO2_min */ <= -2.68488f) {
                                                return true; /* p_pos=0.875, tau=0.45 */
                                            } else {
                                                if (features[5] /* RR_CO2_mean */ <= -1.61674f) {
                                                    return true; /* p_pos=1.000, tau=0.45 */
                                                } else {
                                                    return false; /* p_pos=0.053, tau=0.45 */
                                                }
                                            }
                                        }
                                    }
                                } else {
                                    if (features[50] /* Feature_Rate_Pressure_Product_min */ <= 1.86124f) {
                                        if (features[24] /* RR_CO2_std */ <= 0.23095f) {
                                            if (features[33] /* Feature_HR_Std_60s_std */ <= -0.70943f) {
                                                if (features[28] /* Feature_Pulse_Pressure_std */ <= 2.92714f) {
                                                    return false; /* p_pos=0.045, tau=0.45 */
                                                } else {
                                                    return false; /* p_pos=0.346, tau=0.45 */
                                                }
                                            } else {
                                                if (features[12] /* Feature_Rate_Pressure_Product_mean */ <= 0.16940f) {
                                                    return false; /* p_pos=0.059, tau=0.45 */
                                                } else {
                                                    return false; /* p_pos=0.127, tau=0.45 */
                                                }
                                            }
                                        } else {
                                            if (features[84] /* BT_slope */ <= -5.41331f) {
                                                return false; /* p_pos=0.323, tau=0.45 */
                                            } else {
                                                if (features[0] /* HR_mean */ <= 1.00986f) {
                                                    return false; /* p_pos=0.029, tau=0.45 */
                                                } else {
                                                    return false; /* p_pos=0.140, tau=0.45 */
                                                }
                                            }
                                        }
                                    } else {
                                        if (features[50] /* Feature_Rate_Pressure_Product_min */ <= 2.06825f) {
                                            if (features[41] /* ART_MBP_min */ <= 1.54498f) {
                                                if (features[39] /* ART_SBP_min */ <= 1.12598f) {
                                                    return true; /* p_pos=0.540, tau=0.45 */
                                                } else {
                                                    return false; /* p_pos=0.060, tau=0.45 */
                                                }
                                            } else {
                                                return true; /* p_pos=0.679, tau=0.45 */
                                            }
                                        } else {
                                            if (features[84] /* BT_slope */ <= 0.00500f) {
                                                if (features[14] /* Feature_HR_Std_60s_mean */ <= -0.39678f) {
                                                    return false; /* p_pos=0.000, tau=0.45 */
                                                } else {
                                                    return false; /* p_pos=0.200, tau=0.45 */
                                                }
                                            } else {
                                                return false; /* p_pos=0.182, tau=0.45 */
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
                                                    return false; /* p_pos=0.035, tau=0.45 */
                                                } else {
                                                    return false; /* p_pos=0.017, tau=0.45 */
                                                }
                                            } else {
                                                if (features[88] /* Feature_Rate_Pressure_Product_slope */ <= 2.21626f) {
                                                    return false; /* p_pos=0.147, tau=0.45 */
                                                } else {
                                                    return true; /* p_pos=0.714, tau=0.45 */
                                                }
                                            }
                                        } else {
                                            if (features[38] /* HR_min */ <= 0.17296f) {
                                                if (features[57] /* HR_max */ <= -0.19170f) {
                                                    return false; /* p_pos=0.017, tau=0.45 */
                                                } else {
                                                    return false; /* p_pos=0.080, tau=0.45 */
                                                }
                                            } else {
                                                if (features[58] /* ART_SBP_max */ <= 0.75490f) {
                                                    return false; /* p_pos=0.145, tau=0.45 */
                                                } else {
                                                    return true; /* p_pos=0.485, tau=0.45 */
                                                }
                                            }
                                        }
                                    } else {
                                        if (features[83] /* FIO2_slope */ <= 3.11801f) {
                                            if (features[10] /* Feature_Shock_Index_mean */ <= -0.59234f) {
                                                if (features[72] /* Feature_HR_Delta_60s_max */ <= 1.56520f) {
                                                    return false; /* p_pos=0.021, tau=0.45 */
                                                } else {
                                                    return false; /* p_pos=0.300, tau=0.45 */
                                                }
                                            } else {
                                                if (features[51] /* Feature_HR_Mean_60s_min */ <= 1.34994f) {
                                                    return false; /* p_pos=0.043, tau=0.45 */
                                                } else {
                                                    return true; /* p_pos=0.625, tau=0.45 */
                                                }
                                            }
                                        } else {
                                            if (features[57] /* HR_max */ <= 0.41050f) {
                                                if (features[63] /* ETCO2_max */ <= 0.16613f) {
                                                    return false; /* p_pos=0.147, tau=0.45 */
                                                } else {
                                                    return false; /* p_pos=0.070, tau=0.45 */
                                                }
                                            } else {
                                                if (features[65] /* BT_max */ <= 0.05957f) {
                                                    return false; /* p_pos=0.042, tau=0.45 */
                                                } else {
                                                    return true; /* p_pos=0.475, tau=0.45 */
                                                }
                                            }
                                        }
                                    }
                                } else {
                                    if (features[13] /* Feature_HR_Mean_60s_mean */ <= 1.47902f) {
                                        if (features[70] /* Feature_HR_Mean_60s_max */ <= 0.95521f) {
                                            if (features[16] /* Feature_MBP_Mean_60s_mean */ <= -0.21004f) {
                                                if (features[91] /* Feature_HR_Delta_60s_slope */ <= 2.29942f) {
                                                    return false; /* p_pos=0.091, tau=0.45 */
                                                } else {
                                                    return true; /* p_pos=0.450, tau=0.45 */
                                                }
                                            } else {
                                                if (features[76] /* HR_slope */ <= 2.25052f) {
                                                    return false; /* p_pos=0.044, tau=0.45 */
                                                } else {
                                                    return false; /* p_pos=0.297, tau=0.45 */
                                                }
                                            }
                                        } else {
                                            if (features[62] /* RR_CO2_max */ <= 3.89086f) {
                                                if (features[77] /* ART_SBP_slope */ <= 0.27738f) {
                                                    return false; /* p_pos=0.144, tau=0.45 */
                                                } else {
                                                    return false; /* p_pos=0.328, tau=0.45 */
                                                }
                                            } else {
                                                return true; /* p_pos=0.850, tau=0.45 */
                                            }
                                        }
                                    } else {
                                        if (features[76] /* HR_slope */ <= 0.77210f) {
                                            if (features[0] /* HR_mean */ <= 2.76970f) {
                                                if (features[39] /* ART_SBP_min */ <= 1.64034f) {
                                                    return false; /* p_pos=0.256, tau=0.45 */
                                                } else {
                                                    return true; /* p_pos=1.000, tau=0.45 */
                                                }
                                            } else {
                                                return true; /* p_pos=1.000, tau=0.45 */
                                            }
                                        } else {
                                            if (features[75] /* Feature_MBP_Delta_60s_max */ <= 0.34871f) {
                                                if (features[51] /* Feature_HR_Mean_60s_min */ <= 1.36401f) {
                                                    return false; /* p_pos=0.333, tau=0.45 */
                                                } else {
                                                    return true; /* p_pos=0.765, tau=0.45 */
                                                }
                                            } else {
                                                return false; /* p_pos=0.000, tau=0.45 */
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
                                                    return false; /* p_pos=0.077, tau=0.45 */
                                                } else {
                                                    return false; /* p_pos=0.173, tau=0.45 */
                                                }
                                            } else {
                                                if (features[34] /* Feature_HR_Delta_60s_std */ <= -0.85751f) {
                                                    return true; /* p_pos=0.900, tau=0.45 */
                                                } else {
                                                    return false; /* p_pos=0.178, tau=0.45 */
                                                }
                                            }
                                        } else {
                                            if (features[88] /* Feature_Rate_Pressure_Product_slope */ <= 0.06534f) {
                                                if (features[19] /* HR_std */ <= -0.50463f) {
                                                    return false; /* p_pos=0.099, tau=0.45 */
                                                } else {
                                                    return false; /* p_pos=0.041, tau=0.45 */
                                                }
                                            } else {
                                                if (features[7] /* FIO2_mean */ <= 1.92116f) {
                                                    return false; /* p_pos=0.203, tau=0.45 */
                                                } else {
                                                    return false; /* p_pos=0.091, tau=0.45 */
                                                }
                                            }
                                        }
                                    } else {
                                        return true; /* p_pos=1.000, tau=0.45 */
                                    }
                                } else {
                                    if (features[57] /* HR_max */ <= 0.69152f) {
                                        if (features[74] /* Feature_MBP_Std_60s_max */ <= 2.86905f) {
                                            if (features[19] /* HR_std */ <= 0.49158f) {
                                                if (features[16] /* Feature_MBP_Mean_60s_mean */ <= 7.18601f) {
                                                    return false; /* p_pos=0.059, tau=0.45 */
                                                } else {
                                                    return true; /* p_pos=0.800, tau=0.45 */
                                                }
                                            } else {
                                                if (features[30] /* Feature_Modified_Shock_Index_std */ <= 0.07233f) {
                                                    return false; /* p_pos=0.129, tau=0.45 */
                                                } else {
                                                    return false; /* p_pos=0.392, tau=0.45 */
                                                }
                                            }
                                        } else {
                                            if (features[16] /* Feature_MBP_Mean_60s_mean */ <= 0.77552f) {
                                                return true; /* p_pos=0.523, tau=0.45 */
                                            } else {
                                                return false; /* p_pos=0.054, tau=0.45 */
                                            }
                                        }
                                    } else {
                                        if (features[0] /* HR_mean */ <= 1.51518f) {
                                            if (features[45] /* FIO2_min */ <= 1.83575f) {
                                                if (features[17] /* Feature_MBP_Std_60s_mean */ <= 0.09616f) {
                                                    return false; /* p_pos=0.019, tau=0.45 */
                                                } else {
                                                    return false; /* p_pos=0.333, tau=0.45 */
                                                }
                                            } else {
                                                if (features[41] /* ART_MBP_min */ <= 0.47063f) {
                                                    return true; /* p_pos=0.621, tau=0.45 */
                                                } else {
                                                    return false; /* p_pos=0.258, tau=0.45 */
                                                }
                                            }
                                        } else {
                                            return true; /* p_pos=1.000, tau=0.45 */
                                        }
                                    }
                                }
                            } else {
                                if (features[67] /* Feature_Shock_Index_max */ <= -0.04299f) {
                                    if (features[57] /* HR_max */ <= 1.21342f) {
                                        if (features[6] /* ETCO2_mean */ <= 3.19227f) {
                                            if (features[26] /* FIO2_std */ <= -0.34182f) {
                                                if (features[34] /* Feature_HR_Delta_60s_std */ <= 0.67297f) {
                                                    return false; /* p_pos=0.022, tau=0.45 */
                                                } else {
                                                    return false; /* p_pos=0.128, tau=0.45 */
                                                }
                                            } else {
                                                if (features[13] /* Feature_HR_Mean_60s_mean */ <= 0.84491f) {
                                                    return false; /* p_pos=0.045, tau=0.45 */
                                                } else {
                                                    return false; /* p_pos=0.232, tau=0.45 */
                                                }
                                            }
                                        } else {
                                            return true; /* p_pos=0.600, tau=0.45 */
                                        }
                                    } else {
                                        return true; /* p_pos=0.474, tau=0.45 */
                                    }
                                } else {
                                    if (features[51] /* Feature_HR_Mean_60s_min */ <= -0.86741f) {
                                        return true; /* p_pos=0.625, tau=0.45 */
                                    } else {
                                        if (features[38] /* HR_min */ <= 0.51221f) {
                                            if (features[0] /* HR_mean */ <= -0.76116f) {
                                                return true; /* p_pos=0.600, tau=0.45 */
                                            } else {
                                                if (features[8] /* BT_mean */ <= 0.44742f) {
                                                    return false; /* p_pos=0.041, tau=0.45 */
                                                } else {
                                                    return false; /* p_pos=0.400, tau=0.45 */
                                                }
                                            }
                                        } else {
                                            if (features[39] /* ART_SBP_min */ <= -0.10848f) {
                                                return true; /* p_pos=0.750, tau=0.45 */
                                            } else {
                                                if (features[72] /* Feature_HR_Delta_60s_max */ <= -0.54084f) {
                                                    return false; /* p_pos=0.035, tau=0.45 */
                                                } else {
                                                    return false; /* p_pos=0.252, tau=0.45 */
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
                                                    return false; /* p_pos=0.015, tau=0.45 */
                                                } else {
                                                    return false; /* p_pos=0.429, tau=0.45 */
                                                }
                                            } else {
                                                if (features[72] /* Feature_HR_Delta_60s_max */ <= -0.59158f) {
                                                    return false; /* p_pos=0.102, tau=0.45 */
                                                } else {
                                                    return false; /* p_pos=0.400, tau=0.45 */
                                                }
                                            }
                                        } else {
                                            return true; /* p_pos=0.800, tau=0.45 */
                                        }
                                    } else {
                                        if (features[21] /* ART_DBP_std */ <= 0.38032f) {
                                            if (features[46] /* BT_min */ <= 0.03849f) {
                                                if (features[9] /* Feature_Pulse_Pressure_mean */ <= -0.59745f) {
                                                    return true; /* p_pos=0.750, tau=0.45 */
                                                } else {
                                                    return false; /* p_pos=0.330, tau=0.45 */
                                                }
                                            } else {
                                                if (features[88] /* Feature_Rate_Pressure_Product_slope */ <= -0.05128f) {
                                                    return false; /* p_pos=0.099, tau=0.45 */
                                                } else {
                                                    return false; /* p_pos=0.273, tau=0.45 */
                                                }
                                            }
                                        } else {
                                            if (features[26] /* FIO2_std */ <= -0.11203f) {
                                                if (features[8] /* BT_mean */ <= 0.20967f) {
                                                    return true; /* p_pos=0.586, tau=0.45 */
                                                } else {
                                                    return false; /* p_pos=0.150, tau=0.45 */
                                                }
                                            } else {
                                                return true; /* p_pos=0.775, tau=0.45 */
                                            }
                                        }
                                    }
                                } else {
                                    if (features[14] /* Feature_HR_Std_60s_mean */ <= -0.11087f) {
                                        if (features[12] /* Feature_Rate_Pressure_Product_mean */ <= 2.74129f) {
                                            if (features[50] /* Feature_Rate_Pressure_Product_min */ <= 2.24988f) {
                                                return false; /* p_pos=0.083, tau=0.45 */
                                            } else {
                                                if (features[70] /* Feature_HR_Mean_60s_max */ <= -0.01015f) {
                                                    return false; /* p_pos=0.036, tau=0.45 */
                                                } else {
                                                    return false; /* p_pos=0.003, tau=0.45 */
                                                }
                                            }
                                        } else {
                                            if (features[13] /* Feature_HR_Mean_60s_mean */ <= 2.01693f) {
                                                if (features[13] /* Feature_HR_Mean_60s_mean */ <= 1.69705f) {
                                                    return false; /* p_pos=0.021, tau=0.45 */
                                                } else {
                                                    return false; /* p_pos=0.139, tau=0.45 */
                                                }
                                            } else {
                                                return true; /* p_pos=0.667, tau=0.45 */
                                            }
                                        }
                                    } else {
                                        if (features[13] /* Feature_HR_Mean_60s_mean */ <= 1.89894f) {
                                            if (features[24] /* RR_CO2_std */ <= 5.36051f) {
                                                if (features[13] /* Feature_HR_Mean_60s_mean */ <= 1.02125f) {
                                                    return false; /* p_pos=0.008, tau=0.45 */
                                                } else {
                                                    return false; /* p_pos=0.177, tau=0.45 */
                                                }
                                            } else {
                                                return true; /* p_pos=0.800, tau=0.45 */
                                            }
                                        } else {
                                            return true; /* p_pos=0.815, tau=0.45 */
                                        }
                                    }
                                }
                            } else {
                                if (features[92] /* Feature_MBP_Mean_60s_slope */ <= -0.12669f) {
                                    return true; /* p_pos=1.000, tau=0.45 */
                                } else {
                                    return true; /* p_pos=0.700, tau=0.45 */
                                }
                            }
                        } else {
                            if (features[70] /* Feature_HR_Mean_60s_max */ <= 1.54534f) {
                                if (features[25] /* ETCO2_std */ <= 0.11752f) {
                                    if (features[70] /* Feature_HR_Mean_60s_max */ <= 1.36430f) {
                                        if (features[90] /* Feature_HR_Std_60s_slope */ <= 0.28175f) {
                                            if (features[29] /* Feature_Shock_Index_std */ <= -0.44737f) {
                                                if (features[55] /* Feature_MBP_Std_60s_min */ <= -0.39022f) {
                                                    return false; /* p_pos=0.000, tau=0.45 */
                                                } else {
                                                    return false; /* p_pos=0.233, tau=0.45 */
                                                }
                                            } else {
                                                if (features[68] /* Feature_Modified_Shock_Index_max */ <= 0.92805f) {
                                                    return false; /* p_pos=0.030, tau=0.45 */
                                                } else {
                                                    return false; /* p_pos=0.333, tau=0.45 */
                                                }
                                            }
                                        } else {
                                            if (features[48] /* Feature_Shock_Index_min */ <= 0.66921f) {
                                                if (features[83] /* FIO2_slope */ <= -0.04738f) {
                                                    return false; /* p_pos=0.000, tau=0.45 */
                                                } else {
                                                    return false; /* p_pos=0.317, tau=0.45 */
                                                }
                                            } else {
                                                return true; /* p_pos=0.833, tau=0.45 */
                                            }
                                        }
                                    } else {
                                        if (features[16] /* Feature_MBP_Mean_60s_mean */ <= 1.05999f) {
                                            if (features[43] /* RR_CO2_min */ <= 1.23712f) {
                                                if (features[17] /* Feature_MBP_Std_60s_mean */ <= -0.29703f) {
                                                    return false; /* p_pos=0.328, tau=0.45 */
                                                } else {
                                                    return false; /* p_pos=0.056, tau=0.45 */
                                                }
                                            } else {
                                                return true; /* p_pos=0.800, tau=0.45 */
                                            }
                                        } else {
                                            return true; /* p_pos=1.000, tau=0.45 */
                                        }
                                    }
                                } else {
                                    if (features[4] /* PLETH_SPO2_mean */ <= -0.17559f) {
                                        return true; /* p_pos=0.650, tau=0.45 */
                                    } else {
                                        if (features[44] /* ETCO2_min */ <= -0.35632f) {
                                            return false; /* p_pos=0.000, tau=0.45 */
                                        } else {
                                            return true; /* p_pos=0.531, tau=0.45 */
                                        }
                                    }
                                }
                            } else {
                                if (features[7] /* FIO2_mean */ <= -0.74402f) {
                                    return false; /* p_pos=0.333, tau=0.45 */
                                } else {
                                    if (features[21] /* ART_DBP_std */ <= 0.36672f) {
                                        if (features[31] /* Feature_Rate_Pressure_Product_std */ <= 0.60646f) {
                                            if (features[54] /* Feature_MBP_Mean_60s_min */ <= 0.73897f) {
                                                return true; /* p_pos=1.000, tau=0.45 */
                                            } else {
                                                if (features[87] /* Feature_Modified_Shock_Index_slope */ <= -0.23610f) {
                                                    return true; /* p_pos=0.455, tau=0.45 */
                                                } else {
                                                    return true; /* p_pos=0.969, tau=0.45 */
                                                }
                                            }
                                        } else {
                                            return true; /* p_pos=0.455, tau=0.45 */
                                        }
                                    } else {
                                        return true; /* p_pos=0.520, tau=0.45 */
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
                                                    return false; /* p_pos=0.021, tau=0.45 */
                                                } else {
                                                    return false; /* p_pos=0.049, tau=0.45 */
                                                }
                                            } else {
                                                if (features[62] /* RR_CO2_max */ <= 0.37012f) {
                                                    return false; /* p_pos=0.081, tau=0.45 */
                                                } else {
                                                    return false; /* p_pos=0.197, tau=0.45 */
                                                }
                                            }
                                        } else {
                                            if (features[49] /* Feature_Modified_Shock_Index_min */ <= 2.16986f) {
                                                if (features[15] /* Feature_HR_Delta_60s_mean */ <= 1.24761f) {
                                                    return false; /* p_pos=0.043, tau=0.45 */
                                                } else {
                                                    return false; /* p_pos=0.140, tau=0.45 */
                                                }
                                            } else {
                                                return false; /* p_pos=0.375, tau=0.45 */
                                            }
                                        }
                                    } else {
                                        if (features[76] /* HR_slope */ <= 1.32651f) {
                                            if (features[38] /* HR_min */ <= 2.27634f) {
                                                if (features[64] /* FIO2_max */ <= -0.87730f) {
                                                    return false; /* p_pos=0.222, tau=0.45 */
                                                } else {
                                                    return false; /* p_pos=0.065, tau=0.45 */
                                                }
                                            } else {
                                                if (features[65] /* BT_max */ <= 0.07604f) {
                                                    return false; /* p_pos=0.022, tau=0.45 */
                                                } else {
                                                    return false; /* p_pos=0.313, tau=0.45 */
                                                }
                                            }
                                        } else {
                                            if (features[48] /* Feature_Shock_Index_min */ <= 0.62497f) {
                                                if (features[89] /* Feature_HR_Mean_60s_slope */ <= 2.60666f) {
                                                    return false; /* p_pos=0.195, tau=0.45 */
                                                } else {
                                                    return true; /* p_pos=0.667, tau=0.45 */
                                                }
                                            } else {
                                                return true; /* p_pos=0.652, tau=0.45 */
                                            }
                                        }
                                    }
                                } else {
                                    if (features[50] /* Feature_Rate_Pressure_Product_min */ <= 0.76627f) {
                                        if (features[76] /* HR_slope */ <= 2.06572f) {
                                            if (features[33] /* Feature_HR_Std_60s_std */ <= 0.62212f) {
                                                if (features[30] /* Feature_Modified_Shock_Index_std */ <= 0.55948f) {
                                                    return false; /* p_pos=0.079, tau=0.45 */
                                                } else {
                                                    return false; /* p_pos=0.027, tau=0.45 */
                                                }
                                            } else {
                                                if (features[78] /* ART_DBP_slope */ <= 0.31203f) {
                                                    return false; /* p_pos=0.112, tau=0.45 */
                                                } else {
                                                    return false; /* p_pos=0.231, tau=0.45 */
                                                }
                                            }
                                        } else {
                                            if (features[67] /* Feature_Shock_Index_max */ <= 0.18906f) {
                                                if (features[69] /* Feature_Rate_Pressure_Product_max */ <= 0.41291f) {
                                                    return false; /* p_pos=0.111, tau=0.45 */
                                                } else {
                                                    return false; /* p_pos=0.333, tau=0.45 */
                                                }
                                            } else {
                                                if (features[52] /* Feature_HR_Std_60s_min */ <= -0.27186f) {
                                                    return true; /* p_pos=0.684, tau=0.45 */
                                                } else {
                                                    return false; /* p_pos=0.382, tau=0.45 */
                                                }
                                            }
                                        }
                                    } else {
                                        if (features[57] /* HR_max */ <= 1.29372f) {
                                            if (features[15] /* Feature_HR_Delta_60s_mean */ <= 1.14979f) {
                                                if (features[44] /* ETCO2_min */ <= -2.76659f) {
                                                    return false; /* p_pos=0.380, tau=0.45 */
                                                } else {
                                                    return false; /* p_pos=0.109, tau=0.45 */
                                                }
                                            } else {
                                                if (features[56] /* Feature_MBP_Delta_60s_min */ <= -2.15950f) {
                                                    return true; /* p_pos=1.000, tau=0.45 */
                                                } else {
                                                    return false; /* p_pos=0.354, tau=0.45 */
                                                }
                                            }
                                        } else {
                                            if (features[33] /* Feature_HR_Std_60s_std */ <= 0.28500f) {
                                                return true; /* p_pos=0.882, tau=0.45 */
                                            } else {
                                                if (features[29] /* Feature_Shock_Index_std */ <= -0.31186f) {
                                                    return true; /* p_pos=0.684, tau=0.45 */
                                                } else {
                                                    return false; /* p_pos=0.162, tau=0.45 */
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
                                                    return false; /* p_pos=0.045, tau=0.45 */
                                                } else {
                                                    return true; /* p_pos=0.600, tau=0.45 */
                                                }
                                            } else {
                                                return true; /* p_pos=0.857, tau=0.45 */
                                            }
                                        } else {
                                            if (features[54] /* Feature_MBP_Mean_60s_min */ <= 0.96081f) {
                                                if (features[34] /* Feature_HR_Delta_60s_std */ <= 0.08364f) {
                                                    return false; /* p_pos=0.268, tau=0.45 */
                                                } else {
                                                    return true; /* p_pos=0.636, tau=0.45 */
                                                }
                                            } else {
                                                if (features[8] /* BT_mean */ <= 0.19922f) {
                                                    return false; /* p_pos=0.286, tau=0.45 */
                                                } else {
                                                    return true; /* p_pos=0.820, tau=0.45 */
                                                }
                                            }
                                        }
                                    } else {
                                        if (features[71] /* Feature_HR_Std_60s_max */ <= -0.37174f) {
                                            if (features[19] /* HR_std */ <= 0.81480f) {
                                                if (features[76] /* HR_slope */ <= 1.32651f) {
                                                    return false; /* p_pos=0.087, tau=0.45 */
                                                } else {
                                                    return true; /* p_pos=0.567, tau=0.45 */
                                                }
                                            } else {
                                                return true; /* p_pos=0.889, tau=0.45 */
                                            }
                                        } else {
                                            if (features[69] /* Feature_Rate_Pressure_Product_max */ <= 0.91254f) {
                                                if (features[17] /* Feature_MBP_Std_60s_mean */ <= -0.60653f) {
                                                    return true; /* p_pos=0.875, tau=0.45 */
                                                } else {
                                                    return false; /* p_pos=0.107, tau=0.45 */
                                                }
                                            } else {
                                                if (features[10] /* Feature_Shock_Index_mean */ <= 0.20873f) {
                                                    return false; /* p_pos=0.152, tau=0.45 */
                                                } else {
                                                    return false; /* p_pos=0.289, tau=0.45 */
                                                }
                                            }
                                        }
                                    }
                                } else {
                                    if (features[12] /* Feature_Rate_Pressure_Product_mean */ <= 1.92890f) {
                                        if (features[9] /* Feature_Pulse_Pressure_mean */ <= -0.04261f) {
                                            if (features[28] /* Feature_Pulse_Pressure_std */ <= 0.80473f) {
                                                if (features[18] /* Feature_MBP_Delta_60s_mean */ <= -0.28278f) {
                                                    return false; /* p_pos=0.133, tau=0.45 */
                                                } else {
                                                    return false; /* p_pos=0.000, tau=0.45 */
                                                }
                                            } else {
                                                return true; /* p_pos=0.571, tau=0.45 */
                                            }
                                        } else {
                                            if (features[34] /* Feature_HR_Delta_60s_std */ <= -0.43630f) {
                                                if (features[4] /* PLETH_SPO2_mean */ <= -0.15181f) {
                                                    return true; /* p_pos=0.745, tau=0.45 */
                                                } else {
                                                    return false; /* p_pos=0.221, tau=0.45 */
                                                }
                                            } else {
                                                if (features[68] /* Feature_Modified_Shock_Index_max */ <= 0.43791f) {
                                                    return true; /* p_pos=0.804, tau=0.45 */
                                                } else {
                                                    return false; /* p_pos=0.222, tau=0.45 */
                                                }
                                            }
                                        }
                                    } else {
                                        if (features[14] /* Feature_HR_Std_60s_mean */ <= -0.64677f) {
                                            return false; /* p_pos=0.027, tau=0.45 */
                                        } else {
                                            if (features[37] /* Feature_MBP_Delta_60s_std */ <= -0.51940f) {
                                                return false; /* p_pos=0.000, tau=0.45 */
                                            } else {
                                                if (features[35] /* Feature_MBP_Mean_60s_std */ <= -0.45243f) {
                                                    return true; /* p_pos=0.891, tau=0.45 */
                                                } else {
                                                    return true; /* p_pos=0.609, tau=0.45 */
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
                                                    return false; /* p_pos=0.200, tau=0.45 */
                                                } else {
                                                    return false; /* p_pos=0.027, tau=0.45 */
                                                }
                                            } else {
                                                return false; /* p_pos=0.375, tau=0.45 */
                                            }
                                        } else {
                                            return false; /* p_pos=0.250, tau=0.45 */
                                        }
                                    } else {
                                        if (features[74] /* Feature_MBP_Std_60s_max */ <= -0.49158f) {
                                            if (features[52] /* Feature_HR_Std_60s_min */ <= 0.52241f) {
                                                if (features[19] /* HR_std */ <= 0.67946f) {
                                                    return false; /* p_pos=0.217, tau=0.45 */
                                                } else {
                                                    return true; /* p_pos=1.000, tau=0.45 */
                                                }
                                            } else {
                                                return true; /* p_pos=0.875, tau=0.45 */
                                            }
                                        } else {
                                            if (features[2] /* ART_DBP_mean */ <= 0.86332f) {
                                                if (features[10] /* Feature_Shock_Index_mean */ <= -0.19280f) {
                                                    return false; /* p_pos=0.219, tau=0.45 */
                                                } else {
                                                    return false; /* p_pos=0.085, tau=0.45 */
                                                }
                                            } else {
                                                return false; /* p_pos=0.419, tau=0.45 */
                                            }
                                        }
                                    }
                                } else {
                                    if (features[19] /* HR_std */ <= -0.62574f) {
                                        return false; /* p_pos=0.088, tau=0.45 */
                                    } else {
                                        if (features[73] /* Feature_MBP_Mean_60s_max */ <= -2.03918f) {
                                            return false; /* p_pos=0.200, tau=0.45 */
                                        } else {
                                            if (features[90] /* Feature_HR_Std_60s_slope */ <= 1.37987f) {
                                                return false; /* p_pos=0.000, tau=0.45 */
                                            } else {
                                                return false; /* p_pos=0.077, tau=0.45 */
                                            }
                                        }
                                    }
                                }
                            } else {
                                if (features[53] /* Feature_HR_Delta_60s_min */ <= -0.01601f) {
                                    if (features[14] /* Feature_HR_Std_60s_mean */ <= -0.37298f) {
                                        return true; /* p_pos=0.750, tau=0.45 */
                                    } else {
                                        if (features[75] /* Feature_MBP_Delta_60s_max */ <= -0.58411f) {
                                            return true; /* p_pos=0.750, tau=0.45 */
                                        } else {
                                            if (features[55] /* Feature_MBP_Std_60s_min */ <= 0.00775f) {
                                                if (features[92] /* Feature_MBP_Mean_60s_slope */ <= 0.32562f) {
                                                    return false; /* p_pos=0.121, tau=0.45 */
                                                } else {
                                                    return false; /* p_pos=0.327, tau=0.45 */
                                                }
                                            } else {
                                                if (features[88] /* Feature_Rate_Pressure_Product_slope */ <= -0.13635f) {
                                                    return false; /* p_pos=0.175, tau=0.45 */
                                                } else {
                                                    return false; /* p_pos=0.011, tau=0.45 */
                                                }
                                            }
                                        }
                                    }
                                } else {
                                    if (features[75] /* Feature_MBP_Delta_60s_max */ <= 2.49221f) {
                                        if (features[0] /* HR_mean */ <= 0.90496f) {
                                            if (features[48] /* Feature_Shock_Index_min */ <= -0.31778f) {
                                                if (features[89] /* Feature_HR_Mean_60s_slope */ <= 2.00332f) {
                                                    return false; /* p_pos=0.000, tau=0.45 */
                                                } else {
                                                    return false; /* p_pos=0.333, tau=0.45 */
                                                }
                                            } else {
                                                if (features[47] /* Feature_Pulse_Pressure_min */ <= -0.51388f) {
                                                    return false; /* p_pos=0.029, tau=0.45 */
                                                } else {
                                                    return false; /* p_pos=0.283, tau=0.45 */
                                                }
                                            }
                                        } else {
                                            if (features[34] /* Feature_HR_Delta_60s_std */ <= -0.31785f) {
                                                if (features[54] /* Feature_MBP_Mean_60s_min */ <= -0.16601f) {
                                                    return false; /* p_pos=0.105, tau=0.45 */
                                                } else {
                                                    return false; /* p_pos=0.360, tau=0.45 */
                                                }
                                            } else {
                                                if (features[43] /* RR_CO2_min */ <= -1.63901f) {
                                                    return false; /* p_pos=0.217, tau=0.45 */
                                                } else {
                                                    return true; /* p_pos=0.658, tau=0.45 */
                                                }
                                            }
                                        }
                                    } else {
                                        return true; /* p_pos=0.686, tau=0.45 */
                                    }
                                }
                            }
                        }
                    } else {
                        if (features[13] /* Feature_HR_Mean_60s_mean */ <= 2.24082f) {
                            if (features[14] /* Feature_HR_Std_60s_mean */ <= -0.76847f) {
                                return false; /* p_pos=0.086, tau=0.45 */
                            } else {
                                if (features[89] /* Feature_HR_Mean_60s_slope */ <= 0.21307f) {
                                    if (features[1] /* ART_SBP_mean */ <= 0.19865f) {
                                        if (features[9] /* Feature_Pulse_Pressure_mean */ <= 0.64082f) {
                                            if (features[54] /* Feature_MBP_Mean_60s_min */ <= 0.18477f) {
                                                return true; /* p_pos=0.939, tau=0.45 */
                                            } else {
                                                return true; /* p_pos=0.625, tau=0.45 */
                                            }
                                        } else {
                                            return false; /* p_pos=0.167, tau=0.45 */
                                        }
                                    } else {
                                        if (features[43] /* RR_CO2_min */ <= 1.23712f) {
                                            if (features[26] /* FIO2_std */ <= -0.20331f) {
                                                if (features[5] /* RR_CO2_mean */ <= -1.35655f) {
                                                    return true; /* p_pos=1.000, tau=0.45 */
                                                } else {
                                                    return false; /* p_pos=0.226, tau=0.45 */
                                                }
                                            } else {
                                                return true; /* p_pos=0.700, tau=0.45 */
                                            }
                                        } else {
                                            if (features[44] /* ETCO2_min */ <= 1.45138f) {
                                                if (features[63] /* ETCO2_max */ <= 1.15487f) {
                                                    return true; /* p_pos=0.848, tau=0.45 */
                                                } else {
                                                    return false; /* p_pos=0.200, tau=0.45 */
                                                }
                                            } else {
                                                return false; /* p_pos=0.000, tau=0.45 */
                                            }
                                        }
                                    }
                                } else {
                                    if (features[90] /* Feature_HR_Std_60s_slope */ <= 0.00007f) {
                                        if (features[63] /* ETCO2_max */ <= 0.56162f) {
                                            if (features[46] /* BT_min */ <= 0.42770f) {
                                                if (features[48] /* Feature_Shock_Index_min */ <= 0.96277f) {
                                                    return true; /* p_pos=0.939, tau=0.45 */
                                                } else {
                                                    return true; /* p_pos=0.727, tau=0.45 */
                                                }
                                            } else {
                                                return false; /* p_pos=0.273, tau=0.45 */
                                            }
                                        } else {
                                            return true; /* p_pos=0.452, tau=0.45 */
                                        }
                                    } else {
                                        if (features[54] /* Feature_MBP_Mean_60s_min */ <= 0.28488f) {
                                            return true; /* p_pos=1.000, tau=0.45 */
                                        } else {
                                            if (features[42] /* PLETH_SPO2_min */ <= 0.33752f) {
                                                return true; /* p_pos=0.611, tau=0.45 */
                                            } else {
                                                if (features[39] /* ART_SBP_min */ <= 0.47446f) {
                                                    return true; /* p_pos=0.625, tau=0.45 */
                                                } else {
                                                    return true; /* p_pos=0.978, tau=0.45 */
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
                                        return false; /* p_pos=0.095, tau=0.45 */
                                    } else {
                                        if (features[6] /* ETCO2_mean */ <= 1.28794f) {
                                            if (features[31] /* Feature_Rate_Pressure_Product_std */ <= -0.64923f) {
                                                return true; /* p_pos=1.000, tau=0.45 */
                                            } else {
                                                if (features[71] /* Feature_HR_Std_60s_max */ <= -0.81702f) {
                                                    return false; /* p_pos=0.222, tau=0.45 */
                                                } else {
                                                    return true; /* p_pos=0.745, tau=0.45 */
                                                }
                                            }
                                        } else {
                                            return false; /* p_pos=0.269, tau=0.45 */
                                        }
                                    }
                                } else {
                                    if (features[31] /* Feature_Rate_Pressure_Product_std */ <= -0.90041f) {
                                        return false; /* p_pos=0.222, tau=0.45 */
                                    } else {
                                        if (features[88] /* Feature_Rate_Pressure_Product_slope */ <= -1.12870f) {
                                            return true; /* p_pos=0.781, tau=0.45 */
                                        } else {
                                            if (features[0] /* HR_mean */ <= 2.41921f) {
                                                return true; /* p_pos=0.909, tau=0.45 */
                                            } else {
                                                if (features[16] /* Feature_MBP_Mean_60s_mean */ <= -0.27835f) {
                                                    return true; /* p_pos=0.800, tau=0.45 */
                                                } else {
                                                    return true; /* p_pos=1.000, tau=0.45 */
                                                }
                                            }
                                        }
                                    }
                                }
                            } else {
                                if (features[51] /* Feature_HR_Mean_60s_min */ <= 1.20703f) {
                                    return false; /* p_pos=0.400, tau=0.45 */
                                } else {
                                    if (features[59] /* ART_DBP_max */ <= 2.88154f) {
                                        if (features[2] /* ART_DBP_mean */ <= 1.55493f) {
                                            if (features[37] /* Feature_MBP_Delta_60s_std */ <= -0.31795f) {
                                                if (features[48] /* Feature_Shock_Index_min */ <= 0.35568f) {
                                                    return true; /* p_pos=0.625, tau=0.45 */
                                                } else {
                                                    return true; /* p_pos=0.960, tau=0.45 */
                                                }
                                            } else {
                                                return true; /* p_pos=1.000, tau=0.45 */
                                            }
                                        } else {
                                            return true; /* p_pos=0.733, tau=0.45 */
                                        }
                                    } else {
                                        return true; /* p_pos=0.625, tau=0.45 */
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
                                                    return false; /* p_pos=0.013, tau=0.45 */
                                                } else {
                                                    return true; /* p_pos=0.800, tau=0.45 */
                                                }
                                            } else {
                                                return false; /* p_pos=0.241, tau=0.45 */
                                            }
                                        } else {
                                            return false; /* p_pos=0.429, tau=0.45 */
                                        }
                                    } else {
                                        return true; /* p_pos=0.692, tau=0.45 */
                                    }
                                } else {
                                    return false; /* p_pos=0.000, tau=0.45 */
                                }
                            } else {
                                if (features[1] /* ART_SBP_mean */ <= -2.50672f) {
                                    if (features[17] /* Feature_MBP_Std_60s_mean */ <= -0.25517f) {
                                        if (features[50] /* Feature_Rate_Pressure_Product_min */ <= -1.30611f) {
                                            return true; /* p_pos=0.654, tau=0.45 */
                                        } else {
                                            return true; /* p_pos=0.960, tau=0.45 */
                                        }
                                    } else {
                                        return false; /* p_pos=0.000, tau=0.45 */
                                    }
                                } else {
                                    if (features[46] /* BT_min */ <= 0.50879f) {
                                        if (features[49] /* Feature_Modified_Shock_Index_min */ <= 9.64177f) {
                                            if (features[27] /* BT_std */ <= -0.03369f) {
                                                if (features[2] /* ART_DBP_mean */ <= -1.54331f) {
                                                    return false; /* p_pos=0.037, tau=0.45 */
                                                } else {
                                                    return false; /* p_pos=0.167, tau=0.45 */
                                                }
                                            } else {
                                                return true; /* p_pos=0.769, tau=0.45 */
                                            }
                                        } else {
                                            return true; /* p_pos=0.500, tau=0.45 */
                                        }
                                    } else {
                                        return true; /* p_pos=1.000, tau=0.45 */
                                    }
                                }
                            }
                        } else {
                            if (features[49] /* Feature_Modified_Shock_Index_min */ <= 8.98122f) {
                                if (features[79] /* ART_MBP_slope */ <= -8.57480f) {
                                    return true; /* p_pos=0.833, tau=0.45 */
                                } else {
                                    if (features[13] /* Feature_HR_Mean_60s_mean */ <= 0.91634f) {
                                        if (features[77] /* ART_SBP_slope */ <= 5.01678f) {
                                            if (features[76] /* HR_slope */ <= 3.54414f) {
                                                if (features[8] /* BT_mean */ <= 0.38369f) {
                                                    return false; /* p_pos=0.021, tau=0.45 */
                                                } else {
                                                    return false; /* p_pos=0.101, tau=0.45 */
                                                }
                                            } else {
                                                return true; /* p_pos=0.500, tau=0.45 */
                                            }
                                        } else {
                                            if (features[54] /* Feature_MBP_Mean_60s_min */ <= -1.89107f) {
                                                if (features[7] /* FIO2_mean */ <= 0.26323f) {
                                                    return false; /* p_pos=0.226, tau=0.45 */
                                                } else {
                                                    return false; /* p_pos=0.019, tau=0.45 */
                                                }
                                            } else {
                                                return false; /* p_pos=0.375, tau=0.45 */
                                            }
                                        }
                                    } else {
                                        if (features[5] /* RR_CO2_mean */ <= -0.07699f) {
                                            if (features[65] /* BT_max */ <= -0.92850f) {
                                                if (features[49] /* Feature_Modified_Shock_Index_min */ <= -0.14809f) {
                                                    return false; /* p_pos=0.077, tau=0.45 */
                                                } else {
                                                    return true; /* p_pos=0.467, tau=0.45 */
                                                }
                                            } else {
                                                if (features[35] /* Feature_MBP_Mean_60s_std */ <= -0.85431f) {
                                                    return true; /* p_pos=1.000, tau=0.45 */
                                                } else {
                                                    return false; /* p_pos=0.135, tau=0.45 */
                                                }
                                            }
                                        } else {
                                            if (features[60] /* ART_MBP_max */ <= 2.46759f) {
                                                if (features[8] /* BT_mean */ <= -3.33271f) {
                                                    return false; /* p_pos=0.300, tau=0.45 */
                                                } else {
                                                    return false; /* p_pos=0.010, tau=0.45 */
                                                }
                                            } else {
                                                return true; /* p_pos=0.500, tau=0.45 */
                                            }
                                        }
                                    }
                                }
                            } else {
                                return true; /* p_pos=0.571, tau=0.45 */
                            }
                        }
                    } else {
                        if (features[68] /* Feature_Modified_Shock_Index_max */ <= 5.88961f) {
                            if (features[50] /* Feature_Rate_Pressure_Product_min */ <= -1.28718f) {
                                if (features[25] /* ETCO2_std */ <= -0.11542f) {
                                    return true; /* p_pos=1.000, tau=0.45 */
                                } else {
                                    if (features[41] /* ART_MBP_min */ <= -2.05955f) {
                                        if (features[41] /* ART_MBP_min */ <= -2.17632f) {
                                            return false; /* p_pos=0.375, tau=0.45 */
                                        } else {
                                            return false; /* p_pos=0.023, tau=0.45 */
                                        }
                                    } else {
                                        return true; /* p_pos=0.529, tau=0.45 */
                                    }
                                }
                            } else {
                                if (features[15] /* Feature_HR_Delta_60s_mean */ <= -0.02066f) {
                                    if (features[0] /* HR_mean */ <= 2.40436f) {
                                        if (features[60] /* ART_MBP_max */ <= -1.52936f) {
                                            return true; /* p_pos=1.000, tau=0.45 */
                                        } else {
                                            if (features[71] /* Feature_HR_Std_60s_max */ <= 0.02394f) {
                                                return false; /* p_pos=0.065, tau=0.45 */
                                            } else {
                                                return false; /* p_pos=0.281, tau=0.45 */
                                            }
                                        }
                                    } else {
                                        if (features[2] /* ART_DBP_mean */ <= -1.99050f) {
                                            return true; /* p_pos=0.875, tau=0.45 */
                                        } else {
                                            if (features[68] /* Feature_Modified_Shock_Index_max */ <= 3.31100f) {
                                                return true; /* p_pos=0.800, tau=0.45 */
                                            } else {
                                                return true; /* p_pos=1.000, tau=0.45 */
                                            }
                                        }
                                    }
                                } else {
                                    if (features[39] /* ART_SBP_min */ <= -1.84016f) {
                                        if (features[64] /* FIO2_max */ <= 1.97052f) {
                                            return true; /* p_pos=1.000, tau=0.45 */
                                        } else {
                                            return true; /* p_pos=0.800, tau=0.45 */
                                        }
                                    } else {
                                        return true; /* p_pos=0.750, tau=0.45 */
                                    }
                                }
                            }
                        } else {
                            if (features[38] /* HR_min */ <= 2.61559f) {
                                if (features[20] /* ART_SBP_std */ <= 2.71085f) {
                                    if (features[3] /* ART_MBP_mean */ <= -2.67254f) {
                                        return false; /* p_pos=0.286, tau=0.45 */
                                    } else {
                                        if (features[43] /* RR_CO2_min */ <= -1.90048f) {
                                            return true; /* p_pos=0.667, tau=0.45 */
                                        } else {
                                            return true; /* p_pos=0.979, tau=0.45 */
                                        }
                                    }
                                } else {
                                    return false; /* p_pos=0.389, tau=0.45 */
                                }
                            } else {
                                if (features[26] /* FIO2_std */ <= -0.42424f) {
                                    return true; /* p_pos=0.882, tau=0.45 */
                                } else {
                                    return true; /* p_pos=1.000, tau=0.45 */
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
                                            return true; /* p_pos=0.929, tau=0.45 */
                                        } else {
                                            if (features[14] /* Feature_HR_Std_60s_mean */ <= -0.91053f) {
                                                return true; /* p_pos=1.000, tau=0.45 */
                                            } else {
                                                if (features[49] /* Feature_Modified_Shock_Index_min */ <= 6.10443f) {
                                                    return false; /* p_pos=0.044, tau=0.45 */
                                                } else {
                                                    return false; /* p_pos=0.312, tau=0.45 */
                                                }
                                            }
                                        }
                                    } else {
                                        if (features[70] /* Feature_HR_Mean_60s_max */ <= 0.92135f) {
                                            if (features[13] /* Feature_HR_Mean_60s_mean */ <= -0.01568f) {
                                                if (features[57] /* HR_max */ <= 0.73167f) {
                                                    return false; /* p_pos=0.037, tau=0.45 */
                                                } else {
                                                    return false; /* p_pos=0.333, tau=0.45 */
                                                }
                                            } else {
                                                if (features[64] /* FIO2_max */ <= -0.87730f) {
                                                    return true; /* p_pos=0.667, tau=0.45 */
                                                } else {
                                                    return false; /* p_pos=0.091, tau=0.45 */
                                                }
                                            }
                                        } else {
                                            if (features[26] /* FIO2_std */ <= 1.44106f) {
                                                if (features[14] /* Feature_HR_Std_60s_mean */ <= 0.30286f) {
                                                    return false; /* p_pos=0.150, tau=0.45 */
                                                } else {
                                                    return true; /* p_pos=0.531, tau=0.45 */
                                                }
                                            } else {
                                                if (features[69] /* Feature_Rate_Pressure_Product_max */ <= 1.14145f) {
                                                    return true; /* p_pos=0.767, tau=0.45 */
                                                } else {
                                                    return false; /* p_pos=0.100, tau=0.45 */
                                                }
                                            }
                                        }
                                    }
                                } else {
                                    if (features[33] /* Feature_HR_Std_60s_std */ <= -0.38034f) {
                                        if (features[76] /* HR_slope */ <= 1.14170f) {
                                            if (features[7] /* FIO2_mean */ <= -0.81824f) {
                                                if (features[65] /* BT_max */ <= 0.11721f) {
                                                    return false; /* p_pos=0.108, tau=0.45 */
                                                } else {
                                                    return true; /* p_pos=0.621, tau=0.45 */
                                                }
                                            } else {
                                                if (features[25] /* ETCO2_std */ <= 5.87660f) {
                                                    return false; /* p_pos=0.079, tau=0.45 */
                                                } else {
                                                    return true; /* p_pos=1.000, tau=0.45 */
                                                }
                                            }
                                        } else {
                                            return true; /* p_pos=0.500, tau=0.45 */
                                        }
                                    } else {
                                        if (features[31] /* Feature_Rate_Pressure_Product_std */ <= 0.53690f) {
                                            if (features[76] /* HR_slope */ <= 0.58730f) {
                                                if (features[5] /* RR_CO2_mean */ <= -1.28979f) {
                                                    return false; /* p_pos=0.329, tau=0.45 */
                                                } else {
                                                    return false; /* p_pos=0.115, tau=0.45 */
                                                }
                                            } else {
                                                if (features[29] /* Feature_Shock_Index_std */ <= 1.38604f) {
                                                    return false; /* p_pos=0.316, tau=0.45 */
                                                } else {
                                                    return true; /* p_pos=1.000, tau=0.45 */
                                                }
                                            }
                                        } else {
                                            if (features[6] /* ETCO2_mean */ <= 0.81186f) {
                                                if (features[54] /* Feature_MBP_Mean_60s_min */ <= -0.34220f) {
                                                    return true; /* p_pos=0.493, tau=0.45 */
                                                } else {
                                                    return false; /* p_pos=0.243, tau=0.45 */
                                                }
                                            } else {
                                                return false; /* p_pos=0.000, tau=0.45 */
                                            }
                                        }
                                    }
                                }
                            } else {
                                if (features[24] /* RR_CO2_std */ <= -0.04031f) {
                                    if (features[28] /* Feature_Pulse_Pressure_std */ <= -0.81586f) {
                                        return true; /* p_pos=0.739, tau=0.45 */
                                    } else {
                                        if (features[37] /* Feature_MBP_Delta_60s_std */ <= -0.53033f) {
                                            if (features[82] /* ETCO2_slope */ <= -0.20597f) {
                                                if (features[0] /* HR_mean */ <= 2.21264f) {
                                                    return false; /* p_pos=0.105, tau=0.45 */
                                                } else {
                                                    return true; /* p_pos=0.667, tau=0.45 */
                                                }
                                            } else {
                                                if (features[41] /* ART_MBP_min */ <= 0.28378f) {
                                                    return false; /* p_pos=0.020, tau=0.45 */
                                                } else {
                                                    return false; /* p_pos=0.286, tau=0.45 */
                                                }
                                            }
                                        } else {
                                            if (features[66] /* Feature_Pulse_Pressure_max */ <= -0.71210f) {
                                                if (features[0] /* HR_mean */ <= 2.06428f) {
                                                    return false; /* p_pos=0.253, tau=0.45 */
                                                } else {
                                                    return true; /* p_pos=0.606, tau=0.45 */
                                                }
                                            } else {
                                                if (features[50] /* Feature_Rate_Pressure_Product_min */ <= 1.30887f) {
                                                    return false; /* p_pos=0.201, tau=0.45 */
                                                } else {
                                                    return true; /* p_pos=0.553, tau=0.45 */
                                                }
                                            }
                                        }
                                    }
                                } else {
                                    if (features[30] /* Feature_Modified_Shock_Index_std */ <= -0.45293f) {
                                        return true; /* p_pos=1.000, tau=0.45 */
                                    } else {
                                        if (features[59] /* ART_DBP_max */ <= 0.45162f) {
                                            if (features[49] /* Feature_Modified_Shock_Index_min */ <= 1.11307f) {
                                                return true; /* p_pos=0.853, tau=0.45 */
                                            } else {
                                                if (features[46] /* BT_min */ <= 0.18445f) {
                                                    return false; /* p_pos=0.371, tau=0.45 */
                                                } else {
                                                    return false; /* p_pos=0.087, tau=0.45 */
                                                }
                                            }
                                        } else {
                                            return false; /* p_pos=0.077, tau=0.45 */
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
                                                    return true; /* p_pos=0.487, tau=0.45 */
                                                } else {
                                                    return false; /* p_pos=0.146, tau=0.45 */
                                                }
                                            } else {
                                                if (features[7] /* FIO2_mean */ <= 1.33030f) {
                                                    return false; /* p_pos=0.115, tau=0.45 */
                                                } else {
                                                    return false; /* p_pos=0.321, tau=0.45 */
                                                }
                                            }
                                        } else {
                                            if (features[44] /* ETCO2_min */ <= 1.65223f) {
                                                if (features[13] /* Feature_HR_Mean_60s_mean */ <= 1.07760f) {
                                                    return false; /* p_pos=0.069, tau=0.45 */
                                                } else {
                                                    return false; /* p_pos=0.165, tau=0.45 */
                                                }
                                            } else {
                                                return true; /* p_pos=0.600, tau=0.45 */
                                            }
                                        }
                                    } else {
                                        if (features[11] /* Feature_Modified_Shock_Index_mean */ <= 1.81088f) {
                                            if (features[14] /* Feature_HR_Std_60s_mean */ <= -0.20803f) {
                                                if (features[65] /* BT_max */ <= 0.28189f) {
                                                    return false; /* p_pos=0.232, tau=0.45 */
                                                } else {
                                                    return true; /* p_pos=0.722, tau=0.45 */
                                                }
                                            } else {
                                                if (features[62] /* RR_CO2_max */ <= -0.13284f) {
                                                    return true; /* p_pos=0.476, tau=0.45 */
                                                } else {
                                                    return false; /* p_pos=0.334, tau=0.45 */
                                                }
                                            }
                                        } else {
                                            if (features[53] /* Feature_HR_Delta_60s_min */ <= -0.01601f) {
                                                if (features[36] /* Feature_MBP_Std_60s_std */ <= -0.20760f) {
                                                    return true; /* p_pos=0.938, tau=0.45 */
                                                } else {
                                                    return false; /* p_pos=0.447, tau=0.45 */
                                                }
                                            } else {
                                                if (features[59] /* ART_DBP_max */ <= -0.98140f) {
                                                    return false; /* p_pos=0.174, tau=0.45 */
                                                } else {
                                                    return true; /* p_pos=0.523, tau=0.45 */
                                                }
                                            }
                                        }
                                    }
                                } else {
                                    if (features[72] /* Feature_HR_Delta_60s_max */ <= 0.47412f) {
                                        if (features[28] /* Feature_Pulse_Pressure_std */ <= 3.79277f) {
                                            if (features[70] /* Feature_HR_Mean_60s_max */ <= 1.45082f) {
                                                if (features[70] /* Feature_HR_Mean_60s_max */ <= 1.23687f) {
                                                    return false; /* p_pos=0.265, tau=0.45 */
                                                } else {
                                                    return true; /* p_pos=0.482, tau=0.45 */
                                                }
                                            } else {
                                                if (features[48] /* Feature_Shock_Index_min */ <= 1.91090f) {
                                                    return true; /* p_pos=0.750, tau=0.45 */
                                                } else {
                                                    return true; /* p_pos=0.931, tau=0.45 */
                                                }
                                            }
                                        } else {
                                            return false; /* p_pos=0.071, tau=0.45 */
                                        }
                                    } else {
                                        if (features[76] /* HR_slope */ <= 1.41891f) {
                                            if (features[50] /* Feature_Rate_Pressure_Product_min */ <= 1.23043f) {
                                                if (features[13] /* Feature_HR_Mean_60s_mean */ <= 1.05503f) {
                                                    return false; /* p_pos=0.126, tau=0.45 */
                                                } else {
                                                    return false; /* p_pos=0.370, tau=0.45 */
                                                }
                                            } else {
                                                return true; /* p_pos=0.733, tau=0.45 */
                                            }
                                        } else {
                                            if (features[0] /* HR_mean */ <= 1.69396f) {
                                                if (features[44] /* ETCO2_min */ <= 1.45138f) {
                                                    return false; /* p_pos=0.448, tau=0.45 */
                                                } else {
                                                    return true; /* p_pos=1.000, tau=0.45 */
                                                }
                                            } else {
                                                return true; /* p_pos=0.875, tau=0.45 */
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
                                                    return false; /* p_pos=0.423, tau=0.45 */
                                                } else {
                                                    return true; /* p_pos=0.767, tau=0.45 */
                                                }
                                            } else {
                                                if (features[7] /* FIO2_mean */ <= -0.79207f) {
                                                    return true; /* p_pos=0.671, tau=0.45 */
                                                } else {
                                                    return true; /* p_pos=0.936, tau=0.45 */
                                                }
                                            }
                                        } else {
                                            if (features[5] /* RR_CO2_mean */ <= 1.13010f) {
                                                if (features[60] /* ART_MBP_max */ <= 2.11886f) {
                                                    return false; /* p_pos=0.374, tau=0.45 */
                                                } else {
                                                    return true; /* p_pos=0.800, tau=0.45 */
                                                }
                                            } else {
                                                return true; /* p_pos=0.971, tau=0.45 */
                                            }
                                        }
                                    } else {
                                        return false; /* p_pos=0.000, tau=0.45 */
                                    }
                                } else {
                                    if (features[13] /* Feature_HR_Mean_60s_mean */ <= 2.28221f) {
                                        if (features[34] /* Feature_HR_Delta_60s_std */ <= -0.41485f) {
                                            if (features[53] /* Feature_HR_Delta_60s_min */ <= 0.39719f) {
                                                if (features[46] /* BT_min */ <= 0.18445f) {
                                                    return false; /* p_pos=0.440, tau=0.45 */
                                                } else {
                                                    return false; /* p_pos=0.000, tau=0.45 */
                                                }
                                            } else {
                                                return true; /* p_pos=0.739, tau=0.45 */
                                            }
                                        } else {
                                            if (features[47] /* Feature_Pulse_Pressure_min */ <= 0.91774f) {
                                                if (features[44] /* ETCO2_min */ <= 0.44710f) {
                                                    return true; /* p_pos=0.849, tau=0.45 */
                                                } else {
                                                    return true; /* p_pos=0.582, tau=0.45 */
                                                }
                                            } else {
                                                return false; /* p_pos=0.167, tau=0.45 */
                                            }
                                        }
                                    } else {
                                        if (features[6] /* ETCO2_mean */ <= 2.99077f) {
                                            if (features[19] /* HR_std */ <= -0.29461f) {
                                                if (features[72] /* Feature_HR_Delta_60s_max */ <= -0.23635f) {
                                                    return true; /* p_pos=0.993, tau=0.45 */
                                                } else {
                                                    return true; /* p_pos=0.952, tau=0.45 */
                                                }
                                            } else {
                                                if (features[31] /* Feature_Rate_Pressure_Product_std */ <= -0.40589f) {
                                                    return true; /* p_pos=0.819, tau=0.45 */
                                                } else {
                                                    return true; /* p_pos=0.939, tau=0.45 */
                                                }
                                            }
                                        } else {
                                            return false; /* p_pos=0.000, tau=0.45 */
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
                                                    return false; /* p_pos=0.042, tau=0.45 */
                                                } else {
                                                    return false; /* p_pos=0.091, tau=0.45 */
                                                }
                                            } else {
                                                if (features[9] /* Feature_Pulse_Pressure_mean */ <= -1.29297f) {
                                                    return true; /* p_pos=0.929, tau=0.45 */
                                                } else {
                                                    return false; /* p_pos=0.214, tau=0.45 */
                                                }
                                            }
                                        } else {
                                            if (features[78] /* ART_DBP_slope */ <= -1.42346f) {
                                                if (features[94] /* Feature_MBP_Delta_60s_slope */ <= -0.71815f) {
                                                    return false; /* p_pos=0.059, tau=0.45 */
                                                } else {
                                                    return true; /* p_pos=0.569, tau=0.45 */
                                                }
                                            } else {
                                                if (features[65] /* BT_max */ <= 0.50421f) {
                                                    return false; /* p_pos=0.176, tau=0.45 */
                                                } else {
                                                    return true; /* p_pos=0.577, tau=0.45 */
                                                }
                                            }
                                        }
                                    } else {
                                        if (features[3] /* ART_MBP_mean */ <= -0.44532f) {
                                            if (features[68] /* Feature_Modified_Shock_Index_max */ <= 0.69267f) {
                                                if (features[30] /* Feature_Modified_Shock_Index_std */ <= -0.28137f) {
                                                    return false; /* p_pos=0.125, tau=0.45 */
                                                } else {
                                                    return false; /* p_pos=0.000, tau=0.45 */
                                                }
                                            } else {
                                                if (features[12] /* Feature_Rate_Pressure_Product_mean */ <= 0.65198f) {
                                                    return false; /* p_pos=0.162, tau=0.45 */
                                                } else {
                                                    return true; /* p_pos=0.553, tau=0.45 */
                                                }
                                            }
                                        } else {
                                            if (features[76] /* HR_slope */ <= 0.12529f) {
                                                if (features[4] /* PLETH_SPO2_mean */ <= 0.32122f) {
                                                    return true; /* p_pos=0.550, tau=0.45 */
                                                } else {
                                                    return false; /* p_pos=0.351, tau=0.45 */
                                                }
                                            } else {
                                                if (features[17] /* Feature_MBP_Std_60s_mean */ <= -0.38418f) {
                                                    return true; /* p_pos=0.917, tau=0.45 */
                                                } else {
                                                    return true; /* p_pos=0.588, tau=0.45 */
                                                }
                                            }
                                        }
                                    }
                                } else {
                                    if (features[51] /* Feature_HR_Mean_60s_min */ <= 1.24529f) {
                                        if (features[90] /* Feature_HR_Std_60s_slope */ <= 1.63031f) {
                                            if (features[7] /* FIO2_mean */ <= 2.06056f) {
                                                if (features[5] /* RR_CO2_mean */ <= 0.40915f) {
                                                    return false; /* p_pos=0.299, tau=0.45 */
                                                } else {
                                                    return false; /* p_pos=0.138, tau=0.45 */
                                                }
                                            } else {
                                                if (features[20] /* ART_SBP_std */ <= 0.65435f) {
                                                    return false; /* p_pos=0.107, tau=0.45 */
                                                } else {
                                                    return false; /* p_pos=0.030, tau=0.45 */
                                                }
                                            }
                                        } else {
                                            if (features[7] /* FIO2_mean */ <= 1.43520f) {
                                                return false; /* p_pos=0.000, tau=0.45 */
                                            } else {
                                                return true; /* p_pos=0.489, tau=0.45 */
                                            }
                                        }
                                    } else {
                                        if (features[38] /* HR_min */ <= 1.59783f) {
                                            if (features[26] /* FIO2_std */ <= -0.37237f) {
                                                if (features[25] /* ETCO2_std */ <= -0.48981f) {
                                                    return true; /* p_pos=0.833, tau=0.45 */
                                                } else {
                                                    return false; /* p_pos=0.171, tau=0.45 */
                                                }
                                            } else {
                                                if (features[54] /* Feature_MBP_Mean_60s_min */ <= -0.16281f) {
                                                    return false; /* p_pos=0.379, tau=0.45 */
                                                } else {
                                                    return true; /* p_pos=0.792, tau=0.45 */
                                                }
                                            }
                                        } else {
                                            if (features[42] /* PLETH_SPO2_min */ <= -1.22221f) {
                                                return true; /* p_pos=0.486, tau=0.45 */
                                            } else {
                                                if (features[57] /* HR_max */ <= 1.81562f) {
                                                    return false; /* p_pos=0.102, tau=0.45 */
                                                } else {
                                                    return true; /* p_pos=0.824, tau=0.45 */
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
                                                    return false; /* p_pos=0.157, tau=0.45 */
                                                } else {
                                                    return false; /* p_pos=0.067, tau=0.45 */
                                                }
                                            } else {
                                                if (features[59] /* ART_DBP_max */ <= -0.44142f) {
                                                    return true; /* p_pos=0.556, tau=0.45 */
                                                } else {
                                                    return false; /* p_pos=0.193, tau=0.45 */
                                                }
                                            }
                                        } else {
                                            if (features[31] /* Feature_Rate_Pressure_Product_std */ <= 2.18563f) {
                                                if (features[90] /* Feature_HR_Std_60s_slope */ <= 1.95071f) {
                                                    return false; /* p_pos=0.204, tau=0.45 */
                                                } else {
                                                    return true; /* p_pos=0.870, tau=0.45 */
                                                }
                                            } else {
                                                return true; /* p_pos=0.857, tau=0.45 */
                                            }
                                        }
                                    } else {
                                        if (features[7] /* FIO2_mean */ <= -0.86174f) {
                                            return true; /* p_pos=1.000, tau=0.45 */
                                        } else {
                                            if (features[72] /* Feature_HR_Delta_60s_max */ <= 0.06814f) {
                                                if (features[25] /* ETCO2_std */ <= 1.03335f) {
                                                    return false; /* p_pos=0.209, tau=0.45 */
                                                } else {
                                                    return true; /* p_pos=0.600, tau=0.45 */
                                                }
                                            } else {
                                                if (features[41] /* ART_MBP_min */ <= 0.14365f) {
                                                    return false; /* p_pos=0.413, tau=0.45 */
                                                } else {
                                                    return true; /* p_pos=0.711, tau=0.45 */
                                                }
                                            }
                                        }
                                    }
                                } else {
                                    if (features[70] /* Feature_HR_Mean_60s_max */ <= 1.47997f) {
                                        if (features[19] /* HR_std */ <= -0.09469f) {
                                            if (features[41] /* ART_MBP_min */ <= 0.19036f) {
                                                if (features[11] /* Feature_Modified_Shock_Index_mean */ <= 1.43586f) {
                                                    return false; /* p_pos=0.130, tau=0.45 */
                                                } else {
                                                    return true; /* p_pos=0.812, tau=0.45 */
                                                }
                                            } else {
                                                return true; /* p_pos=0.647, tau=0.45 */
                                            }
                                        } else {
                                            return true; /* p_pos=0.857, tau=0.45 */
                                        }
                                    } else {
                                        if (features[76] /* HR_slope */ <= 0.95690f) {
                                            if (features[84] /* BT_slope */ <= -0.09351f) {
                                                return true; /* p_pos=0.500, tau=0.45 */
                                            } else {
                                                if (features[58] /* ART_SBP_max */ <= 0.14383f) {
                                                    return true; /* p_pos=0.954, tau=0.45 */
                                                } else {
                                                    return true; /* p_pos=0.630, tau=0.45 */
                                                }
                                            }
                                        } else {
                                            if (features[85] /* Feature_Pulse_Pressure_slope */ <= -0.91399f) {
                                                return true; /* p_pos=0.600, tau=0.45 */
                                            } else {
                                                if (features[84] /* BT_slope */ <= 0.03784f) {
                                                    return true; /* p_pos=1.000, tau=0.45 */
                                                } else {
                                                    return true; /* p_pos=0.800, tau=0.45 */
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
                                                    return false; /* p_pos=0.173, tau=0.45 */
                                                } else {
                                                    return true; /* p_pos=0.833, tau=0.45 */
                                                }
                                            } else {
                                                if (features[64] /* FIO2_max */ <= -0.65481f) {
                                                    return true; /* p_pos=0.605, tau=0.45 */
                                                } else {
                                                    return true; /* p_pos=1.000, tau=0.45 */
                                                }
                                            }
                                        } else {
                                            if (features[48] /* Feature_Shock_Index_min */ <= 3.17104f) {
                                                if (features[30] /* Feature_Modified_Shock_Index_std */ <= -0.50292f) {
                                                    return true; /* p_pos=0.526, tau=0.45 */
                                                } else {
                                                    return true; /* p_pos=0.909, tau=0.45 */
                                                }
                                            } else {
                                                return false; /* p_pos=0.000, tau=0.45 */
                                            }
                                        }
                                    } else {
                                        if (features[11] /* Feature_Modified_Shock_Index_mean */ <= 2.32398f) {
                                            if (features[16] /* Feature_MBP_Mean_60s_mean */ <= 0.49224f) {
                                                if (features[91] /* Feature_HR_Delta_60s_slope */ <= -0.25272f) {
                                                    return true; /* p_pos=0.889, tau=0.45 */
                                                } else {
                                                    return true; /* p_pos=0.994, tau=0.45 */
                                                }
                                            } else {
                                                return true; /* p_pos=0.800, tau=0.45 */
                                            }
                                        } else {
                                            return true; /* p_pos=0.818, tau=0.45 */
                                        }
                                    }
                                } else {
                                    if (features[68] /* Feature_Modified_Shock_Index_max */ <= 0.45544f) {
                                        return true; /* p_pos=1.000, tau=0.45 */
                                    } else {
                                        if (features[28] /* Feature_Pulse_Pressure_std */ <= 1.85183f) {
                                            if (features[89] /* Feature_HR_Mean_60s_slope */ <= 0.25083f) {
                                                if (features[91] /* Feature_HR_Delta_60s_slope */ <= 0.33623f) {
                                                    return false; /* p_pos=0.195, tau=0.45 */
                                                } else {
                                                    return true; /* p_pos=0.750, tau=0.45 */
                                                }
                                            } else {
                                                return true; /* p_pos=0.917, tau=0.45 */
                                            }
                                        } else {
                                            return true; /* p_pos=1.000, tau=0.45 */
                                        }
                                    }
                                }
                            } else {
                                if (features[13] /* Feature_HR_Mean_60s_mean */ <= 2.55808f) {
                                    if (features[17] /* Feature_MBP_Std_60s_mean */ <= -0.45808f) {
                                        return true; /* p_pos=1.000, tau=0.45 */
                                    } else {
                                        if (features[32] /* Feature_HR_Mean_60s_std */ <= -0.21954f) {
                                            if (features[92] /* Feature_MBP_Mean_60s_slope */ <= -0.82514f) {
                                                return true; /* p_pos=0.750, tau=0.45 */
                                            } else {
                                                if (features[50] /* Feature_Rate_Pressure_Product_min */ <= 0.42029f) {
                                                    return true; /* p_pos=0.800, tau=0.45 */
                                                } else {
                                                    return true; /* p_pos=0.988, tau=0.45 */
                                                }
                                            }
                                        } else {
                                            if (features[43] /* RR_CO2_min */ <= 3.85179f) {
                                                if (features[57] /* HR_max */ <= 1.17328f) {
                                                    return true; /* p_pos=0.702, tau=0.45 */
                                                } else {
                                                    return true; /* p_pos=0.877, tau=0.45 */
                                                }
                                            } else {
                                                return false; /* p_pos=0.000, tau=0.45 */
                                            }
                                        }
                                    }
                                } else {
                                    if (features[14] /* Feature_HR_Std_60s_mean */ <= -0.93233f) {
                                        return false; /* p_pos=0.000, tau=0.45 */
                                    } else {
                                        if (features[19] /* HR_std */ <= 0.23816f) {
                                            if (features[13] /* Feature_HR_Mean_60s_mean */ <= 5.55340f) {
                                                if (features[51] /* Feature_HR_Mean_60s_min */ <= 2.80436f) {
                                                    return true; /* p_pos=0.967, tau=0.45 */
                                                } else {
                                                    return true; /* p_pos=1.000, tau=0.45 */
                                                }
                                            } else {
                                                return true; /* p_pos=0.800, tau=0.45 */
                                            }
                                        } else {
                                            if (features[3] /* ART_MBP_mean */ <= -0.15888f) {
                                                if (features[93] /* Feature_MBP_Std_60s_slope */ <= -4.34014f) {
                                                    return true; /* p_pos=0.800, tau=0.45 */
                                                } else {
                                                    return true; /* p_pos=1.000, tau=0.45 */
                                                }
                                            } else {
                                                if (features[27] /* BT_std */ <= -0.27547f) {
                                                    return true; /* p_pos=0.690, tau=0.45 */
                                                } else {
                                                    return true; /* p_pos=0.939, tau=0.45 */
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
                                                    return false; /* p_pos=0.006, tau=0.45 */
                                                } else {
                                                    return false; /* p_pos=0.400, tau=0.45 */
                                                }
                                            } else {
                                                if (features[86] /* Feature_Shock_Index_slope */ <= 0.48041f) {
                                                    return false; /* p_pos=0.034, tau=0.45 */
                                                } else {
                                                    return false; /* p_pos=0.125, tau=0.45 */
                                                }
                                            }
                                        } else {
                                            if (features[26] /* FIO2_std */ <= 0.06921f) {
                                                if (features[17] /* Feature_MBP_Std_60s_mean */ <= -0.56510f) {
                                                    return false; /* p_pos=0.152, tau=0.45 */
                                                } else {
                                                    return false; /* p_pos=0.043, tau=0.45 */
                                                }
                                            } else {
                                                if (features[38] /* HR_min */ <= -1.38761f) {
                                                    return true; /* p_pos=0.833, tau=0.45 */
                                                } else {
                                                    return false; /* p_pos=0.125, tau=0.45 */
                                                }
                                            }
                                        }
                                    } else {
                                        if (features[65] /* BT_max */ <= -3.37397f) {
                                            return true; /* p_pos=0.520, tau=0.45 */
                                        } else {
                                            if (features[92] /* Feature_MBP_Mean_60s_slope */ <= 2.57232f) {
                                                if (features[17] /* Feature_MBP_Std_60s_mean */ <= 5.78594f) {
                                                    return false; /* p_pos=0.082, tau=0.45 */
                                                } else {
                                                    return true; /* p_pos=0.750, tau=0.45 */
                                                }
                                            } else {
                                                return false; /* p_pos=0.444, tau=0.45 */
                                            }
                                        }
                                    }
                                } else {
                                    return true; /* p_pos=0.536, tau=0.45 */
                                }
                            } else {
                                if (features[57] /* HR_max */ <= 0.69152f) {
                                    if (features[11] /* Feature_Modified_Shock_Index_mean */ <= 7.96100f) {
                                        if (features[68] /* Feature_Modified_Shock_Index_max */ <= 0.12034f) {
                                            if (features[51] /* Feature_HR_Mean_60s_min */ <= -2.20930f) {
                                                return false; /* p_pos=0.244, tau=0.45 */
                                            } else {
                                                if (features[76] /* HR_slope */ <= 1.51131f) {
                                                    return false; /* p_pos=0.054, tau=0.45 */
                                                } else {
                                                    return false; /* p_pos=0.120, tau=0.45 */
                                                }
                                            }
                                        } else {
                                            if (features[0] /* HR_mean */ <= 1.46602f) {
                                                if (features[67] /* Feature_Shock_Index_max */ <= 1.53706f) {
                                                    return false; /* p_pos=0.109, tau=0.45 */
                                                } else {
                                                    return false; /* p_pos=0.039, tau=0.45 */
                                                }
                                            } else {
                                                return true; /* p_pos=0.800, tau=0.45 */
                                            }
                                        }
                                    } else {
                                        return true; /* p_pos=0.667, tau=0.45 */
                                    }
                                } else {
                                    if (features[1] /* ART_SBP_mean */ <= -0.63389f) {
                                        if (features[54] /* Feature_MBP_Mean_60s_min */ <= -0.83313f) {
                                            if (features[13] /* Feature_HR_Mean_60s_mean */ <= 1.02330f) {
                                                if (features[46] /* BT_min */ <= -3.24548f) {
                                                    return true; /* p_pos=0.475, tau=0.45 */
                                                } else {
                                                    return false; /* p_pos=0.094, tau=0.45 */
                                                }
                                            } else {
                                                if (features[25] /* ETCO2_std */ <= 2.90806f) {
                                                    return true; /* p_pos=0.644, tau=0.45 */
                                                } else {
                                                    return false; /* p_pos=0.067, tau=0.45 */
                                                }
                                            }
                                        } else {
                                            if (features[17] /* Feature_MBP_Std_60s_mean */ <= 0.26352f) {
                                                if (features[12] /* Feature_Rate_Pressure_Product_mean */ <= 0.11199f) {
                                                    return false; /* p_pos=0.343, tau=0.45 */
                                                } else {
                                                    return true; /* p_pos=0.818, tau=0.45 */
                                                }
                                            } else {
                                                if (features[22] /* ART_MBP_std */ <= 1.07978f) {
                                                    return false; /* p_pos=0.017, tau=0.45 */
                                                } else {
                                                    return false; /* p_pos=0.294, tau=0.45 */
                                                }
                                            }
                                        }
                                    } else {
                                        if (features[38] /* HR_min */ <= 0.03726f) {
                                            if (features[0] /* HR_mean */ <= 1.42754f) {
                                                if (features[72] /* Feature_HR_Delta_60s_max */ <= 0.57562f) {
                                                    return false; /* p_pos=0.224, tau=0.45 */
                                                } else {
                                                    return false; /* p_pos=0.087, tau=0.45 */
                                                }
                                            } else {
                                                return true; /* p_pos=0.786, tau=0.45 */
                                            }
                                        } else {
                                            if (features[51] /* Feature_HR_Mean_60s_min */ <= 1.46135f) {
                                                if (features[5] /* RR_CO2_mean */ <= -1.13287f) {
                                                    return false; /* p_pos=0.330, tau=0.45 */
                                                } else {
                                                    return false; /* p_pos=0.149, tau=0.45 */
                                                }
                                            } else {
                                                if (features[40] /* ART_DBP_min */ <= 0.46154f) {
                                                    return true; /* p_pos=0.714, tau=0.45 */
                                                } else {
                                                    return false; /* p_pos=0.208, tau=0.45 */
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
                                                    return true; /* p_pos=0.704, tau=0.45 */
                                                } else {
                                                    return false; /* p_pos=0.197, tau=0.45 */
                                                }
                                            } else {
                                                if (features[30] /* Feature_Modified_Shock_Index_std */ <= -0.07641f) {
                                                    return false; /* p_pos=0.059, tau=0.45 */
                                                } else {
                                                    return false; /* p_pos=0.429, tau=0.45 */
                                                }
                                            }
                                        } else {
                                            return true; /* p_pos=0.792, tau=0.45 */
                                        }
                                    } else {
                                        if (features[55] /* Feature_MBP_Std_60s_min */ <= 0.38066f) {
                                            if (features[53] /* Feature_HR_Delta_60s_min */ <= -0.63580f) {
                                                if (features[3] /* ART_MBP_mean */ <= 0.25726f) {
                                                    return true; /* p_pos=0.600, tau=0.45 */
                                                } else {
                                                    return false; /* p_pos=0.119, tau=0.45 */
                                                }
                                            } else {
                                                if (features[26] /* FIO2_std */ <= 1.45162f) {
                                                    return false; /* p_pos=0.011, tau=0.45 */
                                                } else {
                                                    return true; /* p_pos=0.500, tau=0.45 */
                                                }
                                            }
                                        } else {
                                            return false; /* p_pos=0.364, tau=0.45 */
                                        }
                                    }
                                } else {
                                    if (features[62] /* RR_CO2_max */ <= -0.63580f) {
                                        return false; /* p_pos=0.000, tau=0.45 */
                                    } else {
                                        return true; /* p_pos=0.689, tau=0.45 */
                                    }
                                }
                            } else {
                                if (features[51] /* Feature_HR_Mean_60s_min */ <= 1.80005f) {
                                    if (features[22] /* ART_MBP_std */ <= -0.50274f) {
                                        if (features[25] /* ETCO2_std */ <= -0.15865f) {
                                            if (features[3] /* ART_MBP_mean */ <= 0.07884f) {
                                                if (features[43] /* RR_CO2_min */ <= 0.71419f) {
                                                    return true; /* p_pos=0.529, tau=0.45 */
                                                } else {
                                                    return true; /* p_pos=0.788, tau=0.45 */
                                                }
                                            } else {
                                                return false; /* p_pos=0.300, tau=0.45 */
                                            }
                                        } else {
                                            if (features[21] /* ART_DBP_std */ <= -0.74701f) {
                                                return true; /* p_pos=0.733, tau=0.45 */
                                            } else {
                                                if (features[32] /* Feature_HR_Mean_60s_std */ <= -0.28068f) {
                                                    return true; /* p_pos=0.778, tau=0.45 */
                                                } else {
                                                    return false; /* p_pos=0.100, tau=0.45 */
                                                }
                                            }
                                        }
                                    } else {
                                        if (features[70] /* Feature_HR_Mean_60s_max */ <= 1.26273f) {
                                            if (features[35] /* Feature_MBP_Mean_60s_std */ <= -0.53515f) {
                                                return true; /* p_pos=0.833, tau=0.45 */
                                            } else {
                                                if (features[66] /* Feature_Pulse_Pressure_max */ <= 1.75875f) {
                                                    return false; /* p_pos=0.125, tau=0.45 */
                                                } else {
                                                    return true; /* p_pos=1.000, tau=0.45 */
                                                }
                                            }
                                        } else {
                                            if (features[20] /* ART_SBP_std */ <= -0.17217f) {
                                                if (features[25] /* ETCO2_std */ <= 0.18306f) {
                                                    return false; /* p_pos=0.353, tau=0.45 */
                                                } else {
                                                    return false; /* p_pos=0.000, tau=0.45 */
                                                }
                                            } else {
                                                if (features[39] /* ART_SBP_min */ <= -1.75443f) {
                                                    return false; /* p_pos=0.108, tau=0.45 */
                                                } else {
                                                    return true; /* p_pos=0.649, tau=0.45 */
                                                }
                                            }
                                        }
                                    }
                                } else {
                                    if (features[68] /* Feature_Modified_Shock_Index_max */ <= 0.93078f) {
                                        if (features[82] /* ETCO2_slope */ <= 0.01874f) {
                                            return false; /* p_pos=0.435, tau=0.45 */
                                        } else {
                                            return true; /* p_pos=0.862, tau=0.45 */
                                        }
                                    } else {
                                        if (features[48] /* Feature_Shock_Index_min */ <= 1.94284f) {
                                            if (features[17] /* Feature_MBP_Std_60s_mean */ <= 0.34319f) {
                                                if (features[6] /* ETCO2_mean */ <= 0.60569f) {
                                                    return true; /* p_pos=0.907, tau=0.45 */
                                                } else {
                                                    return false; /* p_pos=0.444, tau=0.45 */
                                                }
                                            } else {
                                                return true; /* p_pos=0.545, tau=0.45 */
                                            }
                                        } else {
                                            return true; /* p_pos=1.000, tau=0.45 */
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
                                                    return false; /* p_pos=0.051, tau=0.45 */
                                                } else {
                                                    return false; /* p_pos=0.375, tau=0.45 */
                                                }
                                            } else {
                                                return true; /* p_pos=0.526, tau=0.45 */
                                            }
                                        } else {
                                            if (features[18] /* Feature_MBP_Delta_60s_mean */ <= -0.08828f) {
                                                if (features[52] /* Feature_HR_Std_60s_min */ <= -0.40007f) {
                                                    return true; /* p_pos=0.571, tau=0.45 */
                                                } else {
                                                    return false; /* p_pos=0.104, tau=0.45 */
                                                }
                                            } else {
                                                if (features[7] /* FIO2_mean */ <= -0.69089f) {
                                                    return true; /* p_pos=0.714, tau=0.45 */
                                                } else {
                                                    return false; /* p_pos=0.234, tau=0.45 */
                                                }
                                            }
                                        }
                                    } else {
                                        return true; /* p_pos=0.619, tau=0.45 */
                                    }
                                } else {
                                    if (features[86] /* Feature_Shock_Index_slope */ <= 1.55302f) {
                                        if (features[77] /* ART_SBP_slope */ <= 1.13909f) {
                                            if (features[17] /* Feature_MBP_Std_60s_mean */ <= -0.45741f) {
                                                return false; /* p_pos=0.357, tau=0.45 */
                                            } else {
                                                if (features[42] /* PLETH_SPO2_min */ <= -0.18239f) {
                                                    return false; /* p_pos=0.005, tau=0.45 */
                                                } else {
                                                    return false; /* p_pos=0.070, tau=0.45 */
                                                }
                                            }
                                        } else {
                                            return false; /* p_pos=0.444, tau=0.45 */
                                        }
                                    } else {
                                        return true; /* p_pos=0.583, tau=0.45 */
                                    }
                                }
                            } else {
                                if (features[8] /* BT_mean */ <= -0.92455f) {
                                    return true; /* p_pos=0.571, tau=0.45 */
                                } else {
                                    if (features[27] /* BT_std */ <= -0.13538f) {
                                        if (features[7] /* FIO2_mean */ <= 2.02143f) {
                                            if (features[64] /* FIO2_max */ <= -0.07635f) {
                                                if (features[86] /* Feature_Shock_Index_slope */ <= -0.96989f) {
                                                    return true; /* p_pos=0.833, tau=0.45 */
                                                } else {
                                                    return false; /* p_pos=0.237, tau=0.45 */
                                                }
                                            } else {
                                                if (features[65] /* BT_max */ <= 0.30659f) {
                                                    return false; /* p_pos=0.017, tau=0.45 */
                                                } else {
                                                    return false; /* p_pos=0.286, tau=0.45 */
                                                }
                                            }
                                        } else {
                                            return true; /* p_pos=0.714, tau=0.45 */
                                        }
                                    } else {
                                        return true; /* p_pos=0.867, tau=0.45 */
                                    }
                                }
                            }
                        } else {
                            if (features[8] /* BT_mean */ <= -0.09242f) {
                                if (features[0] /* HR_mean */ <= 1.79535f) {
                                    return false; /* p_pos=0.222, tau=0.45 */
                                } else {
                                    return true; /* p_pos=0.743, tau=0.45 */
                                }
                            } else {
                                if (features[34] /* Feature_HR_Delta_60s_std */ <= 1.08820f) {
                                    return true; /* p_pos=0.778, tau=0.45 */
                                } else {
                                    if (features[63] /* ETCO2_max */ <= 0.75937f) {
                                        return true; /* p_pos=1.000, tau=0.45 */
                                    } else {
                                        return true; /* p_pos=0.800, tau=0.45 */
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
                                            return false; /* p_pos=0.364, tau=0.45 */
                                        } else {
                                            if (features[48] /* Feature_Shock_Index_min */ <= -0.70820f) {
                                                if (features[89] /* Feature_HR_Mean_60s_slope */ <= 2.08874f) {
                                                    return false; /* p_pos=0.020, tau=0.45 */
                                                } else {
                                                    return false; /* p_pos=0.143, tau=0.45 */
                                                }
                                            } else {
                                                if (features[45] /* FIO2_min */ <= 1.13554f) {
                                                    return false; /* p_pos=0.054, tau=0.45 */
                                                } else {
                                                    return false; /* p_pos=0.163, tau=0.45 */
                                                }
                                            }
                                        }
                                    } else {
                                        if (features[54] /* Feature_MBP_Mean_60s_min */ <= 0.57239f) {
                                            if (features[64] /* FIO2_max */ <= 0.63560f) {
                                                if (features[73] /* Feature_MBP_Mean_60s_max */ <= 3.79203f) {
                                                    return false; /* p_pos=0.007, tau=0.45 */
                                                } else {
                                                    return false; /* p_pos=0.286, tau=0.45 */
                                                }
                                            } else {
                                                if (features[35] /* Feature_MBP_Mean_60s_std */ <= 0.99774f) {
                                                    return false; /* p_pos=0.143, tau=0.45 */
                                                } else {
                                                    return false; /* p_pos=0.027, tau=0.45 */
                                                }
                                            }
                                        } else {
                                            if (features[1] /* ART_SBP_mean */ <= 0.33747f) {
                                                return true; /* p_pos=0.629, tau=0.45 */
                                            } else {
                                                if (features[68] /* Feature_Modified_Shock_Index_max */ <= -0.83430f) {
                                                    return true; /* p_pos=1.000, tau=0.45 */
                                                } else {
                                                    return false; /* p_pos=0.141, tau=0.45 */
                                                }
                                            }
                                        }
                                    }
                                } else {
                                    return true; /* p_pos=0.800, tau=0.45 */
                                }
                            } else {
                                if (features[4] /* PLETH_SPO2_mean */ <= -3.11681f) {
                                    return true; /* p_pos=0.600, tau=0.45 */
                                } else {
                                    if (features[20] /* ART_SBP_std */ <= -0.78215f) {
                                        return true; /* p_pos=0.857, tau=0.45 */
                                    } else {
                                        if (features[21] /* ART_DBP_std */ <= 2.05875f) {
                                            if (features[57] /* HR_max */ <= 0.97255f) {
                                                if (features[47] /* Feature_Pulse_Pressure_min */ <= 2.46164f) {
                                                    return false; /* p_pos=0.101, tau=0.45 */
                                                } else {
                                                    return true; /* p_pos=1.000, tau=0.45 */
                                                }
                                            } else {
                                                if (features[0] /* HR_mean */ <= 1.55952f) {
                                                    return false; /* p_pos=0.241, tau=0.45 */
                                                } else {
                                                    return true; /* p_pos=0.571, tau=0.45 */
                                                }
                                            }
                                        } else {
                                            if (features[54] /* Feature_MBP_Mean_60s_min */ <= 1.08654f) {
                                                if (features[60] /* ART_MBP_max */ <= 0.56300f) {
                                                    return false; /* p_pos=0.136, tau=0.45 */
                                                } else {
                                                    return false; /* p_pos=0.012, tau=0.45 */
                                                }
                                            } else {
                                                return false; /* p_pos=0.333, tau=0.45 */
                                            }
                                        }
                                    }
                                }
                            }
                        } else {
                            if (features[67] /* Feature_Shock_Index_max */ <= 0.14141f) {
                                return false; /* p_pos=0.045, tau=0.45 */
                            } else {
                                if (features[24] /* RR_CO2_std */ <= 1.36017f) {
                                    if (features[35] /* Feature_MBP_Mean_60s_std */ <= -0.69372f) {
                                        return false; /* p_pos=0.077, tau=0.45 */
                                    } else {
                                        if (features[5] /* RR_CO2_mean */ <= 0.27992f) {
                                            if (features[50] /* Feature_Rate_Pressure_Product_min */ <= 0.78604f) {
                                                if (features[22] /* ART_MBP_std */ <= 0.24451f) {
                                                    return false; /* p_pos=0.211, tau=0.45 */
                                                } else {
                                                    return true; /* p_pos=0.900, tau=0.45 */
                                                }
                                            } else {
                                                return true; /* p_pos=0.646, tau=0.45 */
                                            }
                                        } else {
                                            if (features[33] /* Feature_HR_Std_60s_std */ <= 1.62544f) {
                                                if (features[69] /* Feature_Rate_Pressure_Product_max */ <= 1.26541f) {
                                                    return true; /* p_pos=0.838, tau=0.45 */
                                                } else {
                                                    return false; /* p_pos=0.351, tau=0.45 */
                                                }
                                            } else {
                                                if (features[28] /* Feature_Pulse_Pressure_std */ <= -0.65967f) {
                                                    return false; /* p_pos=0.400, tau=0.45 */
                                                } else {
                                                    return true; /* p_pos=0.958, tau=0.45 */
                                                }
                                            }
                                        }
                                    }
                                } else {
                                    if (features[44] /* ETCO2_min */ <= -3.16830f) {
                                        return true; /* p_pos=0.667, tau=0.45 */
                                    } else {
                                        return false; /* p_pos=0.000, tau=0.45 */
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
                                            return true; /* p_pos=0.606, tau=0.45 */
                                        } else {
                                            if (features[33] /* Feature_HR_Std_60s_std */ <= 0.38213f) {
                                                if (features[39] /* ART_SBP_min */ <= 0.85166f) {
                                                    return false; /* p_pos=0.022, tau=0.45 */
                                                } else {
                                                    return false; /* p_pos=0.400, tau=0.45 */
                                                }
                                            } else {
                                                if (features[15] /* Feature_HR_Delta_60s_mean */ <= -2.14483f) {
                                                    return false; /* p_pos=0.100, tau=0.45 */
                                                } else {
                                                    return true; /* p_pos=0.480, tau=0.45 */
                                                }
                                            }
                                        }
                                    } else {
                                        return true; /* p_pos=1.000, tau=0.45 */
                                    }
                                } else {
                                    if (features[51] /* Feature_HR_Mean_60s_min */ <= 1.34319f) {
                                        return false; /* p_pos=0.413, tau=0.45 */
                                    } else {
                                        if (features[66] /* Feature_Pulse_Pressure_max */ <= 3.72388f) {
                                            if (features[85] /* Feature_Pulse_Pressure_slope */ <= -1.07446f) {
                                                return false; /* p_pos=0.222, tau=0.45 */
                                            } else {
                                                if (features[14] /* Feature_HR_Std_60s_mean */ <= 0.67251f) {
                                                    return true; /* p_pos=0.571, tau=0.45 */
                                                } else {
                                                    return true; /* p_pos=0.952, tau=0.45 */
                                                }
                                            }
                                        } else {
                                            return false; /* p_pos=0.000, tau=0.45 */
                                        }
                                    }
                                }
                            } else {
                                if (features[9] /* Feature_Pulse_Pressure_mean */ <= -1.21211f) {
                                    return true; /* p_pos=1.000, tau=0.45 */
                                } else {
                                    if (features[61] /* PLETH_SPO2_max */ <= -1.88715f) {
                                        return true; /* p_pos=0.500, tau=0.45 */
                                    } else {
                                        if (features[44] /* ETCO2_min */ <= -1.02584f) {
                                            return false; /* p_pos=0.000, tau=0.45 */
                                        } else {
                                            if (features[22] /* ART_MBP_std */ <= 0.68049f) {
                                                return true; /* p_pos=0.800, tau=0.45 */
                                            } else {
                                                return false; /* p_pos=0.130, tau=0.45 */
                                            }
                                        }
                                    }
                                }
                            }
                        } else {
                            if (features[20] /* ART_SBP_std */ <= 1.72157f) {
                                if (features[76] /* HR_slope */ <= -1.72274f) {
                                    return true; /* p_pos=0.660, tau=0.45 */
                                } else {
                                    if (features[21] /* ART_DBP_std */ <= -0.60160f) {
                                        if (features[37] /* Feature_MBP_Delta_60s_std */ <= -0.50438f) {
                                            return true; /* p_pos=0.844, tau=0.45 */
                                        } else {
                                            return false; /* p_pos=0.214, tau=0.45 */
                                        }
                                    } else {
                                        if (features[70] /* Feature_HR_Mean_60s_max */ <= 1.67371f) {
                                            if (features[50] /* Feature_Rate_Pressure_Product_min */ <= 1.05172f) {
                                                if (features[88] /* Feature_Rate_Pressure_Product_slope */ <= -0.00953f) {
                                                    return false; /* p_pos=0.071, tau=0.45 */
                                                } else {
                                                    return true; /* p_pos=0.744, tau=0.45 */
                                                }
                                            } else {
                                                if (features[10] /* Feature_Shock_Index_mean */ <= 0.07947f) {
                                                    return false; /* p_pos=0.200, tau=0.45 */
                                                } else {
                                                    return true; /* p_pos=0.918, tau=0.45 */
                                                }
                                            }
                                        } else {
                                            if (features[60] /* ART_MBP_max */ <= 2.46759f) {
                                                if (features[69] /* Feature_Rate_Pressure_Product_max */ <= 1.56776f) {
                                                    return true; /* p_pos=0.922, tau=0.45 */
                                                } else {
                                                    return true; /* p_pos=0.990, tau=0.45 */
                                                }
                                            } else {
                                                return false; /* p_pos=0.200, tau=0.45 */
                                            }
                                        }
                                    }
                                }
                            } else {
                                if (features[89] /* Feature_HR_Mean_60s_slope */ <= -0.71578f) {
                                    return false; /* p_pos=0.286, tau=0.45 */
                                } else {
                                    if (features[28] /* Feature_Pulse_Pressure_std */ <= 1.93314f) {
                                        return true; /* p_pos=0.745, tau=0.45 */
                                    } else {
                                        if (features[13] /* Feature_HR_Mean_60s_mean */ <= 2.01403f) {
                                            return true; /* p_pos=0.778, tau=0.45 */
                                        } else {
                                            if (features[15] /* Feature_HR_Delta_60s_mean */ <= -0.25677f) {
                                                return true; /* p_pos=0.900, tau=0.45 */
                                            } else {
                                                return true; /* p_pos=1.000, tau=0.45 */
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
                        if (features[55] /* Feature_MBP_Std_60s_min */ <= 0.52873f) {
                            if (features[45] /* FIO2_min */ <= -0.73168f) {
                                if (features[38] /* HR_min */ <= 0.64792f) {
                                    if (features[86] /* Feature_Shock_Index_slope */ <= 1.05340f) {
                                        if (features[9] /* Feature_Pulse_Pressure_mean */ <= -0.32036f) {
                                            return false; /* p_pos=0.440, tau=0.45 */
                                        } else {
                                            if (features[1] /* ART_SBP_mean */ <= 1.02816f) {
                                                if (features[92] /* Feature_MBP_Mean_60s_slope */ <= -1.39143f) {
                                                    return false; /* p_pos=0.200, tau=0.45 */
                                                } else {
                                                    return false; /* p_pos=0.012, tau=0.45 */
                                                }
                                            } else {
                                                return false; /* p_pos=0.182, tau=0.45 */
                                            }
                                        }
                                    } else {
                                        return true; /* p_pos=0.833, tau=0.45 */
                                    }
                                } else {
                                    return true; /* p_pos=0.833, tau=0.45 */
                                }
                            } else {
                                if (features[52] /* Feature_HR_Std_60s_min */ <= -0.27186f) {
                                    if (features[47] /* Feature_Pulse_Pressure_min */ <= 2.29321f) {
                                        if (features[75] /* Feature_MBP_Delta_60s_max */ <= 2.41282f) {
                                            if (features[83] /* FIO2_slope */ <= -0.04738f) {
                                                if (features[23] /* PLETH_SPO2_std */ <= 0.28197f) {
                                                    return false; /* p_pos=0.300, tau=0.45 */
                                                } else {
                                                    return false; /* p_pos=0.000, tau=0.45 */
                                                }
                                            } else {
                                                if (features[48] /* Feature_Shock_Index_min */ <= -0.97814f) {
                                                    return false; /* p_pos=0.280, tau=0.45 */
                                                } else {
                                                    return false; /* p_pos=0.082, tau=0.45 */
                                                }
                                            }
                                        } else {
                                            return true; /* p_pos=0.567, tau=0.45 */
                                        }
                                    } else {
                                        return true; /* p_pos=1.000, tau=0.45 */
                                    }
                                } else {
                                    if (features[34] /* Feature_HR_Delta_60s_std */ <= 1.61622f) {
                                        if (features[78] /* ART_DBP_slope */ <= -3.37588f) {
                                            return true; /* p_pos=0.455, tau=0.45 */
                                        } else {
                                            if (features[65] /* BT_max */ <= 0.43833f) {
                                                if (features[44] /* ETCO2_min */ <= 1.38442f) {
                                                    return false; /* p_pos=0.081, tau=0.45 */
                                                } else {
                                                    return false; /* p_pos=0.345, tau=0.45 */
                                                }
                                            } else {
                                                if (features[62] /* RR_CO2_max */ <= 3.51364f) {
                                                    return false; /* p_pos=0.150, tau=0.45 */
                                                } else {
                                                    return true; /* p_pos=1.000, tau=0.45 */
                                                }
                                            }
                                        }
                                    } else {
                                        if (features[33] /* Feature_HR_Std_60s_std */ <= 1.54307f) {
                                            return false; /* p_pos=0.429, tau=0.45 */
                                        } else {
                                            if (features[8] /* BT_mean */ <= 0.44030f) {
                                                return false; /* p_pos=0.049, tau=0.45 */
                                            } else {
                                                return true; /* p_pos=0.600, tau=0.45 */
                                            }
                                        }
                                    }
                                }
                            }
                        } else {
                            if (features[12] /* Feature_Rate_Pressure_Product_mean */ <= 1.25890f) {
                                if (features[3] /* ART_MBP_mean */ <= 2.15589f) {
                                    if (features[14] /* Feature_HR_Std_60s_mean */ <= 1.92298f) {
                                        return false; /* p_pos=0.000, tau=0.45 */
                                    } else {
                                        return false; /* p_pos=0.294, tau=0.45 */
                                    }
                                } else {
                                    return true; /* p_pos=0.800, tau=0.45 */
                                }
                            } else {
                                if (features[20] /* ART_SBP_std */ <= 1.12523f) {
                                    if (features[4] /* PLETH_SPO2_mean */ <= 0.36999f) {
                                        return true; /* p_pos=0.935, tau=0.45 */
                                    } else {
                                        return true; /* p_pos=0.450, tau=0.45 */
                                    }
                                } else {
                                    return false; /* p_pos=0.250, tau=0.45 */
                                }
                            }
                        }
                    } else {
                        if (features[51] /* Feature_HR_Mean_60s_min */ <= 0.99098f) {
                            if (features[46] /* BT_min */ <= 0.50879f) {
                                if (features[57] /* HR_max */ <= 1.25357f) {
                                    if (features[27] /* BT_std */ <= 1.10133f) {
                                        if (features[25] /* ETCO2_std */ <= -0.51814f) {
                                            return false; /* p_pos=0.326, tau=0.45 */
                                        } else {
                                            if (features[63] /* ETCO2_max */ <= 0.56162f) {
                                                if (features[18] /* Feature_MBP_Delta_60s_mean */ <= 6.47096f) {
                                                    return false; /* p_pos=0.050, tau=0.45 */
                                                } else {
                                                    return true; /* p_pos=0.800, tau=0.45 */
                                                }
                                            } else {
                                                if (features[41] /* ART_MBP_min */ <= -0.55701f) {
                                                    return false; /* p_pos=0.048, tau=0.45 */
                                                } else {
                                                    return false; /* p_pos=0.329, tau=0.45 */
                                                }
                                            }
                                        }
                                    } else {
                                        return true; /* p_pos=0.468, tau=0.45 */
                                    }
                                } else {
                                    if (features[53] /* Feature_HR_Delta_60s_min */ <= -2.39189f) {
                                        return false; /* p_pos=0.070, tau=0.45 */
                                    } else {
                                        if (features[16] /* Feature_MBP_Mean_60s_mean */ <= -0.46537f) {
                                            if (features[34] /* Feature_HR_Delta_60s_std */ <= 0.61164f) {
                                                return false; /* p_pos=0.091, tau=0.45 */
                                            } else {
                                                if (features[66] /* Feature_Pulse_Pressure_max */ <= 0.66060f) {
                                                    return true; /* p_pos=0.825, tau=0.45 */
                                                } else {
                                                    return false; /* p_pos=0.000, tau=0.45 */
                                                }
                                            }
                                        } else {
                                            if (features[59] /* ART_DBP_max */ <= -0.60757f) {
                                                return true; /* p_pos=0.833, tau=0.45 */
                                            } else {
                                                if (features[1] /* ART_SBP_mean */ <= 0.11971f) {
                                                    return false; /* p_pos=0.064, tau=0.45 */
                                                } else {
                                                    return true; /* p_pos=0.581, tau=0.45 */
                                                }
                                            }
                                        }
                                    }
                                }
                            } else {
                                if (features[52] /* Feature_HR_Std_60s_min */ <= 0.12560f) {
                                    return false; /* p_pos=0.258, tau=0.45 */
                                } else {
                                    return true; /* p_pos=0.815, tau=0.45 */
                                }
                            }
                        } else {
                            if (features[28] /* Feature_Pulse_Pressure_std */ <= -0.16470f) {
                                if (features[10] /* Feature_Shock_Index_mean */ <= 0.27207f) {
                                    return true; /* p_pos=1.000, tau=0.45 */
                                } else {
                                    if (features[91] /* Feature_HR_Delta_60s_slope */ <= 2.00494f) {
                                        if (features[54] /* Feature_MBP_Mean_60s_min */ <= 0.69732f) {
                                            if (features[26] /* FIO2_std */ <= -0.38218f) {
                                                if (features[11] /* Feature_Modified_Shock_Index_mean */ <= 1.17274f) {
                                                    return false; /* p_pos=0.020, tau=0.45 */
                                                } else {
                                                    return true; /* p_pos=0.600, tau=0.45 */
                                                }
                                            } else {
                                                if (features[74] /* Feature_MBP_Std_60s_max */ <= -0.54423f) {
                                                    return false; /* p_pos=0.108, tau=0.45 */
                                                } else {
                                                    return false; /* p_pos=0.330, tau=0.45 */
                                                }
                                            }
                                        } else {
                                            return true; /* p_pos=0.643, tau=0.45 */
                                        }
                                    } else {
                                        return true; /* p_pos=0.667, tau=0.45 */
                                    }
                                }
                            } else {
                                if (features[7] /* FIO2_mean */ <= -0.14847f) {
                                    if (features[45] /* FIO2_min */ <= -0.61498f) {
                                        return false; /* p_pos=0.318, tau=0.45 */
                                    } else {
                                        if (features[52] /* Feature_HR_Std_60s_min */ <= 0.58226f) {
                                            return false; /* p_pos=0.412, tau=0.45 */
                                        } else {
                                            if (features[48] /* Feature_Shock_Index_min */ <= -0.25283f) {
                                                return false; /* p_pos=0.000, tau=0.45 */
                                            } else {
                                                if (features[15] /* Feature_HR_Delta_60s_mean */ <= -0.11594f) {
                                                    return true; /* p_pos=0.707, tau=0.45 */
                                                } else {
                                                    return true; /* p_pos=0.976, tau=0.45 */
                                                }
                                            }
                                        }
                                    }
                                } else {
                                    if (features[32] /* Feature_HR_Mean_60s_std */ <= -0.14111f) {
                                        if (features[46] /* BT_min */ <= 0.46014f) {
                                            return false; /* p_pos=0.000, tau=0.45 */
                                        } else {
                                            return false; /* p_pos=0.300, tau=0.45 */
                                        }
                                    } else {
                                        if (features[46] /* BT_min */ <= 0.38716f) {
                                            return false; /* p_pos=0.083, tau=0.45 */
                                        } else {
                                            if (features[89] /* Feature_HR_Mean_60s_slope */ <= -0.90101f) {
                                                return false; /* p_pos=0.080, tau=0.45 */
                                            } else {
                                                if (features[38] /* HR_min */ <= 0.98717f) {
                                                    return false; /* p_pos=0.100, tau=0.45 */
                                                } else {
                                                    return true; /* p_pos=0.840, tau=0.45 */
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
                            return false; /* p_pos=0.000, tau=0.45 */
                        } else {
                            return true; /* p_pos=0.619, tau=0.45 */
                        }
                    } else {
                        if (features[73] /* Feature_MBP_Mean_60s_max */ <= 0.58758f) {
                            if (features[11] /* Feature_Modified_Shock_Index_mean */ <= 1.60004f) {
                                if (features[25] /* ETCO2_std */ <= -0.20883f) {
                                    if (features[69] /* Feature_Rate_Pressure_Product_max */ <= 0.52010f) {
                                        return false; /* p_pos=0.286, tau=0.45 */
                                    } else {
                                        if (features[31] /* Feature_Rate_Pressure_Product_std */ <= 0.11598f) {
                                            return true; /* p_pos=0.929, tau=0.45 */
                                        } else {
                                            return true; /* p_pos=1.000, tau=0.45 */
                                        }
                                    }
                                } else {
                                    if (features[85] /* Feature_Pulse_Pressure_slope */ <= -1.36330f) {
                                        return false; /* p_pos=0.333, tau=0.45 */
                                    } else {
                                        if (features[52] /* Feature_HR_Std_60s_min */ <= 0.62304f) {
                                            if (features[91] /* Feature_HR_Delta_60s_slope */ <= -0.35088f) {
                                                return true; /* p_pos=0.733, tau=0.45 */
                                            } else {
                                                return true; /* p_pos=1.000, tau=0.45 */
                                            }
                                        } else {
                                            return true; /* p_pos=0.500, tau=0.45 */
                                        }
                                    }
                                }
                            } else {
                                return true; /* p_pos=1.000, tau=0.45 */
                            }
                        } else {
                            if (features[63] /* ETCO2_max */ <= 0.56162f) {
                                if (features[4] /* PLETH_SPO2_mean */ <= 0.06824f) {
                                    return true; /* p_pos=0.850, tau=0.45 */
                                } else {
                                    return false; /* p_pos=0.161, tau=0.45 */
                                }
                            } else {
                                return true; /* p_pos=0.867, tau=0.45 */
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
                                            return false; /* p_pos=0.333, tau=0.45 */
                                        } else {
                                            if (features[91] /* Feature_HR_Delta_60s_slope */ <= 1.12151f) {
                                                if (features[3] /* ART_MBP_mean */ <= -0.32066f) {
                                                    return false; /* p_pos=0.041, tau=0.45 */
                                                } else {
                                                    return false; /* p_pos=0.009, tau=0.45 */
                                                }
                                            } else {
                                                if (features[45] /* FIO2_min */ <= 1.83575f) {
                                                    return false; /* p_pos=0.086, tau=0.45 */
                                                } else {
                                                    return false; /* p_pos=0.400, tau=0.45 */
                                                }
                                            }
                                        }
                                    } else {
                                        if (features[64] /* FIO2_max */ <= 1.70353f) {
                                            if (features[51] /* Feature_HR_Mean_60s_min */ <= -3.20066f) {
                                                return true; /* p_pos=0.533, tau=0.45 */
                                            } else {
                                                if (features[67] /* Feature_Shock_Index_max */ <= -0.29815f) {
                                                    return false; /* p_pos=0.026, tau=0.45 */
                                                } else {
                                                    return false; /* p_pos=0.104, tau=0.45 */
                                                }
                                            }
                                        } else {
                                            if (features[38] /* HR_min */ <= -1.52331f) {
                                                if (features[66] /* Feature_Pulse_Pressure_max */ <= -0.19192f) {
                                                    return false; /* p_pos=0.048, tau=0.45 */
                                                } else {
                                                    return false; /* p_pos=0.350, tau=0.45 */
                                                }
                                            } else {
                                                if (features[1] /* ART_SBP_mean */ <= -2.21406f) {
                                                    return true; /* p_pos=0.714, tau=0.45 */
                                                } else {
                                                    return false; /* p_pos=0.113, tau=0.45 */
                                                }
                                            }
                                        }
                                    }
                                } else {
                                    if (features[53] /* Feature_HR_Delta_60s_min */ <= 0.34554f) {
                                        if (features[25] /* ETCO2_std */ <= -0.55035f) {
                                            return true; /* p_pos=0.800, tau=0.45 */
                                        } else {
                                            if (features[91] /* Feature_HR_Delta_60s_slope */ <= 2.83929f) {
                                                if (features[41] /* ART_MBP_min */ <= 1.40484f) {
                                                    return false; /* p_pos=0.120, tau=0.45 */
                                                } else {
                                                    return true; /* p_pos=0.450, tau=0.45 */
                                                }
                                            } else {
                                                return true; /* p_pos=0.714, tau=0.45 */
                                            }
                                        }
                                    } else {
                                        if (features[83] /* FIO2_slope */ <= 0.09025f) {
                                            if (features[39] /* ART_SBP_min */ <= 0.74879f) {
                                                return false; /* p_pos=0.204, tau=0.45 */
                                            } else {
                                                return false; /* p_pos=0.000, tau=0.45 */
                                            }
                                        } else {
                                            if (features[24] /* RR_CO2_std */ <= -0.33957f) {
                                                return true; /* p_pos=0.952, tau=0.45 */
                                            } else {
                                                return false; /* p_pos=0.292, tau=0.45 */
                                            }
                                        }
                                    }
                                }
                            } else {
                                if (features[51] /* Feature_HR_Mean_60s_min */ <= -2.51875f) {
                                    return true; /* p_pos=0.696, tau=0.45 */
                                } else {
                                    if (features[12] /* Feature_Rate_Pressure_Product_mean */ <= -1.22344f) {
                                        if (features[15] /* Feature_HR_Delta_60s_mean */ <= -3.30516f) {
                                            return false; /* p_pos=0.333, tau=0.45 */
                                        } else {
                                            if (features[49] /* Feature_Modified_Shock_Index_min */ <= 9.43290f) {
                                                if (features[88] /* Feature_Rate_Pressure_Product_slope */ <= -0.40467f) {
                                                    return false; /* p_pos=0.050, tau=0.45 */
                                                } else {
                                                    return false; /* p_pos=0.000, tau=0.45 */
                                                }
                                            } else {
                                                return false; /* p_pos=0.200, tau=0.45 */
                                            }
                                        }
                                    } else {
                                        if (features[7] /* FIO2_mean */ <= 1.41787f) {
                                            if (features[0] /* HR_mean */ <= 0.94179f) {
                                                if (features[87] /* Feature_Modified_Shock_Index_slope */ <= 1.03609f) {
                                                    return false; /* p_pos=0.079, tau=0.45 */
                                                } else {
                                                    return false; /* p_pos=0.295, tau=0.45 */
                                                }
                                            } else {
                                                return false; /* p_pos=0.378, tau=0.45 */
                                            }
                                        } else {
                                            if (features[1] /* ART_SBP_mean */ <= 0.18170f) {
                                                if (features[52] /* Feature_HR_Std_60s_min */ <= 0.01446f) {
                                                    return true; /* p_pos=0.613, tau=0.45 */
                                                } else {
                                                    return false; /* p_pos=0.206, tau=0.45 */
                                                }
                                            } else {
                                                return false; /* p_pos=0.061, tau=0.45 */
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
                                                    return false; /* p_pos=0.167, tau=0.45 */
                                                } else {
                                                    return false; /* p_pos=0.043, tau=0.45 */
                                                }
                                            } else {
                                                return true; /* p_pos=0.636, tau=0.45 */
                                            }
                                        } else {
                                            return true; /* p_pos=0.800, tau=0.45 */
                                        }
                                    } else {
                                        if (features[87] /* Feature_Modified_Shock_Index_slope */ <= 2.02083f) {
                                            if (features[83] /* FIO2_slope */ <= 3.87495f) {
                                                if (features[19] /* HR_std */ <= 2.89288f) {
                                                    return false; /* p_pos=0.024, tau=0.45 */
                                                } else {
                                                    return false; /* p_pos=0.115, tau=0.45 */
                                                }
                                            } else {
                                                if (features[46] /* BT_min */ <= -0.95075f) {
                                                    return true; /* p_pos=0.483, tau=0.45 */
                                                } else {
                                                    return false; /* p_pos=0.106, tau=0.45 */
                                                }
                                            }
                                        } else {
                                            return false; /* p_pos=0.375, tau=0.45 */
                                        }
                                    }
                                } else {
                                    return true; /* p_pos=0.500, tau=0.45 */
                                }
                            } else {
                                if (features[34] /* Feature_HR_Delta_60s_std */ <= 4.19315f) {
                                    if (features[63] /* ETCO2_max */ <= 5.50535f) {
                                        if (features[66] /* Feature_Pulse_Pressure_max */ <= 0.79064f) {
                                            if (features[13] /* Feature_HR_Mean_60s_mean */ <= 0.39275f) {
                                                if (features[14] /* Feature_HR_Std_60s_mean */ <= 1.68337f) {
                                                    return false; /* p_pos=0.085, tau=0.45 */
                                                } else {
                                                    return false; /* p_pos=0.223, tau=0.45 */
                                                }
                                            } else {
                                                if (features[71] /* Feature_HR_Std_60s_max */ <= 0.81981f) {
                                                    return false; /* p_pos=0.051, tau=0.45 */
                                                } else {
                                                    return false; /* p_pos=0.397, tau=0.45 */
                                                }
                                            }
                                        } else {
                                            if (features[50] /* Feature_Rate_Pressure_Product_min */ <= -2.12146f) {
                                                return true; /* p_pos=0.625, tau=0.45 */
                                            } else {
                                                if (features[21] /* ART_DBP_std */ <= 1.94468f) {
                                                    return false; /* p_pos=0.065, tau=0.45 */
                                                } else {
                                                    return false; /* p_pos=0.009, tau=0.45 */
                                                }
                                            }
                                        }
                                    } else {
                                        return true; /* p_pos=1.000, tau=0.45 */
                                    }
                                } else {
                                    return true; /* p_pos=0.889, tau=0.45 */
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
                                                    return false; /* p_pos=0.138, tau=0.45 */
                                                } else {
                                                    return false; /* p_pos=0.435, tau=0.45 */
                                                }
                                            } else {
                                                if (features[4] /* PLETH_SPO2_mean */ <= 0.35536f) {
                                                    return false; /* p_pos=0.103, tau=0.45 */
                                                } else {
                                                    return true; /* p_pos=0.589, tau=0.45 */
                                                }
                                            }
                                        } else {
                                            if (features[30] /* Feature_Modified_Shock_Index_std */ <= 0.94924f) {
                                                if (features[77] /* ART_SBP_slope */ <= 1.49161f) {
                                                    return true; /* p_pos=0.573, tau=0.45 */
                                                } else {
                                                    return false; /* p_pos=0.118, tau=0.45 */
                                                }
                                            } else {
                                                return false; /* p_pos=0.043, tau=0.45 */
                                            }
                                        }
                                    } else {
                                        if (features[15] /* Feature_HR_Delta_60s_mean */ <= 1.73164f) {
                                            if (features[46] /* BT_min */ <= 0.36284f) {
                                                if (features[29] /* Feature_Shock_Index_std */ <= 0.25369f) {
                                                    return false; /* p_pos=0.062, tau=0.45 */
                                                } else {
                                                    return false; /* p_pos=0.119, tau=0.45 */
                                                }
                                            } else {
                                                if (features[17] /* Feature_MBP_Std_60s_mean */ <= -0.44737f) {
                                                    return false; /* p_pos=0.331, tau=0.45 */
                                                } else {
                                                    return false; /* p_pos=0.129, tau=0.45 */
                                                }
                                            }
                                        } else {
                                            if (features[68] /* Feature_Modified_Shock_Index_max */ <= -0.06529f) {
                                                if (features[85] /* Feature_Pulse_Pressure_slope */ <= 0.11299f) {
                                                    return false; /* p_pos=0.182, tau=0.45 */
                                                } else {
                                                    return false; /* p_pos=0.025, tau=0.45 */
                                                }
                                            } else {
                                                if (features[25] /* ETCO2_std */ <= -0.46051f) {
                                                    return true; /* p_pos=0.537, tau=0.45 */
                                                } else {
                                                    return false; /* p_pos=0.251, tau=0.45 */
                                                }
                                            }
                                        }
                                    }
                                } else {
                                    if (features[75] /* Feature_MBP_Delta_60s_max */ <= 3.26625f) {
                                        if (features[59] /* ART_DBP_max */ <= 0.30625f) {
                                            if (features[66] /* Feature_Pulse_Pressure_max */ <= 0.12597f) {
                                                if (features[55] /* Feature_MBP_Std_60s_min */ <= -0.08545f) {
                                                    return false; /* p_pos=0.176, tau=0.45 */
                                                } else {
                                                    return false; /* p_pos=0.286, tau=0.45 */
                                                }
                                            } else {
                                                if (features[71] /* Feature_HR_Std_60s_max */ <= 3.09556f) {
                                                    return false; /* p_pos=0.254, tau=0.45 */
                                                } else {
                                                    return false; /* p_pos=0.439, tau=0.45 */
                                                }
                                            }
                                        } else {
                                            if (features[70] /* Feature_HR_Mean_60s_max */ <= 0.11728f) {
                                                if (features[46] /* BT_min */ <= 0.44392f) {
                                                    return false; /* p_pos=0.050, tau=0.45 */
                                                } else {
                                                    return true; /* p_pos=0.667, tau=0.45 */
                                                }
                                            } else {
                                                if (features[90] /* Feature_HR_Std_60s_slope */ <= 1.23592f) {
                                                    return false; /* p_pos=0.144, tau=0.45 */
                                                } else {
                                                    return false; /* p_pos=0.331, tau=0.45 */
                                                }
                                            }
                                        }
                                    } else {
                                        return true; /* p_pos=0.944, tau=0.45 */
                                    }
                                }
                            } else {
                                if (features[38] /* HR_min */ <= -1.04836f) {
                                    if (features[51] /* Feature_HR_Mean_60s_min */ <= -1.96961f) {
                                        return false; /* p_pos=0.083, tau=0.45 */
                                    } else {
                                        if (features[10] /* Feature_Shock_Index_mean */ <= 0.50829f) {
                                            if (features[50] /* Feature_Rate_Pressure_Product_min */ <= -0.58439f) {
                                                if (features[68] /* Feature_Modified_Shock_Index_max */ <= -0.09583f) {
                                                    return false; /* p_pos=0.000, tau=0.45 */
                                                } else {
                                                    return true; /* p_pos=0.647, tau=0.45 */
                                                }
                                            } else {
                                                return false; /* p_pos=0.222, tau=0.45 */
                                            }
                                        } else {
                                            return true; /* p_pos=1.000, tau=0.45 */
                                        }
                                    }
                                } else {
                                    if (features[88] /* Feature_Rate_Pressure_Product_slope */ <= 1.16491f) {
                                        if (features[23] /* PLETH_SPO2_std */ <= 0.10542f) {
                                            if (features[87] /* Feature_Modified_Shock_Index_slope */ <= 2.02637f) {
                                                if (features[2] /* ART_DBP_mean */ <= 0.05280f) {
                                                    return true; /* p_pos=0.471, tau=0.45 */
                                                } else {
                                                    return false; /* p_pos=0.056, tau=0.45 */
                                                }
                                            } else {
                                                return true; /* p_pos=0.875, tau=0.45 */
                                            }
                                        } else {
                                            if (features[76] /* HR_slope */ <= 4.09855f) {
                                                return true; /* p_pos=0.485, tau=0.45 */
                                            } else {
                                                return true; /* p_pos=0.962, tau=0.45 */
                                            }
                                        }
                                    } else {
                                        if (features[70] /* Feature_HR_Mean_60s_max */ <= 1.29894f) {
                                            if (features[36] /* Feature_MBP_Std_60s_std */ <= -0.44748f) {
                                                if (features[45] /* FIO2_min */ <= 1.95245f) {
                                                    return true; /* p_pos=0.844, tau=0.45 */
                                                } else {
                                                    return false; /* p_pos=0.286, tau=0.45 */
                                                }
                                            } else {
                                                if (features[94] /* Feature_MBP_Delta_60s_slope */ <= 0.42405f) {
                                                    return true; /* p_pos=0.516, tau=0.45 */
                                                } else {
                                                    return true; /* p_pos=1.000, tau=0.45 */
                                                }
                                            }
                                        } else {
                                            if (features[3] /* ART_MBP_mean */ <= 0.71216f) {
                                                if (features[13] /* Feature_HR_Mean_60s_mean */ <= 0.32224f) {
                                                    return true; /* p_pos=0.951, tau=0.45 */
                                                } else {
                                                    return true; /* p_pos=0.600, tau=0.45 */
                                                }
                                            } else {
                                                return true; /* p_pos=0.688, tau=0.45 */
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
                                                    return false; /* p_pos=0.375, tau=0.45 */
                                                } else {
                                                    return false; /* p_pos=0.045, tau=0.45 */
                                                }
                                            } else {
                                                return false; /* p_pos=0.389, tau=0.45 */
                                            }
                                        } else {
                                            if (features[4] /* PLETH_SPO2_mean */ <= 0.37791f) {
                                                if (features[70] /* Feature_HR_Mean_60s_max */ <= 1.27684f) {
                                                    return true; /* p_pos=0.667, tau=0.45 */
                                                } else {
                                                    return false; /* p_pos=0.065, tau=0.45 */
                                                }
                                            } else {
                                                return false; /* p_pos=0.000, tau=0.45 */
                                            }
                                        }
                                    } else {
                                        if (features[74] /* Feature_MBP_Std_60s_max */ <= -0.27692f) {
                                            if (features[71] /* Feature_HR_Std_60s_max */ <= 1.21149f) {
                                                if (features[42] /* PLETH_SPO2_min */ <= -2.00207f) {
                                                    return true; /* p_pos=0.909, tau=0.45 */
                                                } else {
                                                    return false; /* p_pos=0.190, tau=0.45 */
                                                }
                                            } else {
                                                if (features[90] /* Feature_HR_Std_60s_slope */ <= 1.06043f) {
                                                    return false; /* p_pos=0.320, tau=0.45 */
                                                } else {
                                                    return true; /* p_pos=0.557, tau=0.45 */
                                                }
                                            }
                                        } else {
                                            if (features[71] /* Feature_HR_Std_60s_max */ <= 1.32057f) {
                                                if (features[28] /* Feature_Pulse_Pressure_std */ <= 1.85828f) {
                                                    return false; /* p_pos=0.088, tau=0.45 */
                                                } else {
                                                    return false; /* p_pos=0.230, tau=0.45 */
                                                }
                                            } else {
                                                if (features[28] /* Feature_Pulse_Pressure_std */ <= 2.07521f) {
                                                    return false; /* p_pos=0.270, tau=0.45 */
                                                } else {
                                                    return false; /* p_pos=0.126, tau=0.45 */
                                                }
                                            }
                                        }
                                    }
                                } else {
                                    if (features[57] /* HR_max */ <= 1.41416f) {
                                        if (features[28] /* Feature_Pulse_Pressure_std */ <= -0.53934f) {
                                            if (features[34] /* Feature_HR_Delta_60s_std */ <= 0.62677f) {
                                                return false; /* p_pos=0.316, tau=0.45 */
                                            } else {
                                                if (features[80] /* PLETH_SPO2_slope */ <= -0.28680f) {
                                                    return false; /* p_pos=0.143, tau=0.45 */
                                                } else {
                                                    return false; /* p_pos=0.016, tau=0.45 */
                                                }
                                            }
                                        } else {
                                            if (features[46] /* BT_min */ <= 0.49257f) {
                                                if (features[76] /* HR_slope */ <= 0.58730f) {
                                                    return false; /* p_pos=0.158, tau=0.45 */
                                                } else {
                                                    return true; /* p_pos=0.500, tau=0.45 */
                                                }
                                            } else {
                                                return true; /* p_pos=1.000, tau=0.45 */
                                            }
                                        }
                                    } else {
                                        if (features[31] /* Feature_Rate_Pressure_Product_std */ <= 0.32387f) {
                                            if (features[15] /* Feature_HR_Delta_60s_mean */ <= 0.50722f) {
                                                if (features[42] /* PLETH_SPO2_min */ <= -0.44235f) {
                                                    return true; /* p_pos=0.680, tau=0.45 */
                                                } else {
                                                    return false; /* p_pos=0.326, tau=0.45 */
                                                }
                                            } else {
                                                if (features[54] /* Feature_MBP_Mean_60s_min */ <= -0.22928f) {
                                                    return true; /* p_pos=0.529, tau=0.45 */
                                                } else {
                                                    return true; /* p_pos=0.789, tau=0.45 */
                                                }
                                            }
                                        } else {
                                            if (features[15] /* Feature_HR_Delta_60s_mean */ <= 0.23569f) {
                                                if (features[6] /* ETCO2_mean */ <= -0.04617f) {
                                                    return false; /* p_pos=0.426, tau=0.45 */
                                                } else {
                                                    return false; /* p_pos=0.193, tau=0.45 */
                                                }
                                            } else {
                                                if (features[88] /* Feature_Rate_Pressure_Product_slope */ <= 0.63394f) {
                                                    return false; /* p_pos=0.414, tau=0.45 */
                                                } else {
                                                    return true; /* p_pos=0.635, tau=0.45 */
                                                }
                                            }
                                        }
                                    }
                                }
                            } else {
                                if (features[48] /* Feature_Shock_Index_min */ <= 0.63396f) {
                                    if (features[57] /* HR_max */ <= 0.93240f) {
                                        return true; /* p_pos=0.511, tau=0.45 */
                                    } else {
                                        if (features[60] /* ART_MBP_max */ <= 0.88490f) {
                                            if (features[25] /* ETCO2_std */ <= 4.66705f) {
                                                if (features[41] /* ART_MBP_min */ <= 0.79760f) {
                                                    return true; /* p_pos=0.832, tau=0.45 */
                                                } else {
                                                    return true; /* p_pos=0.676, tau=0.45 */
                                                }
                                            } else {
                                                return true; /* p_pos=0.455, tau=0.45 */
                                            }
                                        } else {
                                            if (features[39] /* ART_SBP_min */ <= 0.66306f) {
                                                return true; /* p_pos=0.674, tau=0.45 */
                                            } else {
                                                return false; /* p_pos=0.000, tau=0.45 */
                                            }
                                        }
                                    }
                                } else {
                                    if (features[32] /* Feature_HR_Mean_60s_std */ <= 2.43731f) {
                                        return true; /* p_pos=1.000, tau=0.45 */
                                    } else {
                                        return true; /* p_pos=0.784, tau=0.45 */
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
                                                    return true; /* p_pos=0.500, tau=0.45 */
                                                } else {
                                                    return false; /* p_pos=0.107, tau=0.45 */
                                                }
                                            } else {
                                                if (features[38] /* HR_min */ <= -0.50555f) {
                                                    return false; /* p_pos=0.048, tau=0.45 */
                                                } else {
                                                    return false; /* p_pos=0.188, tau=0.45 */
                                                }
                                            }
                                        } else {
                                            if (features[2] /* ART_DBP_mean */ <= 0.79125f) {
                                                return false; /* p_pos=0.388, tau=0.45 */
                                            } else {
                                                return false; /* p_pos=0.000, tau=0.45 */
                                            }
                                        }
                                    } else {
                                        if (features[64] /* FIO2_max */ <= 1.61454f) {
                                            return false; /* p_pos=0.342, tau=0.45 */
                                        } else {
                                            return true; /* p_pos=0.690, tau=0.45 */
                                        }
                                    }
                                } else {
                                    return true; /* p_pos=0.688, tau=0.45 */
                                }
                            } else {
                                if (features[57] /* HR_max */ <= 0.69152f) {
                                    if (features[38] /* HR_min */ <= 0.17296f) {
                                        if (features[25] /* ETCO2_std */ <= -0.48652f) {
                                            return true; /* p_pos=0.500, tau=0.45 */
                                        } else {
                                            if (features[27] /* BT_std */ <= 4.92958f) {
                                                if (features[63] /* ETCO2_max */ <= -1.02037f) {
                                                    return true; /* p_pos=0.450, tau=0.45 */
                                                } else {
                                                    return false; /* p_pos=0.046, tau=0.45 */
                                                }
                                            } else {
                                                return false; /* p_pos=0.159, tau=0.45 */
                                            }
                                        }
                                    } else {
                                        return false; /* p_pos=0.263, tau=0.45 */
                                    }
                                } else {
                                    if (features[76] /* HR_slope */ <= 3.35934f) {
                                        if (features[72] /* Feature_HR_Delta_60s_max */ <= 1.18459f) {
                                            if (features[66] /* Feature_Pulse_Pressure_max */ <= 2.03329f) {
                                                if (features[48] /* Feature_Shock_Index_min */ <= -0.62357f) {
                                                    return true; /* p_pos=0.857, tau=0.45 */
                                                } else {
                                                    return false; /* p_pos=0.224, tau=0.45 */
                                                }
                                            } else {
                                                return false; /* p_pos=0.034, tau=0.45 */
                                            }
                                        } else {
                                            return false; /* p_pos=0.000, tau=0.45 */
                                        }
                                    } else {
                                        return false; /* p_pos=0.444, tau=0.45 */
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
                                                    return false; /* p_pos=0.314, tau=0.45 */
                                                } else {
                                                    return true; /* p_pos=0.613, tau=0.45 */
                                                }
                                            } else {
                                                if (features[1] /* ART_SBP_mean */ <= -0.03099f) {
                                                    return true; /* p_pos=0.538, tau=0.45 */
                                                } else {
                                                    return true; /* p_pos=0.827, tau=0.45 */
                                                }
                                            }
                                        } else {
                                            return true; /* p_pos=0.918, tau=0.45 */
                                        }
                                    } else {
                                        if (features[40] /* ART_DBP_min */ <= 0.70965f) {
                                            if (features[31] /* Feature_Rate_Pressure_Product_std */ <= 0.40378f) {
                                                return false; /* p_pos=0.400, tau=0.45 */
                                            } else {
                                                if (features[50] /* Feature_Rate_Pressure_Product_min */ <= 1.01073f) {
                                                    return true; /* p_pos=0.962, tau=0.45 */
                                                } else {
                                                    return true; /* p_pos=0.667, tau=0.45 */
                                                }
                                            }
                                        } else {
                                            return true; /* p_pos=0.500, tau=0.45 */
                                        }
                                    }
                                } else {
                                    if (features[7] /* FIO2_mean */ <= 1.30102f) {
                                        if (features[26] /* FIO2_std */ <= 4.54606f) {
                                            if (features[24] /* RR_CO2_std */ <= -0.48061f) {
                                                return false; /* p_pos=0.378, tau=0.45 */
                                            } else {
                                                if (features[64] /* FIO2_max */ <= -0.69931f) {
                                                    return true; /* p_pos=1.000, tau=0.45 */
                                                } else {
                                                    return true; /* p_pos=0.632, tau=0.45 */
                                                }
                                            }
                                        } else {
                                            return true; /* p_pos=0.955, tau=0.45 */
                                        }
                                    } else {
                                        if (features[88] /* Feature_Rate_Pressure_Product_slope */ <= 3.90912f) {
                                            if (features[67] /* Feature_Shock_Index_max */ <= 2.94516f) {
                                                if (features[50] /* Feature_Rate_Pressure_Product_min */ <= -0.48723f) {
                                                    return false; /* p_pos=0.107, tau=0.45 */
                                                } else {
                                                    return false; /* p_pos=0.326, tau=0.45 */
                                                }
                                            } else {
                                                return true; /* p_pos=1.000, tau=0.45 */
                                            }
                                        } else {
                                            return true; /* p_pos=0.808, tau=0.45 */
                                        }
                                    }
                                }
                            } else {
                                if (features[89] /* Feature_HR_Mean_60s_slope */ <= 3.65959f) {
                                    if (features[17] /* Feature_MBP_Std_60s_mean */ <= 0.34345f) {
                                        if (features[22] /* ART_MBP_std */ <= 0.15185f) {
                                            return false; /* p_pos=0.043, tau=0.45 */
                                        } else {
                                            if (features[69] /* Feature_Rate_Pressure_Product_max */ <= 1.30266f) {
                                                return false; /* p_pos=0.212, tau=0.45 */
                                            } else {
                                                if (features[66] /* Feature_Pulse_Pressure_max */ <= 1.22412f) {
                                                    return true; /* p_pos=0.603, tau=0.45 */
                                                } else {
                                                    return false; /* p_pos=0.250, tau=0.45 */
                                                }
                                            }
                                        }
                                    } else {
                                        if (features[76] /* HR_slope */ <= 3.26693f) {
                                            if (features[74] /* Feature_MBP_Std_60s_max */ <= 1.10808f) {
                                                if (features[41] /* ART_MBP_min */ <= -0.65043f) {
                                                    return false; /* p_pos=0.345, tau=0.45 */
                                                } else {
                                                    return false; /* p_pos=0.095, tau=0.45 */
                                                }
                                            } else {
                                                if (features[18] /* Feature_MBP_Delta_60s_mean */ <= 0.61052f) {
                                                    return false; /* p_pos=0.200, tau=0.45 */
                                                } else {
                                                    return false; /* p_pos=0.040, tau=0.45 */
                                                }
                                            }
                                        } else {
                                            return true; /* p_pos=0.600, tau=0.45 */
                                        }
                                    }
                                } else {
                                    if (features[88] /* Feature_Rate_Pressure_Product_slope */ <= 4.65941f) {
                                        return false; /* p_pos=0.391, tau=0.45 */
                                    } else {
                                        if (features[36] /* Feature_MBP_Std_60s_std */ <= 0.11767f) {
                                            return true; /* p_pos=0.936, tau=0.45 */
                                        } else {
                                            if (features[11] /* Feature_Modified_Shock_Index_mean */ <= -0.37392f) {
                                                return true; /* p_pos=0.522, tau=0.45 */
                                            } else {
                                                return true; /* p_pos=0.949, tau=0.45 */
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    } else {
                        if (features[92] /* Feature_MBP_Mean_60s_slope */ <= 0.53694f) {
                            if (features[70] /* Feature_HR_Mean_60s_max */ <= 0.05803f) {
                                return true; /* p_pos=0.808, tau=0.45 */
                            } else {
                                if (features[54] /* Feature_MBP_Mean_60s_min */ <= -0.48075f) {
                                    return true; /* p_pos=0.750, tau=0.45 */
                                } else {
                                    return true; /* p_pos=1.000, tau=0.45 */
                                }
                            }
                        } else {
                            if (features[89] /* Feature_HR_Mean_60s_slope */ <= 0.24903f) {
                                return false; /* p_pos=0.214, tau=0.45 */
                            } else {
                                if (features[2] /* ART_DBP_mean */ <= 1.37827f) {
                                    if (features[57] /* HR_max */ <= 0.93240f) {
                                        return false; /* p_pos=0.360, tau=0.45 */
                                    } else {
                                        if (features[80] /* PLETH_SPO2_slope */ <= -2.42818f) {
                                            return false; /* p_pos=0.429, tau=0.45 */
                                        } else {
                                            if (features[91] /* Feature_HR_Delta_60s_slope */ <= 3.08469f) {
                                                if (features[5] /* RR_CO2_mean */ <= -0.32377f) {
                                                    return true; /* p_pos=0.828, tau=0.45 */
                                                } else {
                                                    return false; /* p_pos=0.448, tau=0.45 */
                                                }
                                            } else {
                                                if (features[42] /* PLETH_SPO2_min */ <= 0.33752f) {
                                                    return true; /* p_pos=1.000, tau=0.45 */
                                                } else {
                                                    return true; /* p_pos=0.875, tau=0.45 */
                                                }
                                            }
                                        }
                                    }
                                } else {
                                    return false; /* p_pos=0.273, tau=0.45 */
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
                                return false; /* p_pos=0.200, tau=0.45 */
                            } else {
                                if (features[94] /* Feature_MBP_Delta_60s_slope */ <= -0.93478f) {
                                    return false; /* p_pos=0.308, tau=0.45 */
                                } else {
                                    if (features[66] /* Feature_Pulse_Pressure_max */ <= -0.13412f) {
                                        if (features[10] /* Feature_Shock_Index_mean */ <= 2.23353f) {
                                            if (features[64] /* FIO2_max */ <= 1.08057f) {
                                                return true; /* p_pos=1.000, tau=0.45 */
                                            } else {
                                                return false; /* p_pos=0.448, tau=0.45 */
                                            }
                                        } else {
                                            return true; /* p_pos=1.000, tau=0.45 */
                                        }
                                    } else {
                                        if (features[26] /* FIO2_std */ <= 0.51429f) {
                                            return true; /* p_pos=0.864, tau=0.45 */
                                        } else {
                                            return false; /* p_pos=0.308, tau=0.45 */
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
                                                    return false; /* p_pos=0.194, tau=0.45 */
                                                } else {
                                                    return true; /* p_pos=0.565, tau=0.45 */
                                                }
                                            } else {
                                                return true; /* p_pos=0.696, tau=0.45 */
                                            }
                                        } else {
                                            if (features[0] /* HR_mean */ <= 1.96190f) {
                                                if (features[49] /* Feature_Modified_Shock_Index_min */ <= 1.80962f) {
                                                    return false; /* p_pos=0.042, tau=0.45 */
                                                } else {
                                                    return true; /* p_pos=0.600, tau=0.45 */
                                                }
                                            } else {
                                                return false; /* p_pos=0.296, tau=0.45 */
                                            }
                                        }
                                    } else {
                                        if (features[25] /* ETCO2_std */ <= -0.10776f) {
                                            if (features[10] /* Feature_Shock_Index_mean */ <= 1.91458f) {
                                                if (features[65] /* BT_max */ <= 0.32306f) {
                                                    return true; /* p_pos=0.551, tau=0.45 */
                                                } else {
                                                    return false; /* p_pos=0.143, tau=0.45 */
                                                }
                                            } else {
                                                return true; /* p_pos=0.952, tau=0.45 */
                                            }
                                        } else {
                                            if (features[57] /* HR_max */ <= 3.06016f) {
                                                if (features[11] /* Feature_Modified_Shock_Index_mean */ <= 7.22762f) {
                                                    return false; /* p_pos=0.277, tau=0.45 */
                                                } else {
                                                    return true; /* p_pos=1.000, tau=0.45 */
                                                }
                                            } else {
                                                return false; /* p_pos=0.000, tau=0.45 */
                                            }
                                        }
                                    }
                                } else {
                                    if (features[13] /* Feature_HR_Mean_60s_mean */ <= 2.00163f) {
                                        if (features[64] /* FIO2_max */ <= 0.23513f) {
                                            if (features[89] /* Feature_HR_Mean_60s_slope */ <= -0.92079f) {
                                                if (features[72] /* Feature_HR_Delta_60s_max */ <= 2.42792f) {
                                                    return false; /* p_pos=0.205, tau=0.45 */
                                                } else {
                                                    return true; /* p_pos=0.833, tau=0.45 */
                                                }
                                            } else {
                                                if (features[9] /* Feature_Pulse_Pressure_mean */ <= -0.86577f) {
                                                    return true; /* p_pos=0.787, tau=0.45 */
                                                } else {
                                                    return true; /* p_pos=0.505, tau=0.45 */
                                                }
                                            }
                                        } else {
                                            if (features[10] /* Feature_Shock_Index_mean */ <= 0.97134f) {
                                                if (features[26] /* FIO2_std */ <= 5.07584f) {
                                                    return false; /* p_pos=0.120, tau=0.45 */
                                                } else {
                                                    return true; /* p_pos=0.833, tau=0.45 */
                                                }
                                            } else {
                                                if (features[46] /* BT_min */ <= 0.37905f) {
                                                    return true; /* p_pos=0.511, tau=0.45 */
                                                } else {
                                                    return false; /* p_pos=0.175, tau=0.45 */
                                                }
                                            }
                                        }
                                    } else {
                                        if (features[4] /* PLETH_SPO2_mean */ <= 0.37547f) {
                                            if (features[70] /* Feature_HR_Mean_60s_max */ <= 2.13828f) {
                                                return true; /* p_pos=0.800, tau=0.45 */
                                            } else {
                                                return true; /* p_pos=0.977, tau=0.45 */
                                            }
                                        } else {
                                            return true; /* p_pos=0.500, tau=0.45 */
                                        }
                                    }
                                }
                            } else {
                                if (features[5] /* RR_CO2_mean */ <= 0.18348f) {
                                    return false; /* p_pos=0.333, tau=0.45 */
                                } else {
                                    if (features[22] /* ART_MBP_std */ <= -0.61733f) {
                                        return true; /* p_pos=0.640, tau=0.45 */
                                    } else {
                                        return true; /* p_pos=1.000, tau=0.45 */
                                    }
                                }
                            }
                        }
                    } else {
                        if (features[39] /* ART_SBP_min */ <= -2.13163f) {
                            if (features[15] /* Feature_HR_Delta_60s_mean */ <= 2.40793f) {
                                return true; /* p_pos=0.488, tau=0.45 */
                            } else {
                                if (features[90] /* Feature_HR_Std_60s_slope */ <= -2.03945f) {
                                    return false; /* p_pos=0.200, tau=0.45 */
                                } else {
                                    if (features[83] /* FIO2_slope */ <= 0.50312f) {
                                        if (features[7] /* FIO2_mean */ <= 1.58111f) {
                                            return true; /* p_pos=0.821, tau=0.45 */
                                        } else {
                                            return true; /* p_pos=0.533, tau=0.45 */
                                        }
                                    } else {
                                        return true; /* p_pos=0.950, tau=0.45 */
                                    }
                                }
                            }
                        } else {
                            if (features[57] /* HR_max */ <= 0.93240f) {
                                return true; /* p_pos=0.455, tau=0.45 */
                            } else {
                                if (features[70] /* Feature_HR_Mean_60s_max */ <= 1.47621f) {
                                    return false; /* p_pos=0.200, tau=0.45 */
                                } else {
                                    if (features[42] /* PLETH_SPO2_min */ <= 0.33752f) {
                                        if (features[31] /* Feature_Rate_Pressure_Product_std */ <= 4.40656f) {
                                            if (features[15] /* Feature_HR_Delta_60s_mean */ <= 2.04112f) {
                                                return true; /* p_pos=0.844, tau=0.45 */
                                            } else {
                                                if (features[47] /* Feature_Pulse_Pressure_min */ <= 1.25459f) {
                                                    return true; /* p_pos=0.995, tau=0.45 */
                                                } else {
                                                    return true; /* p_pos=0.889, tau=0.45 */
                                                }
                                            }
                                        } else {
                                            return true; /* p_pos=0.750, tau=0.45 */
                                        }
                                    } else {
                                        if (features[51] /* Feature_HR_Mean_60s_min */ <= -0.19618f) {
                                            return false; /* p_pos=0.333, tau=0.45 */
                                        } else {
                                            if (features[7] /* FIO2_mean */ <= -0.81500f) {
                                                return false; /* p_pos=0.286, tau=0.45 */
                                            } else {
                                                if (features[15] /* Feature_HR_Delta_60s_mean */ <= 2.84390f) {
                                                    return true; /* p_pos=0.709, tau=0.45 */
                                                } else {
                                                    return true; /* p_pos=0.981, tau=0.45 */
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
                                        return false; /* p_pos=0.396, tau=0.45 */
                                    } else {
                                        return false; /* p_pos=0.074, tau=0.45 */
                                    }
                                } else {
                                    if (features[89] /* Feature_HR_Mean_60s_slope */ <= 0.12854f) {
                                        if (features[67] /* Feature_Shock_Index_max */ <= 0.82053f) {
                                            return true; /* p_pos=0.737, tau=0.45 */
                                        } else {
                                            return false; /* p_pos=0.250, tau=0.45 */
                                        }
                                    } else {
                                        if (features[27] /* BT_std */ <= -0.27089f) {
                                            return true; /* p_pos=0.971, tau=0.45 */
                                        } else {
                                            if (features[8] /* BT_mean */ <= 0.30375f) {
                                                return true; /* p_pos=0.526, tau=0.45 */
                                            } else {
                                                return true; /* p_pos=0.955, tau=0.45 */
                                            }
                                        }
                                    }
                                }
                            } else {
                                if (features[67] /* Feature_Shock_Index_max */ <= 0.20159f) {
                                    return false; /* p_pos=0.267, tau=0.45 */
                                } else {
                                    if (features[33] /* Feature_HR_Std_60s_std */ <= 0.72579f) {
                                        return true; /* p_pos=0.464, tau=0.45 */
                                    } else {
                                        if (features[33] /* Feature_HR_Std_60s_std */ <= 3.36557f) {
                                            if (features[17] /* Feature_MBP_Std_60s_mean */ <= -0.04182f) {
                                                if (features[56] /* Feature_MBP_Delta_60s_min */ <= 0.15360f) {
                                                    return false; /* p_pos=0.333, tau=0.45 */
                                                } else {
                                                    return true; /* p_pos=0.893, tau=0.45 */
                                                }
                                            } else {
                                                if (features[82] /* ETCO2_slope */ <= 1.59167f) {
                                                    return true; /* p_pos=1.000, tau=0.45 */
                                                } else {
                                                    return true; /* p_pos=0.800, tau=0.45 */
                                                }
                                            }
                                        } else {
                                            return true; /* p_pos=0.500, tau=0.45 */
                                        }
                                    }
                                }
                            }
                        } else {
                            if (features[31] /* Feature_Rate_Pressure_Product_std */ <= 0.66126f) {
                                if (features[7] /* FIO2_mean */ <= -0.10623f) {
                                    return true; /* p_pos=0.833, tau=0.45 */
                                } else {
                                    if (features[45] /* FIO2_min */ <= 1.86492f) {
                                        return false; /* p_pos=0.326, tau=0.45 */
                                    } else {
                                        return true; /* p_pos=0.786, tau=0.45 */
                                    }
                                }
                            } else {
                                if (features[74] /* Feature_MBP_Std_60s_max */ <= -0.47003f) {
                                    return true; /* p_pos=0.730, tau=0.45 */
                                } else {
                                    if (features[3] /* ART_MBP_mean */ <= 2.43176f) {
                                        if (features[0] /* HR_mean */ <= 1.70700f) {
                                            if (features[57] /* HR_max */ <= 1.81562f) {
                                                if (features[75] /* Feature_MBP_Delta_60s_max */ <= 0.84489f) {
                                                    return false; /* p_pos=0.318, tau=0.45 */
                                                } else {
                                                    return false; /* p_pos=0.117, tau=0.45 */
                                                }
                                            } else {
                                                return true; /* p_pos=0.889, tau=0.45 */
                                            }
                                        } else {
                                            if (features[71] /* Feature_HR_Std_60s_max */ <= 0.57745f) {
                                                return false; /* p_pos=0.408, tau=0.45 */
                                            } else {
                                                return true; /* p_pos=0.800, tau=0.45 */
                                            }
                                        }
                                    } else {
                                        return true; /* p_pos=1.000, tau=0.45 */
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
                                                    return false; /* p_pos=0.333, tau=0.45 */
                                                } else {
                                                    return true; /* p_pos=0.800, tau=0.45 */
                                                }
                                            } else {
                                                if (features[0] /* HR_mean */ <= 1.74432f) {
                                                    return false; /* p_pos=0.211, tau=0.45 */
                                                } else {
                                                    return false; /* p_pos=0.378, tau=0.45 */
                                                }
                                            }
                                        } else {
                                            return true; /* p_pos=0.683, tau=0.45 */
                                        }
                                    } else {
                                        return true; /* p_pos=0.840, tau=0.45 */
                                    }
                                } else {
                                    if (features[51] /* Feature_HR_Mean_60s_min */ <= 1.20253f) {
                                        return false; /* p_pos=0.262, tau=0.45 */
                                    } else {
                                        if (features[45] /* FIO2_min */ <= -0.61498f) {
                                            return false; /* p_pos=0.231, tau=0.45 */
                                        } else {
                                            if (features[30] /* Feature_Modified_Shock_Index_std */ <= 0.72860f) {
                                                if (features[57] /* HR_max */ <= 3.72257f) {
                                                    return true; /* p_pos=0.916, tau=0.45 */
                                                } else {
                                                    return true; /* p_pos=0.583, tau=0.45 */
                                                }
                                            } else {
                                                return true; /* p_pos=0.556, tau=0.45 */
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
                                                    return true; /* p_pos=0.694, tau=0.45 */
                                                } else {
                                                    return false; /* p_pos=0.000, tau=0.45 */
                                                }
                                            } else {
                                                if (features[23] /* PLETH_SPO2_std */ <= 0.12382f) {
                                                    return true; /* p_pos=0.982, tau=0.45 */
                                                } else {
                                                    return true; /* p_pos=0.750, tau=0.45 */
                                                }
                                            }
                                        } else {
                                            if (features[46] /* BT_min */ <= 0.33040f) {
                                                if (features[83] /* FIO2_slope */ <= 4.15020f) {
                                                    return true; /* p_pos=0.913, tau=0.45 */
                                                } else {
                                                    return false; /* p_pos=0.333, tau=0.45 */
                                                }
                                            } else {
                                                return true; /* p_pos=1.000, tau=0.45 */
                                            }
                                        }
                                    } else {
                                        if (features[75] /* Feature_MBP_Delta_60s_max */ <= 0.26932f) {
                                            return false; /* p_pos=0.211, tau=0.45 */
                                        } else {
                                            if (features[2] /* ART_DBP_mean */ <= 2.12320f) {
                                                if (features[51] /* Feature_HR_Mean_60s_min */ <= 0.77887f) {
                                                    return true; /* p_pos=0.585, tau=0.45 */
                                                } else {
                                                    return true; /* p_pos=0.914, tau=0.45 */
                                                }
                                            } else {
                                                return false; /* p_pos=0.294, tau=0.45 */
                                            }
                                        }
                                    }
                                } else {
                                    if (features[17] /* Feature_MBP_Std_60s_mean */ <= -0.51468f) {
                                        return false; /* p_pos=0.400, tau=0.45 */
                                    } else {
                                        if (features[48] /* Feature_Shock_Index_min */ <= 1.44733f) {
                                            if (features[63] /* ETCO2_max */ <= 2.53911f) {
                                                if (features[44] /* ETCO2_min */ <= 0.71491f) {
                                                    return true; /* p_pos=0.989, tau=0.45 */
                                                } else {
                                                    return true; /* p_pos=0.769, tau=0.45 */
                                                }
                                            } else {
                                                return true; /* p_pos=0.812, tau=0.45 */
                                            }
                                        } else {
                                            return true; /* p_pos=0.500, tau=0.45 */
                                        }
                                    }
                                }
                            }
                        } else {
                            if (features[57] /* HR_max */ <= 1.93606f) {
                                if (features[7] /* FIO2_mean */ <= 2.08419f) {
                                    if (features[38] /* HR_min */ <= -0.91266f) {
                                        return false; /* p_pos=0.000, tau=0.45 */
                                    } else {
                                        if (features[86] /* Feature_Shock_Index_slope */ <= -2.33758f) {
                                            return false; /* p_pos=0.333, tau=0.45 */
                                        } else {
                                            if (features[40] /* ART_DBP_min */ <= 1.45399f) {
                                                if (features[42] /* PLETH_SPO2_min */ <= -3.95172f) {
                                                    return false; /* p_pos=0.200, tau=0.45 */
                                                } else {
                                                    return true; /* p_pos=0.933, tau=0.45 */
                                                }
                                            } else {
                                                return false; /* p_pos=0.111, tau=0.45 */
                                            }
                                        }
                                    }
                                } else {
                                    if (features[53] /* Feature_HR_Delta_60s_min */ <= 0.00981f) {
                                        return false; /* p_pos=0.350, tau=0.45 */
                                    } else {
                                        return true; /* p_pos=1.000, tau=0.45 */
                                    }
                                }
                            } else {
                                if (features[48] /* Feature_Shock_Index_min */ <= -0.53067f) {
                                    return false; /* p_pos=0.409, tau=0.45 */
                                } else {
                                    if (features[0] /* HR_mean */ <= 2.67927f) {
                                        if (features[69] /* Feature_Rate_Pressure_Product_max */ <= 2.90333f) {
                                            if (features[45] /* FIO2_min */ <= -0.55663f) {
                                                return true; /* p_pos=0.610, tau=0.45 */
                                            } else {
                                                if (features[36] /* Feature_MBP_Std_60s_std */ <= -0.52375f) {
                                                    return false; /* p_pos=0.400, tau=0.45 */
                                                } else {
                                                    return true; /* p_pos=0.920, tau=0.45 */
                                                }
                                            }
                                        } else {
                                            return true; /* p_pos=0.483, tau=0.45 */
                                        }
                                    } else {
                                        if (features[74] /* Feature_MBP_Std_60s_max */ <= -0.55937f) {
                                            return true; /* p_pos=0.786, tau=0.45 */
                                        } else {
                                            if (features[92] /* Feature_MBP_Mean_60s_slope */ <= -2.43179f) {
                                                return true; /* p_pos=0.600, tau=0.45 */
                                            } else {
                                                if (features[25] /* ETCO2_std */ <= 3.02202f) {
                                                    return true; /* p_pos=0.979, tau=0.45 */
                                                } else {
                                                    return true; /* p_pos=0.860, tau=0.45 */
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
                                                return true; /* p_pos=0.500, tau=0.45 */
                                            } else {
                                                if (features[7] /* FIO2_mean */ <= -0.60292f) {
                                                    return false; /* p_pos=0.167, tau=0.45 */
                                                } else {
                                                    return false; /* p_pos=0.000, tau=0.45 */
                                                }
                                            }
                                        } else {
                                            if (features[72] /* Feature_HR_Delta_60s_max */ <= 3.97573f) {
                                                if (features[14] /* Feature_HR_Std_60s_mean */ <= 3.52168f) {
                                                    return false; /* p_pos=0.059, tau=0.45 */
                                                } else {
                                                    return false; /* p_pos=0.364, tau=0.45 */
                                                }
                                            } else {
                                                return true; /* p_pos=0.800, tau=0.45 */
                                            }
                                        }
                                    } else {
                                        return true; /* p_pos=1.000, tau=0.45 */
                                    }
                                } else {
                                    return true; /* p_pos=0.773, tau=0.45 */
                                }
                            } else {
                                if (features[12] /* Feature_Rate_Pressure_Product_mean */ <= 0.55374f) {
                                    if (features[26] /* FIO2_std */ <= -0.19998f) {
                                        if (features[49] /* Feature_Modified_Shock_Index_min */ <= -1.35952f) {
                                            return true; /* p_pos=0.800, tau=0.45 */
                                        } else {
                                            if (features[55] /* Feature_MBP_Std_60s_min */ <= -0.28558f) {
                                                return false; /* p_pos=0.444, tau=0.45 */
                                            } else {
                                                if (features[15] /* Feature_HR_Delta_60s_mean */ <= 1.02246f) {
                                                    return false; /* p_pos=0.016, tau=0.45 */
                                                } else {
                                                    return false; /* p_pos=0.146, tau=0.45 */
                                                }
                                            }
                                        }
                                    } else {
                                        if (features[92] /* Feature_MBP_Mean_60s_slope */ <= -0.88450f) {
                                            return true; /* p_pos=0.552, tau=0.45 */
                                        } else {
                                            if (features[86] /* Feature_Shock_Index_slope */ <= -1.84747f) {
                                                return true; /* p_pos=0.625, tau=0.45 */
                                            } else {
                                                if (features[28] /* Feature_Pulse_Pressure_std */ <= 2.43012f) {
                                                    return false; /* p_pos=0.112, tau=0.45 */
                                                } else {
                                                    return true; /* p_pos=0.500, tau=0.45 */
                                                }
                                            }
                                        }
                                    }
                                } else {
                                    if (features[10] /* Feature_Shock_Index_mean */ <= -0.11503f) {
                                        return false; /* p_pos=0.111, tau=0.45 */
                                    } else {
                                        return true; /* p_pos=0.514, tau=0.45 */
                                    }
                                }
                            }
                        } else {
                            if (features[64] /* FIO2_max */ <= 1.45880f) {
                                if (features[89] /* Feature_HR_Mean_60s_slope */ <= 1.98734f) {
                                    if (features[14] /* Feature_HR_Std_60s_mean */ <= 4.57104f) {
                                        if (features[19] /* HR_std */ <= 2.05422f) {
                                            return false; /* p_pos=0.333, tau=0.45 */
                                        } else {
                                            return true; /* p_pos=0.705, tau=0.45 */
                                        }
                                    } else {
                                        return false; /* p_pos=0.091, tau=0.45 */
                                    }
                                } else {
                                    return true; /* p_pos=0.909, tau=0.45 */
                                }
                            } else {
                                return false; /* p_pos=0.176, tau=0.45 */
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
                                                    return false; /* p_pos=0.014, tau=0.45 */
                                                } else {
                                                    return false; /* p_pos=0.133, tau=0.45 */
                                                }
                                            } else {
                                                return false; /* p_pos=0.286, tau=0.45 */
                                            }
                                        } else {
                                            return true; /* p_pos=0.600, tau=0.45 */
                                        }
                                    } else {
                                        if (features[34] /* Feature_HR_Delta_60s_std */ <= 3.07076f) {
                                            if (features[13] /* Feature_HR_Mean_60s_mean */ <= -0.21994f) {
                                                return false; /* p_pos=0.300, tau=0.45 */
                                            } else {
                                                return false; /* p_pos=0.029, tau=0.45 */
                                            }
                                        } else {
                                            return true; /* p_pos=0.500, tau=0.45 */
                                        }
                                    }
                                } else {
                                    if (features[67] /* Feature_Shock_Index_max */ <= -0.07194f) {
                                        if (features[37] /* Feature_MBP_Delta_60s_std */ <= -0.51445f) {
                                            return false; /* p_pos=0.406, tau=0.45 */
                                        } else {
                                            if (features[24] /* RR_CO2_std */ <= 1.51756f) {
                                                if (features[35] /* Feature_MBP_Mean_60s_std */ <= -0.70651f) {
                                                    return false; /* p_pos=0.400, tau=0.45 */
                                                } else {
                                                    return false; /* p_pos=0.019, tau=0.45 */
                                                }
                                            } else {
                                                return true; /* p_pos=0.500, tau=0.45 */
                                            }
                                        }
                                    } else {
                                        if (features[61] /* PLETH_SPO2_max */ <= -1.88715f) {
                                            if (features[56] /* Feature_MBP_Delta_60s_min */ <= -1.53304f) {
                                                return false; /* p_pos=0.308, tau=0.45 */
                                            } else {
                                                return true; /* p_pos=0.811, tau=0.45 */
                                            }
                                        } else {
                                            if (features[59] /* ART_DBP_max */ <= -0.35835f) {
                                                return true; /* p_pos=0.681, tau=0.45 */
                                            } else {
                                                if (features[89] /* Feature_HR_Mean_60s_slope */ <= 1.53935f) {
                                                    return false; /* p_pos=0.276, tau=0.45 */
                                                } else {
                                                    return true; /* p_pos=0.532, tau=0.45 */
                                                }
                                            }
                                        }
                                    }
                                }
                            } else {
                                if (features[68] /* Feature_Modified_Shock_Index_max */ <= 0.48425f) {
                                    if (features[40] /* ART_DBP_min */ <= 0.21343f) {
                                        return true; /* p_pos=0.731, tau=0.45 */
                                    } else {
                                        if (features[72] /* Feature_HR_Delta_60s_max */ <= 4.45784f) {
                                            if (features[39] /* ART_SBP_min */ <= 1.82894f) {
                                                if (features[49] /* Feature_Modified_Shock_Index_min */ <= -0.20428f) {
                                                    return false; /* p_pos=0.151, tau=0.45 */
                                                } else {
                                                    return true; /* p_pos=1.000, tau=0.45 */
                                                }
                                            } else {
                                                return true; /* p_pos=0.900, tau=0.45 */
                                            }
                                        } else {
                                            return true; /* p_pos=0.938, tau=0.45 */
                                        }
                                    }
                                } else {
                                    if (features[64] /* FIO2_max */ <= -0.25434f) {
                                        return false; /* p_pos=0.188, tau=0.45 */
                                    } else {
                                        if (features[40] /* ART_DBP_min */ <= 1.01290f) {
                                            if (features[73] /* Feature_MBP_Mean_60s_max */ <= -0.22220f) {
                                                return false; /* p_pos=0.286, tau=0.45 */
                                            } else {
                                                if (features[30] /* Feature_Modified_Shock_Index_std */ <= 0.41062f) {
                                                    return false; /* p_pos=0.200, tau=0.45 */
                                                } else {
                                                    return true; /* p_pos=0.951, tau=0.45 */
                                                }
                                            }
                                        } else {
                                            return false; /* p_pos=0.357, tau=0.45 */
                                        }
                                    }
                                }
                            }
                        } else {
                            if (features[8] /* BT_mean */ <= -0.19121f) {
                                return false; /* p_pos=0.238, tau=0.45 */
                            } else {
                                if (features[23] /* PLETH_SPO2_std */ <= 0.86695f) {
                                    if (features[72] /* Feature_HR_Delta_60s_max */ <= 1.94581f) {
                                        if (features[54] /* Feature_MBP_Mean_60s_min */ <= 0.55317f) {
                                            if (features[49] /* Feature_Modified_Shock_Index_min */ <= -0.15565f) {
                                                return false; /* p_pos=0.280, tau=0.45 */
                                            } else {
                                                return true; /* p_pos=0.694, tau=0.45 */
                                            }
                                        } else {
                                            if (features[36] /* Feature_MBP_Std_60s_std */ <= 2.14777f) {
                                                return false; /* p_pos=0.089, tau=0.45 */
                                            } else {
                                                return true; /* p_pos=0.800, tau=0.45 */
                                            }
                                        }
                                    } else {
                                        if (features[82] /* ETCO2_slope */ <= -0.43067f) {
                                            return false; /* p_pos=0.396, tau=0.45 */
                                        } else {
                                            if (features[44] /* ETCO2_min */ <= -1.76231f) {
                                                return false; /* p_pos=0.286, tau=0.45 */
                                            } else {
                                                if (features[76] /* HR_slope */ <= -2.18474f) {
                                                    return true; /* p_pos=0.472, tau=0.45 */
                                                } else {
                                                    return true; /* p_pos=0.771, tau=0.45 */
                                                }
                                            }
                                        }
                                    }
                                } else {
                                    if (features[57] /* HR_max */ <= 1.91599f) {
                                        return false; /* p_pos=0.444, tau=0.45 */
                                    } else {
                                        if (features[48] /* Feature_Shock_Index_min */ <= 0.24761f) {
                                            if (features[22] /* ART_MBP_std */ <= -0.29475f) {
                                                return true; /* p_pos=1.000, tau=0.45 */
                                            } else {
                                                return true; /* p_pos=0.750, tau=0.45 */
                                            }
                                        } else {
                                            return false; /* p_pos=0.333, tau=0.45 */
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
                                return false; /* p_pos=0.111, tau=0.45 */
                            } else {
                                if (features[37] /* Feature_MBP_Delta_60s_std */ <= -0.31752f) {
                                    return true; /* p_pos=1.000, tau=0.45 */
                                } else {
                                    if (features[9] /* Feature_Pulse_Pressure_mean */ <= -0.08176f) {
                                        return true; /* p_pos=0.615, tau=0.45 */
                                    } else {
                                        return true; /* p_pos=0.918, tau=0.45 */
                                    }
                                }
                            }
                        } else {
                            return false; /* p_pos=0.273, tau=0.45 */
                        }
                    } else {
                        if (features[26] /* FIO2_std */ <= 0.42899f) {
                            if (features[67] /* Feature_Shock_Index_max */ <= 0.63007f) {
                                if (features[88] /* Feature_Rate_Pressure_Product_slope */ <= 0.54319f) {
                                    return false; /* p_pos=0.114, tau=0.45 */
                                } else {
                                    return true; /* p_pos=1.000, tau=0.45 */
                                }
                            } else {
                                return true; /* p_pos=0.938, tau=0.45 */
                            }
                        } else {
                            return true; /* p_pos=1.000, tau=0.45 */
                        }
                    }
                }
            } else {
                if (features[13] /* Feature_HR_Mean_60s_mean */ <= 0.97998f) {
                    if (features[70] /* Feature_HR_Mean_60s_max */ <= 0.65991f) {
                        if (features[46] /* BT_min */ <= 0.18445f) {
                            if (features[57] /* HR_max */ <= 4.76638f) {
                                if (features[25] /* ETCO2_std */ <= -0.48483f) {
                                    return true; /* p_pos=0.571, tau=0.45 */
                                } else {
                                    if (features[66] /* Feature_Pulse_Pressure_max */ <= 0.22711f) {
                                        if (features[12] /* Feature_Rate_Pressure_Product_mean */ <= 0.12729f) {
                                            if (features[21] /* ART_DBP_std */ <= -0.04616f) {
                                                if (features[82] /* ETCO2_slope */ <= 0.91756f) {
                                                    return false; /* p_pos=0.030, tau=0.45 */
                                                } else {
                                                    return false; /* p_pos=0.200, tau=0.45 */
                                                }
                                            } else {
                                                return true; /* p_pos=0.522, tau=0.45 */
                                            }
                                        } else {
                                            return true; /* p_pos=1.000, tau=0.45 */
                                        }
                                    } else {
                                        if (features[72] /* Feature_HR_Delta_60s_max */ <= 2.96077f) {
                                            if (features[87] /* Feature_Modified_Shock_Index_slope */ <= -5.46745f) {
                                                return false; /* p_pos=0.200, tau=0.45 */
                                            } else {
                                                return false; /* p_pos=0.000, tau=0.45 */
                                            }
                                        } else {
                                            if (features[7] /* FIO2_mean */ <= 1.39625f) {
                                                return false; /* p_pos=0.029, tau=0.45 */
                                            } else {
                                                return false; /* p_pos=0.375, tau=0.45 */
                                            }
                                        }
                                    }
                                }
                            } else {
                                return true; /* p_pos=0.667, tau=0.45 */
                            }
                        } else {
                            if (features[40] /* ART_DBP_min */ <= -1.71635f) {
                                if (features[32] /* Feature_HR_Mean_60s_std */ <= 3.11182f) {
                                    if (features[58] /* ART_SBP_max */ <= 0.80102f) {
                                        if (features[36] /* Feature_MBP_Std_60s_std */ <= 0.46935f) {
                                            return false; /* p_pos=0.000, tau=0.45 */
                                        } else {
                                            return false; /* p_pos=0.200, tau=0.45 */
                                        }
                                    } else {
                                        return false; /* p_pos=0.400, tau=0.45 */
                                    }
                                } else {
                                    return true; /* p_pos=0.500, tau=0.45 */
                                }
                            } else {
                                if (features[66] /* Feature_Pulse_Pressure_max */ <= 0.21266f) {
                                    if (features[85] /* Feature_Pulse_Pressure_slope */ <= -0.01538f) {
                                        if (features[10] /* Feature_Shock_Index_mean */ <= -0.19768f) {
                                            if (features[53] /* Feature_HR_Delta_60s_min */ <= -2.72761f) {
                                                if (features[28] /* Feature_Pulse_Pressure_std */ <= 0.05852f) {
                                                    return false; /* p_pos=0.040, tau=0.45 */
                                                } else {
                                                    return false; /* p_pos=0.250, tau=0.45 */
                                                }
                                            } else {
                                                return true; /* p_pos=0.500, tau=0.45 */
                                            }
                                        } else {
                                            if (features[72] /* Feature_HR_Delta_60s_max */ <= 3.87424f) {
                                                if (features[32] /* Feature_HR_Mean_60s_std */ <= 1.15482f) {
                                                    return false; /* p_pos=0.338, tau=0.45 */
                                                } else {
                                                    return false; /* p_pos=0.049, tau=0.45 */
                                                }
                                            } else {
                                                return true; /* p_pos=0.769, tau=0.45 */
                                            }
                                        }
                                    } else {
                                        if (features[55] /* Feature_MBP_Std_60s_min */ <= 0.08274f) {
                                            if (features[74] /* Feature_MBP_Std_60s_max */ <= -0.47016f) {
                                                if (features[13] /* Feature_HR_Mean_60s_mean */ <= -0.12373f) {
                                                    return true; /* p_pos=0.523, tau=0.45 */
                                                } else {
                                                    return true; /* p_pos=1.000, tau=0.45 */
                                                }
                                            } else {
                                                if (features[29] /* Feature_Shock_Index_std */ <= 0.95703f) {
                                                    return false; /* p_pos=0.276, tau=0.45 */
                                                } else {
                                                    return true; /* p_pos=0.650, tau=0.45 */
                                                }
                                            }
                                        } else {
                                            if (features[75] /* Feature_MBP_Delta_60s_max */ <= -0.40548f) {
                                                return false; /* p_pos=0.211, tau=0.45 */
                                            } else {
                                                return false; /* p_pos=0.028, tau=0.45 */
                                            }
                                        }
                                    }
                                } else {
                                    if (features[14] /* Feature_HR_Std_60s_mean */ <= 3.80881f) {
                                        if (features[2] /* ART_DBP_mean */ <= 0.77524f) {
                                            if (features[1] /* ART_SBP_mean */ <= -0.40549f) {
                                                return true; /* p_pos=0.917, tau=0.45 */
                                            } else {
                                                if (features[53] /* Feature_HR_Delta_60s_min */ <= -3.52817f) {
                                                    return false; /* p_pos=0.116, tau=0.45 */
                                                } else {
                                                    return true; /* p_pos=0.545, tau=0.45 */
                                                }
                                            }
                                        } else {
                                            return true; /* p_pos=1.000, tau=0.45 */
                                        }
                                    } else {
                                        if (features[33] /* Feature_HR_Std_60s_std */ <= 3.52496f) {
                                            return true; /* p_pos=0.947, tau=0.45 */
                                        } else {
                                            return true; /* p_pos=0.591, tau=0.45 */
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
                                                    return false; /* p_pos=0.409, tau=0.45 */
                                                } else {
                                                    return false; /* p_pos=0.214, tau=0.45 */
                                                }
                                            } else {
                                                if (features[59] /* ART_DBP_max */ <= -0.39988f) {
                                                    return true; /* p_pos=0.873, tau=0.45 */
                                                } else {
                                                    return false; /* p_pos=0.425, tau=0.45 */
                                                }
                                            }
                                        } else {
                                            if (features[59] /* ART_DBP_max */ <= 0.14010f) {
                                                if (features[13] /* Feature_HR_Mean_60s_mean */ <= -0.36510f) {
                                                    return false; /* p_pos=0.170, tau=0.45 */
                                                } else {
                                                    return false; /* p_pos=0.387, tau=0.45 */
                                                }
                                            } else {
                                                if (features[9] /* Feature_Pulse_Pressure_mean */ <= 0.65468f) {
                                                    return false; /* p_pos=0.255, tau=0.45 */
                                                } else {
                                                    return false; /* p_pos=0.000, tau=0.45 */
                                                }
                                            }
                                        }
                                    } else {
                                        if (features[28] /* Feature_Pulse_Pressure_std */ <= 0.55272f) {
                                            if (features[4] /* PLETH_SPO2_mean */ <= 0.33280f) {
                                                if (features[86] /* Feature_Shock_Index_slope */ <= -1.87662f) {
                                                    return true; /* p_pos=0.538, tau=0.45 */
                                                } else {
                                                    return true; /* p_pos=0.887, tau=0.45 */
                                                }
                                            } else {
                                                return true; /* p_pos=0.524, tau=0.45 */
                                            }
                                        } else {
                                            if (features[57] /* HR_max */ <= 2.91964f) {
                                                return true; /* p_pos=0.633, tau=0.45 */
                                            } else {
                                                return false; /* p_pos=0.087, tau=0.45 */
                                            }
                                        }
                                    }
                                } else {
                                    return true; /* p_pos=0.775, tau=0.45 */
                                }
                            } else {
                                if (features[51] /* Feature_HR_Mean_60s_min */ <= -1.24269f) {
                                    if (features[20] /* ART_SBP_std */ <= -0.59810f) {
                                        return true; /* p_pos=0.889, tau=0.45 */
                                    } else {
                                        return true; /* p_pos=0.457, tau=0.45 */
                                    }
                                } else {
                                    if (features[19] /* HR_std */ <= 3.54280f) {
                                        if (features[24] /* RR_CO2_std */ <= 0.28346f) {
                                            if (features[47] /* Feature_Pulse_Pressure_min */ <= -1.18758f) {
                                                return true; /* p_pos=1.000, tau=0.45 */
                                            } else {
                                                if (features[94] /* Feature_MBP_Delta_60s_slope */ <= 0.28620f) {
                                                    return true; /* p_pos=0.767, tau=0.45 */
                                                } else {
                                                    return false; /* p_pos=0.300, tau=0.45 */
                                                }
                                            }
                                        } else {
                                            return false; /* p_pos=0.250, tau=0.45 */
                                        }
                                    } else {
                                        if (features[74] /* Feature_MBP_Std_60s_max */ <= -0.58669f) {
                                            return false; /* p_pos=0.400, tau=0.45 */
                                        } else {
                                            if (features[43] /* RR_CO2_min */ <= 0.45272f) {
                                                if (features[65] /* BT_max */ <= 0.25719f) {
                                                    return true; /* p_pos=1.000, tau=0.45 */
                                                } else {
                                                    return true; /* p_pos=0.867, tau=0.45 */
                                                }
                                            } else {
                                                return true; /* p_pos=0.692, tau=0.45 */
                                            }
                                        }
                                    }
                                }
                            }
                        } else {
                            if (features[91] /* Feature_HR_Delta_60s_slope */ <= 0.63071f) {
                                if (features[38] /* HR_min */ <= -1.18406f) {
                                    if (features[27] /* BT_std */ <= -0.26910f) {
                                        return true; /* p_pos=0.810, tau=0.45 */
                                    } else {
                                        if (features[39] /* ART_SBP_min */ <= -0.63999f) {
                                            return true; /* p_pos=0.818, tau=0.45 */
                                        } else {
                                            if (features[56] /* Feature_MBP_Delta_60s_min */ <= 0.53911f) {
                                                if (features[44] /* ETCO2_min */ <= 0.58100f) {
                                                    return false; /* p_pos=0.148, tau=0.45 */
                                                } else {
                                                    return true; /* p_pos=0.625, tau=0.45 */
                                                }
                                            } else {
                                                return true; /* p_pos=0.714, tau=0.45 */
                                            }
                                        }
                                    }
                                } else {
                                    if (features[65] /* BT_max */ <= 0.25719f) {
                                        if (features[29] /* Feature_Shock_Index_std */ <= 0.89488f) {
                                            if (features[12] /* Feature_Rate_Pressure_Product_mean */ <= 1.25072f) {
                                                return true; /* p_pos=0.600, tau=0.45 */
                                            } else {
                                                return false; /* p_pos=0.000, tau=0.45 */
                                            }
                                        } else {
                                            if (features[16] /* Feature_MBP_Mean_60s_mean */ <= 0.00499f) {
                                                if (features[93] /* Feature_MBP_Std_60s_slope */ <= 0.03832f) {
                                                    return true; /* p_pos=0.848, tau=0.45 */
                                                } else {
                                                    return true; /* p_pos=0.556, tau=0.45 */
                                                }
                                            } else {
                                                if (features[43] /* RR_CO2_min */ <= -0.33168f) {
                                                    return true; /* p_pos=1.000, tau=0.45 */
                                                } else {
                                                    return true; /* p_pos=0.909, tau=0.45 */
                                                }
                                            }
                                        }
                                    } else {
                                        if (features[11] /* Feature_Modified_Shock_Index_mean */ <= 0.64701f) {
                                            if (features[47] /* Feature_Pulse_Pressure_min */ <= -0.34545f) {
                                                return true; /* p_pos=0.735, tau=0.45 */
                                            } else {
                                                if (features[19] /* HR_std */ <= 4.56957f) {
                                                    return false; /* p_pos=0.362, tau=0.45 */
                                                } else {
                                                    return true; /* p_pos=0.625, tau=0.45 */
                                                }
                                            }
                                        } else {
                                            return true; /* p_pos=1.000, tau=0.45 */
                                        }
                                    }
                                }
                            } else {
                                if (features[0] /* HR_mean */ <= 0.30527f) {
                                    if (features[15] /* Feature_HR_Delta_60s_mean */ <= 2.24350f) {
                                        return true; /* p_pos=0.517, tau=0.45 */
                                    } else {
                                        if (features[82] /* ETCO2_slope */ <= -0.20597f) {
                                            return true; /* p_pos=0.682, tau=0.45 */
                                        } else {
                                            if (features[0] /* HR_mean */ <= -0.05043f) {
                                                return true; /* p_pos=1.000, tau=0.45 */
                                            } else {
                                                return true; /* p_pos=0.808, tau=0.45 */
                                            }
                                        }
                                    }
                                } else {
                                    if (features[87] /* Feature_Modified_Shock_Index_slope */ <= 1.40503f) {
                                        if (features[67] /* Feature_Shock_Index_max */ <= 0.99947f) {
                                            return true; /* p_pos=0.619, tau=0.45 */
                                        } else {
                                            if (features[31] /* Feature_Rate_Pressure_Product_std */ <= 2.56831f) {
                                                return true; /* p_pos=0.952, tau=0.45 */
                                            } else {
                                                return true; /* p_pos=0.750, tau=0.45 */
                                            }
                                        }
                                    } else {
                                        if (features[74] /* Feature_MBP_Std_60s_max */ <= -0.57815f) {
                                            return true; /* p_pos=0.800, tau=0.45 */
                                        } else {
                                            return true; /* p_pos=1.000, tau=0.45 */
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
                                            return false; /* p_pos=0.100, tau=0.45 */
                                        } else {
                                            if (features[16] /* Feature_MBP_Mean_60s_mean */ <= -0.20156f) {
                                                return true; /* p_pos=0.850, tau=0.45 */
                                            } else {
                                                return false; /* p_pos=0.286, tau=0.45 */
                                            }
                                        }
                                    } else {
                                        return true; /* p_pos=1.000, tau=0.45 */
                                    }
                                } else {
                                    if (features[39] /* ART_SBP_min */ <= -0.19421f) {
                                        return true; /* p_pos=0.750, tau=0.45 */
                                    } else {
                                        if (features[52] /* Feature_HR_Std_60s_min */ <= 5.33201f) {
                                            if (features[68] /* Feature_Modified_Shock_Index_max */ <= 1.38653f) {
                                                if (features[5] /* RR_CO2_mean */ <= 0.52584f) {
                                                    return false; /* p_pos=0.250, tau=0.45 */
                                                } else {
                                                    return true; /* p_pos=0.889, tau=0.45 */
                                                }
                                            } else {
                                                return false; /* p_pos=0.042, tau=0.45 */
                                            }
                                        } else {
                                            return true; /* p_pos=0.800, tau=0.45 */
                                        }
                                    }
                                }
                            } else {
                                if (features[69] /* Feature_Rate_Pressure_Product_max */ <= 1.56818f) {
                                    return true; /* p_pos=0.935, tau=0.45 */
                                } else {
                                    return true; /* p_pos=0.600, tau=0.45 */
                                }
                            }
                        } else {
                            if (features[88] /* Feature_Rate_Pressure_Product_slope */ <= 0.63688f) {
                                if (features[90] /* Feature_HR_Std_60s_slope */ <= -3.56961f) {
                                    if (features[59] /* ART_DBP_max */ <= -0.19220f) {
                                        return true; /* p_pos=0.833, tau=0.45 */
                                    } else {
                                        if (features[77] /* ART_SBP_slope */ <= 0.39489f) {
                                            if (features[50] /* Feature_Rate_Pressure_Product_min */ <= 0.71488f) {
                                                return true; /* p_pos=0.676, tau=0.45 */
                                            } else {
                                                return false; /* p_pos=0.278, tau=0.45 */
                                            }
                                        } else {
                                            return false; /* p_pos=0.167, tau=0.45 */
                                        }
                                    }
                                } else {
                                    if (features[71] /* Feature_HR_Std_60s_max */ <= 6.90999f) {
                                        if (features[69] /* Feature_Rate_Pressure_Product_max */ <= 2.70690f) {
                                            if (features[39] /* ART_SBP_min */ <= -0.41710f) {
                                                return false; /* p_pos=0.438, tau=0.45 */
                                            } else {
                                                if (features[55] /* Feature_MBP_Std_60s_min */ <= 0.52616f) {
                                                    return true; /* p_pos=0.706, tau=0.45 */
                                                } else {
                                                    return true; /* p_pos=1.000, tau=0.45 */
                                                }
                                            }
                                        } else {
                                            if (features[25] /* ETCO2_std */ <= 1.75733f) {
                                                if (features[10] /* Feature_Shock_Index_mean */ <= -0.24875f) {
                                                    return false; /* p_pos=0.000, tau=0.45 */
                                                } else {
                                                    return true; /* p_pos=0.963, tau=0.45 */
                                                }
                                            } else {
                                                return false; /* p_pos=0.300, tau=0.45 */
                                            }
                                        }
                                    } else {
                                        return false; /* p_pos=0.433, tau=0.45 */
                                    }
                                }
                            } else {
                                if (features[78] /* ART_DBP_slope */ <= 0.89052f) {
                                    if (features[79] /* ART_MBP_slope */ <= -0.13927f) {
                                        return true; /* p_pos=1.000, tau=0.45 */
                                    } else {
                                        if (features[32] /* Feature_HR_Mean_60s_std */ <= 8.10010f) {
                                            if (features[0] /* HR_mean */ <= 1.22931f) {
                                                return true; /* p_pos=0.708, tau=0.45 */
                                            } else {
                                                if (features[58] /* ART_SBP_max */ <= 0.31678f) {
                                                    return true; /* p_pos=0.852, tau=0.45 */
                                                } else {
                                                    return true; /* p_pos=1.000, tau=0.45 */
                                                }
                                            }
                                        } else {
                                            return true; /* p_pos=0.500, tau=0.45 */
                                        }
                                    }
                                } else {
                                    if (features[35] /* Feature_MBP_Mean_60s_std */ <= -0.06120f) {
                                        return false; /* p_pos=0.167, tau=0.45 */
                                    } else {
                                        if (features[13] /* Feature_HR_Mean_60s_mean */ <= 1.03501f) {
                                            return false; /* p_pos=0.200, tau=0.45 */
                                        } else {
                                            if (features[65] /* BT_max */ <= 0.04311f) {
                                                return true; /* p_pos=0.500, tau=0.45 */
                                            } else {
                                                return true; /* p_pos=0.936, tau=0.45 */
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    } else {
                        if (features[0] /* HR_mean */ <= 1.87504f) {
                            if (features[57] /* HR_max */ <= 1.25357f) {
                                return false; /* p_pos=0.000, tau=0.45 */
                            } else {
                                if (features[9] /* Feature_Pulse_Pressure_mean */ <= -1.20791f) {
                                    if (features[32] /* Feature_HR_Mean_60s_std */ <= 1.04321f) {
                                        return false; /* p_pos=0.107, tau=0.45 */
                                    } else {
                                        if (features[39] /* ART_SBP_min */ <= -1.27436f) {
                                            return false; /* p_pos=0.235, tau=0.45 */
                                        } else {
                                            return true; /* p_pos=0.806, tau=0.45 */
                                        }
                                    }
                                } else {
                                    if (features[27] /* BT_std */ <= -0.19738f) {
                                        if (features[47] /* Feature_Pulse_Pressure_min */ <= -0.12089f) {
                                            if (features[23] /* PLETH_SPO2_std */ <= 3.59471f) {
                                                if (features[68] /* Feature_Modified_Shock_Index_max */ <= 0.78219f) {
                                                    return true; /* p_pos=0.615, tau=0.45 */
                                                } else {
                                                    return true; /* p_pos=0.901, tau=0.45 */
                                                }
                                            } else {
                                                if (features[77] /* ART_SBP_slope */ <= 0.17946f) {
                                                    return true; /* p_pos=0.895, tau=0.45 */
                                                } else {
                                                    return false; /* p_pos=0.312, tau=0.45 */
                                                }
                                            }
                                        } else {
                                            if (features[14] /* Feature_HR_Std_60s_mean */ <= 3.23721f) {
                                                return false; /* p_pos=0.304, tau=0.45 */
                                            } else {
                                                if (features[79] /* ART_MBP_slope */ <= -0.40225f) {
                                                    return false; /* p_pos=0.412, tau=0.45 */
                                                } else {
                                                    return true; /* p_pos=0.810, tau=0.45 */
                                                }
                                            }
                                        }
                                    } else {
                                        if (features[7] /* FIO2_mean */ <= -0.06326f) {
                                            if (features[39] /* ART_SBP_min */ <= -0.14277f) {
                                                if (features[10] /* Feature_Shock_Index_mean */ <= 1.01686f) {
                                                    return true; /* p_pos=0.800, tau=0.45 */
                                                } else {
                                                    return true; /* p_pos=0.981, tau=0.45 */
                                                }
                                            } else {
                                                return false; /* p_pos=0.000, tau=0.45 */
                                            }
                                        } else {
                                            if (features[73] /* Feature_MBP_Mean_60s_max */ <= 0.40846f) {
                                                if (features[60] /* ART_MBP_max */ <= -0.69778f) {
                                                    return true; /* p_pos=0.857, tau=0.45 */
                                                } else {
                                                    return false; /* p_pos=0.312, tau=0.45 */
                                                }
                                            } else {
                                                return true; /* p_pos=0.842, tau=0.45 */
                                            }
                                        }
                                    }
                                }
                            }
                        } else {
                            if (features[70] /* Feature_HR_Mean_60s_max */ <= 7.84676f) {
                                if (features[63] /* ETCO2_max */ <= 2.14361f) {
                                    if (features[41] /* ART_MBP_min */ <= -2.00505f) {
                                        return true; /* p_pos=0.571, tau=0.45 */
                                    } else {
                                        if (features[63] /* ETCO2_max */ <= -2.00911f) {
                                            return true; /* p_pos=0.562, tau=0.45 */
                                        } else {
                                            if (features[13] /* Feature_HR_Mean_60s_mean */ <= 2.59895f) {
                                                if (features[11] /* Feature_Modified_Shock_Index_mean */ <= 2.29461f) {
                                                    return true; /* p_pos=0.938, tau=0.45 */
                                                } else {
                                                    return false; /* p_pos=0.417, tau=0.45 */
                                                }
                                            } else {
                                                if (features[40] /* ART_DBP_min */ <= 1.09561f) {
                                                    return true; /* p_pos=0.988, tau=0.45 */
                                                } else {
                                                    return true; /* p_pos=0.571, tau=0.45 */
                                                }
                                            }
                                        }
                                    }
                                } else {
                                    return true; /* p_pos=0.684, tau=0.45 */
                                }
                            } else {
                                return false; /* p_pos=0.000, tau=0.45 */
                            }
                        }
                    }
                }
            }
        }
    }
}

