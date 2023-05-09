# include <stdio.h>
int main()
{
	int a[10000]={1,1};
	int n,i,k,j,c;
	scanf("%d",&n);
	for(i=2;i<10000;i++)
	{
		a[i]=a[i-1]+a[i-2];
	
	}
	
	if(n==1)
	{ printf("1");}
	if(n==2)
	{printf("1");}
	
	for(j=2;j<a[n-1];j++)
	{
		if(a[n-1]%j==0)
	    break;
	    
	    else
	    {
		 if(j==a[n-1]-1)
		 c=1;
		}
	}
	
		if(c==1)
		{
			printf("yes");
		}
        else printf("%d",a[n-1]);

  return 0;
	
 } 
