/*
 * KeyPad.h
 *
 * Created: 7/9/2020 10:54:58 AM
 *  Author: User™
 */ 


#ifndef KEYPAD_H_
#define KEYPAD_H_

#include <avr/io.h>
#include <util/delay.h>

#define SET_BIT(REG,BIT)	REG|=(1<<BIT)
#define CLR_BIT(REG,BIT)	REG &=~(1<<BIT)
#define GET_BIT(REG,BIT)	((REG>>BIT)&1)
#define TOGGLE_BIT(REG,BIT) REG^=(1<<BIT)

#include <avr/io.h>
#include <util/delay.h>

#define KeyPad_DDR DDRD
#define KeyPad_Port PORTD
#define KeyPad_Pin PIND
//read ==input direction
#define r1 PD0
#define r2 PD1
#define r3 PD2
#define r4 PD3

void Check_1();
void Check_2();
void Check_3();
void Check_4();


#endif /* KEYPAD_H_ */