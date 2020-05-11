/**************************************************** 
 	 Author: Mahmoud Gamal
************************************************/
#ifndef TIMER1_CONFIG_H
#define TIMER1_CONFIG_H


/***************************************
Options:
		TIMER1_NORMAL_MODE
		TIMER1_PHASE_CORRECT_PWM_MODE_8_BIT
		TIMER1_PHASE_CORRECT_PWM_MODE_9_BIT
		TIMER1_PHASE_CORRECT_PWM_MODE_10_BIT
		TIMER1_CTC_MODE
		TIMER1_FAST_PWM_MODE_8_BIT
		TIMER1_FAST_PWM_MODE_9_BIT
		TIMER1_FAST_PWM_MODE_10-_BIT
		TCCR1_FAST_PWM_MODE_ICR1

***************************************/

#define	TIMER1_MODE			TCCR1_FAST_PWM_MODE_ICR1

/***************************************
Options:
		TIMER1_CLOCK_NO_CLOCK
		TIMER1_CLOCK_NO_PRESCHALER
		TIMER1_CLOCK_8_PRESCHALER
		TIMER1_CLOCK_64_PRESCHALER
		TIMER1_CLOCK_256_PRESCHALER
		TIMER1_CLOCK_1024_PRESCHALER
		TIMER1_CLOCK_EXTERNAL_FALLING_EDGE
		TIMER1_CLOCK_EXTERNAL_RISING_EDGE

***************************************/

#define	TIMER1_CLOCK		TIMER1_CLOCK_8_PRESCHALER

/***************************************
Options:
		TIMER1_INTERRUPT_OVF_ENABLE & TIMER1_INTERRUPT_CTC_ENABLE
		TIMER1_INTERRUPT_DISABLE

***************************************/
#define	TIMER1_INTERRUPT	TIMER1_INTERRUPT_DISABLE


/***************************************
Options:


TIMER1_OC1A_DISCONNECT
TIMER1_OC1A_TOGGLE
TIMER1_OC1A_CLEAR
TIMER1_OC1A_SET
TIMER1_OC1B_DISCONNECT
TIMER1_OC1B_TOGGLE
TIMER1_OC1B_CLEAR
TIMER1_OC1B_SET


***************************************/


#define	TIMER1_OC1_MODE					TIMER1_OC1B_CLEAR

#define	TIMER1_u16_PRELOAD_VALUE			0
#define	TIMER_u32_NUMBER_OF_OVERFLOWS		5859


#define TIMER1_OCR1_VALUE					100
#define	TIMER_u32_NUMBER_OF_COMPARE_MATCH	1000

#endif