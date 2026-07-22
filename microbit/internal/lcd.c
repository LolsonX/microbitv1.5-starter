#include "lcd.h"

void lcd_send_nibble(uint8_t nibble, uint8_t flags) {
  I2C_write(LCD_ADDRESS, (nibble & 0xF0) | flags | LCD_E | LCD_BACKLIGHT);
  for(volatile int i = 0; i < 10000; i++) { __NOP(); }
  I2C_write(LCD_ADDRESS, (nibble & 0xF0) | flags | LCD_BACKLIGHT); 
  for(volatile int i = 0; i < 10000; i++) { __NOP(); }
}

void lcd_command(uint8_t cmd){
  lcd_send_nibble(cmd & 0xF0, 0); 
  lcd_send_nibble((cmd << 4) & 0xF0, 0);
  if(cmd == 0x01 || cmd == 0x02){
    for(volatile int i = 0; i < 50000; i++) { __NOP(); }
  }
}

void lcd_data(uint8_t data){
  lcd_send_nibble(data & 0xF0, LCD_RS);
  lcd_send_nibble((data << 4) & 0xF0, LCD_RS);
}

void lcd_string(const char *str){
  while(*str){
    lcd_data(*str++);
  }
}

void lcd_init(){
  for(volatile int i = 0; i < 200000; i++) { __NOP(); }
  lcd_send_nibble(0x30, 0);
  for(volatile int i = 0; i < 100000; i++) { __NOP(); }
  lcd_send_nibble(0x30, 0);
  for(volatile int i = 0; i < 100000; i++) { __NOP(); }
  lcd_send_nibble(0x30, 0);
  for(volatile int i = 0; i < 100000; i++) { __NOP(); }
  lcd_send_nibble(0x20, 0);
  for(volatile int i = 0; i < 100000; i++) { __NOP(); }
  lcd_command(0x28);
  lcd_command(0x08);
  lcd_command(0x01);
  lcd_command(0x06);
  lcd_command(0x0C);
}

