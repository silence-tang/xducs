#include<stdio.h>
#include<stdlib.h>
#include<windows.h>

int main()
{
	HANDLE hEvent=OpenEvent(EVENT_ALL_ACCESS,TRUE,"event");//�������¼�
	//OpenEvent��һ����������������ִ�з����¼�����ľ��
	Sleep(1000);
	printf("Signal the event to Parent?[Y\\N]:");
	char ch;
	scanf("%c", &ch);//�����ַ� 
	if(ch=='Y')
	{
		SetEvent(hEvent); //���¼���Ϊ���ź�״̬
	}
	else
	{
	   return 0;  //�˳� 
	}
	Sleep(5000);  //����һ��ʱ��
	return 0;
}
