#include "LedStatusController_ID_101.h"

void LedStatusController_ID_101_init(LedStatusController_ID_101_State* self) {
  if (!self) return;
  self->state = LED_STATE_OFF;
}

void LedStatusController_ID_101_reset(LedStatusController_ID_101_State* self) {
  LedStatusController_ID_101_init(self);
}

void LedStatusController_ID_101_step(
  LedStatusController_ID_101_State* self,
  const LedStatusController_ID_101_In* in,
  LedStatusController_ID_101_Out* out
) {
  if (!self || !in || !out) return;

  if (in->cmd == LED_CMD_RESET) {
    self->state = LED_STATE_OFF;
  } else if (in->error_flag) {
    self->state = LED_STATE_BLINK_RED;
  } else {
    switch (in->cmd) {
      case LED_CMD_OFF:       self->state = LED_STATE_OFF; break;
      case LED_CMD_GREEN:     self->state = LED_STATE_GREEN; break;
      case LED_CMD_YELLOW:    self->state = LED_STATE_YELLOW; break;
      case LED_CMD_RED:       self->state = LED_STATE_RED; break;
      case LED_CMD_BLINK_RED: self->state = LED_STATE_BLINK_RED; break;
      case LED_CMD_NONE:
      default: break;
    }
  }

  out->led_state = self->state;
  out->blink_enable = (self->state == LED_STATE_BLINK_RED);
}