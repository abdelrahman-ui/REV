/*
* Uart_Layer.c
*
* Created: 7/31/2020 11:09:53 PM
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
typedef struct {
	unsigned long MyBoudRate ;
	unsigned char Data_Size ;
	unsigned char Stop_Bits ;
	unsigned char Parity ;
} Uart_Config;


typedef enum {
	B5 ,
	B6 ,
	B7 ,
	B8 ,
	B9 ,
}Data_Size_type;


typedef enum {
	one_stop ,
	two_stop ,
	
}Stop_bit_type;

typedef enum {
	None ,
	Even ,
	odd  ,
}Parity_type;




int main(void)
{
	DDRC|=(1<<PC2);
	Uart_Init ();
	Uart_Send_String("ABDO \r \n");
	char data ;
	while (1)
	{
		data =Uart_Receive();
		_delay_ms(1000);
		if (data =='1')
		{
			PORTC|=(1<<PC2);
		}
		else
		{
			PORTC&=~(1<<PC2);
		}
		Uart_Send_Char(data);
		_delay_ms(1000);
	}
}

void Uart_Init (Uart_Config *config)
{	
	switch(config->Data_Size)
		{
			case B5 :
			
			break; 
			case B6 :
			
			break;
			case B7 :
			
			break;
			case B8 :
			
			break;
			case B9 :
			
			break;
		}
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
