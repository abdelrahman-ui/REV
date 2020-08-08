/*
 * Timer_0_Polling_3_led^.c
 *
 * Created: 7/20/2020 6:01:54 PM
 * Author : User™
 */ 

#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>

volatile unsigned char count_0 =0 ;
volatile unsigned char count_1 =0 ;
volatile unsigned char count_2 =0 ;

int main(void)
{	//Prescaler 16000000/64
	TCCR0|=(1<<CS00)|(1<<CS01);
	DDRD|=(1<<PD5)|(1<<PD6)|(1<<PD7);
	while (1)
	{   
		//check
		while(!((TIFR>>TOV0)&1 ));
		//CLEAR falg
		TIFR |=(1<<TOV0);
		count_0 ++;
		count_1 ++;
		count_2 ++;
		if (count_0==200)
		{
			PORTD^=(1<<PD7);
			
			count_0 =0;
		}
		if (count_1==100)
		{
			PORTD^=(1<<PD5);
			
			count_1 =0;
		}
		if (count_2==250)
		{
			PORTD^=(1<<PD6);
			
			count_2 =0;
		}
		
	}
}

