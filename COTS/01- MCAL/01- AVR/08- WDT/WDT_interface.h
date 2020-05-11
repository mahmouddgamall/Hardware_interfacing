/**************************************************** 
 	 Author: Mahmoud Gamal
************************************************/
#ifndef WDT_INTERFACE_H
#define WDT_INTERFACE_H

#define	WDT_SLEEP_PERIOD_16_3_MS			0b000
#define	WDT_SLEEP_PERIOD_32_5_MS			0b001
#define	WDT_SLEEP_PERIOD_65_MS				0b010
#define	WDT_SLEEP_PERIOD_0_13_S				0b011
#define	WDT_SLEEP_PERIOD_0_26_S				0b100
#define	WDT_SLEEP_PERIOD_0_52_S				0b101
#define	WDT_SLEEP_PERIOD_1_S				0b110
#define	WDT_SLEEP_PERIOD_2_1_S				0b111


void WDT_voidSleep(u8 WDT_SLEEP_PERIOD);

void WDT_voidStop(void);


#endif