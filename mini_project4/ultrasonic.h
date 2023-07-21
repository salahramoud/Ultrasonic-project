/*
 * ultrasonic.h
 *
 *  Created on: ١٥‏/١٠‏/٢٠٢٢
 *      Author: salah ramoud
 */

#ifndef ULTRASONIC_H_
#define ULTRASONIC_H_

#include "gpio.h"
#include "std_types.h"

/*******************************************************************************
 *                              Functions Prototypes                           *
 *******************************************************************************/


/* function to intialize ultrasonic */
void Ultrasonic_init(void);



/*function to Send the Trigger pulse to the ultrasonic */
void Ultrasonic_Trigger(void);



/*Function calculates the distance measured by the Ultrasonic sensor */
uint16 Ultrasonic_readDistance(void);


/*call back function */
void Ultrasonic_edgeProcessing(void);


#endif /* ULTRASONIC_H_ */
