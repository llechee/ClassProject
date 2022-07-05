#include "exti.h"
#include "led.h"
#include "shake.h"
#include "delay.h"
//#include "usart.h"
#include "stm32f10x.h"

void SHAKE_Init(void){
	
	//EXTIX_Init();
	
	GPIO_InitTypeDef io_init;
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);	
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOB,ENABLE);
	
	io_init.GPIO_Mode=GPIO_Mode_IPD;//��������
	io_init.GPIO_Pin = GPIO_Pin_4;
	io_init.GPIO_Speed=GPIO_Speed_50MHz;

}
//�ⲿ�жϷ������ 
void EXTI4_IRQHandler(void)
{
	delay_ms(10);//����
	if(    EXTI_GetFlagStatus( EXTI_Line4) == SET   )	 	 
	{				 
		GPIO_ResetBits(GPIOB,GPIO_Pin_5);
		GPIO_ResetBits(GPIOE,GPIO_Pin_5);
	}
	EXTI_ClearITPendingBit(EXTI_Line4); //���LINE4�ϵ��жϱ�־λ  
}


