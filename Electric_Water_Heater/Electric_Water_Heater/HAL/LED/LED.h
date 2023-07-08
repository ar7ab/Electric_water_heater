/*
 * LED.h
 *
 * Created: 5/2/2023 11:09:38 PM
 *  Author: ahmed
 */ 


#ifndef LED_H_
#define LED_H_

#include "LED_Config.h"

void H_LED_Init(void);

void H_LED_ON(void);

void H_LED_OFF(void);

void H_LED_TOGGLE(void);

void H_LED_BLinkOnce(void);

void H_LED_BLinkTwice(void);




#endif /* LED_H_ */