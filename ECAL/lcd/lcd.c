/*
 * lcd.c
 *
 * Created: 12/4/2022 5:30:02 PM
 *  Author: engmu
 */ 
#include "lcd.h"

void lcd_init_8bit (void)
{
	DDRC = 0x07; 
	DDRD = 0xFF ;  // 8  PINS of LCD on PORTc  (OUTPUT PINS)
	 // 3 pins  Controlled of LCD
	d_elay_ms(30);
	
lcd_send_command(LCD_16x2_8bit); //8bit

lcd_send_command(LCD_DISP_CURSOR_ON);
lcd_send_command(LCD_CLC);
lcd_send_command(LCD_HOME_ADRESS) ; 
lcd_send_command(LCD_CURSOR_HOME);
}
void lcd_send_command (uint8 cmnd)
{
	PORTD = cmnd ;
	CLEAR_BIT(PORTC,1) ;  //RW
	CLEAR_BIT(PORTC,0) ;  // RS
	SET_BIT(PORTC,2);  // EN
	d_elay_ms(1);
	CLEAR_BIT(PORTC,2);
	d_elay_ms(3);
}
void lcd_send_char (uint8 char_data)
{
	PORTD  = char_data ;
	CLEAR_BIT(PORTC,1) ;  //RW
	SET_BIT(PORTC,0) ;  // RS
	SET_BIT(PORTC,2);  // EN
	d_elay_ms(1);
	CLEAR_BIT(PORTC,2);
	d_elay_ms(3);
}
void lcd_send_string  (uint8 * name)
{
	for (int i = 0  ; *(name +i ) != '\0' ; i++)
	{
		PORTD = *(name +i );
		CLEAR_BIT(PORTC,1) ; //RW
		SET_BIT(PORTC,0) ;  // RS
		SET_BIT(PORTC,2);  // EN
		d_elay_ms(1);
		CLEAR_BIT(PORTC,2);
		
		//d_elay_ms(100);
	}
	
}
void lcd_movecursor(uint8 row,uint8 coloumn)
{
	uint8 data ;
	if(row>2 || row<1 || coloumn>16 || coloumn<1)
	{
		data = LCD_HOME_ADRESS ;
	}
	else if(row == 1)
	{
		data= LCD_HOME_ADRESS +coloumn-1 ;
	}
	else if (row==2)
	{
		data=LCD_NEW_LINE+coloumn-1;
	}
	lcd_send_command(data);
}
