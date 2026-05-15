/*
 * File:   main.c
 * Author: Prasad Mahabare
 *
 * Created on 13 May, 2026, 9:29 PM
 */


#include <xc.h>
#include "CONFIG.h"
#include "I2C.h"

void main(void) {
    ADCON1 = 0x0F;
    return;
}
