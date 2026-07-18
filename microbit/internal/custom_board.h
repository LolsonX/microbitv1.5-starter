#ifndef CUSTOM_BOARD_H
#define CUSTOM_BOARD_H

#include "nrf_gpio.h"

#define BOARD_CUSTOM

#define LEDS_NUMBER    0
#define BUTTONS_NUMBER 2

#define BUTTON_0       17
#define BUTTON_1       26
#define BUTTON_PULL    NRF_GPIO_PIN_PULLUP

#define BSP_BUTTON_0   BUTTON_0
#define BSP_BUTTON_1   BUTTON_1

#define BSP_BUTTON_0_MASK (1 << BUTTON_0)
#define BSP_BUTTON_1_MASK (1 << BUTTON_1)
#define BUTTONS_MASK   (BSP_BUTTON_0_MASK | BSP_BUTTON_1_MASK)
#define BUTTONS_LIST   { BUTTON_0, BUTTON_1 }

#define RX_PIN_NUMBER  25
#define TX_PIN_NUMBER  24
#define CTS_PIN_NUMBER 0
#define RTS_PIN_NUMBER 0
#define HWFC           false

#define NRF_CLOCK_LFCLKSRC NRF_CLOCK_LFCLKSRC_XTAL_20_PPM

#endif
