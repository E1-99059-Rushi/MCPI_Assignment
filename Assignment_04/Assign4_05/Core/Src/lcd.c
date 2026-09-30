/*
 * lcd.c
 *
 *  Created on: 25-Sept-2026
 *      Author: laukik
 */
#include "lcd.h"
extern I2C_HandleTypeDef hi2c1;

void PCF8574_write(uint8_t val){

	HAL_I2C_Master_Transmit(&hi2c1, PCF8574_ADDR, &val, 1, HAL_MAX_DELAY);

}

uint8_t PCF8574_read(void){

	uint8_t val;
	HAL_I2C_Master_Receive(&hi2c1, PCF8574_ADDR, &val, 1, HAL_MAX_DELAY);
	return val;
}

void init(void){

	HAL_Delay(20);
	write_nibble(LCD_CMD, 0x03);
	HAL_Delay(5);
	write_nibble(LCD_CMD, 0x03);
	HAL_Delay(1);
	write_nibble(LCD_CMD, 0x03);
	HAL_Delay(1);
	write_nibble(LCD_CMD, 0x02);
	HAL_Delay(1);

	//lcd init cmd

	write_byte(LCD_CMD, LCD_FUNCTION_SET);
	write_byte(LCD_CMD, LCD_DISPLAY_ON_OFF);
	write_byte(LCD_CMD, LCD_ENTRY_MODE_SET);
	write_byte(LCD_CMD, LCD_CLEAR);
	HAL_Delay(20);
}

void write_nibble(uint8_t rs,uint8_t val){

	uint8_t rs_flag = (rs == LCD_DATA)? BV(LCD_RS):0;
	uint8_t data = (val << LCD_D4)|rs_flag |BV(LCD_BL) |BV(LCD_EN);
	PCF8574_write(data);
	HAL_Delay(1);

	data = (val << LCD_D4)|rs_flag |BV(LCD_BL);
	PCF8574_write(data);
}

void write_byte(uint8_t rs,uint8_t val){

	uint8_t high = val >> 4, low = val & 0x0F;
	write_nibble(rs, high);
	write_nibble(rs, low);
	HAL_Delay(3);
}

void lcd_puts(uint8_t line,char str[]){

	write_byte(LCD_CMD, line);
	for(int i = 0; str[i] != '\0'; i++)
		write_byte(LCD_DATA, str[i]);
}

void shift_display(void){

	write_byte(LCD_CMD, 0x18);
}















