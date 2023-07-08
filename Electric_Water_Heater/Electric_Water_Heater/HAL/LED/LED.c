/*
 * LED.c
 *
 * Created: 5/2/2023 11:09:19 PM
 *  Author: ahmed
 */ 

#include "LED.h"

void H_LED_Init(void)
{
	M_Dio_SetPin_Direction(LED_PRT , LED , LED_OUT);
}

void H_LED_ON(void)
{
	M_Dio_SetPin_State(LED_PRT , LED , LED_HIGH);
}

void H_LED_OFF(void)
{
	M_Dio_SetPin_State(LED_PRT , LED , LED_LOW);
}

void H_LED_TOGGLE(void)
{
	M_Dio_TogglePin_state(LED_PRT , LED);
}

void H_LED_BLinkOnce(void)
{
	H_LED_ON();
	_delay_ms(LED_TIME_DELAY);
	H_LED_OFF();
	
}

void H_LED_BLinkTwice(void)
{
	H_LED_BLinkOnce();
	_delay_ms(LED_TIME_DELAY);
	H_LED_BLinkOnce();
}