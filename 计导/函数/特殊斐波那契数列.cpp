#include <stdio.h>

int fib(int n)

{
	int F[10000]={7,11};
	int i,result;
	for(i=2;i<=n;i++)
	{
	   F[i]=F[i-1]+F[i-2];
	   result = F[i];
	}
	 return(result);
	
 } 
 
int main()
{
   int fib(int n);
   int n,result;
   scanf("%d",&n);
   result=fib(n);
   printf("%d",result);
   
   return 0;
	
	
}
