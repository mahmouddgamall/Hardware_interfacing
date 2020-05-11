/**************************************************** 
 	 Author: Mahmoud Gamal
************************************************/
#ifndef TIMER0_PRIVATE_H
#define TIMER0_PRIVATE_H
/*	TCCR0 	*/

#define	FOC0		7
#define	WGM00		6
#define	COM01		5
#define	COM00		4
#define	WTM01		3
#define	CS02		2
#define	CS01		1
#define	CS00		0

/*	TIMSK	*/


#define	OCIE0		1
#define	TOIE0		0




#define	TCCR0_MODE_MASK			0b10110111
#define TIMER0_INTERRUPT_MASK	0b11111100
#define	TIMER0_OC0_MASK			0b11001111

#endif
