/*
 * Keypad.h
 *
 *  Created on: Apr 4, 2023
 *      Author: Hussein
 */

#ifndef KEYPAD_H_
#define KEYPAD_H_

#include "BitMath.h"
#include "StdTypes.h"
#include "DIO.h"

#include "../Config/Keypad_cfg.h"

/*******************************************************************************

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

*******************************************************************************/

#define KEYPAD_u8NONE 	0 //No Key is pressed, Null key

/******************************************************************************/

/*
 * Keypad_vidInit initialize the keypad pins according to the configuration file
 *
 * R1-R4 are Inputs with pull-up enabled
 *
 * C1-C4 are Outputs
 *
 */
void Keypad_vidInit();

/*
 * Keypad_u8GetPressedKey returns the pressed key on the keypad.
 *
 * if no key is pressed, the function returns KEYPAD_u8NONE
 *
 * KEYPAD_u8NONE is a Null character
 */

u8 Keypad_u8GetPressedKey();

#endif /* KEYPAD_H_ */
