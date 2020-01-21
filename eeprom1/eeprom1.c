

/*
  
     File:     eeprom1.c
     Type:     source
     Project:  General Use
   
     Purpose:  Read ID from EEPROM              
     Depend.:
   
     Platform: AVR / PIC
     Language: C
     Compiler: AVR Tool-Chain, MPLAB XC8
  
     Version:  0.1
     Date:     2020-01-21
     Author:   Ing. G. Pechoc
  
     License: (CC BY-NC-SA 4.0)
              Attribution-NonCommercial-ShareAlike 4.0 International 
              https://creativecommons.org/licenses/by-nc-sa/4.0/legalcode
 

***********************************************************************

     Version History:
     
     0.1      2020-01-21       Initial Version
  
***********************************************************************

*/

//
// Choose MCU series, target type and delay in ms if wanted
//
//#define AVR         // AVR | PIC
#define  ATtiny861    // ATtiny85 | ATtiny841 | ATtiny861 | PIC16F18877

// define clock for wait function
#ifdef AVR
#define F_CPU 1000000UL
#endif
#ifdef PIC
#define _XTAL_FREQ 4000000
#endif

// includes depending on MCU models
#ifdef AVR
#include <avr/io.h>
#include <avr/eeprom.h>
#endif
#ifdef PIC
#include <xc.h>
#endif

 uint16_t RomWord = 0x0000 ;


int main(void) {
 

    //
    // EEPROM definitions
    //
    uint16_t DeviceID = 0x0FBC ;
    uint8_t devid = 0;
    uint8_t RomByte = 0x00;
    
    int eind = 0;    // index
    // write Device ID
    // eeprom_update_word(( uint16_t *) eind , DeviceID ) ;
    // eeprom_update_byte (( uint8_t *) 46 , ByteOfData )    
    // Read DeviceId
    RomWord = eeprom_read_word (( uint16_t *) eind) ;
    if (RomWord == DeviceID) devid = 1;
    // erase eeprom partially
    for (int i = 2; i<20; i++){
        eeprom_update_byte (( uint8_t *) i , 0xFF );
    }   

  
    // Return the mandatory for the "main" function value.
    return (0);
}
