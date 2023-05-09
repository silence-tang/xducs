# include <stdio.h>

	double function(int n)
	{
		int i;
		double a = 2.0;
		
		double sum=2;
	
		for(i=1;i<=(n-1);i++)
		{
			a = 1.0+(1.0/a);
			sum=sum+a;
		}
		
		return(sum);
		
	}


int main()
{
	int n;
	double result;
	double function(int n);
	scanf("%d",&n);
    
    result = function(n);
    
    printf("%.2f",result);
    
    return 0;
    
 } 
