#include "std_types.h"
#include "bit_math.h"

#include "PORT_interface.h"

#include"LED_interface.h"
#include "LED_private.h"
#include "LED_config.h"

void setLedOn(void)
{
	setPinValue(LED_Port, LED_Pin, LED_Mode);
}

void SetLedOff(void)
{
	setPinValue(LED_Port, LED_Pin, LED_Mode^1);
}
