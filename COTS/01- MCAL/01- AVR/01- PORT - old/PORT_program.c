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
