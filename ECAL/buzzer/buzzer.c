/*
 * buzzer.c
 *
 * Created: 12/4/2022 5:30:37 PM
 *  Author: engmu
 */ 
#include "buzzer.h"
void buzzer_init (uint8 port ,uint8 pin )
{
	dio_init(port,pin,OUT) ; 
}
void buzzer_on (uint8 port , uint8 pin )
{
	dio_write(port,pin,HIGH) ; 
}
void buzzer_off (uint8 port , uint8 pin)
{
	dio_write(port,pin,LOW) ; 
}
void buzzer_toggle (uint8 port , uint8 pin)
{
	dio_toggle(port,pin);
}