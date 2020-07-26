#include "std_types.h"
#include "bit_math.h"
#include "systick_config.h"
#include "systick_private.h"
#include "systick_register.h"
#include "systick_interface.h"


void (* Systick_CallBack))(void);

void STK_voidIntialize(void)
{
	/*	Enable SYSTICK interrupt, Clock = AHB/8	*/
	STK_CTRL = 0x00000002;
}
void STK_voidStart(u32 Copy_u32Value)
{
	STK_LOAD = Copy_u32Value;	/*	Put the intial Value in STL_LOAD	*/
	
	STK_VAL = 0;	/*	Make sure that the intial timer calue is = 0, to take the STK_LOAD right now	*/
	
	SET_BIT(STK_CTRL, 0);			/*	Start the counter	*/
	
}
void STK_voidSetCallBack(void (*Copy_Ptr)(void))
{
	Systick_CallBack = Copy_Ptr;
}

void Systick_Handler(void)
{
	SysTick_CallBack();
}