/* USER CODE BEGIN Header */
/**
 * @file           : time_sys.h
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

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __TIME_SYS_H
#define __TIME_SYS_H

/* Includes ------------------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include <stdio.h>
#include <string.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/event_groups.h"
#include "freertos/semphr.h"

#include <time.h>       
#include "esp_sntp.h"   

#include "INFOSYS.h"
#include "eventgroup_sys.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */
typedef struct TIME_SYS {
    char year[5];
    char month[3];
    char day[3];
    char hour[3];
    char minute[3];
    char second[3];
} TimeSys_t;
/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
//#define time_sysDEBUG

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */
#define NAME_SERVER_NTP "pool.ntp.org"
#define TIMER_SYS       "TIMER"
/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
/* USER CODE BEGIN PV */
extern EventGroupHandle_t xEventGroup__001;

QueueHandle_t xQueueTransfer_time;
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
/* USER CODE BEGIN PFP */
void vTIMESYS_CreateQueueTransfer();
void vTIMESYS_Task_Request_Time_NTP(void *pvParameters);
void vTIMESYS_Task_Test_Time_System(void *pvParameter);
void vTIMESYS_Task_Find_Time(void *pvParameters);
/* USER CODE END PFP */


#endif /* __TIME_SYS_H */

/*******************************END OF FILE************************************/
