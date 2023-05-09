#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#define STACK_INIT_SIZE 100
#define STACKINCREMENT 10

/*ʾ����
���룺45+2*3-
�����15
*/

typedef struct
{
    int *base;
    int *top;
    int StackSize;
}SqStack;

void InitStack(SqStack &s)
{
    s.base = (int *)malloc(sizeof(int));
    if (!s.base)
    {
        exit(0);
    }
    s.top = s.base;
    s.StackSize = STACK_INIT_SIZE;
}

void Push(SqStack &s, int e)
{
	
    if (s.top - s.base >= s.StackSize)
    {
        s.base = (int *)realloc(s.base, (s.StackSize + STACKINCREMENT) * sizeof(int));
        if (!s.base)
        {
            exit(0);
        }
        s.top = s.base + s.StackSize;  //����ջ�� 
        s.StackSize = s.StackSize + STACKINCREMENT;
    }
    
    *(s.top) = e;
    s.top++;
}

void Pop(SqStack &s, int &e)
{
    if (s.top == s.base)
        return;
    e = *--(s.top);
}

int StackLength(SqStack s)
{
    return (s.top - s.base);
}

int Operate(int n1, int n2, char ch)
{
	if(ch=='+')
		return(n1+n2);
	else if(ch=='-')
		return(n1-n2);
	else if(ch=='*')
		return(n1*n2);
	else
		return(n1/n2);
}

int main()
{
    char str[100];
    int i,j,num1,num2,len,result;
    scanf("%s",str);
    len = strlen(str);
    SqStack S;
    InitStack(S);
    for(i=0;i<len;i++)
    {
    	if(str[i]<='9'&&str[i]>='0')   //���ɨ�赽���֣�����ջ 
    		Push(S,str[i]-'0');
    	else                           //���ɨ�赽�����������ջ���Σ��������㣬���������ջ 
		{
			Pop(S,num1);
			Pop(S,num2);
			Push(S,Operate(num2,num1,str[i])); //���ú����������㲢ֱ�ӽ���������ջ 
		}
	}
	
    Pop(S,result);
    printf("%d",result);
    return 0;
}
