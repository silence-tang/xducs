#include<stdio.h>
#include<string.h>
int main()
{
	char c,str[100]; int n,i,len,count=0;
	scanf("%c %d\n",&c,&n);
	gets(str); len=strlen(str);
	if(n==1)
	{
		for(i=0;i<len;i++)
		{
		   if(str[i]==c) count++;
		}
	}
	if(n==0)
	{
		for(i=0;i<len;i++)
		{   
		    if(c>='A'&&c<='Z')
		    {
		    	if(str[i]==c||str[i]==c+32)
		    	count++;
			}
			if(c>='a'&&c<='z')
		    {
		    	if(str[i]==c||str[i]==c-32)
		    	count++;
			}
			
		}
		
	}
	printf("%d",count);
	return 0;
}
