/*
 * my_Led.c
 *
 *  Created on: 25-Sept-2026
 *      Author: rushikesh
 */

#include "my_Led.h"

void init_led()
{
    // Enable GPIOD clock
    RCC->AHB1ENR |= BV(3);

    // PD12 as output
    GPIOD->MODER |= BV(24);
    GPIOD->MODER &= ~BV(25);

    // Push-pull
    GPIOD->OTYPER &= ~BV(12);

    // Low speed
    GPIOD->OSPEEDR &= ~(BV(24) | BV(25));

    // No pull-up / pull-down
    GPIOD->PUPDR &= ~(BV(24) | BV(25));

    // LED initially OFF
    GPIOD->ODR &= ~BV(12);
}

void led_toggle()
{
    GPIOD->ODR ^= BV(12);
}
