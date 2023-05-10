/* USER CODE BEGIN Header */
/**
 * @file           : main.h
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
#ifndef __MAIN_H
#define __MAIN_H

/* Includes ------------------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include <string.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include <stdio.h>
#include <stdlib.h>     
#include <time.h>       
#include "esp_sntp.h"   
#include "esp_log.h"    
#include "esp_wifi.h"           
#include "esp_event.h"             
#include "nvs_flash.h"             
#include "esp_http_client.h"
#include "string.h"
#include "protocol_examples_common.h"
#include "esp_log.h"

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/event_groups.h"
#include "freertos/semphr.h"
#include "freertos/queue.h"

#include "test.h"
#include "infochip.h"
#include "INFOSYS.h"
#include "eventgroup_sys.h"
#include "time_sys.h"
#include "internet.h"
#include "../components/create_json/include/create_json.h"
#include "capture_data.h"
// #include "create_json.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
//#define mainDEBUG

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
/* USER CODE BEGIN PV */
extern EventGroupHandle_t xEventGroup__001;
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */


#endif /* __MAIN_H */

/*******************************END OF FILE************************************/
