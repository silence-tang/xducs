#include<stdio.h>
int main()
{
	
	int m,i,j,k,flag1=1,flag2=1,flag3=1;
	int a[100][100];
	scanf("%d",&m);
	for(i=0;i<m;i++)
		for(j=0;j<m;j++)
			scanf("%d",&a[i][j]);
	
	for(i=0;i<m;i++)
	{
		if(a[i][i]==0)
		{
			flag1=0;
			break;		
		}                       //��flag1�жϹ�ϵR�Ƿ�����Է��ԣ�flag1=1,��; flag1=0,��  
	}	
	
	for(i=0;i<m;i++)
	{
		for(j=0;j<m;j++)
		{
			if(a[i][j]==1&&a[j][i]==1)
				flag2=0;        //��flag2�жϹ�ϵR�Ƿ���з��Գ��ԣ�flag2=1,��; flag2=0,��  
		}
	}

	for(i=0;i<m;i++)
	{
		for(j=0;j<m;j++)
		{
			for(k=0;k<m;k++)
			{
				if(a[i][j]==1&&a[j][k]==1&&a[i][k]!=1)
					flag3=0;  //��flag3�жϹ�ϵR�Ƿ���д����ԣ�flag3=1,��; flag3=0,��  
			}
		}
	}
	
	if(flag1==1&&flag2==1&&flag3==1)
	printf("�ù�ϵ��ƫ���ϵ");
	else
	printf("�ù�ϵ����ƫ���ϵ"); 
	
	return 0;
}
