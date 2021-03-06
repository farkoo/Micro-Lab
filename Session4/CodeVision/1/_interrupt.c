#include <header.h>

// External Interrupt 1 service routine
interrupt [EXT_INT1] void ext_int1_isr(void)
{
    // Place your code here
    if(PINB.4 == 0){
        // timer start
        timer_init();           
        flag = 0;
    }                 
    if(PINB.5 == 0 && flag == 0){
        //timer stop      
        TCCR0=(0<<WGM00) | (0<<COM01) | (0<<COM00) | (0<<WGM01) | (0<<CS02) | (0<<CS01) | (0<<CS00);
        flag = 1;
    }                          
    else if(PINB.5 == 0 && flag == 1){      
        // timer reset
        lcd_clear();
        lcd_puts("0:0:0:0");       
        flag = 0;
        ms = 0;
        sec = 0;
        min = 0;
        hour = 0;
    
    }
}          

// Timer 0 overflow interrupt service routine
interrupt [TIM0_OVF] void timer0_ovf_isr(void)
{
    // Reinitialize Timer 0 value
    TCNT0=0xB2;
    // Place your code here
    if(ms == 99){
        sec++;
        ms = 0;
    }          
    if(sec == 59){
        min++;
        sec = 0;
    }           
    if(min == 59){
        hour++;
        min = 0;
    }           
    if(hour == 24){
        ms = 0;
        sec = 0;
        min = 0;
        hour = 0;
    }            
    ms++;
    
    sprintf(hour_str, "%d", hour);
    sprintf(min_str,"%d",min);
    sprintf(sec_str,"%d",sec);
    sprintf(ms_str,"%d",ms);
    
    lcd_clear();
    lcd_puts(hour_str);
    lcd_puts(":");
    lcd_puts(min_str);
    lcd_puts(":");
    lcd_puts(sec_str);
    lcd_puts(":");
    lcd_puts(ms_str);
}