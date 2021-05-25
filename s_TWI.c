/*
 * s_TWI.c
 *
 * Created: 15.02.2021 19:06:58
 *  Author: Filip
 */ 

#include "s_TWI.h"


//------------------------------------------------
// Function: TWI_init
// Purpose: Initialise TWI
// Input: None
// Output: None
//------------------------------------------------
void TWI_init(void)
{
	//Set prescaler
	switch (PSC_TWI) {
        case 4:
            TWSR = 0x1;
            break;
        case 16:
            TWSR = 0x2;
            break;
        case 64:
            TWSR = 0x3;
            break;
        default:
            TWSR = 0x00;
            break;
	};
	
	TWBR = (uint8_t)SET_TWBR;
	
	//Enable TWI
	TWCR = (1<<TWEN);
}

//------------------------------------------------
// Function: TWI_start
// Purpose: Start TWI communication
// Input: 
//  - uint8_t address: Address of reciever
// Output: None
//------------------------------------------------
void TWI_start(uint8_t address)
{
	//Start
	TWCR = (1<<TWINT) | (1<<TWSTA) | (1<<TWEN);
	
	
	while(!(TWCR & (1<<TWINT)));
	
	//Send address
	TWDR = address;
	TWCR = (1<<TWINT) | (1<<TWEN);
	
	while(!(TWCR & (1<<TWINT)));
}

//------------------------------------------------
// Function: TWI_stop
// Purpose: Stop TWI communication
// Input: None
// Output: None
//------------------------------------------------
void TWI_stop(void)
{
	//Stop
	TWCR = (1<<TWINT) | (1<<TWSTO) | (1<<TWEN);
}

//------------------------------------------------
// Function: TWI_write
// Purpose: Send byte to TWI interface
// Input: 
//  - uint8_t byte: Byte to send
// Output: None
//------------------------------------------------
void TWI_write(uint8_t byte)
{
	TWDR = byte;
	TWCR = (1<<TWINT) | (1<<TWEN);
	

	while(!(TWCR & (1<<TWINT)));
}

//------------------------------------------------
// Function: TWI_read_ACK
// Purpose: Read acknowledge from TWI interface
// Input: None
// Output:
//  - TWDR: Recieved value at TWI interface
//  - 0: Error
//------------------------------------------------
uint8_t TWI_read_ACK(void)
{
	TWCR = (1<<TWINT) | (1<<TWEN) | (1<<TWEA);
	

	while(!(TWCR & (1<<TWINT)));
	return TWDR;
}

//------------------------------------------------
// Function: TWI_read_NACK
// Purpose: Read non-acknowledge fro TWI interface
// Input: None
// Output:
//  - TWDR: Recieved value at TWI interface
//  - 0: Error
//------------------------------------------------
uint8_t TWI_read_NACK(void)
{
	TWCR = (1<<TWINT) | (1<<TWEN);
	

	while(!(TWCR & (1<<TWINT)));
	return TWDR;
}