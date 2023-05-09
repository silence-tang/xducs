#include<stdio.h>
int main()
{
	int a,n;
	int i=0;
	scanf("%d",&n);
	for(a=n;a>=1949;a--)
	{
		if(a%4==0&&a%100!=0||a%400==0)
		{
		printf("%d ",a);
		i++;		
		}
		if(i%5==0)
		printf("\n");
	 } 
	
   return 0;
 } 
