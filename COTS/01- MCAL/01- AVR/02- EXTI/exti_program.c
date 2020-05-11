/************************************************/
/*	Author		:	Mahmoud Gamal Saad			*/
/*	Component	:	EXTI						*/
/*	Layer		:	MCAL						*/
/*	Version		:	2.0							*/
/************************************************/


#include "std_types.h"
#include "bit_math.h"
#include "exti_config.h"
#include "exti_private.h"
#include "exti_register.h"
#include "exti_interface.h"





void EXTI_voidInt(void)
{


	/********		External INT0		********/
#if EXTI_u8_INT0_SENSE == EXTI_LOW
	CLR_BIT(MCUCR,MCUCR_ISC00);
	CLR_BIT(MCUCR,MCUCR_ISC01);
#elif EXTI_u8_INT0_SENSE == EXTI_ANY_CHANGE
	SET_BIT(MCUCR,MCUCR_ISC00);
	CLR_BIT(MCUCR,MCUCR_ISC01);
#elif EXTI_u8_INT0_SENSE == EXTI_FALLING_EDGE
	CLR_BIT(MCUCR,MCUCR_ISC00);
	SET_BIT(MCUCR,MCUCR_ISC01);
#elif EXTI_u8_INT0_SENSE == EXTI_RISIGN_EDGE
	SET_BIT(MCUCR,MCUCR_ISC00);
	SET_BIT(MCUCR,MCUCR_ISC01);
#else
#error "WRONG EXTI_u8_INT0_SENSE"
#endif

#if	EXTI_u8_INT0_CONTROL == ENABLED
	SET_BIT(GICR,GICR_INT0);
#elif EXTI_u8_INT0_CONTROL == DISABLED
	CLR_BIT(GICR,GICR_INT0);
#else
#error "Wrong EXTI_u8INT0_CONTROL"
#endif



	/********		External INT1		********/
#if EXTI_u8_INT1_SENSE == EXTI_LOW
	CLR_BIT(MCUCR,MCUCR_ISC10);
	CLR_BIT(MCUCR,MCUCR_ISC11);
#elif EXTI_u8_INT1_SENSE == EXTI_ANY_CHANGE
	SET_BIT(MCUCR,MCUCR_ISC10);
	CLR_BIT(MCUCR,MCUCR_ISC11);
#elif EXTI_u8_INT1_SENSE == EXTI_FALLING_EDGE
	CLR_BIT(MCUCR,MCUCR_ISC10);
	SET_BIT(MCUCR,MCUCR_ISC11);
#elif EXTI_u8_INT1_SENSE == EXTI_RISIGN_EDGE
	SET_BIT(MCUCR,MCUCR_ISC10);
	SET_BIT(MCUCR,MCUCR_ISC11);
#else
#error "WRONG EXTI_u8_INT0_SENSE"
#endif


#if	EXTI_u8_INT1_CONTROL == ENABLED
	SET_BIT(GICR,GICR_INT1);
#elif EXTI_u8_INT0_CONTROL == DISABLED
	CLR_BIT(GICR,GICR_INT1);
#else
#error "Wrong EXTI_u8INT0_CONTROL"
#endif




	/********		External INT2		********/

#if EXTI_u8_INT2_SENSE == EXTI_FALLING_EDGE
	CLR_BIT(MCUCR,MCUCSR_ISC2);
#elif EXTI_u8_INT2_SENSE == EXTI_RISIGN_EDGE
	SET_BIT(MCUCR,MCUCSR_ISC2);
#else
#error "WRONG EXTI_u8_INT0_SENSE"
#endif

#if	EXTI_u8_INT2_CONTROL == ENABLED
	SET_BIT(GICR,GICR_INT2);
#elif EXTI_u8_INT0_CONTROL == DISABLED
	CLR_BIT(GICR,GICR_INT2);
#else
#error "Wrong EXTI_u8INT0_CONTROL"
#endif
}

ErrorStatus EXTI_errIntEnable(u8 Copy_u8Idx)
{
	ErrorStatus Local_Error = OK;

	switch(Copy_u8Idx)
	{
	case	EXTI_u8_INT0:
		SET_BIT(GICR,GICR_INT0);

		break;

	case	EXTI_u8_INT1:
		SET_BIT(GICR,GICR_INT1);

		break;

	case	EXTI_u8_INT2:
		SET_BIT(GICR,GICR_INT2);

		break;
	default:
		Local_Error = NOK;
	}

	return Local_Error;
}

ErrorStatus EXTI_errIntDisable(u8 Copy_u8Idx)
{
	ErrorStatus Local_Error = OK;

	switch(Copy_u8Idx)
	{
	case	EXTI_u8_INT0:
		CLR_BIT(GICR,GICR_INT0);

		break;

	case	EXTI_u8_INT1:
		CLR_BIT(GICR,GICR_INT1);

		break;

	case	EXTI_u8_INT2:
		CLR_BIT(GICR,GICR_INT2);

		break;
	default:
		Local_Error = NOK;
	}

	return Local_Error;
}

ErrorStatus EXTI_errSetSenseLevel(u8 Copy_u8Idx, u8 Copy_u8SenseLevel)
{
	ErrorStatus Local_Error = OK;

		switch(Copy_u8Idx)
		{
		case	EXTI_u8_INT0:
			switch(Copy_u8SenseLevel)
			{
			case	LOW_LEVEL:
				CLR_BIT(MCUCR,MCUCR_ISC00);
				CLR_BIT(MCUCR,MCUCR_ISC01);
				break;
			case	ANY_CHANGE:
				SET_BIT(MCUCR,MCUCR_ISC00);
				CLR_BIT(MCUCR,MCUCR_ISC01);
				break;
			case	FALLING_EDGE:
				CLR_BIT(MCUCR,MCUCR_ISC00);
				SET_BIT(MCUCR,MCUCR_ISC01);
				break;
			case	RISIGN_EDGE:
				SET_BIT(MCUCR,MCUCR_ISC00);
				SET_BIT(MCUCR,MCUCR_ISC01);
				break;
			default:
				Local_Error = NOK;
			}
			break;

		case	EXTI_u8_INT1:
			switch(Copy_u8SenseLevel)
					{
					case	LOW_LEVEL:
						CLR_BIT(MCUCR,MCUCR_ISC10);
						CLR_BIT(MCUCR,MCUCR_ISC11);
						break;
					case	ANY_CHANGE:
						SET_BIT(MCUCR,MCUCR_ISC10);
						CLR_BIT(MCUCR,MCUCR_ISC11);
						break;
					case	FALLING_EDGE:
						CLR_BIT(MCUCR,MCUCR_ISC10);
						SET_BIT(MCUCR,MCUCR_ISC11);
						break;
					case	RISIGN_EDGE:
						SET_BIT(MCUCR,MCUCR_ISC10);
						SET_BIT(MCUCR,MCUCR_ISC11);
						break;
					default:
						Local_Error = NOK;
					}
			break;

		case	EXTI_u8_INT2:
			switch(Copy_u8SenseLevel)
					{
					case	FALLING_EDGE:
						CLR_BIT(MCUCSR,MCUCSR_ISC2);
						break;
					case	RISIGN_EDGE:
						SET_BIT(MCUCSR,MCUCSR_ISC2);
						break;
					default:
						Local_Error = NOK;
					}
			break;
		default:
			Local_Error = NOK;
		}

		return Local_Error;
}


/*
 * Global variable to recieve the address of the function in and be able to use this address in
 * 'EXTI_errSetCallBack' as well as the ISR.
 * It is an array because I have 3 External Interrupts
 * 	*/
static void (*EXTI_pvCallBackFunc[3])(void) = {NULL, NULL, NULL};


extern ErrorStatus EXTI_errSetCallBack(u8 Copy_u8Idx, void(*Copy_pvCallBack)(void))
{
	u8 Local_Error = OK;

	if(Copy_pvCallBack != NULL)
	{
		if(Copy_u8Idx < 3)
		{
			EXTI_pvCallBackFunc[Copy_u8Idx] = Copy_pvCallBack;
		}
	}

	else
	{
		Local_Error = NULLPOINTER;
	}


	return Local_Error;
}


void __vector_1(void)
{
	if(EXTI_pvCallBackFunc[EXTI_u8_INT0] != NULL)
	{
		EXTI_pvCallBackFunc[EXTI_u8_INT0]();
	}

}

void __vector_2(void)
{
	if(EXTI_pvCallBackFunc[EXTI_u8_INT1] != NULL)
	{
		EXTI_pvCallBackFunc[EXTI_u8_INT1]();
	}

}

void __vector_3(void)
{
	if(EXTI_pvCallBackFunc[EXTI_u8_INT2] != NULL)
	{
		EXTI_pvCallBackFunc[EXTI_u8_INT2]();
	}

}
