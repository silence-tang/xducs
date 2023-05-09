#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>

void delete_comment_bar(FILE *fp1,FILE *fp2)//�Զ��庯��������ɾ��/* */����ע��
{
	char ch;
	int flag=0;
	while(!feof(fp1))                       //ѭ�������ַ� 
	{

		ch = fgetc(fp1);
		if(ch == '\n')
			fprintf(fp2,"\n");              //����������з�������Ӧ�������ļ��д�ӡ���з� 
		else
		{
			switch(flag)
			{
				case 0:
				if (ch=='/')
					flag=1;
				else
					fprintf(fp2,"%c",ch);    //�������"/"�������ԭ�ַ� 
				break;
					
				case 1:
				if (ch=='*')                 //�������������"/*" 
					flag=2;
				else
				{
					fprintf(fp2,"/%c",ch);   //���ֻ����һ��"/"�������ĺ�����Ϊ"/" 
					flag=0;
				}
				break;
				
				case 2:
				if (ch=='*')
					flag=3;
				break;
					
				case 3:
				if(ch == '/')
					flag = 0;                //�������������"*/"������flagΪ0 
				else
					flag = 2;
				break;
			}
		}
	}
}

int main()
{
	
	FILE *p1,*p2,*p3,*p4;                        //�����ļ�ָ�� 
	char ch,str1[256],str2[256],str3[256];       //�����ַ����ַ����飬����ļ����� 
	int i,j,len,flag,count=1;
	p1 = fopen("d:\\test.cpp","r");              //��ֻ����ʽ��test.txt 
	p2 = fopen("d:\\test1.cpp","w");             //��ֻд��ʽ���ļ�test1.txt

	if(p1 == NULL || p2 == NULL)                 //���ĳ���ļ���ʧ�� 
	{
		printf("Can't open the file, strike any key to exit!");
		getch();
		exit(-1);                                //������˳���������-1 
	}

//Step1:ɾ��ԭʼ�ĵ�test�еĵ���ע�ͣ������ݴ浽test1��

	while(fgets(str1,200,p1)!=NULL)              //û���ļ���βʱѭ������ 
	{
		
		flag = 0;    
		len = strlen(str1);
		for(i=1;i<len;i++)
		{

			if(str1[i] == '/' && str1[i-1] == '/' )  //���ɨ�赽������"//"
			{
				
				str1[i-1] = '\n';                    //����һ��/��Ϊ'\n'����ʾ��һ��������� 
				str1[i] = '\0';                      //��������һ���ַ�������־'\0'
				fputs(str1,p2);                      //���µ���д��test1 
				flag = 1;                            //��flagΪ1��ʾ��һ���Ǿ���������У����������flag=0����� 
				break;
			}

		}

		if(flag == 0)                                //û��ע��ʱ��ֱ��д��ԭ������ 
			fputs(str1, p2);
	}

	fclose(p1); fclose(p2);
	printf("��һ�׶δ���ɹ�...\n");

//Step2:ɾ��ԭtest1�еĿ�״ע�ͣ������ݴ浽test2��

	p2 = fopen("d:\\test1.cpp","r");
	p3 = fopen("d:\\test2.cpp","w");             //���ļ�����ʼ�ڶ��׶β��� 

	if(p2 == NULL || p3 == NULL)
	{
		printf("Can't open the file, strike any key to exit!");
		getch();
		exit(-1);
	}

	delete_comment_bar(p2,p3);                   //ɾ��test1�еĿ�״ע��
	fclose(p2); fclose(p3);
	printf("�ڶ��׶δ���ɹ�...\n");

//Step3:��test2�����кţ������ݴ浽final�� 

	p3 = fopen("d:\\test2.cpp","r");
	p4 = fopen("d:\\final.cpp","w");             //���ļ�����ʼ�����׶β���
	
	if(p3 == NULL || p4 == NULL)
	{
		printf("Can't open the file, strike any key to exit!");
		getch();
		exit(-1);
	}
	
	while(fgets(str2,200,p3)!=NULL)              //û���ļ���βʱѭ������ 
	{

		fprintf(p4,"(%d)",count);                //����к� 
		fputs(str2,p4);                          //�к������Ϻ��ԭ�ļ���һ�е����ݴ��ݸ����ļ� 
		count++;                                 //�����к�ÿ�β���������1 
	}
	
	fclose(p3); fclose(p4);
	printf("�����׶δ���ɹ�...\nCԴ��������ϡ�");
	return 0;
}
