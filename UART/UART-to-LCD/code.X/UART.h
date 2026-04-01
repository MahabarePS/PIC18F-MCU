/* 
 * File:   UART.h
 * Author: Prasad Mahabare
 *
 * Created on 27 March, 2026, 3:23 PM
 */

#ifndef UART_H
#define	UART_H

#ifdef	__cplusplus
extern "C" {
#endif
    
#include "CONFIGS.h"
    
//---Receive data from UART on RC7
#define RX_PIN RC7
//---TRIS register used to data direction
#define RX_PIN_CONFIG TRISCbits.RC7
    void UART_init(){
        //---Setting data direction as input
        RX_PIN_CONFIG = INPUT_PIN;
        //---Initialize SPBRGH:SPBRG(51)
        SPBRGH =0x00 ;
        SPBRG=0x33 ;
        //---16-bit Asynchronous High Speed
        //---SYNC=0,BRGH=0, BRG16=1
        TXSTAbits.SYNC = RESET;
        BAUDCONbits.BRG16 = SET;
        TXSTAbits.BRGH = RESET;
        //---Enable the asynchronous serial port by
        RCSTAbits.SPEN = SET;
        //---Enabling the interrupt
        INTCONbits.PEIE=SET;
        PIE1bits.RCIE=SET;
        //---Enable recception
        RCSTAbits.CREN = SET;
    }
    void UART_reception(){
        /*
         When UART flag is 1
         * get the string received from UART
         * Send it to the LCD as a string;
         */
    }

#ifdef	__cplusplus
}
#endif

#endif	/* UART_H */

