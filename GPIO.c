#include "GPIO.h"

void Dio_set_port(u8_t port_name, u8_t val){
	switch (port_name){
		case 0:
			PORTA_REG = val;	break;
		case 1:
			PORTB_REG = val;	break;
		case 2:
			PORTC_REG = val;	break;
		case 3:
			PORTD_REG = val;	break;
	}
}

u8_t Dio_read_port (u8_t port_name){
	switch (port_name){
		case 0:
			return PINA_REG;	break;
		case 1:
			return PINB_REG;	break;
		case 2:
			return PINC_REG;	break;
		case 3:
			return PIND_REG;	break;
	}
	return 0;
}

void Dio_dir_port (u8_t port_name, u8_t status){
	if (status == INPUT)
	{
		status = 0x00;
	}
	else if (status == OUTPUT)
	{
		status = 0xff;
	}
	
	switch (port_name){
		case 0:
			DDRA_REG = status;	break;
		case 1:
			DDRB_REG = status;	break;
		case 2:
			DDRC_REG = status;	break;
		case 3:
			DDRD_REG = status;	break;
	}
}

void Dio_set_pin (u8_t port_name, u8_t pin_num, u8_t val){
	switch (port_name){
		case 0:
			if (val == 1){
				SET_BIT(PORTA_REG, pin_num);
			} 
			else if (val == 0) {
				CLR_BIT(PORTA_REG, pin_num);
			}
			break; 	
		case 1:
			if (val == 1){
				SET_BIT(PORTB_REG, pin_num);
			}
			else if (val == 0) {
				CLR_BIT(PORTB_REG, pin_num);
			}
			break;	
		case 2:
			if (val == 1){
				SET_BIT(PORTC_REG, pin_num);
			}
			else if (val == 0) {
				CLR_BIT(PORTC_REG, pin_num);
			}
			break;	
		case 3:
			if (val == 1){
				SET_BIT(PORTD_REG, pin_num);
			}
			else if (val == 0) {
				CLR_BIT(PORTD_REG, pin_num);
			}
			break;	
	}
}

u8_t Dio_read_pin(u8_t port_name, u8_t pin_num){
	switch (port_name){
		case 0:
			return GET_BIT(PINA_REG, pin_num);	break;
		case 1:
			return GET_BIT(PINB_REG, pin_num);	break;
		case 2:
			return GET_BIT(PINC_REG, pin_num);	break;
		case 3:
			return GET_BIT(PIND_REG, pin_num);	break;
	}
	return 0;
}

void Dio_dir_pin (u8_t port_name, u8_t pin_num, u8_t status){
	switch (port_name){
		case 0:
			if (status == 1){
				SET_BIT(DDRA_REG, pin_num);
			}
			else if (status == 0) {
				CLR_BIT(DDRA_REG, pin_num);
			}
			break;
		case 1:
			if (status == 1){
				SET_BIT(DDRB_REG, pin_num);
			}
			else if (status == 0) {
				CLR_BIT(DDRB_REG, pin_num);
			}
			break;
		case 2:
			if (status == 1){
				SET_BIT(DDRC_REG, pin_num);
			}
			else if (status == 0) {
				CLR_BIT(DDRC_REG, pin_num);
			}
			break;
		case 3:
			if (status == 1){
				SET_BIT(DDRD_REG, pin_num);
			}
			else if (status == 0) {
				CLR_BIT(DDRD_REG, pin_num);
			}
			break;
	}
}