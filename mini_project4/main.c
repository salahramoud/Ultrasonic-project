/*
 * main.c
 *
 *  Created on: ١٥‏/١٠‏/٢٠٢٢
 *      Author: salah ramoud
 */
#include "lcd.h"
#include "ultrasonic.h"
#include <avr/io.h>




int main(void)
{
	uint32 distance=0;
	/* Enable Global Interrupt I-Bit */
	SREG |= (1<<7);

	/* Initialize the LCD driver */
	LCD_init();

	/* Initialize the Ultrasonic driver */
	Ultrasonic_init();

	LCD_displayString("distance= ");
	LCD_moveCursor(0,13);
	LCD_displayString(" cm");

	LCD_moveCursor(0,10);





while(1)
{
	distance=Ultrasonic_readDistance();
		LCD_intgerToString(distance+2);
		LCD_moveCursor(0,10);



}
}

