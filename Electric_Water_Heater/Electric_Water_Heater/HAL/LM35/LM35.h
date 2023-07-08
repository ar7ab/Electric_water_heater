/*
 * LM35.h
 *
 * Created: 5/2/2023 9:24:37 PM
 *  Author: ahmed
 */ 


#ifndef LM35_H_
#define LM35_H_
/******************* Includes ***********************/
#include "LM35_Config.h"

/***************** Prototypes **********************/
void H_LM35_Init(void);

u32 H_LM35_Read(u8);

#endif /* LM35_H_ */