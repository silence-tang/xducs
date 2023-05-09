#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int main()
{
	int i,d,n,temp,a[100];
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	d = floor(n / 2);  //第一次增量为n/2向下取整 
	for(i=0;i<=n-d-1;i++)
	{
		if(a[i] > a[i+d])
		{
			temp = a[i+d];
			a[i+d] = a[i];
			a[i] = temp;
		}
	}
	for(i=0;i<n;i++)
		printf("%d ",a[i]);
	return 0;
}
