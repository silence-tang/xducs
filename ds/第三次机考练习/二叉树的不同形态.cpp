#include<stdio.h>
#include<stdlib.h>

int ceng[100];
int zhon[100];

typedef struct node
{
	int data;
	struct node *left,*right;
}BiTree;

//�ú����ķ���ֵ�ǽṹ��ָ�����ͣ�����ֱ�ӷ���root���ǳ��ú��� 
BiTree *create(int cengl,int cengr,int zhonl,int zhonr)  //���Ҹ���һ�����������������ʱ 
{                                                        //��������������һ����һ�����ڵ� 
    if(zhonl>zhonr)                                      //�����ڲ��������ʱ��һ���ȳ��� 
		return NULL;                                     //����˳��������������һ�������ȷ��ֶ������ĸ��ڵ� 
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

//������� 
void PreOrderTraverse(BiTree *root)
{
    if (root != NULL)    //�ڵ�ǿյ������Ǳ���� 
	{
		printf("%d ", root->data);
        PreOrderTraverse(root->left);
        PreOrderTraverse(root->right);
    }
}

//������� 
void PostOrderTraverse(BiTree *root)
{
    if (root != NULL)    //�ڵ�ǿյ������Ǳ���� 
	{
        PostOrderTraverse(root->left);
        PostOrderTraverse(root->right);
        printf("%d ", root->data);
    }
}

//�������Ҵ�ӡҶ�ӽ�� 
void PrintLeaves(BiTree *root)
{
    if (root != NULL)    //�ڵ�ǿյ������Ǳ���� 
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
	PrintLeaves(root);      //��ӡҶ�ӽ�� 
	printf("\n");
	PreOrderTraverse(root); //������� 
	printf("\n");
	PostOrderTraverse(root);//������� 
	return 0;
 }
