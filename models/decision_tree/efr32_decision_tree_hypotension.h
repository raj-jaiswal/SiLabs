// Direct C Decision Tree for Future Hypotension (95 Features, W=600s, STRIDE=5s)
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

static inline DecisionTreeResult predict_hypotension_95(const float* features) {
    if (features[39] /* ART_SBP_min */ <= 0.24337f) {
        if (features[73] /* Feature_MBP_Mean_60s_max */ <= -2.46225f) {
            {
                DecisionTreeResult res = { 100.0000f, 0.0000f, 1.00000f, 0.00000f, false };
                return res; /* Class 0: 100.00%, Class 1: 0.00% (tau=0.29) */
            }
        } else {
            if (features[2] /* ART_DBP_mean */ <= -0.26985f) {
                if (features[87] /* Feature_Modified_Shock_Index_slope */ <= 0.10054f) {
                    if (features[1] /* ART_SBP_mean */ <= -0.62833f) {
                        if (features[21] /* ART_DBP_std */ <= 2.40920f) {
                            if (features[2] /* ART_DBP_mean */ <= -0.78659f) {
                                if (features[58] /* ART_SBP_max */ <= -0.83942f) {
                                    {
                                        DecisionTreeResult res = { 2.9402f, 97.0598f, 0.02940f, 0.97060f, true };
                                        return res; /* Class 0: 2.94%, Class 1: 97.06% (tau=0.29) */
                                    }
                                } else {
                                    {
                                        DecisionTreeResult res = { 16.5971f, 83.4029f, 0.16597f, 0.83403f, true };
                                        return res; /* Class 0: 16.60%, Class 1: 83.40% (tau=0.29) */
                                    }
                                }
                            } else {
                                if (features[12] /* Feature_Rate_Pressure_Product_mean */ <= -0.15321f) {
                                    {
                                        DecisionTreeResult res = { 34.4226f, 65.5774f, 0.34423f, 0.65577f, true };
                                        return res; /* Class 0: 34.42%, Class 1: 65.58% (tau=0.29) */
                                    }
                                } else {
                                    {
                                        DecisionTreeResult res = { 17.8131f, 82.1869f, 0.17813f, 0.82187f, true };
                                        return res; /* Class 0: 17.81%, Class 1: 82.19% (tau=0.29) */
                                    }
                                }
                            }
                        } else {
                            if (features[13] /* Feature_HR_Mean_60s_mean */ <= 2.89581f) {
                                if (features[64] /* FIO2_max */ <= 2.02315f) {
                                    {
                                        DecisionTreeResult res = { 54.2120f, 45.7880f, 0.54212f, 0.45788f, true };
                                        return res; /* Class 0: 54.21%, Class 1: 45.79% (tau=0.29) */
                                    }
                                } else {
                                    {
                                        DecisionTreeResult res = { 29.5455f, 70.4545f, 0.29545f, 0.70455f, true };
                                        return res; /* Class 0: 29.55%, Class 1: 70.45% (tau=0.29) */
                                    }
                                }
                            } else {
                                if (features[63] /* ETCO2_max */ <= -0.21672f) {
                                    {
                                        DecisionTreeResult res = { 34.7826f, 65.2174f, 0.34783f, 0.65217f, true };
                                        return res; /* Class 0: 34.78%, Class 1: 65.22% (tau=0.29) */
                                    }
                                } else {
                                    {
                                        DecisionTreeResult res = { 0.0000f, 100.0000f, 0.00000f, 1.00000f, true };
                                        return res; /* Class 0: 0.00%, Class 1: 100.00% (tau=0.29) */
                                    }
                                }
                            }
                        }
                    } else {
                        if (features[60] /* ART_MBP_max */ <= -0.73041f) {
                            if (features[41] /* ART_MBP_min */ <= -0.08557f) {
                                if (features[77] /* ART_SBP_slope */ <= 0.13256f) {
                                    {
                                        DecisionTreeResult res = { 4.8587f, 95.1413f, 0.04859f, 0.95141f, true };
                                        return res; /* Class 0: 4.86%, Class 1: 95.14% (tau=0.29) */
                                    }
                                } else {
                                    {
                                        DecisionTreeResult res = { 14.3925f, 85.6075f, 0.14393f, 0.85607f, true };
                                        return res; /* Class 0: 14.39%, Class 1: 85.61% (tau=0.29) */
                                    }
                                }
                            } else {
                                if (features[16] /* Feature_MBP_Mean_60s_mean */ <= -0.63888f) {
                                    {
                                        DecisionTreeResult res = { 8.6957f, 91.3043f, 0.08696f, 0.91304f, true };
                                        return res; /* Class 0: 8.70%, Class 1: 91.30% (tau=0.29) */
                                    }
                                } else {
                                    {
                                        DecisionTreeResult res = { 37.5000f, 62.5000f, 0.37500f, 0.62500f, true };
                                        return res; /* Class 0: 37.50%, Class 1: 62.50% (tau=0.29) */
                                    }
                                }
                            }
                        } else {
                            if (features[13] /* Feature_HR_Mean_60s_mean */ <= 0.63161f) {
                                if (features[41] /* ART_MBP_min */ <= -0.01604f) {
                                    {
                                        DecisionTreeResult res = { 46.3325f, 53.6675f, 0.46332f, 0.53668f, true };
                                        return res; /* Class 0: 46.33%, Class 1: 53.67% (tau=0.29) */
                                    }
                                } else {
                                    {
                                        DecisionTreeResult res = { 68.9390f, 31.0610f, 0.68939f, 0.31061f, true };
                                        return res; /* Class 0: 68.94%, Class 1: 31.06% (tau=0.29) */
                                    }
                                }
                            } else {
                                if (features[30] /* Feature_Modified_Shock_Index_std */ <= 0.06370f) {
                                    {
                                        DecisionTreeResult res = { 44.2649f, 55.7351f, 0.44265f, 0.55735f, true };
                                        return res; /* Class 0: 44.26%, Class 1: 55.74% (tau=0.29) */
                                    }
                                } else {
                                    {
                                        DecisionTreeResult res = { 29.8598f, 70.1402f, 0.29860f, 0.70140f, true };
                                        return res; /* Class 0: 29.86%, Class 1: 70.14% (tau=0.29) */
                                    }
                                }
                            }
                        }
                    }
                } else {
                    if (features[79] /* ART_MBP_slope */ <= 0.00277f) {
                        if (features[3] /* ART_MBP_mean */ <= -0.60260f) {
                            if (features[22] /* ART_MBP_std */ <= -0.60980f) {
                                if (features[94] /* Feature_MBP_Delta_60s_slope */ <= 0.14878f) {
                                    {
                                        DecisionTreeResult res = { 0.4246f, 99.5754f, 0.00425f, 0.99575f, true };
                                        return res; /* Class 0: 0.42%, Class 1: 99.58% (tau=0.29) */
                                    }
                                } else {
                                    {
                                        DecisionTreeResult res = { 2.3129f, 97.6871f, 0.02313f, 0.97687f, true };
                                        return res; /* Class 0: 2.31%, Class 1: 97.69% (tau=0.29) */
                                    }
                                }
                            } else {
                                if (features[87] /* Feature_Modified_Shock_Index_slope */ <= 0.51607f) {
                                    {
                                        DecisionTreeResult res = { 4.9108f, 95.0892f, 0.04911f, 0.95089f, true };
                                        return res; /* Class 0: 4.91%, Class 1: 95.09% (tau=0.29) */
                                    }
                                } else {
                                    {
                                        DecisionTreeResult res = { 1.3943f, 98.6057f, 0.01394f, 0.98606f, true };
                                        return res; /* Class 0: 1.39%, Class 1: 98.61% (tau=0.29) */
                                    }
                                }
                            }
                        } else {
                            if (features[41] /* ART_MBP_min */ <= 0.01873f) {
                                if (features[3] /* ART_MBP_mean */ <= -0.49817f) {
                                    {
                                        DecisionTreeResult res = { 9.7178f, 90.2822f, 0.09718f, 0.90282f, true };
                                        return res; /* Class 0: 9.72%, Class 1: 90.28% (tau=0.29) */
                                    }
                                } else {
                                    {
                                        DecisionTreeResult res = { 16.1008f, 83.8992f, 0.16101f, 0.83899f, true };
                                        return res; /* Class 0: 16.10%, Class 1: 83.90% (tau=0.29) */
                                    }
                                }
                            } else {
                                if (features[12] /* Feature_Rate_Pressure_Product_mean */ <= -1.17206f) {
                                    {
                                        DecisionTreeResult res = { 21.4470f, 78.5530f, 0.21447f, 0.78553f, true };
                                        return res; /* Class 0: 21.45%, Class 1: 78.55% (tau=0.29) */
                                    }
                                } else {
                                    {
                                        DecisionTreeResult res = { 41.1963f, 58.8037f, 0.41196f, 0.58804f, true };
                                        return res; /* Class 0: 41.20%, Class 1: 58.80% (tau=0.29) */
                                    }
                                }
                            }
                        }
                    } else {
                        if (features[39] /* ART_SBP_min */ <= -0.21250f) {
                            if (features[0] /* HR_mean */ <= 0.76164f) {
                                if (features[11] /* Feature_Modified_Shock_Index_mean */ <= 0.66428f) {
                                    {
                                        DecisionTreeResult res = { 38.7776f, 61.2224f, 0.38778f, 0.61222f, true };
                                        return res; /* Class 0: 38.78%, Class 1: 61.22% (tau=0.29) */
                                    }
                                } else {
                                    {
                                        DecisionTreeResult res = { 7.2464f, 92.7536f, 0.07246f, 0.92754f, true };
                                        return res; /* Class 0: 7.25%, Class 1: 92.75% (tau=0.29) */
                                    }
                                }
                            } else {
                                if (features[58] /* ART_SBP_max */ <= -0.91172f) {
                                    {
                                        DecisionTreeResult res = { 1.9355f, 98.0645f, 0.01935f, 0.98065f, true };
                                        return res; /* Class 0: 1.94%, Class 1: 98.06% (tau=0.29) */
                                    }
                                } else {
                                    {
                                        DecisionTreeResult res = { 16.8966f, 83.1034f, 0.16897f, 0.83103f, true };
                                        return res; /* Class 0: 16.90%, Class 1: 83.10% (tau=0.29) */
                                    }
                                }
                            }
                        } else {
                            if (features[11] /* Feature_Modified_Shock_Index_mean */ <= -0.01353f) {
                                if (features[41] /* ART_MBP_min */ <= -0.08557f) {
                                    {
                                        DecisionTreeResult res = { 43.4694f, 56.5306f, 0.43469f, 0.56531f, true };
                                        return res; /* Class 0: 43.47%, Class 1: 56.53% (tau=0.29) */
                                    }
                                } else {
                                    {
                                        DecisionTreeResult res = { 69.3916f, 30.6084f, 0.69392f, 0.30608f, true };
                                        return res; /* Class 0: 69.39%, Class 1: 30.61% (tau=0.29) */
                                    }
                                }
                            } else {
                                if (features[88] /* Feature_Rate_Pressure_Product_slope */ <= 0.92262f) {
                                    {
                                        DecisionTreeResult res = { 35.3909f, 64.6091f, 0.35391f, 0.64609f, true };
                                        return res; /* Class 0: 35.39%, Class 1: 64.61% (tau=0.29) */
                                    }
                                } else {
                                    {
                                        DecisionTreeResult res = { 57.7586f, 42.2414f, 0.57759f, 0.42241f, true };
                                        return res; /* Class 0: 57.76%, Class 1: 42.24% (tau=0.29) */
                                    }
                                }
                            }
                        }
                    }
                }
            } else {
                if (features[8] /* BT_mean */ <= 0.08730f) {
                    if (features[2] /* ART_DBP_mean */ <= 0.16311f) {
                        if (features[54] /* Feature_MBP_Mean_60s_min */ <= 0.04420f) {
                            if (features[3] /* ART_MBP_mean */ <= -0.38208f) {
                                if (features[21] /* ART_DBP_std */ <= -1.00234f) {
                                    {
                                        DecisionTreeResult res = { 1.3986f, 98.6014f, 0.01399f, 0.98601f, true };
                                        return res; /* Class 0: 1.40%, Class 1: 98.60% (tau=0.29) */
                                    }
                                } else {
                                    {
                                        DecisionTreeResult res = { 27.1584f, 72.8416f, 0.27158f, 0.72842f, true };
                                        return res; /* Class 0: 27.16%, Class 1: 72.84% (tau=0.29) */
                                    }
                                }
                            } else {
                                if (features[79] /* ART_MBP_slope */ <= 0.02858f) {
                                    {
                                        DecisionTreeResult res = { 26.1661f, 73.8339f, 0.26166f, 0.73834f, true };
                                        return res; /* Class 0: 26.17%, Class 1: 73.83% (tau=0.29) */
                                    }
                                } else {
                                    {
                                        DecisionTreeResult res = { 55.8111f, 44.1889f, 0.55811f, 0.44189f, true };
                                        return res; /* Class 0: 55.81%, Class 1: 44.19% (tau=0.29) */
                                    }
                                }
                            }
                        } else {
                            if (features[55] /* Feature_MBP_Std_60s_min */ <= -0.04836f) {
                                if (features[78] /* ART_DBP_slope */ <= -0.12978f) {
                                    {
                                        DecisionTreeResult res = { 67.7878f, 32.2122f, 0.67788f, 0.32212f, true };
                                        return res; /* Class 0: 67.79%, Class 1: 32.21% (tau=0.29) */
                                    }
                                } else {
                                    {
                                        DecisionTreeResult res = { 83.3910f, 16.6090f, 0.83391f, 0.16609f, false };
                                        return res; /* Class 0: 83.39%, Class 1: 16.61% (tau=0.29) */
                                    }
                                }
                            } else {
                                if (features[0] /* HR_mean */ <= 0.24934f) {
                                    {
                                        DecisionTreeResult res = { 49.4220f, 50.5780f, 0.49422f, 0.50578f, true };
                                        return res; /* Class 0: 49.42%, Class 1: 50.58% (tau=0.29) */
                                    }
                                } else {
                                    {
                                        DecisionTreeResult res = { 67.1123f, 32.8877f, 0.67112f, 0.32888f, true };
                                        return res; /* Class 0: 67.11%, Class 1: 32.89% (tau=0.29) */
                                    }
                                }
                            }
                        }
                    } else {
                        if (features[54] /* Feature_MBP_Mean_60s_min */ <= 0.16898f) {
                            if (features[58] /* ART_SBP_max */ <= -1.49015f) {
                                if (features[75] /* Feature_MBP_Delta_60s_max */ <= -0.14196f) {
                                    {
                                        DecisionTreeResult res = { 3.7037f, 96.2963f, 0.03704f, 0.96296f, true };
                                        return res; /* Class 0: 3.70%, Class 1: 96.30% (tau=0.29) */
                                    }
                                } else {
                                    {
                                        DecisionTreeResult res = { 0.0000f, 100.0000f, 0.00000f, 1.00000f, true };
                                        return res; /* Class 0: 0.00%, Class 1: 100.00% (tau=0.29) */
                                    }
                                }
                            } else {
                                if (features[87] /* Feature_Modified_Shock_Index_slope */ <= 0.37752f) {
                                    {
                                        DecisionTreeResult res = { 58.5551f, 41.4449f, 0.58555f, 0.41445f, true };
                                        return res; /* Class 0: 58.56%, Class 1: 41.44% (tau=0.29) */
                                    }
                                } else {
                                    {
                                        DecisionTreeResult res = { 25.5368f, 74.4632f, 0.25537f, 0.74463f, true };
                                        return res; /* Class 0: 25.54%, Class 1: 74.46% (tau=0.29) */
                                    }
                                }
                            }
                        } else {
                            if (features[1] /* ART_SBP_mean */ <= -0.68832f) {
                                if (features[51] /* Feature_HR_Mean_60s_min */ <= -0.84037f) {
                                    {
                                        DecisionTreeResult res = { 75.0000f, 25.0000f, 0.75000f, 0.25000f, false };
                                        return res; /* Class 0: 75.00%, Class 1: 25.00% (tau=0.29) */
                                    }
                                } else {
                                    {
                                        DecisionTreeResult res = { 44.8029f, 55.1971f, 0.44803f, 0.55197f, true };
                                        return res; /* Class 0: 44.80%, Class 1: 55.20% (tau=0.29) */
                                    }
                                }
                            } else {
                                if (features[19] /* HR_std */ <= -0.40104f) {
                                    {
                                        DecisionTreeResult res = { 86.0012f, 13.9988f, 0.86001f, 0.13999f, false };
                                        return res; /* Class 0: 86.00%, Class 1: 14.00% (tau=0.29) */
                                    }
                                } else {
                                    {
                                        DecisionTreeResult res = { 74.2240f, 25.7760f, 0.74224f, 0.25776f, false };
                                        return res; /* Class 0: 74.22%, Class 1: 25.78% (tau=0.29) */
                                    }
                                }
                            }
                        }
                    }
                } else {
                    if (features[78] /* ART_DBP_slope */ <= -0.40590f) {
                        if (features[16] /* Feature_MBP_Mean_60s_mean */ <= 0.01861f) {
                            if (features[86] /* Feature_Shock_Index_slope */ <= 0.64624f) {
                                if (features[19] /* HR_std */ <= 0.07806f) {
                                    {
                                        DecisionTreeResult res = { 46.1521f, 53.8479f, 0.46152f, 0.53848f, true };
                                        return res; /* Class 0: 46.15%, Class 1: 53.85% (tau=0.29) */
                                    }
                                } else {
                                    {
                                        DecisionTreeResult res = { 32.5485f, 67.4515f, 0.32548f, 0.67452f, true };
                                        return res; /* Class 0: 32.55%, Class 1: 67.45% (tau=0.29) */
                                    }
                                }
                            } else {
                                if (features[88] /* Feature_Rate_Pressure_Product_slope */ <= -0.20698f) {
                                    {
                                        DecisionTreeResult res = { 14.1791f, 85.8209f, 0.14179f, 0.85821f, true };
                                        return res; /* Class 0: 14.18%, Class 1: 85.82% (tau=0.29) */
                                    }
                                } else {
                                    {
                                        DecisionTreeResult res = { 29.5499f, 70.4501f, 0.29550f, 0.70450f, true };
                                        return res; /* Class 0: 29.55%, Class 1: 70.45% (tau=0.29) */
                                    }
                                }
                            }
                        } else {
                            if (features[54] /* Feature_MBP_Mean_60s_min */ <= 0.13868f) {
                                if (features[33] /* Feature_HR_Std_60s_std */ <= -0.00469f) {
                                    {
                                        DecisionTreeResult res = { 37.5536f, 62.4464f, 0.37554f, 0.62446f, true };
                                        return res; /* Class 0: 37.55%, Class 1: 62.45% (tau=0.29) */
                                    }
                                } else {
                                    {
                                        DecisionTreeResult res = { 31.4757f, 68.5243f, 0.31476f, 0.68524f, true };
                                        return res; /* Class 0: 31.48%, Class 1: 68.52% (tau=0.29) */
                                    }
                                }
                            } else {
                                if (features[94] /* Feature_MBP_Delta_60s_slope */ <= -0.28661f) {
                                    {
                                        DecisionTreeResult res = { 63.8396f, 36.1604f, 0.63840f, 0.36160f, true };
                                        return res; /* Class 0: 63.84%, Class 1: 36.16% (tau=0.29) */
                                    }
                                } else {
                                    {
                                        DecisionTreeResult res = { 78.3056f, 21.6944f, 0.78306f, 0.21694f, false };
                                        return res; /* Class 0: 78.31%, Class 1: 21.69% (tau=0.29) */
                                    }
                                }
                            }
                        }
                    } else {
                        if (features[41] /* ART_MBP_min */ <= 0.17517f) {
                            if (features[2] /* ART_DBP_mean */ <= 0.09238f) {
                                if (features[77] /* ART_SBP_slope */ <= -0.01501f) {
                                    {
                                        DecisionTreeResult res = { 44.5008f, 55.4992f, 0.44501f, 0.55499f, true };
                                        return res; /* Class 0: 44.50%, Class 1: 55.50% (tau=0.29) */
                                    }
                                } else {
                                    {
                                        DecisionTreeResult res = { 66.9488f, 33.0512f, 0.66949f, 0.33051f, true };
                                        return res; /* Class 0: 66.95%, Class 1: 33.05% (tau=0.29) */
                                    }
                                }
                            } else {
                                if (features[21] /* ART_DBP_std */ <= -1.02106f) {
                                    {
                                        DecisionTreeResult res = { 5.9574f, 94.0426f, 0.05957f, 0.94043f, true };
                                        return res; /* Class 0: 5.96%, Class 1: 94.04% (tau=0.29) */
                                    }
                                } else {
                                    {
                                        DecisionTreeResult res = { 75.7106f, 24.2894f, 0.75711f, 0.24289f, false };
                                        return res; /* Class 0: 75.71%, Class 1: 24.29% (tau=0.29) */
                                    }
                                }
                            }
                        } else {
                            if (features[40] /* ART_DBP_min */ <= 0.69463f) {
                                if (features[2] /* ART_DBP_mean */ <= 0.01284f) {
                                    {
                                        DecisionTreeResult res = { 76.5713f, 23.4287f, 0.76571f, 0.23429f, false };
                                        return res; /* Class 0: 76.57%, Class 1: 23.43% (tau=0.29) */
                                    }
                                } else {
                                    {
                                        DecisionTreeResult res = { 83.7737f, 16.2263f, 0.83774f, 0.16226f, false };
                                        return res; /* Class 0: 83.77%, Class 1: 16.23% (tau=0.29) */
                                    }
                                }
                            } else {
                                if (features[1] /* ART_SBP_mean */ <= -0.88822f) {
                                    {
                                        DecisionTreeResult res = { 62.0130f, 37.9870f, 0.62013f, 0.37987f, true };
                                        return res; /* Class 0: 62.01%, Class 1: 37.99% (tau=0.29) */
                                    }
                                } else {
                                    {
                                        DecisionTreeResult res = { 90.4594f, 9.5406f, 0.90459f, 0.09541f, false };
                                        return res; /* Class 0: 90.46%, Class 1: 9.54% (tau=0.29) */
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    } else {
        if (features[73] /* Feature_MBP_Mean_60s_max */ <= -0.55673f) {
            if (features[3] /* ART_MBP_mean */ <= -0.46757f) {
                if (features[79] /* ART_MBP_slope */ <= 0.02858f) {
                    if (features[58] /* ART_SBP_max */ <= 0.02823f) {
                        if (features[2] /* ART_DBP_mean */ <= -1.24962f) {
                            {
                                DecisionTreeResult res = { 0.0000f, 100.0000f, 0.00000f, 1.00000f, true };
                                return res; /* Class 0: 0.00%, Class 1: 100.00% (tau=0.29) */
                            }
                        } else {
                            if (features[28] /* Feature_Pulse_Pressure_std */ <= -0.82269f) {
                                if (features[30] /* Feature_Modified_Shock_Index_std */ <= -0.70047f) {
                                    {
                                        DecisionTreeResult res = { 5.6452f, 94.3548f, 0.05645f, 0.94355f, true };
                                        return res; /* Class 0: 5.65%, Class 1: 94.35% (tau=0.29) */
                                    }
                                } else {
                                    {
                                        DecisionTreeResult res = { 37.1728f, 62.8272f, 0.37173f, 0.62827f, true };
                                        return res; /* Class 0: 37.17%, Class 1: 62.83% (tau=0.29) */
                                    }
                                }
                            } else {
                                if (features[16] /* Feature_MBP_Mean_60s_mean */ <= -0.62203f) {
                                    {
                                        DecisionTreeResult res = { 1.3289f, 98.6711f, 0.01329f, 0.98671f, true };
                                        return res; /* Class 0: 1.33%, Class 1: 98.67% (tau=0.29) */
                                    }
                                } else {
                                    {
                                        DecisionTreeResult res = { 15.9208f, 84.0792f, 0.15921f, 0.84079f, true };
                                        return res; /* Class 0: 15.92%, Class 1: 84.08% (tau=0.29) */
                                    }
                                }
                            }
                        }
                    } else {
                        if (features[41] /* ART_MBP_min */ <= -0.24201f) {
                            {
                                DecisionTreeResult res = { 0.0000f, 100.0000f, 0.00000f, 1.00000f, true };
                                return res; /* Class 0: 0.00%, Class 1: 100.00% (tau=0.29) */
                            }
                        } else {
                            if (features[37] /* Feature_MBP_Delta_60s_std */ <= -0.60512f) {
                                {
                                    DecisionTreeResult res = { 0.0000f, 100.0000f, 0.00000f, 1.00000f, true };
                                    return res; /* Class 0: 0.00%, Class 1: 100.00% (tau=0.29) */
                                }
                            } else {
                                {
                                    DecisionTreeResult res = { 20.0000f, 80.0000f, 0.20000f, 0.80000f, true };
                                    return res; /* Class 0: 20.00%, Class 1: 80.00% (tau=0.29) */
                                }
                            }
                        }
                    }
                } else {
                    if (features[16] /* Feature_MBP_Mean_60s_mean */ <= -0.73375f) {
                        if (features[49] /* Feature_Modified_Shock_Index_min */ <= -0.11774f) {
                            {
                                DecisionTreeResult res = { 66.6667f, 33.3333f, 0.66667f, 0.33333f, true };
                                return res; /* Class 0: 66.67%, Class 1: 33.33% (tau=0.29) */
                            }
                        } else {
                            if (features[60] /* ART_MBP_max */ <= -0.76547f) {
                                if (features[67] /* Feature_Shock_Index_max */ <= -0.95630f) {
                                    {
                                        DecisionTreeResult res = { 10.0000f, 90.0000f, 0.10000f, 0.90000f, true };
                                        return res; /* Class 0: 10.00%, Class 1: 90.00% (tau=0.29) */
                                    }
                                } else {
                                    {
                                        DecisionTreeResult res = { 0.0000f, 100.0000f, 0.00000f, 1.00000f, true };
                                        return res; /* Class 0: 0.00%, Class 1: 100.00% (tau=0.29) */
                                    }
                                }
                            } else {
                                if (features[37] /* Feature_MBP_Delta_60s_std */ <= -0.60962f) {
                                    {
                                        DecisionTreeResult res = { 60.0000f, 40.0000f, 0.60000f, 0.40000f, true };
                                        return res; /* Class 0: 60.00%, Class 1: 40.00% (tau=0.29) */
                                    }
                                } else {
                                    {
                                        DecisionTreeResult res = { 15.6627f, 84.3373f, 0.15663f, 0.84337f, true };
                                        return res; /* Class 0: 15.66%, Class 1: 84.34% (tau=0.29) */
                                    }
                                }
                            }
                        }
                    } else {
                        if (features[55] /* Feature_MBP_Std_60s_min */ <= -0.20688f) {
                            if (features[79] /* ART_MBP_slope */ <= 0.14471f) {
                                if (features[73] /* Feature_MBP_Mean_60s_max */ <= -0.76183f) {
                                    {
                                        DecisionTreeResult res = { 23.3083f, 76.6917f, 0.23308f, 0.76692f, true };
                                        return res; /* Class 0: 23.31%, Class 1: 76.69% (tau=0.29) */
                                    }
                                } else {
                                    {
                                        DecisionTreeResult res = { 58.0882f, 41.9118f, 0.58088f, 0.41912f, true };
                                        return res; /* Class 0: 58.09%, Class 1: 41.91% (tau=0.29) */
                                    }
                                }
                            } else {
                                if (features[50] /* Feature_Rate_Pressure_Product_min */ <= 1.26746f) {
                                    {
                                        DecisionTreeResult res = { 73.3871f, 26.6129f, 0.73387f, 0.26613f, false };
                                        return res; /* Class 0: 73.39%, Class 1: 26.61% (tau=0.29) */
                                    }
                                } else {
                                    {
                                        DecisionTreeResult res = { 35.0000f, 65.0000f, 0.35000f, 0.65000f, true };
                                        return res; /* Class 0: 35.00%, Class 1: 65.00% (tau=0.29) */
                                    }
                                }
                            }
                        } else {
                            if (features[56] /* Feature_MBP_Delta_60s_min */ <= 0.57074f) {
                                if (features[28] /* Feature_Pulse_Pressure_std */ <= -0.35154f) {
                                    {
                                        DecisionTreeResult res = { 21.5859f, 78.4141f, 0.21586f, 0.78414f, true };
                                        return res; /* Class 0: 21.59%, Class 1: 78.41% (tau=0.29) */
                                    }
                                } else {
                                    {
                                        DecisionTreeResult res = { 48.0519f, 51.9481f, 0.48052f, 0.51948f, true };
                                        return res; /* Class 0: 48.05%, Class 1: 51.95% (tau=0.29) */
                                    }
                                }
                            } else {
                                if (features[93] /* Feature_MBP_Std_60s_slope */ <= 0.05907f) {
                                    {
                                        DecisionTreeResult res = { 50.0000f, 50.0000f, 0.50000f, 0.50000f, true };
                                        return res; /* Class 0: 50.00%, Class 1: 50.00% (tau=0.29) */
                                    }
                                } else {
                                    {
                                        DecisionTreeResult res = { 100.0000f, 0.0000f, 1.00000f, 0.00000f, false };
                                        return res; /* Class 0: 100.00%, Class 1: 0.00% (tau=0.29) */
                                    }
                                }
                            }
                        }
                    }
                }
            } else {
                if (features[87] /* Feature_Modified_Shock_Index_slope */ <= 0.20936f) {
                    if (features[16] /* Feature_MBP_Mean_60s_mean */ <= -0.33321f) {
                        if (features[78] /* ART_DBP_slope */ <= 0.00829f) {
                            if (features[54] /* Feature_MBP_Mean_60s_min */ <= 0.05098f) {
                                if (features[20] /* ART_SBP_std */ <= -0.92976f) {
                                    {
                                        DecisionTreeResult res = { 0.0000f, 100.0000f, 0.00000f, 1.00000f, true };
                                        return res; /* Class 0: 0.00%, Class 1: 100.00% (tau=0.29) */
                                    }
                                } else {
                                    {
                                        DecisionTreeResult res = { 37.0307f, 62.9693f, 0.37031f, 0.62969f, true };
                                        return res; /* Class 0: 37.03%, Class 1: 62.97% (tau=0.29) */
                                    }
                                }
                            } else {
                                if (features[21] /* ART_DBP_std */ <= -0.92543f) {
                                    {
                                        DecisionTreeResult res = { 13.7931f, 86.2069f, 0.13793f, 0.86207f, true };
                                        return res; /* Class 0: 13.79%, Class 1: 86.21% (tau=0.29) */
                                    }
                                } else {
                                    {
                                        DecisionTreeResult res = { 75.1092f, 24.8908f, 0.75109f, 0.24891f, false };
                                        return res; /* Class 0: 75.11%, Class 1: 24.89% (tau=0.29) */
                                    }
                                }
                            }
                        } else {
                            if (features[41] /* ART_MBP_min */ <= 0.17517f) {
                                if (features[50] /* Feature_Rate_Pressure_Product_min */ <= 1.80331f) {
                                    {
                                        DecisionTreeResult res = { 62.4227f, 37.5773f, 0.62423f, 0.37577f, true };
                                        return res; /* Class 0: 62.42%, Class 1: 37.58% (tau=0.29) */
                                    }
                                } else {
                                    {
                                        DecisionTreeResult res = { 18.4211f, 81.5789f, 0.18421f, 0.81579f, true };
                                        return res; /* Class 0: 18.42%, Class 1: 81.58% (tau=0.29) */
                                    }
                                }
                            } else {
                                if (features[39] /* ART_SBP_min */ <= 0.81321f) {
                                    {
                                        DecisionTreeResult res = { 76.9697f, 23.0303f, 0.76970f, 0.23030f, false };
                                        return res; /* Class 0: 76.97%, Class 1: 23.03% (tau=0.29) */
                                    }
                                } else {
                                    {
                                        DecisionTreeResult res = { 100.0000f, 0.0000f, 1.00000f, 0.00000f, false };
                                        return res; /* Class 0: 100.00%, Class 1: 0.00% (tau=0.29) */
                                    }
                                }
                            }
                        }
                    } else {
                        if (features[17] /* Feature_MBP_Std_60s_mean */ <= -0.71091f) {
                            if (features[39] /* ART_SBP_min */ <= 0.43332f) {
                                if (features[6] /* ETCO2_mean */ <= 0.16231f) {
                                    {
                                        DecisionTreeResult res = { 92.1053f, 7.8947f, 0.92105f, 0.07895f, false };
                                        return res; /* Class 0: 92.11%, Class 1: 7.89% (tau=0.29) */
                                    }
                                } else {
                                    {
                                        DecisionTreeResult res = { 31.2500f, 68.7500f, 0.31250f, 0.68750f, true };
                                        return res; /* Class 0: 31.25%, Class 1: 68.75% (tau=0.29) */
                                    }
                                }
                            } else {
                                if (features[47] /* Feature_Pulse_Pressure_min */ <= 1.18730f) {
                                    {
                                        DecisionTreeResult res = { 90.4762f, 9.5238f, 0.90476f, 0.09524f, false };
                                        return res; /* Class 0: 90.48%, Class 1: 9.52% (tau=0.29) */
                                    }
                                } else {
                                    {
                                        DecisionTreeResult res = { 99.4318f, 0.5682f, 0.99432f, 0.00568f, false };
                                        return res; /* Class 0: 99.43%, Class 1: 0.57% (tau=0.29) */
                                    }
                                }
                            }
                        } else {
                            if (features[8] /* BT_mean */ <= 0.21008f) {
                                if (features[54] /* Feature_MBP_Mean_60s_min */ <= 0.34530f) {
                                    {
                                        DecisionTreeResult res = { 87.2807f, 12.7193f, 0.87281f, 0.12719f, false };
                                        return res; /* Class 0: 87.28%, Class 1: 12.72% (tau=0.29) */
                                    }
                                } else {
                                    {
                                        DecisionTreeResult res = { 15.3846f, 84.6154f, 0.15385f, 0.84615f, true };
                                        return res; /* Class 0: 15.38%, Class 1: 84.62% (tau=0.29) */
                                    }
                                }
                            } else {
                                if (features[54] /* Feature_MBP_Mean_60s_min */ <= 0.08986f) {
                                    {
                                        DecisionTreeResult res = { 55.1797f, 44.8203f, 0.55180f, 0.44820f, true };
                                        return res; /* Class 0: 55.18%, Class 1: 44.82% (tau=0.29) */
                                    }
                                } else {
                                    {
                                        DecisionTreeResult res = { 76.8953f, 23.1047f, 0.76895f, 0.23105f, false };
                                        return res; /* Class 0: 76.90%, Class 1: 23.10% (tau=0.29) */
                                    }
                                }
                            }
                        }
                    }
                } else {
                    if (features[76] /* HR_slope */ <= 0.15311f) {
                        if (features[77] /* ART_SBP_slope */ <= -0.56840f) {
                            if (features[93] /* Feature_MBP_Std_60s_slope */ <= 0.04221f) {
                                {
                                    DecisionTreeResult res = { 0.0000f, 100.0000f, 0.00000f, 1.00000f, true };
                                    return res; /* Class 0: 0.00%, Class 1: 100.00% (tau=0.29) */
                                }
                            } else {
                                {
                                    DecisionTreeResult res = { 10.0000f, 90.0000f, 0.10000f, 0.90000f, true };
                                    return res; /* Class 0: 10.00%, Class 1: 90.00% (tau=0.29) */
                                }
                            }
                        } else {
                            if (features[54] /* Feature_MBP_Mean_60s_min */ <= -0.00825f) {
                                if (features[11] /* Feature_Modified_Shock_Index_mean */ <= 0.65330f) {
                                    {
                                        DecisionTreeResult res = { 15.6069f, 84.3931f, 0.15607f, 0.84393f, true };
                                        return res; /* Class 0: 15.61%, Class 1: 84.39% (tau=0.29) */
                                    }
                                } else {
                                    {
                                        DecisionTreeResult res = { 0.0000f, 100.0000f, 0.00000f, 1.00000f, true };
                                        return res; /* Class 0: 0.00%, Class 1: 100.00% (tau=0.29) */
                                    }
                                }
                            } else {
                                if (features[28] /* Feature_Pulse_Pressure_std */ <= -0.68363f) {
                                    {
                                        DecisionTreeResult res = { 33.5878f, 66.4122f, 0.33588f, 0.66412f, true };
                                        return res; /* Class 0: 33.59%, Class 1: 66.41% (tau=0.29) */
                                    }
                                } else {
                                    {
                                        DecisionTreeResult res = { 53.8889f, 46.1111f, 0.53889f, 0.46111f, true };
                                        return res; /* Class 0: 53.89%, Class 1: 46.11% (tau=0.29) */
                                    }
                                }
                            }
                        }
                    } else {
                        if (features[49] /* Feature_Modified_Shock_Index_min */ <= -1.01100f) {
                            {
                                DecisionTreeResult res = { 100.0000f, 0.0000f, 1.00000f, 0.00000f, false };
                                return res; /* Class 0: 100.00%, Class 1: 0.00% (tau=0.29) */
                            }
                        } else {
                            if (features[79] /* ART_MBP_slope */ <= -0.24238f) {
                                if (features[35] /* Feature_MBP_Mean_60s_std */ <= -0.53161f) {
                                    {
                                        DecisionTreeResult res = { 28.2609f, 71.7391f, 0.28261f, 0.71739f, true };
                                        return res; /* Class 0: 28.26%, Class 1: 71.74% (tau=0.29) */
                                    }
                                } else {
                                    {
                                        DecisionTreeResult res = { 3.4483f, 96.5517f, 0.03448f, 0.96552f, true };
                                        return res; /* Class 0: 3.45%, Class 1: 96.55% (tau=0.29) */
                                    }
                                }
                            } else {
                                if (features[21] /* ART_DBP_std */ <= -0.72061f) {
                                    {
                                        DecisionTreeResult res = { 66.3462f, 33.6538f, 0.66346f, 0.33654f, true };
                                        return res; /* Class 0: 66.35%, Class 1: 33.65% (tau=0.29) */
                                    }
                                } else {
                                    {
                                        DecisionTreeResult res = { 43.7710f, 56.2290f, 0.43771f, 0.56229f, true };
                                        return res; /* Class 0: 43.77%, Class 1: 56.23% (tau=0.29) */
                                    }
                                }
                            }
                        }
                    }
                }
            }
        } else {
            if (features[30] /* Feature_Modified_Shock_Index_std */ <= -0.35815f) {
                if (features[40] /* ART_DBP_min */ <= 0.69463f) {
                    if (features[3] /* ART_MBP_mean */ <= -0.06692f) {
                        if (features[77] /* ART_SBP_slope */ <= -0.42083f) {
                            if (features[16] /* Feature_MBP_Mean_60s_mean */ <= -0.22575f) {
                                if (features[18] /* Feature_MBP_Delta_60s_mean */ <= -0.25652f) {
                                    {
                                        DecisionTreeResult res = { 19.5238f, 80.4762f, 0.19524f, 0.80476f, true };
                                        return res; /* Class 0: 19.52%, Class 1: 80.48% (tau=0.29) */
                                    }
                                } else {
                                    {
                                        DecisionTreeResult res = { 43.5606f, 56.4394f, 0.43561f, 0.56439f, true };
                                        return res; /* Class 0: 43.56%, Class 1: 56.44% (tau=0.29) */
                                    }
                                }
                            } else {
                                if (features[41] /* ART_MBP_min */ <= 0.17517f) {
                                    {
                                        DecisionTreeResult res = { 28.4644f, 71.5356f, 0.28464f, 0.71536f, true };
                                        return res; /* Class 0: 28.46%, Class 1: 71.54% (tau=0.29) */
                                    }
                                } else {
                                    {
                                        DecisionTreeResult res = { 65.4737f, 34.5263f, 0.65474f, 0.34526f, true };
                                        return res; /* Class 0: 65.47%, Class 1: 34.53% (tau=0.29) */
                                    }
                                }
                            }
                        } else {
                            if (features[22] /* ART_MBP_std */ <= -0.62519f) {
                                if (features[60] /* ART_MBP_max */ <= -0.64274f) {
                                    {
                                        DecisionTreeResult res = { 38.4615f, 61.5385f, 0.38462f, 0.61538f, true };
                                        return res; /* Class 0: 38.46%, Class 1: 61.54% (tau=0.29) */
                                    }
                                } else {
                                    {
                                        DecisionTreeResult res = { 84.0382f, 15.9618f, 0.84038f, 0.15962f, false };
                                        return res; /* Class 0: 84.04%, Class 1: 15.96% (tau=0.29) */
                                    }
                                }
                            } else {
                                if (features[88] /* Feature_Rate_Pressure_Product_slope */ <= 0.07676f) {
                                    {
                                        DecisionTreeResult res = { 62.1959f, 37.8041f, 0.62196f, 0.37804f, true };
                                        return res; /* Class 0: 62.20%, Class 1: 37.80% (tau=0.29) */
                                    }
                                } else {
                                    {
                                        DecisionTreeResult res = { 80.7522f, 19.2478f, 0.80752f, 0.19248f, false };
                                        return res; /* Class 0: 80.75%, Class 1: 19.25% (tau=0.29) */
                                    }
                                }
                            }
                        }
                    } else {
                        if (features[88] /* Feature_Rate_Pressure_Product_slope */ <= -0.39505f) {
                            if (features[31] /* Feature_Rate_Pressure_Product_std */ <= -0.17049f) {
                                if (features[59] /* ART_DBP_max */ <= 0.13292f) {
                                    {
                                        DecisionTreeResult res = { 82.9856f, 17.0144f, 0.82986f, 0.17014f, false };
                                        return res; /* Class 0: 82.99%, Class 1: 17.01% (tau=0.29) */
                                    }
                                } else {
                                    {
                                        DecisionTreeResult res = { 91.3492f, 8.6508f, 0.91349f, 0.08651f, false };
                                        return res; /* Class 0: 91.35%, Class 1: 8.65% (tau=0.29) */
                                    }
                                }
                            } else {
                                if (features[41] /* ART_MBP_min */ <= 0.43591f) {
                                    {
                                        DecisionTreeResult res = { 56.4286f, 43.5714f, 0.56429f, 0.43571f, true };
                                        return res; /* Class 0: 56.43%, Class 1: 43.57% (tau=0.29) */
                                    }
                                } else {
                                    {
                                        DecisionTreeResult res = { 84.9812f, 15.0188f, 0.84981f, 0.15019f, false };
                                        return res; /* Class 0: 84.98%, Class 1: 15.02% (tau=0.29) */
                                    }
                                }
                            }
                        } else {
                            if (features[54] /* Feature_MBP_Mean_60s_min */ <= 0.34936f) {
                                if (features[78] /* ART_DBP_slope */ <= 0.07732f) {
                                    {
                                        DecisionTreeResult res = { 75.5319f, 24.4681f, 0.75532f, 0.24468f, false };
                                        return res; /* Class 0: 75.53%, Class 1: 24.47% (tau=0.29) */
                                    }
                                } else {
                                    {
                                        DecisionTreeResult res = { 85.6885f, 14.3115f, 0.85689f, 0.14311f, false };
                                        return res; /* Class 0: 85.69%, Class 1: 14.31% (tau=0.29) */
                                    }
                                }
                            } else {
                                if (features[26] /* FIO2_std */ <= 1.78154f) {
                                    {
                                        DecisionTreeResult res = { 91.0116f, 8.9884f, 0.91012f, 0.08988f, false };
                                        return res; /* Class 0: 91.01%, Class 1: 8.99% (tau=0.29) */
                                    }
                                } else {
                                    {
                                        DecisionTreeResult res = { 79.4031f, 20.5969f, 0.79403f, 0.20597f, false };
                                        return res; /* Class 0: 79.40%, Class 1: 20.60% (tau=0.29) */
                                    }
                                }
                            }
                        }
                    }
                } else {
                    if (features[46] /* BT_min */ <= 0.13448f) {
                        if (features[75] /* Feature_MBP_Delta_60s_max */ <= -0.86183f) {
                            if (features[39] /* ART_SBP_min */ <= 2.42774f) {
                                if (features[55] /* Feature_MBP_Std_60s_min */ <= 3.00789f) {
                                    {
                                        DecisionTreeResult res = { 3.4483f, 96.5517f, 0.03448f, 0.96552f, true };
                                        return res; /* Class 0: 3.45%, Class 1: 96.55% (tau=0.29) */
                                    }
                                } else {
                                    {
                                        DecisionTreeResult res = { 59.5745f, 40.4255f, 0.59574f, 0.40426f, true };
                                        return res; /* Class 0: 59.57%, Class 1: 40.43% (tau=0.29) */
                                    }
                                }
                            } else {
                                if (features[48] /* Feature_Shock_Index_min */ <= -0.87554f) {
                                    {
                                        DecisionTreeResult res = { 26.0870f, 73.9130f, 0.26087f, 0.73913f, true };
                                        return res; /* Class 0: 26.09%, Class 1: 73.91% (tau=0.29) */
                                    }
                                } else {
                                    {
                                        DecisionTreeResult res = { 100.0000f, 0.0000f, 1.00000f, 0.00000f, false };
                                        return res; /* Class 0: 100.00%, Class 1: 0.00% (tau=0.29) */
                                    }
                                }
                            }
                        } else {
                            if (features[78] /* ART_DBP_slope */ <= 0.49150f) {
                                if (features[9] /* Feature_Pulse_Pressure_mean */ <= 2.14825f) {
                                    {
                                        DecisionTreeResult res = { 93.0218f, 6.9782f, 0.93022f, 0.06978f, false };
                                        return res; /* Class 0: 93.02%, Class 1: 6.98% (tau=0.29) */
                                    }
                                } else {
                                    {
                                        DecisionTreeResult res = { 69.8718f, 30.1282f, 0.69872f, 0.30128f, true };
                                        return res; /* Class 0: 69.87%, Class 1: 30.13% (tau=0.29) */
                                    }
                                }
                            } else {
                                if (features[71] /* Feature_HR_Std_60s_max */ <= -0.81325f) {
                                    {
                                        DecisionTreeResult res = { 96.9697f, 3.0303f, 0.96970f, 0.03030f, false };
                                        return res; /* Class 0: 96.97%, Class 1: 3.03% (tau=0.29) */
                                    }
                                } else {
                                    {
                                        DecisionTreeResult res = { 81.5542f, 18.4458f, 0.81554f, 0.18446f, false };
                                        return res; /* Class 0: 81.55%, Class 1: 18.45% (tau=0.29) */
                                    }
                                }
                            }
                        }
                    } else {
                        if (features[22] /* ART_MBP_std */ <= -0.44333f) {
                            if (features[10] /* Feature_Shock_Index_mean */ <= -0.26487f) {
                                if (features[3] /* ART_MBP_mean */ <= 0.38633f) {
                                    {
                                        DecisionTreeResult res = { 94.3025f, 5.6975f, 0.94302f, 0.05698f, false };
                                        return res; /* Class 0: 94.30%, Class 1: 5.70% (tau=0.29) */
                                    }
                                } else {
                                    {
                                        DecisionTreeResult res = { 97.2445f, 2.7555f, 0.97245f, 0.02755f, false };
                                        return res; /* Class 0: 97.24%, Class 1: 2.76% (tau=0.29) */
                                    }
                                }
                            } else {
                                if (features[2] /* ART_DBP_mean */ <= 0.52132f) {
                                    {
                                        DecisionTreeResult res = { 92.3481f, 7.6519f, 0.92348f, 0.07652f, false };
                                        return res; /* Class 0: 92.35%, Class 1: 7.65% (tau=0.29) */
                                    }
                                } else {
                                    {
                                        DecisionTreeResult res = { 95.9535f, 4.0465f, 0.95953f, 0.04047f, false };
                                        return res; /* Class 0: 95.95%, Class 1: 4.05% (tau=0.29) */
                                    }
                                }
                            }
                        } else {
                            if (features[76] /* HR_slope */ <= 1.01606f) {
                                if (features[64] /* FIO2_max */ <= 1.71113f) {
                                    {
                                        DecisionTreeResult res = { 94.8855f, 5.1145f, 0.94886f, 0.05114f, false };
                                        return res; /* Class 0: 94.89%, Class 1: 5.11% (tau=0.29) */
                                    }
                                } else {
                                    {
                                        DecisionTreeResult res = { 89.2748f, 10.7252f, 0.89275f, 0.10725f, false };
                                        return res; /* Class 0: 89.27%, Class 1: 10.73% (tau=0.29) */
                                    }
                                }
                            } else {
                                if (features[64] /* FIO2_max */ <= 1.39911f) {
                                    {
                                        DecisionTreeResult res = { 92.5191f, 7.4809f, 0.92519f, 0.07481f, false };
                                        return res; /* Class 0: 92.52%, Class 1: 7.48% (tau=0.29) */
                                    }
                                } else {
                                    {
                                        DecisionTreeResult res = { 79.8851f, 20.1149f, 0.79885f, 0.20115f, false };
                                        return res; /* Class 0: 79.89%, Class 1: 20.11% (tau=0.29) */
                                    }
                                }
                            }
                        }
                    }
                }
            } else {
                if (features[73] /* Feature_MBP_Mean_60s_max */ <= -0.17986f) {
                    if (features[56] /* Feature_MBP_Delta_60s_min */ <= 0.53414f) {
                        if (features[54] /* Feature_MBP_Mean_60s_min */ <= 0.20560f) {
                            if (features[79] /* ART_MBP_slope */ <= -0.12625f) {
                                if (features[92] /* Feature_MBP_Mean_60s_slope */ <= -0.66949f) {
                                    {
                                        DecisionTreeResult res = { 18.5008f, 81.4992f, 0.18501f, 0.81499f, true };
                                        return res; /* Class 0: 18.50%, Class 1: 81.50% (tau=0.29) */
                                    }
                                } else {
                                    {
                                        DecisionTreeResult res = { 37.9704f, 62.0296f, 0.37970f, 0.62030f, true };
                                        return res; /* Class 0: 37.97%, Class 1: 62.03% (tau=0.29) */
                                    }
                                }
                            } else {
                                if (features[3] /* ART_MBP_mean */ <= -0.25800f) {
                                    {
                                        DecisionTreeResult res = { 48.8774f, 51.1226f, 0.48877f, 0.51123f, true };
                                        return res; /* Class 0: 48.88%, Class 1: 51.12% (tau=0.29) */
                                    }
                                } else {
                                    {
                                        DecisionTreeResult res = { 68.1994f, 31.8006f, 0.68199f, 0.31801f, true };
                                        return res; /* Class 0: 68.20%, Class 1: 31.80% (tau=0.29) */
                                    }
                                }
                            }
                        } else {
                            if (features[73] /* Feature_MBP_Mean_60s_max */ <= -0.28468f) {
                                if (features[77] /* ART_SBP_slope */ <= -0.05190f) {
                                    {
                                        DecisionTreeResult res = { 71.2974f, 28.7026f, 0.71297f, 0.28703f, false };
                                        return res; /* Class 0: 71.30%, Class 1: 28.70% (tau=0.29) */
                                    }
                                } else {
                                    {
                                        DecisionTreeResult res = { 84.8226f, 15.1774f, 0.84823f, 0.15177f, false };
                                        return res; /* Class 0: 84.82%, Class 1: 15.18% (tau=0.29) */
                                    }
                                }
                            } else {
                                if (features[35] /* Feature_MBP_Mean_60s_std */ <= -0.50534f) {
                                    {
                                        DecisionTreeResult res = { 89.7764f, 10.2236f, 0.89776f, 0.10224f, false };
                                        return res; /* Class 0: 89.78%, Class 1: 10.22% (tau=0.29) */
                                    }
                                } else {
                                    {
                                        DecisionTreeResult res = { 79.2873f, 20.7127f, 0.79287f, 0.20713f, false };
                                        return res; /* Class 0: 79.29%, Class 1: 20.71% (tau=0.29) */
                                    }
                                }
                            }
                        }
                    } else {
                        if (features[20] /* ART_SBP_std */ <= -0.54466f) {
                            if (features[78] /* ART_DBP_slope */ <= -0.40590f) {
                                if (features[60] /* ART_MBP_max */ <= -0.55508f) {
                                    {
                                        DecisionTreeResult res = { 15.6250f, 84.3750f, 0.15625f, 0.84375f, true };
                                        return res; /* Class 0: 15.62%, Class 1: 84.38% (tau=0.29) */
                                    }
                                } else {
                                    {
                                        DecisionTreeResult res = { 76.1364f, 23.8636f, 0.76136f, 0.23864f, false };
                                        return res; /* Class 0: 76.14%, Class 1: 23.86% (tau=0.29) */
                                    }
                                }
                            } else {
                                if (features[16] /* Feature_MBP_Mean_60s_mean */ <= 0.03453f) {
                                    {
                                        DecisionTreeResult res = { 86.6508f, 13.3492f, 0.86651f, 0.13349f, false };
                                        return res; /* Class 0: 86.65%, Class 1: 13.35% (tau=0.29) */
                                    }
                                } else {
                                    {
                                        DecisionTreeResult res = { 95.4341f, 4.5659f, 0.95434f, 0.04566f, false };
                                        return res; /* Class 0: 95.43%, Class 1: 4.57% (tau=0.29) */
                                    }
                                }
                            }
                        } else {
                            if (features[2] /* ART_DBP_mean */ <= -0.07160f) {
                                if (features[56] /* Feature_MBP_Delta_60s_min */ <= 0.57074f) {
                                    {
                                        DecisionTreeResult res = { 67.2507f, 32.7493f, 0.67251f, 0.32749f, true };
                                        return res; /* Class 0: 67.25%, Class 1: 32.75% (tau=0.29) */
                                    }
                                } else {
                                    {
                                        DecisionTreeResult res = { 86.0544f, 13.9456f, 0.86054f, 0.13946f, false };
                                        return res; /* Class 0: 86.05%, Class 1: 13.95% (tau=0.29) */
                                    }
                                }
                            } else {
                                if (features[40] /* ART_DBP_min */ <= 0.45795f) {
                                    {
                                        DecisionTreeResult res = { 76.7857f, 23.2143f, 0.76786f, 0.23214f, false };
                                        return res; /* Class 0: 76.79%, Class 1: 23.21% (tau=0.29) */
                                    }
                                } else {
                                    {
                                        DecisionTreeResult res = { 90.2574f, 9.7426f, 0.90257f, 0.09743f, false };
                                        return res; /* Class 0: 90.26%, Class 1: 9.74% (tau=0.29) */
                                    }
                                }
                            }
                        }
                    }
                } else {
                    if (features[35] /* Feature_MBP_Mean_60s_std */ <= -0.34731f) {
                        if (features[33] /* Feature_HR_Std_60s_std */ <= 0.23182f) {
                            if (features[94] /* Feature_MBP_Delta_60s_slope */ <= -0.23685f) {
                                if (features[32] /* Feature_HR_Mean_60s_std */ <= 1.45184f) {
                                    {
                                        DecisionTreeResult res = { 82.6754f, 17.3246f, 0.82675f, 0.17325f, false };
                                        return res; /* Class 0: 82.68%, Class 1: 17.32% (tau=0.29) */
                                    }
                                } else {
                                    {
                                        DecisionTreeResult res = { 100.0000f, 0.0000f, 1.00000f, 0.00000f, false };
                                        return res; /* Class 0: 100.00%, Class 1: 0.00% (tau=0.29) */
                                    }
                                }
                            } else {
                                if (features[26] /* FIO2_std */ <= 1.84100f) {
                                    {
                                        DecisionTreeResult res = { 92.0840f, 7.9160f, 0.92084f, 0.07916f, false };
                                        return res; /* Class 0: 92.08%, Class 1: 7.92% (tau=0.29) */
                                    }
                                } else {
                                    {
                                        DecisionTreeResult res = { 79.9465f, 20.0535f, 0.79947f, 0.20053f, false };
                                        return res; /* Class 0: 79.95%, Class 1: 20.05% (tau=0.29) */
                                    }
                                }
                            }
                        } else {
                            if (features[62] /* RR_CO2_max */ <= 2.22546f) {
                                if (features[77] /* ART_SBP_slope */ <= -0.45772f) {
                                    {
                                        DecisionTreeResult res = { 89.3767f, 10.6233f, 0.89377f, 0.10623f, false };
                                        return res; /* Class 0: 89.38%, Class 1: 10.62% (tau=0.29) */
                                    }
                                } else {
                                    {
                                        DecisionTreeResult res = { 95.2446f, 4.7554f, 0.95245f, 0.04755f, false };
                                        return res; /* Class 0: 95.24%, Class 1: 4.76% (tau=0.29) */
                                    }
                                }
                            } else {
                                if (features[24] /* RR_CO2_std */ <= 3.39747f) {
                                    {
                                        DecisionTreeResult res = { 84.8315f, 15.1685f, 0.84831f, 0.15169f, false };
                                        return res; /* Class 0: 84.83%, Class 1: 15.17% (tau=0.29) */
                                    }
                                } else {
                                    {
                                        DecisionTreeResult res = { 58.2609f, 41.7391f, 0.58261f, 0.41739f, true };
                                        return res; /* Class 0: 58.26%, Class 1: 41.74% (tau=0.29) */
                                    }
                                }
                            }
                        }
                    } else {
                        if (features[40] /* ART_DBP_min */ <= 0.57629f) {
                            if (features[68] /* Feature_Modified_Shock_Index_max */ <= -0.34022f) {
                                if (features[85] /* Feature_Pulse_Pressure_slope */ <= -0.26574f) {
                                    {
                                        DecisionTreeResult res = { 73.1167f, 26.8833f, 0.73117f, 0.26883f, false };
                                        return res; /* Class 0: 73.12%, Class 1: 26.88% (tau=0.29) */
                                    }
                                } else {
                                    {
                                        DecisionTreeResult res = { 84.9914f, 15.0086f, 0.84991f, 0.15009f, false };
                                        return res; /* Class 0: 84.99%, Class 1: 15.01% (tau=0.29) */
                                    }
                                }
                            } else {
                                if (features[41] /* ART_MBP_min */ <= 0.27947f) {
                                    {
                                        DecisionTreeResult res = { 61.2197f, 38.7803f, 0.61220f, 0.38780f, true };
                                        return res; /* Class 0: 61.22%, Class 1: 38.78% (tau=0.29) */
                                    }
                                } else {
                                    {
                                        DecisionTreeResult res = { 78.7629f, 21.2371f, 0.78763f, 0.21237f, false };
                                        return res; /* Class 0: 78.76%, Class 1: 21.24% (tau=0.29) */
                                    }
                                }
                            }
                        } else {
                            if (features[87] /* Feature_Modified_Shock_Index_slope */ <= 0.55527f) {
                                if (features[31] /* Feature_Rate_Pressure_Product_std */ <= 0.41989f) {
                                    {
                                        DecisionTreeResult res = { 93.0495f, 6.9505f, 0.93049f, 0.06951f, false };
                                        return res; /* Class 0: 93.05%, Class 1: 6.95% (tau=0.29) */
                                    }
                                } else {
                                    {
                                        DecisionTreeResult res = { 88.5205f, 11.4795f, 0.88520f, 0.11480f, false };
                                        return res; /* Class 0: 88.52%, Class 1: 11.48% (tau=0.29) */
                                    }
                                }
                            } else {
                                if (features[26] /* FIO2_std */ <= -0.35667f) {
                                    {
                                        DecisionTreeResult res = { 88.1481f, 11.8519f, 0.88148f, 0.11852f, false };
                                        return res; /* Class 0: 88.15%, Class 1: 11.85% (tau=0.29) */
                                    }
                                } else {
                                    {
                                        DecisionTreeResult res = { 83.6590f, 16.3410f, 0.83659f, 0.16341f, false };
                                        return res; /* Class 0: 83.66%, Class 1: 16.34% (tau=0.29) */
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

static inline bool predict_hypotension_95_pct(const float* features, float* percent_0, float* percent_1) {
    DecisionTreeResult res = predict_hypotension_95(features);
    if (percent_0) *percent_0 = res.percent_0;
    if (percent_1) *percent_1 = res.percent_1;
    return res.prediction;
}

