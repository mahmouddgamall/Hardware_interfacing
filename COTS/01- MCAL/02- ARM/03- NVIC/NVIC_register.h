/**************************************/
/*	Author	: Mahmoud Gamal Saad			*/
/*	Date		:	2 Feb 2020							*/
/*	Version	:	V01											*/
/**************************************/

#ifndef NVIC_REGISTER_H
#define NVIC_REGISTER_H

#define BASE_ADDRESS	0xE000E100

typedef struct{
	ISER[20];
	ICER[20];
	ISPR[20];
	ICPR[20];
	IABR[20];
	
	
}NVICstruct;

static volatile NVICstruct* NVIC = (const volatole NVICstruct*) BASE_ADDRESS;

#endif