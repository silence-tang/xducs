#include<stdio.h>
int main()
{
	char a[100],b[100];int i,k;
	while(scanf("%c",&a[i])!=EOF)
	{
		if(a[i]<=90&&a[i]>=65)
		{   
		  b[i]=155-a[i];
		  printf("%c",b[i]);
		}
		if(a[i]<=122&&a[i]>=97)
		{
			b[i]=219-a[i];
			printf("%c",b[i]);
		} 	
	}
	 //它扫描的时候是一个一个扫描进去的，处理也是一个一个处理，因此扫描到A后它会输出一个Z，以此类推
	 //但尽管他是一个一个输出处理后的结果的，最后呈现在屏幕上的就是一连串的处理结果 
	return 0;
} 
