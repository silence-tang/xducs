#include<stdio.h>
int main()
{
	int m,n,i,j;
	int a[100][100],b[100][100];
	scanf("%d %d",&n,&m);
	for(i=0;i<n;i++)
      for(j=0;j<m;j++)
        {
		    scanf("%d",&a[i][j]);
			b[i][j]=a[i][j];
		}                   //把原始棋盘a复制给b 
	for(i=0;i<n;i++)
	{
		for(j=1;j<m-1;j++)
		{
			if(a[i][j]==a[i][j-1]&&a[i][j+1]==a[i][j])
			{
				b[i][j-1]=0;
				b[i][j];
				b[i][j+1]=0;
			}
		}
	}
	for(j=0;j<m;j++)
	{
		for(i=1;i<n-1;i++)
		{
			if(a[i-1][j]==a[i][j]&&a[i+1][j]==a[i][j])
			{
				b[i-1][j]=0;
				b[i][j]=0;
				b[i+1][j]=0;
			}
		}
	}
	
	for(i=0;i<n;i++)
      for(j=0;j<m;j++)
		{
			printf("%d ",b[i][j]);
			if(j==m-1) printf("\n");
		}
    return 0;
 } 
