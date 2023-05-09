#include<stdio.h>
#include<windows.h>
int main()
{
	STARTUPINFO sui;             //启动信息结构体 
	PROCESS_INFORMATION pi;      //在创建进程时相关的数据结构之一，该结构返回有关新进程及其主线程的信息。
	ZeroMemory(&sui,sizeof(sui));
	sui.cb = sizeof(STARTUPINFO);//将cb成员设置为信息结构体的大小
	int sum = 0;
	char content[100] = "";      //初始化content字符数组用来存放文件内容 
	if(CreateProcess("D:\\child.exe",NULL,NULL,NULL,FALSE,CREATE_NEW_CONSOLE,NULL,NULL,&sui,&pi))//创建进程 
	{
		printf("已创建一个子进程\n");
		for(int i = 1; i <= 100; i++)
		{
			sum = sum + i;       //求1-100之和 
			Sleep(5);            //延迟时间5ms
			printf("Now, sum = %d\n",sum);
		}
		WaitForSingleObject(pi.hProcess,INFINITE);//一直等下去直到进程结束 
		FILE *fp = fopen("D:\\test.txt","r");
		fread(content,sizeof(char),100,fp);       //设置读取文件内容的相关参数 
		printf("子进程创建的文件内容如下:\n\n%s\n\n",content);
		fclose(fp);
	}
	else
		printf("创建子进程失败\n");
	printf("实验结束！");
	return 0;
}
