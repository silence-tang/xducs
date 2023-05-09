#include<stdio.h>
#include<stdlib.h>

int ceng[100];
int zhon[100];

typedef struct node
{
	int data;
	struct node *left,*right;
}BiTree;

//该函数的返回值是结构体指针类型，可以直接返回root，是常用函数 
BiTree *create(int cengl,int cengr,int zhonl,int zhonr)  //当我给你一个二叉树的中序遍历时 
{                                                        //这个中序遍历遍历一定有一个根节点 
    if(zhonl>zhonr)                                      //体现在层序遍历上时它一定先出现 
		return NULL;                                     //所以顺序遍历层序遍历，一定可以先发现二叉树的根节点 
	BiTree *root = (BiTree *)malloc(sizeof(BiTree));
	int i,j,flag;
	for(i=0;i<=(cengr-cengl);i++)
	{
		flag=false;
		for(j=0;j<=(zhonr-zhonl);j++)
		{
			if(ceng[i+cengl]==zhon[j+zhonl])
			{
				flag=true;
				break;
			}
		}
		if(flag) break;
	}
		root->data=zhon[j+zhonl];                          
		root->left=create(cengl+i+1,cengr,zhonl,zhonl+j-1);
		root->right=create(cengl+i+1,cengr,zhonl+j+1,zhonr);  
		return root;
}

//先序遍历 
void PreOrderTraverse(BiTree *root)
{
    if (root != NULL)    //节点非空的条件是必须的 
	{
		printf("%d ", root->data);
        PreOrderTraverse(root->left);
        PreOrderTraverse(root->right);
    }
}

//后序遍历 
void PostOrderTraverse(BiTree *root)
{
    if (root != NULL)    //节点非空的条件是必须的 
	{
        PostOrderTraverse(root->left);
        PostOrderTraverse(root->right);
        printf("%d ", root->data);
    }
}

//从左往右打印叶子结点 
void PrintLeaves(BiTree *root)
{
    if (root != NULL)    //节点非空的条件是必须的 
	{
		if(root->left==NULL&&root->right==NULL)
			printf("%d ", root->data);
        PrintLeaves(root->left);
        PrintLeaves(root->right);
    }
}

int main()
{
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%d",&ceng[i]);
	for(int i=0;i<n;i++)
		scanf("%d",&zhon[i]);
	node* root=create(0,n-1,0,n-1);
	PrintLeaves(root);      //打印叶子结点 
	printf("\n");
	PreOrderTraverse(root); //先序遍历 
	printf("\n");
	PostOrderTraverse(root);//后序遍历 
	return 0;
 }
