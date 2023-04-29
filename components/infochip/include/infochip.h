#ifndef __INFOCHIP__
#define __INFOCHIP__

#include <string.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_log.h"

#include "INFOSYS.h"

#define INFO_CHIP "INFO_CHIP"

void vINFOCHIP_PrintInfo(void *pvParameters);


#endif // !__INFOCHIP__
