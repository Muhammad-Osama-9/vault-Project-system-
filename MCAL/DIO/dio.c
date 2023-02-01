/*
 * dio.c
 *
 * Created: 12/4/2022 5:31:53 PM
 *  Author: engmu
 */ 

#include "dio.h"
void dio_init (uint8 port_num , uint8 pin , uint8 direction)  //start the pin
{
	if(direction)
	{
	switch (port_num)
	{
	case  PORT_A :
	  SET_BIT(DDRA,pin); //OUTPUT
	  break ;
	  
	  case PORT_B :
	 SET_BIT(DDRB,pin);//OUTPUT
	   break ;
	   
	    case PORT_C :
	   SET_BIT(DDRC,pin);//OUTPUT
		 break ;
	   
		 case PORT_D :
	  SET_BIT(DDRD,pin);//OUTPUT
	    break ;
	}
	}
	/********  INPUT  ********/
	else{
		switch (port_num)
		{
		case PORT_A :
		CLEAR_BIT(DDRA,pin); //INPUT
		break ;
		
		case PORT_B :
	CLEAR_BIT(DDRB,pin);  //INPUT
		break ;
		
		case PORT_C :
		CLEAR_BIT(DDRC,pin);  //INPUT
		break ;
		
		case PORT_D :
		CLEAR_BIT(DDRD,pin); //INPUT
		break ;
		}
	}
}
void  dio_write (uint8 port_num , uint8 pin , uint8 value ) // write on Port
{
	if (value)
	{
		//-----------------------HIGH---------------------------//
		switch (port_num)
		{
			case PORT_A :
			SET_BIT(PORTA,pin);
			break ;
			
			case PORT_B :
			SET_BIT(PORTB,pin);
			break ;
				
			 case PORT_C :
			 SET_BIT(PORTC,pin);
			 break ;
				   
			  case PORT_D :
			SET_BIT(PORTD,pin);
			  break ;
				
		}
	}

else
{
	 //------------------------ LOW -------------------------------//
		switch (port_num)
		{
			case PORT_A :
			CLEAR_BIT(PORTA,pin);  
			break ;
			
			case PORT_B :
			CLEAR_BIT(PORTB,pin); 
			break ;
			
			case PORT_C :
			CLEAR_BIT(PORTC,pin);  
			break ;
			
			case PORT_D :
			CLEAR_BIT(PORTD,pin);  
			break ;
	}
}
}
uint8 dio_read (uint8 port_num , uint8 pin , uint8 *value) // read on Port pin
{
	switch (port_num)
	{
		case  PORT_A :
		*value = GET_BIT(PINA,pin);
		break ; 
		
		 case PORT_B :
		*value = GET_BIT(PINB,pin);
		 break;
		 
		case PORT_C :
		*value = GET_BIT(PINC,pin);
		break;
		
		case PORT_D :
		*value = GET_BIT(PIND,pin);	
		break;
/*    ERROR-Handling      */ 
		default :
		return 1 ; 
		break ;  
	}
	return 0;
}
/*         flip the Bit        */
void dio_toggle (uint8 port_num , uint8 pin ) 
{
	switch (port_num)
	{
		case PORT_A :
		TOGGLE_BIT(PORTA,pin);
		break ;
		
		case PORT_B :
		TOGGLE_BIT(PORTB,pin);
		break ;
		
		case PORT_C :
		TOGGLE_BIT(PORTC,pin);
		break ;
		
		case PORT_D :
		TOGGLE_BIT(PORTD,pin);
		break ;
	}
}
void dio_set_port(uint8 port , uint8 value)
{
	switch (value)  // HIGH
	{
		case HIGH :
		switch (port)
		{
			case PORT_A :
			PORTA = 0xFF ; 
			break ;
			case PORT_B :
			PORTB = 0xFF ; 
			break ; 
			case PORT_C :
			PORTC = 0xFF ;
			break ;
			case PORT_D :
			PORTD = 0xFF ;
			break ;
		}
		break ; 
		
		case LOW :
			switch (port)
			{
				case PORT_A :
				PORTA = 0x00 ;
				break ;
				case PORT_B :
				PORTB = 0x00 ;
				break ;
				case PORT_C :
				PORTC = 0x00 ;
				break ;
				case PORT_D :
				PORTD = 0x00 ;
				break ;
			}
			break ; 
		
	}
}