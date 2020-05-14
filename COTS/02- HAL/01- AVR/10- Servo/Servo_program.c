/**********************************************************************************************
Author :Mohamed Ibrahem
Version:1.0
Date:7 May 2020
Description:This Source file is used to interface with the Servo module in AVR ATMega32  evaluation kit
 ***********************************************************************************************/

#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include"Timer1_interface.h"
#include "Servo_interface.h"
#include "Servo_cnfg.h"


#define ZERO_ANGLE   500

void Servo_Init()
{
	Timer1_Init();
	Timer1_Start();
	Timer1_SetPwmValue(ZERO_ANGLE);

}

void Servo_SetAngle(u8 angle)
{
	Timer1_Init()                        ;
	Timer1_Start()                       ;
	u32 Temp                             ;
	Temp = (((float)(35/3))*angle) + 500 ;
	Timer1_SetPwmValue(Temp)             ;

}

