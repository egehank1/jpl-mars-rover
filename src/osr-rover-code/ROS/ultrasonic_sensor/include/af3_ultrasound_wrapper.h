#pragma once
#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

void af3_ultrasound_init(void);

/**
 * @param trigger   Trigger-Signal (Impuls)
 * @param distance  gemessene Distanz in Metern (oder wie ihr wollt)
 * @return          true, wenn TooClose im AF3-Modell aktiv ist
 */
bool af3_ultrasound_step(bool trigger, float distance);

#ifdef __cplusplus
}
#endif