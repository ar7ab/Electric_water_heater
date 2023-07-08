/*
 * ADC.c
 *
 * Created: 5/2/2023 6:15:27 PM
 *  Author: ahmed
 */ 

#include "ADC.h"

void M_ADC_Init(void)
{
	#if ADC_MODE == AREF
	clr_bit(ADMUX , 6);
	clr_bit(ADMUX , 7);
	#elif ADC_MODE == AVCC
	set_bit(ADMUX , 6);
	clr_bit(ADMUX , 7);
	#elif ADC_MODE == _2V56VOLT
	set_bit(ADMUX , 6);
	set_bit(ADMUX , 7);
	#endif
	// ADC Enable
	set_bit(ADCSRA , 7);
	//the result is right adjusted
	clr_bit(ADMUX , 5);
	// Select PreScaller -> 8 -> for 1MHz
	set_bit(ADCSRA , 0);
	set_bit(ADCSRA , 1);
	clr_bit(ADCSRA , 2);
	// Auto trigger
	set_bit(ADCSRA , 5);
}


int M_ADC_ReadValue(u8 Local_u8_ADC_Channel)
{
	u32 Local_u32_ADC_Value = 0;
	// Select pin
	ADMUX = (ADMUX & 0XE0) | Local_u8_ADC_Channel ;
	// Start Conversion
	set_bit(ADCSRA , 6);
	//Wait to complete conversion
	while(get_bit(ADCSRA , 4)==0);
	_delay_us(10);
	//return value
	Local_u32_ADC_Value = (u32)ADCL + (u32)ADCH *256;
	return Local_u32_ADC_Value;
}