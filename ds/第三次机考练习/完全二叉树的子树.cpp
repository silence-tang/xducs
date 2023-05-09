#include<stdio.h>
#include<math.h> 
int main()
{
    int m,n,i,k=0,num[10000];
    while(scanf("%d %d",&m,&n)&&(m!=0||n!=0))
	{
    	int t=1,p=0,sum=1,i=m;
    	while(i<n)
		{
       		i=2*i+1;
        	p++;                      //s表示从行数 
    	}
    	for(int j=p-1;j>0;j--)
		{                             //最后一行不一定全都有所以s-1 
        	t=t*2;                    //t用于记录每一行的个数 
        	sum=sum+t;                //sum记录除最后一行其余行的总个数 
    	}
    	t=t*2;                        //将最后一行算上 
    	if(n-m*t>=0)
			sum=sum+n-(m*t)+1;        //再将最后一行算上（if判断因为可能没到最后一行结点就到最后一个了）
    	num[k] = sum;
    	k++;
	}
	for(i=0;i<k;i++)
		printf("%d\n",num[i]);
	return 0;
}

