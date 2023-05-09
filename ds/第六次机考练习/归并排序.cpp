#include<stdio.h>
#include<algorithm>
using namespace std;
int main()
{
	int i,j,n1,n2,a1[100],a2[100],a[200];
	scanf("%d %d",&n1,&n2);
	for(i=0;i<n1;i++)
	{
		scanf("%d",&a1[i]);
		a[i] = a1[i];
	}
		
	for(i=0;i<n2;i++)
	{
		scanf("%d",&a2[i]);
		a[i+n1] = a2[i];
	}
	sort(a,a+n1+n2);
	for(i=0;i<n1+n2;i++)
		printf("%d ",a[i]);	
	return 0;
}
