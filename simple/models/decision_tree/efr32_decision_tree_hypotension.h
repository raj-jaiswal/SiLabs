// Direct C Decision Tree for Future Hypotension (95 Features, W=600s, STRIDE=5s)
#include <stdbool.h>

static inline bool predict_hypotension_95(const float* features) {
    if (features[39] /* ART_SBP_min */ <= 0.09726f) {
        if (features[73] /* Feature_MBP_Mean_60s_max */ <= -2.47057f) {
            return false; /* p_pos=0.000, tau=0.29 */
        } else {
            if (features[2] /* ART_DBP_mean */ <= -0.36479f) {
                if (features[87] /* Feature_Modified_Shock_Index_slope */ <= 0.12506f) {
                    if (features[1] /* ART_SBP_mean */ <= -0.62831f) {
                        if (features[21] /* ART_DBP_std */ <= 2.61022f) {
                            if (features[2] /* ART_DBP_mean */ <= -0.82538f) {
                                if (features[58] /* ART_SBP_max */ <= -0.81312f) {
                                    return true; /* p_pos=0.971, tau=0.29 */
                                } else {
                                    return true; /* p_pos=0.834, tau=0.29 */
                                }
                            } else {
                                if (features[12] /* Feature_Rate_Pressure_Product_mean */ <= -0.18953f) {
                                    return true; /* p_pos=0.656, tau=0.29 */
                                } else {
                                    return true; /* p_pos=0.822, tau=0.29 */
                                }
                            }
                        } else {
                            if (features[13] /* Feature_HR_Mean_60s_mean */ <= 2.94078f) {
                                if (features[64] /* FIO2_max */ <= 2.01501f) {
                                    return true; /* p_pos=0.458, tau=0.29 */
                                } else {
                                    return true; /* p_pos=0.705, tau=0.29 */
                                }
                            } else {
                                if (features[63] /* ETCO2_max */ <= -0.22937f) {
                                    return true; /* p_pos=0.652, tau=0.29 */
                                } else {
                                    return true; /* p_pos=1.000, tau=0.29 */
                                }
                            }
                        }
                    } else {
                        if (features[60] /* ART_MBP_max */ <= -0.75143f) {
                            if (features[41] /* ART_MBP_min */ <= -0.23004f) {
                                if (features[77] /* ART_SBP_slope */ <= 0.08154f) {
                                    return true; /* p_pos=0.951, tau=0.29 */
                                } else {
                                    return true; /* p_pos=0.856, tau=0.29 */
                                }
                            } else {
                                if (features[16] /* Feature_MBP_Mean_60s_mean */ <= -0.69560f) {
                                    return true; /* p_pos=0.913, tau=0.29 */
                                } else {
                                    return true; /* p_pos=0.625, tau=0.29 */
                                }
                            }
                        } else {
                            if (features[13] /* Feature_HR_Mean_60s_mean */ <= 0.66294f) {
                                if (features[41] /* ART_MBP_min */ <= -0.16776f) {
                                    return true; /* p_pos=0.537, tau=0.29 */
                                } else {
                                    return true; /* p_pos=0.311, tau=0.29 */
                                }
                            } else {
                                if (features[30] /* Feature_Modified_Shock_Index_std */ <= 0.13347f) {
                                    return true; /* p_pos=0.557, tau=0.29 */
                                } else {
                                    return true; /* p_pos=0.701, tau=0.29 */
                                }
                            }
                        }
                    }
                } else {
                    if (features[79] /* ART_MBP_slope */ <= -0.04487f) {
                        if (features[3] /* ART_MBP_mean */ <= -0.66207f) {
                            if (features[22] /* ART_MBP_std */ <= -0.58531f) {
                                if (features[94] /* Feature_MBP_Delta_60s_slope */ <= 0.14179f) {
                                    return true; /* p_pos=0.996, tau=0.29 */
                                } else {
                                    return true; /* p_pos=0.977, tau=0.29 */
                                }
                            } else {
                                if (features[87] /* Feature_Modified_Shock_Index_slope */ <= 0.56863f) {
                                    return true; /* p_pos=0.951, tau=0.29 */
                                } else {
                                    return true; /* p_pos=0.986, tau=0.29 */
                                }
                            }
                        } else {
                            if (features[41] /* ART_MBP_min */ <= -0.13661f) {
                                if (features[3] /* ART_MBP_mean */ <= -0.56975f) {
                                    return true; /* p_pos=0.903, tau=0.29 */
                                } else {
                                    return true; /* p_pos=0.839, tau=0.29 */
                                }
                            } else {
                                if (features[12] /* Feature_Rate_Pressure_Product_mean */ <= -1.13865f) {
                                    return true; /* p_pos=0.786, tau=0.29 */
                                } else {
                                    return true; /* p_pos=0.588, tau=0.29 */
                                }
                            }
                        }
                    } else {
                        if (features[39] /* ART_SBP_min */ <= -0.31423f) {
                            if (features[0] /* HR_mean */ <= 0.79294f) {
                                if (features[11] /* Feature_Modified_Shock_Index_mean */ <= 0.90604f) {
                                    return true; /* p_pos=0.612, tau=0.29 */
                                } else {
                                    return true; /* p_pos=0.928, tau=0.29 */
                                }
                            } else {
                                if (features[58] /* ART_SBP_max */ <= -0.88230f) {
                                    return true; /* p_pos=0.981, tau=0.29 */
                                } else {
                                    return true; /* p_pos=0.831, tau=0.29 */
                                }
                            }
                        } else {
                            if (features[11] /* Feature_Modified_Shock_Index_mean */ <= 0.17747f) {
                                if (features[41] /* ART_MBP_min */ <= -0.23004f) {
                                    return true; /* p_pos=0.565, tau=0.29 */
                                } else {
                                    return true; /* p_pos=0.306, tau=0.29 */
                                }
                            } else {
                                if (features[88] /* Feature_Rate_Pressure_Product_slope */ <= 0.89619f) {
                                    return true; /* p_pos=0.646, tau=0.29 */
                                } else {
                                    return true; /* p_pos=0.422, tau=0.29 */
                                }
                            }
                        }
                    }
                }
            } else {
                if (features[8] /* BT_mean */ <= 0.00538f) {
                    if (features[2] /* ART_DBP_mean */ <= 0.02113f) {
                        if (features[54] /* Feature_MBP_Mean_60s_min */ <= -0.11796f) {
                            if (features[3] /* ART_MBP_mean */ <= -0.46713f) {
                                if (features[21] /* ART_DBP_std */ <= -1.00550f) {
                                    return true; /* p_pos=0.986, tau=0.29 */
                                } else {
                                    return true; /* p_pos=0.728, tau=0.29 */
                                }
                            } else {
                                if (features[79] /* ART_MBP_slope */ <= -0.01790f) {
                                    return true; /* p_pos=0.738, tau=0.29 */
                                } else {
                                    return true; /* p_pos=0.442, tau=0.29 */
                                }
                            }
                        } else {
                            if (features[55] /* Feature_MBP_Std_60s_min */ <= -0.04193f) {
                                if (features[78] /* ART_DBP_slope */ <= -0.19416f) {
                                    return true; /* p_pos=0.322, tau=0.29 */
                                } else {
                                    return false; /* p_pos=0.166, tau=0.29 */
                                }
                            } else {
                                if (features[0] /* HR_mean */ <= 0.27754f) {
                                    return true; /* p_pos=0.506, tau=0.29 */
                                } else {
                                    return true; /* p_pos=0.329, tau=0.29 */
                                }
                            }
                        }
                    } else {
                        if (features[54] /* Feature_MBP_Mean_60s_min */ <= -0.00744f) {
                            if (features[58] /* ART_SBP_max */ <= -1.43572f) {
                                if (features[75] /* Feature_MBP_Delta_60s_max */ <= -0.09785f) {
                                    return true; /* p_pos=0.963, tau=0.29 */
                                } else {
                                    return true; /* p_pos=1.000, tau=0.29 */
                                }
                            } else {
                                if (features[87] /* Feature_Modified_Shock_Index_slope */ <= 0.42072f) {
                                    return true; /* p_pos=0.414, tau=0.29 */
                                } else {
                                    return true; /* p_pos=0.745, tau=0.29 */
                                }
                            }
                        } else {
                            if (features[1] /* ART_SBP_mean */ <= -0.68024f) {
                                if (features[51] /* Feature_HR_Mean_60s_min */ <= -0.81171f) {
                                    return false; /* p_pos=0.250, tau=0.29 */
                                } else {
                                    return true; /* p_pos=0.552, tau=0.29 */
                                }
                            } else {
                                if (features[19] /* HR_std */ <= -0.36991f) {
                                    return false; /* p_pos=0.140, tau=0.29 */
                                } else {
                                    return false; /* p_pos=0.258, tau=0.29 */
                                }
                            }
                        }
                    }
                } else {
                    if (features[78] /* ART_DBP_slope */ <= -0.48340f) {
                        if (features[16] /* Feature_MBP_Mean_60s_mean */ <= -0.11263f) {
                            if (features[86] /* Feature_Shock_Index_slope */ <= 0.72840f) {
                                if (features[19] /* HR_std */ <= 0.06696f) {
                                    return true; /* p_pos=0.538, tau=0.29 */
                                } else {
                                    return true; /* p_pos=0.675, tau=0.29 */
                                }
                            } else {
                                if (features[88] /* Feature_Rate_Pressure_Product_slope */ <= -0.26100f) {
                                    return true; /* p_pos=0.858, tau=0.29 */
                                } else {
                                    return true; /* p_pos=0.705, tau=0.29 */
                                }
                            }
                        } else {
                            if (features[54] /* Feature_MBP_Mean_60s_min */ <= -0.03427f) {
                                if (features[33] /* Feature_HR_Std_60s_std */ <= -0.03583f) {
                                    return true; /* p_pos=0.624, tau=0.29 */
                                } else {
                                    return true; /* p_pos=0.685, tau=0.29 */
                                }
                            } else {
                                if (features[94] /* Feature_MBP_Delta_60s_slope */ <= -0.31772f) {
                                    return true; /* p_pos=0.362, tau=0.29 */
                                } else {
                                    return false; /* p_pos=0.217, tau=0.29 */
                                }
                            }
                        }
                    } else {
                        if (features[41] /* ART_MBP_min */ <= 0.00352f) {
                            if (features[2] /* ART_DBP_mean */ <= -0.04191f) {
                                if (features[77] /* ART_SBP_slope */ <= -0.07514f) {
                                    return true; /* p_pos=0.555, tau=0.29 */
                                } else {
                                    return true; /* p_pos=0.331, tau=0.29 */
                                }
                            } else {
                                if (features[21] /* ART_DBP_std */ <= -1.02534f) {
                                    return true; /* p_pos=0.940, tau=0.29 */
                                } else {
                                    return false; /* p_pos=0.243, tau=0.29 */
                                }
                            }
                        } else {
                            if (features[40] /* ART_DBP_min */ <= 0.48911f) {
                                if (features[2] /* ART_DBP_mean */ <= -0.11281f) {
                                    return false; /* p_pos=0.234, tau=0.29 */
                                } else {
                                    return false; /* p_pos=0.162, tau=0.29 */
                                }
                            } else {
                                if (features[1] /* ART_SBP_mean */ <= -0.85324f) {
                                    return true; /* p_pos=0.380, tau=0.29 */
                                } else {
                                    return false; /* p_pos=0.095, tau=0.29 */
                                }
                            }
                        }
                    }
                }
            }
        }
    } else {
        if (features[73] /* Feature_MBP_Mean_60s_max */ <= -0.59521f) {
            if (features[3] /* ART_MBP_mean */ <= -0.54270f) {
                if (features[79] /* ART_MBP_slope */ <= -0.01790f) {
                    if (features[58] /* ART_SBP_max */ <= 0.01701f) {
                        if (features[2] /* ART_DBP_mean */ <= -1.23811f) {
                            return true; /* p_pos=1.000, tau=0.29 */
                        } else {
                            if (features[28] /* Feature_Pulse_Pressure_std */ <= -0.80523f) {
                                if (features[30] /* Feature_Modified_Shock_Index_std */ <= -0.65475f) {
                                    return true; /* p_pos=0.944, tau=0.29 */
                                } else {
                                    return true; /* p_pos=0.628, tau=0.29 */
                                }
                            } else {
                                if (features[16] /* Feature_MBP_Mean_60s_mean */ <= -0.68066f) {
                                    return true; /* p_pos=0.987, tau=0.29 */
                                } else {
                                    return true; /* p_pos=0.841, tau=0.29 */
                                }
                            }
                        }
                    } else {
                        if (features[41] /* ART_MBP_min */ <= -0.37017f) {
                            return true; /* p_pos=1.000, tau=0.29 */
                        } else {
                            if (features[37] /* Feature_MBP_Delta_60s_std */ <= -0.58685f) {
                                return true; /* p_pos=1.000, tau=0.29 */
                            } else {
                                return true; /* p_pos=0.800, tau=0.29 */
                            }
                        }
                    }
                } else {
                    if (features[16] /* Feature_MBP_Mean_60s_mean */ <= -0.77972f) {
                        if (features[49] /* Feature_Modified_Shock_Index_min */ <= 0.00924f) {
                            return true; /* p_pos=0.333, tau=0.29 */
                        } else {
                            if (features[60] /* ART_MBP_max */ <= -0.78720f) {
                                if (features[67] /* Feature_Shock_Index_max */ <= -0.82997f) {
                                    return true; /* p_pos=0.900, tau=0.29 */
                                } else {
                                    return true; /* p_pos=1.000, tau=0.29 */
                                }
                            } else {
                                if (features[37] /* Feature_MBP_Delta_60s_std */ <= -0.59156f) {
                                    return true; /* p_pos=0.400, tau=0.29 */
                                } else {
                                    return true; /* p_pos=0.843, tau=0.29 */
                                }
                            }
                        }
                    } else {
                        if (features[55] /* Feature_MBP_Std_60s_min */ <= -0.15919f) {
                            if (features[79] /* ART_MBP_slope */ <= 0.10347f) {
                                if (features[73] /* Feature_MBP_Mean_60s_max */ <= -0.79707f) {
                                    return true; /* p_pos=0.767, tau=0.29 */
                                } else {
                                    return true; /* p_pos=0.419, tau=0.29 */
                                }
                            } else {
                                if (features[50] /* Feature_Rate_Pressure_Product_min */ <= 1.10893f) {
                                    return false; /* p_pos=0.266, tau=0.29 */
                                } else {
                                    return true; /* p_pos=0.650, tau=0.29 */
                                }
                            }
                        } else {
                            if (features[56] /* Feature_MBP_Delta_60s_min */ <= 0.55839f) {
                                if (features[28] /* Feature_Pulse_Pressure_std */ <= -0.30462f) {
                                    return true; /* p_pos=0.784, tau=0.29 */
                                } else {
                                    return true; /* p_pos=0.519, tau=0.29 */
                                }
                            } else {
                                if (features[93] /* Feature_MBP_Std_60s_slope */ <= 0.06759f) {
                                    return true; /* p_pos=0.500, tau=0.29 */
                                } else {
                                    return false; /* p_pos=0.000, tau=0.29 */
                                }
                            }
                        }
                    }
                }
            } else {
                if (features[87] /* Feature_Modified_Shock_Index_slope */ <= 0.24122f) {
                    if (features[16] /* Feature_MBP_Mean_60s_mean */ <= -0.42458f) {
                        if (features[78] /* ART_DBP_slope */ <= -0.04953f) {
                            if (features[54] /* Feature_MBP_Mean_60s_min */ <= -0.11195f) {
                                if (features[20] /* ART_SBP_std */ <= -0.92198f) {
                                    return true; /* p_pos=1.000, tau=0.29 */
                                } else {
                                    return true; /* p_pos=0.630, tau=0.29 */
                                }
                            } else {
                                if (features[21] /* ART_DBP_std */ <= -0.92399f) {
                                    return true; /* p_pos=0.862, tau=0.29 */
                                } else {
                                    return false; /* p_pos=0.249, tau=0.29 */
                                }
                            }
                        } else {
                            if (features[41] /* ART_MBP_min */ <= 0.00352f) {
                                if (features[50] /* Feature_Rate_Pressure_Product_min */ <= 1.61324f) {
                                    return true; /* p_pos=0.376, tau=0.29 */
                                } else {
                                    return true; /* p_pos=0.816, tau=0.29 */
                                }
                            } else {
                                if (features[39] /* ART_SBP_min */ <= 0.61162f) {
                                    return false; /* p_pos=0.230, tau=0.29 */
                                } else {
                                    return false; /* p_pos=0.000, tau=0.29 */
                                }
                            }
                        }
                    } else {
                        if (features[17] /* Feature_MBP_Std_60s_mean */ <= -0.66778f) {
                            if (features[39] /* ART_SBP_min */ <= 0.26872f) {
                                if (features[6] /* ETCO2_mean */ <= 0.14881f) {
                                    return false; /* p_pos=0.079, tau=0.29 */
                                } else {
                                    return true; /* p_pos=0.688, tau=0.29 */
                                }
                            } else {
                                if (features[47] /* Feature_Pulse_Pressure_min */ <= 1.11423f) {
                                    return false; /* p_pos=0.095, tau=0.29 */
                                } else {
                                    return false; /* p_pos=0.006, tau=0.29 */
                                }
                            }
                        } else {
                            if (features[8] /* BT_mean */ <= 0.14596f) {
                                if (features[54] /* Feature_MBP_Mean_60s_min */ <= 0.14873f) {
                                    return false; /* p_pos=0.127, tau=0.29 */
                                } else {
                                    return true; /* p_pos=0.846, tau=0.29 */
                                }
                            } else {
                                if (features[54] /* Feature_MBP_Mean_60s_min */ <= -0.07751f) {
                                    return true; /* p_pos=0.448, tau=0.29 */
                                } else {
                                    return false; /* p_pos=0.231, tau=0.29 */
                                }
                            }
                        }
                    }
                } else {
                    if (features[76] /* HR_slope */ <= 0.12529f) {
                        if (features[77] /* ART_SBP_slope */ <= -0.66266f) {
                            if (features[93] /* Feature_MBP_Std_60s_slope */ <= 0.04988f) {
                                return true; /* p_pos=1.000, tau=0.29 */
                            } else {
                                return true; /* p_pos=0.900, tau=0.29 */
                            }
                        } else {
                            if (features[54] /* Feature_MBP_Mean_60s_min */ <= -0.16441f) {
                                if (features[11] /* Feature_Modified_Shock_Index_mean */ <= 0.89423f) {
                                    return true; /* p_pos=0.844, tau=0.29 */
                                } else {
                                    return true; /* p_pos=1.000, tau=0.29 */
                                }
                            } else {
                                if (features[28] /* Feature_Pulse_Pressure_std */ <= -0.65747f) {
                                    return true; /* p_pos=0.664, tau=0.29 */
                                } else {
                                    return true; /* p_pos=0.461, tau=0.29 */
                                }
                            }
                        }
                    } else {
                        if (features[49] /* Feature_Modified_Shock_Index_min */ <= -1.00299f) {
                            return false; /* p_pos=0.000, tau=0.29 */
                        } else {
                            if (features[79] /* ART_MBP_slope */ <= -0.30111f) {
                                if (features[35] /* Feature_MBP_Mean_60s_std */ <= -0.50716f) {
                                    return true; /* p_pos=0.717, tau=0.29 */
                                } else {
                                    return true; /* p_pos=0.966, tau=0.29 */
                                }
                            } else {
                                if (features[21] /* ART_DBP_std */ <= -0.70690f) {
                                    return true; /* p_pos=0.337, tau=0.29 */
                                } else {
                                    return true; /* p_pos=0.562, tau=0.29 */
                                }
                            }
                        }
                    }
                }
            }
        } else {
            if (features[30] /* Feature_Modified_Shock_Index_std */ <= -0.30166f) {
                if (features[40] /* ART_DBP_min */ <= 0.48911f) {
                    if (features[3] /* ART_MBP_mean */ <= -0.18852f) {
                        if (features[77] /* ART_SBP_slope */ <= -0.50599f) {
                            if (features[16] /* Feature_MBP_Mean_60s_mean */ <= -0.32931f) {
                                if (features[18] /* Feature_MBP_Delta_60s_mean */ <= -0.25960f) {
                                    return true; /* p_pos=0.805, tau=0.29 */
                                } else {
                                    return true; /* p_pos=0.564, tau=0.29 */
                                }
                            } else {
                                if (features[41] /* ART_MBP_min */ <= 0.00352f) {
                                    return true; /* p_pos=0.715, tau=0.29 */
                                } else {
                                    return true; /* p_pos=0.345, tau=0.29 */
                                }
                            }
                        } else {
                            if (features[22] /* ART_MBP_std */ <= -0.60137f) {
                                if (features[60] /* ART_MBP_max */ <= -0.66201f) {
                                    return true; /* p_pos=0.615, tau=0.29 */
                                } else {
                                    return false; /* p_pos=0.160, tau=0.29 */
                                }
                            } else {
                                if (features[88] /* Feature_Rate_Pressure_Product_slope */ <= 0.02967f) {
                                    return true; /* p_pos=0.378, tau=0.29 */
                                } else {
                                    return false; /* p_pos=0.192, tau=0.29 */
                                }
                            }
                        }
                    } else {
                        if (features[88] /* Feature_Rate_Pressure_Product_slope */ <= -0.45367f) {
                            if (features[31] /* Feature_Rate_Pressure_Product_std */ <= -0.13142f) {
                                if (features[59] /* ART_DBP_max */ <= 0.05702f) {
                                    return false; /* p_pos=0.170, tau=0.29 */
                                } else {
                                    return false; /* p_pos=0.087, tau=0.29 */
                                }
                            } else {
                                if (features[41] /* ART_MBP_min */ <= 0.23707f) {
                                    return true; /* p_pos=0.436, tau=0.29 */
                                } else {
                                    return false; /* p_pos=0.150, tau=0.29 */
                                }
                            }
                        } else {
                            if (features[54] /* Feature_MBP_Mean_60s_min */ <= 0.15233f) {
                                if (features[78] /* ART_DBP_slope */ <= 0.02278f) {
                                    return false; /* p_pos=0.245, tau=0.29 */
                                } else {
                                    return false; /* p_pos=0.143, tau=0.29 */
                                }
                            } else {
                                if (features[26] /* FIO2_std */ <= 1.89386f) {
                                    return false; /* p_pos=0.090, tau=0.29 */
                                } else {
                                    return false; /* p_pos=0.206, tau=0.29 */
                                }
                            }
                        }
                    }
                } else {
                    if (features[46] /* BT_min */ <= 0.05471f) {
                        if (features[75] /* Feature_MBP_Delta_60s_max */ <= -0.84874f) {
                            if (features[39] /* ART_SBP_min */ <= 2.06898f) {
                                if (features[55] /* Feature_MBP_Std_60s_min */ <= 2.21877f) {
                                    return true; /* p_pos=0.966, tau=0.29 */
                                } else {
                                    return true; /* p_pos=0.404, tau=0.29 */
                                }
                            } else {
                                if (features[48] /* Feature_Shock_Index_min */ <= -0.74562f) {
                                    return true; /* p_pos=0.739, tau=0.29 */
                                } else {
                                    return false; /* p_pos=0.000, tau=0.29 */
                                }
                            }
                        } else {
                            if (features[78] /* ART_DBP_slope */ <= 0.45665f) {
                                if (features[9] /* Feature_Pulse_Pressure_mean */ <= 2.01682f) {
                                    return false; /* p_pos=0.070, tau=0.29 */
                                } else {
                                    return true; /* p_pos=0.301, tau=0.29 */
                                }
                            } else {
                                if (features[71] /* Feature_HR_Std_60s_max */ <= -0.77461f) {
                                    return false; /* p_pos=0.030, tau=0.29 */
                                } else {
                                    return false; /* p_pos=0.184, tau=0.29 */
                                }
                            }
                        }
                    } else {
                        if (features[22] /* ART_MBP_std */ <= -0.41166f) {
                            if (features[10] /* Feature_Shock_Index_mean */ <= -0.10287f) {
                                if (features[3] /* ART_MBP_mean */ <= 0.21216f) {
                                    return false; /* p_pos=0.057, tau=0.29 */
                                } else {
                                    return false; /* p_pos=0.028, tau=0.29 */
                                }
                            } else {
                                if (features[2] /* ART_DBP_mean */ <= 0.34042f) {
                                    return false; /* p_pos=0.077, tau=0.29 */
                                } else {
                                    return false; /* p_pos=0.040, tau=0.29 */
                                }
                            }
                        } else {
                            if (features[76] /* HR_slope */ <= 0.95690f) {
                                if (features[64] /* FIO2_max */ <= 1.70353f) {
                                    return false; /* p_pos=0.051, tau=0.29 */
                                } else {
                                    return false; /* p_pos=0.107, tau=0.29 */
                                }
                            } else {
                                if (features[64] /* FIO2_max */ <= 1.39205f) {
                                    return false; /* p_pos=0.075, tau=0.29 */
                                } else {
                                    return false; /* p_pos=0.201, tau=0.29 */
                                }
                            }
                        }
                    }
                }
            } else {
                if (features[73] /* Feature_MBP_Mean_60s_max */ <= -0.22431f) {
                    if (features[56] /* Feature_MBP_Delta_60s_min */ <= 0.51984f) {
                        if (features[54] /* Feature_MBP_Mean_60s_min */ <= 0.02500f) {
                            if (features[79] /* ART_MBP_slope */ <= -0.17973f) {
                                if (features[92] /* Feature_MBP_Mean_60s_slope */ <= -0.75193f) {
                                    return true; /* p_pos=0.815, tau=0.29 */
                                } else {
                                    return true; /* p_pos=0.620, tau=0.29 */
                                }
                            } else {
                                if (features[3] /* ART_MBP_mean */ <= -0.35744f) {
                                    return true; /* p_pos=0.511, tau=0.29 */
                                } else {
                                    return true; /* p_pos=0.318, tau=0.29 */
                                }
                            }
                        } else {
                            if (features[73] /* Feature_MBP_Mean_60s_max */ <= -0.32747f) {
                                if (features[77] /* ART_SBP_slope */ <= -0.11430f) {
                                    return false; /* p_pos=0.287, tau=0.29 */
                                } else {
                                    return false; /* p_pos=0.152, tau=0.29 */
                                }
                            } else {
                                if (features[35] /* Feature_MBP_Mean_60s_std */ <= -0.47961f) {
                                    return false; /* p_pos=0.102, tau=0.29 */
                                } else {
                                    return false; /* p_pos=0.207, tau=0.29 */
                                }
                            }
                        }
                    } else {
                        if (features[20] /* ART_SBP_std */ <= -0.50949f) {
                            if (features[78] /* ART_DBP_slope */ <= -0.48340f) {
                                if (features[60] /* ART_MBP_max */ <= -0.57260f) {
                                    return true; /* p_pos=0.844, tau=0.29 */
                                } else {
                                    return false; /* p_pos=0.239, tau=0.29 */
                                }
                            } else {
                                if (features[16] /* Feature_MBP_Mean_60s_mean */ <= -0.09852f) {
                                    return false; /* p_pos=0.133, tau=0.29 */
                                } else {
                                    return false; /* p_pos=0.046, tau=0.29 */
                                }
                            }
                        } else {
                            if (features[2] /* ART_DBP_mean */ <= -0.18808f) {
                                if (features[56] /* Feature_MBP_Delta_60s_min */ <= 0.55839f) {
                                    return true; /* p_pos=0.327, tau=0.29 */
                                } else {
                                    return false; /* p_pos=0.139, tau=0.29 */
                                }
                            } else {
                                if (features[40] /* ART_DBP_min */ <= 0.26856f) {
                                    return false; /* p_pos=0.232, tau=0.29 */
                                } else {
                                    return false; /* p_pos=0.097, tau=0.29 */
                                }
                            }
                        }
                    }
                } else {
                    if (features[35] /* Feature_MBP_Mean_60s_std */ <= -0.31384f) {
                        if (features[33] /* Feature_HR_Std_60s_std */ <= 0.18276f) {
                            if (features[94] /* Feature_MBP_Delta_60s_slope */ <= -0.26521f) {
                                if (features[32] /* Feature_HR_Mean_60s_std */ <= 1.31381f) {
                                    return false; /* p_pos=0.173, tau=0.29 */
                                } else {
                                    return false; /* p_pos=0.000, tau=0.29 */
                                }
                            } else {
                                if (features[26] /* FIO2_std */ <= 1.95617f) {
                                    return false; /* p_pos=0.079, tau=0.29 */
                                } else {
                                    return false; /* p_pos=0.201, tau=0.29 */
                                }
                            }
                        } else {
                            if (features[62] /* RR_CO2_max */ <= 2.13049f) {
                                if (features[77] /* ART_SBP_slope */ <= -0.54516f) {
                                    return false; /* p_pos=0.106, tau=0.29 */
                                } else {
                                    return false; /* p_pos=0.048, tau=0.29 */
                                }
                            } else {
                                if (features[24] /* RR_CO2_std */ <= 3.36319f) {
                                    return false; /* p_pos=0.152, tau=0.29 */
                                } else {
                                    return true; /* p_pos=0.417, tau=0.29 */
                                }
                            }
                        }
                    } else {
                        if (features[40] /* ART_DBP_min */ <= 0.37884f) {
                            if (features[68] /* Feature_Modified_Shock_Index_max */ <= -0.18979f) {
                                if (features[85] /* Feature_Pulse_Pressure_slope */ <= -0.33632f) {
                                    return false; /* p_pos=0.269, tau=0.29 */
                                } else {
                                    return false; /* p_pos=0.150, tau=0.29 */
                                }
                            } else {
                                if (features[41] /* ART_MBP_min */ <= 0.09694f) {
                                    return true; /* p_pos=0.388, tau=0.29 */
                                } else {
                                    return false; /* p_pos=0.212, tau=0.29 */
                                }
                            }
                        } else {
                            if (features[87] /* Feature_Modified_Shock_Index_slope */ <= 0.61047f) {
                                if (features[31] /* Feature_Rate_Pressure_Product_std */ <= 0.45971f) {
                                    return false; /* p_pos=0.070, tau=0.29 */
                                } else {
                                    return false; /* p_pos=0.115, tau=0.29 */
                                }
                            } else {
                                if (features[26] /* FIO2_std */ <= -0.34670f) {
                                    return false; /* p_pos=0.119, tau=0.29 */
                                } else {
                                    return false; /* p_pos=0.163, tau=0.29 */
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}

