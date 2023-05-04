/* USER CODE BEGIN Header */
/**
 * @file           : time_sys.c
 * @brief          :
 ******************************************************************************
 * @attention
 *
 * Author:
 * Date: 03/05/2023
 *
 * Description:
 *
 ******************************************************************************
 */
/* USER CODE END Header */

/* Includes ------------------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "time_sys.h"

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
void vOn_Got_Time(struct timeval *xTv);
/* USER CODE END PFP */

/* Private function ----------------------------------------------------------*/
/* USER CODE BEGIN FUNCTION */

/* USER CODE END FUNCTION */

/* Tasks FreeRTOS ------------------------------------------------------------*/
/* USER CODE BEGIN TASKS FREERTOS */

/* USER CODE END TASKS FREERTOS */

#ifdef time_sysDEBUG
/* DEBUG ---------------------------------------------------------------------*/
/* USER CODE DEBUG */

/* USER CODE END TASKS FREERTOS */

#endif

void vTIMESYS_Task_Request_Time_NTP(void *pvParameters)
{
    vINFOSYS_Messages(INFOSYS_START_TASK, (void*)__func__);

    xEventGroupWaitBits(
        xEventGroup__001,
        BIT_REQUEST_TIME_NTP,
        pdTRUE,
        pdTRUE,
        portMAX_DELAY
    );

    // configuração de sincronização - configuração de forma imediata 
    sntp_set_sync_mode(SNTP_SYNC_MODE_IMMED);
    // configurar servidor ntp para acesso aos dados
    sntp_setservername(0, NAME_SERVER_NTP);
    // inicialização 
    sntp_init();
    // configuração da função de callback
    sntp_set_time_sync_notification_cb(vOn_Got_Time);


    xEventGroupSetBits(
        xEventGroup__001,
        BIT_ATT_TIME_SYSTEM_OK
    );
    vTaskDelete(NULL);
}


void vTIMESYS_Task_Test_Time_System(void *pvParameter)
{
    char cBuffer[50];
    time_t xNow = 0;
    vINFOSYS_Messages(INFOSYS_START_TASK, (void*)__func__);
    for(;;)
    {
        xEventGroupWaitBits(
            xEventGroup__001,
            BIT_ATT_TIME_SYSTEM_OK,
            pdFALSE,
            pdTRUE,
            portMAX_DELAY
        );

        memset(cBuffer, 0x00, sizeof(cBuffer));
        time(&xNow);
        struct tm *xTimeInfo = localtime(&xNow);

        strftime(
            cBuffer, 
            sizeof(cBuffer),
            "%c",    //formato de entrega dos dados 
            xTimeInfo
        );

        ESP_LOGI(TIMER_SYS, "%s", cBuffer);

        vTaskDelay( 1000 / portTICK_PERIOD_MS );
    }

}

/**
 * @brief Função de callabck para o ntf
*/
void vOn_Got_Time(struct timeval *xTv)
{ 
    /**
     * @brief O dado é é informado no formato UTC que deve ser convertido pra o 
     * formato local, para isso é necessário setaro horario local do chip, o
     * segundo atributo abaixo foi obtido através do site descrito abaixo:
     * https://community.progress.com/s/article/P129473
     */
    setenv(
        "TZ",
        "BRST+3BRDT+2,M10.3.0,M2.3.0",
        1
    );
    tzset();

    vINFOSYS_Messages(INFOSYS_TIME_SYSTEM_ATT, NULL);
}