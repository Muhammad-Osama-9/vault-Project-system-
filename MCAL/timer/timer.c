/*
 * timer.c
 *
 * Created: 12/4/2022 5:32:01 PM
 *  Author: engmu
 */ 
#include "timer.h"
volatile uint16 N ;

volatile float r_num ;
volatile uint16 init_num ; 
void d_elay_s (uint16 t_sec)
{
	
	N = (int) ((t_sec / 0.0655 )) ;
	 r_num = (t_sec / 0.0655 )- N ; 
	 init_num = (int)(1-r_num)*256 ; 
	TCCR0 = 0x00 ; // initi
	TCNT0 = init_num;
	TCCR0 = 0x04; // 256 prescaller - START Timer
	while (N--)
	{		
		while (!(GET_BIT(TIFR,0))) ;
		SET_BIT(TIFR,0) ; // remove FLag
	}
	//stop the timer
	TCCR0 = 0x00 ;
	N= 0 ;
	TCNT0 = 0x00 ;
}
void d_elay_ms (uint16 t_msec)
{
	 N = (int)t_msec / 16.384 ; //  (16.384) -->  time to overflow counter with 64 prescaller
	r_num = (t_msec / 16.384)- N ;
	init_num = (int)(1-r_num)*256 ;
	TCCR0 = 0x00 ; // initi
	TCNT0 = init_num ;// initial count number
	TCCR0 = 0x03; // 64 prescaller - START Timer
	while (N--)
	{
		
		while (!(GET_BIT(TIFR,0))) ; // delay //
		
		SET_BIT(TIFR,0) ; // remove FLag
	}
	TCNT0 = 0x00 ;
	
}