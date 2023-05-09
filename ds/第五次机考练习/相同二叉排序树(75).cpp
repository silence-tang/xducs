#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char a[50][200];//存放先序遍历序列 
int k1=0;

typedef struct BiTNode
{
    char data;
    struct BiTNode *lchild, *rchild;
}*BiTree;

//查找函数 
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

//插入函数 
int Insert(BiTree &T, BiTree &p, char n)
{
	if(!Search(T,n,NULL,p))     //查找不成功，代表树中没有相同元素 
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

//创建二叉排序树 
void CreateBiTree(BiTree &T, BiTree &p, char str[], int length)
{
	int i;
	for(i=0;i<length;i++)
		Insert(T,p,str[i]);
}

//先序遍历 
void PreOrderTraverse(BiTree T)
{
	static int m1=0;   //!!!如果不加静态变量标识符static，m会在每次递归的一开始被重置为0 
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
	BiTree T = NULL;                    //这里必须先置T为NULL 
	BiTree p;                           //辅助指针p，用于函数中 
	CreateBiTree(T,p,first,len);        //创建二叉树 
    PreOrderTraverse(T);                //遍历得到先序遍历数组，便于后续比较 
    k1++;                               //每次先序遍历结束后，二维数组的一维序号要+1
	while(scanf("%s",s) && strcmp(s,"0") != 0)
	{
		BiTree T1 = NULL;               //首先置T1为NULL 
		BiTree q;                       //辅助指针q，用于函数中 
		CreateBiTree(T1,q,s,len);       //创建二叉树 
    	PreOrderTraverse(T1);           //先序遍历得到先序遍历数组，便于后续比较 
    	k1++;                           //每次先序遍历结束后，二维数组的一维序号要+1
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
