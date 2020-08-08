/*
 * UART_REV.c
 *
 * Created: 7/31/2020 5:42:44 AM
 * Author : User™
 */ 
#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

#define BAUD	9600
#define BAUD_EQ ((F_CPU/(BAUD*16UL))-1)

 void Uart_Init ();
 void Uart_Send_Char(unsigned char data);
 void Uart_Send_String( char *Str);
  char Uart_Receive();
 
 volatile char recv_buf,recv_flag,recv_byte;
 
int main(void)
{
	DDRC|=(1<<PC2)|(1<<PC3)|(1<<PC1)|(1<<PC0);
    Uart_Init ();
	Uart_Send_String("ABDO \r \n");
	char data ;
    while (1) 
    {
		data =Uart_Receive();
		switch(data)
		{
			case '1' :
			PORTC|=(1<<PC0);
			_delay_ms(500);
			PORTC&=~(1<<PC0);
			break;
			case '2' :
			PORTC|=(1<<PC1);
			_delay_ms(500);
			PORTC&=~(1<<PC2);
			break;
			case '3' :
			PORTC|=(1<<PC2);
			_delay_ms(500);
			PORTC&=~(1<<PC2);
			break;
			case '4' :
			PORTC|=(1<<PC3);
			_delay_ms(500);
			PORTC&=~(1<<PC3);
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