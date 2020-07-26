#ifndef RTOS_INTERFACE_H
#define RTOS_INTERFACE_H


extern void RTOS_voidStartOS(void);

extern void RTOS_voidCreateTask(priority, periodicity, handler);

extern void schedular(void);

#endif