/*
 * T0_wave_generation_CTC_Mode.c
 *
 * Created: 7/22/2020 6:14:37 PM
 * Author : User™
 */ 
#define F_CPU 16000000UL
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
volatile unsigned char oc[2] ={76,178} ;//30 %
volatile unsigned short OCR_Count =0 ;

int main(void)
{	//dir of 0c0
	DDRB|=(1<<PB3);
	DDRD|=(1<<PD1)|(1<<PD0);
	// NO Prescaler have matter at output wave ctc mode
	TCCR0|=(1<<COM00)|(1<<CS00)|(1<<WGM01);//|(1<<CS02);  //no prescaler ,toggle at com
	//Turn On interrupt OVER FLOW
	TIMSK|=(1<<OCIE0); //to enable interrupt
	TIFR|=(1<<OCF0);
	//Global
	sei();
	OCR0=oc[count];
	while (1)
	{
		
		
	}

}
ISR(TIMER0_COMP_vect)
{
	OCR_Count++;
	if(OCR_Count==1)
	{
		OCR0 = OC[OCR_Count];
	}
	else {
		OCR_Count=0;
		OCR0 = OC[OCR_Count];
	}

	
  }