#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    char data;
    struct node *lchild, *rchild;
}BiTNode,*BiTree;


//����ǰ������򴴽������� 
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

//��������ͺ��򴴽������� 
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

//ǰ����� 
void PreOrderTraverse(BiTNode *node)
{
    if (node != NULL)
	{
        printf("%c", node->data);
        PreOrderTraverse(node->lchild);
        PreOrderTraverse(node->rchild);
    }
}

//�������
void InOrderTraverse(BiTNode *node)
{
	if (node != NULL)
	{
        InOrderTraverse(node->lchild);
        printf("%c", node->data);
        InOrderTraverse(node->rchild);
    }
}

//������� 
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
    char *pre = str1;        //����char *���ַ�ָ�� 
    char *in = str2;
    char *post = str3;
    //char *pre = "ABCDEF";
    //char *in = "CBDAEF";
    //char *post = "CDBFEA";
    BiTNode *rootNode = createBinTreeByPreIn(pre, in, 3);   //���뺯�������ַ�ָ�� char *���� 
    
    printf("�������: ");
    PostOrderTraverse(rootNode);
    
    /*rootNode = createBinTreeByInPost(in, post, 6);
    printf("\n�������: ");
    PreOrderTraverse(rootNode);
    
    printf("\n�������: ");
    InOrderTraverse(rootNode);*/
    return 0;
}
