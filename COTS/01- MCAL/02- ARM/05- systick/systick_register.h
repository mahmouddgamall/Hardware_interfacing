#ifndef SYSTICK_REGISTER_H
#define SYSTICK_REGISTER_H

#define BASE_ADDRESS			0xE000E010

#define	STK_CTRL					*((volatile u32*)BASE_ADDRESS)
#define	STK_LOAD					*((volatile u32*)(BASE_ADDRESS+4))
#define	STK_VAL						*((volatile u32*)(BASE_ADDRESS+8))
#define	STK_CALIB					*((volatile u32*)(BASE_ADDRESS+0xCs))


#endif