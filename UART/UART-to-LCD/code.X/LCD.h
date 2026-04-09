/* 
 * File:   LCD.h
 * Author: Prasad Mahabare
 *
 * Created on 27 March, 2026, 3:22 PM
 */

#ifndef LCD_H
#define	LCD_H

#ifdef	__cplusplus
extern "C" {
#endif
    
#include "CONFIGS.h"
#include "UART.h"

#define LCD_PORT LATD
#define LCD_RS LATAbits.LATA0
#define LCD_RW LATAbits.LATA1
#define LCD_EN LATAbits.LATA2

#define LCD_PORT_CONFIG TRISD
#define RS_CONFIG TRISAbits.TRISA0 
#define RW_CONFIG TRISAbits.TRISA1
#define EN_CONFIG TRISAbits.TRISA2

    
void LCD_GPIO_Init(void);
void LCD_Init(void);
void LCD_Command (unsigned char );
void LCD_Data (unsigned char );
void LCD_CharDisplay(unsigned char);

volatile uint8_t count = 0;

void LCD_GPIO_Init(void)
{
   LCD_PORT_CONFIG = OUTPUT_PORT;
   RS_CONFIG=OUTPUT_PIN;
   RW_CONFIG=OUTPUT_PIN;
   EN_CONFIG=OUTPUT_PIN;
}

void LCD_Init(void)
{
     LCD_Command(0x38);
     __delay_ms(2);
     LCD_Command(0x0E);
     __delay_ms(2);
     LCD_Command(0x06);
     __delay_ms(2);
     LCD_Command(0x01);
     __delay_ms(2);
}

void LCD_Command (unsigned char CMD)
{
      LCD_RW=OFF;
      LCD_RS=OFF;
      LCD_PORT=CMD;
      LCD_EN=ON;
      __delay_us(10);
      LCD_EN=OFF;
}

void LCD_Data (unsigned char DAT)
{
      LCD_RW=OFF;
      LCD_RS=ON;
      LCD_PORT=DAT;
      LCD_EN=ON;
      __delay_us(10);
      LCD_EN=OFF;
}

void LCD_CharDisplay(unsigned char ltr)
{
    
    if(count == 16){
        LCD_Command(0xC0);   // move to 2nd line
    }

    if(count == 32){
        LCD_Command(0x01);   // clear display
        __delay_ms(2);
        count = 0;
    }

    LCD_Data(ltr);
    __delay_ms(2);

    count++;
}


#ifdef	__cplusplus
}
#endif

#endif	/* LCD_H */

