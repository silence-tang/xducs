#include <iostream>
#include <cstring>
using namespace std;

void jzdm(int n,int t,int p[][100])
{
	
	int i,j,k,temp=0;
	int q[n][n], res[n][n];
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
 		{
			q[i][j]=p[i][j];
 			res[i][j]=p[i][j];
		}

 	while(t-1!=0)
	{
 		for(i=0;i<n;i++)
 		{
 			for(j=0;j<n;j++)
 			{
 				for(k=0;k<n;k++)
 				{temp += q[i][k] * p[k][j];}
 				res[i][j]=temp;
 				temp=0;
 			}
 		}
 		
 	memcpy(q,res,sizeof(res));
	t--;
 	}

	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
    	{
			printf("%d ",res[i][j]);
			if(j==n-1)
			printf("\n");
 		}
	}
	
}

int main()
{
	int n,i,j,a[100][100];
	scanf("%d",&n);
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			scanf("%d",&a[i][j]);
			
	jzdm(n,6,a);//示例，求矩阵a的三次幂 
	return 0;
}
