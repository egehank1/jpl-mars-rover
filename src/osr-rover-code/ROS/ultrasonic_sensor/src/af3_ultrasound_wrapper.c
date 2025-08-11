#include <stdbool.h>

#include "Component_Architecture1_ID_420.h"
#include "UltraschalSensor_HW_Componete_ID_435.h"
#include "Echo_ID_431.h"
#include "TriggerFunk_ID_427.h"
#include "Timer10_ID_579.h"
#include "Kontext_Rover_ID_704.h"
#include "data_dictionary.h"

#include "af3_ultrasound_wrapper.h"

void af3_ultrasound_init(void) {
    init_Component_Architecture1_ID_420();
}


bool af3_ultrasound_step(bool trigger, float distance) {

    Impuls_Signal_ID_665 = trigger;
    noval_Impuls_Signal_ID_665 = false;

    
    // Distance_ID_XXX = distance;
    // noval_Distance_ID_XXX = false;

    perform_step_Component_Architecture1_ID_420();

    
    return TooClose_ID_712;
}