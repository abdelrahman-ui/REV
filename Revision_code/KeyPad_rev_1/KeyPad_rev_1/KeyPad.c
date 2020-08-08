/*
 * KeyPad.c
 *
 * Created: 7/9/2020 10:54:37 AM
 *  Author: User™
 */ 
#include "KeyPad.h"

void Check_1()
{
	KeyPad_Port=0xEF;
	if(((KeyPad_Pin>>r1)&1)==0)
	{
		
		PORTA|=(1<<0);
		while(((KeyPad_Pin>>r1)&1)==0) ; //6ool ma 2na da8et zaher 
		PORTA&=~(1<<0);
	}
	else if(((KeyPad_Pin>>r2)&1)==0)
	{
		_delay_ms(5);
		PORTA|=(1<<1);
		while(((KeyPad_Pin>>r2)&1)==0) ; //6ool ma 2na da8et
		PORTA&=~(1<<1);
	}
	else if(((KeyPad_Pin>>r3)&1)==0)
	{
		
		PORTA|=(1<<2);
		while(((KeyPad_Pin>>r3)&1)==0) ; //6ool ma 2na da8et
		PORTA&=~(1<<2);
	}
	else if(((KeyPad_Pin>>r4)&1)==0)
	{
		
		PORTA|=(1<<3);
		while(((KeyPad_Pin>>r4)&1)==0) ; //6ool ma 2na da8et
		PORTA&=~(1<<3);
	}
}
void Check_2()
{
	KeyPad_Port=0xDF;
	if(((KeyPad_Pin>>r1)&1)==0)
	{
		
		PORTA|=(1<<0);
		while(((KeyPad_Pin>>r1)&1)==0) ; //6ool ma 2na da8et
		PORTA&=~(1<<0);
	}
	else if(((KeyPad_Pin>>r2)&1)==0)
	{
		_delay_ms(5);
		PORTA|=(1<<1);
		while(((KeyPad_Pin>>r2)&1)==0) ; //6ool ma 2na da8et
		PORTA&=~(1<<1);
	}
	else if(((KeyPad_Pin>>r3)&1)==0)
	{
		
		PORTA|=(1<<2);
		while(((KeyPad_Pin>>r3)&1)==0) ; //6ool ma 2na da8et
		PORTA&=~(1<<2);
	}
	else if(((KeyPad_Pin>>r4)&1)==0)
	{
		
		PORTA|=(1<<3);
		while(((KeyPad_Pin>>r4)&1)==0) ; //6ool ma 2na da8et
		PORTA&=~(1<<3);
	}
	
}
void Check_3()
{
	KeyPad_Port=0xBF;
	if(((KeyPad_Pin>>r1)&1)==0)
	{
		
		PORTA|=(1<<0);
		while(((KeyPad_Pin>>r1)&1)==0) ; //6ool ma 2na da8et
		PORTA&=~(1<<0);
	}
	else if(((KeyPad_Pin>>r2)&1)==0)
	{
		_delay_ms(5);
		PORTA|=(1<<1);
		while(((KeyPad_Pin>>r2)&1)==0) ; //6ool ma 2na da8et
		PORTA&=~(1<<1);
	}
	else if(((KeyPad_Pin>>r3)&1)==0)
	{
		
		PORTA|=(1<<2);
		while(((KeyPad_Pin>>r3)&1)==0) ; //6ool ma 2na da8et
		PORTA&=~(1<<2);
	}
	else if(((KeyPad_Pin>>r4)&1)==0)
	{
		
		PORTA|=(1<<3);
		while(((KeyPad_Pin>>r4)&1)==0) ; //6ool ma 2na da8et
		PORTA&=~(1<<3);
	}
}
void Check_4()
{
	KeyPad_Port=0x7F;
	if(((KeyPad_Pin>>r1)&1)==0)
	{
		
		PORTA|=(1<<0);
		while(((KeyPad_Pin>>r1)&1)==0) ; //6ool ma 2na da8et
		PORTA&=~(1<<0);
	}
	else if(((KeyPad_Pin>>r2)&1)==0)
	{
		_delay_ms(5);
		PORTA|=(1<<1);
		while(((KeyPad_Pin>>r2)&1)==0) ; //6ool ma 2na da8et
		PORTA&=~(1<<1);
	}
	else if(((KeyPad_Pin>>r3)&1)==0)
	{
		
		PORTA|=(1<<2);
		while(((KeyPad_Pin>>r3)&1)==0) ; //6ool ma 2na da8et
		PORTA&=~(1<<2);
	}
	else if(((KeyPad_Pin>>r4)&1)==0)
	{
		
		PORTA|=(1<<3);
		while(((KeyPad_Pin>>r4)&1)==0) ; //6ool ma 2na da8et
		PORTA&=~(1<<3);
	}
}