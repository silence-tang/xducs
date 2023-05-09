#include <stdio.h>
#include <stdlib.h>
typedef int inte;//这两行为以后做准备
inte *creat(int m,int n)//产生动态数组（写的通用函数）
{
inte *p;
if(!(p=(inte *)calloc(m*n,sizeof(inte))))
{
printf("空间申请失败！\n");
system("pause");//系统调用
exit(0);
}
return p;
}
void transpose(inte *p1,inte *p2,int m,int n)//实现矩阵的转置（写的通用函数）
{
int i,j;
for(i=0;i<m;i++)
for(j=0;j<n;j++)
*(p1+j*m+i)=*(p2+i*n+j);
}
void matrix_mul(inte *p1,inte *p2,inte *p,int m,int k,int n)//矩阵乘法（写的通用函数）
{
int i,j,l,sum;
for(i=0;i<m;i++)
for(j=0;j<n;j++)
{
sum=0;
for(l=0;l<k;l++)
sum+=*(p1+i*k+l)**(p2+j*k+l);
*(p+i*n+j)=sum;
}
}
void matrix_i(int *p,int n)// 生成单位阵
{
int i,j;
for(i=0;i<n;i++)
for(j=0;j<n;j++)
*(p+i*n+j)=0;
for(i=0;i<n;i++)
*(p+i*n+i)=1;
}
void matrix_r(inte *p1,inte *p2,int m,int n)//实现两个矩阵的或逻辑
{
int i,j;
for(i=0;i<m;i++)
for(j=0;j<n;j++)
*(p1+i*n+j)=((*(p1+i*n+j))||(*(p2+i*n+j)));
}
int main()
{
int *p1,*p2,*p3,*p4;
int n,a,i,j;
if(scanf("%d",&n))
{
if((p1=creat(n,n))&&(p2=creat(n,n))&&(p3=creat(n,n))&&(p4=creat(n,n)))
{
for(i=0;i<n;i++)
for(j=0;j<n;j++)
scanf("%d",p1+i*n+j);
matrix_i(p4,n);//生成n阶单位阵
if(n>1)
matrix_r(p4,p1,n,n);
transpose(p2,p1,n,n);//矩阵转置
for(i=1;i<n-1;i++)
{
matrix_mul(p1,p2,p3,n,n,n);
matrix_r(p4,p3,n,n);//实现两个矩阵的或逻辑
transpose(p2,p3,n,n);
}
for(i=0;i<n;i++)
{
for(j=0;j<n;j++)
printf("%d ",*(p4+i*n+j));
printf("\n");
}
}
else
{
printf("内存分配错误！\n");
system("pause");
}
}
else
printf("输入错误，请检查！\n");

return 0;
}
