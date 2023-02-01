/*
 * app.h
 *
 * Created: 12/4/2022 5:33:22 PM
 *  Author: engmu
 */ 


#ifndef APP_H_
#define APP_H_

#include "../ECAL/led/led.h"
#include "../ECAL/keypad/keypad.h"
#include "../ECAL/lcd/lcd.h"
#include "../ECAL/EEPROM/EEPROM.h"
#include "../ECAL/buzzer/buzzer.h"
#define  EEPROM_STATUS_LOC 0x20
#define  EEPROM_PASS_LOC1 0x21
#define  EEPROM_PASS_LOC2 0x22
#define  EEPROM_PASS_LOC3 0x23
#define  EEPROM_PASS_LOC4 0x24
#define	 MAX_TRIES 2
#define  NOTPRESSED 0xFF
void app_init ();
void app_start ();
void keypad_enter (uint8 arr [] , uint8 size) ;
void set_pass () ;
uint8 pass_check (uint8 pass []);
void police_calling ();
void vault_opened ();

#endif /* APP_H_ */