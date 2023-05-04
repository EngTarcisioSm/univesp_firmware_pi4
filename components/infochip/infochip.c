/* USER CODE BEGIN Header */
/**
 * @file           : infochip.c
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
#include "infochip.h"

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

/**
 * @brief Informa dados da versão da IDF (versao)
 * 
 * @param pvParameters 
 */
void vINFOCHIP_PrintInfo(void *pvParameters)
{
    vINFOSYS_Messages(INFOSYS_START_TASK, (void*)__func__);

    //ESP_LOGI(INFO_CHIP, "VERSION ESP-IDF: %s %s %s %d", IDF_VER, __FILE__, (void*)__func__, __LINE__);
    ESP_LOGI(INFO_CHIP, "VERSION ESP-IDF: %s", IDF_VER);
    
    vINFOSYS_Messages(INFOSYS_STOP_TASK, (void*)__func__);
    vTaskDelete(NULL);
}
/* USER CODE END TASKS FREERTOS */

#ifdef infochipDEBUG
/* DEBUG ---------------------------------------------------------------------*/
/* USER CODE DEBUG */

/* USER CODE END TASKS FREERTOS */

#endif

