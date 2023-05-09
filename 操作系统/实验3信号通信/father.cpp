#include<stdio.h>
#include<windows.h>

int main()
{
	STARTUPINFO si;//创建进程的准备工作 
	PROCESS_INFORMATION pi;
	ZeroMemory(&pi,sizeof(pi));
	ZeroMemory(&si,sizeof(si));
	si.cb=sizeof(STARTUPINFO);
	if(!CreateProcess("D:\\child.exe",NULL,NULL,NULL,FALSE,CREATE_NEW_CONSOLE,NULL,NULL,&si,&pi))//创建一个有名事件
	{
		printf("创建子进程失败！\n");
		return 0;
	}
	printf("Wait for event.\n");
	HANDLE hEvent=CreateEvent(NULL,FALSE,FALSE,"event");
	if(WAIT_TIMEOUT==WaitForSingleObject(hEvent,10000))//等待事件信号
	{
		printf("等待事件信号失败！\n");
		return 0;//退出 
	}
	printf("Get the event.\n");
	CloseHandle(hEvent);//关闭句柄 
	return 0;
}
