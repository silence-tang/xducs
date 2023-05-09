#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#define STACK_INIT_SIZE 100
#define STACKINCREMENT 10

/*示例：
输入：45+2*3-
结果：15
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
        s.top = s.base + s.StackSize;  //设置栈顶 
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
    	if(str[i]<='9'&&str[i]>='0')   //如果扫描到数字，则入栈 
    		Push(S,str[i]-'0');
    	else                           //如果扫描到操作符，则出栈两次，进行运算，并将结果入栈 
		{
			Pop(S,num1);
			Pop(S,num2);
			Push(S,Operate(num2,num1,str[i])); //调用函数进行运算并直接将运算结果入栈 
		}
	}
	
    Pop(S,result);
    printf("%d",result);
    return 0;
}
