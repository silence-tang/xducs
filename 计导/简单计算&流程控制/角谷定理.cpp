#include <stdio.h>
int main()
{
    int i=0;
    int n,k;
    scanf("%d",&n);
    while(n!=1)
    {  
        if(n%2==1)
	   {
	   	
	   	n=3*n+1;
	   	i++;
		} 
    
       else
        {
        	n=n/2;
        	i++;
		}
	}
	
	printf("%d",i);
	
	
	return 0;
	
	
} 
