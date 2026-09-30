/*
 * lcd.h
 *
 *  Created on: 25-Sept-2026
 *      Author: laukik
 */

#ifndef INC_LCD_H_
#define INC_LCD_H_

#include "stm32f4xx.h"

#ifndef BV
	#define BV(n)	(1 << (n))
#endif
#define PCF8574_ADDR	0x4E
#define LCD_RS	0
#define LCD_RW	1
#define LCD_EN	2
#define LCD_BL	3

#define LCD_D4	4
#define LCD_D5	5
#define LCD_D6	6
#define LCD_D7	7

#define LCD_ENTRY_MODE_SET	0x06
#define LCD_CLEAR	0x01
#define LCD_FUNCTION_SET	0x28
#define LCD_DISPLAY_ON_OFF	0x0C
#define LCD_LINE1	0x80
#define LCD_LINE2	0xC0

#define LCD_CMD	0
#define LCD_DATA	1

void init(void);
void write_nibble(uint8_t rs,uint8_t val);
void write_byte(uint8_t rs,uint8_t val);
void lcd_puts(uint8_t line,char str[]);
void shift_display(void);

void PCF8574_write(uint8_t val);
uint8_t PCF8574_read(void);

#endif /* INC_LCD_H_ */
