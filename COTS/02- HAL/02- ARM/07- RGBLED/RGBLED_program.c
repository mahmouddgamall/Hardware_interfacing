#include "std_types.h"
#include "bit_math.h"

#include "gpio_interface.h"

#include"LED_interface.h"
#include "LED_private.h"
#include "LED_config.h"

void RGBLED_voidSetRedOn(u8 LED)
{
	if(LED < 5)
	{
		LED = LED * 3;
		setPinValue(FIRST_LEDS_Port, LED, LED_Mode);
	}
	
	else if(LED < 10)
	{
		LED = LED * 3;
		setPinValue(SECOND_LEDS_Port, LED, LED_Mode);
	}
}

void RGBLED_voidSetRedOff(u8 LED)
{
	if(LED < 5)
	{
		LED = LED * 3;
		setPinValue(FIRST_LEDS_Port, LED, LED_Mode^1);
	}
	else if(LED < 10)
	{
		LED = LED * 3;
		setPinValue(SECOND_LEDS_Port, LED, LED_Mode^1);
	}
}

void RGBLED_voidSetBlueOn(u8 LED)
{
	if(LED < 5)
	{
		LED = LED * 3;
		setPinValue(FIRST_LEDS_Port, LED+1, LED_Mode);
	
	
	else if(LED < 10)
	{
		LED = LED * 3;
		setPinValue(SECOND_LEDS_Port, LED+1, LED_Mode);
	}}
}

void RGBLED_voidSetBlueOff(u8 LED)
{
	if(LED < 5)
	{
		LED = LED * 3;
		setPinValue(FIRST_LEDS_Port, LED+1, LED_Mode^1);
	}
	else if(LED < 10)
	{
		LED = LED * 3;
		setPinValue(SECOND_LEDS_Port, LED+1, LED_Mode^1);
	}
}

void RGBLED_voidSetGreenOn(u8 LED)
{
	if(LED < 5)
	{
		LED = LED * 3;
		setPinValue(FIRST_LEDS_Port, LED+2, LED_Mode);
	}
	
	else if(LED < 10)
	{
		LED = LED * 3;
		setPinValue(SECOND_LEDS_Port, LED+2, LED_Mode);
	}
}

void RGBLED_voidSetGreenOff(u8 LED)
{
	if(LED < 5)
	{
		LED = LED * 3;
		setPinValue(FIRST_LEDS_Port, LED+2, LED_Mode^1);
	}
	
	else if(LED < 10)
	{
		LED = LED * 3;
		setPinValue(SECOND_LEDS_Port, LED+2, LED_Mode^1);
	}
}

void RGBLED_voidSetWhiteOn(u8 LED)
{
	if(LED < 5)
	{
		LED = LED * 3;
		setPinValue(FIRST_LEDS_Port, LED, LED_Mode);
		setPinValue(FIRST_LEDS_Port, LED+1, LED_Mode);
		setPinValue(FIRST_LEDS_Port, LED+2, LED_Mode);
	}
	
	else if(LED < 10)
	{
		LED = LED * 3;
		setPinValue(SECOND_LEDS_Port, LED, LED_Mode);
		setPinValue(SECOND_LEDS_Port, LED+1, LED_Mode);
		setPinValue(SECOND_LEDS_Port, LED+2, LED_Mode);
	}
}

void RGBLED_voidSetLEDOff(u8 LED)
{
	if(LED < 5)
	{
		LED = LED * 3;
		setPinValue(FIRST_LEDS_Port, LED, LED_Mode^1);
		setPinValue(FIRST_LEDS_Port, LED+1, LED_Mode^1);
		setPinValue(FIRST_LEDS_Port, LED+2, LED_Mode^1);
	}
	else if(LED < 10)
	{
		LED = LED * 3;
		setPinValue(SECOND_LEDS_Port, LED, LED_Mode^1);
		setPinValue(SECOND_LEDS_Port, LED+1, LED_Mode^1);
		setPinValue(SECOND_LEDS_Port, LED+2, LED_Mode^1);
	}
}

