#ifndef LEDSTATUSCONTROLLER_ID_101_H
#define LEDSTATUSCONTROLLER_ID_101_H

#ifdef __cplusplus
extern "C" {
#endif

#include "data_dictionary.h"

typedef struct {
  LedCmdEnum cmd;
  AF_bool error_flag;
  AF_bool blink_toggle;
} LedStatusController_ID_101_In;

typedef struct {
  LedStateEnum led_state;
  AF_bool blink_enable;
} LedStatusController_ID_101_Out;

typedef struct {
  LedStateEnum state;
} LedStatusController_ID_101_State;

void LedStatusController_ID_101_init(LedStatusController_ID_101_State* self);
void LedStatusController_ID_101_reset(LedStatusController_ID_101_State* self);

void LedStatusController_ID_101_step(
  LedStatusController_ID_101_State* self,
  const LedStatusController_ID_101_In* in,
  LedStatusController_ID_101_Out* out
);

#ifdef __cplusplus
}
#endif

#endif