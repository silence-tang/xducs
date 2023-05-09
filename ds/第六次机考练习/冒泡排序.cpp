#include<stdio.h>
int main()
{
	int i,j,n,temp,count=0,a[100];
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	for(i=1;i<=n-1;i++)         //n个元素，最多进行n-1趟排序 
	{
		for(j=0;j<n-i;j++)    //第i趟排序中，从第1个元素到第n-i+1个元素，每个元素和它后面的一个元素比较 
		{
			if(a[j] > a[j+1]) //如果相邻的两个元素中前一个元素大于后一个元素，则交换
			{
				temp = a[j];
				a[j] = a[j+1];
				a[j+1] = temp;
				count++;
			}
		}
	}
	printf("%d",count);
	return 0;
}
