#include<stdio.h>
#include<stdlib.h>

struct node                             //定义一个节点的结构体 
{
	int num;
	int age;                            //定义一个节点的数据域，有两个变量num和age 
	struct node *next;                  //定义一个节点的指针域，该指针变量的值为下一个节点的首地址 
};

struct node *creat(int n)               //指针函数：建立一个含有n个节点的链表
{
	
	struct node *head,*pf,*pb;
//定义node结构指针变量，其中head为头指针，pf为指向两相邻结点中前一结点的指针变量，pb为指向后一结点的指针变量
	int i;
	for(i=0;i<n;i++)                    //循环输入数据 
	{
		pb = (struct node*)malloc(sizeof(struct node));   //分配内存空间 
		printf("请输入数据:\n");
		scanf("%d %d",&pb->num,&pb->age);
		if(i==0)                         //第一个输入的数据
		pf = head = pb;
		else pf->next = pb;              //让pf指向后一个节点 
		pb->next = NULL;                 //同时置后一个节点的指针域为空（因为是一个一个添加节点的） 
		pf = pb;                         //让pf成为pb，形成前后指针间的传递和连接 
	}
	
	return(head);                        //返回的头指针指向该创建完毕的链表结构
	
}
	
void insertnode(struct node *head)       //函数：用前插法插入节点 
{
	loop1:
	int num,element1,element2,i=0;
	struct node *pf,*pb;
	pf=head;
	printf("请输入要插入位置的序号：");
	scanf("%d",&num);
	printf("请输入要插入的数据：");
	scanf("%d %d",&element1,&element2);
	while(pf->next != NULL && i < (num-1))
	{
		i++;
		pf=pf->next;
	}                                                   //这里的while是让头指针一直走到待插入节点的位置前，方便后续处理 

	if(pf == NULL || i > (num-1))
	{	
		printf("待插入的目标位置不存在，请重新输入！");
		goto loop1;                                     //回到本函数开头，重新进行操作
	} 
	else                                                //在用户输入的序号对应的元素前面插入新节点 
	{
		pb=(struct node*)malloc(sizeof(struct node));   //给新插入的节点分配内存 
		pb->num = element1;                             //赋值 
		pb->age = element2;                             //赋值 
		pb->next = pf->next;                            //让被插入节点的指针域指向原来前一个节点指向的节点的数据域 
		pf->next = pb;                                  //而此时被插入节点的前一个节点的指针域指向这个被插入节点 
	}                                                   //至此，完成一次前插法插入 

}

int killnode(struct node *aim)               //函数：删除对应序号的节点
{
	loop2:                                   //循环输入，防止用户输入的序号不符合要求 
	int i,j=0;
	struct node *pf,*pb;
	pf=aim;
	pb=aim->next;
	printf("请输入您要删除的节点序号：");
	scanf("%d",&i);
	while(pf->next != NULL && j < (i-1))
	{
		pf = pf->next;
		j++;
		pb = pf->next;
	}                                       //这里的while是让头指针一直走到待删除节点的位置前，方便后续处理
	
	if(pf->next == NULL || j>i-1)
	{
		printf("\n错误，请重新输入！");
		goto loop2;                         //回到本函数开头，重新进行操作 
	}
	else
	{
		pf->next = pb->next;                //让被删除节点的前一个节点指向被删除节点的后一个节点 
		free(pb);                           //释放内存空间 
	}
	
}

void print(struct node *head)               //函数：打印链表 
{
    struct node *node = head; 
    while(node != NULL)                     //利用指针遍历整个链表 
    {  
        printf("num: %d ---> age: %d\n",node->num,node->age);
        node = node->next;                  //不断指向下一个节点 
    }

}

int main()
{
	
	struct node *head;
	printf("模拟链表程序\n");
	printf("\n"); printf("\n");
 	int caozuo, n, k;
 	printf("新建链表，请输入链表包含的节点数: ");
    scanf("%d",&n);
    head = creat(n);
    printf("当前链表内元素为:\n");        //构建简单的用户交互界面 
    print(head);                          //打印当前链表元素 
    
 	loop:                                 //便于用户循环操作 
 	printf("请选择链表操作：插入节点请按1，删除节点请按2，退出请按0\n");
    scanf("%d", &caozuo);                 //根据用户输入的选项分别进行操作 
    
    switch(caozuo)
    {
    	case 0:                           //退出交互系统 
    		return 0;
    	
    	case 1:                           //调用函数，进行插入节点操作 
    	{
			insertnode(head);
			printf("当前链表内元素为:\n");//每次操作结束后打印当前链表中的元素并回到loop准备下一轮操作 
			print(head);
    		goto loop;
		}
		
		case 2:                           //调用函数，进行删除节点操作 
		{
			killnode(head);
			printf("当前链表内元素为:\n");//每次操作结束后打印当前链表中的元素并回到loop准备下一轮操作 
			print(head);
			goto loop;
		}

	}

	return 0;

}
