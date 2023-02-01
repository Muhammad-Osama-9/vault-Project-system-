/*
 * app.c
 *
 * Created: 12/4/2022 5:33:13 PM
 *  Author: engmu
 */ 
#include "app.h"


/*			Global Variables 		 */
uint8 pass_arr[4];
uint8 key = NOTPRESSED ;
uint8 flag=0, cnt=0, i=0;
uint8 tries=MAX_TRIES;
//--------------------------------------//
void app_init ()
{
	 /*		Initialization	 	*/
	 lcd_init_8bit() ;
	 KEYPAD_voidPinInit() ;
	 led_init(PORT_B,0);//red_led//
	 led_init(PORT_B,1);//blue_led//
	 buzzer_init(PORT_B,2);//buzzer //
	 led_init(PORT_B,3);// green led
 /*-------------------------------------------------------	*/
}
void app_start ()
{
	  
	  if (EEPROM_read(EEPROM_STATUS_LOC)==NOTPRESSED)
	  {
		  FIRST_USE_MENU
		  set_pass() ;
	  }
	  else {
		  /* Do Nothing */
	  }
	  LOOP :
	  START_MENU
	  keypad_enter(pass_arr,sizeof(pass_arr));
	  if (pass_check(pass_arr)==TRUE)
	  {
		  CORRECT_MENU
		  OPEN_MENU
		  while(1)
		  {
			  key = KEYPAD_u8GetPressedKey();
			  if (key != NOTPRESSED)
			  {
				  switch (key)
				  {
					  case '1' :
					  vault_opened();
					  break;
					  
					  case '2':
					  set_pass();
					  PASS_CHANGED_MENU
					  break;
					  
				  }
				  break;
			  }
		  }
	  }
	  else
	  {
		  WRONG_MENU
		  d_elay_s(1);
		  tries--;
		  if (tries > 0)
		  goto LOOP ;
		  else
		  {
			  police_calling();
		  }
	  }
	  
}




/*		---------			FUNCTIONS				-------- 			*/

void keypad_enter (uint8 arr [] , uint8 size)
{
	for (uint8 i = 0 ; i < size ; )
	{
		key = KEYPAD_u8GetPressedKey() ;
		if (key != 0xFF)
		{
			arr[i] = key ;
			lcd_send_char(key);
			d_elay_ms(500);
			lcd_movecursor(2,6+i);
			lcd_send_char('*');
			i++;
		}
		
	}
	
}
void set_pass ()
{
	lcd_send_command(LCD_CLC) ;
	lcd_send_command(LCD_DISP_CURSOR_ON);
	lcd_send_string("Set PASS:");
	cnt=0;
	while(cnt<4)
	{
		key=KEYPAD_u8GetPressedKey();
		if(key != NOTPRESSED)
		{
			lcd_send_char(key);
			d_elay_ms(500);
			lcd_movecursor(1,10+cnt);
			lcd_send_char('*');
			d_elay_ms(500);
			EEPROM_write(EEPROM_PASS_LOC1+cnt,key); // Write password in EEPROM //
			cnt++;
		}
	}
	EEPROM_write(EEPROM_STATUS_LOC,0x00);
}
uint8 pass_check (uint8 pass [])
{
	if (EEPROM_read(EEPROM_PASS_LOC1) == pass[0] &&  EEPROM_read(EEPROM_PASS_LOC2) == pass[1] &&
	EEPROM_read(EEPROM_PASS_LOC3) == pass[2] && EEPROM_read(EEPROM_PASS_LOC4) == pass[3])
	{
		return TRUE ;
	}
	else {return FALSE ; }
}
void police_calling ()
{
	
	THIEF_MENU
	led_on(PORT_B,1);
	led_off(PORT_B,0);
	while(1)
	{
		buzzer_toggle(PORT_B,2) ;
		led_toggle(PORT_B,1);
		led_toggle(PORT_B,0);
		d_elay_ms(500);
	}
}
void vault_opened ()
{
	VAULT_OPEN_MENU
	led_on(PORT_B,3);
	buzzer_toggle(PORT_B,2);
	d_elay_ms(250);
	buzzer_toggle(PORT_B,2);
	d_elay_ms(250);
	buzzer_off(PORT_B,2);
	
}