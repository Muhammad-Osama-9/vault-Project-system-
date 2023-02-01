/*
 * reg_map.h
 *
 * Created: 12/4/2022 5:18:52 PM
 *  Author: engmu
 */ 


#ifndef REG_MAP_H_
#define REG_MAP_H_
#include "bit_math.h"
#include "std_types.h"

/*********************************************
*                            DIO-PINS        *
**********************************************/
//----PORT A---//
#define PORTA  *((volatile uint8 *) (0x3B))   //OUTPUT
#define DDRA *((volatile uint8 *) (0x3A))    // CHOOSE    (input , output)
#define PINA  *((volatile uint8 *) (0x39))   //INPUT

//----PORT B----//
#define PORTB  *((volatile uint8 *)(0x38))
#define DDRB *((volatile uint8 *)(0x37))
#define PINB  *((volatile uint8 *)(0x36))

//----PORTC----//
#define PORTC  *((volatile uint8 *) (0x35))
#define DDRC *((volatile uint8 *) (0x34))
#define PINC  *((volatile uint8 *) (0x33))

//----PORTD----//
#define PORTD  *((volatile uint8 *) (0x32))
#define DDRD   *((volatile uint8 *) (0x31))
#define PIND   *((volatile uint8 *) (0x30))
//------------------------------------------------------------------------------------//

// ---  PIN --//
#define PIN0 0
#define PIN1 1
#define PIN2 2
#define PIN3 3
#define PIN4 4
#define PIN5 5
#define PIN6 6
#define PIN7 7
//-------------------------------------------------------------------------------//
/*                 TIMER Registers                       */
#define TCNT0   *((volatile uint8 *) (0x52))
#define TCCR0   *((volatile uint8 *) (0x53))
#define TIFR   *((volatile uint8  *) (0x58))
#define TIMSK  *((volatile uint8 *) (0x59))
#define OCR0  *((volatile uint8 *) (0x5C))
//----------------------------------------------//
/*                         INTERUPTS Registers                  */
#define SREG   *((volatile uint8 *) (0x5F))  //Global interrupt register
#define GICR   *((volatile uint8 *)(0x5B))
#define GIFR  *((volatile uint8 *)(0x5A))
#define MCUCR  *((volatile uint8 *)(0x55))
#define MCUCSR  *((volatile uint8 *)(0x54))
//----------------------------------------------//
/*                           ADC Registers                                 */
#define ADMUX  *((volatile uint8 *)(0x27))
#define ADCSRA *((volatile uint8 *)(0x26))
#define ADCH  *((volatile uint8 * )(0x25))
#define ADCL  *((volatile uint8 * )(0x24))
#define SFIOR  *((volatile uint8 * )(0x50))
//-------------------------------------------------------//

/*                             UART Registers                                */

#define UDR  *((volatile uint8 *)(0x2C))  //Data Register
#define UCSRA *((volatile uint8 *)(0x2B))
#define UCSRB *((volatile uint8 *)(0x2A))
#define UCSRC *((volatile uint8 *)(0x40))
#define UBRRL  *((volatile uint8 *)(0x29))  //Baud Rate Register

//--------------------------------------------------------//
/*					EEPROM Registers            */
#define EEAR *((volatile uint8 *)(0x3E)) 
#define EEARL *((volatile uint8 *)(0x3E))   
#define EEARH *((volatile uint8 *)(0x3F))  
#define EEDR *((volatile uint8 *)(0x3D))  
#define EECR *((volatile uint8 *)(0x3C))  
/* EEPROM Control Register */
#define EERIE   3
#define EEMWE   2
#define EEWE    1
#define EERE    0

#endif /* REG_MAP_H_ */