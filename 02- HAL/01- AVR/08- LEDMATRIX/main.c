/*
 * main.c
 *
 *  Created on: Feb 4, 2020
 *      Author: mahmo
 */
#include "std_types.h"
#include "bit_math.h"
#include "Delay_interface.h"

#include "PORT_interface.h"

#include "LEDMATRIX_interface.h"

static u8 GS_myChar[]={0b11000011,0b11100111,0b11111111,0b11011011,0b11000011,0b11000011,0b11000011,0b11000011};


int main (void)
{

	portInit();

	while(1)
	{
		LEDMATRIX_voidWriteChar(GS_myChar, LEDMATRIX_ORANGE);

	}
	return 0;
}

