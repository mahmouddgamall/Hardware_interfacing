/************************************************/
/*	Author		:	Mahmoud Gamal Saad			*/
/*	Component	:	EXTI						*/
/*	Layer		:	MCAL						*/
/*	Version		:	2.0							*/
/************************************************/


#ifndef EXTI_INTERFACE_H
#define EXTI_INTERFACE_H

#define EXTI_u8_INT0		0
#define EXTI_u8_INT1		1
#define EXTI_u8_INT2		2

#define	LOW_LEVEL					0
#define	ANY_CHANGE					1
#define	FALLING_EDGE				2
#define	RISIGN_EDGE					3

extern void EXTI_voidInt(void);

/*
 * EXTI_u8_INT0
 * EXTI_u8_INT1
 * EXTI_u8_INT2
 *
 * */


extern ErrorStatus EXTI_errIntEnable(u8 Copy_u8Idx);

/*
 * EXTI_u8_INT0
 * EXTI_u8_INT1
 * EXTI_u8_INT2
 *
 * */


extern ErrorStatus EXTI_errIntDisable(u8 Copy_u8Idx);

/*
 * EXTI_u8_INT0
 * EXTI_u8_INT1
 * EXTI_u8_INT2
 * LOW_LEVEL
 * ANY_CHANGE
 * FALLING_EDGE
 * RISIGN_EDGE
 * */

extern ErrorStatus EXTI_errSetSenseLevel(u8 Copy_u8Idx, u8 Copy_u8SenseLevel);


/*
 * EXTI_u8_INT0
 * EXTI_u8_INT1
 * EXTI_u8_INT2
 *
 * Any Function that you wish to make as an interrupt
 * */

extern ErrorStatus EXTI_errSetCallBack(u8 Copy_u8Idx, void(*Copy_pvCallBack)(void));

#endif

