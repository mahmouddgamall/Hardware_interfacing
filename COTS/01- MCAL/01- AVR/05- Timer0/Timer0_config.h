/**************************************************** 
 	 Author: Mahmoud Gamal
************************************************/
#ifndef TIMER0_CONFIG_H
#define TIMER0_CONFIG_H


/***************************************
Options:
		TIMER0_NORMAL_MODE
		TIMER0_PHASE_CORRECT_PWM_MODE
		TIMER0_CTC_MODE
		TIMER0_FAST_PWM_MODE

***************************************/

#define	TIMER0_MODE			TIMER0_NORMAL_MODE

/***************************************
Options:
		TIMER0_CLOCK_NO_CLOCK
		TIMER0_CLOCK_NO_PRESCHALER
		TIMER0_CLOCK_8_PRESCHALER
		TIMER0_CLOCK_64_PRESCHALER
		TIMER0_CLOCK_256_PRESCHALER
		TIMER0_CLOCK_1024_PRESCHALER
		TIMER0_CLOCK_EXTERNAL_FALLING_EDGE
		TIMER0_CLOCK_EXTERNAL_RISING_EDGE

***************************************/

#define	TIMER0_CLOCK		TIMER0_CLOCK_8_PRESCHALER

/***************************************
Options:
		TIMER0_INTERRUPT_OVF_ENABLE & TIMER0_INTERRUPT_CTC_ENABLE
		TIMER0_INTERRUPT_DISABLE

***************************************/
#define	TIMER0_INTERRUPT	TIMER0_INTERRUPT_DISABLE


/***************************************
Options:

		TIMER0_OC0_DISCONNECT
		TIMER0_OC0_TOGGLE		NOTE THAT:		this mode is not allowed in PWM or fast-PWM modes
		TIMER0_OC0_CLEAR
		TIMER0_OC0_SET

***************************************/


#define	TIMER0_OC0_MODE		TIMER0_OC0_CLEAR

/*	To get 1 sec with preschaler 8 at clock 12MHz 	*/
#define	TIMER0_u8_PRELOAD_VALUE				195
#define	TIMER_u32_NUMBER_OF_OVERFLOWS		5859


#define TIMER0_OCR0_VALUE					100
#define	TIMER_u32_NUMBER_OF_COMPARE_MATCH	1000

#endif
