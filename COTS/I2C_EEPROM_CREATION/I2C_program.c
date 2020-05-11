/*
 * I2C_program.c
 *
 *  Created on: Apr 20, 2020
 *      Author: madel
 */
/*--------------------------------------------------------------------------------------------------------------------*/
/*+++++++++++++++++++++++++++++++++++++++++++++++++++++ Includes +++++++++++++++++++++++++++++++++++++++++++++++++++++*/
/*--------------------------------------------------------------------------------------------------------------------*/
#include "STD_TYPES.h"
#include "DELAY.h"

#include "GPIO_interface.h"
#include "I2C_interface.h"
#include "I2C_config.h"


/*--------------------------------------------------------------------------------------------------------------------*/
/*================================================ General Definitions ===============================================*/
/*--------------------------------------------------------------------------------------------------------------------*/

#define I2C_BASE_ADDRESS			 ( (volatile I2C_Registers_t*) (0x20))
#define TWCR						*( (volatile uint8_t*) (0x56))


#define TIMEOUT_VALUE				(500000)

#define TWIE						(0x01)
#define TWEN						(0x04)
#define TWWC						(0x08)
#define TWSTO						(0x10)
#define TWSTA						(0x20)
#define TWEA						(0x40)
#define TWINT						(0x80)

#define TWSR_TWS_MASK				(0xF8)
#define SLA_W_CODE					(0x00)

/* ACK Codes */
/* Master Transmission */

#define START_COND					(0x08)
#define REPEATED_START_COND         (0x10)
#define SEND_SLAVEADD_W_ACK         (0x18)
#define SEND_SLAVEADD_W_NACK        (0x20)
#define SEND_DATA_ACK               (0x28)
#define SEND_DATA_NACK              (0x30)
#define LOST_ARB_NOT_ADD            (0x38)

/* Master Receive */



/* Slave  Transmission */




/* Slave  Receive */





typedef struct{

	uint8_t TWBR;
	uint8_t TWSR;
	uint8_t TWAR;
	uint8_t TWDR;

}I2C_Registers_t;


typedef enum{

	Idle         = 0 ,
	Sending      = 1 ,
	Receving	 = 2
}I2C_MODDE;



static uint8_t I2C_State = Idle;



typedef struct{

	uint8_t CurrentCounter;
	uint8_t *BufferData;
	uint8_t  BufferSize;

#if   I2C_MODE_OPERATION == I2C_Transmition_MODE_ASYNC

	I2C_CBF_t I2C_CallBackFunction;

#elif I2C_MODE_OPERATION == I2C_Transmition_MODE_SYNC

	/* Do Nothing */

#else

#error "Wrong Mode Operation"

#endif

}I2C_Buffer_t;

I2C_Buffer_t I2C_TX_Buffer , I2C_RX_Buffer;

/*--------------------------------------------------------------------------------------------------------------------*/
/*############################################### APIs Implementation ################################################*/
/*--------------------------------------------------------------------------------------------------------------------*/

I2C_ErrorStatus_t I2C_Init(void)
{
	I2C_ErrorStatus_t Local_Error = I2C_ERROR_OK;
	volatile I2C_Registers_t *I2C_Registers = I2C_BASE_ADDRESS;


#if	I2C_NODE_MODE == I2C_MASTER_NODE


	I2C_Registers->TWBR = (uint8_t) ( ( ((uint32_t)I2C_SYS_CLK/I2C_SCL_SPEED) - 16 ) / (2 * I2C_RATE_PRESCALER) );

	/* Set the Prescaler */
	switch(I2C_RATE_PRESCALER)
	{
	case I2C_RATE_PRESCALER_1:
		I2C_Registers->TWSR &= 0xFC;
		break;

	case I2C_RATE_PRESCALER_4:
		I2C_Registers->TWSR |= 0x01;
		break;

	case I2C_RATE_PRESCALER_16:
		I2C_Registers->TWSR |= 0x02;
		break;

	case I2C_RATE_PRESCALER_64:
		I2C_Registers->TWSR |= 0x03;
		break;
	}

	I2C_Registers->TWAR = I2C_Slave_Address << 1 | I2C_GENERAL_CALL;

#elif I2C_NODE_MODE == I2C_SLAVE_NODE

	I2C_Registers->TWAR = I2C_Slave_Address << 1 | I2C_GENERAL_CALL;

#else

#error "Wrong Mode Option"

#endif

	/* Enable I2C Peripheral & Acknowledge */
	TWCR |= (TWEN | TWEA);



	return Local_Error;
}


I2C_ErrorStatus_t I2C_Master_TransmitData(uint8_t I2C_SLAVE_ADD  , uint8_t *I2C_TX_DataBuffer , uint8_t I2C_BufferSize)
{
	I2C_ErrorStatus_t Local_Error = I2C_ERROR_OK;
	volatile I2C_Registers_t *I2C_Registers = I2C_BASE_ADDRESS;
	uint32_t Timeout = 0;

	if( I2C_TX_DataBuffer )
	{

#if	I2C_NODE_MODE == I2C_MASTER_NODE

		/* Initialize Start Condition (put start condition and clear TWINT flag by setting it ) */

		TWCR |= TWINT | TWSTA ;



		/* wait for initialization to be done */
		while( ((TWCR & TWINT) != TWINT) && Timeout < TIMEOUT_VALUE  )
		{
			Timeout++;
		}


		/* check if the value is right */
		if(Timeout == TIMEOUT_VALUE)
		{
			Local_Error = I2C_ERROR_TIMEOUT;
			GPIO_writePortValue(PORTD,0x1);

		}

		else
		{
			GPIO_writePortValue(PORTD,0x2);

			if( (I2C_Registers->TWSR & TWSR_TWS_MASK) == START_COND )
			{

				/* Clear start condition */
				//TWCR &= ~TWSTA;

				/* write Slave Address with write operations (implicitly OR with Zero) */
				I2C_Registers->TWDR = ( I2C_SLAVE_ADD << 1 );

				/* Clear TWINT FLAG */
				TWCR |= TWINT;

				/* wait for initialization to be done */
				Timeout = 0;
				while(((TWCR & TWINT) != TWINT) && Timeout < TIMEOUT_VALUE  )
				{
					Timeout++;
				}

				/* check if the value is right */
				if(Timeout == TIMEOUT_VALUE)
				{
					Local_Error = I2C_ERROR_TIMEOUT;
					//GPIO_writePinValue(PORTD, PIN6, HIGH);
				}
				else
				{


					if( (I2C_Registers->TWSR & TWSR_TWS_MASK) == SEND_SLAVEADD_W_ACK )
					{
						if( I2C_State == Idle )
						{

							/* Save our buffer */
							I2C_State      = Sending;
							I2C_TX_Buffer.BufferData     = I2C_TX_DataBuffer;
							I2C_TX_Buffer.BufferSize     = I2C_BufferSize;
							I2C_TX_Buffer.CurrentCounter = 1;
							/* Load first data in DR */
							I2C_Registers->TWDR = ( I2C_TX_Buffer.BufferData[0] );

							/* Clear TWINT FLAG & Enabling the Interrupt */
							TWCR |= TWINT |TWIE;
						}
						else
						{
							Local_Error =  I2C_ERROR_BUSY;
						}
					}
					else if( (I2C_Registers->TWSR & TWSR_TWS_MASK) == SEND_SLAVEADD_W_NACK )
					{
						Local_Error = I2C_ERROR_SLA_W_ACK_FAILED;
					}
					else if( (I2C_Registers->TWSR & TWSR_TWS_MASK) == LOST_ARB_NOT_ADD )
					{
						Local_Error = I2C_ERROR_ARB_LOST_NOT_ADD;
					}
					else
					{
						/* This is Not understood case yet */
					}
				}

			}
			else
			{
				Local_Error = I2C_ERROR_STA_COND_ACK_FAILED;
			}
		}


#elif I2C_NODE_MODE == I2C_SLAVE_NODE



#else

#error "Wrong Mode Option"

#endif

	}
	else
	{
		Local_Error = I2C_ERRPR_NULL_POINTER;
	}
	return Local_Error;
}


/* Handlers */
#define I2C						__vector_19

#define ISR(vect)				void vect(void) __attribute__((signal,used));\
		void vect(void)




ISR(I2C)
{

	volatile I2C_Registers_t *I2C_Registers = I2C_BASE_ADDRESS;
	static uint8_t Error_NACK_Counter = 0;



#if	  I2C_NODE_MODE == I2C_MASTER_NODE

	switch(I2C_State)
	{
	case Sending:

		if( (I2C_Registers->TWSR & TWSR_TWS_MASK) == SEND_DATA_ACK )
		{
			Error_NACK_Counter = 0;
			if( I2C_TX_Buffer.CurrentCounter == I2C_TX_Buffer.BufferSize )
			{
				/* Clear TWINT FLAG && Stop the connection */
				TWCR |= TWINT |TWSTO ;

				/* Reset the internal reservoir */
				I2C_TX_Buffer.BufferData     = NULL;
				I2C_TX_Buffer.BufferSize     = 0;
				I2C_TX_Buffer.CurrentCounter = 0;
				I2C_State                    = Idle;

				/* Call the call back function if exists */
				if(I2C_TX_Buffer.I2C_CallBackFunction)
				{
					I2C_TX_Buffer.I2C_CallBackFunction(I2C_ERROR_OK);
				}

			}
			else
			{
				/* Load Current Byte data in DR */
				I2C_Registers->TWDR = ( I2C_TX_Buffer.BufferData[I2C_TX_Buffer.CurrentCounter] );

				/* Update the CurrentCounter */
				I2C_TX_Buffer.CurrentCounter++;

				/* Clear TWINT FLAG */
				TWCR |= TWINT;

			}

		}
		else if( (I2C_Registers->TWSR & TWSR_TWS_MASK) == SEND_DATA_NACK )
		{
			if( Error_NACK_Counter < 3  )
			{
				/* Load Previous Byte data in DR */
				I2C_Registers->TWDR = ( I2C_TX_Buffer.BufferData[I2C_TX_Buffer.CurrentCounter - 1] );

				/* update the Error Counter */
				Error_NACK_Counter++;

				/* Clear TWINT FLAG */
				TWCR |= TWINT;
			}
			else
			{
				/* Clear TWINT FLAG && Stop the connection */
				TWCR |= TWINT |TWSTO ;

				/* Reset the internal reservoir */
				I2C_TX_Buffer.BufferData     = NULL;
				I2C_TX_Buffer.BufferSize     = 0;
				I2C_TX_Buffer.CurrentCounter = 0;
				I2C_State                    = Idle;
				Error_NACK_Counter           = 0;

				/* Call the call back function if exists */
				if(I2C_TX_Buffer.I2C_CallBackFunction)
				{
					I2C_TX_Buffer.I2C_CallBackFunction(I2C_ERROR_DATA_NACK);
				}
			}
		}
		else if( (I2C_Registers->TWSR & TWSR_TWS_MASK) == LOST_ARB_NOT_ADD )
		{
			/* Reset the internal reservoir */
			I2C_TX_Buffer.BufferData     = NULL;
			I2C_TX_Buffer.BufferSize     = 0;
			I2C_TX_Buffer.CurrentCounter = 0;
			I2C_State                    = Idle;
			Error_NACK_Counter           = 0;

			/* Call the call back function if exists */
			if(I2C_TX_Buffer.I2C_CallBackFunction)
			{
				I2C_TX_Buffer.I2C_CallBackFunction(I2C_ERROR_ARB_LOST_NOT_ADD);
			}
		}
		break;

	case Receving:



		break;
	}

#elif I2C_NODE_MODE == I2C_SLAVE_NODE

#else
#error "Wrong Mode Option"
#endif
}


I2C_ErrorStatus_t I2C_Set_TX_CallBackFunction(I2C_CBF_t I2C_CBF)
{
	I2C_ErrorStatus_t Local_Error = I2C_ERROR_OK;
	if(I2C_CBF)
	{
		I2C_TX_Buffer.I2C_CallBackFunction = I2C_CBF;
	}
	else
	{
		Local_Error = I2C_ERRPR_NULL_POINTER;
	}

	return Local_Error;
}

