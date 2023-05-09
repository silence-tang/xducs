#include<stdio.h>
#include<string.h>
#include <stdlib.h>
#include <ctype.h>
int main()
{
	int i,j,len,sum=0;
	char str[200];
	int A[200][200]={};
	gets(str);
	len = strlen(str);
	for(i=0;i<len;i++)
	{
		if(isdigit(str[i])!=0)
		{
			sum=sum+1;
		}
	}
	
	printf("%d",sum);
	//for(i=0;i<str;i++)
	//	printf("%c",str(i));
	
	return 0;

}
