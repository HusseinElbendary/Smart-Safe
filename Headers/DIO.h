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
// 						Port Numbers of atmega32
// PortA: 8 pins from leg 40 to leg 33 on the atmega32
// PortB: 8 pins from leg 1 to leg 8 on the atmega32
// PortC: 8 pins from leg 22 to leg 29 on the atmega32
// PortD: 8 pins from leg 14 to leg 21 on the atmega32
//****************************************************************************//

#define DIO_u8PORTA 	0
#define DIO_u8PORTB 	1
#define DIO_u8PORTC 	2
#define DIO_u8PORTD 	3

// Port A Pins

#define DIO_u8PIN0	0
#define DIO_u8PIN1	1
#define DIO_u8PIN2	2
#define DIO_u8PIN3	3
#define DIO_u8PIN4	4
#define DIO_u8PIN5	5
#define DIO_u8PIN6	6
#define DIO_u8PIN7	7

// Port B Pins

#define DIO_u8PIN8	8
#define DIO_u8PIN9	9
#define DIO_u8PIN10	10
#define DIO_u8PIN11	11
#define DIO_u8PIN12	12
#define DIO_u8PIN13	13
#define DIO_u8PIN14	14
#define DIO_u8PIN15	15

// Port C Pins

#define DIO_u8PIN16	16
#define DIO_u8PIN17	17
#define DIO_u8PIN18	18
#define DIO_u8PIN19	19
#define DIO_u8PIN20	20
#define DIO_u8PIN21	21
#define DIO_u8PIN22	22
#define DIO_u8PIN23	23

// Port D Pins

#define DIO_u8PIN24	24
#define DIO_u8PIN25	25
#define DIO_u8PIN26	26
#define DIO_u8PIN27	27
#define DIO_u8PIN28	28
#define DIO_u8PIN29	29
#define DIO_u8PIN30	30
#define DIO_u8PIN31	31


//****************************************************************************//
// 						Modes of Digital input/output pins
// Input: reads digital input, doesn't have internal pull up resistor
// Input pull up: reads digital input with internal pull up resistor
// Output: Writes digital output onto pin
//****************************************************************************//

#define DIO_u8INPUT 		0
#define DIO_u8OUTPUT 		1
#define DIO_u8INPUT_PULLUP 	2


//****************************************************************************//
// 						Digital levels of the pins
// Low: Digital low is 0, usually 0 volt
// High: Digital high is 1, usually 5 volt
//****************************************************************************//

#define DIO_u8LOW 	0
#define DIO_u8HIGH 	1


//****************************************************************************//





/*******************************************************************************
 *																			   *
 * DIO_vidSetPortDirection sets the direction of the whole port.			   *
 * Function input:															   *
 * 																			   *
 * Port: one of the 4 ports of atmega32 									   *
 * 		- DIO_u8PORTA														   *
 * 		- DIO_u8PORTB														   *
 * 		- DIO_u8PORTC														   *
 * 		- DIO_u8PORTD														   *
 * 																			   *
 * PortDirection: one of the 3 Directions								   	   *
 * 		- DIO_u8INPUT														   *
 * 		- DIO_u8INPUT_PULLUP												   *
 * 		- DIO_u8OUTPUT									   					   *
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
 * 		- DIO_u8PORTA														   *
 * 		- DIO_u8PORTB														   *
 * 		- DIO_u8PORTC														   *
 * 		- DIO_u8PORTD														   *
 * 																			   *
 * PortValue: one of the 2 Values  											   *
 * 		- DIO_u8LOW															   *
 * 		- DIO_u8HIGH														   *
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
 * PinNumber: The desired pin to control, one of the 32 pins of the port	   *
 * 		- DIO_u8PIN0														   *
 * 		- DIO_u8PIN1														   *
 * 		- DIO_u8PIN2														   *
 * 		- DIO_u8PIN3														   *
 * 		- DIO_u8PIN4														   *
 * 		- DIO_u8PIN5														   *
 * 		- DIO_u8PIN6														   *
 * 		- DIO_u8PIN7														   *
 * 		- DIO_u8PIN8														   *
 * 		- DIO_u8PIN9														   *
 * 		- DIO_u8PIN10														   *
 * 		- DIO_u8PIN11														   *
 * 		- DIO_u8PIN12														   *
 * 		- DIO_u8PIN13														   *
 * 		- DIO_u8PIN14														   *
 * 		- DIO_u8PIN15														   *
 * 		- DIO_u8PIN16														   *
 * 		- DIO_u8PIN17														   *
 * 		- DIO_u8PIN18														   *
 * 		- DIO_u8PIN19														   *
 * 		- DIO_u8PIN20														   *
 * 		- DIO_u8PIN21														   *
 * 		- DIO_u8PIN22														   *
 * 		- DIO_u8PIN23 														   *
 * 		- DIO_u8PIN24														   *
 * 		- DIO_u8PIN25														   *
 * 		- DIO_u8PIN26														   *
 * 		- DIO_u8PIN27														   *
 * 		- DIO_u8PIN28														   *
 * 		- DIO_u8PIN29														   *
 * 		- DIO_u8PIN30														   *
 * 		- DIO_u8PIN31														   *
 * 																			   *
 * PortDirection: one of the 3 Directions								   	   *
 * 		- DIO_u8INPUT														   *
 * 		- DIO_u8INPUT_PULLUP												   *
 * 		- DIO_u8OUTPUT									   					   *
 * 																			   *
 * The function has not return 												   *
 *	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	   *
 ******************************************************************************/

void DIO_vidSetPinDirection(u8 u8PinNumber, u8 u8PinDirection);





/*******************************************************************************
 *																			   *
 * DIO_vidSetPinValue sets the Value of a particular pin.		   		  	   *
 * Function input:															   *
 * 																			   *
 * PinNumber: The desired pin to control, one of the 32 pins of the port	   *
 * 		- DIO_u8PIN0														   *
 * 		- DIO_u8PIN1														   *
 * 		- DIO_u8PIN2														   *
 * 		- DIO_u8PIN3														   *
 * 		- DIO_u8PIN4														   *
 * 		- DIO_u8PIN5														   *
 * 		- DIO_u8PIN6														   *
 * 		- DIO_u8PIN7														   *
 * 		- DIO_u8PIN8														   *
 * 		- DIO_u8PIN9														   *
 * 		- DIO_u8PIN10														   *
 * 		- DIO_u8PIN11														   *
 * 		- DIO_u8PIN12														   *
 * 		- DIO_u8PIN13														   *
 * 		- DIO_u8PIN14														   *
 * 		- DIO_u8PIN15														   *
 * 		- DIO_u8PIN16														   *
 * 		- DIO_u8PIN17														   *
 * 		- DIO_u8PIN18														   *
 * 		- DIO_u8PIN19														   *
 * 		- DIO_u8PIN20														   *
 * 		- DIO_u8PIN21														   *
 * 		- DIO_u8PIN22														   *
 * 		- DIO_u8PIN23 														   *
 * 		- DIO_u8PIN24														   *
 * 		- DIO_u8PIN25														   *
 * 		- DIO_u8PIN26														   *
 * 		- DIO_u8PIN27														   *
 * 		- DIO_u8PIN28														   *
 * 		- DIO_u8PIN29														   *
 * 		- DIO_u8PIN30														   *
 * 		- DIO_u8PIN31														   *
 * 																			   *
 * PortValue: one of the 2 Values  											   *
 * 		- DIO_u8LOW															   *
 * 		- DIO_u8HIGH														   *
 * 																			   *
 * The function has not return 												   *
 *	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	   *
 ******************************************************************************/

void DIO_vidSetPinValue(u8 u8PinNumber, u8 u8PinValue);





/*******************************************************************************
 *																			   *
 * DIO_u8ReadPinValue reads the value of particular pin			   		  	   *
 * 																			   *
 * Function input:															   *
 * 																			   *
 * PinNumber: The desired pin to read, one of the 32 pins of the port	 	   *
 * 		- DIO_u8PIN0														   *
 * 		- DIO_u8PIN1														   *
 * 		- DIO_u8PIN2														   *
 * 		- DIO_u8PIN3														   *
 * 		- DIO_u8PIN4														   *
 * 		- DIO_u8PIN5														   *
 * 		- DIO_u8PIN6														   *
 * 		- DIO_u8PIN7														   *
 * 		- DIO_u8PIN8														   *
 * 		- DIO_u8PIN9														   *
 * 		- DIO_u8PIN10														   *
 * 		- DIO_u8PIN11														   *
 * 		- DIO_u8PIN12														   *
 * 		- DIO_u8PIN13														   *
 * 		- DIO_u8PIN14														   *
 * 		- DIO_u8PIN15														   *
 * 		- DIO_u8PIN16														   *
 * 		- DIO_u8PIN17														   *
 * 		- DIO_u8PIN18														   *
 * 		- DIO_u8PIN19														   *
 * 		- DIO_u8PIN20														   *
 * 		- DIO_u8PIN21														   *
 * 		- DIO_u8PIN22														   *
 * 		- DIO_u8PIN23 														   *
 * 		- DIO_u8PIN24														   *
 * 		- DIO_u8PIN25														   *
 * 		- DIO_u8PIN26														   *
 * 		- DIO_u8PIN27														   *
 * 		- DIO_u8PIN28														   *
 * 		- DIO_u8PIN29														   *
 * 		- DIO_u8PIN30														   *
 * 		- DIO_u8PIN31														   *
 * 																			   *
 * Function output:															   *
 * 																			   *
 * PinValue: either one of the 2 Values  									   *
 * 		- DIO_u8LOW  or 0													   *
 * 		- DIO_u8HIGH or 1													   *
 *	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	   *
 ******************************************************************************/

u8 DIO_u8ReadPinValue(u8 u8PinNumber);




#endif /* HEADERS_DIO_H_ */
