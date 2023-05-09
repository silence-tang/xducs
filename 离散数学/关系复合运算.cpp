#include<stdio.h>
int main()
{
	int m,n,o;
	scanf("%d %d %d",&m,&n,&o);
	int i,j,k,a[100][100]={0},b[100][100]={0},c[100][100]={0};
	for(i=0;i<m;i++)
		for(j=0;j<n;j++)
			scanf("%d",&a[i][j]);
			
	for(i=0;i<n;i++)
		for(j=0;j<o;j++)
			scanf("%d",&b[i][j]);
	
	for(i=0;i<m;i++)
	{
		for(j=0;j<o;j++)
		{
			for(k=0;k<n;k++)
			{
				c[i][j] +=a[i][k]*b[k][j];
					
			}
				
		}
		
	}	
	for(i=0;i<m;i++)
		for(j=0;j<o;j++)
			{
				printf("%d ",c[i][j]);
				if(j==o-1)
				printf("\n");
				
			}
			
	return 0;
} 
