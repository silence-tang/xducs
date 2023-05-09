#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>

void delete_comment_bar(FILE *fp1,FILE *fp2)//自定义函数，用来删除/* */类型注释
{
	char ch;
	int flag=0;
	while(!feof(fp1))                       //循环读进字符 
	{

		ch = fgetc(fp1);
		if(ch == '\n')
			fprintf(fp2,"\n");              //如果读到换行符，则相应地在新文件中打印换行符 
		else
		{
			switch(flag)
			{
				case 0:
				if (ch=='/')
					flag=1;
				else
					fprintf(fp2,"%c",ch);    //如果不是"/"，则输出原字符 
				break;
					
				case 1:
				if (ch=='*')                 //如果出现连续的"/*" 
					flag=2;
				else
				{
					fprintf(fp2,"/%c",ch);   //如果只出现一个"/"，则它的后面仍为"/" 
					flag=0;
				}
				break;
				
				case 2:
				if (ch=='*')
					flag=3;
				break;
					
				case 3:
				if(ch == '/')
					flag = 0;                //如果出现连续的"*/"，则置flag为0 
				else
					flag = 2;
				break;
			}
		}
	}
}

int main()
{
	
	FILE *p1,*p2,*p3,*p4;                        //定义文件指针 
	char ch,str1[256],str2[256],str3[256];       //定义字符及字符数组，存放文件内容 
	int i,j,len,flag,count=1;
	p1 = fopen("d:\\test.cpp","r");              //以只读方式打开test.txt 
	p2 = fopen("d:\\test1.cpp","w");             //以只写方式打开文件test1.txt

	if(p1 == NULL || p2 == NULL)                 //如果某个文件打开失败 
	{
		printf("Can't open the file, strike any key to exit!");
		getch();
		exit(-1);                                //报错后退出，并返回-1 
	}

//Step1:删除原始文档test中的单行注释，新内容存到test1中

	while(fgets(str1,200,p1)!=NULL)              //没到文件结尾时循环操作 
	{
		
		flag = 0;    
		len = strlen(str1);
		for(i=1;i<len;i++)
		{

			if(str1[i] == '/' && str1[i-1] == '/' )  //如果扫描到连续的"//"
			{
				
				str1[i-1] = '\n';                    //将第一个/改为'\n'，表示这一行输入结束 
				str1[i] = '\0';                      //在最后添加一个字符结束标志'\0'
				fputs(str1,p2);                      //将新的行写入test1 
				flag = 1;                            //置flag为1表示这一行是经过处理的行，区别于最后flag=0的情况 
				break;
			}

		}

		if(flag == 0)                                //没有注释时，直接写入原来的行 
			fputs(str1, p2);
	}

	fclose(p1); fclose(p2);
	printf("第一阶段处理成功...\n");

//Step2:删除原test1中的块状注释，新内容存到test2中

	p2 = fopen("d:\\test1.cpp","r");
	p3 = fopen("d:\\test2.cpp","w");             //打开文件，开始第二阶段操作 

	if(p2 == NULL || p3 == NULL)
	{
		printf("Can't open the file, strike any key to exit!");
		getch();
		exit(-1);
	}

	delete_comment_bar(p2,p3);                   //删除test1中的块状注释
	fclose(p2); fclose(p3);
	printf("第二阶段处理成功...\n");

//Step3:给test2加上行号，新内容存到final中 

	p3 = fopen("d:\\test2.cpp","r");
	p4 = fopen("d:\\final.cpp","w");             //打开文件，开始第三阶段操作
	
	if(p3 == NULL || p4 == NULL)
	{
		printf("Can't open the file, strike any key to exit!");
		getch();
		exit(-1);
	}
	
	while(fgets(str2,200,p3)!=NULL)              //没到文件结尾时循环操作 
	{

		fprintf(p4,"(%d)",count);                //添加行号 
		fputs(str2,p4);                          //行号添加完毕后把原文件这一行的内容传递给新文件 
		count++;                                 //保持行号每次操作后自增1 
	}
	
	fclose(p3); fclose(p4);
	printf("第三阶段处理成功...\nC源程序处理完毕。");
	return 0;
}
