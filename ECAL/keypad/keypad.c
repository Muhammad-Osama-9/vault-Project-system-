
#include "keypad.h"
	uint8 Local_u8PressedKey = KEYPAD_DEFAULT_KEY;
	uint8 Local_u8ColCounter, Local_u8RowCounter, Local_u8KeyFlag;

	uint8 KeypadArray[KEYPAD_ROWS_NUM][KEYPAD_COLS_NUM] = KEYPAD_ARR_VAL;
	uint8 ColumnsArr[3] = {0, 1, 2};
	uint8 RowsArr[KEYPAD_ROWS_NUM]    = {3, 4, 5, 6};

void KEYPAD_voidPinInit(void)
{
	/*Set keypad columns pins as OUTPUT*/
	dio_init(KEYPAD_PORT, KEYPAD_COLUMN0_PIN, OUT);
	dio_init(KEYPAD_PORT, KEYPAD_COLUMN1_PIN, OUT);
	dio_init(KEYPAD_PORT, KEYPAD_COLUMN2_PIN, OUT);
	

	/*Set keypad rows pins as INPUT*/
	dio_init(KEYPAD_PORT, KEYPAD_ROW0_PIN, IN);
	dio_init(KEYPAD_PORT, KEYPAD_ROW1_PIN, IN);
	dio_init(KEYPAD_PORT, KEYPAD_ROW2_PIN, IN);
	dio_init(KEYPAD_PORT, KEYPAD_ROW3_PIN, IN);


	/*Set the keypad port value to HIGH(to enable pull-up in rows pins, and out high signal on columns pins)*/
	dio_set_port(KEYPAD_PORT, HIGH);
}

uint8 KEYPAD_u8GetPressedKey(void)
{
	Local_u8PressedKey = KEYPAD_DEFAULT_KEY;

	for(Local_u8ColCounter = 0; ColumnsArr[Local_u8ColCounter] < KEYPAD_COLS_NUM; Local_u8ColCounter++)
	{
		/*Activate the current column by setting its value to low*/
		dio_write(KEYPAD_PORT,Local_u8ColCounter, LOW);

		/*Loop for the rows to get if any key is pressed*/
		for(Local_u8RowCounter = 0; Local_u8RowCounter < KEYPAD_ROWS_NUM; Local_u8RowCounter++)
		{
			 dio_read(KEYPAD_PORT, RowsArr[Local_u8RowCounter],&Local_u8KeyFlag);	
			if(LOW == Local_u8KeyFlag)
			{
				/*        POLING -> take the read when the switch released      */
				while(LOW == Local_u8KeyFlag)
				{
					 dio_read(KEYPAD_PORT, RowsArr[Local_u8RowCounter],&Local_u8KeyFlag);
					
				}
				Local_u8PressedKey = KeypadArray[Local_u8RowCounter][Local_u8ColCounter];
				return Local_u8PressedKey;
			}
			else{
				/*Do Nothing*/
				}
			 
		}
		/*Deactivate the current column*/	
		dio_write(KEYPAD_PORT, Local_u8ColCounter , HIGH);
		
	}
	return Local_u8PressedKey;
}

