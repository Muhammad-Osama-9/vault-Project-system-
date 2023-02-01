/*
 * buzzer.h
 *
 * Created: 12/4/2022 5:30:46 PM
 *  Author: engmu
 */ 


#ifndef BUZZER_H_
#define BUZZER_H_
#include "../../MCAL/DIO/dio.h"
void buzzer_init (uint8 port ,uint8 pin );
void buzzer_on (uint8 port , uint8 pin );
void buzzer_off (uint8 port , uint8 pin);
void buzzer_toggle (uint8 port , uint8 pin);
#endif /* BUZZER_H_ */