#include<stdio.h>
#include<string.h>
int main()
{
	char s[100];
	int i,j,len,a[1000][100]={0};
	scanf("%s",s);
	len=strlen(s);
	for(i=0;i<len;i++)
	{
		a[s[i]-'0'][0]++;               //用0单元记录字符出现的个数，利用了ASCII码 
		a[s[i]-'0'][a[s[i]-'0'][0]]=i;  //后面的数组元素位用来依次记录字符出现的位置 
	}
	for(i=0;i<len;i++)
	{	
		if(s[i] != ' ' && a[s[i]-'0'][0] != 1)
		{
			for(j=1;j<a[s[i]-'0'][0];j++) 
				printf("%c:%d,",s[i],a[s[i]-'0'][j]);
			printf("%c:%d\n",s[i],a[s[i]-'0'][a[s[i]-'0'][0]]);//最后一个输出的不加逗号 
			for(j=i+1;j<len;j++)
			{
				if(s[j] == s[i])
					s[j] = ' ';                   //把字符串中重复的字符都置为空格字符  
			}
		}
	}
		return 0; 
}
