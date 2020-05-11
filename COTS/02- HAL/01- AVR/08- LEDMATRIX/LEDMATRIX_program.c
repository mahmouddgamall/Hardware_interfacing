#include "std_types.h"
#include "bit_math.h"
#include "Delay_interface.h"

#include "PORT_interface.h"

#include "LEDMATRIX_config.h"
#include "LEDMATRIX_interface.h"
#include "LEDMATRIX_private.h"
#include "util/delay.h"



extern void LEDMATRIX_voidWriteChar (u8 * Copy_u8Data, u8 Copy_u8Color)
{
	u8 i=0;

	for( i = 0 ; i < 8 ; i++ )
	{
		setPort(LEDMATRIX_R0_PORT);
		setPinValue(LEDMATRIX_R0_PORT,i,0);

		if( Copy_u8Color == LEDMATRIX_YELLOW )
		{
			setPinValue(LEDMATRIX_C0_YELLOW_PORT,LEDMATRIX_C0_YELLOW_PIN,GET_BIT(Copy_u8Data[i],0));
			setPinValue(LEDMATRIX_C1_YELLOW_PORT,LEDMATRIX_C1_YELLOW_PIN,GET_BIT(Copy_u8Data[i],1));
			setPinValue(LEDMATRIX_C2_YELLOW_PORT,LEDMATRIX_C2_YELLOW_PIN,GET_BIT(Copy_u8Data[i],2));
			setPinValue(LEDMATRIX_C3_YELLOW_PORT,LEDMATRIX_C3_YELLOW_PIN,GET_BIT(Copy_u8Data[i],3));
			setPinValue(LEDMATRIX_C4_YELLOW_PORT,LEDMATRIX_C4_YELLOW_PIN,GET_BIT(Copy_u8Data[i],4));
			setPinValue(LEDMATRIX_C5_YELLOW_PORT,LEDMATRIX_C5_YELLOW_PIN,GET_BIT(Copy_u8Data[i],5));
			setPinValue(LEDMATRIX_C6_YELLOW_PORT,LEDMATRIX_C6_YELLOW_PIN,GET_BIT(Copy_u8Data[i],6));
			setPinValue(LEDMATRIX_C7_YELLOW_PORT,LEDMATRIX_C7_YELLOW_PIN,GET_BIT(Copy_u8Data[i],7));

		}
		else if( Copy_u8Color == LEDMATRIX_RED )
		{
			setPinValue(LEDMATRIX_C0_RED_PORT,LEDMATRIX_C0_RED_PIN,GET_BIT(Copy_u8Data[i],0));
			setPinValue(LEDMATRIX_C1_RED_PORT,LEDMATRIX_C1_RED_PIN,GET_BIT(Copy_u8Data[i],1));
			setPinValue(LEDMATRIX_C2_RED_PORT,LEDMATRIX_C2_RED_PIN,GET_BIT(Copy_u8Data[i],2));
			setPinValue(LEDMATRIX_C3_RED_PORT,LEDMATRIX_C3_RED_PIN,GET_BIT(Copy_u8Data[i],3));
			setPinValue(LEDMATRIX_C4_RED_PORT,LEDMATRIX_C4_RED_PIN,GET_BIT(Copy_u8Data[i],4));
			setPinValue(LEDMATRIX_C5_RED_PORT,LEDMATRIX_C5_RED_PIN,GET_BIT(Copy_u8Data[i],5));
			setPinValue(LEDMATRIX_C6_RED_PORT,LEDMATRIX_C6_RED_PIN,GET_BIT(Copy_u8Data[i],6));
			setPinValue(LEDMATRIX_C7_RED_PORT,LEDMATRIX_C7_RED_PIN,GET_BIT(Copy_u8Data[i],7));

		}
		else if( Copy_u8Color == LEDMATRIX_ORANGE )
		{
			setPinValue(LEDMATRIX_C0_RED_PORT,LEDMATRIX_C0_RED_PIN,GET_BIT(Copy_u8Data[i],0));
			setPinValue(LEDMATRIX_C1_RED_PORT,LEDMATRIX_C1_RED_PIN,GET_BIT(Copy_u8Data[i],1));
			setPinValue(LEDMATRIX_C2_RED_PORT,LEDMATRIX_C2_RED_PIN,GET_BIT(Copy_u8Data[i],2));
			setPinValue(LEDMATRIX_C3_RED_PORT,LEDMATRIX_C3_RED_PIN,GET_BIT(Copy_u8Data[i],3));
			setPinValue(LEDMATRIX_C4_RED_PORT,LEDMATRIX_C4_RED_PIN,GET_BIT(Copy_u8Data[i],4));
			setPinValue(LEDMATRIX_C5_RED_PORT,LEDMATRIX_C5_RED_PIN,GET_BIT(Copy_u8Data[i],5));
			setPinValue(LEDMATRIX_C6_RED_PORT,LEDMATRIX_C6_RED_PIN,GET_BIT(Copy_u8Data[i],6));
			setPinValue(LEDMATRIX_C7_RED_PORT,LEDMATRIX_C7_RED_PIN,GET_BIT(Copy_u8Data[i],7));
			setPinValue(LEDMATRIX_C0_YELLOW_PORT,LEDMATRIX_C0_YELLOW_PIN,GET_BIT(Copy_u8Data[i],0));
			setPinValue(LEDMATRIX_C1_YELLOW_PORT,LEDMATRIX_C1_YELLOW_PIN,GET_BIT(Copy_u8Data[i],1));
			setPinValue(LEDMATRIX_C2_YELLOW_PORT,LEDMATRIX_C2_YELLOW_PIN,GET_BIT(Copy_u8Data[i],2));
			setPinValue(LEDMATRIX_C3_YELLOW_PORT,LEDMATRIX_C3_YELLOW_PIN,GET_BIT(Copy_u8Data[i],3));
			setPinValue(LEDMATRIX_C4_YELLOW_PORT,LEDMATRIX_C4_YELLOW_PIN,GET_BIT(Copy_u8Data[i],4));
			setPinValue(LEDMATRIX_C5_YELLOW_PORT,LEDMATRIX_C5_YELLOW_PIN,GET_BIT(Copy_u8Data[i],5));
			setPinValue(LEDMATRIX_C6_YELLOW_PORT,LEDMATRIX_C6_YELLOW_PIN,GET_BIT(Copy_u8Data[i],6));
			setPinValue(LEDMATRIX_C7_YELLOW_PORT,LEDMATRIX_C7_YELLOW_PIN,GET_BIT(Copy_u8Data[i],7));
		}
		else
		{
			//standard erro should be added ya 7aywan
		}

		_delay_us(1000);
	}
}
