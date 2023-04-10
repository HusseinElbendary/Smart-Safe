/*
 * LCD.c
 *
 *  Created on: Apr 10, 2023
 *      Author: Hussein
 */
#include "../Headers/StdTypes.h"
#include "../Headers/DIO.h"
#include "../Headers/Delay.h"


#include "../Headers/LCD.h"




/******************************************************************************
 * LCD_vidInit initialize the LCD.
 * LCD is initialized to 4 bit mode, 2 line, 5x7 matrix.
 * LCD is initialized to Display on with cursor blinking going to the right.
 *
 * finally LCD is set at cursor location 0,0
 *
 ******************************************************************************/
void LCD_vidInit(void)
{
	DIO_vidSetPinDirection(LCD_u8D4_PIN,DIO_u8OUTPUT);
	DIO_vidSetPinDirection(LCD_u8D5_PIN,DIO_u8OUTPUT);
	DIO_vidSetPinDirection(LCD_u8D6_PIN,DIO_u8OUTPUT);
	DIO_vidSetPinDirection(LCD_u8D7_PIN,DIO_u8OUTPUT);

	DIO_vidSetPinDirection(LCD_u8RS_PIN,DIO_u8OUTPUT);
	DIO_vidSetPinDirection(LCD_u8RW_PIN,DIO_u8OUTPUT);
	DIO_vidSetPinDirection(LCD_u8EN_PIN,DIO_u8OUTPUT);

	DIO_vidSetPinValue(LCD_u8RW_PIN,DIO_u8LOW);

	Delay_vidMillis(20);		/* LCD Power ON delay always >15ms */

	LCD_vidSendCommand(0x33);
	LCD_vidSendCommand(0x32);	/* Send for 4 bit initialization of LCD  */
	LCD_vidSendCommand(0x28);	/* 2 line, 5*7 matrix in 4-bit mode */
	LCD_vidSendCommand(0x0E);	/* Display on cursor Blinking */
	LCD_vidSendCommand(0x06);	/* Increment cursor (shift cursor to right) */
	LCD_vidSendCommand(0x01);	/* Clear display screen */
	LCD_vidGoTo(0,0);
}

/******************************************************************************
 * LCD_vidSendCommand sends one command to the LCD
 * @param u8CMD
 *
 * note: this function can not be used to send characters to the LCD
 *
 * the function send the command onto 2 nibbles starting with the higher one.
 *
 * the function writes the command on the 4 data lines then send a HIGH pulse
 * for 1 micro-second. RS pin must be LOW
 *
 ******************************************************************************/

void LCD_vidSendCommand(u8 u8CMD)
{

	DIO_vidSetPinValue(LCD_u8D7_PIN,GetBit(u8CMD,7));
	DIO_vidSetPinValue(LCD_u8D6_PIN,GetBit(u8CMD,6));
	DIO_vidSetPinValue(LCD_u8D5_PIN,GetBit(u8CMD,5));
	DIO_vidSetPinValue(LCD_u8D4_PIN,GetBit(u8CMD,4));/* Sending higher nibble */

	DIO_vidSetPinValue(LCD_u8RS_PIN,DIO_u8LOW); /* RS=0, command reg. */

	DIO_vidSetPinValue(LCD_u8EN_PIN,DIO_u8HIGH); /* Enable pulse */

	Delay_vidMicros(1);
	DIO_vidSetPinValue(LCD_u8EN_PIN,DIO_u8LOW);
	Delay_vidMicros(200);

	DIO_vidSetPinValue(LCD_u8D7_PIN,GetBit(u8CMD,3));
	DIO_vidSetPinValue(LCD_u8D6_PIN,GetBit(u8CMD,2));
	DIO_vidSetPinValue(LCD_u8D5_PIN,GetBit(u8CMD,1));
	DIO_vidSetPinValue(LCD_u8D4_PIN,GetBit(u8CMD,0));/* Sending lower nibble */

	DIO_vidSetPinValue(LCD_u8RS_PIN,DIO_u8LOW); /* RS=0, command reg. */

	DIO_vidSetPinValue(LCD_u8EN_PIN,DIO_u8HIGH); /* Enable pulse */

	Delay_vidMicros(1);
	DIO_vidSetPinValue(LCD_u8EN_PIN,DIO_u8LOW);

	Delay_vidMillis(2);


}

/******************************************************************************
 * LCD_vidWriteCharacter sends one command to the LCD
 * @param u8Chara
 *
 * note: this function can not be used to send commands to the LCD
 *
 * the function send the character onto 2 nibbles starting with the higher one.
 *
 * the function writes the character on the 4 data lines then send a HIGH pulse
 * for 1 micro-second. RS pin must be HIGH
 *
 ******************************************************************************/

void LCD_vidWriteCharacter(u8 u8Chara)
{
	DIO_vidSetPinValue(LCD_u8D7_PIN,GetBit(u8Chara,7));
	DIO_vidSetPinValue(LCD_u8D6_PIN,GetBit(u8Chara,6));
	DIO_vidSetPinValue(LCD_u8D5_PIN,GetBit(u8Chara,5));
	DIO_vidSetPinValue(LCD_u8D4_PIN,GetBit(u8Chara,4));/* Sending higher nibble */

	DIO_vidSetPinValue(LCD_u8RS_PIN,DIO_u8HIGH); /* RS=1, command reg. */

	DIO_vidSetPinValue(LCD_u8EN_PIN,DIO_u8HIGH); /* Enable pulse */

	Delay_vidMicros(1);
	DIO_vidSetPinValue(LCD_u8EN_PIN,DIO_u8LOW);
	Delay_vidMicros(200);

	DIO_vidSetPinValue(LCD_u8D7_PIN,GetBit(u8Chara,3));
	DIO_vidSetPinValue(LCD_u8D6_PIN,GetBit(u8Chara,2));
	DIO_vidSetPinValue(LCD_u8D5_PIN,GetBit(u8Chara,1));
	DIO_vidSetPinValue(LCD_u8D4_PIN,GetBit(u8Chara,0));/* Sending lower nibble */


	DIO_vidSetPinValue(LCD_u8EN_PIN,DIO_u8HIGH); /* Enable pulse */

	Delay_vidMicros(1);
	DIO_vidSetPinValue(LCD_u8EN_PIN,DIO_u8LOW);

	Delay_vidMillis(2);
}

/******************************************************************************
 * LCD_vidSendString Writes a string to the LCD
 * @param u8CharaArray
 *
 * Note: The argument must be casted into u8 pointer.
 * Usage Example: LCD_vidWriteString( (u8*) "hello world");
 *
 ******************************************************************************/

void LCD_vidWriteString(u8* u8CharaArray)
{
	u8 i=0;
	while(u8CharaArray[i]!='\0')
	{
		LCD_vidWriteCharacter(u8CharaArray[i]);
		i++;
	}

}

/******************************************************************************
 * LCD_vidGoTo moves the LCD cursor to location (x,y).
 * @param u8LocX
 * @param u8LocY
 *
 * u8LocX is the horizontal axis/ column number, ranges from 0 to 15.
 *
 * u8LocY is the vertical axis/ row number, ranges from 0 to 1.
 *
 ******************************************************************************/

void LCD_vidGoTo(u8 u8LocX, u8 u8LocY)
{
	if (u8LocY == 0 && u8LocX<16)
		LCD_vidSendCommand((u8LocX & 0x0F)|0x80);	/* Command of first row and required position<16 */
	else if (u8LocY == 1 && u8LocX<16)
		LCD_vidSendCommand((u8LocX & 0x0F)|0xC0);	/* Command of first row and required position<16 */
}

/******************************************************************************
 * LCD_vidClearDisplay clears the display of the LCD
 * 							and returns the cursor to home position (0,0).
 *
 ******************************************************************************/

void LCD_vidClearDisplay(void)
{
	LCD_vidSendCommand (0x01);		/* Clear display */
	Delay_vidMillis(2);
	LCD_vidGoTo(0,0);		/* Cursor at home position */
}
