/**************************************************** 
 	 Author: Mahmoud Gamal
************************************************/
#ifndef SPI_INTERFACE_H
#define SPI_INTERFACE_H


void SPI_voidInit(void);

u8 SPI_errSendDataByteSynch(u8 Copy_u8Data);
u8 SPI_errRecieveDataByteSynch(u8 *Copy_pu8Data);

u8 SPI_errSendReciveDataByteSynch(u8 Copy_u8SendData, u8* Copy_pu8ReciveData);

u8 SPI_errSendReciveDataByteAsynch(u8* Copy_pu8TxBuffer, u8* Copy_pu8RxBuffer, u8 Copy_u8BufferSize, void(*cbf)(void));




#endif
