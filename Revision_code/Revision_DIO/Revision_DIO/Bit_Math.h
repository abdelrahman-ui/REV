/*
 * Bit_Math.h
 *
 * Created: 7/5/2020 5:37:04 AM
 *  Author: User™
 */ 


#ifndef BIT_MATH_H_
#define BIT_MATH_H_

#define  Set_Bit(Reg,Bit) (Reg|=(1<<Bit))
#define  Clear_Bit(Reg,Bit) (Reg &=~ (1<<Bit))
#define  Get_Bit(Reg,Bit) ((Reg>>Bit)&1)
#define TOGGLE_BIT(REG,BIT) REG^=(1<<BIT)

#endif /* BIT_MATH_H_ */