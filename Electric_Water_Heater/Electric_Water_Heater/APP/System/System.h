/*
 * System.h
 *
 * Created: 5/2/2023 6:52:47 PM
 *  Author: ahmed
 */ 


#ifndef SYSTEM_H_
#define SYSTEM_H_

/****************** Includes ***********************/
#include "DIO.h"
#include "ADC.h"
#include "Timer0.h"
#include "Timer2.h"
#include "EEPROM.h"
#include "SSD.h"
#include "Cooler.h"
#include "Heater.h"
#include "Down_BTN.h"
#include "UP_BTN.h"
#include "LED.h"
#include "EXT_INT.h"
#include "LM35.h"
#include "System_Config.h"




/*************** Prototypes *****************/
void A_System_Init(void);

void A_System_ON(void);

void A_System_OFF(void);

void A_System_Setting(void);

void A_Change_Temp(void);

void A_Temp_Arr_Init(void);

void A_Add_New_Temp(u16 * arr , u16 New_val);

u16 A_Calc_Avg_Temp(u16 * arr);

void A_Go_To_Sleep(void);


#endif /* SYSTEM_H_ */