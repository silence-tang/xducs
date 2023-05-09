#include<stdio.h>
#include<stdlib.h>

typedef struct
{
    int coef;               //系数
    int expn;               //指数
}Term;
typedef struct ploynomial
{
    Term term;
    ploynomial* next;
}ploynomial,*LinkList;

void InitList(LinkList &L)  //初始化链表
{
    
    L=(ploynomial*)malloc(sizeof(ploynomial));  //头结点
    L->term.coef=0;
    L->term.expn=-1;
    L->next=NULL;
}

int cmp(Term a,Term b)
{
    //比较结点的系数大小函数
    if(a.expn>b.expn)
		return -1;
    else if(a.expn==b.expn)
		return 0;
    else
		return 1;
}

void insertNode(LinkList &L,Term e)
{
    //将结点插入多项式链表的适当位置，可以同时起到创建链表和多项式相加的功能 
    ploynomial* q=L;
    while(q->next!=NULL)
    {
        if(cmp(q->next->term,e)>0) //如果当前结点q的下一个结点的指数大于要插入的结点的指数 
            q=q->next;             //q指向下一个结点 
        else break;                //此时q.term.expn > e.expn >= q->next->term.expn
    }
    
    if(q->next!=NULL&&cmp(q->next->term,e)==0) //指数相同，系数相加 
        q->next->term.coef+=e.coef;
    else
    {
        ploynomial* node=(ploynomial*)malloc(sizeof(ploynomial));
        node->term.coef=e.coef;
        node->term.expn=e.expn;
        if(q->next==NULL)
            node->next=NULL; //如果q结点为尾结点，则node的指针域设为NULL
        else
            node->next=q->next; //否则node的指针域指向q的下一个结点
        q->next=node;//将node结点插入链表中
    }
}

void CreatPolyn(LinkList &L,int m)
{
    //输入m项的系数和指数，建立表示一元多项式的有序链表L
    Term e;
    int i; 
    InitList(L);
    for(i=1;i<=m;i++)
    {
        scanf("%d %d",&e.coef,&e.expn);
        insertNode(L,e);
    }
}

void addPolyn(LinkList &L,LinkList L1,LinkList L2)
{
    //用L返回L1+L2的结果
    ploynomial* q;
    for(q=L1->next;q!=NULL;q=q->next)
        insertNode(L,q->term);          //将L1的每一项插入到L中
        
    for(q=L2->next;q!=NULL;q=q->next) //将L2的每一项插入到L中
        insertNode(L,q->term);
}

void SubtracatPolyn(LinkList &L,LinkList L1,LinkList L2)
{
    //用L返回L1-L2的结果
    ploynomial* q;
    for(q=L1->next;q!=NULL;q=q->next)
        insertNode(L,q->term);           //将L1的每一项插入到L中 
    
    for(q=L2->next;q!=NULL;q=q->next)
    {    q->term.coef=-(q->term.coef); //把系数变成相反数,再进行相加操作，即为L1-L2
        insertNode(L,q->term);           //将L2的每一项插入到L中
    }
}

void visitList(LinkList L)
{
    //以类数学表达式的形式打印输出一元多项式L
    //即指数或者系数为1的情况下省略1
    ploynomial* q=L;                         //*无头结点*//
    int flag=0;
	while(q!=NULL)
	{
		if(q->term.coef!=0)
		{
			flag=1;
			break;
		}
		q=q->next;	
	}
	
	if(flag==0)                              //如果整个多项式等于0 
		printf("0");

    else                                     //多项式不等于0 
    {
    	q=L;
    	while(q->term.coef==0)
    	q=q->next;                           //此时q指向第一个非零项 
    	if(q->term.expn==0)
    	printf("%d",q->term.coef);
		else
		{
			if(q->term.coef==1||q->term.coef==-1)//处理第一个非零项系数为±1的情况 
        	{
            	if(q->term.expn==1)
				{
               		if(q->term.coef==1)
                   		printf("x");
                	else
             	      	printf("-x");
            	}
				else
				{
               		if(q->term.coef==1)
                    	printf("x^%d",q->term.expn);
                	else
                    	printf("-x^%d",q->term.expn);
            	}
        	}
        	else                                  //第一个非零项系数不为±1的情况 
        	{
        		if(q->term.expn==1)
				{
               		if(q->term.coef==1)
                   		printf("%dx",q->term.coef);
                	else
            	       	printf("%dx",q->term.coef);
            	}
            	else
            		printf("%dx^%d",q->term.coef,q->term.expn);
			}
		}
		
    	while(q->next!=NULL)
    	{
       		q=q->next;
        	if(q->term.coef==0) 
				continue;                    //系数为0不输出
			//以下讨论系数不为0的情况 
        	//已经不存在指数为0的情况 
        	if(q->term.coef==1||q->term.coef==-1)//系数为±1
        	{
            	if(q->term.expn==1)
				{
                	if(q->term.coef==1)
                   		printf("+x");
                	else
                   	printf("-x");
            	}
				else
				{
                	if(q->term.coef==1)
                    	printf("+x^%d",q->term.expn);
                	else
                    	printf("-x^%d",q->term.expn);
            	}
        	}
        	else
			//系数既不等于1也不等于-1的情况 
        	{
        		if(q->term.expn==1)
       	    	{ 
        			if(q->term.coef>0)
                		printf("+%dx",q->term.coef,q->term.expn);
            		else
                		printf("%dx",q->term.coef,q->term.expn);
				}
				else
				{
					if(q->term.coef>0)
                    	printf("+%dx^%d",q->term.coef,q->term.expn);
            		else
                    	printf("%dx^%d",q->term.coef,q->term.expn);
				}
			}
    	}
	}
}

int main()
{
    LinkList L1,L2,add,sub;
    int m,n,t;
    scanf("%d %d %d",&m,&n,&t);
    CreatPolyn(L1,m);
	CreatPolyn(L2,n);
    if(t==0)
    {
    	InitList(add);
    	addPolyn(add,L1,L2);
		visitList(add);
	}
    if(t==1)
    {
    	InitList(sub);
    	SubtracatPolyn(sub,L1,L2);
    	visitList(sub);
	}
	
    return 0;
}
