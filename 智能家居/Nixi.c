#include <REGX52.H>

///////////////延时函数
void Delay1ms()		//@11.0592MHz
{
	unsigned char i, j;

	i = 2;
	j = 199;
	do
	{
		while (--j);
	} while (--i);
}


//////////////段选
unsigned char NixieTable1[]={0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F};
unsigned char NixieTable2[]={0xAF,0x86,0xDB,0xCF,0xE6,0xED,0xFD,0x87,0xFF,0xEF};    
    

void Nixie(unsigned char location,number)
{
//////////////位选（38译码器）
    switch(location)
    {
          case 1: P2_4=0; P2_3=0;P2_2=0;break;
          case 2: P2_4=0; P2_3=0;P2_2=1;break;
          case 3: P2_4=0; P2_3=1;P2_2=0;break;
          case 4: P2_4=0; P2_3=1;P2_2=1;break;
          case 5: P2_4=1; P2_3=0;P2_2=0;break;
          case 6: P2_4=1; P2_3=0;P2_2=1;break;
          case 7: P2_4=1; P2_3=1;P2_2=0;break;
          case 8: P2_4=1; P2_3=1;P2_2=1;break;
    
    }
    
 
    
//////////////段选（16进制数）
    if(location == 6)
    {  P0 = NixieTable2[number]; }
    else
    {  P0 = NixieTable1[number]; }
   
    Delay1ms();
  //  P0 = 0x00;	//清屏
 
}