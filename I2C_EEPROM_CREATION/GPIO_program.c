/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * File name: GPIO_prog.c                                                                              *
 *                                                                                                     *
 * Description: This source file is used to implement the interfacing with the GPIO module in 		   *
 * 				 ATmega32A evaluation kit 															   *
 *                                                                                                     *
 * Author : Mohamed Adel Anis Ahmed				                                                       *
 * date   : 2 March 2020                                                                               *
 * version: 1.0                                                                                        *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */


#include "STD_TYPES.h"

#include "GPIO_interface.h"

typedef struct{

	uint8_t PIN;
	uint8_t DDR;
	uint8_t PORT;

}GPIO_Register_t;



ErrorStatus_t GPIO_InitStr(GPIO_PinConfig_t* GPIO_PinConfig)
{
	volatile GPIO_Register_t *GPIO_Register;
	GPIO_Register = (GPIO_Register_t *) GPIO_PinConfig->PORT;

	ErrorStatus_t Local_Error = ERROR_OK;

	if( GPIO_PinConfig->PORT != PORTA && GPIO_PinConfig->PORT != PORTB && GPIO_PinConfig->PORT != PORTC && GPIO_PinConfig->PORT != PORTD )
	{
		Local_Error = ERROR_NOK;
	}
	else
	{
		if( GPIO_PinConfig->MODE == MODE_OUTPUT )
		{
			GPIO_Register->DDR |= GPIO_PinConfig->PIN;
		}
		else if( GPIO_PinConfig->MODE == MODE_INPUT_FLOATING )
		{
			GPIO_Register->DDR &= ~GPIO_PinConfig->PIN;
		}
		else if( GPIO_PinConfig->MODE == MODE_INPUT_PULLUP )
		{
			GPIO_Register->DDR  &= ~GPIO_PinConfig->PIN;
			GPIO_Register->PORT |=  GPIO_PinConfig->PIN;
		}
		else
		{
			Local_Error = ERROR_NOK;
		}
	}

	return Local_Error;
}


ErrorStatus_t GPIO_SetPinValue(GPIO_PinConfig_t* GPIO_PinConfig , uint8_t Value)
{
	volatile GPIO_Register_t *GPIO_Register;
	GPIO_Register = (GPIO_Register_t *) GPIO_PinConfig->PORT;

	ErrorStatus_t Local_Error = ERROR_OK;

	if( GPIO_PinConfig->PORT != PORTA && GPIO_PinConfig->PORT != PORTB && GPIO_PinConfig->PORT != PORTC && GPIO_PinConfig->PORT != PORTD )
	{
		Local_Error = ERROR_NOK;
	}
	else
	{
		switch(Value)
		{
			case HIGH:
					GPIO_Register->PORT |=  GPIO_PinConfig->PIN;
				break;

			case LOW:
					GPIO_Register->PORT &= ~GPIO_PinConfig->PIN;
				break;
		}
	}

	return Local_Error;
}


ErrorStatus_t GPIO_GetPinValue(GPIO_PinConfig_t* GPIO_PinConfig , uint8_t* Value)
{
	volatile GPIO_Register_t *GPIO_Register;
	GPIO_Register = (GPIO_Register_t *) GPIO_PinConfig->PORT;

	ErrorStatus_t Local_Error = ERROR_OK;

	if( GPIO_PinConfig->PORT != PORTA && GPIO_PinConfig->PORT != PORTB && GPIO_PinConfig->PORT != PORTC && GPIO_PinConfig->PORT != PORTD )
	{
		Local_Error = ERROR_NOK;
	}
	else
	{
		if( (GPIO_Register->PIN & GPIO_PinConfig->PIN) == 0 )
		{
			*Value = LOW;
		}
		else
		{
			*Value = HIGH;
		}
	}

	return Local_Error;
}




ErrorStatus_t GPIO_InitPins(void* PORT , uint8_t PINs , uint8_t MODE)
{
	volatile GPIO_Register_t *GPIO_Register;
	GPIO_Register = (GPIO_Register_t *) PORT;

	ErrorStatus_t Local_Error = ERROR_OK;

	if( PORT != PORTA && PORT != PORTB && PORT != PORTC && PORT != PORTD )
	{
		Local_Error = ERROR_NOK;
	}
	else
	{
		if( MODE == MODE_OUTPUT )
		{
			GPIO_Register->DDR |= PINs;
		}
		else if( MODE == MODE_INPUT_FLOATING )
		{
			GPIO_Register->DDR &= ~PINs;
		}
		else if( MODE == MODE_INPUT_PULLUP )
		{
			GPIO_Register->DDR  &= ~PINs;
			GPIO_Register->PORT |=  PINs;
		}
		else
		{
			Local_Error = ERROR_NOK;
		}
	}

	return Local_Error;
}




ErrorStatus_t GPIO_writePinValue(void* PORT , uint8_t PIN , uint8_t Value)
{
	volatile GPIO_Register_t *GPIO_Register;
	GPIO_Register = (GPIO_Register_t *) PORT;

	ErrorStatus_t Local_Error = ERROR_OK;

	if( PORT != PORTA && PORT != PORTB && PORT != PORTC && PORT != PORTD )
	{
		Local_Error = ERROR_NOK;
	}
	else
	{
		switch(Value)
		{
			case HIGH:
					GPIO_Register->PORT |=  PIN;
				break;

			case LOW:
					GPIO_Register->PORT &= ~PIN;
				break;
		}
	}

	return Local_Error;
}




ErrorStatus_t GPIO_writePortValue(void* PORT , uint8_t PortValue)
{
	volatile GPIO_Register_t *GPIO_Register;
	GPIO_Register = (GPIO_Register_t *) PORT;

	ErrorStatus_t Local_Error = ERROR_OK;

	if( PORT != PORTA && PORT != PORTB && PORT != PORTC && PORT != PORTD )
	{
		Local_Error = ERROR_NOK;
	}
	else
	{
		GPIO_Register->PORT =  PortValue;
	}

	return Local_Error;
}




ErrorStatus_t GPIO_ReadPinValue(void* PORT , uint8_t PIN , uint8_t* Value)
{
	volatile GPIO_Register_t *GPIO_Register;
	GPIO_Register = (GPIO_Register_t *) PORT;

	ErrorStatus_t Local_Error = ERROR_OK;

	if( PORT != PORTA && PORT != PORTB && PORT != PORTC && PORT != PORTD )
	{
		Local_Error = ERROR_NOK;
	}
	else
	{
		if( (GPIO_Register->PIN & PIN) == 0 )
		{
			*Value = LOW;
		}
		else
		{
			*Value = HIGH;
		}
	}

	return Local_Error;
}
