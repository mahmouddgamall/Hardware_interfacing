/**************************************************** 
 	 Author: Mahmoud Gamal
 ************************************************/
#include "std_types.h"
#include "bit_math.h"
#include "AC_config.h"
#include "AC_private.h"
#include "AC_register.h"
#include "AC_interface.h"
#include "PORT_interface.h"

ptr2func_t AC_pfPositiveIsGreater,AC_pfNegativeIsGreater ;
u8* G_value;

void AC_voidAnalogCompInit(void)
{
	ACSR &= AC_ACSR_BANDGAP_MASK;
	ACSR |= AC_POSITIVE_BANDGAP_REFERNCE_VOLTAGE;

	SFIOR &= AC_SFIOR_MULTIPLEXER_MASK;
#if AC_SFIOR_MULTIPLEXER == AC_SFIOR_MULTIPLEXER_DISABLE

#elif AC_SFIOR_MULTIPLEXER == AC_SFIOR_MULTIPLEXER_ENABLE
	SFIOR | = AC_SFIOR_MULTIPLEXER_ENABLE;
	ADMUX &= ADMUX_MASK;
	ADMUX |= AC_NEGATIVE_CHANNLE;
#endif

	ACSR &= AC_ACSR_INPUT_CAPTURE_MASK;
	ACSR |= AC_INTERRUPT_STATUS;

	ACSR &= AC_ACSR_INTERRUP_MODE_MASK;
	ACSR |= AC_INTERRUPT_MODE;

	ACSR &= AC_ACSR_INTERRUPT_MASK;
	ACSR |= AC_INTERRUPT_STATUS;
}

u8 AC_u8GetOutputValueSync(u8 * Output)
{
	u8 error = E_OK;
	if(ACSR & AC_ACSR_ACO)
	{
		*Output = AC_POSITIVE_IS_GREATER;
	}
	else
	{
		*Output = AC_NEGATIVE_IS_GREATER;

	}
	return error;
}
u8 AC_u8GetOutputValueAsync(u8 * Output, ptr2func_t cbfPositGretNegat, ptr2func_t cbfNegatGretPosit)
{
	u8 error = E_NOT_OK;
	if(cbfPositGretNegat)
	{
		if(cbfNegatGretPosit)
		{
			error = E_OK;
			AC_pfNegativeIsGreater = cbfNegatGretPosit;
			AC_pfPositiveIsGreater = cbfPositGretNegat;
			G_value = Output;
		}

	}
	return error;
}

void AC_voidDisable(void)
{
	ACSR |= AC_ACSR_DISABLE_PERIPHERAL;
}

void __vector_18(void)	__attribute__((signal));
void __vector_18(void)
{
	static u8 flag = 0;
	if (flag == 0)
	{
		flag = 1;
		DIO_voidSetPinValue('A',1,0);
	}
	if (flag == 1)
	{
		flag = 0;
		DIO_voidSetPinValue('A',1,1);
	}
#if		AC_INTERRUPT_MODE == AC_ACSR_INTERRUPT_ON_FALLING_EDGE
	if(AC_pfNegativeIsGreater)	AC_pfNegativeIsGreater();
#elif	AC_INTERRUPT_MODE == AC_ACSR_INTERRUPT_ON_RISING_EDGE
	if(AC_pfPositiveIsGreater)	AC_pfPositiveIsGreater();
#elif	AC_INTERRUPT_MODE == AC_ACSR_INTERRUPT_ON_TOGGLE
	if((ACSR & AC_ACSR_ACO) == AC_POSITIVE_IS_GREATER)
	{
		if(AC_pfPositiveIsGreater)	AC_pfPositiveIsGreater();
		*G_value = AC_POSITIVE_IS_GREATER;
	}
	else if ((ACSR & AC_ACSR_ACO) == AC_NEGATIVE_IS_GREATER)
	{
		if(AC_pfNegativeIsGreater)	AC_pfNegativeIsGreater();
		*G_value = AC_NEGATIVE_IS_GREATER;
	}
#endif
}
