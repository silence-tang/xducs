#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h> 
#include <conio.h>
#define N 20

//图书信息的结构体定义
struct book
{
	char num[N];           //图书编号
	char name[N];          //图书书名
	int n;                 //图书数量
    struct book *p;        //结构体指针
};
struct book bk;            //定义结构体变量bk

//读者信息的结构体定义
struct reader
{
	char num[N];           //读者编号
	char name[N];          //读者姓名
	char bknum1[N];        //借阅的第一本图书编号
	char bknum2[N];        //借阅的第二本图书编号
    struct reader *p1;     //结构体指针
};
struct reader rd;          //定义结构体变量rd

/*综合系统用到的函数*/
/* 管理员相关功能 */
void func_adm(int choice); //管理员功能选择
void mainmenu_adm();       //管理员界面主目录
void tjtsxx();             //添加图书信息
void sctsxx();             //删除图书信息（按编号或者书名）
void xgtsxx();             //修改图书信息（按编号或者书名）
void printall_book();      //输出所有图书信息
void tjdzxx();             //添加读者信息
void scdzxx();             //删除读者信息（按编号或者姓名）
void xgdzxx();             //修改读者信息（按编号或者姓名）
void printall_reader();    //输出所有读者信息
/* 读者相关功能 */
void func_usr(int choice); //读者功能选择
void mainmenu_usr();       //读者界面主目录
void borrow();             //借阅图书功能
void giveback();           //归还图书功能
void chaxun();             //按编号或书名查询图书信息
void chaxun_borrowers();   //按编号或书名查询图书被哪些读者借走
void display();            //显示当前用户已借阅的书籍
/*判断函数*/
int judge_adm(char str[N]);                //判断管理员输入的用户名是否正确
int judge_usr(char str[N]);                //判断用户输入的用户名或读者编号是否至少有一个正确
int judge_bk1(char str[N]);                //判断用户输入的书籍编号和书名是否至少有一个正确
int judge_bk2(char str1[N], char str2[N]); //判断用户输入的书籍编号和书名是否都正确

//管理员界面主目录
void mainmenu_adm()
{
	system("cls");//清屏 
    char op[N];
    int OP;
    printf("------尊敬的管理员您好，欢迎登录图书馆管理系统！------\n");
    printf("\n1.添加图书信息\n");
    printf("\n2.显示所有图书信息\n");
    printf("\n3.按编号/书名删除图书信息\n");
    printf("\n4.按编号/书名修改图书信息\n");
    printf("----------------------------------");
    printf("\n5.添加读者信息\n");
    printf("\n6.显示所有读者信息\n");
    printf("\n7.按编号/姓名删除读者信息\n");
    printf("\n8.按编号/姓名修改读者信息\n");
    printf("\n9.退出系统\n");
    
    printf("\n请输入您的选择：\n");
    scanf("%s",op);
    OP = atoi(op);
	if(OP >= 1 && OP <= 9)//当输入的序号在1-9范围内时 
		func_adm(OP);
	
	else//若输入不正确 
	{
    	printf("---  您输入的序号有误,请重新输入!  ---\n");
    	system("pause");
    	mainmenu_adm();
	}
}

//管理员功能选择 
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

//添加图书信息
void tjtsxx()
{
	system("cls");
	FILE *fp;  //声明文件指针fp，指向某个文件 
	int a;
	if((fp = fopen("C:\\Users\\HP\\图书信息.txt","a")) == NULL)//以附加的方式打开只写文件，写入的数据被追加到文件尾 
	{	
		printf("File open error!\n");
		exit(0);
	}
	
	loop10:
	printf("请输入图书编号：\n");//0-999
	scanf("%s",bk.num);
	printf("请输入图书书名：\n");
	scanf("%s",bk.name);
	printf("请输入图书数量：\n");//0-20
	scanf("%d",&bk.n);           //用户输入 
	
	if((atoi(bk.num) >= 1 && atoi(bk.num) <= 999) && (bk.n >= 0 && bk.n <= 20))//输入正确时 
		fprintf(fp,"%s %s %d                    \n",bk.num, bk.name, bk.n);
	else
	{
		while(1)
		{
			system("cls");
			printf("输入错误，重新输入请按1，返回主菜单请按2：\n");
			scanf("%d",&a);
			if(a == 1)
				goto loop10;
			else if(a == 2)
			{
				fclose(fp);
				mainmenu_adm();
			}
			else
				printf("输入错误，请重新输入!\n");
		}
	}
	
	fclose(fp);
	
	while(1)//操作完毕，进行后续衔接 
	{
		system("cls");
		printf("添加完毕，返回主菜单请按1，继续添加请按2\n");
		scanf("%d",&a);
		if(a == 1)
			mainmenu_adm();
		else if(a == 2)
			tjtsxx();
		else
			printf("输入错误，请重新输入!\n");	
	}
}	

//删除图书信息 
void sctsxx()
{
	system("cls");
	struct book bk1[50];
	struct book bk2[50];  //定义两个book类型的结构体数组 
	FILE *fp,*fp1;
	int a, j, n = 0, i = 0;
	char aim[20];
	loop1:  
	printf("请输入目标图书的编号或书名：\n");
	scanf("%s",aim);
	if(judge_bk1(aim) == 0)
	{
		while(1)
		{
			system("cls");
			printf("编号或书名输入有误！重新输入请按1，返回主菜单请按2\n");
			scanf("%d",&a);
			if(a == 1)
				goto loop1;
			else if(a == 2)
				mainmenu_adm();
			else
				printf("输入错误，请重新输入!\n");
		}
	}
	
	else  //当输入正确时 
	{
		if((fp = fopen("C:\\Users\\HP\\图书信息.txt","r")) == NULL)
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
		}//绕开待删除的那本书，将其他书的信息全部给新的结构体数组保存 
		
		fclose(fp);
	
		if((fp = fopen("C:\\Users\\HP\\图书信息.txt","w")) == NULL)//打开只写文件，因为文件存在，故文件长度清零 
		{
			printf("file open error!");
			exit(0);
		}
		
		for(j = 0; j < i - 1; j++)  //若不是i-1，则数组越界 
			fprintf(fp,"%s %s %d                    \n",bk2[j].num ,bk2[j].name, bk2[j].n);
		//从文件开头开始，写入除了待删除的那本书外其他书的所有信息，完成删除操作 //绕开待删除的那本书，将其他书的信息全部给新的结构体数组保存 
		fclose(fp);
	}
	
	while(1)
	{
		system("cls");
		printf("删除完毕，返回主菜单请按1，继续删除请按2\n");
		scanf("%d",&a);
		if(a == 1)
			mainmenu_adm();
		else if(a == 2)
			sctsxx();
		else
			printf("输入错误，请重新输入!\n");	
	}
}

//修改图书信息
void xgtsxx()
{
	system("cls");
	FILE *fp;
	char aim[20], num[20], weishu[20];
	int a, n, flag;
	loop2:
	printf("请输入目标图书的编号或书名：\n");
	scanf("%s", aim);
	if(judge_bk1(aim) == 0)
	{
		while(1)
		{
			system("cls");
			printf("编号或书名输入有误！重新输入请按1，返回主菜单请按2\n");
			scanf("%d",&a);
			if(a == 1)
				goto loop2;
			else if(a == 2)
				mainmenu_adm();
			else
				printf("输入错误，请重新输入!\n");
		}
	}
	
	else  //当输入正确时 
	{
		if((fp = fopen("C:\\Users\\HP\\图书信息.txt","r+")) == NULL)//打开可读写文件
		{
			printf("File open error!");
			exit(0);
		}
		
		printf("修改书籍编号，请按1，修改书籍存量，请按2\n");
		scanf("%d",&flag);
		if(flag == 1)
		{
			while(!feof(fp))
			{	
				fscanf(fp,"%s %s %d",bk.num, bk.name, &bk.n);
				if(strcmp(bk.num,aim) == 0 || strcmp(bk.name,aim) == 0)
				{
					itoa(bk.n,weishu,10);
					fseek(fp,-(2 + strlen(weishu) + strlen(bk.name) + strlen(bk.num)),SEEK_CUR); //回滚指针
					printf("请输入新的书籍编号:\n");
					scanf("%s",&num);
					fprintf(fp,"%s %s %d          ",num, bk.name, bk.n); //覆盖写入
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
					fseek(fp,-(strlen(weishu)),SEEK_CUR); //回滚指针
					printf("请输入新的书籍存量:\n");
					scanf("%d",&n);
					fprintf(fp,"%d          ",n);    //覆盖写入
					break;
				}
			}
		}
	
		fclose(fp); 
	}
	
	while(1)
	{
		system("cls");
		printf("修改完毕，返回主菜单请按1，继续修改请按2\n");
		scanf("%d",&a);
		if(a == 1)
			mainmenu_adm();
		else if(a == 2)
			xgtsxx();
		else
			printf("输入错误，请重新输入!\n");
	}
}

//输出所有图书信息 
void printall_book()
{
	FILE *fp;
	printf("编号    书名        库存\n");
	if((fp = fopen ("C:\\Users\\HP\\图书信息.txt","r")) == NULL)
	{
		printf("File open error!\n");
		exit (0);
	}
	
	while(!feof (fp))
	{
		fscanf(fp,"%s %s %d",bk.num, bk.name, &bk.n);
		if(feof(fp) == 0)//防止最后一行多输出一遍 
			printf("%s      %s       %d\n",bk.num, bk.name, bk.n);
	}
	
	fclose(fp);
	system("pause");
    mainmenu_adm();
}

//添加读者信息
void tjdzxx()
{
	system("cls");
	int a;
	FILE *fp;
	if((fp = fopen("C:\\Users\\HP\\读者信息.txt","a")) == NULL)//以附加的方式打开只写文件，写入的数据被加到文件尾 
	{	
		printf("File open error!\n");
		exit(0);
	}
	loop11:
	printf("请输入读者编号：\n");//0-999
	scanf("%s",rd.num);
	printf("请输入读者用户名：\n");
	scanf("%s",rd.name);
	printf("请输入该读者借阅的第一本书籍的编号(若该读者未借书则编号用---代替)：\n");//0-999或--- 
	scanf("%s",&rd.bknum1);
	printf("请输入该读者借阅的第二本书籍的编号(若该读者未借书则编号用---代替)：\n");//0-999或---
	scanf("%s",&rd.bknum2);
	
	if((atoi(rd.num) >= 1 && atoi(rd.num) <= 999) && ((atoi(rd.bknum1) >= 1 && atoi(rd.bknum1) <= 999) || strcmp(rd.bknum1,"---") == 0) && ((atoi(rd.bknum2) >= 1 && atoi(rd.bknum2) <= 999) || strcmp(rd.bknum2,"---") == 0)) //输入正确时 
		fprintf(fp,"%s %s %s %s                    \n",rd.num, rd.name, rd.bknum1, rd.bknum2);
	else
	{
		while(1)
		{
			system("cls");
			printf("输入错误，重新输入请按1，返回主菜单请按2：\n");
			scanf("%d",&a);
			if(a == 1)
				goto loop11;
			else if(a == 2)
			{
				fclose(fp);
				mainmenu_adm();
			}
			else
				printf("输入错误，请重新输入!\n");
		}
	}
	
	fclose(fp);
	
	while(1)
	{
		system("cls");
		printf("添加完毕，返回上一级请按1，继续添加请按2\n");
		scanf("%d",&a);
		if(a == 1)
			mainmenu_adm();
		else if(a == 2)
			tjdzxx();
		else
			printf("输入错误，请重新输入!\n");
	}
}	

//删除读者信息 
void scdzxx()
{
	system("cls");
	struct reader rd1[20];
	struct reader rd2[20];
	FILE *fp,*fp1;		
	int a, j, n = 0, i = 0;
	char aim[20];
	loop3: 
	printf("请输入读者的编号或用户名：\n");
	scanf("%s",aim);
	if(judge_usr(aim) == 0)
	{
		while(1)
		{
			system("cls");
			printf("编号或用户名输入有误！重新输入请按1，返回主菜单请按2\n");
			scanf("%d",&a);
			if(a == 1)
				goto loop3;
			else if(a == 2)
				mainmenu_adm();
			else
				printf("输入错误，请重新输入!\n");
		}
	}
	
	else  //当输入正确时 
	{
		if((fp = fopen("C:\\Users\\HP\\读者信息.txt","r")) == NULL)
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
		}//绕开待删除的那本书，将其他书的信息全部给新的结构体数组保存 
	
		fclose(fp);
		
		if((fp = fopen("C:\\Users\\HP\\读者信息.txt","w")) == NULL)//打开只写文件，若文件存在则文件长度清零 
		{
			printf("file open error!");
			exit(0);
		}
		
		for(j = 0; j < i - 1; j++)  //若不是i-1，则数组越界 
			fprintf(fp,"%s %s %s %s                    \n",rd2[j].num ,rd2[j].name, rd2[j].bknum1, rd2[j].bknum2);
		//从文件开头开始，写入除了待删除的那本书外其他书的所有信息，完成删除操作 	
		fclose(fp);
	}
	
	while(1)
	{
		system("cls");
		printf("删除完毕，返回主菜单请按1，继续删除请按2\n");
		scanf("%d",&a);
		if(a == 1)
			mainmenu_adm();
		else if(a == 2)
			scdzxx();
		else
			printf("输入错误，请重新输入!\n");
	}
}

//修改读者信息
void xgdzxx()
{
	system("cls");
	FILE *fp;
	char aim[20], num[20], name[20];
	int a, flag;
	loop4:
	printf("请输入目标读者的编号或用户名：\n");
	scanf("%s",aim);
	if(judge_usr(aim) == 0)
	{
		while(1)
		{
			system("cls");
			printf("编号或用户名输入有误！重新输入请按1，返回主菜单请按2\n");
			scanf("%d",&a);
			if(a == 1)
				goto loop4;
			else if(a == 2)
				mainmenu_adm();
			else
				printf("输入错误，请重新输入!\n");
		}
	}
	
	else  //当输入正确时 
	{
		if((fp = fopen("C:\\Users\\HP\\读者信息.txt","r+")) == NULL)//打开可读写文件
		{
			printf("File open error!\n");
			exit (0);
		}
		
		printf("修改读者编号，请按1，修改读者姓名，请按2:\n");
		scanf("%d",&flag);
		if(flag == 1)
		{
			while(!feof(fp))
			{
				fscanf(fp,"%s %s %s %s",rd.num, rd.name, rd.bknum1, rd.bknum2);
				if(strcmp(rd.num,aim) == 0 || strcmp(rd.name,aim) == 0)
				{
					fseek(fp,-(3 + strlen(rd.bknum2) + strlen(rd.bknum1) + strlen(rd.name) + strlen(rd.num)),SEEK_CUR);  //回滚指针
					printf("请输入新的读者编号:\n");
					scanf("%s",&num);
					fprintf(fp,"%s %s %s %s          ",num, rd.name, rd.bknum1, rd.bknum2);//覆盖写入
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
					fseek(fp,-(2 + strlen(rd.bknum2) + strlen(rd.bknum1) + strlen(rd.name)),SEEK_CUR);//回滚指针
					printf("请输入新的读者姓名:\n");
					scanf("%s",&name);
					fprintf(fp,"%s %s %s          ",name, rd.bknum1, rd.bknum2); //覆盖写入
					break;
				}
			}
		}
	 
		fclose(fp);
	}
	
	while(1)
	{
		system("cls");
		printf("修改完毕，返回上一级请按1，继续修改请按2\n");
		scanf("%d",&a);
		if(a == 1)
			mainmenu_adm();
		else if(a == 2)
			xgdzxx();
		else
			printf("输入错误，请重新输入!\n");
	}
} 

//输出所有读者信息 
void printall_reader()
{
	FILE *fp;
	printf("编号     姓名      书籍1      书籍2\n");
	if((fp = fopen ("C:\\Users\\HP\\读者信息.txt","r")) == NULL)
	{
		printf("File open error!\n");
		exit (0);
	}
	
	while(!feof(fp))
	{
		fscanf(fp,"%s %s %s %s",rd.num, rd.name, rd.bknum1, rd.bknum2);
		if(feof(fp) == 0)//防止最后一行多输出一遍 
			printf("%s        %s        %s        %s\n",rd.num, rd.name, rd.bknum1, rd.bknum2);
	}
	
	fclose(fp);
	system("pause");
    mainmenu_adm();
}

/*------------------------------------------------------------------------------------------------------*/

//读者界面主目录
void mainmenu_usr()
{
	system("cls");
    int choice;
    printf("------亲爱的读者您好，欢迎登录图书馆管理系统！------\n");
    printf("\n1.借阅书籍\n");
    printf("\n2.归还书籍\n");
    printf("\n3.按编号/书名查询图书信息\n");
    printf("\n4.按编号查询书籍的所有借阅者\n");
    printf("\n5.显示当前借阅的书籍\n"); 
    printf("\n6.退出系统\n");
    printf("\n请输入您的选择：\n");
	
    scanf("%d",&choice);
    
	if(choice<1||choice>6)
	{
        printf("---  您输入的序号有误,请重新输入!  ---\n"); 
		mainmenu_usr();
	}
	
	else 
		func_usr(choice);
}

//读者功能选择 
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

//按编号或书名查询图书信息 
void chaxun()
{
	system("cls");
	FILE *fp;
	char aim[20];
	int flag = 0;
	printf("请输入图书的编号或书名：\n");
	scanf("%s",aim);
	printf("编号     书名     库存\n");
	if((fp = fopen("C:\\Users\\HP\\图书信息.txt","r")) == NULL)
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
				flag++;//flag自增1，表示在图书数据中找到了这本书 
			}
		}
	}
	
	if(flag == 0)
    	printf("\n没有这本书!\n\n");
    
	fclose(fp);
    system("pause");
    mainmenu_usr();
}

//按编号或书名查询某本图书被哪些读者借走
void chaxun_borrowers()
{
	system("cls");
	FILE *fp, *fp1;
	int a, flag = 0;
	char aim[20];
	loop12:
	printf("请输入图书的编号或书名：\n");
	scanf("%s", aim);
	if(judge_bk1(aim) == 0)
	{
		while(1)
		{
			system("cls");
			printf("编号或书名输入有误！重新输入请按1，返回主菜单请按2\n");
			scanf("%d",&a);
			if(a == 1)
				goto loop12;
			else if(a == 2)
				mainmenu_usr();
			else
				printf("输入错误，请重新输入!\n");
		}
	}
	
	else
	{
		printf("编号     姓名\n");
		if((fp = fopen("C:\\Users\\HP\\读者信息.txt","r")) == NULL)
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
				flag++;//flag自增1，表示在读者数据中找到了这本书 
			}
		}
	
		if(flag == 0)
    	printf("\n没有读者借阅过这本书!\n\n");
	}

	fclose(fp);
    system("pause");
    mainmenu_usr();
}

//借阅图书功能：读者信息作相应的修改；图书信息当中对应的书籍的数量自减1 
void borrow()
{
	FILE *fp, *fp1;
	char aim_num[20], aim_name[20], weishu[20];
	int a, flag1 = 0, flag2 = 0, flag3 = 0; 
	loop5:
	printf("请输入您需要借阅的书籍的编号和书名\n");
	printf("编号:  \n");
	scanf("%s",aim_num);
	printf("书名:  \n");
	scanf("%s",aim_name);
	if(judge_bk2(aim_num,aim_name) == 0)//调用判断函数，判断用户输入的图书编号或书名是否正确 
	{
		printf("编号或书名输入有误！重新输入请按1，返回主菜单请按2\n");
		scanf("%d",&a);
		if(a == 1)
			goto loop5;
		else
			mainmenu_usr(); 
	}
	
	else  //输入正确时
	{
		if((fp = fopen ("C:\\Users\\HP\\图书信息.txt","r+")) == NULL)//打开可读写文件 
		{
			printf("File open error!\n");
			exit (0);
		}
		
		while(!feof(fp))
		{
			fscanf(fp,"%s %s %d",bk.num, bk.name, &bk.n);
			if(strcmp(bk.num,aim_num) == 0 && strcmp(bk.name,aim_name) == 0)
			{
				if(bk.n == 0) //库存为0时 
				{
					printf("抱歉，该书籍当前的库存为0！重新输入请按1，返回主菜单请按2\n");
					scanf("%d",&a);
					if(a == 1)
						goto loop5;
					else
						mainmenu_usr(); 
				}
				
				else //库存不为0时 
				{
					itoa(bk.n,weishu,10);
					fseek(fp,-(strlen(weishu)),SEEK_CUR);//回滚指针
					fprintf(fp,"%d          ",bk.n - 1); //覆盖写入
					break;
				}
			}
		}
	}  //实现图书数量变化
	                                             
	fclose(fp);
	
	char aim[20];
	loop6:
	printf("请输入您的读者编号或用户名(姓名)：\n");
	scanf("%s",&aim);
	if(judge_usr(aim) == 0)//调用判断函数，判断用户输入的读者编号或用户名是否正确 
	{
		printf("编号或用户名输入有误！重新输入请按1，返回主菜单请按2\n");
		scanf("%d",&a);
		if(a == 1)
			goto loop6;
		else
			mainmenu_usr();
	}
	
	else  //输入正确时 
	{
		if((fp1 = fopen ("C:\\Users\\HP\\读者信息.txt","r+")) == NULL)//打开可读写文件 
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
					printf("目前您的书籍借阅数量已经达到两本，暂时无法进行借书操作！\n");
					system("pause");
    				mainmenu_usr();
				}
				else if(strcmp(rd.bknum1,"---") == 0)
				{
					fseek(fp1,-(1 + strlen(rd.bknum2) + strlen(rd.bknum1)),SEEK_CUR);                  //回滚指针
					fprintf(fp1,"%s %s          ",aim_num, rd.bknum2); //覆盖写入
					break;
				}
				else
				{
					fseek(fp1,-(strlen(rd.bknum2)),SEEK_CUR);     //回滚指针
					fprintf(fp1,"%s          ",aim_num);  //覆盖写入
					break;
				}
			}
		}
	}
	
	fclose(fp1);
	printf("借阅完毕！本次您借阅的书籍编号为：%s，书名为：%s\n",aim_num, aim_name); 
    system("pause");
    mainmenu_usr();
} 

//归还图书功能：读者信息作相应的修改；图书信息当中对应的书籍的数量自增1
void giveback()
{	
	FILE *fp, *fp1;
	int a, flag1 = 0, flag2 = 0, flag3 = 0;
	char aim_num[20], aim_name[20], weishu[20];
	loop7:
	printf("请输入您需要归还的书籍的编号和书名:\n");
	printf("书籍编号:  \n");
	scanf("%s",aim_num);
	printf("书名:  \n");
	scanf("%s",aim_name);
	if(judge_bk2(aim_num,aim_name) == 0)//调用判断函数，判断用户输入的图书编号或书名是否正确 
	{
		printf("编号或书名输入有误！重新输入请按1，返回主菜单请按2\n");
		scanf("%d",&a);
		if(a == 1)
			goto loop7;
		else
			mainmenu_usr();
	}
		
	else   //输入正确时 
	{
		char aim[20];
		loop8:
		printf("请输入您的读者编号或用户名(姓名)：\n");
		scanf("%s",&aim);
		if(judge_usr(aim) == 0)//调用判断函数，判断用户输入的读者编号或用户名是否正确 
		{
			printf("编号或用户名输入有误！重新输入请按1，返回主菜单请按2\n");
			scanf("%d",&a);
			if(a == 1)
				goto loop8;
			else
				mainmenu_usr();
		}
	
		else   //输入正确时
		{
			if((fp1 = fopen ("C:\\Users\\HP\\读者信息.txt","r+")) == NULL)//打开可读写文件
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
						printf("目前您借阅的书籍数量为0，暂时无法进行还书操作！\n");
						system("pause");
    					mainmenu_usr();
					}
					else if(strcmp(rd.bknum1,aim_num) != 0 && strcmp(rd.bknum2,aim_num) != 0)
					{
						printf("您未借阅该书籍！重新输入请按1，返回主菜单请按2：\n");
						scanf("%d",&a);
						if(a == 1)
							goto loop7;
						else
							mainmenu_usr();
					}
					else if(strcmp(rd.bknum1,aim_num) == 0  || strcmp(rd.bknum2,aim_num) != 0 )
					{
						fseek(fp1,-(1 + strlen(rd.bknum2) + strlen(rd.bknum1)),SEEK_CUR);//回滚指针
						fprintf(fp1,"--- %s          ",rd.bknum2);//覆盖写入
						break;
					}
					else
					{
						fseek(fp1,-(strlen(rd.bknum2)),SEEK_CUR);//回滚指针
						fprintf(fp1,"---          ");//覆盖写入
						break;				
					}
				}
			}

			if((fp = fopen ("C:\\Users\\HP\\图书信息.txt","r+")) == NULL)//打开可读写文件
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
					fseek(fp,-(strlen(weishu)),SEEK_CUR); //回滚指针
					fprintf(fp,"%d          ",bk.n + 1);  //覆盖写入
					break;
				}
			}
			fclose(fp);
		}
		fclose(fp1);
	}

	printf("还书完毕！本次您归还的书籍编号为：%s，书名为：%s\n",aim_num, aim_name);
    system("pause");
    mainmenu_usr();
}

//显示当前读者已借阅的书籍 
void display()
{
	FILE *fp;
	char aim[20];
	int a;
	loop9:
	printf("请再次输入您的读者编号或用户名(姓名)：\n");
	scanf("%s",&aim);
	if(judge_usr(aim) == 0)//调用判断函数，判断用户输入的读者编号或用户名是否正确 
	{
		printf("编号或用户名输入有误！重新输入请按1，返回主菜单请按2\n");
		scanf("%d",&a);
		if(a == 1)
			goto loop9;
		else
			mainmenu_usr();
	}
	
	else   //输入正确时 
	{
		printf("编号     姓名      书籍1      书籍2\n");
		if((fp = fopen ("C:\\Users\\HP\\读者信息.txt","r")) == NULL)
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
//判断管理员输入的用户名是否正确
int judge_adm(char str[N])
{
	FILE *fp;
	char num[N], name[N];
	int flag = 0;
	fp = fopen("C:\\Users\\HP\\管理员信息.txt","r");
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
	return flag;  //flag = 1表示输入正确，flag = 0表示输入不正确
} 
//判断用户输入的用户名或读者编号是否至少有一个正确
int judge_usr(char str[N])
{
	FILE *fp;
	int flag = 0;
	fp = fopen("C:\\Users\\HP\\读者信息.txt","r");
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
	return flag;  //flag = 1表示输入正确，flag = 0表示输入不正确
}

//判断用户输入的书籍编号或书名是否至少有一个正确
int judge_bk1(char str[N])
{
	FILE *fp;
	int flag = 0;
	fp = fopen("C:\\Users\\HP\\图书信息.txt","r");
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
	return flag;  //flag = 1表示输入正确，flag = 0表示输入不正确
}

//判断用户输入的书籍编号和书名是否都正确
int judge_bk2(char str1[N], char str2[N])
{
	FILE *fp;
	int flag = 0;
	fp = fopen("C:\\Users\\HP\\图书信息.txt","r");
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
	return flag;  //flag = 1表示输入正确，flag = 0表示输入不正确	
}

int main(int argc, char *argv[])
{
	int op;
	char account[N];
    printf("------欢迎使用图书馆信息管理系统------\n");
    if(argc != 3)                        //若用户输入的参数数量不是3
    {
        printf("参数数量错误！\n");      //显示错误信息 
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
				printf("您输入的用户名有误！\n重新输入，请按1，退出系统，请按2：\n");
				scanf("%d",&op);
				if(op == 1)
				{
					printf("请输入您的用户名：\n");
					scanf("%s",account);
					if(judge_adm(account) == 1)//调用判断函数，判断管理员输入的用户名是否正确
						mainmenu_adm();
				}
				else if(op == 2)
					exit(0);
				else
					printf("输入错误，请重新输入!\n");
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
				printf("您输入的用户名有误！\n重新输入，请按1，退出系统，请按2：\n");
				scanf("%d",&op);
				if(op == 1)
				{
					printf("请输入您的用户名：\n");
					scanf("%s",account);
					if(judge_usr(account) == 1)//调用判断函数，判断用户输入的用户名是否正确
						mainmenu_usr();
				}
				else if(op == 2)
					exit(0);
				else
					printf("输入错误，请重新输入!\n");
			}
		}
	}
	
	else
	{
		printf("错误，未知的命令！");
		exit(0);
	}
	
	return 0;
}
