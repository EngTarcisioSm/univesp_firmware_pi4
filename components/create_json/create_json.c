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

/* USER CODE END FUNCTION */

/* Tasks FreeRTOS ------------------------------------------------------------*/
/* USER CODE BEGIN TASKS FREERTOS */

void vCREATEJSON_Create(void *pvParameters)
{
    vINFOSYS_Messages(INFOSYS_START_TASK, (void*)__func__);
    for(;;)
    {
        char *pcJson_Str;
        cJSON *pxRoot = cJSON_CreateObject(); // cria um objeto JSON vazio

        // adiciona as chaves e valores no objeto JSON
        cJSON_AddStringToObject(pxRoot, "ano", "2023");
        cJSON_AddStringToObject(pxRoot,"mes", "4");
        cJSON_AddStringToObject(pxRoot, "dia", "5");
        cJSON_AddStringToObject(pxRoot, "hora", "03");
        cJSON_AddStringToObject(pxRoot, "minuto", "02");
        cJSON_AddStringToObject(pxRoot, "segundo", "30");
        cJSON_AddStringToObject(pxRoot, "milissegundo", "00");
        cJSON_AddStringToObject(pxRoot, "corrente", "20.1");
        cJSON_AddStringToObject(pxRoot, "tensao", "110");
        cJSON_AddStringToObject(pxRoot, "temperatura", "23");

        pcJson_Str = cJSON_Print(pxRoot);

        printf("%s\n", pcJson_Str); // imprime a string JSON na saída padrão
        printf("size %d\n",sizeof(pcJson_Str));

        cJSON_Delete(pxRoot); // libera a memória do objeto JSON
        free(pcJson_Str); // libera a memória da string JSON

        vTaskDelay(5000 / portTICK_PERIOD_MS);
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