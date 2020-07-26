#include"STD_Types.h"
#include"BIT_MATH.h"
#include"DIO_interface.h"
#include"KEYPAD_config.h"
#include"KEYPAD_interafce.h"
#include"KEYPAD_private.h"



void KEYPAD_Init(void)
{
	SetPinMode(KEYPAD_R0_PORT,KEYPAD_R0_Pin,OUTPUT_2_PUSH_PULL);
	SetPinMode(KEYPAD_R1_PORT,KEYPAD_R1_Pin,OUTPUT_2_PUSH_PULL);
	SetPinMode(KEYPAD_R2_PORT,KEYPAD_R2_Pin,OUTPUT_2_PUSH_PULL);
	SetPinMode(KEYPAD_R3_PORT,KEYPAD_R3_Pin,OUTPUT_2_PUSH_PULL);

	SetPinMode(KEYPAD_C0_PORT,KEYPAD_C0_Pin,INPUT_PULL_UP_DWON);
	SetPinMode(KEYPAD_C1_PORT,KEYPAD_C1_Pin,INPUT_PULL_UP_DWON);
	SetPinMode(KEYPAD_C2_PORT,KEYPAD_C2_Pin,INPUT_PULL_UP_DWON);
	SetPinMode(KEYPAD_C3_PORT,KEYPAD_C3_Pin,INPUT_PULL_UP_DWON);





	SetPinValue(KEYPAD_R0_PORT,KEYPAD_R0_Pin,1);
	SetPinValue(KEYPAD_R1_PORT,KEYPAD_R1_Pin,1);
	SetPinValue(KEYPAD_R2_PORT,KEYPAD_R2_Pin,1);
	SetPinValue(KEYPAD_R3_PORT,KEYPAD_R3_Pin,1);


	SetPinValue(KEYPAD_C0_PORT,KEYPAD_C0_Pin,1);
	SetPinValue(KEYPAD_C1_PORT,KEYPAD_C1_Pin,1);
	SetPinValue(KEYPAD_C2_PORT,KEYPAD_C2_Pin,1);
	SetPinValue(KEYPAD_C3_PORT,KEYPAD_C3_Pin,1);



}


u8 KEYPAD_GetPressedKey(void)
{
	u8 pressedKey = KEYPAD_NOKEYPRESSED;
	u8 ROWSConter;
	u8 COLSCounter;
	static u8 KEYPAD_ROWSPortArray[KEYPAD_ROWSMAX]=KEYPAD_ROWS_PORTS;
	static u8 KEYpad_ROWSPinArray[KEYPAD_ROWSMAX]=KEYPAD_ROWS_PINS;

	static u8 KEYPAD_COLSPortArray[KEYPAD_COLSMAX]=KEYPAD_COLS_PORTS;
	static u8 KEYpad_COLSPinArray[KEYPAD_COLSMAX]=KEYPAD_COLS_PINS;

	static u8 KEYPAD_KEYSArray[KEYPAD_ROWSMAX][KEYPAD_COLSMAX]=KEYPAD_KEYS;

	for(ROWSConter=0;ROWSConter<KEYPAD_ROWSMAX;ROWSConter++)
	{
		/* Put on each ROW 0 */
		SetPinValue(KEYPAD_ROWSPortArray[ROWSConter],KEYpad_ROWSPinArray[ROWSConter],0);
		/*Check on each col */
		for(COLSCounter = 0;COLSCounter<KEYPAD_COLSMAX;COLSCounter++)
		{
			while(!GetPinValue(KEYPAD_COLSPortArray[COLSCounter],KEYpad_COLSPinArray[COLSCounter]))
			{
				pressedKey = KEYPAD_KEYSArray[ROWSConter][COLSCounter];
				//for(u8 i=0;i<pressedKey+5;i++)
				//{
					SetPinValue('A',8,1);
					Delay_ms(pressedKey*4);
					SetPinValue('A',8,0);
					Delay_ms(pressedKey*4);

				//}
			}
		}
		SetPinValue(KEYPAD_ROWSPortArray[ROWSConter],KEYpad_ROWSPinArray[ROWSConter],1);


	}

	return pressedKey;




}






//#include"STD_Types.h"
//#include"BIT_MATH.h"
//#include"DIO_interface.h"
//#include"KEYPAD_config.h"
//#include"KEYPAD_interafce.h"
//#include"KEYPAD_private.h"
//
//
//
//void KEYPAD_Init(void)
//{
//	SetPinMode(KEYPAD_R0_PORT,KEYPAD_R0_Pin,OUTPUT_2_PUSH_PULL);
//	SetPinMode(KEYPAD_R1_PORT,KEYPAD_R1_Pin,OUTPUT_2_PUSH_PULL);
//	SetPinMode(KEYPAD_R2_PORT,KEYPAD_R2_Pin,OUTPUT_2_PUSH_PULL);
//	SetPinMode(KEYPAD_R3_PORT,KEYPAD_R3_Pin,OUTPUT_2_PUSH_PULL);
//
//	SetPinMode(KEYPAD_C0_PORT,KEYPAD_C0_Pin,INPUT_PULL_UP_DWON);
//	SetPinMode(KEYPAD_C1_PORT,KEYPAD_C1_Pin,INPUT_PULL_UP_DWON);
//	SetPinMode(KEYPAD_C2_PORT,KEYPAD_C2_Pin,INPUT_PULL_UP_DWON);
//	SetPinMode(KEYPAD_C3_PORT,KEYPAD_C3_Pin,INPUT_PULL_UP_DWON);
//
//
//
//
//
//	SetPinValue(KEYPAD_R0_PORT,KEYPAD_R0_Pin,1);
//	SetPinValue(KEYPAD_R1_PORT,KEYPAD_R1_Pin,1);
//	SetPinValue(KEYPAD_R2_PORT,KEYPAD_R2_Pin,1);
//	SetPinValue(KEYPAD_R3_PORT,KEYPAD_R3_Pin,1);
//
//
//	SetPinValue(KEYPAD_C0_PORT,KEYPAD_C0_Pin,1);
//	SetPinValue(KEYPAD_C1_PORT,KEYPAD_C1_Pin,1);
//	SetPinValue(KEYPAD_C2_PORT,KEYPAD_C2_Pin,1);
//	SetPinValue(KEYPAD_C3_PORT,KEYPAD_C3_Pin,1);
//
//
//
//}
//
//
//u8 KEYPAD_GetPressedKey(void)
//{
//  u8 pressedKey = KEYPAD_NOKEYPRESSED;
//  u8 ROWSConter;
//  u8 COLSCounter;
//  static u8 KEYPAD_ROWSPortArray[KEYPAD_ROWSMAX]=KEYPAD_ROWS_PORTS;
//  static u8 KEYpad_ROWSPinArray[KEYPAD_ROWSMAX]=KEYPAD_ROWS_PINS;
//
//    static u8 KEYPAD_COLSPortArray[KEYPAD_COLSMAX]=KEYPAD_COLS_PORTS;
//    static u8 KEYpad_COLSPinArray[KEYPAD_COLSMAX]=KEYPAD_COLS_PINS;
//
//    static u8 KEYPAD_KEYSArray[KEYPAD_ROWSMAX][KEYPAD_COLSMAX]=KEYPAD_KEYS;
//
//  for(ROWSConter=0;ROWSConter<KEYPAD_ROWSMAX;ROWSConter++)
//  {
//    /* Put on each ROW 0 */
//	  SetPinValue(KEYPAD_ROWSPortArray[ROWSConter],KEYpad_ROWSPinArray[ROWSConter],0);
//    /*Check on each col */
//    for(COLSCounter = 0;COLSCounter<KEYPAD_COLSMAX;COLSCounter++)
//    {
//      while( !GetPinValue(KEYPAD_COLSPortArray[COLSCounter],KEYpad_COLSPinArray[COLSCounter]))
//      {
//        pressedKey = KEYPAD_KEYSArray[ROWSConter][COLSCounter];
//
//      }
//    }
//    SetPinValue(KEYPAD_ROWSPortArray[ROWSConter],KEYpad_ROWSPinArray[ROWSConter],1);
//
//
//  }
//
//  return pressedKey;
//
//
//
//
//}
