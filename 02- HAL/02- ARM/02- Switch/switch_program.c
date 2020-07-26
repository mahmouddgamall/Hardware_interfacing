#include "std_types.h"
#include "bit_math.h"

#include "DIO_interface.h"

#include"switch_interface.h"
#include "switch_config.h"

u8 getSwitchValue(u8 mySwitch)
{
	u8 value;
	if (mySwitch == 0)
	value = GetPinValue(SWITCH_Port, SWITCH_Pin_0);
	else if (mySwitch == 1)
	value = GetPinValue(SWITCH_Port, SWITCH_Pin_1);
	
	#if RELEASE_State==0
		return value;
	#else
		return value^1;
	#endif
}

