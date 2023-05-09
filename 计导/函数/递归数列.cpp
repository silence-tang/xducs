#include<stdio.h>

double function(int n)

 {  
 	 return n==1 ? 1 : 1/(1+function(n-1));//ตÝน้ 
 }

 

    int main()

    {

    	int n;

    	double m;

    	scanf("%d",&n);

    	

    	m=function(n);

    	

    	printf("%.6lf",m);


    	return 0;

	}
