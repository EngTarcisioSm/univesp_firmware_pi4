/* USER CODE BEGIN Header */
/**
 * @file           : internet.h
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
#ifndef __INTERNET_H
#define __INTERNET_H

/* Includes ------------------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/event_groups.h"
#include "freertos/semphr.h"

#include "esp_wifi.h"
#include "esp_event.h"
#include "nvs_flash.h"
#include "esp_http_client.h"
#include "protocol_examples_common.h"
#include "main.h"

#include "INFOSYS.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */
typedef struct chunk_payload_t
{
    uint8_t *buffer;
    int buffer_index;
} chunk_payload_t;

typedef int ErrorHttp_t;
/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
//#define internetDEBUG
#define INTERNET_URL_API            "https://univesppi2023.pythonanywhere.com/"
#define INTERNET_TIMEOUT_MS         6000

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
/* USER CODE BEGIN PV */
extern QueueHandle_t xQueueJSON;

extern EventGroupHandle_t xEventGroup__001;

uint8_t ucSTEP;
char bcData[10];

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
/* USER CODE BEGIN PFP */
void vINTERNET_Task_Request(void *pvParameters);
void vINTERNET_Task_Request2(void *pvParameters);
/* USER CODE END PFP */


#endif /* __INTERNET_H */

/*******************************END OF FILE************************************/
