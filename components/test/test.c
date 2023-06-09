/* USER CODE BEGIN Header */
/**
 * @file           : test.c
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
#include "test.h"

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


/* USER CODE END TASKS FREERTOS */

#ifdef testDEBUG
/* DEBUG ---------------------------------------------------------------------*/
/* USER CODE DEBUG */

/* USER CODE END TASKS FREERTOS */

#endif