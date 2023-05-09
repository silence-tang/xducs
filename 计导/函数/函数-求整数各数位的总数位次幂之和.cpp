#include<stdio.h>
#include<math.h>
#include<stdlib.h>
int function(int n)
{
	int k,j,i,sum=0;
	int m;
	m=n;
	for(j=1;j<=1000;j++)
	{
		n=n/10;
		k=j;
	    if(n==0)
	    break;
	}
		while(m!=0)
	{

       i=m%10;

       m=m/10;

       sum=sum+pow(i,k);

    }
	return(sum);
	
}
int main()
{
	int n,sum;
	int function(int n);
	scanf("%d",&n);
	sum=function(n);
	printf("%d",sum);
	
	return 0;

}
