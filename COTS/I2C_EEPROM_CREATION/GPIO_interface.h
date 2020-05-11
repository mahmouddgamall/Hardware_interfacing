/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * File name: GPIO_interface.h                                                                         *
 *                                                                                                     *
 * Description: This Header file is used to interface with the GPIO module in ATmega32A evaluation kit *
 *                                                                                                     *
 * Author : Mohamed Adel Anis Ahmed				                                                       *
 * date   : 2 March 2020                                                                               *
 * version: 1.0                                                                                        *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#ifndef GPIO_INTERFACE_H_
#define GPIO_INTERFACE_H_


#define PORTA ( (void*) (0x39) )
#define PORTB ( (void*) (0x36) )
#define PORTC ( (void*) (0x33) )
#define PORTD ( (void*) (0x30) )

#define PIN0	(0x01)
#define PIN1	(0x02)
#define PIN2	(0x04)
#define PIN3	(0x08)
#define PIN4	(0x10)
#define PIN5	(0x20)
#define PIN6	(0x40)
#define PIN7	(0x80)

#define MODE_OUTPUT				(1)
#define MODE_INPUT_FLOATING		(0)
#define MODE_INPUT_PULLUP		(2)

#define HIGH	(1)
#define LOW		(0)

typedef struct{

	void* PORT;
	uint8_t PIN;
	uint8_t MODE;

}GPIO_PinConfig_t;

/***************************************************Prototypes************************************************************/

ErrorStatus_t GPIO_InitStr(GPIO_PinConfig_t* GPIO_PinConfig);
ErrorStatus_t GPIO_SetPinValue(GPIO_PinConfig_t* GPIO_PinConfig , uint8_t Value);
ErrorStatus_t GPIO_GetPinValue(GPIO_PinConfig_t* GPIO_PinConfig , uint8_t* Value);


ErrorStatus_t GPIO_InitPins(void* PORT , uint8_t PINs , uint8_t MODE);
ErrorStatus_t GPIO_writePinValue(void* PORT , uint8_t PIN , uint8_t Value);
ErrorStatus_t GPIO_writePortValue(void* PORT , uint8_t PortValue);
ErrorStatus_t GPIO_ReadPinValue(void* PORT , uint8_t PIN , uint8_t* Value);

#endif /* GPIO_INTERFACE_H_ */
