/*
 * lis3dsh.c
 *
 *  Created on: 30-Sept-2026
 *      Author: laukik
 */

#include "lis3dsh.h"

extern SPI_HandleTypeDef hspi1;


void accel_write(uint8_t addr,uint8_t data[],uint8_t size){

	HAL_GPIO_WritePin(ACCEL_GPIO, ACCEL_GPIO_PIN, GPIO_PIN_RESET);

	addr &= ~(1 << 7);
	HAL_SPI_Transmit(&hspi1, &addr,1, HAL_MAX_DELAY);

	HAL_SPI_Transmit(&hspi1, data, size, HAL_MAX_DELAY);

	HAL_GPIO_WritePin(ACCEL_GPIO, ACCEL_GPIO_PIN, GPIO_PIN_SET);
}

void accel_read(uint8_t addr, uint8_t data[],uint8_t size)
{

	HAL_GPIO_WritePin(ACCEL_GPIO, ACCEL_GPIO_PIN, GPIO_PIN_RESET);

	addr |= (1 << 7);

	HAL_SPI_Transmit(&hspi1, &addr, 1, HAL_MAX_DELAY);

	HAL_SPI_Transmit(&hspi1, data, size, HAL_MAX_DELAY);

	HAL_GPIO_WritePin(ACCEL_GPIO, ACCEL_GPIO_PIN, GPIO_PIN_SET);
}
void accel_init(void){

	uint8_t val_cr4 = ACCEL_XYZEN|ACCEL_ODR;
	accel_write(ACCEL_CR4, &val_cr4, 1);
}

void accel_waitforreading(void){

	uint8_t val_sr;
	do{
		accel_read(ACCEL_STATUS, &val_sr, 1);
	}while((val_sr & ACCEL_SR_XYZDA) == 0);

}

accel_r accel_getreading(void){

	uint8_t data[2];

	accel_r val;

	accel_waitforreading();

	accel_read(ACCEL_XL, data, 2);
	val.x  = ((uint16_t)data[1] << 8) | data[0];


	accel_read(ACCEL_YL, data, 2);
	val.y  = ((uint16_t)data[1] << 8) | data[0];


	accel_read(ACCEL_ZL, data, 2);
	val.z  = ((uint16_t)data[1] << 8) | data[0];



}


