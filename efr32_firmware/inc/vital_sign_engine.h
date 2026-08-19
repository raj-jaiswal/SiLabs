/**
 * @file vital_sign_engine.h
 * @brief Real-time Vital Sign Processing & TinyML Feature Engine for Silicon Labs EFR32
 * @details Manages temporal circular ring buffers, online biomarker calculations,
 *          95-feature statistical window extraction, and adverse event classification.
 */

#ifndef VITAL_SIGN_ENGINE_H
#define VITAL_SIGN_ENGINE_H

#include <stdint.h>
#include <stdbool.h>
#include "scaler_params.h"
#include "efr32_decision_tree.h"

#ifdef __cplusplus
extern "C" {
#endif

#define VITAL_NUM_CHANNELS        19
#define VITAL_WINDOW_SIZE_SEC     600  // 10-minute sliding window (1 Hz)
#define VITAL_SHORT_WINDOW_SEC    60   // 60-second moving window for short-term biomarkers
#define VITAL_NUM_OUTPUT_FEATURES 95

/**
 * @brief Channel Indices in exact CSV sequential order
 */
typedef enum {
    // 9 Base Monitor Vitals
    CH_HR = 0,
    CH_ART_SBP,
    CH_ART_DBP,
    CH_ART_MBP,
    CH_PLETH_SPO2,
    CH_RR_CO2,
    CH_ETCO2,
    CH_FIO2,
    CH_BT,
    // 10 Engineered Biomarkers
    CH_PULSE_PRESSURE,
    CH_SHOCK_INDEX,
    CH_MOD_SHOCK_INDEX,
    CH_RATE_PRESSURE_PRODUCT,
    CH_HR_MEAN_60S,
    CH_HR_STD_60S,
    CH_HR_DELTA_60S,
    CH_MBP_MEAN_60S,
    CH_MBP_STD_60S,
    CH_MBP_DELTA_60S
} vital_channel_t;

/**
 * @brief Multi-Target Clinical Adverse Event Alert Structure
 */
typedef struct {
    bool alert_hypotension;   /**< True if MAP < 65 mmHg predicted */
    bool alert_hypoxia;       /**< True if SpO2 < 90% predicted */
    bool alert_tachycardia;   /**< True if HR > 100 bpm predicted */
} efr32_alert_status_t;

/**
 * @brief Initialize the vital sign buffer and internal states
 */
void vital_engine_init(void);

/**
 * @brief Ingest a single 1 Hz raw vital sign reading from patient monitor / BLE
 */
void vital_engine_ingest_raw_sample(float hr, float sbp, float dbp, float mbp, float spo2,
                                    float rr, float etco2, float fio2, float bt);

/**
 * @brief Check if sufficient history (>= 600s) has been collected for evaluation
 */
bool vital_engine_is_ready(void);

/**
 * @brief Get total ingested sample count since boot / reset
 */
uint32_t vital_engine_get_sample_count(void);

/**
 * @brief Extract 95 statistical features across 600s window in exact CSV order
 * @param out_features Array of at least 95 floats to store extracted raw metrics
 */
void vital_engine_extract_features(float* out_features);

/**
 * @brief Apply target-specific StandardScaler z-score normalization
 * @param in_raw Input raw 95 features
 * @param out_scaled Output normalized 95 features
 * @param mean Precomputed feature mean array
 * @param scale Precomputed feature standard deviation array
 */
void vital_engine_scale_features(const float* in_raw, float* out_scaled,
                                 const float* mean, const float* scale);

/**
 * @brief Run inference for all 3 adverse event classifiers on the latest 600s window
 * @return efr32_alert_status_t Results containing alert states for each target
 */
efr32_alert_status_t vital_engine_predict_all(void);

#ifdef __cplusplus
}
#endif

#endif // VITAL_SIGN_ENGINE_H
