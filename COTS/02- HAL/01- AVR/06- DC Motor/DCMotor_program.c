#include "std_types.h"
#include "bit_math.h"

#include "PORT_interface.h"

#include"DCMOTOR_interface.h"
#include "DCMOTOR_config.h"


void DCMOTOR_voidRotateMotorRight(void)
{
		setPinValue(DCMOTOR_Port,DCMOTOR_LEFTLEG_PIN,1);
		setPinValue(DCMOTOR_Port,DCMOTOR_RIGHTLEG_PIN,0);
}

void DCMOTOR_voidRotateMotorLeft(void)
{
	setPinValue(DCMOTOR_Port,DCMOTOR_LEFTLEG_PIN,0);
	setPinValue(DCMOTOR_Port,DCMOTOR_RIGHTLEG_PIN,1);
}

void DCMOTOR_voidStop(void)
{
	setPinValue(DCMOTOR_Port,DCMOTOR_LEFTLEG_PIN,0);
	setPinValue(DCMOTOR_Port,DCMOTOR_RIGHTLEG_PIN,0);	
}