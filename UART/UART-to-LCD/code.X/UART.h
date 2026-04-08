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
#define RX_PIN_CONFIG TRISCbits.TRISC7
    
    void UART_init(void);
    void read_rxBuffer(void);
    
    volatile unsigned char letter = '\0';
    void UART_init(){
        //---Setting data direction as input
        RX_PIN_CONFIG = INPUT_PIN;
        //---Initialize SPBRGH:SPBRG(207)
        SPBRGH =0x00 ;
        SPBRG=0xCF;
        //---16-bit Asynchronous High Speed
        //---SYNC=0,BRGH=0, BRG16=1
        TXSTAbits.SYNC = OFF;
        BAUDCONbits.BRG16 = ON;
        TXSTAbits.BRGH = ON;
        //---Enable the asynchronous serial port by
        RCSTAbits.SPEN = ON;
        //---Enabling the interrupt
        INTCONbits.GIE=ON;
        INTCONbits.PEIE=ON;
        PIE1bits.RCIE=ON;
        //---Enable reception
        RCSTAbits.CREN =ON;
    }
    /*
         When UART flag is 1
         * get the string received from UART
         * Send it to the LCD as a string;
    */
    void __interrupt() ISR(void){
        //---Once the reception is complete RCIF is SET
        if(RCIF==ON){
            if(OERR==ON)
            {
                CREN=OFF;     //Disable receiver
                CREN=ON;       //Enable receiver
            }else{
                read_rxBuffer();  //copy the data and h/w will RESET RCIF
            }
        }
    }
    
    void read_rxBuffer(){
        letter = RCREG;
    }

#ifdef	__cplusplus
}
#endif

#endif	/* UART_H */

