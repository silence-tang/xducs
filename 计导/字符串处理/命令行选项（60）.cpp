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
			flag=1;//���������ڣ����Բ���no
			for(k=0;string[i]!=' '&&string[i]!='\0';i++,k++)
				str[j][k]=string[i];
			str[j][k]='\0';  //��ά���������ַ�����һ�� �����\0����
			j++;//j�����б� k�����б� ��iΪԭ�ַ��������� 
		}
		if(string[i]=='\0') break;//����û���� 
	}
	n=j;//��ʱ��jΪ������Ҳ���Ǵ���-���������������
	
	if(flag)//����������� ���Ľ���ֱ���ж�n�Ƿ�Ϊ0����
	{
		for(i=0;i<n-1;i++)//ѡ������ ��string����ظ����� 
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
