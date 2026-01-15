#include "BlinkTimer10_ID_102.h"

#ifndef BLINK_PERIOD
#define BLINK_PERIOD (10u)
#endif

void BlinkTimer10_ID_102_init(BlinkTimer10_ID_102_State* self) {
  if (!self) return;
  self->cnt = 0u;
  self->phase = false;
}

void BlinkTimer10_ID_102_reset(BlinkTimer10_ID_102_State* self) {
  BlinkTimer10_ID_102_init(self);
}

void BlinkTimer10_ID_102_step(
  BlinkTimer10_ID_102_State* self,
  const BlinkTimer10_ID_102_In* in,
  BlinkTimer10_ID_102_Out* out
) {
  if (!self || !in || !out) return;

  out->toggle = false;

  if (!in->enable) {
    self->cnt = 0u;
    self->phase = false;
    return;
  }

  self->cnt++;

  if (self->cnt >= BLINK_PERIOD) {
    self->cnt = 0u;
    self->phase = !self->phase;
    out->toggle = true;
  }
}