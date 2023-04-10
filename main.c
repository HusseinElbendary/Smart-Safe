/*
 * main.c
 *
 *  Created on: Apr 4, 2023
 *      Author: Hussein
 */

#include "Headers/DIO.h"
#include "Headers/Keypad.h"
#include "Headers/Delay.h"
#include "Headers/LCD.h"

int main(void)
{
	Keypad_vidInit();
	LCD_vidInit();
	DIO_vidSetPinDirection(DIO_u8PIN8,DIO_u8OUTPUT);
	DIO_vidSetPinDirection(DIO_u8PIN9,DIO_u8OUTPUT);
	DIO_vidSetPinValue(DIO_u8PIN9,DIO_u8HIGH);
	LCD_vidWriteString((u8*)"hi!");
	LCD_vidGoTo(6,1);
	while(1)
	{

		if(Keypad_u8GetPressedKey()=='5')
		{
			DIO_vidSetPinValue(DIO_u8PIN8,DIO_u8LOW);
			LCD_vidClearDisplay();
			LCD_vidWriteString((u8*)"hi!");
			LCD_vidGoTo(6,1);
		}
		else if(Keypad_u8GetPressedKey()=='0')
		{
			DIO_vidSetPinValue(DIO_u8PIN8,DIO_u8HIGH);
			LCD_vidWriteString((u8*)"DONE!");
		}

	}


	return 0;
}

