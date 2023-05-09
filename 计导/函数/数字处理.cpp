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

int main()

{
    int function(int n);
    int i,n,sum;
    scanf("%d",&n);
    sum=n;
    for(i=1;i<=1000;i++)
     {
     	
     	sum=function(sum);
     	if(sum<=9)
     	{
     	   printf("%d",sum);
     	   break;
		}
        
     	
	 }
    
    return 0;

}
