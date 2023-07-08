/*
 * Down_BTN.c
 *
 * Created: 5/2/2023 9:59:52 PM
 *  Author: ahmed
 */ 

#include "DOWN_BTN.h"

void H_Down_BTN_Init(void)
{
	M_Dio_SetPin_Direction(DOWN_BTN_PRT , DOWN_BTN_PIN , DOWN_BTN_INPUT);
}

u8 H_Down_BTN_Read(void)
{
	u8 Local_u8_Val = RELEASED;
	if(M_Dio_ReadPin_State(DOWN_BTN_PRT , DOWN_BTN_PIN)==PRESSED)
	{
		_delay_ms(DEBOUNCE_DELAY);
		if(M_Dio_ReadPin_State(DOWN_BTN_PRT , DOWN_BTN_PIN)==PRESSED)
		{
			while(M_Dio_ReadPin_State(DOWN_BTN_PRT , DOWN_BTN_PIN)==PRESSED);
			Local_u8_Val = PRESSED ;
		}
		
	}
	return Local_u8_Val;
}