/**************************************************** 
 	 Author: Mahmoud Gamal
************************************************/
#ifndef AC_PRIVATE_H
#define AC_PRIVATE_H

#define	AC_SFIOR_MULTIPLEXER_ENABLE				0x08
#define	AC_SFIOR_MULTIPLEXER_DISABLE			0x00
#define	AC_SFIOR_MULTIPLEXER_MASK				0xF7

#define	AC_ACSR_DISABLE_PERIPHERAL				0x80
#define	AC_ACSR_DISABLE_PERIPHERAL_MASK			0x7F

#define	AC_ACSR_POSITIVE_BANDGAP_REFERNCE_VOLTAGE		0x40
#define	AC_ACSR_POSITIVE_BANDGAP_REFERNCE_AIN0			0x00
#define	AC_ACSR_BANDGAP_MASK					0xBF

#define	AC_ACSR_INTERRUPT_ENABLE				0x08
#define	AC_ACSR_INTERRUPT_DISABLE				0x00
#define	AC_ACSR_INTERRUPT_MASK					0xF7

#define	AC_ACSR_INPUT_CAPTURE_ENABLE			0x04
#define	AC_ACSR_INPUT_CAPTURE_DISABLE			0x00
#define	AC_ACSR_INPUT_CAPTURE_MASK				0xFB


/*	+ve > -ve then ACO = 1 else ACO =0		*/

#define	AC_ACSR_ACO								0x20




/*	Macros for Negatrive pin input	*/

#define AC_NEGATIVE_PIN_INPUT_AIN1				8
#define AC_NEGATIVE_PIN_INPUT_ADC_CHANNEL_0		0
#define AC_NEGATIVE_PIN_INPUT_ADC_CHANNEL_1		1
#define AC_NEGATIVE_PIN_INPUT_ADC_CHANNEL_2		2
#define AC_NEGATIVE_PIN_INPUT_ADC_CHANNEL_3		3
#define AC_NEGATIVE_PIN_INPUT_ADC_CHANNEL_4		4
#define AC_NEGATIVE_PIN_INPUT_ADC_CHANNEL_5		5
#define AC_NEGATIVE_PIN_INPUT_ADC_CHANNEL_6		6
#define AC_NEGATIVE_PIN_INPUT_ADC_CHANNEL_7		7

/*	Interrupt modes	*/

#define	AC_ACSR_INTERRUPT_ON_TOGGLE				0
#define	AC_ACSR_INTERRUPT_ON_FALLING_EDGE		2
#define	AC_ACSR_INTERRUPT_ON_RISING_EDGE		3
#define AC_ACSR_INTERRUP_MODE_MASK				0xFC


#endif
