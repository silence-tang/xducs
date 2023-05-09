#include<stdio.h>
#define MAXSIZE 100000
int main()
{
	int m,n,i,j,flag,k=0;
	int result[MAXSIZE];
	while(scanf("%d %d",&m,&n) && (m != 0 || n != 0))
	{
		int k1 = 0;
		int k2 = 0;
		int num1[MAXSIZE] = {0};
		int num2[MAXSIZE] = {0};
		while(m != 0)
		{
			num1[k1] = m;
			m = m/2;
			k1++;             //循环结束后k1表示数组num1中的元素个数 
		}
		while(n != 0)
		{
			num2[k2] = n;
			n = n/2;
			k2++;
		}
		for(i=0;i<k1;i++)
		{
			flag = 0;
			for(j=0;j<k2;j++)
			{
				if(num2[j] == num1[i])
				{
					result[k] = num2[j];
					k++;
					flag = 1;
					break;
				}
			}
			if(flag == 1)
				break;
		}
	}
	for(i=0;i<k;i++)
		printf("%d\n",result[i]);
	return 0;
}
