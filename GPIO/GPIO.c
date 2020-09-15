/*
 * GPIO.c
 *
 * Created: 03-Aug-20
 *  Author: shimo
 */
 

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GPIO.h"


void GPIO_voidSetPinDir(u8 port_name, u8 pin_num, u8 status)
{
	switch (port_name){
		case PORTA:
			if (status == OUTPUT){
				SET_BIT(GPIO_DDRA, pin_num);
			}
			
			else if (status == INPUT) {
				CLR_BIT(GPIO_DDRA, pin_num);
			}
			break;
		
		case PORTB:
			if (status == OUTPUT){
				SET_BIT(GPIO_DDRB, pin_num);
			}
			
			else if (status == INPUT) {
				CLR_BIT(GPIO_DDRB, pin_num);
			}
			break;
		
		case PORTC:
			if (status == OUTPUT){
				SET_BIT(GPIO_DDRC, pin_num);
			}
		
			else if (status == INPUT) {
				CLR_BIT(GPIO_DDRC, pin_num);
			}
			break;
		
		case PORTD:
			if (status == OUTPUT){
				SET_BIT(GPIO_DDRD, pin_num);
			}
		
			else if (status == INPUT) {
				CLR_BIT(GPIO_DDRD, pin_num);
			}
			break;
	}
}


void GPIO_voidSetPinVal(u8 port_name, u8 pin_num, u8 val)
{
	switch (port_name){
		case PORTA:
			if (val == HIGH){
				SET_BIT(GPIO_PORTA, pin_num);
			} 
		
			else if (val == LOW){
				CLR_BIT(GPIO_PORTA, pin_num);
			}
			break; 	
		
		case PORTB:
			if (val == HIGH){
				SET_BIT(GPIO_PORTB, pin_num);
			}
			
			else if (val == LOW){
				CLR_BIT(GPIO_PORTB, pin_num);
			}
			break;	
		
		case PORTC:
			if (val == HIGH){
				SET_BIT(GPIO_PORTC, pin_num);
			}
			
			else if (val == LOW){
				CLR_BIT(GPIO_PORTC, pin_num);
			}
			break;	
		
		case PORTD:
			if (val == HIGH){
				SET_BIT(GPIO_PORTD, pin_num);
			}
			
			else if (val == LOW){
				CLR_BIT(GPIO_PORTD, pin_num);
			}
			break;	
	}
}

void GPIO_voidTogPin(u8 port_name, u8 pin_num)
{
	switch (port_name){
		case PORTA:
				TOG_BIT(GPIO_PORTA, pin_num);
				break; 	
		
		case PORTB:
				TOG_BIT(GPIO_PORTB, pin_num);
				break;	
		
		case PORTC:
				TOG_BIT(GPIO_PORTC, pin_num);
				break;	
		
		case PORTD:
				TOG_BIT(GPIO_PORTD, pin_num);
				break;	
	}
}


u8 GPIO_u8ReadPin(u8 port_name, u8 pin_num)
{
	switch (port_name){
		case PORTA:
			return GET_BIT(GPIO_PINA, pin_num);	break;
		
		case PORTB:
			return GET_BIT(GPIO_PINB, pin_num);	break;
		
		case PORTC:
			return GET_BIT(GPIO_PINC, pin_num);	break;
		
		case PORTD:
			return GET_BIT(GPIO_PIND, pin_num);	break;
	}
	return 0;
}


void GPIO_voidSetPortDir(u8 port_name, u8 status)
{
	switch (port_name){
		case PORTA:
			GPIO_DDRA = status;	break;
		
		case PORTB:
			GPIO_DDRB = status;	break;
		
		case PORTC:
			GPIO_DDRC = status;	break;
		
		case PORTD:
			GPIO_DDRD = status;	break;
	}
}

void GPIO_voidSetPortVal(u8 port_name, u8 val)
{
	switch (port_name){
		case PORTA:
			GPIO_PORTA = val;	break;
		
		case PORTB:
			GPIO_PORTB = val;	break;
		
		case PORTC:
			GPIO_PORTC = val;	break;
		
		case PORTD:
			GPIO_PORTD = val;	break;
	}
}

u8 GPIO_u8ReadPort(u8 port_name)
{
	switch (port_name){
		case PORTA:
			return GPIO_PINA;	break;
		
		case PORTB:
			return GPIO_PINB;	break;
		
		case PORTC:
			return GPIO_PINC;	break;
		
		case PORTD:
			return GPIO_PIND;	break;
	}
	return 0;
}

