#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int main()
{
	int i,j,k,n,a[100];
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(i=2;i<=4;i++)      //������ѭ�����ֵ���˼ 
	{
		if(a[i-1]>a[i])
		{
			a[0] = a[i];
			a[i] = a[i-1];
			for(j=i-2;a[0] < a[j];j--)
				a[j+1] = a[j];
			a[j+1] = a[0];
		}                  //�����һ�������Ѿ���� 
		for(k=1;k<=n;k++)
			printf("%d ",a[k]);
		printf("\n");      //���ÿ�����������õ��Ľ�������ﹲ3�� 
	}
	return 0;
}
