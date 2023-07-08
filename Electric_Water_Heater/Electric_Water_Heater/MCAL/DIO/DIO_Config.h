/*
 * DIO_Config.h
 *
 * Created: 5/2/2023 6:21:19 PM
 *  Author: ahmed
 */ 


#ifndef DIO_CONFIG_H_
#define DIO_CONFIG_H_

/***************** Includes ******************/
#include "CPU_Config.h"

/*********** naming Ports *************/
typedef enum
{
	DIO_PORTA = 0,
	DIO_PORTB = 1,
	DIO_PORTC = 2,
	DIO_PORTD = 3
	
}DIO_Port;

/*********** naming PINS *************/
typedef enum
{
	DIO_PIN0 = 0,
	DIO_PIN1 = 1,
	DIO_PIN2 = 2,
	DIO_PIN3 = 3,
	DIO_PIN4 = 4,
	DIO_PIN5 = 5,
	DIO_PIN6 = 6,
	DIO_PIN7 = 7
	
}DIO_Pin;


/*********** naming Directions *************/
typedef enum
{
	DIO_INPUT = 0,
	DIO_OUTPUT = 1
	
}DIO_DIR;

/*********** naming Status *************/
typedef enum
{
	DIO_LOW = 0,
	DIO_HIGH = 1
}DIO_Status;




#endif /* DIO_CONFIG_H_ */