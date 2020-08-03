#ifndef GPIO_H_
#define GPIO_H_

#include "STD_TYPES.h"
#include "BIT_MATH.h"

//PORTA registers
#define PORTA_REG *((volatile u8_t* const) 0x3B)
#define DDRA_REG  *((volatile u8_t* const) 0x3A)
#define PINA_REG  *((volatile u8_t* const) 0x39)
//PORTB registers
#define PORTB_REG *((volatile u8_t* const) 0x38)
#define DDRB_REG  *((volatile u8_t* const) 0x37)
#define PINB_REG  *((volatile u8_t* const) 0x36)
//PORTC regiters
#define PORTC_REG *((volatile u8_t* const) 0x35)
#define DDRC_REG  *((volatile u8_t* const) 0x34)
#define PINC_REG  *((volatile u8_t* const) 0x33)
//PORTD registers
#define PORTD_REG *((volatile u8_t* const) 0x32)
#define DDRD_REG  *((volatile u8_t* const) 0x31)
#define PIND_REG  *((volatile u8_t* const) 0x30)

#define PORTA 0
#define PORTB 1
#define PORTC 2
#define PORTD 3

#define OUTPUT 1
#define INPUT 0

#define HIGH 1
#define LOW  0

//functions prototype
//PORTs function
void Dio_set_port(u8_t port_name, u8_t val);
u8_t Dio_read_port (u8_t port_name);
void Dio_dir_port (u8_t port_name, u8_t status);
//pins functions
void Dio_set_pin (u8_t port_name, u8_t pin_num, u8_t val);
u8_t Dio_read_pin(u8_t port_name, u8_t pin_num);
void Dio_dir_pin (u8_t port_name, u8_t pin_num, u8_t status);

#endif