/************************************************************************************
	Authour		: Mahmoud Gamal Saad
	note that	:	This driver will not work with unipolar stepper motors as it has
					ver different mechanism. most uinpolar stepper motors have 
					motor drivers that make them easier to program, and the one that 
					you might have may work with this mechanise. Please chech your 
					datasheet and make sure that the sequence needed to control 
					your motor is just to switch on one of four coils at a time 
					sequentially. If so, then this driver will work with your stepper
					motor and/or motor driver. If you need any changes please contact
					the author at mahmouddgamall93@gmail.com
*************************************************************************************/

#include "std_types.h"
#include "bit_math.h"

#include "PORT_interface.h"

#include "STEPPERMotor_config.h"
#include "STEPPERMotor_interface.h"

static u8 GS_u8Steps[]={0b1000,0b0100,0b0010,0b0001};

void STEPPERMOTOR_voidRotateMotorRight(void)
{
	for(int step = 0; step < 4 ; step ++)
	{

		setPinValue(STEPPER_MOTOR_Port,STEPPER_MOTOR_PIN_A,0);
		setPinValue(STEPPER_MOTOR_Port,STEPPER_MOTOR_PIN_B,0);
		setPinValue(STEPPER_MOTOR_Port,STEPPER_MOTOR_PIN_C,0);
		setPinValue(STEPPER_MOTOR_Port,STEPPER_MOTOR_PIN_D,0);
		/*	the stepper motor has 4 coils
			to make rotate you should enable only one at a time in the correct order
			which means that:
			1st step => coil 1 = 1
						coil 2 = 0
						coil 3 = 0
						coil 4 = 0
			2nd step => coil 1 = 0
						coil 2 = 1
						coil 3 = 0
						coil 4 = 0
			and so on. Therefore, those values are put in an array and each coil is enabled at each iteration of the for loop


			*/
		setPinValue(STEPPER_MOTOR_Port,STEPPER_MOTOR_PIN_A,GET_BIT(GS_u8Steps[step],0));
		setPinValue(STEPPER_MOTOR_Port,STEPPER_MOTOR_PIN_B,GET_BIT(GS_u8Steps[step],1));
		setPinValue(STEPPER_MOTOR_Port,STEPPER_MOTOR_PIN_C,GET_BIT(GS_u8Steps[step],2));
		setPinValue(STEPPER_MOTOR_Port,STEPPER_MOTOR_PIN_D,GET_BIT(GS_u8Steps[step],3));
	}

}

void STEPPERMOTOR_voidRotateMotorLeft(void)
{
	for(int step = 0; step < 4 ; step ++)
	{
		
		setPinValue(STEPPER_MOTOR_Port,STEPPER_MOTOR_PIN_A,0);
		setPinValue(STEPPER_MOTOR_Port,STEPPER_MOTOR_PIN_B,0);
		setPinValue(STEPPER_MOTOR_Port,STEPPER_MOTOR_PIN_C,0);
		setPinValue(STEPPER_MOTOR_Port,STEPPER_MOTOR_PIN_D,0);

		/*
			the left rotation is very similar to the right rotation in terms of the mechanism used to 
			make the motor rotate. The only difference is that the sequence in reversed.

			1st step => coil 1 = 0
						coil 2 = 0
						coil 3 = 0
						coil 4 = 1
			2nd step => coil 1 = 0
						coil 2 = 0
						coil 3 = 1
						coil 4 = 0
			and so on.
		*/

		setPinValue(STEPPER_MOTOR_Port,STEPPER_MOTOR_PIN_A,GET_BIT(GS_u8Steps[step],3));
		setPinValue(STEPPER_MOTOR_Port,STEPPER_MOTOR_PIN_B,GET_BIT(GS_u8Steps[step],2));
		setPinValue(STEPPER_MOTOR_Port,STEPPER_MOTOR_PIN_C,GET_BIT(GS_u8Steps[step],1));
		setPinValue(STEPPER_MOTOR_Port,STEPPER_MOTOR_PIN_D,GET_BIT(GS_u8Steps[step],0));
	}
}

void STEPPERMOTOR_voidStop(void)
{
	setPinValue(STEPPER_MOTOR_Port,STEPPER_MOTOR_PIN_A,0);
	setPinValue(STEPPER_MOTOR_Port,STEPPER_MOTOR_PIN_B,0);
	setPinValue(STEPPER_MOTOR_Port,STEPPER_MOTOR_PIN_C,0);
	setPinValue(STEPPER_MOTOR_Port,STEPPER_MOTOR_PIN_D,0);
}

