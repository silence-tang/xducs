#include<stdio.h>
int main()
{
	int m,n,i,j,a[100][100];
	scanf("%d %d",&m,&n);
	for(i=0;i<m;i++)
	 for(j=0;j<n;j++)
	  scanf("%d",&a[i][j]);
	  
    for(i=0;i<m;i++)
      {  int count=0,max=0,location=0,sign=0;
      	 for(j=0;j<n;j++)
      	{ 
		   if(a[i][j]==1)
			{
			  count++;
			  sign=1;         //100110 //��Ǳ�������1����sign = 1
			  if(a[i][j+1]==0)        //��һ��Ϊ0 ������ֹͣ
			   {
				 if(count>max)     //��Ƚ��Ƿ�Ϊ�
				 {
				   max=count;
				   location=j;
				   count=0;              //��Ϊ1�����������ˣ�����count�ظ�ֵΪ0
				 }
			   }
			}	
		}
		
      	 if(sign) /*���signΪ��,��sign=1*/ /*ע�����signΪ�٣�����ζ��sign=0*/ 
		 printf("%d %d\n",location-max+1,location);
		 else puts("-1 -1");
	  }
return 0;
}
//�ҳ�ÿһ���������1���У��������ʼλ��(��0��ʼ����)�ͽ���λ��(��0��ʼ����)��
//�����һ��û��1���������-1,Ȼ���С�
/*��������	
5 6
1 0 0 1 1 0
0 0 0 0 0 0
1 1 1 1 1 1
1 1 1 0 1 1
0 0 1 1 0 0												

�������	
3 4
-1 -1
0 5
0 2
2 3  */
