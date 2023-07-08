/*
 * ADC.h
 *
 * Created: 5/2/2023 6:14:50 PM
 *  Author: ahmed
 */ 


#ifndef ADC_H_
#define ADC_H_

/********************** Includes ******************************/
#include "ADC_Config.h"

/********************** Prototypes ****************************/
void M_ADC_Init(void);


int M_ADC_ReadValue(u8);


#endif /* ADC_H_ */