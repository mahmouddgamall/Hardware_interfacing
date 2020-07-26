/**********************************************************************************************
Author :Mohamed Ibrahem, Mahmoud Gamal
Version:1.0
Date:13 May 2020
Description:This Header file is used to interface with the SW_ICU module in AVR ATMega32 evaluation kit
***********************************************************************************************/
#ifndef SW_ICU_INTERFACE_H
#define SW_ICU_INTERFACE_H







void SW_ICU_Init(void);
void SW_ICU_Start(void);
STD_ERROR SW_ICU_GetDutyCycle(u16 *Duty);
STD_ERROR SW_ICU_GetFreq(u16 *Freq);

#endif
