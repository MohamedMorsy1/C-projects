/*
 * dio.c
 *
 * Created: 9/23/2022 9:59:48 PM
 *  Author: Mohamed
 */ 

#include "dio.h"

EN_DIO_ERROR_t DIO_init(uint8_t portNum, uint8_t pinNum, uint8_t direction)
{
	if(pinNum>7 || pinNum<0) return WRONG_PIN;  // handle error wrong pin 
	switch (portNum)
	{
		case 'A':
			if(direction==IN) DDRA &=~(1<<pinNum) ;  //input
			else if(direction==OUT) DDRA |=(1<<pinNum) ; //output
			else return WRONG_DIRECTION;                //// handle error wrong direction
			break;
		
		case 'B':
			if(direction==IN) DDRB &=~(1<<pinNum) ;  //input
			else if(direction==OUT) DDRB |=(1<<pinNum) ; //output
			else return WRONG_DIRECTION;                //// handle error wrong direction
			break;	
		
		case 'C':
			if(direction==IN) DDRC &=~(1<<pinNum) ;  //input
			else if(direction==OUT) DDRC |=(1<<pinNum) ; //output
			else return WRONG_DIRECTION;                //// handle error wrong direction
			break;		
		
		case 'D':
			if(direction==IN) DDRD &=~(1<<pinNum) ;  //input
			else if(direction==OUT) DDRD |=(1<<pinNum) ; //output
			else return WRONG_DIRECTION;                //// handle error wrong direction
			break;
	
		default: return WRONG_PORT ;           //// handle error wrong port
	}
	
	return OK;
}



EN_DIO_ERROR_t DIO_write(uint8_t portNum, uint8_t pinNum, uint8_t value)

{
	if(pinNum>7 || pinNum<0) return WRONG_PIN;  // handle error wrong pin 
	switch (portNum)
	{
		case 'A':
		if(value==LOW) PORTA &=~(1<<pinNum) ;  //
		else if(value==HIGH) PORTA |=(1<<pinNum) ; //
		else return WRONG_VALUE;                //// handle error wrong value
		break;
		
		case 'B':
		if(value==LOW) PORTB &=~(1<<pinNum) ;  //
		else if(value==HIGH) PORTB |=(1<<pinNum) ; //
		else return WRONG_VALUE;
		break;
		
		case 'C':
		if(value==LOW) PORTC &=~(1<<pinNum) ;  //
		else if(value==HIGH) PORTC |=(1<<pinNum) ; //
		else return WRONG_VALUE;
		break;
		
		
		case 'D':
		if(value==LOW) PORTD &=~(1<<pinNum) ;  //
		else if(value==HIGH) PORTD |=(1<<pinNum) ; //
		else return WRONG_VALUE;
		break;
		
		default: return WRONG_PORT ;           //// handle error wrong port
		
	}
	
	return OK;
}



EN_DIO_ERROR_t DIO_toggle(uint8_t portNum, uint8_t pinNum)    
{  
	if(pinNum>7 || pinNum<0) return WRONG_PIN;  // handle error wrong pin 
	switch (portNum)
	{
		case 'A':
		 PORTA ^= (1<<pinNum);
		
		break;
		
		case 'B':
		 PORTB ^= (1<<pinNum);
		
		break;
		
		case 'C':
		  PORTC ^= (1<<pinNum);
		
		break;
		
		case 'D':
		  PORTD ^= (1<<pinNum);
		
		break;
		
		default: return WRONG_PORT ;           //// handle error wrong port
	}
return OK;
}


EN_DIO_ERROR_t DIO_read(uint8_t portNum, uint8_t pinNum, uint8_t *value)
{
	if(pinNum>7 || pinNum<0) return WRONG_PIN;  // handle error wrong pin 
		switch (portNum)
		{
			case 'A':
			 *value = (PINA & (1<<pinNum)) >> pinNum;
			
			break;
			
			case 'B':
			  *value = (PINB & (1<<pinNum)) >> pinNum;
			
			break;
			
			case 'C':
			*value = (PINC & (1<<pinNum)) >> pinNum;
		 
			break;
			
			case 'D':
			 
			 *value = (PIND & (1<<pinNum)) >> pinNum;
			break;
			
			default: return WRONG_PORT ;           //// handle error wrong port
		}
return OK;	
}