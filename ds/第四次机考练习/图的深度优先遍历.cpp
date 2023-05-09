#include<stdio.h>
int visited[100];     //������ʱ������ 
int a[100][100];      //�����ڽӾ��� 
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
			scanf("%d",&a[i][j]);  //�����ڽӾ��� 
    k=0;
	for(i = 0; i < n; i++)
	{
		if(visited[i] != 1)
		{
			DFS(i,n);
			k++;			       //ִ��һ��DFS,k��ֵ����1,���kֵ��Ϊ��ͨ�������� 
		}
	}
	printf("\n%d",k);
	return 0;
}
