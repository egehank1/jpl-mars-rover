#ifndef COMPONENT_ARCHITECTURE1_ID_120_H
#define COMPONENT_ARCHITECTURE1_ID_120_H

#ifdef __cplusplus
extern "C" {
#endif

#include "data_dictionary.h"
#include "LedStatusController_ID_101.h"
#include "BlinkTimer10_ID_102.h"
#include "LedHW_Component_ID_103.h"

typedef struct {
  LedCmdEnum cmd;
  AF_bool error_flag;
  AF_bool enable;
} Component_Architecture1_ID_120_In;

typedef struct {
  AF_bool led_on;
  LedStateEnum led_color;
  LedStateEnum led_state;
} Component_Architecture1_ID_120_Out;

typedef struct {
  LedStatusController_ID_101_State ctrl;
  BlinkTimer10_ID_102_State timer;
  LedHW_Component_ID_103_State hw;
} Component_Architecture1_ID_120_State;

void Component_Architecture1_ID_120_init(Component_Architecture1_ID_120_State* self);
void Component_Architecture1_ID_120_reset(Component_Architecture1_ID_120_State* self);

void Component_Architecture1_ID_120_step(
  Component_Architecture1_ID_120_State* self,
  const Component_Architecture1_ID_120_In* in,
  Component_Architecture1_ID_120_Out* out
);

#ifdef __cplusplus
}
#endif

#endif