// Direct C Decision Tree (95 Features) for Silicon Labs EFR32
// RAM Usage: 0 KB | Flash Footprint: < 2.5 KB
#include <stdbool.h>

static inline bool predict_hypotension_95(const float* features) {
    if (features[54] /* Feature_MBP_Mean_60s_min */ <= -0.10436f) {
        if (features[50] /* Feature_Rate_Pressure_Product_min */ <= -2.36538f) {
            return false;
        } else {
            if (features[79] /* ART_MBP_slope */ <= 0.07651f) {
                if (features[54] /* Feature_MBP_Mean_60s_min */ <= -0.32136f) {
                    if (features[3] /* ART_MBP_mean */ <= -0.66211f) {
                        if (features[3] /* ART_MBP_mean */ <= -0.75660f) {
                            if (features[94] /* Feature_MBP_Delta_60s_slope */ <= 0.37110f) {
                                if (features[77] /* ART_SBP_slope */ <= 0.08164f) {
                                    return true;
                                } else {
                                    return true;
                                }
                            } else {
                                if (features[59] /* ART_DBP_max */ <= -0.73187f) {
                                    return true;
                                } else {
                                    return true;
                                }
                            }
                        } else {
                            if (features[94] /* Feature_MBP_Delta_60s_slope */ <= 0.16785f) {
                                if (features[79] /* ART_MBP_slope */ <= 0.02259f) {
                                    return true;
                                } else {
                                    return true;
                                }
                            } else {
                                if (features[77] /* ART_SBP_slope */ <= -0.07501f) {
                                    return true;
                                } else {
                                    return true;
                                }
                            }
                        }
                    } else {
                        if (features[86] /* Feature_Shock_Index_slope */ <= 0.45283f) {
                            if (features[2] /* ART_DBP_mean */ <= -0.40110f) {
                                if (features[94] /* Feature_MBP_Delta_60s_slope */ <= 0.12851f) {
                                    return true;
                                } else {
                                    return true;
                                }
                            } else {
                                if (features[94] /* Feature_MBP_Delta_60s_slope */ <= 0.08917f) {
                                    return true;
                                } else {
                                    return true;
                                }
                            }
                        } else {
                            if (features[88] /* Feature_Rate_Pressure_Product_slope */ <= -0.01886f) {
                                if (features[94] /* Feature_MBP_Delta_60s_slope */ <= 0.32520f) {
                                    return true;
                                } else {
                                    return true;
                                }
                            } else {
                                if (features[68] /* Feature_Modified_Shock_Index_max */ <= 0.01875f) {
                                    return true;
                                } else {
                                    return true;
                                }
                            }
                        }
                    }
                } else {
                    if (features[78] /* ART_DBP_slope */ <= -0.33873f) {
                        if (features[94] /* Feature_MBP_Delta_60s_slope */ <= 0.08917f) {
                            if (features[54] /* Feature_MBP_Mean_60s_min */ <= -0.20365f) {
                                if (features[37] /* Feature_MBP_Delta_60s_std */ <= -0.42246f) {
                                    return true;
                                } else {
                                    return true;
                                }
                            } else {
                                if (features[93] /* Feature_MBP_Std_60s_slope */ <= 0.01393f) {
                                    return true;
                                } else {
                                    return true;
                                }
                            }
                        } else {
                            if (features[54] /* Feature_MBP_Mean_60s_min */ <= -0.18924f) {
                                if (features[93] /* Feature_MBP_Std_60s_slope */ <= 0.02697f) {
                                    return true;
                                } else {
                                    return true;
                                }
                            } else {
                                if (features[9] /* Feature_Pulse_Pressure_mean */ <= -0.14302f) {
                                    return false;
                                } else {
                                    return true;
                                }
                            }
                        }
                    } else {
                        if (features[16] /* Feature_MBP_Mean_60s_mean */ <= -0.54118f) {
                            if (features[79] /* ART_MBP_slope */ <= -0.04479f) {
                                if (features[17] /* Feature_MBP_Std_60s_mean */ <= -0.71735f) {
                                    return false;
                                } else {
                                    return true;
                                }
                            } else {
                                if (features[41] /* ART_MBP_min */ <= -0.13626f) {
                                    return true;
                                } else {
                                    return false;
                                }
                            }
                        } else {
                            if (features[77] /* ART_SBP_slope */ <= -0.19251f) {
                                if (features[94] /* Feature_MBP_Delta_60s_slope */ <= 0.08917f) {
                                    return true;
                                } else {
                                    return false;
                                }
                            } else {
                                if (features[7] /* FIO2_mean */ <= 2.35889f) {
                                    return false;
                                } else {
                                    return true;
                                }
                            }
                        }
                    }
                }
            } else {
                if (features[3] /* ART_MBP_mean */ <= -0.59042f) {
                    if (features[73] /* Feature_MBP_Mean_60s_max */ <= -0.85590f) {
                        if (features[59] /* ART_DBP_max */ <= -0.77342f) {
                            if (features[73] /* Feature_MBP_Mean_60s_max */ <= -0.88895f) {
                                if (features[54] /* Feature_MBP_Mean_60s_min */ <= -0.57961f) {
                                    return true;
                                } else {
                                    return true;
                                }
                            } else {
                                if (features[55] /* Feature_MBP_Std_60s_min */ <= -0.25118f) {
                                    return true;
                                } else {
                                    return true;
                                }
                            }
                        } else {
                            if (features[93] /* Feature_MBP_Std_60s_slope */ <= 1.55600f) {
                                if (features[68] /* Feature_Modified_Shock_Index_max */ <= 0.14807f) {
                                    return true;
                                } else {
                                    return true;
                                }
                            } else {
                                return true;
                            }
                        }
                    } else {
                        if (features[78] /* ART_DBP_slope */ <= 3.27661f) {
                            if (features[17] /* Feature_MBP_Std_60s_mean */ <= -0.38042f) {
                                if (features[13] /* Feature_HR_Mean_60s_mean */ <= 1.39603f) {
                                    return false;
                                } else {
                                    return true;
                                }
                            } else {
                                if (features[79] /* ART_MBP_slope */ <= 1.92296f) {
                                    return true;
                                } else {
                                    return true;
                                }
                            }
                        } else {
                            if (features[88] /* Feature_Rate_Pressure_Product_slope */ <= 3.65650f) {
                                if (features[37] /* Feature_MBP_Delta_60s_std */ <= 0.64465f) {
                                    return false;
                                } else {
                                    return false;
                                }
                            } else {
                                if (features[49] /* Feature_Modified_Shock_Index_min */ <= 0.15258f) {
                                    return false;
                                } else {
                                    return true;
                                }
                            }
                        }
                    }
                } else {
                    if (features[41] /* ART_MBP_min */ <= -0.18296f) {
                        if (features[78] /* ART_DBP_slope */ <= 0.38434f) {
                            if (features[40] /* ART_DBP_min */ <= 0.04800f) {
                                if (features[37] /* Feature_MBP_Delta_60s_std */ <= 0.05390f) {
                                    return false;
                                } else {
                                    return true;
                                }
                            } else {
                                if (features[41] /* ART_MBP_min */ <= -0.27637f) {
                                    return false;
                                } else {
                                    return false;
                                }
                            }
                        } else {
                            if (features[11] /* Feature_Modified_Shock_Index_mean */ <= 0.25011f) {
                                if (features[8] /* BT_mean */ <= -0.00591f) {
                                    return false;
                                } else {
                                    return false;
                                }
                            } else {
                                if (features[17] /* Feature_MBP_Std_60s_mean */ <= -0.18736f) {
                                    return false;
                                } else {
                                    return false;
                                }
                            }
                        }
                    } else {
                        if (features[77] /* ART_SBP_slope */ <= 0.51245f) {
                            if (features[77] /* ART_SBP_slope */ <= -0.03585f) {
                                if (features[94] /* Feature_MBP_Delta_60s_slope */ <= 1.21033f) {
                                    return false;
                                } else {
                                    return true;
                                }
                            } else {
                                if (features[70] /* Feature_HR_Mean_60s_max */ <= -0.37257f) {
                                    return false;
                                } else {
                                    return false;
                                }
                            }
                        } else {
                            if (features[66] /* Feature_Pulse_Pressure_max */ <= 0.29987f) {
                                if (features[68] /* Feature_Modified_Shock_Index_max */ <= -0.13584f) {
                                    return false;
                                } else {
                                    return false;
                                }
                            } else {
                                if (features[13] /* Feature_HR_Mean_60s_mean */ <= 0.27591f) {
                                    return false;
                                } else {
                                    return false;
                                }
                            }
                        }
                    }
                }
            }
        }
    } else {
        if (features[41] /* ART_MBP_min */ <= 0.25294f) {
            if (features[79] /* ART_MBP_slope */ <= -0.05827f) {
                if (features[54] /* Feature_MBP_Mean_60s_min */ <= 0.04939f) {
                    if (features[55] /* Feature_MBP_Std_60s_min */ <= 0.95735f) {
                        if (features[94] /* Feature_MBP_Delta_60s_slope */ <= -0.06163f) {
                            if (features[20] /* ART_SBP_std */ <= -0.48300f) {
                                if (features[93] /* Feature_MBP_Std_60s_slope */ <= 0.11999f) {
                                    return false;
                                } else {
                                    return true;
                                }
                            } else {
                                if (features[93] /* Feature_MBP_Std_60s_slope */ <= 0.01058f) {
                                    return false;
                                } else {
                                    return true;
                                }
                            }
                        } else {
                            if (features[87] /* Feature_Modified_Shock_Index_slope */ <= 0.43065f) {
                                if (features[41] /* ART_MBP_min */ <= 0.09726f) {
                                    return false;
                                } else {
                                    return false;
                                }
                            } else {
                                if (features[94] /* Feature_MBP_Delta_60s_slope */ <= 0.01049f) {
                                    return true;
                                } else {
                                    return false;
                                }
                            }
                        }
                    } else {
                        if (features[74] /* Feature_MBP_Std_60s_max */ <= -0.24152f) {
                            return true;
                        } else {
                            return true;
                        }
                    }
                } else {
                    if (features[60] /* ART_MBP_max */ <= -0.84061f) {
                        if (features[27] /* BT_std */ <= -0.27806f) {
                            return true;
                        } else {
                            return true;
                        }
                    } else {
                        if (features[87] /* Feature_Modified_Shock_Index_slope */ <= 0.47653f) {
                            if (features[54] /* Feature_MBP_Mean_60s_min */ <= 0.34046f) {
                                if (features[31] /* Feature_Rate_Pressure_Product_std */ <= -0.28555f) {
                                    return false;
                                } else {
                                    return false;
                                }
                            } else {
                                if (features[55] /* Feature_MBP_Std_60s_min */ <= 0.78529f) {
                                    return false;
                                } else {
                                    return false;
                                }
                            }
                        } else {
                            if (features[93] /* Feature_MBP_Std_60s_slope */ <= 0.14279f) {
                                if (features[54] /* Feature_MBP_Mean_60s_min */ <= 0.42094f) {
                                    return false;
                                } else {
                                    return false;
                                }
                            } else {
                                if (features[94] /* Feature_MBP_Delta_60s_slope */ <= -0.34356f) {
                                    return true;
                                } else {
                                    return false;
                                }
                            }
                        }
                    }
                }
            } else {
                if (features[40] /* ART_DBP_min */ <= -0.11740f) {
                    if (features[78] /* ART_DBP_slope */ <= -0.48334f) {
                        if (features[54] /* Feature_MBP_Mean_60s_min */ <= 0.06180f) {
                            if (features[10] /* Feature_Shock_Index_mean */ <= 0.19902f) {
                                return false;
                            } else {
                                return true;
                            }
                        } else {
                            if (features[89] /* Feature_HR_Mean_60s_slope */ <= 0.20747f) {
                                if (features[17] /* Feature_MBP_Std_60s_mean */ <= 1.56542f) {
                                    return false;
                                } else {
                                    return false;
                                }
                            } else {
                                return true;
                            }
                        }
                    } else {
                        if (features[32] /* Feature_HR_Mean_60s_std */ <= -0.32376f) {
                            if (features[11] /* Feature_Modified_Shock_Index_mean */ <= 0.72122f) {
                                if (features[83] /* FIO2_slope */ <= 0.84853f) {
                                    return false;
                                } else {
                                    return false;
                                }
                            } else {
                                return false;
                            }
                        } else {
                            if (features[6] /* ETCO2_mean */ <= -1.78723f) {
                                return true;
                            } else {
                                if (features[79] /* ART_MBP_slope */ <= 3.98507f) {
                                    return false;
                                } else {
                                    return true;
                                }
                            }
                        }
                    }
                } else {
                    if (features[70] /* Feature_HR_Mean_60s_max */ <= 0.37794f) {
                        if (features[77] /* ART_SBP_slope */ <= 0.35579f) {
                            if (features[54] /* Feature_MBP_Mean_60s_min */ <= 0.18672f) {
                                if (features[28] /* Feature_Pulse_Pressure_std */ <= -0.50320f) {
                                    return false;
                                } else {
                                    return false;
                                }
                            } else {
                                if (features[20] /* ART_SBP_std */ <= 0.28336f) {
                                    return false;
                                } else {
                                    return false;
                                }
                            }
                        } else {
                            if (features[66] /* Feature_Pulse_Pressure_max */ <= 0.38660f) {
                                if (features[79] /* ART_MBP_slope */ <= 0.26519f) {
                                    return false;
                                } else {
                                    return false;
                                }
                            } else {
                                if (features[26] /* FIO2_std */ <= -0.28210f) {
                                    return false;
                                } else {
                                    return false;
                                }
                            }
                        }
                    } else {
                        if (features[55] /* Feature_MBP_Std_60s_min */ <= 0.71788f) {
                            if (features[54] /* Feature_MBP_Mean_60s_min */ <= 0.04058f) {
                                if (features[86] /* Feature_Shock_Index_slope */ <= -0.24042f) {
                                    return false;
                                } else {
                                    return false;
                                }
                            } else {
                                if (features[67] /* Feature_Shock_Index_max */ <= 0.20870f) {
                                    return false;
                                } else {
                                    return false;
                                }
                            }
                        } else {
                            if (features[70] /* Feature_HR_Mean_60s_max */ <= 1.12657f) {
                                return false;
                            } else {
                                return true;
                            }
                        }
                    }
                }
            }
        } else {
            if (features[26] /* FIO2_std */ <= 1.99746f) {
                if (features[40] /* ART_DBP_min */ <= 0.59930f) {
                    if (features[94] /* Feature_MBP_Delta_60s_slope */ <= -0.23866f) {
                        if (features[54] /* Feature_MBP_Mean_60s_min */ <= 0.44656f) {
                            if (features[1] /* ART_SBP_mean */ <= 0.18132f) {
                                if (features[65] /* BT_max */ <= -0.08859f) {
                                    return false;
                                } else {
                                    return false;
                                }
                            } else {
                                if (features[77] /* ART_SBP_slope */ <= -0.07501f) {
                                    return false;
                                } else {
                                    return false;
                                }
                            }
                        } else {
                            if (features[25] /* ETCO2_std */ <= 1.53506f) {
                                if (features[70] /* Feature_HR_Mean_60s_max */ <= 0.59614f) {
                                    return false;
                                } else {
                                    return false;
                                }
                            } else {
                                if (features[65] /* BT_max */ <= -0.60734f) {
                                    return false;
                                } else {
                                    return false;
                                }
                            }
                        }
                    } else {
                        if (features[54] /* Feature_MBP_Mean_60s_min */ <= 0.27440f) {
                            if (features[78] /* ART_DBP_slope */ <= -0.04950f) {
                                if (features[69] /* Feature_Rate_Pressure_Product_max */ <= -0.01168f) {
                                    return false;
                                } else {
                                    return false;
                                }
                            } else {
                                if (features[69] /* Feature_Rate_Pressure_Product_max */ <= -0.36147f) {
                                    return false;
                                } else {
                                    return false;
                                }
                            }
                        } else {
                            if (features[1] /* ART_SBP_mean */ <= -0.53830f) {
                                if (features[2] /* ART_DBP_mean */ <= -0.29462f) {
                                    return true;
                                } else {
                                    return false;
                                }
                            } else {
                                if (features[20] /* ART_SBP_std */ <= -0.24573f) {
                                    return false;
                                } else {
                                    return false;
                                }
                            }
                        }
                    }
                } else {
                    if (features[9] /* Feature_Pulse_Pressure_mean */ <= -2.39127f) {
                        return true;
                    } else {
                        if (features[41] /* ART_MBP_min */ <= 0.65771f) {
                            if (features[87] /* Feature_Modified_Shock_Index_slope */ <= 0.45050f) {
                                if (features[94] /* Feature_MBP_Delta_60s_slope */ <= -0.18620f) {
                                    return false;
                                } else {
                                    return false;
                                }
                            } else {
                                if (features[49] /* Feature_Modified_Shock_Index_min */ <= 1.02543f) {
                                    return false;
                                } else {
                                    return false;
                                }
                            }
                        } else {
                            if (features[20] /* ART_SBP_std */ <= 0.67526f) {
                                if (features[1] /* ART_SBP_mean */ <= -0.66274f) {
                                    return false;
                                } else {
                                    return false;
                                }
                            } else {
                                if (features[84] /* BT_slope */ <= -1.11277f) {
                                    return false;
                                } else {
                                    return false;
                                }
                            }
                        }
                    }
                }
            } else {
                if (features[39] /* ART_SBP_min */ <= -0.34811f) {
                    if (features[66] /* Feature_Pulse_Pressure_max */ <= -0.50952f) {
                        return true;
                    } else {
                        if (features[72] /* Feature_HR_Delta_60s_max */ <= -0.08401f) {
                            return true;
                        } else {
                            if (features[85] /* Feature_Pulse_Pressure_slope */ <= -0.59311f) {
                                return false;
                            } else {
                                if (features[90] /* Feature_HR_Std_60s_slope */ <= 0.10867f) {
                                    return false;
                                } else {
                                    return false;
                                }
                            }
                        }
                    }
                } else {
                    if (features[17] /* Feature_MBP_Std_60s_mean */ <= -0.15515f) {
                        if (features[83] /* FIO2_slope */ <= 0.91739f) {
                            if (features[6] /* ETCO2_mean */ <= -0.66240f) {
                                return false;
                            } else {
                                if (features[69] /* Feature_Rate_Pressure_Product_max */ <= 0.89396f) {
                                    return false;
                                } else {
                                    return false;
                                }
                            }
                        } else {
                            if (features[5] /* RR_CO2_mean */ <= -0.32220f) {
                                if (features[40] /* ART_DBP_min */ <= -1.49566f) {
                                    return true;
                                } else {
                                    return false;
                                }
                            } else {
                                if (features[36] /* Feature_MBP_Std_60s_std */ <= -0.48691f) {
                                    return false;
                                } else {
                                    return false;
                                }
                            }
                        }
                    } else {
                        if (features[67] /* Feature_Shock_Index_max */ <= -0.35320f) {
                            if (features[23] /* PLETH_SPO2_std */ <= 0.54538f) {
                                if (features[90] /* Feature_HR_Std_60s_slope */ <= 0.82321f) {
                                    return false;
                                } else {
                                    return false;
                                }
                            } else {
                                if (features[53] /* Feature_HR_Delta_60s_min */ <= 0.24225f) {
                                    return false;
                                } else {
                                    return false;
                                }
                            }
                        } else {
                            if (features[40] /* ART_DBP_min */ <= 0.65443f) {
                                if (features[46] /* BT_min */ <= 0.26552f) {
                                    return false;
                                } else {
                                    return false;
                                }
                            } else {
                                if (features[39] /* ART_SBP_min */ <= 0.78325f) {
                                    return false;
                                } else {
                                    return false;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}
