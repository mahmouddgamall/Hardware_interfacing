#ifndef UARTM_INTERFACE_H
#define UARTM_INTERFACE_H

typedef struct
{
	u8 jobType;
	u8* dataBuffer;
	u8 length;
	void (*callBack)(void);
}UARTM_JobRequesr;

u8 UARTM_errPerformJobRquest(UARTM_JobRequesr Copy_JobInfo);


#endif