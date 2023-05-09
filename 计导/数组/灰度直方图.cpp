#include<stdio.h>

int main()
{
    int img[256][256],a[256]={0},max;
    int m,n,i,j;
    scanf("%d %d",&m,&n);
    for(i=0;i<n;i++)
      for(j=0;j<m;j++)
		{
           scanf("%d",&img[i][j]);
           a[ img[i][j] ]++;
        }
         max=img[0][0];
     for(i=0;i<n;i++)
        for(j=0;j<m;j++)
		{
		   if(img[i][j]>=max) max=img[i][j];	
        }
    for(i=0;i<=max;i++)
	{   
	    if(a[i]!=0)
        printf("%d %d\n",i,a[i]);
        
    }
    return 0;
}
