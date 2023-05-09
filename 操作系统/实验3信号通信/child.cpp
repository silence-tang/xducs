#include<stdio.h>
#include<stdlib.h>
#include<windows.h>

int main()
{
	HANDLE hEvent=OpenEvent(EVENT_ALL_ACCESS,TRUE,"event");//打开命名事件
	//OpenEvent是一个函数，可以用来执行返回事件对象的句柄
	Sleep(1000);
	printf("Signal the event to Parent?[Y\\N]:");
	char ch;
	scanf("%c", &ch);//接收字符 
	if(ch=='Y')
	{
		SetEvent(hEvent); //将事件置为有信号状态
	}
	else
	{
	   return 0;  //退出 
	}
	Sleep(5000);  //休眠一段时间
	return 0;
}
