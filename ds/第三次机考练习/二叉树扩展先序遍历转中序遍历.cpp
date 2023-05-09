#include <stdio.h>
#include <stdlib.h>

typedef struct BiTNode
{
    char data;
    struct BiTNode *lchild, *rchild;
}*BiTree;

/*void CreateBiTree(BiTree &T)
{
	char ch;
	scanf("%c",&ch);
	if(ch == '#')
		T = NULL;
	else
	{
		T = (BiTNode *)malloc(sizeof(BiTNode));
		T->data = ch;
		CreateBiTree(T->lchild);
		CreateBiTree(T->rchild);
	}
}*/

void CreateBiTree(BiTree &T)
{
	char c;
	scanf("%c",&c);
	if(c=='#')
		T=NULL;
	else
	{
		//���ڶ��庯��ʱ�Ѿ���T�����BiTree���͵�ָ����
		//�����ڷ���T�ռ������һ�в���Ҫ��дBiTree T�� 
		T = (BiTNode*)malloc(sizeof(BiTNode));
		T->data = c;
		CreateBiTree(T->lchild);
		CreateBiTree(T->rchild);
	}
}

int InOrderTraverse(BiTree T)
{
	if (T != NULL)
	{
        InOrderTraverse(T->lchild);
        printf("%c ", T->data);
        InOrderTraverse(T->rchild);
    }
    return 0;
}

int main()
{
	BiTree T;
	CreateBiTree(T);
	InOrderTraverse(T);
	return 0;
}
