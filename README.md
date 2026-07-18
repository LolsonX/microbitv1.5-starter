# micro:bit Starter

Minimal CMake project for BBC micro:bit v1 (nRF51822) with Nordic nRF5 SDK. Single header include, clean build, zero warnings.

## Requirements

- `arm-none-eabi-gcc` (16.x tested)
- `cmake` (3.20+)
- `srec_cat` (`srec` package)

```bash
# Ubuntu/Debian
sudo apt install gcc-arm-none-eabi cmake srecord
```

## Quick Start

```bash
./compile
cp bin/app.hex /media/$USER/MICROBIT/
```

## Project Structure

```
├── compile             # Build script
├── CMakeLists.txt      # Root build config
├── src/                # Your code
│   └── main.cpp
├── bin/                # Build output (app.hex)
└── microbit/           # Runtime (don't touch)
    ├── microbit.h      # Include this
    └── internal/       # SDK, board support, linker
```

## User Code

```cpp
#include "microbit.h"

int main(void)
{
    while (true)
    {
        display_all_on();
        nrf_delay_ms(500);
        display_all_off();
        nrf_delay_ms(500);
    }
}
```

`board_init()` is called automatically by startup. Just include `microbit.h` and write your code.

## Available API

### Display

```c
display_init();      // Called by startup
display_all_on();    // All LEDs on
display_all_off();   // All LEDs off
```

### Buttons

```c
button_a_pressed();  // Returns true if BTN_A pressed
button_b_pressed();  // Returns true if BTN_B pressed
```

### nRF SDK

Available through `microbit.h`:

```c
nrf_gpio_pin_set(pin);
nrf_gpio_pin_clear(pin);
nrf_delay_ms(100);
nrf_delay_us(100);
```

### Pin Definitions

```c
BTN_A   // P0.17
BTN_B   // P0.26
ROW1-3  // P0.13-P0.15
COL1-9  // P0.04-P0.12
SCL     // P0.00
SDA     // P0.30
TX      // P0.24
RX      // P0.25
```

## Hardware

- **MCU:** nRF51822-QFAA-R rev 3 (Cortex-M0, 256KB flash, 16KB RAM)
- **SoftDevice:** S110 v8.0.0 (96KB flash @ 0x18000, 8KB RAM)
- **LED Matrix:** 5x5 via 9 columns (active-low) + 3 rows (active-high)
- **Buttons:** Active-low with internal pull-up

## Custom Source Directory

```bash
cmake -B build -DCMAKE_TOOLCHAIN_FILE=microbit/cmake/toolchain/arm-none-eabi-gcc.cmake -DSOURCE_DIR=/path/to/your/code
cmake --build build
```

Or edit `CMakeLists.txt`:

```cmake
set(SOURCE_DIR ${CMAKE_SOURCE_DIR}/your_dir CACHE PATH "Source directory")
```

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

### SDK

The nRF5 SDK (v10.0.0) included in `microbit/nrf51sdk1000dc26b5e/` is property of Nordic Semiconductor ASA and licensed under a BSD 3-clause license. See the copyright headers in individual SDK source files for details.

### LLMs

LLMs were used in creating this project - mostly to scan and modify files after giving them explanaiton of problem.
