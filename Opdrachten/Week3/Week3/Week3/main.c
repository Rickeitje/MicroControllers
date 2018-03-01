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
#include "lcd.h"

static char zin[] = "Hallo Diedrich";

int main(void)
{
    /* Replace with your application code */
		DDRD = 0xFF;
		DDRC = 0xFF;
		PORTC = 0x00;
   
   
		init();
		clearDisplay();
		display_text(zin);
		while(1){
			_delay_ms(200);
		}
    
}

