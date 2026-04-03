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
    LCD_StringDisplay(data);
    while(1){
        
    }
    return;
}
