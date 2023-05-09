#include<stdio.h>

int main()
{
    int n,i,j,sum1=0,sum2=0,sum,a[100][100];
    scanf("%d",&n);
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
           scanf("%d",&a[i][j]);	
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
       {
       	  if(i==j)
       	  sum1+=a[i][j];
    	  if(i==n-1-j)
    	  sum2+=a[i][j];
	   }
	if(n%2==0) sum=sum1+sum2;
	else       sum=sum1+sum2-a[n/2][n/2];
	
    printf("%d",sum);
    return 0;
}    
