#include<stdio.h>
#include<stdlib.h>

struct node                             //����һ���ڵ�Ľṹ�� 
{
	int num;
	int age;                            //����һ���ڵ������������������num��age 
	struct node *next;                  //����һ���ڵ��ָ���򣬸�ָ�������ֵΪ��һ���ڵ���׵�ַ 
};

struct node *creat(int n)               //ָ�뺯��������һ������n���ڵ������
{
	
	struct node *head,*pf,*pb;
//����node�ṹָ�����������headΪͷָ�룬pfΪָ�������ڽ����ǰһ����ָ�������pbΪָ���һ����ָ�����
	int i;
	for(i=0;i<n;i++)                    //ѭ���������� 
	{
		pb = (struct node*)malloc(sizeof(struct node));   //�����ڴ�ռ� 
		printf("����������:\n");
		scanf("%d %d",&pb->num,&pb->age);
		if(i==0)                         //��һ�����������
		pf = head = pb;
		else pf->next = pb;              //��pfָ���һ���ڵ� 
		pb->next = NULL;                 //ͬʱ�ú�һ���ڵ��ָ����Ϊ�գ���Ϊ��һ��һ����ӽڵ�ģ� 
		pf = pb;                         //��pf��Ϊpb���γ�ǰ��ָ���Ĵ��ݺ����� 
	}
	
	return(head);                        //���ص�ͷָ��ָ��ô�����ϵ�����ṹ
	
}
	
void insertnode(struct node *head)       //��������ǰ�巨����ڵ� 
{
	loop1:
	int num,element1,element2,i=0;
	struct node *pf,*pb;
	pf=head;
	printf("������Ҫ����λ�õ���ţ�");
	scanf("%d",&num);
	printf("������Ҫ��������ݣ�");
	scanf("%d %d",&element1,&element2);
	while(pf->next != NULL && i < (num-1))
	{
		i++;
		pf=pf->next;
	}                                                   //�����while����ͷָ��һֱ�ߵ�������ڵ��λ��ǰ������������� 

	if(pf == NULL || i > (num-1))
	{	
		printf("�������Ŀ��λ�ò����ڣ����������룡");
		goto loop1;                                     //�ص���������ͷ�����½��в���
	} 
	else                                                //���û��������Ŷ�Ӧ��Ԫ��ǰ������½ڵ� 
	{
		pb=(struct node*)malloc(sizeof(struct node));   //���²���Ľڵ�����ڴ� 
		pb->num = element1;                             //��ֵ 
		pb->age = element2;                             //��ֵ 
		pb->next = pf->next;                            //�ñ�����ڵ��ָ����ָ��ԭ��ǰһ���ڵ�ָ��Ľڵ�������� 
		pf->next = pb;                                  //����ʱ������ڵ��ǰһ���ڵ��ָ����ָ�����������ڵ� 
	}                                                   //���ˣ����һ��ǰ�巨���� 

}

int killnode(struct node *aim)               //������ɾ����Ӧ��ŵĽڵ�
{
	loop2:                                   //ѭ�����룬��ֹ�û��������Ų�����Ҫ�� 
	int i,j=0;
	struct node *pf,*pb;
	pf=aim;
	pb=aim->next;
	printf("��������Ҫɾ���Ľڵ���ţ�");
	scanf("%d",&i);
	while(pf->next != NULL && j < (i-1))
	{
		pf = pf->next;
		j++;
		pb = pf->next;
	}                                       //�����while����ͷָ��һֱ�ߵ���ɾ���ڵ��λ��ǰ�������������
	
	if(pf->next == NULL || j>i-1)
	{
		printf("\n�������������룡");
		goto loop2;                         //�ص���������ͷ�����½��в��� 
	}
	else
	{
		pf->next = pb->next;                //�ñ�ɾ���ڵ��ǰһ���ڵ�ָ��ɾ���ڵ�ĺ�һ���ڵ� 
		free(pb);                           //�ͷ��ڴ�ռ� 
	}
	
}

void print(struct node *head)               //��������ӡ���� 
{
    struct node *node = head; 
    while(node != NULL)                     //����ָ������������� 
    {  
        printf("num: %d ---> age: %d\n",node->num,node->age);
        node = node->next;                  //����ָ����һ���ڵ� 
    }

}

int main()
{
	
	struct node *head;
	printf("ģ���������\n");
	printf("\n"); printf("\n");
 	int caozuo, n, k;
 	printf("�½�������������������Ľڵ���: ");
    scanf("%d",&n);
    head = creat(n);
    printf("��ǰ������Ԫ��Ϊ:\n");        //�����򵥵��û��������� 
    print(head);                          //��ӡ��ǰ����Ԫ�� 
    
 	loop:                                 //�����û�ѭ������ 
 	printf("��ѡ���������������ڵ��밴1��ɾ���ڵ��밴2���˳��밴0\n");
    scanf("%d", &caozuo);                 //�����û������ѡ��ֱ���в��� 
    
    switch(caozuo)
    {
    	case 0:                           //�˳�����ϵͳ 
    		return 0;
    	
    	case 1:                           //���ú��������в���ڵ���� 
    	{
			insertnode(head);
			printf("��ǰ������Ԫ��Ϊ:\n");//ÿ�β����������ӡ��ǰ�����е�Ԫ�ز��ص�loop׼����һ�ֲ��� 
			print(head);
    		goto loop;
		}
		
		case 2:                           //���ú���������ɾ���ڵ���� 
		{
			killnode(head);
			printf("��ǰ������Ԫ��Ϊ:\n");//ÿ�β����������ӡ��ǰ�����е�Ԫ�ز��ص�loop׼����һ�ֲ��� 
			print(head);
			goto loop;
		}

	}

	return 0;

}
