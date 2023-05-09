#include<stdio.h>
int main ()
	{
		int m,n,q,r;
		
		scanf("%d %d %d %d",&m,&n,&q,&r);
		
		if(r==m%n && q==m/n)
		printf("yes");
		
		else
		printf("%d %d",m/n,m%n);
		
		return 0;
	}
