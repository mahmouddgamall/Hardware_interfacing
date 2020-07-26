/**************************************************** 
 	 Author: Mahmoud Gamal
************************************************/
#include "std_types.h"
#include "bit_math.h"

#include "I2C_interface.h"

#include "EEPROM_config.h"
#include "EEPROM_private.h"
#include "EEPROM_interface.h"


void EEPROM_voidInitComm(void)
{
	I2c_voidMasterInit();
}

u8 EEPROM_u8WriteDataByte(u16 Copy_u16ByteAdress, u8 Copy_u8Data)
{
	/*	To understand this sequence, you should check the datasheet page 11	*/
	u8 ErrorState = OK;

	/*	I2C start condition	*/
	ErrorState = I2c_errSendStartCondition();
	/*	Send the default address(1010) + A2 A1 A0	*/
	ErrorState = I2c_errSendSlaveAddressWrite(EEPROM_FIXED_ADDRESS | ((Copy_u16ByteAdress >> 8 ) & 7) );
	/*	Send the rest of the address	*/
	ErrorState = I2c_errMasterSendDataByte((u8)Copy_u16ByteAdress);
	/*	Send Actual Data */
	ErrorState = I2c_errMasterSendDataByte(Copy_u8Data);
	/*	I2C stop condition	*/
	I2c_voidSendStopCondition();
	return ErrorState;
}


/*u8 EEPROM_u8WriteDataBuffer(u16 Copy_u16ByteAdress, u8* Copy_u8Data, u8 Copy_u8Size)
{
	u8 ErrorState = OK;

		I2C start condition
	ErrorState = I2c_errSendStartCondition();
		Send the default address(1010) + A2 A1 A0
	ErrorState = I2c_errSendSlaveAddressWrite(EEPROM_FIXED_ADDRESS | ((Copy_u16ByteAdress >> 8 ) & 7) );
		Send the rest of the address
	ErrorState = I2c_errMasterSendDataByte((u8)Copy_u16ByteAdress);
	for(u8 i = 0 ; i < Copy_u8Size ; i ++)
	{
			Send Actual Data
		ErrorState = I2c_errMasterSendDataByte(Copy_u8Data[i]);
		_delay_ms(5);
	}
		I2C stop condition
	I2c_voidSendStopCondition();
	return ErrorState;
}*/

u8 EEPROM_u8ReadDataByte(u16 Copy_u16ByteAdress, u8* Copy_pu8Data)
{

	/*	To understand this sequence, you should check the datasheet page 12	*/
	u8 ErrorState = OK;

	/*	I2C start condition	*/
	ErrorState = I2c_errSendStartCondition();
	/*	Send the default address(1010) + A2 A1 A0	*/
	ErrorState = I2c_errSendSlaveAddressWrite(EEPROM_FIXED_ADDRESS | ((Copy_u16ByteAdress >> 8 ) & 7) );
	/*	Send the rest of the address	*/
	ErrorState = I2c_errMasterSendDataByte((u8)Copy_u16ByteAdress);
	/*	restart condition	*/
	ErrorState = I2c_errSendRestartCondition();
	/*	I2C REstart condition	*/
	ErrorState = I2c_errSendSlaveAddressRead(EEPROM_FIXED_ADDRESS | ((Copy_u16ByteAdress >> 8 ) & 7));
	/*	Send Actual Data */
	ErrorState = I2c_errMasterReadDataByte(Copy_pu8Data);
	/*	I2C stop condition	*/
	I2c_voidSendStopCondition();
	return ErrorState;
}

