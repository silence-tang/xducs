#include<stdio.h>
int main()
{
	int n,m,t,k;
	int i,j;
	int a[25][25];
	int b[2400]={0};
	int p=0;
	scanf("%d %d %d %d",&n,&m,&t,&k);
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			scanf("%d",&a[i][j]);
		}
	}
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			//p++;
			if(a[i][j]==k)
			{
				if(a[i-1][j]!=k)
				{b[p]=a[i-1][j];  p++;}
				if(a[i+1][j]!=k)
				{b[p]=a[i+1][j];  p++; }
				if(a[i][j-1]!=k)
				{b[p]=a[i][j-1];  p++; }
				if(a[i][j+1]!=k)
				{b[p]=a[i][j+1];  p++; }	
				
			}
			
			
		}
	}
	
//	printf("%d\n",p);
	
	int count=0;
	for(i=1;i<=t;i++)
	{
		for(j=0;j<=2400;j++)
		{
			if(b[j]==i&&b[j]!=k)
			{
				count++;
			//	printf("%d\n",b[j]);
				break;
			}	
		}
	}
	printf("%d",count);
	
	
	return 0;
}
