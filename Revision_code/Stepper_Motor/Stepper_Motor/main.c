  /*
 * Stepper_Motor.c
 *
 * Created: 7/29/2020 2:47:07 AM
 * Author : User™
 */ 
#define  F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h> 
#define Stepper_Dir		DDRC
#define Stepper_PORT		PORTC
#define H_bridage_Dir	DDRD
#define H_bridage_Port	PORTD

void Stepper_Motor(unsigned char mode);

int main(void)
{  
	Stepper_Dir|=(1<<PC3)|(1<<PC4)|(1<<PC5)|(1<<PC6); 
	//Enable For H_bridage
	H_bridage_Dir|=(1<<PD4)|(1<<PD5);
	//Enable open Always
	H_bridage_Port|=(1<<PD4)|(1<<PD5);
    while (1) 
    {
		
		Stepper_Motor(1);
		_delay_ms(1000);
		Stepper_PORT|=0X00;			//MAKE ALL=0
		Stepper_Motor(2);
		_delay_ms(1000);
		Stepper_PORT|=0X00;
		Stepper_Motor(3);
		_delay_ms(1000);
		Stepper_PORT|=0X00;
		Stepper_Motor(4);
		_delay_ms(1000);
		Stepper_PORT|=0X00;
    }
}

void Stepper_Motor(unsigned char mode)
{
	switch(mode)
	  {
		  case  1 : //C
				Stepper_PORT |=(1<<PC5)|(1<<PC6); 
				Stepper_PORT &=~(1<<PC3)|(1<<PC4);
				
			 break;
		  case 2 : //6
				Stepper_PORT |=(1<<PC5)|(1<<PC4);
				Stepper_PORT &=~(1<<PC3)|(1<<PC6);
			break;
			    
		  case  3://3
		      Stepper_PORT |=(1<<PC3)|(1<<PC4);
		      Stepper_PORT &=~(1<<PC5)|(1<<PC6);
			break;
		  case  4 ://9
				Stepper_PORT |=(1<<PC3)|(1<<PC6);
				Stepper_PORT &=~(1<<PC5)|(1<<PC4);
			break;
			 
	  }
}