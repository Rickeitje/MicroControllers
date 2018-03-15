/*
 * lcd.h
 *
 * Created: 2/22/2018 4:33:32 PM
 *  Author: Ricky
 */ 

void init();
void display_text();
void lcd_command ( unsigned char dat );
void set_cursor(int position);
void clearDisplay();
void lcd_writeChar(unsigned char dat);