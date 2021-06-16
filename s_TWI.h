/***************************************
* Name: TWI.h                          *
* Author: Filip Bartoš                 *
*                                      *
* Contains the main functions used for *
* TWI communication                    *
***************************************/


#ifndef S_TWI_H_
#define S_TWI_H_


#define F_CPU 16000000UL
#define F_TWI 100000UL	//TWI Clock
#define PSC_TWI 1		//TWI Prescaler
#define SET_TWBR (F_CPU / F_TWI - 16UL)/(PSC_TWI * 2UL)

#include <stdio.h>
#include <avr/io.h>


#define TWI_START          0 //Timeout start-condition
#define TWI_SENDADDRESS    1 //Timeout device-address
#define TWI_BYTE           2 //Timeout byte-transmission
#define TWI_READACK        3 //Timeout read acknowledge
#define TWI_READNACK       4 //Timeout read nacknowledge


void TWI_init(void);
void TWI_start(uint8_t address);
void TWI_stop(void);
void TWI_write(uint8_t byte);

uint8_t TWI_read_ACK(void);
uint8_t TWI_read_NACK(void);


#endif /* S_TWI_H_ */
