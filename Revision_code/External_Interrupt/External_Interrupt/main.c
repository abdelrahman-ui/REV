/*
 * External_Interrupt.c
 *
 * Created: 7/18/2020 3:08:55 AM
 * Author : User™
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>
#define  Led_0  0
#define  Led_1  1

#include <util/delay.h>
#include "bit_math.h"
#define  PD2  2

ISR (INT0_vect)
{
	PORTA^=(1<<Led_0);
	while(GET_BIT(PIND,PD2));
	PORTA^=(1<<Led_0);
}

ISR (INT1_vect)
{
	PORTA^=(1<<Led_1);
	while(GET_BIT(PIND,PD3));
	PORTA^=(1<<Led_1);
}

int main(void)
{
	DDRA|=(1<<Led_0)|(1<<Led_1);
    //Enable pin interrupt from GICR
	GICR|=(1<<INT0);
	GICR|=(1<<INT1);
	//Change at Raissing edag
	MCUCR|=(1<<ISC00)|(1<<ISC01);
	MCUCR|=(1<<ISC10)|(1<<ISC11);
	//Enable Global 
	sei();
    while (1) 
    {
    }
}

