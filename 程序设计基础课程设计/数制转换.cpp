#include <stdio.h>
#include <string.h>

int main()
{
	char str[100];
	int i,len,sum=0;
	gets(str);                   //��ȡ�������ַ��� 
	len = strlen(str);           //����ַ����ĳ��� 
	for(i=0;i<len;i++)
		sum=sum*2+(str[i]-'0');	 //�ؾ����㷨
		
	printf("%d",sum);            //������
	return 0;
 } 
