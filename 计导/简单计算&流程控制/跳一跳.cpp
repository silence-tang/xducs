#include<stdio.h>
int main()
{
	int i,l,j;
	int count;
	int sum=0;
	int a[1000];
	for(i=0;i<1000;i++)
	{
		scanf("%d",&a[i]);
		if(a[i]==0) break;
	}
	for(i=0;i<1000;i++)
	{
		count=1;
		if(a[i]==1) sum+=1;
		if(a[i]==2)
		{
			if(i==0||a[i-1]==1) sum+=2;
			else
			{
				for(j=i-1;j>=0;j--)
				{
					if(a[j]==2) count+=1;
					else break;
				}
				sum=sum+2*count;
			}
		}
		if(a[i]==0)
		{
			sum=sum+0;
			break;
		 } 
	}
	printf("%d",sum);
	return 0;
 } 
