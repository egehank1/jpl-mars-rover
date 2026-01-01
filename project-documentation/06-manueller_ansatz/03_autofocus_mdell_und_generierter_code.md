---

# 📄 `03_autofocus_modell_und_generierter_code.md`

```md
# AutoFOCUS-Modell und generierter Code (theoretisch)

## Modellidee (abstrahiert)

Das AutoFOCUS-Modell beschreibt einen **Status-Controller** als Zustandsautomat mit folgenden Zuständen:

- IDLE
- DRIVING
- ERROR
- MANUAL
- AUTONOMY

Eingang:
- Kommando (`StatusEnum`)
- Takt (`tick`)

Ausgang:
- Aktueller Status

---

## Typischer AutoFOCUS-Code (generiert)

### Datei: `status_controller.h`

```c
#ifndef STATUS_CONTROLLER_H
#define STATUS_CONTROLLER_H

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef enum {
  STATUS_IDLE    = 0u,
  STATUS_DRIVING = 1u,
  STATUS_ERROR   = 2u,
  STATUS_MANUAL  = 3u,
  STATUS_AUTONOMY= 4u
} StatusEnum;

typedef struct {
  StatusEnum in_cmd;
  uint8_t    in_tick;

  StatusEnum out_status;

  StatusEnum _state;
} StatusController;

void StatusController_init(StatusController* self);
void StatusController_step(StatusController* self);

#ifdef __cplusplus
}
#endif

#endif