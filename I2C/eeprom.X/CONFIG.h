/* 
 * File:   CONFIG.h
 * Author: Prasad Mahabare
 *
 * Created on 14 May, 2026, 7:19 PM
 */

#ifndef CONFIG_H
#define	CONFIG_H

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
#define INPUT_PORT 0xffS
    
#define ON 1
#define OFF 0

#ifdef	__cplusplus
}
#endif

#endif	/* CONFIG_H */

