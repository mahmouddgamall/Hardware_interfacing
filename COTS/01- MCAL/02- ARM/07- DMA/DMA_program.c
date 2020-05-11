#include "std_types.h"
#include "bit_math.h"
#include "DMA_config.h"
#include "DMA_private.h"
#include "DMA_register.h"
#include "DMA_interface.h"


void DMA_init(void)
{
	/*Enable M2M*/
	/*	Data Size 32	*/
	/*	MINC & PINC =1	*/
	/*	Not circular	*/
	/*	CPAR -> CMAR	*/
	/*	Transmission Complete Interruor	*/
	DMA->Channel[0].CCR = 0x00007AC2;
}
void DMA_Start(u32 Copy_u32SourceAddress, u32 Copy_u32DestinationAddress,u16 Copy_u16BlockLength)
{
	DMA->Channel[0].CPAR = Copy_u32SourceAddress;
	DMA->Channel[0].CMAR = Copy_u32DestinationAddress;
	DMA->Channel[0].CNDTR = Copy_u16BlockLength;
	
	/*	DMA Channel 1 Enable	*/
	DMA->Channel |= 1;
}