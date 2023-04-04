/*
 * BitMath.h
 *
 *  Created on: Apr 4, 2023
 *      Author: Hussein
 */

#ifndef HEADERS_BITMATH_H_
#define HEADERS_BITMATH_H_



/*******************************************************************************
																			   *
 * SetBit turns bit to 1 in a register. 									   *
																			   *
 * note: bits are 0 indexed													   *
																			   *
 * Example: SetBit(0b00110001,3) will result in 0b00111001					   *
 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	   *
 ******************************************************************************/

#define SetBit(reg,bit) 	( reg = reg | ( 1 << bit ))



/*******************************************************************************
																			   *
 * ClearBit turns bit to 0 in a register. 									   *
																			   *
 * note: bits are 0 indexed													   *
																			   *
 * Example: ClearBit(0b00110001,0) will result in 0b00110000				   *
 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	   *
 ******************************************************************************/

#define ClearBit(reg,bit) 	( reg= reg & ~ ( 1 << bit ))



/*******************************************************************************
																			   *
 * ToggleBit turns bit from 0 to 1 or from 1 to 0 in a register. 			   *
																			   *
 * note: bits are 0 indexed													   *
																			   *
 * Example: ToggleBit(0b00110001,3) will result in 0b00111001				   *
 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	   *
 * Example: ToggleBit(0b00110001,4) will result in 0b00100001 	 	 	 	   *
 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	   *
 ******************************************************************************/

#define ToggleBit(reg,bit) 	( reg = reg ^ ( 1 << bit ))

#define GetBit(reg,bit) 	( ( reg & (1 << bit) ) >> bit)

#endif /* HEADERS_BITMATH_H_ */
