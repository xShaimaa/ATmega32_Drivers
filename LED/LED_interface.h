/*********************************************************************************/
/* Author    : Shimo	                                                          */
/* Version   : V01                                                               */
/* Date      : 13 Aug 2020                                                       */
/*********************************************************************************/
#ifndef LED_INTERFACE_H
#define LED_INTERFACE_H

/* LED values */
#define LED_OFF	0
#define LED_ON	1
#define LED_TOG 2

/* public functions prototypes */

/******************************************************************************
* Description : configuring an LED as output
* Parameters  : none
* Return type : void
******************************************************************************/
void LED_voidInit(u8 Copy_u8PORT, u8 Copy_u8PIN);

/******************************************************************************
* Description : control the state of an LED
* Parameters  : PORT number (PORTA -> D), PIN number(PIN0 -> 8), Val(LED_ON, LED_OFF, LED_TOG)
* Return type : void                                                                           
*******************************************************************************/
void LED_voidLEDVal(u8 Copy_u8PORT, u8 Copy_u8PIN, u8 Copy_u8Val);

#endif
