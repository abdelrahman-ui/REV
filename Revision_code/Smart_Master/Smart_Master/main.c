/*
 * Smart_Master.c
 *
 * Created: 8/8/2020 7:44:39 AM
 * Author : User™
 */ 

#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

#define BAUD	9600
#define BAUD_EQ ((F_CPU/(BAUD*16UL))-1)
#define MOSI	5
#define MISO	6
#define SCK		7
#define CS		0
#define LED0	4

#define SS_ENABLE()		PORTC&=~(1<<CS)
#define SS_DISABLE()	PORTC|=(1<<CS)

#define SS_ENABLE()		PORTC&=~(1<<CS)
#define SS_DISABLE()	PORTC|=(1<<CS)

void Uart_Init ();
void Uart_Send_Char(unsigned char data);
void Uart_Send_String( char *Str);
char Uart_Receive();
void SPI_Init();
unsigned char SPI_Transfer(unsigned char sendByte);
volatile char recv_buf,recv_flag,recv_byte;

int main(void)
{
	
	DDRC|=(1<<PC2)|(1<<PC3)|(1<<PC1)|(1<<PC0);
	Uart_Init ();
	Uart_Send_String("ABDO \r \n");
	char data ;
	SPI_Init();
	while (1)
	{
		data =Uart_Receive();
		switch(data)
		{
			case '1' :
			SS_ENABLE();
			unsigned char recvByte=SPI_Transfer(0xAA);
			SS_DISABLE();
			_delay_ms(1000);
			if (recvByte==0x55)
			{
				PORTC^=(1<<LED0);
				_delay_ms(1000);
			}
			break;
			case '2' :
			SS_ENABLE();
			unsigned char recvByte_1=SPI_Transfer(0xBB);
			SS_DISABLE();
			_delay_ms(1000);
			if (recvByte_1==0x66)
			{
				PORTC^=(1<<PC1);
				_delay_ms(1000);
			}
			break;
			case '3' :
			SS_ENABLE();
			unsigned char recvByte_2=SPI_Transfer(0xDD);
			SS_DISABLE();
			_delay_ms(1000);
			if (recvByte_2==0x77)
			{
				PORTC^=(1<<PC2);
				_delay_ms(1000);
			}
			break;
			case '4' :
			SS_ENABLE();
			unsigned char recvByte_3=SPI_Transfer(0xFF);
			SS_DISABLE();
			_delay_ms(1000);
			if (recvByte_3==0x88)
			{
				PORTC^=(1<<PC4);
				_delay_ms(1000);
			}
			break;
		}
	}
}

void Uart_Init ()
{
	// Initialize Boud Rate
	UBRRL=BAUD_EQ;
	// Transimate & Resive & Enable interrupt of reciver complete
	UCSRB |=(1<<RXCIE)|(1<<RXEN)|(1<<TXEN);
	//Number Of Stop bits & size from [5.....9] & No parity & Asynchronous
	UCSRC |=(1<<URSEL)|(1<<UCSZ1)|(1<<UCSZ0);
	
}


void Uart_Send_Char( unsigned char data)
{
	//Send data
	while(!(UCSRA&(1<<UDRE)));//polling
	UDR=data;

}


char Uart_Receive()
{
	while(!(UCSRA&(1<<RXC)));   //make sure i have data now
	return UDR;

}

void Uart_Send_String( char *Str)
{
	unsigned short i=0;
	while(Str[i]!='\0'){
		Uart_Send_Char(Str[i]);
		i++;
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