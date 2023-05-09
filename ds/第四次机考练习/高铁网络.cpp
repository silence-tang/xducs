#include <stdio.h>
#include<algorithm>
#define MAXNUM 1000
using namespace std;
int Group[MAXNUM];			//记录图中节点是否被访问过 
int dist[MAXNUM][MAXNUM];	//通过邻接矩阵保存图 

int DFS(int i,int n)
{
	int j;
	static int dgcs = 0;
	//定义静态变量记录递归次数 
	//要注意的是变量dgcs并不会在下一次大调用的时候清零，而是会继续叠加下去 
	//（大调用指的是第53行的调用，相对于函数内部的嵌套调用（小调用）而言）
	Group[i] = 1;
	dgcs++;
	for (j = 0; j < n; j++)
	{
		if (dist[i][j] == 1)
		{
			if (Group[j] != 1)
			{
				DFS(j, n);
			}
		}
	}
	return dgcs;
}

int main()
{
	int i, j, k, n, m, p, q = 0;
	for(i = 0; i < MAXNUM; i++)
	{
		for(j = 0; j < MAXNUM; j++)
			dist[i][j] = 0;				//初始化邻接矩阵，初始值为0 
		Group[i] = 0;					//同上 
	}
	scanf("%d %d", &n, &m);			    //获取图的节点数n，和边数m 
	int dgzcs[n],node_num[n];           //递归调用的总次数和连通分量中的结点个数（用数组保存） 
	for(i = 0; i < m; i++)
	{
		scanf("%d %d", &p, &q);
		dist[p-1][q-1] = 1;		    	//如果节点1和节3相连 则令dist[1][3]和dist[3][1]的值为1 
		dist[q-1][p-1] = 1;
	}
	
    k=0;
    j=0;
	for(i = 0; i < n; i++)
	{
		if(Group[i] != 1)
		{
			dgzcs[j]=DFS(i,n);
			k++;			        	   //执行一次DFS就是k的值自增1 
			j++;
		}
	}
	
	printf("%d\n", k-1);                     //输出连通分量个数-1 
	return 0;
}
