/*
 * Timer2.h
 *
 * Created: 5/2/2023 6:42:25 PM
 *  Author: ahmed
 */ 


#ifndef TIMER2_H_
#define TIMER2_H_

#include "Timer2_Config.h"

void M_Timer2_Init(void);

void M_Timer2_SetTime(u32 Local_u32_DesiredTime);

void M_Timer2_Start(void);

void M_Timer2_Stop(void);

void M_Timer2_Set_CallBack(void (*)(void));

#endif /* TIMER2_H_ */