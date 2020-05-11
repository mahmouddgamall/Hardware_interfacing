#include "std_types.h"
#include "bit_math.h"

#include "PORT_interface.h"

#include "STEPPERMotor_config.h"
#include "STEPPERMotor_interface.h"

static u8 GS_u8Steps[]={0b1000,0b0100,0b0010,0b0001};

void STEPPERMOTOR_voidRotateMotorRight(u8 In_u8STep)
{
	setPinValue(STEPPER_MOTOR_Port,STEPPER_MOTOR_PIN_A,0);
	setPinValue(STEPPER_MOTOR_Port,STEPPER_MOTOR_PIN_B,0);
	setPinValue(STEPPER_MOTOR_Port,STEPPER_MOTOR_PIN_C,0);
	setPinValue(STEPPER_MOTOR_Port,STEPPER_MOTOR_PIN_D,0);

	setPinValue(STEPPER_MOTOR_Port,STEPPER_MOTOR_PIN_A,GET_BIT(GS_u8Steps[In_u8STep],0));
	setPinValue(STEPPER_MOTOR_Port,STEPPER_MOTOR_PIN_B,GET_BIT(GS_u8Steps[In_u8STep],1));
	setPinValue(STEPPER_MOTOR_Port,STEPPER_MOTOR_PIN_C,GET_BIT(GS_u8Steps[In_u8STep],2));
	setPinValue(STEPPER_MOTOR_Port,STEPPER_MOTOR_PIN_D,GET_BIT(GS_u8Steps[In_u8STep],3));

}

void STEPPERMOTOR_voidRotateMotorLeft(u8 In_u8STep)
{
	setPinValue(STEPPER_MOTOR_Port,STEPPER_MOTOR_PIN_A,0);
	setPinValue(STEPPER_MOTOR_Port,STEPPER_MOTOR_PIN_B,0);
	setPinValue(STEPPER_MOTOR_Port,STEPPER_MOTOR_PIN_C,0);
	setPinValue(STEPPER_MOTOR_Port,STEPPER_MOTOR_PIN_D,0);

	setPinValue(STEPPER_MOTOR_Port,STEPPER_MOTOR_PIN_A,GET_BIT(GS_u8Steps[In_u8STep],3));
	setPinValue(STEPPER_MOTOR_Port,STEPPER_MOTOR_PIN_B,GET_BIT(GS_u8Steps[In_u8STep],2));
	setPinValue(STEPPER_MOTOR_Port,STEPPER_MOTOR_PIN_C,GET_BIT(GS_u8Steps[In_u8STep],1));
	setPinValue(STEPPER_MOTOR_Port,STEPPER_MOTOR_PIN_D,GET_BIT(GS_u8Steps[In_u8STep],0));
}

void STEPPERMOTOR_voidStop(void)
{
	setPinValue(STEPPER_MOTOR_Port,STEPPER_MOTOR_PIN_A,0);
	setPinValue(STEPPER_MOTOR_Port,STEPPER_MOTOR_PIN_B,0);
	setPinValue(STEPPER_MOTOR_Port,STEPPER_MOTOR_PIN_C,0);
	setPinValue(STEPPER_MOTOR_Port,STEPPER_MOTOR_PIN_D,0);
}

