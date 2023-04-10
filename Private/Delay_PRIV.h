/*
 * Delay_PRIV.h
 *
 *  Created on: Apr 5, 2023
 *      Author: Hussein
 */

#ifndef PRIVATE_DELAY_PRIV_H_
#define PRIVATE_DELAY_PRIV_H_


#define TCCR0 	*((volatile unsigned char* const) 0x53)
#define TCNT0 	*((volatile unsigned char* const) 0x52)

#define TIFR 	*((volatile unsigned char* const) 0x58)

#define TOV0 	0

#endif /* PRIVATE_DELAY_PRIV_H_ */
