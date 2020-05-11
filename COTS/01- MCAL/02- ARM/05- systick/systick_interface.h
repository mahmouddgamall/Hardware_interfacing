#ifndef SYSTICK_INTERFACE_H
#define SYSTICK_INTERFACE_H


void STK_voidIntialize(void);
void STK_voidStart(u32 Copy_u32Value);
void STK_voidSetCallBack(void (*Copy_Ptr)(void));

#endif