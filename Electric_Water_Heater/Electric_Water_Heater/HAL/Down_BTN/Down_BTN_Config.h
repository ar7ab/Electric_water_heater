/*
 * Down_BTN_Config.h
 *
 * Created: 5/2/2023 10:00:32 PM
 *  Author: ahmed
 */ 


#ifndef DOWN_BTN_CONFIG_H_
#define DOWN_BTN_CONFIG_H_

#include "DIO.h"



/********************************* Macros **********************************/

#define ACTIVE_HIGH 1

#define ACTIVE_LOW 0

#define DEBOUNCE_DELAY  50

/****************************** Select PB Mode ****************************/
#define PUSH_BUTTON_MODE ACTIVE_HIGH

#define DOWN_BTN_PRT  DIO_PORTB

#define DOWN_BTN_PIN  DIO_PIN7

#define DOWN_BTN_INPUT   DIO_INPUT


#endif /* DOWN_BTN_CONFIG_H_ */