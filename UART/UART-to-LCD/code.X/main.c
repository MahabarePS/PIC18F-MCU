/*
 * File:   main.c
 * Author: Prasad Mahabare
 *
 * Created on 27 March, 2026, 3:20 PM
 */

#include <xc.h>
#include "LCD.h"
#include "UART.h"
#include "CONFIGS.h"

void main(void) {
    ADCON1 = 0x0F;
    LCD_GPIO_Init();
    LCD_Init();
    UART_init();
    
    while(1){
        if(letter != '\0'){
            LCD_CharDisplay(letter);
            letter = '\0';
        }
    }
    return;
}
