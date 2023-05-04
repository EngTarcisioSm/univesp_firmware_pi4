/* USER CODE BEGIN Header */
/**
 * @file           : eventgroup_sys.c
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
#include "eventgroup_sys.h"

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

/**
 * @brief Inicialização do eventgroup
 * 
 */
void vEVENTGROUPSYS_InitEvent_001(void)
{
    xEventGroup__001 = xEventGroupCreate();

    if (xEventGroup__001 == NULL)
    {
        // falha na criação do eventgroup
        vINFOSYS_Messages(INFOSYS_ERROR_EVENTGROUP, (void*)("EventGroup_001"));
        esp_restart();
    } else {
        // sucesso na criação do eventgroup
        vINFOSYS_Messages(INFOSYS_START_EVENTGROUP, (void*)("EventGroup_001"));
    }
}


/* USER CODE END FUNCTION */

/* Tasks FreeRTOS ------------------------------------------------------------*/
/* USER CODE BEGIN TASKS FREERTOS */

/* USER CODE END TASKS FREERTOS */

#ifdef eventgroup_sysDEBUG
/* DEBUG ---------------------------------------------------------------------*/
/* USER CODE DEBUG */

/* USER CODE END TASKS FREERTOS */



#endif