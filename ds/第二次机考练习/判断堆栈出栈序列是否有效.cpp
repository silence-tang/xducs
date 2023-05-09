#include<stdio.h>
#include<stdbool.h>

bool check(int Popped[],int Pushed[],int m)
{
    int stack[m],top=-1;//设置一个栈
    stack[m]={0};
    int pop=0;//设置top1在popped中游走，popped表示弹栈的序列
    
    for(int i=0;i<m;i++)//i在入栈序列之中游走
    {
        stack[++top]=Pushed[i];//压栈一个元素
        while(top!=-1&&Popped[pop]==stack[top])
		{
            --top;//若栈不为空且当前栈顶等于出栈序列头的值，栈顶元素出栈
            ++pop;//出栈序列头元素出队
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
