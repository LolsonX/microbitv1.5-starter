#include "buttons.h"
#include "pins.h"
#include <nrf_gpio.h>

void buttons_init(void)
{
    nrf_gpio_cfg_input(BTN_A, NRF_GPIO_PIN_PULLUP);
    nrf_gpio_cfg_input(BTN_B, NRF_GPIO_PIN_PULLUP);
}

bool button_a_pressed(void)
{
    return !nrf_gpio_pin_read(BTN_A);
}

bool button_b_pressed(void)
{
    return !nrf_gpio_pin_read(BTN_B);
}
