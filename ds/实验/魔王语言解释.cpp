#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX_SIZE 100

/* B(einxgz)B ---> tsaedsae,ezegexeneie,tsaedsae */

typedef struct node{       //链栈和链队列的结点定义 
    char data;
    struct node *next;
}*LinkStack,*QueueNode,StackNode,Queuenode;

typedef struct{
    QueueNode rear;
	QueueNode front;
}LinkQueue;

void InitStack(LinkStack &S)     //初始化栈 
{
    S=NULL;
}

void Push(LinkStack &S, char x)  //入栈 
{
	LinkStack p;
    p=(LinkStack)malloc(sizeof(StackNode));
    if(!p) exit(1);
    p->data=x;
    p->next=S;
    S=p;
}

int PoP(LinkStack &S, char &x)    //出栈 
{
	LinkStack p;
    if(S==NULL) return 0;
    x=S->data;
    p=S;
    S=S->next;
    free(p);
    return 1;
}

void InitQueue(LinkQueue &Q) //初始化队列 
{
    Q.front=Q.rear=(QueueNode)malloc(sizeof(Queuenode));
    if(!Q.front) exit(1);
    Q.front->next=NULL;
}

void EnQueue(LinkQueue &Q, char x)//进队列 
{
	QueueNode p;
    p=(QueueNode)malloc(sizeof(Queuenode));
    if(!p) exit(1);
    p->data=x;
    p->next=NULL;
    Q.rear->next=p;
    Q.rear=p;
}

int DeQueue(LinkQueue &Q, char &x)  //出队列 
{
    if(Q.front==Q.rear) return 0;    //队空 
    QueueNode p;
	p=Q.front->next;
    x=p->data;
    Q.front->next=p->next;
    if(Q.rear==p) Q.rear=Q.front;
    free(p);
    return 1;
}

int main()
{
    //char c;
    char str[MAX_SIZE];
    char data;
    LinkStack S;
    LinkQueue Q;
    InitQueue(Q);
    InitStack(S);
    int len;
    scanf("%s",&str);
    len=strlen(str);
    for(int j=len-1;j>=0;j--)  //数组自右向左逐一进栈
        Push(S,str[j]);
    while(PoP(S,data))//出栈操作 
    {
        if(data=='A')
            printf("sae");
        else if(data=='B')
            printf("tsaedsae");
        else if(data=='(')
        {
            char frontdata;
            while(data!=')')
            {
                PoP(S,data);
                EnQueue(Q, data);
            }
            DeQueue(Q,data); //出首元素 
            frontdata=data;
            while(DeQueue(Q, data))
            {
                Push(S,frontdata);
                Push(S,data);
            }
        }
        else if(data==')')
        {}
        else
            printf("%c",data);
    }
    return 0;
}
