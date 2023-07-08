/*
 * CPU_Config.h
 *
 * Created: 5/2/2023 6:10:12 PM
 *  Author: ahmed
 */ 


#ifndef CPU_CONFIG_H_
#define CPU_CONFIG_H_

#undef F_CPU               // Disable internal oscillator (Crystal)
#define F_CPU 1000000UL   // Enable external oscillator  (Crystal)
#include <avr/io.h>
#include <util/delay.h>  
#include <avr/interrupt.h>
#include "BIT_MATH.h"
#include "STD_TYPES.h"


#endif /* CPU_CONFIG_H_ */