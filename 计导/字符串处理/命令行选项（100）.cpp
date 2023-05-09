#include<stdio.h>
int main()
{
	char a[256],b[256],c;
	gets(a);
	int i,j,k=0,t=0;
	for(i=0;a[i]!='\0'||a[i]==' ';i++)
	{
		if(a[i]==' '&&a[i+1]=='-')
		{
			b[k]=a[i+2];
			k++;
		}
	}
	for(i=0;i<k-1;i++)
	{
		for(j=0;j<k-1-i;j++)
		{
			if(b[j]>b[j+1])
			{
				c=b[j];
				b[j]=b[j+1];
				b[j+1]=c;
			}
		}
	}
	if(k==0)
		printf("no");
	else
	{
		for(i=0;i<k;i++)
		{
			if(b[i]!=b[i+1])
				printf("-%c ",b[i]);
		}
	}
	return 0;
}
