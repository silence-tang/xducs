#include<stdio.h>
#include<stdlib.h>
int main()
{
	int i,n,low,high,temp,pivotkey,a[100];
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	pivotkey = a[0];       //ѡ�������¼�ؼ���Ϊ�����һ��Ԫ�� 
	low = 0; high = n-1;   //��ʼ��low,high��־���ֱ�ָ���һ�������һ��Ԫ�� 
	while(low!=high)       //ѭ������������low==high 
	{
		while(low != high && a[high] >= pivotkey)
			high--;        //��ʱhighָ����������һ����keyС���� 
		temp = a[low];
		a[low] = a[high];
		a[high] = temp;    //����a[high]��a[low] 
		while(low != high && a[low] <= pivotkey)
			low++;         //��ʱlowָ��������ҵ�һ����key����� 
		temp = a[high];
		a[high] = a[low];
		a[low] = temp;     //����a[high]��a[low] 
	}
	for(i=0;i<n;i++)
		printf("%d ",a[i]);
	return 0;
}
