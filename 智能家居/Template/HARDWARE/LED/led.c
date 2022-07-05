#include "led.h"
#include "usart_led.h"
#include "stm32f10x.h"

	void  LED_Init(void)
	{
		GPIO_InitTypeDef GPIO_InitStruct;
		
		RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB | RCC_APB2Periph_GPIOE,ENABLE);//时钟使能
		
		GPIO_InitStruct.GPIO_Mode = GPIO_Mode_Out_PP;
		GPIO_InitStruct.GPIO_Pin = GPIO_Pin_2;
		GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
		GPIO_Init(GPIOB,&GPIO_InitStruct);
		GPIO_SetBits(GPIOB,GPIO_Pin_2);//拉高电平
		
		GPIO_InitStruct.GPIO_Mode = GPIO_Mode_Out_PP;
		GPIO_InitStruct.GPIO_Pin = GPIO_Pin_5;
		GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
		GPIO_Init(GPIOE,&GPIO_InitStruct);
		GPIO_SetBits(GPIOE,GPIO_Pin_5);
	}	