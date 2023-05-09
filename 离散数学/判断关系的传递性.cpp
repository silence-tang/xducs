#include<stdio.h>

int main()
{
	int n,i,j,k,flag=1;
	int a[200][200]={};
	scanf("%d",&n);
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			scanf("%d",&a[i][j]);
	
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			for(k=0;k<n;k++)
			{
				if(a[i][j]!=0&&a[j][k]!=0&&a[i][k]==0)
				{
					flag = 0;
					break;	
				}
			}
		}
	}
	if(flag==1)
		printf("The matrix is transitive.");
	if(flag==0)
		printf("The matrix is not transitive.");
	return 0;
}
