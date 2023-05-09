# include <stdio.h>
int main()
{
	int i,j,flag;
	printf("2\n");
		for(i=3;i<=1000;i++)
	  {
	  	
	  	  for(j=2;j<=i/2;j++)
	  	{
	  		if(i%j!=0)
		    flag=1;
		    else
			{
				flag=0;
				break;
			}	  
			
	  	}	
	  	if(flag==0) continue;
	  	else printf("%d\n",i);	
      }
    return 0;	
 } 
