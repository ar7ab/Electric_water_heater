/*
 * SSD.h
 *
 * Created: 5/2/2023 7:24:19 PM
 *  Author: ahmed
 */ 


#ifndef SSD_H_
#define SSD_H_

/********************** Includes ******************************/
#include "SSD_Config.h"

/********************** Prototypes ****************************/

void H_SSD_Init(void);

void H_SSD_Enable(u8 Local_u8_SSD);

void H_SSD_Disable(void);

void H_SSD_Turn_off(void);

void H_SSD_Write_Number(u8 Local_u8_number);


#endif /* SSD_H_ */