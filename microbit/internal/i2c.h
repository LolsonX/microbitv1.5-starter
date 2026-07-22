#include "nrf.h"
#include "nrf_gpio.h"
#include "gpio.h"

#define TWI_ENABLE 1
#define TWI_DISABLE 0
typedef struct {
    int sda, scl;
} I2C;

I2C I2C_setup(int sda, int sck);
void I2C_write(int address, uint8_t data);
