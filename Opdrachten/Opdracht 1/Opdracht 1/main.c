/*
* Opdracht 1.c
*
* Created: 2/1/2018 4:27:29 PM
* Author : Ricky
*/

#define F_CPU 8000000
#include <avr/io.h>
#include <util/delay.h>

int opdrachtB2();
int opdrachtB3();
int opdrachtB4();
int opdrachtB5();
int opdrachtB6();
int opdrachtB7();

void wait(int ms){
	for (int i=0; i<ms; i++)
	{
		_delay_ms( 1 );		// library function (max 30 ms at 8MHz)
	}

}

int main(void)
{
	opdrachtB7();
	return 1;
}


int opdrachtB2(void){
	
	DDRD = 0b11111111;
	/* Replace with your application code */
	while (1)
	{
		PORTD = 0x40;
		wait(500);
		PORTD = 0x20;
		wait(500);
	}
	return 1;
}

int opdrachtB3(void){
	DDRD = 0b11111111;
	
	while(1){
		if (PINC == 1)
		{
			PORTD = 0x20;
			wait(200);
			PORTD = 0;
			wait(200);
		}
		else
		{
			PORTD = 0;
		}
	}
	return 1;
}

int opdrachtB4(void){
	DDRD = 0b11111111;
	
	int idx = 0;
	int lampje = 0b00000001;
	while(idx < 8){
		PORTD = lampje;
		wait(50);
		PORTD = 0;
		lampje = lampje << 1;
		idx++;
	}
	return opdrachtB4();
}

int opdrachtB5(void){
	DDRD = 0b11111111;
	
	int lampje = 0b00000001;
	int idx = 0;
	int array[8];
	int i = 0;
	int bool = 0;
	
	while(idx < 8){
		array[idx] = lampje;
		lampje = lampje << 1;
		idx++;
	}
	
	while(1){
		
		PORTD = array[i] + array[7-i];
		wait(200);
		if(i==7)
		bool = 1;
		if(i==0)
		bool = 0;

		if(bool == 0)
		i++;
		else
		i--;
		
	}
}

int opdrachtB6(void){
	DDRD = 0b11111111;
	int bool = 0;

	while(1){
		while(bool == 0){
			if(PINC == 1){
				wait(1000);
				if(PINC == 1) {

					bool = 1;
				}
			}
			PORTD = 0x40;
			wait(1000);
			PORTD = 0;
			wait(1000);
		}
		
		while(bool == 1){
			if(PINC == 1){
				wait(1000);
				if(PINC == 1) {

					bool = 0;
				}
			}
			PORTD = 0x40;
			wait(250);
			PORTD = 0;
			wait(250);
		}
		
	}
}

int opdrachtB7(void){
	DDRD = 0b11111111;
	
	int state = 0;
	while(1){
		switch (state)
		{
			case 0:
			PORTD = 0;
			PORTD = 0b00000001;
			if(PIND & 64) /*6*/{
				state = 1;
				wait(200);
			}
			if(PIND & 32) /*5*/{
				state = 2;
				wait(200);
			}
			break;

			case 1:
			PORTD = 0;
			PORTD = 0b00000010;
			if(PIND & 128) /*7*/{
				state = 0;
				wait(200);
			}
			if(PIND & 32) /*5*/{
				state = 2;
				wait(200);
			}
			break;

			case 2:
			PORTD = 0;
			PORTD = 0b00000100;
			if(PIND & 64) /*6*/{
				state = 1;
				wait(200);
			}
			if(PIND & 32) /*5*/{
				state = 3;
				wait(200);
			}
			if(PIND & 128) /*7*/{
				state = 0;
				wait(200);
			}
			break;

			case 3:
			PORTD = 0;
			PORTD = 0b00001000;
			if(PIND & 128) /*7*/{
				state = 0;
				wait(200);
			}
			if(PIND & 64) /*6*/{
				state = 4;
				wait(200);
			}
			if(PIND & 32) /*5*/{
				state = 4;
				wait(200);
			}
			break;

			case 4:
			PORTD = 0;
			PORTD = 0b10000000;
			if(PIND & 128) /*7*/{
				state = 0;
				wait(200);
			}
		}
	}
}
