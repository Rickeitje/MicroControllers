
#define F_CPU 8000000

#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

typedef unsigned long int u_int32;
typedef unsigned int u_int16;

u_int16 measured = 0;

ISR(ADC_vect)
{
	u_int32 result = ADC;
	result *= 5000;
	result /= 1023;
	measured = result;
}

void adcInit( void )
{
	ADMUX = 0x01;
	ADCSRA = 0xEE;
}

int main(void)
{
	DDRA = 0xFF;
	DDRB = 0xFF;
	DDRF = 0x00;
	
	adcInit();
	
	sei();
	
	while (1)
	{
		u_int32 lamps = measured / 625 ;
		
		if(lamps<=1)
		PORTA = PORTB = 0b10000000;
		else if(lamps <= 2)
		PORTA = PORTB = 0b11000000;
		else if(lamps <= 3)
		PORTA = PORTB = 0b11100000;
		else if(lamps <= 4)
		PORTA = PORTB = 0b11110000;
		else if(lamps <= 5)
		PORTA = PORTB = 0b111111000;
		else if(lamps <= 6)
		PORTA = PORTB = 0b111111100;
		else if(lamps <= 7)
		PORTA = PORTB = 0b111111110;
		else
		PORTA = PORTB = 0b111111111;		
	}
}
