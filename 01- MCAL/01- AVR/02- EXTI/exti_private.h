/************************************************/
/*	Author		:	Mahmoud Gamal Saad			*/
/*	Component	:	EXTI						*/
/*	Layer		:	MCAL						*/
/*	Version		:	2.0							*/
/************************************************/

#ifndef EXTI_PRIVATE_H
#define EXTI_PRIVATE_H

#define	EXTI_LOW						0
#define	EXTI_ANY_CHANGE					1
#define	EXTI_FALLING_EDGE				2
#define	EXTI_RISIGN_EDGE				3



void __vector_1(void)__attribute__ ((signal,used));

void __vector_2(void)__attribute__ ((signal,used));

void __vector_3(void)__attribute__ ((signal,used));


#endif
