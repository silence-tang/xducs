#include<stdio.h>
int main()
	{
		int a,b,c,d,e,f,s;
		scanf("%d",&s);
		a=s/100;
		b=(s%100)/50;
		c=(s%50)/20;
		d=((s%50)%20)/10;
		e=(s%10)/5;
		f=(s%5)/1;
		printf("%d %d %d %d %d %d",a,b,c,d,e,f);
		return 0;
	}
