#include<stdio.h>
int visited[100];     //定义访问标记数组 
int a[100][100];      //定义邻接矩阵 
void DFS(int i,int n)
{
	int j;
	visited[i] = 1;
	printf("%d ",i+1);
	for(j = 0; j < n; j++)
	{
		if(a[i][j] == 1&&visited[j]==0)
			DFS(j, n);
	}
}

int main()
{
	int i, j, k, n;
	scanf("%d",&n);
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			scanf("%d",&a[i][j]);  //输入邻接矩阵 
    k=0;
	for(i = 0; i < n; i++)
	{
		if(visited[i] != 1)
		{
			DFS(i,n);
			k++;			       //执行一次DFS,k的值自增1,最后k值即为连通分量个数 
		}
	}
	printf("\n%d",k);
	return 0;
}
