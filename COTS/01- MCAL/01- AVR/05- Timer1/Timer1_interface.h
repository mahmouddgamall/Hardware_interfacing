/**************************************************** 
 	 Author: Mahmoud Gamal
************************************************/
#ifndef TIMER1_INTERFACE_H
#define TIMER1_INTERFACE_H



#define		TCCR1_FAST_PWM_MODE_ICR1			0x0218


#define		TIMER1_OC1A_DISCONNECT			0x0
#define		TIMER1_OC1A_TOGGLE				0x4000
#define		TIMER1_OC1A_CLEAR				0x8000
#define		TIMER1_OC1A_SET					0xC000
#define		TIMER1_OC1B_DISCONNECT			0x0
#define		TIMER1_OC1B_TOGGLE				0x1000
#define		TIMER1_OC1B_CLEAR				0x2000
#define		TIMER1_OC1B_SET					0x3000

#define		TIMER1_CLOCK_NO_CLOCK					0b11111000				
#define		TIMER1_CLOCK_NO_PRESCHALER				1				
#define		TIMER1_CLOCK_8_PRESCHALER				2				
#define		TIMER1_CLOCK_64_PRESCHALER				3
#define		TIMER1_CLOCK_256_PRESCHALER				4
#define		TIMER1_CLOCK_1024_PRESCHALER			5	
#define		TIMER1_CLOCK_EXTERNAL_FALLING_EDGE		6		
#define		TIMER1_CLOCK_EXTERNAL_RISING_EDGE		7

#define 	TIMER1_INTERRUPT_OVF_ENABLE				1
#define 	TIMER1_INTERRUPT_CTC_ENABLE				2
#define 	TIMER1_INTERRUPT_DISABLE				0


void TIMER1_voidInit(void);

void TIMER1_voidSetCallBackOVF(void (*Copy_pfNotification)(void));
void TIMER1_voidSetCallBackCTC(void (*Copy_pfNotification)(void));

void TIMER1_voidSetPWMvalue(u16 value);

void TIMER1_voidStartTimer(void);

void TIMER1_voidStopTimer(void);


#endif
