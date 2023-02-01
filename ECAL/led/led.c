/*
 * led.c
 *
 * Created: 12/4/2022 5:30:20 PM
 *  Author: engmu
 */ 
#include "led.h"
void led_init(uint8 port , uint8 pin )
{
	dio_init(port , pin , OUT) ;
}
void led_on (uint8 port,uint8 pin)
{
	dio_write(port,pin,HIGH) ;
}
void led_off (uint8 port , uint8 pin)
{
	dio_write(port  , pin , LOW) ;
}
void led_toggle (uint8 port , uint8 pin )
{
	dio_toggle(port , pin ) ;
}
