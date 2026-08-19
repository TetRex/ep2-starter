# Embedded Programming 2 — starter project

Everything you need to start each lab. Clone it once; each session you'll swap
the active sketch and (later) drop in your trained model.

**Board:** ESP32-S3-DevKitC-1 · **Framework:** Arduino · **Tool:** PlatformIO (in VS Code)

---

## Quick start

1. Install **VS Code** + the **PlatformIO IDE** extension. Wait for it to finish
   downloading its toolchain, then restart.
2. **File → Open Folder →** this project.
3. Bottom blue bar: **✓ Build**, **→ Upload**, **🔌 Serial Monitor**.
   Or in the PlatformIO terminal: `pio run -t upload && pio device monitor`

The board that ships in this repo is **Session 1's blink + hello**. Flash it
first to prove your whole toolchain works.

> **The LED:** this board has no simple on/off LED — it has one addressable RGB
> LED on **GPIO38** (check the silkscreen: ours reads `RGB@IO38`). The blink
> uses it, but the real proof is the **serial "hello"**, which always works.

> **GPIO2 is a test signal, not a mistake.** `setup()` starts a 1 kHz square
> wave on GPIO2 and leaves it running. It's there for the oscilloscope block in
> session 1 — probe it and you'll find a wave in seconds. The LED pin carries
> pulses for only ~30 µs at a time, which is a much harder first capture.

---

## How the project is organised

| Path | What |
|---|---|
| `src/main.cpp` | The **active** sketch that gets built + flashed. |
| `examples/` | Per-session reference sketches — **copy one into `src/main.cpp`** to use it. |
| `include/` | Headers (e.g. `test_images.h` for session 6). |
| `lib/` | Libraries — **drop your Edge Impulse model here** (session 4). |
| `tools/` | Helper scripts (image → C array). |
| `platformio.ini` | The build recipe (board, libraries, flags). |

PlatformIO only builds `src/` + `lib/`, so the files in `examples/` sit safely
out of the build until you copy one in.

---

## Session by session

- **Session 1 — first flash:** flash `src/main.cpp` as-is (blink + hello).
- **Session 2 — sensor + data:**
  - Wire the MPU-6050: **3V3 → VCC, GND → GND, GPIO8 → SDA, GPIO9 → SCL** *(power off while wiring)*.
  - Copy `examples/session02_i2c_scanner.cpp` → `src/main.cpp`, flash → find `0x68`.
  - Copy `examples/session02_mpu_read.cpp` → `src/main.cpp` → read motion, sanity-check gravity on Z.
  - Record CSVs: `pio device monitor --quiet > wave_01.csv` (one file per gesture).
- **Session 3 — train:** upload your CSVs to Edge Impulse and train. *(Optional: the data forwarder streams live — `npx edge-impulse-data-forwarder`.)*
- **Session 4 — deploy:** export your model as an **Arduino library**, unzip into `lib/`, then work from `examples/session04_deploy.cpp` (edit the `#include` to your project's header).
- **Session 5 — security:** copy `examples/session05_plant_secret.cpp` → `src/main.cpp`, flash, then dump the flash and find your secret (see that file's header).
- **Session 6 — vision:** generate baked-in test images with `tools/image_to_header.py` (see `include/test_images.h`).

---

## Wiring: MPU-6050 (GY-521)

| MPU-6050 | ESP32-S3 |
|---|---|
| VCC | 3V3 |
| GND | GND |
| SDA | GPIO 8 |
| SCL | GPIO 9 |

*(If your board's I²C defaults differ, change the pins in the session-2 sketches.)*

---

## Notes

- **PSRAM:** the default build works on any S3-DevKitC-1. If your board has
  **octal PSRAM** (an `…R8` part) and a TinyML model needs it, uncomment the
  PSRAM block in `platformio.ini`. Don't enable it otherwise — it can stop a
  non-PSRAM board from booting.
- **Can't upload / can't dump flash?** Hold **BOOT**, tap **RESET**, release,
  then retry — that forces download mode.
