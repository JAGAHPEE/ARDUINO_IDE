/*
 * blink.c
 *
 * Created: 18-12-2022 12:37:05
 * Author : kales
 */ 
#define F_CPU 12000000UL 
#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
	DDRD = 0xFF;
    /* Replace with your application code */
    while (1) 
    {
		PORTD=0xFF;
		 _delay_ms(100);
		PORTD=0x00;
		 _delay_ms(100);
    }
}