/*******************************************************
This program was created by the
CodeWizardAVR V3.12 Advanced
Automatic Program Generator
� Copyright 1998-2014 Pavel Haiduc, HP InfoTech s.r.l.
http://www.hpinfotech.com

Project : 
Version : 
Date    : 3/17/2021
Author  : Farzaneh Koohestani
Company : IUT
Comments: 
Session: 3
Question: 4


Chip type               : ATmega16
Program type            : Application
AVR Core Clock frequency: 8.000000 MHz
Memory model            : Small
External RAM size       : 0
Data Stack size         : 256
*******************************************************/

#include <header.h>

// Declare your global variables here
unsigned char key_pad[16] = {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F' };
// External Interrupt 1 service routine
interrupt [EXT_INT1] void ext_int1_isr(void)
{
// Place your code here
    DDRB=0x0F;
    PORTB=0xF0;    
    keypad();

}

void main(void)
{
// Declare your local variables here



    init();
    func4();
while (1)
      {
      // Place your code here

      }
}
