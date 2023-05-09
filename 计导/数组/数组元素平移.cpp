#include<stdio.h>
int main()
{
    int a[10]={1,2,3,4,5,6,7,8,9,10},b[9],i,p,k=0;
    scanf("%d",&p);
    for(i=p+1;i<10;i++)
    { 
      b[k]=a[i];
      k++;
	}//´ËÊ±k=9-p 
	
    for(i=0;i<=p;i++)
    {
      b[k]=a[i];
      k++;	
	}
	
	for(i=0;i<10;i++)
    printf("%d ",b[i]);
    
  return 0;
} 
