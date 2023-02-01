/*
 * bit_math.h
 *
 * Created: 12/4/2022 5:19:02 PM
 *  Author: engmu
 */ 


#ifndef BIT_MATH_H_
#define BIT_MATH_H_



//----DIRECTION DEFINES----//
#define TRUE  1
#define FALSE  0

#define HIGH 1
#define LOW 0

#define IN 0
#define OUT 1
//------------------------------------------//
#define CLEAR_BIT(port,pin)     port&=~(1<<pin)
#define SET_BIT(port,pin)        port|=(1<<pin)
#define GET_BIT(REG, BITNO)   ((REG >> BITNO) & (1))
#define TOGGLE_BIT(port,pin)    port^=(1<<pin)




#endif /* BIT_MATH_H_ */