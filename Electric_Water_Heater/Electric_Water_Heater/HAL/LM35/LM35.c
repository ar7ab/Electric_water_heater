/*
 * LM35.c
 *
 * Created: 5/2/2023 9:24:22 PM
 *  Author: ahmed
 */ 

#include "LM35.h"

void H_LM35_Init(void)
{
	M_ADC_Init();
}

u32 H_LM35_Read(u8 Local_u8_Channel)
{
	f32 Local_f32_Value_ADC = M_ADC_ReadValue(Local_u8_Channel);
	
	f32 Local_f64_temp = ((f64)Local_f32_Value_ADC * 500.0)/1023.0;
	
	return Local_f64_temp ;
}