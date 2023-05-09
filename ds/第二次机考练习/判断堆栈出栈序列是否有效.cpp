#include<stdio.h>
#include<stdbool.h>

bool check(int Popped[],int Pushed[],int m)
{
    int stack[m],top=-1;//����һ��ջ
    stack[m]={0};
    int pop=0;//����top1��popped�����ߣ�popped��ʾ��ջ������
    
    for(int i=0;i<m;i++)//i����ջ����֮������
    {
        stack[++top]=Pushed[i];//ѹջһ��Ԫ��
        while(top!=-1&&Popped[pop]==stack[top])
		{
            --top;//��ջ��Ϊ���ҵ�ǰջ�����ڳ�ջ����ͷ��ֵ��ջ��Ԫ�س�ջ
            ++pop;//��ջ����ͷԪ�س���
        }
    }
    if(top==-1)
        return true;
    else
        return false;
}

int main()
{
	int n,i;
	scanf("%d",&n);
	int pushed[n],popped[n];
	for(i=0;i<n;i++)
		pushed[i] = i+1;
	for(i=0;i<n;i++)
		scanf("%d",&popped[i]);
    bool is_true=check(popped, pushed,n);
    if(is_true == 1)
    	printf("yes");
    else
    	printf("no");
    return 0;
}
