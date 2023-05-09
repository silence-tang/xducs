#include<stdio.h>
#include<stdlib.h>
#define OK 1
#define ERROR 0

typedef struct LNode{
	int seq;
	int pw;
	struct LNode *next;
}LNode, *LinkList;       //定义线性表的单链表顺序存储结构 

void CreatList_DXXH(LinkList &L,int n){
	L = (LinkList)malloc(sizeof(LNode));
	L->next = L;         //先建立一个只有一个“头结点”的单循环链表 
	LinkList p,q;
	q = L;
	int i,password;
	for(i=1;i<=n;i++)
	{
		p = (LinkList)malloc(sizeof(LNode));
		scanf("%d",&password);
		p->seq = i;
		p->pw = password;
		L->next = p;
		L = p;
	}
	p->next = q->next;  //让最后一个数据结点链接到第一个数据结点上 
	free(q);            //释放一开始建立的“头结点”
	//至此，一个单向循环链表建立完毕 
}
void DisplaySeq(LinkList L, int n, int PW){
	LinkList p,q;
	int i,j,cur_pw,cur_seq;
	p = L;
	for(i=0;i<n;i++)
	{
		for(j=0;j<PW-1;j++)
			p = p->next;
		q = p->next;
		PW = q->pw;
		cur_seq = q->seq;
		printf("%d ",cur_seq);
		p->next = q->next;
		free(q);
	}
}

int main()
{
	LinkList L;
	int m,n;
	scanf("%d %d",&n,&m);
	CreatList_DXXH(L,n);
	DisplaySeq(L,n,m);
	return 0;
}
