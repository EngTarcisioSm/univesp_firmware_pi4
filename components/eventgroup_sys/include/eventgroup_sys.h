/* USER CODE BEGIN Header */
/**
 * @file           : eventgroup_sys.h
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
#ifndef __EVENTGROUP_SYS_H
#define __EVENTGROUP_SYS_H

/* Includes ------------------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/event_groups.h"
#include "freertos/semphr.h"

#include "INFOSYS.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
//#define eventgroup_sysDEBUG

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */
#define BIT_REQUEST_TIME_NTP            1<<0
#define BIT_ATT_TIME_SYSTEM_OK          1<<1
#define BIT_INTERNET_REQUEST            1<<2
#define BIT_INTERNET_SEND_API_FINISH    1<<3
/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
/* USER CODE BEGIN PV */
EventGroupHandle_t xEventGroup__001;
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
/* USER CODE BEGIN PFP */
void vEVENTGROUPSYS_InitEvent_001(void);
/* USER CODE END PFP */


#endif /* __EVENTGROUP_SYS_H */

/*******************************END OF FILE************************************/
