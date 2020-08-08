/*
 * Uart.h
 *
 * Created: 8/8/2020 7:46:17 AM
 *  Author: User™
 */ 


#ifndef UART_H_
#define UART_H_


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


#endif /* UART_H_ */