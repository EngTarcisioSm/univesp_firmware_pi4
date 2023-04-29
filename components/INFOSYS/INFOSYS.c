#include "INFOSYS.h"


/**
 * @brief Função de exibição de mensagens do sistema
 * 
 * @param ucType tipo de mensagem a ser exibida
 * @param pvMessage mensagem a ser exibida 
 */
void vINFOSYS_Messages(uint8_t ucType, void *pvMessage)
{
    switch (ucType)
    {
        case INFOSYS_START_TASK:
            ESP_LOGI(INFOSYS_TAG, "TASK START: %s", (char*)pvMessage);
            break;
        case INFOSYS_STOP_TASK:
            ESP_LOGI(INFOSYS_TAG, "TASK STOP: %s", (char*)pvMessage);
            break;
        case 3:
            break;
        case 4:
            break;            
        
        default:
            break;
    }
}
