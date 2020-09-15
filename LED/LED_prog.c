/*********************************************************************************/
/* Author    : Shimo	                                                         */
/* Version   : V01                                                               */
/* Date      : 13 Aug 2020                                                       */
/*********************************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GPIO.h"

#include "LED_private.h"
#include "LED_config.h"
#include "LED_interface.h"

/* configuring an LED as output */
void LED_voidInit(u8 Copy_u8PORT, u8 Copy_u8PIN)
{
	/* setting the pin as output */
	GPIO_voidSetPinDir(Copy_u8PORT, Copy_u8PIN, OUTPUT);
	
	/* setting the initial value as LOW */
	GPIO_VoidSetPinVal(Copy_u8PORT, Copy_u8PIN, LOW);
}

/* control the state of an LED */
void LED_voidLEDVal(u8 Copy_u8PORT, u8 Copy_u8PIN, u8 Copy_u8Val)
{
	switch(Copy_u8Val)
	{
		case LED_ON : 	GPIO_voidSetPinVal(Copy_u8PORT, Copy_u8PIN, LED_MODE);		break;
		
		case LED_OFF: 	GPIO_voidSetPinVal(Copy_u8PORT, Copy_u8PIN, ~(LED_MODE));	break;
		
		case LED_TOG: 	GPIO_voidTogPin(Copy_u8PORT, Copy_u8PIN);					break;
		
		default 	:	 															break;
	}
}
