#ifndef __func4_INCLUDE__
#define __func4_INCLUDE__

/*
* Function: func4
* -------------------
* show numbers(s) on LED(s) from 0-9 or 9-0
* 
* direction: inc -> increasing(0->9), dec -> decreasing(9->0)
* cuncurrent: True -> 4 LEDs are on, False -> one of the LEDs is on
* which: LED number that is on
*
* returns: nothing
*/ 
void func4(char direction, char concurrent, char which);

#endif