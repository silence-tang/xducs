#include<stdio.h>
#include<math.h>
int main()
	{
		float s,a,b,c,p;
		scanf("%f %f %f",&a,&b,&c);
		p=(a+b+c)/2.00;
		s=sqrt(p*(p-a)*(p-b)*(p-c));
		printf("%.2f",s);
		return 0;
	}
