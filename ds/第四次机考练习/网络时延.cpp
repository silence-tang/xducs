#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#define MAX_VERtEX_NUM 20                       //顶点的最大个数 
#define VRType int                              //表示弧的权值的类型 
#define VertexType int                          //图中顶点的数据类型 
#define INFINITY 65535
using namespace std;

int yuandian;

typedef struct
{
    VertexType vexs[MAX_VERtEX_NUM];            //存储图中顶点数据 
    VRType arcs[MAX_VERtEX_NUM][MAX_VERtEX_NUM];//二维数组，记录顶点之间的关系
    int vexnum,arcnum;                          //记录图的顶点数和弧（边）数
}MGraph;
typedef int PathMatrix[MAX_VERtEX_NUM];         //用于存储最短路径中经过的顶点的下标
typedef int ShortPathTable[MAX_VERtEX_NUM];     //用于存储各个最短路径的权值和

//根据顶点本身数据，判断出顶点在二维数组中的位置
int LocateVex(MGraph *G,VertexType v)
{
    int i=0;
    //遍历一维数组，找到变量v
    for (; i<G->vexnum; i++)
	{
        if (G->vexs[i]==v)
		{
            break;
        }
    }
    //如果找不到，输出提示语句，返回-1
    if (i>G->vexnum)
	{
        printf("no such vertex.\n");
        return -1;
    }
    return i;
}
//构造有向网
void CreateUDG(MGraph *G)
{
    scanf("%d %d %d",&(G->arcnum),&(G->vexnum),&yuandian);
    for (int i=0; i<G->vexnum; i++)
	{
        G->vexs[i] = i;
		//scanf("%d",&(G->vexs[i]));
    }
    for (int i=0; i<G->vexnum; i++)
	{
        for (int j=0; j<G->vexnum; j++)
		{
            G->arcs[i][j]=INFINITY;  //初始化邻接矩阵 
        }
    }
    for (int i=0; i<G->arcnum; i++)
	{
        int v1,v2,w;
        scanf("%d %d %d",&v1,&v2,&w);
        int n=LocateVex(G, v1);
        int m=LocateVex(G, v2);
        G->arcs[n-1][m-1]=w;
    }
}
//迪杰斯特拉算法，v0表示有向网中起始点所在数组中的下标 
void ShortestPath_Dijkstra(MGraph G,int v0,PathMatrix *p,ShortPathTable *D)
{
    int final[MAX_VERtEX_NUM];//用于存储各顶点是否已经确定最短路径的数组
    //对各数组进行初始化
    for (int v=0; v<G.vexnum; v++)
	{
        final[v]=0;
        (*D)[v]=G.arcs[v0][v];
        (*p)[v]=0;
    }
    //由于以v0位下标的顶点为起始点，所以不用再判断
    (*D)[v0]=0;
    final[v0]=1;
    int k = 0;
    for (int i=0; i<G.vexnum; i++)
	{
        int min=INFINITY;
        //选择到各顶点权值最小的顶点，即为本次能确定最短路径的顶点
        for (int w=0; w<G.vexnum; w++)
		{
            if (!final[w]) {
                if ((*D)[w]<min)
				{
                    k=w;
                    min=(*D)[w];
                }
            }
        }
        //设置该顶点的标志位为1，避免下次重复判断
        final[k]=1;
        //对v0到各顶点的权值进行更新
        for (int w=0; w<G.vexnum; w++)
		{
            if (!final[w]&&(min+G.arcs[k][w]<(*D)[w]))
			{
                (*D)[w]=min+G.arcs[k][w];
                (*p)[w]=k;//记录各个最短路径上存在的顶点
            }
        }
    }
}

int main()
{
	int i,flag=0;
    MGraph G;
    CreateUDG(&G);
    PathMatrix P;
    ShortPathTable D;
    ShortestPath_Dijkstra(G, yuandian-1, &P, &D);  //D中保存源点到各结点最短路径长度，从D[0]开始 
    sort(D,D+G.vexnum);    //升序排列D数组
    //for(i=0;i<G.vexnum;i++)
    //	printf("%d ",D[i]);   //升序打印源点到各点的最短路径长*/
    for(i=0;i<G.vexnum;i++)
    {
    	if(D[i]==65535)
    	{
    		printf("-1");
    		flag=1;
    		break;
		}
	}
	if(flag == 0)
		printf("%d",D[G.vexnum-1]);
    return 0;
}
