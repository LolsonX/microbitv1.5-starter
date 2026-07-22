#include "nrf_gpio.h"

#define GPIO_INPUT_PULLUP \
    ((GPIO_PIN_CNF_DIR_Input << GPIO_PIN_CNF_DIR_Pos) | \
     (GPIO_PIN_CNF_INPUT_Connect << GPIO_PIN_CNF_INPUT_Pos) | \
     (GPIO_PIN_CNF_PULL_Pullup << GPIO_PIN_CNF_PULL_Pos))

#define GPIO_INPUT_PULLDOWN \
     ((GPIO_PIN_CNF_DIR_Input << GPIO_PIN_CNF_DIR_Pos) | \
     (GPIO_PIN_CNF_INPUT_Connect << GPIO_PIN_CNF_INPUT_Pos) | \
     (GPIO_PIN_CNF_PULL_Pulldown << GPIO_PIN_CNF_PULL_Pos))

void GPIO_config_pullup(int pin);
