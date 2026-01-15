#include "LedHW_Component_ID_103.h"

void LedHW_Component_ID_103_init(LedHW_Component_ID_103_State* self) {
  if (!self) return;
  self->phase = false;
}

void LedHW_Component_ID_103_reset(LedHW_Component_ID_103_State* self) {
  LedHW_Component_ID_103_init(self);
}

void LedHW_Component_ID_103_step(
  LedHW_Component_ID_103_State* self,
  const LedHW_Component_ID_103_In* in,
  LedHW_Component_ID_103_Out* out
) {
  if (!self || !in || !out) return;

  if (in->blink_enable && in->blink_toggle) {
    self->phase = !self->phase;
  }

  out->led_color = in->led_state;

  if (in->led_state == LED_STATE_OFF) {
    out->led_on = false;
  } else if (in->led_state == LED_STATE_BLINK_RED) {
    out->led_on = self->phase;
    out->led_color = LED_STATE_RED;
  } else {
    out->led_on = true;
  }
}