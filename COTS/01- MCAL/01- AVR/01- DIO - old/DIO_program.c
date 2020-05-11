#include "std_types.h"
#include "bit_math.h"

#include "DIO_Interface.h"
#include "DIO_private.h"
#include "DIO_Register.h"
#include "DIO_config.h"

void setPinDirection(u8 port, u8 pin, u8 direction)
{
	switch(port)
	{
		case 'A':
			if(direction == 0)
			{
				CLR_BIT(DDRA,pin);
			}
			else if(direction == 1)
			{
				SET_BIT(DDRA,pin);
			}
		break;
		case 'B':
			if(direction == 0)
			{
				CLR_BIT(DDRB,pin);
			}
			else if(direction == 1)
			{
				SET_BIT(DDRB,pin);
			}
		
		break;
		case 'C':
			if(direction == 0)
			{
				CLR_BIT(DDRC,pin);
			}
			else if(direction == 1)
			{
				SET_BIT(DDRC,pin);
			}
		break;
		case 'D':
			if(direction == 0)
			{
				CLR_BIT(DDRD,pin);
			}
			else if(direction == 1)
			{
				SET_BIT(DDRD,pin);
			}
		
		
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


