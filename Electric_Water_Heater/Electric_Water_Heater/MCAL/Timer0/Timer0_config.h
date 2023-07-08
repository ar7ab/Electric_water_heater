/*
 * Timer0_config.h
 *
 * Created: 5/2/2023 6:29:45 PM
 *  Author: ahmed
 */ 


#ifndef TIMER0_CONFIG_H_
#define TIMER0_CONFIG_H_

/***************** Includes ******************/
#include "CPU_Config.h"

/***************** Macros *******************/
#define NORMAL_MODE        1
#define CTC_MODE		   2

/************** select Timer0 Mode ***************/
#define TIMER0_MODE  CTC_MODE

/************** select Fosc *********************/
#define F_OSC             1

/************* select prescaller ***************/
#define TIMER0_PRESCALER 256



#endif /* TIMER0_CONFIG_H_ */