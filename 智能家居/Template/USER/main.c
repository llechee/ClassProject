#include "stm32f10x.h"
//#include "led.h"
#include "delay.h"
//#include "shake.h"
//#include "usart.h"
#include "sys.h"
//#include "car.h"
#include "exti.h"
//#include "usart_led.h"
//#include "usart_key.h"
//#include "timer.h"
#include "servo.h"
#include "pwm.h"
#include "infared.h"

void delay(uint16_t time)//毫秒级别
{
	long long i = 0;
	while(time--)
	{
		i = 1200;
		while(i--);
	}
}


//////////////////////////////////////////////////
//垃圾桶
int main()   
{	
	delay_init();
	servo_Init();	 //PWM初始化
    EXTIX_Init();
    TIM_SetCompare1(TIM3, 180);//合盖
	while(1)
	{
       // delay_ms(100);
		//TIM_SetCompare1(TIM3, 180);//合盖
	}
}
void EXTI2_IRQHandler(void)
{
	if(    EXTI_GetFlagStatus( EXTI_Line2) == SET   )	 	 
	{			EXTI_ClearITPendingBit(EXTI_Line2); //清除LINE8上的中断标志位
        if(GPIO_ReadInputDataBit( GPIOD,  GPIO_Pin_2) == 0 )   
        {            
		    TIM_SetCompare1(TIM3, 190);//开盖
            while(GPIO_ReadInputDataBit( GPIOD,  GPIO_Pin_2) == 0 );
            TIM_SetCompare1(TIM3, 180);//合盖
        }
     
         
	}  
}


/*
int main(void)  //车
{   
	
	delay_init();
	CAR_Init();
	//wheel1_go();
	
	GPIO_SetBits(GPIOE,GPIO_Pin_2);
	GPIO_ResetBits(GPIOE,GPIO_Pin_3);
}
*/

/*  int main()
{
	u16 led0pwmval=0;
	u8 dir=1;
	delay_init();
	LED_Init();
	PWM_Init(899,0);
	
	while(1)
	{
	delay_ms(10);
	if(dir)
		led0pwmval++;
	else
		led0pwmval--;
	
	if(led0pwmval>300)
		dir=0;
	if (led0pwmval==00)
		dir=1;
	
	TIM_SetCompare2(TIM3,led0pwmval);
	
	}

}*/


/*
int main()    //舵机
{	
	delay_init();
	servo_Init();	 //PWM初始化
    
	while(1)
	{
		TIM_SetCompare1(TIM3,195);//正向最大转速
		delay_ms(500);
		TIM_SetCompare1(TIM3,185);//速度为0
		delay_ms(500);
		TIM_SetCompare1(TIM3,175);//反向最大转速
		delay_ms(500);

		
		
		//delay_ms(100);
		TIM_SetCompare1(TIM3, 190);//开盖
		//delay_ms(100);
		//TIM_SetCompare1(TIM3, 180);//合盖

	}
}*/

/*int main()
{
		delay_init();
		LED_Init();
		Timer_Init(4999,7199);
	
	while(1){
	LED1=!LED1;
	delay_ms(200);
	}

}
*/

/*
int main()
{
    delay_init();	    	 //延时函数初始化	  
	
	//uart_init(115200);	 //串口初始化为115200
 	LED_Init();		  		//初始化与LED连接的硬件接口
	usart_key_Init();         	//初始化与按键连接的硬件接口
	//EXTIX_Init();	
}



	
void  EXTI0_IRQHandler(void)
	{
		if(EXTI_GetFlagStatus( EXTI_Line0) == SET )
		{
			if(GPIO_ReadInputData( GPIOA) == 1){
				
		  delay_ms(20);
		  GPIO_ResetBits(GPIOB,GPIO_Pin_5);
		  USART_SendData(USART1,'a');
			}
		}
		EXTI_ClearITPendingBit(EXTI_Line0);
	}
	
void  EXTI4_IRQHandler(void)
	{
		if(EXTI_GetFlagStatus( EXTI_Line4) == SET )
		{
		  delay_ms(20);
		  GPIO_ResetBits(GPIOE,GPIO_Pin_5);
		  USART_SendData(USART1,'b');
		}
		EXTI_ClearITPendingBit(EXTI_Line4);
	}
	
	*/



/*int main(void)
{
    //NVIC_PriorityGroupConfig( NVIC_PriorityGroup_2);
	usart_led_Init();	
	LED_Init();
	//void USART1_IRQHandler();
	while(1){}
}

void USART1_IRQHandler(void)
	{ 
	char a;
		
		
		if(USART_GetITStatus(USART1,USART_IT_RXNE))
		{a=USART_ReceiveData(USART1);
		   if(a == 'a')
			   GPIO_ResetBits(GPIOB,GPIO_Pin_5);
		   
		   else 
    		   GPIO_ResetBits(GPIOE,GPIO_Pin_5);
		
		}
		 
			
		 
		
		USART_ClearITPendingBit(USART1, USART_IT_RXNE);
	}*/
/*
int main(void)  //灯
{   
	
	delay_init();
	LED_Init();
	


while(1)
	{
		GPIO_SetBits(GPIOB,GPIO_Pin_2);//拉高电平
		GPIO_SetBits(GPIOE,GPIO_Pin_5);
		 delay_ms(5000);
		
		
		GPIO_ResetBits(GPIOB,GPIO_Pin_2);//拉低电平
		GPIO_ResetBits(GPIOE,GPIO_Pin_5);
		 delay_ms(5000);
		
	}
}
*/
/* int main(void)
 {		
 
	delay_init();	    	 //延时函数初始化	  
	
	uart_init(115200);	 //串口初始化为115200
 	LED_Init();		  		//初始化与LED连接的硬件接口
	SHAKE_Init();         	//初始化与按键连接的硬件接口
	EXTIX_Init(();		 	//外部中断初始化
*/





/*void EXTI4_IRQHandler(void)
	{ 
		//if(USART_GetITStatus(USART1,USART_IT_RXNE))
		if(EXTI_GetFlagStatus( EXTI_Line4) == SET )
		{
		  USART_SendData(USART1,'a');
		}
		EXTI_ClearITPendingBit(EXTI_Line4);
	}
*/








