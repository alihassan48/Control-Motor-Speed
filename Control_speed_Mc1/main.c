/*
 * main.c
 *
 *  Created on: Apr 6, 2016
 *      Author: Ali
 */

#include "lcd.h"
#include "keypad.h"
#include "uart.h"
//problem is the UART driver
#define Plus_speed   '*'
#define Minus_speed  '#'
ISR(USART_RXC_vect)
{
	g_data=UDR;
}

int main(void)
{
	uint8 pressed;
	static uint8 current_speed=0;
	LCD_init();
	LCD_displayString("Motor speed = ");
	LCD_intgerToString(current_speed);
	UART_init();
	while(1)
	{
		pressed=KeyPad_getPressedKey();
		pressed=KeyPad_4x3_adjustKeyNumber(pressed);
		for(int i=0;i<3000;i++){i++;}
		if(pressed == Plus_speed)
		{
			if(current_speed<100)
			{
				current_speed += 10;
			}
			else{}
				//if(g_data == '1')
				//{
					UART_sendByte('+');
				//}
		}
		else if(pressed == Minus_speed)
		{
			if(current_speed==100)
			{
				LCD_goToRowColumn(0,13);
				LCD_displayString("   ");
			}
			if(current_speed>0)
			{
			current_speed -= 10;
			}
			else{}
				//if(g_data=='1')
				//{
					UART_sendByte('-');
				//}
		}
		LCD_goToRowColumn(0,13);
		LCD_displayString("  ");
		LCD_goToRowColumn(0,13);
		LCD_intgerToString(current_speed);
	}
}
