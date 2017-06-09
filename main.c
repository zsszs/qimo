
#include "LPC11xx.h"
#include "uart.h"
#include "delay.h"
#include "ADC.h"
#include "oled.h"
#include "ui.h"
#include "Key.h"
#include "temp.h"
#include "Init.h"
#include <stdio.h>
#include <string.h>
extern uint8_t LOGO_Phantom[];
//extern float  temp(void); 
int main()
{ 
	key_init();
	UART_Init ();
	ADC_Init ();
	OLED_Init();
  System_Init();
	while(1)
	{ 
		temp();   
	 Main_UI();		
	}

	}
