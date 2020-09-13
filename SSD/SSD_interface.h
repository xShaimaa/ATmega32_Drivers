/*********************************************************************************/
/* Author    : Shimo	                                                         */
/* Version   : V01                                                               */
/* Date      : 13 Aug 2020                                                       */
/*********************************************************************************/
#ifndef SSD_INTERFACE_H
#define SSD_INTERFACE_H

/* SSD Common types */
#define COM_ANOD    0
#define COM_CATHOD  1

/* public functions prototypes */

/******************************************************************************
* Description : configuring an SSD as output
* Parameters  : none
* Return type : void
******************************************************************************/
void SSD_voidInit();

/******************************************************************************
* Description : Displaying a number on the SSD
* Parameters  : num (0 -> 9)
* Return type : void                                                                           
******************************************************************************/
void SSD_voidDisplay(u8 Copy_u8Num);


#endif
