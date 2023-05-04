/* USER CODE BEGIN Header */
/**
 * @file           : internet.c
 * @brief          :
 ******************************************************************************
 * @attention
 *
 * Author:
 * Date: 04/05/2023
 *
 * Description:
 *
 ******************************************************************************
 */
/* USER CODE END Header */

/* Includes ------------------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "internet.h"

/* USER CODE END Includes */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
/* USER CODE BEGIN PFP */
esp_err_t clientEvent(esp_http_client_event_t *evt);
/* USER CODE END PFP */

/* Private function ----------------------------------------------------------*/
/* USER CODE BEGIN FUNCTION */

esp_err_t clientEvent(esp_http_client_event_t *evt)
{
    switch (evt->event_id)
    {
        case HTTP_EVENT_ON_DATA:
            printf("%.*s\n", evt->data_len, (char *)evt->data);
            break;
        default:
            break;
    }
    return ESP_OK;
}

/* USER CODE END FUNCTION */

/* Tasks FreeRTOS ------------------------------------------------------------*/
/* USER CODE BEGIN TASKS FREERTOS */

void vINTERNET_Task_Request(void *pvParameters)
{
    vINFOSYS_Messages(INFOSYS_START_TASK, (void*)__func__);
    for (;;)
    {
        /**
         * @brief esse bit esta sendo acinado para testes apenas na função de conexao a internet
         * na função vINTERNET_Task_Connect no arquivo main
         */
        xEventGroupWaitBits(
            xEventGroup__001,
            BIT_INTERNET_REQUEST,
            pdTRUE,
            pdTRUE,
            portMAX_DELAY
        );
        {
            esp_http_client_config_t clientConfig = {
                .url = "http://google.com",
                .event_handler = clientEvent
            };

            esp_http_client_handle_t client = esp_http_client_init(&clientConfig);
            esp_http_client_perform(client);
            esp_http_client_cleanup(client);
        }
    }
    vINFOSYS_Messages(INFOSYS_STOP_TASK, (void*)__func__);
    vTaskDelete(NULL);
    
}

/* USER CODE END TASKS FREERTOS */

#ifdef internetDEBUG
/* DEBUG ---------------------------------------------------------------------*/
/* USER CODE DEBUG */

/* USER CODE END TASKS FREERTOS */

#endif