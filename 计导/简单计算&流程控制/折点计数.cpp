#include<stdio.h>



int main()

{

	

	int n,sub1,sub2,t,x,y,i;

	

	scanf("%d",&n);

	

	scanf("%d",&x);

	scanf("%d",&y);

	sub1=x-y;

	

	

	for(i=0,t=0;i<n-2;++i)

	{

		scanf("%d",&x);

		sub2=y-x;

		y=x;

		

		if(sub1*sub2<0)

        {t++;}	

	

		

		sub1=sub2;

	}

	

	printf("%d",t);

	

	

	

	

	

	return 0;

 }
