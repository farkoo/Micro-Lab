#include <header.h>
#include <func2.h>

void func2(char startpos, int ms_duration){
    int counter;   
    DDRB = 0xFF;      
    switch(startpos){
        case 1:
            PORTB = 0x01;
            break;
         case 2:
            PORTB = 0x02;
            break;
        case 3:
            PORTB = 0x04;
            break;
        case 4:
            PORTB = 0x08;
            break;
         case 5:
            PORTB = 0x10;
            break;
         case 6:
            PORTB = 0x20;
            break;
        case 7:
            PORTB = 0x40;
            break;
        case 8:
            PORTB = 0x80;
            break;
         default:
            PORTB = 0x80;
    }
    counter = 0;
    while(counter != ms_duration){
              if(PORTB == 0x00)
                PORTB =  0x80;
              delay_ms(100);
              counter += 100;      
              PORTB = PORTB>>1;     
    }
    return;
}