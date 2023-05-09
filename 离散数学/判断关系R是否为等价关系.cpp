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
		}                       //用flag1判断关系R是否具有自反性，flag1=1,有; flag1=0,无  
	}	
	
	for(i=0;i<m;i++)
	{
		for(j=0;j<m;j++)
		{
			if(a[i][j]==1&&a[j][i]==1)
				flag2=0;        //用flag2判断关系R是否具有反对称性，flag2=1,有; flag2=0,无  
		}
	}

	for(i=0;i<m;i++)
	{
		for(j=0;j<m;j++)
		{
			for(k=0;k<m;k++)
			{
				if(a[i][j]==1&&a[j][k]==1&&a[i][k]!=1)
					flag3=0;  //用flag3判断关系R是否具有传递性，flag3=1,有; flag3=0,无  
			}
		}
	}
	
	if(flag1==1&&flag2==1&&flag3==1)
	printf("该关系是偏序关系");
	else
	printf("该关系不是偏序关系"); 
	
	return 0;
}
