/**************************************************** 
 	 Author: Mahmoud Gamal
************************************************/
#ifndef AC_CONFIG_H
#define AC_CONFIG_H

/***********************************
OPTIONS:
AC_SFIOR_MULTIPLEXER_ENABLE
AC_SFIOR_MULTIPLEXER_DISABLE

************************************/
#define		AC_SFIOR_MULTIPLEXER 	AC_SFIOR_MULTIPLEXER_DISABLE

/***********************************
OPTIONS:
AC_ACSR_POSITIVE_BANDGAP_REFERNCE_VOLTAGE
AC_ACSR_POSITIVE_BANDGAP_REFERNCE_AIN0

************************************/

#define	AC_POSITIVE_BANDGAP_REFERNCE_VOLTAGE	AC_ACSR_POSITIVE_BANDGAP_REFERNCE_AIN0

/***********************************
OPTIONS:
AC_ACSR_INTERRUPT_ENABLE
AC_ACSR_INTERRUPT_DISABLE

************************************/
#define	AC_INTERRUPT_STATUS 	AC_ACSR_INTERRUPT_ENABLE




/***********************************
OPTIONS:
AC_ACSR_INTERRUPT_ON_TOGGLE
AC_ACSR_INTERRUPT_ON_FALLING_EDGE
AC_ACSR_INTERRUPT_ON_RISING_EDGE
************************************/

#define AC_INTERRUPT_MODE	AC_ACSR_INTERRUPT_ON_TOGGLE


/***********************************
OPTIONS:
AC_ACSR_INPUT_CAPTURE_ENABLE
AC_ACSR_INPUT_CAPTURE_DISABLE

************************************/

#define	AC_INPUT_CAPTURE_STATUS	AC_ACSR_INPUT_CAPTURE_DISABLE


/***********************************
OPTIONS:
AC_NEGATIVE_PIN_INPUT_ANI
AC_NEGATIVE_PIN_INPUT_ADC_CHANNEL_0
AC_NEGATIVE_PIN_INPUT_ADC_CHANNEL_1
AC_NEGATIVE_PIN_INPUT_ADC_CHANNEL_2
AC_NEGATIVE_PIN_INPUT_ADC_CHANNEL_3
AC_NEGATIVE_PIN_INPUT_ADC_CHANNEL_4
AC_NEGATIVE_PIN_INPUT_ADC_CHANNEL_5
AC_NEGATIVE_PIN_INPUT_ADC_CHANNEL_6
AC_NEGATIVE_PIN_INPUT_ADC_CHANNEL_7

************************************/
#define	AC_NEGATIVE_CHANNLE		AC_NEGATIVE_PIN_INPUT_ANI


#define	ADMUX_MASK				0XF8


















#endif
