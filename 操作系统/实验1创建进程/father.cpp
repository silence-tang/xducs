#include<stdio.h>
#include<windows.h>
int main()
{
	STARTUPINFO sui;             //������Ϣ�ṹ�� 
	PROCESS_INFORMATION pi;      //�ڴ�������ʱ��ص����ݽṹ֮һ���ýṹ�����й��½��̼������̵߳���Ϣ��
	ZeroMemory(&sui,sizeof(sui));
	sui.cb = sizeof(STARTUPINFO);//��cb��Ա����Ϊ��Ϣ�ṹ��Ĵ�С
	int sum = 0;
	char content[100] = "";      //��ʼ��content�ַ�������������ļ����� 
	if(CreateProcess("D:\\child.exe",NULL,NULL,NULL,FALSE,CREATE_NEW_CONSOLE,NULL,NULL,&sui,&pi))//�������� 
	{
		printf("�Ѵ���һ���ӽ���\n");
		for(int i = 1; i <= 100; i++)
		{
			sum = sum + i;       //��1-100֮�� 
			Sleep(5);            //�ӳ�ʱ��5ms
			printf("Now, sum = %d\n",sum);
		}
		WaitForSingleObject(pi.hProcess,INFINITE);//һֱ����ȥֱ�����̽��� 
		FILE *fp = fopen("D:\\test.txt","r");
		fread(content,sizeof(char),100,fp);       //���ö�ȡ�ļ����ݵ���ز��� 
		printf("�ӽ��̴������ļ���������:\n\n%s\n\n",content);
		fclose(fp);
	}
	else
		printf("�����ӽ���ʧ��\n");
	printf("ʵ�������");
	return 0;
}
