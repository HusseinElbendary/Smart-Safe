/*
 * Keypad.c
 *
 *  Created on: Apr 4, 2023
 *      Author: Hussein
 */

#include "../Headers/Keypad.h"
#include "../Headers/Dio.h"
#include "../Headers/Delay.h"


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

/*
 * Hidden variables to make the code neater
 *
 * Keypad_u8KeypadSymbolsArr is the collection of the symbols on the keypad
 *
 * Keypad_u8KeypadColsArr is the collection of column pins of the keypad,
 * made for easier iteration on the pins
 *
 * Keypad_u8KeypadRowsArr is the collection of Rows pins of the keypad,
 * made for easier iteration on the pins
 */

u8 Keypad_u8KeypadSymbolsArr[]={'1', '2', '3', 'A',
								'4', '5', '6', 'B',
								'7', '8', '9', 'C',
								'*', '0', '#', 'D'};

u8 Keypad_u8KeypadColsArr[]={KEYPAD_u8PIN_C1, KEYPAD_u8PIN_C2,
							 KEYPAD_u8PIN_C3, KEYPAD_u8PIN_C4};

u8 Keypad_u8KeypadRowsArr[]={KEYPAD_u8PIN_R1, KEYPAD_u8PIN_R2,
							 KEYPAD_u8PIN_R3, KEYPAD_u8PIN_R4};


/******************************************************************************/

/*
 * Keypad_vidInit initialize the keypad pins according to the configuration file
 *
 * R1-R4 pins are set to INPUT with PULLUP enabled
 *
 * C1-C4 pins are set to OUTPUT
 *
 */

void Keypad_vidInit()
{

	DIO_vidSetPinDirection(KEYPAD_u8PIN_R1,DIO_u8INPUT_PULLUP);
	DIO_vidSetPinDirection(KEYPAD_u8PIN_R2,DIO_u8INPUT_PULLUP);
	DIO_vidSetPinDirection(KEYPAD_u8PIN_R3,DIO_u8INPUT_PULLUP);
	DIO_vidSetPinDirection(KEYPAD_u8PIN_R4,DIO_u8INPUT_PULLUP);



	DIO_vidSetPinDirection(KEYPAD_u8PIN_C1,DIO_u8OUTPUT);
	DIO_vidSetPinDirection(KEYPAD_u8PIN_C2,DIO_u8OUTPUT);
	DIO_vidSetPinDirection(KEYPAD_u8PIN_C3,DIO_u8OUTPUT);
	DIO_vidSetPinDirection(KEYPAD_u8PIN_C4,DIO_u8OUTPUT);


}

/*
 * Keypad_u8GetPressedKey checks and returns the pressed key on the keypad
 *
 * Function output: either one of the 16 keypad symbols (from the diagram)
 * or returns Null character or 0 if no key is pressed.
 *
 *
 * the function iterate on the columns, bringing each column to logic LOW.
 *
 * with each column, the function reads all rows.
 *
 * if the row reads logic LOW, then the switch at this column and row is pressed
 *
 *
 * note: the function waits 75 milliseconds for debounce when key is pressed.
 *
 *
 */

u8 Keypad_u8GetPressedKey()
{

	//Turn on voltage in the keypad
	DIO_vidSetPinValue(KEYPAD_u8PIN_C1,DIO_u8HIGH);
	DIO_vidSetPinValue(KEYPAD_u8PIN_C2,DIO_u8HIGH);
	DIO_vidSetPinValue(KEYPAD_u8PIN_C3,DIO_u8HIGH);
	DIO_vidSetPinValue(KEYPAD_u8PIN_C4,DIO_u8HIGH);



	for(u8 i=0; i<4; i++)
	{
		//iterate on each column one by one
		DIO_vidSetPinValue(Keypad_u8KeypadColsArr[i],DIO_u8LOW);
		Delay_vidMillis(1);
		for(u8 j=0; j<4; j++)
		{
			//check if the row reads low voltage
			if(DIO_u8ReadPinValue(Keypad_u8KeypadRowsArr[j]) == DIO_u8LOW)
			{


				Delay_vidMillis(75); //wait for 75 ms

				if(DIO_u8ReadPinValue(Keypad_u8KeypadRowsArr[j]) == DIO_u8LOW)
				{
					//turn the power off from the keypad
					DIO_vidSetPinValue(KEYPAD_u8PIN_C1,DIO_u8LOW);
					DIO_vidSetPinValue(KEYPAD_u8PIN_C2,DIO_u8LOW);
					DIO_vidSetPinValue(KEYPAD_u8PIN_C3,DIO_u8LOW);
					DIO_vidSetPinValue(KEYPAD_u8PIN_C4,DIO_u8LOW);

					//return the corresponding symbol
					return Keypad_u8KeypadSymbolsArr[i*4 +j];
				}


			}


		}

		DIO_vidSetPinValue(Keypad_u8KeypadColsArr[i],DIO_u8HIGH);
	}
	//turn the power off from the keypad
	DIO_vidSetPinValue(KEYPAD_u8PIN_C1,DIO_u8LOW);
	DIO_vidSetPinValue(KEYPAD_u8PIN_C2,DIO_u8LOW);
	DIO_vidSetPinValue(KEYPAD_u8PIN_C3,DIO_u8LOW);
	DIO_vidSetPinValue(KEYPAD_u8PIN_C4,DIO_u8LOW);

	//return null
	return KEYPAD_u8NONE;
}
