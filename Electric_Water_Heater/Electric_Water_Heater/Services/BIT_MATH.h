/*
 * BIT_MATH.h
 *
 * Created: 5/2/2023 6:09:36 PM
 *  Author: ahmed
 */ 


#ifndef BIT_MATH_H_
#define BIT_MATH_H_

#define set_bit(reg,bit) reg|=(1<<bit)  // Set logic(1) to specific bit inside specific register
#define clr_bit(reg,bit) reg&=~(1<<bit) // Set logic(0) to specific bit inside specific register
#define tgl_bit(reg,bit) reg^=(1<<bit)  // Toggle logic(1) to Logic(0) or vice-versa specific bit inside specific register
#define get_bit(reg,bit) ((reg>>bit)&1) // Set logic(1) to specific bit inside specific register

#endif /* BIT_MATH_H_ */