/*
 * lcd.h
 *
 *  Created on: 20-Sept-2026
 *      Author: rushikesh
 */

#ifndef INC_LCD_H_
#define INC_LCD_H_

#include "stm32f4xx.h"

#ifndef BV
		#define BV(n) (1<<(n))
#endif
#define PCF8574_ADDR	0x4E

#define LCD_RS_POS			0
#define LCD_RW_POS			1
#define LCD_EN_POS			2
#define LCD_BL_POS			3

#define LCD_DB4_POS			4
#define LCD_DB5_POS			5
#define LCD_DB6_POS			6
#define LCD_DB7_POS			7

#define LCD_CLEAR 			0x01
#define ENTRY_MODE_SET		0x06
#define DISPLAY_ON_OFF		0X0C
#define FUNCTION_SET		0X28
#define LCD_LINE1			0x80
#define LCD_LINE2			0xC0

#define LCD_CMD				0
#define LCD_DATA			1


void lcd_init(void);
void lcd_write_nibble(uint8_t rs, uint8_t val);
void lcd_busy_wait(void);
void lcd_write_byte(uint8_t rs, uint8_t val);
void lcd_puts(uint8_t line, char str[]);
void lcd_shift_display(void);

void PCF8574_Write(uint8_t val);
uint8_t PCF8574_Read(void);















#endif /* INC_LCD_H_ */
