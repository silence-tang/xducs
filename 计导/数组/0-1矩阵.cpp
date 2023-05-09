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
			  sign=1;         //100110 //标记变量，有1就是sign = 1
			  if(a[i][j+1]==0)        //下一个为0 即连续停止
			   {
				 if(count>max)     //需比较是否为最长
				 {
				   max=count;
				   location=j;
				   count=0;              //因为1的连续结束了，所以count重赋值为0
				 }
			   }
			}	
		}
		
      	 if(sign) /*如果sign为真,即sign=1*/ /*注：如果sign为假，则意味着sign=0*/ 
		 printf("%d %d\n",location-max+1,location);
		 else puts("-1 -1");
	  }
return 0;
}
//找出每一行最长的连续1序列，输出其起始位置(从0开始计算)和结束位置(从0开始计算)，
//如果这一行没有1则输出两个-1,然后换行。
/*输入样例	
5 6
1 0 0 1 1 0
0 0 0 0 0 0
1 1 1 1 1 1
1 1 1 0 1 1
0 0 1 1 0 0												

输出样例	
3 4
-1 -1
0 5
0 2
2 3  */
