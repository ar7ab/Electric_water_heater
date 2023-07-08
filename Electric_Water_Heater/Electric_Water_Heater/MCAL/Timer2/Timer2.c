/*
 * Timer2.c
 *
 * Created: 5/2/2023 6:42:10 PM
 *  Author: ahmed
 */ 


/***************** Includes ******************/
#include "Timer2.h"

// Global Variables
u32 Global_u32_Timer2_NumerOverflows = 0;

u32 Global_u32_Timer2_NumOfCompareMatch = 0 ;

u8  Global_u8_Timer2_RemainderTicks = 0 ;

void (*CallBack_Timer2)(void);

void M_Timer2_Init(void)
{
	#if TIMER2_MODE == NORMAL_MODE
	clr_bit(TCCR2 , 6);
	clr_bit(TCCR2 , 3);
	set_bit(TIMSK , 6); // Enable the PIE (OVF)
	#elif TIMER2_MODE == CTC_MODE
	clr_bit(TCCR2 , 6);
	set_bit(TCCR2 , 3);
	set_bit(TIMSK , 7); // Enable the PIE (CTC)
	#endif
	sei(); // Enable global interrupt
}

void M_Timer2_SetTime(u32 Local_u32_DesiredTime)
{
	#if TIMER2_MODE == NORMAL_MODE
	
	u32 Local_u32_TickTime = TIMER2_PRESCALER / F_OSC ;
	
	u32 Local_u32_TotalTicks = (Local_u32_DesiredTime * 1000) / Local_u32_TickTime ;
	
	Global_u32_Timer2_NumerOverflows = Local_u32_TotalTicks / 256 ;
	
	u8 Timer2_u8_RemainderTicks = Local_u32_TotalTicks % 256 ;
	
	if(Timer2_u8_RemainderTicks != 0)
	{
		TCNT2 = 256 - Timer2_u8_RemainderTicks ;
		
		Global_u32_Timer2_NumerOverflows++ ;
	}
	
	#elif TIMER2_MODE == CTC_MODE
	
	u32 Local_u32_TickTime = TIMER2_PRESCALER / F_OSC ;
	
	u32 Local_u32_TotalTicks = (Local_u32_DesiredTime * 1000) / Local_u32_TickTime ;
	
	u8 Local_u8_DivisionFactor = 255 ;
	
	while(Local_u32_TotalTicks % Local_u8_DivisionFactor)
	{
		Local_u8_DivisionFactor--;
	}
	
	Global_u32_Timer2_NumOfCompareMatch = Local_u32_TotalTicks / Local_u8_DivisionFactor ;
	
	OCR2 = Local_u8_DivisionFactor - 1 ;
	
	#endif
}

void M_Timer2_Start(void)
{
	//start timer
	#if TIMER2_PRESCALER   == 1024
	set_bit(TCCR2 , 0);
	set_bit(TCCR2 , 1);
	set_bit(TCCR2 , 2);
	#elif TIMER2_PRESCALER == 256
	clr_bit(TCCR2 , 0);
	set_bit(TCCR2 , 1);
	set_bit(TCCR2 , 2);
	#elif TIMER2_PRESCALER == 64
	clr_bit(TCCR2 , 0);
	clr_bit(TCCR2 , 1);
	set_bit(TCCR2 , 2);
	#elif TIMER2_PRESCALER == 32
	set_bit(TCCR2 , 0);
	set_bit(TCCR2 , 1);
	clr_bit(TCCR2 , 2);
	#elif TIMER2_PRESCALER == 8
	clr_bit(TCCR2 , 0);
	set_bit(TCCR2 , 1);
	clr_bit(TCCR2 , 2);
	#endif
}

void M_Timer2_Stop(void)
{
	// stop timer
	clr_bit(TCCR2 , 0);
	clr_bit(TCCR2 , 1);
	clr_bit(TCCR2 , 2);
}

void M_Timer2_Set_CallBack(void (*ptr)(void))
{
	//CallBack Function
	CallBack_Timer2 = ptr ;
}

#if TIMER2_MODE == NORMAL_MODE
ISR(TIMER2_OVF_vect)
{
	static u32 Local_u32_counter = 0;
	
	Local_u32_counter++;
	
	if(Local_u32_counter == Global_u32_Timer2_NumerOverflows)
	{
		CallBack_Timer2();
		Local_u32_counter = 0;
		TCNT2 = 256 - Global_u8_Timer2_RemainderTicks ;
	}
}

#elif TIMER2_MODE == CTC_MODE

ISR(TIMER2_COMP_vect)
{
	static u32 Local_u32_counter = 0;
	
	Local_u32_counter++;
	
	if(Local_u32_counter == Global_u32_Timer2_NumOfCompareMatch)
	{
		CallBack_Timer2();
		Local_u32_counter = 0;
	}
}
#endif