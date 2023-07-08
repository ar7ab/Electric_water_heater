/*
 * Down_BTN.h
 *
 * Created: 5/2/2023 9:58:59 PM
 *  Author: ahmed
 */ 


#ifndef DOWN_BTN_H_
#define DOWN_BTN_H_

#include "Down_BTN_Config.h"

#if  PUSH_BUTTON_MODE == ACTIVE_HIGH
#define PRESSED  1
#define RELEASED 0
#elif   PUSH_BUTTON_MODE == ACTIVE_LOW
#define PRESSED  0
#define RELEASED 1
#endif

void H_Down_BTN_Init(void);


u8 H_Down_BTN_Read(void);

#endif /* DOWN_BTN_H_ */