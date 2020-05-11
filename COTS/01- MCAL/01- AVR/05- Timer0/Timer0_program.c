/**************************************************** 
 	 Author: Mahmoud Gamal
 ************************************************/
#include "std_types.h"
#include "bit_math.h"
#include "PORT_interface.h"
#include "Timer0_interface.h"
#include "Timer0_config.h"
#include "Timer0_private.h"
#include "Timer0_register.h"

static void (*TIMER_pfNotificationOVF)(void);
static void (*TIMER_pfNotificationCTC)(void);


void TIMER0_voidInit(void)
{
	/*	choose mode: 	*/
	TCCR0 &= TCCR0_MODE_MASK;
	TCCR0 |= TIMER0_MODE;

	OCR0 = TIMER0_OCR0_VALUE;

	/*	choose clear OC0 on compare match	*/

	TCCR0 &= TIMER0_OC0_MASK;
	TCCR0 |= TIMER0_OC0_MODE;

	/*	Enable interrupt	*/
	TIMSK &= TIMER0_INTERRUPT_MASK;
	TIMSK |= TIMER0_INTERRUPT;
	/*	SET PRELOAD VALUE	*/
	TCNT0 = TIMER0_u8_PRELOAD_VALUE;

}

void TIMER0_voidSetCallBackOVF(void (*Copy_pfNotification)(void))
{
	if(Copy_pfNotification)
	{

		TIMER_pfNotificationOVF = Copy_pfNotification;
	}
}

void TIMER0_voidSetCallBackCTC(void (*Copy_pfNotification)(void))
{
	if(Copy_pfNotification)
	{
		TIMER_pfNotificationCTC = Copy_pfNotification;
	}
}


void TIMER0_voidStartTimer(void)
{
	TCCR0 &= TIMER0_CLOCK_NO_CLOCK;
	TCCR0 |= TIMER0_CLOCK;
}


void TIMER0_voidStopTimer(void)
{
	TCCR0 &= TIMER0_CLOCK_NO_CLOCK;
}


void __vector_11(void)__attribute__((signal,used));

void __vector_11 (void)
{
	static u32 counter =  0;
	counter++;
	if(counter == TIMER_u32_NUMBER_OF_OVERFLOWS)
	{
		counter = 0;
		TCNT0= TIMER0_u8_PRELOAD_VALUE;
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
