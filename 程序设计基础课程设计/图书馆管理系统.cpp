#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h> 
#include <conio.h>
#define N 20

//ͼ����Ϣ�Ľṹ�嶨��
struct book
{
	char num[N];           //ͼ����
	char name[N];          //ͼ������
	int n;                 //ͼ������
    struct book *p;        //�ṹ��ָ��
};
struct book bk;            //����ṹ�����bk

//������Ϣ�Ľṹ�嶨��
struct reader
{
	char num[N];           //���߱��
	char name[N];          //��������
	char bknum1[N];        //���ĵĵ�һ��ͼ����
	char bknum2[N];        //���ĵĵڶ���ͼ����
    struct reader *p1;     //�ṹ��ָ��
};
struct reader rd;          //����ṹ�����rd

/*�ۺ�ϵͳ�õ��ĺ���*/
/* ����Ա��ع��� */
void func_adm(int choice); //����Ա����ѡ��
void mainmenu_adm();       //����Ա������Ŀ¼
void tjtsxx();             //���ͼ����Ϣ
void sctsxx();             //ɾ��ͼ����Ϣ������Ż���������
void xgtsxx();             //�޸�ͼ����Ϣ������Ż���������
void printall_book();      //�������ͼ����Ϣ
void tjdzxx();             //��Ӷ�����Ϣ
void scdzxx();             //ɾ��������Ϣ������Ż���������
void xgdzxx();             //�޸Ķ�����Ϣ������Ż���������
void printall_reader();    //������ж�����Ϣ
/* ������ع��� */
void func_usr(int choice); //���߹���ѡ��
void mainmenu_usr();       //���߽�����Ŀ¼
void borrow();             //����ͼ�鹦��
void giveback();           //�黹ͼ�鹦��
void chaxun();             //����Ż�������ѯͼ����Ϣ
void chaxun_borrowers();   //����Ż�������ѯͼ�鱻��Щ���߽���
void display();            //��ʾ��ǰ�û��ѽ��ĵ��鼮
/*�жϺ���*/
int judge_adm(char str[N]);                //�жϹ���Ա������û����Ƿ���ȷ
int judge_usr(char str[N]);                //�ж��û�������û�������߱���Ƿ�������һ����ȷ
int judge_bk1(char str[N]);                //�ж��û�������鼮��ź������Ƿ�������һ����ȷ
int judge_bk2(char str1[N], char str2[N]); //�ж��û�������鼮��ź������Ƿ���ȷ

//����Ա������Ŀ¼
void mainmenu_adm()
{
	system("cls");//���� 
    char op[N];
    int OP;
    printf("------�𾴵Ĺ���Ա���ã���ӭ��¼ͼ��ݹ���ϵͳ��------\n");
    printf("\n1.���ͼ����Ϣ\n");
    printf("\n2.��ʾ����ͼ����Ϣ\n");
    printf("\n3.�����/����ɾ��ͼ����Ϣ\n");
    printf("\n4.�����/�����޸�ͼ����Ϣ\n");
    printf("----------------------------------");
    printf("\n5.��Ӷ�����Ϣ\n");
    printf("\n6.��ʾ���ж�����Ϣ\n");
    printf("\n7.�����/����ɾ��������Ϣ\n");
    printf("\n8.�����/�����޸Ķ�����Ϣ\n");
    printf("\n9.�˳�ϵͳ\n");
    
    printf("\n����������ѡ��\n");
    scanf("%s",op);
    OP = atoi(op);
	if(OP >= 1 && OP <= 9)//������������1-9��Χ��ʱ 
		func_adm(OP);
	
	else//�����벻��ȷ 
	{
    	printf("---  ��������������,����������!  ---\n");
    	system("pause");
    	mainmenu_adm();
	}
}

//����Ա����ѡ�� 
void func_adm(int op)
{
	switch(op)
	{
		case 1:
			tjtsxx();
			break;
		case 2:
			printall_book();
			break;
		case 3:
			sctsxx();
			break; 
		case 4:
			xgtsxx();
			break;
		case 5:
			tjdzxx();
			break;
		case 6:
			printall_reader();
			break;
		case 7:
			scdzxx();
			break;
		case 8:
			xgdzxx();
			break;
		case 9:
			exit(0);
			break;
	}
}

//���ͼ����Ϣ
void tjtsxx()
{
	system("cls");
	FILE *fp;  //�����ļ�ָ��fp��ָ��ĳ���ļ� 
	int a;
	if((fp = fopen("C:\\Users\\HP\\ͼ����Ϣ.txt","a")) == NULL)//�Ը��ӵķ�ʽ��ֻд�ļ���д������ݱ�׷�ӵ��ļ�β 
	{	
		printf("File open error!\n");
		exit(0);
	}
	
	loop10:
	printf("������ͼ���ţ�\n");//0-999
	scanf("%s",bk.num);
	printf("������ͼ��������\n");
	scanf("%s",bk.name);
	printf("������ͼ��������\n");//0-20
	scanf("%d",&bk.n);           //�û����� 
	
	if((atoi(bk.num) >= 1 && atoi(bk.num) <= 999) && (bk.n >= 0 && bk.n <= 20))//������ȷʱ 
		fprintf(fp,"%s %s %d                    \n",bk.num, bk.name, bk.n);
	else
	{
		while(1)
		{
			system("cls");
			printf("����������������밴1���������˵��밴2��\n");
			scanf("%d",&a);
			if(a == 1)
				goto loop10;
			else if(a == 2)
			{
				fclose(fp);
				mainmenu_adm();
			}
			else
				printf("�����������������!\n");
		}
	}
	
	fclose(fp);
	
	while(1)//������ϣ����к����ν� 
	{
		system("cls");
		printf("�����ϣ��������˵��밴1����������밴2\n");
		scanf("%d",&a);
		if(a == 1)
			mainmenu_adm();
		else if(a == 2)
			tjtsxx();
		else
			printf("�����������������!\n");	
	}
}	

//ɾ��ͼ����Ϣ 
void sctsxx()
{
	system("cls");
	struct book bk1[50];
	struct book bk2[50];  //��������book���͵Ľṹ������ 
	FILE *fp,*fp1;
	int a, j, n = 0, i = 0;
	char aim[20];
	loop1:  
	printf("������Ŀ��ͼ��ı�Ż�������\n");
	scanf("%s",aim);
	if(judge_bk1(aim) == 0)
	{
		while(1)
		{
			system("cls");
			printf("��Ż����������������������밴1���������˵��밴2\n");
			scanf("%d",&a);
			if(a == 1)
				goto loop1;
			else if(a == 2)
				mainmenu_adm();
			else
				printf("�����������������!\n");
		}
	}
	
	else  //��������ȷʱ 
	{
		if((fp = fopen("C:\\Users\\HP\\ͼ����Ϣ.txt","r")) == NULL)
		{
			printf("File open error!");
			exit(0);
		}
		
		while(!feof(fp))
		{
			fscanf(fp,"%s %s %d",bk1[n].num ,bk1[n].name, &bk1[n].n);
			if(strcmp(bk1[n].name,aim) != 0 && strcmp(bk1[n].num,aim) != 0)
			{
				strcpy(bk2[i].num ,bk1[n].num);
				strcpy(bk2[i].name,bk1[n].name);
				bk2[i].n = bk1[n].n;
				i++;
			}
			
			n++;
		}//�ƿ���ɾ�����Ǳ��飬�����������Ϣȫ�����µĽṹ�����鱣�� 
		
		fclose(fp);
	
		if((fp = fopen("C:\\Users\\HP\\ͼ����Ϣ.txt","w")) == NULL)//��ֻд�ļ�����Ϊ�ļ����ڣ����ļ��������� 
		{
			printf("file open error!");
			exit(0);
		}
		
		for(j = 0; j < i - 1; j++)  //������i-1��������Խ�� 
			fprintf(fp,"%s %s %d                    \n",bk2[j].num ,bk2[j].name, bk2[j].n);
		//���ļ���ͷ��ʼ��д����˴�ɾ�����Ǳ������������������Ϣ�����ɾ������ //�ƿ���ɾ�����Ǳ��飬�����������Ϣȫ�����µĽṹ�����鱣�� 
		fclose(fp);
	}
	
	while(1)
	{
		system("cls");
		printf("ɾ����ϣ��������˵��밴1������ɾ���밴2\n");
		scanf("%d",&a);
		if(a == 1)
			mainmenu_adm();
		else if(a == 2)
			sctsxx();
		else
			printf("�����������������!\n");	
	}
}

//�޸�ͼ����Ϣ
void xgtsxx()
{
	system("cls");
	FILE *fp;
	char aim[20], num[20], weishu[20];
	int a, n, flag;
	loop2:
	printf("������Ŀ��ͼ��ı�Ż�������\n");
	scanf("%s", aim);
	if(judge_bk1(aim) == 0)
	{
		while(1)
		{
			system("cls");
			printf("��Ż����������������������밴1���������˵��밴2\n");
			scanf("%d",&a);
			if(a == 1)
				goto loop2;
			else if(a == 2)
				mainmenu_adm();
			else
				printf("�����������������!\n");
		}
	}
	
	else  //��������ȷʱ 
	{
		if((fp = fopen("C:\\Users\\HP\\ͼ����Ϣ.txt","r+")) == NULL)//�򿪿ɶ�д�ļ�
		{
			printf("File open error!");
			exit(0);
		}
		
		printf("�޸��鼮��ţ��밴1���޸��鼮�������밴2\n");
		scanf("%d",&flag);
		if(flag == 1)
		{
			while(!feof(fp))
			{	
				fscanf(fp,"%s %s %d",bk.num, bk.name, &bk.n);
				if(strcmp(bk.num,aim) == 0 || strcmp(bk.name,aim) == 0)
				{
					itoa(bk.n,weishu,10);
					fseek(fp,-(2 + strlen(weishu) + strlen(bk.name) + strlen(bk.num)),SEEK_CUR); //�ع�ָ��
					printf("�������µ��鼮���:\n");
					scanf("%s",&num);
					fprintf(fp,"%s %s %d          ",num, bk.name, bk.n); //����д��
					break;
				}
			}
		}

		if(flag == 2)
		{
			while(!feof(fp))
			{	
				fscanf(fp,"%s %s %d",bk.num, bk.name, &bk.n);
				if(strcmp(bk.num,aim) == 0 || strcmp(bk.name,aim) == 0)
				{
					itoa(bk.n,weishu,10);
					fseek(fp,-(strlen(weishu)),SEEK_CUR); //�ع�ָ��
					printf("�������µ��鼮����:\n");
					scanf("%d",&n);
					fprintf(fp,"%d          ",n);    //����д��
					break;
				}
			}
		}
	
		fclose(fp); 
	}
	
	while(1)
	{
		system("cls");
		printf("�޸���ϣ��������˵��밴1�������޸��밴2\n");
		scanf("%d",&a);
		if(a == 1)
			mainmenu_adm();
		else if(a == 2)
			xgtsxx();
		else
			printf("�����������������!\n");
	}
}

//�������ͼ����Ϣ 
void printall_book()
{
	FILE *fp;
	printf("���    ����        ���\n");
	if((fp = fopen ("C:\\Users\\HP\\ͼ����Ϣ.txt","r")) == NULL)
	{
		printf("File open error!\n");
		exit (0);
	}
	
	while(!feof (fp))
	{
		fscanf(fp,"%s %s %d",bk.num, bk.name, &bk.n);
		if(feof(fp) == 0)//��ֹ���һ�ж����һ�� 
			printf("%s      %s       %d\n",bk.num, bk.name, bk.n);
	}
	
	fclose(fp);
	system("pause");
    mainmenu_adm();
}

//��Ӷ�����Ϣ
void tjdzxx()
{
	system("cls");
	int a;
	FILE *fp;
	if((fp = fopen("C:\\Users\\HP\\������Ϣ.txt","a")) == NULL)//�Ը��ӵķ�ʽ��ֻд�ļ���д������ݱ��ӵ��ļ�β 
	{	
		printf("File open error!\n");
		exit(0);
	}
	loop11:
	printf("��������߱�ţ�\n");//0-999
	scanf("%s",rd.num);
	printf("����������û�����\n");
	scanf("%s",rd.name);
	printf("������ö��߽��ĵĵ�һ���鼮�ı��(���ö���δ����������---����)��\n");//0-999��--- 
	scanf("%s",&rd.bknum1);
	printf("������ö��߽��ĵĵڶ����鼮�ı��(���ö���δ����������---����)��\n");//0-999��---
	scanf("%s",&rd.bknum2);
	
	if((atoi(rd.num) >= 1 && atoi(rd.num) <= 999) && ((atoi(rd.bknum1) >= 1 && atoi(rd.bknum1) <= 999) || strcmp(rd.bknum1,"---") == 0) && ((atoi(rd.bknum2) >= 1 && atoi(rd.bknum2) <= 999) || strcmp(rd.bknum2,"---") == 0)) //������ȷʱ 
		fprintf(fp,"%s %s %s %s                    \n",rd.num, rd.name, rd.bknum1, rd.bknum2);
	else
	{
		while(1)
		{
			system("cls");
			printf("����������������밴1���������˵��밴2��\n");
			scanf("%d",&a);
			if(a == 1)
				goto loop11;
			else if(a == 2)
			{
				fclose(fp);
				mainmenu_adm();
			}
			else
				printf("�����������������!\n");
		}
	}
	
	fclose(fp);
	
	while(1)
	{
		system("cls");
		printf("�����ϣ�������һ���밴1����������밴2\n");
		scanf("%d",&a);
		if(a == 1)
			mainmenu_adm();
		else if(a == 2)
			tjdzxx();
		else
			printf("�����������������!\n");
	}
}	

//ɾ��������Ϣ 
void scdzxx()
{
	system("cls");
	struct reader rd1[20];
	struct reader rd2[20];
	FILE *fp,*fp1;		
	int a, j, n = 0, i = 0;
	char aim[20];
	loop3: 
	printf("��������ߵı�Ż��û�����\n");
	scanf("%s",aim);
	if(judge_usr(aim) == 0)
	{
		while(1)
		{
			system("cls");
			printf("��Ż��û��������������������밴1���������˵��밴2\n");
			scanf("%d",&a);
			if(a == 1)
				goto loop3;
			else if(a == 2)
				mainmenu_adm();
			else
				printf("�����������������!\n");
		}
	}
	
	else  //��������ȷʱ 
	{
		if((fp = fopen("C:\\Users\\HP\\������Ϣ.txt","r")) == NULL)
		{
			printf("File open error!");
			exit(0);
		}
		
		while(!feof(fp))
		{
			fscanf(fp,"%s %s %s %s",rd1[n].num ,rd1[n].name, rd1[n].bknum1, rd1[n].bknum2);
			if(strcmp(rd1[n].num,aim) != 0 && strcmp(rd1[n].name,aim) != 0)
			{
				strcpy(rd2[i].num,    rd1[n].num);
				strcpy(rd2[i].name,   rd1[n].name);
				strcpy(rd2[i].bknum1, rd1[n].bknum1);
				strcpy(rd2[i].bknum2, rd1[n].bknum2);
				i++;
			}
			
			n++;
		}//�ƿ���ɾ�����Ǳ��飬�����������Ϣȫ�����µĽṹ�����鱣�� 
	
		fclose(fp);
		
		if((fp = fopen("C:\\Users\\HP\\������Ϣ.txt","w")) == NULL)//��ֻд�ļ������ļ��������ļ��������� 
		{
			printf("file open error!");
			exit(0);
		}
		
		for(j = 0; j < i - 1; j++)  //������i-1��������Խ�� 
			fprintf(fp,"%s %s %s %s                    \n",rd2[j].num ,rd2[j].name, rd2[j].bknum1, rd2[j].bknum2);
		//���ļ���ͷ��ʼ��д����˴�ɾ�����Ǳ������������������Ϣ�����ɾ������ 	
		fclose(fp);
	}
	
	while(1)
	{
		system("cls");
		printf("ɾ����ϣ��������˵��밴1������ɾ���밴2\n");
		scanf("%d",&a);
		if(a == 1)
			mainmenu_adm();
		else if(a == 2)
			scdzxx();
		else
			printf("�����������������!\n");
	}
}

//�޸Ķ�����Ϣ
void xgdzxx()
{
	system("cls");
	FILE *fp;
	char aim[20], num[20], name[20];
	int a, flag;
	loop4:
	printf("������Ŀ����ߵı�Ż��û�����\n");
	scanf("%s",aim);
	if(judge_usr(aim) == 0)
	{
		while(1)
		{
			system("cls");
			printf("��Ż��û��������������������밴1���������˵��밴2\n");
			scanf("%d",&a);
			if(a == 1)
				goto loop4;
			else if(a == 2)
				mainmenu_adm();
			else
				printf("�����������������!\n");
		}
	}
	
	else  //��������ȷʱ 
	{
		if((fp = fopen("C:\\Users\\HP\\������Ϣ.txt","r+")) == NULL)//�򿪿ɶ�д�ļ�
		{
			printf("File open error!\n");
			exit (0);
		}
		
		printf("�޸Ķ��߱�ţ��밴1���޸Ķ����������밴2:\n");
		scanf("%d",&flag);
		if(flag == 1)
		{
			while(!feof(fp))
			{
				fscanf(fp,"%s %s %s %s",rd.num, rd.name, rd.bknum1, rd.bknum2);
				if(strcmp(rd.num,aim) == 0 || strcmp(rd.name,aim) == 0)
				{
					fseek(fp,-(3 + strlen(rd.bknum2) + strlen(rd.bknum1) + strlen(rd.name) + strlen(rd.num)),SEEK_CUR);  //�ع�ָ��
					printf("�������µĶ��߱��:\n");
					scanf("%s",&num);
					fprintf(fp,"%s %s %s %s          ",num, rd.name, rd.bknum1, rd.bknum2);//����д��
					break;
				}
			}
		}

		if(flag == 2)
		{
			while(!feof(fp))
			{	
				fscanf(fp,"%s %s %s %s",rd.num, rd.name, rd.bknum1, rd.bknum2);
				if(strcmp(rd.num,aim) == 0 || strcmp(rd.name,aim) == 0)
				{
					fseek(fp,-(2 + strlen(rd.bknum2) + strlen(rd.bknum1) + strlen(rd.name)),SEEK_CUR);//�ع�ָ��
					printf("�������µĶ�������:\n");
					scanf("%s",&name);
					fprintf(fp,"%s %s %s          ",name, rd.bknum1, rd.bknum2); //����д��
					break;
				}
			}
		}
	 
		fclose(fp);
	}
	
	while(1)
	{
		system("cls");
		printf("�޸���ϣ�������һ���밴1�������޸��밴2\n");
		scanf("%d",&a);
		if(a == 1)
			mainmenu_adm();
		else if(a == 2)
			xgdzxx();
		else
			printf("�����������������!\n");
	}
} 

//������ж�����Ϣ 
void printall_reader()
{
	FILE *fp;
	printf("���     ����      �鼮1      �鼮2\n");
	if((fp = fopen ("C:\\Users\\HP\\������Ϣ.txt","r")) == NULL)
	{
		printf("File open error!\n");
		exit (0);
	}
	
	while(!feof(fp))
	{
		fscanf(fp,"%s %s %s %s",rd.num, rd.name, rd.bknum1, rd.bknum2);
		if(feof(fp) == 0)//��ֹ���һ�ж����һ�� 
			printf("%s        %s        %s        %s\n",rd.num, rd.name, rd.bknum1, rd.bknum2);
	}
	
	fclose(fp);
	system("pause");
    mainmenu_adm();
}

/*------------------------------------------------------------------------------------------------------*/

//���߽�����Ŀ¼
void mainmenu_usr()
{
	system("cls");
    int choice;
    printf("------�װ��Ķ������ã���ӭ��¼ͼ��ݹ���ϵͳ��------\n");
    printf("\n1.�����鼮\n");
    printf("\n2.�黹�鼮\n");
    printf("\n3.�����/������ѯͼ����Ϣ\n");
    printf("\n4.����Ų�ѯ�鼮�����н�����\n");
    printf("\n5.��ʾ��ǰ���ĵ��鼮\n"); 
    printf("\n6.�˳�ϵͳ\n");
    printf("\n����������ѡ��\n");
	
    scanf("%d",&choice);
    
	if(choice<1||choice>6)
	{
        printf("---  ��������������,����������!  ---\n"); 
		mainmenu_usr();
	}
	
	else 
		func_usr(choice);
}

//���߹���ѡ�� 
void func_usr(int choice)
{
	switch(choice)
	{
		case 1:
			borrow();
			break;
		case 2:
			giveback();
			break;
		case 3:
			chaxun();
			break; 
		case 4:
			chaxun_borrowers();
			break;
		case 5:
			display();
			break;
		case 6:
			exit(0);
			break;
	}
} 

//����Ż�������ѯͼ����Ϣ 
void chaxun()
{
	system("cls");
	FILE *fp;
	char aim[20];
	int flag = 0;
	printf("������ͼ��ı�Ż�������\n");
	scanf("%s",aim);
	printf("���     ����     ���\n");
	if((fp = fopen("C:\\Users\\HP\\ͼ����Ϣ.txt","r")) == NULL)
	{
		printf("File open error!\n");
		exit (0);
	}
	
	while(!feof(fp))
	{
		fscanf(fp,"%s %s %d",bk.num, bk.name, &bk.n);
		if(feof(fp) == 0)
		{
			if(strcmp(bk.num,aim) == 0 || strcmp(bk.name,aim) == 0)
			{
				printf("%s      %s        %d\n",bk.num, bk.name, bk.n);
				flag++;//flag����1����ʾ��ͼ���������ҵ����Ȿ�� 
			}
		}
	}
	
	if(flag == 0)
    	printf("\nû���Ȿ��!\n\n");
    
	fclose(fp);
    system("pause");
    mainmenu_usr();
}

//����Ż�������ѯĳ��ͼ�鱻��Щ���߽���
void chaxun_borrowers()
{
	system("cls");
	FILE *fp, *fp1;
	int a, flag = 0;
	char aim[20];
	loop12:
	printf("������ͼ��ı�Ż�������\n");
	scanf("%s", aim);
	if(judge_bk1(aim) == 0)
	{
		while(1)
		{
			system("cls");
			printf("��Ż����������������������밴1���������˵��밴2\n");
			scanf("%d",&a);
			if(a == 1)
				goto loop12;
			else if(a == 2)
				mainmenu_usr();
			else
				printf("�����������������!\n");
		}
	}
	
	else
	{
		printf("���     ����\n");
		if((fp = fopen("C:\\Users\\HP\\������Ϣ.txt","r")) == NULL)
		{
			printf("File open error!\n");
			exit (0);
		}
	
		while(!feof(fp))
		{
			fscanf(fp,"%s %s %s %s\n",rd.num, rd.name, rd.bknum1, rd.bknum2);
			if(strcmp(rd.bknum1,aim) == 0 || strcmp(rd.bknum2,aim) == 0)
			{
				printf("%s        %s\n",rd.num, rd.name);
				flag++;//flag����1����ʾ�ڶ����������ҵ����Ȿ�� 
			}
		}
	
		if(flag == 0)
    	printf("\nû�ж��߽��Ĺ��Ȿ��!\n\n");
	}

	fclose(fp);
    system("pause");
    mainmenu_usr();
}

//����ͼ�鹦�ܣ�������Ϣ����Ӧ���޸ģ�ͼ����Ϣ���ж�Ӧ���鼮�������Լ�1 
void borrow()
{
	FILE *fp, *fp1;
	char aim_num[20], aim_name[20], weishu[20];
	int a, flag1 = 0, flag2 = 0, flag3 = 0; 
	loop5:
	printf("����������Ҫ���ĵ��鼮�ı�ź�����\n");
	printf("���:  \n");
	scanf("%s",aim_num);
	printf("����:  \n");
	scanf("%s",aim_name);
	if(judge_bk2(aim_num,aim_name) == 0)//�����жϺ������ж��û������ͼ���Ż������Ƿ���ȷ 
	{
		printf("��Ż����������������������밴1���������˵��밴2\n");
		scanf("%d",&a);
		if(a == 1)
			goto loop5;
		else
			mainmenu_usr(); 
	}
	
	else  //������ȷʱ
	{
		if((fp = fopen ("C:\\Users\\HP\\ͼ����Ϣ.txt","r+")) == NULL)//�򿪿ɶ�д�ļ� 
		{
			printf("File open error!\n");
			exit (0);
		}
		
		while(!feof(fp))
		{
			fscanf(fp,"%s %s %d",bk.num, bk.name, &bk.n);
			if(strcmp(bk.num,aim_num) == 0 && strcmp(bk.name,aim_name) == 0)
			{
				if(bk.n == 0) //���Ϊ0ʱ 
				{
					printf("��Ǹ�����鼮��ǰ�Ŀ��Ϊ0�����������밴1���������˵��밴2\n");
					scanf("%d",&a);
					if(a == 1)
						goto loop5;
					else
						mainmenu_usr(); 
				}
				
				else //��治Ϊ0ʱ 
				{
					itoa(bk.n,weishu,10);
					fseek(fp,-(strlen(weishu)),SEEK_CUR);//�ع�ָ��
					fprintf(fp,"%d          ",bk.n - 1); //����д��
					break;
				}
			}
		}
	}  //ʵ��ͼ�������仯
	                                             
	fclose(fp);
	
	char aim[20];
	loop6:
	printf("���������Ķ��߱�Ż��û���(����)��\n");
	scanf("%s",&aim);
	if(judge_usr(aim) == 0)//�����жϺ������ж��û�����Ķ��߱�Ż��û����Ƿ���ȷ 
	{
		printf("��Ż��û��������������������밴1���������˵��밴2\n");
		scanf("%d",&a);
		if(a == 1)
			goto loop6;
		else
			mainmenu_usr();
	}
	
	else  //������ȷʱ 
	{
		if((fp1 = fopen ("C:\\Users\\HP\\������Ϣ.txt","r+")) == NULL)//�򿪿ɶ�д�ļ� 
		{
			printf("File open error!\n");
			exit (0);
		}
		
		while(!feof(fp1))
		{	
			fscanf(fp1,"%s %s %s %s",rd.num, rd.name, rd.bknum1, rd.bknum2);
			if(strcmp(rd.num,aim) == 0 || strcmp(rd.name,aim) == 0)
			{
				if(strcmp(rd.bknum1,"---") != 0 && strcmp(rd.bknum2,"---") != 0)
				{
					printf("Ŀǰ�����鼮���������Ѿ��ﵽ��������ʱ�޷����н��������\n");
					system("pause");
    				mainmenu_usr();
				}
				else if(strcmp(rd.bknum1,"---") == 0)
				{
					fseek(fp1,-(1 + strlen(rd.bknum2) + strlen(rd.bknum1)),SEEK_CUR);                  //�ع�ָ��
					fprintf(fp1,"%s %s          ",aim_num, rd.bknum2); //����д��
					break;
				}
				else
				{
					fseek(fp1,-(strlen(rd.bknum2)),SEEK_CUR);     //�ع�ָ��
					fprintf(fp1,"%s          ",aim_num);  //����д��
					break;
				}
			}
		}
	}
	
	fclose(fp1);
	printf("������ϣ����������ĵ��鼮���Ϊ��%s������Ϊ��%s\n",aim_num, aim_name); 
    system("pause");
    mainmenu_usr();
} 

//�黹ͼ�鹦�ܣ�������Ϣ����Ӧ���޸ģ�ͼ����Ϣ���ж�Ӧ���鼮����������1
void giveback()
{	
	FILE *fp, *fp1;
	int a, flag1 = 0, flag2 = 0, flag3 = 0;
	char aim_num[20], aim_name[20], weishu[20];
	loop7:
	printf("����������Ҫ�黹���鼮�ı�ź�����:\n");
	printf("�鼮���:  \n");
	scanf("%s",aim_num);
	printf("����:  \n");
	scanf("%s",aim_name);
	if(judge_bk2(aim_num,aim_name) == 0)//�����жϺ������ж��û������ͼ���Ż������Ƿ���ȷ 
	{
		printf("��Ż����������������������밴1���������˵��밴2\n");
		scanf("%d",&a);
		if(a == 1)
			goto loop7;
		else
			mainmenu_usr();
	}
		
	else   //������ȷʱ 
	{
		char aim[20];
		loop8:
		printf("���������Ķ��߱�Ż��û���(����)��\n");
		scanf("%s",&aim);
		if(judge_usr(aim) == 0)//�����жϺ������ж��û�����Ķ��߱�Ż��û����Ƿ���ȷ 
		{
			printf("��Ż��û��������������������밴1���������˵��밴2\n");
			scanf("%d",&a);
			if(a == 1)
				goto loop8;
			else
				mainmenu_usr();
		}
	
		else   //������ȷʱ
		{
			if((fp1 = fopen ("C:\\Users\\HP\\������Ϣ.txt","r+")) == NULL)//�򿪿ɶ�д�ļ�
			{
				printf("File open error!\n");
				exit (0);
			}
		
			while(!feof(fp1))
			{
				fscanf(fp1,"%s %s %s %s",rd.num, rd.name, rd.bknum1, rd.bknum2);
				if(strcmp(rd.num,aim) == 0 || strcmp(rd.name,aim) == 0)
				{
					if(strcmp(rd.bknum1,"---") == 0 && strcmp(rd.bknum2,"---") == 0)
					{
						printf("Ŀǰ�����ĵ��鼮����Ϊ0����ʱ�޷����л��������\n");
						system("pause");
    					mainmenu_usr();
					}
					else if(strcmp(rd.bknum1,aim_num) != 0 && strcmp(rd.bknum2,aim_num) != 0)
					{
						printf("��δ���ĸ��鼮�����������밴1���������˵��밴2��\n");
						scanf("%d",&a);
						if(a == 1)
							goto loop7;
						else
							mainmenu_usr();
					}
					else if(strcmp(rd.bknum1,aim_num) == 0  || strcmp(rd.bknum2,aim_num) != 0 )
					{
						fseek(fp1,-(1 + strlen(rd.bknum2) + strlen(rd.bknum1)),SEEK_CUR);//�ع�ָ��
						fprintf(fp1,"--- %s          ",rd.bknum2);//����д��
						break;
					}
					else
					{
						fseek(fp1,-(strlen(rd.bknum2)),SEEK_CUR);//�ع�ָ��
						fprintf(fp1,"---          ");//����д��
						break;				
					}
				}
			}

			if((fp = fopen ("C:\\Users\\HP\\ͼ����Ϣ.txt","r+")) == NULL)//�򿪿ɶ�д�ļ�
			{
				printf("File open error!\n");
				exit (0);
			}

			while(!feof(fp))
			{	
				fscanf(fp,"%s %s %d",bk.num, bk.name, &bk.n);
				if(strcmp(bk.num,aim_num) == 0 && strcmp(bk.name,aim_name) == 0)
				{
					itoa(bk.n,weishu,10);
					fseek(fp,-(strlen(weishu)),SEEK_CUR); //�ع�ָ��
					fprintf(fp,"%d          ",bk.n + 1);  //����д��
					break;
				}
			}
			fclose(fp);
		}
		fclose(fp1);
	}

	printf("������ϣ��������黹���鼮���Ϊ��%s������Ϊ��%s\n",aim_num, aim_name);
    system("pause");
    mainmenu_usr();
}

//��ʾ��ǰ�����ѽ��ĵ��鼮 
void display()
{
	FILE *fp;
	char aim[20];
	int a;
	loop9:
	printf("���ٴ��������Ķ��߱�Ż��û���(����)��\n");
	scanf("%s",&aim);
	if(judge_usr(aim) == 0)//�����жϺ������ж��û�����Ķ��߱�Ż��û����Ƿ���ȷ 
	{
		printf("��Ż��û��������������������밴1���������˵��밴2\n");
		scanf("%d",&a);
		if(a == 1)
			goto loop9;
		else
			mainmenu_usr();
	}
	
	else   //������ȷʱ 
	{
		printf("���     ����      �鼮1      �鼮2\n");
		if((fp = fopen ("C:\\Users\\HP\\������Ϣ.txt","r")) == NULL)
		{
			printf("File open error!\n");
			exit (0);
		}
		
		while(!feof(fp))
		{
			fscanf(fp,"%s %s %s %s",rd.num, rd.name, rd.bknum1, rd.bknum2);
			if(strcmp(rd.num,aim) == 0 || strcmp(rd.name,aim) == 0)
			{
				printf("%s        %s        %s        %s\n",rd.num, rd.name, rd.bknum1, rd.bknum2);
				break;
			}
		}
	}
	
	fclose(fp);
	system("pause");
    mainmenu_usr();
}

/*------------------------------------------------------------------------------------------------------*/
//�жϹ���Ա������û����Ƿ���ȷ
int judge_adm(char str[N])
{
	FILE *fp;
	char num[N], name[N];
	int flag = 0;
	fp = fopen("C:\\Users\\HP\\����Ա��Ϣ.txt","r");
	while(!feof(fp))
	{
		fscanf(fp,"%s %s",num, name);
		if(strcmp(name,str) == 0)
		{	
			flag = 1;
			break;
		}
	}
	fclose(fp);
	return flag;  //flag = 1��ʾ������ȷ��flag = 0��ʾ���벻��ȷ
} 
//�ж��û�������û�������߱���Ƿ�������һ����ȷ
int judge_usr(char str[N])
{
	FILE *fp;
	int flag = 0;
	fp = fopen("C:\\Users\\HP\\������Ϣ.txt","r");
	while(!feof(fp))
	{
		fscanf(fp,"%s %s %s %s",rd.num, rd.name, rd.bknum1, rd.bknum2);
		if(strcmp(rd.num,str) == 0 || strcmp(rd.name,str) == 0)
		{	
			flag = 1;
			break;
		}
	}
	fclose(fp);
	return flag;  //flag = 1��ʾ������ȷ��flag = 0��ʾ���벻��ȷ
}

//�ж��û�������鼮��Ż������Ƿ�������һ����ȷ
int judge_bk1(char str[N])
{
	FILE *fp;
	int flag = 0;
	fp = fopen("C:\\Users\\HP\\ͼ����Ϣ.txt","r");
	while(!feof(fp))
	{
		fscanf(fp,"%s %s %d",bk.num, bk.name, &bk.n);
		if(strcmp(bk.num,str) == 0 || strcmp(bk.name,str) == 0)
		{	
			flag = 1;
			break;
		}
	}
	fclose(fp);
	return flag;  //flag = 1��ʾ������ȷ��flag = 0��ʾ���벻��ȷ
}

//�ж��û�������鼮��ź������Ƿ���ȷ
int judge_bk2(char str1[N], char str2[N])
{
	FILE *fp;
	int flag = 0;
	fp = fopen("C:\\Users\\HP\\ͼ����Ϣ.txt","r");
	while(!feof(fp))
	{
		fscanf(fp,"%s %s %d",bk.num, bk.name, &bk.n);
		if(strcmp(bk.num,str1) == 0 && strcmp(bk.name,str2) == 0)
		{	
			flag = 1;
			break;
		}
	}
	fclose(fp);
	return flag;  //flag = 1��ʾ������ȷ��flag = 0��ʾ���벻��ȷ	
}

int main(int argc, char *argv[])
{
	int op;
	char account[N];
    printf("------��ӭʹ��ͼ�����Ϣ����ϵͳ------\n");
    if(argc != 3)                        //���û�����Ĳ�����������3
    {
        printf("������������\n");      //��ʾ������Ϣ 
        exit(0);
    }
    
	if(strcmp(argv[1],"-a")==0)
	{	
		if(judge_adm(argv[2]) == 1)
			mainmenu_adm();
		else
		{
			while(1)
			{
				system("cls");
				printf("��������û�������\n�������룬�밴1���˳�ϵͳ���밴2��\n");
				scanf("%d",&op);
				if(op == 1)
				{
					printf("�����������û�����\n");
					scanf("%s",account);
					if(judge_adm(account) == 1)//�����жϺ������жϹ���Ա������û����Ƿ���ȷ
						mainmenu_adm();
				}
				else if(op == 2)
					exit(0);
				else
					printf("�����������������!\n");
			}
		}
	}
	
	else if(strcmp(argv[1],"-u")==0)
	{
		if(judge_usr(argv[2]) == 1)
			mainmenu_usr();
		else
		{
			while(1)
			{
				system("cls");
				printf("��������û�������\n�������룬�밴1���˳�ϵͳ���밴2��\n");
				scanf("%d",&op);
				if(op == 1)
				{
					printf("�����������û�����\n");
					scanf("%s",account);
					if(judge_usr(account) == 1)//�����жϺ������ж��û�������û����Ƿ���ȷ
						mainmenu_usr();
				}
				else if(op == 2)
					exit(0);
				else
					printf("�����������������!\n");
			}
		}
	}
	
	else
	{
		printf("����δ֪�����");
		exit(0);
	}
	
	return 0;
}
