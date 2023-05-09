#include<stdio.h>
int main()
{
	int i,k,c,m,n;
	int sum=0;
	scanf("%d %d",&m,&n);
	
	for(i=m;i<=n;i++)
	{
		for(k=2;k<i;k++)
		{
			if(i%k==0)
			break;
			else
			{
			  if(k==i-1)
			  c=1;
			  
			}
			
		}
		
		if(c==1)
		{
			sum=sum+(i*i);
			c=0;
		}
		
	}
	  printf("%d",sum);
	  return 0;
	
 } 
