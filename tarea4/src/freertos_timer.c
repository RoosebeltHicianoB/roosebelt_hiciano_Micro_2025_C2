#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/timers.h"
#include "freertos_timer.h"

static TimerHandle_t xTimer = NULL;

void vTimerCallback(TimerHandle_t xTimer) {
    printf("Timer expired!\n");
}

void init_timer(void) {
    xTimer = xTimerCreate("MyTimer", pdMS_TO_TICKS(1000), pdTRUE, (void *)0, vTimerCallback);
    if (xTimer == NULL) {
        printf("Timer creation failed!\n");
    }
}

void start_timer(void) {
    if (xTimer != NULL) {
        if (xTimerStart(xTimer, 0) != pdPASS) {
            printf("Timer start failed!\n");
        }
    }
}

void stop_timer(void) {
    if (xTimer != NULL) {
        if (xTimerStop(xTimer, 0) != pdPASS) {
            printf("Timer stop failed!\n");
        }
    }
}

void delete_timer(void) {
    if (xTimer != NULL) {
        xTimerDelete(xTimer, 0);
        xTimer = NULL;
    }
}