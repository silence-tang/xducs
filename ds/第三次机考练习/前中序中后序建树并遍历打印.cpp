#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    char data;
    struct node *lchild, *rchild;
}BiTNode,*BiTree;


//根据前序和中序创建二叉树 
BiTNode *createBinTreeByPreIn(char *pre, char *in, int number)
{
    if(number == 0)
		return NULL;
    char c = pre[0];
    int i = 0;
    while(i < number && in[i] != c)
		i++;
    int leftNumber = i;
    int rightNumber = number - i - 1;
    BiTNode *node = (BiTNode *)malloc(sizeof(BiTNode));
    node->data = c;
    node->lchild = createBinTreeByPreIn(&pre[1], &in[0], leftNumber);
    node->rchild = createBinTreeByPreIn(&pre[leftNumber + 1], &in[leftNumber + 1], rightNumber);
    return node;
}

//根据中序和后序创建二叉树 
BiTNode *createBinTreeByInPost(char *in, char *post, int number)
{
    if(number == 0)
		return NULL;
    char c = post[number - 1];
    int i = 0;
    while(i < number && in[i] != c)
		i++;
    int leftNumber = i;
    int rightNumber = number - i - 1;
    BiTNode *node = (BiTNode *) malloc(sizeof(BiTNode));
    node->data = c;
    node->lchild = createBinTreeByInPost(&in[0], &post[0], leftNumber);
    node->rchild = createBinTreeByInPost(&in[leftNumber + 1], &post[leftNumber], rightNumber);
    return node;
}

//前序遍历 
void PreOrderTraverse(BiTNode *node)
{
    if (node != NULL)
	{
        printf("%c", node->data);
        PreOrderTraverse(node->lchild);
        PreOrderTraverse(node->rchild);
    }
}

//中序遍历
void InOrderTraverse(BiTNode *node)
{
	if (node != NULL)
	{
        InOrderTraverse(node->lchild);
        printf("%c", node->data);
        InOrderTraverse(node->rchild);
    }
}

//后序遍历 
void PostOrderTraverse(BiTNode *node)
{
    if (node != NULL)
	{
        PostOrderTraverse(node->lchild);
        PostOrderTraverse(node->rchild);
        printf("%c", node->data);
    }
}

int main()
{
	char str1[20],str2[20],str3[20];
	scanf("%s",str1);
	scanf("%s",str2);
	//scanf("%s",str3);
    char *pre = str1;        //这里char *是字符指针 
    char *in = str2;
    char *post = str3;
    //char *pre = "ABCDEF";
    //char *in = "CBDAEF";
    //char *post = "CDBFEA";
    BiTNode *rootNode = createBinTreeByPreIn(pre, in, 3);   //传入函数的是字符指针 char *类型 
    
    printf("后序遍历: ");
    PostOrderTraverse(rootNode);
    
    /*rootNode = createBinTreeByInPost(in, post, 6);
    printf("\n先序遍历: ");
    PreOrderTraverse(rootNode);
    
    printf("\n中序遍历: ");
    InOrderTraverse(rootNode);*/
    return 0;
}
