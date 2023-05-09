#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#define STACK_INIT_SIZE 100
#define STACKINCREMENT 10

/*示例：
输入：+ * + 42 8 – 36 6 / 9 3
结果：1503
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

void fun(char *str)
{
	char *str_c=str;
	int i,j=0;
	for(i=0;str[i]!='\0';i++)
	{
		if(str[i]!=' ')
			str_c[j++]=str[i];
	}
	str_c[j]='\0';
	str=str_c;	
}

int main()
{
    char str[100];
    int i,j,k,weishu,cur_num,num1,num2,len,result;
    scanf("%[^\n]",str);
    len = strlen(str);
    SqStack S;
    InitStack(S);
    for(i=len-1;i>=0;i--)
    {
    	if(str[i]<='9'&&str[i]>='0')        //如果扫描到数字 
    	{
    		weishu = 1;
    		for(j=i-1;j>=0;j--)
    		{
    			if(str[j]>='0'&&str[j]<='9')
    				weishu++;              //求连续数字的位数 
    			if(str[j]==' ')
    				break;
			}
			cur_num = str[i-weishu+1]-'0';
			if(weishu==1)                  //只有一位数字的情况 
				Push(S,cur_num);
			else                           //有两位及以上数字的情况 
			{
				for(k=0;k<weishu-1;k++)
					cur_num = 10*cur_num + (str[i-(weishu-2-k)]-'0');  //！！！字符和数字不能混淆 
				Push(S,cur_num);           //将数字压入栈 
				for(k=1;k<weishu;k++)
					str[i-k] = ' ';
			}
		}
		
    	if(str[i]=='+' || str[i]=='-' || str[i]=='*' || str[i]=='/') 
		{
			Pop(S,num1);
			Pop(S,num2);
			Push(S,Operate(num1,num2,str[i])); //调用函数进行运算并直接将运算结果入栈 
		}
	}
	
    Pop(S,result);
    printf("%d",result);
    return 0;
}
