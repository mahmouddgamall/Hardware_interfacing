/**********************************************************************************************
Author :Mohamed Ibrahem, Mahmoud Gamal
Version:1.0
Date:13 May 2020
Description:This Source file is used to interface with the SW_ICU module in AVR ATMega32  evaluation kit
 ***********************************************************************************************/
#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include "exti_interfac.h"
#include"Timer1_interface.h"
#include "SW_ICU_interface.h"
#include "SW_ICU_private.h"
#include "SW_ICU_cnfg.h"


volatile u16 AllPeriod  = 0;
volatile u16 OffTime = 0;

static void SW_ICU_DEI_CBF(void);


void SW_ICU_Init( void )
{
	Timer1_Init();
	EXTI_errIntEnable(DEI_CHANNEL,SW_ICU_DEI_CBF);
	EXTI_errSetSenseLevel(DEI_CHANNEL,RISIGN_EDGE);

}

void SW_ICU_Start(void)
{
	EXTI_errIntEnable(DEI_CHANNEL);
	Timer1_Start();
}
STD_ERROR SW_ICU_GetDutyCycle(u16 *CopyDuty)
{
	STD_ERROR LocalError = OK;
	if (CopyDuty)
	{
		*CopyDuty= (((AllPeriod-OffTime)*100)/(AllPeriod));
	}
	else
	{
		LocalError = NULL_POINTER ;
	}
	return LocalError ;
}

STD_ERROR SW_ICU_GetFreq(u16 *Freq)
{
	STD_ERROR LocalError = OK;
	if (Freq)
	{
		u32 temp = Timer1_GetTimerSpeed();
		temp/= (AllPeriod)     ;
		*Freq = (u16)temp;
	}
	else
	{
		LocalError = NULL_POINTER ;
	}
	return LocalError ;
}



static void SW_ICU_DEI_CBF(void)
{
	static flag = 0 ;

	if (flag == 0 )
	{
		OffTime = Timer1_GetTimerCount();
		EXTI_errSetSenseLevel(DEI_CHANNEL,FALLING_EDGE);
		flag = 1 ;
	}
	else if (flag == 1)
	{
		AllPeriod = Timer1_GetTimerCount();
		Timer1_ClearCounter();

		EXTI_errSetSenseLevel(DEI_CHANNEL,RISIGN_EDGE);
		flag = 0 ;
	}
}
