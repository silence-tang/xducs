#include<stdio.h>
#include<iostream>
#include<cstring>
using namespace std;

void jzdm(int n,int t,int p[][100]) //用函数实现矩阵的幂运算 
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

void jzdm_bool(int n,int t,int p[][100]) //求可达性矩阵
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

int flag3_judge(int n,int t,int p[][100])    //为了后续求出flag3的值 
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
    		if(j != i)                     //不考虑主对角线元素 
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
	return flag;//若flag=1，则G为弱连通图，若flag=0，则G不连通 

}	

void ltxpd(int n,int t,int p[][100]) //实现连通性判断
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
 	}                                      //先得到可达性矩阵 

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
	if(flag1 == 0)                          //若flag1=0,则G不是强连通图,继续后续判断 
	{
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
    		{
    			
				if(res[i][j] + res[j][i] <= 0)
				{
					flag2 = 0;    //若flag2=0,则G不是单项分图 
				}
			}
		}
	}
	
	if(flag1 == 0 && flag2 == 0)           //当G既不是强连通图也不是单项分图时,继续后续判断 
	{
		
		if(p[i][j] == 1 || p[j][i] == 1)   //将原邻接矩阵转化为p',再计算p'的可达性矩阵
		{
			p[i][j] = 1;
			p[j][i] = 1;
		}
		
		flag3 = flag3_judge(n,n+1,p);
	
	}
	
	if(flag1 == 0 && flag2 == 0 && flag3 == 0)
		printf("该图不连通");
	else
		printf("该图连通");
		
}

int main()
{
	int n,i,j,k,a[100][100],c[100][100]={0};
	scanf("%d",&n);
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
		{	
			scanf("%d",&a[i][j]);    //输入邻接矩阵
		}

	for(i=0;i<n;i++)
	{
		printf("关联矩阵b%d:\n",i+1);
		jzdm(n,i+2,a);               //分步调用函数，求出所有关联矩阵 
	}
	
	printf("可达矩阵P:\n");              
	for(i=0;i<n;i++)
		a[i][i]  += 1;
		
	jzdm_bool(n,n+1,a);              //求可达性矩阵
	ltxpd(n,n+1,a);                  //判断图的类型 

	return 0;
	
}
