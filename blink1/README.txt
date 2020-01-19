/*
  
     File:     README.txt
     Source:   blink1.c
     Project:  General Use
   
     Purpose:  Blink one LED              
     Depend.:
   
     Platform: AVR / PIC
     Language: C
     Compiler: AVR Tool-Chain, MPLAB XC8
  
     Version:  1.x
     Date:     2020-01-19
     Author:   Ing. G. Pechoc
  
     License: (CC BY-NC-SA 4.0)
              Attribution-NonCommercial-ShareAlike 4.0 International 
              https://creativecommons.org/licenses/by-nc-sa/4.0/legalcode

*/

	
	This program is your first "Hello World", but on a MCU we let blink a LED.

	Please change before compilation the following lines accordingly to your 
    used hardware:
     
    #define PIC           // AVR | PIC
       if choosen AVR maybe there is a warning about a second definition.
       It can be ignored, or you comment this line out.

    #define  ATtiny861    // ATtiny85 | ATtiny817 | ATtiny841 | ATtiny861 | 
                          // PIC16F18877
       Choose the right hardware. If yours is not in the list then look in 
       the data sheet for a valid Port number for PORTB and change a line 
       in the PORT definitions.

    #define DELAY 10
       Either you comment that out if no delay is wanted or you change 
       the ms to wait.
       In case the delay should work precise then probably values for F_CPU 
       or _XTAL_FREQ should be adapted accordingly to the data sheet.

    ATTENTION:
       please hold in mind that the outputs normally can not provide much current.
       So please never connect a LED without a series resistor!!!
       It depends on the supply voltage and the capability of the output pin
       but 470 Ohms is a good guess.


    Compile, load and run the program.
