#ifndef BLINKTIMER10_ID_102_H
#define BLINKTIMER10_ID_102_H

#ifdef __cplusplus
extern "C" {
#endif

#include "data_dictionary.h"

typedef struct {
  AF_bool enable;
} BlinkTimer10_ID_102_In;

typedef struct {
  AF_bool toggle;
} BlinkTimer10_ID_102_Out;

typedef struct {
  AF_uint32 cnt;
  AF_bool phase;
} BlinkTimer10_ID_102_State;

void BlinkTimer10_ID_102_init(BlinkTimer10_ID_102_State* self);
void BlinkTimer10_ID_102_reset(BlinkTimer10_ID_102_State* self);

void BlinkTimer10_ID_102_step(
  BlinkTimer10_ID_102_State* self,
  const BlinkTimer10_ID_102_In* in,
  BlinkTimer10_ID_102_Out* out
);

#ifdef __cplusplus
}
#endif

#endif