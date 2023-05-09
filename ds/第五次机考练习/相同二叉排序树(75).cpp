#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char a[50][200];//�������������� 
int k1=0;

typedef struct BiTNode
{
    char data;
    struct BiTNode *lchild, *rchild;
}*BiTree;

//���Һ��� 
int Search(BiTree T, char n, BiTree f, BiTree &p)
{
	if(!T)
	{
		p=f;
		return 0;
	}
	else if(T->data-'0' == n-'0')
	{
		p=T;
		return 1;
	}
	else if(T->data-'0' <= n-'0')
		return Search(T->rchild,n,T,p);
	else
		return Search(T->lchild,n,T,p);
}

//���뺯�� 
int Insert(BiTree &T, BiTree &p, char n)
{
	if(!Search(T,n,NULL,p))     //���Ҳ��ɹ�����������û����ͬԪ�� 
	{
		BiTree s;
		s = (BiTree)malloc(sizeof(BiTNode));
		s->data = n;
		s->lchild=NULL;
		s->rchild=NULL;
		if(!p)
			T=s;
		else if(p->data-'0'<n-'0')
			p->rchild=s;
		else
			p->lchild=s;
		return 1;
	}
	else
		return 0;
} 

//�������������� 
void CreateBiTree(BiTree &T, BiTree &p, char str[], int length)
{
	int i;
	for(i=0;i<length;i++)
		Insert(T,p,str[i]);
}

//������� 
void PreOrderTraverse(BiTree T)
{
	static int m1=0;   //!!!������Ӿ�̬������ʶ��static��m����ÿ�εݹ��һ��ʼ������Ϊ0 
	if (T != NULL)
	{
		a[k1][m1] = T->data;
		m1++;
        PreOrderTraverse(T->lchild);
        PreOrderTraverse(T->rchild);
    }
}

int main()
{
	int i, j, n, len, flag;
	char first[10], s[10];
	scanf("%d",&n);
	scanf("%s",first);
	len = strlen(first); 
	BiTree T = NULL;                    //�����������TΪNULL 
	BiTree p;                           //����ָ��p�����ں����� 
	CreateBiTree(T,p,first,len);        //���������� 
    PreOrderTraverse(T);                //�����õ�����������飬���ں����Ƚ� 
    k1++;                               //ÿ��������������󣬶�ά�����һά���Ҫ+1
	while(scanf("%s",s) && strcmp(s,"0") != 0)
	{
		BiTree T1 = NULL;               //������T1ΪNULL 
		BiTree q;                       //����ָ��q�����ں����� 
		CreateBiTree(T1,q,s,len);       //���������� 
    	PreOrderTraverse(T1);           //��������õ�����������飬���ں����Ƚ� 
    	k1++;                           //ÿ��������������󣬶�ά�����һά���Ҫ+1
	}
	for(i=1;i<k1;i++)
	{
		flag = 1;
		for(j=len*i;j<len*i+len-1;j++)
		{
			if(a[i][j] != a[0][j-len*i])
			{
				flag = 0;
				break;
			}
		}
		if(flag == 1)
			printf("YES\n");
		else
			printf("NO\n");
	}
    return 0;
}
