/*
 * Session 5 — plant a secret, then read it back off the flash.
 * --------------------------------------------------------------------------
 * Copy into src/main.cpp and flash. Then, on your laptop:
 *
 *   esptool.py read_flash 0x0 0x800000 dump.bin
 *   strings dump.bin | grep -i -E "pass|ssid"
 *
 * If esptool can't connect (native-USB boards are fussy):
 *   hold BOOT, tap RESET, release — then run the command again.
 *
 * WHY the Serial.println below is required, not decoration:
 *   with optimisation on, an UNUSED string gets stripped out of the binary,
 *   so `strings | grep` would find nothing. Actually using the string forces
 *   the compiler to keep it. (And printing a secret to serial is itself a
 *   real vulnerability — that's the point.)
 */
#include <Arduino.h>

const char* ssid     = "Savonia-IoT";
const char* password = "SuperSecret123";   // "temporary"... ships forever

void setup() {
  Serial.begin(115200);
  delay(300);
  Serial.println(password);                 // forces the string into flash — and leaks it
}

void loop() {}
