#include<stdio.h>
#include<math.h>

int func(int n)    //定义函数求2的次幂，因为pow()函数返回值和参数值的类型必须为double 
{
	if(n==0)
		return 1;
	else
		return(2*func(n-1)); 
}

int main()
{
	int n,d,l,i,j,k=0;
	int a[100][100];                   //定义二维数组保存相关信息，二维数组尺寸不能很大 
	while(scanf("%d",&n) && n != 0)    //当输入的n不为0时循环输入 
	{
		int num[10000]={0};
		int k1=1;
		for(i=0;i<n;i++)
			scanf("%d",&num[i]);  //输入所有结点的编号 
		scanf("%d",&d);           //输入待求深度d 
		l = log(n)/log(2)+1;      //l是二叉树的深度，深度为1的仅有结点1 
		if(d == l)                //最后一行的情况 
		{
			for(i=func(l-1)-1;i<=n-1;i++)
			{
				a[k][k1] = num[i];
				k1++;               //k1-1表示a[k][k1]中的数据元素个数（除数组第一位） 
				a[k][0] = k1-1;     //为了方便后续输出，将k1存入数组的第一位 
			}
		}
		else if(d<l&&d>=1)
		{
			for(i=func(d-1)-1;i<=func(d)-2;i++)
			{
				a[k][k1] = num[i];  //k1-1表示a[k][k1]中的数据元素个数（除数组第一位） 
				k1++;
				a[k][0] = k1-1;     //为了方便后续输出，将k1存入数组的第一位 
			}
		}
		else                        //d<1和d>l的情况 
		{
			a[k][0] = 0;
		}	
		k++;     //最终k值表示输入的数据组数 
	}
	
	for(i=0;i<k;i++)
	{
		if(a[i][0] == 0)
			printf("EMPTY\n");
		else
		{
			for(j=1;j<=a[i][0];j++) 
			{
				printf("%d ",a[i][j]);
			}
			printf("\n");
		}
	}
	return 0;
}
