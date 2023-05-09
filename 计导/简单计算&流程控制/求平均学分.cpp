#include<stdio.h>
int main()
{
	int i,n,a;
	float x,sum1=0.0,sum2=0.0,result;
	  printf("请输入课程门数：");
	  scanf("%d",&n);
	  printf("请输入每门课的学分及课程分数："); 
	    for(i=1;i<=n;i++)
	      {
	  	    scanf("%f %d",&x,&a);
		    sum1+=x*a;
		    sum2+=x;
	      } 
	result = (0.05*sum1)/sum2;
    printf("总绩点的平均值为：%.2f",result);
	return 0;
}
