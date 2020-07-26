/***************************************************
Author	: Mahmoud Gamal
Date		: 10 March 2020
Version	: V01

***************************************************/
#ifndef DMA_INTERFACE_H
#define DMA_INTERFACE_H

void DMA_init(void);

void DMA_Start(u32 Copy_u32SourceAddress, u32 Copy_u32DestinationAddress,u16 Copy_u16BlockLength);
#endif