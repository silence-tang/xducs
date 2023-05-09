#include<stdio.h>
#include <string.h>
int main()
{
	long int i,j,m,k,sum=0,n,flag,b[100000];
	scanf("%ld",&n);
	for(i=0,k=n;i<=100000;i++)
	{   
	    m=i+1;
	    b[i]=k%10;
	    k=k/10;
	    if(k==0) break;	
	}
	for(i=0,j=m-1;i<(m/2);i++,j--)
	{
	    	if(b[i]==b[j]) flag=1;
			else flag=0;
	}  
		if(flag==1)
	{
		for(i=0;i<m;i++)
		  sum+=b[i]; 	   
	    printf("%d",sum);
	}
	    if(flag==0) printf("no");
   return 0;	
}
