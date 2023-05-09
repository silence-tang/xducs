#include<stdio.h>
#include<stdlib.h>
int k=0, a[1000];

typedef struct BiTNode
{
    int data;
    struct BiTNode *lchild, *rchild;
}*BiTree;

//���Һ��� 
int Search(BiTree T, int n, BiTree f, BiTree &p)
{
	if(!T)
	{
		p=f;
		return 0;
	}
	else if(T->data == n)
	{
		p=T;
		return 1;
	}
	else if(T->data <= n)
		return Search(T->rchild,n,T,p);
	else
		return Search(T->lchild,n,T,p);
}

//���뺯�� 
int Insert(BiTree &T, BiTree &p, int n)
{
	if(!Search(T,n,NULL,p))     //���Ҳ��ɹ�����������û����ͬԪ�� 
	{
		BiTree s;
		s = (BiTree)malloc(sizeof(BiTNode));
		s->data = n;
		s->lchild=NULL;
		s->rchild=NULL;
		if(!p)
		{
			T=s;
			a[k] = -1;
			k++;
		}
			
		else if(p->data<n)
		{
			p->rchild=s;
			a[k] = p->data;
			k++;
		} 	
		else
		{
			p->lchild=s;
			a[k] = p->data;
			k++;
		}
		return 1;
	}
	else
		return 0;
} 

void CreateBiTree(BiTree &T,BiTree &p)
{
	int i, m, a[1000];
	scanf("%d",&m);
	for(i=0;i<m;i++)
	{
		scanf("%d",&a[i]);
		Insert(T,p,a[i]);
	}
}

//ǰ����� 
void PreOrderTraverse(BiTree T)
{
	if (T != NULL)
	{
		printf("%d ", T->data);
        PreOrderTraverse(T->lchild);
        PreOrderTraverse(T->rchild);
    }
}

//������� 
void InOrderTraverse(BiTree T)
{
	if (T != NULL)
	{
        InOrderTraverse(T->lchild);
        printf("%d ", T->data);
        InOrderTraverse(T->rchild);
    }
}

//������� 
void PostOrderTraverse(BiTree T)
{
    if (T != NULL)
	{
        PostOrderTraverse(T->lchild);
        PostOrderTraverse(T->rchild);
        printf("%d ", T->data);
    }
}

int main()
{
	int i;
	BiTree T=NULL,p;        //�����������TΪNULL 
	CreateBiTree(T,p);      //���ò��뺯������������ 
	for(i=0;i<k;i++)
    	printf("%d\n",a[i]);
    return 0;
}

