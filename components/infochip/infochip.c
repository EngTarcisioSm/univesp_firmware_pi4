#include <stdio.h>
#include "infochip.h"

void vINFOCHIP_PrintInfo(void *pvParameters)
{
    vINFOSYS_Messages(INFOSYS_START_TASK, (void*)__func__);

    //ESP_LOGI(INFO_CHIP, "VERSION ESP-IDF: %s %s %s %d", IDF_VER, __FILE__, (void*)__func__, __LINE__);
    ESP_LOGI(INFO_CHIP, "VERSION ESP-IDF: %s", IDF_VER);
    
    vINFOSYS_Messages(INFOSYS_STOP_TASK, (void*)__func__);
    vTaskDelete(NULL);
}