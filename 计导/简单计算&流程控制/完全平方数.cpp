#include <stdio.h>
int main()
{
    int n,m;
    scanf("%d",&n);
    for(m=0;m<=1000000;m++)
    {
    	if(m*m==n)
    	{  
		  printf("%d",m);
    	
    	  break;
		}
		
		
	}
     
		  if(m>n)
	      printf("no"); 
    return 0;
}
