#include <REGX52.H>
#include "Nixi.h"
#include "HTR.h"
#include "delay.h"
#include "key.h" 
//#include "motor.h"


typedef unsigned char  U8;       /* defined for unsigned 8-bits integer variable 	  无符号8位整型变量  */
typedef unsigned char u8;

unsigned char speed=65;
unsigned char code zheng[] = {0x09,0x08,0x0c,0x04,0x06,0x02,0x03,0x01};
unsigned char code fan[] = {0x01,0x03,0x02,0x06,0x04,0x0c,0x08,0x09};

extern U8  U8T_data_H,U8T_data_L,U8RH_data_H,U8RH_data_L;
extern u8 KeyValue;
u8 z=0;
u8 y;
U8 x;
   
void main()
{

    //  RH();//获取温度
      P2_7=1;
      P2_1=1;
  
     // KeyDown();	
    
     TMOD|=0X01;//选择为定时器0模式，工作方式1，仅用TR0打开启动。

	 TH0=0XFC;	//给定时器赋初值，定时1ms
	 TL0=0X18;	
	 ET0=1;//打开定时器0中断允许
	 EA=1;//打开总中断
	 TR0=1;//打开定时器		
     PT0=1;
    
    
	while(1)
	{	      
        /*控制空调开关*/
		 KeyDown();		   //按键判断函数
        //按键控制空调
		 if(KeyValue == 2)
             { P2_7 = 0;  }
         if(KeyValue == 3)
             { P2_7 = 1;  }
             
//        /*按键控制窗帘电机*/   
        if (KeyValue == 4 && KeyValue != 6){
			for(y=0;y<8;y++){
				P3 = zheng[y];
				delay1ms(speed);	
			}
            P3=0x00;
            KeyValue = 0;
		}
		if (KeyValue == 5 && KeyValue != 6){
			for(y=0;y<8;y++){
				P3 = fan[y];
				delay1ms(speed);
			}
            P3=0x00;
            KeyValue = 0;
	    }	

        
//        /*光电控制电机*/
        if (P2_1 == 1 && x!=1 )//hei
        {
          for(y=0;y<8;y++){
				P3 = fan[y];
				delay1ms(speed);}	
            P3=0x00;
            x=1;
        }
        
        else if(P2_1 != 1 && x!=1 )//liang
        {
			for(y=0;y<8;y++){
				P3 = zheng [y];
				delay1ms(speed);}
            P3=0x00;
           x=1;
        }
	}
}

 //数码管显示湿度、温度

    void Timer0() interrupt 1
 {
        Nixie(1,U8RH_data_H/10);
        Nixie(2,U8RH_data_H%10);

        Nixie(3,U8T_data_H/10);
        Nixie(4,U8T_data_H%10);   
    
        z++;
       if(z==10)
       {
           z=0;
           RH();//获取温度 
           P0 = 0x00;
       }
       
       if(U8T_data_H >20 && KeyValue !=3 )
        {
            P2_7 = 0; 
        }
        

	   TH0=0XE0;	//给定时器赋初值
   	   TL0=0X10;
        
    
}