/*
 * main.c
 *
 *  Created on: Apr 6, 2016
 *      Author: Ali
 */

#include "uart.h"
ISR(USART_RXC_vect)
{
	g_data=UDR;
}

void PWM_Init(volatile uint8 duty_cycle)
{
	DDRB |= (1<<3);
	TCCR0 |= (1<<WGM00)|(1<<WGM01)|(1<<CS01)|(1<<COM01);
	OCR0 = duty_cycle;
}
void Set_MotorSpeed(volatile uint8 speed)
{

	PWM_Init(speed);
}

int main(void)
{
	//uint8 pressed=0;
	uint8 current_speed=0;
	//uint16 i=0;
	PWM_Init(0);
	UART_init();
	for(int i=0;i<10000;i++)
		i++;
	UART_sendByte('1');

	while(1)
	{
		//pressed=UART_recieveByte();
		/*Apply speed on the Motor*/
		if(g_data=='+')
		{
			if(current_speed<245)
				current_speed += 5;
			g_data =0;
		}
		else if(g_data == '-')
		{
			if(current_speed>10)
				current_speed -= 5;
			g_data=0;
		}
		Set_MotorSpeed(current_speed);
	}
}
