#include<stdio.h>
int main()
{
	int i,a,b,sum;
	int m;
	for(i=0;i<=10000;i++)
	{
     	
		scanf("%d",&m);
		  if(m==0)
	      break;
		  a=m/90;
		  b=m%90;
		  if(b>60) b=60;
		  printf("%d ",sum=3*60*a+3*b);
	    
	     
	}
	return 0;
}

