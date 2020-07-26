#include "STD_TYPES.h"

#include "GPIO_interface.h"
#include "I2C_interface.h"

void I2C_alg(I2C_ErrorStatus_t I2C_ErrorStatus);

int main(void)
{
	GPIO_InitPins(PORTD, PIN0|PIN1|PIN2|PIN3|PIN4|PIN7|PIN5 | PIN6, MODE_OUTPUT);

	I2C_Set_TX_CallBackFunction(&I2C_alg);

	I2C_Init();

	uint8_t Buffer[1] = {0x52};

	I2C_Master_TransmitData(I2C_SLAVE_ADD_MAR_MCU , Buffer , 1);

	while(1)
	{

	}

	return 0;
}

void I2C_alg(I2C_ErrorStatus_t I2C_ErrorStatus)
{
	GPIO_writePinValue(PORTD, PIN5, HIGH);
}

