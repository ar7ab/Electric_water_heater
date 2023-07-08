/*
 * SSD.c
 *
 * Created: 5/2/2023 7:24:36 PM
 *  Author: ahmed
 */ 

/********************** Includes ******************************/
#include "SSD.h"

// Array for number's value
u8 Nums[10]={0x3F ,0x06 ,0x5B ,0x4F ,0x66 ,0x6D ,0x7D ,0x07 ,0x7F ,0x6F };
	
static void H_SSD_Send_Number(u8 Local_u8_number);	

void H_SSD_Init(void)
{
	// set data Port as output
	SSD_DATA_DDR = 0xFF ;
	
	// set Control Pins as output
	M_Dio_SetPin_Direction(SSD_CONTROL_PRT , SSD_EN1_PIN , SSD_OUT);
	M_Dio_SetPin_Direction(SSD_CONTROL_PRT , SSD_EN2_PIN , SSD_OUT);
	
	// In the first Seven Segment OFF
	H_SSD_Disable();
}

static void H_SSD_Send_Number(u8 Local_u8_number)
{
	SSD_DATA_PRT = Nums[Local_u8_number];
}

void H_SSD_Enable(u8 Local_u8_SSD)
{
	if(Local_u8_SSD == SSD_RIGHT)
	{
		M_Dio_SetPin_State(SSD_CONTROL_PRT , SSD_EN1_PIN , SSD_HIGH);
		M_Dio_SetPin_State(SSD_CONTROL_PRT , SSD_EN2_PIN , SSD_LOW);
	}
	else if(Local_u8_SSD == SSD_LEFT)
	{
		M_Dio_SetPin_State(SSD_CONTROL_PRT , SSD_EN1_PIN , SSD_LOW);
		M_Dio_SetPin_State(SSD_CONTROL_PRT , SSD_EN2_PIN , SSD_HIGH);
	}
}

void H_SSD_Disable(void)
{
	M_Dio_SetPin_State(SSD_CONTROL_PRT , SSD_EN1_PIN , SSD_LOW);
	M_Dio_SetPin_State(SSD_CONTROL_PRT , SSD_EN2_PIN , SSD_LOW);
}

void H_SSD_Turn_off(void)
{	
	SSD_DATA_PRT = 0x00;
}

void H_SSD_Write_Number(u8 Local_u8_number)
{
	u8 units ;
	u8 tens ;
	u8 Local_u8_Count = 0;
	
	units = Local_u8_number % 10 ;
	tens  = (u32)Local_u8_number / 10;
	for(Local_u8_Count = 0; Local_u8_Count <50 ;Local_u8_Count++)
	{
		H_SSD_Enable(SSD_RIGHT);
		H_SSD_Send_Number(units);
		_delay_ms(5);
		
		H_SSD_Enable(SSD_LEFT);
		H_SSD_Send_Number(tens);
		_delay_ms(5);
	}
}