	#include "usart.h"
	#include "exti.h"
	#include "stm32f10x.h"


	void  USART1_Init(void)
	{
		GPIO_InitTypeDef GPIO_InitStruct;
		USART_InitTypeDef USART_InitStruct;
		
		
		RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);
		RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1,ENABLE);
		
		GPIO_InitStruct.GPIO_Mode = GPIO_Mode_AF_PP;
		GPIO_InitStruct.GPIO_Pin = GPIO_Pin_9;
		GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
		GPIO_Init(GPIOA, &GPIO_InitStruct);
		
		GPIO_InitStruct.GPIO_Mode = GPIO_Mode_IN_FLOATING;
		GPIO_InitStruct.GPIO_Pin = GPIO_Pin_10;
		GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
		GPIO_Init(GPIOA, &GPIO_InitStruct);
		
	
		USART_InitStruct.USART_BaudRate = 115200;
		USART_InitStruct.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
		USART_InitStruct.USART_Mode=USART_Mode_Rx | USART_Mode_Tx;
		USART_InitStruct.USART_Parity=USART_Parity_No;
		USART_InitStruct.USART_StopBits=USART_StopBits_1;
		USART_InitStruct.USART_WordLength=USART_WordLength_8b;
		USART_Init(USART1,&USART_InitStruct);
		
		USART_Cmd(USART1,ENABLE);	
		
		USART_ITConfig(USART1,USART_IT_RXNE,ENABLE);
		
	}

	
	
/*	void USART1_IRQHandler(void)
{
	u8 res;
	
	if(USART_GetITStatus(USART1,USART_IT_RXNE))
	{
	  res = USART_ReceiveData(USART1);
	  USART_SendData(USART1,res);
	}
	USART_ClearITPendingBit( USART1,  USART_IT_RXNE);
}
*/


















