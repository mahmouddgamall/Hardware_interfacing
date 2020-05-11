/**************************************************** 
 	 Author: Mahmoud Gamal
************************************************/
#include "std_types.h"
#include "bit_math.h"
#include "SPI_config.h"
#include "SPI_private.h"
#include "SPI_register.h"
#include "SPI_interface.h"

#define SPI_DOUBLE_SPEED_MASK		0b11111110

/*	global variables of the buffers	*/
static u8 * SPI_pu8TxBuffer = NULL;
static u8 * SPI_pu8RxBuffer = NULL;
/*	globla variables to hold the value of the size of the buffers	*/
static u8 SPI_u8BufferSize;

/*	global pointer to the call back fuction	*/
static void (*SPI_pfNotificationFun)(void) = NULL;

/*	global index of the buffer	*/
static u8 SPI_u8BufferIndex = 0;

static u8 SPI_u8Flag = OK;

void SPI_voidInit(void)
{
	SPI_SPCR = (SPI_INTERRUPT | SPI_STATE | SPI_DATA_ORDER | SPI_MODE | SPI_LEADING_EDGE | SPI_FIRST_ACTION | SPI_PRESCHALER);
	SPI_SPSR &=	 SPI_DOUBLE_SPEED_MASK;                  
	SPI_SPSR |= SPI_DOUBLE_SPEED;
}

u8 SPI_errSendDataByteSynch(u8 Copy_u8Data)
{
	u8 Local_u8Dummy, Local_u8State = OK;
	u16 Local_timeOut;
	/*	send data	*/
	SPI_SPDR = Copy_u8Data;
	/*	check the collasion SPI_u8Flag	*/
	if(GET_BIT(SPI_SPSR, SPSR_WCOL))
	{
		Local_u8State = NOK;
	}

	/*	Polling on the SPI_u8Flag	*/
	while((GET_BIT(SPI_SPSR, SPSR_SPIF)==0) && (Local_timeOut < TIME_OUT))
	{
		Local_timeOut++;
	}
	if(Local_timeOut == TIME_OUT)
	{
		Local_u8State = TIMEOUT;
	}
	else
	{
		/* to clear the SPIF you must read this SPI_u8Flag and the data register */
		Local_u8Dummy = SPI_SPDR;
	}

	return Local_u8State;

}

u8 SPI_errRecieveDataByteSynch(u8 *Copy_pu8Data)
{
	u8 Local_u8Dummy, Local_u8State = OK;
	u16 Local_timeOut;

	/*	check that the recieved address is not NULL	*/
	if(Copy_pu8Data == NULL)
	{
		Local_u8State = NULLPOINTER;
	}
	else
	{
		/*	put any data in the SPI_SPDR to be able to transmit	*/
		SPI_SPDR = 0;

		/*	Polling on the SPI_u8Flag	*/
		while((GET_BIT(SPI_SPSR, SPSR_SPIF)==0) && (Local_timeOut < TIME_OUT))
		{
			Local_timeOut++;
		}
		if(Local_timeOut == TIME_OUT)
		{
			Local_u8State = TIMEOUT;
		}
		else
		{
			*Copy_pu8Data = SPI_SPDR;
		}
	}

	return Local_u8State;

}

u8 SPI_errSendReciveDataByteSynch(u8 Copy_u8SendData, u8* Copy_pu8ReciveData)
{
	u8 Local_u8Dummy, Local_u8State = OK;
	u16 Local_timeOut;
		/*	check that the recieved address is not NULL	*/
	if(Copy_pu8ReciveData == NULL)
	{
		Local_u8State = NULLPOINTER;
	}
	else
	{
		/*	send data	*/
		SPI_SPDR = Copy_u8SendData;
		/*	check the collasion SPI_u8Flag	*/
		if( GET_BIT(SPI_SPSR, SPSR_WCOL) )
		{
			Local_u8State = NOK;
		}

		/*	Polling on the SPI_u8Flag	*/
		while( (GET_BIT(SPI_SPSR, SPSR_SPIF)==0 ) && (Local_timeOut < TIME_OUT))
		{
			Local_timeOut++;
		}
		if(Local_timeOut == TIME_OUT)
		{
			Local_u8State = TIMEOUT;
		}
		else
		{
			/* to clear the SPIF you must read this SPI_u8Flag and the data register */
			*Copy_pu8ReciveData = SPI_SPDR;
		}

	}

	return Local_u8State;

}


u8 SPI_errSendReciveDataByteAsynch(u8* Copy_pu8TxBuffer, u8* Copy_pu8RxBuffer, u8 Copy_u8BufferSize, void(*cbf)(void))
{
	u8  Local_u8State = OK;
		/*	check that the recieved address is not NULL	*/
	if(Copy_pu8TxBuffer == NULL || Copy_pu8RxBuffer == NULL || cbf  == NULL || SPI_u8Flag == BUSY)
	{
		Local_u8State = NULLPOINTER;
	}
	else
	{
		SPI_u8Flag = BUSY;
		SPI_pu8TxBuffer = Copy_pu8TxBuffer;
		SPI_pu8RxBuffer = Copy_pu8RxBuffer;
		SPI_u8BufferSize = Copy_u8BufferSize;
		SPI_pfNotificationFun = cbf;

		/*	Transmit the first byte in the buffer	*/
		SPI_SPDR = SPI_pu8TxBuffer[SPI_u8BufferIndex];

	}

	return Local_u8State;

}


void __vector_12(void)
{
	SPI_pu8RxBuffer[SPI_u8BufferIndex] = SPI_SPDR;
	SPI_u8BufferIndex++;
	if(SPI_u8BufferIndex == SPI_u8BufferSize)
	{

		SPI_u8BufferIndex = SPI_u8BufferSize = 0;
		SPI_pfNotificationFun();
		SPI_u8Flag = OK;
	}
	else
	{
		SPI_SPDR = SPI_pu8TxBuffer[SPI_u8BufferIndex];
	}
}
