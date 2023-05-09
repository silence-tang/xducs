#include<stdio.h>
#include<string.h>

int main()
{
	int len,i,j,k,next[100];
	scanf("%d",&len);
	char str[100],str2[100];
	getchar(); //输入缓冲字符'\n' 
	gets(str); //然后再输入待输入字符 
	k=0;
	for(i=0;i<strlen(str);i++)
	{
		if(str[i] != ' ')
		{
			str2[k] = str[i];
			k++;
		}
	}
	i=1;j=0;
	next[1]=0;
	while(i<len)
	{
		if(j==0 || str2[i-1]==str2[j-1])
		{
			i++;
			j++;
			next[i]=j;
		}
		else
			j=next[j];
	}
	for(i=1;i<=len;i++)
		printf("%d ",next[i]-1);
	return 0;
}
