#include <header.h>

unsigned char keypad(void){
    int key = 16;
    DDRB = 0xF0;
    PORTB = 0x0F;         
    
    //lcd_clear();
  
    do{           
        PORTB.4=1; PORTB.5=0; PORTB.6=0; PORTB.7=0;
        if(PINB.0) { key = 0;  continue;}
        if(PINB.1) {key = 1;  continue;}
        if(PINB.2) {key = 2;  continue;}
        if(PINB.3) {key =3;   continue;}                              
        delay_ms(10);
        PORTB.4=0; PORTB.5=1; PORTB.6=0; PORTB.7=0;
        if(PINB.0) {key = 4;  continue;}
        if(PINB.1) {key =  5; continue;}
        if(PINB.2) {key =  6;  continue;}
        if(PINB.3) {key =  7; continue;}                    
        delay_ms(10);
        PORTB.4=0; PORTB.5=0; PORTB.6=1; PORTB.7=0;
        if(PINB.0) {key =  8;   continue;}
        if(PINB.1) {key =  9;   continue;}
        if(PINB.2) {key =  10;   continue;}
        if(PINB.3) {key =  11; continue;}
        delay_ms(10);
        PORTB.4=0; PORTB.5=0; PORTB.6=0; PORTB.7=1;
        if(PINB.0) {key =  12;   continue;}
        if(PINB.1) {key =  13;     continue;}
        if(PINB.2) {key =  14;   continue;}
        if(PINB.3) {key =  15;   continue;}     
        delay_ms(10);
        key = 16;                 
    } while(key == 16);
    
     lcd_putchar(key_pad[key]);              
     delay_ms(200);   
     return key;


}