#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#define MAX_VERtEX_NUM 20                       //����������� 
#define VRType int                              //��ʾ����Ȩֵ������ 
#define VertexType int                          //ͼ�ж������������ 
#define INFINITY 65535
using namespace std;

int yuandian;

typedef struct
{
    VertexType vexs[MAX_VERtEX_NUM];            //�洢ͼ�ж������� 
    VRType arcs[MAX_VERtEX_NUM][MAX_VERtEX_NUM];//��ά���飬��¼����֮��Ĺ�ϵ
    int vexnum,arcnum;                          //��¼ͼ�Ķ������ͻ����ߣ���
}MGraph;
typedef int PathMatrix[MAX_VERtEX_NUM];         //���ڴ洢���·���о����Ķ�����±�
typedef int ShortPathTable[MAX_VERtEX_NUM];     //���ڴ洢�������·����Ȩֵ��

//���ݶ��㱾�����ݣ��жϳ������ڶ�ά�����е�λ��
int LocateVex(MGraph *G,VertexType v)
{
    int i=0;
    //����һά���飬�ҵ�����v
    for (; i<G->vexnum; i++)
	{
        if (G->vexs[i]==v)
		{
            break;
        }
    }
    //����Ҳ����������ʾ��䣬����-1
    if (i>G->vexnum)
	{
        printf("no such vertex.\n");
        return -1;
    }
    return i;
}
//����������
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
            G->arcs[i][j]=INFINITY;  //��ʼ���ڽӾ��� 
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
//�Ͻ�˹�����㷨��v0��ʾ����������ʼ�����������е��±� 
void ShortestPath_Dijkstra(MGraph G,int v0,PathMatrix *p,ShortPathTable *D)
{
    int final[MAX_VERtEX_NUM];//���ڴ洢�������Ƿ��Ѿ�ȷ�����·��������
    //�Ը�������г�ʼ��
    for (int v=0; v<G.vexnum; v++)
	{
        final[v]=0;
        (*D)[v]=G.arcs[v0][v];
        (*p)[v]=0;
    }
    //������v0λ�±�Ķ���Ϊ��ʼ�㣬���Բ������ж�
    (*D)[v0]=0;
    final[v0]=1;
    int k = 0;
    for (int i=0; i<G.vexnum; i++)
	{
        int min=INFINITY;
        //ѡ�񵽸�����Ȩֵ��С�Ķ��㣬��Ϊ������ȷ�����·���Ķ���
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
        //���øö���ı�־λΪ1�������´��ظ��ж�
        final[k]=1;
        //��v0���������Ȩֵ���и���
        for (int w=0; w<G.vexnum; w++)
		{
            if (!final[w]&&(min+G.arcs[k][w]<(*D)[w]))
			{
                (*D)[w]=min+G.arcs[k][w];
                (*p)[w]=k;//��¼�������·���ϴ��ڵĶ���
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
    ShortestPath_Dijkstra(G, yuandian-1, &P, &D);  //D�б���Դ�㵽��������·�����ȣ���D[0]��ʼ 
    sort(D,D+G.vexnum);    //��������D����
    //for(i=0;i<G.vexnum;i++)
    //	printf("%d ",D[i]);   //�����ӡԴ�㵽��������·����*/
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
