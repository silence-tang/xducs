#include<stdio.h>
#include<algorithm>
using namespace std; 
int main()
{
	int n,a[1000],i,j,sum1=0,sum2=0,flag;
	scanf("%d",&n);
	 for(i=0;i<n;i++)
	  scanf("%d",&a[i]);
    sort(a,a+n);
    for(i=0;i<n;i++)
    {   flag=-1;
    	for(j=0;j<i;j++)
    	 {
    	  if(a[j]<a[i])
		  sum1++;	
		 }//��a[i]С��Ԫ�ظ��� 
		
    	   for(j=i+1;j<n;j++)
    	   {
    	      if(a[j]>a[i])
		      sum2++;	
		   }//��a[i]���Ԫ�ظ���
		 if(sum1==sum2)
		 {
		   flag=1;
		   printf("%d",i);
		   break;	
		 }
		
	}
	if(flag==-1) printf("-1");
  return 0;
}
