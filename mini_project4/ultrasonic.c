/*
 * ultrasonic.c
 *
 *  Created on: ١٥‏/١٠‏/٢٠٢٢
 *      Author: salah ramoud
 */

#include "ultrasonic.h"
#include  "icu.h"
#include <util/delay.h>
#include <avr/io.h>


static uint8 g_edgeCount = 0;
static uint16 g_timeHigh = 0;
static uint8 g_distance = 0;


void Ultrasonic_init()
{
	/* Create configuration structure for ICU driver */
	Icu_ConfigType Icu_Config ={F_CPU_8,RISING};

	Icu_init(&Icu_Config);

	/* Set the Call back function pointer in the ICU driver */
	Icu_setCallBack(Ultrasonic_edgeProcessing);

	/* Configure the Trigger pin as output */
	GPIO_setupPinDirection(PORTB_ID,PIN5_ID,PIN_OUTPUT);


}


void Ultrasonic_Trigger(void)
{
	/* Send the Trigger pulse */
	GPIO_writePin(PORTB_ID,PIN5_ID,LOGIC_HIGH);
	_delay_us(10);
	GPIO_writePin(PORTB_ID,PIN5_ID,LOGIC_LOW);
}

uint16 Ultrasonic_readDistance(void)
{
	/* Clear all variables as they may have values from previous read operation */
	g_distance = 0;
	g_edgeCount = 0;
	g_timeHigh = 0;
	Icu_clearTimerValue();
	Ultrasonic_Trigger();
	while(g_edgeCount != 2);
	g_distance=(float)g_timeHigh/58.8;
	return g_distance;



}

/*
 * Description :
 * Call-Back Function used to calculate g_timeHigh for the Ultrasonic pulse
 */
void Ultrasonic_edgeProcessing(void)
{
	g_edgeCount++;
	if(g_edgeCount==1)
	{
		Icu_clearTimerValue();
	    Icu_setEdgeDetectionType(FALLING);
	}
	else if(g_edgeCount==2)
	{
		g_timeHigh= Icu_getInputCaptureValue();
		Icu_setEdgeDetectionType(RISING);
	}



}



