/*
 * my_switch.c
 *
 *  Created on: 16-Sept-2026
 *      Author: rushikesh
 */
#include "my_led.h"
void init_switch()
{

 RCC->AHB1ENR |= BV(0);

	//Set GPIO A0 as input
	GPIOA->MODER &= ~(BV(1) | BV(0));

	//Set GPIO A0 as low speed
	GPIOA->OSPEEDR &= ~(BV(1) | BV(0));

	//Set GPIO A0 as no pull up no pull down
	GPIOA->PUPDR &= ~(BV(1) | BV(0));



}

