/**************************************************** 
 	 Author: Mahmoud Gamal
************************************************/
#ifndef TIMER0_INTERFACE_H
#define TIMER0_INTERFACE_H

#define		TIMER0_NORMAL_MODE				0
#define		TIMER0_PHASE_CORRECT_PWM_MODE	0b01000000
#define		TIMER0_CTC_MODE					0b00001000
#define		TIMER0_FAST_PWM_MODE			0b01001000

#define		TIMER0_OC0_DISCONNECT			0
#define		TIMER0_OC0_TOGGLE				0b00010000
#define		TIMER0_OC0_CLEAR				0b00100000
#define		TIMER0_OC0_SET					0b00110000

#define		TIMER0_CLOCK_NO_CLOCK					0b11111000				
#define		TIMER0_CLOCK_NO_PRESCHALER				1				
#define		TIMER0_CLOCK_8_PRESCHALER				2				
#define		TIMER0_CLOCK_64_PRESCHALER				3
#define		TIMER0_CLOCK_256_PRESCHALER				4
#define		TIMER0_CLOCK_1024_PRESCHALER			5	
#define		TIMER0_CLOCK_EXTERNAL_FALLING_EDGE		6		
#define		TIMER0_CLOCK_EXTERNAL_RISING_EDGE		7

#define 	TIMER0_INTERRUPT_OVF_ENABLE				1
#define 	TIMER0_INTERRUPT_CTC_ENABLE				2
#define 	TIMER0_INTERRUPT_DISABLE				0


void TIMER0_voidInit(void);

void TIMER0_voidSetCallBackOVF(void (*Copy_pfNotification)(void));
void TIMER0_voidSetCallBackCTC(void (*Copy_pfNotification)(void));

void TIMER0_voidStartTimer(void);

void TIMER0_voidStopTimer(void);


#endif
