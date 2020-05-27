/*
 * keypad.c
 *
 * Created: 05-Apr-20 6:43:11 AM
 *  Author: shimo
 */ 

#include "keypad.h"

//rows an columns of the keypad
int keypad_rows [] = {R0, R1, R2, R3};						//array for the rows
int keypad_columns [] = {C0, C1, C2, C3};					//array for the columns

//functions
void keypad_init(){
	DDRD &= ~((1<<R0) | (1<<R1) | (1<<R2) | (1<<R3));		//rows are set as input
	DDRD |= ((1<<C0) | (1<<C1) | (1<<C2) | (1<<C3));		//columns are set as output
	keypadPORT = 0xFF;										//enable the pullup for all pins
}
/*****************************************************************************************************************************/
char keypad_check(){
	int i =0;
	int j =0;
	for (i=0; i<4; i++)
	{
		keypadPORT |= ((1<<keypad_columns[0]) | (1<<keypad_columns[1]) | (1<<keypad_columns[2]) | (1<<keypad_columns[3]));	//send 1 to columns 
		keypadPORT &= ~(1<<keypad_columns[i]);				//send 0 to one column at a time
		for (j=0; j<4; j++)
		{
			if (!(keypadPIN & (1<<keypad_rows[j])))			//check if button is pressed
			{
				switch (i) {
					case (0):{
						if (j==0) return '7';
						else if (j==1) {return '4';}
						else if (j==2) {return '1';}
						else if (j==3) {return 'C';}
						break;
						}
						case (1):{
							if (j==0) return '8';
							else if (j==1) {return '5';}
							else if (j==2) {return '2';}
							else if (j==3) {return '0';}
							break;
						}
						case (2):{
							if (j==0) return '9';
							else if (j==1) {return '6';}
							else if (j==2) {return '3';}
							else if (j==3) {return '=';}
							break;
						}
						case (3):{
							if (j==0) return '/';
							else if (j==1) {return '*';}
							else if (j==2) {return '-';}
							else if (j==3) {return '+';}
							break;
						}
				}
			
			}
		}
		_delay_ms(10);
	}
	return 'X';												//if no key is pressed, return X
}
/*****************************************************************************************************************************/
char keypad_getkey()										//check if there is a pressed key
{
	char key_pressed;
	key_pressed = 'X';
	while (key_pressed == 'X'){
		key_pressed = keypad_check();
	}
	return key_pressed;
}
/*****************************************************************************************************************************/

