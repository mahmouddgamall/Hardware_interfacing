#ifndef NVIC_INTERFACE_H
#define NVIC_INTERFACE_H

extern void NVIC_voidEnableExternalInterrupt(u8 Copy_u8Idx);
extern void NVIC_voidDisableExternalInterrupt(u8 Copy_u8Idx);


extern void NVIC_voidSetPendingFlag(u8 Copy_u8Idx);
extern void NVIC_voidClearPendingFlag(u8 Copy_u8Idx);


extern u8 NVIC_u8GetActiveFlag(u8 Copy_u8Idx);

extern void NVIC_voidInitPriority(void);

extern void NVIC_voidSetPriority(u8 Copy_u8Idx, u8 Copy_u8Priority);


#endif