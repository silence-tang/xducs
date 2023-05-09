#include <stdio.h>
#include <string.h>
#include <math.h>

char* plus_dashu(char* str1,char* str2)              //自定义函数，实现大数加法 
{
   char strl[100], strs[100];
   int a[100] = {0}, b[100] = {0}, c[100] = {0};     //数组a,b用来存放两个大数，数组c用来存放两数之和 
   int i, j, k, len1, len2, lenm, sub;
   len1 = strlen(str1);
   len2 = strlen(str2);
   sub  = abs(len1-len2);
   if(len1>=len2)
   {
   		strcpy(strl,str1);
        strcpy(strs,str2);
        lenm = len1;                                  //找出str1,str2中的较长和较短串 
   }
	else
   {
	    strcpy(strl,str2);
        strcpy(strs,str1);
        lenm = len2;                                  //找出str1,str2中的较长和较短串 
   }                     
	
    for(i=lenm; i>=1; i--)
        a[i] = strl[i-1] - '0';
 			for(i=lenm;i>=lenm-strlen(strs)+1;i--)
          		b[i] = strs[i-1-sub] - '0';           //将两个大数末位对齐，分别正序存入数组a[],b[]
          				
	int temp;                                         //加法计算的具体流程 
	if(a[lenm] + b[lenm] <= 9)
	{
		c[lenm] = a[lenm] + b[lenm];
		temp = 0;
	}
	else
	{
		c[lenm] = a[lenm] + b[lenm] - 10;
		temp = 1;                                     //由两数末端之和得出temp初值（0/1），便于判断下一位是否需要进一 
	}
			    
    for(j=lenm-1; j>=0; j--)
	{
		if(a[j] + b[j] + temp <= 9)                   //无需进位的情况 
		{
		  	c[j] = a[j] + b[j] + temp;
		  	temp = 0;
		}
		else
		{
		  	c[j] = a[j] + b[j] + temp -10;            //需要进位的情况 
		  	temp = 1;
		}
    }
            		
    if(c[0]==0)                                       //如果c[0]=0，则从数组c的第二个元素开始输出
    {
        for(k=1; k<=lenm; k++)
        printf("%d",c[k]);
	}
    else
    {
        for(k=0; k<=lenm; k++)
        printf("%d",c[k]);	
	}
	
}

char* sub_dashu(char* str1,char* str2)   //自定义函数，实现大数减法 
{
	
	int a[100] = {0};                    // 数组a用来存放被减数大数 
	int b[100] = {0};                    // 数组b用来存放减数大数 
	int c[100];                          // 数组c用来存放两大数之差 
	int len1,len2;
	int i,j,k,m,n;
	len1 = strlen(str1);
	len2 = strlen(str2);
	 
	if(len1>len2)
		k = len1;
	else 
		k = len2;                        //求出两个大数的最大位数

	c[0] = 0;
	if(len1>len2)
		n = 1;
	else if(len1==len2)
		n = strcmp(str1,str2);
	else
		n = -1;                          //n=1代表a>b, n=0代表a=b, n<0代表a<b

	for(i=len1-1, j=0; i>=0; i--, j++)
		a[j] = str1[i] - '0';

	for(i=len2-1, j=0; i>=0; i--, j++)
		b[j] = str2[i] - '0';	         //将两个大数首位对齐，分别倒序存入数组a,b

	for(i=0; i<k; i++)                   //减法计算的具体流程 
	{
		if(n>=0)
		{
			if(a[i]-b[i]>=0)
				c[i] = a[i] - b[i];
			else 
			{
				c[i] = a[i] + 10 - b[i];
				a[i+1]--;                //a[i+1]这一位数被 “借了1 ”，故减去1 
			}
		}
		else 
		{
			if(b[i]-a[i] >= 0)
				c[i] = b[i] - a[i];
			else
			{
				c[i] = b[i] + 10 - a[i];
				b[i+1]--;                //b[i+1]这一位数被 “借了1 ”，故减去1 
			}
		}
	}
	
	if(n<0)
		printf("-");		             //处理结果为负数的情况（加上负号） 

	int flag;	                         //用flag判断两数之差是否为0 
	for(i=k-1; i>=0; i--)
	{
		flag=0;
		if(c[i]!=0)
			flag=1;
		if(flag==1)
			break;
	}
	if(flag==0)                          
		printf("0");                     //若flag=0，则输出0 
	else                                 //若flag!=0，则从数组c的倒序中第一个不是0的数开始输出
		{
			for(i=k-1; i>=0; i--)
			{
				if(c[i]!=0)
			    {	
					m=i;
					break;               
				}
			}
			for(i=m; i>=0; i--)
			printf("%d",c[i]);
		}
		
}

int main()                               //主函数 
{
    char str1[100],str2[100],flag;
    gets(str1); gets(str2);
    scanf("%c",&flag);
    char* plus_dashu(char* str1,char* str2);
    char* sub_dashu(char* str1,char* str2);
    if(flag=='+')                        //若输入加号，则进行加法操作
    {
    	printf("两个大数之和为："); 
    	plus_dashu(str1,str2);
	}
    if(flag=='-')                        //若输入减号，则进行减法操作
    {
    	printf("两个大数之差为：");
    	sub_dashu(str1,str2);
	}
    return 0;
}
