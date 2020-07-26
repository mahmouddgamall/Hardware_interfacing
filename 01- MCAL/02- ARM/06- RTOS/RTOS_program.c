#include "std_types.h"
#include "bit_math.h"
#include "RTOS_config.h"
#include "RTOS_private.h"
#include "RTOS_register.h"
#include "RTOS_interface.h"

#define NUM_OF_TASKS 2

Tasks SysTasks[NUM_OF_TASKS];
u32 RTOS_u8TickTime = 500000;
u8 Tick_Counter = 0;

void RTOS_voidStartOS(void)
{
	STK_voidSetCallBack(schedular);

	STK_voidStart(RTOS_u8TickTime);
}

void RTOS_voidCreateTask(priority, periodicity, handler)
{
	SysTasks[priority].periodicity = periodicity;
	SysTasks[priority].TaskHandler = handler;
}

void schedular(void)
{
	u8 i=0;
	Tick_Counter++;
	for( i=0 ; i < NUM_OF_TASKS ; i++ )
	{
		if(!(Tick_Counter % SysTasks[i].periodicity))
		{
			SysTasks[i].TaskHandler();
		}
	}
	if (Tick_Counter == 2)	Tick_Counter = 0;
}
