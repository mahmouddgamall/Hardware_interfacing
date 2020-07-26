/**************************************************** 
 	 Author: Mahmoud Gamal
************************************************/
#ifndef EEPROM_INTERFACE_H
#define EEPROM_INTERFACE_H

void EEPROM_voidInitComm(void);

u8 EEPROM_u8WriteDataByte(u16 Copy_u16ByteAdress, u8 Copy_u8Data);

u8 EEPROM_u8WriteDataBuffer(u16 Copy_u16ByteAdress, u8* Copy_u8Data, u8 Copy_u8Size);

u8 EEPROM_u8ReadDataByte(u16 Copy_u16ByteAdress, u8* Copy_pu8Data);




#endif