
#define KEYPAD_ROWSMAX  4
#define KEYPAD_COLSMAX  4
/*

KEYPAD ROWS AND COL CONFIGRATION
*/





#define KEYPAD_R0_PORT   	'A'
#define KEYPAD_R0_Pin     	 4


#define KEYPAD_R1_PORT  	'A'
#define KEYPAD_R1_Pin   	 5


#define KEYPAD_R2_PORT    	'A'
#define KEYPAD_R2_Pin        6

#define KEYPAD_R3_PORT   	'A'
#define KEYPAD_R3_Pin    	 7



#define KEYPAD_C0_PORT    	'A'
#define KEYPAD_C0_Pin  		 3


#define KEYPAD_C1_PORT 		 'A'
#define KEYPAD_C1_Pin  		  2


#define KEYPAD_C2_PORT 		 'A'
#define KEYPAD_C2_Pin  		  1

#define KEYPAD_C3_PORT 		  'A'
#define KEYPAD_C3_Pin   	   0


#define KEYPAD_COLS_PORTS   {KEYPAD_C0_PORT,KEYPAD_C1_PORT,KEYPAD_C2_PORT,KEYPAD_C3_PORT}
#define KEYPAD_COLS_PINS    {KEYPAD_C0_Pin,KEYPAD_C1_Pin,KEYPAD_C2_Pin,KEYPAD_C3_Pin}

#define KEYPAD_ROWS_PORTS   {KEYPAD_R0_PORT,KEYPAD_R1_PORT,KEYPAD_R2_PORT,KEYPAD_R3_PORT}
#define KEYPAD_ROWS_PINS    {KEYPAD_R0_Pin,KEYPAD_R1_Pin,KEYPAD_R2_Pin,KEYPAD_R3_Pin}

#define KEYPAD_KEYS         {{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}}

#define KEYPAD_NOKEYPRESSED    255

