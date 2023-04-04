/*
 * DIO_PRIV.h
 *
 *  Created on: Apr 4, 2023
 *      Author: Hussein
 */

#ifndef PRIVATE_DIO_PRIV_H_
#define PRIVATE_DIO_PRIV_H_

#define PORTA 	*((volatile unsigned char* const) 0x3B)
#define DDRA 	*((volatile unsigned char* const) 0x3A)
#define PINA 	*((volatile unsigned char* const) 0x39)

#define PORTB 	*((volatile unsigned char* const) 0x38)
#define DDRB 	*((volatile unsigned char* const) 0x37)
#define PINB 	*((volatile unsigned char* const) 0x36)

#define PORTC	*((volatile unsigned char* const) 0x35)
#define DDRC 	*((volatile unsigned char* const) 0x34)
#define PINC 	*((volatile unsigned char* const) 0x33)

#define PORTD 	*((volatile unsigned char* const) 0x32)
#define DDRD 	*((volatile unsigned char* const) 0x31)
#define PIND 	*((volatile unsigned char* const) 0x30)



#endif /* PRIVATE_DIO_PRIV_H_ */
