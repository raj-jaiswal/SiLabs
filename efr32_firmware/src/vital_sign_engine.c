/**
 * @file vital_sign_engine.c
 * @brief High-performance TinyML Feature Extraction Engine for Silicon Labs EFR32
 */

#include "vital_sign_engine.h"
#include <math.h>
#include <string.h>

// Static Ring Buffer in MCU SRAM (600 samples x 19 channels x 4 bytes ≈ 45.6 KB)
static float s_ring_buffer[VITAL_WINDOW_SIZE_SEC][VITAL_NUM_CHANNELS];
static uint16_t s_head_idx = 0;
static uint32_t s_total_samples = 0;
static bool s_is_full = false;

void vital_engine_init(void) {
    memset(s_ring_buffer, 0, sizeof(s_ring_buffer));
    s_head_idx = 0;
    s_total_samples = 0;
    s_is_full = false;
}

bool vital_engine_is_ready(void) {
    return s_is_full;
}

uint32_t vital_engine_get_sample_count(void) {
    return s_total_samples;
}

// Helper to compute 60-second moving average and standard deviation from ring buffer
static void compute_60s_stats(uint8_t raw_ch_idx, float current_val, float* out_mean, float* out_std, float* out_delta) {
    uint16_t count = (s_total_samples < VITAL_SHORT_WINDOW_SEC) ? (uint16_t)s_total_samples : VITAL_SHORT_WINDOW_SEC;
    if (count == 0) {
        *out_mean = current_val;
        *out_std = 0.0f;
        *out_delta = 0.0f;
        return;
    }

    float sum = current_val;
    float oldest_val = current_val;

    for (uint16_t k = 1; k < count; ++k) {
        int idx = (int)s_head_idx - (int)k;
        if (idx < 0) {
            idx += VITAL_WINDOW_SIZE_SEC;
        }
        float v = s_ring_buffer[idx][raw_ch_idx];
        sum += v;
        if (k == count - 1) {
            oldest_val = v;
        }
    }

    float mean = sum / (float)count;
    float sq_diff = (current_val - mean) * (current_val - mean);
    for (uint16_t k = 1; k < count; ++k) {
        int idx = (int)s_head_idx - (int)k;
        if (idx < 0) {
            idx += VITAL_WINDOW_SIZE_SEC;
        }
        float diff = s_ring_buffer[idx][raw_ch_idx] - mean;
        sq_diff += diff * diff;
    }

    *out_mean = mean;
    *out_std = sqrtf(sq_diff / (float)count);
    *out_delta = current_val - oldest_val;
}

void vital_engine_ingest_raw_sample(float hr, float sbp, float dbp, float mbp, float spo2,
                                    float rr, float etco2, float fio2, float bt) {
    float* current_slot = s_ring_buffer[s_head_idx];

    // 1. Store Base Vitals
    current_slot[CH_HR]         = hr;
    current_slot[CH_ART_SBP]    = sbp;
    current_slot[CH_ART_DBP]    = dbp;
    current_slot[CH_ART_MBP]    = mbp;
    current_slot[CH_PLETH_SPO2] = spo2;
    current_slot[CH_RR_CO2]     = rr;
    current_slot[CH_ETCO2]      = etco2;
    current_slot[CH_FIO2]       = fio2;
    current_slot[CH_BT]         = bt;

    // 2. Compute Instantaneous Biomarkers
    current_slot[CH_PULSE_PRESSURE]       = sbp - dbp;
    current_slot[CH_SHOCK_INDEX]          = (sbp > 1.0f) ? (hr / sbp) : 0.0f;
    current_slot[CH_MOD_SHOCK_INDEX]      = (mbp > 1.0f) ? (hr / mbp) : 0.0f;
    current_slot[CH_RATE_PRESSURE_PRODUCT] = (hr * sbp) / 100.0f;

    // 3. Compute Short-term 60-second Moving Statistics
    float hr_m = 0.0f, hr_s = 0.0f, hr_d = 0.0f;
    compute_60s_stats(CH_HR, hr, &hr_m, &hr_s, &hr_d);
    current_slot[CH_HR_MEAN_60S]  = hr_m;
    current_slot[CH_HR_STD_60S]   = hr_s;
    current_slot[CH_HR_DELTA_60S] = hr_d;

    float mbp_m = 0.0f, mbp_s = 0.0f, mbp_d = 0.0f;
    compute_60s_stats(CH_ART_MBP, mbp, &mbp_m, &mbp_s, &mbp_d);
    current_slot[CH_MBP_MEAN_60S]  = mbp_m;
    current_slot[CH_MBP_STD_60S]   = mbp_s;
    current_slot[CH_MBP_DELTA_60S] = mbp_d;

    // Advance head index
    s_head_idx = (s_head_idx + 1) % VITAL_WINDOW_SIZE_SEC;
    s_total_samples++;
    if (s_total_samples >= VITAL_WINDOW_SIZE_SEC) {
        s_is_full = true;
    }
}

void vital_engine_extract_features(float* out_features) {
    if (!out_features) return;

    uint8_t out_idx = 0;
    const float inv_N = 1.0f / (float)VITAL_WINDOW_SIZE_SEC;

    // For each channel, compute [mean, std, min, max, slope]
    for (uint8_t c = 0; c < VITAL_NUM_CHANNELS; ++c) {
        float sum = 0.0f;
        float min_v = 1e9f;
        float max_v = -1e9f;

        for (uint16_t i = 0; i < VITAL_WINDOW_SIZE_SEC; ++i) {
            float val = s_ring_buffer[i][c];
            sum += val;
            if (val < min_v) min_v = val;
            if (val > max_v) max_v = val;
        }

        float mean_v = sum * inv_N;

        // Two-pass Variance/Std
        float sq_sum = 0.0f;
        for (uint16_t i = 0; i < VITAL_WINDOW_SIZE_SEC; ++i) {
            float diff = s_ring_buffer[i][c] - mean_v;
            sq_sum += diff * diff;
        }
        float std_v = sqrtf(sq_sum * inv_N);

        // Slope = (latest - oldest) / (WINDOW_SIZE + 1e-5)
        uint16_t oldest_idx = s_head_idx;
        uint16_t latest_idx = (s_head_idx == 0) ? (VITAL_WINDOW_SIZE_SEC - 1) : (s_head_idx - 1);
        float slope_v = (s_ring_buffer[latest_idx][c] - s_ring_buffer[oldest_idx][c]) / (float)(VITAL_WINDOW_SIZE_SEC + 1e-5f);

        // Output in exact CSV column sequential order: [mean, std, min, max, slope]
        out_features[out_idx++] = mean_v;
        out_features[out_idx++] = std_v;
        out_features[out_idx++] = min_v;
        out_features[out_idx++] = max_v;
        out_features[out_idx++] = slope_v;
    }
}

void vital_engine_scale_features(const float* in_raw, float* out_scaled,
                                 const float* mean, const float* scale) {
    if (!in_raw || !out_scaled || !mean || !scale) return;

    for (uint8_t i = 0; i < VITAL_NUM_OUTPUT_FEATURES; ++i) {
        float s = scale[i];
        if (s > 1e-7f) {
            out_scaled[i] = (in_raw[i] - mean[i]) / s;
        } else {
            out_scaled[i] = 0.0f;
        }
    }
}

efr32_alert_status_t vital_engine_predict_all(void) {
    efr32_alert_status_t status = { false, false, false };
    if (!s_is_full) {
        return status;
    }

    float raw_feats[VITAL_NUM_OUTPUT_FEATURES];
    float scaled_feats[VITAL_NUM_OUTPUT_FEATURES];

    vital_engine_extract_features(raw_feats);

    // 1. Future_Hypotension
    vital_engine_scale_features(raw_feats, scaled_feats, SCALER_HYPOTENSION_MEAN, SCALER_HYPOTENSION_SCALE);
    status.alert_hypotension = predict_hypotension_efr32(scaled_feats);

    // 2. Future_Hypoxia
    vital_engine_scale_features(raw_feats, scaled_feats, SCALER_HYPOXIA_MEAN, SCALER_HYPOXIA_SCALE);
    status.alert_hypoxia = predict_hypoxia_efr32(scaled_feats);

    // 3. Future_Tachycardia
    vital_engine_scale_features(raw_feats, scaled_feats, SCALER_TACHYCARDIA_MEAN, SCALER_TACHYCARDIA_SCALE);
    status.alert_tachycardia = predict_tachycardia_efr32(scaled_feats);

    return status;
}
