#include "std_types.h"
#include "bit_math.h"

#include "PORT_interface.h"
#include "lcd_config.h"
#include "lcd_private.h"
#include "lcd_register.h"
#include "lcd_interface.h"
#include "Delay_interface.h"
/*	Description: This API shall intialize the LCD for STM32	*/
void CLCD_voidInitialize(void)
{
	_delay_ms(10);

	/*	DataSheet Initialization	*/
#if CLCD_u8_DATA_LENGTH == FOUR_BITS_MODE

	/*Send 0b0010 twice and then the N=1F=0*/
	/*	set RS =0	*/

	setPinValue(CLCD_u8_RS_PORT,CLCD_u8_RS_PIN,0);

	/*	set RW = 0	*/


	setPinValue(CLCD_u8_RW_PORT,CLCD_u8_RW_PIN,0);



	CLCD_voidSetHalfDataPort(0b0010);

	CLCD_voidSendEnablePulse();


	CLCD_voidSetHalfDataPort(0b0010);

	CLCD_voidSendEnablePulse();

	CLCD_voidSetHalfDataPort(0b1000);

	CLCD_voidSendEnablePulse();




#elif	CLCD_u8_DATA_LENGTH == EIGHT_BITS_MODE

	CLCD_voidWriteCmd(CLCD_u8_FUNCTION_SET_TWO_LINES_COMMAND);


#else
#warning "Invalid data length in function 'CLCD_voidInitialize'"
#endif
	//NOTE THAT WE ALREADY WAIT FOR 1 MS IN THE CLCD_voidWriteData

	/*	Display ON/OFF Control	*/
	CLCD_voidWriteCmd(0b00001100);

	//NOTE THAT WE ALREADY WAIT FOR 1 MS IN THE CLCD_voidWriteCmd

	/*	Display Clear	*/
	CLCD_voidWriteCmd(0b00000001);

	_delay_ms(2);


}

/*	Description: This API shall Display data on the LCD for STM32	*/
void CLCD_voidWriteData(u8 Copy_u8Data)
{


	/*	set RS =1	*/

	setPinValue(CLCD_u8_RS_PORT,CLCD_u8_RS_PIN,1);

	/*	set RW = 0	*/


	setPinValue(CLCD_u8_RW_PORT,CLCD_u8_RW_PIN,0);


	/*	set data on data port	*/
#if CLCD_u8_DATA_LENGTH == FOUR_BITS_MODE

	/*	Set the higher order bits first, put them at the beggining of the bits, so that the CLCD_voidSetHalfDataPort would be able to see them since it only sees the first 4 bits and sends them using the second 4 bits	*/
	CLCD_voidSetHalfDataPort(Copy_u8Data>>4);

	/*	Enable Pulse	*/


	CLCD_voidSendEnablePulse();

	CLCD_voidSetHalfDataPort(Copy_u8Data);

	/*	Enable Pulse	*/


	CLCD_voidSendEnablePulse();

#elif	CLCD_u8_DATA_LENGTH == EIGHT_BITS_MODE
	CLCD_voidSetDataPort(Copy_u8Data);

	/*	Enable Pulse	*/

	CLCD_voidSendEnablePulse();

#else
#warning "Invalid data length in function 'CLCD_voidWriteData'"

#endif
	_delay_ms(2);


}

/*	Description: This API shall send commands to the LCD for STM32	*/
void CLCD_voidWriteCmd(u8 Copy_u8Cmd)
{

	/*	set RS =0	*/

	setPinValue(CLCD_u8_RS_PORT,CLCD_u8_RS_PIN,0);

	/*	set RW = 0	*/


	setPinValue(CLCD_u8_RW_PORT,CLCD_u8_RW_PIN,0);


	/*	set data on data port	*/
#if CLCD_u8_DATA_LENGTH == FOUR_BITS_MODE

	/*	Set the higher order bits first, put them at the beggining of the bits, so that the CLCD_voidSetHalfDataPort would be able to see them since it only sees the first 4 bits and sends them using the second 4 bits	*/
	CLCD_voidSetHalfDataPort(Copy_u8Cmd>>4);

	/*	Enable Pulse	*/


	CLCD_voidSendEnablePulse();

	CLCD_voidSetHalfDataPort(Copy_u8Cmd);

	/*	Enable Pulse	*/

	CLCD_voidSendEnablePulse();

#elif	CLCD_u8_DATA_LENGTH == EIGHT_BITS_MODE
	CLCD_voidSetDataPort(Copy_u8Cmd);
	CLCD_voidSendEnablePulse();

#else
#warning "Invalid data length in function 'CLCD_voidWriteCmd'"

#endif
	_delay_ms(2);


}
#if CLCD_u8_DATA_LENGTH == EIGHT_BITS_MODE


static void CLCD_voidSetDataPort(u8 Copy_u8Data)					/*this function is private, which means that no other
file can call it, therefore it is static*/
{
	u8 Local_u8BitVal;


	Local_u8BitVal = GET_BIT(Copy_u8Data,0);
	setPinValue(CLCD_u8_D0_PORT,CLCD_u8_D0_PIN,Local_u8BitVal);

	Local_u8BitVal = GET_BIT(Copy_u8Data,1);
	setPinValue(CLCD_u8_D1_PORT,CLCD_u8_D1_PIN,Local_u8BitVal);

	Local_u8BitVal = GET_BIT(Copy_u8Data,2);
	setPinValue(CLCD_u8_D2_PORT,CLCD_u8_D2_PIN,Local_u8BitVal);

	Local_u8BitVal = GET_BIT(Copy_u8Data,3);
	setPinValue(CLCD_u8_D3_PORT,CLCD_u8_D3_PIN,Local_u8BitVal);

	Local_u8BitVal = GET_BIT(Copy_u8Data,4);
	setPinValue(CLCD_u8_D4_PORT,CLCD_u8_D4_PIN,Local_u8BitVal);

	Local_u8BitVal = GET_BIT(Copy_u8Data,5);
	setPinValue(CLCD_u8_D5_PORT,CLCD_u8_D5_PIN,Local_u8BitVal);

	Local_u8BitVal = GET_BIT(Copy_u8Data,6);
	setPinValue(CLCD_u8_D6_PORT,CLCD_u8_D6_PIN,Local_u8BitVal);

	Local_u8BitVal = GET_BIT(Copy_u8Data,7);
	setPinValue(CLCD_u8_D7_PORT,CLCD_u8_D7_PIN,Local_u8BitVal);
}
#elif	CLCD_u8_DATA_LENGTH == FOUR_BITS_MODE


static void CLCD_voidSetHalfDataPort(u8 Copy_u8Data)
{

	u8 Local_u8BitVal;

	Local_u8BitVal = GET_BIT(Copy_u8Data,0);
	setPinValue(CLCD_u8_D4_PORT,CLCD_u8_D4_PIN,Local_u8BitVal);

	Local_u8BitVal = GET_BIT(Copy_u8Data,1);
	setPinValue(CLCD_u8_D5_PORT,CLCD_u8_D5_PIN,Local_u8BitVal);

	Local_u8BitVal = GET_BIT(Copy_u8Data,2);
	setPinValue(CLCD_u8_D6_PORT,CLCD_u8_D6_PIN,Local_u8BitVal);

	Local_u8BitVal = GET_BIT(Copy_u8Data,3);
	setPinValue(CLCD_u8_D7_PORT,CLCD_u8_D7_PIN,Local_u8BitVal);
}
#endif

void CLCD_voidClearDisplay(void)
{
	CLCD_voidWriteCmd(1);
}

void CLCD_voidShiftLeft(void)
{
	CLCD_voidWriteCmd(0b00011000);

}

void CLCD_voidShiftRight(void)
{
	CLCD_voidWriteCmd(0b00011100);

}

void CLCD_voidGoto(u8 row, u8 col)
{
	if(row == CLCD_LINE_ONE)
	{
		CLCD_voidWriteCmd(CLCD_FIRST_LINE+col);
	}
	else if(row == CLCD_LINE_TWO)
	{
		CLCD_voidWriteCmd(CLCD_SECOND_LINE+col);
	}
}


void CLCD_voidWriteString(char * Copy_pu8String)
{
	u8 Local_u8Counter=0;
	while(Copy_pu8String[Local_u8Counter] != '\0')
	{
		CLCD_voidWriteData(Copy_pu8String[Local_u8Counter]);
		Local_u8Counter++;
	}
}

void CLCD_voidPrintMyName(void)
{
	CLCD_voidWriteData('J');
	CLCD_voidWriteData('E');
	CLCD_voidWriteData('M');
	CLCD_voidWriteData('M');
	CLCD_voidWriteData('Y');
}

void CLCD_voidSendEnablePulse(void)
{

	/*	Enable Pulse	*/

	setPinValue(CLCD_u8_E_PORT,CLCD_u8_E_PIN,1);
	_delay_ms(5);
	setPinValue(CLCD_u8_E_PORT,CLCD_u8_E_PIN,0);
	_delay_ms(5);
}
