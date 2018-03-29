/*
* Week3.c
*
* Created: 2/22/2018 4:32:30 PM
* Author : Ricky
*/



#define F_CPU 8000000
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include <stdlib.h>
#include "lcd.h"

static char zin[] = "Hallo Diedrich";
int count = 0;
char buffer[20];

ISR(TIMER2_OVF_vect){
	for(int i = 0; i < 100; i++){
		count++;
	clearDisplay();
	//display_text(' ');
	display_text(itoa(count, buffer, 10));
	//if(count > 99){
		//lcd_writeChar(count/100+'0');
		//lcd_writeChar(count%100+'0');
		//}else if(count > 9){
			//lcd_writeChar(count/10+'0');
			//lcd_writeChar(count%10+'0');
		//}else{
			//lcd_writeChar(count+'0');
	//}
	TCNT2 = -1;
	_delay_ms(150);
	}
}




int main(void)
{
	DDRD = 0xFF;
	DDRC = 0xFF;
	PORTC = 0x00;
	
	TCNT2 = -1;
	TIMSK |= (1 << 6);
	SREG |= (1 << 7);
	TCCR2 = 0b0000111;
	sei();
	
	init();
	clearDisplay();
	display_text(zin);
	
	while(1){
		_delay_ms(200);
	}
	
}

