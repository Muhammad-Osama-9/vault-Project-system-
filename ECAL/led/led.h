/*
 * lcd.h
 *
 * Created: 12/4/2022 5:30:28 PM
 *  Author: engmu
 */ 


#ifndef LED_H_
#define LED_H_
#include "../../MCAL/dio/DIO.h"
#include "../../MCAL/timer/timer.h"
void led_init(uint8 port , uint8 pin ) ;
void led_on (uint8 port,uint8 pin);
void led_off (uint8 port , uint8 pin);
void led_toggle (uint8 port , uint8 pin ) ;



#endif /* LCD_H_ */