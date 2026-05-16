/* 
 * File:   I2C.h
 * Author: Prasad Mahabare
 *
 * Created on 14 May, 2026, 7:19 PM
 */

#ifndef I2C_H
#define	I2C_H

#ifdef	__cplusplus
extern "C" {
#endif

#include "CONFIG.h"
/*
 * RC3/SCK/SCL
 * RC4/SDI/SDA
 */
#define TRISCbits.TRISC3 SCL
#define TRISCbits.TRISC4 SDA
 
    void I2C_init(void);        //I2C driver
    //need global interrupt enabled
    
    void I2C_init(){
        //---Enabling the interrupt
        INTCONbits.GIE=ON;
        INTCONbits.PEIE=ON;
    }
#ifdef	__cplusplus
}
#endif

#endif	/* I2C_H */

