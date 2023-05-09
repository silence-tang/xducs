#include<stdio.h>
#include<math.h>
int main()
{
	int a,p,i,k,sum,num,len,reverse;
    scanf("%d",&a);
      k=a;p=a;
	  while(a>=1)
		{
		    a=a/10;
            len++;
		}               //求a的位数(此时a已经改变）,故用k代表一开始的a 
		reverse=0;sum=0;
		while(k!=0)
		{
			num=k%10;
			k=k/10;
			reverse=reverse*10+num;
			sum=sum+num;
		}  //k已经改变  //求出将a倒着写出来的数字，接下来判断a是否为回文数  //求出a的各位数字之和                
		
		if(reverse==p)  printf("%d",sum); //上面说了a和k已经在循环之后改变,
		if (reverse!=p) printf("no");     //故一开始令p也等于a，便于此处使用
	return 0;
}
