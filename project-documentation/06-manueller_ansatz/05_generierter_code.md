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