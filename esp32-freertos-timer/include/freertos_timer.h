#ifndef FREERTOS_TIMER_H
#define FREERTOS_TIMER_H

#include <freertos/FreeRTOS.h>
#include <freertos/timers.h>

// Function prototypes
void init_timer(void);
void start_timer(TickType_t period);
void stop_timer(void);

#endif // FREERTOS_TIMER_H