/* ---------------------------------------------------------------------------
** This software is in the public domain, furnished "as is", without technical
** support, and with no warranty, express or implied, as to its usefulness for
** any purpose.
**
** ledmatrix.c
**
** Beschrijving:	Simple HT16K33 Ledmatix demo.
** Target:			AVR mcu
** Build:			avr-gcc -std=c99 -Wall -O3 -mmcu=atmega128 -D F_CPU=8000000UL -c ledmatrix.c
**					avr-gcc -g -mmcu=atmega128 -o ledmatrix.elf ledmatrix.o
**					avr-objcopy -O ihex ledmatrix.elf ledmatrix.hex 
**					or type 'make'
** Author: 			dkroeske@gmail.com
** -------------------------------------------------------------------------*/


#include <avr/io.h>
#include <util/delay.h>
#include "ledmatrix.h"

/******************************************************************/
void twi_init()
/* 
short:			Init AVR TWI interface and set bitrate
inputs:			
outputs:	
notes:			TWI clock is set to 100 kHz
Version :    	DMK, Initial code
*******************************************************************/
{
	TWSR = 0;
	TWBR = 32;	 // TWI clock set to 100kHz, prescaler = 0
	
	twi_start();
	twi_tx(0xE0);    // Display I2C addres + R/W bit
	twi_tx(0x21);    // Internal osc on (page 10 HT16K33)
	twi_stop();

	twi_start();
	twi_tx(0xE0);    // Display I2C address + R/W bit
	twi_tx(0xA0);    // HT16K33 pins all output
	twi_stop();

	twi_start();
	twi_tx(0xE0);    // Display I2C address + R/W bit
	twi_tx(0xE3);    // Display Dimming 4/16 duty cycle
	twi_stop();

	twi_start();
	twi_tx(0xE0);    // Display I2C address + R/W bit
	twi_tx(0x81);    // Display OFF - Blink On
	twi_stop();
}

/******************************************************************/
void twi_start()
/* 
short:			Generate TWI start condition
inputs:		
outputs:	
notes:			
Version :    	DMK, Initial code
*******************************************************************/
{
	TWCR = (0x80 | 0x20 | 0x04);
	while( 0x00 == (TWCR & 0x80) );
}

/******************************************************************/
void twi_stop()
/* 
short:			Generate TWI stop condition
inputs:		
outputs:	
notes:			
Version :    	DMK, Initial code
*******************************************************************/
{
	TWCR = (0x80 | 0x10 | 0x04);
}

/******************************************************************/
void twi_tx(unsigned char data)
/* 
short:			transmit 8 bits data
inputs:		
outputs:	
notes:			
Version :    	DMK, Initial code
*******************************************************************/
{
	TWDR = data;
	TWCR = (0x80 | 0x04);
	while( 0 == (TWCR & 0x80) );
}

/******************************************************************/
void wait(int ms)
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


/************************************************************************/
/* Write data to the dot matrix                                                                     */
/************************************************************************/
void writeData(int adress, int data){
	twi_start();
	twi_tx(0xE0);    // Display I2C addres + R/W bit
	twi_tx(adress);    // Address
	twi_tx(data);    // data
	twi_stop();
}