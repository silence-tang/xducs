#include <stdio.h>
int main(){
	int a[]={1,2,3,4,5,6,7,8,9,0};
	int n=10;//n=10;
	int i;
	for(i=0;i<10;i++)
	{
		if(a[i]==n)
        break;
	}
	if(i<10)
		printf("pos=%d\n",i);
	if(i=10)                  //i=10代表a[0]-a[9]都没有要找的数（即最后一次循环中i自增为10，随后i不满足i<10，循环结束） 
		printf("pos=-1\n");

	return 0;
}

