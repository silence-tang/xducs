// Write.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <ctype.h>
#include <windows.h>
using namespace std;
#define BUF_SIZE 1025
char szName[] = "NameOfMappingObject";    // 共享内存的名字

int main(int argc, char* argv[])
{
	// 创建共享文件句柄
    HANDLE hMapFile = CreateFileMapping(INVALID_HANDLE_VALUE,NULL,PAGE_READWRITE,0,BUF_SIZE,szName);
    char *pBuf = (char *)MapViewOfFile(hMapFile,FILE_MAP_WRITE,0,0,BUF_SIZE);
    if(hMapFile!=NULL)
		cout<<"Create Success"<<endl;
    while(1)
    {	
		loop:
			char szInfo[BUF_SIZE] = {0};
			gets(szInfo);
			if(isalpha(szInfo[0]))
			{
				cout << "Write " << szInfo << " into ShareMemory" << endl;
				strncpy(pBuf, szInfo, BUF_SIZE - 1);
				pBuf[BUF_SIZE - 1] = '\0';	
			}
			else
			{
				cout << "Input Again" << endl;
				goto loop;
			}
    }
    UnmapViewOfFile(pBuf);
    CloseHandle(hMapFile);
	return 0;
}