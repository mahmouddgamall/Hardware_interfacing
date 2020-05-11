#include "std_types.h"
#include "bit_math.h"
#include "I2C_config.h"
#include "I2C_private.h"
#include "I2C_register.h"
#include "I2C_interface.h"



void I2c_voidMasterInit(void)
{
	/*	set frequency, preschaler 0	*/
	CLR_BIT(TWSR,TWSR_TWPS1);
	CLR_BIT(TWSR,TWSR_TWPS0);
	TWBR = 0x02;

	/*	Enable I2C	*/
	SET_BIT(TWCR,TWCR_TWEN);

	/*	Enable ACK	*/
	SET_BIT(TWCR,TWCR_TWEA);


}
void I2c_voidSlaveInit(u8 Copy_u8SlaveAddress)
{
	/*	SET SLAVE ADDRESS	*/	
	TWAR = Copy_u8SlaveAddress;


	/*	Enable I2C	*/
	SET_BIT(TWCR,TWCR_TWEN);

	/*	Enable ACK	*/
	SET_BIT(TWCR,TWCR_TWEA);

}


I2C_ERROR_STATUS I2c_errSendStartCondition(void)
{
	u8 Local_u8Error = OK;
	/*	Clear Flag	*/
	SET_BIT(TWCR, TWCR_TWINT);

	/*	Start Condition	*/
	SET_BIT(TWCR, TWCR_TWSTA);

	/*	To make sure that the start condition is done: polling on flag	*/
	while(!GET_BIT(TWCR, TWCR_TWINT));

	if((TWSR & I2C_STATUS_CODE_MASK) != I2C_MT_SC_ACK)
	{
		Local_u8Error = I2C_SC_ERROR;
	}
	else
	{

	}
	return Local_u8Error;


}
I2C_ERROR_STATUS I2c_errSendRestartCondition(void)
{
	u8 Local_u8Error = OK;
	/*	Clear Flag	*/
	SET_BIT(TWCR, TWCR_TWINT);

	/*	Start Condition	*/
	SET_BIT(TWCR, TWCR_TWSTA);

	/*	To make sure that the REstart condition is done: polling on flag	*/
	while(!GET_BIT(TWCR, TWCR_TWINT));

	if((TWSR & I2C_STATUS_CODE_MASK) != I2C_MT_RSC_ACK)
	{
		Local_u8Error = I2C_RSC_ERROR;
	}
	else
	{

	}	
	return Local_u8Error;
}


I2C_ERROR_STATUS I2c_errSendSlaveAddressWrite(u8 Copy_u8SlaveAddress)
{
	u8 Local_u8Error = OK;

	/*	Write the address in the register,	shift by 1, because thats how the register is	*/
	TWDR = (Copy_u8SlaveAddress<<1);

	/*	clear last bit to indicate the writing operation	*/
	CLR_BIT(TWDR,0);

	/*	clear start condition	*/
	SET_BIT(TWCR, TWCR_TWINT);


	/*	To make sure that the condition is done: polling on flag	*/
	while(!GET_BIT(TWCR, TWCR_TWINT));

	if((TWSR & I2C_STATUS_CODE_MASK) != I2C_MT_SLA_W_ACK)
	{
		Local_u8Error = I2C_SLA_ERROR;
	}
	else
	{

	}	
	return Local_u8Error;

}
I2C_ERROR_STATUS I2c_errSendSlaveAddressRead(u8 Copy_u8SlaveAddress)
{
	u8 Local_u8Error = OK;

	/*	Write the address in the register,	shift by 1, because thats how the register is	*/
	TWDR = (Copy_u8SlaveAddress<<1);

	/*	Set last bit to indicate the reading operation	*/
	SET_BIT(TWDR,0);

	/*	clear start condition	*/
	SET_BIT(TWCR, TWCR_TWINT);

	while(!GET_BIT(TWCR, TWCR_TWINT));


	if((TWSR & I2C_STATUS_CODE_MASK) != I2C_MR_SLA_R_ACK)
	{
		Local_u8Error = I2C_SLA_ERROR;
	}
	else
	{

	}	
	return Local_u8Error;
}

I2C_ERROR_STATUS I2c_errMasterSendDataByte(u8 Copy_u8Data)
{
	u8 Local_u8Error = OK;

	/*	write data to the register	*/
	TWDR = Copy_u8Data;


	/*	clear start Condition flag	*/
	SET_BIT(TWCR, TWCR_TWINT);

	/*	polling on flag to make sure 	*/
	while(!GET_BIT(TWCR, TWCR_TWINT));

	if((TWSR & I2C_STATUS_CODE_MASK) != I2C_MT_DATA_ACK)
	{
		Local_u8Error = I2C_MT_DATA_ERROR;
	}
	else
	{

	}	

	return Local_u8Error;

}
I2C_ERROR_STATUS I2c_errMasterReadDataByte(u8 *Copy_u8Data)
{
		u8 Local_u8Error = OK;

	/*	clear start Condition flag	*/
	SET_BIT(TWCR, TWCR_TWINT);

	/*	polling on flag to make sure 	*/
	while(!GET_BIT(TWCR, TWCR_TWINT));


	if((TWSR & I2C_STATUS_CODE_MASK) != I2C_MR_DATA_ACK)
	{
		Local_u8Error = I2C_MR_DATA_ERROR;
	}
	else
	{
		*Copy_u8Data = TWDR;
	}	
		return Local_u8Error;
	
}

void I2c_voidSendStopCondition(void)
{

	/*	clear start Condition flag	*/
	SET_BIT(TWCR, TWCR_TWINT);

	/*	Stop condition	*/
	SET_BIT(TWCR,TWCR_TWSTO);
}
