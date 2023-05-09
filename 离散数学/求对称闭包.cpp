#include<stdio.h>

int main()
{
	int zn,i,j;
	int a[200][200]={};
	scanf("%d",&n);
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			scanf("%d",&a[i][j]);
	
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(a[i][j]==1)
				a[j][i]=1;
		}
	}
	
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			printf("%d ",a[i][j]);
			if(j==n-1)
			printf("\n");
		}
	}
	
	return 0;

}
