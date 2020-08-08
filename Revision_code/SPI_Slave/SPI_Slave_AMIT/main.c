/*
 * SPI_Slave_AMIT.c
 *
 * Created: 5/2/2020 3:10:48 PM
 * Author : infin
 */ 
#define F_CPU 16000000
#include <avr/io.h>
#include <util/delay.h>
#define  SS		4
#define MOSI	5
#define MISO	6
#define LED0	2

void DC_Init();
unsigned char SPI_Transfer(unsigned char sendByte);
int main(void)
{
	DC_Init();
	DDRB|=(1<<MISO);
	DDRB&=~(1<<SS); //input pin
	DDRC|=(1<<LED0);
	
	SPCR|=(1<<SPE);

    while (1) 
    {
		unsigned char recv=SPI_Transfer(0x55);
		_delay_ms(1000);
		if(recv==0xAA){
			PORTD|=(1<<PD1);
			PORTD&=~(1<<PD0);
			PORTC^=(1<<LED0);
			_delay_ms(1000);
		}
    }
}

void DC_Init()
{
	//dir of 0c0
	DDRB|=(1<<PB3);
	DDRD|=(1<<PD0)|(1<<PD1);

	// Fast _ pwm _ non inverting _no prescaler _ toggle on compare match
	TCCR0|=(1<<COM01)|(1<<CS00)|(1<<WGM01)|(1<<WGM00);//|(1<<CS02);  //no prescaler ,toggle at com
	//Turn On interrupt OVER FLOW
	//TIMSK|=(1<<TOV0)|(1<<OCIE0); //to enable interrupt
	//Global
	//sei();
	OCR0=255;
}
unsigned char SPI_Transfer(unsigned char sendByte){
	
	SPDR =sendByte;
	while(!(SPSR&(1<<SPIF)));
	return SPDR;
}