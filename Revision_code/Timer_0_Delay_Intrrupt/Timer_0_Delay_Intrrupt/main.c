/*
 * Timer_0_Delay_Intrrupt.c
 *
 * Created: 7/20/2020 5:34:12 PM
 * Author : User™
 */ 
#define F_CPU 16000000UL
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
volatile unsigned char count_0 =0 ;
volatile unsigned char count_1 =0 ;
volatile unsigned char count_2 =0 ;

int main(void)
{	//Prescaler 16000000/64 
	TCCR0|=(1<<CS00)|(1<<CS01);
	//Turn On interrupt OVER FLOW
	TIMSK|=(1<<TOV0);
	//Global 
	sei();
	DDRD|=(1<<PD5)|(1<<PD6)|(1<<PD7);
    while (1) 
    {
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

ISR(TIMER0_OVF_vect)
{
	count_0 ++;
	count_1 ++;
	count_2 ++;
}