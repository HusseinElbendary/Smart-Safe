/*
 * LCD.h
 *
 *  Created on: Apr 10, 2023
 *      Author: Hussein
 */

#ifndef HEADERS_LCD_H_
#define HEADERS_LCD_H_

#include "../Config/LCD_cfg.h"



void LCD_vidInit(void);
void LCD_vidSendCommand(u8 u8CMD);
void LCD_vidWriteCharacter(u8 u8Chara);
void LCD_vidWriteString(u8* u8CharaArray);
void LCD_vidGoTo(u8 u8LocX, u8 u8LocY);
void LCD_vidClearDisplay(void);


#endif /* HEADERS_LCD_H_ */
