#include<stdio.h>
#include<windows.h>

int main()
{
	STARTUPINFO si;//�������̵�׼������ 
	PROCESS_INFORMATION pi;
	ZeroMemory(&pi,sizeof(pi));
	ZeroMemory(&si,sizeof(si));
	si.cb=sizeof(STARTUPINFO);
	if(!CreateProcess("D:\\child.exe",NULL,NULL,NULL,FALSE,CREATE_NEW_CONSOLE,NULL,NULL,&si,&pi))//����һ�������¼�
	{
		printf("�����ӽ���ʧ�ܣ�\n");
		return 0;
	}
	printf("Wait for event.\n");
	HANDLE hEvent=CreateEvent(NULL,FALSE,FALSE,"event");
	if(WAIT_TIMEOUT==WaitForSingleObject(hEvent,10000))//�ȴ��¼��ź�
	{
		printf("�ȴ��¼��ź�ʧ�ܣ�\n");
		return 0;//�˳� 
	}
	printf("Get the event.\n");
	CloseHandle(hEvent);//�رվ�� 
	return 0;
}
