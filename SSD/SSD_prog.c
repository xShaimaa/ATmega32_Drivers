/*********************************************************************************/
/* Author    : Shimo	                                                         */
/* Version   : V01                                                               */
/* Date      : 13 Aug 2020                                                       */
/*********************************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GPIO_interface.h"

#include "SSD_config.h"
#include "SSD_interface.h"

/* Global variables */
u8 SSD[10]		= {0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x6F};
u8 SSD_Pins[7]  = {SSD_A, SSD_B, SSD_C, SSD_D, SSD_E, SSD_F, SSD_G};
u8 i = 0;

/* initializing the SSD as output */
void SSD_voidInit()
{
	/* setting the SSD pins as output, and setting the initial value as low */
	for(i = 0; i<8; i++)
	{
		GPIO_voidSetPortDir(SSD_PORT,  OUTPUT);
		GPIO_voidSetPortVal(SSD_PORT, SSD_COM);
	}
}

/* displaying a number on an SSD */
void SSD_voidDisplay(u8 Copy_u8Num)
{
	#if (SSD_COM == COM_CATHOD)
		GPIO_voidSetPortVal(SSD_PORT,  SSD[Copy_u8Num]);

	#elif (SSD_COM == COM_ANOD)
		GPIO_voidSetPortVal(SSD_PORT,~(SSD[Copy_u8Num]));

	#endif
}
