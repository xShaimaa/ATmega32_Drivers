/*********************************************************************************/
/* Author    : Shimo	                                                         */
/* Version   : V01                                                               */
/* Date      : 17 Aug 2020                                                       */
/*********************************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GPIO.h"

#include "PB_private.h"
#include "PB_config.h"
#include "PB_interface.h"


/* struct to hold the push button data */
typedef struct
{
    u8 samples[2];
    PB_State_t state;
}PB_Info_t;

/* Global variables */
PB_Info_t  PB_info ;

/* configuring Push Button as input and seting the initial states */
void PB_voidInit()
{	
	/* stting the pull configurations */
	#if (PB_INPUT_MODE == INTERNAL_PULL_UP)
		GPIO_voidSetPinDir(PB_PORT, PB_PIN, INPUT);
		GPIO_voidSetPinVal(PB_PORT, PB_PIN, HIGH);
	
	#elif (PB_INPUT_MODE == EXTERNAL_PULL_UP) || (PB_INPUT_MODE == EXTERNAL_PULL_DOWN)
		GPIO_voidSetPinDir(PB_PORT, PB_PIN, INPUT);
	#endif	
	
	/* setting the voltage configurations passed on pull type*/
	#if   (PB_INPUT_MODE == INTERNAL_PULL_UP ) || (PB_INPUT_MODE == EXTERNAL_PULL_UP )
		#define PB_PRESS_VOLT    0
		#define PB_RELEASE_VOLT  1

	#elif (PB_INPUT_MODE == EXTERNAL_PULL_DOWN)
		#define PB_PRESS_VOLT    1
		#define PB_RELEASE_VOLT  0
	#endif

	/* setting the push button initial state */
	PB_info.state = RELEASED;
}


void PB_voidUpdate(void)
{	
	/* updating the samples */
	PB_info.samples[0] = PB_info.samples[1];
	PB_info.samples[1] = GPIO_u8ReadPinVal(PB_PORT, PB_PIN);
	
	/* scanning the push button and determinig the state */
	switch(PB_info.state)
	{
		/* button is not pressed yet */
		case RELEASED:
					if((PB_info.samples[0] == PB_PRESS_VOLT) &&
				       (PB_info.samples[1] == PB_PRESS_VOLT))
					{
						PB_info.state = PRE_PRESSED;
					}
					break;
		
		/* button starts to be pressed*/
		case PRE_PRESSED:
					if(PB_info.samples[1] == PB_PRESS_VOLT)
					{
						PB_info.state = PRESSED;
					}
					break;	
		
		/* button is being pressed, but not yet released */
		case PRESSED:
					if((PB_info.samples[0] == PB_RELEASE_VOLT) &&
				       (PB_info.samples[1] == PB_RELEASE_VOLT))
					{
						PB_info.state = PRE_RELEASED;
					}
					break;
		
		/* button is pressed and released */
		case PRE_RELEASED:
					if(PB_info.samples[1] == PB_RELEASE_VOLT)
					{
						PB_info.state = RELEASED;
					}
					break;	
		
		default: 	break;
					
	}
}

/* return the push button current state */
PB_State_t PB_GetState(void)
{
	return (PB_info.state);
}
