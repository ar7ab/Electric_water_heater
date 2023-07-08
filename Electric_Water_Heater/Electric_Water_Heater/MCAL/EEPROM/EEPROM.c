/*
 * EEPROM.c
 *
 * Created: 5/2/2023 7:01:02 PM
 *  Author: ahmed
 */ 

/******************* Includes *****************/

#include "EEPROM.h"

void M_EEPROM_Write(u32 Local_u32_address , u8 Local_u8_data)
{
	// Wait for completion of previous write 
	while(EECR&(1<<EEWE));
	
	// Set up address and data registers 
	EEAR = Local_u32_address ;
	EEDR = Local_u8_data ;
	
	// Write logical one to EEMWE
	EECR|=(1<<EEMWE);
	
	// Start EEPROM write by setting EEWE
	EECR|=(1<<EEWE);
}

u8   M_EEPROM_Read(u32 Local_32_address)
{
	
	// Wait for completion of previous write 
	while(EECR & (1<<EEWE)) ;
	
	// Set up address register 
	EEAR = Local_32_address;
	
	// Start EEPROM read by writing EERE 
	EECR |= (1<<EERE);
	
	// Return data from data register 
	return EEDR ;
	
}