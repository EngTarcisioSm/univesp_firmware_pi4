/**
 * @file main.c
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-04-27
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <string.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

#include "test.h"
#include "infochip.h"
#include "INFOSYS.h"


/*********************************************************************************/
/* DEFINES */
#define DEBUG_FREERTOS_1

/*********************************************************************************/
/* TYPEDEF */


/*********************************************************************************/
/* PROTOTYPES */
void vInitialize_INFO_SYS(void);
void vInitialize_Process(void);
void vInitialize_Init(void *pvParameters);

/*********************************************************************************/
/* MAIN */
void app_main(void)
{
    vInitialize_INFO_SYS();

    vInitialize_Process();


}

/*********************************************************************************/
/* FUNCTIONS */

/**
 * @brief Função que inicializa a task que informa a versão do sistema ESP-IDF
 * 
 */
void vInitialize_INFO_SYS(void)
{
    xTaskCreate(
        &vINFOCHIP_PrintInfo, 
        "vINFOCHIP_PrintInfo", 
        2048, 
        NULL, 
        10, 
        NULL
    );
}

/**
 * @brief Função que efetua o startup do sistema 
 * 
 */
void vInitialize_Process(void)
{
    xTaskCreate(
        &vInitialize_Init, 
        "vInitialize_Init", 
        2048, 
        NULL, 
        10, 
        NULL
    );
}


/**
 * @brief Tarefa responsavel por efetuar o startup do sistema 
 * 
 * @param pvParameters 
 */
void vInitialize_Init(void *pvParameters)
{
    vTaskDelay( 5000/portTICK_PERIOD_MS );

    vINFOSYS_Messages(INFOSYS_START_TASK, (void*)__func__);

#ifdef DEBUG_FREERTOS_1
    xTaskCreate(
        &vTEST_FreeRTOS_1, 
        "vTEST_FreeRTOS_1", 
        2048, 
        NULL, 
        2, 
        NULL
    );
    xTaskCreate(
        &vTEST_FreeRTOS_2, 
        "vTEST_FreeRTOS_2", 
        2048, 
        NULL, 
        2, 
        NULL
    );
#endif

    vINFOSYS_Messages(INFOSYS_STOP_TASK, (void*)__func__);
    vTaskDelete(NULL);
}

