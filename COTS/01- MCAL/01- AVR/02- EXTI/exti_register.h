/************************************************/
/*	Author		:	Mahmoud Gamal Saad			*/
/*	Component	:	EXTI						*/
/*	Layer		:	MCAL						*/
/*	Version		:	2.0							*/
/************************************************/


#ifndef EXTI_REGISTER_H
#define EXTI_REGISTER_H


#define	MCUCR							(*((volatile u8*)0x55))		/*	Control Register	*/
#define	MCUCR_ISC00						(u8)0
#define	MCUCR_ISC01						(u8)1
#define	MCUCR_ISC10						(u8)2
#define	MCUCR_ISC11						(u8)3


#define	MCUCSR							(*((volatile u8*)0x54))		/*	Control and status Register	*/
#define	MCUCSR_ISC2						(u8)6


#define	GICR							(*((volatile u8*)0x5B))		/*	General Control Register	*/
#define	GICR_INT1						(u8)7
#define	GICR_INT0						(u8)6
#define	GICR_INT2						(u8)5

#define	GIFR							(*((volatile u8*)0x5A))		/*	General Flag Register	*/

#endif
