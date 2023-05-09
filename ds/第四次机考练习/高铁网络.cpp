#include <stdio.h>
#include<algorithm>
#define MAXNUM 1000
using namespace std;
int Group[MAXNUM];			//��¼ͼ�нڵ��Ƿ񱻷��ʹ� 
int dist[MAXNUM][MAXNUM];	//ͨ���ڽӾ��󱣴�ͼ 

int DFS(int i,int n)
{
	int j;
	static int dgcs = 0;
	//���徲̬������¼�ݹ���� 
	//Ҫע����Ǳ���dgcs����������һ�δ���õ�ʱ�����㣬���ǻ����������ȥ 
	//�������ָ���ǵ�53�еĵ��ã�����ں����ڲ���Ƕ�׵��ã�С���ã����ԣ�
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
			dist[i][j] = 0;				//��ʼ���ڽӾ��󣬳�ʼֵΪ0 
		Group[i] = 0;					//ͬ�� 
	}
	scanf("%d %d", &n, &m);			    //��ȡͼ�Ľڵ���n���ͱ���m 
	int dgzcs[n],node_num[n];           //�ݹ���õ��ܴ�������ͨ�����еĽ������������鱣�棩 
	for(i = 0; i < m; i++)
	{
		scanf("%d %d", &p, &q);
		dist[p-1][q-1] = 1;		    	//����ڵ�1�ͽ�3���� ����dist[1][3]��dist[3][1]��ֵΪ1 
		dist[q-1][p-1] = 1;
	}
	
    k=0;
    j=0;
	for(i = 0; i < n; i++)
	{
		if(Group[i] != 1)
		{
			dgzcs[j]=DFS(i,n);
			k++;			        	   //ִ��һ��DFS����k��ֵ����1 
			j++;
		}
	}
	
	printf("%d\n", k-1);                     //�����ͨ��������-1 
	return 0;
}
