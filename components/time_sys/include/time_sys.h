#ifndef __TIME_SYS_H__

#include <stdio.h>
#include <string.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/event_groups.h"
#include "freertos/semphr.h"

#include <time.h>       
#include "esp_sntp.h"   

#include "INFOSYS.h"
#include "eventgroup_sys.h"

#define NAME_SERVER_NTP "pool.ntp.org"
#define TIMER_SYS       "TIMER"

extern EventGroupHandle_t xEventGroup__001;

void vTIMESYS_Task_Request_Time_NTP(void *pvParameters);
void vTIMESYS_Task_Test_Time_System(void *pvParameter);

#endif // !__TIME_SYS_H__
