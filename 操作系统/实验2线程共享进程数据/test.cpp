#include<stdio.h>
#include<windows.h>
static int count;//����ȫ�ֹ������� 
DWORD WINAPI ThreadProc(LPVOID IpParameter)//�̺߳��������й涨���߳�Ҫ������ 
{
	printf("���߳����У�\n\n");
	for(count=1;count<=10;count=count+2)//���߳���ֱ������count�������и��Ĳ���������� 
	{
		printf("Now,�߳�count = %d\n\n",count);
	}
	printf("�̵߳ȴ�3����...\n\n");
	Sleep(3000);//����3s�ĵȴ�ʱ�� 
	return 0;//�˳����� 
}

int main()
{
	count=20;
	printf("�������У�\n\n����count=%d\n\n",count);//��ʾcount������ֵ 
	HANDLE hEvent=CreateThread(NULL,0,ThreadProc,NULL,0,NULL);//�������̲߳���������߳���Ϣ 
	WaitForSingleObject(hEvent,INFINITE);//�ȴ��߳����н��� 
	CloseHandle(hEvent);//�رվ�� 
	printf("���߳̽�����\n");
	printf("���̽�����\n\n");
	printf("Now,count = %d",count);//��ʾcount����������ֵ 
	return 0;
}
