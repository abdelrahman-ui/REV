/*
 * SPI_Master.c
 *
 * Created: 5/2/2020 2:33:16 PM
 * Author :Abdelrahman_Magdy
 
 *LAB01-SPI
 *Requirements:
 *Configure SPI in MODE 0 and with 1Mhz Speed
 *MSB as a data order
 *Polling Mode
 */ 

#define MOSI	5
#define MISO	6
#define SCK		7
#define CS		0
#define LED0	2

#define SS_ENABLE()		PORTC&=~(1<<CS)
#define SS_DISABLE()	PORTC|=(1<<CS)

#define F_CPU 16000000UL			/* Define CPU Frequency e.g. here 8MHz */
#include <util/delay.h>
#include "lcd.h"
#include <avr/io.h>
#include <avr/interrupt.h>


void SPI_Init();
unsigned char SPI_Transfer(unsigned char sendByte);
int main(void)
{
    SPI_Init();
	LCD_Init();
	LCD_Char('M');
    while (1) 
    {
		LCD_Command (0x01);		/* Clear display */
		_delay_ms(2);
		LCD_Command (0x80);		/* Cursor at home position */
		LCD_String("HI");
		SS_ENABLE();
		unsigned char recvByte=SPI_Transfer(0xAA);
		SS_DISABLE();
		_delay_ms(1000);
		if (recvByte==0x55)
		{
		
			PORTC^=(1<<LED0);
			_delay_ms(1000);
			
		}
    }
}
void SPI_Init(){
	//data direction for SPI bus Pins
	DDRB|=(1<<MOSI)|(1<<SCK);
	DDRC|=(1<<CS)|(1<<LED0);
	//MODE0-CPOL=0 CPHA=0 , SPE=1 , MSTR=1 DORD=MSB(0) , SPEED=FOSC/16=1Mhz
	SPCR|=(1<<MSTR)|(1<<SPE)|(1<<SPR0);
	
}

unsigned char SPI_Transfer(unsigned char sendByte){
	//
	SPDR=sendByte;
	while(!(SPSR&(1<<SPIF)));
	return SPDR;
}
