/*
 * EEPROM.c
 *
 * Created: 12/22/2022 7:53:44 PM
 *  Author: engmu
 */ 
#include "EEPROM.h"

uint8 EEPROM_read( uint8 address ){
	/* Wait for completion of previous write */
	while(EECR & (1<<EEWE)){
		//DO NOTNING
	}
	/* Set up address register */
	EEAR = address ;
	/* Start EEPROM read by setting EERE */
	SET_BIT(EECR,EERE);
	/* Return data from data register */
	return EEDR;
}

void EEPROM_write(uint8 address, uint8 value ){
	/* Wait for completion of previous write */
	while(EECR & (1<<EEWE)){
		//DO NOTNING
	}
	/* Set up address and value registers */
	EEAR = address;
	EEDR = value;
	/* Write logical one to EEMWE */
	SET_BIT(EECR,EEMWE);
	/* Start EEPROM write by setting EEWE */
	SET_BIT(EECR,EEWE);
}
void EEPROM_clear(uint8 address){
	address = 0xFF;
}

