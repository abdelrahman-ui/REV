/*
 * T0_wave_genration_change_OCR_AT_runtime_CTC.c
 *
 * Created: 7/22/2020 6:25:17 PM
 * Author : User™
 */ 


#define F_CPU 16000000UL
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
volatile unsigned short OC[4] = {10,100,170,220} ;
volatile unsigned short OCR_Count =0;  

int main(void)
{	//dir of 0c0
	DDRB|=(1<<PB3);
	// NO Prescaler have matter at output wave ctc mode
	TCCR0|=(1<<COM00)|(1<<CS00)|(1<<WGM01);//|(1<<CS02);  //no prescaler ,toggle at com
	//Turn On interrupt OVER FLOW
	TIMSK|=(1<<TOV0)|(1<<OCIE0); //to enable interrupt
	//Global
	sei();
	OCR0=OC[0];
	while (1)
	{
		
		
	}

}

ISR (TIMER0_COMP_vect)
{
	
	OCR_Count++;
	if(OCR_Count<4)
	{
		OCR0 = OC[OCR_Count];
	} 
	else {
		OCR_Count=0;
		OCR0 = OC[OCR_Count];
	}
}