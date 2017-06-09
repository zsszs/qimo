#include "LPC11xx.h"
#include "uart.h"
#include "string.h"
#include "delay.h"
#include "ADC.h"
#include "oled.h"
#include "temp.h"
#include "stdio.h"
//#define UART_BPS  9600
static uint8_t Arrow = 3,KEY_=0;
//char  GcRcvBuf[20];
  uint32_t t;
	float k;
	float temp_value = 0;
float temp(void)
{
//  uint32_t t;
//	float k;
	uint32_t ulADCData;
	uint32_t i;
	uint32_t ulADCBuf;
	uint32_t res_value;
	UART_Init ();
	ADC_Init ();
	//OLED_Init();

	
    ulADCData=0;
    for(i=0;i<10;i++)
     {
			 LPC_ADC->CR |=(1<<24);
			 while((LPC_ADC ->DR[7]&0x80000000)==0);
			 LPC_ADC->CR |=(1<<24);
			 while((LPC_ADC ->DR[7]&0x80000000)==0);
			 ulADCBuf =LPC_ADC->DR[7];
			 ulADCBuf =(ulADCBuf >>6)&0x3ff;
			 ulADCData+=ulADCBuf ;
		 }	
    ulADCData=ulADCData/10;
		 

    ulADCData=(ulADCData*3300)/1024;
		res_value = ((ulADCData*10000)/(3300-ulADCData));
		 
		 
	if((res_value<33970)&&(res_value>20310))  //0-10
	{
			k = 1366;
		  t = (33970-res_value)/k;
	}		
	else if ((res_value<20310)&&(res_value>12570)) //10-20
	{
			k = 774;
		  t = (20310-res_value)/k+10;
	}
	else if ((res_value<12570)&&(res_value>8034)) //20-30
	{
			k = 453.7;
		  t = ((12570-res_value)/k)+20;
	}
	else if ((res_value<8034)&&(res_value>5298))  //30-40
	{
			k = 273.7;
		  t = ((8034-res_value)/k)+30;
	}
	else if ((res_value<5298)&&(res_value>3586))  //40-50
	{
			k = 171.7;
		  t = ((5298-res_value)/k)+40;
	}
	else if ((res_value<3586)&&(res_value>2484))  //50-60
	{   k = 110.2;
		  t = ((3586-res_value)/k)+50;
	}

//if( (res_value<29371)&&(res_value>18680) )  // 0~10???
//		{
//			 k = 1069;
//       t = ((29370-res_value)/k)+0;
//		}
//		
//		else if( (res_value<18681)&&(res_value>12240) ) // 10~20
//     {
//       k = 644;
//       t = ((18680-res_value)/k)+7;
//     }
//	 
//    else if( (res_value<12241)&&(res_value>8221) ) // 20~30
//     {
//        k = 402;
//        t = ((12240-res_value)/k)+17;
//     }
//		 
//    else if( (res_value<8222)&&(res_value>5648) ) // 30~40
//     {
//        k = 250;
//        t = ((8221-res_value)/k)+28;
//     }
//		 
//    else if( (res_value<5649)&&(res_value>3958) ) // 40~50
//     {
//        k = 169;
//        t = ((5648-res_value)/k)+40;
//     }
//		 
//		 else if( (res_value<3958)&&(res_value>2832) ) // 50~60
//     {
//        k = 113;
//        t = ((3957-res_value)/k)+50;
//     }
//		 
//		 
//		 else if( (res_value<2832)&&(res_value>2047) ) // 60~70
//     {
//        k = 76;
//        t = ((2831-res_value)/k)+60;
//     }
//		 
//		 
//		 else if( (res_value<2047)&&(res_value>1506) ) // 70~80
//     {
//        k = 54;
//        t = ((2046-res_value)/k)+70;
//     }		 

	
    //sprintf (GcRcvBuf,"temp=%f C\r\n", t);
	  //UART_SendStr(GcRcvBuf);
	  //OLED_Print(1,3,GcRcvBuf);
	  return t;
	}
void Value_Setting(void) 

 {
	
          while(1)
          {
            //OLED_Write_Number(40,3,t);
            if((LPC_GPIO3->DATA&(1<<0))==0 )                
            {
                t++;
            }
        
            if((LPC_GPIO3->DATA&(1<<1))==0)               
            {
                t--;
            }
					}
}
			
		
			