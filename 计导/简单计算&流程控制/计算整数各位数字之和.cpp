#include<stdio.h>

int main()

{

    int x,i;

    int sum=0;

    scanf("%d",&x);

    while(x!=0)
	{

       i=x%10;

       x=x/10;

       sum+=i;

    }

    printf("%d",sum);
    
    return 0;

}
//Á÷³Ì£º 
//x=12345
//i=5  x=1234  sum=5
//i=4  x=123   sum=5+4
//i=3  x=12    sum=5+4+3
//i=2  x=1     sum=5+4+3+2
//i=1  x=0     sum=5+4+3+2+1
