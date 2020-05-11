#include "std_types.h"
#include "bit_math.h"
#include "NVIC_config.h"
#include "NVIC_private.h"
#include "NVIC_register.h"
#include "NVIC_interface.h"

extern void NVIC_voidInitPriority(void)
{

#define SCB_AIRCR						*((volatile u32*)0xE000ED0C)
	SCB_AIRCR = 0x05FA0500;
}

extern void NVIC_voidEnableExternalInterrupt(u8 Copy_u8Idx)
{
	if(Copy_u8Idx <= 31)
	{
		NVIC->ISER[0] = (1<<Copy_u8Idx)
	}
	else if (Copy_u8Idx <= 59)
	{
		Copy_u8Idx = Copy_u8Idx - 32;
		NVIC->ISER[1] = (1<<Copy_u8Idx)	
	}
}

extern void NVIC_voidDisableExternalInterrupt(u8 Copy_u8Idx)
{
	
	if(Copy_u8Idx <= 31)
	{
		NVIC->ICER[0] = (1<<Copy_u8Idx)
	}
	else if (Copy_u8Idx <= 59)
	{
		Copy_u8Idx = Copy_u8Idx - 32;
		NVIC->ICER[1] = (1<<Copy_u8Idx)	
	}
}


extern void NVIC_voidSetPendingFlag(u8 Copy_u8Idx)
{
	
	if(Copy_u8Idx <= 31)
	{
		NVIC->IPER[0] = (1<<Copy_u8Idx)
	}
	else if (Copy_u8Idx <= 59)
	{
		Copy_u8Idx = Copy_u8Idx - 32;
		NVIC->IPER[1] = (1<<Copy_u8Idx)	
	}
}

extern void NVIC_voidClearPendingFlag(u8 Copy_u8Idx)
{
	
	if(Copy_u8Idx <= 31)
	{
		NVIC->ICPR[0] = (1<<Copy_u8Idx)
	}
	else if (Copy_u8Idx <= 59)
	{
		Copy_u8Idx = Copy_u8Idx - 32;
		NVIC->ICPR[1] = (1<<Copy_u8Idx)	
	}
}


extern u8 NVIC_u8GetActiveFlag(u8 Copy_u8Idx)
{
	u8 Local_u8Result;
	
	if(Copy_u8Idx <= 31)
	{
		Local_u8Result = GET_BIT(NVIC->IABR[0], Copy_u8Idx)
	}
	else if (Copy_u8Idx <= 59)
	{
		Copy_u8Idx = Copy_u8Idx - 32;
		Local_u8Result = GET_BIT(NVIC->IABR[1], Copy_u8Idx)
	}
}

extern void NVIC_voidSetPriority(u8 Copy_u8Idx, u8 Copy_u8Priority)
{
		NVIC_IPR[Copy_u8Idx] = Copy_u8Priority;
}