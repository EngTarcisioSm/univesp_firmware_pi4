/* USER CODE BEGIN Header */
/**
 * @file           : capture_data.c
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

/* Includes ------------------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "capture_data.h"

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
void vCAPTUREDATA_CreateQueueTransfer()
{
    xQueueTransfer = xQueueCreate( 1, sizeof(DataRound_t) );

    if( xQueueTransfer == NULL )
    {
        /**
         * @brief queue não foi criada
         */
        vINFOSYS_Messages(INFOSYS_ERROR_QUEUE_FAIL, (void*)("xQueueTransfer"));
        esp_restart();
    }
    vINFOSYS_Messages(INFOSYS_ERROR_QUEUE_SUCCESS, (void*)("xQueueTransfer"));
}

void vCAPTUREDATA_CreateQueueTransfer_FROM_JSON()
{
    xQueueTransfer_FROM_JSON = xQueueCreate( 1, sizeof(DataRound_t) );

    if( xQueueTransfer == NULL )
    {
        /**
         * @brief queue não foi criada
         */
        vINFOSYS_Messages(INFOSYS_ERROR_QUEUE_FAIL, (void*)("xQueueTransfer_FROM_JSON"));
        esp_restart();
    }
    vINFOSYS_Messages(INFOSYS_ERROR_QUEUE_SUCCESS, (void*)("xQueueTransfer_FROM_JSON"));
}
/* USER CODE END FUNCTION */

/* Tasks FreeRTOS ------------------------------------------------------------*/
/* USER CODE BEGIN TASKS FREERTOS */


void vCAPTUREDATA_ReceiveData(void *pvParameters)
{
    DataRound_t xRound;

    vINFOSYS_Messages(INFOSYS_START_TASK, (void*)__func__);
    for(;;)
    {
        //pegar tensão  - depois o rand será substituido pela forma correta de se captar o dado
        xRound.dTensao = rand() % 1000;
        //pegar corrente  - depois o rand será substituido pela forma correta de se captar o dado
        xRound.dCorrente = rand() % 1000;
        //pegar temperatura - depois o rand será substituido pela forma correta de se captar o dado
        xRound.dTemperatura = rand() % 1000;

        /**
         * @brief envia o dado captado para a queue
         * 
         */
        xQueueSend(
            xQueueTransfer,
            &xRound,
            portMAX_DELAY
        );

        vTaskDelay( CAPTUREDATA_DELAY_ANOSTRAS / portTICK_PERIOD_MS);
    }
    vTaskDelete(NULL);
}

void vCAPTUREDATA_FilterMed(void *pvParamerts)
{
    DataRound_t xDataReceive, xDataSend;
    uint32_t ulCount = 0;
    vINFOSYS_Messages(INFOSYS_START_TASK, (void*)__func__);
    for(;;)
    {
        xQueueReceive(
            xQueueTransfer,
            &(xDataReceive),
            portMAX_DELAY
        );
        {
            if(ulCount) 
            {
                xDataSend.dTensao += xDataReceive.dTensao;
                xDataSend.dCorrente += xDataReceive.dCorrente;
                xDataSend.dTemperatura += xDataReceive.dTemperatura;
                xDataSend.dTensao /= 2;
                xDataSend.dCorrente /= 2;
                xDataSend.dTemperatura /= 2;

            }
            else 
            {
                xDataSend.dTensao = xDataReceive.dTensao;
                xDataSend.dCorrente = xDataReceive.dCorrente;
                xDataSend.dTemperatura = xDataReceive.dTemperatura;
            }
            ulCount++;

            if(ulCount > ( CAPTUREDATA_N_ANOSTRAS - 1) )
            {
                /**
                 * @brief aqui ocorre o envio da média para o local onde é criado o json 
                 * 
                 */
                xQueueSend(
                    xQueueTransfer_FROM_JSON,
                    &xDataSend,
                    ( 10 / portTICK_PERIOD_MS )
                );
                printf(
                    "Tensao: %f Corrente: %f Temperatura: %f \n", 
                    xDataSend.dTensao, 
                    xDataSend.dCorrente, 
                    xDataSend.dTemperatura
                );



                /**
                 * @brief Limpando os buffers e contadores
                 */
                ulCount = 0;
                xDataSend.dTensao = 0;
                xDataSend.dCorrente = 0;
                xDataSend.dTemperatura = 0;
            }


        }
    }
    vINFOSYS_Messages(INFOSYS_STOP_TASK, (void*)__func__);
    vTaskDelete(NULL);
}
/* USER CODE END TASKS FREERTOS */

#ifdef capture_dataDEBUG
/* DEBUG ---------------------------------------------------------------------*/
/* USER CODE DEBUG */

/* USER CODE END TASKS FREERTOS */

#endif