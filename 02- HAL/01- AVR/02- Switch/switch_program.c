#include "std_types.h"
#include "bit_math.h"

#include "PORT_interface.h"

#include"switch_interface.h"
#include "switch_private.h"
#include "switch_config.h"

u8 getSwitchValue(void)
{
	u8 value = getPinValue(SWITCH_Port, SWITCH_Pin);
	#if RELEASE_State==0
		return value;
	#else
		return value^1;
	#endif
}

