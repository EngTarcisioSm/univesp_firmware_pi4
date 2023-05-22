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
void vINTERNET_Slipt_LastID(char *data, uint8_t *pucStart, uint8_t *pucqtd);
void vINTERNET_OrganizeID();
void vINTERNET_OrganizeID_Error();
/* USER CODE END PFP */

/* Private function ----------------------------------------------------------*/
/* USER CODE BEGIN FUNCTION */

esp_err_t clientEvent(esp_http_client_event_t *evt)
{
    //bcData é uma variavel global uma vez que essa variavel é alimentada pela 
    //internet apenas uma vez na inicialização, após isso somente incrementos
    //internos
    uint8_t ucParseStart, ucParseQTD;
    switch (evt->event_id)
    {
        case HTTP_EVENT_ON_DATA:

            /**
             * @brief ucSTEP definido globalmente para que as tasks possam 
             * efetuar iterações
             * 
             */
            switch (ucSTEP)
            {
                case 1:
                    vINTERNET_Slipt_LastID((char *)evt->data, &ucParseStart, &ucParseQTD);
                    memset(bcData, 0x00, sizeof(bcData));
                    evt->data += ucParseStart;
                    memcpy(bcData, (char *)evt->data, ucParseQTD);

                    printf("*************************************************\n");
                    //printf("%s\n", bcData);
                    printf("%.*s\n", evt->data_len, (char *)evt->data);
                    printf("*************************************************\n");
                    break;
                case 2:
                    printf("*************************************************\n");
                    printf("%.*s\n", evt->data_len, (char *)evt->data);
                    printf("*************************************************\n");
                default:
                    break;
            }
            break;
        default:
            vINTERNET_OrganizeID_Error();

            break;
    }
    
    return ESP_OK;
}

/**
 * @brief Fornece a posição de inicio e quantidade de dados para capturar 
 * o ID 
 * 
 * @param data 
 * @param pucStart 
 * @param pucqtd 
 */
void vINTERNET_Slipt_LastID(char *data, uint8_t *pucStart, uint8_t *pucqtd)
{
    uint8_t ucPosStart = 0, ucQtd = 0;
    char *d1;
    d1 = data;
    printf("++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
    printf("PASSOU AQUI\n");
    printf("++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
    for(;;d1++){
        ucPosStart++;       //a ordem importa
        if (*d1 == ' ') break; 
    }
    for(;;d1++){
        if (*d1 == '}') break; 
        ucQtd++;            //a ordem importa 
    }
    *pucStart = ucPosStart;
    *pucqtd = ucQtd;
    printf("++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
    printf("%d %d\n ", ucPosStart, ucQtd);
    printf("++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
}

/**
 * @brief efetua incremento do ID
 * 
 */
void vINTERNET_OrganizeID()
{
    uint32_t id = atoi(bcData);
    memset(bcData, 0x00, sizeof(id));
    id++;
    sprintf(bcData, "%d", id);
}

/**
 * @brief efetua incremento do ID
 * 
 */
void vINTERNET_OrganizeID_Error()
{
    uint32_t id = atoi(bcData);
    memset(bcData, 0x00, sizeof(id));
    id--;
    sprintf(bcData, "%d", id);
}
/* USER CODE END FUNCTION */

/* Tasks FreeRTOS ------------------------------------------------------------*/
/* USER CODE BEGIN TASKS FREERTOS */

void vINTERNET_Task_Request(void *pvParameters)
{
    char url[50];
    vINFOSYS_Messages(INFOSYS_START_TASK, (void*)__func__);

    memset(url, 0x00, sizeof(url));
    memcpy(url, INTERNET_URL_API, sizeof(INTERNET_URL_API));
    strcat(url, "lastID");
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
            ucSTEP = 1;
            esp_http_client_config_t clientConfig = {
                .url = url,
                .event_handler = clientEvent
            };
            esp_http_client_handle_t client = esp_http_client_init(&clientConfig);
            esp_http_client_perform(client);
            esp_http_client_cleanup(client);
            ucSTEP = 0;
        }
    }
    vINFOSYS_Messages(INFOSYS_STOP_TASK, (void*)__func__);
    vTaskDelete(NULL);
    
}

/**
 * @brief efetua o envio dos dados para o servidor 
 * 
 * @param pvParameters 
 */
void vINTERNET_Task_Request2(void *pvParameters)
{
    char url[50];
    char *json;
    vINFOSYS_Messages(INFOSYS_START_TASK, (void*)__func__);
    for(;;)
    {
        chunk_payload_t chunk_payload = {0};
        xQueueReceive(
            xQueueJSON,
            &json,
            portMAX_DELAY
        );

        memset(url, 0x00, sizeof(url));
        memcpy(url, INTERNET_URL_API, sizeof(INTERNET_URL_API));
        strcat(url, "dado/");
        
        vINTERNET_OrganizeID();


        strcat(url, bcData);
        printf("++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
        printf("ID send: %s\n", bcData);
        printf("++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
        printf("*************************************************\n");
        printf("url send: %s\n", url);
        printf("data send: \n %s \n", json);
        printf("*************************************************\n");

        {
            ucSTEP = 2;
            esp_http_client_config_t clientConfig = {
                .url = url,
                .event_handler = clientEvent,
                .user_data = &chunk_payload,
                .method = HTTP_METHOD_POST
                //.timeout_ms = INTERNET_TIMEOUT_MS
            };
            esp_http_client_handle_t client = esp_http_client_init(&clientConfig);
            esp_http_client_set_header(client, "Content-Type", "application/json");
            esp_http_client_set_post_field(client, json, strlen(json));
            esp_http_client_perform(client);
            esp_http_client_cleanup(client);
            ucSTEP = 0;
        }

        /**
         * @brief limpar o buffer do gerador de json 
         * 
         */
        xEventGroupSetBits(
            xEventGroup__001,
            BIT_INTERNET_SEND_API_FINISH
        );
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