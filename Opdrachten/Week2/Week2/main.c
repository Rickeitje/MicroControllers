/* ---------------------------------------------------------------------------
** This software is in the public domain, furnished "as is", without technical
** support, and with no warranty, express or implied, as to its usefulness for
** any purpose.
**
** ioisr.c
**
** Beschrijving:	ISR on PORTD demonstrattion
** Target:			AVR mcu
** Build:			avr-gcc -std=c99 -Wall -O3 -mmcu=atmega128 -D F_CPU=8000000UL -c ioisr.c
**					avr-gcc -g -mmcu=atmega128 -o ioisr.elf ioisr.o
**					avr-objcopy -O ihex ioisr.elf ioisr.hex
**					or type 'make'
** Author: 			dkroeske@gmail.com
** -------------------------------------------------------------------------*/

#define F_CPU 8000000
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

void display(int);
void displayloop();


int lampje;
/******************************************************************/
void wait( int ms )
/*
short:			Busy wait number of millisecs
inputs:			int ms (Number of millisecs to busy wait)
outputs:
notes:			Busy wait, not very accurate. Make sure (external)
clock value is set. This is used by _delay_ms inside
util/delay.h
Version :    	DMK, Initial code
*******************************************************************/
{
	for (int i=0; i<ms; i++)
	{
		_delay_ms( 1 );		// library function (max 30 ms at 8MHz)
	}
}

/******************************************************************/
ISR( INT0_vect )
/*
short:			ISR INT0
inputs:
outputs:
notes:			Set PORTD.5
Version :    	DMK, Initial code
*******************************************************************/
{
	PORTC = 0;
	
	if (lampje == 0b10000000)
	{
		lampje = 0b00000001;
		}else{
		lampje = lampje<<1;
	}
	
	PORTC |= (lampje);
	wait(10);
}

/******************************************************************/
ISR( INT1_vect )
/*
short:			ISR INT1
inputs:
outputs:
notes:			Clear PORTD.5
Version :    	DMK, Initial code
*******************************************************************/
{
	PORTC = 0;
	lampje = lampje>>1;
	if(lampje == 0b00000000){
		lampje = 0b10000000;
	}
	
	PORTC |= (lampje);
	wait(10);
}

void displayloop(){

	const unsigned char numbers[7] =
	{
		0b00000001,
		0b00000010,
		0b00000100,
		0b00001000,
		0b00010000,
		0b00100000,
		0b01000000,
	};
	int i = 0;
	while(1)
	{
		PORTD = 0b00000000;
		PORTD = numbers[i];
		if(i<6){
			i++;
		}
		else{
			i=0;
		}
		wait(500);
	}
}


void display(int digit)
{
	const unsigned char Numbers [16] =
	{
		0b00111111, // 0
		0b00000110, // 1
		0b01011011, // 2
		0b01001111, // 3
		0b01100110, // 4
		0b01101101, // 5
		0b01111101, // 6
		0b00000111, // 7
		0b01111111, // 8
		0b01101111, // 9
		0b01110111, // A
		0b01111100, // b
		0b00111001, // C
		0b01011110, // d
		0b01111001, // E
		0b01110001, // F
	};
	
	for(int i = 0; i < 16; i++)
	{
		PORTD = 0b00000000;
		PORTD = Numbers[i];
		wait(500);
	}
}

/******************************************************************/
int main( void )
/*
short:			main() loop, entry point of executable
inputs:
outputs:
notes:			Slow background task after init ISR
Version :    	DMK, Initial code
*******************************************************************/
{
	// Init I/O
	DDRD = 0b11111111;
	//DDRC = 0b11111111;
	
	//lampje = 0b00000001;
	// Init Interrupt hardware
	//EICRA |= 0x0B;			// INT1 falling edge, INT0 rising edge
	//EIMSK |= 0x03;			// Enable INT1 & INT0
	
	// Enable global interrupt system
	//SREG = 0x80;			// Of direct via SREG of via wrapper
	//sei();
	
	while (1)
	{
		//PORTD ^= (1<<7);	// Toggle PORTD.7
		//wait( 500 );
		displayloop();
	}

	return 1;
}