
#include "eventgroup_sys.h"


void vEVENTGROUPSYS_InitEvent_001(void)
{
    xEventGroup__001 = xEventGroupCreate();

    if (xEventGroup__001 == NULL)
    {
        // falha na criação do eventgroup
        vINFOSYS_Messages(INFOSYS_ERROR_EVENTGROUP, (void*)("EventGroup_001"));
        esp_restart();
    } else {
        // sucesso na criação do eventgroup
        vINFOSYS_Messages(INFOSYS_START_EVENTGROUP, (void*)("EventGroup_001"));
    }
}
