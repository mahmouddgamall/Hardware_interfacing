/**************************************************** 
 	 Author: Mahmoud Gamal
************************************************/

#ifndef I2C_INTERFACE_H
#define I2C_INTERFACE_H

typedef enum name
{
	I2C_SC_ERROR,
	I2C_RSC_ERROR,
	I2C_SLA_ERROR,
	I2C_DATA_ERROR,
	I2C_MR_DATA_ERROR,
	I2C_MT_DATA_ERROR


}I2C_ERROR_STATUS;

void I2c_voidMasterInit(void);
void I2c_voidSlaveInit(u8 Copy_u8SlaveAddress);

I2C_ERROR_STATUS I2c_errSendStartCondition(void);
I2C_ERROR_STATUS I2c_errSendRestartCondition(void);


I2C_ERROR_STATUS I2c_errSendSlaveAddressWrite(u8 Copy_u8SlaveAddress);
I2C_ERROR_STATUS I2c_errSendSlaveAddressRead(u8 Copy_u8SlaveAddress);

I2C_ERROR_STATUS I2c_errMasterSendDataByte(u8 Copy_u8Data);
I2C_ERROR_STATUS I2c_errMasterReadDataByte(u8 *Copy_u8Data);

void I2c_voidSendStopCondition(void);

#endif
