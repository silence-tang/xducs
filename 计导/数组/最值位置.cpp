# include<stdio.h>
int main()
{
         int a[10000],i,k,n;
         scanf("%d",&n);
        for(i=0;i<n;i++)
       { 
	      scanf("%d",&a[i]);
	   } 
          int max=a[0];
        for(i=1;i<n;i++)
    
      {
      	if( a[i]>max ) 
	    {
	    	max=a[i];
	        k=i;
	    	
		}
	  }
    printf("%d %d %d",n,a[k],k);
    return 0;
}
