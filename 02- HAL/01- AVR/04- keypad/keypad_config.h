/*	keypad rows pins configuration	*/

#define KEYPAD_R0_PORT		'D'
#define KEYPAD_R0_PIN			4

#define KEYPAD_R1_PORT		'D'
#define KEYPAD_R1_PIN			5

#define KEYPAD_R2_PORT		'D'
#define KEYPAD_R2_PIN			6

#define KEYPAD_R3_PORT		'D'
#define KEYPAD_R3_PIN			7


/*	keypad coloums pins configuration	*/

#define KEYPAD_C0_PORT		'D'
#define KEYPAD_C0_PIN			3

#define KEYPAD_C1_PORT		'D'
#define KEYPAD_C1_PIN			2

#define KEYPAD_C2_PORT		'D'
#define KEYPAD_C2_PIN			1

#define KEYPAD_C3_PORT		'D'
#define KEYPAD_C3_PIN			0

/*how many coloums do you need with a max of 4*/

#define	KEYPAD_COL_NUM	4

/*how many rows do you need with a max of 4*/

#define	KEYPAD_ROW_NUM	4

/*	CHOOSE THE PINS THAT YOU NEED	*/

#define KEYPAD_COL_PINS	{KEYPAD_C0_PIN,KEYPAD_C1_PIN,KEYPAD_C2_PIN,KEYPAD_C3_PIN}
#define KEYPAD_ROW_PINS	{KEYPAD_R0_PIN,KEYPAD_R1_PIN,KEYPAD_R2_PIN,KEYPAD_R3_PIN}

/*	CHOOSE THE PORTS THAT YOU NEED	*/

#define KEYPAD_COL_PORTS	{KEYPAD_C0_PORT,KEYPAD_C1_PORT,KEYPAD_C2_PORT,KEYPAD_C3_PORT}
#define KEYPAD_ROW_PORTS	{KEYPAD_R0_PORT,KEYPAD_R1_PORT,KEYPAD_R2_PORT,KEYPAD_R3_PORT}

#define KEYPAD_KEYS				{{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}}

#define KEYPAD_DEFAULT	17
