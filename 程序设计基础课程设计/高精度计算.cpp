#include <stdio.h>
#include <string.h>
#include <math.h>

char* plus_dashu(char* str1,char* str2)              //�Զ��庯����ʵ�ִ����ӷ� 
{
   char strl[100], strs[100];
   int a[100] = {0}, b[100] = {0}, c[100] = {0};     //����a,b���������������������c�����������֮�� 
   int i, j, k, len1, len2, lenm, sub;
   len1 = strlen(str1);
   len2 = strlen(str2);
   sub  = abs(len1-len2);
   if(len1>=len2)
   {
   		strcpy(strl,str1);
        strcpy(strs,str2);
        lenm = len1;                                  //�ҳ�str1,str2�еĽϳ��ͽ϶̴� 
   }
	else
   {
	    strcpy(strl,str2);
        strcpy(strs,str1);
        lenm = len2;                                  //�ҳ�str1,str2�еĽϳ��ͽ϶̴� 
   }                     
	
    for(i=lenm; i>=1; i--)
        a[i] = strl[i-1] - '0';
 			for(i=lenm;i>=lenm-strlen(strs)+1;i--)
          		b[i] = strs[i-1-sub] - '0';           //����������ĩλ���룬�ֱ������������a[],b[]
          				
	int temp;                                         //�ӷ�����ľ������� 
	if(a[lenm] + b[lenm] <= 9)
	{
		c[lenm] = a[lenm] + b[lenm];
		temp = 0;
	}
	else
	{
		c[lenm] = a[lenm] + b[lenm] - 10;
		temp = 1;                                     //������ĩ��֮�͵ó�temp��ֵ��0/1���������ж���һλ�Ƿ���Ҫ��һ 
	}
			    
    for(j=lenm-1; j>=0; j--)
	{
		if(a[j] + b[j] + temp <= 9)                   //�����λ����� 
		{
		  	c[j] = a[j] + b[j] + temp;
		  	temp = 0;
		}
		else
		{
		  	c[j] = a[j] + b[j] + temp -10;            //��Ҫ��λ����� 
		  	temp = 1;
		}
    }
            		
    if(c[0]==0)                                       //���c[0]=0���������c�ĵڶ���Ԫ�ؿ�ʼ���
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

char* sub_dashu(char* str1,char* str2)   //�Զ��庯����ʵ�ִ������� 
{
	
	int a[100] = {0};                    // ����a������ű��������� 
	int b[100] = {0};                    // ����b������ż������� 
	int c[100];                          // ����c�������������֮�� 
	int len1,len2;
	int i,j,k,m,n;
	len1 = strlen(str1);
	len2 = strlen(str2);
	 
	if(len1>len2)
		k = len1;
	else 
		k = len2;                        //����������������λ��

	c[0] = 0;
	if(len1>len2)
		n = 1;
	else if(len1==len2)
		n = strcmp(str1,str2);
	else
		n = -1;                          //n=1����a>b, n=0����a=b, n<0����a<b

	for(i=len1-1, j=0; i>=0; i--, j++)
		a[j] = str1[i] - '0';

	for(i=len2-1, j=0; i>=0; i--, j++)
		b[j] = str2[i] - '0';	         //������������λ���룬�ֱ����������a,b

	for(i=0; i<k; i++)                   //��������ľ������� 
	{
		if(n>=0)
		{
			if(a[i]-b[i]>=0)
				c[i] = a[i] - b[i];
			else 
			{
				c[i] = a[i] + 10 - b[i];
				a[i+1]--;                //a[i+1]��һλ���� ������1 �����ʼ�ȥ1 
			}
		}
		else 
		{
			if(b[i]-a[i] >= 0)
				c[i] = b[i] - a[i];
			else
			{
				c[i] = b[i] + 10 - a[i];
				b[i+1]--;                //b[i+1]��һλ���� ������1 �����ʼ�ȥ1 
			}
		}
	}
	
	if(n<0)
		printf("-");		             //������Ϊ��������������ϸ��ţ� 

	int flag;	                         //��flag�ж�����֮���Ƿ�Ϊ0 
	for(i=k-1; i>=0; i--)
	{
		flag=0;
		if(c[i]!=0)
			flag=1;
		if(flag==1)
			break;
	}
	if(flag==0)                          
		printf("0");                     //��flag=0�������0 
	else                                 //��flag!=0���������c�ĵ����е�һ������0������ʼ���
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

int main()                               //������ 
{
    char str1[100],str2[100],flag;
    gets(str1); gets(str2);
    scanf("%c",&flag);
    char* plus_dashu(char* str1,char* str2);
    char* sub_dashu(char* str1,char* str2);
    if(flag=='+')                        //������Ӻţ�����мӷ�����
    {
    	printf("��������֮��Ϊ��"); 
    	plus_dashu(str1,str2);
	}
    if(flag=='-')                        //��������ţ�����м�������
    {
    	printf("��������֮��Ϊ��");
    	sub_dashu(str1,str2);
	}
    return 0;
}
