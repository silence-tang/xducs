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
	int j,k,i,m,p,q,x,y,a,b; int sum=0; int n=0;
	int function(int n);
	scanf("%d %d",&a,&b);
    x=a<=b?a:b;  y=a>=b?a:b;
    for(i=x;i<=y;i++)
    {   m=i; p=i;
        for(j=1;j<=100000;j++)
	   {
		 p=p/10;
		 k=j;
	     if(p==0)
	     break;
	   }      
	   
	   if(k>=3)
	   {
	   	if(m==function(m))
	   	n++;
       }
    }
    
    printf("%d",n);
	  return 0;
}

