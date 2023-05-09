#include<windows.h>
#include<iostream>
#include<stdlib.h>
using namespace std;

HANDLE h_Mutex;                 //������
HANDLE bufferFullSemaphore;     //��װ���ź���
HANDLE bufferEmptySemaphore;    //�����ź���
const int BUFFER_SIZE=3;        //��������С
long buffer[BUFFER_SIZE]={0};   //���������飬���ڴ�Ų�Ʒ���
int in=0;                       //�����Ʒָ��
int out=0;                      //�Ƴ���Ʒָ��
int num=0;                      //�Ѿ������Ĳ�Ʒ��������ֵΪ0
int seq=1;                      //�����Ĳ�Ʒ�ţ���ֵΪ1
int num1=0;                     //Thread1���ѵĲ�Ʒ������ֵΪ0
int num2=0;                     //Thread2���ѵĲ�Ʒ������ֵΪ0
const int PRODUCER_NUM=1;       //��������Ŀ
const int CONSUMER_NUM=2;       //��������Ŀ
bool flag=true;                 //ѭ��������
DWORD producerID[PRODUCER_NUM]; //�������߳�
DWORD consumerID[CONSUMER_NUM]; //�������߳�

//�����ߺ���
void producer()
{
	while(flag)
	{
		WaitForSingleObject(bufferEmptySemaphore,INFINITE);//p(bufferEmptySemaphore)
		WaitForSingleObject(h_Mutex,INFINITE);     //p(h_Mutex)
		cout << "Producer is producing\n";         //����������Ʒ
		cout << "Successfully produced\n";         //�����ɹ�
		cout << "Product No: " << seq << endl;     //�����Ʒ���
		buffer[in]=seq;                            //����Ʒ���뻺����
		in=(in+1)%BUFFER_SIZE;                     //ָ����λ
		num=num+1;                                 //�Ѿ������Ĳ�Ʒ����+1
		seq=seq+1;                                 //��Ʒ���+1
		cout << "Producer has produced " << num << " products all together";
		cout << endl << endl;
        Sleep(1000);   
        ReleaseMutex(h_Mutex); //v(h_Mutex)  
        ReleaseSemaphore(bufferFullSemaphore,1,NULL); //v(bufferFullSemaphore)

	}
}

//������1����
void consumer1()  
{   
	while(flag)
	{
		WaitForSingleObject(bufferFullSemaphore,INFINITE); //p(bufferFullSemaphore)
		WaitForSingleObject(h_Mutex,INFINITE); //p(h_Mutex)
		cout << "Thread1 gets Mutex" << endl;
        cout << "Thread1 is consuming a product" << endl;
		buffer[out] = 0;//����Ʒ�Ƴ�������
		out = (out + 1) % BUFFER_SIZE; //ָ����λ
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

//������2����
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

//������
int main(int argc, char* argv[])
{
	cout << "������ģ������������������\n\n��������Ŀ��1\n��������Ŀ��2\n��������С:100\n" << endl;
	cout << "1���������̺߳�2���������߳���׼������\n" << endl;
	cout << "�������߳�1����ʱ�䣺0.5s���������߳�2����ʱ�䣺1s\n" << endl;
	h_Mutex = CreateMutex(NULL,false,NULL);                                   //���������ź���
    bufferFullSemaphore = CreateSemaphore(NULL,0,BUFFER_SIZE,NULL);           //����ͬ���ź���
    bufferEmptySemaphore = CreateSemaphore(NULL,BUFFER_SIZE,BUFFER_SIZE,NULL);//����ͬ���ź���
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