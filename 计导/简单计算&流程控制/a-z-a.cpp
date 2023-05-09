#include<stdio.h>
int main()
{
	int i;
	
	for(i=97;i<=122;i++)
	printf("%c ",i);
	printf("\n");
    for(i=122;i>=97;i--)
	printf("%c ",i);
	
	return 0;
}
