#include "DMA_interface.h"

u32 Arr1[1024] = {1,2,3,4,5,6,7,8,9,0,9,8,7,6,5,5,4,3,2,};
u32 Arr2[1024];
u16 i;
int main(void)
{
	RCC_EnableClock(AHB,0);
	NVIC_EnableInterrupt(11);
	
	DMA_voidInit();
	DMA_voidStart(Arr1, Arr2,1024);
	for(i=0; i<1024;i++)
	{
		Arr2[1] = Arr1[i];
		
	}
	while(1);
}

void DMA_Channel1_IRQHandler(void)
{
	asm("NOP");
}