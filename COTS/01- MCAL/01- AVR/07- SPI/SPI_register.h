/**************************************************** 
 	 Author: Mahmoud Gamal
************************************************/
#ifndef SPI_REGISTER_H
#define SPI_REGISTER_H

#define SPI_SPCR		*(u8*)0x2D
#define SPI_SPSR		*(u8*)0x2E
#define SPSR_SPIF		7
#define SPSR_WCOL		6

#define SPI_SPDR		*(u8*)0x2F

#endif