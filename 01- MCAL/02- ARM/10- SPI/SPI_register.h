/**************************************************** 
 	 Author: Mahmoud Gamal
************************************************/
#ifndef SPI_REGISTER_H
#define SPI_REGISTER_H

typedef struct {
	u32 CR1;
	u32 CR2;
	u32 SR;
	u32 DR;
	u32 CRCPR;
	u32 RXCRCR;
	u32 TXCRCR;
	u32 I2SCFGR;
	u32 I2SPR;
}

#endif