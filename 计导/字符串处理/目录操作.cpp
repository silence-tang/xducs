#include<stdio.h>
#include<string.h>
int main()
{
	char a[201],b[201];
	gets(a);
	int i,j;
	while(1)
	{
		gets(b);
		if(strcmp(b,"pwd")==0) break;
		
			if(strcmp(b,"cd /")==0)
			{
				strcpy(a,"/"); 
			}
			else if(b[4]=='.')
			{
				if(strcmp(a,"/")!=0)
				{
					for(i=strlen(a)-1;i>=0;i--)
					{
						if(a[i]!='/') a[i]=0;
						else if(a[i]=='/'&& strlen(a)>1)
						{
							a[i]=0;
							break;
						}
					}
				}
			}
			else if(b[3]=='/'&&b[4]!=0)
			{
				for(i=0;i<strlen(a);i++)
					a[i]=1;   //这是令我百思不得其解的问题，需要dalao指正（发现想把a数组全部赋值为0（也就是字符‘\0’）是不行的）
				for(i=3;b[i]!='\0';i++)
				{
					a[i-3]=b[i];
				}
				a[i+4]=0;
			}
			else
			{
				if(strcmp(a,"/")==0)
				{
					j=1;
					for(i=3;b[i]!='\0';i++,j++)
					{
						a[j]=b[i];
					}
					a[j]='\0';
				}
				else
				{
	
					i=strlen(a);
					a[i]='/';
					i++;
					for(j=3;b[j]!='\0';i++,j++)
					{
						a[i]=b[j];
					}
					a[++i]='\0';
				}
			}
			
	}
	puts(a);
 }
