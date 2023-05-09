#include<stdio.h>
int main()
{
	int n,m,a[100],i,j,flag1,flag2;
	scanf("%d %d",&n,&m);
	for(i=0;i<n;i++)
    scanf("%d",&a[i]);
	for(i=0;i<n;i++)
	{   
	    flag1=-1;
	    if(a[i]==m)
		{ 
		  flag1=1;
		  break;
		}		
	}
	if(flag1==1)
	{
	    for(i=0;i<n;i++)
	    {
	    	if(a[i]==m)
	  	   { 
	  	      printf("%d ",i); 
	       }
		}
	} 
	else printf("-1");
   return 0;
}
