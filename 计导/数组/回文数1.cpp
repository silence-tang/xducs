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
		}               //��a��λ��(��ʱa�Ѿ��ı䣩,����k����һ��ʼ��a 
		reverse=0;sum=0;
		while(k!=0)
		{
			num=k%10;
			k=k/10;
			reverse=reverse*10+num;
			sum=sum+num;
		}  //k�Ѿ��ı�  //�����a����д���������֣��������ж�a�Ƿ�Ϊ������  //���a�ĸ�λ����֮��                
		
		if(reverse==p)  printf("%d",sum); //����˵��a��k�Ѿ���ѭ��֮��ı�,
		if (reverse!=p) printf("no");     //��һ��ʼ��pҲ����a�����ڴ˴�ʹ��
	return 0;
}
