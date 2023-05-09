#include<stdio.h>
#include<stdlib.h>
#define OK 1
#define ERROR 0

typedef struct LNode{
	int seq;
	int pw;
	struct LNode *next;
}LNode, *LinkList;       //�������Ա�ĵ�����˳��洢�ṹ 

void CreatList_DXXH(LinkList &L,int n){
	L = (LinkList)malloc(sizeof(LNode));
	L->next = L;         //�Ƚ���һ��ֻ��һ����ͷ��㡱�ĵ�ѭ������ 
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
	p->next = q->next;  //�����һ�����ݽ�����ӵ���һ�����ݽ���� 
	free(q);            //�ͷ�һ��ʼ�����ġ�ͷ��㡱
	//���ˣ�һ������ѭ����������� 
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
