#include<stdio.h>
#include<stdlib.h>

struct stack                  //构建一个栈的结构体 
{
	int element[100] = {0};   //初始化存放元素的数组
	int top = 0;              //初始化栈顶元素为0
	int count = 0;            //计数器，用来标明元素位置
}Stack;                       //将此结构体取别名为Stack,方便调用

int main()                    //主函数
{
	printf("模拟堆栈程序\n");
	printf("\n");
	printf("\n");
	int i, caozuo, a = 0;
	loop:
	printf("请选择栈操作：入栈请按1，出栈请按2，返回栈顶元素请按3，退出请按0\n");
	scanf("%d", &caozuo);     //构建基本的用户交互界面
	
	switch (caozuo)
	{
		
		case 0:
			return 0;         //输入0,则退出 
		
		case 1:               //输入1,则进行入栈操作 
		{
			
			printf("请输入需要入栈的元素：");
			scanf("%d", &a);
			Stack.element[Stack.count] = a;
			Stack.top = a;                      //最新入栈的元素总是在栈顶 
			Stack.count++;                      //进入了一个元素,计数器自增1,代表下一个待入栈的元素在数组中的位置 
			printf("当前栈中元素个数为%d,显示如下：",Stack.count);
			for(i=0; i < Stack.count; i++)
				printf("%d ",Stack.element[i]); //for循环遍历栈的数组，输出当前栈中的所有元素 
			printf("\n");
			goto loop;
		}
		
		case 2:               //输入2,则进行出栈操作 
		{
			
			Stack.element[Stack.count - 1] = 0;  //将原来的栈顶元素清空为0,为以后新入栈的元素腾出空间 
			Stack.top = Stack.element[Stack.count - 2];  //新的栈顶元素 
			Stack.count--;                               //计数器自减1,指向新入栈的元素应当在数组中的位置 
			printf("当前栈中元素个数为%d,显示如下：",Stack.count);   //for循环遍历栈的数组，输出当前栈中的所有元素 
			for(i=0; i < Stack.count; i++)
				printf("%d ",Stack.element[i]);
			printf("\n");
			goto loop;
		}
		
		case 3:
		{
			printf("当前栈顶元素为：%d\n", Stack.top);   //打印当前的栈顶元素 
			printf("当前栈中元素个数为%d,显示如下：",Stack.count);   //for循环遍历栈的数组，输出当前栈中的所有元素 
			for(i=0; i < Stack.count; i++)
				printf("%d ",Stack.element[i]);
			printf("\n");
			goto loop;
		}
		
	}
	
	return 0;
}

