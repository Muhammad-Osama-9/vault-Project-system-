/*
 * dio.h
 *
 * Created: 12/4/2022 5:31:46 PM
 *  Author: engmu
 */ 


#ifndef DIO_H_
#define DIO_H_

#include "../../drivers/reg_map.h"







//-----------------------MACROS-----------------//

#define PORT_A 'A'
#define PORT_B 'B'
#define PORT_C 'C'
#define PORT_D 'D'
// -------------------------FUNCTIONS----------//

void dio_init (uint8 port_num , uint8 pin , uint8 direction);  //start the pin
void  dio_write (uint8 port_num , uint8 pin , uint8 value ); // write on Port
uint8 dio_read (uint8 port_num , uint8 pin , uint8 *value); // read on Port pin
void dio_toggle (uint8 port_num , uint8 pin );  // flip the Bit
void dio_set_port(uint8 port , uint8 value); 



#endif /* DIO_H_ */