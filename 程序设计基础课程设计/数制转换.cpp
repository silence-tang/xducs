#include <stdio.h>
#include <string.h>

int main()
{
	char str[100];
	int i,len,sum=0;
	gets(str);                   //获取二进制字符串 
	len = strlen(str);           //求该字符串的长度 
	for(i=0;i<len;i++)
		sum=sum*2+(str[i]-'0');	 //秦九韶算法
		
	printf("%d",sum);            //输出结果
	return 0;
 } 
