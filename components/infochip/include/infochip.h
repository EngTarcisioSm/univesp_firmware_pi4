/* USER CODE BEGIN Header */
/**
 * @file           : infochip.h
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
#ifndef __INFOCHIP_H
#define __INFOCHIP_H

/* Includes ------------------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include <string.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_log.h"

#include "INFOSYS.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
//#define infochipDEBUG

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */
#define INFO_CHIP "INFO_CHIP"
/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
/* USER CODE BEGIN PFP */
void vINFOCHIP_PrintInfo(void *pvParameters);
/* USER CODE END PFP */


#endif /* __INFOCHIP_H */

/*******************************END OF FILE************************************/
