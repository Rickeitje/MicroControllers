/*
 * OpdrachtB3.c
 *
 * Created: 2018-03-29 13:27:30
 * Author : Kevin Quist
 */ 

#define F_CPU 8000000

#include <avr/io.h>
#include <avr/delay.h>
#include <avr/interrupt.h>


int counter = 0;

ISR(TIMER2_COMP_vect){
	counter++;
	counter = counter % 40;
	
	if(counter == 0) {
		PORTD = 0b10000000;
		} else if(counter == 15) {
		PORTD = 0b00000000;
	}	
}


int main(void)
{
	TCNT2 = 0;
	OCR2 = 125;
	TIMSK |= (1 << 7);
	TCCR2 = 0b00001011;
	
	DDRC = 0xFF;
	DDRD = 0xFF;
	DDRB = 0xFF;
	
	sei();	
	
    while (1) 
    {
    }
}

