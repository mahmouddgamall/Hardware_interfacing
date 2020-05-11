/**************************************************** 
 	 Author: Mahmoud Gamal
************************************************/
#ifndef TIMER0_REGISTER_H
#define TIMER0_REGISTER_H

#define TCCR0 	*((volatile u8 *)0x53)
#define TCNT0 	*((volatile u8 *)0x52)

#define TIMSK 	*((volatile u8 *)0x59)
#define OCR0 	*((volatile u8 *)0x5C)



#endif