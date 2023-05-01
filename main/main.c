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

#include "main.h"


/*********************************************************************************/
/* DEFINES */
#define DEBUG_FREERTOS_1

/*********************************************************************************/
/* TYPEDEF */


/*********************************************************************************/
/* VARIABLES */
extern EventGroupHandle_t xEventGroup__001;

/*********************************************************************************/
/* PROTOTYPES */
void vInitialize_INFO_SYS(void);
void vInitialize_Process(void);
void vInitialize_Init(void *pvParameters);
void vInitialize_Hardwares(void);

void vINTERNET_Task_Connect(void *pvParameters);
void vINTERNET_Task_Disconnect(void *pvParameters);



void vTIMESYS_Task_Request_Time_NTP(void *pvParameters);

/*********************************************************************************/
/* MAIN */
void app_main(void)
{
    vInitialize_INFO_SYS();

    vInitialize_Hardwares();

    vEVENTGROUPSYS_InitEvent_001();

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
    xTaskCreate(
        &vTIMESYS_Task_Test_Time_System, 
        "Task_Test_Time_System", 
        2048, 
        NULL, 
        2, 
        NULL
    );

    
#endif

    /**
     * @brief Inicialização de conexão a internet no segundo core
     */
    xTaskCreatePinnedToCore(
        &vINTERNET_Task_Connect,
        "Connect_Internet",
        5*2048, 
        NULL, 
        2, 
        NULL,
        1
    );

    /**
     * @brief Inicialização de conexão a internet no segundo core
     */
    xTaskCreatePinnedToCore(
        &vTIMESYS_Task_Request_Time_NTP,
        "Task_Request_Time_NTP",
        5*2048, 
        NULL, 
        2, 
        NULL,
        1
    );


    vINFOSYS_Messages(INFOSYS_STOP_TASK, (void*)__func__);
    vTaskDelete(NULL);
}

/**
 * @brief Função de inicialização de todos periféricos do projeto
 * 
 */
void vInitialize_Hardwares(void)
{
    /**
     * @brief Inicialização de Perifericos de Wi-Fi
     */
    vINFOSYS_Messages(INFOSYS_INITIALIZE_HARDWARE, (void*)"WI-FI");
    nvs_flash_init();
    tcpip_adapter_init();
    esp_event_loop_create_default();
}

/**
 * @brief Efetua conexao a internet no wifi atravez do segundo nucleo do microcontrolador
 * 
 * @param pvParameters 
 */
void vINTERNET_Task_Connect(void *pvParameters)
{

    vINFOSYS_Messages(INFOSYS_START_TASK, (void*)__func__);
    
    example_connect();

    /**
     * @brief Colocar aqui algum eventgroup para indicar que a conexão foi inicializada com sucesso
     * e seja inicializado o processo de atualização do tempo do chip 
     * 
     */
    xEventGroupSetBits(
        xEventGroup__001,
        BIT_REQUEST_TIME_NTP
    );
    /**
     * @brief Em caso hipotetico do eventgroup n ser setado ocorre um reset do sistema 
     * 
     */
    // if( ( uxBits & ( BIT_REQUEST_TIME_NTP ) ) != ( BIT_REQUEST_TIME_NTP ) )
    // {
        
    //     vINFOSYS_Messages(
    //         INFOSYS_ERROR_EVENTGROUP_BIT, 
    //         (void*)("xEventGroup__001 in BIT_REQUEST_TIME_NTP")
    //     );
    //     esp_restart();
    // }

    vINFOSYS_Messages(INFOSYS_STOP_TASK, (void*)__func__);
    vTaskDelete(NULL);

}

/**
 * @brief Efetua a desconexão da internet wifi que esta sendo gerenciado no segundo núcleo 
 * 
 * @param pvParameters 
 */
void vINTERNET_Task_Disconnect(void *pvParameters)
{
    vINFOSYS_Messages(INFOSYS_START_TASK, (void*)__func__);

    example_disconnect();


    /**
     * @brief Eventgroup aqui informando que a desconexão foi realizada com sucesso
     * 
     */

    vINFOSYS_Messages(INFOSYS_STOP_TASK, (void*)__func__);
    vTaskDelete(NULL);

}




// void vTIMESYS_Task_Request_Time_NTP(void *pvParameters)
// {
//     xEventGroupWaitBits(
//         xEventGroup__001,
//         BIT_REQUEST_TIME_NTP,
//         pdTRUE,
//         pdTRUE,
//         portMAX_DELAY
//     );
//     printf("TESTE OOOOOOOOOOOOOOOOOOOOOOOOOOOK\n");
//     vTaskDelete(NULL);
// }