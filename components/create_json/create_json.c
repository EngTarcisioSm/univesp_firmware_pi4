/* USER CODE BEGIN Header */
/**
 * @file           : create_json.c
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
#include "create_json.h"

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

/* USER CODE END PFP */

/* Private function ----------------------------------------------------------*/
/* USER CODE BEGIN FUNCTION */
void vCREATEJSON_CreateQueueSENDJSON()
{
    xQueueJSON = xQueueCreate( 1, sizeof(char *) );

    if( xQueueJSON == NULL )
    {
        /**
         * @brief queue não foi criada
         */
        vINFOSYS_Messages(INFOSYS_ERROR_QUEUE_FAIL, (void*)("xQueueJSON"));
        esp_restart();
    }
    vINFOSYS_Messages(INFOSYS_ERROR_QUEUE_SUCCESS, (void*)("xQueueJSON"));
}
/* USER CODE END FUNCTION */

/* Tasks FreeRTOS ------------------------------------------------------------*/
/* USER CODE BEGIN TASKS FREERTOS */

void vCREATEJSON_Create(void *pvParameters)
{
    DataRound_t xDataReceive;
    TimeSys_t xTimeReceive = {0};
    char cTensao[10], cCorrente[10], cTemperatura[10];

    vINFOSYS_Messages(INFOSYS_START_TASK, (void*)__func__);

    for(;;)
    {
        char *pcJson_Str;
        cJSON *pxRoot = cJSON_CreateObject(); // cria um objeto JSON vazio

        /**
         * @brief Aguarda a queue de dados para envio 
         * 
         */
        xQueueReceive(
            xQueueTransfer_FROM_JSON,
            &(xDataReceive),
            portMAX_DELAY
        );
        {
            memset(cTensao, 0x00, sizeof(cTensao));
            memset(cCorrente, 0x00, sizeof(cCorrente));
            memset(cTemperatura, 0x00, sizeof(cTemperatura));

            sprintf(
                cTensao,
                "%.2f",
                xDataReceive.dTensao
            );
            sprintf(
                cCorrente,
                "%.2f",
                xDataReceive.dCorrente
            );
            sprintf(
                cTemperatura,
                "%.2f",
                xDataReceive.dTemperatura
            );

            /**
             * @brief Criada a task que organiza os valores de tempo
             * 
             */
            xTaskCreate(
                &vTIMESYS_Task_Find_Time,
                "vTIMESYS_Task_Find_Time",
                5*2048, 
                NULL, 
                2, 
                NULL
            );

            xQueueReceive(
                xQueueTransfer_time,
                &(xTimeReceive),
                portMAX_DELAY
            );

            // adiciona as chaves e valores no objeto JSON
            cJSON_AddStringToObject(pxRoot, "ano", xTimeReceive.year);
            cJSON_AddStringToObject(pxRoot,"mes", xTimeReceive.month);
            cJSON_AddStringToObject(pxRoot, "dia", xTimeReceive.day);
            cJSON_AddStringToObject(pxRoot, "hora", xTimeReceive.hour);
            cJSON_AddStringToObject(pxRoot, "minuto", xTimeReceive.minute);
            cJSON_AddStringToObject(pxRoot, "segundo", xTimeReceive.second);
            cJSON_AddStringToObject(pxRoot, "milissegundo", "00");
            cJSON_AddStringToObject(pxRoot, "corrente", cCorrente);
            cJSON_AddStringToObject(pxRoot, "tensao", cTensao);
            cJSON_AddStringToObject(pxRoot, "temperatura", cTemperatura);

            pcJson_Str = cJSON_Print(pxRoot);

            printf("%s\n", pcJson_Str); // imprime a string JSON na saída padrão
            printf("size %d\n",sizeof(pcJson_Str));

            /**
             * @brief Passar o ponteiro do json para uma queue que é encaminhada para ser enviada para o servidor
             * 
             */
            xQueueSend(
                xQueueJSON,
                &pcJson_Str,
                portMAX_DELAY
            );

            /**
             * @brief Esperar por um eventgroup que deleta o ponteiro para não haver transbordamento de memoria
             * 
             */
            xEventGroupWaitBits(
                xEventGroup__001,
                BIT_INTERNET_SEND_API_FINISH,
                pdTRUE,
                pdTRUE,
                portMAX_DELAY
            );
            {
                cJSON_Delete(pxRoot); // libera a memória do objeto JSON
                free(pcJson_Str); // libera a memória da string JSON
            }
        }
    }
    vINFOSYS_Messages(INFOSYS_STOP_TASK, (void*)__func__);
    vTaskDelete(NULL);
}



/* USER CODE END TASKS FREERTOS */

#ifdef create_jsonDEBUG
/* DEBUG ---------------------------------------------------------------------*/
/* USER CODE DEBUG */

/* USER CODE END TASKS FREERTOS */

#endif