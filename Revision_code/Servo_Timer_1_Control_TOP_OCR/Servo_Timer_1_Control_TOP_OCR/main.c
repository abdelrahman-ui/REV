/*
 * Servo_Timer_1_Control_TOP_OCR.c
 *
 * Created: 7/28/2020 1:10:23 AM
 * Author : User™
 */ 

#define F_CPU 16000000UL
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

#define  MAX_Angle		180
#define  Mini_Angle		0
#define  MAX_Count		500
#define  Mini_Count		250

void Servo_Motor(unsigned short Angle  );

int main(void)
{	// Take The Mode  Fast _PWM__Action_non_inverting 
   TCCR1A|=(1<<WGM11)|(1<<COM1A1);
   TCCR1B|=(1<<WGM12)|(1<<WGM13);
    //Dir of  OC1A & OC1B
   DDRD|=(1<<PD4)|(1<<PD5);
    //Prescaler 64
	TCCR1B|=(1<<CS11)|(1<<CS10);
	//Make TOP =5000 
	ICR1 = 4999;
	
    while (1) 
    {
		_delay_ms(2000);
		Servo_Motor(0);
		_delay_ms(2000);
		Servo_Motor(45);
		_delay_ms(2000);
		Servo_Motor(90);
		_delay_ms(2000);
		Servo_Motor(125);
		_delay_ms(2000);
		Servo_Motor(170);
		_delay_ms(2000);
    }
}

// Control Duty Cycle To Control Angle Of The Servo 
void Servo_Motor(unsigned short Angle  ) //m4 fahem el char m4 btege badel el short 
{
	 OCR1A = ((( Angle - Mini_Angle )*(MAX_Count -Mini_Count))/(MAX_Angle - Mini_Angle))+250-1;
}