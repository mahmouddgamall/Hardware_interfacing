#include "std_types.h"
#include "bit_math.h"

#include "rcc_interface.h"

#ifndef RCC_REGISTER_H
#define RCC_REGISTER_H

#define BASE_ADDRESS	0x40021000

typedef struct
{
	u32 CR;
	u32 CFGR;
	u32 CIR;
	u32 APB2RSTR;
	u32 APB1RSTR;
	u32 AHBENR;
	u32 APB2ENR;
	u32 APB1ENR;
	u32 BDCR;
	u32 CSR;
}RCCstruct;

static volatile RCCstruct* RCC = (volatile RCCstruct*) BASE_ADDRESS;

#endif


u8 rcc_u8Clock (u8 clockSource)
{
	u8 status=0;
	switch(clockSource)
	{
		case HSI_VAL:
			SET_BIT(RCC->CR,HSION);
			while(GET_BIT(RCC->CR,HSIRDY)!=1);
			RCC->CFGR &=~(SW_CLEAR<<SW_PIN);
			RCC->CFGR |= (HSI_VAL<<SW_PIN);
			CLEAR_BIT(RCC->CR,PLLON);
			CLEAR_BIT(RCC->CR,HSEON);
			if(HSI_VAL==GET_BIT(RCC->CFGR,SWS_PIN))
			{
				status=1;
			}
			break;
			
		case HSE_VAL:
			SET_BIT(RCC->CR,HSEON);
			while(GET_BIT(RCC->CR,HSERDY)!=1);
			RCC->CFGR &=~(SW_CLEAR<<SW_PIN);
			RCC->CFGR |= (HSE_VAL<<SW_PIN);
			CLEAR_BIT(RCC->CR,PLLON);
			CLEAR_BIT(RCC->CR,HSION);
			if(HSE_VAL==GET_BIT(RCC->CFGR,SWS_PIN))
			{
				status=1;
			}
			break;
			
		case PLL_VAL:
			SET_BIT(RCC->CR,PLLON);
			while(GET_BIT(RCC->CR,PLLRDY)!=1);
			RCC->CFGR &=~(SW_CLEAR<<SW_PIN);
			RCC->CFGR |= (PLL_VAL<<SW_PIN);
			if(PLL_VAL==GET_BIT(RCC->CFGR,SWS_PIN))					//has the operation been done succesfully??
			{
				status=1;
			}
			break;
		default:
			status=0;										//if the clocksource is  not equal any number of the defined numbers
		
	}
	return status;
}

u8 rcc_u8PllEnable (u8 pllmul, u8 pllsrc)
{
	u8 Loc_status=0;
	u8 srcStatus;
	if (pllsrc == HSEDIV2_check)
	{
		 srcStatus = rcc_u8Clock(HSE_VAL);
		SET_BIT(RCC->CFGR,PLLXTPRE);									//USE HSE/2

	}
	else
	{
		 srcStatus = rcc_u8Clock(pllsrc);						//HSE or HSI
		if(pllsrc == HSE_VAL)
		{
			CLEAR_BIT(RCC->CFGR,PLLXTPRE);
		}
	}
	
	if (srcStatus!=1)		
	{
		return Loc_status;
	}
	
	
	RCC->CFGR &=~ (PLLMULL_CLEAR<<PLLMUL);
	RCC->CFGR |= (pllmul<<PLLMUL);
	
	Loc_status = rcc_u8Clock(PLL_VAL);
	return Loc_status;

}

void rcc_voidEnablePeripheral (u8 peripheral)
{
	if(peripheral<32)
	{
		SET_BIT(RCC->AHBENR,peripheral);
	}
	else if(peripheral >= 32 && peripheral<64)
	{
		peripheral = peripheral-32;
		SET_BIT(RCC->APB2ENR,peripheral);
	}
	else if(peripheral >= 64 && peripheral<96)
	{
		peripheral = peripheral-64;
		SET_BIT(RCC->APB1ENR,peripheral);
	}
}

void rcc_voidDisablePeripheral (u8 peripheral)
{
	if(peripheral<32)
	{
		CLEAR_BIT(RCC->AHBENR,peripheral);
	}
	else if(peripheral >= 32 && peripheral<64)
	{
		peripheral = peripheral-32;
		CLEAR_BIT(RCC->APB2ENR,peripheral);
	}
	else if(peripheral >= 64 && peripheral<96)
	{
		peripheral = peripheral-64;
		CLEAR_BIT(RCC->APB1ENR,peripheral);
	}
}

void rcc_voidsetMCO(u8 mcosrc)
{
	RCC->CFGR &=~(0b111<<MCO_PIN);
	switch(mcosrc)
	{
		case MCO_NO_CLOCK:
		
		break;
		
		case MCO_SYS_CLOCK:
		RCC->CFGR |= (MCO_SYS_CLOCK<<MCO_PIN);
		break;
		
		case MCO_HSI_CLOCK:
		RCC->CFGR |= (MCO_HSI_CLOCK<<MCO_PIN);
		break;
		
		case MCO_HSE_CLOCK:
		RCC->CFGR |= (MCO_HSE_CLOCK<<MCO_PIN);
		break;
		
		case MCO_PLL_CLOCK:
		RCC->CFGR |= (MCO_PLL_CLOCK<<MCO_PIN);
		break;
	}
}

void rcc_voidAHBprescaler(u8 prescaler)
{
		RCC->CFGR &=~(AHB_CLEAR_BITS<<AHB_PRESCHALER_PIN);
	switch(prescaler)
	{
		case AHB_NO_DIVISOR:
		
		break;
		
		case AHB_2_DIVISOR:
		RCC->CFGR |= (AHB_2_DIVISOR<<MCO_PIN);
		break;
		
		case AHB_4_DIVISOR:
		RCC->CFGR |= (AHB_4_DIVISOR<<MCO_PIN);
		break;
		
		case AHB_8_DIVISOR:
		RCC->CFGR |= (AHB_8_DIVISOR<<MCO_PIN);
		break;
		
		case AHB_16_DIVISOR:
		RCC->CFGR |= (AHB_16_DIVISOR<<MCO_PIN);
		break;
		
		case AHB_64_DIVISOR:
		RCC->CFGR |= (AHB_64_DIVISOR<<MCO_PIN);
		break;
		
		case AHB_128_DIVISOR:
		RCC->CFGR |= (AHB_128_DIVISOR<<MCO_PIN);
		break;
		
		case AHB_256_DIVISOR:
		RCC->CFGR |= (AHB_256_DIVISOR<<MCO_PIN);
		break;
		
		case AHB_512_DIVISOR:
		RCC->CFGR |= (AHB_512_DIVISOR<<MCO_PIN);
		break;
	}
}

void rcc_voidAPB2prescaler(u8 prescaler)
{
	RCC->CFGR &=~(APB2_CLEAR_BITS<<APB2_PRESCHALER_PIN);
	switch(prescaler)
	{
		case APB2_NO_DIVISOR:
		
		break;
		
		case APB2_2_DIVISOR:
		RCC->CFGR |= (APB2_2_DIVISOR<<MCO_PIN);
		break;
		
		case APB2_4_DIVISOR:
		RCC->CFGR |= (APB2_4_DIVISOR<<MCO_PIN);
		break;
		
		case APB2_8_DIVISOR:
		RCC->CFGR |= (APB2_8_DIVISOR<<MCO_PIN);
		break;
		
		case APB2_16_DIVISOR:
		RCC->CFGR |= (APB2_16_DIVISOR<<MCO_PIN);
		break;
		
	}
}

void rcc_voidAPB1prescaler(u8 prescaler)
{
	RCC->CFGR &=~(APB1_CLEAR_BITS<<APB1_PRESCHALER_PIN);
	switch(prescaler)
	{
		case APB1_NO_DIVISOR:
		
		break;
		
		case APB1_2_DIVISOR:
		RCC->CFGR |= (APB1_2_DIVISOR<<MCO_PIN);
		break;
		
		case APB1_4_DIVISOR:
		RCC->CFGR |= (APB1_4_DIVISOR<<MCO_PIN);
		break;
		
		case APB1_8_DIVISOR:
		RCC->CFGR |= (APB1_8_DIVISOR<<MCO_PIN);
		break;
		
		case APB1_16_DIVISOR:
		RCC->CFGR |= (APB1_16_DIVISOR<<MCO_PIN);
		break;
		
	}
}
