/**********************************************************************************************
Author :Mohamed Ibrahem 
Version:1.0
Date:7 May 2020
Description:This Header file is used to interface with the Servo module in AVR ATMega32 evaluation kit
***********************************************************************************************/
#ifndef Servo_INTERFACE_H
#define Servo_INTERFACE_H


/* configuration for Timer1 				           */

/*
#define CLK_SELECT                    T1_CLK_PRESCALLER8

#define MODE_OC1A                     CLEAR_OC1A_ON_COMPARE_MATCH_SET_TOP

#define MODE_OC1B                     CLEAR_OC1B_ON_COMPARE_MATCH_SET_TOP

#define T1_WAVE_GENERATION            T1_WG_FAST_PWM_ICR1_TOP

#define OC1B_VALUE                     999

#define PRE_LOAD_VALUE                  0



#define ICR1_VALUE				       19999

#define NUM_OVER_FLOW                  0
#define NUM_COMPARE_MATCH_A            0
#define NUM_COMPARE_MATCH_B            0

*/


void Servo_Init();
void Servo_SetAngle(u8 angle);

#endif
