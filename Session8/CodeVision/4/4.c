#include <headers.h>

// Graphic Display functions

GLCDINIT_t glcd_init_data;

// Declare your global variables here

unsigned long int x;
unsigned long int y;
unsigned int s = 0;
unsigned int m = 0;
unsigned int h = 0;

const unsigned short FK[] = {
        0xFF, 0xFF, 0xFF, 0x00, 0xF6, 0xF6, 0xF6, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0xE7, 0xDB, 0xBD, 0x7E, 0xFF, 0xFF, // Code for char  
        0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0xF6, 0xF6, 0xF6, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0xE7, 0xDB, 0xBD, 0x7E, 0xFF,  // Code for char !
        0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0xF6, 0xF6, 0xF6, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0xE7, 0xDB, 0xBD, 0x7E,  // Code for char "
        0x7E, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0xF6, 0xF6, 0xF6, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0xE7, 0xDB, 0xBD,  // Code for char #
        0xBD, 0x7E, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0xF6, 0xF6, 0xF6, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0xE7, 0xDB,  // Code for char $
        0xDB, 0xBD, 0x7E, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0xF6, 0xF6, 0xF6, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0xE7,  // Code for char %
        0xE7, 0xDB, 0xBD, 0x7E, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0xF6, 0xF6, 0xF6, 0xFF, 0xFF, 0xFF, 0xFF, 0x00,  // Code for char &
        0x00, 0xE7, 0xDB, 0xBD, 0x7E, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0xF6, 0xF6, 0xF6, 0xFF, 0xFF, 0xFF, 0xFF,  // Code for char '
        0xFF, 0x00, 0xE7, 0xDB, 0xBD, 0x7E, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0xF6, 0xF6, 0xF6, 0xFF, 0xFF, 0xFF,  // Code for char (
        0xFF, 0xFF, 0x00, 0xE7, 0xDB, 0xBD, 0x7E, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0xF6, 0xF6, 0xF6, 0xFF, 0xFF,  // Code for char )
        0xFF, 0xFF, 0xFF, 0x00, 0xE7, 0xDB, 0xBD, 0x7E, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0xF6, 0xF6, 0xF6, 0xFF,  // Code for char *
        0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0xE7, 0xDB, 0xBD, 0x7E, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0xF6, 0xF6, 0xF6,  // Code for char +
        0xF6, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0xE7, 0xDB, 0xBD, 0x7E, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0xF6, 0xF6,  // Code for char ,
        0xF6, 0xF6, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0xE7, 0xDB, 0xBD, 0x7E, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0xF6,  // Code for char -
        0xF6, 0xF6, 0xF6, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0xE7, 0xDB, 0xBD, 0x7E, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x00,  // Code for char .
        0x00, 0xF6, 0xF6, 0xF6, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0xE7, 0xDB, 0xBD, 0x7E, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,  // Code for char /
        0xFF, 0x00, 0xF6, 0xF6, 0xF6, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0xE7, 0xDB, 0xBD, 0x7E, 0xFF, 0xFF, 0xFF, 0xFF   // Code for char 0
        };
        
// Timer1 overflow interrupt service routine
interrupt [TIM1_OVF] void timer1_ovf_isr(void)
{
// Reinitialize Timer1 value
TCNT1H=0x85EE >> 8;
TCNT1L=0x85EE & 0xff;
// Place your code here
question3();

}

void main(void)
{
    int i,j;
    // Declare your local variables here
    // Variable used to store graphic display
    init_board();
    glcd_init(&glcd_init_data);

    // Global enable interrupts
    question2();   
     for(i = 0; i < 90; i++)
        for(j = 0; j < 90; j++);    
    // Global enable interrupts
    #asm("sei")
     for(i = 0; i < 90; i++)
        for(j = 0; j < 90; j++);    #asm("cli")
    question1(); 
}