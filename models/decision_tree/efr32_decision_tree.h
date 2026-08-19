// Silicon Labs EFR32 Microcontroller Fast Decision Tree Classifier
// Memory Footprint: ~2 KB Flash, 0 KB Dynamic RAM
#include <stdbool.h>

static inline bool predict_hypotension_efr32(const float* features) {
    if (features[82] /* Feature_MBP_Mean_60s_min */ <= 0.18449f) {
        if (features[57] /* Feature_Modified_Shock_Index_min */ <= -1.49146f) {
            return false;
        } else {
            if (features[19] /* Solar8000_ART_MBP_slope */ <= 0.11462f) {
                if (features[82] /* Feature_MBP_Mean_60s_min */ <= -0.04852f) {
                    return true;
                } else {
                    return true;
                }
            } else {
                if (features[17] /* Solar8000_ART_MBP_min */ <= -0.02895f) {
                    return true;
                } else {
                    return false;
                }
            }
        }
    } else {
        if (features[17] /* Solar8000_ART_MBP_min */ <= 0.55985f) {
            if (features[19] /* Solar8000_ART_MBP_slope */ <= -0.28922f) {
                if (features[82] /* Feature_MBP_Mean_60s_min */ <= 0.67840f) {
                    return true;
                } else {
                    return false;
                }
            } else {
                if (features[87] /* Feature_MBP_Std_60s_min */ <= 1.34514f) {
                    return false;
                } else {
                    return true;
                }
            }
        } else {
            if (features[39] /* Primus_FIO2_slope */ <= 1.19343f) {
                if (features[12] /* Solar8000_ART_DBP_min */ <= 0.93182f) {
                    return false;
                } else {
                    return false;
                }
            } else {
                if (features[40] /* Solar8000_BT_mean */ <= 0.15051f) {
                    return false;
                } else {
                    return false;
                }
            }
        }
    }
}
