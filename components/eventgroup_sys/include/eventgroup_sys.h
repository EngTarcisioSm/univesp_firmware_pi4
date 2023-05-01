#ifndef EVENTGROUP_SYS_H__

#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/event_groups.h"
#include "freertos/semphr.h"

#include "INFOSYS.h"

#define BIT_REQUEST_TIME_NTP        1<<0
#define BIT_ATT_TIME_SYSTEM_OK      1<<1


EventGroupHandle_t xEventGroup__001;


void vEVENTGROUPSYS_InitEvent_001(void);

#endif // !EVENTGROUP_SYS_H__
