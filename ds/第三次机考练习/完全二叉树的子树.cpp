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
        	p++;                      //s��ʾ������ 
    	}
    	for(int j=p-1;j>0;j--)
		{                             //���һ�в�һ��ȫ��������s-1 
        	t=t*2;                    //t���ڼ�¼ÿһ�еĸ��� 
        	sum=sum+t;                //sum��¼�����һ�������е��ܸ��� 
    	}
    	t=t*2;                        //�����һ������ 
    	if(n-m*t>=0)
			sum=sum+n-(m*t)+1;        //�ٽ����һ�����ϣ�if�ж���Ϊ����û�����һ�н��͵����һ���ˣ�
    	num[k] = sum;
    	k++;
	}
	for(i=0;i<k;i++)
		printf("%d\n",num[i]);
	return 0;
}

