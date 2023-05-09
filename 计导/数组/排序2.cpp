#include<stdio.h>
int da(int m,int n){
   if(m%2==0&&n%2!=0)return 0;
   else
	   if(m%2!=0&&n%2==0)return 1;
	   else
		   if(m<n)return 1;
		   else   return 0;
}
int main(){
  int n,i,j,t,a[100];
  scanf("%d",&n);
  for(i=0;i<n;++i)
	  scanf("%d",&a[i]);
  for(i=1;i<n;++i){
     for(t=a[i],j=i-1;j>=0&&da(a[j],t);--j)
		 a[j+1]=a[j];
	 if(j!=i-1)a[j+1]=t;
  }
  for(i=0;i<n;++i)
	  printf("%d%c",a[i],' ');              //printf(¡°%d   ¡±,a[i]);
   printf("\n");
  return 0;
}
