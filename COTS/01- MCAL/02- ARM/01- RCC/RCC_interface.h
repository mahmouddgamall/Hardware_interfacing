#ifndef RCC_INTERFACE_H
#define RCC_INTERFACE_H


#define	HSI_VAL							(u8)0
#define	HSE_VAL							(u8)1
#define	PLL_VAL							(u8)2
#define	SW_PIN							(u8)0
#define	SWS_PIN							(u8)2

#define SW_CLEAR						(u8)0b11

#define HSEDIV2_check				(u8)2
#define HSEDIV2_VAL					(u8)0

#define PLLHSE							(u8)0
#define PLLHS1							(u8)1

#define	HSION								(u8)0
#define	HSEON								(u8)16
#define	PLLON								(u8)24

#define	HSIRDY							(u8)1
#define	HSERDY							(u8)17
#define	PLLRDY							(u8)25

#define	CSSON								(u8)19
#define	HSEBYP							(u8)18

#define	PLLXTPRE						(u8)17
#define	PLLSRC							(u8)16
#define	PLLMUL							(u8)18

#define	PPRE2								(u8)11
#define	PPRE1								(u8)8
#define	HPRE								(u8)4


#define	AHB									(u8)0
#define	APB2								(u8)1
#define	APB1								(u8)2

#define PLLMULL_CLEAR					(u8)0b1111
#define PLLMUL2								(u8)0
#define PLLMUL3								(u8)1
#define PLLMUL4								(u8)2
#define PLLMUL5								(u8)3
#define PLLMUL6								(u8)4
#define PLLMUL7								(u8)5
#define PLLMUL8								(u8)6
#define PLLMUL9								(u8)7
#define PLLMUL10							(u8)8
#define PLLMUL11							(u8)9
#define PLLMUL12							(u8)10
#define PLLMUL13							(u8)11
#define PLLMUL14							(u8)12
#define PLLMUL15							(u8)13
#define PLLMUL16							(u8)14


#define	DMA1EN_AHBENR				(u8)0
#define	DMA2EN_AHBENR				(u8)1
#define	SRAMEN_AHBENR				(u8)2
#define	FLITFEN_AHBENR			(u8)4
#define	CRCEEN_AHBENR				(u8)6
#define	FSMCEN_AHBENR				(u8)8
#define	SDIOEN_AHBENR				(u8)10

#define	AFIOEN_APB2ENR			(u8)32
#define	IOPAEN_APB2ENR			(u8)34
#define	IOPBEN_APB2ENR			(u8)35
#define	IOPCEN_APB2ENR			(u8)36
#define	IOPDEN_APB2ENR			(u8)37
#define	IOPEEN_APB2ENR			(u8)38
#define	IOPFEN_APB2ENR			(u8)39
#define	IOPGEN_APB2ENR			(u8)40
#define	ADC1EN_APB2ENR			(u8)41
#define	ADC2EN_APB2ENR			(u8)42
#define	TIM1EN_APB2ENR			(u8)43
#define	SPI1EN_APB2ENR			(u8)44
#define	TIM8EN_APB2ENR			(u8)45
#define	USART1EN_APB2ENR		(u8)46
#define	ADC3EN_APB2ENR			(u8)47
#define	TIM9EN_APB2ENR			(u8)51
#define	TIM10EN_APB2ENR			(u8)52
#define	TIM11EN_APB2ENR			(u8)53

#define	TIM2EN_APB1ENR			(u8)64
#define	TIM3EN_APB1ENR			(u8)65
#define	TIM4EN_APB1ENR			(u8)66
#define	TIM5EN_APB1ENR			(u8)67
#define	TIM6EN_APB1ENR			(u8)68
#define	TIM7EN_APB1ENR			(u8)69
#define	TIM12EN_APB1ENR			(u8)70
#define	TIM13EN_APB1ENR			(u8)71
#define	TIM14EN_APB1ENR			(u8)72
#define	WWDEN_APB1ENR				(u8)75
#define	SPI2EN_APB1ENR			(u8)78
#define	USART2EN_APB1ENR		(u8)81
#define	USART3EN_APB1ENR		(u8)82
#define	I2C1EN_APB1ENR			(u8)85
#define	I2C2EN_APB1ENR			(u8)86
#define	USBEN_APB1ENR				(u8)87
#define	CANEN_APB1ENR				(u8)89
#define	BKPEN_APB1ENR				(u8)91
#define	PWREN_APB1ENR				(u8)92
#define	DACEN_APB1ENR				(u8)93



#define MCO_PIN							(u8)24
#define	MCO_NO_CLOCK				(u8)0
#define	MCO_SYS_CLOCK				(u8)4
#define	MCO_HSI_CLOCK				(u8)5
#define	MCO_HSE_CLOCK				(u8)6
#define	MCO_PLL_CLOCK				(u8)7

#define	APB2_PRESCHALER_PIN		(u8)11

#define APB2_CLEAR_BITS			(u8)0b111

#define	APB2_NO_DIVISOR			(u8)0
#define	APB2_2_DIVISOR			(u8)4
#define	APB2_4_DIVISOR			(u8)5
#define	APB2_8_DIVISOR			(u8)6
#define	APB2_16_DIVISOR			(u8)7



#define	APB1_PRESCHALER_PIN		(u8)8


#define APB1_CLEAR_BITS			(u8)0b111

#define	APB1_NO_DIVISOR			(u8)0
#define	APB1_2_DIVISOR			(u8)4
#define	APB1_4_DIVISOR			(u8)5
#define	APB1_8_DIVISOR			(u8)6
#define	APB1_16_DIVISOR			(u8)7

#define	AHB_PRESCHALER_PIN		(u8)4

#define AHB_CLEAR_BITS			(u8)0b1111

#define	AHB_NO_DIVISOR			(u8)0
#define	AHB_2_DIVISOR			(u8)0b1000
#define	AHB_4_DIVISOR			(u8)0b1001
#define	AHB_8_DIVISOR			(u8)0b1010
#define	AHB_16_DIVISOR			(u8)0b1011
#define	AHB_64_DIVISOR			(u8)0b1100
#define	AHB_128_DIVISOR			(u8)0b1101
#define	AHB_256_DIVISOR			(u8)0b1110
#define	AHB_512_DIVISOR			(u8)0b1111





u8 rcc_u8Clock (u8 clockSource);

u8 rcc_u8PllEnable (u8 pllmul, u8 pllsrc);

void rcc_voidEnablePeripheral (u8 peripheral);

void rcc_voidDisablePeripheral (u8 peripheral);

void rcc_voidsetMCO(u8 mcosrc);

void rcc_voidAHBprescaler(u8 prescaler);

void rcc_voidAPB2prescaler(u8 prescaler);

void rcc_voidAPB1prescaler(u8 prescaler);



#endif
