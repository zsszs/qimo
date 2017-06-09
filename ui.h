#ifndef __UI_H
#define __UI_H	
#include "LPC11xx.h"

#define MAIN_MENU_ID           0          
#define temperature_test_id     1         
#define logo_id                  2   
#define basic_information_id    3;
#define Time_and_date_id       4;
extern void OLED_CLS(void);       //«Â∆¡
extern void OLED_P6x8Str(uint8_t  x,uint8_t y,uint8_t ch[]);
extern uint8_t Main_Menu(void);
extern uint8_t Main_UI(void);



#endif
