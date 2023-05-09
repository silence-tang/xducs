#include<stdio.h>
#include<stdlib.h>
 
typedef struct
{
	unsigned int weight;
	unsigned int parent,lchild,rchild;	
}HTNode, *HuffmanTree;       //动态分配数组存储哈夫曼树 

int main()
{
	int c,f,n,m,min1,min2,i,j,k,S1,S2,WPL=0;
	scanf("%d",&n);
	m = 2 * n - 1;           //m为哈夫曼树总结点数 
	int w[n+1],path_len[n+1];
	for(i=1;i<=n;i++)
		scanf("%d",&w[i]);	 //w数组0号单元不用 
	HuffmanTree HT;          //定义指针HT的类型 
	HT = (HuffmanTree)malloc((m+1) * sizeof(HTNode));
	for(i=1; i<=n; i++)      //初始化叶子结点 
	{
		HT[i].weight = w[i];
		HT[i].parent = 0;
		HT[i].lchild = 0;
		HT[i].rchild = 0;
	}
	for(i=n+1;i<=m;i++)      //初始化其他结点 
	{
		HT[i].weight = 0;
		HT[i].parent = 0;
		HT[i].lchild = 0;
		HT[i].rchild = 0;
	}
	
	for(i=n+1;i<=m;i++)      //建立哈夫曼树 
	{
		for(j=1;j<=i-1;j++)
		{
			if(HT[j].parent==0)
			{
				min1 = HT[j].weight;
				break;
			}
		}
		
		for(j=1;j<=i-1;j++)
		{
			if(HT[j].weight<=min1 && HT[j].parent==0)
			{
				min1 = HT[j].weight;
				S1 = j;
			}
		}
		for(k=1;k<=i-1;k++)
		{
			if(HT[k].weight>=min1 && HT[k].parent==0 && k!=S1)
			{
				min2 = HT[k].weight;   //初始化min2 
				break;
			}
		}
		
		for(k=1;k<=i-1;k++)
		{
			if(HT[k].weight<=min2 && HT[k].weight>=min1 && HT[k].parent==0 && k!=S1)
			{
				min2 = HT[k].weight;
				S2 = k;	
			}
		}
		
		HT[S1].parent = i;  HT[S2].parent = i;
		HT[i].lchild = S1;  HT[i].rchild = S2;
		HT[i].weight = HT[S1].weight + HT[S2].weight;
	}
	
	for(i=1;i<=n;i++)         //求各个叶子结点的路径长度 
	{
		c = i;
		path_len[i] = -1;
		f = HT[c].parent;
		while(f!=0)
		{
			f = HT[c].parent;
			c = f;
			path_len[i]++;    //用数组保存n个叶子结点的路径长度 
		}
		WPL += path_len[i]*HT[i].weight;
	}
	printf("%d",WPL);
	return 0; 
}
