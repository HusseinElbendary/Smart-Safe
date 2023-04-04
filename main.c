/*
 * main.c
 *
 *  Created on: Apr 4, 2023
 *      Author: Hussein
 */

#include "Headers/DIO.h"

int main(void)
{
	DIO_vidSetPortDirection(DIO_PORTA,DIO_INPUT);
	return 0;
}

