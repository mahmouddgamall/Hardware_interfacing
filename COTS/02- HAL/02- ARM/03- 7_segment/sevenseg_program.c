#include "std_types.h"
#include "bit_math.h"

#include "PORT_interface.h"

#include"sevenseg_interface.h"
#include "sevenseg_private.h"
#include "sevenseg_config.h"

u8 lastNum = SEVENSEG_INITIAL_VALUE;
u8 sevensegEnablePorts[SEVENSEG_NUMBER]={SEVENSEG_ENABLE_PORT_1,SEVENSEG_ENABLE_PORT_2};
u8 sevensegEnablePins[SEVENSEG_NUMBER]={SEVENSEG_ENABLE_PIN_1,SEVENSEG_ENABLE_PIN_2};

void sevensegSetNum (u8 num)
{
	if(num>=0 || num<=9)
	{
		u8 seven_segNum[10]={0b00111111,0b00000110,0b01011011,0b01001111,0b01100110,0b01101101,0b01111101,0b00000111,0b01111111,0b01101111};
		#if SEVENSEG_Mode == 1
		setPinValue(SEVENSEG_PIN_A_PORT,SEVENSEG_PIN_A_NUM,GET_BIT(seven_segNum[num],0));
		setPinValue(SEVENSEG_PIN_B_PORT,SEVENSEG_PIN_B_NUM,GET_BIT(seven_segNum[num],1));
		setPinValue(SEVENSEG_PIN_C_PORT,SEVENSEG_PIN_C_NUM,GET_BIT(seven_segNum[num],2));
		setPinValue(SEVENSEG_PIN_D_PORT,SEVENSEG_PIN_D_NUM,GET_BIT(seven_segNum[num],3));
		setPinValue(SEVENSEG_PIN_E_PORT,SEVENSEG_PIN_E_NUM,GET_BIT(seven_segNum[num],4));
		setPinValue(SEVENSEG_PIN_F_PORT,SEVENSEG_PIN_F_NUM,GET_BIT(seven_segNum[num],5));
		setPinValue(SEVENSEG_PIN_G_PORT,SEVENSEG_PIN_G_NUM,GET_BIT(seven_segNum[num],6));
		setPinValue(SEVENSEG_PIN_H_PORT,SEVENSEG_PIN_H_NUM,GET_BIT(seven_segNum[num],7));
		
		#elif	SEVENSEG_Mode == 0
		setPinValue(SEVENSEG_PIN_A_PORT,SEVENSEG_PIN_A_NUM,GET_BIT(seven_segNum[num],0)^1);
		setPinValue(SEVENSEG_PIN_B_PORT,SEVENSEG_PIN_B_NUM,GET_BIT(seven_segNum[num],1)^1);
		setPinValue(SEVENSEG_PIN_C_PORT,SEVENSEG_PIN_C_NUM,GET_BIT(seven_segNum[num],2)^1);
		setPinValue(SEVENSEG_PIN_D_PORT,SEVENSEG_PIN_D_NUM,GET_BIT(seven_segNum[num],3)^1);
		setPinValue(SEVENSEG_PIN_E_PORT,SEVENSEG_PIN_E_NUM,GET_BIT(seven_segNum[num],4)^1);
		setPinValue(SEVENSEG_PIN_F_PORT,SEVENSEG_PIN_F_NUM,GET_BIT(seven_segNum[num],5)^1);
		setPinValue(SEVENSEG_PIN_G_PORT,SEVENSEG_PIN_G_NUM,GET_BIT(seven_segNum[num],6)^1);
		setPinValue(SEVENSEG_PIN_H_PORT,SEVENSEG_PIN_H_NUM,GET_BIT(seven_segNum[num],7)^1);

		#endif
		lastNum=num;
	}
}

void sevensegEnable (u8 sevensegNum)
{
	#if SEVENSEG_Mode == 1

	setPinValue(sevensegEnablePorts[sevensegNum],sevensegEnablePins[sevensegNum],0);
	#elif SEVENSEG_Mode == 0
	setPinValue(sevensegEnablePorts[sevensegNum],sevensegEnablePins[sevensegNum],1);
	#endif
	//sevensegSetNum(lastNum);
}

void sevensegDisable (u8 sevensegNum)
{
	#if SEVENSEG_Mode == 1
	setPinValue(sevensegEnablePorts[sevensegNum],sevensegEnablePins[sevensegNum],1);
	#elif SEVENSEG_Mode == 0
	setPinValue(sevensegEnablePorts[sevensegNum],sevensegEnablePins[sevensegNum],0);
	#endif
}
