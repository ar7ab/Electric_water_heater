/*
 * Electric_Water_Heater.c
 *
 * Created: 5/2/2023 6:04:06 PM
 * Author : ahmed
 */ 

#include "System.h"

void A_Timer0_Excution(void);
void A_Timer2_Excution(void);
void A_ExtInt_Excution(void);

u16 Toggle_Flag ;
u8 Current_state ;
u16 Desired_Temp;
u8 Temp_Measure_Flag;
u8 Setting_Count;

int main(void)
{
    /* Replace with your application code */
	
	A_System_Init();
    M_ExtInt_Set_CallBack(A_ExtInt_Excution);
	M_Timer0_SetTime(100);
	M_Timer0_Set_CallBack(A_Timer0_Excution);
	M_Timer0_Start();
	M_Timer2_SetTime(1000);
	M_Timer2_Set_CallBack(A_Timer2_Excution);
	M_Timer2_Start();
    while (1) 
    {
		switch(Current_state)
		{
			case ON :
			A_System_ON();
			break;
			case OFF :
			A_System_OFF();
			break;
			case SETTING :
			A_System_Setting();
			break;
		}
	
	}
}

void A_Timer0_Excution(void)
{
	// Write here what you want to execute
	Temp_Measure_Flag = 1 ;
	
}

void A_Timer2_Excution(void)
{
	// Write here what you want to execute
	if((Current_state == SETTING) || (Current_state == ON))
	{
		Setting_Count++ ;
		if(Setting_Count % 4 == 0)
		{
			Toggle_Flag ^= 1 ;
		}
		
		if(Setting_Count > 20)
		{
			Current_state = ON;
		}
	}
}

void A_ExtInt_Excution(void)
{
	// Write here what you want to execute
	if(Current_state==OFF)
	{
		Current_state = ON;
	}
	else if(Current_state == ON || Current_state == SETTING)
	{
		Current_state = OFF ;
	}
}
