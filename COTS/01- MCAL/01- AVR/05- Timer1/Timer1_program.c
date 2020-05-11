/**************************************************** 
 	 Author: Mahmoud Gamal
 ************************************************/
#include "std_types.h"
#include "bit_math.h"
#include "PORT_interface.h"
#include "TIMER1_interface.h"
#include "TIMER1_config.h"
#include "TIMER1_private.h"
#include "TIMER1_register.h"

static void (*TIMER_pfNotificationOVF)(void);
static void (*TIMER_pfNotificationCTC)(void);


void TIMER1_voidInit(void)
{
	/*	choose mode: 	*/
	TCCR1 &= TCCR0_MODE_MASK;
	TCCR1 |= TIMER1_MODE;


	/*	choose clear OC1 on compare match	*/

	TCCR1 &= TIMER1_OC0_MASK;
	TCCR1 |= TIMER1_OC0_MODE;

	/*	Enable interrupt	*/
	TIMSK &= TIMER1_INTERRUPT_MASK;
	TIMSK |= TIMER1_INTERRUPT;
	/*	SET PRELOAD VALUE	*/
	TCNT1 = TIMER1_u8_PRELOAD_VALUE;

	ICR1 = 75;

}

void TIMER1_voidSetCallBackOVF(void (*Copy_pfNotification)(void))
{
	if(Copy_pfNotification)
	{

		TIMER_pfNotificationOVF = Copy_pfNotification;
	}
}

void TIMER1_voidSetCallBackCTC(void (*Copy_pfNotification)(void))
{
	if(Copy_pfNotification)
	{
		TIMER_pfNotificationCTC = Copy_pfNotification;
	}
}

void TIMER1_voidSetPWMvalue(u16 value)
{
	OCR1B = value;
}


void TIMER1_voidStartTimer(void)
{
	TCCR1 &= TIMER1_CLOCK_NO_CLOCK;
	TCCR1 |= TIMER1_CLOCK;
}


void TIMER1_voidStopTimer(void)
{
	TCCR1 &= TIMER1_CLOCK_NO_CLOCK;
}

#if 0

void __vector_11(void)__attribute__((signal,used));

void __vector_11 (void)
{
	static u32 counter =  0;
	counter++;
	if(counter == TIMER_u32_NUMBER_OF_OVERFLOWS)
	{
		counter = 0;
		TCNT0= TIMER1_u8_PRELOAD_VALUE;
		if(TIMER_pfNotificationOVF)
		{
			TIMER_pfNotificationOVF();
		}
	}
}

void __vector_10(void)__attribute__((signal,used));

void __vector_10 (void)
{
	static u32 counter =  0;
	counter++;

	if(counter == TIMER_u32_NUMBER_OF_COMPARE_MATCH)
	{
		counter = 0;
		if(TIMER_pfNotificationCTC)
		{
			TIMER_pfNotificationCTC();
		}
	}
}
#endif