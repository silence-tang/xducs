#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef struct LNode
{
	int key,seq;
	struct LNode *next;
}LNode, *LinkList;

void CreatList(LinkList &L, int fstadd, int n)  //创建单链表 
{
	L = (LinkList)malloc(sizeof(LNode));
	L->next = fstadd;
	int i,add,data,next;
	LinkList p;
	for(i=1;i<=n;i++)
	{
		p = (LinkList)malloc(sizeof(LNode));
		printf("请输入：");
		scanf("%d %d %d",&add,&data,&next);
		p = add;
		p->key = data;
		p->next = next;
	}
}

void TagList(LinkList &L)
{
	int i=1;
	LinkList p;
	p = L;
	while(p->next)
	{
		p = p->next;
		p->seq = i;
		i++;
	}
}

void DeleteList(LinkList &L, int i)
{
	int j=0;
	LinkList p,q;
	p = L;
	while(p->next && j<i-1)   //寻找第i个结点，并让p指向待删除结点的前驱 
	{
		p = p->next;
		++j;
	}
	q = p->next;
	p->next = q->next;
	free(q);
}

void DispList(LinkList L, int n)
{
	int i;
	LinkList p;
	p = L;
	for(i=1;i<=n;i++)
	{
		p = p->next;
		printf("%d %d %d\n",p,p->key,p->next);
	}
}

int ListLength(LinkList L)
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
	int firstaddr,n;
	scanf("%d %d",&firstaddr,&n);
	CreatList(L,firstaddr,n);
	TagList(L);
	p = L;
	while(p->next)             //链表去重 
	{
		p=p->next;
		q=p;
		while(q->next)
		{
			q = q->next;
			if(abs(q->key) == abs(p->key))
			{
				DeleteList(L,q->seq);
			} 
		}
	}
	
	printf("%d\n",ListLength(L));
	DispList(L, ListLength(L));
	return 0;
}
