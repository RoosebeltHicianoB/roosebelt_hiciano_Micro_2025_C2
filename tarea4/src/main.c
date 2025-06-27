#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/timers.h"
#include "freertos_timer.h"

#define TIMER_PERIOD pdMS_TO_TICKS(1000) // Timer period in milliseconds

static TimerHandle_t xTimer = NULL;

void vTimerCallback(TimerHandle_t xTimer) {
    printf("Timer expired!\n");
}

void app_main(void) {
    // Create the timer
    xTimer = xTimerCreate("MyTimer", TIMER_PERIOD, pdTRUE, (void *)0, vTimerCallback);
    
    if (xTimer != NULL) {
        // Start the timer
        xTimerStart(xTimer, 0);
    } else {
        printf("Failed to create timer.\n");
    }
    
    // Start the FreeRTOS scheduler
    vTaskStartScheduler();
}