#include <stdio.h>
int main()
{
	int n,i,m;
	int a[1000]={5,11};
	
	scanf("%d",&n);
	
	for(i=2;i<=(n-1);i++)
	{
		a[i]=a[i-1]+a[i-2];
		m=a[i];
	
	}
		printf("%d ",m)£» 
	
return 0;	
 } 
