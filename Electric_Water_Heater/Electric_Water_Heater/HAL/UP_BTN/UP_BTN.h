/*
 * UP_BTN.h
 *
 * Created: 5/2/2023 10:00:53 PM
 *  Author: ahmed
 */ 


#ifndef UP_BTN_H_
#define UP_BTN_H_


#include "UP_BTN_Config.h"

#if  PUSH_BUTTON_MODE == ACTIVE_HIGH
#define PRESSED  1
#define RELEASED 0
#elif   PUSH_BUTTON_MODE == ACTIVE_LOW
#define PRESSED  0
#define RELEASED 1
#endif

void H_UP_BTN_Init(void);


u8 H_UP_BTN_Read(void);



#endif /* UP_BTN_H_ */