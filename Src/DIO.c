/*
 * DIO.c
 *
 *  Created on: Apr 4, 2023
 *      Author: Hussein
 */

#include "../Headers/DIO.h"
#include "../Private/DIO_PRIV.h"


void DIO_vidSetPortDirection(u8 u8Port, u8 u8PortDirection)
{

	switch(u8Port)
	{
	case DIO_PORTA:
		if(u8PortDirection == DIO_INPUT)
		{
			DDRA  = 0x00;
			PORTA = 0x00;
		}
		else if(u8PortDirection == DIO_INPUT_PULLUP)
		{
			DDRA = 0x00;
			PORTA = 0xff;
		}
		else if(u8PortDirection == DIO_OUTPUT)
		{
			DDRA = 0xff;
			PORTA = 0x00;
		}
		break;
	case DIO_PORTB:
		if(u8PortDirection == DIO_INPUT)
		{
			DDRB  = 0x00;
			PORTB = 0x00;
		}
		else if(u8PortDirection == DIO_INPUT_PULLUP)
		{
			DDRB = 0x00;
			PORTB = 0xff;
		}
		else if(u8PortDirection == DIO_OUTPUT)
		{
			DDRB = 0xff;
			PORTB = 0x00;
		}
		break;
	case DIO_PORTC:
		if(u8PortDirection == DIO_INPUT)
		{
			DDRC  = 0x00;
			PORTC = 0x00;
		}
		else if(u8PortDirection == DIO_INPUT_PULLUP)
		{
			DDRC = 0x00;
			PORTC = 0xff;
		}
		else if(u8PortDirection == DIO_OUTPUT)
		{
			DDRC = 0xff;
			PORTC = 0x00;
		}
		break;
	case DIO_PORTD:
		if(u8PortDirection == DIO_INPUT)
		{
			DDRD  = 0x00;
			PORTD = 0x00;
		}
		else if(u8PortDirection == DIO_INPUT_PULLUP)
		{
			DDRD = 0x00;
			PORTD = 0xff;
		}
		else if(u8PortDirection == DIO_OUTPUT)
		{
			DDRD = 0xff;
			PORTD = 0x00;
		}
		break;
	default:


	}

}

void DIO_vidSetPortValue(u8 u8Port, u8 u8PortValue)
{
	switch(u8Port)
		{
		case DIO_PORTA:
			if(u8PortValue == DIO_HIGH)
			{
				PORTA = 0xff;
			}
			else if(u8PortValue == DIO_LOW)
			{
				PORTA = 0x00;
			}
			break;

		case DIO_PORTB:
			if(u8PortValue == DIO_HIGH)
			{
				PORTB = 0xff;
			}
			else if(u8PortValue == DIO_LOW)
			{
				PORTB = 0x00;
			}
			break;

		case DIO_PORTC:
			if(u8PortValue == DIO_HIGH)
			{
				PORTC = 0xff;
			}
			else if(u8PortValue == DIO_LOW)
			{
				PORTC = 0x00;
			}
			break;

		case DIO_PORTD:
			if(u8PortValue == DIO_HIGH)
			{
				PORTD = 0xff;
			}
			else if(u8PortValue == DIO_LOW)
			{
				PORTD = 0x00;
			}

			break;
		default:

		}

}

void DIO_vidSetPinDirection(u8 u8Port, u8 u8PinNumber, u8 u8PinDirection)
{

	switch(u8Port)
	{
	case DIO_PORTA:
		if(u8PinDirection == DIO_INPUT)
		{
			ClearBit(DDRA,u8PinNumber);
			ClearBit(PORTA,u8PinNumber);
		}
		else if(u8PinDirection == DIO_INPUT_PULLUP)
		{
			ClearBit(DDRA,u8PinNumber);
			SetBit(PORTA,u8PinNumber);
		}
		else if(u8PinDirection == DIO_OUTPUT)
		{
			SetBit(DDRA,u8PinNumber);
			ClearBit(PORTA,u8PinNumber);
		}
		break;
	case DIO_PORTB:
		if(u8PinDirection == DIO_INPUT)
		{
			ClearBit(DDRB,u8PinNumber);
			ClearBit(PORTB,u8PinNumber);
		}
		else if(u8PinDirection == DIO_INPUT_PULLUP)
		{
			ClearBit(DDRD,u8PinNumber);
			SetBit(PORTD,u8PinNumber);
		}
		else if(u8PinDirection == DIO_OUTPUT)
		{
			SetBit(DDRB,u8PinNumber);
			ClearBit(PORTB,u8PinNumber);
		}
		break;
	case DIO_PORTC:
		if(u8PinDirection == DIO_INPUT)
		{
			ClearBit(DDRC,u8PinNumber);
			ClearBit(PORTC,u8PinNumber);
		}
		else if(u8PinDirection == DIO_INPUT_PULLUP)
		{
			ClearBit(DDRC,u8PinNumber);
			SetBit(PORTC,u8PinNumber);
		}
		else if(u8PinDirection == DIO_OUTPUT)
		{
			SetBit(DDRC,u8PinNumber);
			ClearBit(PORTC,u8PinNumber);
		}
		break;
	case DIO_PORTD:
		if(u8PinDirection == DIO_INPUT)
		{
			ClearBit(DDRD,u8PinNumber);
			ClearBit(PORTD,u8PinNumber);
		}
		else if(u8PinDirection == DIO_INPUT_PULLUP)
		{
			ClearBit(DDRD,u8PinNumber);
			SetBit(PORTD,u8PinNumber);
		}
		else if(u8PinDirection == DIO_OUTPUT)
		{
			SetBit(DDRD,u8PinNumber);
			ClearBit(PORTD,u8PinNumber);
		}
		break;
	default:


	}

}

void DIO_vidSetPinValue(u8 u8Port, u8 u8PinNumber, u8 u8PinValue)
{
	switch(u8Port)
		{
		case DIO_PORTA:
			if(u8PinValue == DIO_HIGH)
			{
				SetBit(PORTA,u8PinNumber);
			}
			else if(u8PinValue == DIO_LOW)
			{
				ClearBit(PORTA,u8PinNumber);
			}
			break;

		case DIO_PORTB:
			if(u8PinValue == DIO_HIGH)
			{
				SetBit(PORTB,u8PinNumber);
			}
			else if(u8PinValue == DIO_LOW)
			{
				ClearBit(PORTB,u8PinNumber);
			}
			break;

		case DIO_PORTC:
			if(u8PinValue == DIO_HIGH)
			{
				SetBit(PORTC,u8PinNumber);
			}
			else if(u8PinValue == DIO_LOW)
			{
				ClearBit(PORTC,u8PinNumber);
			}
			break;

		case DIO_PORTD:
			if(u8PinValue == DIO_HIGH)
			{
				SetBit(PORTD,u8PinNumber);
			}
			else if(u8PinValue == DIO_LOW)
			{
				ClearBit(PORTD,u8PinNumber);
			}

			break;

		default:

		}

}

void DIO_vidTogglePinValue(u8 u8Port, u8 u8PinNumber)
{

	switch(u8Port)
		{
		case DIO_PORTA:
			ToggleBit(PINA,u8PinNumber);
			break;

		case DIO_PORTB:
			ToggleBit(PINB,u8PinNumber);
			break;

		case DIO_PORTC:
			ToggleBit(PINC,u8PinNumber);
			break;

		case DIO_PORTD:
			ToggleBit(PIND,u8PinNumber);
			break;

		default:
			break;
		}

}

u8 DIO_u8ReadPinValue(u8 u8Port, u8 u8PinNumber)
{

	switch(u8Port)
		{
		case DIO_PORTA:
			return GetBit(PINA,u8PinNumber);
			break;

		case DIO_PORTB:
			return GetBit(PINB,u8PinNumber);
			break;

		case DIO_PORTC:
			return GetBit(PINC,u8PinNumber);
			break;

		case DIO_PORTD:
			return GetBit(PIND,u8PinNumber);
			break;

		default:
			return 0xff;
			break;
		}
}
