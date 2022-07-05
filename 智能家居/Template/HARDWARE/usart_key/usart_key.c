#include "usart_key.h"
#include "stm32f10x.h"
#include "delay.h"


   //A0 E4 UNAVLUABLE
void usart_key_Init(void)
	{
        GPIO_InitTypeDef GPIO_InitStruct;
		EXTI_InitTypeDef EXTI_InitStructure;
		NVIC_InitTypeDef NVIC_InitStruct;
		
	    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);
		RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOE,ENABLE);
		NVIC_PriorityGroupConfig(NVIC_PriorityGroup_1);
	  
	
		GPIO_InitStruct.GPIO_Mode= GPIO_Mode_IPD;
		GPIO_InitStruct.GPIO_Pin=GPIO_Pin_0;
		//GPIO_InitStruct.GPIO_Speed=GPIO_Speed_50MHz;
		GPIO_Init( GPIOA, &GPIO_InitStruct);
		
	    GPIO_InitStruct.GPIO_Mode= GPIO_Mode_IPU;
		GPIO_InitStruct.GPIO_Pin=GPIO_Pin_4;
		//GPIO_InitStruct.GPIO_Speed=GPIO_Speed_50MHz;
		GPIO_Init( GPIOE, &GPIO_InitStruct);
		
		GPIO_EXTILineConfig(GPIO_PortSourceGPIOA,GPIO_PinSource0);
		EXTI_InitStructure.EXTI_Line=EXTI_Line0;	//KEY0
		EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;	
		EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Falling;
		EXTI_InitStructure.EXTI_LineCmd = ENABLE;
		EXTI_Init(&EXTI_InitStructure);	 
		
		GPIO_EXTILineConfig(GPIO_PortSourceGPIOE,GPIO_PinSource4);
		EXTI_InitStructure.EXTI_Line=EXTI_Line4;	//KEY0
		EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;	
		EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Falling;
		EXTI_InitStructure.EXTI_LineCmd = ENABLE;
		EXTI_Init(&EXTI_InitStructure);	 
		
		NVIC_InitStruct.NVIC_IRQChannel = EXTI0_IRQn | EXTI4_IRQn;
		NVIC_InitStruct.NVIC_IRQChannelCmd = ENABLE;
		NVIC_InitStruct.NVIC_IRQChannelPreemptionPriority = 0;
		NVIC_InitStruct.NVIC_IRQChannelSubPriority = 0;
		NVIC_Init(&NVIC_InitStruct);
		
		
		
	}


	