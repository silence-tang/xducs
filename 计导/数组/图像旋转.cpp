#include<stdio.h>
int main()
{
	int n,m,a[100][100],b[100][100],i,j;
	scanf("%d %d",&n,&m);
	for(i=0;i<n;i++)
	  for(j=0;j<m;j++)
        scanf("%d",&a[i][j]);
	for(j=0;j<m;j++)
      {
      	 for(i=n-1;i>=0;i--)
         {
       	    b[j][n-1-i]=a[i][j];
	     }
      	
	  }

	for(i=0;i<m;i++)
	  for(j=0;j<n;j++)
	    {
	       printf("%d ",b[i][j]);
	       if(j==n-1) printf("\n");
		}
	    
  return 0;
}
