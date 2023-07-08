/*
 * UP_BTN.c
 *
 * Created: 5/2/2023 10:01:49 PM
 *  Author: ahmed
 */ 

#include "UP_BTN.h"

void H_UP_BTN_Init(void)
{
	M_Dio_SetPin_Direction(UP_BTN_PRT , UP_BTN_PIN , UP_BTN_INPUT);
}

u8 H_UP_BTN_Read(void)
{
	u8 Local_u8_Val = RELEASED;
	if(M_Dio_ReadPin_State(UP_BTN_PRT , UP_BTN_PIN)==PRESSED)
	{
		_delay_ms(DEBOUNCE_DELAY);
		if(M_Dio_ReadPin_State(UP_BTN_PRT , UP_BTN_PIN)==PRESSED)
		{
			while(M_Dio_ReadPin_State(UP_BTN_PRT , UP_BTN_PIN)==PRESSED);
			Local_u8_Val = PRESSED ;
		}
		
	}
	return Local_u8_Val;
}