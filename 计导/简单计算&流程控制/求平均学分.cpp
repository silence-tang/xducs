#include<stdio.h>
int main()
{
	int i,n,a;
	float x,sum1=0.0,sum2=0.0,result;
	  printf("������γ�������");
	  scanf("%d",&n);
	  printf("������ÿ�ſε�ѧ�ּ��γ̷�����"); 
	    for(i=1;i<=n;i++)
	      {
	  	    scanf("%f %d",&x,&a);
		    sum1+=x*a;
		    sum2+=x;
	      } 
	result = (0.05*sum1)/sum2;
    printf("�ܼ����ƽ��ֵΪ��%.2f",result);
	return 0;
}
