/*
 * System.c
 *
 * Created: 5/2/2023 6:53:30 PM
 *  Author: ahmed
 */ 

#include "System.h"

extern u8 Current_state;

u16 Temp_arr[NUM_OF_TEMP_MEASURES];

extern u16 Desired_Temp;

u16 Actual_Temp;

u16 Avg_Temp;

extern u8 Temp_Measure_Flag;

u8 Temp_Measure_Count;

extern u8 Setting_Count;

u16 Array_count;


extern u16 Toggle_Flag ;


void A_System_Init(void)
{
	M_ExtInt_INT0_Init();
	H_HEATER_Init();
	H_Cooler_Init();
	H_LED_Init();
	H_UP_BTN_Init();
	H_Down_BTN_Init();
	H_LM35_Init();
	H_SSD_Init();
	M_Timer0_Init();
	M_Timer2_Init();

	
	Current_state = OFF ;
	
	if(M_EEPROM_Read(0x60) != 0xFF)
	{
		Desired_Temp = M_EEPROM_Read(0x60);
	}
	else 
	{
		Desired_Temp = INIT_DESIRED_TEMP;
		
	}
	
	A_Temp_Arr_Init();
	
	M_EEPROM_Write(0x60 ,(u8)Desired_Temp);
	
}

void A_System_OFF(void)
{
	H_SSD_Turn_off();
	H_LED_OFF();
	H_HEATER_Stop();
	H_Cooler_Stop();
	A_Go_To_Sleep();
}

void A_System_ON(void)
{
	

   if(Temp_Measure_Flag == 1)
   {
		Actual_Temp = H_LM35_Read(0);
		
		A_Add_New_Temp(Temp_arr , Actual_Temp);
		
		Avg_Temp = A_Calc_Avg_Temp(Temp_arr);
		
		Temp_Measure_Flag = 0 ;
   }
		
	H_SSD_Write_Number(Actual_Temp);
	
	
	A_Change_Temp();
	
	
	if(H_UP_BTN_Read()==PRESSED || H_Down_BTN_Read()==PRESSED)
	{
		H_SSD_Turn_off();
		Setting_Count = 0;
		Current_state = SETTING ;
	}
}


void A_System_Setting(void)
{
	H_HEATER_Stop();
	H_Cooler_Stop();
	H_LED_OFF();
	
	if(Toggle_Flag == 1)
	{
		H_SSD_Write_Number(Desired_Temp);
	}
	else
	{
		H_SSD_Turn_off();
	}


	if((H_UP_BTN_Read() == PRESSED ) && (Desired_Temp < MAX_TEMP))
	{
		Desired_Temp += 5 ;
		Setting_Count = 0 ;
		H_SSD_Write_Number(Desired_Temp);
	}
	
    if((H_Down_BTN_Read()==PRESSED) && (Desired_Temp > MIN_TEMP))
	{
		Desired_Temp -= 5 ;
		Setting_Count = 0;
		H_SSD_Write_Number(Desired_Temp);
	}
	
	M_EEPROM_Write(0x60 , Desired_Temp);
}


void A_Change_Temp(void)
{ 
  
	if(Desired_Temp < (Avg_Temp + MARGIN_TEMP) && Desired_Temp > ( Avg_Temp - MARGIN_TEMP))
	{
		H_HEATER_Stop();
		H_Cooler_Stop();
		H_LED_OFF();
	}
    else if(Desired_Temp < ( Avg_Temp + MARGIN_TEMP))
	{
		H_HEATER_Stop();
		H_Cooler_Start();
		H_LED_ON();
	}
    else if(Desired_Temp > ( Avg_Temp - MARGIN_TEMP))
	{
		H_HEATER_Start();
		H_Cooler_Stop();
		if(Toggle_Flag == 1)
		{
			H_LED_ON();
		}
		else
		{
			H_LED_OFF();
		}
			
	}
}
void A_Temp_Arr_Init(void)
{
	u16 First_Temp = H_LM35_Read(0);
	
	for (u8 i=0 ; i<NUM_OF_TEMP_MEASURES ; i++)
	{
		Temp_arr[i] = First_Temp;
	}
	Avg_Temp = A_Calc_Avg_Temp(Temp_arr);
	Array_count = 0 ;
}

void A_Add_New_Temp(u16 * arr , u16 New_val)
{
	arr[Array_count] = New_val ;
	
	Array_count++ ;
	
	if(Array_count == 10)
	{
		Array_count = 0 ;
	}
}

u16 A_Calc_Avg_Temp(u16 * arr)
{
	u16 sum = 0 ;
	u16 avg ;
	
	for(u8 i=0 ; i<NUM_OF_TEMP_MEASURES ; i++)
	{
		sum = sum + arr[i];
	}
	avg =(u16) sum / NUM_OF_TEMP_MEASURES ;
	
	return avg ;
}

void A_Go_To_Sleep(void)
{
	MCUCR&=~(1<<SM0);
	MCUCR&=~(1<<SM1);
	MCUCR&=~(1<<SM2);
	
	MCUCR|=(1<<SE);
}