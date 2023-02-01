/*
 * lcd.h
 *
 * Created: 12/4/2022 5:30:10 PM
 *  Author: engmu
 */ 


#ifndef LCD_H_
#define LCD_H_
#include "../../MCAL/timer/timer.h" 


void lcd_init_8bit (void);
void lcd_send_command (uint8 cmnd);
void lcd_send_char (uint8 char_data);
void lcd_send_string  (uint8 * name);
void lcd_movecursor(uint8 row,uint8 coloumn) ; // Position Function // 
/******************************************
*            LCD  INSTRUCTIONS            *
*******************************************/
#define LCD_16x2_8bit 0x3F 
#define LCD_CLC 0x01 
#define LCD_DISP_CURSOR_ON 0x0F
#define LCD_DISP_CURSOR_OFF 0x0C
#define LCD_HOME_ADRESS 0x80 
#define LCD_DISP_SHIFT_RIGHT 0x1C
#define LCD_DISP_SHIFT_LEFT  0x18
#define LCD_CURSOR_SHIFT_RIGHT 0x14
#define LCD_CURSOR_SHIFT_LEFT  0x10
#define LCD_CURSOR_HOME 0x03 
#define LCD_NEW_LINE 0xC0 
//-------------------------------//
//            MENUS             //
#define START_MENU  lcd_send_command(LCD_DISP_CURSOR_ON);\
lcd_send_command(LCD_CLC);\
lcd_send_string("Welcome!") ; \
lcd_send_command(LCD_NEW_LINE) ;\
lcd_send_string("Pass:");\



#define CORRECT_MENU lcd_send_command(LCD_CLC) ; \
lcd_send_command(LCD_DISP_CURSOR_OFF)  ;\
 lcd_send_string("Correct Password");\
 d_elay_s(1) ;

#define OPEN_MENU   lcd_send_command(LCD_CLC) ;\
lcd_send_command(LCD_DISP_CURSOR_OFF)  ;\
lcd_send_string("1-Open vault");\
lcd_send_command(LCD_NEW_LINE) ;\
lcd_send_string("2-Set New Password") ;\
d_elay_s(1) ;\
lcd_send_command(LCD_DISP_SHIFT_LEFT) ;\
d_elay_ms(300) ;\
lcd_send_command(LCD_DISP_SHIFT_LEFT) ;\
d_elay_ms(300) ;\
lcd_send_command(LCD_DISP_SHIFT_LEFT) ;

 #define WRONG_MENU lcd_send_command(LCD_CLC);\
 lcd_send_command(LCD_DISP_CURSOR_OFF);\
 lcd_send_string("Wrong Password!");\
 lcd_send_command(LCD_NEW_LINE) ;\
 lcd_send_char(tries +'0') ;\
 lcd_send_string(" Tries Left ") ;
 
 
 #define THIEF_MENU lcd_send_command(LCD_CLC);\
 lcd_send_string("CALLING 911 ...") ; 
 
 
 #define VAULT_OPEN_MENU lcd_send_command(LCD_CLC);\
 lcd_send_command(LCD_DISP_CURSOR_OFF);\
 lcd_send_string("VAULT Oppened");
 
 #define FIRST_USE_MENU lcd_send_command(LCD_CLC);\
 lcd_send_command(LCD_DISP_CURSOR_OFF);\
 lcd_send_string("WELCOME ");\
 lcd_send_command(LCD_NEW_LINE);\
 lcd_send_string("SET YOUR NEW PASS");\
 d_elay_s(1);\
 lcd_send_command(LCD_DISP_SHIFT_LEFT);\
 d_elay_ms(300);\
 lcd_send_command(LCD_DISP_SHIFT_LEFT);\
 d_elay_ms(300);\
 lcd_send_command(LCD_DISP_SHIFT_LEFT);\
  d_elay_s(1);
 
 #define PASS_CHANGED_MENU lcd_send_command(LCD_CLC);\
 lcd_send_command(LCD_DISP_CURSOR_OFF);\
 lcd_send_string("PASSWORD");\
 lcd_send_command(LCD_NEW_LINE);\
 lcd_send_string("CHANGED !") ; 
 
 
#endif /* LCD_H_ */