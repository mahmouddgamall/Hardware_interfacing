/*
 * I2C_interface.h
 *
 *  Created on: Apr 20, 2020
 *      Author: madel
 */

#ifndef I2C_INTERFACE_H_
#define I2C_INTERFACE_H_

#include "I2C_config.h"

/*--------------------------------------------------------------------------------------------------------------------*/
/*+++++++++++++++++++++++++++++++++++++++++++++ General Configuration ++++++++++++++++++++++++++++++++++++++++++++++++*/
/*--------------------------------------------------------------------------------------------------------------------*/

/* I2C NODE Mode */
#define I2C_MASTER_NODE						(1)
#define I2C_SLAVE_NODE						(0)

/* I2C NODE Mode */
#define I2C_Transmition_MODE_ASYNC			(1)
#define I2C_Transmition_MODE_SSYNC			(0)

/* I2C System Clock */
#define I2C_SYS_CLK_1MHZ					(1000000)
#define I2C_SYS_CLK_8MHZ					(8000000)
#define I2C_SYS_CLK_12MHZ					(12000000)

/* I2C Rate Prescaler */
#define I2C_RATE_PRESCALER_1				(1)
#define I2C_RATE_PRESCALER_4				(4)
#define I2C_RATE_PRESCALER_16				(16)
#define I2C_RATE_PRESCALER_64				(64)

/* I2C SDL Speed */
#define I2C_SCL_SPEED_100KHZ				(100000)
#define I2C_SCL_SPEED_400KHZ				(400000)

/* I2C Slave General Call Recognition */
#define I2C_GENERAL_CALL_EN					(0x01)
#define I2C_GENERAL_CALL_DS					(0x00)


typedef uint8_t I2C_ErrorStatus_t;

#define I2C_ERROR_OK						(0)
#define I2C_ERRPR_NULL_POINTER				(2)
#define I2C_ERROR_BUSY						(3)
#define I2C_ERROR_TIMEOUT					(4)
#define I2C_ERROR_STA_COND_ACK_FAILED		(5)
#define I2C_ERROR_SLA_W_ACK_FAILED			(6)
#define I2C_ERROR_ARB_LOST_NOT_ADD			(7)
#define I2C_ERROR_DATA_NACK					(8)


typedef void(*I2C_CBF_t)(I2C_ErrorStatus_t I2C_ErrorStatus);
/******************************************************** Prototypes ********************************************************/

I2C_ErrorStatus_t I2C_Init(void);


I2C_ErrorStatus_t I2C_Master_TransmitData(uint8_t I2C_SlaveAddress  , uint8_t *I2C_TX_DataBuffer , uint8_t I2C_BufferSize);
I2C_ErrorStatus_t I2C_Master_ReceiveData( uint8_t I2C_SlaveAddress  , uint8_t *I2C_RX_DataBuffer , uint8_t I2C_BufferSize);

I2C_ErrorStatus_t I2C_Slave_TransmitData(uint8_t *I2C_TX_DataBuffer , uint8_t I2C_BufferSize);
I2C_ErrorStatus_t I2C_Slave_ReceiveData( uint8_t *I2C_RX_DataBuffer , uint8_t I2C_BufferSize);

I2C_ErrorStatus_t I2C_Set_TX_CallBackFunction(I2C_CBF_t I2C_CBF);
I2C_ErrorStatus_t I2C_Set_RX_CallBackFunction(I2C_CBF_t I2C_CBF);

#endif /* I2C_INTERFACE_H_ */
