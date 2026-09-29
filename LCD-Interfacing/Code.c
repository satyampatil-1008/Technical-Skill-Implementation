#include<reg51.h>
sbit RW=P3^0;
sbit RS=P3^1;
sbit EN=P3^2;
void LCD_CMD(unsigned int cmd);
void LCD_str(unsigned char *str);
void delay(unsigned int t);
void LCD_display(unsigned int text);
void main()
{
	RW=0;
	LCD_CMD(0x38);
	LCD_CMD(0x0E);
	while(1)
	{
		LCD_CMD(0x80);
		LCD_str("LCD");
		LCD_CMD(0xC0);
		LCD_str("INTERFACING");
		LCD_CMD(0x01);
	}
}
void LCD_CMD(unsigned int cmd)
{
	P2=cmd;
	RS=0;
	EN=1;
	delay(30);
	EN=0;
}
void LCD_str(unsigned char *str)
{
	unsigned int loop;
	for(loop=0;str[loop]!='\0';loop++)
	{
		LCD_display(str[loop]);
	}
}
void LCD_display(unsigned int text)
{
	P2=text;
	RS=1;
	EN=1;
	delay(30);
	EN=0;
}
void delay(unsigned int t)
{
	unsigned int i,j;
	for(i=0;i<t;i++)
	{
		for(j=0;i<1275;j++)
		{
		}
	}
}



