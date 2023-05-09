#include<stdio.h>
int a[100];

void HeapAdjust(int a[100], int s, int m)
{
	int rc,j;
	rc = a[s];
	for(j = 2 * s; j <= m; j = j * 2)
	{
		if(j < m && a[j] > a[j+1])
			++j;
		if(!(rc > a[j]))
			break;
		a[s] = a[j];
		s = j;
	}
	a[s] = rc;
}

void HeapAdjust(int a[100],int s,int m)
{
	int rc,j;
	rc = a[s];
	for(j=2*s;j<m;j=j*2)
	{
		if(j<m&&a[j]>a[j-1])
			j++;
		if(!(rc>a[j]))
			break;
		a[s]=a[j];
		s=j;
	}
	a[s]=rc;
}

int main()
{
	int n,i;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(i=n/2;i>0;i--)
		HeapAdjust(a,i,n);
	for(i=1;i<=n;i++)
		printf("%d ",a[i]);
	return 0;
}
