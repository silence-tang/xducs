#include<stdio.h>
#include<stdlib.h>

typedef struct
{
    int coef;               //ϵ��
    int expn;               //ָ��
}Term;
typedef struct ploynomial
{
    Term term;
    ploynomial* next;
}ploynomial,*LinkList;

void InitList(LinkList &L)  //��ʼ������
{
    
    L=(ploynomial*)malloc(sizeof(ploynomial));  //ͷ���
    L->term.coef=0;
    L->term.expn=-1;
    L->next=NULL;
}

int cmp(Term a,Term b)
{
    //�ȽϽ���ϵ����С����
    if(a.expn>b.expn)
		return -1;
    else if(a.expn==b.expn)
		return 0;
    else
		return 1;
}

void insertNode(LinkList &L,Term e)
{
    //�����������ʽ������ʵ�λ�ã�����ͬʱ�𵽴�������Ͷ���ʽ��ӵĹ��� 
    ploynomial* q=L;
    while(q->next!=NULL)
    {
        if(cmp(q->next->term,e)>0) //�����ǰ���q����һ������ָ������Ҫ����Ľ���ָ�� 
            q=q->next;             //qָ����һ����� 
        else break;                //��ʱq.term.expn > e.expn >= q->next->term.expn
    }
    
    if(q->next!=NULL&&cmp(q->next->term,e)==0) //ָ����ͬ��ϵ����� 
        q->next->term.coef+=e.coef;
    else
    {
        ploynomial* node=(ploynomial*)malloc(sizeof(ploynomial));
        node->term.coef=e.coef;
        node->term.expn=e.expn;
        if(q->next==NULL)
            node->next=NULL; //���q���Ϊβ��㣬��node��ָ������ΪNULL
        else
            node->next=q->next; //����node��ָ����ָ��q����һ�����
        q->next=node;//��node������������
    }
}

void CreatPolyn(LinkList &L,int m)
{
    //����m���ϵ����ָ����������ʾһԪ����ʽ����������L
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
    //��L����L1+L2�Ľ��
    ploynomial* q;
    for(q=L1->next;q!=NULL;q=q->next)
        insertNode(L,q->term);          //��L1��ÿһ����뵽L��
        
    for(q=L2->next;q!=NULL;q=q->next) //��L2��ÿһ����뵽L��
        insertNode(L,q->term);
}

void SubtracatPolyn(LinkList &L,LinkList L1,LinkList L2)
{
    //��L����L1-L2�Ľ��
    ploynomial* q;
    for(q=L1->next;q!=NULL;q=q->next)
        insertNode(L,q->term);           //��L1��ÿһ����뵽L�� 
    
    for(q=L2->next;q!=NULL;q=q->next)
    {    q->term.coef=-(q->term.coef); //��ϵ������෴��,�ٽ�����Ӳ�������ΪL1-L2
        insertNode(L,q->term);           //��L2��ÿһ����뵽L��
    }
}

void visitList(LinkList L)
{
    //������ѧ���ʽ����ʽ��ӡ���һԪ����ʽL
    //��ָ������ϵ��Ϊ1�������ʡ��1
    ploynomial* q=L;                         //*��ͷ���*//
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
	
	if(flag==0)                              //�����������ʽ����0 
		printf("0");

    else                                     //����ʽ������0 
    {
    	q=L;
    	while(q->term.coef==0)
    	q=q->next;                           //��ʱqָ���һ�������� 
    	if(q->term.expn==0)
    	printf("%d",q->term.coef);
		else
		{
			if(q->term.coef==1||q->term.coef==-1)//�����һ��������ϵ��Ϊ��1����� 
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
        	else                                  //��һ��������ϵ����Ϊ��1����� 
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
				continue;                    //ϵ��Ϊ0�����
			//��������ϵ����Ϊ0����� 
        	//�Ѿ�������ָ��Ϊ0����� 
        	if(q->term.coef==1||q->term.coef==-1)//ϵ��Ϊ��1
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
			//ϵ���Ȳ�����1Ҳ������-1����� 
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
