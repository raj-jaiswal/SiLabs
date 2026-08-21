// Direct C Decision Tree for Future Hypoxia (95 Features, W=600s, STRIDE=5s)
#include <stdbool.h>

static inline bool predict_hypoxia_95(const float* features) {
    if (features[83] /* FIO2_slope */ <= 1.19125f) {
        if (features[42] /* PLETH_SPO2_min */ <= -1.48216f) {
            if (features[80] /* PLETH_SPO2_slope */ <= -2.96353f) {
                if (features[80] /* PLETH_SPO2_slope */ <= -5.64026f) {
                    if (features[70] /* Feature_HR_Mean_60s_max */ <= 0.62229f) {
                        if (features[88] /* Feature_Rate_Pressure_Product_slope */ <= -0.70749f) {
                            if (features[51] /* Feature_HR_Mean_60s_min */ <= -1.91785f) {
                                return false; /* p_pos=0.000, tau=0.33 */
                            } else {
                                if (features[67] /* Feature_Shock_Index_max */ <= 2.72305f) {
                                    if (features[90] /* Feature_HR_Std_60s_slope */ <= 0.23445f) {
                                        return true; /* p_pos=1.000, tau=0.33 */
                                    } else {
                                        return true; /* p_pos=0.667, tau=0.33 */
                                    }
                                } else {
                                    return false; /* p_pos=0.200, tau=0.33 */
                                }
                            }
                        } else {
                            if (features[94] /* Feature_MBP_Delta_60s_slope */ <= 0.44375f) {
                                if (features[13] /* Feature_HR_Mean_60s_mean */ <= -0.86766f) {
                                    if (features[86] /* Feature_Shock_Index_slope */ <= 0.11969f) {
                                        if (features[64] /* FIO2_max */ <= 1.05833f) {
                                            return true; /* p_pos=0.667, tau=0.33 */
                                        } else {
                                            return true; /* p_pos=1.000, tau=0.33 */
                                        }
                                    } else {
                                        return true; /* p_pos=1.000, tau=0.33 */
                                    }
                                } else {
                                    return true; /* p_pos=1.000, tau=0.33 */
                                }
                            } else {
                                if (features[66] /* Feature_Pulse_Pressure_max */ <= 0.42941f) {
                                    return true; /* p_pos=1.000, tau=0.33 */
                                } else {
                                    return true; /* p_pos=0.643, tau=0.33 */
                                }
                            }
                        }
                    } else {
                        if (features[38] /* HR_min */ <= 3.29410f) {
                            return true; /* p_pos=1.000, tau=0.33 */
                        } else {
                            return true; /* p_pos=0.958, tau=0.33 */
                        }
                    }
                } else {
                    if (features[42] /* PLETH_SPO2_min */ <= -2.52197f) {
                        if (features[61] /* PLETH_SPO2_max */ <= -1.88715f) {
                            if (features[26] /* FIO2_std */ <= -0.13054f) {
                                return true; /* p_pos=1.000, tau=0.33 */
                            } else {
                                return true; /* p_pos=0.889, tau=0.33 */
                            }
                        } else {
                            if (features[65] /* BT_max */ <= 0.20778f) {
                                if (features[23] /* PLETH_SPO2_std */ <= 5.31440f) {
                                    if (features[28] /* Feature_Pulse_Pressure_std */ <= -0.67814f) {
                                        return true; /* p_pos=0.375, tau=0.33 */
                                    } else {
                                        if (features[53] /* Feature_HR_Delta_60s_min */ <= 0.24224f) {
                                            if (features[94] /* Feature_MBP_Delta_60s_slope */ <= -0.81662f) {
                                                return false; /* p_pos=0.000, tau=0.33 */
                                            } else {
                                                if (features[21] /* ART_DBP_std */ <= -0.20356f) {
                                                    return true; /* p_pos=0.478, tau=0.33 */
                                                } else {
                                                    if (features[89] /* Feature_HR_Mean_60s_slope */ <= -0.02791f) {
                                                        if (features[60] /* ART_MBP_max */ <= -0.08080f) {
                                                            return true; /* p_pos=1.000, tau=0.33 */
                                                        } else {
                                                            return true; /* p_pos=0.417, tau=0.33 */
                                                        }
                                                    } else {
                                                        return true; /* p_pos=1.000, tau=0.33 */
                                                    }
                                                }
                                            }
                                        } else {
                                            if (features[4] /* PLETH_SPO2_mean */ <= -0.71507f) {
                                                if (features[37] /* Feature_MBP_Delta_60s_std */ <= -0.55031f) {
                                                    return true; /* p_pos=0.800, tau=0.33 */
                                                } else {
                                                    return true; /* p_pos=1.000, tau=0.33 */
                                                }
                                            } else {
                                                return true; /* p_pos=0.762, tau=0.33 */
                                            }
                                        }
                                    }
                                } else {
                                    if (features[56] /* Feature_MBP_Delta_60s_min */ <= -2.02457f) {
                                        return true; /* p_pos=0.800, tau=0.33 */
                                    } else {
                                        return true; /* p_pos=1.000, tau=0.33 */
                                    }
                                }
                            } else {
                                if (features[8] /* BT_mean */ <= 0.36186f) {
                                    if (features[60] /* ART_MBP_max */ <= 2.42288f) {
                                        if (features[32] /* Feature_HR_Mean_60s_std */ <= -0.72518f) {
                                            return true; /* p_pos=1.000, tau=0.33 */
                                        } else {
                                            if (features[93] /* Feature_MBP_Std_60s_slope */ <= 0.10125f) {
                                                if (features[26] /* FIO2_std */ <= 0.45059f) {
                                                    if (features[30] /* Feature_Modified_Shock_Index_std */ <= 0.15279f) {
                                                        if (features[15] /* Feature_HR_Delta_60s_mean */ <= -0.05354f) {
                                                            return true; /* p_pos=0.588, tau=0.33 */
                                                        } else {
                                                            return false; /* p_pos=0.111, tau=0.33 */
                                                        }
                                                    } else {
                                                        return true; /* p_pos=0.739, tau=0.33 */
                                                    }
                                                } else {
                                                    return false; /* p_pos=0.077, tau=0.33 */
                                                }
                                            } else {
                                                if (features[23] /* PLETH_SPO2_std */ <= 3.40512f) {
                                                    return true; /* p_pos=0.533, tau=0.33 */
                                                } else {
                                                    return true; /* p_pos=1.000, tau=0.33 */
                                                }
                                            }
                                        }
                                    } else {
                                        return false; /* p_pos=0.000, tau=0.33 */
                                    }
                                } else {
                                    if (features[62] /* RR_CO2_max */ <= -0.13284f) {
                                        return true; /* p_pos=0.625, tau=0.33 */
                                    } else {
                                        if (features[81] /* RR_CO2_slope */ <= -0.50672f) {
                                            return true; /* p_pos=0.600, tau=0.33 */
                                        } else {
                                            return true; /* p_pos=1.000, tau=0.33 */
                                        }
                                    }
                                }
                            }
                        }
                    } else {
                        if (features[63] /* ETCO2_max */ <= 2.73686f) {
                            if (features[42] /* PLETH_SPO2_min */ <= -1.74211f) {
                                if (features[59] /* ART_DBP_max */ <= 0.55547f) {
                                    if (features[65] /* BT_max */ <= 0.24072f) {
                                        if (features[23] /* PLETH_SPO2_std */ <= 3.56312f) {
                                            if (features[34] /* Feature_HR_Delta_60s_std */ <= -0.72463f) {
                                                return false; /* p_pos=0.083, tau=0.33 */
                                            } else {
                                                if (features[81] /* RR_CO2_slope */ <= -1.12344f) {
                                                    return true; /* p_pos=1.000, tau=0.33 */
                                                } else {
                                                    if (features[12] /* Feature_Rate_Pressure_Product_mean */ <= 0.13752f) {
                                                        if (features[25] /* ETCO2_std */ <= -0.39603f) {
                                                            return true; /* p_pos=0.357, tau=0.33 */
                                                        } else {
                                                            if (features[65] /* BT_max */ <= 0.10074f) {
                                                                return true; /* p_pos=1.000, tau=0.33 */
                                                            } else {
                                                                if (features[56] /* Feature_MBP_Delta_60s_min */ <= 0.35599f) {
                                                                    return true; /* p_pos=0.417, tau=0.33 */
                                                                } else {
                                                                    return true; /* p_pos=0.889, tau=0.33 */
                                                                }
                                                            }
                                                        }
                                                    } else {
                                                        if (features[59] /* ART_DBP_max */ <= -0.37912f) {
                                                            return true; /* p_pos=1.000, tau=0.33 */
                                                        } else {
                                                            if (features[90] /* Feature_HR_Std_60s_slope */ <= -0.02551f) {
                                                                return true; /* p_pos=0.562, tau=0.33 */
                                                            } else {
                                                                return false; /* p_pos=0.095, tau=0.33 */
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        } else {
                                            return false; /* p_pos=0.000, tau=0.33 */
                                        }
                                    } else {
                                        if (features[26] /* FIO2_std */ <= -0.33649f) {
                                            if (features[89] /* Feature_HR_Mean_60s_slope */ <= 0.15192f) {
                                                if (features[6] /* ETCO2_mean */ <= 0.45806f) {
                                                    if (features[42] /* PLETH_SPO2_min */ <= -2.26202f) {
                                                        return true; /* p_pos=0.727, tau=0.33 */
                                                    } else {
                                                        return false; /* p_pos=0.188, tau=0.33 */
                                                    }
                                                } else {
                                                    return false; /* p_pos=0.000, tau=0.33 */
                                                }
                                            } else {
                                                if (features[9] /* Feature_Pulse_Pressure_mean */ <= 0.10665f) {
                                                    return true; /* p_pos=1.000, tau=0.33 */
                                                } else {
                                                    return true; /* p_pos=0.400, tau=0.33 */
                                                }
                                            }
                                        } else {
                                            if (features[83] /* FIO2_slope */ <= -0.18500f) {
                                                return true; /* p_pos=0.471, tau=0.33 */
                                            } else {
                                                if (features[24] /* RR_CO2_std */ <= -0.13846f) {
                                                    return false; /* p_pos=0.273, tau=0.33 */
                                                } else {
                                                    return false; /* p_pos=0.000, tau=0.33 */
                                                }
                                            }
                                        }
                                    }
                                } else {
                                    if (features[30] /* Feature_Modified_Shock_Index_std */ <= 0.35445f) {
                                        if (features[91] /* Feature_HR_Delta_60s_slope */ <= 1.51415f) {
                                            if (features[63] /* ETCO2_max */ <= 1.74812f) {
                                                return true; /* p_pos=1.000, tau=0.33 */
                                            } else {
                                                return true; /* p_pos=0.500, tau=0.33 */
                                            }
                                        } else {
                                            return true; /* p_pos=0.444, tau=0.33 */
                                        }
                                    } else {
                                        return true; /* p_pos=0.357, tau=0.33 */
                                    }
                                }
                            } else {
                                if (features[88] /* Feature_Rate_Pressure_Product_slope */ <= -0.26002f) {
                                    if (features[87] /* Feature_Modified_Shock_Index_slope */ <= 1.26129f) {
                                        if (features[26] /* FIO2_std */ <= 0.43332f) {
                                            return false; /* p_pos=0.000, tau=0.33 */
                                        } else {
                                            return false; /* p_pos=0.154, tau=0.33 */
                                        }
                                    } else {
                                        return true; /* p_pos=0.444, tau=0.33 */
                                    }
                                } else {
                                    if (features[23] /* PLETH_SPO2_std */ <= 2.24458f) {
                                        if (features[91] /* Feature_HR_Delta_60s_slope */ <= 0.43439f) {
                                            if (features[93] /* Feature_MBP_Std_60s_slope */ <= 0.17709f) {
                                                if (features[86] /* Feature_Shock_Index_slope */ <= -0.13552f) {
                                                    return false; /* p_pos=0.000, tau=0.33 */
                                                } else {
                                                    if (features[13] /* Feature_HR_Mean_60s_mean */ <= -1.16981f) {
                                                        return false; /* p_pos=0.000, tau=0.33 */
                                                    } else {
                                                        return true; /* p_pos=0.429, tau=0.33 */
                                                    }
                                                }
                                            } else {
                                                return true; /* p_pos=0.727, tau=0.33 */
                                            }
                                        } else {
                                            return true; /* p_pos=0.739, tau=0.33 */
                                        }
                                    } else {
                                        if (features[12] /* Feature_Rate_Pressure_Product_mean */ <= -0.61554f) {
                                            return true; /* p_pos=0.400, tau=0.33 */
                                        } else {
                                            return false; /* p_pos=0.000, tau=0.33 */
                                        }
                                    }
                                }
                            }
                        } else {
                            if (features[46] /* BT_min */ <= 0.39527f) {
                                if (features[58] /* ART_SBP_max */ <= 1.08926f) {
                                    return true; /* p_pos=1.000, tau=0.33 */
                                } else {
                                    return true; /* p_pos=0.800, tau=0.33 */
                                }
                            } else {
                                return true; /* p_pos=0.400, tau=0.33 */
                            }
                        }
                    }
                }
            } else {
                if (features[4] /* PLETH_SPO2_mean */ <= -5.22352f) {
                    if (features[26] /* FIO2_std */ <= -0.27839f) {
                        if (features[61] /* PLETH_SPO2_max */ <= -3.29614f) {
                            if (features[42] /* PLETH_SPO2_min */ <= -2.00207f) {
                                if (features[46] /* BT_min */ <= -0.31018f) {
                                    if (features[33] /* Feature_HR_Std_60s_std */ <= 4.99271f) {
                                        return true; /* p_pos=1.000, tau=0.33 */
                                    } else {
                                        return true; /* p_pos=0.800, tau=0.33 */
                                    }
                                } else {
                                    if (features[0] /* HR_mean */ <= 1.40650f) {
                                        if (features[6] /* ETCO2_mean */ <= -4.24611f) {
                                            return true; /* p_pos=1.000, tau=0.33 */
                                        } else {
                                            if (features[75] /* Feature_MBP_Delta_60s_max */ <= -0.60396f) {
                                                return false; /* p_pos=0.000, tau=0.33 */
                                            } else {
                                                if (features[61] /* PLETH_SPO2_max */ <= -8.93212f) {
                                                    if (features[63] /* ETCO2_max */ <= 0.56162f) {
                                                        if (features[14] /* Feature_HR_Std_60s_mean */ <= -0.51280f) {
                                                            return true; /* p_pos=0.800, tau=0.33 */
                                                        } else {
                                                            return true; /* p_pos=1.000, tau=0.33 */
                                                        }
                                                    } else {
                                                        return true; /* p_pos=0.500, tau=0.33 */
                                                    }
                                                } else {
                                                    if (features[59] /* ART_DBP_max */ <= -0.81525f) {
                                                        return false; /* p_pos=0.000, tau=0.33 */
                                                    } else {
                                                        if (features[41] /* ART_MBP_min */ <= -0.41688f) {
                                                            return true; /* p_pos=0.909, tau=0.33 */
                                                        } else {
                                                            if (features[20] /* ART_SBP_std */ <= -0.21009f) {
                                                                return true; /* p_pos=0.737, tau=0.33 */
                                                            } else {
                                                                return false; /* p_pos=0.067, tau=0.33 */
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    } else {
                                        if (features[24] /* RR_CO2_std */ <= 1.05873f) {
                                            if (features[30] /* Feature_Modified_Shock_Index_std */ <= -0.04005f) {
                                                if (features[4] /* PLETH_SPO2_mean */ <= -6.18360f) {
                                                    return true; /* p_pos=1.000, tau=0.33 */
                                                } else {
                                                    return true; /* p_pos=0.600, tau=0.33 */
                                                }
                                            } else {
                                                return true; /* p_pos=1.000, tau=0.33 */
                                            }
                                        } else {
                                            return true; /* p_pos=0.571, tau=0.33 */
                                        }
                                    }
                                }
                            } else {
                                if (features[21] /* ART_DBP_std */ <= -0.97792f) {
                                    return true; /* p_pos=0.800, tau=0.33 */
                                } else {
                                    return false; /* p_pos=0.000, tau=0.33 */
                                }
                            }
                        } else {
                            if (features[5] /* RR_CO2_mean */ <= -1.71174f) {
                                if (features[4] /* PLETH_SPO2_mean */ <= -17.63090f) {
                                    return false; /* p_pos=0.200, tau=0.33 */
                                } else {
                                    return false; /* p_pos=0.000, tau=0.33 */
                                }
                            } else {
                                if (features[44] /* ETCO2_min */ <= -2.36488f) {
                                    if (features[3] /* ART_MBP_mean */ <= -0.94843f) {
                                        return true; /* p_pos=0.800, tau=0.33 */
                                    } else {
                                        return true; /* p_pos=1.000, tau=0.33 */
                                    }
                                } else {
                                    if (features[43] /* RR_CO2_min */ <= 1.23712f) {
                                        if (features[50] /* Feature_Rate_Pressure_Product_min */ <= 0.72071f) {
                                            if (features[5] /* RR_CO2_mean */ <= 0.02201f) {
                                                if (features[28] /* Feature_Pulse_Pressure_std */ <= 0.39555f) {
                                                    if (features[34] /* Feature_HR_Delta_60s_std */ <= -0.32070f) {
                                                        if (features[69] /* Feature_Rate_Pressure_Product_max */ <= -0.88319f) {
                                                            return true; /* p_pos=1.000, tau=0.33 */
                                                        } else {
                                                            if (features[9] /* Feature_Pulse_Pressure_mean */ <= -1.41894f) {
                                                                return true; /* p_pos=0.824, tau=0.33 */
                                                            } else {
                                                                if (features[86] /* Feature_Shock_Index_slope */ <= 0.32737f) {
                                                                    return false; /* p_pos=0.000, tau=0.33 */
                                                                } else {
                                                                    return true; /* p_pos=0.357, tau=0.33 */
                                                                }
                                                            }
                                                        }
                                                    } else {
                                                        if (features[6] /* ETCO2_mean */ <= 0.19858f) {
                                                            return false; /* p_pos=0.000, tau=0.33 */
                                                        } else {
                                                            return false; /* p_pos=0.286, tau=0.33 */
                                                        }
                                                    }
                                                } else {
                                                    return true; /* p_pos=0.870, tau=0.33 */
                                                }
                                            } else {
                                                if (features[25] /* ETCO2_std */ <= 1.10370f) {
                                                    return true; /* p_pos=1.000, tau=0.33 */
                                                } else {
                                                    return true; /* p_pos=0.500, tau=0.33 */
                                                }
                                            }
                                        } else {
                                            return false; /* p_pos=0.000, tau=0.33 */
                                        }
                                    } else {
                                        if (features[93] /* Feature_MBP_Std_60s_slope */ <= 3.49736f) {
                                            return true; /* p_pos=1.000, tau=0.33 */
                                        } else {
                                            return true; /* p_pos=0.600, tau=0.33 */
                                        }
                                    }
                                }
                            }
                        }
                    } else {
                        if (features[33] /* Feature_HR_Std_60s_std */ <= -0.64483f) {
                            if (features[43] /* RR_CO2_min */ <= -1.37754f) {
                                return false; /* p_pos=0.286, tau=0.33 */
                            } else {
                                if (features[89] /* Feature_HR_Mean_60s_slope */ <= -0.59439f) {
                                    return true; /* p_pos=0.778, tau=0.33 */
                                } else {
                                    return true; /* p_pos=1.000, tau=0.33 */
                                }
                            }
                        } else {
                            if (features[59] /* ART_DBP_max */ <= 2.36233f) {
                                if (features[80] /* PLETH_SPO2_slope */ <= -0.28680f) {
                                    if (features[27] /* BT_std */ <= -0.01243f) {
                                        if (features[1] /* ART_SBP_mean */ <= -0.66286f) {
                                            return true; /* p_pos=0.792, tau=0.33 */
                                        } else {
                                            if (features[7] /* FIO2_mean */ <= 2.05985f) {
                                                if (features[69] /* Feature_Rate_Pressure_Product_max */ <= -0.71211f) {
                                                    return true; /* p_pos=0.400, tau=0.33 */
                                                } else {
                                                    return false; /* p_pos=0.000, tau=0.33 */
                                                }
                                            } else {
                                                return true; /* p_pos=0.875, tau=0.33 */
                                            }
                                        }
                                    } else {
                                        return true; /* p_pos=1.000, tau=0.33 */
                                    }
                                } else {
                                    if (features[13] /* Feature_HR_Mean_60s_mean */ <= 1.78449f) {
                                        if (features[62] /* RR_CO2_max */ <= -0.63580f) {
                                            return false; /* p_pos=0.000, tau=0.33 */
                                        } else {
                                            if (features[80] /* PLETH_SPO2_slope */ <= 3.99597f) {
                                                if (features[41] /* ART_MBP_min */ <= -1.60801f) {
                                                    return true; /* p_pos=0.889, tau=0.33 */
                                                } else {
                                                    if (features[55] /* Feature_MBP_Std_60s_min */ <= -0.17377f) {
                                                        return true; /* p_pos=0.706, tau=0.33 */
                                                    } else {
                                                        if (features[54] /* Feature_MBP_Mean_60s_min */ <= -0.15320f) {
                                                            if (features[85] /* Feature_Pulse_Pressure_slope */ <= -0.20794f) {
                                                                return true; /* p_pos=0.600, tau=0.33 */
                                                            } else {
                                                                if (features[55] /* Feature_MBP_Std_60s_min */ <= -0.07204f) {
                                                                    return false; /* p_pos=0.000, tau=0.33 */
                                                                } else {
                                                                    return false; /* p_pos=0.278, tau=0.33 */
                                                                }
                                                            }
                                                        } else {
                                                            return false; /* p_pos=0.000, tau=0.33 */
                                                        }
                                                    }
                                                }
                                            } else {
                                                if (features[90] /* Feature_HR_Std_60s_slope */ <= 0.92141f) {
                                                    if (features[53] /* Feature_HR_Delta_60s_min */ <= 0.34554f) {
                                                        return false; /* p_pos=0.000, tau=0.33 */
                                                    } else {
                                                        return true; /* p_pos=0.400, tau=0.33 */
                                                    }
                                                } else {
                                                    return true; /* p_pos=0.429, tau=0.33 */
                                                }
                                            }
                                        }
                                    } else {
                                        if (features[27] /* BT_std */ <= -0.23200f) {
                                            if (features[4] /* PLETH_SPO2_mean */ <= -12.02277f) {
                                                return true; /* p_pos=0.682, tau=0.33 */
                                            } else {
                                                if (features[45] /* FIO2_min */ <= 2.50678f) {
                                                    return false; /* p_pos=0.000, tau=0.33 */
                                                } else {
                                                    return false; /* p_pos=0.200, tau=0.33 */
                                                }
                                            }
                                        } else {
                                            if (features[40] /* ART_DBP_min */ <= -0.00712f) {
                                                return true; /* p_pos=1.000, tau=0.33 */
                                            } else {
                                                return false; /* p_pos=0.000, tau=0.33 */
                                            }
                                        }
                                    }
                                }
                            } else {
                                if (features[40] /* ART_DBP_min */ <= -1.99203f) {
                                    return false; /* p_pos=0.200, tau=0.33 */
                                } else {
                                    return true; /* p_pos=1.000, tau=0.33 */
                                }
                            }
                        }
                    }
                } else {
                    if (features[80] /* PLETH_SPO2_slope */ <= -0.82215f) {
                        if (features[42] /* PLETH_SPO2_min */ <= -1.74211f) {
                            if (features[23] /* PLETH_SPO2_std */ <= 2.79956f) {
                                if (features[55] /* Feature_MBP_Std_60s_min */ <= 0.03936f) {
                                    if (features[7] /* FIO2_mean */ <= 2.14673f) {
                                        if (features[13] /* Feature_HR_Mean_60s_mean */ <= -2.06007f) {
                                            return true; /* p_pos=1.000, tau=0.33 */
                                        } else {
                                            if (features[49] /* Feature_Modified_Shock_Index_min */ <= -0.82026f) {
                                                if (features[62] /* RR_CO2_max */ <= -0.38432f) {
                                                    return false; /* p_pos=0.000, tau=0.33 */
                                                } else {
                                                    if (features[84] /* BT_slope */ <= 0.03784f) {
                                                        if (features[49] /* Feature_Modified_Shock_Index_min */ <= -1.19124f) {
                                                            return false; /* p_pos=0.263, tau=0.33 */
                                                        } else {
                                                            return false; /* p_pos=0.000, tau=0.33 */
                                                        }
                                                    } else {
                                                        return true; /* p_pos=1.000, tau=0.33 */
                                                    }
                                                }
                                            } else {
                                                if (features[41] /* ART_MBP_min */ <= -0.04319f) {
                                                    if (features[26] /* FIO2_std */ <= 0.07333f) {
                                                        if (features[48] /* Feature_Shock_Index_min */ <= 1.43313f) {
                                                            if (features[71] /* Feature_HR_Std_60s_max */ <= -0.68909f) {
                                                                return true; /* p_pos=1.000, tau=0.33 */
                                                            } else {
                                                                if (features[33] /* Feature_HR_Std_60s_std */ <= 1.00069f) {
                                                                    return true; /* p_pos=0.426, tau=0.33 */
                                                                } else {
                                                                    return true; /* p_pos=0.889, tau=0.33 */
                                                                }
                                                            }
                                                        } else {
                                                            if (features[4] /* PLETH_SPO2_mean */ <= -1.18627f) {
                                                                return false; /* p_pos=0.000, tau=0.33 */
                                                            } else {
                                                                return true; /* p_pos=0.400, tau=0.33 */
                                                            }
                                                        }
                                                    } else {
                                                        if (features[61] /* PLETH_SPO2_max */ <= -4.70514f) {
                                                            return true; /* p_pos=0.800, tau=0.33 */
                                                        } else {
                                                            if (features[4] /* PLETH_SPO2_mean */ <= -0.90038f) {
                                                                return false; /* p_pos=0.000, tau=0.33 */
                                                            } else {
                                                                if (features[7] /* FIO2_mean */ <= 0.93077f) {
                                                                    return true; /* p_pos=0.467, tau=0.33 */
                                                                } else {
                                                                    return false; /* p_pos=0.000, tau=0.33 */
                                                                }
                                                            }
                                                        }
                                                    }
                                                } else {
                                                    if (features[1] /* ART_SBP_mean */ <= 0.91790f) {
                                                        if (features[63] /* ETCO2_max */ <= 0.36387f) {
                                                            if (features[23] /* PLETH_SPO2_std */ <= 1.15004f) {
                                                                return false; /* p_pos=0.000, tau=0.33 */
                                                            } else {
                                                                if (features[62] /* RR_CO2_max */ <= 0.62160f) {
                                                                    return false; /* p_pos=0.162, tau=0.33 */
                                                                } else {
                                                                    return true; /* p_pos=0.667, tau=0.33 */
                                                                }
                                                            }
                                                        } else {
                                                            if (features[79] /* ART_MBP_slope */ <= -0.60454f) {
                                                                return true; /* p_pos=0.333, tau=0.33 */
                                                            } else {
                                                                return false; /* p_pos=0.000, tau=0.33 */
                                                            }
                                                        }
                                                    } else {
                                                        if (features[58] /* ART_SBP_max */ <= 0.31678f) {
                                                            return true; /* p_pos=1.000, tau=0.33 */
                                                        } else {
                                                            return false; /* p_pos=0.292, tau=0.33 */
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    } else {
                                        if (features[6] /* ETCO2_mean */ <= -1.10869f) {
                                            return true; /* p_pos=0.955, tau=0.33 */
                                        } else {
                                            if (features[10] /* Feature_Shock_Index_mean */ <= -0.28691f) {
                                                return true; /* p_pos=0.810, tau=0.33 */
                                            } else {
                                                if (features[13] /* Feature_HR_Mean_60s_mean */ <= 0.72390f) {
                                                    if (features[8] /* BT_mean */ <= 0.13126f) {
                                                        return true; /* p_pos=0.571, tau=0.33 */
                                                    } else {
                                                        if (features[15] /* Feature_HR_Delta_60s_mean */ <= 1.51829f) {
                                                            return false; /* p_pos=0.000, tau=0.33 */
                                                        } else {
                                                            return false; /* p_pos=0.286, tau=0.33 */
                                                        }
                                                    }
                                                } else {
                                                    if (features[41] /* ART_MBP_min */ <= 0.14365f) {
                                                        return true; /* p_pos=0.944, tau=0.33 */
                                                    } else {
                                                        return false; /* p_pos=0.222, tau=0.33 */
                                                    }
                                                }
                                            }
                                        }
                                    }
                                } else {
                                    if (features[3] /* ART_MBP_mean */ <= 1.19936f) {
                                        if (features[9] /* Feature_Pulse_Pressure_mean */ <= 1.21071f) {
                                            if (features[15] /* Feature_HR_Delta_60s_mean */ <= 0.24075f) {
                                                if (features[3] /* ART_MBP_mean */ <= 0.95897f) {
                                                    if (features[52] /* Feature_HR_Std_60s_min */ <= 4.63103f) {
                                                        if (features[38] /* HR_min */ <= -2.20182f) {
                                                            return true; /* p_pos=1.000, tau=0.33 */
                                                        } else {
                                                            if (features[48] /* Feature_Shock_Index_min */ <= -0.43655f) {
                                                                return false; /* p_pos=0.067, tau=0.33 */
                                                            } else {
                                                                if (features[13] /* Feature_HR_Mean_60s_mean */ <= -0.32978f) {
                                                                    return true; /* p_pos=0.857, tau=0.33 */
                                                                } else {
                                                                    return true; /* p_pos=0.485, tau=0.33 */
                                                                }
                                                            }
                                                        }
                                                    } else {
                                                        return true; /* p_pos=1.000, tau=0.33 */
                                                    }
                                                } else {
                                                    return false; /* p_pos=0.000, tau=0.33 */
                                                }
                                            } else {
                                                if (features[41] /* ART_MBP_min */ <= -0.41688f) {
                                                    if (features[65] /* BT_max */ <= 0.37246f) {
                                                        if (features[2] /* ART_DBP_mean */ <= -0.19019f) {
                                                            return true; /* p_pos=0.368, tau=0.33 */
                                                        } else {
                                                            return false; /* p_pos=0.000, tau=0.33 */
                                                        }
                                                    } else {
                                                        return false; /* p_pos=0.000, tau=0.33 */
                                                    }
                                                } else {
                                                    if (features[23] /* PLETH_SPO2_std */ <= 1.96868f) {
                                                        if (features[25] /* ETCO2_std */ <= 0.04506f) {
                                                            if (features[12] /* Feature_Rate_Pressure_Product_mean */ <= 0.94724f) {
                                                                if (features[47] /* Feature_Pulse_Pressure_min */ <= -0.42967f) {
                                                                    return false; /* p_pos=0.000, tau=0.33 */
                                                                } else {
                                                                    return true; /* p_pos=0.375, tau=0.33 */
                                                                }
                                                            } else {
                                                                return true; /* p_pos=0.875, tau=0.33 */
                                                            }
                                                        } else {
                                                            return false; /* p_pos=0.000, tau=0.33 */
                                                        }
                                                    } else {
                                                        if (features[73] /* Feature_MBP_Mean_60s_max */ <= -0.24659f) {
                                                            return true; /* p_pos=1.000, tau=0.33 */
                                                        } else {
                                                            return true; /* p_pos=0.500, tau=0.33 */
                                                        }
                                                    }
                                                }
                                            }
                                        } else {
                                            if (features[8] /* BT_mean */ <= 0.08630f) {
                                                return true; /* p_pos=0.600, tau=0.33 */
                                            } else {
                                                return false; /* p_pos=0.000, tau=0.33 */
                                            }
                                        }
                                    } else {
                                        if (features[50] /* Feature_Rate_Pressure_Product_min */ <= 0.22139f) {
                                            return false; /* p_pos=0.200, tau=0.33 */
                                        } else {
                                            return true; /* p_pos=1.000, tau=0.33 */
                                        }
                                    }
                                }
                            } else {
                                if (features[38] /* HR_min */ <= 0.64792f) {
                                    if (features[82] /* ETCO2_slope */ <= 0.46815f) {
                                        if (features[68] /* Feature_Modified_Shock_Index_max */ <= -0.28118f) {
                                            if (features[65] /* BT_max */ <= 0.17485f) {
                                                if (features[78] /* ART_DBP_slope */ <= -0.04953f) {
                                                    return true; /* p_pos=0.739, tau=0.33 */
                                                } else {
                                                    return true; /* p_pos=1.000, tau=0.33 */
                                                }
                                            } else {
                                                if (features[50] /* Feature_Rate_Pressure_Product_min */ <= 0.37327f) {
                                                    if (features[7] /* FIO2_mean */ <= -0.20781f) {
                                                        return true; /* p_pos=0.714, tau=0.33 */
                                                    } else {
                                                        if (features[89] /* Feature_HR_Mean_60s_slope */ <= 0.16181f) {
                                                            return false; /* p_pos=0.000, tau=0.33 */
                                                        } else {
                                                            return true; /* p_pos=0.333, tau=0.33 */
                                                        }
                                                    }
                                                } else {
                                                    return true; /* p_pos=1.000, tau=0.33 */
                                                }
                                            }
                                        } else {
                                            if (features[42] /* PLETH_SPO2_min */ <= -4.60160f) {
                                                if (features[48] /* Feature_Shock_Index_min */ <= -0.47445f) {
                                                    if (features[22] /* ART_MBP_std */ <= -0.06616f) {
                                                        return false; /* p_pos=0.000, tau=0.33 */
                                                    } else {
                                                        return true; /* p_pos=0.643, tau=0.33 */
                                                    }
                                                } else {
                                                    if (features[31] /* Feature_Rate_Pressure_Product_std */ <= 0.24284f) {
                                                        return true; /* p_pos=0.500, tau=0.33 */
                                                    } else {
                                                        if (features[33] /* Feature_HR_Std_60s_std */ <= 3.42603f) {
                                                            return true; /* p_pos=1.000, tau=0.33 */
                                                        } else {
                                                            return true; /* p_pos=0.800, tau=0.33 */
                                                        }
                                                    }
                                                }
                                            } else {
                                                if (features[18] /* Feature_MBP_Delta_60s_mean */ <= 0.06252f) {
                                                    if (features[75] /* Feature_MBP_Delta_60s_max */ <= -0.50472f) {
                                                        if (features[90] /* Feature_HR_Std_60s_slope */ <= -0.77886f) {
                                                            return true; /* p_pos=0.600, tau=0.33 */
                                                        } else {
                                                            return false; /* p_pos=0.000, tau=0.33 */
                                                        }
                                                    } else {
                                                        if (features[68] /* Feature_Modified_Shock_Index_max */ <= -0.11550f) {
                                                            return false; /* p_pos=0.000, tau=0.33 */
                                                        } else {
                                                            if (features[0] /* HR_mean */ <= -0.36337f) {
                                                                return true; /* p_pos=1.000, tau=0.33 */
                                                            } else {
                                                                if (features[40] /* ART_DBP_min */ <= 0.15829f) {
                                                                    return true; /* p_pos=0.583, tau=0.33 */
                                                                } else {
                                                                    return false; /* p_pos=0.000, tau=0.33 */
                                                                }
                                                            }
                                                        }
                                                    }
                                                } else {
                                                    return false; /* p_pos=0.000, tau=0.33 */
                                                }
                                            }
                                        }
                                    } else {
                                        if (features[26] /* FIO2_std */ <= -0.26483f) {
                                            if (features[78] /* ART_DBP_slope */ <= 0.96284f) {
                                                if (features[69] /* Feature_Rate_Pressure_Product_max */ <= 0.29320f) {
                                                    return true; /* p_pos=0.333, tau=0.33 */
                                                } else {
                                                    return true; /* p_pos=0.909, tau=0.33 */
                                                }
                                            } else {
                                                return false; /* p_pos=0.000, tau=0.33 */
                                            }
                                        } else {
                                            if (features[51] /* Feature_HR_Mean_60s_min */ <= 0.05926f) {
                                                if (features[54] /* Feature_MBP_Mean_60s_min */ <= -1.98637f) {
                                                    return false; /* p_pos=0.200, tau=0.33 */
                                                } else {
                                                    return false; /* p_pos=0.000, tau=0.33 */
                                                }
                                            } else {
                                                return false; /* p_pos=0.316, tau=0.33 */
                                            }
                                        }
                                    }
                                } else {
                                    if (features[45] /* FIO2_min */ <= -0.43993f) {
                                        if (features[58] /* ART_SBP_max */ <= -0.72088f) {
                                            return true; /* p_pos=1.000, tau=0.33 */
                                        } else {
                                            if (features[41] /* ART_MBP_min */ <= 0.00352f) {
                                                return true; /* p_pos=0.500, tau=0.33 */
                                            } else {
                                                return false; /* p_pos=0.059, tau=0.33 */
                                            }
                                        }
                                    } else {
                                        if (features[76] /* HR_slope */ <= 1.23411f) {
                                            if (features[44] /* ETCO2_min */ <= -0.35632f) {
                                                if (features[27] /* BT_std */ <= 2.69039f) {
                                                    return true; /* p_pos=1.000, tau=0.33 */
                                                } else {
                                                    return true; /* p_pos=0.800, tau=0.33 */
                                                }
                                            } else {
                                                if (features[57] /* HR_max */ <= 0.12947f) {
                                                    return true; /* p_pos=1.000, tau=0.33 */
                                                } else {
                                                    if (features[80] /* PLETH_SPO2_slope */ <= -1.35749f) {
                                                        if (features[76] /* HR_slope */ <= 0.03289f) {
                                                            return true; /* p_pos=0.643, tau=0.33 */
                                                        } else {
                                                            return true; /* p_pos=1.000, tau=0.33 */
                                                        }
                                                    } else {
                                                        return false; /* p_pos=0.308, tau=0.33 */
                                                    }
                                                }
                                            }
                                        } else {
                                            return false; /* p_pos=0.273, tau=0.33 */
                                        }
                                    }
                                }
                            }
                        } else {
                            if (features[5] /* RR_CO2_mean */ <= 1.33009f) {
                                if (features[59] /* ART_DBP_max */ <= 0.72162f) {
                                    if (features[51] /* Feature_HR_Mean_60s_min */ <= 1.72466f) {
                                        if (features[89] /* Feature_HR_Mean_60s_slope */ <= 0.30928f) {
                                            if (features[59] /* ART_DBP_max */ <= 0.22317f) {
                                                if (features[11] /* Feature_Modified_Shock_Index_mean */ <= -0.08826f) {
                                                    if (features[26] /* FIO2_std */ <= -0.34708f) {
                                                        if (features[33] /* Feature_HR_Std_60s_std */ <= 0.73154f) {
                                                            return false; /* p_pos=0.000, tau=0.33 */
                                                        } else {
                                                            return true; /* p_pos=0.600, tau=0.33 */
                                                        }
                                                    } else {
                                                        if (features[14] /* Feature_HR_Std_60s_mean */ <= -0.51467f) {
                                                            return true; /* p_pos=1.000, tau=0.33 */
                                                        } else {
                                                            return false; /* p_pos=0.318, tau=0.33 */
                                                        }
                                                    }
                                                } else {
                                                    if (features[70] /* Feature_HR_Mean_60s_max */ <= 0.51649f) {
                                                        if (features[52] /* Feature_HR_Std_60s_min */ <= 1.53141f) {
                                                            return false; /* p_pos=0.000, tau=0.33 */
                                                        } else {
                                                            return true; /* p_pos=0.400, tau=0.33 */
                                                        }
                                                    } else {
                                                        if (features[24] /* RR_CO2_std */ <= -0.41642f) {
                                                            return true; /* p_pos=0.562, tau=0.33 */
                                                        } else {
                                                            if (features[47] /* Feature_Pulse_Pressure_min */ <= -1.32793f) {
                                                                return true; /* p_pos=0.400, tau=0.33 */
                                                            } else {
                                                                return false; /* p_pos=0.000, tau=0.33 */
                                                            }
                                                        }
                                                    }
                                                }
                                            } else {
                                                if (features[20] /* ART_SBP_std */ <= 1.23482f) {
                                                    return false; /* p_pos=0.000, tau=0.33 */
                                                } else {
                                                    return false; /* p_pos=0.200, tau=0.33 */
                                                }
                                            }
                                        } else {
                                            if (features[27] /* BT_std */ <= -0.09941f) {
                                                if (features[93] /* Feature_MBP_Std_60s_slope */ <= 0.12873f) {
                                                    return false; /* p_pos=0.000, tau=0.33 */
                                                } else {
                                                    if (features[86] /* Feature_Shock_Index_slope */ <= 0.78048f) {
                                                        return false; /* p_pos=0.000, tau=0.33 */
                                                    } else {
                                                        return false; /* p_pos=0.200, tau=0.33 */
                                                    }
                                                }
                                            } else {
                                                return true; /* p_pos=0.400, tau=0.33 */
                                            }
                                        }
                                    } else {
                                        if (features[6] /* ETCO2_mean */ <= -0.00199f) {
                                            return true; /* p_pos=0.929, tau=0.33 */
                                        } else {
                                            if (features[66] /* Feature_Pulse_Pressure_max */ <= -1.20338f) {
                                                return true; /* p_pos=0.600, tau=0.33 */
                                            } else {
                                                return false; /* p_pos=0.000, tau=0.33 */
                                            }
                                        }
                                    }
                                } else {
                                    if (features[13] /* Feature_HR_Mean_60s_mean */ <= 1.15838f) {
                                        if (features[69] /* Feature_Rate_Pressure_Product_max */ <= -0.05786f) {
                                            return false; /* p_pos=0.000, tau=0.33 */
                                        } else {
                                            if (features[62] /* RR_CO2_max */ <= -0.51006f) {
                                                return false; /* p_pos=0.182, tau=0.33 */
                                            } else {
                                                if (features[5] /* RR_CO2_mean */ <= -0.35344f) {
                                                    return true; /* p_pos=1.000, tau=0.33 */
                                                } else {
                                                    return true; /* p_pos=0.545, tau=0.33 */
                                                }
                                            }
                                        }
                                    } else {
                                        return false; /* p_pos=0.000, tau=0.33 */
                                    }
                                }
                            } else {
                                if (features[58] /* ART_SBP_max */ <= 0.16689f) {
                                    if (features[25] /* ETCO2_std */ <= 0.15780f) {
                                        if (features[89] /* Feature_HR_Mean_60s_slope */ <= 0.33985f) {
                                            return false; /* p_pos=0.000, tau=0.33 */
                                        } else {
                                            return false; /* p_pos=0.200, tau=0.33 */
                                        }
                                    } else {
                                        return true; /* p_pos=0.889, tau=0.33 */
                                    }
                                } else {
                                    if (features[58] /* ART_SBP_max */ <= 0.55890f) {
                                        return true; /* p_pos=1.000, tau=0.33 */
                                    } else {
                                        return true; /* p_pos=0.667, tau=0.33 */
                                    }
                                }
                            }
                        }
                    } else {
                        if (features[23] /* PLETH_SPO2_std */ <= 1.78737f) {
                            if (features[84] /* BT_slope */ <= -0.78312f) {
                                if (features[10] /* Feature_Shock_Index_mean */ <= -0.01037f) {
                                    if (features[0] /* HR_mean */ <= -0.32687f) {
                                        if (features[68] /* Feature_Modified_Shock_Index_max */ <= -0.48181f) {
                                            return true; /* p_pos=0.789, tau=0.33 */
                                        } else {
                                            return false; /* p_pos=0.133, tau=0.33 */
                                        }
                                    } else {
                                        if (features[50] /* Feature_Rate_Pressure_Product_min */ <= 1.28369f) {
                                            return true; /* p_pos=1.000, tau=0.33 */
                                        } else {
                                            return true; /* p_pos=0.667, tau=0.33 */
                                        }
                                    }
                                } else {
                                    if (features[62] /* RR_CO2_max */ <= 0.37012f) {
                                        if (features[2] /* ART_DBP_mean */ <= 0.61606f) {
                                            if (features[47] /* Feature_Pulse_Pressure_min */ <= -0.68230f) {
                                                return false; /* p_pos=0.200, tau=0.33 */
                                            } else {
                                                return false; /* p_pos=0.000, tau=0.33 */
                                            }
                                        } else {
                                            return true; /* p_pos=0.600, tau=0.33 */
                                        }
                                    } else {
                                        if (features[79] /* ART_MBP_slope */ <= -0.22019f) {
                                            return true; /* p_pos=1.000, tau=0.33 */
                                        } else {
                                            return false; /* p_pos=0.235, tau=0.33 */
                                        }
                                    }
                                }
                            } else {
                                if (features[1] /* ART_SBP_mean */ <= 1.18527f) {
                                    if (features[0] /* HR_mean */ <= 0.41395f) {
                                        if (features[15] /* Feature_HR_Delta_60s_mean */ <= 2.99569f) {
                                            if (features[53] /* Feature_HR_Delta_60s_min */ <= 0.60378f) {
                                                if (features[2] /* ART_DBP_mean */ <= -0.32988f) {
                                                    if (features[12] /* Feature_Rate_Pressure_Product_mean */ <= -0.74359f) {
                                                        if (features[29] /* Feature_Shock_Index_std */ <= 8.21792f) {
                                                            if (features[76] /* HR_slope */ <= 1.88092f) {
                                                                if (features[48] /* Feature_Shock_Index_min */ <= 6.78415f) {
                                                                    return false; /* p_pos=0.018, tau=0.33 */
                                                                } else {
                                                                    return true; /* p_pos=0.600, tau=0.33 */
                                                                }
                                                            } else {
                                                                return true; /* p_pos=0.455, tau=0.33 */
                                                            }
                                                        } else {
                                                            return true; /* p_pos=0.571, tau=0.33 */
                                                        }
                                                    } else {
                                                        if (features[52] /* Feature_HR_Std_60s_min */ <= 1.79201f) {
                                                            return false; /* p_pos=0.000, tau=0.33 */
                                                        } else {
                                                            if (features[52] /* Feature_HR_Std_60s_min */ <= 2.46140f) {
                                                                return true; /* p_pos=0.400, tau=0.33 */
                                                            } else {
                                                                return false; /* p_pos=0.000, tau=0.33 */
                                                            }
                                                        }
                                                    }
                                                } else {
                                                    if (features[49] /* Feature_Modified_Shock_Index_min */ <= -1.35855f) {
                                                        return true; /* p_pos=1.000, tau=0.33 */
                                                    } else {
                                                        if (features[7] /* FIO2_mean */ <= 2.46630f) {
                                                            if (features[4] /* PLETH_SPO2_mean */ <= 0.29257f) {
                                                                if (features[63] /* ETCO2_max */ <= -0.82262f) {
                                                                    return false; /* p_pos=0.005, tau=0.33 */
                                                                } else {
                                                                    return false; /* p_pos=0.067, tau=0.33 */
                                                                }
                                                            } else {
                                                                if (features[8] /* BT_mean */ <= 0.33642f) {
                                                                    return false; /* p_pos=0.111, tau=0.33 */
                                                                } else {
                                                                    return true; /* p_pos=0.684, tau=0.33 */
                                                                }
                                                            }
                                                        } else {
                                                            if (features[59] /* ART_DBP_max */ <= -0.00528f) {
                                                                return false; /* p_pos=0.000, tau=0.33 */
                                                            } else {
                                                                return true; /* p_pos=0.789, tau=0.33 */
                                                            }
                                                        }
                                                    }
                                                }
                                            } else {
                                                if (features[27] /* BT_std */ <= -0.20410f) {
                                                    if (features[45] /* FIO2_min */ <= -0.49828f) {
                                                        if (features[5] /* RR_CO2_mean */ <= 2.86185f) {
                                                            if (features[1] /* ART_SBP_mean */ <= 0.92958f) {
                                                                if (features[70] /* Feature_HR_Mean_60s_max */ <= -0.90310f) {
                                                                    return false; /* p_pos=0.000, tau=0.33 */
                                                                } else {
                                                                    return false; /* p_pos=0.081, tau=0.33 */
                                                                }
                                                            } else {
                                                                return true; /* p_pos=0.500, tau=0.33 */
                                                            }
                                                        } else {
                                                            return true; /* p_pos=1.000, tau=0.33 */
                                                        }
                                                    } else {
                                                        if (features[6] /* ETCO2_mean */ <= 0.81559f) {
                                                            if (features[43] /* RR_CO2_min */ <= 1.62932f) {
                                                                if (features[55] /* Feature_MBP_Std_60s_min */ <= -0.23878f) {
                                                                    return false; /* p_pos=0.050, tau=0.33 */
                                                                } else {
                                                                    return false; /* p_pos=0.326, tau=0.33 */
                                                                }
                                                            } else {
                                                                return true; /* p_pos=1.000, tau=0.33 */
                                                            }
                                                        } else {
                                                            return false; /* p_pos=0.000, tau=0.33 */
                                                        }
                                                    }
                                                } else {
                                                    if (features[5] /* RR_CO2_mean */ <= -0.32548f) {
                                                        if (features[7] /* FIO2_mean */ <= -0.60007f) {
                                                            return false; /* p_pos=0.000, tau=0.33 */
                                                        } else {
                                                            if (features[28] /* Feature_Pulse_Pressure_std */ <= -0.21492f) {
                                                                return true; /* p_pos=0.429, tau=0.33 */
                                                            } else {
                                                                if (features[9] /* Feature_Pulse_Pressure_mean */ <= -0.73171f) {
                                                                    return false; /* p_pos=0.200, tau=0.33 */
                                                                } else {
                                                                    return false; /* p_pos=0.000, tau=0.33 */
                                                                }
                                                            }
                                                        }
                                                    } else {
                                                        return false; /* p_pos=0.000, tau=0.33 */
                                                    }
                                                }
                                            }
                                        } else {
                                            if (features[69] /* Feature_Rate_Pressure_Product_max */ <= 0.38829f) {
                                                return true; /* p_pos=1.000, tau=0.33 */
                                            } else {
                                                if (features[9] /* Feature_Pulse_Pressure_mean */ <= 0.16028f) {
                                                    return true; /* p_pos=0.471, tau=0.33 */
                                                } else {
                                                    return false; /* p_pos=0.000, tau=0.33 */
                                                }
                                            }
                                        }
                                    } else {
                                        if (features[65] /* BT_max */ <= 0.30659f) {
                                            if (features[3] /* ART_MBP_mean */ <= -0.30706f) {
                                                if (features[4] /* PLETH_SPO2_mean */ <= -1.54958f) {
                                                    if (features[24] /* RR_CO2_std */ <= -0.05630f) {
                                                        if (features[27] /* BT_std */ <= -0.06724f) {
                                                            if (features[68] /* Feature_Modified_Shock_Index_max */ <= 3.10545f) {
                                                                if (features[55] /* Feature_MBP_Std_60s_min */ <= 0.25283f) {
                                                                    return false; /* p_pos=0.221, tau=0.33 */
                                                                } else {
                                                                    return true; /* p_pos=0.667, tau=0.33 */
                                                                }
                                                            } else {
                                                                return true; /* p_pos=1.000, tau=0.33 */
                                                            }
                                                        } else {
                                                            return true; /* p_pos=1.000, tau=0.33 */
                                                        }
                                                    } else {
                                                        if (features[6] /* ETCO2_mean */ <= -1.63473f) {
                                                            return true; /* p_pos=0.667, tau=0.33 */
                                                        } else {
                                                            if (features[54] /* Feature_MBP_Mean_60s_min */ <= -0.29415f) {
                                                                return false; /* p_pos=0.000, tau=0.33 */
                                                            } else {
                                                                return false; /* p_pos=0.133, tau=0.33 */
                                                            }
                                                        }
                                                    }
                                                } else {
                                                    if (features[2] /* ART_DBP_mean */ <= -0.62830f) {
                                                        if (features[23] /* PLETH_SPO2_std */ <= 1.44003f) {
                                                            return false; /* p_pos=0.000, tau=0.33 */
                                                        } else {
                                                            if (features[63] /* ETCO2_max */ <= -0.22937f) {
                                                                return false; /* p_pos=0.000, tau=0.33 */
                                                            } else {
                                                                if (features[9] /* Feature_Pulse_Pressure_mean */ <= -1.00522f) {
                                                                    return true; /* p_pos=0.545, tau=0.33 */
                                                                } else {
                                                                    return false; /* p_pos=0.000, tau=0.33 */
                                                                }
                                                            }
                                                        }
                                                    } else {
                                                        if (features[51] /* Feature_HR_Mean_60s_min */ <= 0.84020f) {
                                                            if (features[9] /* Feature_Pulse_Pressure_mean */ <= -0.22254f) {
                                                                return false; /* p_pos=0.000, tau=0.33 */
                                                            } else {
                                                                return true; /* p_pos=0.333, tau=0.33 */
                                                            }
                                                        } else {
                                                            if (features[68] /* Feature_Modified_Shock_Index_max */ <= 0.40802f) {
                                                                return true; /* p_pos=0.833, tau=0.33 */
                                                            } else {
                                                                if (features[28] /* Feature_Pulse_Pressure_std */ <= 0.52949f) {
                                                                    return false; /* p_pos=0.110, tau=0.33 */
                                                                } else {
                                                                    return true; /* p_pos=0.636, tau=0.33 */
                                                                }
                                                            }
                                                        }
                                                    }
                                                }
                                            } else {
                                                if (features[7] /* FIO2_mean */ <= -0.71741f) {
                                                    return false; /* p_pos=0.000, tau=0.33 */
                                                } else {
                                                    if (features[65] /* BT_max */ <= 0.07604f) {
                                                        if (features[64] /* FIO2_max */ <= -0.52132f) {
                                                            if (features[49] /* Feature_Modified_Shock_Index_min */ <= -0.45758f) {
                                                                return true; /* p_pos=1.000, tau=0.33 */
                                                            } else {
                                                                return false; /* p_pos=0.000, tau=0.33 */
                                                            }
                                                        } else {
                                                            if (features[32] /* Feature_HR_Mean_60s_std */ <= -0.62831f) {
                                                                return true; /* p_pos=0.500, tau=0.33 */
                                                            } else {
                                                                if (features[78] /* ART_DBP_slope */ <= -1.31499f) {
                                                                    return true; /* p_pos=0.600, tau=0.33 */
                                                                } else {
                                                                    return false; /* p_pos=0.039, tau=0.33 */
                                                                }
                                                            }
                                                        }
                                                    } else {
                                                        if (features[24] /* RR_CO2_std */ <= 2.35421f) {
                                                            if (features[53] /* Feature_HR_Delta_60s_min */ <= -6.31725f) {
                                                                return true; /* p_pos=0.500, tau=0.33 */
                                                            } else {
                                                                if (features[38] /* HR_min */ <= 0.58007f) {
                                                                    return false; /* p_pos=0.005, tau=0.33 */
                                                                } else {
                                                                    return false; /* p_pos=0.060, tau=0.33 */
                                                                }
                                                            }
                                                        } else {
                                                            if (features[63] /* ETCO2_max */ <= 1.74812f) {
                                                                return false; /* p_pos=0.053, tau=0.33 */
                                                            } else {
                                                                return true; /* p_pos=0.778, tau=0.33 */
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        } else {
                                            if (features[70] /* Feature_HR_Mean_60s_max */ <= 3.15584f) {
                                                if (features[66] /* Feature_Pulse_Pressure_max */ <= 0.50165f) {
                                                    if (features[36] /* Feature_MBP_Std_60s_std */ <= -0.51295f) {
                                                        if (features[8] /* BT_mean */ <= 0.38863f) {
                                                            return false; /* p_pos=0.053, tau=0.33 */
                                                        } else {
                                                            if (features[39] /* ART_SBP_min */ <= -0.45139f) {
                                                                return true; /* p_pos=0.333, tau=0.33 */
                                                            } else {
                                                                return true; /* p_pos=1.000, tau=0.33 */
                                                            }
                                                        }
                                                    } else {
                                                        if (features[59] /* ART_DBP_max */ <= -0.39988f) {
                                                            return false; /* p_pos=0.000, tau=0.33 */
                                                        } else {
                                                            if (features[55] /* Feature_MBP_Std_60s_min */ <= 0.33837f) {
                                                                if (features[49] /* Feature_Modified_Shock_Index_min */ <= -0.65192f) {
                                                                    return false; /* p_pos=0.321, tau=0.33 */
                                                                } else {
                                                                    return false; /* p_pos=0.061, tau=0.33 */
                                                                }
                                                            } else {
                                                                return true; /* p_pos=0.529, tau=0.33 */
                                                            }
                                                        }
                                                    }
                                                } else {
                                                    if (features[28] /* Feature_Pulse_Pressure_std */ <= 1.37250f) {
                                                        if (features[15] /* Feature_HR_Delta_60s_mean */ <= -0.14968f) {
                                                            return false; /* p_pos=0.083, tau=0.33 */
                                                        } else {
                                                            if (features[42] /* PLETH_SPO2_min */ <= -2.26202f) {
                                                                return true; /* p_pos=0.364, tau=0.33 */
                                                            } else {
                                                                if (features[21] /* ART_DBP_std */ <= 1.98661f) {
                                                                    return true; /* p_pos=1.000, tau=0.33 */
                                                                } else {
                                                                    return true; /* p_pos=0.600, tau=0.33 */
                                                                }
                                                            }
                                                        }
                                                    } else {
                                                        if (features[64] /* FIO2_max */ <= 1.90377f) {
                                                            return false; /* p_pos=0.000, tau=0.33 */
                                                        } else {
                                                            return true; /* p_pos=1.000, tau=0.33 */
                                                        }
                                                    }
                                                }
                                            } else {
                                                if (features[44] /* ETCO2_min */ <= -0.08852f) {
                                                    if (features[23] /* PLETH_SPO2_std */ <= 0.59034f) {
                                                        return true; /* p_pos=1.000, tau=0.33 */
                                                    } else {
                                                        return false; /* p_pos=0.100, tau=0.33 */
                                                    }
                                                } else {
                                                    return true; /* p_pos=1.000, tau=0.33 */
                                                }
                                            }
                                        }
                                    }
                                } else {
                                    if (features[7] /* FIO2_mean */ <= 2.39759f) {
                                        if (features[3] /* ART_MBP_mean */ <= 0.91938f) {
                                            if (features[14] /* Feature_HR_Std_60s_mean */ <= 1.75017f) {
                                                if (features[33] /* Feature_HR_Std_60s_std */ <= -0.71005f) {
                                                    return false; /* p_pos=0.200, tau=0.33 */
                                                } else {
                                                    return false; /* p_pos=0.000, tau=0.33 */
                                                }
                                            } else {
                                                return true; /* p_pos=0.400, tau=0.33 */
                                            }
                                        } else {
                                            if (features[65] /* BT_max */ <= 0.27366f) {
                                                if (features[26] /* FIO2_std */ <= -0.30528f) {
                                                    if (features[93] /* Feature_MBP_Std_60s_slope */ <= 0.08886f) {
                                                        if (features[34] /* Feature_HR_Delta_60s_std */ <= -0.67341f) {
                                                            return true; /* p_pos=0.429, tau=0.33 */
                                                        } else {
                                                            return false; /* p_pos=0.000, tau=0.33 */
                                                        }
                                                    } else {
                                                        if (features[68] /* Feature_Modified_Shock_Index_max */ <= -0.75099f) {
                                                            return true; /* p_pos=1.000, tau=0.33 */
                                                        } else {
                                                            if (features[73] /* Feature_MBP_Mean_60s_max */ <= 0.64244f) {
                                                                return true; /* p_pos=0.600, tau=0.33 */
                                                            } else {
                                                                return false; /* p_pos=0.000, tau=0.33 */
                                                            }
                                                        }
                                                    }
                                                } else {
                                                    if (features[27] /* BT_std */ <= -0.19907f) {
                                                        if (features[39] /* ART_SBP_min */ <= 1.96610f) {
                                                            if (features[6] /* ETCO2_mean */ <= -0.21729f) {
                                                                return true; /* p_pos=0.417, tau=0.33 */
                                                            } else {
                                                                if (features[0] /* HR_mean */ <= 1.47785f) {
                                                                    return true; /* p_pos=1.000, tau=0.33 */
                                                                } else {
                                                                    return true; /* p_pos=0.800, tau=0.33 */
                                                                }
                                                            }
                                                        } else {
                                                            return false; /* p_pos=0.000, tau=0.33 */
                                                        }
                                                    } else {
                                                        return false; /* p_pos=0.000, tau=0.33 */
                                                    }
                                                }
                                            } else {
                                                if (features[2] /* ART_DBP_mean */ <= 0.67365f) {
                                                    return true; /* p_pos=0.533, tau=0.33 */
                                                } else {
                                                    return false; /* p_pos=0.000, tau=0.33 */
                                                }
                                            }
                                        }
                                    } else {
                                        if (features[76] /* HR_slope */ <= 0.21769f) {
                                            return true; /* p_pos=0.357, tau=0.33 */
                                        } else {
                                            if (features[29] /* Feature_Shock_Index_std */ <= 0.45673f) {
                                                return true; /* p_pos=1.000, tau=0.33 */
                                            } else {
                                                return true; /* p_pos=0.600, tau=0.33 */
                                            }
                                        }
                                    }
                                }
                            }
                        } else {
                            if (features[50] /* Feature_Rate_Pressure_Product_min */ <= -1.43073f) {
                                if (features[39] /* ART_SBP_min */ <= -0.86288f) {
                                    if (features[11] /* Feature_Modified_Shock_Index_mean */ <= 5.68594f) {
                                        if (features[45] /* FIO2_min */ <= 2.59431f) {
                                            if (features[64] /* FIO2_max */ <= 1.43655f) {
                                                if (features[51] /* Feature_HR_Mean_60s_min */ <= -0.03245f) {
                                                    if (features[91] /* Feature_HR_Delta_60s_slope */ <= 0.82703f) {
                                                        if (features[23] /* PLETH_SPO2_std */ <= 6.15913f) {
                                                            return false; /* p_pos=0.000, tau=0.33 */
                                                        } else {
                                                            return false; /* p_pos=0.100, tau=0.33 */
                                                        }
                                                    } else {
                                                        return false; /* p_pos=0.167, tau=0.33 */
                                                    }
                                                } else {
                                                    if (features[42] /* PLETH_SPO2_min */ <= -1.74211f) {
                                                        if (features[12] /* Feature_Rate_Pressure_Product_mean */ <= -1.98189f) {
                                                            if (features[45] /* FIO2_min */ <= -0.26487f) {
                                                                return false; /* p_pos=0.000, tau=0.33 */
                                                            } else {
                                                                return false; /* p_pos=0.158, tau=0.33 */
                                                            }
                                                        } else {
                                                            return true; /* p_pos=0.500, tau=0.33 */
                                                        }
                                                    } else {
                                                        return true; /* p_pos=1.000, tau=0.33 */
                                                    }
                                                }
                                            } else {
                                                if (features[91] /* Feature_HR_Delta_60s_slope */ <= 0.04176f) {
                                                    return false; /* p_pos=0.000, tau=0.33 */
                                                } else {
                                                    if (features[78] /* ART_DBP_slope */ <= -0.04953f) {
                                                        if (features[24] /* RR_CO2_std */ <= 2.45852f) {
                                                            if (features[65] /* BT_max */ <= -0.85439f) {
                                                                return false; /* p_pos=0.000, tau=0.33 */
                                                            } else {
                                                                if (features[64] /* FIO2_max */ <= 1.92602f) {
                                                                    return false; /* p_pos=0.312, tau=0.33 */
                                                                } else {
                                                                    return false; /* p_pos=0.000, tau=0.33 */
                                                                }
                                                            }
                                                        } else {
                                                            return false; /* p_pos=0.000, tau=0.33 */
                                                        }
                                                    } else {
                                                        return false; /* p_pos=0.000, tau=0.33 */
                                                    }
                                                }
                                            }
                                        } else {
                                            if (features[24] /* RR_CO2_std */ <= -0.04739f) {
                                                return false; /* p_pos=0.000, tau=0.33 */
                                            } else {
                                                if (features[79] /* ART_MBP_slope */ <= -0.44271f) {
                                                    return true; /* p_pos=0.875, tau=0.33 */
                                                } else {
                                                    if (features[76] /* HR_slope */ <= -0.24431f) {
                                                        return false; /* p_pos=0.000, tau=0.33 */
                                                    } else {
                                                        return false; /* p_pos=0.300, tau=0.33 */
                                                    }
                                                }
                                            }
                                        }
                                    } else {
                                        if (features[65] /* BT_max */ <= -1.00260f) {
                                            if (features[50] /* Feature_Rate_Pressure_Product_min */ <= -1.71098f) {
                                                return true; /* p_pos=0.882, tau=0.33 */
                                            } else {
                                                return false; /* p_pos=0.000, tau=0.33 */
                                            }
                                        } else {
                                            if (features[56] /* Feature_MBP_Delta_60s_min */ <= 1.76955f) {
                                                return false; /* p_pos=0.000, tau=0.33 */
                                            } else {
                                                return false; /* p_pos=0.200, tau=0.33 */
                                            }
                                        }
                                    }
                                } else {
                                    if (features[49] /* Feature_Modified_Shock_Index_min */ <= -1.16408f) {
                                        return false; /* p_pos=0.000, tau=0.33 */
                                    } else {
                                        return true; /* p_pos=0.826, tau=0.33 */
                                    }
                                }
                            } else {
                                if (features[13] /* Feature_HR_Mean_60s_mean */ <= 2.08659f) {
                                    if (features[84] /* BT_slope */ <= -1.53840f) {
                                        if (features[48] /* Feature_Shock_Index_min */ <= 1.76524f) {
                                            if (features[68] /* Feature_Modified_Shock_Index_max */ <= -0.42391f) {
                                                if (features[69] /* Feature_Rate_Pressure_Product_max */ <= 1.02461f) {
                                                    return true; /* p_pos=1.000, tau=0.33 */
                                                } else {
                                                    return true; /* p_pos=0.800, tau=0.33 */
                                                }
                                            } else {
                                                if (features[50] /* Feature_Rate_Pressure_Product_min */ <= -0.19097f) {
                                                    return false; /* p_pos=0.091, tau=0.33 */
                                                } else {
                                                    if (features[56] /* Feature_MBP_Delta_60s_min */ <= 0.30780f) {
                                                        if (features[7] /* FIO2_mean */ <= 0.51177f) {
                                                            return true; /* p_pos=1.000, tau=0.33 */
                                                        } else {
                                                            return true; /* p_pos=0.800, tau=0.33 */
                                                        }
                                                    } else {
                                                        if (features[47] /* Feature_Pulse_Pressure_min */ <= 0.83353f) {
                                                            return false; /* p_pos=0.235, tau=0.33 */
                                                        } else {
                                                            return true; /* p_pos=1.000, tau=0.33 */
                                                        }
                                                    }
                                                }
                                            }
                                        } else {
                                            return false; /* p_pos=0.000, tau=0.33 */
                                        }
                                    } else {
                                        if (features[20] /* ART_SBP_std */ <= -0.65355f) {
                                            if (features[66] /* Feature_Pulse_Pressure_max */ <= -1.52127f) {
                                                if (features[67] /* Feature_Shock_Index_max */ <= 0.60816f) {
                                                    if (features[27] /* BT_std */ <= -0.14957f) {
                                                        return true; /* p_pos=0.826, tau=0.33 */
                                                    } else {
                                                        return false; /* p_pos=0.000, tau=0.33 */
                                                    }
                                                } else {
                                                    return false; /* p_pos=0.000, tau=0.33 */
                                                }
                                            } else {
                                                if (features[4] /* PLETH_SPO2_mean */ <= -1.94093f) {
                                                    if (features[21] /* ART_DBP_std */ <= -0.46409f) {
                                                        if (features[31] /* Feature_Rate_Pressure_Product_std */ <= -1.05406f) {
                                                            return false; /* p_pos=0.000, tau=0.33 */
                                                        } else {
                                                            if (features[9] /* Feature_Pulse_Pressure_mean */ <= 0.18314f) {
                                                                if (features[23] /* PLETH_SPO2_std */ <= 6.97597f) {
                                                                    return true; /* p_pos=0.421, tau=0.33 */
                                                                } else {
                                                                    return false; /* p_pos=0.000, tau=0.33 */
                                                                }
                                                            } else {
                                                                return false; /* p_pos=0.000, tau=0.33 */
                                                            }
                                                        }
                                                    } else {
                                                        return true; /* p_pos=1.000, tau=0.33 */
                                                    }
                                                } else {
                                                    if (features[9] /* Feature_Pulse_Pressure_mean */ <= -0.54487f) {
                                                        return false; /* p_pos=0.000, tau=0.33 */
                                                    } else {
                                                        if (features[27] /* BT_std */ <= -0.19084f) {
                                                            if (features[17] /* Feature_MBP_Std_60s_mean */ <= -0.70667f) {
                                                                return true; /* p_pos=0.600, tau=0.33 */
                                                            } else {
                                                                if (features[47] /* Feature_Pulse_Pressure_min */ <= 0.55282f) {
                                                                    return false; /* p_pos=0.051, tau=0.33 */
                                                                } else {
                                                                    return false; /* p_pos=0.000, tau=0.33 */
                                                                }
                                                            }
                                                        } else {
                                                            return false; /* p_pos=0.304, tau=0.33 */
                                                        }
                                                    }
                                                }
                                            }
                                        } else {
                                            if (features[71] /* Feature_HR_Std_60s_max */ <= -0.84015f) {
                                                if (features[28] /* Feature_Pulse_Pressure_std */ <= 0.84976f) {
                                                    if (features[22] /* ART_MBP_std */ <= -0.61752f) {
                                                        return false; /* p_pos=0.000, tau=0.33 */
                                                    } else {
                                                        if (features[25] /* ETCO2_std */ <= -0.49052f) {
                                                            return true; /* p_pos=0.476, tau=0.33 */
                                                        } else {
                                                            if (features[18] /* Feature_MBP_Delta_60s_mean */ <= -0.19684f) {
                                                                return true; /* p_pos=0.533, tau=0.33 */
                                                            } else {
                                                                if (features[74] /* Feature_MBP_Std_60s_max */ <= -0.57823f) {
                                                                    return true; /* p_pos=0.800, tau=0.33 */
                                                                } else {
                                                                    return true; /* p_pos=1.000, tau=0.33 */
                                                                }
                                                            }
                                                        }
                                                    }
                                                } else {
                                                    if (features[66] /* Feature_Pulse_Pressure_max */ <= 0.66060f) {
                                                        return true; /* p_pos=1.000, tau=0.33 */
                                                    } else {
                                                        if (features[89] /* Feature_HR_Mean_60s_slope */ <= 0.10427f) {
                                                            return false; /* p_pos=0.000, tau=0.33 */
                                                        } else {
                                                            return true; /* p_pos=0.400, tau=0.33 */
                                                        }
                                                    }
                                                }
                                            } else {
                                                if (features[7] /* FIO2_mean */ <= 2.07618f) {
                                                    if (features[33] /* Feature_HR_Std_60s_std */ <= 0.00211f) {
                                                        if (features[12] /* Feature_Rate_Pressure_Product_mean */ <= -1.22062f) {
                                                            if (features[46] /* BT_min */ <= 0.31418f) {
                                                                if (features[16] /* Feature_MBP_Mean_60s_mean */ <= -0.74260f) {
                                                                    return true; /* p_pos=0.571, tau=0.33 */
                                                                } else {
                                                                    return true; /* p_pos=1.000, tau=0.33 */
                                                                }
                                                            } else {
                                                                return false; /* p_pos=0.000, tau=0.33 */
                                                            }
                                                        } else {
                                                            if (features[8] /* BT_mean */ <= 0.50928f) {
                                                                if (features[24] /* RR_CO2_std */ <= 0.66278f) {
                                                                    return false; /* p_pos=0.237, tau=0.33 */
                                                                } else {
                                                                    return false; /* p_pos=0.079, tau=0.33 */
                                                                }
                                                            } else {
                                                                if (features[9] /* Feature_Pulse_Pressure_mean */ <= -0.81157f) {
                                                                    return true; /* p_pos=0.957, tau=0.33 */
                                                                } else {
                                                                    return true; /* p_pos=0.368, tau=0.33 */
                                                                }
                                                            }
                                                        }
                                                    } else {
                                                        if (features[72] /* Feature_HR_Delta_60s_max */ <= 0.72786f) {
                                                            if (features[13] /* Feature_HR_Mean_60s_mean */ <= -0.15058f) {
                                                                if (features[9] /* Feature_Pulse_Pressure_mean */ <= 1.13617f) {
                                                                    return false; /* p_pos=0.110, tau=0.33 */
                                                                } else {
                                                                    return true; /* p_pos=0.600, tau=0.33 */
                                                                }
                                                            } else {
                                                                if (features[47] /* Feature_Pulse_Pressure_min */ <= -1.18758f) {
                                                                    return false; /* p_pos=0.250, tau=0.33 */
                                                                } else {
                                                                    return false; /* p_pos=0.023, tau=0.33 */
                                                                }
                                                            }
                                                        } else {
                                                            if (features[70] /* Feature_HR_Mean_60s_max */ <= -0.62191f) {
                                                                if (features[43] /* RR_CO2_min */ <= 0.45272f) {
                                                                    return false; /* p_pos=0.207, tau=0.33 */
                                                                } else {
                                                                    return true; /* p_pos=0.897, tau=0.33 */
                                                                }
                                                            } else {
                                                                if (features[57] /* HR_max */ <= 2.21708f) {
                                                                    return false; /* p_pos=0.126, tau=0.33 */
                                                                } else {
                                                                    return false; /* p_pos=0.260, tau=0.33 */
                                                                }
                                                            }
                                                        }
                                                    }
                                                } else {
                                                    if (features[62] /* RR_CO2_max */ <= 1.62753f) {
                                                        if (features[54] /* Feature_MBP_Mean_60s_min */ <= 0.54876f) {
                                                            if (features[48] /* Feature_Shock_Index_min */ <= -0.66659f) {
                                                                if (features[55] /* Feature_MBP_Std_60s_min */ <= -0.18503f) {
                                                                    return true; /* p_pos=1.000, tau=0.33 */
                                                                } else {
                                                                    return false; /* p_pos=0.328, tau=0.33 */
                                                                }
                                                            } else {
                                                                if (features[26] /* FIO2_std */ <= -0.40487f) {
                                                                    return true; /* p_pos=0.421, tau=0.33 */
                                                                } else {
                                                                    return false; /* p_pos=0.096, tau=0.33 */
                                                                }
                                                            }
                                                        } else {
                                                            if (features[25] /* ETCO2_std */ <= 0.02149f) {
                                                                if (features[6] /* ETCO2_mean */ <= 0.02354f) {
                                                                    return true; /* p_pos=1.000, tau=0.33 */
                                                                } else {
                                                                    return true; /* p_pos=0.600, tau=0.33 */
                                                                }
                                                            } else {
                                                                if (features[92] /* Feature_MBP_Mean_60s_slope */ <= 0.66674f) {
                                                                    return false; /* p_pos=0.233, tau=0.33 */
                                                                } else {
                                                                    return true; /* p_pos=0.850, tau=0.33 */
                                                                }
                                                            }
                                                        }
                                                    } else {
                                                        if (features[17] /* Feature_MBP_Std_60s_mean */ <= -0.27227f) {
                                                            if (features[9] /* Feature_Pulse_Pressure_mean */ <= 1.09031f) {
                                                                if (features[40] /* ART_DBP_min */ <= -1.52337f) {
                                                                    return false; /* p_pos=0.111, tau=0.33 */
                                                                } else {
                                                                    return true; /* p_pos=0.870, tau=0.33 */
                                                                }
                                                            } else {
                                                                return false; /* p_pos=0.000, tau=0.33 */
                                                            }
                                                        } else {
                                                            if (features[23] /* PLETH_SPO2_std */ <= 7.76384f) {
                                                                if (features[87] /* Feature_Modified_Shock_Index_slope */ <= -0.68361f) {
                                                                    return false; /* p_pos=0.000, tau=0.33 */
                                                                } else {
                                                                    return true; /* p_pos=0.331, tau=0.33 */
                                                                }
                                                            } else {
                                                                return true; /* p_pos=0.933, tau=0.33 */
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                } else {
                                    if (features[24] /* RR_CO2_std */ <= 2.00259f) {
                                        if (features[26] /* FIO2_std */ <= -0.26207f) {
                                            if (features[9] /* Feature_Pulse_Pressure_mean */ <= 0.21614f) {
                                                if (features[53] /* Feature_HR_Delta_60s_min */ <= 0.70708f) {
                                                    if (features[48] /* Feature_Shock_Index_min */ <= 0.17655f) {
                                                        return true; /* p_pos=1.000, tau=0.33 */
                                                    } else {
                                                        if (features[4] /* PLETH_SPO2_mean */ <= -2.82482f) {
                                                            if (features[70] /* Feature_HR_Mean_60s_max */ <= 2.03436f) {
                                                                return false; /* p_pos=0.125, tau=0.33 */
                                                            } else {
                                                                if (features[90] /* Feature_HR_Std_60s_slope */ <= 0.64276f) {
                                                                    return true; /* p_pos=0.906, tau=0.33 */
                                                                } else {
                                                                    return false; /* p_pos=0.300, tau=0.33 */
                                                                }
                                                            }
                                                        } else {
                                                            if (features[43] /* RR_CO2_min */ <= 0.45272f) {
                                                                if (features[13] /* Feature_HR_Mean_60s_mean */ <= 2.45847f) {
                                                                    return true; /* p_pos=1.000, tau=0.33 */
                                                                } else {
                                                                    return false; /* p_pos=0.273, tau=0.33 */
                                                                }
                                                            } else {
                                                                if (features[24] /* RR_CO2_std */ <= -0.36883f) {
                                                                    return false; /* p_pos=0.000, tau=0.33 */
                                                                } else {
                                                                    return true; /* p_pos=0.400, tau=0.33 */
                                                                }
                                                            }
                                                        }
                                                    }
                                                } else {
                                                    if (features[58] /* ART_SBP_max */ <= -0.35194f) {
                                                        return true; /* p_pos=1.000, tau=0.33 */
                                                    } else {
                                                        return true; /* p_pos=0.800, tau=0.33 */
                                                    }
                                                }
                                            } else {
                                                if (features[49] /* Feature_Modified_Shock_Index_min */ <= 1.46456f) {
                                                    return false; /* p_pos=0.000, tau=0.33 */
                                                } else {
                                                    return true; /* p_pos=0.500, tau=0.33 */
                                                }
                                            }
                                        } else {
                                            if (features[30] /* Feature_Modified_Shock_Index_std */ <= 0.43505f) {
                                                if (features[55] /* Feature_MBP_Std_60s_min */ <= 0.01056f) {
                                                    return false; /* p_pos=0.000, tau=0.33 */
                                                } else {
                                                    if (features[65] /* BT_max */ <= 0.45480f) {
                                                        if (features[62] /* RR_CO2_max */ <= 0.11864f) {
                                                            return false; /* p_pos=0.250, tau=0.33 */
                                                        } else {
                                                            return true; /* p_pos=1.000, tau=0.33 */
                                                        }
                                                    } else {
                                                        return false; /* p_pos=0.000, tau=0.33 */
                                                    }
                                                }
                                            } else {
                                                if (features[7] /* FIO2_mean */ <= 0.90193f) {
                                                    return false; /* p_pos=0.000, tau=0.33 */
                                                } else {
                                                    if (features[64] /* FIO2_max */ <= 1.61454f) {
                                                        return true; /* p_pos=0.800, tau=0.33 */
                                                    } else {
                                                        if (features[23] /* PLETH_SPO2_std */ <= 7.17077f) {
                                                            return false; /* p_pos=0.000, tau=0.33 */
                                                        } else {
                                                            return true; /* p_pos=0.600, tau=0.33 */
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    } else {
                                        if (features[38] /* HR_min */ <= 2.81915f) {
                                            if (features[5] /* RR_CO2_mean */ <= -1.64013f) {
                                                return false; /* p_pos=0.000, tau=0.33 */
                                            } else {
                                                if (features[9] /* Feature_Pulse_Pressure_mean */ <= -0.04499f) {
                                                    return true; /* p_pos=1.000, tau=0.33 */
                                                } else {
                                                    return true; /* p_pos=0.818, tau=0.33 */
                                                }
                                            }
                                        } else {
                                            return false; /* p_pos=0.059, tau=0.33 */
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        } else {
            if (features[42] /* PLETH_SPO2_min */ <= -0.18239f) {
                if (features[61] /* PLETH_SPO2_max */ <= -0.47816f) {
                    if (features[84] /* BT_slope */ <= -5.18344f) {
                        if (features[10] /* Feature_Shock_Index_mean */ <= 0.17297f) {
                            if (features[62] /* RR_CO2_max */ <= -0.13284f) {
                                return true; /* p_pos=0.333, tau=0.33 */
                            } else {
                                return true; /* p_pos=1.000, tau=0.33 */
                            }
                        } else {
                            return false; /* p_pos=0.000, tau=0.33 */
                        }
                    } else {
                        if (features[48] /* Feature_Shock_Index_min */ <= 1.42023f) {
                            if (features[80] /* PLETH_SPO2_slope */ <= -1.35749f) {
                                if (features[9] /* Feature_Pulse_Pressure_mean */ <= -0.15143f) {
                                    if (features[26] /* FIO2_std */ <= 0.78905f) {
                                        if (features[55] /* Feature_MBP_Std_60s_min */ <= -0.03750f) {
                                            if (features[5] /* RR_CO2_mean */ <= -1.25042f) {
                                                return true; /* p_pos=0.353, tau=0.33 */
                                            } else {
                                                if (features[32] /* Feature_HR_Mean_60s_std */ <= 1.71965f) {
                                                    return false; /* p_pos=0.000, tau=0.33 */
                                                } else {
                                                    return false; /* p_pos=0.222, tau=0.33 */
                                                }
                                            }
                                        } else {
                                            if (features[49] /* Feature_Modified_Shock_Index_min */ <= 0.69415f) {
                                                if (features[53] /* Feature_HR_Delta_60s_min */ <= 0.60378f) {
                                                    if (features[56] /* Feature_MBP_Delta_60s_min */ <= 0.48129f) {
                                                        return false; /* p_pos=0.000, tau=0.33 */
                                                    } else {
                                                        return true; /* p_pos=0.333, tau=0.33 */
                                                    }
                                                } else {
                                                    return true; /* p_pos=0.571, tau=0.33 */
                                                }
                                            } else {
                                                return true; /* p_pos=0.609, tau=0.33 */
                                            }
                                        }
                                    } else {
                                        return true; /* p_pos=0.625, tau=0.33 */
                                    }
                                } else {
                                    if (features[47] /* Feature_Pulse_Pressure_min */ <= -1.29986f) {
                                        return true; /* p_pos=0.429, tau=0.33 */
                                    } else {
                                        if (features[63] /* ETCO2_max */ <= 1.74812f) {
                                            if (features[50] /* Feature_Rate_Pressure_Product_min */ <= 1.39458f) {
                                                if (features[10] /* Feature_Shock_Index_mean */ <= -0.88229f) {
                                                    return false; /* p_pos=0.200, tau=0.33 */
                                                } else {
                                                    return false; /* p_pos=0.000, tau=0.33 */
                                                }
                                            } else {
                                                if (features[16] /* Feature_MBP_Mean_60s_mean */ <= 0.14548f) {
                                                    return true; /* p_pos=0.600, tau=0.33 */
                                                } else {
                                                    return false; /* p_pos=0.000, tau=0.33 */
                                                }
                                            }
                                        } else {
                                            return false; /* p_pos=0.182, tau=0.33 */
                                        }
                                    }
                                }
                            } else {
                                if (features[26] /* FIO2_std */ <= 1.35740f) {
                                    if (features[42] /* PLETH_SPO2_min */ <= -0.96225f) {
                                        if (features[6] /* ETCO2_mean */ <= 0.23456f) {
                                            if (features[50] /* Feature_Rate_Pressure_Product_min */ <= 0.86926f) {
                                                if (features[9] /* Feature_Pulse_Pressure_mean */ <= -0.36604f) {
                                                    if (features[52] /* Feature_HR_Std_60s_min */ <= -0.07902f) {
                                                        if (features[66] /* Feature_Pulse_Pressure_max */ <= -0.79880f) {
                                                            return false; /* p_pos=0.000, tau=0.33 */
                                                        } else {
                                                            if (features[50] /* Feature_Rate_Pressure_Product_min */ <= -0.44333f) {
                                                                if (features[78] /* ART_DBP_slope */ <= 0.81821f) {
                                                                    return false; /* p_pos=0.000, tau=0.33 */
                                                                } else {
                                                                    return false; /* p_pos=0.231, tau=0.33 */
                                                                }
                                                            } else {
                                                                if (features[37] /* Feature_MBP_Delta_60s_std */ <= -0.43651f) {
                                                                    return true; /* p_pos=0.651, tau=0.33 */
                                                                } else {
                                                                    return false; /* p_pos=0.114, tau=0.33 */
                                                                }
                                                            }
                                                        }
                                                    } else {
                                                        if (features[89] /* Feature_HR_Mean_60s_slope */ <= -2.19671f) {
                                                            return false; /* p_pos=0.200, tau=0.33 */
                                                        } else {
                                                            return false; /* p_pos=0.000, tau=0.33 */
                                                        }
                                                    }
                                                } else {
                                                    if (features[84] /* BT_slope */ <= -0.09351f) {
                                                        if (features[46] /* BT_min */ <= 0.37905f) {
                                                            if (features[81] /* RR_CO2_slope */ <= 0.11001f) {
                                                                return false; /* p_pos=0.000, tau=0.33 */
                                                            } else {
                                                                if (features[88] /* Feature_Rate_Pressure_Product_slope */ <= 0.82582f) {
                                                                    return false; /* p_pos=0.000, tau=0.33 */
                                                                } else {
                                                                    return true; /* p_pos=0.500, tau=0.33 */
                                                                }
                                                            }
                                                        } else {
                                                            return false; /* p_pos=0.304, tau=0.33 */
                                                        }
                                                    } else {
                                                        return false; /* p_pos=0.000, tau=0.33 */
                                                    }
                                                }
                                            } else {
                                                if (features[60] /* ART_MBP_max */ <= -0.21493f) {
                                                    if (features[36] /* Feature_MBP_Std_60s_std */ <= -0.48843f) {
                                                        if (features[26] /* FIO2_std */ <= -0.23508f) {
                                                            if (features[72] /* Feature_HR_Delta_60s_max */ <= -0.00798f) {
                                                                return true; /* p_pos=0.556, tau=0.33 */
                                                            } else {
                                                                return true; /* p_pos=1.000, tau=0.33 */
                                                            }
                                                        } else {
                                                            return false; /* p_pos=0.091, tau=0.33 */
                                                        }
                                                    } else {
                                                        return false; /* p_pos=0.042, tau=0.33 */
                                                    }
                                                } else {
                                                    if (features[85] /* Feature_Pulse_Pressure_slope */ <= 0.88322f) {
                                                        return false; /* p_pos=0.000, tau=0.33 */
                                                    } else {
                                                        return false; /* p_pos=0.250, tau=0.33 */
                                                    }
                                                }
                                            }
                                        } else {
                                            if (features[69] /* Feature_Rate_Pressure_Product_max */ <= -0.31362f) {
                                                if (features[27] /* BT_std */ <= -0.07725f) {
                                                    if (features[69] /* Feature_Rate_Pressure_Product_max */ <= -0.36180f) {
                                                        return false; /* p_pos=0.000, tau=0.33 */
                                                    } else {
                                                        if (features[2] /* ART_DBP_mean */ <= 0.27527f) {
                                                            return false; /* p_pos=0.000, tau=0.33 */
                                                        } else {
                                                            return true; /* p_pos=0.600, tau=0.33 */
                                                        }
                                                    }
                                                } else {
                                                    if (features[12] /* Feature_Rate_Pressure_Product_mean */ <= -0.76196f) {
                                                        return true; /* p_pos=0.800, tau=0.33 */
                                                    } else {
                                                        return false; /* p_pos=0.000, tau=0.33 */
                                                    }
                                                }
                                            } else {
                                                return false; /* p_pos=0.000, tau=0.33 */
                                            }
                                        }
                                    } else {
                                        if (features[8] /* BT_mean */ <= 0.50123f) {
                                            if (features[56] /* Feature_MBP_Delta_60s_min */ <= -2.67995f) {
                                                if (features[55] /* Feature_MBP_Std_60s_min */ <= 0.30672f) {
                                                    if (features[5] /* RR_CO2_mean */ <= -0.64302f) {
                                                        if (features[65] /* BT_max */ <= 0.32306f) {
                                                            if (features[15] /* Feature_HR_Delta_60s_mean */ <= -0.94993f) {
                                                                return true; /* p_pos=0.500, tau=0.33 */
                                                            } else {
                                                                return false; /* p_pos=0.000, tau=0.33 */
                                                            }
                                                        } else {
                                                            return true; /* p_pos=1.000, tau=0.33 */
                                                        }
                                                    } else {
                                                        if (features[17] /* Feature_MBP_Std_60s_mean */ <= -0.09975f) {
                                                            return false; /* p_pos=0.167, tau=0.33 */
                                                        } else {
                                                            return false; /* p_pos=0.000, tau=0.33 */
                                                        }
                                                    }
                                                } else {
                                                    if (features[70] /* Feature_HR_Mean_60s_max */ <= 0.75866f) {
                                                        return false; /* p_pos=0.000, tau=0.33 */
                                                    } else {
                                                        return true; /* p_pos=1.000, tau=0.33 */
                                                    }
                                                }
                                            } else {
                                                if (features[36] /* Feature_MBP_Std_60s_std */ <= -0.42632f) {
                                                    if (features[44] /* ETCO2_min */ <= 2.05394f) {
                                                        if (features[3] /* ART_MBP_mean */ <= 0.18918f) {
                                                            if (features[55] /* Feature_MBP_Std_60s_min */ <= 0.28359f) {
                                                                if (features[25] /* ETCO2_std */ <= -0.49777f) {
                                                                    return false; /* p_pos=0.024, tau=0.33 */
                                                                } else {
                                                                    return false; /* p_pos=0.006, tau=0.33 */
                                                                }
                                                            } else {
                                                                if (features[8] /* BT_mean */ <= -3.33271f) {
                                                                    return true; /* p_pos=1.000, tau=0.33 */
                                                                } else {
                                                                    return false; /* p_pos=0.023, tau=0.33 */
                                                                }
                                                            }
                                                        } else {
                                                            if (features[40] /* ART_DBP_min */ <= -0.33794f) {
                                                                if (features[69] /* Feature_Rate_Pressure_Product_max */ <= -0.07526f) {
                                                                    return true; /* p_pos=0.463, tau=0.33 */
                                                                } else {
                                                                    return false; /* p_pos=0.028, tau=0.33 */
                                                                }
                                                            } else {
                                                                if (features[8] /* BT_mean */ <= 0.34937f) {
                                                                    return false; /* p_pos=0.010, tau=0.33 */
                                                                } else {
                                                                    return false; /* p_pos=0.066, tau=0.33 */
                                                                }
                                                            }
                                                        }
                                                    } else {
                                                        return false; /* p_pos=0.318, tau=0.33 */
                                                    }
                                                } else {
                                                    if (features[7] /* FIO2_mean */ <= -0.64375f) {
                                                        if (features[68] /* Feature_Modified_Shock_Index_max */ <= 1.20309f) {
                                                            return false; /* p_pos=0.000, tau=0.33 */
                                                        } else {
                                                            if (features[31] /* Feature_Rate_Pressure_Product_std */ <= -0.55594f) {
                                                                return true; /* p_pos=0.333, tau=0.33 */
                                                            } else {
                                                                if (features[30] /* Feature_Modified_Shock_Index_std */ <= 0.00154f) {
                                                                    return false; /* p_pos=0.200, tau=0.33 */
                                                                } else {
                                                                    return false; /* p_pos=0.000, tau=0.33 */
                                                                }
                                                            }
                                                        }
                                                    } else {
                                                        if (features[28] /* Feature_Pulse_Pressure_std */ <= 0.05301f) {
                                                            if (features[11] /* Feature_Modified_Shock_Index_mean */ <= -0.38744f) {
                                                                if (features[84] /* BT_slope */ <= 4.30681f) {
                                                                    return false; /* p_pos=0.026, tau=0.33 */
                                                                } else {
                                                                    return true; /* p_pos=0.500, tau=0.33 */
                                                                }
                                                            } else {
                                                                if (features[7] /* FIO2_mean */ <= -0.62782f) {
                                                                    return false; /* p_pos=0.049, tau=0.33 */
                                                                } else {
                                                                    return false; /* p_pos=0.004, tau=0.33 */
                                                                }
                                                            }
                                                        } else {
                                                            if (features[23] /* PLETH_SPO2_std */ <= -0.35986f) {
                                                                return true; /* p_pos=0.600, tau=0.33 */
                                                            } else {
                                                                if (features[7] /* FIO2_mean */ <= -0.64292f) {
                                                                    return false; /* p_pos=0.200, tau=0.33 */
                                                                } else {
                                                                    return false; /* p_pos=0.000, tau=0.33 */
                                                                }
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        } else {
                                            if (features[6] /* ETCO2_mean */ <= 0.18739f) {
                                                return true; /* p_pos=0.647, tau=0.33 */
                                            } else {
                                                return false; /* p_pos=0.000, tau=0.33 */
                                            }
                                        }
                                    }
                                } else {
                                    if (features[8] /* BT_mean */ <= 0.30079f) {
                                        if (features[7] /* FIO2_mean */ <= 1.45590f) {
                                            if (features[74] /* Feature_MBP_Std_60s_max */ <= -0.32570f) {
                                                if (features[20] /* ART_SBP_std */ <= -0.43023f) {
                                                    return false; /* p_pos=0.118, tau=0.33 */
                                                } else {
                                                    return true; /* p_pos=1.000, tau=0.33 */
                                                }
                                            } else {
                                                if (features[63] /* ETCO2_max */ <= -0.62487f) {
                                                    return true; /* p_pos=0.667, tau=0.33 */
                                                } else {
                                                    if (features[85] /* Feature_Pulse_Pressure_slope */ <= -1.58795f) {
                                                        return false; /* p_pos=0.200, tau=0.33 */
                                                    } else {
                                                        return false; /* p_pos=0.000, tau=0.33 */
                                                    }
                                                }
                                            }
                                        } else {
                                            return false; /* p_pos=0.000, tau=0.33 */
                                        }
                                    } else {
                                        return false; /* p_pos=0.000, tau=0.33 */
                                    }
                                }
                            }
                        } else {
                            if (features[59] /* ART_DBP_max */ <= -0.93987f) {
                                if (features[30] /* Feature_Modified_Shock_Index_std */ <= 2.36945f) {
                                    if (features[15] /* Feature_HR_Delta_60s_mean */ <= 1.08907f) {
                                        return false; /* p_pos=0.000, tau=0.33 */
                                    } else {
                                        return false; /* p_pos=0.067, tau=0.33 */
                                    }
                                } else {
                                    return true; /* p_pos=0.357, tau=0.33 */
                                }
                            } else {
                                if (features[75] /* Feature_MBP_Delta_60s_max */ <= -0.56426f) {
                                    if (features[31] /* Feature_Rate_Pressure_Product_std */ <= -0.20679f) {
                                        return false; /* p_pos=0.000, tau=0.33 */
                                    } else {
                                        return false; /* p_pos=0.095, tau=0.33 */
                                    }
                                } else {
                                    if (features[54] /* Feature_MBP_Mean_60s_min */ <= -2.17858f) {
                                        return true; /* p_pos=1.000, tau=0.33 */
                                    } else {
                                        if (features[32] /* Feature_HR_Mean_60s_std */ <= 2.32349f) {
                                            if (features[63] /* ETCO2_max */ <= -6.16184f) {
                                                return true; /* p_pos=1.000, tau=0.33 */
                                            } else {
                                                if (features[5] /* RR_CO2_mean */ <= 5.30884f) {
                                                    if (features[55] /* Feature_MBP_Std_60s_min */ <= -0.09014f) {
                                                        if (features[35] /* Feature_MBP_Mean_60s_std */ <= 1.15178f) {
                                                            return false; /* p_pos=0.000, tau=0.33 */
                                                        } else {
                                                            return false; /* p_pos=0.200, tau=0.33 */
                                                        }
                                                    } else {
                                                        if (features[55] /* Feature_MBP_Std_60s_min */ <= -0.08545f) {
                                                            return true; /* p_pos=1.000, tau=0.33 */
                                                        } else {
                                                            if (features[8] /* BT_mean */ <= 0.44182f) {
                                                                if (features[48] /* Feature_Shock_Index_min */ <= 1.43841f) {
                                                                    return true; /* p_pos=0.750, tau=0.33 */
                                                                } else {
                                                                    return false; /* p_pos=0.056, tau=0.33 */
                                                                }
                                                            } else {
                                                                return true; /* p_pos=0.615, tau=0.33 */
                                                            }
                                                        }
                                                    }
                                                } else {
                                                    return true; /* p_pos=0.667, tau=0.33 */
                                                }
                                            }
                                        } else {
                                            return true; /* p_pos=0.619, tau=0.33 */
                                        }
                                    }
                                }
                            }
                        }
                    }
                } else {
                    if (features[84] /* BT_slope */ <= -0.75028f) {
                        if (features[66] /* Feature_Pulse_Pressure_max */ <= 0.32826f) {
                            if (features[5] /* RR_CO2_mean */ <= 2.04448f) {
                                if (features[39] /* ART_SBP_min */ <= -2.56026f) {
                                    if (features[84] /* BT_slope */ <= -5.01925f) {
                                        return true; /* p_pos=1.000, tau=0.33 */
                                    } else {
                                        if (features[38] /* HR_min */ <= -0.16629f) {
                                            return false; /* p_pos=0.000, tau=0.33 */
                                        } else {
                                            return true; /* p_pos=0.545, tau=0.33 */
                                        }
                                    }
                                } else {
                                    if (features[64] /* FIO2_max */ <= 1.79253f) {
                                        if (features[47] /* Feature_Pulse_Pressure_min */ <= -0.23317f) {
                                            if (features[8] /* BT_mean */ <= 0.24194f) {
                                                if (features[88] /* Feature_Rate_Pressure_Product_slope */ <= -0.95504f) {
                                                    return false; /* p_pos=0.167, tau=0.33 */
                                                } else {
                                                    return false; /* p_pos=0.000, tau=0.33 */
                                                }
                                            } else {
                                                return true; /* p_pos=0.333, tau=0.33 */
                                            }
                                        } else {
                                            if (features[49] /* Feature_Modified_Shock_Index_min */ <= 0.74559f) {
                                                if (features[67] /* Feature_Shock_Index_max */ <= -0.39385f) {
                                                    if (features[25] /* ETCO2_std */ <= 0.32763f) {
                                                        return false; /* p_pos=0.000, tau=0.33 */
                                                    } else {
                                                        return false; /* p_pos=0.158, tau=0.33 */
                                                    }
                                                } else {
                                                    if (features[84] /* BT_slope */ <= -1.34137f) {
                                                        if (features[53] /* Feature_HR_Delta_60s_min */ <= 0.55213f) {
                                                            if (features[4] /* PLETH_SPO2_mean */ <= 0.25600f) {
                                                                return true; /* p_pos=0.545, tau=0.33 */
                                                            } else {
                                                                if (features[56] /* Feature_MBP_Delta_60s_min */ <= 0.48129f) {
                                                                    return false; /* p_pos=0.000, tau=0.33 */
                                                                } else {
                                                                    return false; /* p_pos=0.250, tau=0.33 */
                                                                }
                                                            }
                                                        } else {
                                                            return true; /* p_pos=0.857, tau=0.33 */
                                                        }
                                                    } else {
                                                        if (features[8] /* BT_mean */ <= 0.00673f) {
                                                            return false; /* p_pos=0.200, tau=0.33 */
                                                        } else {
                                                            return false; /* p_pos=0.000, tau=0.33 */
                                                        }
                                                    }
                                                }
                                            } else {
                                                return false; /* p_pos=0.000, tau=0.33 */
                                            }
                                        }
                                    } else {
                                        return true; /* p_pos=0.588, tau=0.33 */
                                    }
                                }
                            } else {
                                return true; /* p_pos=1.000, tau=0.33 */
                            }
                        } else {
                            if (features[54] /* Feature_MBP_Mean_60s_min */ <= 0.18317f) {
                                if (features[72] /* Feature_HR_Delta_60s_max */ <= 0.16964f) {
                                    if (features[10] /* Feature_Shock_Index_mean */ <= -0.22924f) {
                                        if (features[73] /* Feature_MBP_Mean_60s_max */ <= 0.09993f) {
                                            return true; /* p_pos=0.750, tau=0.33 */
                                        } else {
                                            return false; /* p_pos=0.000, tau=0.33 */
                                        }
                                    } else {
                                        if (features[21] /* ART_DBP_std */ <= -0.27907f) {
                                            return false; /* p_pos=0.200, tau=0.33 */
                                        } else {
                                            return false; /* p_pos=0.000, tau=0.33 */
                                        }
                                    }
                                } else {
                                    if (features[55] /* Feature_MBP_Std_60s_min */ <= 0.01733f) {
                                        return false; /* p_pos=0.158, tau=0.33 */
                                    } else {
                                        return true; /* p_pos=1.000, tau=0.33 */
                                    }
                                }
                            } else {
                                if (features[25] /* ETCO2_std */ <= 0.13891f) {
                                    if (features[11] /* Feature_Modified_Shock_Index_mean */ <= -0.93970f) {
                                        return true; /* p_pos=1.000, tau=0.33 */
                                    } else {
                                        if (features[45] /* FIO2_min */ <= -0.73168f) {
                                            return true; /* p_pos=1.000, tau=0.33 */
                                        } else {
                                            if (features[63] /* ETCO2_max */ <= 0.16613f) {
                                                if (features[42] /* PLETH_SPO2_min */ <= -0.44235f) {
                                                    if (features[1] /* ART_SBP_mean */ <= 1.27903f) {
                                                        if (features[18] /* Feature_MBP_Delta_60s_mean */ <= -0.00157f) {
                                                            if (features[27] /* BT_std */ <= 5.09634f) {
                                                                return true; /* p_pos=0.500, tau=0.33 */
                                                            } else {
                                                                return true; /* p_pos=1.000, tau=0.33 */
                                                            }
                                                        } else {
                                                            return true; /* p_pos=1.000, tau=0.33 */
                                                        }
                                                    } else {
                                                        return false; /* p_pos=0.067, tau=0.33 */
                                                    }
                                                } else {
                                                    if (features[16] /* Feature_MBP_Mean_60s_mean */ <= 1.26840f) {
                                                        return false; /* p_pos=0.000, tau=0.33 */
                                                    } else {
                                                        return false; /* p_pos=0.286, tau=0.33 */
                                                    }
                                                }
                                            } else {
                                                return false; /* p_pos=0.042, tau=0.33 */
                                            }
                                        }
                                    }
                                } else {
                                    if (features[65] /* BT_max */ <= 0.38893f) {
                                        if (features[52] /* Feature_HR_Std_60s_min */ <= 0.00171f) {
                                            if (features[25] /* ETCO2_std */ <= 0.26355f) {
                                                return true; /* p_pos=0.800, tau=0.33 */
                                            } else {
                                                return true; /* p_pos=1.000, tau=0.33 */
                                            }
                                        } else {
                                            if (features[33] /* Feature_HR_Std_60s_std */ <= 0.25303f) {
                                                return true; /* p_pos=0.353, tau=0.33 */
                                            } else {
                                                return true; /* p_pos=1.000, tau=0.33 */
                                            }
                                        }
                                    } else {
                                        return false; /* p_pos=0.200, tau=0.33 */
                                    }
                                }
                            }
                        }
                    } else {
                        if (features[45] /* FIO2_min */ <= 2.01080f) {
                            if (features[42] /* PLETH_SPO2_min */ <= -0.96225f) {
                                if (features[80] /* PLETH_SPO2_slope */ <= -1.35749f) {
                                    if (features[4] /* PLETH_SPO2_mean */ <= -0.59376f) {
                                        if (features[49] /* Feature_Modified_Shock_Index_min */ <= 0.70835f) {
                                            if (features[86] /* Feature_Shock_Index_slope */ <= -2.23095f) {
                                                return true; /* p_pos=0.833, tau=0.33 */
                                            } else {
                                                if (features[19] /* HR_std */ <= -0.13651f) {
                                                    if (features[81] /* RR_CO2_slope */ <= 0.52116f) {
                                                        if (features[16] /* Feature_MBP_Mean_60s_mean */ <= -0.04344f) {
                                                            return false; /* p_pos=0.000, tau=0.33 */
                                                        } else {
                                                            if (features[54] /* Feature_MBP_Mean_60s_min */ <= -0.04948f) {
                                                                return true; /* p_pos=0.800, tau=0.33 */
                                                            } else {
                                                                if (features[25] /* ETCO2_std */ <= -0.33915f) {
                                                                    return false; /* p_pos=0.261, tau=0.33 */
                                                                } else {
                                                                    return false; /* p_pos=0.022, tau=0.33 */
                                                                }
                                                            }
                                                        }
                                                    } else {
                                                        if (features[24] /* RR_CO2_std */ <= 0.70466f) {
                                                            return true; /* p_pos=0.833, tau=0.33 */
                                                        } else {
                                                            return false; /* p_pos=0.000, tau=0.33 */
                                                        }
                                                    }
                                                } else {
                                                    if (features[80] /* PLETH_SPO2_slope */ <= -2.42818f) {
                                                        if (features[27] /* BT_std */ <= -0.21351f) {
                                                            if (features[4] /* PLETH_SPO2_mean */ <= -1.31855f) {
                                                                return false; /* p_pos=0.000, tau=0.33 */
                                                            } else {
                                                                return true; /* p_pos=0.333, tau=0.33 */
                                                            }
                                                        } else {
                                                            return false; /* p_pos=0.000, tau=0.33 */
                                                        }
                                                    } else {
                                                        return false; /* p_pos=0.000, tau=0.33 */
                                                    }
                                                }
                                            }
                                        } else {
                                            if (features[60] /* ART_MBP_max */ <= -0.44741f) {
                                                if (features[67] /* Feature_Shock_Index_max */ <= 0.47819f) {
                                                    return true; /* p_pos=0.833, tau=0.33 */
                                                } else {
                                                    return false; /* p_pos=0.042, tau=0.33 */
                                                }
                                            } else {
                                                return true; /* p_pos=0.867, tau=0.33 */
                                            }
                                        }
                                    } else {
                                        if (features[66] /* Feature_Pulse_Pressure_max */ <= 1.13743f) {
                                            if (features[91] /* Feature_HR_Delta_60s_slope */ <= -0.93983f) {
                                                return false; /* p_pos=0.000, tau=0.33 */
                                            } else {
                                                if (features[90] /* Feature_HR_Std_60s_slope */ <= 1.21507f) {
                                                    if (features[32] /* Feature_HR_Mean_60s_std */ <= 1.22675f) {
                                                        if (features[4] /* PLETH_SPO2_mean */ <= 0.31451f) {
                                                            if (features[28] /* Feature_Pulse_Pressure_std */ <= 1.02385f) {
                                                                if (features[44] /* ETCO2_min */ <= 0.44710f) {
                                                                    return true; /* p_pos=0.336, tau=0.33 */
                                                                } else {
                                                                    return false; /* p_pos=0.122, tau=0.33 */
                                                                }
                                                            } else {
                                                                return false; /* p_pos=0.000, tau=0.33 */
                                                            }
                                                        } else {
                                                            return false; /* p_pos=0.000, tau=0.33 */
                                                        }
                                                    } else {
                                                        return false; /* p_pos=0.000, tau=0.33 */
                                                    }
                                                } else {
                                                    return true; /* p_pos=0.583, tau=0.33 */
                                                }
                                            }
                                        } else {
                                            if (features[78] /* ART_DBP_slope */ <= 0.96284f) {
                                                if (features[26] /* FIO2_std */ <= 0.80138f) {
                                                    if (features[43] /* RR_CO2_min */ <= -0.33168f) {
                                                        return false; /* p_pos=0.000, tau=0.33 */
                                                    } else {
                                                        return true; /* p_pos=0.500, tau=0.33 */
                                                    }
                                                } else {
                                                    return true; /* p_pos=0.833, tau=0.33 */
                                                }
                                            } else {
                                                return true; /* p_pos=0.909, tau=0.33 */
                                            }
                                        }
                                    }
                                } else {
                                    if (features[38] /* HR_min */ <= 3.70121f) {
                                        if (features[29] /* Feature_Shock_Index_std */ <= 1.90340f) {
                                            if (features[7] /* FIO2_mean */ <= 2.35732f) {
                                                if (features[31] /* Feature_Rate_Pressure_Product_std */ <= -0.68009f) {
                                                    if (features[0] /* HR_mean */ <= -1.90201f) {
                                                        return true; /* p_pos=1.000, tau=0.33 */
                                                    } else {
                                                        if (features[43] /* RR_CO2_min */ <= -1.37754f) {
                                                            if (features[65] /* BT_max */ <= 0.27366f) {
                                                                return false; /* p_pos=0.000, tau=0.33 */
                                                            } else {
                                                                if (features[44] /* ETCO2_min */ <= -0.35632f) {
                                                                    return false; /* p_pos=0.000, tau=0.33 */
                                                                } else {
                                                                    return true; /* p_pos=0.364, tau=0.33 */
                                                                }
                                                            }
                                                        } else {
                                                            if (features[53] /* Feature_HR_Delta_60s_min */ <= -1.53967f) {
                                                                return true; /* p_pos=1.000, tau=0.33 */
                                                            } else {
                                                                if (features[64] /* FIO2_max */ <= -0.65481f) {
                                                                    return false; /* p_pos=0.051, tau=0.33 */
                                                                } else {
                                                                    return false; /* p_pos=0.202, tau=0.33 */
                                                                }
                                                            }
                                                        }
                                                    }
                                                } else {
                                                    if (features[24] /* RR_CO2_std */ <= 1.10197f) {
                                                        if (features[27] /* BT_std */ <= -0.15134f) {
                                                            if (features[70] /* Feature_HR_Mean_60s_max */ <= 3.32136f) {
                                                                if (features[34] /* Feature_HR_Delta_60s_std */ <= 2.83746f) {
                                                                    return false; /* p_pos=0.063, tau=0.33 */
                                                                } else {
                                                                    return false; /* p_pos=0.000, tau=0.33 */
                                                                }
                                                            } else {
                                                                return true; /* p_pos=0.700, tau=0.33 */
                                                            }
                                                        } else {
                                                            if (features[5] /* RR_CO2_mean */ <= -0.77026f) {
                                                                return false; /* p_pos=0.000, tau=0.33 */
                                                            } else {
                                                                if (features[53] /* Feature_HR_Delta_60s_min */ <= 0.29389f) {
                                                                    return false; /* p_pos=0.286, tau=0.33 */
                                                                } else {
                                                                    return false; /* p_pos=0.047, tau=0.33 */
                                                                }
                                                            }
                                                        }
                                                    } else {
                                                        if (features[21] /* ART_DBP_std */ <= 0.32878f) {
                                                            if (features[65] /* BT_max */ <= -0.13804f) {
                                                                if (features[31] /* Feature_Rate_Pressure_Product_std */ <= -0.23246f) {
                                                                    return true; /* p_pos=0.400, tau=0.33 */
                                                                } else {
                                                                    return false; /* p_pos=0.000, tau=0.33 */
                                                                }
                                                            } else {
                                                                return false; /* p_pos=0.000, tau=0.33 */
                                                            }
                                                        } else {
                                                            if (features[20] /* ART_SBP_std */ <= -0.18358f) {
                                                                return true; /* p_pos=0.583, tau=0.33 */
                                                            } else {
                                                                if (features[58] /* ART_SBP_max */ <= 1.07773f) {
                                                                    return false; /* p_pos=0.000, tau=0.33 */
                                                                } else {
                                                                    return false; /* p_pos=0.130, tau=0.33 */
                                                                }
                                                            }
                                                        }
                                                    }
                                                }
                                            } else {
                                                if (features[73] /* Feature_MBP_Mean_60s_max */ <= 0.58102f) {
                                                    return false; /* p_pos=0.087, tau=0.33 */
                                                } else {
                                                    return true; /* p_pos=1.000, tau=0.33 */
                                                }
                                            }
                                        } else {
                                            if (features[28] /* Feature_Pulse_Pressure_std */ <= 5.42505f) {
                                                return false; /* p_pos=0.000, tau=0.33 */
                                            } else {
                                                if (features[52] /* Feature_HR_Std_60s_min */ <= 0.42621f) {
                                                    return false; /* p_pos=0.000, tau=0.33 */
                                                } else {
                                                    return true; /* p_pos=0.600, tau=0.33 */
                                                }
                                            }
                                        }
                                    } else {
                                        return true; /* p_pos=0.800, tau=0.33 */
                                    }
                                }
                            } else {
                                if (features[80] /* PLETH_SPO2_slope */ <= -0.82215f) {
                                    if (features[4] /* PLETH_SPO2_mean */ <= 0.03350f) {
                                        if (features[25] /* ETCO2_std */ <= 0.00155f) {
                                            if (features[66] /* Feature_Pulse_Pressure_max */ <= -0.24972f) {
                                                if (features[55] /* Feature_MBP_Std_60s_min */ <= 0.00476f) {
                                                    if (features[66] /* Feature_Pulse_Pressure_max */ <= -0.48091f) {
                                                        if (features[37] /* Feature_MBP_Delta_60s_std */ <= -0.57467f) {
                                                            if (features[19] /* HR_std */ <= 0.12652f) {
                                                                if (features[93] /* Feature_MBP_Std_60s_slope */ <= 0.04381f) {
                                                                    return false; /* p_pos=0.000, tau=0.33 */
                                                                } else {
                                                                    return false; /* p_pos=0.200, tau=0.33 */
                                                                }
                                                            } else {
                                                                if (features[38] /* HR_min */ <= -0.16629f) {
                                                                    return false; /* p_pos=0.029, tau=0.33 */
                                                                } else {
                                                                    return true; /* p_pos=0.385, tau=0.33 */
                                                                }
                                                            }
                                                        } else {
                                                            return false; /* p_pos=0.000, tau=0.33 */
                                                        }
                                                    } else {
                                                        if (features[35] /* Feature_MBP_Mean_60s_std */ <= -0.26655f) {
                                                            if (features[63] /* ETCO2_max */ <= -0.22937f) {
                                                                return false; /* p_pos=0.000, tau=0.33 */
                                                            } else {
                                                                if (features[52] /* Feature_HR_Std_60s_min */ <= 0.54830f) {
                                                                    return false; /* p_pos=0.124, tau=0.33 */
                                                                } else {
                                                                    return true; /* p_pos=1.000, tau=0.33 */
                                                                }
                                                            }
                                                        } else {
                                                            if (features[18] /* Feature_MBP_Delta_60s_mean */ <= 0.29372f) {
                                                                return false; /* p_pos=0.000, tau=0.33 */
                                                            } else {
                                                                return false; /* p_pos=0.200, tau=0.33 */
                                                            }
                                                        }
                                                    }
                                                } else {
                                                    if (features[51] /* Feature_HR_Mean_60s_min */ <= 0.99548f) {
                                                        if (features[9] /* Feature_Pulse_Pressure_mean */ <= -1.76904f) {
                                                            return true; /* p_pos=0.571, tau=0.33 */
                                                        } else {
                                                            if (features[94] /* Feature_MBP_Delta_60s_slope */ <= 0.08927f) {
                                                                return false; /* p_pos=0.000, tau=0.33 */
                                                            } else {
                                                                if (features[77] /* ART_SBP_slope */ <= -0.15347f) {
                                                                    return false; /* p_pos=0.240, tau=0.33 */
                                                                } else {
                                                                    return false; /* p_pos=0.000, tau=0.33 */
                                                                }
                                                            }
                                                        }
                                                    } else {
                                                        if (features[79] /* ART_MBP_slope */ <= -0.34157f) {
                                                            if (features[8] /* BT_mean */ <= 0.32696f) {
                                                                return false; /* p_pos=0.250, tau=0.33 */
                                                            } else {
                                                                return true; /* p_pos=0.923, tau=0.33 */
                                                            }
                                                        } else {
                                                            if (features[69] /* Feature_Rate_Pressure_Product_max */ <= -0.03684f) {
                                                                return true; /* p_pos=0.500, tau=0.33 */
                                                            } else {
                                                                if (features[90] /* Feature_HR_Std_60s_slope */ <= -0.68249f) {
                                                                    return false; /* p_pos=0.200, tau=0.33 */
                                                                } else {
                                                                    return false; /* p_pos=0.000, tau=0.33 */
                                                                }
                                                            }
                                                        }
                                                    }
                                                }
                                            } else {
                                                if (features[13] /* Feature_HR_Mean_60s_mean */ <= 0.05306f) {
                                                    if (features[74] /* Feature_MBP_Std_60s_max */ <= -0.55080f) {
                                                        if (features[12] /* Feature_Rate_Pressure_Product_mean */ <= -0.21450f) {
                                                            return false; /* p_pos=0.000, tau=0.33 */
                                                        } else {
                                                            if (features[29] /* Feature_Shock_Index_std */ <= -0.47877f) {
                                                                return true; /* p_pos=1.000, tau=0.33 */
                                                            } else {
                                                                return false; /* p_pos=0.130, tau=0.33 */
                                                            }
                                                        }
                                                    } else {
                                                        if (features[54] /* Feature_MBP_Mean_60s_min */ <= -0.69458f) {
                                                            if (features[82] /* ETCO2_slope */ <= 0.46815f) {
                                                                if (features[62] /* RR_CO2_max */ <= -0.63580f) {
                                                                    return false; /* p_pos=0.118, tau=0.33 */
                                                                } else {
                                                                    return false; /* p_pos=0.000, tau=0.33 */
                                                                }
                                                            } else {
                                                                return true; /* p_pos=0.500, tau=0.33 */
                                                            }
                                                        } else {
                                                            if (features[74] /* Feature_MBP_Std_60s_max */ <= -0.45097f) {
                                                                if (features[75] /* Feature_MBP_Delta_60s_max */ <= -0.46503f) {
                                                                    return false; /* p_pos=0.000, tau=0.33 */
                                                                } else {
                                                                    return false; /* p_pos=0.083, tau=0.33 */
                                                                }
                                                            } else {
                                                                return false; /* p_pos=0.000, tau=0.33 */
                                                            }
                                                        }
                                                    }
                                                } else {
                                                    if (features[9] /* Feature_Pulse_Pressure_mean */ <= -1.49224f) {
                                                        return false; /* p_pos=0.200, tau=0.33 */
                                                    } else {
                                                        return false; /* p_pos=0.000, tau=0.33 */
                                                    }
                                                }
                                            }
                                        } else {
                                            if (features[0] /* HR_mean */ <= -1.27546f) {
                                                if (features[68] /* Feature_Modified_Shock_Index_max */ <= -0.18782f) {
                                                    if (features[5] /* RR_CO2_mean */ <= 0.06937f) {
                                                        if (features[23] /* PLETH_SPO2_std */ <= 0.55281f) {
                                                            return false; /* p_pos=0.143, tau=0.33 */
                                                        } else {
                                                            return true; /* p_pos=0.952, tau=0.33 */
                                                        }
                                                    } else {
                                                        return false; /* p_pos=0.143, tau=0.33 */
                                                    }
                                                } else {
                                                    return false; /* p_pos=0.000, tau=0.33 */
                                                }
                                            } else {
                                                if (features[53] /* Feature_HR_Delta_60s_min */ <= 0.60378f) {
                                                    if (features[5] /* RR_CO2_mean */ <= -0.33975f) {
                                                        if (features[44] /* ETCO2_min */ <= -2.23098f) {
                                                            if (features[4] /* PLETH_SPO2_mean */ <= -0.26398f) {
                                                                return false; /* p_pos=0.000, tau=0.33 */
                                                            } else {
                                                                return false; /* p_pos=0.208, tau=0.33 */
                                                            }
                                                        } else {
                                                            return false; /* p_pos=0.000, tau=0.33 */
                                                        }
                                                    } else {
                                                        if (features[73] /* Feature_MBP_Mean_60s_max */ <= 1.40487f) {
                                                            if (features[60] /* ART_MBP_max */ <= -0.53683f) {
                                                                if (features[45] /* FIO2_min */ <= -0.43993f) {
                                                                    return false; /* p_pos=0.000, tau=0.33 */
                                                                } else {
                                                                    return false; /* p_pos=0.270, tau=0.33 */
                                                                }
                                                            } else {
                                                                if (features[52] /* Feature_HR_Std_60s_min */ <= 0.84139f) {
                                                                    return false; /* p_pos=0.030, tau=0.33 */
                                                                } else {
                                                                    return false; /* p_pos=0.174, tau=0.33 */
                                                                }
                                                            }
                                                        } else {
                                                            if (features[49] /* Feature_Modified_Shock_Index_min */ <= -1.19508f) {
                                                                return true; /* p_pos=1.000, tau=0.33 */
                                                            } else {
                                                                if (features[44] /* ETCO2_min */ <= -0.75804f) {
                                                                    return true; /* p_pos=0.571, tau=0.33 */
                                                                } else {
                                                                    return false; /* p_pos=0.000, tau=0.33 */
                                                                }
                                                            }
                                                        }
                                                    }
                                                } else {
                                                    if (features[28] /* Feature_Pulse_Pressure_std */ <= -0.30836f) {
                                                        if (features[76] /* HR_slope */ <= -0.42912f) {
                                                            return false; /* p_pos=0.200, tau=0.33 */
                                                        } else {
                                                            return false; /* p_pos=0.000, tau=0.33 */
                                                        }
                                                    } else {
                                                        if (features[45] /* FIO2_min */ <= 1.60235f) {
                                                            if (features[38] /* HR_min */ <= 1.80138f) {
                                                                if (features[90] /* Feature_HR_Std_60s_slope */ <= 0.10232f) {
                                                                    return false; /* p_pos=0.000, tau=0.33 */
                                                                } else {
                                                                    return true; /* p_pos=0.333, tau=0.33 */
                                                                }
                                                            } else {
                                                                return true; /* p_pos=0.688, tau=0.33 */
                                                            }
                                                        } else {
                                                            return true; /* p_pos=1.000, tau=0.33 */
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    } else {
                                        if (features[16] /* Feature_MBP_Mean_60s_mean */ <= 1.28558f) {
                                            if (features[9] /* Feature_Pulse_Pressure_mean */ <= -1.32788f) {
                                                if (features[24] /* RR_CO2_std */ <= 0.14819f) {
                                                    if (features[41] /* ART_MBP_min */ <= -0.65043f) {
                                                        return false; /* p_pos=0.050, tau=0.33 */
                                                    } else {
                                                        return true; /* p_pos=0.667, tau=0.33 */
                                                    }
                                                } else {
                                                    return true; /* p_pos=0.733, tau=0.33 */
                                                }
                                            } else {
                                                if (features[23] /* PLETH_SPO2_std */ <= 0.85550f) {
                                                    if (features[56] /* Feature_MBP_Delta_60s_min */ <= 0.53911f) {
                                                        if (features[17] /* Feature_MBP_Std_60s_mean */ <= -0.34767f) {
                                                            if (features[6] /* ETCO2_mean */ <= -0.69506f) {
                                                                return false; /* p_pos=0.000, tau=0.33 */
                                                            } else {
                                                                if (features[40] /* ART_DBP_min */ <= -0.69632f) {
                                                                    return true; /* p_pos=0.522, tau=0.33 */
                                                                } else {
                                                                    return false; /* p_pos=0.187, tau=0.33 */
                                                                }
                                                            }
                                                        } else {
                                                            if (features[78] /* ART_DBP_slope */ <= 2.77064f) {
                                                                if (features[4] /* PLETH_SPO2_mean */ <= 0.08958f) {
                                                                    return false; /* p_pos=0.000, tau=0.33 */
                                                                } else {
                                                                    return false; /* p_pos=0.099, tau=0.33 */
                                                                }
                                                            } else {
                                                                return true; /* p_pos=0.556, tau=0.33 */
                                                            }
                                                        }
                                                    } else {
                                                        return false; /* p_pos=0.000, tau=0.33 */
                                                    }
                                                } else {
                                                    return true; /* p_pos=0.750, tau=0.33 */
                                                }
                                            }
                                        } else {
                                            if (features[66] /* Feature_Pulse_Pressure_max */ <= 0.76174f) {
                                                return false; /* p_pos=0.176, tau=0.33 */
                                            } else {
                                                return true; /* p_pos=0.875, tau=0.33 */
                                            }
                                        }
                                    }
                                } else {
                                    if (features[74] /* Feature_MBP_Std_60s_max */ <= -0.46763f) {
                                        if (features[66] /* Feature_Pulse_Pressure_max */ <= 0.38606f) {
                                            if (features[39] /* ART_SBP_min */ <= -0.51997f) {
                                                if (features[56] /* Feature_MBP_Delta_60s_min */ <= 0.38491f) {
                                                    if (features[19] /* HR_std */ <= -0.11957f) {
                                                        if (features[9] /* Feature_Pulse_Pressure_mean */ <= -0.53444f) {
                                                            return true; /* p_pos=0.870, tau=0.33 */
                                                        } else {
                                                            return false; /* p_pos=0.000, tau=0.33 */
                                                        }
                                                    } else {
                                                        if (features[58] /* ART_SBP_max */ <= -0.51335f) {
                                                            return false; /* p_pos=0.200, tau=0.33 */
                                                        } else {
                                                            return false; /* p_pos=0.000, tau=0.33 */
                                                        }
                                                    }
                                                } else {
                                                    if (features[6] /* ETCO2_mean */ <= 0.46850f) {
                                                        if (features[43] /* RR_CO2_min */ <= 1.23712f) {
                                                            if (features[84] /* BT_slope */ <= -0.15919f) {
                                                                if (features[40] /* ART_DBP_min */ <= -1.63364f) {
                                                                    return true; /* p_pos=0.514, tau=0.33 */
                                                                } else {
                                                                    return false; /* p_pos=0.000, tau=0.33 */
                                                                }
                                                            } else {
                                                                if (features[8] /* BT_mean */ <= 0.30548f) {
                                                                    return false; /* p_pos=0.080, tau=0.33 */
                                                                } else {
                                                                    return false; /* p_pos=0.014, tau=0.33 */
                                                                }
                                                            }
                                                        } else {
                                                            if (features[62] /* RR_CO2_max */ <= 1.37605f) {
                                                                return true; /* p_pos=0.833, tau=0.33 */
                                                            } else {
                                                                return false; /* p_pos=0.000, tau=0.33 */
                                                            }
                                                        }
                                                    } else {
                                                        return false; /* p_pos=0.000, tau=0.33 */
                                                    }
                                                }
                                            } else {
                                                if (features[51] /* Feature_HR_Mean_60s_min */ <= -0.28789f) {
                                                    if (features[25] /* ETCO2_std */ <= -0.25399f) {
                                                        if (features[50] /* Feature_Rate_Pressure_Product_min */ <= 1.44597f) {
                                                            if (features[70] /* Feature_HR_Mean_60s_max */ <= 0.88515f) {
                                                                if (features[53] /* Feature_HR_Delta_60s_min */ <= 0.44884f) {
                                                                    return false; /* p_pos=0.002, tau=0.33 */
                                                                } else {
                                                                    return false; /* p_pos=0.017, tau=0.33 */
                                                                }
                                                            } else {
                                                                if (features[62] /* RR_CO2_max */ <= -1.13876f) {
                                                                    return true; /* p_pos=1.000, tau=0.33 */
                                                                } else {
                                                                    return false; /* p_pos=0.010, tau=0.33 */
                                                                }
                                                            }
                                                        } else {
                                                            return true; /* p_pos=0.500, tau=0.33 */
                                                        }
                                                    } else {
                                                        if (features[67] /* Feature_Shock_Index_max */ <= -0.85442f) {
                                                            if (features[65] /* BT_max */ <= 0.17485f) {
                                                                return true; /* p_pos=0.619, tau=0.33 */
                                                            } else {
                                                                if (features[40] /* ART_DBP_min */ <= 0.13072f) {
                                                                    return false; /* p_pos=0.286, tau=0.33 */
                                                                } else {
                                                                    return false; /* p_pos=0.000, tau=0.33 */
                                                                }
                                                            }
                                                        } else {
                                                            if (features[62] /* RR_CO2_max */ <= -0.63580f) {
                                                                if (features[6] /* ETCO2_mean */ <= 0.07052f) {
                                                                    return false; /* p_pos=0.022, tau=0.33 */
                                                                } else {
                                                                    return false; /* p_pos=0.213, tau=0.33 */
                                                                }
                                                            } else {
                                                                if (features[21] /* ART_DBP_std */ <= -0.00940f) {
                                                                    return false; /* p_pos=0.011, tau=0.33 */
                                                                } else {
                                                                    return false; /* p_pos=0.090, tau=0.33 */
                                                                }
                                                            }
                                                        }
                                                    }
                                                } else {
                                                    if (features[71] /* Feature_HR_Std_60s_max */ <= -0.87918f) {
                                                        return true; /* p_pos=0.643, tau=0.33 */
                                                    } else {
                                                        if (features[4] /* PLETH_SPO2_mean */ <= 0.19077f) {
                                                            if (features[50] /* Feature_Rate_Pressure_Product_min */ <= -0.67239f) {
                                                                return true; /* p_pos=0.400, tau=0.33 */
                                                            } else {
                                                                if (features[74] /* Feature_MBP_Std_60s_max */ <= -0.47114f) {
                                                                    return false; /* p_pos=0.025, tau=0.33 */
                                                                } else {
                                                                    return true; /* p_pos=0.333, tau=0.33 */
                                                                }
                                                            }
                                                        } else {
                                                            if (features[8] /* BT_mean */ <= 0.48328f) {
                                                                if (features[14] /* Feature_HR_Std_60s_mean */ <= -0.62613f) {
                                                                    return false; /* p_pos=0.159, tau=0.33 */
                                                                } else {
                                                                    return false; /* p_pos=0.043, tau=0.33 */
                                                                }
                                                            } else {
                                                                return true; /* p_pos=0.667, tau=0.33 */
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        } else {
                                            if (features[44] /* ETCO2_min */ <= 0.17929f) {
                                                if (features[66] /* Feature_Pulse_Pressure_max */ <= 1.10853f) {
                                                    if (features[41] /* ART_MBP_min */ <= -0.13661f) {
                                                        if (features[24] /* RR_CO2_std */ <= 1.83142f) {
                                                            return false; /* p_pos=0.000, tau=0.33 */
                                                        } else {
                                                            return false; /* p_pos=0.200, tau=0.33 */
                                                        }
                                                    } else {
                                                        if (features[9] /* Feature_Pulse_Pressure_mean */ <= -0.69794f) {
                                                            return true; /* p_pos=1.000, tau=0.33 */
                                                        } else {
                                                            if (features[74] /* Feature_MBP_Std_60s_max */ <= -0.49511f) {
                                                                if (features[7] /* FIO2_mean */ <= -0.59964f) {
                                                                    return true; /* p_pos=0.697, tau=0.33 */
                                                                } else {
                                                                    return false; /* p_pos=0.225, tau=0.33 */
                                                                }
                                                            } else {
                                                                if (features[21] /* ART_DBP_std */ <= -0.40957f) {
                                                                    return false; /* p_pos=0.200, tau=0.33 */
                                                                } else {
                                                                    return false; /* p_pos=0.000, tau=0.33 */
                                                                }
                                                            }
                                                        }
                                                    }
                                                } else {
                                                    if (features[8] /* BT_mean */ <= -0.55006f) {
                                                        return true; /* p_pos=0.455, tau=0.33 */
                                                    } else {
                                                        return false; /* p_pos=0.000, tau=0.33 */
                                                    }
                                                }
                                            } else {
                                                if (features[49] /* Feature_Modified_Shock_Index_min */ <= -0.02628f) {
                                                    if (features[46] /* BT_min */ <= 0.39527f) {
                                                        if (features[10] /* Feature_Shock_Index_mean */ <= -0.54605f) {
                                                            if (features[70] /* Feature_HR_Mean_60s_max */ <= -1.48241f) {
                                                                return false; /* p_pos=0.190, tau=0.33 */
                                                            } else {
                                                                return false; /* p_pos=0.000, tau=0.33 */
                                                            }
                                                        } else {
                                                            if (features[22] /* ART_MBP_std */ <= -0.53090f) {
                                                                return true; /* p_pos=0.875, tau=0.33 */
                                                            } else {
                                                                return false; /* p_pos=0.083, tau=0.33 */
                                                            }
                                                        }
                                                    } else {
                                                        if (features[34] /* Feature_HR_Delta_60s_std */ <= -0.43126f) {
                                                            return true; /* p_pos=0.625, tau=0.33 */
                                                        } else {
                                                            return false; /* p_pos=0.000, tau=0.33 */
                                                        }
                                                    }
                                                } else {
                                                    if (features[80] /* PLETH_SPO2_slope */ <= 1.85458f) {
                                                        if (features[47] /* Feature_Pulse_Pressure_min */ <= 2.29321f) {
                                                            return false; /* p_pos=0.000, tau=0.33 */
                                                        } else {
                                                            return false; /* p_pos=0.154, tau=0.33 */
                                                        }
                                                    } else {
                                                        return false; /* p_pos=0.286, tau=0.33 */
                                                    }
                                                }
                                            }
                                        }
                                    } else {
                                        if (features[51] /* Feature_HR_Mean_60s_min */ <= 1.20197f) {
                                            if (features[7] /* FIO2_mean */ <= -0.79780f) {
                                                if (features[46] /* BT_min */ <= 0.24932f) {
                                                    if (features[55] /* Feature_MBP_Std_60s_min */ <= 0.40514f) {
                                                        if (features[6] /* ETCO2_mean */ <= 0.59097f) {
                                                            if (features[42] /* PLETH_SPO2_min */ <= -0.70230f) {
                                                                return true; /* p_pos=0.917, tau=0.33 */
                                                            } else {
                                                                if (features[90] /* Feature_HR_Std_60s_slope */ <= -0.02990f) {
                                                                    return false; /* p_pos=0.000, tau=0.33 */
                                                                } else {
                                                                    return false; /* p_pos=0.250, tau=0.33 */
                                                                }
                                                            }
                                                        } else {
                                                            return true; /* p_pos=0.889, tau=0.33 */
                                                        }
                                                    } else {
                                                        return false; /* p_pos=0.000, tau=0.33 */
                                                    }
                                                } else {
                                                    if (features[86] /* Feature_Shock_Index_slope */ <= 0.57411f) {
                                                        return false; /* p_pos=0.000, tau=0.33 */
                                                    } else {
                                                        if (features[4] /* PLETH_SPO2_mean */ <= 0.23222f) {
                                                            return false; /* p_pos=0.000, tau=0.33 */
                                                        } else {
                                                            return true; /* p_pos=0.333, tau=0.33 */
                                                        }
                                                    }
                                                }
                                            } else {
                                                if (features[80] /* PLETH_SPO2_slope */ <= 0.24855f) {
                                                    if (features[7] /* FIO2_mean */ <= -0.63102f) {
                                                        if (features[23] /* PLETH_SPO2_std */ <= 0.96941f) {
                                                            if (features[51] /* Feature_HR_Mean_60s_min */ <= 0.92797f) {
                                                                if (features[40] /* ART_DBP_min */ <= -1.60607f) {
                                                                    return false; /* p_pos=0.074, tau=0.33 */
                                                                } else {
                                                                    return false; /* p_pos=0.008, tau=0.33 */
                                                                }
                                                            } else {
                                                                if (features[52] /* Feature_HR_Std_60s_min */ <= -0.00984f) {
                                                                    return false; /* p_pos=0.000, tau=0.33 */
                                                                } else {
                                                                    return false; /* p_pos=0.125, tau=0.33 */
                                                                }
                                                            }
                                                        } else {
                                                            if (features[33] /* Feature_HR_Std_60s_std */ <= 0.88770f) {
                                                                if (features[26] /* FIO2_std */ <= -0.37825f) {
                                                                    return false; /* p_pos=0.200, tau=0.33 */
                                                                } else {
                                                                    return false; /* p_pos=0.000, tau=0.33 */
                                                                }
                                                            } else {
                                                                return true; /* p_pos=1.000, tau=0.33 */
                                                            }
                                                        }
                                                    } else {
                                                        if (features[82] /* ETCO2_slope */ <= -2.00361f) {
                                                            if (features[0] /* HR_mean */ <= 1.20793f) {
                                                                if (features[64] /* FIO2_max */ <= 0.01265f) {
                                                                    return true; /* p_pos=0.538, tau=0.33 */
                                                                } else {
                                                                    return false; /* p_pos=0.052, tau=0.33 */
                                                                }
                                                            } else {
                                                                return true; /* p_pos=1.000, tau=0.33 */
                                                            }
                                                        } else {
                                                            if (features[83] /* FIO2_slope */ <= 0.15906f) {
                                                                if (features[45] /* FIO2_min */ <= -0.55663f) {
                                                                    return false; /* p_pos=0.089, tau=0.33 */
                                                                } else {
                                                                    return false; /* p_pos=0.028, tau=0.33 */
                                                                }
                                                            } else {
                                                                if (features[10] /* Feature_Shock_Index_mean */ <= -0.65786f) {
                                                                    return true; /* p_pos=0.448, tau=0.33 */
                                                                } else {
                                                                    return false; /* p_pos=0.072, tau=0.33 */
                                                                }
                                                            }
                                                        }
                                                    }
                                                } else {
                                                    if (features[8] /* BT_mean */ <= 0.30222f) {
                                                        if (features[6] /* ETCO2_mean */ <= 1.38525f) {
                                                            if (features[4] /* PLETH_SPO2_mean */ <= -0.15365f) {
                                                                if (features[52] /* Feature_HR_Std_60s_min */ <= 4.69679f) {
                                                                    return false; /* p_pos=0.001, tau=0.33 */
                                                                } else {
                                                                    return false; /* p_pos=0.118, tau=0.33 */
                                                                }
                                                            } else {
                                                                if (features[39] /* ART_SBP_min */ <= -1.72014f) {
                                                                    return false; /* p_pos=0.000, tau=0.33 */
                                                                } else {
                                                                    return false; /* p_pos=0.021, tau=0.33 */
                                                                }
                                                            }
                                                        } else {
                                                            if (features[45] /* FIO2_min */ <= 0.40616f) {
                                                                return false; /* p_pos=0.000, tau=0.33 */
                                                            } else {
                                                                if (features[17] /* Feature_MBP_Std_60s_mean */ <= 0.08567f) {
                                                                    return false; /* p_pos=0.000, tau=0.33 */
                                                                } else {
                                                                    return true; /* p_pos=0.467, tau=0.33 */
                                                                }
                                                            }
                                                        }
                                                    } else {
                                                        if (features[12] /* Feature_Rate_Pressure_Product_mean */ <= -0.06123f) {
                                                            if (features[4] /* PLETH_SPO2_mean */ <= -0.71507f) {
                                                                if (features[39] /* ART_SBP_min */ <= -0.31423f) {
                                                                    return false; /* p_pos=0.000, tau=0.33 */
                                                                } else {
                                                                    return false; /* p_pos=0.309, tau=0.33 */
                                                                }
                                                            } else {
                                                                if (features[73] /* Feature_MBP_Mean_60s_max */ <= 2.57899f) {
                                                                    return false; /* p_pos=0.013, tau=0.33 */
                                                                } else {
                                                                    return false; /* p_pos=0.214, tau=0.33 */
                                                                }
                                                            }
                                                        } else {
                                                            if (features[58] /* ART_SBP_max */ <= -0.39806f) {
                                                                return false; /* p_pos=0.150, tau=0.33 */
                                                            } else {
                                                                if (features[55] /* Feature_MBP_Std_60s_min */ <= -0.19015f) {
                                                                    return false; /* p_pos=0.043, tau=0.33 */
                                                                } else {
                                                                    return false; /* p_pos=0.000, tau=0.33 */
                                                                }
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        } else {
                                            if (features[14] /* Feature_HR_Std_60s_mean */ <= -0.89521f) {
                                                return true; /* p_pos=1.000, tau=0.33 */
                                            } else {
                                                if (features[36] /* Feature_MBP_Std_60s_std */ <= 4.08056f) {
                                                    if (features[73] /* Feature_MBP_Mean_60s_max */ <= 0.78944f) {
                                                        if (features[73] /* Feature_MBP_Mean_60s_max */ <= 0.61876f) {
                                                            if (features[42] /* PLETH_SPO2_min */ <= -0.70230f) {
                                                                if (features[63] /* ETCO2_max */ <= -0.03162f) {
                                                                    return false; /* p_pos=0.172, tau=0.33 */
                                                                } else {
                                                                    return false; /* p_pos=0.017, tau=0.33 */
                                                                }
                                                            } else {
                                                                if (features[4] /* PLETH_SPO2_mean */ <= 0.36084f) {
                                                                    return false; /* p_pos=0.026, tau=0.33 */
                                                                } else {
                                                                    return false; /* p_pos=0.308, tau=0.33 */
                                                                }
                                                            }
                                                        } else {
                                                            if (features[40] /* ART_DBP_min */ <= -1.90932f) {
                                                                return true; /* p_pos=1.000, tau=0.33 */
                                                            } else {
                                                                if (features[64] /* FIO2_max */ <= -0.83280f) {
                                                                    return true; /* p_pos=0.667, tau=0.33 */
                                                                } else {
                                                                    return false; /* p_pos=0.014, tau=0.33 */
                                                                }
                                                            }
                                                        }
                                                    } else {
                                                        if (features[71] /* Feature_HR_Std_60s_max */ <= 1.11836f) {
                                                            if (features[43] /* RR_CO2_min */ <= 2.54446f) {
                                                                return false; /* p_pos=0.000, tau=0.33 */
                                                            } else {
                                                                return false; /* p_pos=0.125, tau=0.33 */
                                                            }
                                                        } else {
                                                            return false; /* p_pos=0.130, tau=0.33 */
                                                        }
                                                    }
                                                } else {
                                                    return true; /* p_pos=0.667, tau=0.33 */
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        } else {
                            if (features[80] /* PLETH_SPO2_slope */ <= 0.24855f) {
                                if (features[3] /* ART_MBP_mean */ <= 0.93336f) {
                                    if (features[65] /* BT_max */ <= -0.41799f) {
                                        if (features[41] /* ART_MBP_min */ <= -0.79057f) {
                                            if (features[9] /* Feature_Pulse_Pressure_mean */ <= -2.46433f) {
                                                return true; /* p_pos=0.556, tau=0.33 */
                                            } else {
                                                if (features[18] /* Feature_MBP_Delta_60s_mean */ <= 9.37729f) {
                                                    return false; /* p_pos=0.000, tau=0.33 */
                                                } else {
                                                    return true; /* p_pos=0.400, tau=0.33 */
                                                }
                                            }
                                        } else {
                                            if (features[21] /* ART_DBP_std */ <= -0.30425f) {
                                                if (features[88] /* Feature_Rate_Pressure_Product_slope */ <= 0.13041f) {
                                                    return false; /* p_pos=0.000, tau=0.33 */
                                                } else {
                                                    return true; /* p_pos=0.500, tau=0.33 */
                                                }
                                            } else {
                                                if (features[23] /* PLETH_SPO2_std */ <= 0.68197f) {
                                                    if (features[9] /* Feature_Pulse_Pressure_mean */ <= 1.33620f) {
                                                        if (features[33] /* Feature_HR_Std_60s_std */ <= -0.31244f) {
                                                            return true; /* p_pos=0.750, tau=0.33 */
                                                        } else {
                                                            if (features[25] /* ETCO2_std */ <= -0.50299f) {
                                                                return true; /* p_pos=1.000, tau=0.33 */
                                                            } else {
                                                                if (features[88] /* Feature_Rate_Pressure_Product_slope */ <= 0.79878f) {
                                                                    return false; /* p_pos=0.015, tau=0.33 */
                                                                } else {
                                                                    return true; /* p_pos=0.333, tau=0.33 */
                                                                }
                                                            }
                                                        }
                                                    } else {
                                                        return true; /* p_pos=0.938, tau=0.33 */
                                                    }
                                                } else {
                                                    if (features[22] /* ART_MBP_std */ <= 0.64278f) {
                                                        if (features[45] /* FIO2_min */ <= 2.50678f) {
                                                            return true; /* p_pos=0.800, tau=0.33 */
                                                        } else {
                                                            return true; /* p_pos=1.000, tau=0.33 */
                                                        }
                                                    } else {
                                                        return true; /* p_pos=0.400, tau=0.33 */
                                                    }
                                                }
                                            }
                                        }
                                    } else {
                                        if (features[26] /* FIO2_std */ <= -0.33651f) {
                                            if (features[39] /* ART_SBP_min */ <= -2.13163f) {
                                                return true; /* p_pos=1.000, tau=0.33 */
                                            } else {
                                                if (features[42] /* PLETH_SPO2_min */ <= -0.96225f) {
                                                    if (features[69] /* Feature_Rate_Pressure_Product_max */ <= 2.98972f) {
                                                        if (features[57] /* HR_max */ <= -0.99463f) {
                                                            return true; /* p_pos=0.667, tau=0.33 */
                                                        } else {
                                                            if (features[73] /* Feature_MBP_Mean_60s_max */ <= -0.02714f) {
                                                                if (features[3] /* ART_MBP_mean */ <= -0.13612f) {
                                                                    return false; /* p_pos=0.022, tau=0.33 */
                                                                } else {
                                                                    return true; /* p_pos=0.333, tau=0.33 */
                                                                }
                                                            } else {
                                                                return false; /* p_pos=0.000, tau=0.33 */
                                                            }
                                                        }
                                                    } else {
                                                        return true; /* p_pos=1.000, tau=0.33 */
                                                    }
                                                } else {
                                                    if (features[6] /* ETCO2_mean */ <= -2.30487f) {
                                                        return true; /* p_pos=0.333, tau=0.33 */
                                                    } else {
                                                        if (features[79] /* ART_MBP_slope */ <= 0.54851f) {
                                                            if (features[9] /* Feature_Pulse_Pressure_mean */ <= -1.09309f) {
                                                                return false; /* p_pos=0.217, tau=0.33 */
                                                            } else {
                                                                if (features[82] /* ETCO2_slope */ <= -2.22831f) {
                                                                    return false; /* p_pos=0.182, tau=0.33 */
                                                                } else {
                                                                    return false; /* p_pos=0.007, tau=0.33 */
                                                                }
                                                            }
                                                        } else {
                                                            if (features[47] /* Feature_Pulse_Pressure_min */ <= -0.28931f) {
                                                                if (features[86] /* Feature_Shock_Index_slope */ <= -5.10050f) {
                                                                    return false; /* p_pos=0.200, tau=0.33 */
                                                                } else {
                                                                    return false; /* p_pos=0.000, tau=0.33 */
                                                                }
                                                            } else {
                                                                if (features[4] /* PLETH_SPO2_mean */ <= 0.32975f) {
                                                                    return true; /* p_pos=0.409, tau=0.33 */
                                                                } else {
                                                                    return false; /* p_pos=0.000, tau=0.33 */
                                                                }
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        } else {
                                            if (features[3] /* ART_MBP_mean */ <= 0.42482f) {
                                                if (features[46] /* BT_min */ <= 0.33040f) {
                                                    if (features[23] /* PLETH_SPO2_std */ <= -0.00857f) {
                                                        if (features[27] /* BT_std */ <= -0.27255f) {
                                                            return false; /* p_pos=0.111, tau=0.33 */
                                                        } else {
                                                            return true; /* p_pos=0.783, tau=0.33 */
                                                        }
                                                    } else {
                                                        if (features[62] /* RR_CO2_max */ <= 4.64530f) {
                                                            if (features[58] /* ART_SBP_max */ <= 2.23069f) {
                                                                if (features[18] /* Feature_MBP_Delta_60s_mean */ <= 2.88757f) {
                                                                    return false; /* p_pos=0.048, tau=0.33 */
                                                                } else {
                                                                    return true; /* p_pos=0.438, tau=0.33 */
                                                                }
                                                            } else {
                                                                return true; /* p_pos=0.692, tau=0.33 */
                                                            }
                                                        } else {
                                                            return true; /* p_pos=0.667, tau=0.33 */
                                                        }
                                                    }
                                                } else {
                                                    if (features[42] /* PLETH_SPO2_min */ <= -1.22221f) {
                                                        if (features[5] /* RR_CO2_mean */ <= -1.22503f) {
                                                            return true; /* p_pos=0.857, tau=0.33 */
                                                        } else {
                                                            if (features[10] /* Feature_Shock_Index_mean */ <= -0.31678f) {
                                                                return false; /* p_pos=0.200, tau=0.33 */
                                                            } else {
                                                                return false; /* p_pos=0.000, tau=0.33 */
                                                            }
                                                        }
                                                    } else {
                                                        if (features[83] /* FIO2_slope */ <= 0.02143f) {
                                                            return false; /* p_pos=0.000, tau=0.33 */
                                                        } else {
                                                            if (features[10] /* Feature_Shock_Index_mean */ <= -0.68560f) {
                                                                return true; /* p_pos=0.600, tau=0.33 */
                                                            } else {
                                                                if (features[4] /* PLETH_SPO2_mean */ <= -0.64679f) {
                                                                    return false; /* p_pos=0.267, tau=0.33 */
                                                                } else {
                                                                    return false; /* p_pos=0.008, tau=0.33 */
                                                                }
                                                            }
                                                        }
                                                    }
                                                }
                                            } else {
                                                if (features[74] /* Feature_MBP_Std_60s_max */ <= -0.37137f) {
                                                    if (features[27] /* BT_std */ <= -0.27547f) {
                                                        if (features[17] /* Feature_MBP_Std_60s_mean */ <= -0.13222f) {
                                                            if (features[60] /* ART_MBP_max */ <= -0.24175f) {
                                                                return true; /* p_pos=0.667, tau=0.33 */
                                                            } else {
                                                                return true; /* p_pos=1.000, tau=0.33 */
                                                            }
                                                        } else {
                                                            return false; /* p_pos=0.200, tau=0.33 */
                                                        }
                                                    } else {
                                                        if (features[66] /* Feature_Pulse_Pressure_max */ <= 0.14042f) {
                                                            return false; /* p_pos=0.000, tau=0.33 */
                                                        } else {
                                                            if (features[66] /* Feature_Pulse_Pressure_max */ <= 0.71839f) {
                                                                return true; /* p_pos=0.938, tau=0.33 */
                                                            } else {
                                                                return false; /* p_pos=0.125, tau=0.33 */
                                                            }
                                                        }
                                                    }
                                                } else {
                                                    if (features[93] /* Feature_MBP_Std_60s_slope */ <= 0.15336f) {
                                                        if (features[4] /* PLETH_SPO2_mean */ <= -1.40877f) {
                                                            return true; /* p_pos=0.600, tau=0.33 */
                                                        } else {
                                                            if (features[4] /* PLETH_SPO2_mean */ <= 0.32793f) {
                                                                if (features[69] /* Feature_Rate_Pressure_Product_max */ <= -0.28942f) {
                                                                    return false; /* p_pos=0.200, tau=0.33 */
                                                                } else {
                                                                    return false; /* p_pos=0.000, tau=0.33 */
                                                                }
                                                            } else {
                                                                if (features[11] /* Feature_Modified_Shock_Index_mean */ <= -0.03599f) {
                                                                    return false; /* p_pos=0.000, tau=0.33 */
                                                                } else {
                                                                    return true; /* p_pos=0.500, tau=0.33 */
                                                                }
                                                            }
                                                        }
                                                    } else {
                                                        if (features[78] /* ART_DBP_slope */ <= 1.50518f) {
                                                            if (features[75] /* Feature_MBP_Delta_60s_max */ <= 0.75558f) {
                                                                if (features[90] /* Feature_HR_Std_60s_slope */ <= 0.31375f) {
                                                                    return true; /* p_pos=0.524, tau=0.33 */
                                                                } else {
                                                                    return false; /* p_pos=0.050, tau=0.33 */
                                                                }
                                                            } else {
                                                                return false; /* p_pos=0.000, tau=0.33 */
                                                            }
                                                        } else {
                                                            return true; /* p_pos=0.800, tau=0.33 */
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                } else {
                                    if (features[27] /* BT_std */ <= -0.26994f) {
                                        if (features[5] /* RR_CO2_mean */ <= -0.64331f) {
                                            if (features[57] /* HR_max */ <= 0.69152f) {
                                                return false; /* p_pos=0.000, tau=0.33 */
                                            } else {
                                                return true; /* p_pos=0.524, tau=0.33 */
                                            }
                                        } else {
                                            if (features[64] /* FIO2_max */ <= 1.79253f) {
                                                if (features[63] /* ETCO2_max */ <= -0.82262f) {
                                                    return true; /* p_pos=0.600, tau=0.33 */
                                                } else {
                                                    return false; /* p_pos=0.000, tau=0.33 */
                                                }
                                            } else {
                                                if (features[46] /* BT_min */ <= 0.36284f) {
                                                    if (features[9] /* Feature_Pulse_Pressure_mean */ <= 1.95715f) {
                                                        if (features[30] /* Feature_Modified_Shock_Index_std */ <= 0.62508f) {
                                                            if (features[48] /* Feature_Shock_Index_min */ <= -0.80716f) {
                                                                return true; /* p_pos=1.000, tau=0.33 */
                                                            } else {
                                                                if (features[34] /* Feature_HR_Delta_60s_std */ <= -0.46128f) {
                                                                    return false; /* p_pos=0.000, tau=0.33 */
                                                                } else {
                                                                    return true; /* p_pos=0.900, tau=0.33 */
                                                                }
                                                            }
                                                        } else {
                                                            return false; /* p_pos=0.167, tau=0.33 */
                                                        }
                                                    } else {
                                                        return false; /* p_pos=0.300, tau=0.33 */
                                                    }
                                                } else {
                                                    if (features[52] /* Feature_HR_Std_60s_min */ <= -0.18580f) {
                                                        return true; /* p_pos=0.625, tau=0.33 */
                                                    } else {
                                                        if (features[10] /* Feature_Shock_Index_mean */ <= -0.24851f) {
                                                            return false; /* p_pos=0.000, tau=0.33 */
                                                        } else {
                                                            return false; /* p_pos=0.200, tau=0.33 */
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    } else {
                                        if (features[2] /* ART_DBP_mean */ <= 1.17544f) {
                                            return false; /* p_pos=0.000, tau=0.33 */
                                        } else {
                                            if (features[54] /* Feature_MBP_Mean_60s_min */ <= 1.04089f) {
                                                if (features[56] /* Feature_MBP_Delta_60s_min */ <= -0.24156f) {
                                                    return false; /* p_pos=0.000, tau=0.33 */
                                                } else {
                                                    return true; /* p_pos=1.000, tau=0.33 */
                                                }
                                            } else {
                                                if (features[65] /* BT_max */ <= 0.21602f) {
                                                    return true; /* p_pos=0.400, tau=0.33 */
                                                } else {
                                                    return false; /* p_pos=0.000, tau=0.33 */
                                                }
                                            }
                                        }
                                    }
                                }
                            } else {
                                if (features[67] /* Feature_Shock_Index_max */ <= -0.02449f) {
                                    if (features[44] /* ETCO2_min */ <= 0.58100f) {
                                        if (features[5] /* RR_CO2_mean */ <= 1.37431f) {
                                            if (features[58] /* ART_SBP_max */ <= -1.74702f) {
                                                if (features[47] /* Feature_Pulse_Pressure_min */ <= -1.32793f) {
                                                    return false; /* p_pos=0.118, tau=0.33 */
                                                } else {
                                                    return true; /* p_pos=1.000, tau=0.33 */
                                                }
                                            } else {
                                                if (features[59] /* ART_DBP_max */ <= 1.09545f) {
                                                    if (features[18] /* Feature_MBP_Delta_60s_mean */ <= -0.06832f) {
                                                        if (features[43] /* RR_CO2_min */ <= 0.71419f) {
                                                            if (features[48] /* Feature_Shock_Index_min */ <= -0.54337f) {
                                                                if (features[10] /* Feature_Shock_Index_mean */ <= -0.77754f) {
                                                                    return false; /* p_pos=0.000, tau=0.33 */
                                                                } else {
                                                                    return true; /* p_pos=0.417, tau=0.33 */
                                                                }
                                                            } else {
                                                                if (features[85] /* Feature_Pulse_Pressure_slope */ <= -1.33121f) {
                                                                    return false; /* p_pos=0.200, tau=0.33 */
                                                                } else {
                                                                    return false; /* p_pos=0.000, tau=0.33 */
                                                                }
                                                            }
                                                        } else {
                                                            return true; /* p_pos=0.353, tau=0.33 */
                                                        }
                                                    } else {
                                                        return false; /* p_pos=0.000, tau=0.33 */
                                                    }
                                                } else {
                                                    if (features[2] /* ART_DBP_mean */ <= 1.31204f) {
                                                        if (features[11] /* Feature_Modified_Shock_Index_mean */ <= -0.69870f) {
                                                            return false; /* p_pos=0.200, tau=0.33 */
                                                        } else {
                                                            return false; /* p_pos=0.000, tau=0.33 */
                                                        }
                                                    } else {
                                                        return true; /* p_pos=0.667, tau=0.33 */
                                                    }
                                                }
                                            }
                                        } else {
                                            if (features[55] /* Feature_MBP_Std_60s_min */ <= 0.04018f) {
                                                return false; /* p_pos=0.000, tau=0.33 */
                                            } else {
                                                return true; /* p_pos=0.833, tau=0.33 */
                                            }
                                        }
                                    } else {
                                        return false; /* p_pos=0.000, tau=0.33 */
                                    }
                                } else {
                                    if (features[86] /* Feature_Shock_Index_slope */ <= 0.74314f) {
                                        if (features[27] /* BT_std */ <= 0.05916f) {
                                            if (features[7] /* FIO2_mean */ <= 2.69873f) {
                                                if (features[10] /* Feature_Shock_Index_mean */ <= -0.17437f) {
                                                    if (features[55] /* Feature_MBP_Std_60s_min */ <= 0.25200f) {
                                                        return false; /* p_pos=0.000, tau=0.33 */
                                                    } else {
                                                        return false; /* p_pos=0.286, tau=0.33 */
                                                    }
                                                } else {
                                                    return false; /* p_pos=0.000, tau=0.33 */
                                                }
                                            } else {
                                                return false; /* p_pos=0.286, tau=0.33 */
                                            }
                                        } else {
                                            return false; /* p_pos=0.125, tau=0.33 */
                                        }
                                    } else {
                                        if (features[65] /* BT_max */ <= 0.20778f) {
                                            if (features[38] /* HR_min */ <= -0.23415f) {
                                                if (features[24] /* RR_CO2_std */ <= 3.97700f) {
                                                    return false; /* p_pos=0.000, tau=0.33 */
                                                } else {
                                                    return false; /* p_pos=0.200, tau=0.33 */
                                                }
                                            } else {
                                                if (features[31] /* Feature_Rate_Pressure_Product_std */ <= 1.55325f) {
                                                    if (features[25] /* ETCO2_std */ <= -0.39007f) {
                                                        return true; /* p_pos=0.714, tau=0.33 */
                                                    } else {
                                                        return false; /* p_pos=0.000, tau=0.33 */
                                                    }
                                                } else {
                                                    return true; /* p_pos=0.875, tau=0.33 */
                                                }
                                            }
                                        } else {
                                            return false; /* p_pos=0.000, tau=0.33 */
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            } else {
                if (features[84] /* BT_slope */ <= -0.52041f) {
                    if (features[83] /* FIO2_slope */ <= 0.09025f) {
                        if (features[84] /* BT_slope */ <= -5.38047f) {
                            if (features[11] /* Feature_Modified_Shock_Index_mean */ <= -0.95319f) {
                                if (features[26] /* FIO2_std */ <= -0.32892f) {
                                    return true; /* p_pos=1.000, tau=0.33 */
                                } else {
                                    return false; /* p_pos=0.267, tau=0.33 */
                                }
                            } else {
                                if (features[55] /* Feature_MBP_Std_60s_min */ <= -0.04946f) {
                                    if (features[44] /* ETCO2_min */ <= 0.04539f) {
                                        if (features[10] /* Feature_Shock_Index_mean */ <= -0.43365f) {
                                            return true; /* p_pos=0.875, tau=0.33 */
                                        } else {
                                            if (features[67] /* Feature_Shock_Index_max */ <= 0.17504f) {
                                                return false; /* p_pos=0.000, tau=0.33 */
                                            } else {
                                                return true; /* p_pos=0.400, tau=0.33 */
                                            }
                                        }
                                    } else {
                                        if (features[64] /* FIO2_max */ <= -0.74380f) {
                                            return false; /* p_pos=0.000, tau=0.33 */
                                        } else {
                                            if (features[25] /* ETCO2_std */ <= -0.36997f) {
                                                if (features[33] /* Feature_HR_Std_60s_std */ <= -0.60512f) {
                                                    return false; /* p_pos=0.000, tau=0.33 */
                                                } else {
                                                    return false; /* p_pos=0.261, tau=0.33 */
                                                }
                                            } else {
                                                return false; /* p_pos=0.000, tau=0.33 */
                                            }
                                        }
                                    }
                                } else {
                                    if (features[84] /* BT_slope */ <= -5.74169f) {
                                        if (features[62] /* RR_CO2_max */ <= 0.62160f) {
                                            return false; /* p_pos=0.000, tau=0.33 */
                                        } else {
                                            return true; /* p_pos=0.600, tau=0.33 */
                                        }
                                    } else {
                                        if (features[65] /* BT_max */ <= 0.35600f) {
                                            if (features[48] /* Feature_Shock_Index_min */ <= 0.12238f) {
                                                if (features[37] /* Feature_MBP_Delta_60s_std */ <= -0.00202f) {
                                                    if (features[65] /* BT_max */ <= 0.32306f) {
                                                        if (features[37] /* Feature_MBP_Delta_60s_std */ <= -0.18706f) {
                                                            if (features[11] /* Feature_Modified_Shock_Index_mean */ <= -0.49808f) {
                                                                return true; /* p_pos=0.800, tau=0.33 */
                                                            } else {
                                                                return true; /* p_pos=1.000, tau=0.33 */
                                                            }
                                                        } else {
                                                            return false; /* p_pos=0.000, tau=0.33 */
                                                        }
                                                    } else {
                                                        if (features[2] /* ART_DBP_mean */ <= 1.47892f) {
                                                            return false; /* p_pos=0.000, tau=0.33 */
                                                        } else {
                                                            return true; /* p_pos=0.778, tau=0.33 */
                                                        }
                                                    }
                                                } else {
                                                    return false; /* p_pos=0.000, tau=0.33 */
                                                }
                                            } else {
                                                if (features[25] /* ETCO2_std */ <= -0.40624f) {
                                                    return false; /* p_pos=0.286, tau=0.33 */
                                                } else {
                                                    return false; /* p_pos=0.000, tau=0.33 */
                                                }
                                            }
                                        } else {
                                            return true; /* p_pos=0.913, tau=0.33 */
                                        }
                                    }
                                }
                            }
                        } else {
                            if (features[1] /* ART_SBP_mean */ <= 0.80744f) {
                                if (features[68] /* Feature_Modified_Shock_Index_max */ <= 0.22852f) {
                                    if (features[5] /* RR_CO2_mean */ <= -1.90489f) {
                                        return true; /* p_pos=0.667, tau=0.33 */
                                    } else {
                                        if (features[9] /* Feature_Pulse_Pressure_mean */ <= -1.17320f) {
                                            if (features[41] /* ART_MBP_min */ <= 0.14365f) {
                                                if (features[72] /* Feature_HR_Delta_60s_max */ <= -0.54084f) {
                                                    if (features[32] /* Feature_HR_Mean_60s_std */ <= -0.63723f) {
                                                        if (features[13] /* Feature_HR_Mean_60s_mean */ <= -0.92884f) {
                                                            return false; /* p_pos=0.200, tau=0.33 */
                                                        } else {
                                                            return false; /* p_pos=0.000, tau=0.33 */
                                                        }
                                                    } else {
                                                        if (features[65] /* BT_max */ <= 0.20778f) {
                                                            return false; /* p_pos=0.000, tau=0.33 */
                                                        } else {
                                                            if (features[6] /* ETCO2_mean */ <= 0.84839f) {
                                                                if (features[14] /* Feature_HR_Std_60s_mean */ <= -0.49111f) {
                                                                    return true; /* p_pos=0.526, tau=0.33 */
                                                                } else {
                                                                    return true; /* p_pos=1.000, tau=0.33 */
                                                                }
                                                            } else {
                                                                return false; /* p_pos=0.000, tau=0.33 */
                                                            }
                                                        }
                                                    }
                                                } else {
                                                    if (features[91] /* Feature_HR_Delta_60s_slope */ <= -0.64536f) {
                                                        return true; /* p_pos=0.400, tau=0.33 */
                                                    } else {
                                                        if (features[15] /* Feature_HR_Delta_60s_mean */ <= 1.27459f) {
                                                            return false; /* p_pos=0.000, tau=0.33 */
                                                        } else {
                                                            return false; /* p_pos=0.143, tau=0.33 */
                                                        }
                                                    }
                                                }
                                            } else {
                                                return true; /* p_pos=0.929, tau=0.33 */
                                            }
                                        } else {
                                            if (features[66] /* Feature_Pulse_Pressure_max */ <= -0.36531f) {
                                                if (features[65] /* BT_max */ <= 0.15838f) {
                                                    return false; /* p_pos=0.000, tau=0.33 */
                                                } else {
                                                    if (features[2] /* ART_DBP_mean */ <= 0.47500f) {
                                                        if (features[54] /* Feature_MBP_Mean_60s_min */ <= -0.10755f) {
                                                            return false; /* p_pos=0.000, tau=0.33 */
                                                        } else {
                                                            if (features[26] /* FIO2_std */ <= -0.36893f) {
                                                                if (features[66] /* Feature_Pulse_Pressure_max */ <= -0.82770f) {
                                                                    return true; /* p_pos=0.600, tau=0.33 */
                                                                } else {
                                                                    return false; /* p_pos=0.007, tau=0.33 */
                                                                }
                                                            } else {
                                                                if (features[63] /* ETCO2_max */ <= -0.82262f) {
                                                                    return true; /* p_pos=0.700, tau=0.33 */
                                                                } else {
                                                                    return false; /* p_pos=0.117, tau=0.33 */
                                                                }
                                                            }
                                                        }
                                                    } else {
                                                        if (features[30] /* Feature_Modified_Shock_Index_std */ <= -0.58004f) {
                                                            return false; /* p_pos=0.200, tau=0.33 */
                                                        } else {
                                                            return false; /* p_pos=0.000, tau=0.33 */
                                                        }
                                                    }
                                                }
                                            } else {
                                                if (features[18] /* Feature_MBP_Delta_60s_mean */ <= -0.31837f) {
                                                    if (features[43] /* RR_CO2_min */ <= 1.23712f) {
                                                        if (features[31] /* Feature_Rate_Pressure_Product_std */ <= -0.56235f) {
                                                            return false; /* p_pos=0.083, tau=0.33 */
                                                        } else {
                                                            return false; /* p_pos=0.000, tau=0.33 */
                                                        }
                                                    } else {
                                                        return false; /* p_pos=0.250, tau=0.33 */
                                                    }
                                                } else {
                                                    if (features[62] /* RR_CO2_max */ <= 0.62160f) {
                                                        if (features[94] /* Feature_MBP_Delta_60s_slope */ <= 0.04988f) {
                                                            if (features[17] /* Feature_MBP_Std_60s_mean */ <= -0.21165f) {
                                                                if (features[83] /* FIO2_slope */ <= -0.66669f) {
                                                                    return false; /* p_pos=0.300, tau=0.33 */
                                                                } else {
                                                                    return false; /* p_pos=0.053, tau=0.33 */
                                                                }
                                                            } else {
                                                                if (features[52] /* Feature_HR_Std_60s_min */ <= 0.08576f) {
                                                                    return false; /* p_pos=0.000, tau=0.33 */
                                                                } else {
                                                                    return false; /* p_pos=0.040, tau=0.33 */
                                                                }
                                                            }
                                                        } else {
                                                            if (features[3] /* ART_MBP_mean */ <= 0.27542f) {
                                                                if (features[9] /* Feature_Pulse_Pressure_mean */ <= -0.39923f) {
                                                                    return false; /* p_pos=0.279, tau=0.33 */
                                                                } else {
                                                                    return false; /* p_pos=0.054, tau=0.33 */
                                                                }
                                                            } else {
                                                                if (features[65] /* BT_max */ <= 0.22425f) {
                                                                    return false; /* p_pos=0.087, tau=0.33 */
                                                                } else {
                                                                    return false; /* p_pos=0.289, tau=0.33 */
                                                                }
                                                            }
                                                        }
                                                    } else {
                                                        if (features[65] /* BT_max */ <= 0.15838f) {
                                                            if (features[31] /* Feature_Rate_Pressure_Product_std */ <= 0.03237f) {
                                                                return false; /* p_pos=0.000, tau=0.33 */
                                                            } else {
                                                                return false; /* p_pos=0.200, tau=0.33 */
                                                            }
                                                        } else {
                                                            if (features[19] /* HR_std */ <= 0.56103f) {
                                                                if (features[6] /* ETCO2_mean */ <= 1.23854f) {
                                                                    return false; /* p_pos=0.149, tau=0.33 */
                                                                } else {
                                                                    return true; /* p_pos=0.619, tau=0.33 */
                                                                }
                                                            } else {
                                                                return true; /* p_pos=1.000, tau=0.33 */
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                } else {
                                    if (features[64] /* FIO2_max */ <= -0.03185f) {
                                        if (features[7] /* FIO2_mean */ <= -0.65640f) {
                                            if (features[8] /* BT_mean */ <= 0.37963f) {
                                                return false; /* p_pos=0.000, tau=0.33 */
                                            } else {
                                                return false; /* p_pos=0.200, tau=0.33 */
                                            }
                                        } else {
                                            if (features[54] /* Feature_MBP_Mean_60s_min */ <= -0.37423f) {
                                                if (features[30] /* Feature_Modified_Shock_Index_std */ <= 2.30318f) {
                                                    return false; /* p_pos=0.000, tau=0.33 */
                                                } else {
                                                    return false; /* p_pos=0.154, tau=0.33 */
                                                }
                                            } else {
                                                if (features[33] /* Feature_HR_Std_60s_std */ <= 0.03775f) {
                                                    if (features[22] /* ART_MBP_std */ <= 1.49611f) {
                                                        if (features[20] /* ART_SBP_std */ <= 0.06184f) {
                                                            return false; /* p_pos=0.200, tau=0.33 */
                                                        } else {
                                                            return true; /* p_pos=0.818, tau=0.33 */
                                                        }
                                                    } else {
                                                        return false; /* p_pos=0.000, tau=0.33 */
                                                    }
                                                } else {
                                                    if (features[7] /* FIO2_mean */ <= -0.57815f) {
                                                        return false; /* p_pos=0.143, tau=0.33 */
                                                    } else {
                                                        return false; /* p_pos=0.000, tau=0.33 */
                                                    }
                                                }
                                            }
                                        }
                                    } else {
                                        return false; /* p_pos=0.000, tau=0.33 */
                                    }
                                }
                            } else {
                                if (features[64] /* FIO2_max */ <= 1.41430f) {
                                    if (features[66] /* Feature_Pulse_Pressure_max */ <= 0.27046f) {
                                        if (features[43] /* RR_CO2_min */ <= 0.19126f) {
                                            if (features[87] /* Feature_Modified_Shock_Index_slope */ <= -0.18215f) {
                                                return true; /* p_pos=0.429, tau=0.33 */
                                            } else {
                                                if (features[53] /* Feature_HR_Delta_60s_min */ <= 0.13894f) {
                                                    return true; /* p_pos=0.375, tau=0.33 */
                                                } else {
                                                    if (features[77] /* ART_SBP_slope */ <= 0.86491f) {
                                                        return false; /* p_pos=0.000, tau=0.33 */
                                                    } else {
                                                        return false; /* p_pos=0.200, tau=0.33 */
                                                    }
                                                }
                                            }
                                        } else {
                                            return false; /* p_pos=0.000, tau=0.33 */
                                        }
                                    } else {
                                        if (features[30] /* Feature_Modified_Shock_Index_std */ <= -0.09378f) {
                                            if (features[6] /* ETCO2_mean */ <= -0.05717f) {
                                                if (features[25] /* ETCO2_std */ <= -0.43958f) {
                                                    if (features[19] /* HR_std */ <= -0.68805f) {
                                                        return false; /* p_pos=0.000, tau=0.33 */
                                                    } else {
                                                        return true; /* p_pos=0.438, tau=0.33 */
                                                    }
                                                } else {
                                                    return false; /* p_pos=0.000, tau=0.33 */
                                                }
                                            } else {
                                                if (features[12] /* Feature_Rate_Pressure_Product_mean */ <= 0.91070f) {
                                                    if (features[45] /* FIO2_min */ <= -0.03147f) {
                                                        if (features[68] /* Feature_Modified_Shock_Index_max */ <= -0.86598f) {
                                                            return false; /* p_pos=0.062, tau=0.33 */
                                                        } else {
                                                            if (features[53] /* Feature_HR_Delta_60s_min */ <= 0.81038f) {
                                                                if (features[75] /* Feature_MBP_Delta_60s_max */ <= -0.10778f) {
                                                                    return true; /* p_pos=0.886, tau=0.33 */
                                                                } else {
                                                                    return false; /* p_pos=0.286, tau=0.33 */
                                                                }
                                                            } else {
                                                                return false; /* p_pos=0.000, tau=0.33 */
                                                            }
                                                        }
                                                    } else {
                                                        return false; /* p_pos=0.045, tau=0.33 */
                                                    }
                                                } else {
                                                    if (features[11] /* Feature_Modified_Shock_Index_mean */ <= 0.43830f) {
                                                        if (features[6] /* ETCO2_mean */ <= -0.03033f) {
                                                            return true; /* p_pos=0.545, tau=0.33 */
                                                        } else {
                                                            if (features[79] /* ART_MBP_slope */ <= 0.73058f) {
                                                                if (features[46] /* BT_min */ <= -0.13179f) {
                                                                    return false; /* p_pos=0.000, tau=0.33 */
                                                                } else {
                                                                    return false; /* p_pos=0.111, tau=0.33 */
                                                                }
                                                            } else {
                                                                return true; /* p_pos=0.333, tau=0.33 */
                                                            }
                                                        }
                                                    } else {
                                                        return true; /* p_pos=1.000, tau=0.33 */
                                                    }
                                                }
                                            }
                                        } else {
                                            if (features[76] /* HR_slope */ <= -1.16833f) {
                                                return false; /* p_pos=0.200, tau=0.33 */
                                            } else {
                                                return false; /* p_pos=0.000, tau=0.33 */
                                            }
                                        }
                                    }
                                } else {
                                    if (features[9] /* Feature_Pulse_Pressure_mean */ <= 0.30082f) {
                                        return true; /* p_pos=1.000, tau=0.33 */
                                    } else {
                                        if (features[7] /* FIO2_mean */ <= 2.53400f) {
                                            if (features[68] /* Feature_Modified_Shock_Index_max */ <= 0.36495f) {
                                                if (features[13] /* Feature_HR_Mean_60s_mean */ <= 1.40768f) {
                                                    if (features[37] /* Feature_MBP_Delta_60s_std */ <= -0.29309f) {
                                                        return false; /* p_pos=0.000, tau=0.33 */
                                                    } else {
                                                        if (features[11] /* Feature_Modified_Shock_Index_mean */ <= -0.74176f) {
                                                            return true; /* p_pos=0.800, tau=0.33 */
                                                        } else {
                                                            if (features[49] /* Feature_Modified_Shock_Index_min */ <= -0.33130f) {
                                                                return false; /* p_pos=0.000, tau=0.33 */
                                                            } else {
                                                                return false; /* p_pos=0.250, tau=0.33 */
                                                            }
                                                        }
                                                    }
                                                } else {
                                                    return true; /* p_pos=0.636, tau=0.33 */
                                                }
                                            } else {
                                                return true; /* p_pos=1.000, tau=0.33 */
                                            }
                                        } else {
                                            return true; /* p_pos=1.000, tau=0.33 */
                                        }
                                    }
                                }
                            }
                        }
                    } else {
                        if (features[48] /* Feature_Shock_Index_min */ <= 0.32258f) {
                            if (features[87] /* Feature_Modified_Shock_Index_slope */ <= 0.17842f) {
                                if (features[74] /* Feature_MBP_Std_60s_max */ <= 1.89027f) {
                                    if (features[19] /* HR_std */ <= -0.41122f) {
                                        if (features[46] /* BT_min */ <= -0.24531f) {
                                            if (features[91] /* Feature_HR_Delta_60s_slope */ <= -0.05640f) {
                                                return true; /* p_pos=0.917, tau=0.33 */
                                            } else {
                                                if (features[2] /* ART_DBP_mean */ <= -0.16078f) {
                                                    return false; /* p_pos=0.077, tau=0.33 */
                                                } else {
                                                    return true; /* p_pos=0.667, tau=0.33 */
                                                }
                                            }
                                        } else {
                                            if (features[15] /* Feature_HR_Delta_60s_mean */ <= -0.17160f) {
                                                return false; /* p_pos=0.000, tau=0.33 */
                                            } else {
                                                return false; /* p_pos=0.312, tau=0.33 */
                                            }
                                        }
                                    } else {
                                        if (features[65] /* BT_max */ <= 0.38893f) {
                                            if (features[54] /* Feature_MBP_Mean_60s_min */ <= 1.16503f) {
                                                if (features[26] /* FIO2_std */ <= 0.47647f) {
                                                    if (features[3] /* ART_MBP_mean */ <= 1.50091f) {
                                                        if (features[13] /* Feature_HR_Mean_60s_mean */ <= 0.54332f) {
                                                            if (features[63] /* ETCO2_max */ <= 0.95712f) {
                                                                if (features[3] /* ART_MBP_mean */ <= 0.68705f) {
                                                                    return true; /* p_pos=0.708, tau=0.33 */
                                                                } else {
                                                                    return false; /* p_pos=0.222, tau=0.33 */
                                                                }
                                                            } else {
                                                                return true; /* p_pos=1.000, tau=0.33 */
                                                            }
                                                        } else {
                                                            return true; /* p_pos=1.000, tau=0.33 */
                                                        }
                                                    } else {
                                                        return false; /* p_pos=0.000, tau=0.33 */
                                                    }
                                                } else {
                                                    return false; /* p_pos=0.227, tau=0.33 */
                                                }
                                            } else {
                                                return true; /* p_pos=0.952, tau=0.33 */
                                            }
                                        } else {
                                            return false; /* p_pos=0.000, tau=0.33 */
                                        }
                                    }
                                } else {
                                    return false; /* p_pos=0.000, tau=0.33 */
                                }
                            } else {
                                if (features[47] /* Feature_Pulse_Pressure_min */ <= -1.46829f) {
                                    return true; /* p_pos=0.875, tau=0.33 */
                                } else {
                                    if (features[12] /* Feature_Rate_Pressure_Product_mean */ <= 1.13474f) {
                                        if (features[18] /* Feature_MBP_Delta_60s_mean */ <= -0.00213f) {
                                            return false; /* p_pos=0.000, tau=0.33 */
                                        } else {
                                            return false; /* p_pos=0.300, tau=0.33 */
                                        }
                                    } else {
                                        return true; /* p_pos=0.583, tau=0.33 */
                                    }
                                }
                            }
                        } else {
                            if (features[50] /* Feature_Rate_Pressure_Product_min */ <= 0.32708f) {
                                return false; /* p_pos=0.000, tau=0.33 */
                            } else {
                                if (features[44] /* ETCO2_min */ <= -1.42755f) {
                                    return true; /* p_pos=0.833, tau=0.33 */
                                } else {
                                    if (features[63] /* ETCO2_max */ <= 0.95712f) {
                                        if (features[68] /* Feature_Modified_Shock_Index_max */ <= 0.62371f) {
                                            return false; /* p_pos=0.000, tau=0.33 */
                                        } else {
                                            return false; /* p_pos=0.200, tau=0.33 */
                                        }
                                    } else {
                                        return true; /* p_pos=0.600, tau=0.33 */
                                    }
                                }
                            }
                        }
                    }
                } else {
                    if (features[26] /* FIO2_std */ <= -0.31902f) {
                        if (features[65] /* BT_max */ <= -0.10510f) {
                            if (features[7] /* FIO2_mean */ <= -0.21184f) {
                                if (features[67] /* Feature_Shock_Index_max */ <= -0.43041f) {
                                    if (features[67] /* Feature_Shock_Index_max */ <= -0.43130f) {
                                        if (features[45] /* FIO2_min */ <= -0.49828f) {
                                            if (features[21] /* ART_DBP_std */ <= 0.72516f) {
                                                if (features[13] /* Feature_HR_Mean_60s_mean */ <= -0.40673f) {
                                                    if (features[19] /* HR_std */ <= 0.85766f) {
                                                        if (features[9] /* Feature_Pulse_Pressure_mean */ <= 0.30568f) {
                                                            if (features[11] /* Feature_Modified_Shock_Index_mean */ <= -0.21730f) {
                                                                if (features[59] /* ART_DBP_max */ <= 1.01237f) {
                                                                    return false; /* p_pos=0.000, tau=0.33 */
                                                                } else {
                                                                    return false; /* p_pos=0.100, tau=0.33 */
                                                                }
                                                            } else {
                                                                if (features[93] /* Feature_MBP_Std_60s_slope */ <= -0.02157f) {
                                                                    return true; /* p_pos=0.571, tau=0.33 */
                                                                } else {
                                                                    return false; /* p_pos=0.000, tau=0.33 */
                                                                }
                                                            }
                                                        } else {
                                                            if (features[51] /* Feature_HR_Mean_60s_min */ <= -0.71606f) {
                                                                if (features[65] /* BT_max */ <= -1.06024f) {
                                                                    return false; /* p_pos=0.090, tau=0.33 */
                                                                } else {
                                                                    return false; /* p_pos=0.000, tau=0.33 */
                                                                }
                                                            } else {
                                                                if (features[68] /* Feature_Modified_Shock_Index_max */ <= -0.63473f) {
                                                                    return true; /* p_pos=0.556, tau=0.33 */
                                                                } else {
                                                                    return false; /* p_pos=0.072, tau=0.33 */
                                                                }
                                                            }
                                                        }
                                                    } else {
                                                        return true; /* p_pos=1.000, tau=0.33 */
                                                    }
                                                } else {
                                                    if (features[88] /* Feature_Rate_Pressure_Product_slope */ <= 0.90226f) {
                                                        return false; /* p_pos=0.000, tau=0.33 */
                                                    } else {
                                                        if (features[47] /* Feature_Pulse_Pressure_min */ <= 1.33880f) {
                                                            return false; /* p_pos=0.000, tau=0.33 */
                                                        } else {
                                                            return true; /* p_pos=0.400, tau=0.33 */
                                                        }
                                                    }
                                                }
                                            } else {
                                                if (features[68] /* Feature_Modified_Shock_Index_max */ <= -0.87356f) {
                                                    return true; /* p_pos=1.000, tau=0.33 */
                                                } else {
                                                    if (features[66] /* Feature_Pulse_Pressure_max */ <= 0.41496f) {
                                                        return false; /* p_pos=0.000, tau=0.33 */
                                                    } else {
                                                        if (features[40] /* ART_DBP_min */ <= -0.83416f) {
                                                            return true; /* p_pos=1.000, tau=0.33 */
                                                        } else {
                                                            if (features[22] /* ART_MBP_std */ <= 0.24875f) {
                                                                return true; /* p_pos=0.714, tau=0.33 */
                                                            } else {
                                                                return false; /* p_pos=0.000, tau=0.33 */
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        } else {
                                            if (features[0] /* HR_mean */ <= -1.96493f) {
                                                return false; /* p_pos=0.176, tau=0.33 */
                                            } else {
                                                if (features[68] /* Feature_Modified_Shock_Index_max */ <= 0.41175f) {
                                                    return false; /* p_pos=0.000, tau=0.33 */
                                                } else {
                                                    if (features[74] /* Feature_MBP_Std_60s_max */ <= 0.19378f) {
                                                        return false; /* p_pos=0.200, tau=0.33 */
                                                    } else {
                                                        return false; /* p_pos=0.000, tau=0.33 */
                                                    }
                                                }
                                            }
                                        }
                                    } else {
                                        return true; /* p_pos=0.588, tau=0.33 */
                                    }
                                } else {
                                    if (features[65] /* BT_max */ <= -3.37397f) {
                                        if (features[52] /* Feature_HR_Std_60s_min */ <= 1.23111f) {
                                            if (features[31] /* Feature_Rate_Pressure_Product_std */ <= -0.78015f) {
                                                if (features[31] /* Feature_Rate_Pressure_Product_std */ <= -0.78290f) {
                                                    return false; /* p_pos=0.000, tau=0.33 */
                                                } else {
                                                    return false; /* p_pos=0.200, tau=0.33 */
                                                }
                                            } else {
                                                return false; /* p_pos=0.000, tau=0.33 */
                                            }
                                        } else {
                                            return false; /* p_pos=0.091, tau=0.33 */
                                        }
                                    } else {
                                        if (features[37] /* Feature_MBP_Delta_60s_std */ <= -0.42113f) {
                                            if (features[75] /* Feature_MBP_Delta_60s_max */ <= -0.58411f) {
                                                return false; /* p_pos=0.000, tau=0.33 */
                                            } else {
                                                if (features[32] /* Feature_HR_Mean_60s_std */ <= -0.86358f) {
                                                    return true; /* p_pos=1.000, tau=0.33 */
                                                } else {
                                                    if (features[14] /* Feature_HR_Std_60s_mean */ <= -0.43446f) {
                                                        if (features[26] /* FIO2_std */ <= -0.33692f) {
                                                            return false; /* p_pos=0.000, tau=0.33 */
                                                        } else {
                                                            if (features[52] /* Feature_HR_Std_60s_min */ <= -0.02636f) {
                                                                return false; /* p_pos=0.000, tau=0.33 */
                                                            } else {
                                                                return true; /* p_pos=0.400, tau=0.33 */
                                                            }
                                                        }
                                                    } else {
                                                        if (features[64] /* FIO2_max */ <= -0.69931f) {
                                                            if (features[16] /* Feature_MBP_Mean_60s_mean */ <= -0.62563f) {
                                                                if (features[68] /* Feature_Modified_Shock_Index_max */ <= 0.60058f) {
                                                                    return false; /* p_pos=0.308, tau=0.33 */
                                                                } else {
                                                                    return false; /* p_pos=0.000, tau=0.33 */
                                                                }
                                                            } else {
                                                                if (features[2] /* ART_DBP_mean */ <= 0.26078f) {
                                                                    return false; /* p_pos=0.290, tau=0.33 */
                                                                } else {
                                                                    return false; /* p_pos=0.000, tau=0.33 */
                                                                }
                                                            }
                                                        } else {
                                                            return false; /* p_pos=0.000, tau=0.33 */
                                                        }
                                                    }
                                                }
                                            }
                                        } else {
                                            if (features[8] /* BT_mean */ <= -0.07864f) {
                                                if (features[67] /* Feature_Shock_Index_max */ <= -0.32594f) {
                                                    if (features[81] /* RR_CO2_slope */ <= 0.52116f) {
                                                        if (features[51] /* Feature_HR_Mean_60s_min */ <= 0.67816f) {
                                                            return false; /* p_pos=0.000, tau=0.33 */
                                                        } else {
                                                            return false; /* p_pos=0.200, tau=0.33 */
                                                        }
                                                    } else {
                                                        return false; /* p_pos=0.286, tau=0.33 */
                                                    }
                                                } else {
                                                    if (features[24] /* RR_CO2_std */ <= 2.73115f) {
                                                        return false; /* p_pos=0.000, tau=0.33 */
                                                    } else {
                                                        return false; /* p_pos=0.200, tau=0.33 */
                                                    }
                                                }
                                            } else {
                                                if (features[6] /* ETCO2_mean */ <= -0.41079f) {
                                                    return false; /* p_pos=0.000, tau=0.33 */
                                                } else {
                                                    return true; /* p_pos=0.800, tau=0.33 */
                                                }
                                            }
                                        }
                                    }
                                }
                            } else {
                                if (features[16] /* Feature_MBP_Mean_60s_mean */ <= 1.25805f) {
                                    if (features[49] /* Feature_Modified_Shock_Index_min */ <= 1.08328f) {
                                        if (features[26] /* FIO2_std */ <= -0.41743f) {
                                            if (features[89] /* Feature_HR_Mean_60s_slope */ <= 2.57249f) {
                                                if (features[38] /* HR_min */ <= 2.14064f) {
                                                    if (features[25] /* ETCO2_std */ <= 1.14749f) {
                                                        return false; /* p_pos=0.000, tau=0.33 */
                                                    } else {
                                                        return false; /* p_pos=0.200, tau=0.33 */
                                                    }
                                                } else {
                                                    return false; /* p_pos=0.250, tau=0.33 */
                                                }
                                            } else {
                                                return false; /* p_pos=0.150, tau=0.33 */
                                            }
                                        } else {
                                            if (features[25] /* ETCO2_std */ <= -0.27913f) {
                                                if (features[13] /* Feature_HR_Mean_60s_mean */ <= 2.64577f) {
                                                    if (features[14] /* Feature_HR_Std_60s_mean */ <= 0.08585f) {
                                                        if (features[93] /* Feature_MBP_Std_60s_slope */ <= 0.06315f) {
                                                            if (features[58] /* ART_SBP_max */ <= -0.12135f) {
                                                                return false; /* p_pos=0.000, tau=0.33 */
                                                            } else {
                                                                if (features[5] /* RR_CO2_mean */ <= -0.33233f) {
                                                                    return false; /* p_pos=0.000, tau=0.33 */
                                                                } else {
                                                                    return false; /* p_pos=0.043, tau=0.33 */
                                                                }
                                                            }
                                                        } else {
                                                            if (features[68] /* Feature_Modified_Shock_Index_max */ <= -0.78979f) {
                                                                return true; /* p_pos=0.556, tau=0.33 */
                                                            } else {
                                                                if (features[28] /* Feature_Pulse_Pressure_std */ <= -0.29416f) {
                                                                    return false; /* p_pos=0.000, tau=0.33 */
                                                                } else {
                                                                    return false; /* p_pos=0.088, tau=0.33 */
                                                                }
                                                            }
                                                        }
                                                    } else {
                                                        return false; /* p_pos=0.000, tau=0.33 */
                                                    }
                                                } else {
                                                    return true; /* p_pos=0.600, tau=0.33 */
                                                }
                                            } else {
                                                if (features[70] /* Feature_HR_Mean_60s_max */ <= -0.82881f) {
                                                    if (features[9] /* Feature_Pulse_Pressure_mean */ <= -0.45067f) {
                                                        return false; /* p_pos=0.000, tau=0.33 */
                                                    } else {
                                                        if (features[9] /* Feature_Pulse_Pressure_mean */ <= -0.32527f) {
                                                            return true; /* p_pos=0.714, tau=0.33 */
                                                        } else {
                                                            if (features[65] /* BT_max */ <= -0.43446f) {
                                                                if (features[28] /* Feature_Pulse_Pressure_std */ <= 0.79335f) {
                                                                    return false; /* p_pos=0.000, tau=0.33 */
                                                                } else {
                                                                    return false; /* p_pos=0.150, tau=0.33 */
                                                                }
                                                            } else {
                                                                return true; /* p_pos=0.476, tau=0.33 */
                                                            }
                                                        }
                                                    }
                                                } else {
                                                    if (features[54] /* Feature_MBP_Mean_60s_min */ <= 0.13071f) {
                                                        if (features[54] /* Feature_MBP_Mean_60s_min */ <= -0.66735f) {
                                                            if (features[86] /* Feature_Shock_Index_slope */ <= -0.16729f) {
                                                                return false; /* p_pos=0.000, tau=0.33 */
                                                            } else {
                                                                if (features[65] /* BT_max */ <= -0.78852f) {
                                                                    return false; /* p_pos=0.228, tau=0.33 */
                                                                } else {
                                                                    return false; /* p_pos=0.014, tau=0.33 */
                                                                }
                                                            }
                                                        } else {
                                                            if (features[24] /* RR_CO2_std */ <= 1.60945f) {
                                                                if (features[6] /* ETCO2_mean */ <= -1.40079f) {
                                                                    return false; /* p_pos=0.200, tau=0.33 */
                                                                } else {
                                                                    return false; /* p_pos=0.000, tau=0.33 */
                                                                }
                                                            } else {
                                                                if (features[92] /* Feature_MBP_Mean_60s_slope */ <= 0.62004f) {
                                                                    return false; /* p_pos=0.000, tau=0.33 */
                                                                } else {
                                                                    return true; /* p_pos=0.400, tau=0.33 */
                                                                }
                                                            }
                                                        }
                                                    } else {
                                                        if (features[54] /* Feature_MBP_Mean_60s_min */ <= 1.17063f) {
                                                            if (features[54] /* Feature_MBP_Mean_60s_min */ <= 0.15834f) {
                                                                if (features[40] /* ART_DBP_min */ <= 0.13072f) {
                                                                    return false; /* p_pos=0.000, tau=0.33 */
                                                                } else {
                                                                    return true; /* p_pos=0.714, tau=0.33 */
                                                                }
                                                            } else {
                                                                if (features[56] /* Feature_MBP_Delta_60s_min */ <= 0.48129f) {
                                                                    return false; /* p_pos=0.025, tau=0.33 */
                                                                } else {
                                                                    return false; /* p_pos=0.200, tau=0.33 */
                                                                }
                                                            }
                                                        } else {
                                                            return true; /* p_pos=0.583, tau=0.33 */
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    } else {
                                        if (features[51] /* Feature_HR_Mean_60s_min */ <= 0.74792f) {
                                            return false; /* p_pos=0.000, tau=0.33 */
                                        } else {
                                            if (features[57] /* HR_max */ <= 0.12947f) {
                                                if (features[62] /* RR_CO2_max */ <= -0.51006f) {
                                                    if (features[91] /* Feature_HR_Delta_60s_slope */ <= 0.13992f) {
                                                        return true; /* p_pos=1.000, tau=0.33 */
                                                    } else {
                                                        return true; /* p_pos=0.667, tau=0.33 */
                                                    }
                                                } else {
                                                    return false; /* p_pos=0.000, tau=0.33 */
                                                }
                                            } else {
                                                if (features[73] /* Feature_MBP_Mean_60s_max */ <= -0.39007f) {
                                                    if (features[62] /* RR_CO2_max */ <= 3.89086f) {
                                                        if (features[58] /* ART_SBP_max */ <= -2.34656f) {
                                                            return true; /* p_pos=0.667, tau=0.33 */
                                                        } else {
                                                            return false; /* p_pos=0.000, tau=0.33 */
                                                        }
                                                    } else {
                                                        return true; /* p_pos=0.625, tau=0.33 */
                                                    }
                                                } else {
                                                    if (features[38] /* HR_min */ <= 2.54774f) {
                                                        return false; /* p_pos=0.000, tau=0.33 */
                                                    } else {
                                                        if (features[19] /* HR_std */ <= -0.72307f) {
                                                            return true; /* p_pos=0.333, tau=0.33 */
                                                        } else {
                                                            return true; /* p_pos=1.000, tau=0.33 */
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                } else {
                                    if (features[7] /* FIO2_mean */ <= 2.27229f) {
                                        if (features[46] /* BT_min */ <= -0.13990f) {
                                            if (features[25] /* ETCO2_std */ <= -0.61812f) {
                                                return false; /* p_pos=0.200, tau=0.33 */
                                            } else {
                                                return false; /* p_pos=0.000, tau=0.33 */
                                            }
                                        } else {
                                            return true; /* p_pos=0.556, tau=0.33 */
                                        }
                                    } else {
                                        if (features[75] /* Feature_MBP_Delta_60s_max */ <= -0.14747f) {
                                            if (features[44] /* ETCO2_min */ <= -2.36488f) {
                                                return false; /* p_pos=0.000, tau=0.33 */
                                            } else {
                                                if (features[10] /* Feature_Shock_Index_mean */ <= 0.45754f) {
                                                    if (features[54] /* Feature_MBP_Mean_60s_min */ <= 0.80584f) {
                                                        return true; /* p_pos=0.400, tau=0.33 */
                                                    } else {
                                                        return true; /* p_pos=1.000, tau=0.33 */
                                                    }
                                                } else {
                                                    return false; /* p_pos=0.200, tau=0.33 */
                                                }
                                            }
                                        } else {
                                            if (features[25] /* ETCO2_std */ <= 1.63309f) {
                                                if (features[45] /* FIO2_min */ <= 2.76936f) {
                                                    return true; /* p_pos=0.333, tau=0.33 */
                                                } else {
                                                    return false; /* p_pos=0.000, tau=0.33 */
                                                }
                                            } else {
                                                return true; /* p_pos=1.000, tau=0.33 */
                                            }
                                        }
                                    }
                                }
                            }
                        } else {
                            if (features[9] /* Feature_Pulse_Pressure_mean */ <= -1.26797f) {
                                if (features[7] /* FIO2_mean */ <= 1.42045f) {
                                    if (features[84] /* BT_slope */ <= -0.29054f) {
                                        if (features[8] /* BT_mean */ <= 0.28555f) {
                                            if (features[66] /* Feature_Pulse_Pressure_max */ <= -1.23228f) {
                                                if (features[54] /* Feature_MBP_Mean_60s_min */ <= -1.28001f) {
                                                    if (features[13] /* Feature_HR_Mean_60s_mean */ <= 0.08177f) {
                                                        if (features[13] /* Feature_HR_Mean_60s_mean */ <= -1.21390f) {
                                                            return false; /* p_pos=0.000, tau=0.33 */
                                                        } else {
                                                            if (features[33] /* Feature_HR_Std_60s_std */ <= -0.20326f) {
                                                                return true; /* p_pos=1.000, tau=0.33 */
                                                            } else {
                                                                return false; /* p_pos=0.250, tau=0.33 */
                                                            }
                                                        }
                                                    } else {
                                                        if (features[32] /* Feature_HR_Mean_60s_std */ <= -0.59635f) {
                                                            return false; /* p_pos=0.286, tau=0.33 */
                                                        } else {
                                                            return false; /* p_pos=0.000, tau=0.33 */
                                                        }
                                                    }
                                                } else {
                                                    return true; /* p_pos=1.000, tau=0.33 */
                                                }
                                            } else {
                                                return false; /* p_pos=0.000, tau=0.33 */
                                            }
                                        } else {
                                            return false; /* p_pos=0.000, tau=0.33 */
                                        }
                                    } else {
                                        if (features[13] /* Feature_HR_Mean_60s_mean */ <= -2.03799f) {
                                            return true; /* p_pos=1.000, tau=0.33 */
                                        } else {
                                            if (features[8] /* BT_mean */ <= 0.49676f) {
                                                if (features[25] /* ETCO2_std */ <= 1.07002f) {
                                                    if (features[14] /* Feature_HR_Std_60s_mean */ <= -0.63769f) {
                                                        if (features[51] /* Feature_HR_Mean_60s_min */ <= -0.90060f) {
                                                            if (features[7] /* FIO2_mean */ <= -0.57977f) {
                                                                return false; /* p_pos=0.000, tau=0.33 */
                                                            } else {
                                                                if (features[38] /* HR_min */ <= -0.77695f) {
                                                                    return false; /* p_pos=0.070, tau=0.33 */
                                                                } else {
                                                                    return true; /* p_pos=0.800, tau=0.33 */
                                                                }
                                                            }
                                                        } else {
                                                            if (features[64] /* FIO2_max */ <= -0.87730f) {
                                                                if (features[46] /* BT_min */ <= 0.33040f) {
                                                                    return false; /* p_pos=0.222, tau=0.33 */
                                                                } else {
                                                                    return false; /* p_pos=0.000, tau=0.33 */
                                                                }
                                                            } else {
                                                                return false; /* p_pos=0.000, tau=0.33 */
                                                            }
                                                        }
                                                    } else {
                                                        if (features[50] /* Feature_Rate_Pressure_Product_min */ <= 0.46065f) {
                                                            if (features[33] /* Feature_HR_Std_60s_std */ <= -0.67819f) {
                                                                if (features[49] /* Feature_Modified_Shock_Index_min */ <= 3.95038f) {
                                                                    return false; /* p_pos=0.035, tau=0.33 */
                                                                } else {
                                                                    return true; /* p_pos=0.538, tau=0.33 */
                                                                }
                                                            } else {
                                                                if (features[56] /* Feature_MBP_Delta_60s_min */ <= -3.14257f) {
                                                                    return true; /* p_pos=0.333, tau=0.33 */
                                                                } else {
                                                                    return false; /* p_pos=0.014, tau=0.33 */
                                                                }
                                                            }
                                                        } else {
                                                            if (features[25] /* ETCO2_std */ <= -0.66817f) {
                                                                return true; /* p_pos=1.000, tau=0.33 */
                                                            } else {
                                                                if (features[9] /* Feature_Pulse_Pressure_mean */ <= -1.44619f) {
                                                                    return false; /* p_pos=0.103, tau=0.33 */
                                                                } else {
                                                                    return false; /* p_pos=0.005, tau=0.33 */
                                                                }
                                                            }
                                                        }
                                                    }
                                                } else {
                                                    if (features[44] /* ETCO2_min */ <= -1.89622f) {
                                                        return true; /* p_pos=0.571, tau=0.33 */
                                                    } else {
                                                        return false; /* p_pos=0.000, tau=0.33 */
                                                    }
                                                }
                                            } else {
                                                if (features[6] /* ETCO2_mean */ <= -0.56103f) {
                                                    return true; /* p_pos=1.000, tau=0.33 */
                                                } else {
                                                    if (features[33] /* Feature_HR_Std_60s_std */ <= 0.25215f) {
                                                        return false; /* p_pos=0.000, tau=0.33 */
                                                    } else {
                                                        return true; /* p_pos=0.600, tau=0.33 */
                                                    }
                                                }
                                            }
                                        }
                                    }
                                } else {
                                    if (features[37] /* Feature_MBP_Delta_60s_std */ <= 3.63592f) {
                                        if (features[68] /* Feature_Modified_Shock_Index_max */ <= 0.32715f) {
                                            if (features[48] /* Feature_Shock_Index_min */ <= 0.78123f) {
                                                if (features[24] /* RR_CO2_std */ <= 0.71369f) {
                                                    if (features[16] /* Feature_MBP_Mean_60s_mean */ <= -2.03414f) {
                                                        return false; /* p_pos=0.158, tau=0.33 */
                                                    } else {
                                                        return false; /* p_pos=0.000, tau=0.33 */
                                                    }
                                                } else {
                                                    return true; /* p_pos=0.833, tau=0.33 */
                                                }
                                            } else {
                                                if (features[13] /* Feature_HR_Mean_60s_mean */ <= 0.54455f) {
                                                    return true; /* p_pos=1.000, tau=0.33 */
                                                } else {
                                                    return false; /* p_pos=0.200, tau=0.33 */
                                                }
                                            }
                                        } else {
                                            if (features[62] /* RR_CO2_max */ <= 0.87309f) {
                                                if (features[14] /* Feature_HR_Std_60s_mean */ <= -0.76832f) {
                                                    return false; /* p_pos=0.200, tau=0.33 */
                                                } else {
                                                    return false; /* p_pos=0.000, tau=0.33 */
                                                }
                                            } else {
                                                return true; /* p_pos=0.375, tau=0.33 */
                                            }
                                        }
                                    } else {
                                        return true; /* p_pos=0.867, tau=0.33 */
                                    }
                                }
                            } else {
                                if (features[8] /* BT_mean */ <= 0.32878f) {
                                    if (features[7] /* FIO2_mean */ <= -0.21105f) {
                                        if (features[50] /* Feature_Rate_Pressure_Product_min */ <= 4.43294f) {
                                            if (features[19] /* HR_std */ <= -0.75261f) {
                                                if (features[5] /* RR_CO2_mean */ <= 0.02543f) {
                                                    if (features[44] /* ETCO2_min */ <= 1.11662f) {
                                                        if (features[49] /* Feature_Modified_Shock_Index_min */ <= 1.36479f) {
                                                            if (features[58] /* ART_SBP_max */ <= 0.04007f) {
                                                                if (features[21] /* ART_DBP_std */ <= -0.57180f) {
                                                                    return false; /* p_pos=0.000, tau=0.33 */
                                                                } else {
                                                                    return false; /* p_pos=0.003, tau=0.33 */
                                                                }
                                                            } else {
                                                                if (features[21] /* ART_DBP_std */ <= -0.84436f) {
                                                                    return false; /* p_pos=0.070, tau=0.33 */
                                                                } else {
                                                                    return false; /* p_pos=0.004, tau=0.33 */
                                                                }
                                                            }
                                                        } else {
                                                            if (features[66] /* Feature_Pulse_Pressure_max */ <= -0.48091f) {
                                                                return false; /* p_pos=0.000, tau=0.33 */
                                                            } else {
                                                                if (features[16] /* Feature_MBP_Mean_60s_mean */ <= -0.37311f) {
                                                                    return false; /* p_pos=0.014, tau=0.33 */
                                                                } else {
                                                                    return true; /* p_pos=0.562, tau=0.33 */
                                                                }
                                                            }
                                                        }
                                                    } else {
                                                        if (features[27] /* BT_std */ <= -0.27849f) {
                                                            return true; /* p_pos=0.545, tau=0.33 */
                                                        } else {
                                                            if (features[17] /* Feature_MBP_Std_60s_mean */ <= -0.63459f) {
                                                                return true; /* p_pos=0.400, tau=0.33 */
                                                            } else {
                                                                return false; /* p_pos=0.000, tau=0.33 */
                                                            }
                                                        }
                                                    }
                                                } else {
                                                    if (features[12] /* Feature_Rate_Pressure_Product_mean */ <= -0.01018f) {
                                                        if (features[14] /* Feature_HR_Std_60s_mean */ <= -0.66831f) {
                                                            if (features[46] /* BT_min */ <= 0.34662f) {
                                                                return false; /* p_pos=0.000, tau=0.33 */
                                                            } else {
                                                                if (features[25] /* ETCO2_std */ <= -0.06123f) {
                                                                    return false; /* p_pos=0.000, tau=0.33 */
                                                                } else {
                                                                    return false; /* p_pos=0.080, tau=0.33 */
                                                                }
                                                            }
                                                        } else {
                                                            if (features[74] /* Feature_MBP_Std_60s_max */ <= -0.60986f) {
                                                                if (features[77] /* ART_SBP_slope */ <= 0.27738f) {
                                                                    return false; /* p_pos=0.009, tau=0.33 */
                                                                } else {
                                                                    return true; /* p_pos=0.625, tau=0.33 */
                                                                }
                                                            } else {
                                                                if (features[48] /* Feature_Shock_Index_min */ <= -0.77458f) {
                                                                    return false; /* p_pos=0.028, tau=0.33 */
                                                                } else {
                                                                    return false; /* p_pos=0.000, tau=0.33 */
                                                                }
                                                            }
                                                        }
                                                    } else {
                                                        return false; /* p_pos=0.000, tau=0.33 */
                                                    }
                                                }
                                            } else {
                                                if (features[74] /* Feature_MBP_Std_60s_max */ <= -0.49545f) {
                                                    if (features[66] /* Feature_Pulse_Pressure_max */ <= 1.28192f) {
                                                        if (features[74] /* Feature_MBP_Std_60s_max */ <= -0.50767f) {
                                                            if (features[83] /* FIO2_slope */ <= 0.02143f) {
                                                                if (features[2] /* ART_DBP_mean */ <= -2.13672f) {
                                                                    return false; /* p_pos=0.269, tau=0.33 */
                                                                } else {
                                                                    return false; /* p_pos=0.005, tau=0.33 */
                                                                }
                                                            } else {
                                                                if (features[86] /* Feature_Shock_Index_slope */ <= 0.27091f) {
                                                                    return false; /* p_pos=0.023, tau=0.33 */
                                                                } else {
                                                                    return false; /* p_pos=0.003, tau=0.33 */
                                                                }
                                                            }
                                                        } else {
                                                            if (features[34] /* Feature_HR_Delta_60s_std */ <= -0.48437f) {
                                                                if (features[67] /* Feature_Shock_Index_max */ <= -0.18496f) {
                                                                    return false; /* p_pos=0.013, tau=0.33 */
                                                                } else {
                                                                    return false; /* p_pos=0.076, tau=0.33 */
                                                                }
                                                            } else {
                                                                if (features[49] /* Feature_Modified_Shock_Index_min */ <= -0.28595f) {
                                                                    return false; /* p_pos=0.035, tau=0.33 */
                                                                } else {
                                                                    return false; /* p_pos=0.004, tau=0.33 */
                                                                }
                                                            }
                                                        }
                                                    } else {
                                                        if (features[17] /* Feature_MBP_Std_60s_mean */ <= -0.47748f) {
                                                            if (features[25] /* ETCO2_std */ <= -0.52748f) {
                                                                if (features[66] /* Feature_Pulse_Pressure_max */ <= 1.64316f) {
                                                                    return true; /* p_pos=0.333, tau=0.33 */
                                                                } else {
                                                                    return false; /* p_pos=0.000, tau=0.33 */
                                                                }
                                                            } else {
                                                                return false; /* p_pos=0.000, tau=0.33 */
                                                            }
                                                        } else {
                                                            if (features[67] /* Feature_Shock_Index_max */ <= -0.67580f) {
                                                                if (features[54] /* Feature_MBP_Mean_60s_min */ <= -0.00143f) {
                                                                    return true; /* p_pos=0.722, tau=0.33 */
                                                                } else {
                                                                    return false; /* p_pos=0.059, tau=0.33 */
                                                                }
                                                            } else {
                                                                if (features[45] /* FIO2_min */ <= -0.73168f) {
                                                                    return true; /* p_pos=0.538, tau=0.33 */
                                                                } else {
                                                                    return false; /* p_pos=0.031, tau=0.33 */
                                                                }
                                                            }
                                                        }
                                                    }
                                                } else {
                                                    if (features[4] /* PLETH_SPO2_mean */ <= -0.31640f) {
                                                        if (features[9] /* Feature_Pulse_Pressure_mean */ <= 2.35682f) {
                                                            if (features[36] /* Feature_MBP_Std_60s_std */ <= -0.50832f) {
                                                                if (features[35] /* Feature_MBP_Mean_60s_std */ <= -0.44179f) {
                                                                    return false; /* p_pos=0.000, tau=0.33 */
                                                                } else {
                                                                    return false; /* p_pos=0.200, tau=0.33 */
                                                                }
                                                            } else {
                                                                return false; /* p_pos=0.000, tau=0.33 */
                                                            }
                                                        } else {
                                                            return false; /* p_pos=0.071, tau=0.33 */
                                                        }
                                                    } else {
                                                        if (features[84] /* BT_slope */ <= -0.32338f) {
                                                            if (features[30] /* Feature_Modified_Shock_Index_std */ <= -0.36210f) {
                                                                if (features[43] /* RR_CO2_min */ <= -0.07021f) {
                                                                    return false; /* p_pos=0.000, tau=0.33 */
                                                                } else {
                                                                    return false; /* p_pos=0.240, tau=0.33 */
                                                                }
                                                            } else {
                                                                if (features[50] /* Feature_Rate_Pressure_Product_min */ <= 0.46294f) {
                                                                    return false; /* p_pos=0.000, tau=0.33 */
                                                                } else {
                                                                    return false; /* p_pos=0.045, tau=0.33 */
                                                                }
                                                            }
                                                        } else {
                                                            if (features[44] /* ETCO2_min */ <= -0.75804f) {
                                                                if (features[32] /* Feature_HR_Mean_60s_std */ <= 0.27856f) {
                                                                    return false; /* p_pos=0.005, tau=0.33 */
                                                                } else {
                                                                    return false; /* p_pos=0.051, tau=0.33 */
                                                                }
                                                            } else {
                                                                if (features[44] /* ETCO2_min */ <= 0.04539f) {
                                                                    return false; /* p_pos=0.002, tau=0.33 */
                                                                } else {
                                                                    return false; /* p_pos=0.005, tau=0.33 */
                                                                }
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        } else {
                                            return true; /* p_pos=0.400, tau=0.33 */
                                        }
                                    } else {
                                        if (features[24] /* RR_CO2_std */ <= 1.41510f) {
                                            if (features[4] /* PLETH_SPO2_mean */ <= -0.06525f) {
                                                if (features[69] /* Feature_Rate_Pressure_Product_max */ <= -1.20252f) {
                                                    if (features[47] /* Feature_Pulse_Pressure_min */ <= 0.60896f) {
                                                        return false; /* p_pos=0.000, tau=0.33 */
                                                    } else {
                                                        return true; /* p_pos=0.500, tau=0.33 */
                                                    }
                                                } else {
                                                    if (features[66] /* Feature_Pulse_Pressure_max */ <= -0.59651f) {
                                                        if (features[1] /* ART_SBP_mean */ <= 0.35571f) {
                                                            if (features[46] /* BT_min */ <= 0.33040f) {
                                                                return false; /* p_pos=0.000, tau=0.33 */
                                                            } else {
                                                                if (features[36] /* Feature_MBP_Std_60s_std */ <= -0.54257f) {
                                                                    return false; /* p_pos=0.200, tau=0.33 */
                                                                } else {
                                                                    return false; /* p_pos=0.000, tau=0.33 */
                                                                }
                                                            }
                                                        } else {
                                                            if (features[72] /* Feature_HR_Delta_60s_max */ <= -0.64233f) {
                                                                return true; /* p_pos=0.400, tau=0.33 */
                                                            } else {
                                                                return false; /* p_pos=0.000, tau=0.33 */
                                                            }
                                                        }
                                                    } else {
                                                        return false; /* p_pos=0.000, tau=0.33 */
                                                    }
                                                }
                                            } else {
                                                if (features[42] /* PLETH_SPO2_min */ <= 0.07756f) {
                                                    if (features[4] /* PLETH_SPO2_mean */ <= 0.31756f) {
                                                        if (features[39] /* ART_SBP_min */ <= 1.02311f) {
                                                            if (features[65] /* BT_max */ <= 0.17485f) {
                                                                if (features[89] /* Feature_HR_Mean_60s_slope */ <= 0.03593f) {
                                                                    return false; /* p_pos=0.000, tau=0.33 */
                                                                } else {
                                                                    return false; /* p_pos=0.038, tau=0.33 */
                                                                }
                                                            } else {
                                                                return false; /* p_pos=0.000, tau=0.33 */
                                                            }
                                                        } else {
                                                            if (features[19] /* HR_std */ <= -0.78068f) {
                                                                return true; /* p_pos=1.000, tau=0.33 */
                                                            } else {
                                                                if (features[52] /* Feature_HR_Std_60s_min */ <= 0.04250f) {
                                                                    return false; /* p_pos=0.000, tau=0.33 */
                                                                } else {
                                                                    return false; /* p_pos=0.125, tau=0.33 */
                                                                }
                                                            }
                                                        }
                                                    } else {
                                                        if (features[46] /* BT_min */ <= 0.20066f) {
                                                            if (features[2] /* ART_DBP_mean */ <= -0.24302f) {
                                                                if (features[8] /* BT_mean */ <= 0.26393f) {
                                                                    return false; /* p_pos=0.000, tau=0.33 */
                                                                } else {
                                                                    return false; /* p_pos=0.200, tau=0.33 */
                                                                }
                                                            } else {
                                                                if (features[73] /* Feature_MBP_Mean_60s_max */ <= -0.18516f) {
                                                                    return true; /* p_pos=0.453, tau=0.33 */
                                                                } else {
                                                                    return false; /* p_pos=0.092, tau=0.33 */
                                                                }
                                                            }
                                                        } else {
                                                            if (features[43] /* RR_CO2_min */ <= -2.16194f) {
                                                                return true; /* p_pos=1.000, tau=0.33 */
                                                            } else {
                                                                if (features[12] /* Feature_Rate_Pressure_Product_mean */ <= 0.83953f) {
                                                                    return false; /* p_pos=0.013, tau=0.33 */
                                                                } else {
                                                                    return false; /* p_pos=0.136, tau=0.33 */
                                                                }
                                                            }
                                                        }
                                                    }
                                                } else {
                                                    if (features[53] /* Feature_HR_Delta_60s_min */ <= 0.50048f) {
                                                        if (features[66] /* Feature_Pulse_Pressure_max */ <= 0.41496f) {
                                                            if (features[36] /* Feature_MBP_Std_60s_std */ <= -0.49064f) {
                                                                if (features[8] /* BT_mean */ <= -0.02693f) {
                                                                    return false; /* p_pos=0.152, tau=0.33 */
                                                                } else {
                                                                    return false; /* p_pos=0.008, tau=0.33 */
                                                                }
                                                            } else {
                                                                if (features[38] /* HR_min */ <= 0.37651f) {
                                                                    return false; /* p_pos=0.000, tau=0.33 */
                                                                } else {
                                                                    return false; /* p_pos=0.003, tau=0.33 */
                                                                }
                                                            }
                                                        } else {
                                                            if (features[63] /* ETCO2_max */ <= 0.56162f) {
                                                                if (features[1] /* ART_SBP_mean */ <= 2.21113f) {
                                                                    return false; /* p_pos=0.007, tau=0.33 */
                                                                } else {
                                                                    return false; /* p_pos=0.184, tau=0.33 */
                                                                }
                                                            } else {
                                                                if (features[44] /* ETCO2_min */ <= 1.51833f) {
                                                                    return false; /* p_pos=0.037, tau=0.33 */
                                                                } else {
                                                                    return true; /* p_pos=1.000, tau=0.33 */
                                                                }
                                                            }
                                                        }
                                                    } else {
                                                        if (features[54] /* Feature_MBP_Mean_60s_min */ <= 1.09135f) {
                                                            if (features[7] /* FIO2_mean */ <= -0.09087f) {
                                                                if (features[66] /* Feature_Pulse_Pressure_max */ <= -0.42311f) {
                                                                    return false; /* p_pos=0.001, tau=0.33 */
                                                                } else {
                                                                    return false; /* p_pos=0.009, tau=0.33 */
                                                                }
                                                            } else {
                                                                if (features[55] /* Feature_MBP_Std_60s_min */ <= 0.05585f) {
                                                                    return false; /* p_pos=0.013, tau=0.33 */
                                                                } else {
                                                                    return false; /* p_pos=0.056, tau=0.33 */
                                                                }
                                                            }
                                                        } else {
                                                            if (features[55] /* Feature_MBP_Std_60s_min */ <= -0.15675f) {
                                                                return false; /* p_pos=0.000, tau=0.33 */
                                                            } else {
                                                                if (features[27] /* BT_std */ <= -0.27069f) {
                                                                    return false; /* p_pos=0.155, tau=0.33 */
                                                                } else {
                                                                    return false; /* p_pos=0.027, tau=0.33 */
                                                                }
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        } else {
                                            if (features[62] /* RR_CO2_max */ <= 0.37012f) {
                                                if (features[66] /* Feature_Pulse_Pressure_max */ <= -0.78435f) {
                                                    return false; /* p_pos=0.083, tau=0.33 */
                                                } else {
                                                    return false; /* p_pos=0.000, tau=0.33 */
                                                }
                                            } else {
                                                if (features[52] /* Feature_HR_Std_60s_min */ <= -0.35859f) {
                                                    return false; /* p_pos=0.000, tau=0.33 */
                                                } else {
                                                    if (features[6] /* ETCO2_mean */ <= -1.38681f) {
                                                        return true; /* p_pos=0.812, tau=0.33 */
                                                    } else {
                                                        if (features[70] /* Feature_HR_Mean_60s_max */ <= -0.53351f) {
                                                            return false; /* p_pos=0.000, tau=0.33 */
                                                        } else {
                                                            if (features[9] /* Feature_Pulse_Pressure_mean */ <= 0.83132f) {
                                                                if (features[32] /* Feature_HR_Mean_60s_std */ <= -0.69165f) {
                                                                    return true; /* p_pos=1.000, tau=0.33 */
                                                                } else {
                                                                    return false; /* p_pos=0.075, tau=0.33 */
                                                                }
                                                            } else {
                                                                if (features[33] /* Feature_HR_Std_60s_std */ <= 0.74392f) {
                                                                    return true; /* p_pos=0.773, tau=0.33 */
                                                                } else {
                                                                    return false; /* p_pos=0.000, tau=0.33 */
                                                                }
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                } else {
                                    if (features[77] /* ART_SBP_slope */ <= 0.12071f) {
                                        if (features[44] /* ETCO2_min */ <= -3.30220f) {
                                            if (features[25] /* ETCO2_std */ <= 3.40957f) {
                                                return false; /* p_pos=0.000, tau=0.33 */
                                            } else {
                                                return true; /* p_pos=0.900, tau=0.33 */
                                            }
                                        } else {
                                            if (features[40] /* ART_DBP_min */ <= 0.98534f) {
                                                if (features[0] /* HR_mean */ <= -1.34709f) {
                                                    if (features[63] /* ETCO2_max */ <= -0.03162f) {
                                                        if (features[44] /* ETCO2_min */ <= 0.58100f) {
                                                            if (features[1] /* ART_SBP_mean */ <= 0.03080f) {
                                                                return false; /* p_pos=0.000, tau=0.33 */
                                                            } else {
                                                                if (features[21] /* ART_DBP_std */ <= 0.12354f) {
                                                                    return false; /* p_pos=0.047, tau=0.33 */
                                                                } else {
                                                                    return false; /* p_pos=0.266, tau=0.33 */
                                                                }
                                                            }
                                                        } else {
                                                            return true; /* p_pos=1.000, tau=0.33 */
                                                        }
                                                    } else {
                                                        if (features[93] /* Feature_MBP_Std_60s_slope */ <= -4.22925f) {
                                                            return false; /* p_pos=0.200, tau=0.33 */
                                                        } else {
                                                            return false; /* p_pos=0.000, tau=0.33 */
                                                        }
                                                    }
                                                } else {
                                                    if (features[63] /* ETCO2_max */ <= -0.62487f) {
                                                        if (features[3] /* ART_MBP_mean */ <= -0.76686f) {
                                                            if (features[16] /* Feature_MBP_Mean_60s_mean */ <= -0.81568f) {
                                                                return false; /* p_pos=0.000, tau=0.33 */
                                                            } else {
                                                                if (features[75] /* Feature_MBP_Delta_60s_max */ <= -0.46503f) {
                                                                    return false; /* p_pos=0.000, tau=0.33 */
                                                                } else {
                                                                    return true; /* p_pos=0.400, tau=0.33 */
                                                                }
                                                            }
                                                        } else {
                                                            if (features[25] /* ETCO2_std */ <= -0.04430f) {
                                                                if (features[91] /* Feature_HR_Delta_60s_slope */ <= 2.59390f) {
                                                                    return false; /* p_pos=0.000, tau=0.33 */
                                                                } else {
                                                                    return false; /* p_pos=0.025, tau=0.33 */
                                                                }
                                                            } else {
                                                                if (features[8] /* BT_mean */ <= 0.33238f) {
                                                                    return false; /* p_pos=0.250, tau=0.33 */
                                                                } else {
                                                                    return false; /* p_pos=0.006, tau=0.33 */
                                                                }
                                                            }
                                                        }
                                                    } else {
                                                        if (features[66] /* Feature_Pulse_Pressure_max */ <= -0.30752f) {
                                                            if (features[6] /* ETCO2_mean */ <= 0.92985f) {
                                                                if (features[39] /* ART_SBP_min */ <= 0.44017f) {
                                                                    return false; /* p_pos=0.010, tau=0.33 */
                                                                } else {
                                                                    return false; /* p_pos=0.000, tau=0.33 */
                                                                }
                                                            } else {
                                                                if (features[8] /* BT_mean */ <= 0.52512f) {
                                                                    return false; /* p_pos=0.000, tau=0.33 */
                                                                } else {
                                                                    return false; /* p_pos=0.043, tau=0.33 */
                                                                }
                                                            }
                                                        } else {
                                                            if (features[49] /* Feature_Modified_Shock_Index_min */ <= 0.24945f) {
                                                                if (features[56] /* Feature_MBP_Delta_60s_min */ <= -2.75706f) {
                                                                    return false; /* p_pos=0.047, tau=0.33 */
                                                                } else {
                                                                    return false; /* p_pos=0.008, tau=0.33 */
                                                                }
                                                            } else {
                                                                if (features[34] /* Feature_HR_Delta_60s_std */ <= -0.87604f) {
                                                                    return true; /* p_pos=0.333, tau=0.33 */
                                                                } else {
                                                                    return false; /* p_pos=0.020, tau=0.33 */
                                                                }
                                                            }
                                                        }
                                                    }
                                                }
                                            } else {
                                                if (features[12] /* Feature_Rate_Pressure_Product_mean */ <= 1.20902f) {
                                                    if (features[88] /* Feature_Rate_Pressure_Product_slope */ <= 0.23468f) {
                                                        return false; /* p_pos=0.000, tau=0.33 */
                                                    } else {
                                                        if (features[88] /* Feature_Rate_Pressure_Product_slope */ <= 0.23958f) {
                                                            return false; /* p_pos=0.125, tau=0.33 */
                                                        } else {
                                                            return false; /* p_pos=0.000, tau=0.33 */
                                                        }
                                                    }
                                                } else {
                                                    if (features[57] /* HR_max */ <= 0.24991f) {
                                                        if (features[43] /* RR_CO2_min */ <= -0.07021f) {
                                                            if (features[11] /* Feature_Modified_Shock_Index_mean */ <= -0.24222f) {
                                                                return false; /* p_pos=0.000, tau=0.33 */
                                                            } else {
                                                                return true; /* p_pos=0.750, tau=0.33 */
                                                            }
                                                        } else {
                                                            if (features[87] /* Feature_Modified_Shock_Index_slope */ <= -0.03267f) {
                                                                return false; /* p_pos=0.105, tau=0.33 */
                                                            } else {
                                                                if (features[12] /* Feature_Rate_Pressure_Product_mean */ <= 1.22306f) {
                                                                    return false; /* p_pos=0.143, tau=0.33 */
                                                                } else {
                                                                    return false; /* p_pos=0.000, tau=0.33 */
                                                                }
                                                            }
                                                        }
                                                    } else {
                                                        if (features[54] /* Feature_MBP_Mean_60s_min */ <= 0.61724f) {
                                                            return false; /* p_pos=0.045, tau=0.33 */
                                                        } else {
                                                            return false; /* p_pos=0.000, tau=0.33 */
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    } else {
                                        if (features[66] /* Feature_Pulse_Pressure_max */ <= -0.94329f) {
                                            if (features[3] /* ART_MBP_mean */ <= -0.28639f) {
                                                return false; /* p_pos=0.000, tau=0.33 */
                                            } else {
                                                if (features[40] /* ART_DBP_min */ <= 0.37884f) {
                                                    return true; /* p_pos=0.769, tau=0.33 */
                                                } else {
                                                    if (features[53] /* Feature_HR_Delta_60s_min */ <= 0.75873f) {
                                                        if (features[15] /* Feature_HR_Delta_60s_mean */ <= 1.12618f) {
                                                            return false; /* p_pos=0.000, tau=0.33 */
                                                        } else {
                                                            return false; /* p_pos=0.200, tau=0.33 */
                                                        }
                                                    } else {
                                                        return true; /* p_pos=0.700, tau=0.33 */
                                                    }
                                                }
                                            }
                                        } else {
                                            if (features[32] /* Feature_HR_Mean_60s_std */ <= -0.77525f) {
                                                if (features[26] /* FIO2_std */ <= -0.39936f) {
                                                    if (features[67] /* Feature_Shock_Index_max */ <= -0.19686f) {
                                                        return false; /* p_pos=0.000, tau=0.33 */
                                                    } else {
                                                        if (features[18] /* Feature_MBP_Delta_60s_mean */ <= -0.22013f) {
                                                            return true; /* p_pos=0.429, tau=0.33 */
                                                        } else {
                                                            if (features[29] /* Feature_Shock_Index_std */ <= -0.53633f) {
                                                                return false; /* p_pos=0.286, tau=0.33 */
                                                            } else {
                                                                if (features[49] /* Feature_Modified_Shock_Index_min */ <= 0.36056f) {
                                                                    return false; /* p_pos=0.048, tau=0.33 */
                                                                } else {
                                                                    return false; /* p_pos=0.000, tau=0.33 */
                                                                }
                                                            }
                                                        }
                                                    }
                                                } else {
                                                    if (features[8] /* BT_mean */ <= 0.36079f) {
                                                        if (features[78] /* ART_DBP_slope */ <= 1.79442f) {
                                                            return false; /* p_pos=0.000, tau=0.33 */
                                                        } else {
                                                            return true; /* p_pos=0.400, tau=0.33 */
                                                        }
                                                    } else {
                                                        if (features[41] /* ART_MBP_min */ <= 0.70418f) {
                                                            if (features[33] /* Feature_HR_Std_60s_std */ <= -0.21560f) {
                                                                if (features[71] /* Feature_HR_Std_60s_max */ <= -0.88837f) {
                                                                    return true; /* p_pos=0.500, tau=0.33 */
                                                                } else {
                                                                    return false; /* p_pos=0.034, tau=0.33 */
                                                                }
                                                            } else {
                                                                return true; /* p_pos=0.583, tau=0.33 */
                                                            }
                                                        } else {
                                                            if (features[39] /* ART_SBP_min */ <= 0.86880f) {
                                                                if (features[25] /* ETCO2_std */ <= -0.20389f) {
                                                                    return false; /* p_pos=0.000, tau=0.33 */
                                                                } else {
                                                                    return true; /* p_pos=0.400, tau=0.33 */
                                                                }
                                                            } else {
                                                                if (features[51] /* Feature_HR_Mean_60s_min */ <= -0.46456f) {
                                                                    return true; /* p_pos=0.857, tau=0.33 */
                                                                } else {
                                                                    return true; /* p_pos=0.375, tau=0.33 */
                                                                }
                                                            }
                                                        }
                                                    }
                                                }
                                            } else {
                                                if (features[63] /* ETCO2_max */ <= 2.34136f) {
                                                    if (features[66] /* Feature_Pulse_Pressure_max */ <= 0.27046f) {
                                                        if (features[55] /* Feature_MBP_Std_60s_min */ <= 0.13339f) {
                                                            if (features[68] /* Feature_Modified_Shock_Index_max */ <= 0.46992f) {
                                                                if (features[33] /* Feature_HR_Std_60s_std */ <= -0.78454f) {
                                                                    return false; /* p_pos=0.122, tau=0.33 */
                                                                } else {
                                                                    return false; /* p_pos=0.009, tau=0.33 */
                                                                }
                                                            } else {
                                                                return false; /* p_pos=0.000, tau=0.33 */
                                                            }
                                                        } else {
                                                            if (features[54] /* Feature_MBP_Mean_60s_min */ <= 0.41302f) {
                                                                if (features[6] /* ETCO2_mean */ <= -0.40557f) {
                                                                    return false; /* p_pos=0.124, tau=0.33 */
                                                                } else {
                                                                    return false; /* p_pos=0.024, tau=0.33 */
                                                                }
                                                            } else {
                                                                if (features[52] /* Feature_HR_Std_60s_min */ <= 6.10483f) {
                                                                    return false; /* p_pos=0.000, tau=0.33 */
                                                                } else {
                                                                    return false; /* p_pos=0.059, tau=0.33 */
                                                                }
                                                            }
                                                        }
                                                    } else {
                                                        if (features[68] /* Feature_Modified_Shock_Index_max */ <= -0.11685f) {
                                                            if (features[89] /* Feature_HR_Mean_60s_slope */ <= 0.05981f) {
                                                                if (features[67] /* Feature_Shock_Index_max */ <= -0.96655f) {
                                                                    return true; /* p_pos=0.500, tau=0.33 */
                                                                } else {
                                                                    return false; /* p_pos=0.009, tau=0.33 */
                                                                }
                                                            } else {
                                                                if (features[28] /* Feature_Pulse_Pressure_std */ <= -0.04663f) {
                                                                    return false; /* p_pos=0.103, tau=0.33 */
                                                                } else {
                                                                    return false; /* p_pos=0.028, tau=0.33 */
                                                                }
                                                            }
                                                        } else {
                                                            if (features[52] /* Feature_HR_Std_60s_min */ <= -0.29436f) {
                                                                if (features[14] /* Feature_HR_Std_60s_mean */ <= 3.37006f) {
                                                                    return false; /* p_pos=0.015, tau=0.33 */
                                                                } else {
                                                                    return true; /* p_pos=0.556, tau=0.33 */
                                                                }
                                                            } else {
                                                                if (features[79] /* ART_MBP_slope */ <= 6.29357f) {
                                                                    return false; /* p_pos=0.000, tau=0.33 */
                                                                } else {
                                                                    return false; /* p_pos=0.111, tau=0.33 */
                                                                }
                                                            }
                                                        }
                                                    }
                                                } else {
                                                    if (features[19] /* HR_std */ <= 2.18093f) {
                                                        if (features[9] /* Feature_Pulse_Pressure_mean */ <= 1.32187f) {
                                                            if (features[15] /* Feature_HR_Delta_60s_mean */ <= 1.43565f) {
                                                                return false; /* p_pos=0.000, tau=0.33 */
                                                            } else {
                                                                return false; /* p_pos=0.200, tau=0.33 */
                                                            }
                                                        } else {
                                                            return true; /* p_pos=0.600, tau=0.33 */
                                                        }
                                                    } else {
                                                        return true; /* p_pos=0.889, tau=0.33 */
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    } else {
                        if (features[45] /* FIO2_min */ <= 1.95245f) {
                            if (features[74] /* Feature_MBP_Std_60s_max */ <= 0.06963f) {
                                if (features[27] /* BT_std */ <= -0.26952f) {
                                    if (features[48] /* Feature_Shock_Index_min */ <= -0.60503f) {
                                        if (features[32] /* Feature_HR_Mean_60s_std */ <= -0.46716f) {
                                            if (features[6] /* ETCO2_mean */ <= -2.50134f) {
                                                if (features[63] /* ETCO2_max */ <= -1.21812f) {
                                                    if (features[57] /* HR_max */ <= -1.15521f) {
                                                        return true; /* p_pos=0.875, tau=0.33 */
                                                    } else {
                                                        if (features[6] /* ETCO2_mean */ <= -4.03584f) {
                                                            if (features[52] /* Feature_HR_Std_60s_min */ <= 0.24500f) {
                                                                if (features[32] /* Feature_HR_Mean_60s_std */ <= -0.73939f) {
                                                                    return true; /* p_pos=0.455, tau=0.33 */
                                                                } else {
                                                                    return false; /* p_pos=0.043, tau=0.33 */
                                                                }
                                                            } else {
                                                                return true; /* p_pos=0.636, tau=0.33 */
                                                            }
                                                        } else {
                                                            return true; /* p_pos=0.750, tau=0.33 */
                                                        }
                                                    }
                                                } else {
                                                    return false; /* p_pos=0.000, tau=0.33 */
                                                }
                                            } else {
                                                if (features[79] /* ART_MBP_slope */ <= 0.38668f) {
                                                    if (features[36] /* Feature_MBP_Std_60s_std */ <= -0.01213f) {
                                                        if (features[72] /* Feature_HR_Delta_60s_max */ <= -0.23635f) {
                                                            if (features[5] /* RR_CO2_mean */ <= -0.75543f) {
                                                                return false; /* p_pos=0.000, tau=0.33 */
                                                            } else {
                                                                if (features[83] /* FIO2_slope */ <= -2.93752f) {
                                                                    return true; /* p_pos=0.375, tau=0.33 */
                                                                } else {
                                                                    return false; /* p_pos=0.056, tau=0.33 */
                                                                }
                                                            }
                                                        } else {
                                                            if (features[33] /* Feature_HR_Std_60s_std */ <= -0.32572f) {
                                                                return true; /* p_pos=0.542, tau=0.33 */
                                                            } else {
                                                                if (features[45] /* FIO2_min */ <= -0.49828f) {
                                                                    return false; /* p_pos=0.000, tau=0.33 */
                                                                } else {
                                                                    return false; /* p_pos=0.231, tau=0.33 */
                                                                }
                                                            }
                                                        }
                                                    } else {
                                                        return true; /* p_pos=0.857, tau=0.33 */
                                                    }
                                                } else {
                                                    if (features[6] /* ETCO2_mean */ <= 1.52785f) {
                                                        if (features[56] /* Feature_MBP_Delta_60s_min */ <= 0.55839f) {
                                                            if (features[14] /* Feature_HR_Std_60s_mean */ <= -0.61382f) {
                                                                if (features[79] /* ART_MBP_slope */ <= 1.39813f) {
                                                                    return false; /* p_pos=0.000, tau=0.33 */
                                                                } else {
                                                                    return false; /* p_pos=0.200, tau=0.33 */
                                                                }
                                                            } else {
                                                                if (features[65] /* BT_max */ <= 0.19955f) {
                                                                    return false; /* p_pos=0.056, tau=0.33 */
                                                                } else {
                                                                    return true; /* p_pos=0.500, tau=0.33 */
                                                                }
                                                            }
                                                        } else {
                                                            return true; /* p_pos=0.706, tau=0.33 */
                                                        }
                                                    } else {
                                                        return true; /* p_pos=0.923, tau=0.33 */
                                                    }
                                                }
                                            }
                                        } else {
                                            if (features[60] /* ART_MBP_max */ <= 0.50041f) {
                                                if (features[63] /* ETCO2_max */ <= 3.52786f) {
                                                    if (features[53] /* Feature_HR_Delta_60s_min */ <= 0.55213f) {
                                                        if (features[40] /* ART_DBP_min */ <= -0.39307f) {
                                                            if (features[81] /* RR_CO2_slope */ <= -0.71229f) {
                                                                if (features[6] /* ETCO2_mean */ <= 0.29234f) {
                                                                    return false; /* p_pos=0.043, tau=0.33 */
                                                                } else {
                                                                    return false; /* p_pos=0.298, tau=0.33 */
                                                                }
                                                            } else {
                                                                if (features[83] /* FIO2_slope */ <= -2.04295f) {
                                                                    return false; /* p_pos=0.000, tau=0.33 */
                                                                } else {
                                                                    return false; /* p_pos=0.038, tau=0.33 */
                                                                }
                                                            }
                                                        } else {
                                                            if (features[78] /* ART_DBP_slope */ <= 1.46902f) {
                                                                return false; /* p_pos=0.000, tau=0.33 */
                                                            } else {
                                                                if (features[32] /* Feature_HR_Mean_60s_std */ <= -0.33988f) {
                                                                    return true; /* p_pos=0.500, tau=0.33 */
                                                                } else {
                                                                    return false; /* p_pos=0.000, tau=0.33 */
                                                                }
                                                            }
                                                        }
                                                    } else {
                                                        if (features[8] /* BT_mean */ <= 0.23433f) {
                                                            if (features[6] /* ETCO2_mean */ <= -0.35095f) {
                                                                if (features[74] /* Feature_MBP_Std_60s_max */ <= -0.52551f) {
                                                                    return true; /* p_pos=0.444, tau=0.33 */
                                                                } else {
                                                                    return false; /* p_pos=0.000, tau=0.33 */
                                                                }
                                                            } else {
                                                                return false; /* p_pos=0.000, tau=0.33 */
                                                            }
                                                        } else {
                                                            if (features[83] /* FIO2_slope */ <= 0.09025f) {
                                                                if (features[66] /* Feature_Pulse_Pressure_max */ <= 2.00440f) {
                                                                    return false; /* p_pos=0.023, tau=0.33 */
                                                                } else {
                                                                    return true; /* p_pos=0.474, tau=0.33 */
                                                                }
                                                            } else {
                                                                return true; /* p_pos=0.684, tau=0.33 */
                                                            }
                                                        }
                                                    }
                                                } else {
                                                    if (features[35] /* Feature_MBP_Mean_60s_std */ <= -0.75013f) {
                                                        return false; /* p_pos=0.105, tau=0.33 */
                                                    } else {
                                                        return true; /* p_pos=1.000, tau=0.33 */
                                                    }
                                                }
                                            } else {
                                                if (features[47] /* Feature_Pulse_Pressure_min */ <= 0.94581f) {
                                                    if (features[48] /* Feature_Shock_Index_min */ <= -0.61686f) {
                                                        if (features[25] /* ETCO2_std */ <= 0.04929f) {
                                                            return false; /* p_pos=0.200, tau=0.33 */
                                                        } else {
                                                            return false; /* p_pos=0.000, tau=0.33 */
                                                        }
                                                    } else {
                                                        return true; /* p_pos=0.857, tau=0.33 */
                                                    }
                                                } else {
                                                    return true; /* p_pos=1.000, tau=0.33 */
                                                }
                                            }
                                        }
                                    } else {
                                        if (features[58] /* ART_SBP_max */ <= 0.04007f) {
                                            if (features[45] /* FIO2_min */ <= -0.20652f) {
                                                if (features[0] /* HR_mean */ <= 2.57360f) {
                                                    if (features[65] /* BT_max */ <= 0.45480f) {
                                                        if (features[70] /* Feature_HR_Mean_60s_max */ <= 0.40505f) {
                                                            if (features[83] /* FIO2_slope */ <= 0.09025f) {
                                                                if (features[32] /* Feature_HR_Mean_60s_std */ <= -0.85990f) {
                                                                    return false; /* p_pos=0.035, tau=0.33 */
                                                                } else {
                                                                    return false; /* p_pos=0.001, tau=0.33 */
                                                                }
                                                            } else {
                                                                if (features[37] /* Feature_MBP_Delta_60s_std */ <= -0.50857f) {
                                                                    return false; /* p_pos=0.050, tau=0.33 */
                                                                } else {
                                                                    return false; /* p_pos=0.000, tau=0.33 */
                                                                }
                                                            }
                                                        } else {
                                                            if (features[67] /* Feature_Shock_Index_max */ <= -0.06211f) {
                                                                if (features[85] /* Feature_Pulse_Pressure_slope */ <= -0.01538f) {
                                                                    return false; /* p_pos=0.011, tau=0.33 */
                                                                } else {
                                                                    return false; /* p_pos=0.203, tau=0.33 */
                                                                }
                                                            } else {
                                                                if (features[70] /* Feature_HR_Mean_60s_max */ <= 0.44737f) {
                                                                    return false; /* p_pos=0.102, tau=0.33 */
                                                                } else {
                                                                    return false; /* p_pos=0.007, tau=0.33 */
                                                                }
                                                            }
                                                        }
                                                    } else {
                                                        return true; /* p_pos=0.333, tau=0.33 */
                                                    }
                                                } else {
                                                    if (features[74] /* Feature_MBP_Std_60s_max */ <= -0.25504f) {
                                                        if (features[29] /* Feature_Shock_Index_std */ <= -0.25341f) {
                                                            return true; /* p_pos=0.667, tau=0.33 */
                                                        } else {
                                                            if (features[32] /* Feature_HR_Mean_60s_std */ <= -0.63033f) {
                                                                return false; /* p_pos=0.286, tau=0.33 */
                                                            } else {
                                                                return false; /* p_pos=0.000, tau=0.33 */
                                                            }
                                                        }
                                                    } else {
                                                        return true; /* p_pos=1.000, tau=0.33 */
                                                    }
                                                }
                                            } else {
                                                if (features[7] /* FIO2_mean */ <= 0.23504f) {
                                                    if (features[4] /* PLETH_SPO2_mean */ <= 0.12920f) {
                                                        return false; /* p_pos=0.000, tau=0.33 */
                                                    } else {
                                                        if (features[9] /* Feature_Pulse_Pressure_mean */ <= 0.69064f) {
                                                            if (features[21] /* ART_DBP_std */ <= -0.23571f) {
                                                                if (features[36] /* Feature_MBP_Std_60s_std */ <= -0.57060f) {
                                                                    return true; /* p_pos=0.538, tau=0.33 */
                                                                } else {
                                                                    return false; /* p_pos=0.029, tau=0.33 */
                                                                }
                                                            } else {
                                                                if (features[39] /* ART_SBP_min */ <= -0.03990f) {
                                                                    return false; /* p_pos=0.037, tau=0.33 */
                                                                } else {
                                                                    return false; /* p_pos=0.293, tau=0.33 */
                                                                }
                                                            }
                                                        } else {
                                                            if (features[83] /* FIO2_slope */ <= -0.04738f) {
                                                                if (features[2] /* ART_DBP_mean */ <= -0.25299f) {
                                                                    return false; /* p_pos=0.222, tau=0.33 */
                                                                } else {
                                                                    return true; /* p_pos=0.842, tau=0.33 */
                                                                }
                                                            } else {
                                                                return false; /* p_pos=0.000, tau=0.33 */
                                                            }
                                                        }
                                                    }
                                                } else {
                                                    if (features[46] /* BT_min */ <= 0.33040f) {
                                                        if (features[9] /* Feature_Pulse_Pressure_mean */ <= -0.13481f) {
                                                            if (features[10] /* Feature_Shock_Index_mean */ <= 0.61155f) {
                                                                if (features[69] /* Feature_Rate_Pressure_Product_max */ <= -0.71647f) {
                                                                    return false; /* p_pos=0.000, tau=0.33 */
                                                                } else {
                                                                    return false; /* p_pos=0.028, tau=0.33 */
                                                                }
                                                            } else {
                                                                return false; /* p_pos=0.000, tau=0.33 */
                                                            }
                                                        } else {
                                                            return false; /* p_pos=0.000, tau=0.33 */
                                                        }
                                                    } else {
                                                        if (features[44] /* ETCO2_min */ <= -0.08852f) {
                                                            if (features[19] /* HR_std */ <= 4.19917f) {
                                                                if (features[27] /* BT_std */ <= -0.27211f) {
                                                                    return false; /* p_pos=0.028, tau=0.33 */
                                                                } else {
                                                                    return false; /* p_pos=0.165, tau=0.33 */
                                                                }
                                                            } else {
                                                                return true; /* p_pos=0.833, tau=0.33 */
                                                            }
                                                        } else {
                                                            if (features[40] /* ART_DBP_min */ <= -1.52337f) {
                                                                return false; /* p_pos=0.267, tau=0.33 */
                                                            } else {
                                                                if (features[93] /* Feature_MBP_Std_60s_slope */ <= -0.30694f) {
                                                                    return false; /* p_pos=0.100, tau=0.33 */
                                                                } else {
                                                                    return false; /* p_pos=0.000, tau=0.33 */
                                                                }
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        } else {
                                            if (features[37] /* Feature_MBP_Delta_60s_std */ <= -0.29923f) {
                                                if (features[79] /* ART_MBP_slope */ <= 0.42714f) {
                                                    if (features[62] /* RR_CO2_max */ <= 1.12457f) {
                                                        if (features[72] /* Feature_HR_Delta_60s_max */ <= -0.43934f) {
                                                            if (features[92] /* Feature_MBP_Mean_60s_slope */ <= -0.65538f) {
                                                                if (features[17] /* Feature_MBP_Std_60s_mean */ <= -0.60064f) {
                                                                    return false; /* p_pos=0.200, tau=0.33 */
                                                                } else {
                                                                    return false; /* p_pos=0.000, tau=0.33 */
                                                                }
                                                            } else {
                                                                if (features[40] /* ART_DBP_min */ <= -0.39307f) {
                                                                    return false; /* p_pos=0.211, tau=0.33 */
                                                                } else {
                                                                    return false; /* p_pos=0.060, tau=0.33 */
                                                                }
                                                            }
                                                        } else {
                                                            if (features[87] /* Feature_Modified_Shock_Index_slope */ <= 0.61519f) {
                                                                if (features[67] /* Feature_Shock_Index_max */ <= 0.01291f) {
                                                                    return false; /* p_pos=0.021, tau=0.33 */
                                                                } else {
                                                                    return false; /* p_pos=0.000, tau=0.33 */
                                                                }
                                                            } else {
                                                                if (features[5] /* RR_CO2_mean */ <= 0.49703f) {
                                                                    return false; /* p_pos=0.028, tau=0.33 */
                                                                } else {
                                                                    return false; /* p_pos=0.286, tau=0.33 */
                                                                }
                                                            }
                                                        }
                                                    } else {
                                                        if (features[8] /* BT_mean */ <= 0.31649f) {
                                                            if (features[53] /* Feature_HR_Delta_60s_min */ <= 0.75873f) {
                                                                if (features[15] /* Feature_HR_Delta_60s_mean */ <= 1.17087f) {
                                                                    return false; /* p_pos=0.000, tau=0.33 */
                                                                } else {
                                                                    return false; /* p_pos=0.300, tau=0.33 */
                                                                }
                                                            } else {
                                                                return true; /* p_pos=0.625, tau=0.33 */
                                                            }
                                                        } else {
                                                            if (features[40] /* ART_DBP_min */ <= 0.54424f) {
                                                                if (features[92] /* Feature_MBP_Mean_60s_slope */ <= -0.39974f) {
                                                                    return false; /* p_pos=0.000, tau=0.33 */
                                                                } else {
                                                                    return true; /* p_pos=0.750, tau=0.33 */
                                                                }
                                                            } else {
                                                                if (features[75] /* Feature_MBP_Delta_60s_max */ <= -0.45510f) {
                                                                    return false; /* p_pos=0.000, tau=0.33 */
                                                                } else {
                                                                    return true; /* p_pos=0.400, tau=0.33 */
                                                                }
                                                            }
                                                        }
                                                    }
                                                } else {
                                                    if (features[29] /* Feature_Shock_Index_std */ <= 0.00588f) {
                                                        if (features[66] /* Feature_Pulse_Pressure_max */ <= 1.18078f) {
                                                            if (features[45] /* FIO2_min */ <= 0.31863f) {
                                                                if (features[45] /* FIO2_min */ <= -0.08982f) {
                                                                    return false; /* p_pos=0.128, tau=0.33 */
                                                                } else {
                                                                    return true; /* p_pos=0.341, tau=0.33 */
                                                                }
                                                            } else {
                                                                if (features[1] /* ART_SBP_mean */ <= 0.12974f) {
                                                                    return true; /* p_pos=0.400, tau=0.33 */
                                                                } else {
                                                                    return false; /* p_pos=0.000, tau=0.33 */
                                                                }
                                                            }
                                                        } else {
                                                            if (features[66] /* Feature_Pulse_Pressure_max */ <= 1.59981f) {
                                                                return true; /* p_pos=0.750, tau=0.33 */
                                                            } else {
                                                                return false; /* p_pos=0.211, tau=0.33 */
                                                            }
                                                        }
                                                    } else {
                                                        if (features[27] /* BT_std */ <= -0.27043f) {
                                                            if (features[19] /* HR_std */ <= -0.59387f) {
                                                                return false; /* p_pos=0.133, tau=0.33 */
                                                            } else {
                                                                return false; /* p_pos=0.000, tau=0.33 */
                                                            }
                                                        } else {
                                                            return true; /* p_pos=0.417, tau=0.33 */
                                                        }
                                                    }
                                                }
                                            } else {
                                                if (features[45] /* FIO2_min */ <= 1.60235f) {
                                                    if (features[26] /* FIO2_std */ <= 1.16390f) {
                                                        if (features[3] /* ART_MBP_mean */ <= 1.48298f) {
                                                            if (features[93] /* Feature_MBP_Std_60s_slope */ <= 0.66276f) {
                                                                if (features[37] /* Feature_MBP_Delta_60s_std */ <= -0.28477f) {
                                                                    return false; /* p_pos=0.036, tau=0.33 */
                                                                } else {
                                                                    return false; /* p_pos=0.002, tau=0.33 */
                                                                }
                                                            } else {
                                                                if (features[63] /* ETCO2_max */ <= 0.56162f) {
                                                                    return false; /* p_pos=0.000, tau=0.33 */
                                                                } else {
                                                                    return false; /* p_pos=0.235, tau=0.33 */
                                                                }
                                                            }
                                                        } else {
                                                            if (features[57] /* HR_max */ <= 0.37035f) {
                                                                return false; /* p_pos=0.318, tau=0.33 */
                                                            } else {
                                                                return false; /* p_pos=0.000, tau=0.33 */
                                                            }
                                                        }
                                                    } else {
                                                        if (features[11] /* Feature_Modified_Shock_Index_mean */ <= 0.28455f) {
                                                            if (features[27] /* BT_std */ <= -0.28055f) {
                                                                if (features[93] /* Feature_MBP_Std_60s_slope */ <= 0.00919f) {
                                                                    return false; /* p_pos=0.045, tau=0.33 */
                                                                } else {
                                                                    return true; /* p_pos=0.333, tau=0.33 */
                                                                }
                                                            } else {
                                                                if (features[77] /* ART_SBP_slope */ <= -2.22941f) {
                                                                    return false; /* p_pos=0.200, tau=0.33 */
                                                                } else {
                                                                    return false; /* p_pos=0.000, tau=0.33 */
                                                                }
                                                            }
                                                        } else {
                                                            if (features[76] /* HR_slope */ <= -3.33976f) {
                                                                return false; /* p_pos=0.200, tau=0.33 */
                                                            } else {
                                                                return false; /* p_pos=0.000, tau=0.33 */
                                                            }
                                                        }
                                                    }
                                                } else {
                                                    if (features[50] /* Feature_Rate_Pressure_Product_min */ <= -0.59250f) {
                                                        if (features[72] /* Feature_HR_Delta_60s_max */ <= 0.44875f) {
                                                            return false; /* p_pos=0.188, tau=0.33 */
                                                        } else {
                                                            return true; /* p_pos=0.933, tau=0.33 */
                                                        }
                                                    } else {
                                                        if (features[13] /* Feature_HR_Mean_60s_mean */ <= 1.31774f) {
                                                            if (features[7] /* FIO2_mean */ <= 1.37844f) {
                                                                return true; /* p_pos=0.600, tau=0.33 */
                                                            } else {
                                                                if (features[75] /* Feature_MBP_Delta_60s_max */ <= -0.44518f) {
                                                                    return true; /* p_pos=0.333, tau=0.33 */
                                                                } else {
                                                                    return false; /* p_pos=0.000, tau=0.33 */
                                                                }
                                                            }
                                                        } else {
                                                            return true; /* p_pos=0.667, tau=0.33 */
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                } else {
                                    if (features[66] /* Feature_Pulse_Pressure_max */ <= 0.50165f) {
                                        if (features[64] /* FIO2_max */ <= -0.29883f) {
                                            if (features[26] /* FIO2_std */ <= -0.31900f) {
                                                return true; /* p_pos=0.500, tau=0.33 */
                                            } else {
                                                if (features[55] /* Feature_MBP_Std_60s_min */ <= 0.24420f) {
                                                    if (features[33] /* Feature_HR_Std_60s_std */ <= -0.54852f) {
                                                        if (features[52] /* Feature_HR_Std_60s_min */ <= -0.21566f) {
                                                            if (features[7] /* FIO2_mean */ <= -0.83168f) {
                                                                if (features[17] /* Feature_MBP_Std_60s_mean */ <= -0.65412f) {
                                                                    return true; /* p_pos=0.500, tau=0.33 */
                                                                } else {
                                                                    return false; /* p_pos=0.011, tau=0.33 */
                                                                }
                                                            } else {
                                                                if (features[22] /* ART_MBP_std */ <= -0.10808f) {
                                                                    return false; /* p_pos=0.001, tau=0.33 */
                                                                } else {
                                                                    return false; /* p_pos=0.021, tau=0.33 */
                                                                }
                                                            }
                                                        } else {
                                                            if (features[48] /* Feature_Shock_Index_min */ <= 0.08589f) {
                                                                if (features[32] /* Feature_HR_Mean_60s_std */ <= -0.79634f) {
                                                                    return false; /* p_pos=0.250, tau=0.33 */
                                                                } else {
                                                                    return false; /* p_pos=0.033, tau=0.33 */
                                                                }
                                                            } else {
                                                                if (features[34] /* Feature_HR_Delta_60s_std */ <= -0.50675f) {
                                                                    return false; /* p_pos=0.000, tau=0.33 */
                                                                } else {
                                                                    return false; /* p_pos=0.035, tau=0.33 */
                                                                }
                                                            }
                                                        }
                                                    } else {
                                                        if (features[64] /* FIO2_max */ <= -0.96629f) {
                                                            return false; /* p_pos=0.235, tau=0.33 */
                                                        } else {
                                                            if (features[4] /* PLETH_SPO2_mean */ <= -1.08264f) {
                                                                if (features[83] /* FIO2_slope */ <= 0.02143f) {
                                                                    return false; /* p_pos=0.000, tau=0.33 */
                                                                } else {
                                                                    return true; /* p_pos=0.600, tau=0.33 */
                                                                }
                                                            } else {
                                                                if (features[47] /* Feature_Pulse_Pressure_min */ <= -0.23317f) {
                                                                    return false; /* p_pos=0.006, tau=0.33 */
                                                                } else {
                                                                    return false; /* p_pos=0.000, tau=0.33 */
                                                                }
                                                            }
                                                        }
                                                    }
                                                } else {
                                                    if (features[86] /* Feature_Shock_Index_slope */ <= 0.00637f) {
                                                        if (features[47] /* Feature_Pulse_Pressure_min */ <= 1.70372f) {
                                                            if (features[18] /* Feature_MBP_Delta_60s_mean */ <= -0.13530f) {
                                                                if (features[6] /* ETCO2_mean */ <= 0.22784f) {
                                                                    return true; /* p_pos=0.562, tau=0.33 */
                                                                } else {
                                                                    return false; /* p_pos=0.000, tau=0.33 */
                                                                }
                                                            } else {
                                                                if (features[66] /* Feature_Pulse_Pressure_max */ <= -0.56761f) {
                                                                    return false; /* p_pos=0.114, tau=0.33 */
                                                                } else {
                                                                    return false; /* p_pos=0.007, tau=0.33 */
                                                                }
                                                            }
                                                        } else {
                                                            return true; /* p_pos=0.714, tau=0.33 */
                                                        }
                                                    } else {
                                                        if (features[17] /* Feature_MBP_Std_60s_mean */ <= -0.32435f) {
                                                            if (features[29] /* Feature_Shock_Index_std */ <= -0.13338f) {
                                                                return false; /* p_pos=0.000, tau=0.33 */
                                                            } else {
                                                                return true; /* p_pos=0.429, tau=0.33 */
                                                            }
                                                        } else {
                                                            return false; /* p_pos=0.000, tau=0.33 */
                                                        }
                                                    }
                                                }
                                            }
                                        } else {
                                            if (features[21] /* ART_DBP_std */ <= -0.64905f) {
                                                if (features[84] /* BT_slope */ <= -0.12635f) {
                                                    if (features[8] /* BT_mean */ <= 0.31627f) {
                                                        if (features[83] /* FIO2_slope */ <= 0.15906f) {
                                                            return false; /* p_pos=0.000, tau=0.33 */
                                                        } else {
                                                            if (features[39] /* ART_SBP_min */ <= -2.28594f) {
                                                                return true; /* p_pos=0.429, tau=0.33 */
                                                            } else {
                                                                return false; /* p_pos=0.000, tau=0.33 */
                                                            }
                                                        }
                                                    } else {
                                                        if (features[7] /* FIO2_mean */ <= -0.02645f) {
                                                            if (features[86] /* Feature_Shock_Index_slope */ <= -0.00720f) {
                                                                return true; /* p_pos=1.000, tau=0.33 */
                                                            } else {
                                                                if (features[44] /* ETCO2_min */ <= -0.22242f) {
                                                                    return true; /* p_pos=0.500, tau=0.33 */
                                                                } else {
                                                                    return false; /* p_pos=0.019, tau=0.33 */
                                                                }
                                                            }
                                                        } else {
                                                            if (features[59] /* ART_DBP_max */ <= -0.81525f) {
                                                                return false; /* p_pos=0.118, tau=0.33 */
                                                            } else {
                                                                return false; /* p_pos=0.000, tau=0.33 */
                                                            }
                                                        }
                                                    }
                                                } else {
                                                    if (features[72] /* Feature_HR_Delta_60s_max */ <= -0.23635f) {
                                                        if (features[8] /* BT_mean */ <= -0.76506f) {
                                                            return false; /* p_pos=0.273, tau=0.33 */
                                                        } else {
                                                            if (features[52] /* Feature_HR_Std_60s_min */ <= 0.02874f) {
                                                                if (features[66] /* Feature_Pulse_Pressure_max */ <= -0.16302f) {
                                                                    return false; /* p_pos=0.000, tau=0.33 */
                                                                } else {
                                                                    return false; /* p_pos=0.008, tau=0.33 */
                                                                }
                                                            } else {
                                                                if (features[3] /* ART_MBP_mean */ <= 0.55517f) {
                                                                    return false; /* p_pos=0.004, tau=0.33 */
                                                                } else {
                                                                    return false; /* p_pos=0.100, tau=0.33 */
                                                                }
                                                            }
                                                        }
                                                    } else {
                                                        return false; /* p_pos=0.000, tau=0.33 */
                                                    }
                                                }
                                            } else {
                                                if (features[71] /* Feature_HR_Std_60s_max */ <= 0.23587f) {
                                                    if (features[8] /* BT_mean */ <= 0.30724f) {
                                                        if (features[11] /* Feature_Modified_Shock_Index_mean */ <= 1.06448f) {
                                                            if (features[52] /* Feature_HR_Std_60s_min */ <= 0.42339f) {
                                                                if (features[71] /* Feature_HR_Std_60s_max */ <= -0.68193f) {
                                                                    return false; /* p_pos=0.035, tau=0.33 */
                                                                } else {
                                                                    return false; /* p_pos=0.009, tau=0.33 */
                                                                }
                                                            } else {
                                                                if (features[38] /* HR_min */ <= -1.45546f) {
                                                                    return true; /* p_pos=0.476, tau=0.33 */
                                                                } else {
                                                                    return false; /* p_pos=0.041, tau=0.33 */
                                                                }
                                                            }
                                                        } else {
                                                            if (features[67] /* Feature_Shock_Index_max */ <= 0.67361f) {
                                                                if (features[67] /* Feature_Shock_Index_max */ <= 0.60170f) {
                                                                    return false; /* p_pos=0.056, tau=0.33 */
                                                                } else {
                                                                    return true; /* p_pos=0.800, tau=0.33 */
                                                                }
                                                            } else {
                                                                return false; /* p_pos=0.000, tau=0.33 */
                                                            }
                                                        }
                                                    } else {
                                                        if (features[29] /* Feature_Shock_Index_std */ <= -0.49617f) {
                                                            return false; /* p_pos=0.000, tau=0.33 */
                                                        } else {
                                                            if (features[62] /* RR_CO2_max */ <= 0.11864f) {
                                                                if (features[67] /* Feature_Shock_Index_max */ <= -0.53104f) {
                                                                    return false; /* p_pos=0.161, tau=0.33 */
                                                                } else {
                                                                    return false; /* p_pos=0.057, tau=0.33 */
                                                                }
                                                            } else {
                                                                if (features[83] /* FIO2_slope */ <= -1.63007f) {
                                                                    return false; /* p_pos=0.110, tau=0.33 */
                                                                } else {
                                                                    return false; /* p_pos=0.018, tau=0.33 */
                                                                }
                                                            }
                                                        }
                                                    }
                                                } else {
                                                    if (features[72] /* Feature_HR_Delta_60s_max */ <= -0.84532f) {
                                                        return true; /* p_pos=0.500, tau=0.33 */
                                                    } else {
                                                        if (features[75] /* Feature_MBP_Delta_60s_max */ <= -0.40548f) {
                                                            if (features[1] /* ART_SBP_mean */ <= 0.03755f) {
                                                                if (features[80] /* PLETH_SPO2_slope */ <= -0.28680f) {
                                                                    return false; /* p_pos=0.055, tau=0.33 */
                                                                } else {
                                                                    return false; /* p_pos=0.004, tau=0.33 */
                                                                }
                                                            } else {
                                                                return false; /* p_pos=0.000, tau=0.33 */
                                                            }
                                                        } else {
                                                            if (features[73] /* Feature_MBP_Mean_60s_max */ <= 0.17542f) {
                                                                if (features[20] /* ART_SBP_std */ <= -0.37925f) {
                                                                    return false; /* p_pos=0.000, tau=0.33 */
                                                                } else {
                                                                    return false; /* p_pos=0.034, tau=0.33 */
                                                                }
                                                            } else {
                                                                if (features[60] /* ART_MBP_max */ <= 0.48253f) {
                                                                    return false; /* p_pos=0.000, tau=0.33 */
                                                                } else {
                                                                    return false; /* p_pos=0.222, tau=0.33 */
                                                                }
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    } else {
                                        if (features[84] /* BT_slope */ <= 0.30054f) {
                                            if (features[6] /* ETCO2_mean */ <= 0.28582f) {
                                                if (features[49] /* Feature_Modified_Shock_Index_min */ <= -0.91637f) {
                                                    if (features[51] /* Feature_HR_Mean_60s_min */ <= -1.76931f) {
                                                        return true; /* p_pos=0.579, tau=0.33 */
                                                    } else {
                                                        return false; /* p_pos=0.000, tau=0.33 */
                                                    }
                                                } else {
                                                    if (features[4] /* PLETH_SPO2_mean */ <= 0.31878f) {
                                                        if (features[9] /* Feature_Pulse_Pressure_mean */ <= -0.83748f) {
                                                            return false; /* p_pos=0.200, tau=0.33 */
                                                        } else {
                                                            return false; /* p_pos=0.000, tau=0.33 */
                                                        }
                                                    } else {
                                                        if (features[83] /* FIO2_slope */ <= 0.64075f) {
                                                            if (features[87] /* Feature_Modified_Shock_Index_slope */ <= -0.62303f) {
                                                                if (features[50] /* Feature_Rate_Pressure_Product_min */ <= 0.98431f) {
                                                                    return false; /* p_pos=0.055, tau=0.33 */
                                                                } else {
                                                                    return true; /* p_pos=0.667, tau=0.33 */
                                                                }
                                                            } else {
                                                                if (features[89] /* Feature_HR_Mean_60s_slope */ <= 2.69748f) {
                                                                    return false; /* p_pos=0.019, tau=0.33 */
                                                                } else {
                                                                    return false; /* p_pos=0.194, tau=0.33 */
                                                                }
                                                            }
                                                        } else {
                                                            if (features[50] /* Feature_Rate_Pressure_Product_min */ <= 0.68388f) {
                                                                if (features[78] /* ART_DBP_slope */ <= 0.60128f) {
                                                                    return false; /* p_pos=0.000, tau=0.33 */
                                                                } else {
                                                                    return true; /* p_pos=0.357, tau=0.33 */
                                                                }
                                                            } else {
                                                                return true; /* p_pos=0.533, tau=0.33 */
                                                            }
                                                        }
                                                    }
                                                }
                                            } else {
                                                if (features[7] /* FIO2_mean */ <= 0.76201f) {
                                                    if (features[7] /* FIO2_mean */ <= -0.62502f) {
                                                        if (features[91] /* Feature_HR_Delta_60s_slope */ <= 1.21967f) {
                                                            return false; /* p_pos=0.000, tau=0.33 */
                                                        } else {
                                                            return false; /* p_pos=0.200, tau=0.33 */
                                                        }
                                                    } else {
                                                        if (features[74] /* Feature_MBP_Std_60s_max */ <= -0.37690f) {
                                                            if (features[69] /* Feature_Rate_Pressure_Product_max */ <= -0.01201f) {
                                                                if (features[85] /* Feature_Pulse_Pressure_slope */ <= 1.01160f) {
                                                                    return false; /* p_pos=0.147, tau=0.33 */
                                                                } else {
                                                                    return true; /* p_pos=0.667, tau=0.33 */
                                                                }
                                                            } else {
                                                                if (features[13] /* Feature_HR_Mean_60s_mean */ <= 1.58137f) {
                                                                    return false; /* p_pos=0.012, tau=0.33 */
                                                                } else {
                                                                    return true; /* p_pos=0.500, tau=0.33 */
                                                                }
                                                            }
                                                        } else {
                                                            if (features[50] /* Feature_Rate_Pressure_Product_min */ <= 0.29109f) {
                                                                if (features[6] /* ETCO2_mean */ <= 1.06873f) {
                                                                    return false; /* p_pos=0.053, tau=0.33 */
                                                                } else {
                                                                    return true; /* p_pos=0.692, tau=0.33 */
                                                                }
                                                            } else {
                                                                if (features[45] /* FIO2_min */ <= 0.20193f) {
                                                                    return true; /* p_pos=0.547, tau=0.33 */
                                                                } else {
                                                                    return false; /* p_pos=0.000, tau=0.33 */
                                                                }
                                                            }
                                                        }
                                                    }
                                                } else {
                                                    if (features[69] /* Feature_Rate_Pressure_Product_max */ <= -0.03101f) {
                                                        if (features[6] /* ETCO2_mean */ <= 1.33193f) {
                                                            if (features[8] /* BT_mean */ <= 0.33218f) {
                                                                return false; /* p_pos=0.000, tau=0.33 */
                                                            } else {
                                                                return false; /* p_pos=0.188, tau=0.33 */
                                                            }
                                                        } else {
                                                            return true; /* p_pos=0.545, tau=0.33 */
                                                        }
                                                    } else {
                                                        if (features[26] /* FIO2_std */ <= -0.31086f) {
                                                            return false; /* p_pos=0.200, tau=0.33 */
                                                        } else {
                                                            return false; /* p_pos=0.000, tau=0.33 */
                                                        }
                                                    }
                                                }
                                            }
                                        } else {
                                            if (features[14] /* Feature_HR_Std_60s_mean */ <= 1.56167f) {
                                                return false; /* p_pos=0.000, tau=0.33 */
                                            } else {
                                                if (features[19] /* HR_std */ <= 1.43384f) {
                                                    return true; /* p_pos=0.400, tau=0.33 */
                                                } else {
                                                    return false; /* p_pos=0.000, tau=0.33 */
                                                }
                                            }
                                        }
                                    }
                                }
                            } else {
                                if (features[50] /* Feature_Rate_Pressure_Product_min */ <= 0.26258f) {
                                    if (features[67] /* Feature_Shock_Index_max */ <= -0.93863f) {
                                        if (features[6] /* ETCO2_mean */ <= -0.03368f) {
                                            return false; /* p_pos=0.000, tau=0.33 */
                                        } else {
                                            if (features[20] /* ART_SBP_std */ <= 0.65366f) {
                                                if (features[38] /* HR_min */ <= -1.18406f) {
                                                    return false; /* p_pos=0.000, tau=0.33 */
                                                } else {
                                                    return true; /* p_pos=0.353, tau=0.33 */
                                                }
                                            } else {
                                                return true; /* p_pos=0.750, tau=0.33 */
                                            }
                                        }
                                    } else {
                                        if (features[65] /* BT_max */ <= -1.06024f) {
                                            if (features[48] /* Feature_Shock_Index_min */ <= 1.39442f) {
                                                if (features[28] /* Feature_Pulse_Pressure_std */ <= 0.00856f) {
                                                    if (features[59] /* ART_DBP_max */ <= -0.19220f) {
                                                        return false; /* p_pos=0.000, tau=0.33 */
                                                    } else {
                                                        if (features[6] /* ETCO2_mean */ <= 0.14005f) {
                                                            if (features[87] /* Feature_Modified_Shock_Index_slope */ <= -5.85658f) {
                                                                return true; /* p_pos=0.400, tau=0.33 */
                                                            } else {
                                                                return false; /* p_pos=0.000, tau=0.33 */
                                                            }
                                                        } else {
                                                            if (features[48] /* Feature_Shock_Index_min */ <= 0.11959f) {
                                                                return true; /* p_pos=0.846, tau=0.33 */
                                                            } else {
                                                                return false; /* p_pos=0.087, tau=0.33 */
                                                            }
                                                        }
                                                    }
                                                } else {
                                                    if (features[5] /* RR_CO2_mean */ <= -0.25102f) {
                                                        return false; /* p_pos=0.000, tau=0.33 */
                                                    } else {
                                                        if (features[66] /* Feature_Pulse_Pressure_max */ <= 1.88880f) {
                                                            if (features[11] /* Feature_Modified_Shock_Index_mean */ <= 3.93945f) {
                                                                return false; /* p_pos=0.000, tau=0.33 */
                                                            } else {
                                                                return false; /* p_pos=0.200, tau=0.33 */
                                                            }
                                                        } else {
                                                            if (features[45] /* FIO2_min */ <= -0.58580f) {
                                                                return true; /* p_pos=0.800, tau=0.33 */
                                                            } else {
                                                                if (features[65] /* BT_max */ <= -3.37397f) {
                                                                    return false; /* p_pos=0.214, tau=0.33 */
                                                                } else {
                                                                    return false; /* p_pos=0.000, tau=0.33 */
                                                                }
                                                            }
                                                        }
                                                    }
                                                }
                                            } else {
                                                return true; /* p_pos=0.600, tau=0.33 */
                                            }
                                        } else {
                                            if (features[8] /* BT_mean */ <= 0.16852f) {
                                                if (features[29] /* Feature_Shock_Index_std */ <= 3.70921f) {
                                                    if (features[66] /* Feature_Pulse_Pressure_max */ <= 0.29936f) {
                                                        if (features[14] /* Feature_HR_Std_60s_mean */ <= 2.12295f) {
                                                            if (features[53] /* Feature_HR_Delta_60s_min */ <= 0.60378f) {
                                                                return false; /* p_pos=0.000, tau=0.33 */
                                                            } else {
                                                                if (features[28] /* Feature_Pulse_Pressure_std */ <= 0.54981f) {
                                                                    return false; /* p_pos=0.000, tau=0.33 */
                                                                } else {
                                                                    return false; /* p_pos=0.064, tau=0.33 */
                                                                }
                                                            }
                                                        } else {
                                                            if (features[65] /* BT_max */ <= 0.31483f) {
                                                                return false; /* p_pos=0.000, tau=0.33 */
                                                            } else {
                                                                return true; /* p_pos=0.800, tau=0.33 */
                                                            }
                                                        }
                                                    } else {
                                                        return false; /* p_pos=0.000, tau=0.33 */
                                                    }
                                                } else {
                                                    if (features[49] /* Feature_Modified_Shock_Index_min */ <= -0.67693f) {
                                                        if (features[62] /* RR_CO2_max */ <= -0.88728f) {
                                                            return false; /* p_pos=0.238, tau=0.33 */
                                                        } else {
                                                            if (features[52] /* Feature_HR_Std_60s_min */ <= -0.00984f) {
                                                                if (features[47] /* Feature_Pulse_Pressure_min */ <= -3.20868f) {
                                                                    return false; /* p_pos=0.182, tau=0.33 */
                                                                } else {
                                                                    return false; /* p_pos=0.011, tau=0.33 */
                                                                }
                                                            } else {
                                                                return false; /* p_pos=0.000, tau=0.33 */
                                                            }
                                                        }
                                                    } else {
                                                        return false; /* p_pos=0.000, tau=0.33 */
                                                    }
                                                }
                                            } else {
                                                if (features[35] /* Feature_MBP_Mean_60s_std */ <= 1.72992f) {
                                                    if (features[86] /* Feature_Shock_Index_slope */ <= -11.40486f) {
                                                        return true; /* p_pos=0.833, tau=0.33 */
                                                    } else {
                                                        if (features[52] /* Feature_HR_Std_60s_min */ <= 0.56106f) {
                                                            if (features[41] /* ART_MBP_min */ <= -2.25417f) {
                                                                return false; /* p_pos=0.235, tau=0.33 */
                                                            } else {
                                                                if (features[15] /* Feature_HR_Delta_60s_mean */ <= -0.55360f) {
                                                                    return false; /* p_pos=0.001, tau=0.33 */
                                                                } else {
                                                                    return false; /* p_pos=0.009, tau=0.33 */
                                                                }
                                                            }
                                                        } else {
                                                            if (features[75] /* Feature_MBP_Delta_60s_max */ <= 2.69068f) {
                                                                if (features[30] /* Feature_Modified_Shock_Index_std */ <= -0.08009f) {
                                                                    return false; /* p_pos=0.069, tau=0.33 */
                                                                } else {
                                                                    return false; /* p_pos=0.006, tau=0.33 */
                                                                }
                                                            } else {
                                                                if (features[68] /* Feature_Modified_Shock_Index_max */ <= 0.34706f) {
                                                                    return true; /* p_pos=0.786, tau=0.33 */
                                                                } else {
                                                                    return false; /* p_pos=0.000, tau=0.33 */
                                                                }
                                                            }
                                                        }
                                                    }
                                                } else {
                                                    if (features[57] /* HR_max */ <= -0.87419f) {
                                                        if (features[2] /* ART_DBP_mean */ <= 0.61704f) {
                                                            return false; /* p_pos=0.000, tau=0.33 */
                                                        } else {
                                                            if (features[26] /* FIO2_std */ <= -0.08715f) {
                                                                return false; /* p_pos=0.000, tau=0.33 */
                                                            } else {
                                                                return true; /* p_pos=0.429, tau=0.33 */
                                                            }
                                                        }
                                                    } else {
                                                        return false; /* p_pos=0.000, tau=0.33 */
                                                    }
                                                }
                                            }
                                        }
                                    }
                                } else {
                                    if (features[63] /* ETCO2_max */ <= 1.15487f) {
                                        if (features[24] /* RR_CO2_std */ <= 2.62939f) {
                                            if (features[8] /* BT_mean */ <= 0.39682f) {
                                                if (features[2] /* ART_DBP_mean */ <= 2.27825f) {
                                                    if (features[19] /* HR_std */ <= -0.75904f) {
                                                        if (features[40] /* ART_DBP_min */ <= 0.32370f) {
                                                            if (features[2] /* ART_DBP_mean */ <= -0.06735f) {
                                                                return false; /* p_pos=0.000, tau=0.33 */
                                                            } else {
                                                                if (features[21] /* ART_DBP_std */ <= -0.27978f) {
                                                                    return true; /* p_pos=0.538, tau=0.33 */
                                                                } else {
                                                                    return false; /* p_pos=0.021, tau=0.33 */
                                                                }
                                                            }
                                                        } else {
                                                            return false; /* p_pos=0.000, tau=0.33 */
                                                        }
                                                    } else {
                                                        if (features[45] /* FIO2_min */ <= 1.71905f) {
                                                            if (features[40] /* ART_DBP_min */ <= 0.04802f) {
                                                                if (features[27] /* BT_std */ <= -0.28055f) {
                                                                    return false; /* p_pos=0.035, tau=0.33 */
                                                                } else {
                                                                    return false; /* p_pos=0.004, tau=0.33 */
                                                                }
                                                            } else {
                                                                return false; /* p_pos=0.000, tau=0.33 */
                                                            }
                                                        } else {
                                                            if (features[68] /* Feature_Modified_Shock_Index_max */ <= -0.76330f) {
                                                                return true; /* p_pos=0.800, tau=0.33 */
                                                            } else {
                                                                if (features[9] /* Feature_Pulse_Pressure_mean */ <= -0.20887f) {
                                                                    return false; /* p_pos=0.222, tau=0.33 */
                                                                } else {
                                                                    return false; /* p_pos=0.009, tau=0.33 */
                                                                }
                                                            }
                                                        }
                                                    }
                                                } else {
                                                    if (features[44] /* ETCO2_min */ <= 0.04539f) {
                                                        return false; /* p_pos=0.000, tau=0.33 */
                                                    } else {
                                                        return true; /* p_pos=0.615, tau=0.33 */
                                                    }
                                                }
                                            } else {
                                                if (features[55] /* Feature_MBP_Std_60s_min */ <= 0.00476f) {
                                                    if (features[82] /* ETCO2_slope */ <= -0.88008f) {
                                                        return false; /* p_pos=0.176, tau=0.33 */
                                                    } else {
                                                        return false; /* p_pos=0.000, tau=0.33 */
                                                    }
                                                } else {
                                                    if (features[41] /* ART_MBP_min */ <= 0.33049f) {
                                                        return false; /* p_pos=0.000, tau=0.33 */
                                                    } else {
                                                        if (features[24] /* RR_CO2_std */ <= 0.11686f) {
                                                            if (features[78] /* ART_DBP_slope */ <= -0.12184f) {
                                                                return false; /* p_pos=0.053, tau=0.33 */
                                                            } else {
                                                                if (features[1] /* ART_SBP_mean */ <= 0.50290f) {
                                                                    return true; /* p_pos=1.000, tau=0.33 */
                                                                } else {
                                                                    return false; /* p_pos=0.312, tau=0.33 */
                                                                }
                                                            }
                                                        } else {
                                                            if (features[76] /* HR_slope */ <= 1.28031f) {
                                                                return false; /* p_pos=0.000, tau=0.33 */
                                                            } else {
                                                                return false; /* p_pos=0.200, tau=0.33 */
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        } else {
                                            if (features[9] /* Feature_Pulse_Pressure_mean */ <= 0.79403f) {
                                                if (features[83] /* FIO2_slope */ <= 0.36550f) {
                                                    return false; /* p_pos=0.000, tau=0.33 */
                                                } else {
                                                    return false; /* p_pos=0.200, tau=0.33 */
                                                }
                                            } else {
                                                if (features[4] /* PLETH_SPO2_mean */ <= 0.37547f) {
                                                    return false; /* p_pos=0.000, tau=0.33 */
                                                } else {
                                                    if (features[93] /* Feature_MBP_Std_60s_slope */ <= -0.38453f) {
                                                        return false; /* p_pos=0.111, tau=0.33 */
                                                    } else {
                                                        return true; /* p_pos=0.941, tau=0.33 */
                                                    }
                                                }
                                            }
                                        }
                                    } else {
                                        if (features[69] /* Feature_Rate_Pressure_Product_max */ <= 3.30926f) {
                                            if (features[7] /* FIO2_mean */ <= 0.70192f) {
                                                if (features[55] /* Feature_MBP_Std_60s_min */ <= 0.14930f) {
                                                    if (features[45] /* FIO2_min */ <= -0.49828f) {
                                                        if (features[14] /* Feature_HR_Std_60s_mean */ <= 0.08958f) {
                                                            if (features[46] /* BT_min */ <= 0.37905f) {
                                                                return false; /* p_pos=0.000, tau=0.33 */
                                                            } else {
                                                                return false; /* p_pos=0.174, tau=0.33 */
                                                            }
                                                        } else {
                                                            return true; /* p_pos=0.625, tau=0.33 */
                                                        }
                                                    } else {
                                                        return false; /* p_pos=0.000, tau=0.33 */
                                                    }
                                                } else {
                                                    if (features[57] /* HR_max */ <= 0.73167f) {
                                                        if (features[16] /* Feature_MBP_Mean_60s_mean */ <= 0.13944f) {
                                                            return true; /* p_pos=1.000, tau=0.33 */
                                                        } else {
                                                            if (features[7] /* FIO2_mean */ <= 0.02370f) {
                                                                return true; /* p_pos=0.833, tau=0.33 */
                                                            } else {
                                                                return false; /* p_pos=0.000, tau=0.33 */
                                                            }
                                                        }
                                                    } else {
                                                        return false; /* p_pos=0.000, tau=0.33 */
                                                    }
                                                }
                                            } else {
                                                if (features[50] /* Feature_Rate_Pressure_Product_min */ <= 0.28256f) {
                                                    return false; /* p_pos=0.200, tau=0.33 */
                                                } else {
                                                    return false; /* p_pos=0.000, tau=0.33 */
                                                }
                                            }
                                        } else {
                                            return true; /* p_pos=0.478, tau=0.33 */
                                        }
                                    }
                                }
                            }
                        } else {
                            if (features[16] /* Feature_MBP_Mean_60s_mean */ <= 0.77132f) {
                                if (features[62] /* RR_CO2_max */ <= 2.13049f) {
                                    if (features[30] /* Feature_Modified_Shock_Index_std */ <= 0.25061f) {
                                        if (features[76] /* HR_slope */ <= 0.67970f) {
                                            if (features[23] /* PLETH_SPO2_std */ <= -0.07912f) {
                                                if (features[10] /* Feature_Shock_Index_mean */ <= 7.81297f) {
                                                    if (features[10] /* Feature_Shock_Index_mean */ <= -0.75420f) {
                                                        if (features[55] /* Feature_MBP_Std_60s_min */ <= -0.00127f) {
                                                            if (features[44] /* ETCO2_min */ <= -2.63269f) {
                                                                return true; /* p_pos=0.522, tau=0.33 */
                                                            } else {
                                                                if (features[83] /* FIO2_slope */ <= 0.46872f) {
                                                                    return false; /* p_pos=0.085, tau=0.33 */
                                                                } else {
                                                                    return true; /* p_pos=0.667, tau=0.33 */
                                                                }
                                                            }
                                                        } else {
                                                            return false; /* p_pos=0.000, tau=0.33 */
                                                        }
                                                    } else {
                                                        if (features[66] /* Feature_Pulse_Pressure_max */ <= 1.39752f) {
                                                            if (features[11] /* Feature_Modified_Shock_Index_mean */ <= 0.32419f) {
                                                                if (features[20] /* ART_SBP_std */ <= 0.20727f) {
                                                                    return false; /* p_pos=0.033, tau=0.33 */
                                                                } else {
                                                                    return false; /* p_pos=0.007, tau=0.33 */
                                                                }
                                                            } else {
                                                                return false; /* p_pos=0.000, tau=0.33 */
                                                            }
                                                        } else {
                                                            if (features[47] /* Feature_Pulse_Pressure_min */ <= 0.49667f) {
                                                                if (features[66] /* Feature_Pulse_Pressure_max */ <= 1.54201f) {
                                                                    return false; /* p_pos=0.145, tau=0.33 */
                                                                } else {
                                                                    return false; /* p_pos=0.015, tau=0.33 */
                                                                }
                                                            } else {
                                                                if (features[2] /* ART_DBP_mean */ <= -0.22373f) {
                                                                    return false; /* p_pos=0.000, tau=0.33 */
                                                                } else {
                                                                    return false; /* p_pos=0.304, tau=0.33 */
                                                                }
                                                            }
                                                        }
                                                    }
                                                } else {
                                                    return true; /* p_pos=1.000, tau=0.33 */
                                                }
                                            } else {
                                                return false; /* p_pos=0.000, tau=0.33 */
                                            }
                                        } else {
                                            if (features[30] /* Feature_Modified_Shock_Index_std */ <= -0.34082f) {
                                                if (features[25] /* ETCO2_std */ <= 0.12004f) {
                                                    if (features[91] /* Feature_HR_Delta_60s_slope */ <= 0.53255f) {
                                                        if (features[7] /* FIO2_mean */ <= 2.21850f) {
                                                            return false; /* p_pos=0.250, tau=0.33 */
                                                        } else {
                                                            if (features[18] /* Feature_MBP_Delta_60s_mean */ <= -0.09627f) {
                                                                return true; /* p_pos=0.700, tau=0.33 */
                                                            } else {
                                                                return true; /* p_pos=1.000, tau=0.33 */
                                                            }
                                                        }
                                                    } else {
                                                        if (features[25] /* ETCO2_std */ <= -0.47044f) {
                                                            return false; /* p_pos=0.000, tau=0.33 */
                                                        } else {
                                                            return true; /* p_pos=0.381, tau=0.33 */
                                                        }
                                                    }
                                                } else {
                                                    if (features[52] /* Feature_HR_Std_60s_min */ <= 0.03970f) {
                                                        if (features[24] /* RR_CO2_std */ <= 1.38979f) {
                                                            return false; /* p_pos=0.000, tau=0.33 */
                                                        } else {
                                                            return true; /* p_pos=0.364, tau=0.33 */
                                                        }
                                                    } else {
                                                        return false; /* p_pos=0.000, tau=0.33 */
                                                    }
                                                }
                                            } else {
                                                if (features[89] /* Feature_HR_Mean_60s_slope */ <= 1.31725f) {
                                                    if (features[48] /* Feature_Shock_Index_min */ <= -0.34232f) {
                                                        if (features[56] /* Feature_MBP_Delta_60s_min */ <= 0.17287f) {
                                                            return false; /* p_pos=0.000, tau=0.33 */
                                                        } else {
                                                            if (features[27] /* BT_std */ <= -0.27145f) {
                                                                if (features[6] /* ETCO2_mean */ <= -0.60521f) {
                                                                    return false; /* p_pos=0.000, tau=0.33 */
                                                                } else {
                                                                    return true; /* p_pos=0.471, tau=0.33 */
                                                                }
                                                            } else {
                                                                if (features[2] /* ART_DBP_mean */ <= -0.48380f) {
                                                                    return false; /* p_pos=0.200, tau=0.33 */
                                                                } else {
                                                                    return false; /* p_pos=0.000, tau=0.33 */
                                                                }
                                                            }
                                                        }
                                                    } else {
                                                        return false; /* p_pos=0.000, tau=0.33 */
                                                    }
                                                } else {
                                                    if (features[69] /* Feature_Rate_Pressure_Product_max */ <= -0.39141f) {
                                                        return true; /* p_pos=0.500, tau=0.33 */
                                                    } else {
                                                        if (features[71] /* Feature_HR_Std_60s_max */ <= 1.78356f) {
                                                            if (features[4] /* PLETH_SPO2_mean */ <= 0.30598f) {
                                                                return false; /* p_pos=0.000, tau=0.33 */
                                                            } else {
                                                                if (features[90] /* Feature_HR_Std_60s_slope */ <= 3.89926f) {
                                                                    return false; /* p_pos=0.140, tau=0.33 */
                                                                } else {
                                                                    return true; /* p_pos=0.800, tau=0.33 */
                                                                }
                                                            }
                                                        } else {
                                                            return false; /* p_pos=0.000, tau=0.33 */
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    } else {
                                        if (features[47] /* Feature_Pulse_Pressure_min */ <= 0.60896f) {
                                            if (features[53] /* Feature_HR_Delta_60s_min */ <= 0.55213f) {
                                                if (features[0] /* HR_mean */ <= -1.94015f) {
                                                    return false; /* p_pos=0.200, tau=0.33 */
                                                } else {
                                                    if (features[83] /* FIO2_slope */ <= 0.43431f) {
                                                        return false; /* p_pos=0.000, tau=0.33 */
                                                    } else {
                                                        if (features[87] /* Feature_Modified_Shock_Index_slope */ <= 0.17008f) {
                                                            return false; /* p_pos=0.000, tau=0.33 */
                                                        } else {
                                                            if (features[47] /* Feature_Pulse_Pressure_min */ <= -1.38408f) {
                                                                return true; /* p_pos=0.400, tau=0.33 */
                                                            } else {
                                                                return false; /* p_pos=0.000, tau=0.33 */
                                                            }
                                                        }
                                                    }
                                                }
                                            } else {
                                                if (features[47] /* Feature_Pulse_Pressure_min */ <= -1.29986f) {
                                                    if (features[11] /* Feature_Modified_Shock_Index_mean */ <= -0.02967f) {
                                                        return true; /* p_pos=1.000, tau=0.33 */
                                                    } else {
                                                        if (features[9] /* Feature_Pulse_Pressure_mean */ <= -1.55577f) {
                                                            return true; /* p_pos=0.600, tau=0.33 */
                                                        } else {
                                                            return false; /* p_pos=0.000, tau=0.33 */
                                                        }
                                                    }
                                                } else {
                                                    return false; /* p_pos=0.000, tau=0.33 */
                                                }
                                            }
                                        } else {
                                            if (features[7] /* FIO2_mean */ <= 2.11859f) {
                                                if (features[43] /* RR_CO2_min */ <= -0.59314f) {
                                                    return true; /* p_pos=0.800, tau=0.33 */
                                                } else {
                                                    if (features[85] /* Feature_Pulse_Pressure_slope */ <= -0.20794f) {
                                                        return false; /* p_pos=0.200, tau=0.33 */
                                                    } else {
                                                        return false; /* p_pos=0.000, tau=0.33 */
                                                    }
                                                }
                                            } else {
                                                if (features[63] /* ETCO2_max */ <= -1.02037f) {
                                                    return false; /* p_pos=0.200, tau=0.33 */
                                                } else {
                                                    return false; /* p_pos=0.000, tau=0.33 */
                                                }
                                            }
                                        }
                                    }
                                } else {
                                    if (features[43] /* RR_CO2_min */ <= -2.16194f) {
                                        if (features[89] /* Feature_HR_Mean_60s_slope */ <= 2.90519f) {
                                            if (features[14] /* Feature_HR_Std_60s_mean */ <= 0.12796f) {
                                                if (features[16] /* Feature_MBP_Mean_60s_mean */ <= 0.03586f) {
                                                    return false; /* p_pos=0.000, tau=0.33 */
                                                } else {
                                                    if (features[4] /* PLETH_SPO2_mean */ <= 0.37669f) {
                                                        return true; /* p_pos=0.667, tau=0.33 */
                                                    } else {
                                                        return false; /* p_pos=0.000, tau=0.33 */
                                                    }
                                                }
                                            } else {
                                                return false; /* p_pos=0.000, tau=0.33 */
                                            }
                                        } else {
                                            return true; /* p_pos=0.375, tau=0.33 */
                                        }
                                    } else {
                                        if (features[30] /* Feature_Modified_Shock_Index_std */ <= 0.07878f) {
                                            if (features[89] /* Feature_HR_Mean_60s_slope */ <= 1.11134f) {
                                                if (features[72] /* Feature_HR_Delta_60s_max */ <= 1.89507f) {
                                                    if (features[1] /* ART_SBP_mean */ <= 0.20148f) {
                                                        if (features[53] /* Feature_HR_Delta_60s_min */ <= -1.28142f) {
                                                            return true; /* p_pos=0.800, tau=0.33 */
                                                        } else {
                                                            return false; /* p_pos=0.000, tau=0.33 */
                                                        }
                                                    } else {
                                                        if (features[48] /* Feature_Shock_Index_min */ <= -0.58089f) {
                                                            if (features[67] /* Feature_Shock_Index_max */ <= -0.79441f) {
                                                                return true; /* p_pos=1.000, tau=0.33 */
                                                            } else {
                                                                return false; /* p_pos=0.000, tau=0.33 */
                                                            }
                                                        } else {
                                                            if (features[52] /* Feature_HR_Std_60s_min */ <= 0.06492f) {
                                                                if (features[69] /* Feature_Rate_Pressure_Product_max */ <= -0.12344f) {
                                                                    return false; /* p_pos=0.200, tau=0.33 */
                                                                } else {
                                                                    return true; /* p_pos=0.943, tau=0.33 */
                                                                }
                                                            } else {
                                                                return false; /* p_pos=0.000, tau=0.33 */
                                                            }
                                                        }
                                                    }
                                                } else {
                                                    return true; /* p_pos=1.000, tau=0.33 */
                                                }
                                            } else {
                                                if (features[64] /* FIO2_max */ <= 1.77028f) {
                                                    return false; /* p_pos=0.000, tau=0.33 */
                                                } else {
                                                    if (features[52] /* Feature_HR_Std_60s_min */ <= 0.07515f) {
                                                        return true; /* p_pos=1.000, tau=0.33 */
                                                    } else {
                                                        return true; /* p_pos=0.700, tau=0.33 */
                                                    }
                                                }
                                            }
                                        } else {
                                            if (features[47] /* Feature_Pulse_Pressure_min */ <= -1.18758f) {
                                                if (features[70] /* Feature_HR_Mean_60s_max */ <= 1.56555f) {
                                                    if (features[15] /* Feature_HR_Delta_60s_mean */ <= 0.81333f) {
                                                        return false; /* p_pos=0.000, tau=0.33 */
                                                    } else {
                                                        return true; /* p_pos=0.667, tau=0.33 */
                                                    }
                                                } else {
                                                    return true; /* p_pos=0.941, tau=0.33 */
                                                }
                                            } else {
                                                if (features[52] /* Feature_HR_Std_60s_min */ <= 0.28214f) {
                                                    if (features[71] /* Feature_HR_Std_60s_max */ <= 3.57880f) {
                                                        return false; /* p_pos=0.000, tau=0.33 */
                                                    } else {
                                                        return false; /* p_pos=0.200, tau=0.33 */
                                                    }
                                                } else {
                                                    if (features[65] /* BT_max */ <= 0.20778f) {
                                                        return true; /* p_pos=0.467, tau=0.33 */
                                                    } else {
                                                        return false; /* p_pos=0.000, tau=0.33 */
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            } else {
                                if (features[65] /* BT_max */ <= 0.19132f) {
                                    if (features[5] /* RR_CO2_mean */ <= 0.36893f) {
                                        if (features[1] /* ART_SBP_mean */ <= 1.12326f) {
                                            if (features[49] /* Feature_Modified_Shock_Index_min */ <= -0.39102f) {
                                                if (features[1] /* ART_SBP_mean */ <= 0.98467f) {
                                                    return false; /* p_pos=0.000, tau=0.33 */
                                                } else {
                                                    return false; /* p_pos=0.125, tau=0.33 */
                                                }
                                            } else {
                                                if (features[24] /* RR_CO2_std */ <= 2.38586f) {
                                                    if (features[32] /* Feature_HR_Mean_60s_std */ <= 2.70330f) {
                                                        if (features[82] /* ETCO2_slope */ <= 0.24344f) {
                                                            return false; /* p_pos=0.000, tau=0.33 */
                                                        } else {
                                                            return false; /* p_pos=0.188, tau=0.33 */
                                                        }
                                                    } else {
                                                        return true; /* p_pos=0.600, tau=0.33 */
                                                    }
                                                } else {
                                                    if (features[40] /* ART_DBP_min */ <= 0.73722f) {
                                                        if (features[88] /* Feature_Rate_Pressure_Product_slope */ <= -0.07598f) {
                                                            return true; /* p_pos=0.600, tau=0.33 */
                                                        } else {
                                                            return true; /* p_pos=1.000, tau=0.33 */
                                                        }
                                                    } else {
                                                        return false; /* p_pos=0.167, tau=0.33 */
                                                    }
                                                }
                                            }
                                        } else {
                                            if (features[90] /* Feature_HR_Std_60s_slope */ <= -0.20140f) {
                                                if (features[94] /* Feature_MBP_Delta_60s_slope */ <= -0.59999f) {
                                                    return false; /* p_pos=0.000, tau=0.33 */
                                                } else {
                                                    if (features[92] /* Feature_MBP_Mean_60s_slope */ <= 0.40398f) {
                                                        if (features[49] /* Feature_Modified_Shock_Index_min */ <= -0.31239f) {
                                                            return false; /* p_pos=0.000, tau=0.33 */
                                                        } else {
                                                            return true; /* p_pos=0.429, tau=0.33 */
                                                        }
                                                    } else {
                                                        return true; /* p_pos=0.875, tau=0.33 */
                                                    }
                                                }
                                            } else {
                                                if (features[48] /* Feature_Shock_Index_min */ <= -1.07453f) {
                                                    return true; /* p_pos=1.000, tau=0.33 */
                                                } else {
                                                    if (features[52] /* Feature_HR_Std_60s_min */ <= 0.51794f) {
                                                        if (features[75] /* Feature_MBP_Delta_60s_max */ <= -0.00854f) {
                                                            if (features[70] /* Feature_HR_Mean_60s_max */ <= 0.90160f) {
                                                                if (features[87] /* Feature_Modified_Shock_Index_slope */ <= 0.15608f) {
                                                                    return true; /* p_pos=0.852, tau=0.33 */
                                                                } else {
                                                                    return false; /* p_pos=0.276, tau=0.33 */
                                                                }
                                                            } else {
                                                                return true; /* p_pos=1.000, tau=0.33 */
                                                            }
                                                        } else {
                                                            if (features[94] /* Feature_MBP_Delta_60s_slope */ <= -0.22582f) {
                                                                return false; /* p_pos=0.000, tau=0.33 */
                                                            } else {
                                                                return true; /* p_pos=0.450, tau=0.33 */
                                                            }
                                                        }
                                                    } else {
                                                        return false; /* p_pos=0.000, tau=0.33 */
                                                    }
                                                }
                                            }
                                        }
                                    } else {
                                        if (features[0] /* HR_mean */ <= -0.51113f) {
                                            if (features[69] /* Feature_Rate_Pressure_Product_max */ <= -0.41210f) {
                                                return true; /* p_pos=0.800, tau=0.33 */
                                            } else {
                                                if (features[82] /* ETCO2_slope */ <= -0.43067f) {
                                                    return true; /* p_pos=0.400, tau=0.33 */
                                                } else {
                                                    return false; /* p_pos=0.000, tau=0.33 */
                                                }
                                            }
                                        } else {
                                            if (features[4] /* PLETH_SPO2_mean */ <= 0.25051f) {
                                                return false; /* p_pos=0.000, tau=0.33 */
                                            } else {
                                                if (features[85] /* Feature_Pulse_Pressure_slope */ <= -2.55075f) {
                                                    return false; /* p_pos=0.143, tau=0.33 */
                                                } else {
                                                    if (features[33] /* Feature_HR_Std_60s_std */ <= 0.92696f) {
                                                        if (features[83] /* FIO2_slope */ <= -0.04738f) {
                                                            return true; /* p_pos=1.000, tau=0.33 */
                                                        } else {
                                                            if (features[90] /* Feature_HR_Std_60s_slope */ <= -0.41309f) {
                                                                return true; /* p_pos=0.444, tau=0.33 */
                                                            } else {
                                                                if (features[66] /* Feature_Pulse_Pressure_max */ <= 1.16633f) {
                                                                    return true; /* p_pos=0.781, tau=0.33 */
                                                                } else {
                                                                    return true; /* p_pos=1.000, tau=0.33 */
                                                                }
                                                            }
                                                        }
                                                    } else {
                                                        return true; /* p_pos=0.417, tau=0.33 */
                                                    }
                                                }
                                            }
                                        }
                                    }
                                } else {
                                    if (features[89] /* Feature_HR_Mean_60s_slope */ <= 1.23632f) {
                                        if (features[56] /* Feature_MBP_Delta_60s_min */ <= -1.08006f) {
                                            return false; /* p_pos=0.000, tau=0.33 */
                                        } else {
                                            if (features[57] /* HR_max */ <= -0.51287f) {
                                                if (features[9] /* Feature_Pulse_Pressure_mean */ <= 0.65020f) {
                                                    if (features[3] /* ART_MBP_mean */ <= 0.86847f) {
                                                        return true; /* p_pos=0.500, tau=0.33 */
                                                    } else {
                                                        return false; /* p_pos=0.000, tau=0.33 */
                                                    }
                                                } else {
                                                    if (features[55] /* Feature_MBP_Std_60s_min */ <= 0.10467f) {
                                                        if (features[59] /* ART_DBP_max */ <= 0.65931f) {
                                                            return true; /* p_pos=0.357, tau=0.33 */
                                                        } else {
                                                            return true; /* p_pos=1.000, tau=0.33 */
                                                        }
                                                    } else {
                                                        return false; /* p_pos=0.000, tau=0.33 */
                                                    }
                                                }
                                            } else {
                                                if (features[56] /* Feature_MBP_Delta_60s_min */ <= -1.06078f) {
                                                    return true; /* p_pos=1.000, tau=0.33 */
                                                } else {
                                                    if (features[12] /* Feature_Rate_Pressure_Product_mean */ <= 2.17346f) {
                                                        if (features[52] /* Feature_HR_Std_60s_min */ <= 3.09532f) {
                                                            if (features[85] /* Feature_Pulse_Pressure_slope */ <= 1.01160f) {
                                                                if (features[50] /* Feature_Rate_Pressure_Product_min */ <= 1.54126f) {
                                                                    return false; /* p_pos=0.000, tau=0.33 */
                                                                } else {
                                                                    return false; /* p_pos=0.133, tau=0.33 */
                                                                }
                                                            } else {
                                                                if (features[63] /* ETCO2_max */ <= 0.95712f) {
                                                                    return false; /* p_pos=0.000, tau=0.33 */
                                                                } else {
                                                                    return false; /* p_pos=0.250, tau=0.33 */
                                                                }
                                                            }
                                                        } else {
                                                            return true; /* p_pos=0.600, tau=0.33 */
                                                        }
                                                    } else {
                                                        if (features[11] /* Feature_Modified_Shock_Index_mean */ <= -0.15408f) {
                                                            return true; /* p_pos=0.750, tau=0.33 */
                                                        } else {
                                                            if (features[68] /* Feature_Modified_Shock_Index_max */ <= 0.84481f) {
                                                                return false; /* p_pos=0.000, tau=0.33 */
                                                            } else {
                                                                return false; /* p_pos=0.200, tau=0.33 */
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    } else {
                                        if (features[51] /* Feature_HR_Mean_60s_min */ <= 1.03318f) {
                                            if (features[59] /* ART_DBP_max */ <= 0.80469f) {
                                                return false; /* p_pos=0.000, tau=0.33 */
                                            } else {
                                                if (features[89] /* Feature_HR_Mean_60s_slope */ <= 3.33409f) {
                                                    if (features[71] /* Feature_HR_Std_60s_max */ <= 1.10888f) {
                                                        if (features[62] /* RR_CO2_max */ <= 2.25623f) {
                                                            if (features[65] /* BT_max */ <= 0.32306f) {
                                                                if (features[5] /* RR_CO2_mean */ <= 0.59774f) {
                                                                    return false; /* p_pos=0.000, tau=0.33 */
                                                                } else {
                                                                    return true; /* p_pos=0.400, tau=0.33 */
                                                                }
                                                            } else {
                                                                return true; /* p_pos=0.545, tau=0.33 */
                                                            }
                                                        } else {
                                                            return true; /* p_pos=1.000, tau=0.33 */
                                                        }
                                                    } else {
                                                        if (features[79] /* ART_MBP_slope */ <= 1.64088f) {
                                                            return false; /* p_pos=0.000, tau=0.33 */
                                                        } else {
                                                            return false; /* p_pos=0.200, tau=0.33 */
                                                        }
                                                    }
                                                } else {
                                                    return true; /* p_pos=0.765, tau=0.33 */
                                                }
                                            }
                                        } else {
                                            return true; /* p_pos=1.000, tau=0.33 */
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
        if (features[45] /* FIO2_min */ <= -0.90673f) {
            if (features[50] /* Feature_Rate_Pressure_Product_min */ <= -0.49181f) {
                if (features[80] /* PLETH_SPO2_slope */ <= -1.89284f) {
                    if (features[38] /* HR_min */ <= -0.57340f) {
                        return true; /* p_pos=0.913, tau=0.33 */
                    } else {
                        return true; /* p_pos=0.389, tau=0.33 */
                    }
                } else {
                    if (features[43] /* RR_CO2_min */ <= -0.85461f) {
                        if (features[72] /* Feature_HR_Delta_60s_max */ <= 2.73241f) {
                            if (features[29] /* Feature_Shock_Index_std */ <= -0.69313f) {
                                if (features[8] /* BT_mean */ <= 0.46446f) {
                                    if (features[52] /* Feature_HR_Std_60s_min */ <= 2.82549f) {
                                        if (features[70] /* Feature_HR_Mean_60s_max */ <= 0.00207f) {
                                            if (features[7] /* FIO2_mean */ <= 0.78740f) {
                                                return false; /* p_pos=0.000, tau=0.33 */
                                            } else {
                                                if (features[82] /* ETCO2_slope */ <= -0.20597f) {
                                                    return true; /* p_pos=0.429, tau=0.33 */
                                                } else {
                                                    if (features[91] /* Feature_HR_Delta_60s_slope */ <= 1.41599f) {
                                                        if (features[57] /* HR_max */ <= -1.21543f) {
                                                            return false; /* p_pos=0.200, tau=0.33 */
                                                        } else {
                                                            return false; /* p_pos=0.000, tau=0.33 */
                                                        }
                                                    } else {
                                                        return true; /* p_pos=0.333, tau=0.33 */
                                                    }
                                                }
                                            }
                                        } else {
                                            if (features[24] /* RR_CO2_std */ <= 2.01012f) {
                                                if (features[0] /* HR_mean */ <= -0.41083f) {
                                                    return true; /* p_pos=0.727, tau=0.33 */
                                                } else {
                                                    if (features[32] /* Feature_HR_Mean_60s_std */ <= -0.65890f) {
                                                        return true; /* p_pos=0.667, tau=0.33 */
                                                    } else {
                                                        if (features[45] /* FIO2_min */ <= -0.96508f) {
                                                            if (features[76] /* HR_slope */ <= -1.26073f) {
                                                                return false; /* p_pos=0.300, tau=0.33 */
                                                            } else {
                                                                if (features[7] /* FIO2_mean */ <= 1.78904f) {
                                                                    return false; /* p_pos=0.013, tau=0.33 */
                                                                } else {
                                                                    return true; /* p_pos=0.400, tau=0.33 */
                                                                }
                                                            }
                                                        } else {
                                                            return true; /* p_pos=0.556, tau=0.33 */
                                                        }
                                                    }
                                                }
                                            } else {
                                                if (features[71] /* Feature_HR_Std_60s_max */ <= -0.06885f) {
                                                    return false; /* p_pos=0.167, tau=0.33 */
                                                } else {
                                                    return false; /* p_pos=0.000, tau=0.33 */
                                                }
                                            }
                                        }
                                    } else {
                                        return true; /* p_pos=0.462, tau=0.33 */
                                    }
                                } else {
                                    return true; /* p_pos=0.875, tau=0.33 */
                                }
                            } else {
                                if (features[4] /* PLETH_SPO2_mean */ <= -2.71815f) {
                                    if (features[67] /* Feature_Shock_Index_max */ <= 4.89762f) {
                                        if (features[82] /* ETCO2_slope */ <= 3.38931f) {
                                            if (features[12] /* Feature_Rate_Pressure_Product_mean */ <= 0.15852f) {
                                                return false; /* p_pos=0.000, tau=0.33 */
                                            } else {
                                                return false; /* p_pos=0.200, tau=0.33 */
                                            }
                                        } else {
                                            return true; /* p_pos=0.571, tau=0.33 */
                                        }
                                    } else {
                                        return true; /* p_pos=1.000, tau=0.33 */
                                    }
                                } else {
                                    if (features[17] /* Feature_MBP_Std_60s_mean */ <= 1.08767f) {
                                        if (features[36] /* Feature_MBP_Std_60s_std */ <= 1.65233f) {
                                            if (features[82] /* ETCO2_slope */ <= 7.65870f) {
                                                if (features[39] /* ART_SBP_min */ <= 0.20013f) {
                                                    if (features[12] /* Feature_Rate_Pressure_Product_mean */ <= -1.96785f) {
                                                        if (features[56] /* Feature_MBP_Delta_60s_min */ <= 0.92463f) {
                                                            return false; /* p_pos=0.000, tau=0.33 */
                                                        } else {
                                                            if (features[18] /* Feature_MBP_Delta_60s_mean */ <= 4.90414f) {
                                                                if (features[69] /* Feature_Rate_Pressure_Product_max */ <= -1.15603f) {
                                                                    return false; /* p_pos=0.037, tau=0.33 */
                                                                } else {
                                                                    return true; /* p_pos=0.500, tau=0.33 */
                                                                }
                                                            } else {
                                                                return false; /* p_pos=0.000, tau=0.33 */
                                                            }
                                                        }
                                                    } else {
                                                        if (features[92] /* Feature_MBP_Mean_60s_slope */ <= -3.09423f) {
                                                            return false; /* p_pos=0.091, tau=0.33 */
                                                        } else {
                                                            return false; /* p_pos=0.000, tau=0.33 */
                                                        }
                                                    }
                                                } else {
                                                    return false; /* p_pos=0.286, tau=0.33 */
                                                }
                                            } else {
                                                if (features[81] /* RR_CO2_slope */ <= 2.98807f) {
                                                    return false; /* p_pos=0.000, tau=0.33 */
                                                } else {
                                                    return true; /* p_pos=0.714, tau=0.33 */
                                                }
                                            }
                                        } else {
                                            return true; /* p_pos=0.357, tau=0.33 */
                                        }
                                    } else {
                                        return false; /* p_pos=0.000, tau=0.33 */
                                    }
                                }
                            }
                        } else {
                            return true; /* p_pos=0.500, tau=0.33 */
                        }
                    } else {
                        if (features[67] /* Feature_Shock_Index_max */ <= 0.61933f) {
                            if (features[24] /* RR_CO2_std */ <= -0.48061f) {
                                if (features[90] /* Feature_HR_Std_60s_slope */ <= 0.31005f) {
                                    return true; /* p_pos=0.435, tau=0.33 */
                                } else {
                                    return true; /* p_pos=1.000, tau=0.33 */
                                }
                            } else {
                                if (features[57] /* HR_max */ <= 0.63130f) {
                                    if (features[33] /* Feature_HR_Std_60s_std */ <= -0.66976f) {
                                        return false; /* p_pos=0.200, tau=0.33 */
                                    } else {
                                        return false; /* p_pos=0.000, tau=0.33 */
                                    }
                                } else {
                                    return true; /* p_pos=0.733, tau=0.33 */
                                }
                            }
                        } else {
                            if (features[77] /* ART_SBP_slope */ <= -2.64068f) {
                                return true; /* p_pos=0.400, tau=0.33 */
                            } else {
                                if (features[17] /* Feature_MBP_Std_60s_mean */ <= 1.94208f) {
                                    return false; /* p_pos=0.000, tau=0.33 */
                                } else {
                                    return false; /* p_pos=0.067, tau=0.33 */
                                }
                            }
                        }
                    }
                }
            } else {
                if (features[36] /* Feature_MBP_Std_60s_std */ <= -0.58727f) {
                    if (features[80] /* PLETH_SPO2_slope */ <= -2.96353f) {
                        return true; /* p_pos=0.667, tau=0.33 */
                    } else {
                        if (features[26] /* FIO2_std */ <= 2.12868f) {
                            if (features[1] /* ART_SBP_mean */ <= -0.75819f) {
                                return false; /* p_pos=0.200, tau=0.33 */
                            } else {
                                return false; /* p_pos=0.000, tau=0.33 */
                            }
                        } else {
                            return false; /* p_pos=0.000, tau=0.33 */
                        }
                    }
                } else {
                    if (features[6] /* ETCO2_mean */ <= -1.15250f) {
                        if (features[80] /* PLETH_SPO2_slope */ <= -0.82215f) {
                            return true; /* p_pos=0.556, tau=0.33 */
                        } else {
                            return false; /* p_pos=0.000, tau=0.33 */
                        }
                    } else {
                        if (features[92] /* Feature_MBP_Mean_60s_slope */ <= 0.48471f) {
                            if (features[49] /* Feature_Modified_Shock_Index_min */ <= 1.76877f) {
                                if (features[43] /* RR_CO2_min */ <= -0.59314f) {
                                    if (features[46] /* BT_min */ <= 0.13580f) {
                                        return false; /* p_pos=0.000, tau=0.33 */
                                    } else {
                                        if (features[51] /* Feature_HR_Mean_60s_min */ <= -0.21194f) {
                                            if (features[33] /* Feature_HR_Std_60s_std */ <= -0.63275f) {
                                                return false; /* p_pos=0.200, tau=0.33 */
                                            } else {
                                                return false; /* p_pos=0.000, tau=0.33 */
                                            }
                                        } else {
                                            if (features[42] /* PLETH_SPO2_min */ <= -4.34165f) {
                                                return true; /* p_pos=1.000, tau=0.33 */
                                            } else {
                                                if (features[44] /* ETCO2_min */ <= -2.49878f) {
                                                    if (features[15] /* Feature_HR_Delta_60s_mean */ <= -1.34205f) {
                                                        return true; /* p_pos=0.400, tau=0.33 */
                                                    } else {
                                                        return false; /* p_pos=0.000, tau=0.33 */
                                                    }
                                                } else {
                                                    if (features[12] /* Feature_Rate_Pressure_Product_mean */ <= 0.60267f) {
                                                        return true; /* p_pos=0.864, tau=0.33 */
                                                    } else {
                                                        return false; /* p_pos=0.056, tau=0.33 */
                                                    }
                                                }
                                            }
                                        }
                                    }
                                } else {
                                    if (features[1] /* ART_SBP_mean */ <= 1.22734f) {
                                        if (features[83] /* FIO2_slope */ <= 4.15020f) {
                                            if (features[45] /* FIO2_min */ <= -1.37354f) {
                                                return false; /* p_pos=0.000, tau=0.33 */
                                            } else {
                                                if (features[88] /* Feature_Rate_Pressure_Product_slope */ <= 0.62551f) {
                                                    if (features[48] /* Feature_Shock_Index_min */ <= 0.45316f) {
                                                        if (features[55] /* Feature_MBP_Std_60s_min */ <= -0.15256f) {
                                                            return true; /* p_pos=1.000, tau=0.33 */
                                                        } else {
                                                            if (features[27] /* BT_std */ <= -0.27160f) {
                                                                return true; /* p_pos=0.778, tau=0.33 */
                                                            } else {
                                                                return false; /* p_pos=0.118, tau=0.33 */
                                                            }
                                                        }
                                                    } else {
                                                        return false; /* p_pos=0.000, tau=0.33 */
                                                    }
                                                } else {
                                                    return false; /* p_pos=0.000, tau=0.33 */
                                                }
                                            }
                                        } else {
                                            if (features[1] /* ART_SBP_mean */ <= 0.42159f) {
                                                return false; /* p_pos=0.250, tau=0.33 */
                                            } else {
                                                return true; /* p_pos=1.000, tau=0.33 */
                                            }
                                        }
                                    } else {
                                        return true; /* p_pos=0.905, tau=0.33 */
                                    }
                                }
                            } else {
                                return true; /* p_pos=0.826, tau=0.33 */
                            }
                        } else {
                            if (features[41] /* ART_MBP_min */ <= 0.75089f) {
                                if (features[70] /* Feature_HR_Mean_60s_max */ <= -0.43382f) {
                                    return true; /* p_pos=1.000, tau=0.33 */
                                } else {
                                    if (features[51] /* Feature_HR_Mean_60s_min */ <= -0.25695f) {
                                        return false; /* p_pos=0.000, tau=0.33 */
                                    } else {
                                        if (features[11] /* Feature_Modified_Shock_Index_mean */ <= 0.21805f) {
                                            if (features[57] /* HR_max */ <= 0.33020f) {
                                                return false; /* p_pos=0.292, tau=0.33 */
                                            } else {
                                                if (features[0] /* HR_mean */ <= 0.27140f) {
                                                    return true; /* p_pos=0.800, tau=0.33 */
                                                } else {
                                                    return true; /* p_pos=1.000, tau=0.33 */
                                                }
                                            }
                                        } else {
                                            if (features[20] /* ART_SBP_std */ <= 0.64852f) {
                                                return false; /* p_pos=0.273, tau=0.33 */
                                            } else {
                                                return false; /* p_pos=0.000, tau=0.33 */
                                            }
                                        }
                                    }
                                }
                            } else {
                                if (features[75] /* Feature_MBP_Delta_60s_max */ <= -0.44518f) {
                                    return false; /* p_pos=0.250, tau=0.33 */
                                } else {
                                    if (features[46] /* BT_min */ <= 0.34662f) {
                                        if (features[3] /* ART_MBP_mean */ <= 1.81493f) {
                                            return true; /* p_pos=1.000, tau=0.33 */
                                        } else {
                                            return true; /* p_pos=0.750, tau=0.33 */
                                        }
                                    } else {
                                        return true; /* p_pos=0.538, tau=0.33 */
                                    }
                                }
                            }
                        }
                    }
                }
            }
        } else {
            if (features[83] /* FIO2_slope */ <= 3.11801f) {
                if (features[59] /* ART_DBP_max */ <= 0.51393f) {
                    if (features[80] /* PLETH_SPO2_slope */ <= -5.10491f) {
                        if (features[70] /* Feature_HR_Mean_60s_max */ <= -0.64354f) {
                            return true; /* p_pos=0.800, tau=0.33 */
                        } else {
                            return true; /* p_pos=1.000, tau=0.33 */
                        }
                    } else {
                        if (features[43] /* RR_CO2_min */ <= -1.11608f) {
                            if (features[10] /* Feature_Shock_Index_mean */ <= 1.08950f) {
                                if (features[84] /* BT_slope */ <= -1.50556f) {
                                    if (features[71] /* Feature_HR_Std_60s_max */ <= -0.55677f) {
                                        if (features[15] /* Feature_HR_Delta_60s_mean */ <= -0.33435f) {
                                            return true; /* p_pos=0.400, tau=0.33 */
                                        } else {
                                            return false; /* p_pos=0.000, tau=0.33 */
                                        }
                                    } else {
                                        if (features[85] /* Feature_Pulse_Pressure_slope */ <= 0.04880f) {
                                            return true; /* p_pos=1.000, tau=0.33 */
                                        } else {
                                            return true; /* p_pos=0.500, tau=0.33 */
                                        }
                                    }
                                } else {
                                    if (features[80] /* PLETH_SPO2_slope */ <= -0.82215f) {
                                        if (features[19] /* HR_std */ <= -0.31459f) {
                                            return false; /* p_pos=0.000, tau=0.33 */
                                        } else {
                                            if (features[40] /* ART_DBP_min */ <= -1.16498f) {
                                                return true; /* p_pos=0.933, tau=0.33 */
                                            } else {
                                                if (features[45] /* FIO2_min */ <= -0.03147f) {
                                                    return false; /* p_pos=0.050, tau=0.33 */
                                                } else {
                                                    if (features[8] /* BT_mean */ <= 0.26523f) {
                                                        return false; /* p_pos=0.154, tau=0.33 */
                                                    } else {
                                                        return true; /* p_pos=0.682, tau=0.33 */
                                                    }
                                                }
                                            }
                                        }
                                    } else {
                                        if (features[51] /* Feature_HR_Mean_60s_min */ <= -0.62153f) {
                                            if (features[15] /* Feature_HR_Delta_60s_mean */ <= 2.73934f) {
                                                if (features[71] /* Feature_HR_Std_60s_max */ <= -0.84408f) {
                                                    return true; /* p_pos=0.800, tau=0.33 */
                                                } else {
                                                    if (features[6] /* ETCO2_mean */ <= -0.63988f) {
                                                        return false; /* p_pos=0.000, tau=0.33 */
                                                    } else {
                                                        if (features[27] /* BT_std */ <= -0.23303f) {
                                                            if (features[27] /* BT_std */ <= -0.27083f) {
                                                                if (features[6] /* ETCO2_mean */ <= -0.40743f) {
                                                                    return false; /* p_pos=0.133, tau=0.33 */
                                                                } else {
                                                                    return false; /* p_pos=0.000, tau=0.33 */
                                                                }
                                                            } else {
                                                                if (features[48] /* Feature_Shock_Index_min */ <= -0.89482f) {
                                                                    return true; /* p_pos=0.857, tau=0.33 */
                                                                } else {
                                                                    return false; /* p_pos=0.120, tau=0.33 */
                                                                }
                                                            }
                                                        } else {
                                                            return false; /* p_pos=0.000, tau=0.33 */
                                                        }
                                                    }
                                                }
                                            } else {
                                                return true; /* p_pos=0.833, tau=0.33 */
                                            }
                                        } else {
                                            if (features[83] /* FIO2_slope */ <= 2.01701f) {
                                                if (features[66] /* Feature_Pulse_Pressure_max */ <= 1.05073f) {
                                                    if (features[62] /* RR_CO2_max */ <= 5.39974f) {
                                                        if (features[25] /* ETCO2_std */ <= 1.23050f) {
                                                            if (features[68] /* Feature_Modified_Shock_Index_max */ <= -0.12377f) {
                                                                if (features[68] /* Feature_Modified_Shock_Index_max */ <= -0.21644f) {
                                                                    return false; /* p_pos=0.094, tau=0.33 */
                                                                } else {
                                                                    return true; /* p_pos=0.800, tau=0.33 */
                                                                }
                                                            } else {
                                                                if (features[52] /* Feature_HR_Std_60s_min */ <= 1.19073f) {
                                                                    return false; /* p_pos=0.000, tau=0.33 */
                                                                } else {
                                                                    return false; /* p_pos=0.200, tau=0.33 */
                                                                }
                                                            }
                                                        } else {
                                                            return false; /* p_pos=0.000, tau=0.33 */
                                                        }
                                                    } else {
                                                        return true; /* p_pos=0.400, tau=0.33 */
                                                    }
                                                } else {
                                                    if (features[6] /* ETCO2_mean */ <= 0.18665f) {
                                                        if (features[73] /* Feature_MBP_Mean_60s_max */ <= -0.56497f) {
                                                            return true; /* p_pos=0.400, tau=0.33 */
                                                        } else {
                                                            return false; /* p_pos=0.000, tau=0.33 */
                                                        }
                                                    } else {
                                                        return true; /* p_pos=0.455, tau=0.33 */
                                                    }
                                                }
                                            } else {
                                                if (features[46] /* BT_min */ <= -0.07503f) {
                                                    if (features[93] /* Feature_MBP_Std_60s_slope */ <= 0.03379f) {
                                                        if (features[69] /* Feature_Rate_Pressure_Product_max */ <= -1.39534f) {
                                                            return false; /* p_pos=0.167, tau=0.33 */
                                                        } else {
                                                            return false; /* p_pos=0.000, tau=0.33 */
                                                        }
                                                    } else {
                                                        if (features[52] /* Feature_HR_Std_60s_min */ <= -0.05564f) {
                                                            return false; /* p_pos=0.000, tau=0.33 */
                                                        } else {
                                                            return true; /* p_pos=0.350, tau=0.33 */
                                                        }
                                                    }
                                                } else {
                                                    if (features[11] /* Feature_Modified_Shock_Index_mean */ <= 1.22501f) {
                                                        if (features[64] /* FIO2_max */ <= 1.79253f) {
                                                            if (features[7] /* FIO2_mean */ <= -0.08440f) {
                                                                if (features[48] /* Feature_Shock_Index_min */ <= 0.32661f) {
                                                                    return true; /* p_pos=0.545, tau=0.33 */
                                                                } else {
                                                                    return false; /* p_pos=0.000, tau=0.33 */
                                                                }
                                                            } else {
                                                                if (features[52] /* Feature_HR_Std_60s_min */ <= 0.35038f) {
                                                                    return false; /* p_pos=0.000, tau=0.33 */
                                                                } else {
                                                                    return false; /* p_pos=0.231, tau=0.33 */
                                                                }
                                                            }
                                                        } else {
                                                            if (features[39] /* ART_SBP_min */ <= -0.15992f) {
                                                                if (features[37] /* Feature_MBP_Delta_60s_std */ <= -0.31736f) {
                                                                    return true; /* p_pos=0.758, tau=0.33 */
                                                                } else {
                                                                    return false; /* p_pos=0.176, tau=0.33 */
                                                                }
                                                            } else {
                                                                if (features[41] /* ART_MBP_min */ <= 0.65747f) {
                                                                    return false; /* p_pos=0.000, tau=0.33 */
                                                                } else {
                                                                    return true; /* p_pos=0.625, tau=0.33 */
                                                                }
                                                            }
                                                        }
                                                    } else {
                                                        return true; /* p_pos=1.000, tau=0.33 */
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            } else {
                                if (features[23] /* PLETH_SPO2_std */ <= 7.69247f) {
                                    if (features[53] /* Feature_HR_Delta_60s_min */ <= 0.13894f) {
                                        return false; /* p_pos=0.000, tau=0.33 */
                                    } else {
                                        if (features[10] /* Feature_Shock_Index_mean */ <= 1.27834f) {
                                            return false; /* p_pos=0.214, tau=0.33 */
                                        } else {
                                            if (features[15] /* Feature_HR_Delta_60s_mean */ <= -1.55370f) {
                                                return false; /* p_pos=0.222, tau=0.33 */
                                            } else {
                                                return false; /* p_pos=0.000, tau=0.33 */
                                            }
                                        }
                                    }
                                } else {
                                    return false; /* p_pos=0.286, tau=0.33 */
                                }
                            }
                        } else {
                            if (features[68] /* Feature_Modified_Shock_Index_max */ <= -1.17287f) {
                                if (features[6] /* ETCO2_mean */ <= -1.39557f) {
                                    return false; /* p_pos=0.087, tau=0.33 */
                                } else {
                                    if (features[6] /* ETCO2_mean */ <= 1.75209f) {
                                        if (features[8] /* BT_mean */ <= -0.02068f) {
                                            if (features[53] /* Feature_HR_Delta_60s_min */ <= 0.60378f) {
                                                return true; /* p_pos=1.000, tau=0.33 */
                                            } else {
                                                return true; /* p_pos=0.769, tau=0.33 */
                                            }
                                        } else {
                                            if (features[25] /* ETCO2_std */ <= -0.56722f) {
                                                return false; /* p_pos=0.000, tau=0.33 */
                                            } else {
                                                if (features[6] /* ETCO2_mean */ <= -0.21245f) {
                                                    if (features[83] /* FIO2_slope */ <= 1.98260f) {
                                                        return false; /* p_pos=0.188, tau=0.33 */
                                                    } else {
                                                        return true; /* p_pos=0.667, tau=0.33 */
                                                    }
                                                } else {
                                                    if (features[27] /* BT_std */ <= -0.27175f) {
                                                        return true; /* p_pos=0.952, tau=0.33 */
                                                    } else {
                                                        if (features[63] /* ETCO2_max */ <= 0.75937f) {
                                                            if (features[57] /* HR_max */ <= -0.61324f) {
                                                                return true; /* p_pos=1.000, tau=0.33 */
                                                            } else {
                                                                if (features[65] /* BT_max */ <= 0.17485f) {
                                                                    return false; /* p_pos=0.143, tau=0.33 */
                                                                } else {
                                                                    return true; /* p_pos=0.786, tau=0.33 */
                                                                }
                                                            }
                                                        } else {
                                                            return true; /* p_pos=0.357, tau=0.33 */
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    } else {
                                        return false; /* p_pos=0.000, tau=0.33 */
                                    }
                                }
                            } else {
                                if (features[93] /* Feature_MBP_Std_60s_slope */ <= 0.03219f) {
                                    if (features[42] /* PLETH_SPO2_min */ <= -3.56179f) {
                                        if (features[55] /* Feature_MBP_Std_60s_min */ <= 0.20433f) {
                                            if (features[7] /* FIO2_mean */ <= 0.52708f) {
                                                return true; /* p_pos=0.583, tau=0.33 */
                                            } else {
                                                return true; /* p_pos=1.000, tau=0.33 */
                                            }
                                        } else {
                                            return false; /* p_pos=0.263, tau=0.33 */
                                        }
                                    } else {
                                        if (features[2] /* ART_DBP_mean */ <= -0.98157f) {
                                            if (features[76] /* HR_slope */ <= 1.41891f) {
                                                return false; /* p_pos=0.000, tau=0.33 */
                                            } else {
                                                return false; /* p_pos=0.200, tau=0.33 */
                                            }
                                        } else {
                                            if (features[80] /* PLETH_SPO2_slope */ <= 0.24855f) {
                                                if (features[86] /* Feature_Shock_Index_slope */ <= -0.10765f) {
                                                    if (features[86] /* Feature_Shock_Index_slope */ <= -1.21850f) {
                                                        return false; /* p_pos=0.000, tau=0.33 */
                                                    } else {
                                                        if (features[72] /* Feature_HR_Delta_60s_max */ <= 4.05185f) {
                                                            if (features[55] /* Feature_MBP_Std_60s_min */ <= 0.08825f) {
                                                                if (features[25] /* ETCO2_std */ <= -0.54413f) {
                                                                    return true; /* p_pos=0.889, tau=0.33 */
                                                                } else {
                                                                    return false; /* p_pos=0.213, tau=0.33 */
                                                                }
                                                            } else {
                                                                if (features[58] /* ART_SBP_max */ <= -0.40959f) {
                                                                    return false; /* p_pos=0.000, tau=0.33 */
                                                                } else {
                                                                    return true; /* p_pos=0.508, tau=0.33 */
                                                                }
                                                            }
                                                        } else {
                                                            return true; /* p_pos=1.000, tau=0.33 */
                                                        }
                                                    }
                                                } else {
                                                    if (features[64] /* FIO2_max */ <= 1.74803f) {
                                                        if (features[30] /* Feature_Modified_Shock_Index_std */ <= 0.32863f) {
                                                            if (features[7] /* FIO2_mean */ <= 0.60183f) {
                                                                if (features[52] /* Feature_HR_Std_60s_min */ <= 0.24987f) {
                                                                    return false; /* p_pos=0.130, tau=0.33 */
                                                                } else {
                                                                    return true; /* p_pos=0.444, tau=0.33 */
                                                                }
                                                            } else {
                                                                if (features[55] /* Feature_MBP_Std_60s_min */ <= -0.31067f) {
                                                                    return true; /* p_pos=0.400, tau=0.33 */
                                                                } else {
                                                                    return false; /* p_pos=0.007, tau=0.33 */
                                                                }
                                                            }
                                                        } else {
                                                            return false; /* p_pos=0.000, tau=0.33 */
                                                        }
                                                    } else {
                                                        if (features[40] /* ART_DBP_min */ <= 0.21343f) {
                                                            if (features[93] /* Feature_MBP_Std_60s_slope */ <= 0.01391f) {
                                                                if (features[20] /* ART_SBP_std */ <= -0.51722f) {
                                                                    return true; /* p_pos=1.000, tau=0.33 */
                                                                } else {
                                                                    return false; /* p_pos=0.254, tau=0.33 */
                                                                }
                                                            } else {
                                                                return true; /* p_pos=0.909, tau=0.33 */
                                                            }
                                                        } else {
                                                            if (features[46] /* BT_min */ <= 0.03038f) {
                                                                return true; /* p_pos=0.500, tau=0.33 */
                                                            } else {
                                                                return false; /* p_pos=0.000, tau=0.33 */
                                                            }
                                                        }
                                                    }
                                                }
                                            } else {
                                                if (features[84] /* BT_slope */ <= -0.75028f) {
                                                    return true; /* p_pos=0.400, tau=0.33 */
                                                } else {
                                                    if (features[27] /* BT_std */ <= -0.23837f) {
                                                        if (features[49] /* Feature_Modified_Shock_Index_min */ <= 3.20462f) {
                                                            if (features[6] /* ETCO2_mean */ <= 0.29737f) {
                                                                if (features[33] /* Feature_HR_Std_60s_std */ <= -0.68142f) {
                                                                    return true; /* p_pos=0.714, tau=0.33 */
                                                                } else {
                                                                    return false; /* p_pos=0.120, tau=0.33 */
                                                                }
                                                            } else {
                                                                if (features[88] /* Feature_Rate_Pressure_Product_slope */ <= 1.02045f) {
                                                                    return false; /* p_pos=0.000, tau=0.33 */
                                                                } else {
                                                                    return false; /* p_pos=0.200, tau=0.33 */
                                                                }
                                                            }
                                                        } else {
                                                            return true; /* p_pos=0.800, tau=0.33 */
                                                        }
                                                    } else {
                                                        return false; /* p_pos=0.000, tau=0.33 */
                                                    }
                                                }
                                            }
                                        }
                                    }
                                } else {
                                    if (features[44] /* ETCO2_min */ <= -0.08852f) {
                                        if (features[30] /* Feature_Modified_Shock_Index_std */ <= 0.49145f) {
                                            if (features[23] /* PLETH_SPO2_std */ <= 3.10598f) {
                                                if (features[64] /* FIO2_max */ <= 1.70353f) {
                                                    if (features[76] /* HR_slope */ <= -0.05951f) {
                                                        if (features[53] /* Feature_HR_Delta_60s_min */ <= 0.39719f) {
                                                            return false; /* p_pos=0.000, tau=0.33 */
                                                        } else {
                                                            if (features[34] /* Feature_HR_Delta_60s_std */ <= -0.53600f) {
                                                                if (features[29] /* Feature_Shock_Index_std */ <= -0.51640f) {
                                                                    return false; /* p_pos=0.200, tau=0.33 */
                                                                } else {
                                                                    return false; /* p_pos=0.000, tau=0.33 */
                                                                }
                                                            } else {
                                                                return false; /* p_pos=0.294, tau=0.33 */
                                                            }
                                                        }
                                                    } else {
                                                        if (features[83] /* FIO2_slope */ <= 2.63632f) {
                                                            if (features[9] /* Feature_Pulse_Pressure_mean */ <= -0.05861f) {
                                                                if (features[35] /* Feature_MBP_Mean_60s_std */ <= -0.62842f) {
                                                                    return false; /* p_pos=0.200, tau=0.33 */
                                                                } else {
                                                                    return false; /* p_pos=0.000, tau=0.33 */
                                                                }
                                                            } else {
                                                                if (features[54] /* Feature_MBP_Mean_60s_min */ <= 0.51112f) {
                                                                    return true; /* p_pos=0.357, tau=0.33 */
                                                                } else {
                                                                    return false; /* p_pos=0.056, tau=0.33 */
                                                                }
                                                            }
                                                        } else {
                                                            if (features[75] /* Feature_MBP_Delta_60s_max */ <= -0.32610f) {
                                                                if (features[71] /* Feature_HR_Std_60s_max */ <= -0.53011f) {
                                                                    return false; /* p_pos=0.000, tau=0.33 */
                                                                } else {
                                                                    return true; /* p_pos=0.381, tau=0.33 */
                                                                }
                                                            } else {
                                                                return true; /* p_pos=0.833, tau=0.33 */
                                                            }
                                                        }
                                                    }
                                                } else {
                                                    if (features[1] /* ART_SBP_mean */ <= 0.08312f) {
                                                        if (features[72] /* Feature_HR_Delta_60s_max */ <= 0.19501f) {
                                                            if (features[7] /* FIO2_mean */ <= 0.45816f) {
                                                                return false; /* p_pos=0.182, tau=0.33 */
                                                            } else {
                                                                return false; /* p_pos=0.000, tau=0.33 */
                                                            }
                                                        } else {
                                                            return true; /* p_pos=0.600, tau=0.33 */
                                                        }
                                                    } else {
                                                        if (features[42] /* PLETH_SPO2_min */ <= 0.07756f) {
                                                            if (features[8] /* BT_mean */ <= 0.08020f) {
                                                                return true; /* p_pos=0.950, tau=0.33 */
                                                            } else {
                                                                if (features[13] /* Feature_HR_Mean_60s_mean */ <= -0.58176f) {
                                                                    return true; /* p_pos=0.750, tau=0.33 */
                                                                } else {
                                                                    return false; /* p_pos=0.200, tau=0.33 */
                                                                }
                                                            }
                                                        } else {
                                                            if (features[25] /* ETCO2_std */ <= -0.20527f) {
                                                                return false; /* p_pos=0.000, tau=0.33 */
                                                            } else {
                                                                if (features[55] /* Feature_MBP_Std_60s_min */ <= -0.12481f) {
                                                                    return true; /* p_pos=0.625, tau=0.33 */
                                                                } else {
                                                                    return false; /* p_pos=0.160, tau=0.33 */
                                                                }
                                                            }
                                                        }
                                                    }
                                                }
                                            } else {
                                                if (features[74] /* Feature_MBP_Std_60s_max */ <= -0.39622f) {
                                                    return true; /* p_pos=0.818, tau=0.33 */
                                                } else {
                                                    return false; /* p_pos=0.000, tau=0.33 */
                                                }
                                            }
                                        } else {
                                            if (features[44] /* ETCO2_min */ <= -0.22242f) {
                                                return false; /* p_pos=0.000, tau=0.33 */
                                            } else {
                                                return false; /* p_pos=0.200, tau=0.33 */
                                            }
                                        }
                                    } else {
                                        if (features[42] /* PLETH_SPO2_min */ <= -2.00207f) {
                                            if (features[72] /* Feature_HR_Delta_60s_max */ <= 1.00698f) {
                                                if (features[64] /* FIO2_max */ <= 1.30306f) {
                                                    if (features[45] /* FIO2_min */ <= -0.03147f) {
                                                        return false; /* p_pos=0.222, tau=0.33 */
                                                    } else {
                                                        return true; /* p_pos=0.846, tau=0.33 */
                                                    }
                                                } else {
                                                    if (features[52] /* Feature_HR_Std_60s_min */ <= -0.27186f) {
                                                        return true; /* p_pos=0.667, tau=0.33 */
                                                    } else {
                                                        return true; /* p_pos=1.000, tau=0.33 */
                                                    }
                                                }
                                            } else {
                                                return false; /* p_pos=0.000, tau=0.33 */
                                            }
                                        } else {
                                            if (features[32] /* Feature_HR_Mean_60s_std */ <= -0.70866f) {
                                                if (features[50] /* Feature_Rate_Pressure_Product_min */ <= 0.92273f) {
                                                    if (features[52] /* Feature_HR_Std_60s_min */ <= 0.02874f) {
                                                        if (features[29] /* Feature_Shock_Index_std */ <= -0.52726f) {
                                                            return false; /* p_pos=0.000, tau=0.33 */
                                                        } else {
                                                            if (features[72] /* Feature_HR_Delta_60s_max */ <= -0.84532f) {
                                                                return true; /* p_pos=0.857, tau=0.33 */
                                                            } else {
                                                                if (features[47] /* Feature_Pulse_Pressure_min */ <= -0.28931f) {
                                                                    return false; /* p_pos=0.031, tau=0.33 */
                                                                } else {
                                                                    return false; /* p_pos=0.262, tau=0.33 */
                                                                }
                                                            }
                                                        }
                                                    } else {
                                                        return true; /* p_pos=0.615, tau=0.33 */
                                                    }
                                                } else {
                                                    if (features[37] /* Feature_MBP_Delta_60s_std */ <= -0.58333f) {
                                                        return false; /* p_pos=0.286, tau=0.33 */
                                                    } else {
                                                        return false; /* p_pos=0.000, tau=0.33 */
                                                    }
                                                }
                                            } else {
                                                if (features[58] /* ART_SBP_max */ <= 0.27066f) {
                                                    if (features[63] /* ETCO2_max */ <= 1.94587f) {
                                                        if (features[72] /* Feature_HR_Delta_60s_max */ <= 1.00698f) {
                                                            if (features[85] /* Feature_Pulse_Pressure_slope */ <= 2.03858f) {
                                                                if (features[7] /* FIO2_mean */ <= -0.25622f) {
                                                                    return true; /* p_pos=0.435, tau=0.33 */
                                                                } else {
                                                                    return false; /* p_pos=0.241, tau=0.33 */
                                                                }
                                                            } else {
                                                                return true; /* p_pos=1.000, tau=0.33 */
                                                            }
                                                        } else {
                                                            if (features[44] /* ETCO2_min */ <= 0.58100f) {
                                                                return false; /* p_pos=0.000, tau=0.33 */
                                                            } else {
                                                                return true; /* p_pos=0.333, tau=0.33 */
                                                            }
                                                        }
                                                    } else {
                                                        return false; /* p_pos=0.000, tau=0.33 */
                                                    }
                                                } else {
                                                    if (features[90] /* Feature_HR_Std_60s_slope */ <= 0.42820f) {
                                                        if (features[31] /* Feature_Rate_Pressure_Product_std */ <= 1.15210f) {
                                                            if (features[46] /* BT_min */ <= 0.21688f) {
                                                                if (features[57] /* HR_max */ <= 0.39042f) {
                                                                    return true; /* p_pos=0.464, tau=0.33 */
                                                                } else {
                                                                    return true; /* p_pos=1.000, tau=0.33 */
                                                                }
                                                            } else {
                                                                if (features[25] /* ETCO2_std */ <= -0.44876f) {
                                                                    return true; /* p_pos=0.588, tau=0.33 */
                                                                } else {
                                                                    return false; /* p_pos=0.195, tau=0.33 */
                                                                }
                                                            }
                                                        } else {
                                                            return false; /* p_pos=0.000, tau=0.33 */
                                                        }
                                                    } else {
                                                        if (features[63] /* ETCO2_max */ <= -0.82262f) {
                                                            return false; /* p_pos=0.000, tau=0.33 */
                                                        } else {
                                                            if (features[31] /* Feature_Rate_Pressure_Product_std */ <= -0.14841f) {
                                                                if (features[20] /* ART_SBP_std */ <= -0.05024f) {
                                                                    return true; /* p_pos=0.517, tau=0.33 */
                                                                } else {
                                                                    return false; /* p_pos=0.000, tau=0.33 */
                                                                }
                                                            } else {
                                                                if (features[85] /* Feature_Pulse_Pressure_slope */ <= 0.69067f) {
                                                                    return true; /* p_pos=0.943, tau=0.33 */
                                                                } else {
                                                                    return true; /* p_pos=0.567, tau=0.33 */
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
                    }
                } else {
                    if (features[39] /* ART_SBP_min */ <= -0.41710f) {
                        if (features[74] /* Feature_MBP_Std_60s_max */ <= 0.50435f) {
                            if (features[5] /* RR_CO2_mean */ <= -0.65272f) {
                                if (features[49] /* Feature_Modified_Shock_Index_min */ <= 0.22342f) {
                                    if (features[57] /* HR_max */ <= -0.55302f) {
                                        return true; /* p_pos=0.333, tau=0.33 */
                                    } else {
                                        return false; /* p_pos=0.000, tau=0.33 */
                                    }
                                } else {
                                    if (features[7] /* FIO2_mean */ <= 1.43419f) {
                                        return true; /* p_pos=0.545, tau=0.33 */
                                    } else {
                                        return false; /* p_pos=0.000, tau=0.33 */
                                    }
                                }
                            } else {
                                if (features[3] /* ART_MBP_mean */ <= 0.86532f) {
                                    if (features[64] /* FIO2_max */ <= 1.83703f) {
                                        if (features[58] /* ART_SBP_max */ <= 0.87020f) {
                                            return false; /* p_pos=0.000, tau=0.33 */
                                        } else {
                                            return true; /* p_pos=0.412, tau=0.33 */
                                        }
                                    } else {
                                        return true; /* p_pos=0.733, tau=0.33 */
                                    }
                                } else {
                                    return true; /* p_pos=1.000, tau=0.33 */
                                }
                            }
                        } else {
                            if (features[42] /* PLETH_SPO2_min */ <= -0.96225f) {
                                if (features[50] /* Feature_Rate_Pressure_Product_min */ <= -1.23683f) {
                                    if (features[7] /* FIO2_mean */ <= 2.17881f) {
                                        return false; /* p_pos=0.000, tau=0.33 */
                                    } else {
                                        return false; /* p_pos=0.200, tau=0.33 */
                                    }
                                } else {
                                    return true; /* p_pos=0.478, tau=0.33 */
                                }
                            } else {
                                if (features[84] /* BT_slope */ <= 3.15747f) {
                                    return false; /* p_pos=0.000, tau=0.33 */
                                } else {
                                    return false; /* p_pos=0.300, tau=0.33 */
                                }
                            }
                        }
                    } else {
                        if (features[93] /* Feature_MBP_Std_60s_slope */ <= 0.13114f) {
                            if (features[66] /* Feature_Pulse_Pressure_max */ <= 0.44385f) {
                                if (features[88] /* Feature_Rate_Pressure_Product_slope */ <= 0.29446f) {
                                    if (features[45] /* FIO2_min */ <= 0.14358f) {
                                        if (features[4] /* PLETH_SPO2_mean */ <= -1.17103f) {
                                            return false; /* p_pos=0.000, tau=0.33 */
                                        } else {
                                            if (features[59] /* ART_DBP_max */ <= 0.80469f) {
                                                if (features[66] /* Feature_Pulse_Pressure_max */ <= -0.24972f) {
                                                    return true; /* p_pos=0.842, tau=0.33 */
                                                } else {
                                                    if (features[9] /* Feature_Pulse_Pressure_mean */ <= 0.44832f) {
                                                        return false; /* p_pos=0.091, tau=0.33 */
                                                    } else {
                                                        return true; /* p_pos=0.562, tau=0.33 */
                                                    }
                                                }
                                            } else {
                                                if (features[58] /* ART_SBP_max */ <= 0.91632f) {
                                                    if (features[52] /* Feature_HR_Std_60s_min */ <= 0.08576f) {
                                                        return false; /* p_pos=0.000, tau=0.33 */
                                                    } else {
                                                        if (features[71] /* Feature_HR_Std_60s_max */ <= -0.43397f) {
                                                            return true; /* p_pos=0.625, tau=0.33 */
                                                        } else {
                                                            return false; /* p_pos=0.000, tau=0.33 */
                                                        }
                                                    }
                                                } else {
                                                    return true; /* p_pos=1.000, tau=0.33 */
                                                }
                                            }
                                        }
                                    } else {
                                        if (features[87] /* Feature_Modified_Shock_Index_slope */ <= -0.04044f) {
                                            return false; /* p_pos=0.200, tau=0.33 */
                                        } else {
                                            return false; /* p_pos=0.000, tau=0.33 */
                                        }
                                    }
                                } else {
                                    if (features[87] /* Feature_Modified_Shock_Index_slope */ <= 0.53019f) {
                                        if (features[31] /* Feature_Rate_Pressure_Product_std */ <= -0.53906f) {
                                            return true; /* p_pos=0.833, tau=0.33 */
                                        } else {
                                            if (features[67] /* Feature_Shock_Index_max */ <= -0.60340f) {
                                                if (features[90] /* Feature_HR_Std_60s_slope */ <= 0.24373f) {
                                                    return false; /* p_pos=0.000, tau=0.33 */
                                                } else {
                                                    return false; /* p_pos=0.200, tau=0.33 */
                                                }
                                            } else {
                                                if (features[7] /* FIO2_mean */ <= 0.34704f) {
                                                    if (features[44] /* ETCO2_min */ <= -0.22242f) {
                                                        return false; /* p_pos=0.000, tau=0.33 */
                                                    } else {
                                                        if (features[53] /* Feature_HR_Delta_60s_min */ <= -0.22261f) {
                                                            return true; /* p_pos=1.000, tau=0.33 */
                                                        } else {
                                                            if (features[65] /* BT_max */ <= 0.20778f) {
                                                                return true; /* p_pos=0.381, tau=0.33 */
                                                            } else {
                                                                return false; /* p_pos=0.000, tau=0.33 */
                                                            }
                                                        }
                                                    }
                                                } else {
                                                    if (features[46] /* BT_min */ <= 0.28986f) {
                                                        return true; /* p_pos=0.826, tau=0.33 */
                                                    } else {
                                                        if (features[48] /* Feature_Shock_Index_min */ <= -0.27170f) {
                                                            return false; /* p_pos=0.000, tau=0.33 */
                                                        } else {
                                                            return true; /* p_pos=0.571, tau=0.33 */
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    } else {
                                        return true; /* p_pos=0.810, tau=0.33 */
                                    }
                                }
                            } else {
                                if (features[25] /* ETCO2_std */ <= 0.06595f) {
                                    if (features[69] /* Feature_Rate_Pressure_Product_max */ <= -0.01318f) {
                                        if (features[90] /* Feature_HR_Std_60s_slope */ <= -0.04542f) {
                                            return false; /* p_pos=0.143, tau=0.33 */
                                        } else {
                                            return true; /* p_pos=0.913, tau=0.33 */
                                        }
                                    } else {
                                        if (features[33] /* Feature_HR_Std_60s_std */ <= 1.15613f) {
                                            if (features[20] /* ART_SBP_std */ <= -0.18808f) {
                                                return false; /* p_pos=0.000, tau=0.33 */
                                            } else {
                                                if (features[55] /* Feature_MBP_Std_60s_min */ <= 0.03263f) {
                                                    if (features[60] /* ART_MBP_max */ <= -0.06292f) {
                                                        return true; /* p_pos=1.000, tau=0.33 */
                                                    } else {
                                                        if (features[64] /* FIO2_max */ <= 1.48105f) {
                                                            if (features[81] /* RR_CO2_slope */ <= -0.50672f) {
                                                                return true; /* p_pos=0.400, tau=0.33 */
                                                            } else {
                                                                return false; /* p_pos=0.000, tau=0.33 */
                                                            }
                                                        } else {
                                                            if (features[10] /* Feature_Shock_Index_mean */ <= -0.27974f) {
                                                                if (features[53] /* Feature_HR_Delta_60s_min */ <= 0.55213f) {
                                                                    return false; /* p_pos=0.294, tau=0.33 */
                                                                } else {
                                                                    return true; /* p_pos=1.000, tau=0.33 */
                                                                }
                                                            } else {
                                                                return false; /* p_pos=0.000, tau=0.33 */
                                                            }
                                                        }
                                                    }
                                                } else {
                                                    if (features[38] /* HR_min */ <= -0.09844f) {
                                                        if (features[71] /* Feature_HR_Std_60s_max */ <= 0.06048f) {
                                                            return false; /* p_pos=0.000, tau=0.33 */
                                                        } else {
                                                            return true; /* p_pos=0.700, tau=0.33 */
                                                        }
                                                    } else {
                                                        if (features[94] /* Feature_MBP_Delta_60s_slope */ <= 0.08927f) {
                                                            return true; /* p_pos=0.579, tau=0.33 */
                                                        } else {
                                                            return true; /* p_pos=1.000, tau=0.33 */
                                                        }
                                                    }
                                                }
                                            }
                                        } else {
                                            return false; /* p_pos=0.000, tau=0.33 */
                                        }
                                    }
                                } else {
                                    if (features[70] /* Feature_HR_Mean_60s_max */ <= 1.73389f) {
                                        if (features[90] /* Feature_HR_Std_60s_slope */ <= 0.14029f) {
                                            if (features[77] /* ART_SBP_slope */ <= -0.85851f) {
                                                if (features[8] /* BT_mean */ <= 0.31392f) {
                                                    return false; /* p_pos=0.000, tau=0.33 */
                                                } else {
                                                    return true; /* p_pos=0.429, tau=0.33 */
                                                }
                                            } else {
                                                if (features[32] /* Feature_HR_Mean_60s_std */ <= 0.17556f) {
                                                    if (features[84] /* BT_slope */ <= -0.55325f) {
                                                        return true; /* p_pos=0.824, tau=0.33 */
                                                    } else {
                                                        if (features[94] /* Feature_MBP_Delta_60s_slope */ <= -0.50153f) {
                                                            return true; /* p_pos=1.000, tau=0.33 */
                                                        } else {
                                                            if (features[10] /* Feature_Shock_Index_mean */ <= -0.25837f) {
                                                                if (features[41] /* ART_MBP_min */ <= 1.00780f) {
                                                                    return true; /* p_pos=0.654, tau=0.33 */
                                                                } else {
                                                                    return false; /* p_pos=0.174, tau=0.33 */
                                                                }
                                                            } else {
                                                                if (features[24] /* RR_CO2_std */ <= 2.25500f) {
                                                                    return false; /* p_pos=0.000, tau=0.33 */
                                                                } else {
                                                                    return true; /* p_pos=0.400, tau=0.33 */
                                                                }
                                                            }
                                                        }
                                                    }
                                                } else {
                                                    if (features[44] /* ETCO2_min */ <= -1.02584f) {
                                                        if (features[62] /* RR_CO2_max */ <= 1.87901f) {
                                                            return false; /* p_pos=0.318, tau=0.33 */
                                                        } else {
                                                            return true; /* p_pos=0.947, tau=0.33 */
                                                        }
                                                    } else {
                                                        if (features[84] /* BT_slope */ <= -0.09352f) {
                                                            return true; /* p_pos=0.800, tau=0.33 */
                                                        } else {
                                                            return true; /* p_pos=1.000, tau=0.33 */
                                                        }
                                                    }
                                                }
                                            }
                                        } else {
                                            if (features[54] /* Feature_MBP_Mean_60s_min */ <= 1.43892f) {
                                                if (features[66] /* Feature_Pulse_Pressure_max */ <= 1.44087f) {
                                                    if (features[72] /* Feature_HR_Delta_60s_max */ <= 1.48908f) {
                                                        if (features[14] /* Feature_HR_Std_60s_mean */ <= 0.08067f) {
                                                            if (features[54] /* Feature_MBP_Mean_60s_min */ <= 0.91195f) {
                                                                return false; /* p_pos=0.250, tau=0.33 */
                                                            } else {
                                                                return true; /* p_pos=1.000, tau=0.33 */
                                                            }
                                                        } else {
                                                            return true; /* p_pos=1.000, tau=0.33 */
                                                        }
                                                    } else {
                                                        return false; /* p_pos=0.000, tau=0.33 */
                                                    }
                                                } else {
                                                    if (features[56] /* Feature_MBP_Delta_60s_min */ <= 0.26925f) {
                                                        return true; /* p_pos=1.000, tau=0.33 */
                                                    } else {
                                                        return true; /* p_pos=0.684, tau=0.33 */
                                                    }
                                                }
                                            } else {
                                                return false; /* p_pos=0.286, tau=0.33 */
                                            }
                                        }
                                    } else {
                                        if (features[53] /* Feature_HR_Delta_60s_min */ <= 0.06146f) {
                                            return false; /* p_pos=0.042, tau=0.33 */
                                        } else {
                                            return true; /* p_pos=0.600, tau=0.33 */
                                        }
                                    }
                                }
                            }
                        } else {
                            if (features[80] /* PLETH_SPO2_slope */ <= -5.10491f) {
                                return true; /* p_pos=1.000, tau=0.33 */
                            } else {
                                if (features[66] /* Feature_Pulse_Pressure_max */ <= 0.44385f) {
                                    if (features[46] /* BT_min */ <= -0.78858f) {
                                        if (features[64] /* FIO2_max */ <= 1.79253f) {
                                            if (features[55] /* Feature_MBP_Std_60s_min */ <= -0.09264f) {
                                                return false; /* p_pos=0.000, tau=0.33 */
                                            } else {
                                                if (features[85] /* Feature_Pulse_Pressure_slope */ <= 0.36973f) {
                                                    return true; /* p_pos=1.000, tau=0.33 */
                                                } else {
                                                    return true; /* p_pos=0.500, tau=0.33 */
                                                }
                                            }
                                        } else {
                                            return true; /* p_pos=0.955, tau=0.33 */
                                        }
                                    } else {
                                        if (features[4] /* PLETH_SPO2_mean */ <= -1.47033f) {
                                            return false; /* p_pos=0.000, tau=0.33 */
                                        } else {
                                            if (features[23] /* PLETH_SPO2_std */ <= 0.61643f) {
                                                if (features[16] /* Feature_MBP_Mean_60s_mean */ <= 0.12074f) {
                                                    return false; /* p_pos=0.000, tau=0.33 */
                                                } else {
                                                    if (features[70] /* Feature_HR_Mean_60s_max */ <= 1.32386f) {
                                                        if (features[90] /* Feature_HR_Std_60s_slope */ <= 0.01210f) {
                                                            return false; /* p_pos=0.042, tau=0.33 */
                                                        } else {
                                                            if (features[3] /* ART_MBP_mean */ <= 0.35939f) {
                                                                return true; /* p_pos=0.875, tau=0.33 */
                                                            } else {
                                                                if (features[21] /* ART_DBP_std */ <= 0.48164f) {
                                                                    return true; /* p_pos=0.447, tau=0.33 */
                                                                } else {
                                                                    return false; /* p_pos=0.121, tau=0.33 */
                                                                }
                                                            }
                                                        }
                                                    } else {
                                                        return true; /* p_pos=0.727, tau=0.33 */
                                                    }
                                                }
                                            } else {
                                                if (features[13] /* Feature_HR_Mean_60s_mean */ <= 1.16596f) {
                                                    if (features[20] /* ART_SBP_std */ <= 0.12712f) {
                                                        return true; /* p_pos=1.000, tau=0.33 */
                                                    } else {
                                                        return true; /* p_pos=0.579, tau=0.33 */
                                                    }
                                                } else {
                                                    return false; /* p_pos=0.000, tau=0.33 */
                                                }
                                            }
                                        }
                                    }
                                } else {
                                    if (features[24] /* RR_CO2_std */ <= 1.54360f) {
                                        if (features[68] /* Feature_Modified_Shock_Index_max */ <= -0.23708f) {
                                            if (features[11] /* Feature_Modified_Shock_Index_mean */ <= -0.37606f) {
                                                if (features[32] /* Feature_HR_Mean_60s_std */ <= 3.13703f) {
                                                    if (features[41] /* ART_MBP_min */ <= 0.05023f) {
                                                        return false; /* p_pos=0.083, tau=0.33 */
                                                    } else {
                                                        if (features[39] /* ART_SBP_min */ <= 0.26872f) {
                                                            if (features[64] /* FIO2_max */ <= 1.23631f) {
                                                                return true; /* p_pos=0.529, tau=0.33 */
                                                            } else {
                                                                if (features[89] /* Feature_HR_Mean_60s_slope */ <= -0.05938f) {
                                                                    return true; /* p_pos=0.733, tau=0.33 */
                                                                } else {
                                                                    return true; /* p_pos=1.000, tau=0.33 */
                                                                }
                                                            }
                                                        } else {
                                                            if (features[46] /* BT_min */ <= -0.96697f) {
                                                                return true; /* p_pos=0.957, tau=0.33 */
                                                            } else {
                                                                if (features[58] /* ART_SBP_max */ <= 2.00010f) {
                                                                    return true; /* p_pos=0.454, tau=0.33 */
                                                                } else {
                                                                    return true; /* p_pos=0.727, tau=0.33 */
                                                                }
                                                            }
                                                        }
                                                    }
                                                } else {
                                                    return false; /* p_pos=0.000, tau=0.33 */
                                                }
                                            } else {
                                                if (features[72] /* Feature_HR_Delta_60s_max */ <= 0.37263f) {
                                                    if (features[36] /* Feature_MBP_Std_60s_std */ <= -0.32116f) {
                                                        if (features[16] /* Feature_MBP_Mean_60s_mean */ <= 0.31107f) {
                                                            return true; /* p_pos=1.000, tau=0.33 */
                                                        } else {
                                                            if (features[35] /* Feature_MBP_Mean_60s_std */ <= -0.02972f) {
                                                                return false; /* p_pos=0.000, tau=0.33 */
                                                            } else {
                                                                return true; /* p_pos=0.692, tau=0.33 */
                                                            }
                                                        }
                                                    } else {
                                                        if (features[68] /* Feature_Modified_Shock_Index_max */ <= -0.31966f) {
                                                            return false; /* p_pos=0.000, tau=0.33 */
                                                        } else {
                                                            return false; /* p_pos=0.308, tau=0.33 */
                                                        }
                                                    }
                                                } else {
                                                    return true; /* p_pos=0.727, tau=0.33 */
                                                }
                                            }
                                        } else {
                                            if (features[56] /* Feature_MBP_Delta_60s_min */ <= 0.53911f) {
                                                if (features[92] /* Feature_MBP_Mean_60s_slope */ <= 1.82700f) {
                                                    if (features[56] /* Feature_MBP_Delta_60s_min */ <= 0.03794f) {
                                                        if (features[26] /* FIO2_std */ <= 1.49435f) {
                                                            return true; /* p_pos=0.643, tau=0.33 */
                                                        } else {
                                                            return true; /* p_pos=1.000, tau=0.33 */
                                                        }
                                                    } else {
                                                        if (features[27] /* BT_std */ <= -0.25187f) {
                                                            if (features[48] /* Feature_Shock_Index_min */ <= -0.06521f) {
                                                                if (features[33] /* Feature_HR_Std_60s_std */ <= -0.31497f) {
                                                                    return false; /* p_pos=0.000, tau=0.33 */
                                                                } else {
                                                                    return true; /* p_pos=0.778, tau=0.33 */
                                                                }
                                                            } else {
                                                                return true; /* p_pos=1.000, tau=0.33 */
                                                            }
                                                        } else {
                                                            return false; /* p_pos=0.273, tau=0.33 */
                                                        }
                                                    }
                                                } else {
                                                    if (features[93] /* Feature_MBP_Std_60s_slope */ <= 0.24643f) {
                                                        return true; /* p_pos=0.800, tau=0.33 */
                                                    } else {
                                                        return true; /* p_pos=1.000, tau=0.33 */
                                                    }
                                                }
                                            } else {
                                                return false; /* p_pos=0.000, tau=0.33 */
                                            }
                                        }
                                    } else {
                                        if (features[54] /* Feature_MBP_Mean_60s_min */ <= 0.70173f) {
                                            if (features[93] /* Feature_MBP_Std_60s_slope */ <= 0.62617f) {
                                                if (features[50] /* Feature_Rate_Pressure_Product_min */ <= -0.28167f) {
                                                    if (features[49] /* Feature_Modified_Shock_Index_min */ <= -0.38348f) {
                                                        return true; /* p_pos=0.833, tau=0.33 */
                                                    } else {
                                                        return false; /* p_pos=0.200, tau=0.33 */
                                                    }
                                                } else {
                                                    if (features[39] /* ART_SBP_min */ <= 0.50875f) {
                                                        if (features[49] /* Feature_Modified_Shock_Index_min */ <= 0.36763f) {
                                                            if (features[82] /* ETCO2_slope */ <= -3.57654f) {
                                                                return true; /* p_pos=0.800, tau=0.33 */
                                                            } else {
                                                                return true; /* p_pos=1.000, tau=0.33 */
                                                            }
                                                        } else {
                                                            return true; /* p_pos=0.400, tau=0.33 */
                                                        }
                                                    } else {
                                                        if (features[55] /* Feature_MBP_Std_60s_min */ <= 0.04297f) {
                                                            return true; /* p_pos=0.529, tau=0.33 */
                                                        } else {
                                                            return true; /* p_pos=1.000, tau=0.33 */
                                                        }
                                                    }
                                                }
                                            } else {
                                                return true; /* p_pos=1.000, tau=0.33 */
                                            }
                                        } else {
                                            if (features[11] /* Feature_Modified_Shock_Index_mean */ <= -0.96460f) {
                                                return true; /* p_pos=1.000, tau=0.33 */
                                            } else {
                                                if (features[28] /* Feature_Pulse_Pressure_std */ <= 0.35020f) {
                                                    if (features[67] /* Feature_Shock_Index_max */ <= -0.36324f) {
                                                        return true; /* p_pos=1.000, tau=0.33 */
                                                    } else {
                                                        return true; /* p_pos=0.643, tau=0.33 */
                                                    }
                                                } else {
                                                    if (features[78] /* ART_DBP_slope */ <= -0.77265f) {
                                                        return true; /* p_pos=1.000, tau=0.33 */
                                                    } else {
                                                        if (features[71] /* Feature_HR_Std_60s_max */ <= -0.08019f) {
                                                            if (features[32] /* Feature_HR_Mean_60s_std */ <= -0.30827f) {
                                                                return true; /* p_pos=0.667, tau=0.33 */
                                                            } else {
                                                                if (features[78] /* ART_DBP_slope */ <= 0.02278f) {
                                                                    return true; /* p_pos=0.375, tau=0.33 */
                                                                } else {
                                                                    return false; /* p_pos=0.000, tau=0.33 */
                                                                }
                                                            }
                                                        } else {
                                                            if (features[69] /* Feature_Rate_Pressure_Product_max */ <= 0.72608f) {
                                                                return true; /* p_pos=1.000, tau=0.33 */
                                                            } else {
                                                                if (features[89] /* Feature_HR_Mean_60s_slope */ <= 1.85406f) {
                                                                    return false; /* p_pos=0.208, tau=0.33 */
                                                                } else {
                                                                    return true; /* p_pos=0.690, tau=0.33 */
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
                    }
                }
            } else {
                if (features[15] /* Feature_HR_Delta_60s_mean */ <= 0.41953f) {
                    if (features[5] /* RR_CO2_mean */ <= -1.87836f) {
                        if (features[42] /* PLETH_SPO2_min */ <= -0.96225f) {
                            if (features[13] /* Feature_HR_Mean_60s_mean */ <= 1.08504f) {
                                if (features[34] /* Feature_HR_Delta_60s_std */ <= -0.60819f) {
                                    return true; /* p_pos=0.625, tau=0.33 */
                                } else {
                                    if (features[48] /* Feature_Shock_Index_min */ <= 5.84805f) {
                                        return false; /* p_pos=0.000, tau=0.33 */
                                    } else {
                                        return false; /* p_pos=0.250, tau=0.33 */
                                    }
                                }
                            } else {
                                return true; /* p_pos=0.500, tau=0.33 */
                            }
                        } else {
                            if (features[51] /* Feature_HR_Mean_60s_min */ <= -1.33383f) {
                                return false; /* p_pos=0.176, tau=0.33 */
                            } else {
                                return false; /* p_pos=0.000, tau=0.33 */
                            }
                        }
                    } else {
                        if (features[49] /* Feature_Modified_Shock_Index_min */ <= -1.21060f) {
                            if (features[13] /* Feature_HR_Mean_60s_mean */ <= 1.15770f) {
                                if (features[84] /* BT_slope */ <= -5.34764f) {
                                    return true; /* p_pos=1.000, tau=0.33 */
                                } else {
                                    if (features[25] /* ETCO2_std */ <= -0.09132f) {
                                        if (features[8] /* BT_mean */ <= -0.24348f) {
                                            return false; /* p_pos=0.053, tau=0.33 */
                                        } else {
                                            if (features[34] /* Feature_HR_Delta_60s_std */ <= 0.92485f) {
                                                if (features[70] /* Feature_HR_Mean_60s_max */ <= -0.64824f) {
                                                    if (features[53] /* Feature_HR_Delta_60s_min */ <= 0.75873f) {
                                                        if (features[44] /* ETCO2_min */ <= 0.71491f) {
                                                            if (features[84] /* BT_slope */ <= -0.09351f) {
                                                                return true; /* p_pos=1.000, tau=0.33 */
                                                            } else {
                                                                if (features[6] /* ETCO2_mean */ <= -0.39792f) {
                                                                    return true; /* p_pos=1.000, tau=0.33 */
                                                                } else {
                                                                    return true; /* p_pos=0.632, tau=0.33 */
                                                                }
                                                            }
                                                        } else {
                                                            return true; /* p_pos=0.333, tau=0.33 */
                                                        }
                                                    } else {
                                                        return false; /* p_pos=0.125, tau=0.33 */
                                                    }
                                                } else {
                                                    if (features[24] /* RR_CO2_std */ <= 0.28654f) {
                                                        if (features[43] /* RR_CO2_min */ <= 0.45272f) {
                                                            if (features[0] /* HR_mean */ <= 0.47342f) {
                                                                if (features[15] /* Feature_HR_Delta_60s_mean */ <= -0.95921f) {
                                                                    return false; /* p_pos=0.200, tau=0.33 */
                                                                } else {
                                                                    return false; /* p_pos=0.000, tau=0.33 */
                                                                }
                                                            } else {
                                                                return true; /* p_pos=0.500, tau=0.33 */
                                                            }
                                                        } else {
                                                            if (features[4] /* PLETH_SPO2_mean */ <= -0.35176f) {
                                                                return false; /* p_pos=0.000, tau=0.33 */
                                                            } else {
                                                                if (features[65] /* BT_max */ <= 0.32306f) {
                                                                    return true; /* p_pos=0.885, tau=0.33 */
                                                                } else {
                                                                    return false; /* p_pos=0.111, tau=0.33 */
                                                                }
                                                            }
                                                        }
                                                    } else {
                                                        return true; /* p_pos=0.800, tau=0.33 */
                                                    }
                                                }
                                            } else {
                                                return true; /* p_pos=1.000, tau=0.33 */
                                            }
                                        }
                                    } else {
                                        if (features[44] /* ETCO2_min */ <= -2.90049f) {
                                            return false; /* p_pos=0.167, tau=0.33 */
                                        } else {
                                            if (features[34] /* Feature_HR_Delta_60s_std */ <= -0.72167f) {
                                                return true; /* p_pos=0.429, tau=0.33 */
                                            } else {
                                                if (features[64] /* FIO2_max */ <= 1.83703f) {
                                                    if (features[81] /* RR_CO2_slope */ <= 0.52116f) {
                                                        if (features[4] /* PLETH_SPO2_mean */ <= -0.43405f) {
                                                            return true; /* p_pos=0.333, tau=0.33 */
                                                        } else {
                                                            return true; /* p_pos=1.000, tau=0.33 */
                                                        }
                                                    } else {
                                                        return true; /* p_pos=0.571, tau=0.33 */
                                                    }
                                                } else {
                                                    if (features[33] /* Feature_HR_Std_60s_std */ <= 1.77061f) {
                                                        return true; /* p_pos=1.000, tau=0.33 */
                                                    } else {
                                                        return true; /* p_pos=0.600, tau=0.33 */
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            } else {
                                if (features[84] /* BT_slope */ <= -1.24285f) {
                                    return true; /* p_pos=0.438, tau=0.33 */
                                } else {
                                    return false; /* p_pos=0.000, tau=0.33 */
                                }
                            }
                        } else {
                            if (features[21] /* ART_DBP_std */ <= -0.07456f) {
                                if (features[3] /* ART_MBP_mean */ <= -0.63806f) {
                                    if (features[5] /* RR_CO2_mean */ <= 3.55940f) {
                                        if (features[80] /* PLETH_SPO2_slope */ <= -2.96353f) {
                                            return true; /* p_pos=1.000, tau=0.33 */
                                        } else {
                                            if (features[67] /* Feature_Shock_Index_max */ <= 0.39275f) {
                                                if (features[2] /* ART_DBP_mean */ <= -0.98206f) {
                                                    return false; /* p_pos=0.000, tau=0.33 */
                                                } else {
                                                    if (features[76] /* HR_slope */ <= -0.33672f) {
                                                        if (features[19] /* HR_std */ <= -0.66035f) {
                                                            return false; /* p_pos=0.200, tau=0.33 */
                                                        } else {
                                                            return false; /* p_pos=0.000, tau=0.33 */
                                                        }
                                                    } else {
                                                        if (features[35] /* Feature_MBP_Mean_60s_std */ <= -0.46628f) {
                                                            return true; /* p_pos=0.571, tau=0.33 */
                                                        } else {
                                                            return false; /* p_pos=0.111, tau=0.33 */
                                                        }
                                                    }
                                                }
                                            } else {
                                                return false; /* p_pos=0.000, tau=0.33 */
                                            }
                                        }
                                    } else {
                                        return true; /* p_pos=1.000, tau=0.33 */
                                    }
                                } else {
                                    if (features[19] /* HR_std */ <= -0.71999f) {
                                        if (features[42] /* PLETH_SPO2_min */ <= -2.78193f) {
                                            return true; /* p_pos=1.000, tau=0.33 */
                                        } else {
                                            if (features[54] /* Feature_MBP_Mean_60s_min */ <= -0.27893f) {
                                                if (features[45] /* FIO2_min */ <= -0.49828f) {
                                                    return false; /* p_pos=0.083, tau=0.33 */
                                                } else {
                                                    return true; /* p_pos=0.933, tau=0.33 */
                                                }
                                            } else {
                                                if (features[6] /* ETCO2_mean */ <= -0.17573f) {
                                                    if (features[52] /* Feature_HR_Std_60s_min */ <= -0.18580f) {
                                                        if (features[90] /* Feature_HR_Std_60s_slope */ <= 0.02325f) {
                                                            return false; /* p_pos=0.000, tau=0.33 */
                                                        } else {
                                                            if (features[72] /* Feature_HR_Delta_60s_max */ <= -0.74383f) {
                                                                if (features[66] /* Feature_Pulse_Pressure_max */ <= 0.15487f) {
                                                                    return false; /* p_pos=0.320, tau=0.33 */
                                                                } else {
                                                                    return false; /* p_pos=0.000, tau=0.33 */
                                                                }
                                                            } else {
                                                                return false; /* p_pos=0.000, tau=0.33 */
                                                            }
                                                        }
                                                    } else {
                                                        if (features[39] /* ART_SBP_min */ <= 1.09169f) {
                                                            if (features[76] /* HR_slope */ <= -0.05951f) {
                                                                return true; /* p_pos=0.429, tau=0.33 */
                                                            } else {
                                                                return false; /* p_pos=0.000, tau=0.33 */
                                                            }
                                                        } else {
                                                            return true; /* p_pos=0.900, tau=0.33 */
                                                        }
                                                    }
                                                } else {
                                                    if (features[87] /* Feature_Modified_Shock_Index_slope */ <= 0.21422f) {
                                                        if (features[9] /* Feature_Pulse_Pressure_mean */ <= 0.44260f) {
                                                            if (features[63] /* ETCO2_max */ <= -0.42712f) {
                                                                return true; /* p_pos=1.000, tau=0.33 */
                                                            } else {
                                                                if (features[35] /* Feature_MBP_Mean_60s_std */ <= -0.49351f) {
                                                                    return true; /* p_pos=0.479, tau=0.33 */
                                                                } else {
                                                                    return false; /* p_pos=0.108, tau=0.33 */
                                                                }
                                                            }
                                                        } else {
                                                            if (features[87] /* Feature_Modified_Shock_Index_slope */ <= 0.02168f) {
                                                                if (features[17] /* Feature_MBP_Std_60s_mean */ <= -0.32063f) {
                                                                    return false; /* p_pos=0.193, tau=0.33 */
                                                                } else {
                                                                    return true; /* p_pos=0.875, tau=0.33 */
                                                                }
                                                            } else {
                                                                return false; /* p_pos=0.000, tau=0.33 */
                                                            }
                                                        }
                                                    } else {
                                                        return false; /* p_pos=0.000, tau=0.33 */
                                                    }
                                                }
                                            }
                                        }
                                    } else {
                                        if (features[84] /* BT_slope */ <= -5.31480f) {
                                            if (features[56] /* Feature_MBP_Delta_60s_min */ <= 0.30780f) {
                                                return false; /* p_pos=0.000, tau=0.33 */
                                            } else {
                                                if (features[68] /* Feature_Modified_Shock_Index_max */ <= -0.16535f) {
                                                    if (features[93] /* Feature_MBP_Std_60s_slope */ <= 0.21466f) {
                                                        return true; /* p_pos=1.000, tau=0.33 */
                                                    } else {
                                                        return true; /* p_pos=0.800, tau=0.33 */
                                                    }
                                                } else {
                                                    return true; /* p_pos=0.500, tau=0.33 */
                                                }
                                            }
                                        } else {
                                            if (features[55] /* Feature_MBP_Std_60s_min */ <= 0.58495f) {
                                                if (features[42] /* PLETH_SPO2_min */ <= -0.44235f) {
                                                    if (features[8] /* BT_mean */ <= 0.29700f) {
                                                        if (features[11] /* Feature_Modified_Shock_Index_mean */ <= -0.66159f) {
                                                            return true; /* p_pos=1.000, tau=0.33 */
                                                        } else {
                                                            if (features[1] /* ART_SBP_mean */ <= 1.11688f) {
                                                                if (features[2] /* ART_DBP_mean */ <= -0.30749f) {
                                                                    return true; /* p_pos=0.350, tau=0.33 */
                                                                } else {
                                                                    return true; /* p_pos=0.738, tau=0.33 */
                                                                }
                                                            } else {
                                                                return false; /* p_pos=0.067, tau=0.33 */
                                                            }
                                                        }
                                                    } else {
                                                        if (features[2] /* ART_DBP_mean */ <= -0.12091f) {
                                                            if (features[54] /* Feature_MBP_Mean_60s_min */ <= -0.35141f) {
                                                                return false; /* p_pos=0.000, tau=0.33 */
                                                            } else {
                                                                if (features[30] /* Feature_Modified_Shock_Index_std */ <= -0.40445f) {
                                                                    return true; /* p_pos=0.600, tau=0.33 */
                                                                } else {
                                                                    return true; /* p_pos=1.000, tau=0.33 */
                                                                }
                                                            }
                                                        } else {
                                                            if (features[79] /* ART_MBP_slope */ <= 0.18439f) {
                                                                return false; /* p_pos=0.000, tau=0.33 */
                                                            } else {
                                                                if (features[68] /* Feature_Modified_Shock_Index_max */ <= -0.45927f) {
                                                                    return true; /* p_pos=0.688, tau=0.33 */
                                                                } else {
                                                                    return false; /* p_pos=0.000, tau=0.33 */
                                                                }
                                                            }
                                                        }
                                                    }
                                                } else {
                                                    if (features[8] /* BT_mean */ <= -0.03256f) {
                                                        if (features[58] /* ART_SBP_max */ <= 0.66267f) {
                                                            if (features[2] /* ART_DBP_mean */ <= -0.64480f) {
                                                                return false; /* p_pos=0.000, tau=0.33 */
                                                            } else {
                                                                if (features[6] /* ETCO2_mean */ <= -0.88333f) {
                                                                    return false; /* p_pos=0.000, tau=0.33 */
                                                                } else {
                                                                    return true; /* p_pos=0.479, tau=0.33 */
                                                                }
                                                            }
                                                        } else {
                                                            if (features[46] /* BT_min */ <= -0.52911f) {
                                                                if (features[9] /* Feature_Pulse_Pressure_mean */ <= 1.65153f) {
                                                                    return true; /* p_pos=0.533, tau=0.33 */
                                                                } else {
                                                                    return true; /* p_pos=0.938, tau=0.33 */
                                                                }
                                                            } else {
                                                                return true; /* p_pos=1.000, tau=0.33 */
                                                            }
                                                        }
                                                    } else {
                                                        if (features[64] /* FIO2_max */ <= 1.79253f) {
                                                            if (features[82] /* ETCO2_slope */ <= -0.65538f) {
                                                                if (features[4] /* PLETH_SPO2_mean */ <= 0.21820f) {
                                                                    return true; /* p_pos=0.348, tau=0.33 */
                                                                } else {
                                                                    return false; /* p_pos=0.051, tau=0.33 */
                                                                }
                                                            } else {
                                                                if (features[21] /* ART_DBP_std */ <= -0.35808f) {
                                                                    return false; /* p_pos=0.199, tau=0.33 */
                                                                } else {
                                                                    return true; /* p_pos=0.439, tau=0.33 */
                                                                }
                                                            }
                                                        } else {
                                                            if (features[39] /* ART_SBP_min */ <= -0.38281f) {
                                                                if (features[62] /* RR_CO2_max */ <= -0.00710f) {
                                                                    return true; /* p_pos=0.423, tau=0.33 */
                                                                } else {
                                                                    return true; /* p_pos=0.958, tau=0.33 */
                                                                }
                                                            } else {
                                                                if (features[5] /* RR_CO2_mean */ <= -0.75200f) {
                                                                    return false; /* p_pos=0.172, tau=0.33 */
                                                                } else {
                                                                    return true; /* p_pos=0.380, tau=0.33 */
                                                                }
                                                            }
                                                        }
                                                    }
                                                }
                                            } else {
                                                return false; /* p_pos=0.000, tau=0.33 */
                                            }
                                        }
                                    }
                                }
                            } else {
                                if (features[42] /* PLETH_SPO2_min */ <= -2.26202f) {
                                    if (features[80] /* PLETH_SPO2_slope */ <= -4.56957f) {
                                        return true; /* p_pos=1.000, tau=0.33 */
                                    } else {
                                        if (features[78] /* ART_DBP_slope */ <= 1.46902f) {
                                            if (features[28] /* Feature_Pulse_Pressure_std */ <= 0.21734f) {
                                                if (features[67] /* Feature_Shock_Index_max */ <= 0.43270f) {
                                                    if (features[89] /* Feature_HR_Mean_60s_slope */ <= 0.11865f) {
                                                        if (features[58] /* ART_SBP_max */ <= 0.25913f) {
                                                            return false; /* p_pos=0.000, tau=0.33 */
                                                        } else {
                                                            return true; /* p_pos=0.684, tau=0.33 */
                                                        }
                                                    } else {
                                                        return false; /* p_pos=0.000, tau=0.33 */
                                                    }
                                                } else {
                                                    return true; /* p_pos=0.812, tau=0.33 */
                                                }
                                            } else {
                                                if (features[52] /* Feature_HR_Std_60s_min */ <= 1.75327f) {
                                                    if (features[78] /* ART_DBP_slope */ <= -1.35115f) {
                                                        return false; /* p_pos=0.273, tau=0.33 */
                                                    } else {
                                                        if (features[81] /* RR_CO2_slope */ <= -2.35690f) {
                                                            return true; /* p_pos=0.400, tau=0.33 */
                                                        } else {
                                                            if (features[65] /* BT_max */ <= 0.38893f) {
                                                                if (features[15] /* Feature_HR_Delta_60s_mean */ <= -0.15052f) {
                                                                    return true; /* p_pos=1.000, tau=0.33 */
                                                                } else {
                                                                    return true; /* p_pos=0.822, tau=0.33 */
                                                                }
                                                            } else {
                                                                return true; /* p_pos=0.429, tau=0.33 */
                                                            }
                                                        }
                                                    }
                                                } else {
                                                    return false; /* p_pos=0.000, tau=0.33 */
                                                }
                                            }
                                        } else {
                                            return true; /* p_pos=1.000, tau=0.33 */
                                        }
                                    }
                                } else {
                                    if (features[30] /* Feature_Modified_Shock_Index_std */ <= 1.92948f) {
                                        if (features[84] /* BT_slope */ <= -0.88163f) {
                                            if (features[14] /* Feature_HR_Std_60s_mean */ <= -0.74509f) {
                                                return false; /* p_pos=0.000, tau=0.33 */
                                            } else {
                                                if (features[58] /* ART_SBP_max */ <= 2.93399f) {
                                                    if (features[35] /* Feature_MBP_Mean_60s_std */ <= -0.58487f) {
                                                        if (features[89] /* Feature_HR_Mean_60s_slope */ <= -0.47660f) {
                                                            return true; /* p_pos=0.667, tau=0.33 */
                                                        } else {
                                                            return false; /* p_pos=0.000, tau=0.33 */
                                                        }
                                                    } else {
                                                        if (features[40] /* ART_DBP_min */ <= -0.77903f) {
                                                            if (features[52] /* Feature_HR_Std_60s_min */ <= 2.69655f) {
                                                                if (features[9] /* Feature_Pulse_Pressure_mean */ <= 1.59505f) {
                                                                    return true; /* p_pos=0.831, tau=0.33 */
                                                                } else {
                                                                    return true; /* p_pos=0.419, tau=0.33 */
                                                                }
                                                            } else {
                                                                return false; /* p_pos=0.167, tau=0.33 */
                                                            }
                                                        } else {
                                                            if (features[2] /* ART_DBP_mean */ <= -0.44153f) {
                                                                return false; /* p_pos=0.000, tau=0.33 */
                                                            } else {
                                                                if (features[31] /* Feature_Rate_Pressure_Product_std */ <= 0.45123f) {
                                                                    return true; /* p_pos=0.678, tau=0.33 */
                                                                } else {
                                                                    return true; /* p_pos=0.444, tau=0.33 */
                                                                }
                                                            }
                                                        }
                                                    }
                                                } else {
                                                    return false; /* p_pos=0.000, tau=0.33 */
                                                }
                                            }
                                        } else {
                                            if (features[64] /* FIO2_max */ <= 1.70353f) {
                                                if (features[37] /* Feature_MBP_Delta_60s_std */ <= 0.03010f) {
                                                    if (features[7] /* FIO2_mean */ <= -0.03783f) {
                                                        if (features[79] /* ART_MBP_slope */ <= 1.33745f) {
                                                            if (features[23] /* PLETH_SPO2_std */ <= 1.14453f) {
                                                                if (features[67] /* Feature_Shock_Index_max */ <= -0.59120f) {
                                                                    return false; /* p_pos=0.056, tau=0.33 */
                                                                } else {
                                                                    return true; /* p_pos=0.436, tau=0.33 */
                                                                }
                                                            } else {
                                                                return true; /* p_pos=0.889, tau=0.33 */
                                                            }
                                                        } else {
                                                            return true; /* p_pos=1.000, tau=0.33 */
                                                        }
                                                    } else {
                                                        if (features[26] /* FIO2_std */ <= 3.48743f) {
                                                            if (features[85] /* Feature_Pulse_Pressure_slope */ <= 0.69067f) {
                                                                if (features[23] /* PLETH_SPO2_std */ <= 1.28825f) {
                                                                    return false; /* p_pos=0.000, tau=0.33 */
                                                                } else {
                                                                    return false; /* p_pos=0.200, tau=0.33 */
                                                                }
                                                            } else {
                                                                if (features[11] /* Feature_Modified_Shock_Index_mean */ <= -0.39689f) {
                                                                    return true; /* p_pos=0.600, tau=0.33 */
                                                                } else {
                                                                    return false; /* p_pos=0.043, tau=0.33 */
                                                                }
                                                            }
                                                        } else {
                                                            return true; /* p_pos=0.429, tau=0.33 */
                                                        }
                                                    }
                                                } else {
                                                    return false; /* p_pos=0.000, tau=0.33 */
                                                }
                                            } else {
                                                if (features[54] /* Feature_MBP_Mean_60s_min */ <= -0.38064f) {
                                                    if (features[44] /* ETCO2_min */ <= -0.22242f) {
                                                        if (features[27] /* BT_std */ <= 0.26092f) {
                                                            if (features[6] /* ETCO2_mean */ <= -0.45459f) {
                                                                return false; /* p_pos=0.000, tau=0.33 */
                                                            } else {
                                                                if (features[54] /* Feature_MBP_Mean_60s_min */ <= -0.50157f) {
                                                                    return false; /* p_pos=0.125, tau=0.33 */
                                                                } else {
                                                                    return true; /* p_pos=1.000, tau=0.33 */
                                                                }
                                                            }
                                                        } else {
                                                            return true; /* p_pos=1.000, tau=0.33 */
                                                        }
                                                    } else {
                                                        if (features[66] /* Feature_Pulse_Pressure_max */ <= 2.07664f) {
                                                            if (features[46] /* BT_min */ <= 0.20066f) {
                                                                if (features[33] /* Feature_HR_Std_60s_std */ <= -0.02063f) {
                                                                    return false; /* p_pos=0.000, tau=0.33 */
                                                                } else {
                                                                    return true; /* p_pos=0.429, tau=0.33 */
                                                                }
                                                            } else {
                                                                if (features[18] /* Feature_MBP_Delta_60s_mean */ <= 0.24681f) {
                                                                    return true; /* p_pos=0.641, tau=0.33 */
                                                                } else {
                                                                    return false; /* p_pos=0.000, tau=0.33 */
                                                                }
                                                            }
                                                        } else {
                                                            return true; /* p_pos=1.000, tau=0.33 */
                                                        }
                                                    }
                                                } else {
                                                    if (features[71] /* Feature_HR_Std_60s_max */ <= -0.76409f) {
                                                        if (features[22] /* ART_MBP_std */ <= -0.00639f) {
                                                            if (features[50] /* Feature_Rate_Pressure_Product_min */ <= -0.07695f) {
                                                                if (features[50] /* Feature_Rate_Pressure_Product_min */ <= -0.61892f) {
                                                                    return false; /* p_pos=0.235, tau=0.33 */
                                                                } else {
                                                                    return true; /* p_pos=0.864, tau=0.33 */
                                                                }
                                                            } else {
                                                                if (features[18] /* Feature_MBP_Delta_60s_mean */ <= 0.23029f) {
                                                                    return false; /* p_pos=0.125, tau=0.33 */
                                                                } else {
                                                                    return true; /* p_pos=0.714, tau=0.33 */
                                                                }
                                                            }
                                                        } else {
                                                            return false; /* p_pos=0.000, tau=0.33 */
                                                        }
                                                    } else {
                                                        if (features[28] /* Feature_Pulse_Pressure_std */ <= 2.57946f) {
                                                            if (features[82] /* ETCO2_slope */ <= -4.02595f) {
                                                                if (features[85] /* Feature_Pulse_Pressure_slope */ <= 0.49811f) {
                                                                    return true; /* p_pos=0.650, tau=0.33 */
                                                                } else {
                                                                    return true; /* p_pos=0.968, tau=0.33 */
                                                                }
                                                            } else {
                                                                if (features[93] /* Feature_MBP_Std_60s_slope */ <= -0.24402f) {
                                                                    return false; /* p_pos=0.246, tau=0.33 */
                                                                } else {
                                                                    return true; /* p_pos=0.523, tau=0.33 */
                                                                }
                                                            }
                                                        } else {
                                                            if (features[44] /* ETCO2_min */ <= -1.09279f) {
                                                                return true; /* p_pos=0.375, tau=0.33 */
                                                            } else {
                                                                return false; /* p_pos=0.000, tau=0.33 */
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    } else {
                                        return false; /* p_pos=0.000, tau=0.33 */
                                    }
                                }
                            }
                        }
                    }
                } else {
                    if (features[11] /* Feature_Modified_Shock_Index_mean */ <= 1.27507f) {
                        if (features[59] /* ART_DBP_max */ <= 0.76315f) {
                            if (features[49] /* Feature_Modified_Shock_Index_min */ <= -1.18773f) {
                                if (features[44] /* ETCO2_min */ <= -3.03440f) {
                                    return false; /* p_pos=0.200, tau=0.33 */
                                } else {
                                    if (features[33] /* Feature_HR_Std_60s_std */ <= 0.18369f) {
                                        if (features[70] /* Feature_HR_Mean_60s_max */ <= 0.44549f) {
                                            if (features[7] /* FIO2_mean */ <= 0.16274f) {
                                                if (features[6] /* ETCO2_mean */ <= -0.00386f) {
                                                    return false; /* p_pos=0.250, tau=0.33 */
                                                } else {
                                                    return true; /* p_pos=0.857, tau=0.33 */
                                                }
                                            } else {
                                                if (features[34] /* Feature_HR_Delta_60s_std */ <= -0.55247f) {
                                                    return true; /* p_pos=0.600, tau=0.33 */
                                                } else {
                                                    if (features[6] /* ETCO2_mean */ <= -0.90812f) {
                                                        return true; /* p_pos=0.800, tau=0.33 */
                                                    } else {
                                                        return true; /* p_pos=1.000, tau=0.33 */
                                                    }
                                                }
                                            }
                                        } else {
                                            if (features[25] /* ETCO2_std */ <= -0.08297f) {
                                                if (features[0] /* HR_mean */ <= 0.30121f) {
                                                    return true; /* p_pos=0.667, tau=0.33 */
                                                } else {
                                                    return false; /* p_pos=0.091, tau=0.33 */
                                                }
                                            } else {
                                                if (features[15] /* Feature_HR_Delta_60s_mean */ <= 3.35239f) {
                                                    if (features[27] /* BT_std */ <= -0.04387f) {
                                                        return true; /* p_pos=0.941, tau=0.33 */
                                                    } else {
                                                        return true; /* p_pos=0.579, tau=0.33 */
                                                    }
                                                } else {
                                                    return false; /* p_pos=0.000, tau=0.33 */
                                                }
                                            }
                                        }
                                    } else {
                                        if (features[5] /* RR_CO2_mean */ <= -0.66927f) {
                                            if (features[46] /* BT_min */ <= -0.00205f) {
                                                if (features[51] /* Feature_HR_Mean_60s_min */ <= -0.52814f) {
                                                    return true; /* p_pos=0.696, tau=0.33 */
                                                } else {
                                                    return false; /* p_pos=0.000, tau=0.33 */
                                                }
                                            } else {
                                                return true; /* p_pos=0.952, tau=0.33 */
                                            }
                                        } else {
                                            if (features[84] /* BT_slope */ <= -0.02784f) {
                                                if (features[51] /* Feature_HR_Mean_60s_min */ <= -0.43643f) {
                                                    return true; /* p_pos=1.000, tau=0.33 */
                                                } else {
                                                    if (features[91] /* Feature_HR_Delta_60s_slope */ <= 1.71046f) {
                                                        if (features[82] /* ETCO2_slope */ <= -2.00361f) {
                                                            return true; /* p_pos=0.833, tau=0.33 */
                                                        } else {
                                                            return true; /* p_pos=1.000, tau=0.33 */
                                                        }
                                                    } else {
                                                        return true; /* p_pos=0.727, tau=0.33 */
                                                    }
                                                }
                                            } else {
                                                return true; /* p_pos=0.571, tau=0.33 */
                                            }
                                        }
                                    }
                                }
                            } else {
                                if (features[36] /* Feature_MBP_Std_60s_std */ <= -0.50415f) {
                                    if (features[65] /* BT_max */ <= -0.36859f) {
                                        return false; /* p_pos=0.000, tau=0.33 */
                                    } else {
                                        if (features[37] /* Feature_MBP_Delta_60s_std */ <= -0.45774f) {
                                            if (features[2] /* ART_DBP_mean */ <= -0.37024f) {
                                                if (features[7] /* FIO2_mean */ <= -0.30186f) {
                                                    return true; /* p_pos=0.375, tau=0.33 */
                                                } else {
                                                    return false; /* p_pos=0.000, tau=0.33 */
                                                }
                                            } else {
                                                if (features[76] /* HR_slope */ <= 1.55751f) {
                                                    if (features[52] /* Feature_HR_Std_60s_min */ <= 0.02874f) {
                                                        if (features[73] /* Feature_MBP_Mean_60s_max */ <= 0.37845f) {
                                                            if (features[48] /* Feature_Shock_Index_min */ <= 0.03616f) {
                                                                if (features[55] /* Feature_MBP_Std_60s_min */ <= -0.18480f) {
                                                                    return true; /* p_pos=0.667, tau=0.33 */
                                                                } else {
                                                                    return true; /* p_pos=1.000, tau=0.33 */
                                                                }
                                                            } else {
                                                                if (features[67] /* Feature_Shock_Index_max */ <= -0.36518f) {
                                                                    return false; /* p_pos=0.000, tau=0.33 */
                                                                } else {
                                                                    return true; /* p_pos=0.654, tau=0.33 */
                                                                }
                                                            }
                                                        } else {
                                                            return false; /* p_pos=0.000, tau=0.33 */
                                                        }
                                                    } else {
                                                        if (features[65] /* BT_max */ <= 0.05134f) {
                                                            return true; /* p_pos=0.800, tau=0.33 */
                                                        } else {
                                                            if (features[83] /* FIO2_slope */ <= 4.15020f) {
                                                                return false; /* p_pos=0.000, tau=0.33 */
                                                            } else {
                                                                return true; /* p_pos=0.400, tau=0.33 */
                                                            }
                                                        }
                                                    }
                                                } else {
                                                    return true; /* p_pos=0.826, tau=0.33 */
                                                }
                                            }
                                        } else {
                                            return true; /* p_pos=1.000, tau=0.33 */
                                        }
                                    }
                                } else {
                                    if (features[14] /* Feature_HR_Std_60s_mean */ <= 2.93945f) {
                                        if (features[42] /* PLETH_SPO2_min */ <= -0.96225f) {
                                            if (features[3] /* ART_MBP_mean */ <= 1.29142f) {
                                                if (features[88] /* Feature_Rate_Pressure_Product_slope */ <= 1.44225f) {
                                                    if (features[59] /* ART_DBP_max */ <= 0.59700f) {
                                                        if (features[9] /* Feature_Pulse_Pressure_mean */ <= 0.02797f) {
                                                            if (features[22] /* ART_MBP_std */ <= -0.43941f) {
                                                                return false; /* p_pos=0.000, tau=0.33 */
                                                            } else {
                                                                if (features[6] /* ETCO2_mean */ <= 0.62638f) {
                                                                    return true; /* p_pos=0.824, tau=0.33 */
                                                                } else {
                                                                    return false; /* p_pos=0.111, tau=0.33 */
                                                                }
                                                            }
                                                        } else {
                                                            if (features[83] /* FIO2_slope */ <= 3.73733f) {
                                                                if (features[21] /* ART_DBP_std */ <= 0.92998f) {
                                                                    return true; /* p_pos=0.808, tau=0.33 */
                                                                } else {
                                                                    return false; /* p_pos=0.125, tau=0.33 */
                                                                }
                                                            } else {
                                                                if (features[21] /* ART_DBP_std */ <= 0.72151f) {
                                                                    return true; /* p_pos=1.000, tau=0.33 */
                                                                } else {
                                                                    return true; /* p_pos=0.667, tau=0.33 */
                                                                }
                                                            }
                                                        }
                                                    } else {
                                                        if (features[28] /* Feature_Pulse_Pressure_std */ <= -0.39587f) {
                                                            return false; /* p_pos=0.000, tau=0.33 */
                                                        } else {
                                                            if (features[70] /* Feature_HR_Mean_60s_max */ <= 1.45364f) {
                                                                if (features[79] /* ART_MBP_slope */ <= 0.14393f) {
                                                                    return true; /* p_pos=0.500, tau=0.33 */
                                                                } else {
                                                                    return true; /* p_pos=1.000, tau=0.33 */
                                                                }
                                                            } else {
                                                                return false; /* p_pos=0.000, tau=0.33 */
                                                            }
                                                        }
                                                    }
                                                } else {
                                                    if (features[59] /* ART_DBP_max */ <= 0.14010f) {
                                                        if (features[4] /* PLETH_SPO2_mean */ <= -0.00978f) {
                                                            return true; /* p_pos=0.947, tau=0.33 */
                                                        } else {
                                                            return true; /* p_pos=0.333, tau=0.33 */
                                                        }
                                                    } else {
                                                        if (features[57] /* HR_max */ <= 1.49445f) {
                                                            return true; /* p_pos=1.000, tau=0.33 */
                                                        } else {
                                                            return true; /* p_pos=0.800, tau=0.33 */
                                                        }
                                                    }
                                                }
                                            } else {
                                                return false; /* p_pos=0.143, tau=0.33 */
                                            }
                                        } else {
                                            if (features[54] /* Feature_MBP_Mean_60s_min */ <= -0.77747f) {
                                                if (features[31] /* Feature_Rate_Pressure_Product_std */ <= 0.46224f) {
                                                    return true; /* p_pos=0.421, tau=0.33 */
                                                } else {
                                                    return false; /* p_pos=0.000, tau=0.33 */
                                                }
                                            } else {
                                                if (features[25] /* ETCO2_std */ <= 0.04118f) {
                                                    if (features[84] /* BT_slope */ <= 0.00500f) {
                                                        if (features[19] /* HR_std */ <= -0.58906f) {
                                                            return false; /* p_pos=0.091, tau=0.33 */
                                                        } else {
                                                            if (features[45] /* FIO2_min */ <= 0.14358f) {
                                                                if (features[55] /* Feature_MBP_Std_60s_min */ <= -0.14643f) {
                                                                    return true; /* p_pos=0.438, tau=0.33 */
                                                                } else {
                                                                    return true; /* p_pos=0.594, tau=0.33 */
                                                                }
                                                            } else {
                                                                return true; /* p_pos=1.000, tau=0.33 */
                                                            }
                                                        }
                                                    } else {
                                                        if (features[71] /* Feature_HR_Std_60s_max */ <= 0.39898f) {
                                                            if (features[27] /* BT_std */ <= -0.22616f) {
                                                                return true; /* p_pos=0.400, tau=0.33 */
                                                            } else {
                                                                return false; /* p_pos=0.000, tau=0.33 */
                                                            }
                                                        } else {
                                                            return true; /* p_pos=0.500, tau=0.33 */
                                                        }
                                                    }
                                                } else {
                                                    if (features[40] /* ART_DBP_min */ <= 0.21343f) {
                                                        if (features[83] /* FIO2_slope */ <= 3.66851f) {
                                                            if (features[41] /* ART_MBP_min */ <= 0.14365f) {
                                                                if (features[19] /* HR_std */ <= 0.83670f) {
                                                                    return true; /* p_pos=0.627, tau=0.33 */
                                                                } else {
                                                                    return false; /* p_pos=0.218, tau=0.33 */
                                                                }
                                                            } else {
                                                                if (features[6] /* ETCO2_mean */ <= -0.84605f) {
                                                                    return false; /* p_pos=0.000, tau=0.33 */
                                                                } else {
                                                                    return true; /* p_pos=0.882, tau=0.33 */
                                                                }
                                                            }
                                                        } else {
                                                            if (features[69] /* Feature_Rate_Pressure_Product_max */ <= 0.40920f) {
                                                                if (features[24] /* RR_CO2_std */ <= -0.20985f) {
                                                                    return true; /* p_pos=0.355, tau=0.33 */
                                                                } else {
                                                                    return true; /* p_pos=0.783, tau=0.33 */
                                                                }
                                                            } else {
                                                                if (features[36] /* Feature_MBP_Std_60s_std */ <= -0.41986f) {
                                                                    return true; /* p_pos=1.000, tau=0.33 */
                                                                } else {
                                                                    return true; /* p_pos=0.831, tau=0.33 */
                                                                }
                                                            }
                                                        }
                                                    } else {
                                                        if (features[76] /* HR_slope */ <= 2.89733f) {
                                                            if (features[16] /* Feature_MBP_Mean_60s_mean */ <= 1.05430f) {
                                                                if (features[11] /* Feature_Modified_Shock_Index_mean */ <= 0.02226f) {
                                                                    return true; /* p_pos=0.398, tau=0.33 */
                                                                } else {
                                                                    return true; /* p_pos=0.840, tau=0.33 */
                                                                }
                                                            } else {
                                                                return false; /* p_pos=0.000, tau=0.33 */
                                                            }
                                                        } else {
                                                            return true; /* p_pos=1.000, tau=0.33 */
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    } else {
                                        if (features[81] /* RR_CO2_slope */ <= 0.31559f) {
                                            return false; /* p_pos=0.000, tau=0.33 */
                                        } else {
                                            return true; /* p_pos=0.444, tau=0.33 */
                                        }
                                    }
                                }
                            }
                        } else {
                            if (features[42] /* PLETH_SPO2_min */ <= -0.70230f) {
                                if (features[80] /* PLETH_SPO2_slope */ <= -2.96353f) {
                                    if (features[76] /* HR_slope */ <= 1.97332f) {
                                        return true; /* p_pos=1.000, tau=0.33 */
                                    } else {
                                        if (features[67] /* Feature_Shock_Index_max */ <= -0.15954f) {
                                            return true; /* p_pos=0.773, tau=0.33 */
                                        } else {
                                            return true; /* p_pos=1.000, tau=0.33 */
                                        }
                                    }
                                } else {
                                    if (features[84] /* BT_slope */ <= -5.28196f) {
                                        if (features[4] /* PLETH_SPO2_mean */ <= 0.21759f) {
                                            if (features[25] /* ETCO2_std */ <= 0.35096f) {
                                                return true; /* p_pos=0.652, tau=0.33 */
                                            } else {
                                                if (features[58] /* ART_SBP_max */ <= 1.95398f) {
                                                    return false; /* p_pos=0.000, tau=0.33 */
                                                } else {
                                                    return false; /* p_pos=0.200, tau=0.33 */
                                                }
                                            }
                                        } else {
                                            return true; /* p_pos=0.929, tau=0.33 */
                                        }
                                    } else {
                                        if (features[86] /* Feature_Shock_Index_slope */ <= -1.62821f) {
                                            return false; /* p_pos=0.000, tau=0.33 */
                                        } else {
                                            if (features[83] /* FIO2_slope */ <= 3.80614f) {
                                                if (features[28] /* Feature_Pulse_Pressure_std */ <= 0.12945f) {
                                                    if (features[81] /* RR_CO2_slope */ <= -0.30114f) {
                                                        return true; /* p_pos=0.909, tau=0.33 */
                                                    } else {
                                                        if (features[51] /* Feature_HR_Mean_60s_min */ <= -0.02401f) {
                                                            return false; /* p_pos=0.000, tau=0.33 */
                                                        } else {
                                                            return true; /* p_pos=0.550, tau=0.33 */
                                                        }
                                                    }
                                                } else {
                                                    if (features[10] /* Feature_Shock_Index_mean */ <= -0.84864f) {
                                                        return true; /* p_pos=1.000, tau=0.33 */
                                                    } else {
                                                        if (features[9] /* Feature_Pulse_Pressure_mean */ <= 0.67521f) {
                                                            if (features[10] /* Feature_Shock_Index_mean */ <= -0.22591f) {
                                                                if (features[28] /* Feature_Pulse_Pressure_std */ <= 1.55764f) {
                                                                    return true; /* p_pos=0.714, tau=0.33 */
                                                                } else {
                                                                    return true; /* p_pos=1.000, tau=0.33 */
                                                                }
                                                            } else {
                                                                if (features[18] /* Feature_MBP_Delta_60s_mean */ <= -0.15848f) {
                                                                    return true; /* p_pos=0.800, tau=0.33 */
                                                                } else {
                                                                    return true; /* p_pos=1.000, tau=0.33 */
                                                                }
                                                            }
                                                        } else {
                                                            if (features[58] /* ART_SBP_max */ <= 1.49280f) {
                                                                if (features[44] /* ETCO2_min */ <= -1.96317f) {
                                                                    return true; /* p_pos=0.706, tau=0.33 */
                                                                } else {
                                                                    return false; /* p_pos=0.235, tau=0.33 */
                                                                }
                                                            } else {
                                                                if (features[60] /* ART_MBP_max */ <= 0.28581f) {
                                                                    return false; /* p_pos=0.000, tau=0.33 */
                                                                } else {
                                                                    return true; /* p_pos=0.833, tau=0.33 */
                                                                }
                                                            }
                                                        }
                                                    }
                                                }
                                            } else {
                                                if (features[8] /* BT_mean */ <= 0.23459f) {
                                                    if (features[54] /* Feature_MBP_Mean_60s_min */ <= 1.28355f) {
                                                        if (features[2] /* ART_DBP_mean */ <= 1.66300f) {
                                                            if (features[13] /* Feature_HR_Mean_60s_mean */ <= -0.61388f) {
                                                                if (features[58] /* ART_SBP_max */ <= 1.37750f) {
                                                                    return true; /* p_pos=0.360, tau=0.33 */
                                                                } else {
                                                                    return true; /* p_pos=0.875, tau=0.33 */
                                                                }
                                                            } else {
                                                                if (features[52] /* Feature_HR_Std_60s_min */ <= -0.02935f) {
                                                                    return true; /* p_pos=1.000, tau=0.33 */
                                                                } else {
                                                                    return true; /* p_pos=0.812, tau=0.33 */
                                                                }
                                                            }
                                                        } else {
                                                            return false; /* p_pos=0.000, tau=0.33 */
                                                        }
                                                    } else {
                                                        if (features[65] /* BT_max */ <= -1.01907f) {
                                                            return true; /* p_pos=0.800, tau=0.33 */
                                                        } else {
                                                            return true; /* p_pos=1.000, tau=0.33 */
                                                        }
                                                    }
                                                } else {
                                                    if (features[24] /* RR_CO2_std */ <= -0.44600f) {
                                                        return true; /* p_pos=0.700, tau=0.33 */
                                                    } else {
                                                        return true; /* p_pos=1.000, tau=0.33 */
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            } else {
                                if (features[63] /* ETCO2_max */ <= -0.62487f) {
                                    if (features[71] /* Feature_HR_Std_60s_max */ <= 0.97774f) {
                                        if (features[17] /* Feature_MBP_Std_60s_mean */ <= 0.22748f) {
                                            if (features[51] /* Feature_HR_Mean_60s_min */ <= 1.00674f) {
                                                if (features[38] /* HR_min */ <= 0.03726f) {
                                                    if (features[9] /* Feature_Pulse_Pressure_mean */ <= 0.38993f) {
                                                        return true; /* p_pos=0.526, tau=0.33 */
                                                    } else {
                                                        if (features[48] /* Feature_Shock_Index_min */ <= -0.97707f) {
                                                            return true; /* p_pos=0.400, tau=0.33 */
                                                        } else {
                                                            return false; /* p_pos=0.000, tau=0.33 */
                                                        }
                                                    }
                                                } else {
                                                    if (features[73] /* Feature_MBP_Mean_60s_max */ <= 1.16948f) {
                                                        if (features[68] /* Feature_Modified_Shock_Index_max */ <= -0.36603f) {
                                                            return true; /* p_pos=1.000, tau=0.33 */
                                                        } else {
                                                            return true; /* p_pos=0.444, tau=0.33 */
                                                        }
                                                    } else {
                                                        return false; /* p_pos=0.143, tau=0.33 */
                                                    }
                                                }
                                            } else {
                                                return false; /* p_pos=0.000, tau=0.33 */
                                            }
                                        } else {
                                            return true; /* p_pos=0.850, tau=0.33 */
                                        }
                                    } else {
                                        return true; /* p_pos=0.947, tau=0.33 */
                                    }
                                } else {
                                    if (features[32] /* Feature_HR_Mean_60s_std */ <= 3.01771f) {
                                        if (features[33] /* Feature_HR_Std_60s_std */ <= -0.57721f) {
                                            if (features[25] /* ETCO2_std */ <= 0.10882f) {
                                                return true; /* p_pos=0.700, tau=0.33 */
                                            } else {
                                                if (features[35] /* Feature_MBP_Mean_60s_std */ <= 0.12322f) {
                                                    return true; /* p_pos=0.412, tau=0.33 */
                                                } else {
                                                    return false; /* p_pos=0.000, tau=0.33 */
                                                }
                                            }
                                        } else {
                                            if (features[63] /* ETCO2_max */ <= 1.15487f) {
                                                if (features[10] /* Feature_Shock_Index_mean */ <= 0.47710f) {
                                                    if (features[42] /* PLETH_SPO2_min */ <= 0.07756f) {
                                                        if (features[62] /* RR_CO2_max */ <= 4.64530f) {
                                                            if (features[52] /* Feature_HR_Std_60s_min */ <= 0.01446f) {
                                                                if (features[90] /* Feature_HR_Std_60s_slope */ <= 1.96468f) {
                                                                    return true; /* p_pos=0.955, tau=0.33 */
                                                                } else {
                                                                    return true; /* p_pos=0.375, tau=0.33 */
                                                                }
                                                            } else {
                                                                if (features[51] /* Feature_HR_Mean_60s_min */ <= -0.22431f) {
                                                                    return true; /* p_pos=0.845, tau=0.33 */
                                                                } else {
                                                                    return true; /* p_pos=0.459, tau=0.33 */
                                                                }
                                                            }
                                                        } else {
                                                            return false; /* p_pos=0.000, tau=0.33 */
                                                        }
                                                    } else {
                                                        if (features[28] /* Feature_Pulse_Pressure_std */ <= -0.41836f) {
                                                            return false; /* p_pos=0.190, tau=0.33 */
                                                        } else {
                                                            if (features[28] /* Feature_Pulse_Pressure_std */ <= 4.71282f) {
                                                                if (features[56] /* Feature_MBP_Delta_60s_min */ <= -1.88964f) {
                                                                    return true; /* p_pos=1.000, tau=0.33 */
                                                                } else {
                                                                    return true; /* p_pos=0.652, tau=0.33 */
                                                                }
                                                            } else {
                                                                return false; /* p_pos=0.000, tau=0.33 */
                                                            }
                                                        }
                                                    }
                                                } else {
                                                    if (features[52] /* Feature_HR_Std_60s_min */ <= -0.21566f) {
                                                        return true; /* p_pos=0.667, tau=0.33 */
                                                    } else {
                                                        if (features[28] /* Feature_Pulse_Pressure_std */ <= 0.06887f) {
                                                            return true; /* p_pos=0.600, tau=0.33 */
                                                        } else {
                                                            return false; /* p_pos=0.000, tau=0.33 */
                                                        }
                                                    }
                                                }
                                            } else {
                                                if (features[27] /* BT_std */ <= -0.27594f) {
                                                    if (features[11] /* Feature_Modified_Shock_Index_mean */ <= -0.70261f) {
                                                        return false; /* p_pos=0.167, tau=0.33 */
                                                    } else {
                                                        if (features[74] /* Feature_MBP_Std_60s_max */ <= -0.22812f) {
                                                            if (features[34] /* Feature_HR_Delta_60s_std */ <= -0.42444f) {
                                                                return true; /* p_pos=0.333, tau=0.33 */
                                                            } else {
                                                                if (features[22] /* ART_MBP_std */ <= -0.34587f) {
                                                                    return true; /* p_pos=0.800, tau=0.33 */
                                                                } else {
                                                                    return true; /* p_pos=1.000, tau=0.33 */
                                                                }
                                                            }
                                                        } else {
                                                            if (features[33] /* Feature_HR_Std_60s_std */ <= 0.45089f) {
                                                                if (features[51] /* Feature_HR_Mean_60s_min */ <= 0.77718f) {
                                                                    return true; /* p_pos=0.346, tau=0.33 */
                                                                } else {
                                                                    return true; /* p_pos=1.000, tau=0.33 */
                                                                }
                                                            } else {
                                                                if (features[43] /* RR_CO2_min */ <= -1.63901f) {
                                                                    return true; /* p_pos=1.000, tau=0.33 */
                                                                } else {
                                                                    return true; /* p_pos=0.625, tau=0.33 */
                                                                }
                                                            }
                                                        }
                                                    }
                                                } else {
                                                    if (features[45] /* FIO2_min */ <= -0.14817f) {
                                                        if (features[48] /* Feature_Shock_Index_min */ <= -1.23460f) {
                                                            return true; /* p_pos=0.500, tau=0.33 */
                                                        } else {
                                                            if (features[33] /* Feature_HR_Std_60s_std */ <= -0.55611f) {
                                                                return true; /* p_pos=0.400, tau=0.33 */
                                                            } else {
                                                                if (features[6] /* ETCO2_mean */ <= 0.45172f) {
                                                                    return true; /* p_pos=1.000, tau=0.33 */
                                                                } else {
                                                                    return true; /* p_pos=0.881, tau=0.33 */
                                                                }
                                                            }
                                                        }
                                                    } else {
                                                        if (features[72] /* Feature_HR_Delta_60s_max */ <= -0.03336f) {
                                                            return true; /* p_pos=0.412, tau=0.33 */
                                                        } else {
                                                            if (features[93] /* Feature_MBP_Std_60s_slope */ <= 0.59938f) {
                                                                return true; /* p_pos=1.000, tau=0.33 */
                                                            } else {
                                                                return true; /* p_pos=0.583, tau=0.33 */
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    } else {
                                        if (features[35] /* Feature_MBP_Mean_60s_std */ <= 0.92073f) {
                                            if (features[65] /* BT_max */ <= 0.01017f) {
                                                return true; /* p_pos=0.824, tau=0.33 */
                                            } else {
                                                return true; /* p_pos=1.000, tau=0.33 */
                                            }
                                        } else {
                                            if (features[49] /* Feature_Modified_Shock_Index_min */ <= -0.02873f) {
                                                if (features[57] /* HR_max */ <= 1.21342f) {
                                                    if (features[55] /* Feature_MBP_Std_60s_min */ <= -0.39022f) {
                                                        return true; /* p_pos=1.000, tau=0.33 */
                                                    } else {
                                                        if (features[46] /* BT_min */ <= -0.53722f) {
                                                            return true; /* p_pos=0.600, tau=0.33 */
                                                        } else {
                                                            return false; /* p_pos=0.000, tau=0.33 */
                                                        }
                                                    }
                                                } else {
                                                    if (features[10] /* Feature_Shock_Index_mean */ <= 0.02046f) {
                                                        if (features[13] /* Feature_HR_Mean_60s_mean */ <= -0.42273f) {
                                                            return true; /* p_pos=0.800, tau=0.33 */
                                                        } else {
                                                            return true; /* p_pos=1.000, tau=0.33 */
                                                        }
                                                    } else {
                                                        return false; /* p_pos=0.222, tau=0.33 */
                                                    }
                                                }
                                            } else {
                                                return true; /* p_pos=1.000, tau=0.33 */
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    } else {
                        if (features[80] /* PLETH_SPO2_slope */ <= -1.89284f) {
                            return true; /* p_pos=1.000, tau=0.33 */
                        } else {
                            if (features[50] /* Feature_Rate_Pressure_Product_min */ <= -1.27199f) {
                                return false; /* p_pos=0.000, tau=0.33 */
                            } else {
                                if (features[40] /* ART_DBP_min */ <= -1.33039f) {
                                    if (features[83] /* FIO2_slope */ <= 3.73733f) {
                                        return false; /* p_pos=0.059, tau=0.33 */
                                    } else {
                                        return true; /* p_pos=0.714, tau=0.33 */
                                    }
                                } else {
                                    if (features[88] /* Feature_Rate_Pressure_Product_slope */ <= 2.50066f) {
                                        return false; /* p_pos=0.000, tau=0.33 */
                                    } else {
                                        return false; /* p_pos=0.200, tau=0.33 */
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

