#ifndef LEDHW_COMPONENT_ID_103_H
#define LEDHW_COMPONENT_ID_103_H

#ifdef __cplusplus
extern "C" {
#endif

#include "data_dictionary.h"

typedef struct {
  LedStateEnum led_state;
  AF_bool blink_enable;
  AF_bool blink_toggle;
} LedHW_Component_ID_103_In;

typedef struct {
  AF_bool led_on;
  LedStateEnum led_color;
} LedHW_Component_ID_103_Out;

typedef struct {
  AF_bool phase;
} LedHW_Component_ID_103_State;

void LedHW_Component_ID_103_init(LedHW_Component_ID_103_State* self);
void LedHW_Component_ID_103_reset(LedHW_Component_ID_103_State* self);

void LedHW_Component_ID_103_step(
  LedHW_Component_ID_103_State* self,
  const LedHW_Component_ID_103_In* in,
  LedHW_Component_ID_103_Out* out
);

#ifdef __cplusplus
}
#endif

#endif