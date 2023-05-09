#include<stdio.h>
int function(int n)
{
	int i,sum=0;
	while(n!=0)
	{

       i=n%10;

       n=n/10;

       sum+=i;

    }
	
	return(sum);
	
}

