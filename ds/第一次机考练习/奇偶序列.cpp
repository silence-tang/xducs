#include<stdio.h>
int main()
{
	int i,n;
	scanf("%d",&n);
	int a[n+1];
	for(i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		if(i%2==1)
			printf("%d ",a[i]);
	}
	for(i=1;i<=n;i++)
	{
		if(i%2 == 0)
			printf("%d ",a[i]);
	}
	return 0;
} 
