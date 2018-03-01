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


int main(void)
{
    /* Replace with your application code */
   
		init();
		display_text();
		while(1){

		}
    
}

