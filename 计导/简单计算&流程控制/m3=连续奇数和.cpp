#include<stdio.h>
int main()
{
	int n,i,k,a;
	scanf("%d",&n);
	a=n*n*n;
	for(i=7;i<=1000000;i=i+2)
	{
		if(a==n*(i-n+1))
	   {
	   	 for(k=n;k>=1;k--)
	   	 { 
			printf("%d ",(i-2*k+2));
	   	 
		 }
         break;
	   }	
	}
	
    return 0;
 } 
