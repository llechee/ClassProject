#include "car.h"
#include "stm32f10x.h"

	void CAR_Init(void)
	{
		GPIO_InitTypeDef GPIO_InitStruct;
		
		RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC | RCC_APB2Periph_GPIOE,ENABLE);//时钟使能
		
		GPIO_InitStruct.GPIO_Mode = GPIO_Mode_Out_PP;
		GPIO_InitStruct.GPIO_Pin = GPIO_Pin_7 | GPIO_Pin_8;
		GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
		GPIO_Init(GPIOC,&GPIO_InitStruct);

		GPIO_InitStruct.GPIO_Mode = GPIO_Mode_Out_PP;
		GPIO_InitStruct.GPIO_Pin = GPIO_Pin_2;
		GPIO_InitStruct.GPIO_Pin = GPIO_Pin_3;
		GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
		GPIO_Init(GPIOE,&GPIO_InitStruct);
		
		GPIO_ResetBits(GPIOC,GPIO_Pin_7 );
		GPIO_ResetBits(GPIOC,GPIO_Pin_8 );
		GPIO_ResetBits(GPIOE,GPIO_Pin_2);
		GPIO_ResetBits(GPIOE,GPIO_Pin_3);
	}
	

    
	void wheel1_go(void)
	{
		GPIO_ResetBits(GPIOC,GPIO_Pin_7);//拉低电平
		GPIO_SetBits(GPIOC,GPIO_Pin_8);
	}
