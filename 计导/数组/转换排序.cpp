#include<stdio.h>
#include<string.h>
#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int n,j,i;
    char a[100],b[100],x;
    gets(a);               //����һ���ַ���������a
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
		
    }                     //������a������д�д��ĸ��˳�����ηŵ�����c�У���c[0],c[1]...ȫ���Ǵ�д��ĸ 
	   
	    sort(b,b+j);     //������c����С�����˳������A-Z�� 
	   
        for(i=0,j=0;i<n;i++)
    {
    	if(a[i]<65||(a[i]>90&&a[i]<97)||a[i]>122)
	    putchar(a[i]);
        else
		{
			putchar(b[j]);
			j++;
		}                //���μ��a�е�Ԫ�أ���Ϊ���֣���������֣���Ϊ��������c�е�Ԫ��������� 
	}
    
    return 0;
}    
