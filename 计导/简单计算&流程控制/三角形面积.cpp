# include<stdio.h>
# include<math.h>

int main()
{
	float a,b,c,s,C;
	
	scanf("%f %f %f",&a,&b,&c);
	
	if(a+b<=c||b+c<=a||a+c<=b)
	printf("Wrong!");
	else
	C=(a+b+c)/2.0;
	s=sqrt(C*(C-a)*(C-b)*(C-c));
	printf("%f",s);
}
