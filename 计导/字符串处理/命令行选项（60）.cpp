#include<stdio.h>
#include<string.h>
int main()
{
	char string[256];
	char str[100][20];
	int i,j,k,n,flag=0;
	gets(string);
	j=0;
	for(i=0;string[i]!='\0';i++)
	{
		if(string[i]=='-')
		{
			flag=1;//标记命令存在，所以不是no
			for(k=0;string[i]!=' '&&string[i]!='\0';i++,k++)
				str[j][k]=string[i];
			str[j][k]='\0';  //二维数组来存字符串的一行 最后以\0结束
			j++;//j控制行标 k控制列标 而i为原字符串的索引 
		}
		if(string[i]=='\0') break;//好像没意义 
	}
	n=j;//此时的j为行数，也就是带“-”的命令符的数量
	
	if(flag)//如果存在命令 ，改进：直接判断n是否为0即可
	{
		for(i=0;i<n-1;i++)//选择排序 ，string多次重复利用 
		{
			k=i;
			for(j=i+1;j<n;j++)
				if(strcmp(str[k],str[j])>0) k=j;
			if(k!=i)
			{
				strcpy(string,str[i]);
				strcpy(str[i],str[k]);
				strcpy(str[k],string);
			}
		}
		 strcpy(string,str[0]);
		 printf("%s",string);
		 for(i=1;i<n;i++)
		 {
		 	if(strcmp(string,str[i])!=0)
		 	{
		 		strcpy(string,str[i]);
		 		printf(" %s",string);
			}
		 } 
	}
	else printf("no");
	return 0;
}
