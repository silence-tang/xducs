#include<stdio.h>
#include<stdlib.h>
int main()
{
	int m,n,i,j,k1,k2,k3,sum1=0,sum2=0;
	int a[100][100],b[100][100],c[100][100];
	int v1[10000],v2[10000],v3[10000];
	scanf("%d %d",&m,&n);
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			scanf("%d",&a[i][j]);
			if(a[i][j]==1)
				sum1++;             //sum1��¼����A��0Ԫ�ظ��� 
		}
	}
	for(i=0;i<sum1;i++)
		scanf("%d",&v1[i]);         //�������A������v1 
	
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			scanf("%d",&b[i][j]);
			if(b[i][j]==1)
				sum2++;             //sum2��¼����B��0Ԫ�ظ��� 
		}
	}
	for(i=0;i<sum2;i++)
		scanf("%d",&v2[i]);         //�������B������v2 
		
	k1=0; k2=0;
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			if(a[i][j]==1)
			{
				a[i][j] = v1[k1];
				k1++;
			}
			if(b[i][j]==1)
			{
				b[i][j] = v2[k2];
				k2++;
			}
			c[i][j] = a[i][j] + b[i][j];    //�����ľ���������� 
		}
	}
	
	k3=0;
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			if(c[i][j] != 0)
			{
				printf("1 ");
				v3[k3] = c[i][j];
				k3++;
			}
			else
				printf("0 ");
		}
		printf("\n");          //һ�д�ӡ�������� 
	}
	
	for(i=0;i<k3;i++)
		printf("%d ",v3[i]);
	
	return 0;
}
