#include "delay.h"
#include "stdint.h"
#include "i2c.h"

#define LCD_ADDRESS 0x27
#define LCD_RS 0x01
#define LCD_RW 0x02
#define LCD_E  0x04
#define LCD_BACKLIGHT 0x08

void lcd_send_nibble(uint8_t nibble, uint8_t flags);
void lcd_command(uint8_t cmd);
void lcd_data(uint8_t data);
void lcd_string(const char *str);
void lcd_init();
