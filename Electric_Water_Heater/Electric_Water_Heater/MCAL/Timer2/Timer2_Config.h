/*
 * Timer2_Config.h
 *
 * Created: 5/2/2023 6:42:58 PM
 *  Author: ahmed
 */ 


#ifndef TIMER2_CONFIG_H_
#define TIMER2_CONFIG_H_

/***************** Includes ******************/
#include "CPU_Config.h"

/******************************** Macros *****************************/
#define NORMAL_MODE        1
#define CTC_MODE		   2

#define NON_INVERTED	   0
#define INVERTED		   1

#define FAST_PWM           0
#define PHASE_CORRECT_PWM  1
/***************************** select Timer0 Mode *************************/
#define TIMER2_MODE  CTC_MODE
/************************************* select Fosc ************************************/
#define F_OSC             1

/***************************** select prescaller *************************/
#define TIMER2_PRESCALER 256


#endif /* TIMER2_CONFIG_H_ */