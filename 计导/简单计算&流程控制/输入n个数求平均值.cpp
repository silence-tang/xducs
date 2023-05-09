#include <stdio.h>
int main()
{
	int n,m,i;
	float x;
	int k=0;
	
	scanf("%d\n",&n);
	for(i=1;i<=n;i++)
	{
	  scanf("%d",&m);
	  k=(k+m);
	  x=k/n*1.0;
	}
	printf("%.2f",x);
	
	return 0;
	
}
	
