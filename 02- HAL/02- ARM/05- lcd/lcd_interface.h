/****************************/
/*	Author : Mahmoud Gamal	*/
/*	Version: V01						*/
/*	Date	 : 14/1						*/
/****************************/


#ifndef LCD_INTERFACE_H
#define LCD_INTERFACE_H

/*	Description: This API shall intialize the LCD for STM32	*/
void CLCD_voidInitialize(void);

/*	Description: This API shall Display data on the LCD for STM32	*/
void CLCD_voidWriteData(u8 Copy_u8Data);

/*	Description: This API shall send commands to the LCD for STM32	*/
void CLCD_voidWriteCmd(u8 Copy_u8Cmd);


void CLCD_voidWriteString(char * Copy_pu8String);

void CLCD_voidClearDisplay(void);

void CLCD_voidShiftLeft(void);

void CLCD_voidShiftRight(void);

void CLCD_voidGoto(u8 row, u8 col);

void CLCD_voidPrintMyName(void);




#endif