#ifndef DATA_DICTIONARY_H
#define DATA_DICTIONARY_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include <stdbool.h>

typedef uint8_t  AF_uint8;
typedef uint16_t AF_uint16;
typedef uint32_t AF_uint32;
typedef bool     AF_bool;

typedef enum {
  LED_STATE_OFF = 0u,
  LED_STATE_GREEN = 1u,
  LED_STATE_YELLOW = 2u,
  LED_STATE_RED = 3u,
  LED_STATE_BLINK_RED = 4u
} LedStateEnum;

typedef enum {
  LED_CMD_NONE = 0u,
  LED_CMD_OFF = 1u,
  LED_CMD_GREEN = 2u,
  LED_CMD_YELLOW = 3u,
  LED_CMD_RED = 4u,
  LED_CMD_BLINK_RED = 5u,
  LED_CMD_RESET = 6u
} LedCmdEnum;

#ifdef __cplusplus
}
#endif

#endif