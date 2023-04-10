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
	case DIO_u8PORTA:
		if(u8PortDirection == DIO_u8INPUT)
		{
			DDRA  = 0x00;
			PORTA = 0x00;
		}
		else if(u8PortDirection == DIO_u8INPUT_PULLUP)
		{
			DDRA = 0x00;
			PORTA = 0xff;
		}
		else if(u8PortDirection == DIO_u8OUTPUT)
		{
			DDRA = 0xff;
			PORTA = 0x00;
		}
		break;
	case DIO_u8PORTB:
		if(u8PortDirection == DIO_u8INPUT)
		{
			DDRB  = 0x00;
			PORTB = 0x00;
		}
		else if(u8PortDirection == DIO_u8INPUT_PULLUP)
		{
			DDRB = 0x00;
			PORTB = 0xff;
		}
		else if(u8PortDirection == DIO_u8OUTPUT)
		{
			DDRB = 0xff;
			PORTB = 0x00;
		}
		break;
	case DIO_u8PORTC:
		if(u8PortDirection == DIO_u8INPUT)
		{
			DDRC  = 0x00;
			PORTC = 0x00;
		}
		else if(u8PortDirection == DIO_u8INPUT_PULLUP)
		{
			DDRC = 0x00;
			PORTC = 0xff;
		}
		else if(u8PortDirection == DIO_u8OUTPUT)
		{
			DDRC = 0xff;
			PORTC = 0x00;
		}
		break;
	case DIO_u8PORTD:
		if(u8PortDirection == DIO_u8INPUT)
		{
			DDRD  = 0x00;
			PORTD = 0x00;
		}
		else if(u8PortDirection == DIO_u8INPUT_PULLUP)
		{
			DDRD = 0x00;
			PORTD = 0xff;
		}
		else if(u8PortDirection == DIO_u8OUTPUT)
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
		case DIO_u8PORTA:
			if(u8PortValue == DIO_u8HIGH)
			{
				PORTA = 0xff;
			}
			else if(u8PortValue == DIO_u8LOW)
			{
				PORTA = 0x00;
			}
			break;

		case DIO_u8PORTB:
			if(u8PortValue == DIO_u8HIGH)
			{
				PORTB = 0xff;
			}
			else if(u8PortValue == DIO_u8LOW)
			{
				PORTB = 0x00;
			}
			break;

		case DIO_u8PORTC:
			if(u8PortValue == DIO_u8HIGH)
			{
				PORTC = 0xff;
			}
			else if(u8PortValue == DIO_u8LOW)
			{
				PORTC = 0x00;
			}
			break;

		case DIO_u8PORTD:
			if(u8PortValue == DIO_u8HIGH)
			{
				PORTD = 0xff;
			}
			else if(u8PortValue == DIO_u8LOW)
			{
				PORTD = 0x00;
			}

			break;
		default:

		}

}

void DIO_vidSetPinDirection(u8 u8PinNumber, u8 u8PinDirection)
{
	u8 u8Port = u8PinNumber / 8;
	u8PinNumber = u8PinNumber % 8;

	switch(u8Port)
	{
	case DIO_u8PORTA:
		if(u8PinDirection == DIO_u8INPUT)
		{
			ClearBit(DDRA,u8PinNumber);
			ClearBit(PORTA,u8PinNumber);
		}
		else if(u8PinDirection == DIO_u8INPUT_PULLUP)
		{
			ClearBit(DDRA,u8PinNumber);
			SetBit(PORTA,u8PinNumber);
		}
		else if(u8PinDirection == DIO_u8OUTPUT)
		{
			SetBit(DDRA,u8PinNumber);
			ClearBit(PORTA,u8PinNumber);
		}
		break;
	case DIO_u8PORTB:
		if(u8PinDirection == DIO_u8INPUT)
		{
			ClearBit(DDRB,u8PinNumber);
			ClearBit(PORTB,u8PinNumber);
		}
		else if(u8PinDirection == DIO_u8INPUT_PULLUP)
		{
			ClearBit(DDRD,u8PinNumber);
			SetBit(PORTD,u8PinNumber);
		}
		else if(u8PinDirection == DIO_u8OUTPUT)
		{
			SetBit(DDRB,u8PinNumber);
			ClearBit(PORTB,u8PinNumber);
		}
		break;
	case DIO_u8PORTC:
		if(u8PinDirection == DIO_u8INPUT)
		{
			ClearBit(DDRC,u8PinNumber);
			ClearBit(PORTC,u8PinNumber);
		}
		else if(u8PinDirection == DIO_u8INPUT_PULLUP)
		{
			ClearBit(DDRC,u8PinNumber);
			SetBit(PORTC,u8PinNumber);
		}
		else if(u8PinDirection == DIO_u8OUTPUT)
		{
			SetBit(DDRC,u8PinNumber);
			ClearBit(PORTC,u8PinNumber);
		}
		break;
	case DIO_u8PORTD:
		if(u8PinDirection == DIO_u8INPUT)
		{
			ClearBit(DDRD,u8PinNumber);
			ClearBit(PORTD,u8PinNumber);
		}
		else if(u8PinDirection == DIO_u8INPUT_PULLUP)
		{
			ClearBit(DDRD,u8PinNumber);
			SetBit(PORTD,u8PinNumber);
		}
		else if(u8PinDirection == DIO_u8OUTPUT)
		{
			SetBit(DDRD,u8PinNumber);
			ClearBit(PORTD,u8PinNumber);
		}
		break;
	default:


	}

}

void DIO_vidSetPinValue(u8 u8PinNumber, u8 u8PinValue)
{

	u8 u8Port = u8PinNumber / 8;
	u8PinNumber = u8PinNumber % 8;

	switch(u8Port)
		{
		case DIO_u8PORTA:
			if(u8PinValue == DIO_u8HIGH)
			{
				SetBit(PORTA,u8PinNumber);
			}
			else if(u8PinValue == DIO_u8LOW)
			{
				ClearBit(PORTA,u8PinNumber);
			}
			break;

		case DIO_u8PORTB:
			if(u8PinValue == DIO_u8HIGH)
			{
				SetBit(PORTB,u8PinNumber);
			}
			else if(u8PinValue == DIO_u8LOW)
			{
				ClearBit(PORTB,u8PinNumber);
			}
			break;

		case DIO_u8PORTC:
			if(u8PinValue == DIO_u8HIGH)
			{
				SetBit(PORTC,u8PinNumber);
			}
			else if(u8PinValue == DIO_u8LOW)
			{
				ClearBit(PORTC,u8PinNumber);
			}
			break;

		case DIO_u8PORTD:
			if(u8PinValue == DIO_u8HIGH)
			{
				SetBit(PORTD,u8PinNumber);
			}
			else if(u8PinValue == DIO_u8LOW)
			{
				ClearBit(PORTD,u8PinNumber);
			}

			break;

		default:

		}

}

void DIO_vidTogglePinValue(u8 u8PinNumber)
{
	u8 u8Port = u8PinNumber / 8;
	u8PinNumber = u8PinNumber % 8;

	switch(u8Port)
		{
		case DIO_u8PORTA:
			ToggleBit(PORTA,u8PinNumber);
			break;

		case DIO_u8PORTB:
			ToggleBit(PORTB,u8PinNumber);
			break;

		case DIO_u8PORTC:
			ToggleBit(PORTC,u8PinNumber);
			break;

		case DIO_u8PORTD:
			ToggleBit(PORTD,u8PinNumber);
			break;

		default:
			break;
		}

}

u8 DIO_u8ReadPinValue(u8 u8PinNumber)
{
	u8 u8Port = u8PinNumber / 8;
	u8PinNumber = u8PinNumber % 8;

	switch(u8Port)
		{
		case DIO_u8PORTA:
			return GetBit(PINA,u8PinNumber);
			break;

		case DIO_u8PORTB:
			return GetBit(PINB,u8PinNumber);
			break;

		case DIO_u8PORTC:
			return GetBit(PINC,u8PinNumber);
			break;

		case DIO_u8PORTD:
			return GetBit(PIND,u8PinNumber);
			break;

		default:
			return 0xff;
			break;
		}
}
