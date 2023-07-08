/*
 * DIO.c
 *
 * Created: 5/2/2023 6:20:40 PM
 *  Author: ahmed
 */ 

/***************** Includes ******************/
#include "DIO.h"

/************************************ PINS ************************************/

// Define the PIN direction as (INPUT or OUTPUT)
void M_Dio_SetPin_Direction(DIO_Port port , DIO_Pin pin , DIO_DIR direction)
{
	switch(direction)
	{
		case DIO_INPUT:
		switch(port)
		{
			case DIO_PORTA:
			clr_bit(DDRA,pin);
			break;
			case DIO_PORTB:
			clr_bit(DDRB,pin);
			break;
			case DIO_PORTC:
			clr_bit(DDRC,pin);
			break;
			case DIO_PORTD:
			clr_bit(DDRD,pin);
			break;
		}
		break;
		case DIO_OUTPUT:
		switch(port)
		{
			case DIO_PORTA:
			set_bit(DDRA,pin);
			break;
			case DIO_PORTB:
			set_bit(DDRB,pin);
			break;
			case DIO_PORTC:
			set_bit(DDRC,pin);
			break;
			case DIO_PORTD:
			set_bit(DDRD,pin);
			break;
		}
		break;
	}
}
// Define the PIN status as (HIGH or LOW)
void M_Dio_SetPin_State(DIO_Port port , DIO_Pin pin , DIO_Status state)
{
	switch(state)
	{
		case DIO_LOW:
		switch(port)
		{
			case DIO_PORTA:
			clr_bit(PORTA,pin);
			break;
			case DIO_PORTB:
			clr_bit(PORTB,pin);
			break;
			case DIO_PORTC:
			clr_bit(PORTC,pin);
			break;
			case DIO_PORTD:
			clr_bit(PORTD,pin);
			break;
		}
		break;
		case DIO_HIGH:
		switch(port)
		{
			case DIO_PORTA:
			set_bit(PORTA,pin);
			break;
			case DIO_PORTB:
			set_bit(PORTB,pin);
			break;
			case DIO_PORTC:
			set_bit(PORTC,pin);
			break;
			case DIO_PORTD:
			set_bit(PORTD,pin);
			break;
		}
		break;
	}
}
//Toggle the PIN state(NOT)
void M_Dio_TogglePin_state(DIO_Port port , DIO_Pin pin)
{
	switch(port)
	{
		case DIO_PORTA:
		tgl_bit(PORTA,pin);
		break;
		case DIO_PORTB:
		tgl_bit(PORTB,pin);
		break;
		case DIO_PORTC:
		tgl_bit(PORTC,pin);
		break;
		case DIO_PORTD:
		tgl_bit(PORTD,pin);
		break;
	}
}
//Get PIN State (HIGH or LOW)
u8 M_Dio_ReadPin_State(DIO_Port port , DIO_Pin pin)
{
	u8 val = 0;
	switch(port)
	{
		case DIO_PORTA:
		val = get_bit(PINA,pin);
		break;
		case DIO_PORTB:
		val = get_bit(PINB,pin);
		break;
		case DIO_PORTC:
		val = get_bit(PINC,pin);
		break;
		case DIO_PORTD:
		val = get_bit(PIND,pin);
		break;
	}
	return val;
}
//Activate PIN internal PULLUP
void M_Dio_ActivatePin_PUllUP(DIO_Port port , DIO_Pin pin)
{
	switch(port)
	{
		case DIO_PORTA:
		set_bit(PORTA,pin);
		break;
		case DIO_PORTB:
		set_bit(PORTB,pin);
		break;
		case DIO_PORTC:
		set_bit(PORTC,pin);
		break;
		case DIO_PORTD:
		set_bit(PORTD,pin);
		break;
	}
}


/************************************ PORTS ************************************/


// Define the PORT direction as (INPUT or OUTPUT)
void M_Dio_SetPort_Direction(DIO_Port port , DIO_DIR direction)
{
	switch(direction)
	{
		case DIO_INPUT:
		switch(port)
		{
			case DIO_PORTA:
			DDRA = 0x00;
			break;
			case DIO_PORTB:
			DDRB = 0x00;
			break;
			case DIO_PORTC:
			DDRC = 0x00;
			break;
			case DIO_PORTD:
			DDRD = 0x00;
			break;
		}
		break;
		case DIO_OUTPUT:
		switch(port)
		{
			case DIO_PORTA:
			DDRA = 0xFF;
			break;
			case DIO_PORTB:
			DDRB = 0xFF;
			break;
			case DIO_PORTC:
			DDRC = 0xFF;
			break;
			case DIO_PORTD:
			DDRD = 0xFF;
			break;
		}
		break;
	}
}
// Define the PORT status as (HIGH or LOW)
void M_Dio_SetPort_State(DIO_Port port , DIO_Status state)
{
	switch(state)
	{
		case DIO_LOW:
		switch(port)
		{
			case DIO_PORTA:
			PORTA = 0x00;
			break;
			case DIO_PORTB:
			PORTB = 0x00;
			break;
			case DIO_PORTC:
			PORTC = 0x00;
			break;
			case DIO_PORTD:
			PORTD = 0x00;
			break;
		}
		break;
		case DIO_HIGH:
		switch(port)
		{
			case DIO_PORTA:
			PORTA = 0xFF;
			break;
			case DIO_PORTB:
			PORTB = 0xFF;
			break;
			case DIO_PORTC:
			PORTC = 0xFF;
			break;
			case DIO_PORTD:
			PORTD = 0xFF;
			break;
		}
		break;
	}
}
//Toggle the PORT state(NOT)
void M_Dio_TogglePort_state(DIO_Port port)
{
	switch(port)
	{
		case DIO_PORTA:
		PORTA ^= 0xFF;
		break;
		case DIO_PORTB:
		PORTB ^= 0xFF;
		break;
		case DIO_PORTC:
		PORTC ^= 0xFF;
		break;
		case DIO_PORTD:
		PORTD ^= 0xFF;
		break;
	}
}
//Get PORT State (HIGH or LOW)
u8 M_Dio_ReadPort_State(DIO_Port port)
{
	u8 val = 0;
	switch(port)
	{
		case DIO_PORTA:
		val = PINA;
		break;
		case DIO_PORTB:
		val = PINB;
		break;
		case DIO_PORTC:
		val = PINC;
		break;
		case DIO_PORTD:
		val = PIND;
		break;
	}
	return val ;
}
//Activate PORT internal PULLUP
void M_Dio_ActivatePort_PUllUP(DIO_Port port)
{
	switch(port)
	{
		case DIO_PORTA:
		PORTA = 0xFF;
		break;
		case DIO_PORTB:
		PORTB = 0xFF;
		break;
		case DIO_PORTC:
		PORTC = 0xFF;
		break;
		case DIO_PORTD:
		PORTD = 0xFF;
		break;
	}
}