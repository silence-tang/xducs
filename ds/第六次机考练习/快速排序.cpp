#include<stdio.h>
#include<stdlib.h>
int main()
{
	int i,n,low,high,temp,pivotkey,a[100];
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	pivotkey = a[0];       //选定枢轴记录关键字为数组第一个元素 
	low = 0; high = n-1;   //初始化low,high标志，分别指向第一个和最后一个元素 
	while(low!=high)       //循环结束条件是low==high 
	{
		while(low != high && a[high] >= pivotkey)
			high--;        //此时high指向从右往左第一个比key小的数 
		temp = a[low];
		a[low] = a[high];
		a[high] = temp;    //交换a[high]和a[low] 
		while(low != high && a[low] <= pivotkey)
			low++;         //此时low指向从左往右第一个比key大的数 
		temp = a[high];
		a[high] = a[low];
		a[low] = temp;     //交换a[high]和a[low] 
	}
	for(i=0;i<n;i++)
		printf("%d ",a[i]);
	return 0;
}
