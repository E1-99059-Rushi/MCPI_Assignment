/*
 * my_led.h
 *
 *  Created on: 16-Sept-2026
 *      Author: rushikesh
 */

#ifndef MY_LED_H_
#define MY_LED_H_
#include <stdint.h>
#include<stm32f4xx.h>

void init_led();

void Led_On_Off_Rev();
void Led_Toggle_Opposite();
void init_switch();

#endif /* MY_LED_H_ */
