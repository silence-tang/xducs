#include <stdio.h>
#include <string.h> 
//�����׹�ʽ 
int jiecheng(int a)  //�ݹ���׳�  
{   
    if(a==0)
        return 1;
    return a*jiecheng(a-1);
}

int zuheshu(int n, int m)  //�������
{   
    return jiecheng(n)/(jiecheng(m)*jiecheng(n-m));  //�������ʽ
}

int mi(int n, int m)     //��n^m    (n-1)^m  
{       
    if(m==1)
        return n;
    return n*mi(n,m-1);
}

int main()
{
	char str1[100],str2[100];
	gets(str1); gets(str2);
	int len1, len2, i, j, m=0, n=0, sum=0;
	len1 = strlen(str1);
	len2 = strlen(str2);
	for(i=0;i<len1;i++)
	{
		if(str1[i]<='9'&&str1[i]>='0')
		m++;
	}
	for(j=0;j<len2;j++)
	{
		if(str2[j]<='9'&&str2[j]>='0')
		n++;
	}
    for(i=0;i<n;i++)
	{         
        if(i%2==0)
            sum+=zuheshu(n,n-i)*mi(n-i,m);  //ʵ��ż�����ǣ� ��������-  �� (-1)^(n-1)
        else
            sum-=zuheshu(n,n-i)*mi(n-i,m);
    }
    printf("%d",sum);
	    
return 0;
}
