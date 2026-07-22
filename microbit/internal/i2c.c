#include "i2c.h"

I2C I2C_setup(int sda, int scl) {
  NRF_TWI0->ENABLE = 0;

  GPIO_config_pullup(sda);
  GPIO_config_pullup(scl);

  NRF_TWI0->EVENTS_RXDREADY = 0;
  NRF_TWI0->EVENTS_TXDSENT = 0;
  NRF_TWI0->EVENTS_ERROR = 0;
  NRF_TWI0->EVENTS_STOPPED = 0;

  NRF_TWI0->PSELSCL = scl;
  NRF_TWI0->PSELSDA = sda;

  NRF_TWI0->FREQUENCY = TWI_FREQUENCY_FREQUENCY_K100;
  NRF_TWI0->ENABLE = TWI_ENABLE_ENABLE_Enabled;

  return (I2C){
      .sda = sda,
      .scl = scl
  };
}

void I2C_write(int address, uint8_t data){
  NRF_TWI0->ADDRESS = address;

  NRF_TWI0->EVENTS_TXDSENT = 0;
  NRF_TWI0->EVENTS_ERROR = 0;
  NRF_TWI0->EVENTS_STOPPED = 0;

  NRF_TWI0->TXD = data;
  NRF_TWI0->TASKS_STARTTX = 1;

  while(1){
    if(NRF_TWI0->EVENTS_TXDSENT)
      break;

    if(NRF_TWI0->EVENTS_ERROR){
      NRF_TWI0->TASKS_STOP = 1;
      while(!NRF_TWI0->EVENTS_STOPPED);
      return;
    }
  }

  NRF_TWI0->TASKS_STOP = 1;
  while(!NRF_TWI0->EVENTS_STOPPED);
}
