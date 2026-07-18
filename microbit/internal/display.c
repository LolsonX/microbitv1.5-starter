#include "display.h"
#include "pins.h"
#include <nrf_gpio.h>

static const uint8_t col_pins[NUM_COLS] = {
    PIN_COL1, PIN_COL2, PIN_COL3, PIN_COL4, PIN_COL5,
    PIN_COL6, PIN_COL7, PIN_COL8, PIN_COL9
};

static const uint8_t row_pins[NUM_ROWS] = {
    PIN_ROW1, PIN_ROW2, PIN_ROW3
};

void display_init(void)
{
    for (int i = 0; i < NUM_COLS; i++) {
        nrf_gpio_cfg_output(col_pins[i]);
        nrf_gpio_pin_set(col_pins[i]);
    }

    for (int i = 0; i < NUM_ROWS; i++) {
        nrf_gpio_cfg_output(row_pins[i]);
        nrf_gpio_pin_clear(row_pins[i]);
    }
}

void display_all_on(void)
{
    for (int i = 0; i < NUM_COLS; i++) {
        nrf_gpio_pin_clear(col_pins[i]);
    }
    for (int i = 0; i < NUM_ROWS; i++) {
        nrf_gpio_pin_set(row_pins[i]);
    }
}

void display_all_off(void)
{
    for (int i = 0; i < NUM_ROWS; i++) {
        nrf_gpio_pin_clear(row_pins[i]);
    }
    for (int i = 0; i < NUM_COLS; i++) {
        nrf_gpio_pin_set(col_pins[i]);
    }
}
