#include<stdio.h>
#include<math.h>
#include<stdlib.h>
int func(int n)
{
    int j,k,i;
	    for(j=1;j<=100000;j++)
	   {
		 n=n/10;
		 k=j;
	     if(n==0)
	     break;
       } 
       return(k);
       
} 
int main()
{
	int func(int n);
	int n,dig;
	scanf("%d",&n);
	dig=func(n);
	printf("%d",dig);
	
	return 0;
	
}
