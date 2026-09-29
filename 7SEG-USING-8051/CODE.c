#include<reg51.h>
sbit digH=P1^0;
sbit digT=P1^1;
sbit digU=P1^2;
sbit extPulse=P3^5;
unsigned int setCode[10]={0XC0,0XF9,0XA4,0XB0,0X99,0X92,0X82,0XF8,0X80,0X90};
void display(unsigned int num);
void delay(unsigned int t);

void main()
{
	int count=0;
	extPulse=1;
	TMOD=0X50;
	TH1=0X00;
	TL1=0X00;
	TR1=1;
	while(1)
	{
		count=(TH1<<8)|TL1;
		if(count>>999){
			TH1=0X00;
			TL1=0X00;
			count=0;
		}
		display(count);
	}
}
void display(unsigned int num)
{
	unsigned int dH,dT,dU;
	dH=num/100;
	dT=(num/10)%10;
	dU=num%10;
	digH=0;digT=1;digU=1;
	P2=setCode[dH];
	delay(30);
	digH=1;digT=0;digU=1;
	P2=setCode[dT];
	delay(30);
	digH=1;digT=1;digU=0;
	P2=setCode[dU];
	delay(30);
}
void delay(unsigned int t)
 {
  unsigned int i,j;
		for(i=0;i<t;i++)
	 {
		 for(j=0;j<1275;j++)
		 {
		 }
	 }
 }
