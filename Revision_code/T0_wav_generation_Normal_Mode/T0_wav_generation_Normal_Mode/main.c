/*
 * T0_wav_generation_Normal_Mode.c
 *
 * Created: 7/22/2020 4:59:59 PM
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
{	//dir of 0c0
	DDRB|=(1<<PB3); 
	// NO Prescaler have matter at output wave
	TCCR0|=(1<<COM00)|(1<<CS00)//|(1<<CS02);  //no prescaler ,toggle at com
	//Turn On interrupt OVER FLOW
	//TIMSK|=(1<<TOV0)|(1<<OCIE0); //to enable interrupt
	//Global
	//sei();
	OCR0=127; 
	while (1)
	{
		
    }

}