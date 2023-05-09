#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int main()
{
	int i,j,k,n,a[100];
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(i=2;i<=4;i++)      //这里是循环三轮的意思 
	{
		if(a[i-1]>a[i])
		{
			a[0] = a[i];
			a[i] = a[i-1];
			for(j=i-2;a[0] < a[j];j--)
				a[j+1] = a[j];
			a[j+1] = a[0];
		}                  //这里，第一趟排序已经完成 
		for(k=1;k<=n;k++)
			printf("%d ",a[k]);
		printf("\n");      //输出每趟排序结束后得到的结果，这里共3行 
	}
	return 0;
}
