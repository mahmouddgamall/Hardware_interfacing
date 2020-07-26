#ifndef I2C_PRIVATE_H
#define I2C_PRIVATE_H

#define TWCR_TWINT			7
#define TWCR_TWEA			6
#define TWCR_TWSTA			5
#define TWCR_TWSTO			4
#define TWCR_TWWC			3
#define TWCR_TWEN			2
#define TWCR_TWIW			0

#define	TWSR_TWPS1			1
#define	TWSR_TWPS0			0

#define	I2C_STATUS_CODE_MASK	0xF8

#define I2C_MT_SC_ACK		0X08
#define I2C_MT_RSC_ACK		0X10
#define I2C_MT_SLA_W_ACK	0X18
#define I2C_MT_DATA_ACK		0X28


#define I2C_MR_SC_ACK		0X08
#define I2C_MR_RSC_ACK		0X10
#define I2C_MR_SLA_R_ACK	0X40
#define I2C_MR_DATA_ACK		0X50

#endif