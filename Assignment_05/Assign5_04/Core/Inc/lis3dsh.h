/*
 * lis3dsh.h
 *
 *  Created on: 30-Sept-2026
 *      Author: laukik
 */

#ifndef INC_LIS3DSH_H_
#define INC_LIS3DSH_H_

#include "stm32f4xx.h"

#define ACCEL_CR4	0x20
#define ACCEL_STATUS	0x27
#define ACCEL_XL	0x28
#define ACCEL_YL	0x2A
#define ACCEL_ZL	0x2C

#define ACCEL_XYZEN	((1 << 2)|(1 << 1)|(1 << 0))
#define ACCEL_ODR	(1 << 6)
#define ACCEL_SR_XYZDA	(1 << 3)

#define ACCEL_GPIO	GPIOE
#define ACCEL_GPIO_PIN	GPIO_PIN_3

typedef struct AccelReading {
	int16_t x,y,z;
}accel_r;

void accel_init(void);
void accel_waitforreading(void);
accel_r accel_getreading(void);

void accel_write(uint8_t addr,uint8_t data[],uint8_t size);
void accel_read(uint8_t addr, uint8_t data[],uint8_t size);

#endif /* INC_LIS3DSH_H_ */
