/*
 * DIO.h
 *
 *  Created on: Apr 4, 2023
 *      Author: Hussein
 */

#ifndef HEADERS_DIO_H_
#define HEADERS_DIO_H_

#include "BitMath.h"
#include "StdTypes.h"



//****************************************************************************//
// 						Modes of Digital input/output pins
// Input: reads digital input, doesn't have internal pull up resistor
// Input pull up: reads digital input with internal pull up resistor
// Output: Writes digital output onto pin
//****************************************************************************//

#define DIO_INPUT 	0
#define DIO_OUTPUT 	1
#define DIO_INPUT_PULLUP 2



//****************************************************************************//
// 						Digital levels of the pins
// Low: Digital low is 0, usually 0 volt
// High: Digital high is 1, usually 5 volt
//****************************************************************************//

#define DIO_LOW 	0
#define DIO_HIGH 	1

//****************************************************************************//
// 						Port Numbers of atmega32
// PortA: 8 pins from leg 40 to leg 33 on the atmega32
// PortB: 8 pins from leg 1 to leg 8 on the atmega32
// PortC: 8 pins from leg 22 to leg 29 on the atmega32
// PortD: 8 pins from leg 14 to leg 21 on the atmega32
//****************************************************************************//

#define DIO_PORTA 	0
#define DIO_PORTB 	1
#define DIO_PORTC 	2
#define DIO_PORTD 	3

#define DIO_PIN0	0
#define DIO_PIN1	1
#define DIO_PIN2	2
#define DIO_PIN3	3
#define DIO_PIN4	4
#define DIO_PIN5	5
#define DIO_PIN6	6
#define DIO_PIN7	7


//****************************************************************************//





/*******************************************************************************
 *																			   *
 * DIO_vidSetPortDirection sets the direction of the whole port.			   *
 * Function input:															   *
 * 																			   *
 * Port: one of the 4 ports of atmega32 									   *
 * 		- DIO_PORTA															   *
 * 		- DIO_PORTB															   *
 * 		- DIO_PORTC															   *
 * 		- DIO_PORTD															   *
 * 																			   *
 * PortDirection: one of the 3 Directions								   	   *
 * 		- DIO_INPUT															   *
 * 		- DIO_INPUT_PULLUP													   *
 * 		- DIO_OUTPUT									   					   *
 * 																			   *
 * The function has not return 												   *
 *	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	   *
 ******************************************************************************/

void DIO_vidSetPortDirection(u8 u8Port, u8 u8PortDirection);





/*******************************************************************************
 *																			   *
 * DIO_vidSetPortValue sets the Value of the whole port.			   		   *
 * Function input:															   *
 * 																			   *
 * Port: one of the 4 ports of atmega32 									   *
 * 		- DIO_PORTA															   *
 * 		- DIO_PORTB															   *
 * 		- DIO_PORTC															   *
 * 		- DIO_PORTD															   *
 * 																			   *
 * PortValue: one of the 2 Values  											   *
 * 		- DIO_LOW															   *
 * 		- DIO_HIGH															   *
 * 																			   *
 * The function has not return 												   *
 *	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	   *
 ******************************************************************************/

void DIO_vidSetPortValue(u8 u8Port, u8 u8PortValue);





/*******************************************************************************
 *																			   *
 * DIO_vidSetPinDirection sets the direction of a particular pin.			   *
 * Function input:															   *
 * 																			   *
 * Port: one of the 4 ports of atmega32 									   *
 * 		- DIO_PORTA															   *
 * 		- DIO_PORTB															   *
 * 		- DIO_PORTC															   *
 * 		- DIO_PORTD															   *
 * 																			   *
 * PinNumber: The desired pin to control, one of the 8 pins of the port		   *
 * 		- DIO_PIN0															   *
 * 		- DIO_PIN1															   *
 * 		- DIO_PIN2															   *
 * 		- DIO_PIN3															   *
 * 		- DIO_PIN4															   *
 * 		- DIO_PIN5															   *
 * 		- DIO_PIN6															   *
 * 		- DIO_PIN7															   *
 * 																			   *
 * PortDirection: one of the 3 Directions								   	   *
 * 		- DIO_INPUT															   *
 * 		- DIO_INPUT_PULLUP													   *
 * 		- DIO_OUTPUT									   					   *
 * 																			   *
 * The function has not return 												   *
 *	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	   *
 ******************************************************************************/

void DIO_vidSetPinDirection(u8 u8Port, u8 u8PinNumber, u8 u8PinDirection);





/*******************************************************************************
 *																			   *
 * DIO_vidSetPinValue sets the Value of a particular pin.		   		  	   *
 * Function input:															   *
 * 																			   *
 * Port: one of the 4 ports of atmega32 									   *
 * 		- DIO_PORTA															   *
 * 		- DIO_PORTB															   *
 * 		- DIO_PORTC															   *
 * 		- DIO_PORTD															   *
 * 																			   *
 * PinNumber: The desired pin to control, one of the 8 pins of the port		   *
 * 		- DIO_PIN0															   *
 * 		- DIO_PIN1															   *
 * 		- DIO_PIN2															   *
 * 		- DIO_PIN3															   *
 * 		- DIO_PIN4															   *
 * 		- DIO_PIN5															   *
 * 		- DIO_PIN6															   *
 * 		- DIO_PIN7															   *
 * 																			   *
 * PortValue: one of the 2 Values  											   *
 * 		- DIO_LOW															   *
 * 		- DIO_HIGH															   *
 * 																			   *
 * The function has not return 												   *
 *	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	   *
 ******************************************************************************/

void DIO_vidSetPinValue(u8 u8Port, u8 u8PinNumber, u8 u8PinValue);





/*******************************************************************************
 *																			   *
 * DIO_u8ReadPinValue reads the value of particular pin			   		  	   *
 * 																			   *
 * Function input:															   *
 * 																			   *
 * Port: one of the 4 ports of atmega32 									   *
 * 		- DIO_PORTA															   *
 * 		- DIO_PORTB															   *
 * 		- DIO_PORTC															   *
 * 		- DIO_PORTD															   *
 * 																			   *
 * PinNumber: The desired pin to control, one of the 8 pins of the port		   *
 * 		- DIO_PIN0															   *
 * 		- DIO_PIN1															   *
 * 		- DIO_PIN2															   *
 * 		- DIO_PIN3															   *
 * 		- DIO_PIN4															   *
 * 		- DIO_PIN5															   *
 * 		- DIO_PIN6															   *
 * 		- DIO_PIN7															   *
 * 																			   *
 * Function output:															   *
 * 																			   *
 * PinValue: either one of the 2 Values  									   *
 * 		- DIO_LOW or 0														   *
 * 		- DIO_HIGH or 1														   *
 *	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	   *
 ******************************************************************************/

u8 DIO_u8ReadPinValue(u8 u8Port, u8 u8PinNumber);




#endif /* HEADERS_DIO_H_ */
