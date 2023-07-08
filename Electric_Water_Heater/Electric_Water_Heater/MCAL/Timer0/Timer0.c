/*
 * Timer0.c
 *
 * Created: 5/2/2023 6:30:01 PM
 *  Author: ahmed
 */ 

/***************** Includes ******************/
#include "Timer0.h"

// Global Variables
u32 Global_u32_Timer0_NumerOverflows = 0;

u32 Global_u32_Timer0_NumOfCompareMatch = 0 ;

u8  Global_u8_Timer0_RemainderTicks = 0 ;


void (*CallBack_Timer0)(void);

void M_Timer0_Init(void)
{
	#if TIMER0_MODE == NORMAL_MODE
	clr_bit(TCCR0 , 6);
	clr_bit(TCCR0 , 3);
	set_bit(TIMSK , 0); // Enable the PIE (OVF)
	#elif TIMER0_MODE == CTC_MODE
	clr_bit(TCCR0 , 6);
	set_bit(TCCR0 , 3);
	set_bit(TIMSK , 1); // Enable the PIE (CTC)
	#endif
	sei(); // Enable global interrupt
}

void M_Timer0_SetTime(u32 Local_u32_DesiredTime)
{
	#if TIMER0_MODE == NORMAL_MODE
	
	u32 Local_u32_TickTime = TIMER0_PRESCALER / F_OSC ;
	
	u32 Local_u32_TotalTicks = (Local_u32_DesiredTime * 1000) / Local_u32_TickTime ;
	
	Global_u32_Timer0_NumerOverflows = Local_u32_TotalTicks / 256 ;
	
	u8 Timer0_u8_RemainderTicks = Local_u32_TotalTicks % 256 ;
	
	if(Timer0_u8_RemainderTicks != 0)
	{
		TCNT0 = 256 - Timer0_u8_RemainderTicks ;
		
		Global_u32_Timer0_NumerOverflows++ ;
	}
	
	#elif TIMER0_MODE == CTC_MODE
	
	u32 Local_u32_TickTime = TIMER0_PRESCALER / F_OSC ;
	
	u32 Local_u32_TotalTicks = (Local_u32_DesiredTime * 1000) / Local_u32_TickTime ;
	
	u8 Local_u8_DivisionFactor = 255 ;
	
	while(Local_u32_TotalTicks % Local_u8_DivisionFactor)
	{
		Local_u8_DivisionFactor--;
	}
	
	Global_u32_Timer0_NumOfCompareMatch = Local_u32_TotalTicks / Local_u8_DivisionFactor ;
	
	OCR0 = Local_u8_DivisionFactor - 1 ;
	
	#endif
}

void M_Timer0_Start(void)
{
	//start timer
	#if TIMER0_PRESCALER   == 1024
	set_bit(TCCR0 , 0);
	clr_bit(TCCR0 , 1);
	set_bit(TCCR0 , 2);
	#elif TIMER0_PRESCALER == 256
	clr_bit(TCCR0 , 0);
	clr_bit(TCCR0 , 1);
	set_bit(TCCR0 , 2);
	#elif TIMER0_PRESCALER == 64
	set_bit(TCCR0 , 0);
	set_bit(TCCR0 , 1);
	clr_bit(TCCR0 , 2);
	#elif TIMER0_PRESCALER == 8
	clr_bit(TCCR0 , 0);
	set_bit(TCCR0 , 1);
	clr_bit(TCCR0 , 2);
	#endif
}

void M_Timer0_Stop(void)
{
	// stop timer
	clr_bit(TCCR0 , 0);
	clr_bit(TCCR0 , 1);
	clr_bit(TCCR0 , 2);
}

void M_Timer0_Set_CallBack(void (*ptr)(void))
{
	//CallBack Function
	CallBack_Timer0 = ptr ;
}

#if TIMER0_MODE == NORMAL_MODE

ISR(TIMER0_OVF_vect)
{
	static u32 Local_u32_counter = 0;
	
	Local_u32_counter++;
	
	if(Local_u32_counter == Global_u32_Timer0_NumerOverflows)
	{
		CallBack_Timer0();
		Local_u32_counter = 0;
		TCNT0 = 256 - Global_u8_Timer0_RemainderTicks ;
	}
}

#elif TIMER0_MODE == CTC_MODE

ISR(TIMER0_COMP_vect)
{
	static u32 Local_u32_counter = 0;
	
	Local_u32_counter++;
	
	if(Local_u32_counter == Global_u32_Timer0_NumOfCompareMatch)
	{
		CallBack_Timer0();
		Local_u32_counter = 0;
	}
}

#endif