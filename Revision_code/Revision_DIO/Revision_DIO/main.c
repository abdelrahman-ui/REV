/*
* Revision_DIO.c
*
* Created: 7/5/2020 5:28:15 AM
* Author : User™
*/
#define  F_CPU 16000000UL
#include <avr/io.h>
#include "Bit_Math.h"
#include <util/delay.h>
#include "main.h"
int main(void)
{
	Set_Bit(DDRD_Reg,6);
	Clear_Bit(DDRD_Reg,0);
	while (1)
	{
		if(Get_Bit(PIND_Reg,0)==1)
		{
			_delay_ms(20);
			Set_Bit(PORTD_Reg,6);
			_delay_ms(250);
			
		}
		
   

}

/*int main(void)
{

DDRD_Reg->Register_Bits.Bit6=1;
DDRD_Reg->Register_Bits.Bit0=0;
while(1)
{
if(PIND_Reg->Register_Bits.Bit0==1)
{
_delay_ms(20);
PORTD_Reg->Register_Bits.Bit6=1;
_delay_ms(1000);
PORTD_Reg->Register_Bits.Bit6=0;
_delay_ms(1000);
}
}
}*/