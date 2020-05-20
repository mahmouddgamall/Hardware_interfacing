/**************************************************** 
 	 Author: Mahmoud Gamal
************************************************/
#ifndef AC_INTERFACE_H
#define AC_INTERFACE_H

#define	AC_POSITIVE_IS_GREATER		0x20
#define	AC_NEGATIVE_IS_GREATER		0

void AC_voidAnalogCompInit(void);

u8 AC_u8GetOutputValueSync(u8 * Output);
u8 AC_u8GetOutputValueAsync(u8 * Output, ptr2func_t cbfPositGretNegat, ptr2func_t cbfNegatGretPosit);

void AC_voidDisable(void);

#endif
