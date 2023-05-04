/* USER CODE BEGIN Header */
/**
 * @file           : INFOSYS.c
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
#include "INFOSYS.h"

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

/* USER CODE END TASKS FREERTOS */

#ifdef INFOSYSDEBUG
/* DEBUG ---------------------------------------------------------------------*/
/* USER CODE DEBUG */

/* USER CODE END TASKS FREERTOS */

#endif

/**
 * @brief Função de exibição de mensagens do sistema
 * 
 * @param ucType tipo de mensagem a ser exibida
 * @param pvMessage mensagem a ser exibida 
 */
void vINFOSYS_Messages(uint8_t ucType, void *pvMessage)
{
    switch (ucType)
    {
        case INFOSYS_START_TASK:
            ESP_LOGI(INFOSYS_TAG, "TASK START: %s", (char*)pvMessage);
            break;
        case INFOSYS_STOP_TASK:
            ESP_LOGI(INFOSYS_TAG, "TASK STOP: %s", (char*)pvMessage);
            break;
        case INFOSYS_INITIALIZE_HARDWARE:
            ESP_LOGI(INFOSYS_TAG, "INITIALIZE HARDWARE: %s", (char*)pvMessage);
            break;
        case INFOSYS_START_EVENTGROUP:
            ESP_LOGI(INFOSYS_TAG, "EventGroup %s Initialized", (char*)pvMessage);
            break;  
        case INFOSYS_ERROR_EVENTGROUP:
            ESP_LOGI(INFOSYS_TAG, "EventGroup %s Fail", (char*)pvMessage);
            break;                       
        case INFOSYS_ERROR_EVENTGROUP_BIT:
            ESP_LOGI(INFOSYS_TAG, "EventGroup Error bit %s ", (char*)pvMessage);
            break; 
        case INFOSYS_TIME_SYSTEM_ATT:
            ESP_LOGI(INFOSYS_TAG, "TIME SYSTEM UPDATE");
            break; 
        case 8:
            break; 
        case 9:
            break;   
        case 10:
            break;  
        case 11:
            break;                       
        case 12:
            break; 
        case 13:
            break; 
        case 14:
            break; 
        case 15:
            break;  
        case 16:
            break;  
        case 17:
            break;                       
        case 18:
            break; 
        case 19:
            break; 
        case 20:
            break; 
        case 21:
            break;                                                                    
        default:
            break;
    }
}