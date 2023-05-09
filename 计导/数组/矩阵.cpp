#include <stdio.h>
#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	int m,i,j,k,a[20][20]={0},b[42]={0};
   scanf("%d",&m);
   for(i=0;i<m;i++)
	   for(j=0;j<m;j++)
	   {
		   scanf("%d",&a[i][j]);
		   b[i]+=a[i][j];
	   }//此时b的前几项分别是矩阵各行之和 
   for(j=0,k=m;j<m;j++)
   {
   	for(i=0;i<m;i++)
	{
     	b[k]+=a[i][j];
   	    k++;
	} 
   }    //此时b从b[m]开始为矩阵各列之和  
   for(i=0,j=0;i<m;i++,j++) b[k]+=a[i][j];
   for(j=m-1,i=0;i<m;j--,i=m-1-j) b[k+1]+=a[i][j];
   sort(b,b+(2*m+2));
   for(i=2*m+1;i>=0;i--)
   printf("%d ",b[i]);
  return 0;
}
