#include<stdio.h>
int main()
{
	int i,j,n,temp,count=0,a[100];
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	for(i=1;i<=n-1;i++)         //n��Ԫ�أ�������n-1������ 
	{
		for(j=0;j<n-i;j++)    //��i�������У��ӵ�1��Ԫ�ص���n-i+1��Ԫ�أ�ÿ��Ԫ�غ��������һ��Ԫ�رȽ� 
		{
			if(a[j] > a[j+1]) //������ڵ�����Ԫ����ǰһ��Ԫ�ش��ں�һ��Ԫ�أ��򽻻�
			{
				temp = a[j];
				a[j] = a[j+1];
				a[j+1] = temp;
				count++;
			}
		}
	}
	printf("%d",count);
	return 0;
}
