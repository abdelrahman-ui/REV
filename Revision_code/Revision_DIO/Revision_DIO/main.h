 /*
 * main.h
 *
 * Created: 7/5/2020 7:03:12 AM
 *  Author: User™
 */ 


#ifndef MAIN_H_
#define MAIN_H_

#include "STD_Types1.h "
//#ifndef Way1
#define 
#define  DDRD_Reg (*((volatile  uint8 *)0x31)) 
#define  PORTD_Reg (*((volatile  uint8 *)0x32))
#define  PIND_Reg (*((volatile  uint8  *)0x30))
//#else
typedef struct
{
	uint8 Bit0 :1;
	uint8 Bit1 :1;
	uint8 Bit2 :1;
	uint8 Bit3 :1;
	uint8 Bit4 :1;
	uint8 Bit5 :1;
	uint8 Bit6 :1; 
	uint8 Bit7 :1;
	}Bits; 
	typedef union
	{
		uint8 All_Reg;
		Bits Register_Bits;
	}REGISTER;
	
	volatile REGISTER * DDRD_Reg=(  REGISTER *)0X31;
	volatile REGISTER * PORTD_Reg=(  REGISTER *)0X32 ;
	volatile REGISTER * PIND_Reg=(  REGISTER *)0X30;
		//#endif*/
#endif /* MAIN_H_ */