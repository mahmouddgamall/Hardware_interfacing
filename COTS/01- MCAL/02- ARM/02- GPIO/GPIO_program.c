#include "std_types.h"
#include "GPIO_interface.h"

#define PORTA_BASE_ADDRESS 0x40010800


#define PORTB_BASE_ADDRESS 0x40010C00

#define PORTC_BASE_ADDRESS 0x40011000


typedef struct
{
	u32 CRL;
	u32 CRH;
	u32 IDR;
	u32 ODR;
	u32 BSR;
	u32 BRR;
	u32 LCK;
}GPIOstruct;

static volatile GPIOstruct* GPIOA = (const volatile GPIOstruct*) PORTA_BASE_ADDRESS;
static volatile GPIOstruct* GPIOB = (const volatile GPIOstruct*) PORTB_BASE_ADDRESS;
static volatile GPIOstruct* GPIOC = (const volatile GPIOstruct*) PORTC_BASE_ADDRESS;



void GPIO_voidSetPinMode(u8 port ,u8 pin,u8 mode)
{
	
	switch(port)
	{
		case PORTA:
		if(pin<=7)
		{
			GPIOA->CRL&=~(0b1111<<(pin*4));
			GPIOA->CRL|=mode<<(pin*4);
		}
		else if(pin<=15)
		{
			pin=pin-8;
			GPIOA->CRH&=~(0b1111<<(pin*4));
			GPIOA->CRH|=(mode<<(pin*4));

		}
		break;
		case PORTB:
		if(pin<=7)
		{
			GPIOB->CRL&=~(0b1111<<(pin*4));
			GPIOB->CRL|=mode<<(pin*4);
		}
		else if(pin<=15)
		{
			pin=pin-8;
			GPIOB->CRH&=~(0b1111<<(pin*4));
			GPIOB->CRH|=(mode<<(pin*4));
		}
		break;
		case PORTC:
		if((pin>=13)&& (pin<=15))
		{
			pin=pin-8;
			GPIOC->CRH&=~(0b1111<<(pin*4));
			GPIOC->CRH|=mode<<(pin*4);
		}
		break;
	}
}

void GPIO_voidSetPinValue(u8 Copy_u8Pin, u8 Copy_u8Val)
{
	u8 Local_u8ReqPort = Copy_u8Pin/16;
	u8 Local_u8ReqPin = Copy_u8Pin%16;
	if(Copy_u8Val == GPIO_HIGH)
	{
		switch(port)
		{
			case 0:
			GPIOA->BSR =(1<<pin);
			break;
			case 1:
			GPIOB->BSR =(1<<pin);
			break;

			case 2:
			GPIOC->BSR =(1<<pin);
			break;
		}
	}
	else
	{
		switch(port)
		{
			case 0:
			GPIOA->BRR =(1<<pin);
			break;
			case 1:
			GPIOB->BRR =(1<<pin);
			break;

			case 2:
			GPIOC->BRR =(1<<pin);
			break;
		}
	}
	

	
}




void GPIO_voidSetPin(u8 port,u32 pin)
{
	switch(port)
	{
		case 0:
		GPIOA->BSR =(1<<pin);
		break;
		case 1:
		GPIOB->BSR =(1<<pin);
		break;

		case 2:
		GPIOC->BSR =(1<<pin);
		break;
	}
}


void GPIO_voidResetPin(u8 port,u32 pin)
{
	switch(port)
	{
		case 0:
		GPIOA->BRR =(1<<pin);
		break;
		case 1:
		GPIOB->BRR =(1<<pin);
		break;

		case 2:
		GPIOC->BRR =(1<<pin);
		break;
	}
}


void GPIO_voidSetPortValue(u8 port, u32 value)
{
	
	switch(port)
	{
		case 0:
		GPIOA->ODR=value;
		break;
		case 1:
		GPIOB->ODR=value;
		break;

		case 2:
		GPIOC->ODR=value;
		break;
	}
}

u8 GPIO_u8GetPinValue(u8 port,u8 pin)
{
	u8 result=0;
	switch(port)
	{

		case 0:
		result = (GPIOA->IDR>>pin)&1;
		break;
		case 1:
		result = (GPIOB->IDR>>pin)&1;
		break;
		case 2:
		result = (GPIOC->IDR>>pin)&1;
		break;
		default:
		result = 255;

	}
	return result;

}
