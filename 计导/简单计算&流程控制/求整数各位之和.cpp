#include <stdio.h>

int main()
{
	
	int a,b,c,d,e;
	
	scanf("%d",&a);
	
	b=a/100;
	c=a%100/10;
	d=a%10;
	
	e=b+c+d;

	printf("%d",e);
	
	return 0; 
	
	
 } 
