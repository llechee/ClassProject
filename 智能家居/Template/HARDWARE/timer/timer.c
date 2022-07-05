#include "timer.h"
#include "led.h"
#include "sys.h"


void  Timer_Init(u16 arrr,u16 pscc)
{
	TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStruct;
	NVIC_InitTypeDef NVIC_InitStruct;
	
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3 ,ENABLE);
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_1);
	
	TIM_TimeBaseInitStruct.TIM_ClockDivision=TIM_CKD_DIV1 ;
	TIM_TimeBaseInitStruct.TIM_CounterMode=TIM_CounterMode_Up;
	TIM_TimeBaseInitStruct.TIM_Period=arrr;
	TIM_TimeBaseInitStruct.TIM_Prescaler=pscc;
	TIM_TimeBaseInit(TIM3,&TIM_TimeBaseInitStruct);


	TIM_ITConfig(TIM3, TIM_IT_Update ,ENABLE);
	
	NVIC_InitStruct.NVIC_IRQChannel = TIM3_IRQn ;
	NVIC_InitStruct.NVIC_IRQChannelCmd = ENABLE;
	NVIC_InitStruct.NVIC_IRQChannelPreemptionPriority = 1;
	NVIC_InitStruct.NVIC_IRQChannelSubPriority = 1;
	NVIC_Init(&NVIC_InitStruct);
	
	TIM_Cmd(TIM3, ENABLE);
}

/*
void TIM3_IRQHandler(void)
{
if( TIM_GetITStatus(TIM3, TIM_IT_Update)!=RESET )
	{
		LED0=!LED0;
		TIM_ClearITPendingBit(TIM3, TIM_IT_Update );
	}

}

*/

