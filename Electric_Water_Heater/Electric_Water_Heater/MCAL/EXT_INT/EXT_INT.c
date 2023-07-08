/*
 * EXT_INT.c
 *
 * Created: 5/2/2023 11:27:28 PM
 *  Author: ahmed
 */ 

#include "EXT_INT.h"

// Pointer to function
void (*CallBack)(void);

void M_ExtInt_INT0_Init(void)
{
	#if SENSE_CONTROL == RISING_EDGE
	set_bit(MCUCR , 0);
	set_bit(MCUCR , 1);
	#elif SENSE_CONTROL == FALLING_EDGE
	clr_bit(MCUCR , 0);
	set_bit(MCUCR , 1);
	#elif SENSE_CONTROL == LOGICAL_CHANGE
	set_bit(MCUCR , 0);
	clr_bit(MCUCR , 1);
	#elif SENSE_CONTROL == LOW_LEVEL
	clr_bit(MCUCR , 0);
	clr_bit(MCUCR , 1);
	#endif
	set_bit(GICR , 6);// To enable local interrupt
	sei();// To enable global interrupt
}

void M_ExtInt_Set_CallBack(void (*ptr)(void))
{
	//CallBack Function
	CallBack = ptr ;
}

ISR(INT0_vect)
{
	CallBack();
}