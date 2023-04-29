#include <stdio.h>
#include "test.h"


void vTEST_FreeRTOS_1(void *pvParameters)
{
    vINFOSYS_Messages(INFOSYS_START_TASK, (void*)__func__);
    for(;;)
    {
        printf("Am I task 1?\n");
        vTaskDelay( 250 / portTICK_PERIOD_MS );
    }
    vINFOSYS_Messages(INFOSYS_STOP_TASK, (void*)__func__);
    vTaskDelete(NULL);
}

void vTEST_FreeRTOS_2(void *pvParameters)
{
    vINFOSYS_Messages(INFOSYS_START_TASK, (void*)__func__);
    for(;;)
    {
        printf("Am I task 2?\n");
        vTaskDelay( 1000 / portTICK_PERIOD_MS );
    }
    vINFOSYS_Messages(INFOSYS_STOP_TASK, (void*)__func__);
    vTaskDelete(NULL);
}
