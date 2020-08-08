/*
 * Smart_Slave.c
 *
 * Created: 8/8/2020 8:29:58 AM
 * Author : User™
 */ 

#define F_CPU 16000000
#include <avr/io.h>
#include <util/delay.h>
#define  SS		4
#define MOSI	5
#define MISO	6
#define LED0	0
#define LED1	1
#define LED2	2
#define LED3	3
unsigned char SPI_Transfer(unsigned char sendByte){
	
	SPDR =sendByte;
	while(!(SPSR&(1<<SPIF)));
	return SPDR;
}
int main(void)
{
	DDRB|=(1<<MISO);
	DDRB&=~(1<<SS); //input pin
	DDRC|=(1<<LED0)|(1<<LED1)|(1<<LED2)|(1<<LED3);
	
	SPCR|=(1<<SPE);

	while (1)
	{
		unsigned char recv=SPI_Transfer(0x55);
		_delay_ms(1000);
		switch(recv)
		{
			case 0xAA :
			SPI_Transfer(0X55);
			_delay_ms(1000);
			PORTC^=(1<<LED0);
			_delay_ms(1000);
			SPDR=0X00;
			break;
			case 0xBB :
			SPI_Transfer(0X66);
			_delay_ms(1000);
			PORTC^=(1<<LED1);
			_delay_ms(1000);
			break;
			case 0xDD :
			SPI_Transfer(0X77);
			_delay_ms(1000);
			PORTC^=(1<<LED2);
			_delay_ms(1000);
			break;
			case 0xFF :
			SPI_Transfer(0X88);
			_delay_ms(1000);
			PORTC^=(1<<LED3);
			_delay_ms(1000);
			break;
			
		}
		
		
	}

}


