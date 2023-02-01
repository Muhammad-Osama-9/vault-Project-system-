/*
 * EEPROM.h
 *
 * Created: 12/22/2022 7:53:54 PM
 *  Author: engmu
 */ 


#ifndef EEPROM_H_
#define EEPROM_H_


#include "../../MCAL/DIO/dio.h"

void EEPROM_write(uint8 address, uint8 value );
uint8 EEPROM_read( uint8 address );
void EEPROM_clear(uint8 address);





#endif /* EEPROM_H_ */