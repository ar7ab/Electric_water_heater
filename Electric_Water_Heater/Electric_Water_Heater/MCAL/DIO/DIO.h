/*
 * DIO.h
 *
 * Created: 5/2/2023 6:21:01 PM
 *  Author: ahmed
 */ 


#ifndef DIO_H_
#define DIO_H_

/***************** Includes ******************/
#include "DIO_Config.h"
/************************************ PINS ************************************/

// Define the PIN direction as (INPUT or OUTPUT)
void M_Dio_SetPin_Direction(DIO_Port port , DIO_Pin pin , DIO_DIR direction);
// Define the PIN status as (HIGH or LOW)
void M_Dio_SetPin_State(DIO_Port port , DIO_Pin pin , DIO_Status state);
//Toggle the PIN state(NOT)
void M_Dio_TogglePin_state(DIO_Port port , DIO_Pin pin);
//Get PIN State (HIGH or LOW)
u8 M_Dio_ReadPin_State(DIO_Port port , DIO_Pin pin);
//Activate PIN internal PULLUP
void M_Dio_ActivatePin_PUllUP(DIO_Port port , DIO_Pin pin);


/************************************ PORTS ************************************/


// Define the PORT direction as (INPUT or OUTPUT)
void M_Dio_SetPort_Direction(DIO_Port port , DIO_DIR direction);
// Define the PORT status as (HIGH or LOW)
void M_Dio_SetPort_State(DIO_Port port , DIO_Status state);
//Toggle the PORT state(NOT)
void M_Dio_TogglePort_state(DIO_Port port);
//Get PORT State (HIGH or LOW)
u8 M_Dio_ReadPort_State(DIO_Port port);
//Activate PORT internal PULLUP
void M_Dio_ActivatePort_PUllUP(DIO_Port port);


#endif /* DIO_H_ */