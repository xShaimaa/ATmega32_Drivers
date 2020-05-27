/*
 * keypad.h
 *
 * Created: 05-Apr-20 6:42:17 AM
 *  Author: shimo
 */ 


#ifndef KEYPAD_H_
#define KEYPAD_H_

#include <avr/io.h>
#include <util/delay.h>
#ifndef F_CPU
#define F_CPU 8000000UL
#endif
//keypad pins
#define keypadPORT PORTD
#define keypadPIN PIND
#define keupadDDR DDRD

//rows
#define R0 0
#define R1 1
#define R2 2
#define R3 3

//columns
#define C0 4
#define C1 5
#define C2 6
#define C3 7

//functions
void keypad_init();			// initialize the keypad
char keypad_check();		//check if there is any pressed key
char keypad_getkey ();		//print out the pressed key	

#endif /* KEYPAD_H_ */