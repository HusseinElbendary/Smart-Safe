/*
 * Keypad_cfg.h
 *
 *  Created on: Apr 4, 2023
 *      Author: Hussein
 */

#ifndef CONFIG_KEYPAD_CFG_H_
#define CONFIG_KEYPAD_CFG_H_

#include "../Headers/DIO.h"

/*
 * configuration file of the keypad:
 *
 * R1-R4 are input pins
 *
 * C1-C4 are output pins
 *
 *******************************************************************************

			+-----------------------------------------------------+
			|                                                     |
			|   +-----+      +-----+       +-----+      +-----+   |
			|   |  1  |      |  2  |       |  3  |      |  A  |   |
			|   |     |      |     |       |     |      |     |   |
			|   +-----+      +-----+       +-----+      +-----+   |
			|                                                     |
			|                                                     |
			|   +-----+      +-----+       +-----+      +-----+   |
			|   |  4  |      |  5  |       |  6  |      |  B  |   |
			|   |     |      |     |       |     |      |     |   |
			|   +-----+      +-----+       +-----+      +-----+   |
			|                                                     |
			|                                                     |
			|   +-----+      +-----+       +-----+      +-----+   |
			|   |  7  |      |  8  |       |  9  |      |  C  |   |
			|   |     |      |     |       |     |      |     |   |
			|   +-----+      +-----+       +-----+      +-----+   |
			|                                                     |
			|                                                     |
			|   +-----+      +-----+       +-----+      +-----+   |
			|   |  *  |      |  0  |       |  #  |      |  D  |   |
			|   |     |      |     |       |     |      |     |   |
			|   +-----+      +-----+       +-----+      +-----+   |
			|                                                     |
			|                                                     |
			+-----------------------------------------------------+
							 |  |  |  |  |  |  |  |
							 |  |  |  |  |  |  |  |
							 |  |  |  |  |  |  |  |
							 |  |  |  |  |  |  |  |
							 |  |  |  |  |  |  |  |
							 |  |  |  |  |  |  |  |
							 |  |  |  |  |  |  |  |
							 |  |  |  |  |  |  |  |
							 |  |  |  |  |  |  |  |
							 |  |  |  |  |  |  |  |
							 |  |  |  |  |  |  |  |
							 |  |  |  |  |  |  |  |
							 |  |  |  |  |  |  |  |
							 |  |  |  |  |  |  |  |
							 v  v  v  v  v  v  v  v
							 R1 R2 R3 R4 C1 C2 C3 C4

 *******************************************************************************
 *
 *
 */


#define KEYPAD_u8PIN_R1	DIO_u8PIN0
#define KEYPAD_u8PIN_R2	DIO_u8PIN1
#define KEYPAD_u8PIN_R3	DIO_u8PIN2
#define KEYPAD_u8PIN_R4	DIO_u8PIN3

#define KEYPAD_u8PIN_C1 DIO_u8PIN4
#define KEYPAD_u8PIN_C2 DIO_u8PIN5
#define KEYPAD_u8PIN_C3 DIO_u8PIN6
#define KEYPAD_u8PIN_C4 DIO_u8PIN7

#endif /* CONFIG_KEYPAD_CFG_H_ */
