#define	PORTA_Config_CRL	0x00000000
#define	PORTA_Config_CRH	0x00000000
#define	PORTB_Config_CRL	0x00000000
#define	PORTB_Config_CRH	0x00000000
#define	PORTC_Config_CRH	0x00000000


#define INPUT_ANALOG							(u8)0
#define INPUT_FLOATING						(u8)4
#define INPUT_PULL_UP_DWON				(u8)8

#define OUTPUT_10_PUSH_PULL				(u8)1
#define OUTPUT_10_DRAIN						(u8)5
#define OUTPUT_10_AF_PUSH_PULL		(u8)9
#define OUTPUT_10_AF_OPEN_DRAIN		((u8)13)

#define OUTPUT_2_PUSH_PULL				((u8)2)
#define OUTPUT_2_DRAIN						((u8)6)
#define OUTPUT_2_AF_PUSH_PULL			((u8)10)
#define OUTPUT_2_AF_OPEN_DRAIN		((u8)14)

#define OUTPUT_50_PUSH_PULL				((u8)3)
#define OUTPUT_50_DRAIN						((u8)7)
#define OUTPUT_50_AF_PUSH_PULL		((u8)11)
#define OUTPUT_50_AF_OPEN_DRAIN		((u8)15)

#define PORTA 										(u8)0
#define PORTB 										(u8)1
#define PORTC 										(u8)2


#define GPIO_HIGH						1
#define GPIO_LOW						0


void GPIO_initPin(GPIO_t* hal);

void GPIO_writePin(GPIO_t* hal, u8 state);

u8 GPIO_readPin(GPIO_t* hal);

void GPIO_voidSetPinValue(u8 Copy_u8Pin, u8 Copy_u8Val);



void GPIO_voidSetPinMode(u8 port ,u8 pin,u8 mode);

/*


PORTA
PORTB
PORTC

*/

void GPIO_voidSetPin(u8 port,u32 pin);


/*


PORTA
PORTB
PORTC

*/
void GPIO_voidResetPin(u8 port,u32 pin);

/*

PORTA
PORTB
PORTC

*/

void GPIO_voidSetPortValue(u8 port, u32 value);


/*
0
1
2
3
4
5
6
7
8
9
10
11
12
13
14
15

PORTA
PORTB
PORTC

*/

u8 GPIO_u8GetPinValue(u8 port,u8 pin);










