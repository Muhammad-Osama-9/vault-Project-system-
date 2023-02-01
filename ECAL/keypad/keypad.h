/*
 * keypad.h
 *
 * Created: 12/4/2022 5:29:33 PM
 *  Author: engmu
 */ 


#ifndef KEYPAD_H_
#define KEYPAD_H_

#include "../../MCAL/DIO/dio.h"
#include "../../MCAL/timer/timer.h"
#define KEYPAD_ROWS_NUM		4
#define KEYPAD_COLS_NUM		3
#define KEYPAD_PORT			PORT_A

#define KEYPAD_COLUMN0_PIN		PIN0
#define KEYPAD_COLUMN1_PIN		PIN1
#define KEYPAD_COLUMN2_PIN		PIN2


#define KEYPAD_ROW0_PIN			PIN3
#define KEYPAD_ROW1_PIN			PIN4
#define KEYPAD_ROW2_PIN			PIN5
#define KEYPAD_ROW3_PIN			PIN6

#define KEYPAD_DEFAULT_KEY		0xFF

#define KEYPAD_ARR_VAL			{{'1','2','3'},{'4','5','6'},{'7','8','9'},{'*','0','#'}}
//---------------------------------------------------------------------------------//
									// FUNCTIONS // 
void KEYPAD_voidPinInit(void);
uint8 KEYPAD_u8GetPressedKey(void);
//--------------------------------------------------------------------------------//
#endif /* KEYPAD_H_ */