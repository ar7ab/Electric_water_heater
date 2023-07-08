/*
 * Cooler.c
 *
 * Created: 5/2/2023 9:36:05 PM
 *  Author: ahmed
 */ 

#include "Cooler.h"

void H_Cooler_Init(void)
{
	M_Dio_SetPin_Direction(COOLER_PRT , COOLER_PIN , COOLER_OUT);
}

void H_Cooler_Start(void)
{
	M_Dio_SetPin_State(COOLER_PRT , COOLER_PIN , COOLER_ON);
}

void H_Cooler_Stop(void)
{
	M_Dio_SetPin_State(COOLER_PRT , COOLER_PIN , COOLER_OFF);
}