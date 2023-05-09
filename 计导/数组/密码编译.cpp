#include<stdio.h>
int main()
{
	char a[7],b[7];int i;
	for(i=0;i<7;i++)
     scanf("%c",&a[i]);
	for(i=0;i<7;i++)
	{
		if(a[i]<=90&&a[i]>=65)
		b[i]=155-a[i];
		if(a[i]<=122&&a[i]>=97)
		b[i]=219-a[i];
	}
     for(i=0;i<7;i++)
	 printf("%c",b[i]);
	return 0;
} 
