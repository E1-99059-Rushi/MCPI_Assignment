/*
 * main.c
 */

#include <stdint.h>
#include <stdio.h>
#include <stm32f4xx.h>

#include "my_Led.h"



// Flag shared between ISR and main
volatile int button_pressed = 0;


// EXTI0 Interrupt Handler
void EXTI0_IRQHandler(void)
{
    // Clear EXTI0 pending flag
    EXTI->PR |= BV(0);

    // Set flag
    button_pressed = 1;
}


int main(void)
{
    // Initialize LED
    init_led();

    // Initialize switch
    init_switch();

    while(1)
    {
        // Check whether button was pressed
        if(button_pressed)
        {
            // Clear flag
            button_pressed = 0;

            // Toggle LED
            led_toggle();
        }
    }
}
