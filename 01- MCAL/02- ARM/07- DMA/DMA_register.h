/***************************************************
Author	: Mahmoud Gamal
Date		: 10 March 2020
Version	: V01

***************************************************/

#ifndef DMA_REGISTER_H
#define DMA_REGISTER_H

typedef struct
{
	u32 CCR;
	u32 CNDTR;
	u32 CPAR;
	u32 CMAR;
	u32 Reserved;
}DMA_Channel;

typedef struct
{
	u32 				ISR				;
	u32 				IFCR			;
	DMA_Channel Channel[7];
}DMA_t;

#define DMA_Channel		((volatile DMA_t*)0x4002000)


#endif