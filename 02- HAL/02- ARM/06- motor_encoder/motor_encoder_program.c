#include "std_types.h"
#include "bit_math.h"

#include "GPIO_interface.h"

#include "motor_encoder_interface.h"
#include "motor_encoder_config.h"


u8 Encoder_u8Pass(void)
{
	u8 state=0;
	if( GPIO_u8GetPinValue(ENCODER_PORT,ENCODER_Pin) )
	{
		while( GPIO_u8GetPinValue(ENCODER_PORT,ENCODER_Pin) );
		state=1;
	}
	return state;
}
