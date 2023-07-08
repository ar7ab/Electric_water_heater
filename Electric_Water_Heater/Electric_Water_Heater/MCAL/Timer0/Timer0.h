/*
 * Timer0.h
 *
 * Created: 5/2/2023 6:29:24 PM
 *  Author: ahmed
 */ 


#ifndef TIMER0_H_
#define TIMER0_H_

/***************** Includes ******************/
#include "Timer0_config.h"

/************** Pritotypes ******************/

void M_Timer0_Init(void);

void M_Timer0_SetTime(u32 Local_u32_DesiredTime);

void M_Timer0_Start(void);

void M_Timer0_Stop(void);

void M_Timer0_Set_CallBack(void (*)(void));

#endif /* TIMER0_H_ */