

/*
  
     File:     blink1.c
     Type:     source
     Project:  General Use
   
     Purpose:  Blink one LED              
     Depend.:
   
     Platform: AVR / PIC
     Language: C
     Compiler: AVR Tool-Chain, MPLAB XC8
  
     Version:  1.5
     Date:     2020-01-19
     Author:   Ing. G. Pechoc
  
     License: (CC BY-NC-SA 4.0)
              Attribution-NonCommercial-ShareAlike 4.0 International 
              https://creativecommons.org/licenses/by-nc-sa/4.0/legalcode
 

***********************************************************************

     Version History:
     
     1.0      2020-01-16       Version for AVR and PIC
     1.1      2020-01-17       Changes after Test with PIC
     1.2      2020-01-18       Enhanced documentation
     1.3      2020-01-18       Corrections for PIC16F18877
     1.5      2020-01-19       Added support for ATtiny817 (Xplained)
  
***********************************************************************

*/

/* ********************************************************************

   Choose MCU series, target type and delay in ms if wanted
   or comment out DELAY to get maximum possible frequency.

*/ 
//#define AVR            // AVR | PIC
#define ATtiny817  // ATtiny85 | ATtiny817 | ATtiny841 | ATtiny861 | PIC16F18877
#define DELAY 10
/*
******************************************************end params***** */


// define clock for wait function
#if defined(ATtiny817) 
#define F_CPU 3333333
#elif defined(ATtiny85) ||  definedATtiny841) || defined(ATtiny861) 
#define F_CPU 1000000UL
#endif 
#ifdef PIC
#define _XTAL_FREQ 4000000
#endif

// includes depending on MCU model
#ifdef AVR
#include <avr/io.h>
#include <avr/portpins.h>
#include <util/delay.h>
#endif
#ifdef PIC
#include <xc.h>
#include <stdint.h>
#endif

/*
   Define the I/O port to be used for the LED.
 
   ATTENTION:
    please hold in mind that the outputs normally can not provide much current.
    So please never connect a LED without a series resistor!!!
    It depends on the supply voltage and the capability of the output pin
    but 470 Ohms is a good guess.

*/
#ifdef ATtiny85
#define LED_PORT PB2    // pin 7
#endif
#ifdef ATtiny817
#define LED_PORT 0    // User LED on XPLAIN Board
#endif
#ifdef ATtiny841
#define LED_PORT PB2    // pin 5
#endif
#ifdef ATtiny861
#define LED_PORT PB2    // pin 3
#endif
#ifdef PIC16F18877
#define LED_PORT _PORTB_RB2_MASK   // pin 35
#endif
 


int main(void) {
 
    // Set the LED port number as output.
    // The DDRB is the data direction for port B.
#if defined(ATtiny817) 
    PORTC.DIR |= (1 << LED_PORT);
#elif defined(ATtiny85) ||  definedATtiny841) || defined(ATtiny861) 
    DDRB |= (1 << LED_PORT);
    //DDRB = 0x80;
#endif 
#ifdef PIC
    ANSELB = 0x0;      // portB is digital not analog
    TRISB = 0x00;      // set all = output 
    PORTB = 0x00;
#endif
    
    
    
    //   
    // Start infinite loop.
    //
    while (1) {
 
        // Set the LED bit to "1" - LED will be "on".
#if defined(ATtiny817) 
    PORTC.OUT = 0x01;
#elif defined(ATtiny85) ||  definedATtiny841) || defined(ATtiny861) 
    DDRB |= (1 << LED_PORT);
#endif    
#ifdef PIC
        PORTB = LED_PORT;
#endif
 
        // Wait a little.
        // The delay function simply does N-number of "empty" loops.
#ifdef DELAY 
#ifdef PIC
        __delay_ms(DELAY);
#endif
#ifdef AVR
        _delay_ms(DELAY);
#endif
#endif
       
        
        // Set the LED bit to "0" - LED will be "off".
#if defined(ATtiny817) 
    PORTC.OUT = 0x00;
#elif defined(ATtiny85) ||  definedATtiny841) || defined(ATtiny861) 
    PORTB &= ~(1 << LED_PORT);
#endif    
#ifdef PIC
        PORTB = 0x00;
#endif

        // Wait a little.
#ifdef DELAY 
#ifdef PIC
        __delay_ms(DELAY);
#endif
#ifdef AVR
        _delay_ms(DELAY);
#endif
#endif
 
        // Do it again ...
    }
 
    // Return the mandatory for the "main" function value.
    return (0);
}
