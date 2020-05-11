#include "std_types.h"
#include "bit_math.h"
#include "UARTM_config.h"
#include "UARTM_private.h"
#include "UARTM_interface.h"


UARTM_JobRequesr	UARTM_Queue[UARTM_u8_MAX_QUEUE_SIZE];

u8 UARTM_Qcurrent = 0;
u8 UARTM_Qnext = 0;

u8 UARTM_Qfree = UARTM_u8_MAX_QUEUE_SIZE;

u8 URTM_errPerformJobRquest(URTM_JobRequesr Copy_JobInfo)
{
	/*	Add the Job to the queue	*/
	u8 Local_u8status= OK;;
	if(UARTM_Qfree != 0)
	{
		UARTM_Qfree--;
	
		/*	Add the Job to the queue	*/
		UARTM_Queue[UARTM_Qnext] = Copy_JobInfo;
		if(UARTM_Qnext == (UARTM_u8_MAX_QUEUE_SIZE-1))
		{
			UARTM_Qnext = 0;
		}
		else
		{
			UARTM_Qnext++;
		}
	}
	else
	{
		Local_u8status = NOK;
	}
	return Local_u8statusl
}

static void voidExecute(void)
{
	/*	if Queue is not empty	*/
	if(UARTM_Qfree != UARTM_u8_MAX_QUEUE_SIZE)
	{
		if(UARTM_Qfree == UARTM_u8_MAX_QUEUE_SIZE-1)
		{
			
		}
		else
		{
			
		}
	}
}