/*
 * T0_Fast_PWM_Motor.c
 *
 * Created: 7/26/2020 4:09:40 AM
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
	DDRD|=(1<<PD0)|(1<<PD1);

	// Fast _ pwm _ non inverting _no prescaler _ toggle on compare match
	TCCR0|=(1<<COM01)|(1<<CS00)|(1<<WGM01)|(1<<WGM00);//|(1<<CS02);  //no prescaler ,toggle at com
	//Turn On interrupt OVER FLOW
	//TIMSK|=(1<<TOV0)|(1<<OCIE0); //to enable interrupt
	//Global
	//sei();
  OCR0=255;
	while (1)
	{
			
			PORTD|=(1<<PD1);
			PORTD&=~(1<<PD0);
	}

}
