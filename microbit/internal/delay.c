#include "delay.h"

void delay_us(uint32_t us){
  while (--us){
    __NOP();
  }
}

void delay_ms(int ms){
  delay_us(ms * 1000);
}
