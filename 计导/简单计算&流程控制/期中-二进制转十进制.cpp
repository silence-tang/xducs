#include <stdio.h>
#include <string.h>
int main()
{
	char str[100];
	int i,len,sum=0;
	gets(str);
	len = strlen(str);
	for(i=0;i<len;i++)
		sum=sum*2+(str[i]-'0');	
	printf("%d",sum);
	return 0;
 } 
