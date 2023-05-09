#include<stdio.h>
#include<stdlib.h>
#define MAXVEX 100
#define INF 65535

int num[MAXVEX] = {0}, low[MAXVEX];
int e[MAXVEX][MAXVEX];
int child, index;
int n, m;
int cnt;

int min(int a, int b)
{
	return a < b ? a : b;
}
	
void dfs(int cur, int father)
{
	int i;
	index++;
	num[cur] = index;
	low[cur] = index;
	child = 0;
	for(i = 1; i <= n; i++)
	{
		if(e[cur][i] == 1)
		{
			if(num[i] == 0)
			{
				child++;
				dfs(i, cur);
				low[cur] = min(low[cur], low[i]);
				if(low[i] > num[cur])
				{
					printf("%d %d\n",cur, i);
					cnt++;
				}
			}
			
			else if(i != father)
			{
				low[cur] = min(low[cur], num[i]);
			}		
		}
	}
}

int main()
{
	int i, j, x, y;
	scanf("%d%d",&n,&m); 
	for(i = 1; i <= n; i++ )
	{
		for(j = 1; j < n; j++ )
		{
			if(i == j)
				e[i][j] = 0;
			else
				e[i][j] = INF;	
		}
	}
	cnt = 0;
	index = 0;
	for(i = 1; i <= m; i++ )
	{
		scanf("%d %d",&x,&y);
		e[x][y] = 1;
		e[y][x] = 1;
	}
	dfs(1, 1);
	return 0;
}
