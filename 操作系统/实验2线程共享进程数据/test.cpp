#include<stdio.h>
#include<windows.h>
static int count;//定义全局共享数据 
DWORD WINAPI ThreadProc(LPVOID IpParameter)//线程函数，其中规定了线程要做的事 
{
	printf("新线程运行！\n\n");
	for(count=1;count<=10;count=count+2)//在线程中直接引用count变量进行更改并输出新数据 
	{
		printf("Now,线程count = %d\n\n",count);
	}
	printf("线程等待3秒钟...\n\n");
	Sleep(3000);//设置3s的等待时间 
	return 0;//退出运行 
}

int main()
{
	count=20;
	printf("进程运行！\n\n进程count=%d\n\n",count);//显示count变量初值 
	HANDLE hEvent=CreateThread(NULL,0,ThreadProc,NULL,0,NULL);//创建新线程并定义相关线程信息 
	WaitForSingleObject(hEvent,INFINITE);//等待线程运行结束 
	CloseHandle(hEvent);//关闭句柄 
	printf("新线程结束！\n");
	printf("进程结束！\n\n");
	printf("Now,count = %d",count);//显示count变量的最终值 
	return 0;
}
