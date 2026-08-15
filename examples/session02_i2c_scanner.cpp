/*
 * Session 2 — I2C bus scanner.
 * --------------------------------------------------------------------------
 * The first tool for any I2C sensor: ask every address, see who answers.
 * Copy this into src/main.cpp (replacing the blink), then build + upload.
 *
 * Expected:  "I2C device found at 0x68"  <- that's the MPU-6050.
 * Nothing found? -> wiring (SDA/SCL swapped?), power, or a missing GND.
 */
#include <Arduino.h>
#include <Wire.h>

// ESP32-S3-DevKitC-1 Arduino defaults: SDA = GPIO8, SCL = GPIO9.
// Change these two lines if your wiring uses different pins.
#define SDA_PIN 8
#define SCL_PIN 9

void setup() {
  Serial.begin(115200);
  delay(300);
  Wire.begin(SDA_PIN, SCL_PIN);

  Serial.println("\nScanning the I2C bus...");
  int found = 0;
  for (uint8_t addr = 1; addr < 127; addr++) {
    Wire.beginTransmission(addr);
    if (Wire.endTransmission() == 0) {        // 0 = someone ACKed
      Serial.printf("  I2C device found at 0x%02X\n", addr);
      found++;
    }
  }
  Serial.println(found ? "Done." : "Nothing found — check wiring, power, and GND.");
}

void loop() {}
