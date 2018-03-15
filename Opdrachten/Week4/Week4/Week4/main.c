
#define F_CPU 8000000

#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include <string.h>

#include "lcd.h"
//
//typedef unsigned long int u_int32;
//typedef unsigned int u_int16;
//
//u_int16 measured = 0;

//ISR(ADC_vect)
//{
	//u_int32 result = ADC;
	//result *= 5000;
	//result /= 1023;
	//measured = result;
//}

void adcInit( void )
{
	ADMUX = 0x01;
	ADCSRA = 0xEE;
}

int main(void)
{
	char zin[16];
	int temp;
	DDRA = 0xFF;
	DDRB = 0xFF;
	DDRC = 0xFF;
	DDRD = 0x00;
	DDRF = 0x00;
	
	ADMUX = 0b11100000;
	ADCSRA = 0b11100110;
	
	init();
	
	display_text("Werkt dit ding");
	
	//adcInit();
	
	//sei();
	
	while (1)
	{		
		clearDisplay();
		temp = ADCH;
		sprintf(zin, "Temperatuur %d", temp);
		display_text(zin);
		PORTA = ADCH;
		wait(1000);		
		
		//u_int32 lamps = measured / 625 ;
		//
		//if(lamps<=1)
		//PORTA = PORTB = 0b10000000;
		//else if(lamps <= 2)
		//PORTA = PORTB = 0b11000000;
		//else if(lamps <= 3)
		//PORTA = PORTB = 0b11100000;
		//else if(lamps <= 4)
		//PORTA = PORTB = 0b11110000;
		//else if(lamps <= 5)
		//PORTA = PORTB = 0b111111000;
		//else if(lamps <= 6)
		//PORTA = PORTB = 0b111111100;
		//else if(lamps <= 7)
		//PORTA = PORTB = 0b111111110;
		//else
		//PORTA = PORTB = 0b111111111;		
	}	
	
}


void wait( int ms )
{
	for (int tms=0; tms<ms; tms++)
	{
		_delay_ms( 1 );			// library function (max 30 ms at 8MHz)
	}
}