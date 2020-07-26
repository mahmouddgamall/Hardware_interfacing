#include "std_types.h"
#include "bit_math.h"

#include "INTGBL_register.h"
#include "INTGBL_interface.h"



void INT_voidEnableGlobal(void)
{
	SET_BIT(SREG,SREG_I);
}
void INT_voidDisableGlobal(void)
{
	CLR_BIT(SREG,SREG_I);
}