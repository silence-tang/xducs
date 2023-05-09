// Read.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>  
#include <windows.h>  
using namespace std;  
#define BUF_SIZE 1025  
char szName[] = "NameOfMappingObject";    // 共享内存的名字  

int main(int argc, char* argv[])
{
	// 创建共享文件句柄  
    HANDLE hMapFile = CreateFileMapping(INVALID_HANDLE_VALUE,NULL,PAGE_READWRITE,0,BUF_SIZE,szName);
    char *pBuf = (char *)MapViewOfFile(hMapFile,FILE_MAP_READ,0,0,BUF_SIZE);
	cout<<"Open Success"<<endl;
    while(1)
    {
        getchar();
        cout << "Read " << pBuf << " out of ShareMemory" << endl;
    }
    UnmapViewOfFile(pBuf);  
    CloseHandle(hMapFile);
	return 0;
}