#include<stdio.h>
int isprime(int n)
{
	int m,flag;
	if(n<=1)
	return 0;
	if(n>=2)
	{
	    for(m=2;m<n;m++)
	  { 
	     flag=-1;
	     if(n%m==0)
	     {
	     	flag=1;
	     	break;
		 }
	        
      }
		  if(flag==1)   return 1;
	      if(flag==-1)  return 0;
	}
	
}               //判断素数的函数，若是，返回1；若不是，返回0 
int main()
{
	int m=1,n;
	for(n=1;n<=m;n++)
	{
		int a,b;
		scanf("%d",&a);
		for(b=a-1;b>=2;--b)
			 if(isprime(b)==1&&isprime(a-b)==1)
				 break;
				printf("%d %d",a-b,b);
	}
		return 0;
}
