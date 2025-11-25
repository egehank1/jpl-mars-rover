
/**
 * @file I2CSniffer.ino
 * @brief Non-intrusive I2C sniffer for Arduino Uno (ATmega328).
 *
 * This sketch monitors I2C traffic directly from the SCL/SDA pins without acting
 * as an active I2C participant. It samples the I2C lines at high speed and logs
 * START/STOP conditions, ACK/NACKs, and data bytes.
 *
 * Based on ideas from
 * Bill Grundmann's i2c sniffer (https://billgrundmann.wordpress.com/tag/i2c-sniffer/)
 * avr-freaks forum (https://www.avrfreaks.net/forum/i2c-non-intrusive-slave-monitoring-existing-address)
 * 
 * @author teknoid
 * @date 2018
 */

#include <Arduino.h>

// SCL  D2  00000100  0x04
// SDA  D3  00001000  0x08
// SCL+SDA  00001100  0x0c


/** @brief Bitmask for SCL pin (PD2 / D2). */
#define SCL_MASK 0x04
/** @brief Bitmask for SDA pin (PD3 / D3). */
#define SDA_MASK 0x08
/** @brief Combined mask for both I2C lines. */
#define I2C_MASK 0x0C

/** @brief Reads logic level of SCL pin from PIN register. */
#define SCL (byte)(PIND & SCL_MASK)
/** @brief Reads logic level of SDA pin from PIN register (shifted to LSB). */
#define SDA (byte)((PIND >> 3) & 0x01)
/** @brief Reads combined I2C pin state. */
#define I2C (byte)(PIND & I2C_MASK)

/**
 * @brief Number of START/STOP cycles to capture before dumping to serial.
 */
#define MAX_SAMPLES 10

/**
 * @brief Number of I2C wire samples (00 01 10 11) to capture for debugging the raw SCL/SDA levels.
 */
#define MAX_WIRE_SAMPLES    255

/**
 * @brief Pointer to sample buffer used to store captured I2C events.
 */
char *b;

/**
 * @brief Determines the largest available RAM block by attempted allocation.
 *
 * @return Size in bytes of largest allocatable block.
 */
uint16_t availableMemory() {
  int size = 2048; // start with the most
  char *buf;
  while ((buf = (char *) malloc(--size)) == NULL) ;
  free(buf);
  return size;
}

/**
 * @brief Dumps the collected I2C event queue to the serial console.
 *
 * @param from  Pointer to beginning of buffer content.
 * @param to    Pointer to end of buffer content.
 */
void dump_queue(char *from, char *to) {
  int length = (int)to - (int)b;
  Serial.println();
  Serial.print("Queue was filled: ");
  Serial.println(length);
  char *ptr = from;
  while (ptr < to) {
    printhex(*ptr++);
    if (*ptr == '-') {
      Serial.write(*ptr++);
      Serial.println();
    }
    if (*ptr == '+') {
      Serial.write(*ptr++);
      Serial.print(" ");
    }
  }
  Serial.println();
  Serial.flush();
}

/**
 * @brief Prints a 4-bit nibble as hex.
 *
 * @param d Nibble value (0–15).
 */
void printnibble(byte d) {
  if (d < 10) Serial.write(d + '0');
  else Serial.write(d - 10 + 'A');
}

/**
 * @brief Prints a byte in 2-digit hexadecimal format.
 *
 * @param d Byte to print.
 */
void printhex(byte d) {
  printnibble(d >> 4);
  printnibble(d & 0xf);
}

/**
 * @brief Prints a byte in binary representation (8 bits).
 *
 * @param d Byte to print.
 */
void printbin(byte d) {
  Serial.write(' ');
  for (byte mask = 0b10000000; mask > 0; mask >>= 1) {
    if (d & mask) {
      Serial.write('1');
    } else {
      Serial.write('0');
    }
  }
  Serial.flush();
}

/**
 * @brief Samples raw I2C pin states (SCL+SDA) into buffer.
 *
 * @param from Write pointer into sample buffer.
 */
void sample_wire(char *from) {
  for (byte i = 0; i < MAX_WIRE_SAMPLES; i++) {
    *from++ = I2C;
  }
}

/**
 * @brief Dumps raw I2C wire-level samples (00, 01, 10, 11) to serial.
 *
 * @param from Pointer to recorded sample buffer.
 */
void dump_wire(char *from) {
  Serial.println();
  Serial.println("I2C wire samples");
  char data;
  for (byte i = 0; i < MAX_WIRE_SAMPLES; i++) {
    data = *from++;
    switch (data) {
      case SCL_MASK: Serial.print("01 "); break;
      case SDA_MASK: Serial.print("10 "); break;
      case I2C_MASK: Serial.print("11 "); break;
      default:       Serial.print("00 "); break;
    }
  }
  Serial.println();
  Serial.flush();
}

/**
 * @brief Debug mode: captures and dumps raw wire states.
 */
void debug() {
  byte d;
  char *p = b;
  byte count = MAX_SAMPLES;

i2c_idle:
  while (I2C != I2C_MASK);
  while (I2C == I2C_MASK);
  if (!SCL) goto i2c_idle;

  sample_wire(p);
  dump_wire(p);
}

/**
 * @brief Main I2C sniffer logic. Captures full I2C frames including:
 * - START conditions
 * - STOP conditions
 * - Slave address
 * - Register/Data bytes
 * - ACK/NACK bits
 *
 * Uses precise timing loops to detect transitions on SDA/SCL.
 */
void sample() {
  byte d, x;
  char *p = b;
  byte count = MAX_SAMPLES;

i2c_sync:
  if (I2C != I2C_MASK) goto i2c_sync;
i2c_idle:
  if (I2C == I2C_MASK) goto i2c_idle;
  if (SDA) goto i2c_sync; // not a START condition
  while (SCL);

i2c_start:
  // Read slave address byte (MSB → LSB)
  while (!SCL); d  = SDA; d = d << 1; while (SCL);  // MSB
  while (!SCL); d |= SDA; d = d << 1; while (SCL);
  while (!SCL); d |= SDA; d = d << 1; while (SCL);
  while (!SCL); d |= SDA; d = d << 1; while (SCL);
  while (!SCL); d |= SDA; d = d << 1; while (SCL);
  while (!SCL); d |= SDA; d = d << 1; while (SCL);
  while (!SCL); d |= SDA; d = d << 1; while (SCL);
  while (!SCL); d |= SDA; *p++ = d;   while (SCL);  // LSB

  // ACK bit
  while (!SCL);
  if (!SDA) {
    *p++ = '+';     // ACK
  } else {
    *p++ = '-';     // NACK -> abort
    goto i2c_sync;  // nobody there or busy
  }
  while (SCL);

  // Slave Register / Data
  while (!SCL); d  = SDA; d = d << 1; while (SCL);  // MSB

i2c_next:
  while (!SCL); d |= SDA; d = d << 1; while (SCL);
  while (!SCL); d |= SDA; d = d << 1; while (SCL);
  while (!SCL); d |= SDA; d = d << 1; while (SCL);
  while (!SCL); d |= SDA; d = d << 1; while (SCL);
  while (!SCL); d |= SDA; d = d << 1; while (SCL);
  while (!SCL); d |= SDA; d = d << 1; while (SCL);
  while (!SCL); d |= SDA; *p++ = d;   while (SCL);  // LSB
  while (!SCL);

  // ACK bit
  if (!SDA) {
    *p++ = '+';     // ACK
  } else {
    *p++ = '-';     // NACK
  }
  while (SCL);

  // STOP or RESTART detection
  while (!SCL) x = SDA;
  d = SDA;

  if (!x) {
    // SDA was low on SCL rise --> STOP or continue
    x = I2C;
    while (x == I2C);
    if (SDA) {
      if (--count == 0) goto i2c_dump;
      goto i2c_idle; // SDA rises too --> STOP
    }
  } else {
    // SDA was HIGH on SCL rise --> RESTART or continue
    x = I2C;
    while (x == I2C);
    if (SCL) {
      while (SCL);
      goto i2c_start;  // SCL rises too --> RESTART
    }
  }

  // continue
  d = d << 1;
  while (SCL);
  goto i2c_next;

i2c_dump:
  dump_queue(b, p);
  p = b;
  count = MAX_SAMPLES;
  goto i2c_idle;

i2c_debug:
  sample_wire(p);
  dump_queue(b, p);
  dump_wire(p);
  p = b;
  count = MAX_SAMPLES;
  goto i2c_idle;
}

/**
 * @brief Arduino setup routine.
 * Initializes memory buffer and serial connection.
 */
void setup() {
  int memory_size = availableMemory();
  int queue_size = memory_size - 128;
  b = (char *) malloc(queue_size);

  // report various sizes
  Serial.begin(115200);
  Serial.println();
  Serial.print("Available memory size: ");
  Serial.println(memory_size);
  Serial.print("Queue size: ");
  Serial.println(queue_size);
  Serial.flush();

  noInterrupts();
}

/**
 * @brief Arduino main loop. Runs the I2C sniffer.
 */
void loop() {
  // debug();
  sample();
}