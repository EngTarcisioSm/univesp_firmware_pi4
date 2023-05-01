#ifndef __INFOSYS_H__
#define __INFOSYS_H__

#include <stdio.h>
#include "esp_log.h"

#define INFOSYS_TAG             "INFOSYS"

#define INFOSYS_START_TASK                  1
#define INFOSYS_STOP_TASK                   2
#define INFOSYS_INITIALIZE_HARDWARE         3
#define INFOSYS_START_EVENTGROUP            4
#define INFOSYS_ERROR_EVENTGROUP            5
#define INFOSYS_ERROR_EVENTGROUP_BIT        6
#define INFOSYS_TIME_SYSTEM_ATT             7

void vINFOSYS_Messages(uint8_t ucType, void *pvMessage);



#endif // !__INFOSYS_H__
