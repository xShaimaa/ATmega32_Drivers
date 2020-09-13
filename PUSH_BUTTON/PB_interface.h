/*********************************************************************************/
/* Author    : Shimo	                                                         */
/* Version   : V01                                                               */
/* Date      : 17 Aug 2020                                                       */
/*********************************************************************************/
#ifndef PB_INTERFACE_H
#define PB_INTERFACE_H

/* data type to hold the push button state */
typedef enum{	
		PRE_PRESSED,
		PRESSED,
		PRE_RELEASED,
		RELEASED		
}PB_State_t;


/* public functions prototypes */

/******************************************************************************
* Description : configuring a push button as input
* Parameters  : none
* Return type : void
******************************************************************************/
void PB_voidInit();

/******************************************************************************
* Description : check the state of the push button
* Parameters  : none
* Return type : void                                                                           
*******************************************************************************/
void PB_voidUpdate(void);

/******************************************************************************
* Description : check if a button is pressed
* Parameters  : none
* Return type : PB_states_t(the push button state)                                                                         
*******************************************************************************/
PB_State_t PB_GetState(void);


#endif
