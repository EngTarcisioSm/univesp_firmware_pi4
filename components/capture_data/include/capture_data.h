/* USER CODE BEGIN Header */
/**
 * @file           : capture_data.h
 * @brief          :
 ******************************************************************************
 * @attention
 *
 * Author:
 * Date: 10/05/2023
 *
 * Description:
 *
 ******************************************************************************
 */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __CAPTURE_DATA_H
#define __CAPTURE_DATA_H

/* Includes ------------------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include<stdlib.h>

#include <stdio.h>
#include <string.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/event_groups.h"
#include "freertos/semphr.h"
#include "freertos/queue.h"

#include <time.h>       
#include "esp_sntp.h"   

#include "INFOSYS.h"
#include "eventgroup_sys.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */
typedef struct DATAROUND {
    double dTensao;
    double dCorrente;
    double dTemperatura;
} DataRound_t;
/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
//#define capture_dataDEBUG
#define CAPTUREDATA_DELAY_ANOSTRAS          1000
#define CAPTUREDATA_N_ANOSTRAS              10
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
/* USER CODE BEGIN PV */
QueueHandle_t xQueueTransfer;
QueueHandle_t xQueueTransfer_FROM_JSON;
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
/* USER CODE BEGIN PFP */
void vCAPTUREDATA_CreateQueueTransfer();
void vCAPTUREDATA_CreateQueueTransfer_FROM_JSON();
void vCAPTUREDATA_ReceiveData(void *pvParameters);
void vCAPTUREDATA_FilterMed(void *pvParamerts);
/* USER CODE END PFP */


#endif /* __CAPTURE_DATA_H */

/*******************************END OF FILE************************************/
