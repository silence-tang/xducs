#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef struct LNode
{
	int seq,cur_seq;
	struct LNode *next;
}LNode, *LinkList;

void CreatList(LinkList &L, int n)//���������� 
{
	L = (LinkList)malloc(sizeof(LNode));
	L->next=NULL;
	int i;
	LinkList p;
	for(i=1;i<=n;i++)
	{
		p = (LinkList)malloc(sizeof(LNode));
		p->seq = n+1-i;
		p->cur_seq = n+1-i;
		p->next = L->next;
		L->next = p;
	}
}

void TagList(LinkList &L)//�������еĽ���1��ʼ��� 
{
	int i=1;
	LinkList p;
	p = L;
	while(p->next)
	{
		p = p->next;
		p->cur_seq = i;
		i++;
	}
}

void DeleteList(LinkList &L, int i)//ɾ����� 
{
	LinkList p,q;
	p = L;
	while(p->next && p->next->cur_seq!=i)//Ѱ�ұ��Ϊi�Ľ�㣬����pָ���ɾ������ǰ�� 
		p = p->next;
	q = p->next;
	p->next = q->next;
	free(q);
}

void DispList(LinkList L, int n)//��ӡ���� 
{
	int i;
	LinkList p;
	p = L;
	for(i=1;i<=n;i++)
	{
		p = p->next;
		printf("%d ",p->seq);//��ӡ���ĳ�ʼ��� 
	}
}

int ListLength(LinkList L)//�������� 
{
	int i,num=0;
	LinkList p;
	p = L;
	while(p->next)
	{
		p = p->next;
		num++;
	}
	return num;
}

int main()
{
	LinkList L,p,q;
	int i,j,n,len;
	scanf("%d",&n);
	CreatList(L,n);
	p = L;
	i=1;	
	while(ListLength(L)>3)
	{
		if(i%2==1)     //����ʱ��������Ϊ��������ɾȥ���Ϊ2�ı����Ľ�� 
		{
			len = ListLength(L);
			for(j=1;j<=len;j++)
			{
				if(j%2==0)
					DeleteList(L,j);
			}
			TagList(L);//���ɾ����Ϻ����±�� 
		}
		
		if(i%2==0)     //����ʱ��������Ϊż������ɾȥ���Ϊ3�ı����Ľ�� 
		{
			len = ListLength(L);
			for(j=1;j<=len;j++)
			{
				if(j%3==0)
					DeleteList(L,j);
			}
			TagList(L);//���ɾ����Ϻ����±�� 
		}
		i++;
	}
	DispList(L,ListLength(L));
	return 0;
}
