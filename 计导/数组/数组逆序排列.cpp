#include<stdio.h>
int main()
{
	 char a[9],b[5];int i;
	 for(i=0;i<9;i++)
     scanf("%c",&a[i]);
     
	 for(i=0;i<5;i++)
	 {
	  b[i]=a[8-2*i];
	 }
	 
     for(i=0;i<5;i++)
	 printf("%c ",b[i]);
	return 0;
} 
