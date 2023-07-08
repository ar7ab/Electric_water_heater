/*
 * UP_BTN_Config.h
 *
 * Created: 5/2/2023 10:01:22 PM
 *  Author: ahmed
 */ 


#ifndef UP_BTN_CONFIG_H_
#define UP_BTN_CONFIG_H_

#include "DIO.h"

/********************************* Macros **********************************/

#define ACTIVE_HIGH 1

#define ACTIVE_LOW 0

#define DEBOUNCE_DELAY  50

/****************************** Select PB Mode ****************************/
#define PUSH_BUTTON_MODE ACTIVE_HIGH

#define UP_BTN_PRT  DIO_PORTB

#define UP_BTN_PIN  DIO_PIN6

#define UP_BTN_INPUT   DIO_INPUT

#endif /* UP_BTN_CONFIG_H_ */