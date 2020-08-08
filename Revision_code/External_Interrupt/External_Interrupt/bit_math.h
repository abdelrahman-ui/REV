/*
 * bit_math.h
 *
 * Created: 6/12/2020:57:24 PM
 * Author : abdelrahman_magdy
 */ 


#ifndef BIT_MATH_H_
#define BIT_MATH_H_

#define SET_BIT(REG,BIT)	REG|=(1<<BIT)
#define CLR_BIT(REG,BIT)	REG &=~(1<<BIT)
#define GET_BIT(REG,BIT)	((REG>>BIT)&1)
#define TOGGLE_BIT(REG,BIT) REG^=(1<<BIT)
//#define MASK(BIT)         BIT&1

#endif /* BIT_MATH_H_ */