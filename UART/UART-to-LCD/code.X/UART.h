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
#define RX_PIN_CONFIG TRISC0
    void UART_init(){
        //---Setting data direction as input
        RX_PIN_CONFIG = INPUT_PIN;
        //---Data received will be stored in
        RCREG;
        //---Control flags for reception
        RCSTA;
        
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

