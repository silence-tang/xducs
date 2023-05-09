#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef struct LNode
{
	int seq,cur_seq;
	struct LNode *next;
}LNode, *LinkList;

void CreatList(LinkList &L, int n)//创建单链表 
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

void TagList(LinkList &L)//给链表中的结点从1开始编号 
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

void DeleteList(LinkList &L, int i)//删除结点 
{
	LinkList p,q;
	p = L;
	while(p->next && p->next->cur_seq!=i)//寻找编号为i的结点，并让p指向待删除结点的前驱 
		p = p->next;
	q = p->next;
	p->next = q->next;
	free(q);
}

void DispList(LinkList L, int n)//打印链表 
{
	int i;
	LinkList p;
	p = L;
	for(i=1;i<=n;i++)
	{
		p = p->next;
		printf("%d ",p->seq);//打印结点的初始编号 
	}
}

int ListLength(LinkList L)//求链表长度 
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
		if(i%2==1)     //若此时链表结点数为奇数，则删去序号为2的倍数的结点 
		{
			len = ListLength(L);
			for(j=1;j<=len;j++)
			{
				if(j%2==0)
					DeleteList(L,j);
			}
			TagList(L);//结点删除完毕后重新编号 
		}
		
		if(i%2==0)     //若此时链表结点数为偶数，则删去序号为3的倍数的结点 
		{
			len = ListLength(L);
			for(j=1;j<=len;j++)
			{
				if(j%3==0)
					DeleteList(L,j);
			}
			TagList(L);//结点删除完毕后重新编号 
		}
		i++;
	}
	DispList(L,ListLength(L));
	return 0;
}
