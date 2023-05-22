/* USER CODE BEGIN Header */
/**
 * @file           : create_json.h
 * @brief          :
 ******************************************************************************
 * @attention
 *
 * Author:
 * Date: 04/05/2023
 *
 * Description:
 *
 ******************************************************************************
 */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __CREATE_JSON_H
#define __CREATE_JSON_H

/* Includes ------------------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include <stdio.h>
#include <string.h>
#include "cJSON.h"
#include "INFOSYS.h"
#include "capture_data.h"
#include "time_sys.h"

#include <stdio.h>
#include <string.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/event_groups.h"
#include "freertos/semphr.h"
#include "freertos/queue.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
//#define create_jsonDEBUG

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
/* USER CODE BEGIN PV */
extern QueueHandle_t xQueueTransfer_FROM_JSON;
extern QueueHandle_t xQueueTransfer_time;

QueueHandle_t xQueueJSON;
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
/* USER CODE BEGIN PFP */
void vCREATEJSON_Create(void *pvParameters);
void vCREATEJSON_CreateQueueSENDJSON();
/* USER CODE END PFP */


#endif /* __CREATE_JSON_H */

/*******************************END OF FILE************************************/
