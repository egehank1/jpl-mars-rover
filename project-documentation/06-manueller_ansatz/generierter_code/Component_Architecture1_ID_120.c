#include "Component_Architecture1_ID_120.h"

void Component_Architecture1_ID_120_init(Component_Architecture1_ID_120_State* self) {
  if (!self) return;
  LedStatusController_ID_101_init(&self->ctrl);
  BlinkTimer10_ID_102_init(&self->timer);
  LedHW_Component_ID_103_init(&self->hw);
}

void Component_Architecture1_ID_120_reset(Component_Architecture1_ID_120_State* self) {
  if (!self) return;
  LedStatusController_ID_101_reset(&self->ctrl);
  BlinkTimer10_ID_102_reset(&self->timer);
  LedHW_Component_ID_103_reset(&self->hw);
}

void Component_Architecture1_ID_120_step(
  Component_Architecture1_ID_120_State* self,
  const Component_Architecture1_ID_120_In* in,
  Component_Architecture1_ID_120_Out* out
) {
  if (!self || !in || !out) return;

  BlinkTimer10_ID_102_In t_in;
  BlinkTimer10_ID_102_Out t_out;

  LedStatusController_ID_101_In c_in;
  LedStatusController_ID_101_Out c_out;

  LedHW_Component_ID_103_In h_in;
  LedHW_Component_ID_103_Out h_out;

  t_in.enable = in->enable;
  BlinkTimer10_ID_102_step(&self->timer, &t_in, &t_out);

  c_in.cmd = in->cmd;
  c_in.error_flag = in->error_flag;
  c_in.blink_toggle = t_out.toggle;
  LedStatusController_ID_101_step(&self->ctrl, &c_in, &c_out);

  h_in.led_state = c_out.led_state;
  h_in.blink_enable = c_out.blink_enable;
  h_in.blink_toggle = t_out.toggle;
  LedHW_Component_ID_103_step(&self->hw, &h_in, &h_out);

  out->led_on = h_out.led_on;
  out->led_color = h_out.led_color;
  out->led_state = c_out.led_state;
}