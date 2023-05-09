#include<stdio.h>
#include<stdlib.h>
 
typedef struct
{
	unsigned int weight;
	unsigned int parent,lchild,rchild;	
}HTNode, *HuffmanTree;       //��̬��������洢�������� 

int main()
{
	int c,f,n,m,min1,min2,i,j,k,S1,S2,WPL=0;
	scanf("%d",&n);
	m = 2 * n - 1;           //mΪ���������ܽ���� 
	int w[n+1],path_len[n+1];
	for(i=1;i<=n;i++)
		scanf("%d",&w[i]);	 //w����0�ŵ�Ԫ���� 
	HuffmanTree HT;          //����ָ��HT������ 
	HT = (HuffmanTree)malloc((m+1) * sizeof(HTNode));
	for(i=1; i<=n; i++)      //��ʼ��Ҷ�ӽ�� 
	{
		HT[i].weight = w[i];
		HT[i].parent = 0;
		HT[i].lchild = 0;
		HT[i].rchild = 0;
	}
	for(i=n+1;i<=m;i++)      //��ʼ��������� 
	{
		HT[i].weight = 0;
		HT[i].parent = 0;
		HT[i].lchild = 0;
		HT[i].rchild = 0;
	}
	
	for(i=n+1;i<=m;i++)      //������������ 
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
				min2 = HT[k].weight;   //��ʼ��min2 
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
	
	for(i=1;i<=n;i++)         //�����Ҷ�ӽ���·������ 
	{
		c = i;
		path_len[i] = -1;
		f = HT[c].parent;
		while(f!=0)
		{
			f = HT[c].parent;
			c = f;
			path_len[i]++;    //�����鱣��n��Ҷ�ӽ���·������ 
		}
		WPL += path_len[i]*HT[i].weight;
	}
	printf("%d",WPL);
	return 0; 
}
