# include <stdio.h>
int main()

{   
	float x,w;
	char A=65; char B=66; char C=67;
	scanf("%f",&x);
	
	if(x>=0&&x<=110)
	{w = 0.50*x;
	 printf("%.2f %c %.2f",w,A,x-x);
	}
	
	else if(x>110&&x<=210)
	{w = 55+0.55*(x-110);	
     printf("%.2f %c %.2f",w,B,x-110);
	}
	
	else
	{w = 110+0.70*(x-210);
     printf("%.2f %c %.2f",w,C,x-210);
	} 

	
	
	return 0;
	
}
