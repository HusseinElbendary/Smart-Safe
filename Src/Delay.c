/*
 * Delay.c
 *
 *  Created on: Apr 5, 2023
 *      Author: Hussein
 */
#include "../Headers/Delay.h"
#include "../Private/Delay_PRIV.h"


void Delay_vidMillis(u32 u32Delay)
{
	while(u32Delay!=0)
	{
		TCNT0 = 131; //125 tick
		TCCR0 = 0b00000011; //64 prescalar
		while(!GetBit(TIFR,TOV0)); //wait for overflow
		TCCR0 = 0; //reset the counter
		SetBit(TIFR,TOV0); //reset the flag
		u32Delay--;
	}
}

void Delay_vidMicros(u32 u32Delay)
{
	while(u32Delay!=0)
	{
		TCNT0 = 248; //8 ticks
		TCCR0 = 0b00000001; //no prescalar
		while(!GetBit(TIFR,TOV0)); //wait for overflow
		TCCR0 = 0; //reset the counter
		SetBit(TIFR,TOV0); //reset the flag
		u32Delay--;
	}
}
