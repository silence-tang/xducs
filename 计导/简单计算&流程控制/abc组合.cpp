# include<stdio.h>
int main()
{
	int n,i,a,b,c;
	scanf("%d",&n);
	
	for(i=100;i<=1000;i++)
	{
		a=i/100;
		b=(i/10)%10;
		c=i%10;
		
	    if(100*c+10*b+a==(n-i))
	    {
	    	printf("%d %d %d\n",a,b,c);
	    	
		}
		
		
	}
	
	return 0;
	
	
 } 
