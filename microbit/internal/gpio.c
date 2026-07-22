#include "gpio.h"

void GPIO_config_pullup(int pin){
  NRF_GPIO->PIN_CNF[pin] = GPIO_INPUT_PULLUP;
}
