/* 
 * File:   CONFIGS.h
 * Author: Prasad Mahabare
 *
 * Created on 27 March, 2026, 3:33 PM
 */

#ifndef CONFIGS_H
#define	CONFIGS_H

#ifdef	__cplusplus
extern "C" {
#endif

#pragma config OSC = HS         // Oscillator Selection bits (HS oscillator)
#pragma config WDT = OFF        // Watchdog Timer Enable bit (WDT disabled (control is placed on the SWDTEN bit))
#pragma config MCLRE = OFF      // MCLR Pin Enable bit (RE3 input pin enabled; MCLR disabled)

#define _XTAL_FREQ 8000000      // 8MHz Crystal Frequency
    
#define OUTPUT_PIN 0
#define INPUT_PIN 1
    
#define OUTPUT_PORT 0x00
#define INPUT_PORT 0xff
    
#define SET 1
#define RESET 0


#ifdef	__cplusplus
}
#endif

#endif	/* CONFIGS_H */

