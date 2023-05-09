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
	int m,n,k,i,j;
	int a[100][100]={},b[100][100]={},result[100][100]={};
	scanf("%d %d %d",&m,&n,&k);
	
	for(i=0;i<m;i++)
		for(j=0;j<n;j++)
			scanf("%d",&a[i][j]);
	
	for(i=0;i<n;i++)
		for(j=0;j<k;j++)
			scanf("%d",&b[i][j]);
	
	jzcf(a,b,result,n);
	
	for(i=0;i<m;i++)
	{
		for(j=0;j<k;j++)
		{
			if(result[i][j]>0)
				result[i][j]=1;
			printf("%d ",result[i][j]);
			if(j==k-1)
			printf("\n");
		}
	}
	
	return 0;

}
