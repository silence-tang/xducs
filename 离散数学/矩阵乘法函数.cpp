#include <bits/stdc++.h>
using namespace std;
 
void mult(int a[][100], int b[][100], int c[][100], int n)
{
	int i,j,k;
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
		{
			c[i][j] = 0;
			for(k=0;k<n;k++)
			c[i][j] += a[i][k]*b[k][j];	
		}
		
}

int main()
{   
	int i,j,n;
	int a[100][100],b[100][100],c[100][100]={0};
	scanf("%d",&n);
    for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			scanf("%d",&a[i][j]);
    for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			scanf("%d",&b[i][j]);
    mult(a,b,c,n);
    for(i=0;i<n;i++)
		for(j=0;j<n;j++)
		{
			printf("%d ",c[i][j]);
			if(j==n-1)
			printf("\n"); 
		}

	return 0;
}
