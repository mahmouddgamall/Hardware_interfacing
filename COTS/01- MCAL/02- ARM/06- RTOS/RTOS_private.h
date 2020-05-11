#ifndef RTOS_PRIVATE_H
#define RTOS_PRIVATE_H

typedef struct
{
	void (*TaskHandler)(void);
	u32 periodicity;
}Task;

#endif