/*
 * Embedded Programming 2 — Session 1: your first flash
 * --------------------------------------------------------------------------
 * The smallest thing that proves the WHOLE chain works:
 *   your code -> compiler -> USB -> real silicon -> and back to your screen.
 *
 * About the LED: this board has no ordinary on/off LED. It carries a single
 * addressable RGB LED (a WS2812), so you don't switch it on — you send it a
 * colour. neopixelWrite(pin, red, green, blue) does that for you.
 *
 * Check the silkscreen next to the LED for its pin! Ours says "RGB@IO38".
 * Other ESP32-S3 boards put it on GPIO48 — if yours does, change the line
 * below. (This is why LED_BUILTIN doesn't help here: it assumes GPIO48.)
 *
 * The serial "hello" is the guaranteed proof: if you see it in the monitor,
 * your toolchain, your cable and your board are all fine.
 */
#include <Arduino.h>

#define RGB_LED_PIN 38   // silkscreen: RGB@IO38

void setup() {
  Serial.begin(115200);
  delay(300);                                 // let serial come up before printing
  Serial.println();
  Serial.println("Hello from ESP32-S3 — the whole chain works!");
}

void loop() {
  neopixelWrite(RGB_LED_PIN, 0, 24, 0);       // dim green (r, g, b)
  Serial.println("blink: on");
  delay(500);

  neopixelWrite(RGB_LED_PIN, 0, 0, 0);        // off
  Serial.println("blink: off");
  delay(500);
}
