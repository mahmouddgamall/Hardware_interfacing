/************************************************/
/*	Author		:	Mahmoud Gamal Saad			*/
/*	Component	:	EXTI						*/
/*	Layer		:	MCAL						*/
/*	Version		:	2.0							*/
/************************************************/

#ifndef EXTI_CONFIG_H
#define EXTI_CONFIG_H


/*
 * ENABLED
 * DISABLED
 * */
#define	EXTI_u8_INT0_CONTROL			DISABLED

/*
 * ENABLED
 * DISABLED
 * */

#define	EXTI_u8_INT1_CONTROL			ENABLED

/*
 * ENABLED
 * DISABLED
 * */

#define	EXTI_u8_INT2_CONTROL			DISABLED

/*
 * 	EXTI_LOW
	EXTI_ANY_CHANGE
	EXTI_FALLING_EDGE
	EXTI_RISIGN_EDGE

 * */

#define	EXTI_u8_INT0_SENSE				EXTI_FALLING_EDGE

/*
 * 	EXTI_LOW
	EXTI_ANY_CHANGE
	EXTI_FALLING_EDGE
	EXTI_RISIGN_EDGE

 * */

#define	EXTI_u8_INT1_SENSE				EXTI_LOW

/*
 * 	EXTI_FALLING_EDGE
	EXTI_RISIGN_EDGE

 * */

#define	EXTI_u8_INT2_SENSE				EXTI_RISIGN_EDGE




#endif
