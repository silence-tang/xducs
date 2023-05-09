#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;
 
struct Node
{
	int key, next;
}node[100000];

int main()
{
	int a,b,c,i,m,n,n1=0;
	int vis[100000],no1[100000];
	scanf("%d %d", &n,&m);
	memset(vis, 0, sizeof(vis));
	for(i = 0; i < m; i++)
	{
		scanf("%d %d %d", &a, &b, &c);
		node[a].key = b;
		node[a].next = c;
	}
	
	for(i = n; i != -1; i = node[i].next)
	{
		a = node[i].key;
		if(!vis[abs(a)])
		{
			vis[abs(a)] = 1;
			no1[n1++] = i;
		}
	}
	
	printf("%d\n",n1);
	for(int i = 0; i < n1; i++)
	{
		printf("%05d %d ", no1[i], node[no1[i]].key);
		if(i == n1-1)
			printf("-1\n");
		else printf("%05d\n", no1[i+1]);
	}
	
	return 0;
}
