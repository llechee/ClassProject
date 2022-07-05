#include "infared.h"
#include "stm32f10x.h"


void infared_Init(void)
    {
        	
        GPIO_InitTypeDef io_init;
        
        RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOE,ENABLE);	
        GPIO_EXTILineConfig(GPIO_PortSourceGPIOE,ENABLE);
        
        io_init.GPIO_Mode =  GPIO_Mode_IPD;//œ¬¿≠ ‰»Î
        io_init.GPIO_Pin = GPIO_Pin_2;
        //io_init.GPIO_Speed = GPIO_Speed_50MHz;
        GPIO_Init( GPIOE, & io_init);

        
        
    }
 
