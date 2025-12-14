# Generator Code (AutoFOCUS-orientiert)

Der folgende Code stellt einen **manuell erstellten,
generator C-Code** dar, wie er typisch
aus modellbasierten Tools hervorgeht.

## status_controller.h
```c
typedef enum {
  STATUS_IDLE = 0,
  STATUS_DRIVING,
  STATUS_ERROR,
  STATUS_MANUAL,
  STATUS_AUTONOMY
} StatusEnum;

typedef struct {
  StatusEnum in_cmd;
  uint8_t in_tick;
  StatusEnum out_status;
  StatusEnum state;
} StatusController;

void StatusController_init(StatusController* self);
void StatusController_step(StatusController* self);

## status_controller.c

void StatusController_init(StatusController* self) {
  self->state = STATUS_IDLE;
  self->out_status = STATUS_IDLE;
}

void StatusController_step(StatusController* self) {
  if (self->in_tick) {
    self->state = self->in_cmd;
    self->out_status = self->state;
    self->in_tick = 0;
  }
}