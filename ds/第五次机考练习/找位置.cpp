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
		a[s[i]-'0'][0]++;               //��0��Ԫ��¼�ַ����ֵĸ�����������ASCII�� 
		a[s[i]-'0'][a[s[i]-'0'][0]]=i;  //���������Ԫ��λ�������μ�¼�ַ����ֵ�λ�� 
	}
	for(i=0;i<len;i++)
	{	
		if(s[i] != ' ' && a[s[i]-'0'][0] != 1)
		{
			for(j=1;j<a[s[i]-'0'][0];j++) 
				printf("%c:%d,",s[i],a[s[i]-'0'][j]);
			printf("%c:%d\n",s[i],a[s[i]-'0'][a[s[i]-'0'][0]]);//���һ������Ĳ��Ӷ��� 
			for(j=i+1;j<len;j++)
			{
				if(s[j] == s[i])
					s[j] = ' ';                   //���ַ������ظ����ַ�����Ϊ�ո��ַ�  
			}
		}
	}
		return 0; 
}
