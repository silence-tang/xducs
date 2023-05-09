#include<stdio.h>
#include<queue>
using namespace std;
int visited1[100];     //定义全局变量访问标记数组，以便在DFS函数中使用
int visited2[100];     //定义全局变量访问标记数组，以便在BFS函数中使用
int a[100][100];       //定义邻接矩阵 

void DFS(int i,int n)
{
	int j;
	visited1[i] = 1;
	for (j = 0; j < n; j++)
	{
		if(a[i][j] == 1 && visited1[j] == 0)
			DFS(j, n);
	}
}

void BFS(int n)    //BFS不是递归算法 
{
	queue<int>Q;
	int v,i,j,temp;
	for(v=0;v<n;v++)
	{
		if(visited2[v]==0)
		{
			visited2[v] = 1;
			printf("%d ",v+1);
			Q.push(v);
		}
		while(!Q.empty())
		{
			temp = Q.front();
			Q.pop();
			for(j=0;j<n;j++)
			{
				if(a[temp][j]==1&&visited2[j]==0)
				{
					visited2[j] = 1;
					printf("%d ",j+1);
					Q.push(j);
				}
			}
		}
	}
}

int main()
{
	int i, j, k=0, n;
	scanf("%d",&n);
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			scanf("%d",&a[i][j]);  //输入邻接矩阵 
	for(i = 0; i < n; i++)
	{
		if(visited1[i] != 1)
		{
			DFS(i,n);
			k++;			       //执行一次DFS,k的值自增1,最后k值即为连通分量个数 
		}
	}
	BFS(n);
	printf("\n%d",k);
	return 0;
}
