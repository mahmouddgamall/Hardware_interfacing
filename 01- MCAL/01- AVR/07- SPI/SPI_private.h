/**************************************************** 
 	 Author: Mahmoud Gamal
************************************************/
#ifndef SPI_PRIVATE_H
#define SPI_PRIVATE_H


#define SPI_INTERRUPT_ENABLE		0b10000000
#define SPI_INTERRUPT_DISABLE		0b00000000

#define SPI_ENABLE					0b01000000
#define SPI_DISABLE					0b00000000

#define	SPI_DATA_ORDER_LSB_FIRST	0b00100000
#define	SPI_DATA_ORDER_MSB_FIRST	0b00000000

#define	SPI_MASTER_MODE				0b00010000
#define	SPI_SLAVE_MODE				0b00000000

#define	SPI_LEADING_EDGE_FALLING	0b00001000
#define	SPI_LEADING_EDGE_RISING		0b00000000

#define	SPI_SAMPLE_FIRST			0b00000100
#define	SPI_SETUP_FIRST				0b00000000

#define	SPI_PRESCHALER_4			0b00000000
#define	SPI_PRESCHALER_16			0b00000001
#define	SPI_PRESCHALER_64			0b00000010
#define	SPI_PRESCHALER_128			0b00000011

#define	SPI_DOUBLE_SPEED_ENABLE		0b00000001			
#define	SPI_DOUBLE_SPEED_DISABLE	0b00000000			

/*	ISR prototype	*/
void __vector_12(void) __attribute__((used,signal));

#endif