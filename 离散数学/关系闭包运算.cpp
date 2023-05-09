#include<stdio.h>
int main()
{
	int m,i,j;
	int a[100][100],b[100][100]={0},c[100][100]={0};
	scanf("%d",&m);
	for(i=0;i<m;i++)
	{
		for(j=0;j<m;j++)
		{
			scanf("%d",&a[i][j]);
			b[i][j] = a[i][j];
			c[i][j] = a[i][j];
		}
			
	}
	
	for(i=0;i<m;i++)
		b[i][i] = 1;
			
	for(i=0;i<m;i++)
	{
		for(j=0;j<m;j++)
		{
			
			if(c[i][j]==1)
			c[j][i] = 1;
				
		}
		
	}
	
	printf("r(R):\n");
	for(i=0;i<m;i++)
		for(j=0;j<m;j++)
			{
				printf("%d ",b[i][j]);
				if(j==m-1)
				printf("\n");
			}	
			
	printf("s(R):\n");		
	for(i=0;i<m;i++)
		for(j=0;j<m;j++)
		{	
			printf("%d ",c[i][j]);
			if(j==m-1)
			printf("\n");
	    }
	return 0;
}
