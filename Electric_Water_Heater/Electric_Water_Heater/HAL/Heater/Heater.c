/*
 * Heater.c
 *
 * Created: 5/2/2023 9:47:24 PM
 *  Author: ahmed
 */ 

#include "Heater.h"

void H_HEATER_Init(void)
{
	M_Dio_SetPin_Direction(HEATER_PRT , HEATER_PIN , HEATER_OUT);
}
	
void H_HEATER_Start(void)
{
	M_Dio_SetPin_State(HEATER_PRT , HEATER_PIN , HEATER_ON);
}

void H_HEATER_Stop(void)
{
	M_Dio_SetPin_State(HEATER_PRT , HEATER_PIN , HEATER_OFF);
}

