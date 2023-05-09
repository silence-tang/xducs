#include<stdio.h>
#include<queue>
using namespace std;
int visited1[100];     //����ȫ�ֱ������ʱ�����飬�Ա���DFS������ʹ��
int visited2[100];     //����ȫ�ֱ������ʱ�����飬�Ա���BFS������ʹ��
int a[100][100];       //�����ڽӾ��� 

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

void BFS(int n)    //BFS���ǵݹ��㷨 
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
			scanf("%d",&a[i][j]);  //�����ڽӾ��� 
	for(i = 0; i < n; i++)
	{
		if(visited1[i] != 1)
		{
			DFS(i,n);
			k++;			       //ִ��һ��DFS,k��ֵ����1,���kֵ��Ϊ��ͨ�������� 
		}
	}
	BFS(n);
	printf("\n%d",k);
	return 0;
}
