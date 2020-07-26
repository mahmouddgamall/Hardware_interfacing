/**************************************************** 
 	 Author: Mahmoud Gamal
************************************************/
#include "std_types.h"
#include "bit_math.h"
#include "WDT_config.h"
#include "WDT_private.h"
#include "WDT_register.h"
#include "WDT_interface.h"



void WDT_voidSleep(u8 WDT_SLEEP_PERIOD)
{
	/*	Disable the WDT before you do any changes using this sequence	*/
	WDTCR = 0b00011000;
	WDTCR = 0;

	/*	Enablw WDT and put the time option	*/
	WDTCR |= (0b0001000|WDT_SLEEP_PERIOD);

}

void WDT_voidStop(void)
{
	/*	Disable the WDT this sequence	*/
	WDTCR = 0b00011000;
	WDTCR = 0;


}
