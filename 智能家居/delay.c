#include <REGX52.H>

void Delay18ms()		//@11.0592MHz
{
	unsigned char i, j;

	i = 194;
	j = 161;
	do
	{
		while (--j);
	} while (--i);
}

    
  
 void  Delay_10us(void)
      {
       unsigned char i;
        i--;
        i--;
        i--;
        i--;
        i--;
        i--;
       }
      
       
 void Delay100us( )		//@11.0592MHz,—” ±100Œ¢√Î
{
	unsigned char i, j;

	i = 2;
	j = 15;
	do
	{
		while (--j);
	} while (--i);
}


void delay1ms(unsigned char t){
	char i;
	while(t--){
	 	for(i=0;i<113;i++);
	}
}
