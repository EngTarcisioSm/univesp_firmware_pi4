/* USER CODE BEGIN Header */
/**
 * @file           : test.h
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
#ifndef __TEST_H
#define __TEST_H

/* Includes ------------------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

#include "INFOSYS.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
//#define testDEBUG

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
/* USER CODE BEGIN PFP */
void vTEST_FreeRTOS_1(void *pvParameters);
void vTEST_FreeRTOS_2(void *pvParameters);
/* USER CODE END PFP */


#endif /* __TEST_H */

/*******************************END OF FILE************************************/
