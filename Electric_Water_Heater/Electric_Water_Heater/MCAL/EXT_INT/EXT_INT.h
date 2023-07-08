/*
 * EXT_INT.h
 *
 * Created: 5/2/2023 11:26:48 PM
 *  Author: ahmed
 */ 


#ifndef EXT_INT_H_
#define EXT_INT_H_

#include "EXT_INT_Config.h"

void M_ExtInt_INT0_Init(void);

void M_ExtInt_Set_CallBack(void (*)(void));

#endif /* EXT_INT_H_ */