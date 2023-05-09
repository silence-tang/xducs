#include <stdio.h>
#include <string.h>
char str1[30],str2[30];
int loc;        //静态数组中已经分配的结点个数 

struct Node
{
    Node *lChild;
    Node *rChild;
    char c;
}Tree[50];      //静态内存分配数组 

Node *creat()
{
    Tree[loc].lChild = Tree[loc].rChild = NULL;
    return &Tree[loc++];
}

void postOrder(Node *T)
{
    if(T->lChild != NULL)
        postOrder(T->lChild);
    if(T->rChild != NULL)
        postOrder(T->rChild);
    printf("%c",T->c);
}

Node *build(int s1,int e1,int s2,int e2)
{
    Node *ret = creat();
    ret->c = str1[s1];
    int rootIdx;
    for(int i = s2;i <= e2;i++)
    {
        if(str2[i] == str1[s1])
        {
            rootIdx = i;
            break;
        }
    }
    if(rootIdx != s2)
    {
        ret->lChild = build(s1 + 1,s1 + (rootIdx - s2),s2,rootIdx - 1);
    }
    if(rootIdx != e2)
    {
        ret->rChild = build(s1 + (rootIdx - s2) + 1,e1,rootIdx + 1,e2);
    }
    return ret;
}

int main()
{
	scanf("%s",str1);
	scanf("%s",str2);
    loc = 0;
    int L1 = strlen(str1);
    int L2 = strlen(str2);
    Node *T = build(0,L1 - 1,0,L2 - 1);
    postOrder(T);
    return 0;
}
