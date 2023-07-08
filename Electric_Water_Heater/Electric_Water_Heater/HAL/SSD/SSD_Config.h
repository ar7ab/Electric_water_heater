/*
 * SSD_Config.h
 *
 * Created: 5/2/2023 7:24:05 PM
 *  Author: ahmed
 */ 


#ifndef SSD_CONFIG_H_
#define SSD_CONFIG_H_

/************** Includes *******************/
#include "DIO.h"

#define SSD_RIGHT 1

#define SSD_LEFT  2

#define SSD_DATA_DDR     DDRC

#define SSD_DATA_PRT     PORTC

#define SSD_CONTROL_PRT  DIO_PORTB

#define SSD_EN1_PIN		 DIO_PIN1

#define SSD_EN2_PIN      DIO_PIN2

#define SSD_LOW			 DIO_LOW

#define SSD_HIGH		 DIO_HIGH

#define SSD_OUT			 DIO_OUTPUT

#endif /* SSD_CONFIG_H_ */