/* USER CODE BEGIN Header */
/**
 * @file           : INFOSYS.h
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

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __INFOSYS_H
#define __INFOSYS_H

/* Includes ------------------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include <stdio.h>
#include "esp_log.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
//#define INFOSYSDEBUG

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */
#define INFOSYS_TAG             "INFOSYS"

#define INFOSYS_START_TASK                  1
#define INFOSYS_STOP_TASK                   2
#define INFOSYS_INITIALIZE_HARDWARE         3
#define INFOSYS_START_EVENTGROUP            4
#define INFOSYS_ERROR_EVENTGROUP            5
#define INFOSYS_ERROR_EVENTGROUP_BIT        6
#define INFOSYS_TIME_SYSTEM_ATT             7
/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
/* USER CODE BEGIN PFP */
void vINFOSYS_Messages(uint8_t ucType, void *pvMessage);
/* USER CODE END PFP */


#endif /* __INFOSYS_H */

/*******************************END OF FILE************************************/
