#include<windows.h>
#include<iostream>
#include<stdlib.h>
using namespace std;

HANDLE h_Mutex;                 //互斥量
HANDLE bufferFullSemaphore;     //已装填信号量
HANDLE bufferEmptySemaphore;    //空余信号量
const int BUFFER_SIZE=3;        //缓冲区大小
long buffer[BUFFER_SIZE]={0};   //缓冲区数组，用于存放产品编号
int in=0;                       //放入产品指针
int out=0;                      //移出产品指针
int num=0;                      //已经生产的产品数量，初值为0
int seq=1;                      //生产的产品号，初值为1
int num1=0;                     //Thread1消费的产品数，初值为0
int num2=0;                     //Thread2消费的产品数，初值为0
const int PRODUCER_NUM=1;       //生产者数目
const int CONSUMER_NUM=2;       //消费者数目
bool flag=true;                 //循环控制量
DWORD producerID[PRODUCER_NUM]; //生产者线程
DWORD consumerID[CONSUMER_NUM]; //消费者线程

//生产者函数
void producer()
{
	while(flag)
	{
		WaitForSingleObject(bufferEmptySemaphore,INFINITE);//p(bufferEmptySemaphore)
		WaitForSingleObject(h_Mutex,INFINITE);     //p(h_Mutex)
		cout << "Producer is producing\n";         //正在生产产品
		cout << "Successfully produced\n";         //生产成功
		cout << "Product No: " << seq << endl;     //输出产品编号
		buffer[in]=seq;                            //将产品放入缓冲区
		in=(in+1)%BUFFER_SIZE;                     //指针移位
		num=num+1;                                 //已经生产的产品数量+1
		seq=seq+1;                                 //产品编号+1
		cout << "Producer has produced " << num << " products all together";
		cout << endl << endl;
        Sleep(1000);   
        ReleaseMutex(h_Mutex); //v(h_Mutex)  
        ReleaseSemaphore(bufferFullSemaphore,1,NULL); //v(bufferFullSemaphore)

	}
}

//消费者1函数
void consumer1()  
{   
	while(flag)
	{
		WaitForSingleObject(bufferFullSemaphore,INFINITE); //p(bufferFullSemaphore)
		WaitForSingleObject(h_Mutex,INFINITE); //p(h_Mutex)
		cout << "Thread1 gets Mutex" << endl;
        cout << "Thread1 is consuming a product" << endl;
		buffer[out] = 0;//将产品移出缓冲区
		out = (out + 1) % BUFFER_SIZE; //指针移位
		num1=num1+1;
		Sleep(500);
		cout << "A product has been consumed by Thread1" << endl;
		cout << "Thread1 has consumed " << num1 << " products" << endl;
		cout << "Two threads have consumed " << num1+num2 << " products all together" << endl;
		cout << "Thread1 releases Mutex\n" << endl;
		ReleaseMutex(h_Mutex);//v(h_Mutex)
		ReleaseSemaphore(bufferEmptySemaphore,1,NULL);//v(bufferEmptySemaphore)
	}
}

//消费者2函数
void consumer2()
{
	while(flag)
	{
		WaitForSingleObject(bufferFullSemaphore,INFINITE); //p(bufferFullSemaphore)
		WaitForSingleObject(h_Mutex,INFINITE); //p(h_Mutex)
		cout << "Thread2 get Mutex" << endl;
        cout << "Thread2 is consuming a product" << endl;
		buffer[out] = 0;
		out = (out + 1) % BUFFER_SIZE;
		num2=num2+1;
		Sleep(1000);
		cout << "A product has been consumed by Thread2" << endl;
		cout << "Thread2 has consumed " << num2 << " products" << endl;
		cout << "Two threads have consumed " << num1+num2 << " products all together" << endl;
		cout << "Thread2 releases Mutex\n" << endl;
		ReleaseMutex(h_Mutex);//v(h_Mutex)
		ReleaseSemaphore(bufferEmptySemaphore,1,NULL);//v(bufferEmptySemaphore)
	}
}

//主函数
int main(int argc, char* argv[])
{
	cout << "本程序模拟生产者消费者问题\n\n生产者数目：1\n消费者数目：2\n缓冲区大小:100\n" << endl;
	cout << "1个生产者线程和2个消费者线程已准备就绪\n" << endl;
	cout << "消费者线程1消费时间：0.5s，消费者线程2消费时间：1s\n" << endl;
	h_Mutex = CreateMutex(NULL,false,NULL);                                   //创建互斥信号量
    bufferFullSemaphore = CreateSemaphore(NULL,0,BUFFER_SIZE,NULL);           //创建同步信号量
    bufferEmptySemaphore = CreateSemaphore(NULL,BUFFER_SIZE,BUFFER_SIZE,NULL);//创建同步信号量
	CreateThread(NULL,0,(LPTHREAD_START_ROUTINE)producer,NULL,0,&producerID[0]);
	CreateThread(NULL,0,(LPTHREAD_START_ROUTINE)consumer1,NULL,0,&consumerID[1]);
    CreateThread(NULL,0,(LPTHREAD_START_ROUTINE)consumer2,NULL,0,&consumerID[0]);

    while(flag)
	{
		if(getchar())
		{
			flag = false;
		}
	}
	return   0;
}