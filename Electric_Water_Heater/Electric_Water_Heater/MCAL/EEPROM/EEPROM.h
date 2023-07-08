/*
 * EEPROM.h
 *
 * Created: 5/2/2023 7:01:15 PM
 *  Author: ahmed
 */ 


#ifndef EEPROM_H_
#define EEPROM_H_

/******************* Includes *****************/

#include "EEPROM_Config.h"

/******************* Prototypes *****************/

void M_EEPROM_Write(u32 Local_u32_address , u8 Local_u8_data);

u8   M_EEPROM_Read(u32 Local_32_address);


#endif /* EEPROM_H_ */