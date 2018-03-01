/*
 * lcd.h
 *
 * Created: 2/22/2018 4:33:32 PM
 *  Author: Ricky
 */ 

void init();
void display_text();
void set_cursor(int position);
void lcd_writeChar(unsigned char dat);