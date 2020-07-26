#ifndef ADC_REGISTER_H
#define ADC_REGISTER_H

#define     ADMUX    *((u8*volatile)0x27)     
#define     ADCSRA   *((u8*volatile)0x26)
#define     ADCH     *((u8*volatile)0x25)		/*	note that to use this register you must use the left adjustment	*/
#define     ADCL     *((u8*volatile)0x24)

#define     SFIOR    *((u8*volatile)0x50)

#define     ADCL_ADCH     *((u16*volatile)0x24)		/*	note that if you are using this register you must use the right adjustment	*/

#endif
