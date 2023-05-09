#include<stdio.h>
int main(){
  int m,n,i,j,k,p,q,a[100];
  scanf("%d%d",&n,&m);
  for(i=0;i<n;++i)
     scanf("%d",&a[i]);
  for(k=0,i=0;k<n;++k){
     for(j=i,p=0,q=0;p<m;++p,++q){
		i=j+q;
        if(i>n-1)i=i%n;
        if(a[i]==0)--p;
	     }
	 m=a[i];
	 a[i]=0;
	 printf("%d%c",i+1,' ');
	 for(++i>n-1?i=i%n:i;k<n-1&&a[i]==0;++i>n-1?i=i%n:i);
}	 
  printf("\n");
  return 0;
}
