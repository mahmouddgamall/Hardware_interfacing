/*
 * I2C_config.h
 *
 *  Created on: Apr 20, 2020
 *      Author: madel
 */

#ifndef I2C_CONFIG_H_
#define I2C_CONFIG_H_



/* Slaves Address Alias * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *
 *   you can use all the address except for "1111 ---"  & "0000 ---"
 *
 *   address 0000 000(0 write) is for General call "Broadcasting"
 *
 *	The number placed here is 7-bits address
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
#define I2C_SLAVE_ADD_MAR_MCU				0x40

/*--------------------------------------------------------------------------------------------------------------------*/
/*+++++++++++++++++++++++++++++++++++++++++++++ General Configuration ++++++++++++++++++++++++++++++++++++++++++++++++*/
/*--------------------------------------------------------------------------------------------------------------------*/

/* I2C NODE Mode * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *
 *    Options:
 *    		1- I2C_MASTER_NODE
 *    		2- I2C_SLAVE_NODE
 *
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
#define I2C_NODE_MODE							I2C_MASTER_NODE

/* I2C Transmission Mode * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *
 *    Options:
 *    		1- I2C_Transmition_MODE_SYNC
 *    		2- I2C_Transmition_MODE_ASYNC
 *
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
#define I2C_MODE_OPERATION							I2C_Transmition_MODE_ASYNC


/*--------------------------------------------------------------------------------------------------------------------*/
/*++++++++++++++++++++++++++++++++++++++++++++++ Master Configuration ++++++++++++++++++++++++++++++++++++++++++++++++*/
/*--------------------------------------------------------------------------------------------------------------------*/

/* I2C System Clock * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *
 *    Options:
 *    		1- I2C_SYS_CLK_1MHZ
 *    		2- I2C_SYS_CLK_8MHZ
 *    		3- I2C_SYS_CLK_12MHZ
 *
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
#define I2C_SYS_CLK									I2C_SYS_CLK_8MHZ



/* I2C Rate Prescaler * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *
 *    Options:
 *    		1- I2C_RATE_PRESCALER_1
 *    		2- I2C_RATE_PRESCALER_4
 *    		3- I2C_RATE_PRESCALER_16
 *			4- I2C_RATE_PRESCALER_64
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
#define I2C_RATE_PRESCALER							I2C_RATE_PRESCALER_1


/* I2C SDL Speed * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *
 *    Options:
 *    		1- I2C_SCL_SPEED_100KHZ
 *    		2- I2C_SCL_SPEED_400KHZ
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
#define I2C_SCL_SPEED								I2C_SCL_SPEED_100KHZ




/*--------------------------------------------------------------------------------------------------------------------*/
/*+++++++++++++++++++++++++++++++++++++++++++++++ Slave Configuration ++++++++++++++++++++++++++++++++++++++++++++++++*/
/*--------------------------------------------------------------------------------------------------------------------*/

/* I2C Slave Address * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *
 *   you can use all the address except for "1111 ---"  & "0000 ---"
 *
 *   address 0000 000(0 write) is for General call "Broadcasting"
 *
 *   In case of multiple masters, put address here also
 *
 *   0x10 is default address never used
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
#define I2C_Slave_Address							(0x10)


/* I2C Slave General Call Recognition * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *
 *    Options:
 *    		1- I2C_GENERAL_CALL_EN
 *    		2- I2C_GENERAL_CALL_DS
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
#define I2C_GENERAL_CALL							I2C_GENERAL_CALL_EN


#endif /* I2C_CONFIG_H_ */
