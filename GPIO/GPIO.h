/*
 * GPIO.h
 *
 * Created: 03-Aug-20
 *  Author: shimo
 */
 
#ifndef GPIO_H_
#define GPIO_H_

#include "STD_TYPES.h"
#include "BIT_MATH.h"

/* register definitions */

/*PORTA registers */
#define GPIO_PORTA *((volatile u8* const) 0x3B)
#define GPIO_DDRA  *((volatile u8* const) 0x3A)
#define GPIO_PINA  *((volatile u8* const) 0x39)

/*PORTB registers */
#define GPIO_PORTB *((volatile u8* const) 0x38)
#define GPIO_DDRB  *((volatile u8* const) 0x37)
#define GPIO_PINB  *((volatile u8* const) 0x36)

/*PORTC regiters */
#define GPIO_PORTC *((volatile u8* const) 0x35)
#define GPIO_DDRC  *((volatile u8* const) 0x34)
#define GPIO_PINC  *((volatile u8* const) 0x33)

/*PORTD registers */
#define GPIO_PORTD *((volatile u8* const) 0x32)
#define GPIO_DDRD  *((volatile u8* const) 0x31)
#define GPIO_PIND  *((volatile u8* const) 0x30)

/* GPIO PORTs */
#define PORTA 0
#define PORTB 1
#define PORTC 2
#define PORTD 3

/* GPIO PINs  */
#define PIN0   0
#define PIN1   1
#define PIN2   2
#define PIN3   3
#define PIN4   4
#define PIN5   5
#define PIN6   6
#define PIN7   7
#define PIN8   8

/* GPIO Dir */
#define OUTPUT 1
#define INPUT 0

/* GPIO Vals*/
#define HIGH 1
#define LOW  0

/* public functions prototypes */

/******************************************************************************
* Description : setting the PIN Direction
* Parameters  : PORT (PORTA -> D) - PIN (PIN0 -> 8) - Status(INPUT - OUTPUT)
* Return type : void
******************************************************************************/
void GPIO_voidSetPinDir(u8 port_name, u8 pin_num, u8 status);

/******************************************************************************
* Description : setting the PIN Value
* Parameters  : PORT (PORTA -> D) - PIN (PIN0 -> 8) - Val(HIGH - LOW)
* Return type : void
******************************************************************************/
void GPIO_voidSetPinVal(u8 port_name, u8 pin_num, u8 val);

/******************************************************************************
* Description : toggling the PIN Value
* Parameters  : PORT (PORTA -> D) - PIN (PIN0 -> 8)
* Return type : void
******************************************************************************/
void GPIO_voidTogPin(u8 port_name, u8 pin_num)

/******************************************************************************
* Description : reading the PIN value
* Parameters  : PORT (PORTA -> D) - PIN (PIN0 -> 8)
* Return type : u8(pin value)
******************************************************************************/
u8 GPIO_u8ReadPin(u8 port_name, u8 pin_num);

/******************************************************************************
* Description : setting the PORT Direction
* Parameters  : PORT (PORTA -> D) - Status(INPUT - OUTPUT)
* Return type : void
******************************************************************************/
void GPIO_voidSetPortDir(u8 port_name, u8 status);

/******************************************************************************
* Description : setting the PORT Value
* Parameters  : PORT (PORTA -> D) - Val(HIGH - LOW)
* Return type : void
******************************************************************************/
void GPIO_voidSetPortVal(u8 port_name, u8 val);

/******************************************************************************
* Description : reading the PORT value
* Parameters  : PORT (PORTA -> D)
* Return type : u8(pin value)
******************************************************************************/
u8 GPIO_u8ReadPort(u8 port_name);

#endif