#include <stdio.h>

int main()
{
	
	char x,y;	
	scanf("%c",&x);
	
	if(x>=65&&x<=90)
	{
	  y=x+32;
	  printf("%c",y);
	}
	 
	else if(x>=97&&x<=122)
	{
	 y=x-32;
	 printf("%c",y);
	}
	else
	printf("%c",x);
	
	return 0; 
	
	
 } 
