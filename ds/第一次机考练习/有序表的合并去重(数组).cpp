#include<stdio.h>
#include<stdlib.h>
int mycmp(const void* p1, const void* p2){
	const int * a = (const int *) p1;
	const int * b = (const int *) p2;
	
	int value = 0;
	
	if(*a < *b)
		value = -1;
	else if(*a == *b)
		value = 0;
	else value = 1;
	
	return value;
}

int main()
{
	int m,n,i,j;
	scanf("%d %d",&m,&n);
	int a[m],b[n],c[m+n];
	for(i=0;i<=m-1;i++)
		scanf("%d",&a[i]);
	for(i=0;i<=n-1;i++)
		scanf("%d",&b[i]);
	for(i=0;i<=m-1;i++)
		c[i] = a[i];
	for(i=m;i<=m+n-1;i++)
		c[i] = b[i-6];
	qsort(c,m+n,sizeof(int),mycmp);   //将数组c从小到大排序 
	for(i=0;i<=m+n-1;i++)
	{
		for(j=i+1;j<=m+n-1;j++)
		{
			if(c[j] == c[i])
				c[j] = 0;
		}
	} 
	for(i=0;i<=m+n-2;i++)
	{
		if(c[i] != 0)
			printf("%d ",c[i]);
	}
	if(c[m+n-1]!=0)
		printf("%d",c[m+n-1]);

	return 0;
}
