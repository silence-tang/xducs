#include<stdio.h>
#include<iostream>
#include<cstring>
using namespace std;

void jzdm(int n,int t,int p[][100]) //�ú���ʵ�־���������� 
{
	
	int i,j,k,temp=0;
	int q[n][n], res[n][n];
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
 		{
			q[i][j]=p[i][j];
 			res[i][j]=p[i][j];
		}

 	while(t-1!=0)
	{
 		for(i=0;i<n;i++)
 		{
 			for(j=0;j<n;j++)
 			{
 				for(k=0;k<n;k++)
 				{temp += q[i][k] * p[k][j];}
 				res[i][j]=temp;
 				temp=0;
 			}
 		}
 		
 	memcpy(q,res,sizeof(res));
	t--;
 	}

	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
    	{
			printf("%d ",res[i][j]);
			if(j==n-1)
			printf("\n");
 		}
	}
	
}

void jzdm_bool(int n,int t,int p[][100]) //��ɴ��Ծ���
{
	
	int i,j,k,temp=0;
	int q[n][n], res[n][n];
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
 		{
			q[i][j]=p[i][j];
 			res[i][j]=p[i][j];
		}

 	while(t-1!=0)
	{
 		for(i=0;i<n;i++)
 		{
 			for(j=0;j<n;j++)
 			{
 				for(k=0;k<n;k++)
 				{temp += q[i][k] * p[k][j];}
 				res[i][j]=temp;
 				temp=0;
 			}
 		}
 		
 	memcpy(q,res,sizeof(res));
	t--;
 	}

	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
    	{
    		if(res[i][j] != 0)
    		{
    			res[i][j] = 1;
			}
			printf("%d ",res[i][j]);
			if(j==n-1)
			printf("\n");
 		}
 		
	}

}	

int flag3_judge(int n,int t,int p[][100])    //Ϊ�˺������flag3��ֵ 
{
	
	int i,j,k,temp=0;int flag=1;
	int q[n][n], res[n][n];
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
 		{
			q[i][j]=p[i][j];
 			res[i][j]=p[i][j];
		}

 	while(t-1!=0)
	{
 		for(i=0;i<n;i++)
 		{
 			for(j=0;j<n;j++)
 			{
 				for(k=0;k<n;k++)
 				{temp += q[i][k] * p[k][j];}
 				res[i][j]=temp;
 				temp=0;
 			}
 		}
 		
 	memcpy(q,res,sizeof(res));
	t--;
 	}

	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
    	{
    		if(res[i][j] != 0)
    		{
    			res[i][j] = 1;
			}
		
 		}
 		
	}
	
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
    	{
    		if(j != i)                     //���������Խ���Ԫ�� 
    		{
    			if(res[i][j] != 1)
    			{
    				flag = 0;
    				goto loop;
				}
			
			}
			
		}
		
	}
	loop:
	return flag;//��flag=1����GΪ����ͨͼ����flag=0����G����ͨ 

}	

void ltxpd(int n,int t,int p[][100]) //ʵ����ͨ���ж�
{
	int i,j,k,temp=0;
	int flag1=1,flag2=1,flag3=1;
	int q[n][n], res[n][n];
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
 		{
			q[i][j]=p[i][j];
 			res[i][j]=p[i][j];
		}

 	while(t-1!=0)
	{
 		for(i=0;i<n;i++)
 		{
 			for(j=0;j<n;j++)
 			{
 				for(k=0;k<n;k++)
 				{temp += q[i][k] * p[k][j];}
 				res[i][j]=temp;
 				temp=0;
 			}
 		}
 		
 	memcpy(q,res,sizeof(res));
	t--;
 	}                                      //�ȵõ��ɴ��Ծ��� 

	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
    	{
    		
    		if(res[i][j] != 0)
    		{
    			res[i][j] = 1;
			}
			
		}
		
	}
	
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
    	{
	    	if(res[i][j] != 1)
    		{
    			flag1 = 0;                          
			}
		
		}
		
	}
	//printf("%d",flag1);
	if(flag1 == 0)                          //��flag1=0,��G����ǿ��ͨͼ,���������ж� 
	{
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
    		{
    			
				if(res[i][j] + res[j][i] <= 0)
				{
					flag2 = 0;    //��flag2=0,��G���ǵ����ͼ 
				}
			}
		}
	}
	
	if(flag1 == 0 && flag2 == 0)           //��G�Ȳ���ǿ��ͨͼҲ���ǵ����ͼʱ,���������ж� 
	{
		
		if(p[i][j] == 1 || p[j][i] == 1)   //��ԭ�ڽӾ���ת��Ϊp',�ټ���p'�Ŀɴ��Ծ���
		{
			p[i][j] = 1;
			p[j][i] = 1;
		}
		
		flag3 = flag3_judge(n,n+1,p);
	
	}
	
	if(flag1 == 0 && flag2 == 0 && flag3 == 0)
		printf("��ͼ����ͨ");
	else
		printf("��ͼ��ͨ");
		
}

int main()
{
	int n,i,j,k,a[100][100],c[100][100]={0};
	scanf("%d",&n);
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
		{	
			scanf("%d",&a[i][j]);    //�����ڽӾ���
		}

	for(i=0;i<n;i++)
	{
		printf("��������b%d:\n",i+1);
		jzdm(n,i+2,a);               //�ֲ����ú�����������й������� 
	}
	
	printf("�ɴ����P:\n");              
	for(i=0;i<n;i++)
		a[i][i]  += 1;
		
	jzdm_bool(n,n+1,a);              //��ɴ��Ծ���
	ltxpd(n,n+1,a);                  //�ж�ͼ������ 

	return 0;
	
}
