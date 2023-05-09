#include<stdio.h>
#include<string.h>
#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int n,j,i;
    char a[100],b[100],x;
    gets(a);               //输入一个字符串到数组a
    n=strlen(a);
    for(i=0,j=0;i<n;i++)
    {
        if(a[i]>=97) 
		{
			b[j]=a[i]-32;
			j++;
		}
        if(a[i]>=65&&a[i]<=90)
        {
        	b[j]=a[i];
        	j++;
		}
		
    }                     //把数组a里的所有大写字母按顺序依次放到数组c中，即c[0],c[1]...全都是大写字母 
	   
	    sort(b,b+j);     //将数组c按从小到大的顺序排序（A-Z） 
	   
        for(i=0,j=0;i<n;i++)
    {
    	if(a[i]<65||(a[i]>90&&a[i]<97)||a[i]>122)
	    putchar(a[i]);
        else
		{
			putchar(b[j]);
			j++;
		}                //依次检查a中的元素，若为数字，则输出数字；若为其他，则将c中的元素依次输出 
	}
    
    return 0;
}    
