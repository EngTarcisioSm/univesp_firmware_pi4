/* USER CODE BEGIN Header */
/**
 * @file           : main.c
 * @brief          :
 ******************************************************************************
 * @attention
 *
 * Author:
 * Date: 02/05/2023
 *
 * Description:
 *
 ******************************************************************************
 */
/* USER CODE END Header */

/* Includes ------------------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "main.h"

/* USER CODE END Includes */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */
// #define DEBUG_FREERTOS_1
/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
/* USER CODE BEGIN PFP */
void vInitialize_INFO_SYS(void);
void vInitialize_Process(void);
void vInitialize_Init(void *pvParameters);
void vInitialize_Hardwares(void);
void vINTERNET_Task_Connect(void *pvParameters);
void vINTERNET_Task_Disconnect(void *pvParameters);
void vTIMESYS_Task_Request_Time_NTP(void *pvParameters);

extern void vEVENTGROUPSYS_InitEvent_001(void);

// esp_err_t clientEvent(esp_http_client_event_t *evt);
// void vINTERNET_Task_Request(void *pvParameters);
extern void vINTERNET_Task_Request(void *pvParameters);
/* USER CODE END PFP */

/* Private function ----------------------------------------------------------*/
/* USER CODE BEGIN FUNCTION */

/* USER CODE END FUNCTION */

/* Tasks FreeRTOS ------------------------------------------------------------*/
/* USER CODE BEGIN TASKS FREERTOS */

/* USER CODE END TASKS FREERTOS */

#ifdef mainDEBUG
/* DEBUG ---------------------------------------------------------------------*/
/* USER CODE DEBUG */

/* USER CODE END TASKS FREERTOS */

#endif

void app_main(void)
{
    vInitialize_INFO_SYS();

    vInitialize_Hardwares();

    vEVENTGROUPSYS_InitEvent_001();

    /**
     * @brief Criação de Queues
     */
    vCAPTUREDATA_CreateQueueTransfer();
    vCAPTUREDATA_CreateQueueTransfer_FROM_JSON();
    vTIMESYS_CreateQueueTransfer();
    vCREATEJSON_CreateQueueSENDJSON();

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
    xTaskCreate(
        &vTIMESYS_Task_Test_Time_System, 
        "Task_Test_Time_System", 
        2048, 
        NULL, 
        2, 
        NULL
    );

    

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


    /**
     * @brief Inicialização de task que efetua requisições a internet
     */
    xTaskCreatePinnedToCore(
        &vINTERNET_Task_Request,
        "vINTERNET_Task_Request",
        5*2048, 
        NULL, 
        2, 
        NULL,
        1
    );

    /**
     * @brief Task de envio de json para o servidor
     * 
     * @param pvParameters 
     */
    xTaskCreatePinnedToCore(
        &vINTERNET_Task_Request2,
        "vINTERNET_Task_Request2",
        5*2048, 
        NULL, 
        3, 
        NULL,
        1
    );

    /**
     * @brief Task de criação de JSON
     */
    xTaskCreate(
        &vCREATEJSON_Create,
        "vCREATEJSON_Create",
        2*2048, 
        NULL, 
        2, 
        NULL
    );

    /**
     * @brief APENAS TESTE
     * ? NADA ALEM DISSO
     */
    xTaskCreate(
        &vCAPTUREDATA_ReceiveData,
        "vCAPTUREDATA_ReceiveData",
        1*2048, 
        NULL, 
        2, 
        NULL
    );

    /**
     * @brief Criação da função que cuida da filtragem por media do sinal 
     * 
     */
    xTaskCreate(
        &vCAPTUREDATA_FilterMed,
        "vCAPTUREDATA_FilterMed",
        2*2048, 
        NULL, 
        3, 
        NULL
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
     * @brief Apenas para teste
     * 
     */
    xEventGroupSetBits(
        xEventGroup__001,
        BIT_INTERNET_REQUEST
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

// esp_err_t clientEvent(esp_http_client_event_t *evt)
// {
//     switch (evt->event_id)
//     {
//         case HTTP_EVENT_ON_DATA:
//             printf("%.*s\n", evt->data_len, (char *)evt->data);
//             break;
//         default:
//             break;
//     }
//     return ESP_OK;
// }


// void vINTERNET_Task_Request(void *pvParameters)
// {
//     vINFOSYS_Messages(INFOSYS_START_TASK, (void*)__func__);
//     for (;;)
//     {
//         /**
//          * @brief esse bit esta sendo acinado para testes apenas na função de conexao a internet
//          * na função vINTERNET_Task_Connect no arquivo main
//          */
//         xEventGroupWaitBits(
//             xEventGroup__001,
//             BIT_INTERNET_REQUEST,
//             pdTRUE,
//             pdTRUE,
//             portMAX_DELAY
//         );
//         {
//             esp_http_client_config_t clientConfig = {
//                 .url = "http://google.com",
//                 .event_handler = clientEvent
//             };

//             esp_http_client_handle_t client = esp_http_client_init(&clientConfig);
//             esp_http_client_perform(client);
//             esp_http_client_cleanup(client);
//         }
//     }
//     vINFOSYS_Messages(INFOSYS_STOP_TASK, (void*)__func__);
//     vTaskDelete(NULL);
    
// }