#include<stdio.h>
#include<stdlib.h>

struct stack                  //����һ��ջ�Ľṹ�� 
{
	int element[100] = {0};   //��ʼ�����Ԫ�ص�����
	int top = 0;              //��ʼ��ջ��Ԫ��Ϊ0
	int count = 0;            //����������������Ԫ��λ��
}Stack;                       //���˽ṹ��ȡ����ΪStack,�������

int main()                    //������
{
	printf("ģ���ջ����\n");
	printf("\n");
	printf("\n");
	int i, caozuo, a = 0;
	loop:
	printf("��ѡ��ջ��������ջ�밴1����ջ�밴2������ջ��Ԫ���밴3���˳��밴0\n");
	scanf("%d", &caozuo);     //�����������û���������
	
	switch (caozuo)
	{
		
		case 0:
			return 0;         //����0,���˳� 
		
		case 1:               //����1,�������ջ���� 
		{
			
			printf("��������Ҫ��ջ��Ԫ�أ�");
			scanf("%d", &a);
			Stack.element[Stack.count] = a;
			Stack.top = a;                      //������ջ��Ԫ��������ջ�� 
			Stack.count++;                      //������һ��Ԫ��,����������1,������һ������ջ��Ԫ���������е�λ�� 
			printf("��ǰջ��Ԫ�ظ���Ϊ%d,��ʾ���£�",Stack.count);
			for(i=0; i < Stack.count; i++)
				printf("%d ",Stack.element[i]); //forѭ������ջ�����飬�����ǰջ�е�����Ԫ�� 
			printf("\n");
			goto loop;
		}
		
		case 2:               //����2,����г�ջ���� 
		{
			
			Stack.element[Stack.count - 1] = 0;  //��ԭ����ջ��Ԫ�����Ϊ0,Ϊ�Ժ�����ջ��Ԫ���ڳ��ռ� 
			Stack.top = Stack.element[Stack.count - 2];  //�µ�ջ��Ԫ�� 
			Stack.count--;                               //�������Լ�1,ָ������ջ��Ԫ��Ӧ���������е�λ�� 
			printf("��ǰջ��Ԫ�ظ���Ϊ%d,��ʾ���£�",Stack.count);   //forѭ������ջ�����飬�����ǰջ�е�����Ԫ�� 
			for(i=0; i < Stack.count; i++)
				printf("%d ",Stack.element[i]);
			printf("\n");
			goto loop;
		}
		
		case 3:
		{
			printf("��ǰջ��Ԫ��Ϊ��%d\n", Stack.top);   //��ӡ��ǰ��ջ��Ԫ�� 
			printf("��ǰջ��Ԫ�ظ���Ϊ%d,��ʾ���£�",Stack.count);   //forѭ������ջ�����飬�����ǰջ�е�����Ԫ�� 
			for(i=0; i < Stack.count; i++)
				printf("%d ",Stack.element[i]);
			printf("\n");
			goto loop;
		}
		
	}
	
	return 0;
}

