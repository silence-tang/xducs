#include<stdio.h>

int main ()
	{
		int a,b;
	    double t,T;
		scanf("%d %d",&a,&b);
		t=a+b/60.00;
		T=4*t*t/(t+2)-20;
		printf("%.2f",T);
		return 0;
	}
