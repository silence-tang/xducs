#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
int main()
{
    char str[100],a[100],b[100],ch;
    int i,j,k,p,len,flag1,flag2,n1,n2;
    gets(str); len=strlen(str);
    for(i=0;i<len;i++)
	{
		if(isdigit(str[i]))
		{
			a[0]=str[i];
			for(j=i+1,k=1;j<len;j++)
			{
				if(isdigit(str[j]))
				{
					a[k]=str[j];
					k++;
				}
				else
				{
				    p=j;
					flag1=-1;
					break;
				}
			} 
		}
		
            if(flag1==-1) break;
	}//此时数组a表示第一个数字，p表示第一个数字后的那个空格的数组下标 
     
    for(i=p;i<len;i++)
    {
    	    if(isdigit(str[i]))
		{
			b[0]=str[i];
			for(j=i+1,k=1;j<len;j++)
			{
				if(isdigit(str[j]))
				{
					b[k]=str[j];
					k++;
				}
				else
				{
					flag2=-1;
					break;
				}
			}
        }
    	if(flag2==-1) break;
	}    //此时数组b表示第二个数字
    n1=atoi(a);   n2=atoi(b);
    for(i=0;i<len;i++)
    {
    	if(str[i]=='+'||str[i]=='-'||str[i]=='*'||str[i]=='/'||str[i]=='%')
        {
		   ch=str[i];
		   break;
		}	
	}
	switch(ch) 
	{
		case'+':cout<<n1+n2; break;
		case'-':cout<<n1-n2;break;
		case'*':cout<<n1*n2;break;
		case'/':cout<<n1/n2;break;
		case'%':cout<<n1%n2;break; 
	}
	return 0;
}
