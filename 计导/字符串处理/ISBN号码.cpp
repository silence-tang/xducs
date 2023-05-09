#include<stdio.h>
#include<string.h>
int main()
{
	char str[100],a[100],flag;
	int n,i,k,len,sum=0,result;
	gets(str); len=strlen(str);
	for(i=0,k=0;i<len-2;i++)
	{
		if(str[i]!='-')
		{
			a[k]=str[i];
			k++;
		}
	}
	for(i=0;i<k;i++)
	sum=sum+(a[i]-'0')*(i+1);
	result=sum%11;
	
	if(result>=0&&result<=9) flag=result+'0';
	if(result==10) flag='X';
	
	if(str[len-1]==flag) printf("Right");
	else
	{
	   for(i=0;i<len-1;i++)
	   putchar(str[i]);
	   printf("%c",flag);
	}
	
	return 0; 
}
