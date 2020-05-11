/****************************/
/*	Author : Mahmoud Gamal	*/
/*	Version: V01						*/
/*	Date	 : 14/1						*/
/****************************/


/*	Description: This API shall configure the LCD for STM32	*/
#ifndef LCD_CONFIG_H
#define LCD_CONFIG_H

/*FOUR_BITS_MODE
	EIGHT_BITS_MODE*/

#define CLCD_u8_DATA_LENGTH		FOUR_BITS_MODE

#define	CLCD_u8_RS_PORT 'C'
#define	CLCD_u8_RW_PORT 'C'
#define	CLCD_u8_E_PORT  'C'
#define	CLCD_u8_D0_PORT 'A'
#define	CLCD_u8_D1_PORT 'A'
#define	CLCD_u8_D2_PORT 'A'
#define	CLCD_u8_D3_PORT 'A'
#define	CLCD_u8_D4_PORT 'A'
#define	CLCD_u8_D5_PORT 'A'
#define	CLCD_u8_D6_PORT 'A'
#define	CLCD_u8_D7_PORT 'A'


#define	CLCD_u8_RS_PIN	0
#define	CLCD_u8_RW_PIN	1
#define	CLCD_u8_E_PIN	2
#define	CLCD_u8_D0_PIN	0
#define	CLCD_u8_D1_PIN	1
#define	CLCD_u8_D2_PIN	2
#define	CLCD_u8_D3_PIN	3
#define	CLCD_u8_D4_PIN	4
#define	CLCD_u8_D5_PIN	5
#define	CLCD_u8_D6_PIN	6
#define	CLCD_u8_D7_PIN	7

#define CLCD_u8_FUNCTION_SET_TWO_LINES_COMMAND	0b00111000

#define CLCD_LINE_ONE	0
#define CLCD_LINE_TWO	1
#define CLCD_FIRST_LINE		0x80
#define CLCD_SECOND_LINE	0xC0


#endif
