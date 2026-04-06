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
    
volatile unsigned char data='\0';            // copy RCREG data in to data register
volatile uint8_t rx_flag = 0;                // indicator or new data   
    void UART_init(){
        //---Setting data direction as input
        RX_PIN_CONFIG = INPUT_PIN;
        //---Initialize SPBRGH:SPBRG(51)
        SPBRGH =0x00 ;
        SPBRG=0x33 ;
        //---16-bit Asynchronous High Speed
        //---SYNC=0,BRGH=1, BRG16=1
        TXSTAbits.SYNC = RESET;
        BAUDCONbits.BRG16 = SET;
        TXSTAbits.BRGH = SET;
        //---Enable the asynchronous serial port by
        RCSTAbits.SPEN = SET;
        //---Enabling the interrupt
        INTCONbits.GIE=SET;
        INTCONbits.PEIE=SET;
        PIE1bits.RCIE=SET;
        //---Enable reception
        RCSTAbits.CREN = SET;
    }
    /*
         When UART flag is 1
         * get the string received from UART
         * Send it to the LCD as a string;
    */
    void __interrupt() ISR(void){
        //---Once the reception is complete RCIF is SET
        if(RCIF==SET){
            if(OERR==SET)
            {
                CREN=RESET;     //Disable receiver
                CREN=SET;       //Enable receiver
            }else{
                rx_flag=SET;
                read_rxBuffer();  //copy the data and h/w will RESET RCIF
            }
        }
    }
    
    void read_rxBuffer(){
        data = RCREG;
    }

#ifdef	__cplusplus
}
#endif

#endif	/* UART_H */

