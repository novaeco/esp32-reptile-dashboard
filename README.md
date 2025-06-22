# ESP32 Reptile Dashboard

## Overview
The project provides a skeleton for a reptile monitoring dashboard running on an ESP32.
It uses the LVGL graphics library and includes basic components for LCD and touch
controller drivers. Data about the animals is expected in JSON format and can be
stored on the device for display.

## Hardware requirements
- ESP32 development board
- LCD using an ST7262 controller
- GT911 touch controller
- Optional storage (SPI flash or similar) for JSON data

## Build instructions (ESP‑IDF)
1. Install the [ESP‑IDF](https://docs.espressif.com/projects/esp-idf/en/latest/esp32/get-started/index.html) toolchain.
2. Configure the project:
   ```bash
   idf.py menuconfig
   ```
3. Build the firmware:
   ```bash
   idf.py build
   ```
4. Flash the board and monitor the output:
   ```bash
   idf.py -p /dev/ttyUSB0 flash monitor
   ```
5. Place any JSON data (e.g. `data/animals.json`) onto the target storage if required.
