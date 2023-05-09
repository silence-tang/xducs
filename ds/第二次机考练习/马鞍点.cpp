#include<stdio.h>
int main()
{
  int a[100][100],b,c=0,i,j,k,p,m,n,min,max;
  scanf("%d%d",&m,&n);
  for(i=0;i<m;i++)
	 for(j=0;j<n;j++)
		 scanf("%d",&a[i][j]);
  for(i=0;i<m;i++)
{
		min=a[i][0];k=0;
	    for(j=1;j<n;j++)
			if(a[i][j]<min) {min=a[i][j];k=j;} //找到某一行的最小项及所处列数 
	    max=a[0][k];b=0;//使“最小项”所处列的第一个数暂定为此列的最大值，接下来与此列其他数比较，找出此列最大值 
		for(p=1;p<m;p++)
			if(a[p][k]>max) {max=a[p][k];b=p;}//找到这一列的最大项及所处行数 
		if(b==i)//如果这一列最大项的行数等于上面找到的“那一行的最小项”的行数 
		{
          c=1;//那么c=1，判定出它是马鞍点 
		  printf("%d %d %d\n",b+1,k+1,a[b][k]);
		  goto flag;//如果找到马鞍点了，则c=1，并且输出结果,程序结束;否则c为零一直到循环结束。 
		}
	    else c=0;
}
  if(c==0)printf("NO\n");
  flag: return 0;
}
