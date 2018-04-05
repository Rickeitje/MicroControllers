/*
* main.c
*
* Created: 3/31/2018 2:26:01 PM
*  Author: Ricky Hoogerdijk && Kevin Quist
*/

#define F_CPU 8000000

#include <avr/interrupt.h>
#include <avr/io.h>
#include <util/delay.h>
#include <string.h>
#include "ledmatrix.h"
#include "textutil.h"

void clearMatrix(void){
	int i;
	for(i = 0x00; i < 0x10; i++){
		writeData(i, 0);
	}
}

int main(void){
	DDRA = 0b11111111;

	EICRB |= 0b11000000; //set INT7 faling edge
	EIMSK |= 0b10000000; //enable INT&
	//enable global interrupt system
	
	
	twi_init();
	sei();
	
	//int data[] = {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x3f, 0x04, 0x04, 0x04, 0x3f,0x00, 0x3f, 0x21, 0x21, 0x21, 0x3f,0x00, 0x21, 0x21, 0x3f, 0x21, 0x21,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00};
	
	
	clearMatrix();
	
	stringToTextArray();
	
	
	
	return 1;
}


