#include<stdio.h>
#include<math.h>

int func(int n)    //���庯����2�Ĵ��ݣ���Ϊpow()��������ֵ�Ͳ���ֵ�����ͱ���Ϊdouble 
{
	if(n==0)
		return 1;
	else
		return(2*func(n-1)); 
}

int main()
{
	int n,d,l,i,j,k=0;
	int a[100][100];                   //�����ά���鱣�������Ϣ����ά����ߴ粻�ܴܺ� 
	while(scanf("%d",&n) && n != 0)    //�������n��Ϊ0ʱѭ������ 
	{
		int num[10000]={0};
		int k1=1;
		for(i=0;i<n;i++)
			scanf("%d",&num[i]);  //�������н��ı�� 
		scanf("%d",&d);           //����������d 
		l = log(n)/log(2)+1;      //l�Ƕ���������ȣ����Ϊ1�Ľ��н��1 
		if(d == l)                //���һ�е���� 
		{
			for(i=func(l-1)-1;i<=n-1;i++)
			{
				a[k][k1] = num[i];
				k1++;               //k1-1��ʾa[k][k1]�е�����Ԫ�ظ������������һλ�� 
				a[k][0] = k1-1;     //Ϊ�˷�������������k1��������ĵ�һλ 
			}
		}
		else if(d<l&&d>=1)
		{
			for(i=func(d-1)-1;i<=func(d)-2;i++)
			{
				a[k][k1] = num[i];  //k1-1��ʾa[k][k1]�е�����Ԫ�ظ������������һλ�� 
				k1++;
				a[k][0] = k1-1;     //Ϊ�˷�������������k1��������ĵ�һλ 
			}
		}
		else                        //d<1��d>l����� 
		{
			a[k][0] = 0;
		}	
		k++;     //����kֵ��ʾ������������� 
	}
	
	for(i=0;i<k;i++)
	{
		if(a[i][0] == 0)
			printf("EMPTY\n");
		else
		{
			for(j=1;j<=a[i][0];j++) 
			{
				printf("%d ",a[i][j]);
			}
			printf("\n");
		}
	}
	return 0;
}
