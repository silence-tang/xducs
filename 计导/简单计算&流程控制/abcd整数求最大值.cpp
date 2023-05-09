#include <stdio.h>
int main()
{
	int a,b,c,d,max1,max2,X;
	
	scanf("%d %d %d %d",&a,&b,&c,&d);
	
	if(a>=b&&a>=c)
     max1=a;
	else if(b>=a&&b>=c)
	 max1=b;
	else
	 max1=c;
	
	if(b>=c&&b>=d)
	 max2=b;
	else if(c>=b&&c>=d)
	 max2=c;
	else
	 max2=d;
	 
	 X=(max1>max2)?max1:max2;
	
	printf("%d",X);
	
	return 0;
	
	
	
	
	
	
	
	
	
 } 
