#include "gpio.h"

void GPIO_config_pullup(int pin){
  NRF_GPIO->PIN_CNF[pin] = GPIO_INPUT_PULLUP;
}

void GPIO_config_output(int pin){
  nrf_gpio_cfg_output(pin);
}

void GPIO_unset_pin(int pin){
  nrf_gpio_pin_write(pin, 0);
}

void GPIO_write_pin(int pin, int value){
  nrf_gpio_pin_write(pin, value);
}
