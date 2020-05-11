#include "std_types.h"
#include "bit_math.h"

#include "PORT_interface.h"
#include "PORT_register.h"
#include "PORT_config.h"
#include "PORT_private.h"				//Note that the private.h must be included after the config.h because it is depening on it in many if not all of its functionality

void portInit(void)
{
	DDRA = PORTA_DIR;
	DDRB = PORTB_DIR;
	DDRC = PORTC_DIR;
	DDRD = PORTD_DIR;
	
	PORTA = PORTA_INITIALVAL;
	PORTB = PORTB_INITIALVAL;
	PORTC = PORTC_INITIALVAL;
	PORTD = PORTD_INITIALVAL;
		
}

void DIO_voidSetPinValue(u8 Copy_u8Pin, u8 Copy_u8Val)
{
	u8 Local_u8ReqPort = Copy_u8Pin/8;
	u8 Local_u8ReqPin = Copy_u8Pin%8;
	
	switch (Local_u8ReqPort)
	{
		case 0: ASSIGN_BIT(PORTA, Local_u8ReqPin, Copy_u8Val);break;
		case 1: ASSIGN_BIT(PORTB, Local_u8ReqPin, Copy_u8Val);break;
		case 2: ASSIGN_BIT(PORTC, Local_u8ReqPin, Copy_u8Val);break;
		case 3: ASSIGN_BIT(PORTD, Local_u8ReqPin, Copy_u8Val);break;
	}
	
}


u8 DIO_voidGetPinValue(u8 Copy_u8Pin, u8 Copy_u8Val)
{
	u8 Local_u8ReqPort = Copy_u8Pin/8;
	u8 Local_u8ReqPin = Copy_u8Pin%8;
	u8 Local_u8Value = 2;
	switch (Local_u8ReqPort)
	{
		case 0: Local_u8Value = GET_BIT(PINA, Local_u8ReqPin);break;
		case 1: Local_u8Value = GET_BIT(PINB, Local_u8ReqPin);break
		case 2: Local_u8Value = GET_BIT(PINC, Local_u8ReqPin);break
		case 3: Local_u8Value = GET_BIT(PIND, Local_u8ReqPin);break
	}
	
}


void setPinValue(u8 port, u8 pin, u8 value)
{
	switch(port)
	{
		case 'A':
			if(value == 0)
			{
				CLR_BIT(PORTA,pin);
			}
			else if(value == 1)
			{
				SET_BIT(PORTA,pin);
			}
		break;
		case 'B':
			if(value == 0)
			{
				CLR_BIT(PORTB,pin);
			}
			else if(value == 1)
			{
				SET_BIT(PORTB,pin);
			}

		break;
		case 'C':
			if(value == 0)
			{
				CLR_BIT(PORTC,pin);
			}
			else if(value == 1)
			{
				SET_BIT(PORTC,pin);
			}
		break;
		case 'D':
			if(value == 0)
			{
				CLR_BIT(PORTD,pin);
			}
			else if(value == 1)
			{
				SET_BIT(PORTD,pin);
			}


	}

}



u8 getPinValue(u8 port, u8 pin)
{
	u8 result;
	switch (port)
	{
	case 'A': result = GET_BIT(PINA,pin); break;
	case 'B': result = GET_BIT(PINB,pin); break;
	case 'C': result = GET_BIT(PINC,pin); break;
	case 'D': result = GET_BIT(PIND,pin);
	}					
	return result;
}

void setPort(u8 port)
{
	switch(port)
	{
	case 'A': PORTA=255; break;
	case 'B': PORTB=255; break;
	case 'C': PORTC=255; break;
	case 'D': PORTD=255;
	}
}

void clearPort(u8 port)
{
	switch(port)
	{
	case 'A': PORTA=0; break;
	case 'B': PORTB=0; break;
	case 'C': PORTC=0; break;
	case 'D': PORTD=0;
	}
}
