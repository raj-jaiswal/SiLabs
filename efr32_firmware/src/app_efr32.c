/**
 * @file app_efr32.c
 * @brief Main Silicon Labs Gecko SDK Application Logic for Intraoperative TinyML Monitoring
 * @details Target hardware: EFR32xG24, EFR32BG22, EFR32MG21 (Silicon Labs Gecko SDK v4.x)
 */

#include "vital_sign_engine.h"
#include <stdio.h>

#if defined(SL_CATALOG_POWER_MANAGER_PRESENT)
#include "sl_power_manager.h"
#endif

// Periodic 1-second timer state
static uint32_t s_seconds_elapsed = 0;

void app_init(void) {
    printf("\r\n======================================================\r\n");
    printf(" Silicon Labs EFR32 Intraoperative TinyML Monitor\r\n");
    printf(" Multi-Target Adverse Event Predictor Initialized\r\n");
    printf(" Targets: Hypotension, Hypoxia, Tachycardia\r\n");
    printf("======================================================\r\n");

    vital_engine_init();
}

void app_process_action(void) {
    // In a full Gecko SDK application, this is called from the main loop or an RTOS task
    // Sample vital signs arriving from UART/BLE or ADC sensors
    // Example: vital_engine_ingest_raw_sample(hr, sbp, dbp, mbp, spo2, rr, etco2, fio2, bt);

    if (vital_engine_is_ready()) {
        efr32_alert_status_t alert = vital_engine_predict_all();

        if (alert.alert_hypotension || alert.alert_hypoxia || alert.alert_tachycardia) {
            printf("[ALERT @ %lu s] ", (unsigned long)s_seconds_elapsed);
            if (alert.alert_hypotension)  printf("[HYPOTENSION RISK] ");
            if (alert.alert_hypoxia)      printf("[HYPOXIA RISK] ");
            if (alert.alert_tachycardia)  printf("[TACHYCARDIA RISK] ");
            printf("\r\n");

            // Hardware Action on EFR32 (e.g. Toggle LED / Trigger Buzzer / Send BLE GATT indication)
            // sl_led_toggle(&sl_led_led0);
        }
    }
}
