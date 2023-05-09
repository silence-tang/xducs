#include<stdio.h>
int jzcf(int m[100][100],int n[100][100],int result[100][100],int jieshu)//¾ØÕó³Ë·¨
{
	int i, j, k;
	for(i=0;i<jieshu;i++)  
	{   
		for(j=0;j<jieshu;j++)  
		{    
			for(k=0;k<jieshu;k++)    
			{     
				result[i][j]+=m[i][k]*n[k][j];  
			}   
		}  
	}
}

int main()
{
	int n,i,j,k;
	int a[100][100]={},b[100][100]={},result[100][100]={},sum[100][100]={};
	scanf("%d",&n);
	
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			scanf("%d",&a[i][j]);
	
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			b[i][j]=a[i][j];
			sum[i][j]=a[i][j];
		}
	}
	
	for(i=0;i<n-1;i++)
	{
		jzcf(a,b,result,n);
		
		for(j=0;j<n;j++)
		{
			for(k=0;k<n;k++)
			{
				b[j][k]=result[j][k];
				sum[j][k]=sum[j][k]+result[j][k];
			}
		}
	}
	
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{	
			if(sum[i][j]>0)
				sum[i][j]=1;
		}
	}
	
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			printf("%d ",sum[i][j]);
			if(j==n-1)
			printf("\n");
		}
	}
	
	return 0;

}
